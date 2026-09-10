#ifndef POKEHEARTGOLD_TRAINER_TURN_SEQUENCE_INTERNAL_H
#define POKEHEARTGOLD_TRAINER_TURN_SEQUENCE_INTERNAL_H
#include "global.h"

#include "constants/std_script.h"

typedef struct LMO LMO;
typedef struct MOM MOM;
typedef struct PAV PAV;
typedef struct FSYS FSYS;

typedef struct TrState {
    u8 unk0;
    u8 unk1;
    s8 unk2;
    s8 unk3;
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s8 unk8;
} TrState;

typedef struct AppriState {
    u32 unk0;
    u32 unk4;
    void *unk8;
    u8 unkC[0x0C];
} AppriState;

typedef struct FsysPriv {
    u8 pad00[0x0C];
    void *unkC;
    u8 pad10[0x2C];
    MOM *unk3C;
    PAV *unk40;
} FsysPriv;

typedef struct EngageParams {
    int x;
    int z;
    int scriptId;
    int trainerNum;
    int isDouble;
    LMO *obj;
} EngageParams;

typedef struct FourValues {
    u32 values[4];
} FourValues;

typedef struct TwoByTwoValues {
    u32 values[2][2];
} TwoByTwoValues;

typedef char AssertAppriStateSize[(sizeof(AppriState) == 0x18) ? 1 : -1];
typedef char AssertEngageParamsSize[(sizeof(EngageParams) == 0x18) ? 1 : -1];
typedef char AssertFsysObjects[(offsetof(FsysPriv, unk3C) == 0x3C) ? 1 : -1];
typedef char AssertFsysAvatar[(offsetof(FsysPriv, unk40) == 0x40) ? 1 : -1];

extern const FourValues _020FE0C4;
extern const TwoByTwoValues _020FE0D4;
extern void *sub_0205F3BC(LMO *obj);
extern int MapObject_GetFacingDirection(LMO *obj);
extern void MapObject_ForceSetHeldMovement(LMO *obj, int movement);
extern void MapObject_SetFacingDirection(LMO *obj, int direction);
extern int sub_0206234C(int movement, int param);
extern int sub_02062428(LMO *obj);
extern BOOL CheckSeenByNpcTrainers(FSYS *fsys, MOM *manager, PAV *avatar, LMO *exclude, EngageParams *out);
extern void GetEngagingTrainerParams(EngageParams *out, LMO *obj, int x, int z);
extern void StartMapSceneScript(FSYS *fsys, int script, LMO *obj);
extern void FieldSystem_SetEngagedTrainer(FSYS *fsys, LMO *obj, int x, int z, int scriptId, int trainerNum, int mode, int slot);
extern int sub_02064520(FSYS *fsys, MOM *manager, LMO *obj, int trainerNum);
extern void GF_AssertFail(void);

BOOL sub_02063B9C(LMO *obj);
BOOL TryGetSeenByNpcTrainers(FSYS *fsys, BOOL doublesEligible);

BOOL sub_02063B9C(LMO *obj);
BOOL TryGetSeenByNpcTrainers(FSYS *fsys, BOOL doublesEligible);

#endif
