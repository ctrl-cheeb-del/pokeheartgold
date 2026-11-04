#include "nitro/mi/memory.h"

#include "global.h"

#include "pokeathlon/pokeathlon.h"
#include "pokeathlon/pokeathlon_save.h"

#include "assert.h"
#include "heap.h"
#include "player_data.h"
#include "render_text.h"
#include "communication_player_state.h"
#include "communication_core.h"

// External functions used throughout this file (in assembly for now)
extern int PokeathlonBox_Init(OverlayManager *man, int *state); // Init
extern int PokeathlonBox_Main(OverlayManager *man, int *state); // Main/Exec
extern int PokeathlonBox_Exit(OverlayManager *man, int *state); // Exit
extern void LinkSync_StartSync(u8 param);
extern BOOL LinkSync_IsSynced(u8 param);
extern BOOL GF_heap_c_dummy_return_true(enum HeapID heapId);

// Data tables in assembly
extern const OverlayManagerTemplate subOverlayTemplate;
extern const u8 gPokeathlonCourseEventIds[40];
extern const void *sPokeathlonStateInfoFuncTable;

BOOL PokeathlonCourse_Init(OverlayManager *manager, int *state) {
    PokeathlonCourseData *data;
    PokeathlonCourseArgs *args;
    OverlayManager *subOverlay;
    BOOL specialMode;
    OverlayManagerTemplate subTemplate;
    void *system;

    Heap_Create(HEAP_ID_3, HEAP_ID_POKEATHLON, 0x72000);

    data = OverlayManager_CreateAndGetData(manager, sizeof(PokeathlonCourseData), HEAP_ID_POKEATHLON);
    MI_CpuFill8(data, 0, sizeof(PokeathlonCourseData));

    data->heapId = HEAP_ID_POKEATHLON;

    args = OverlayManager_GetArgs(manager);
    data->args = args;

    subTemplate = subOverlayTemplate;

    subOverlay = OverlayManager_New(&subTemplate, &data->args, HEAP_ID_POKEATHLON);
    data->subOverlay = subOverlay;

    specialMode = FALSE;
    data->state = specialMode;
    args = data->args;

    if (args->mode == 1) {
        specialMode = TRUE;
        data->participantCount = Comm_CountConnected();
        data->maxParticipants = 4;
    } else {
        data->participantCount = 1;
        data->maxParticipants = 3;
    }

    system = PokeathlonCourseLink_New(PokeathlonCourseCmd_GetTable(), PokeathlonCourseCmd_GetCount(), data, specialMode, data->heapId);
    data->system = system;

    PokeathlonCourse_InitStateInfo(&sPokeathlonStateInfoFuncTable, &data->stateInfo);

    data->stateInfo.stateIndex = 0;
    data->courseState.argsPtr = &data->stateInfo;
    data->courseState.exitFlag = 0;

    PokeathlonCourse_InitPlayerProfiles(data);

    system = PokeathlonCourseScoreList_New(HEAP_ID_POKEATHLON);
    data->graphicsSystem = system;

    if (data->args->mode != 1) {
        TextFlags_SetCanABSpeedUpPrint(TRUE);
        TextFlags_SetAutoScrollParam(0);
        TextFlags_SetCanTouchSpeedUpPrint(TRUE);
    } else {
        TextFlags_SetCanABSpeedUpPrint(FALSE);
        TextFlags_SetAutoScrollParam(1);
        TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    }

    PokeathlonCourse_SetEventDrawEnabled(data, 0);
    PokeathlonCourse_SetEventInitState(data, 0);

    return TRUE;
}

