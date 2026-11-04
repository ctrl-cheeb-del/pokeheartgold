#ifndef POKEHEARTGOLD_POKEATHLON_H
#define POKEHEARTGOLD_POKEATHLON_H

#include "constants/heap.h"

#include "pokeathlon/pokeathlon_save.h"

#include "overlay_manager.h"
#include "player_data.h"
#include "save.h"

typedef struct PokeathlonCourseData PokeathlonCourseData;
typedef struct PokeathlonCourseMon PokeathlonCourseMon;
typedef struct PokeathlonCourseParticipant PokeathlonCourseParticipant;
typedef struct PokeathlonCourseResults PokeathlonCourseResults;

struct BgConfig;
struct PokeathlonCourseLink;
struct PokeathlonCourseScoreList;

// Function pointer types for state management
typedef BOOL (*PokeathlonStateFunc)(PokeathlonCourseData *, void **);
typedef BOOL (*PokeathlonStateHandlerFunc)(PokeathlonCourseData *, int);

// State info structure (8 bytes)
typedef struct PokeathlonStateInfo {
    void *ptr;        // 0x00 - Pointer to state function table
    u8 field_04;      // 0x04 - Field at offset 4 (initialized to 1)
    u8 stateArgsBase; // 0x05 - Base for state function args
    u8 stateIndex;    // 0x06 - State function index
    u8 nextStateIndex;      // 0x07 - Field at offset 7
} PokeathlonStateInfo;

// Pokeathlon course arguments structure
typedef struct PokeathlonCourseArgs {
    SaveData *saveData;
    u32 mode;          // 1 = link
    u16 points;        // athlete points won (out)
    u16 totalPoints;   // course total (out)
    u8 course;         // 0..4 solo courses, 5..10 link courses (10 = random events)
    u8 rank;           // (out)
    u8 shouldFreeHeap; // Flag: if 0, free heap allocations in Exit
    u8 isSupreme;      // harder NPC teams
} PokeathlonCourseArgs;

// Main state machine states
typedef enum PokeathlonCourseMainState {
    POKEATHLON_STATE_IDLE = 0,         // Idle state - waiting for transitions
    POKEATHLON_STATE_START_TRANSITION, // Start transition
    POKEATHLON_STATE_WAIT_TRANSITION,  // Wait for transition to complete
    POKEATHLON_STATE_START_EXIT,       // Start exit transition (for type 0x10)
    POKEATHLON_STATE_EXIT_SEQUENCE     // Exit sequence
} PokeathlonCourseMainState;

// State machine structure (overlays stateArgsPtr at 0x3B4)
// This struct maps to a u32 array view for code generation compatibility
typedef struct PokeathlonCourseState {
    PokeathlonStateInfo *argsPtr; // [0] 0x3B4 - Pointer to state data pointer
    u32 transitionType;           // [1] 0x3B8 - Transition type (0x10 = exit)
    u32 mainState;                // [2] 0x3BC - Main state machine state
    u32 exitFlag;                 // [3] 0x3C0 - Exit flag
} PokeathlonCourseState;

BOOL PokeathlonCourse_Init(OverlayManager *manager, int *state);
BOOL PokeathlonCourse_Main(OverlayManager *manager, int *state);
BOOL PokeathlonCourse_Exit(OverlayManager *manager, int *state);

