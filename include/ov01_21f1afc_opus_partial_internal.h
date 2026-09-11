#ifndef PRIVATE_OV01_021F1AFC_H
#define PRIVATE_OV01_021F1AFC_H

#include "global.h"

#include "constants/heap.h"
#include "constants/sndseq.h"

#include "metatile_behavior.h"
#include "overlay_01.h"
#include "overlay_01_021F1AFC.h"

struct SurfWork {
    int unk0;
    u32 gender;
    u32 unk8;
    void *unkC;
};

struct RockClimbWork {
    u16 state;
    u16 unk2;
    int direction;
    u32 unk8;
    FieldSystem *fieldSystem;
    PlayerAvatar *playerAvatar;
    LocalMapObject *obj;
    u32 unk18;
    struct SurfWork surf;
    u32 unk2c;
};

struct WaterfallWork {
    int state;
    int direction;
    u32 filler08[11];
    FieldSystem *fieldSystem;
    PlayerAvatar *playerAvatar;
    LocalMapObject *obj;
    struct SurfWork surf;
    void *unk50;
};

struct SurfTaskWork {
    int state;
    int direction;
    u32 unk8;
    struct SurfWork surf;
    FieldSystem *fieldSystem;
    PlayerAvatar *playerAvatar;
    LocalMapObject *obj;
    u32 unk28;
};

struct SavingWork {
    int unk0;
    int state;
    FieldSystem *fieldSystem;
    PlayerAvatar *playerAvatar;
};

/* Module-internal helpers (defined later in this file / in the original module). */
void ov01_021F3084(PlayerAvatar *playerAvatar, u32 sprite);
void *ov01_021F30D0(u32 size);
void ov01_021F30F4(void *env);
LocalMapObject *ov01_021F3094(PlayerAvatar *playerAvatar, int direction);
void *ov01_021F3100(FieldSystem *fieldSystem, int partySlot);
void ov01_021F3040(FieldSystem *fieldSystem, u32 a1, struct SurfWork *work);
void ov01_021F3030(SysTask *task, void *data);
void ov01_021F3054(FieldSystem *fieldSystem, struct SurfWork *work);
BOOL ov01_021F3068(struct SurfWork *work);

/* Module functions used before their definitions. */
void ov01_021F1B38(PlayerAvatar *playerAvatar);
BOOL ov01_021F1DF4(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int a2, int a3);
BOOL ov01_021F1E54(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int a2, int a3);
void ov01_021F1EA4(int a0, FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, LocalMapObject *obj);
BOOL ov01_021F1ECC(TaskManager *taskManager);
BOOL ov01_021F1F8C(FieldSystem *fieldSystem, LocalMapObject *obj);
BOOL ov01_021F2004(TaskManager *taskManager, FieldSystem *fieldSystem, LocalMapObject *obj);
void ov01_021F202C(FieldSystem *fieldSystem, int a1, struct SurfWork *a2);
BOOL ov01_021F2118(TaskManager *taskManager);
BOOL ov01_021F232C(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int a2, int a3);
BOOL ov01_021F24F4(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int a2, int a3);
BOOL ov01_021F2538(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int a2);

/* External helpers with no tracked prototype reachable from here. */
void ov01_021F1640(int a0);
u32 ov01_021FE7DC(LocalMapObject *obj, u32 x, u32 y, u32 dir, u32 a4);
int sub_0205DEC0(PlayerAvatar *avatar, int direction);
BOOL sub_0205DE38(PlayerAvatar *avatar);
u32 sub_0206234C(int direction, int a1);
u32 sub_02060BB8(LocalMapObject *object, int direction);
int ov01_022062CC(FieldSystem *fieldSystem);

extern void (*const sPlayerAvatarBitUpdateFuncs[15])(PlayerAvatar *);

void ov01_021F1B78(PlayerAvatar *playerAvatar);
void ov01_021F1BC0(PlayerAvatar *playerAvatar);
void ov01_021F1C30(PlayerAvatar *playerAvatar);
void ov01_021F1C70(PlayerAvatar *playerAvatar);
void ov01_021F1C7C(PlayerAvatar *playerAvatar);
void ov01_021F1C98(PlayerAvatar *playerAvatar);
void ov01_021F1CB4(PlayerAvatar *playerAvatar);
void ov01_021F1CD0(PlayerAvatar *playerAvatar);
void ov01_021F1CEC(PlayerAvatar *playerAvatar);
void ov01_021F1D08(PlayerAvatar *playerAvatar);
void ov01_021F1D24(PlayerAvatar *playerAvatar);
void ov01_021F1D40(PlayerAvatar *playerAvatar);
void ov01_021F1D5C(PlayerAvatar *playerAvatar);
void ov01_021F1D78(PlayerAvatar *playerAvatar);
int sub_0205CBE4(PlayerAvatar *avatar, int a1);

void PlaySE(u16 seq);