BOOL PokeathlonCourse_Main(OverlayManager *manager, int *state) {
    PokeathlonCourseData *data = OverlayManager_GetData(manager);
    PokeathlonCourseState *courseState = &data->courseState;

    // Frame counter system: increments frameTimer each frame, and frameCounter every 1800 frames (up to max 59999)
    if (data->counterEnabled != FALSE) {
        data->frameTimer++;
        if (data->frameTimer >= 1800) {
            if (data->frameCounter < 59999) {
                data->frameCounter++;
            }
            data->frameTimer = 0;
        }
    }

    // Main state machine
    switch (courseState->mainState) {
    case POKEATHLON_STATE_IDLE:
        if (PokeathlonCourse_RunStateFunc(data)) {
            return TRUE;
        }

        // Handle exit flag
        if (courseState->exitFlag != 0) {
            PokeathlonStateInfo *stateInfo = courseState->argsPtr;
            stateInfo->stateIndex = stateInfo->nextStateIndex;
            stateInfo->stateArgsBase = 0;
            courseState->exitFlag = 0;
        }

        // Check for state transitions
        if (courseState->transitionType != 0) {
            if (courseState->transitionType == 0x10) { // Special exit transition
                courseState->mainState = POKEATHLON_STATE_START_EXIT;
            } else {
                courseState->mainState = POKEATHLON_STATE_START_TRANSITION;
            }
        }
        break;

    case POKEATHLON_STATE_START_TRANSITION:
        LinkSync_StartSync(courseState->transitionType);
        courseState->mainState = POKEATHLON_STATE_WAIT_TRANSITION;
        // Fallthrough to case POKEATHLON_STATE_WAIT_TRANSITION

    case POKEATHLON_STATE_WAIT_TRANSITION:
        if (LinkSync_IsSynced(courseState->transitionType)) {
            courseState->mainState = POKEATHLON_STATE_IDLE;
            courseState->transitionType = 0; // Clear transition type
        }
        break;

    case POKEATHLON_STATE_START_EXIT:
        GF_ASSERT(courseState->transitionType == 0x10);
        LinkSync_StartSync(courseState->transitionType);
        courseState->mainState = POKEATHLON_STATE_EXIT_SEQUENCE;
        // Fallthrough to case POKEATHLON_STATE_EXIT_SEQUENCE

    case POKEATHLON_STATE_EXIT_SEQUENCE:
        if (!LinkSync_IsSynced(courseState->transitionType)) {
            if (PokeathlonCourse_GetNetId(data)) {
                break;
            }

            // Copy data between buffers
            {
                int src;
                u8 *dest1;
                u8 *dest2;
                u32 copyCount;

                src = PokeathlonCourseCmd_PacketSize();
                dest1 = data->dataCopyBuffer1; // Destination buffer 1
                PokeathlonCourseLink_SendCommand(0x1B, dest1, src, data->system);

                dest1 = PokeathlonCourse_ToBytes(data->dataCopyBuffer2); // Destination buffer 2
                dest2 = PokeathlonCourse_ToBytes(data->dataCopySource);  // Source buffer

                // Copy 0x28 bytes from source to dest
                for (copyCount = 0x28; copyCount != 0; copyCount--) {
                    u8 byte;
                    byte = dest2[0];
                    dest2++;
                    dest1[0] = byte;
                    dest1++;
                }
            }
        } else {
            courseState->mainState = POKEATHLON_STATE_IDLE;
            courseState->transitionType = 0; // Clear transition type
        }
        break;
    }

    PokeathlonCourse_DrawEvent(data);
    return FALSE;
}

BOOL PokeathlonCourse_Exit(OverlayManager *manager, int *state) {
    PokeathlonCourseData *data;
    PokeathlonCourseArgs *args;
    PokeathlonSave *pokeathlonSave;
    PokeathlonStatistics *result;
    SaveData *saveData;

    data = OverlayManager_GetData(manager);

    // Verify heap is valid
    GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKEATHLON));

    // Check if we need to free certain allocations
    args = data->args;
    if (args->shouldFreeHeap == FALSE) {
        // Free two heap allocations
        Heap_Free(data->juiceRecord);
        Heap_Free(data->playerJuiceRecords);
    }

    // Get Pokeathlon save data and process result
    saveData = *(SaveData **)data->args;
    pokeathlonSave = Save_Pokeathlon_Get(saveData);
    result = PokeathlonSave_GetStatistics2(pokeathlonSave);
    PokeathlonCourse_AddCapped(data->frameCounter, 59999, result);

    // Reset text flags
    TextFlags_SetCanABSpeedUpPrint(FALSE);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);

    // Free system objects
    PokeathlonCourseScoreList_Free(data->graphicsSystem);
    Heap_Free(data->playerProfiles);
    PokeathlonCourseLink_Free(data->system);

    // Clean up overlay data and heap
    OverlayManager_FreeData(manager);
    Heap_Destroy(HEAP_ID_POKEATHLON);

    return TRUE;
}

BOOL PokeathlonCourse_RunStateFunc(PokeathlonCourseData *data) {
    void **stateDataPtr = (void **)&data->stateInfo.stateArgsBase;
    u8 index = data->stateInfo.stateIndex;
    PokeathlonStateFunc *functionTable = (PokeathlonStateFunc *)data->stateInfo.ptr;
    PokeathlonStateFunc func = functionTable[index];
    BOOL result = func(data, stateDataPtr);

    return result != FALSE;
}