BOOL PokeathlonCourse_RunStateFunc(PokeathlonCourseData *data);
BOOL PokeathlonCourse_RunSubStateLoop(PokeathlonCourseData *data);
void PokeathlonCourse_InitStateInfo(const void *funcTable, PokeathlonStateInfo *stateInfo);
void PokeathlonCourse_InitPlayerProfiles(PokeathlonCourseData *data);
PlayerProfile *PokeathlonCourse_GetPlayerProfile(PlayerProfile *profiles, int index);
u8 PokeathlonCourse_GetParticipantCount(PokeathlonCourseData *data);
PokeathlonCourseParticipant *PokeathlonCourse_GetParticipantData(PokeathlonCourseData *data, int index);
PokeathlonCourseMon *PokeathlonCourse_GetParticipantMons(PokeathlonCourseData *data, int index);
SaveData *PokeathlonCourse_GetSaveData(PokeathlonCourseData *data);
PokeathlonCourseResults *PokeathlonCourse_GetFieldData(PokeathlonCourseData *data);
u32 *PokeathlonCourse_GetFieldData_AtIndex(PokeathlonCourseData *data, int index);
u8 *PokeathlonCourse_GetMonCounters(PokeathlonCourseData *data);
void *PokeathlonCourse_AllocWork(PokeathlonCourseData *data, u32 size);
void PokeathlonCourse_FreeWork(PokeathlonCourseData *data);
void *PokeathlonCourse_GetWork(PokeathlonCourseData *data);
enum HeapID PokeathlonCourse_GetHeapID(PokeathlonCourseData *data);
u8 PokeathlonCourse_GetEventInitState(PokeathlonCourseData *data);
void PokeathlonCourse_SetEventInitState(PokeathlonCourseData *data, int param);
void PokeathlonCourse_AdvanceEventInitState(PokeathlonCourseData *data);
void PokeathlonCourse_SetEventDrawEnabled(PokeathlonCourseData *data, int param);
void PokeathlonCourse_SetEvents(PokeathlonCourseData *data, u8 *param);
u32 PokeathlonCourse_GetCurrentEvent(PokeathlonCourseData *data);
u32 PokeathlonCourse_GetRoundEvent(PokeathlonCourseData *data, u8 index);
u32 PokeathlonCourse_FindCourseId(PokeathlonCourseData *data);
u32 PokeathlonCourse_GetRound(PokeathlonCourseData *data);
u32 PokeathlonCourse_GetMode(PokeathlonCourseData *data);
u8 PokeathlonCourse_GetReceivedCount(PokeathlonCourseData *data);
void PokeathlonCourse_IncrementReceivedCount(PokeathlonCourseData *data);
void PokeathlonCourse_ResetReceivedCount(PokeathlonCourseData *data);
struct PokeathlonCourseLink *PokeathlonCourse_GetSystem(PokeathlonCourseData *data);
int PokeathlonCourse_GetNetId(PokeathlonCourseData *data);
PlayerProfile *PokeathlonCourse_GetPlayerProfileFromData(PokeathlonCourseData *data, int index);
PokeathlonStatistics *PokeathlonCourse_GetRecord(PokeathlonCourseData *data, int index);
u8 *PokeathlonCourse_GetDataCopyArea(PokeathlonCourseData *data);
void PokeathlonCourse_ResetDataCopyArea(PokeathlonCourseData *data);
void PokeathlonCourse_SetEventDataTransfer(PokeathlonCourseData *data, void *toSend, void *recvBuffer, u32 size);
void PokeathlonCourse_ClearEventDataTransfer(PokeathlonCourseData *data);
void *PokeathlonCourse_GetEventRecvBuffer(PokeathlonCourseData *data);
u32 PokeathlonCourse_GetEventResultSize();
void PokeathlonCourse_SetEventScore(PokeathlonCourseData *data, int index, u16 value);
u16 PokeathlonCourse_GetReceivedScore(PokeathlonCourseData *data, int index);
void PokeathlonCourse_SetNextState(PokeathlonCourseData *data, u8 value);
void PokeathlonCourse_SetNextStateIfNot(PokeathlonCourseData *data, u8 value, u8 value2);
void PokeathlonCourse_SetStateTransitionType(PokeathlonCourseData *data, u32 transitionType);
void PokeathlonCourse_SetVBlankIntrCB(struct BgConfig *bgConfig);
struct PokeathlonCourseScoreList *PokeathlonCourse_GetGraphicsSystem(PokeathlonCourseData *data);

// Internal overlay 96 functions (stubs for now, in assembly)
void PokeathlonCourse_DrawEvent(PokeathlonCourseData *data);
void PokeathlonCourse_VBlankCallback(void *);
void PokeathlonCourse_AddCapped(s32 frameCount, u32 maxValue, PokeathlonStatistics *result);
struct PokeathlonCourseLink *PokeathlonCourseLink_New(const void *commands, int count, PokeathlonCourseData *data, BOOL isLink, enum HeapID heapId);
BOOL PokeathlonCourseLink_SendCommand(int command, void *data, int size, struct PokeathlonCourseLink *linkArg);
void PokeathlonCourseLink_Free(struct PokeathlonCourseLink *ptr);
int PokeathlonCourseLink_GetNetId(struct PokeathlonCourseLink *);
u8 *PokeathlonCourse_ToBytes(void *ptr);
const void *PokeathlonCourseCmd_GetTable(void);
int PokeathlonCourseCmd_GetCount(void);
struct PokeathlonCourseScoreList *PokeathlonCourseScoreList_New(enum HeapID heapId);
void PokeathlonCourseScoreList_Free(struct PokeathlonCourseScoreList *ptr);
int PokeathlonCourseCmd_PacketSize(void);

#endif // POKEHEARTGOLD_POKEATHLON_H
