#ifndef POKEHEARTGOLD_POKEATHLON_H
#define POKEHEARTGOLD_POKEATHLON_H

#include "constants/heap.h"

#include "pokeathlon/pokeathlon_save.h"

#include "overlay_manager.h"
#include "player_data.h"
#include "save.h"

typedef struct PokeathlonCourseData PokeathlonCourseData;

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

// Participant data structure (0x7C = 124 bytes each)
typedef struct PokeathlonParticipantData {
    u8 npcTeam[0x04];
    u8 mons;
    u8 field_05[0x77];
} PokeathlonParticipantData;

// Field data structure (0x60 = 96 bytes each)
typedef struct PokeathlonFieldData {
    u8 data[0x60]; // Opaque data for now
} PokeathlonFieldData;

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

// Unknown sub-structure at offset 0x974 (0x74 bytes)
typedef struct PokeathlonParticipantStats {
    u8 data[0x74]; // Opaque data for now
} PokeathlonParticipantStats;

// Pokeathlon course data structure (0xD70 = 3440 bytes)
struct PokeathlonCourseData {
    u32 field_0[4];                            // 0x000
    u8 filler_10[0x14C];                       // 0x010
    u8 field_15C;                              // 0x15C
    u8 filler_15D[0x83];                       // 0x15D
    u32 state;                                 // 0x1E0
    void *work;                                // 0x1E4 - Heap allocated pointer
    u8 filler_1E8[0x5];                        // 0x1E8
    u8 eventInitState;                              // 0x1ED
    u8 participantCount;                       // 0x1EE - Number of active participants (1-4)
    u8 receivedCount;                              // 0x1EF
    u32 round;                                 // 0x1F0
    u32 eventDrawEnabled;                             // 0x1F4
    PokeathlonCourseArgs *args;                // 0x1F8
    u8 filler_1FC[0x74];                       // 0x1FC
    void *field_270;                           // 0x270
    u8 filler_274[0x8];                        // 0x274
    u32 boxCourseId;                           // 0x27C
    OverlayManager *subOverlay;                // 0x280
    enum HeapID heapId;                        // 0x284
    struct PokeathlonCourseLink *system;       // 0x288
    u8 dataCopySource[0x28];                   // 0x28C - Source buffer for exit data copy
    u8 dataCopyBuffer1[0x28];                  // 0x2B4 - Destination buffer 1
    u8 dataCopyBuffer2[0x28];                  // 0x2DC - Destination buffer 2
    u8 filler_304[0xA0];                       // 0x304
    u32 eventDataTransfer[4];                          // 0x3A4
    PokeathlonCourseState courseState;         // 0x3B4 - State machine structure (16 bytes: 4 fields x 4 bytes)
    PokeathlonStateInfo stateInfo;             // 0x3C4 - State information (8 bytes)
    u8 filler_3CC[0xC];                        // 0x3CC
    u32 roundEvents[4];                          // 0x3D8 - Array of 4 u32s (16 bytes)
    u32 courseId;                             // 0x3E8
    PokeathlonParticipantData participants[4]; // 0x3EC - 4 participant data elements (0x7C each = 0x1F0 bytes)
    PlayerProfile *playerProfiles;             // 0x5DC - Player profiles pointer (heap allocated, 4 profiles)
    u16 eventResults[4][2];                       // 0x5E0
    u16 receivedResults[4][2];                       // 0x5F0
    u8 filler_600[0x14];                       // 0x600
    struct PokeathlonCourseScoreList *graphicsSystem; // 0x614 - Graphics/UI subsystem pointer
    u8 filler_618[0x112];                      // 0x618
    u8 maxParticipants;                        // 0x72A - Maximum participant limit (3 or 4)
    u8 filler_72B[1];                          // 0x72B
    PokeathlonFieldData fieldData[6];          // 0x72C - Array of PokeathlonFieldData (6 * 0x60 = 0x1E0 bytes)
    u8 filler_96C[8];                          // 0x96C
    PokeathlonStatistics records[4];         // 0x974 - Array of 4 unknown sub-structures (0x74 bytes each = 0x1D0 bytes)
    u8 filler_B44[0x60];                       // 0xB44
    u8 monCounters[0x180];                       // 0xBA4
    s32 frameCounter;                          // 0xD24 - Increments every 0x708 frames (max 0xEA5F)
    u16 frameTimer;                            // 0xD28 - Frame counter, resets at 0x708
    u16 filler_D2A;                            // 0xD2A - Alignment padding
    u32 counterEnabled;                        // 0xD2C - Flag to enable frame counters
    u8 filler_D30[0x34];                       // 0xD30
    void *juiceRecord;                         // 0xD64 - Heap allocated pointer (freed in Exit if mode == 0)
    void *playerJuiceRecords;                  // 0xD68 - Heap allocated pointer (freed in Exit if mode == 0)
    u8 filler_D6C[4];                          // 0xD6C
};

BOOL PokeathlonCourse_Init(OverlayManager *manager, int *state);
BOOL PokeathlonCourse_Main(OverlayManager *manager, int *state);
BOOL PokeathlonCourse_Exit(OverlayManager *manager, int *state);

BOOL PokeathlonCourse_RunStateFunc(PokeathlonCourseData *data);
BOOL PokeathlonCourse_RunSubStateLoop(PokeathlonCourseData *data);
void PokeathlonCourse_InitStateInfo(const void *funcTable, PokeathlonStateInfo *stateInfo);
void PokeathlonCourse_InitPlayerProfiles(PokeathlonCourseData *data);
PlayerProfile *PokeathlonCourse_GetPlayerProfile(PlayerProfile *profiles, int index);
u8 PokeathlonCourse_GetParticipantCount(PokeathlonCourseData *data);
PokeathlonParticipantData *PokeathlonCourse_GetParticipantData(PokeathlonCourseData *data, int index);
u8 *PokeathlonCourse_GetParticipantMons(PokeathlonCourseData *data, int index);
SaveData *PokeathlonCourse_GetSaveData(PokeathlonCourseData *data);
PokeathlonFieldData *PokeathlonCourse_GetFieldData(PokeathlonCourseData *data);
PokeathlonFieldData *PokeathlonCourse_GetFieldData_AtIndex(PokeathlonCourseData *data, int index);
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
void PokeathlonCourse_SetEventDataTransfer(PokeathlonCourseData *data, u32 a0, u32 a1, u32 a2);
void PokeathlonCourse_ClearEventDataTransfer(PokeathlonCourseData *data);
u32 PokeathlonCourse_GetEventRecvBuffer(PokeathlonCourseData *data);
u32 PokeathlonCourse_GetEventResultSize();
void PokeathlonCourse_SetEventScore(PokeathlonCourseData *data, int index, u16 value);
u16 PokeathlonCourse_GetReceivedScore(PokeathlonCourseData *data, int index);
void PokeathlonCourse_SetNextState(PokeathlonCourseData *data, u8 value);
void PokeathlonCourse_SetNextStateIfNot(PokeathlonCourseData *data, u8 value, u8 value2);
void PokeathlonCourse_SetStateTransitionType(PokeathlonCourseData *data, u32 transitionType);
void PokeathlonCourse_SetVBlankIntrCB(PokeathlonCourseData *data);
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