BOOL PokeathlonCourse_RunSubStateLoop(PokeathlonCourseData *data) {
    PokeathlonStateHandlerFunc *statePtr;
    PokeathlonStateHandlerFunc func;
    BOOL result;

    do {
        statePtr = (PokeathlonStateHandlerFunc *)data->state;
        func = statePtr[0];
        result = func(data, 0);

        if (result == 1) {
            return TRUE;
        }

        if (result == 0) {
            break;
        }
    } while (data->args->mode == 0);

    return FALSE;
}

void PokeathlonCourse_InitStateInfo(const void *funcTable, PokeathlonStateInfo *stateInfo) {
    stateInfo->ptr = (void *)funcTable;
    stateInfo->field_04 = 1;
    stateInfo->stateArgsBase = 0;
    stateInfo->stateIndex = 0;
    stateInfo->nextStateIndex = 0;
}

void PokeathlonCourse_InitPlayerProfiles(PokeathlonCourseData *data) {
    int i;

    data->playerProfiles = Heap_Alloc(data->heapId, PlayerProfile_sizeof() * 4);

    for (i = 0; i < 4; i++) {
        PlayerProfile_Init(PokeathlonCourse_GetPlayerProfile(data->playerProfiles, i));
    }

    if (data->args->mode == 0) {
        PlayerProfile *dest = PokeathlonCourse_GetPlayerProfile(data->playerProfiles, 0);
        PlayerProfile *src = Save_PlayerData_GetProfile(data->args->saveData);
        PlayerProfile_Copy(src, dest);
    } else {
        for (i = 0; i < data->participantCount; i++) {
            PlayerProfile *dest = PokeathlonCourse_GetPlayerProfile(data->playerProfiles, i);
            PlayerProfile *src = CommPlayerInfo_GetProfile(i);
            PlayerProfile_Copy(src, dest);
        }
    }
}

PlayerProfile *PokeathlonCourse_GetPlayerProfile(PlayerProfile *profiles, int index) {
    return (PlayerProfile *)&((u8 *)profiles)[PlayerProfile_sizeof() * index];
}

u8 PokeathlonCourse_GetParticipantCount(PokeathlonCourseData *data) {
    return data->participantCount;
}

PokeathlonParticipantData *PokeathlonCourse_GetParticipantData(PokeathlonCourseData *data, int index) {
    return &data->participants[index];
}

u8 *PokeathlonCourse_GetParticipantMons(PokeathlonCourseData *data, int index) {
    return &data->participants[index].mons;
}

SaveData *PokeathlonCourse_GetSaveData(PokeathlonCourseData *data) {
    return data->args->saveData;
}

PokeathlonFieldData *PokeathlonCourse_GetFieldData(PokeathlonCourseData *data) {
    return data->fieldData;
}

PokeathlonFieldData *PokeathlonCourse_GetFieldData_AtIndex(PokeathlonCourseData *data, int index) {
    return &data->fieldData[index];
}

u8 *PokeathlonCourse_GetMonCounters(PokeathlonCourseData *data) {
    return data->monCounters;
}

void *PokeathlonCourse_AllocWork(PokeathlonCourseData *data, u32 size) {
    data->work = Heap_Alloc(data->heapId, size);
    return data->work;
}

void PokeathlonCourse_FreeWork(PokeathlonCourseData *data) {
    Heap_Free(data->work);
    data->work = NULL;
}

void *PokeathlonCourse_GetWork(PokeathlonCourseData *data) {
    return data->work;
}

enum HeapID PokeathlonCourse_GetHeapID(PokeathlonCourseData *data) {
    return data->heapId;
}

u8 PokeathlonCourse_GetEventInitState(PokeathlonCourseData *data) {
    return data->eventInitState;
}

void PokeathlonCourse_SetEventInitState(PokeathlonCourseData *data, int param) {
    data->eventInitState = param;
}

void PokeathlonCourse_AdvanceEventInitState(PokeathlonCourseData *data) {
    data->eventInitState++;
}

void PokeathlonCourse_SetEventDrawEnabled(PokeathlonCourseData *data, int param) {
    data->eventDrawEnabled = param;
}

void PokeathlonCourse_SetEvents(PokeathlonCourseData *data, u8 *param) {
    for (int i = 0; i < data->maxParticipants; i++) {
        data->roundEvents[i] = param[i];
    }

    data->courseId = PokeathlonCourse_FindCourseId(data);
    data->boxCourseId = data->courseId;
}

u32 PokeathlonCourse_GetCurrentEvent(PokeathlonCourseData *data) {
    return data->roundEvents[data->round];
}

u32 PokeathlonCourse_GetRoundEvent(PokeathlonCourseData *data, u8 index) {
    if (index >= data->maxParticipants) {
        GF_ASSERT(FALSE);
        return 0;
    }
    return data->roundEvents[index];
}

