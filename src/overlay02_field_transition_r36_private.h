#ifndef OVERLAY02_FIELD_TRANSITION_R36_PRIVATE_H
#define OVERLAY02_FIELD_TRANSITION_R36_PRIVATE_H
#include "global.h"

#include "constants/sndseq.h"

typedef struct R36Work {
    s32 state;
    s32 counter;
    u32 hasFollower;
    u32 warpId;
    void *playerMovement;
    void *followerMovement;
    u32 unk18;
    void *effect;
    void *playerObject;
    void *unk24;
    u32 unk28;
    void *unk2C;
} R36Work;

typedef struct R36FieldSystem {
    u8 pad00[0xC];
    void *saveData;
    u8 pad10[0x30];
    void *playerAvatar;
    u8 pad44[0xA0];
    void *mapObjectManager;
} R36FieldSystem;

typedef struct R36WarpData {
    u8 raw[0x14];
} R36WarpData;
typedef struct R36MovementScriptCommand R36MovementScriptCommand;
typedef struct R36MovementManager R36MovementManager;
extern const R36MovementScriptCommand ov02_02253770[];
extern const R36MovementScriptCommand ov02_02253794[];
extern const R36MovementScriptCommand ov02_022537B8[];
extern const R36MovementScriptCommand ov02_022537DC[];
extern const R36MovementScriptCommand ov02_02253820[];
void *ov01_021FCD2C(void *, int);
void ov01_021FCD8C(void *, int, u32, int);
void ov01_021FCD78(void *);
R36MovementManager *EventObjectMovementMan_Create(void *, const R36MovementScriptCommand *);
BOOL EventObjectMovementMan_IsFinish(R36MovementManager *);
void EventObjectMovementMan_Delete(R36MovementManager *);
void *Save_LocalFieldData_Get(void *);
void *LocalFieldData_GetBlackoutSpawn(void *);
void *LocalFieldData_GetSpecialSpawnWarpPtr(void *);
void GetFlyWarpData(void *, R36WarpData *);
void GetSpecialSpawnWarpData(void *, void *);
void sub_02053B04(void *, R36WarpData *, u32);
int PlayerAvatar_GetState(void *);
void *ov02_0224DDE0(void *);
void *ov02_0224DDF4(void *);
void ov02_0224DE08(void *);
void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
BOOL IsPaletteFadeFinished(void);
void PlaySE(u32);
int ov02_0224C698(void *, R36FieldSystem *, R36Work *);
int ov02_0224C6DC(void *, R36FieldSystem *, R36Work *);
int ov02_0224C71C(void *, R36FieldSystem *, R36Work *);
int ov02_0224C75C(void *, R36FieldSystem *, R36Work *);
int ov02_0224C7D4(void *, R36FieldSystem *, R36Work *);
int ov02_0224C840(void *, R36FieldSystem *, R36Work *);
int ov02_0224C87C(void *, R36FieldSystem *, R36Work *);
int ov02_0224C8D0(void *, R36FieldSystem *, R36Work *);
int ov02_0224C93C(void *, R36FieldSystem *, R36Work *);
int ov02_0224C9B8(void *, R36FieldSystem *, R36Work *);
#endif
