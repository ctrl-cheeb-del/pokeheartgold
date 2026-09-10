#ifndef GUARD_OV01_021FC66C_PRIVATE_H
#define GUARD_OV01_021FC66C_PRIVATE_H

// global.h is what puts the compiler in Thumb mode: it includes <nitro/code16.h>,
// which is a bare `#pragma thumb on`. It also supplies u8/s16/u32/BOOL/TRUE/FALSE,
// NULL (stddef.h), memset (string.h) and GF_AssertFail (assert.h -> error_handling.h),
// so none of those are declared privately here.
#include "global.h"

#include "constants/heap.h"

#ifndef SEQ_SE_DP_FW104
#define SEQ_SE_DP_FW104 1615
#endif
#ifndef GAME_STAT_FISH_LANDED
#define GAME_STAT_FISH_LANDED 11
#endif
#ifndef GAME_STAT_UNK101
#define GAME_STAT_UNK101 0x65
#endif

typedef struct PlayerAvatar PlayerAvatar;
typedef struct LocalMapObject LocalMapObject;
typedef struct MapObjectManager MapObjectManager;
typedef struct BattleSetup BattleSetup;
typedef struct TaskManager TaskManager;
typedef struct SysTask SysTask;
typedef struct SaveData SaveData;
typedef struct GameStats GameStats;
typedef struct BgConfig BgConfig;
typedef struct Options Options;
typedef struct String String;
typedef struct MsgData MsgData;
typedef struct MessageFormat MessageFormat;
typedef struct Pokemon Pokemon;
typedef struct Party Party;
typedef struct GearPhoneRingManager GearPhoneRingManager;
typedef struct FieldSystemUnkSub108 FieldSystemUnkSub108;

typedef struct FieldSystem {
    u8 pad_00[0x8];
    BgConfig *bgConfig; // 0x08
    SaveData *saveData; // 0x0C
    u8 pad_10[0x3C - 0x10];
    MapObjectManager *mapObjectManager; // 0x3C
    PlayerAvatar *playerAvatar;         // 0x40
    u8 pad_44[0x108 - 0x44];
    FieldSystemUnkSub108 *unk108; // 0x108
} FieldSystem;

typedef struct Window {
    u8 dummy[0x10];
} Window;

// SysTask environment for the fishing rod animation, 0x4C bytes.
typedef struct FishingRodEnv {
    u32 hooked;               // 0x00
    BOOL finished;            // 0x04
    BOOL result;              // 0x08
    u32 state;                // 0x0C
    s32 timer;                // 0x10
    s32 counter1;             // 0x14
    s32 counter2;             // 0x18
    u32 rodType;              // 0x1C
    FieldSystem *fieldSystem; // 0x20
    int effect;               // 0x24
    u8 printHandle;           // 0x28
    u8 pad_29[3];
    String *strExpanded;   // 0x2C
    String *strRaw;        // 0x30
    MessageFormat *msgFmt; // 0x34
    Window window;         // 0x38
    MsgData *msgData;      // 0x48
} FishingRodEnv;

// Task environment for Task_OverworldFish, 0x18 bytes.
typedef struct FishingRodTaskEnv {
    u32 state;                // 0x00
    u32 msgId;                // 0x04
    BOOL hooked;              // 0x08
    u32 rodType;              // 0x0C
    BattleSetup *battleSetup; // 0x10
    SysTask *task;            // 0x14
} FishingRodTaskEnv;

struct System {
    u8 pad_00[0x48];
    u32 heldKeys; // 0x48
};
extern struct System gSystem;

void *Heap_AllocAtEnd(u32 heapId, u32 size);
void Heap_Free(void *ptr);
u16 LCRandom(void);
void PlaySE(u16 seq);
s32 _s32_div_f(s32 num, s32 den);

FieldSystem *TaskManager_GetFieldSystem(TaskManager *taskMan);
void *TaskManager_GetEnvironment(TaskManager *taskMan);

void MapObjectManager_PauseAllMovement(MapObjectManager *manager);
void MapObjectManager_UnpauseAllMovement(MapObjectManager *manager);
BOOL FieldSystem_PerformFishEncounterCheck(FieldSystem *fieldSystem, u32 rodType, BattleSetup **pBattleSetup);
void FieldSystem_StartForcedWildBattle(FieldSystem *fieldSystem, TaskManager *taskMan, BattleSetup *setup);
GearPhoneRingManager *FieldSystem_GetGearPhoneRingManager(FieldSystem *fieldSystem);
void GearPhoneRingManager_ResetIfActive(GearPhoneRingManager *manager);
GameStats *Save_GameStats_Get(SaveData *saveData);
void GameStats_Inc(GameStats *stats, u32 statId);
void BattleSetup_Delete(BattleSetup *setup);

SysTask *SysTask_CreateOnMainQueue(void (*func)(SysTask *, void *), void *data, u32 priority);
void *SysTask_GetData(SysTask *task);
void SysTask_Destroy(SysTask *task);

LocalMapObject *PlayerAvatar_GetMapObject(PlayerAvatar *avatar);
u32 PlayerAvatar_GetState(PlayerAvatar *avatar);
u32 PlayerAvatar_GetTransitionBits(u32 state);
void Field_PlayerAvatar_OrrTransitionFlags(PlayerAvatar *avatar, u32 flags);
void Field_PlayerAvatar_ApplyTransitionFlags(PlayerAvatar *avatar);
void MapObject_UnpauseMovement(LocalMapObject *obj);
BOOL MapObject_AreBitsSetForMovementScriptInit(LocalMapObject *obj);
void MapObject_ClearHeldMovementIfActive(LocalMapObject *obj);
void sub_0205F328(LocalMapObject *obj, u32 param1);

LocalMapObject *FollowMon_GetMapObject(FieldSystem *fieldSystem);
BOOL FollowMon_IsActive(FieldSystem *fieldSystem);
s8 FieldSystem_UnkSub108_GetMonMood(FieldSystemUnkSub108 *unk);
int ov01_02200540(LocalMapObject *obj, int a0, int a1);
void ov01_02200400(int effect);
void sub_02068B48(int effect);

MsgData *NewMsgDataFromNarc(u32 type, u32 narcId, u32 fileId, u32 heapId);
void DestroyMsgData(MsgData *msgData);
void ReadMsgDataIntoString(MsgData *msgData, u32 msgId, String *dst);
String *String_New(u32 size, u32 heapId);
void String_Delete(String *str);
MessageFormat *MessageFormat_New_Custom(u32 count, u32 size, u32 heapId);
void MessageFormat_Delete(MessageFormat *fmt);
void StringExpandPlaceholders(MessageFormat *fmt, String *dst, String *src);

void DialogBox_AddWindowToLayer3(BgConfig *bgConfig, Window *window, u32 layer);
void DialogBox_LoadFrame(Window *window, Options *options);
u8 DialogBox_PrintMessage(Window *window, String *str, Options *options, u32 a3);
BOOL DialogBox_IsPrintFinished(u8 handle);
void ClearFrameAndWindow2(Window *window, u32 a1);
void RemoveWindow(Window *window);
Options *Save_PlayerData_GetOptionsAddr(SaveData *saveData);

Party *SaveArray_Party_Get(SaveData *saveData);
Pokemon *GetFirstAliveMonInParty_CrashIfNone(Party *party);
u32 GetMonData(Pokemon *mon, u32 field, void *dest);

#endif // GUARD_OV01_021FC66C_PRIVATE_H