void ov01_021FA930(LocalMapObject *obj, u32 sprite);
void sub_0205F484(LocalMapObject *obj);
void *ov02_02249458(FieldSystem *fieldSystem, int a1, u32 a2, u32 a3);
BOOL ov02_0224953C(void *a0);
void ov02_02249548(void *a0);

int GetDeltaXByFacingDirection(int direction);
int GetDeltaYByFacingDirection(int direction);

int ov01_021F2694(struct RockClimbWork *work, TaskManager *taskManager);
int ov01_021F26AC(struct RockClimbWork *work, TaskManager *taskManager);
int ov01_021F2E08(struct WaterfallWork *work, TaskManager *taskManager);
int ov01_021F2E20(struct WaterfallWork *work, TaskManager *taskManager);
int ov01_021F2E38(struct WaterfallWork *work, TaskManager *taskManager);
BOOL MetatileBehavior_IsRockClimbNorthSouth(u8 tile);
BOOL MetatileBehavior_IsRockClimbEastWest(u8 tile);
BOOL FollowMon_IsActive(FieldSystem *fieldSystem);
LocalMapObject *FollowMon_GetMapObject(FieldSystem *fieldSystem);
void MapObject_UnpauseMovement(LocalMapObject *obj);
void *ov02_0224D67C(FieldSystem *fieldSystem);
BOOL MapObject_AreBitsSetForMovementScriptInit(LocalMapObject *obj);

int ov01_021F2734(struct RockClimbWork *work, TaskManager *taskManager);
int ov01_021F27C0(struct RockClimbWork *work, TaskManager *taskManager);
int ov01_021F27E8(struct RockClimbWork *work, TaskManager *taskManager);
int ov01_021F2808(struct RockClimbWork *work, TaskManager *taskManager);
int ov01_021F2894(struct RockClimbWork *work, TaskManager *taskManager);
void ov01_021F28EC(FieldSystem *fieldSystem, u32 a1);
void *ov01_021F28B8(FieldSystem *fieldSystem, int a1, struct SurfWork *a2);
BOOL ov01_021F2944(TaskManager *taskManager);
int ov01_021F2E6C(struct WaterfallWork *work, TaskManager *taskManager);
int ov01_021F2998(struct WaterfallWork *work, TaskManager *taskManager);
int ov01_021F29C0(struct WaterfallWork *work, TaskManager *taskManager);
int ov01_021F2B80(struct WaterfallWork *work, TaskManager *taskManager);
int ov01_021F2BA4(struct WaterfallWork *work, TaskManager *taskManager);
BOOL IsCryFinished(void);
void ov01_02205EE0(TaskManager *taskManager);
void MapObject_SetHeldMovement(LocalMapObject *obj, u32 movement);
BOOL MapObject_IsMovementPaused(LocalMapObject *obj);
void MapObject_ClearHeldMovementIfActive(LocalMapObject *obj);
void ov01_021FEB30(u32 a0, int a1);

typedef int (*StepFunc)(void *work, TaskManager *taskManager);
typedef int (*StepFunc1)(void *work);
int ov01_021F26CC(void *work, TaskManager *taskManager);
int ov01_021F2700(void *work, TaskManager *taskManager);
int ov01_021F2758(void *work, TaskManager *taskManager);
int ov01_021F2830(void *work, TaskManager *taskManager);
int ov01_021F29E4(void *work, TaskManager *taskManager);
int ov01_021F2AB8(void *work, TaskManager *taskManager);
int ov01_021F2AF8(void *work, TaskManager *taskManager);
int ov01_021F2BC8(void *work, TaskManager *taskManager);
int ov01_021F2C88(void *work, TaskManager *taskManager);
int ov01_021F2CD4(void *work, TaskManager *taskManager);
int ov01_021F2E94(struct WaterfallWork *work);
void ov01_021F2548(FieldSystem *fieldSystem, int a1, struct SurfWork *a2);
void ov01_021F2D68(FieldSystem *fieldSystem, int a1, struct SurfWork *a2);
int ov01_021F2DD0(TaskManager *taskManager);
int ov01_021F2628(TaskManager *taskManager);
void ov01_021F2EDC(PlayerAvatar *playerAvatar);
u32 MapObject_GetSpriteID(LocalMapObject *obj);
SysTask *SysTask_CreateOnMainQueue(void (*func)(SysTask *, void *), void *data, u32 priority);
BOOL sub_0205F73C(LocalMapObject *obj);
u32 MapObject_GetNextFacingDirection(LocalMapObject *obj);
BOOL MetatileBehavior_IsWhirlpool(u8 tile);
void ov02_0224D690(void *a0);
extern const StepFunc ov01_02206994[5];
extern const StepFunc ov01_022069A8[5];
extern const StepFunc ov01_022069BC[5];
extern const StepFunc ov01_022069D0[8];
extern const StepFunc ov01_022069F0[9];
extern const u16 ov01_02206A14[4][5];

#endif