u32 PokeathlonCourse_FindCourseId(PokeathlonCourseData *data) {
    u8 i, j, numParticipants;
    BOOL flag = (PokeathlonCourse_GetMode(data) == 1);
    u32 *fieldPtr = data->roundEvents;
    numParticipants = flag ? 4 : 3;

    for (i = 0; i < 10; i++) {
        BOOL match = TRUE;
        for (j = 0; j < numParticipants; j++) {
            if (fieldPtr[j] != gPokeathlonCourseEventIds[i * 4 + j]) {
                match = FALSE;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    return 10;
}

u32 PokeathlonCourse_GetRound(PokeathlonCourseData *data) {
    return data->round;
}

u32 PokeathlonCourse_GetMode(PokeathlonCourseData *data) {
    return data->args->mode;
}

u8 PokeathlonCourse_GetReceivedCount(PokeathlonCourseData *data) {
    return data->receivedCount;
}

void PokeathlonCourse_IncrementReceivedCount(PokeathlonCourseData *data) {
    data->receivedCount++;
}

void PokeathlonCourse_ResetReceivedCount(PokeathlonCourseData *data) {
    data->receivedCount = 0;
}

struct PokeathlonCourseLink *PokeathlonCourse_GetSystem(PokeathlonCourseData *data) {
    return data->system;
}

int PokeathlonCourse_GetNetId(PokeathlonCourseData *data) {
    return PokeathlonCourseLink_GetNetId(data->system);
}

PlayerProfile *PokeathlonCourse_GetPlayerProfileFromData(PokeathlonCourseData *data, int index) {
    return PokeathlonCourse_GetPlayerProfile(data->playerProfiles, index);
}

PokeathlonStatistics *PokeathlonCourse_GetRecord(PokeathlonCourseData *data, int index) {
    return &data->records[index];
}

u8 *PokeathlonCourse_GetDataCopyArea(PokeathlonCourseData *data) {
    return data->dataCopySource;
}

void PokeathlonCourse_ResetDataCopyArea(PokeathlonCourseData *data) {
    // Look like it's filling dataCopySource + dataCopyBuffer1 + dataCopyBuffer2 + filler_304 + eventDataTransfer
    MI_CpuFill8(data->dataCopySource, 0, 296);
}

void PokeathlonCourse_SetEventDataTransfer(PokeathlonCourseData *data, u32 a0, u32 a1, u32 a2) {
    data->eventDataTransfer[0] = a0;
    data->eventDataTransfer[1] = a1;
    data->eventDataTransfer[2] = a2;
    data->eventDataTransfer[3] = 1;
}

void PokeathlonCourse_ClearEventDataTransfer(PokeathlonCourseData *data) {
    data->eventDataTransfer[0] = 0;
    data->eventDataTransfer[1] = 0;
    data->eventDataTransfer[2] = 0;
    data->eventDataTransfer[3] = 0;
}

u32 PokeathlonCourse_GetEventRecvBuffer(PokeathlonCourseData *data) {
    return data->eventDataTransfer[1];
}

u32 PokeathlonCourse_GetEventResultSize() {
    return 4; // might be max participants or something; needs to see where it's called
}

void PokeathlonCourse_SetEventScore(PokeathlonCourseData *data, int index, u16 value) {
    data->eventResults[index][0] = value;
}

u16 PokeathlonCourse_GetReceivedScore(PokeathlonCourseData *data, int index) {
    return data->receivedResults[index][0];
}

void PokeathlonCourse_SetNextState(PokeathlonCourseData *data, u8 value) {
    GF_ASSERT(data->courseState.exitFlag != 1);
    data->courseState.exitFlag = 1;
    data->courseState.argsPtr->nextStateIndex = value;
}

void PokeathlonCourse_SetNextStateIfNot(PokeathlonCourseData *data, u8 value, u8 value2) {
    if (data->courseState.argsPtr->nextStateIndex != value2) {
        GF_ASSERT(data->courseState.exitFlag != 1);
        data->courseState.exitFlag = 1;
        data->courseState.argsPtr->nextStateIndex = value;
    }
}

void PokeathlonCourse_SetStateTransitionType(PokeathlonCourseData *data, u32 transitionType) {
    if (data->args->mode == 1) {
        data->courseState.transitionType = transitionType;
    }
}

void PokeathlonCourse_SetVBlankIntrCB(PokeathlonCourseData *data) {
    Main_SetVBlankIntrCB(PokeathlonCourse_VBlankCallback, data);
}

struct PokeathlonCourseScoreList *PokeathlonCourse_GetGraphicsSystem(PokeathlonCourseData *data) {
    return data->graphicsSystem;
}
