#ifndef POKEHEARTGOLD_MAP_OBJECT_TRAINER_BEHAVIOR_INTERNAL_H
#define POKEHEARTGOLD_MAP_OBJECT_TRAINER_BEHAVIOR_INTERNAL_H
#include "global.h"

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
typedef char AssertAppriSize[(sizeof(AppriState) == 0x18) ? 1 : -1];
typedef char AssertAppriPointer[(offsetof(AppriState, unk8) == 8) ? 1 : -1];

typedef struct Unk394 {
    u16 unk0;
    u16 unk2;
} Unk394;

typedef struct FsysPriv {
    u8 pad00[0xc];
    void *unkC;
    u8 pad10[0x3c - 0x10];
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

extern void *sub_0205F398(LMO *obj, int size);
extern void *sub_0205F3BC(LMO *obj);
extern void *sub_0205F3E8(LMO *obj, int size);
extern void sub_0205F484(LMO *obj);
extern Unk394 *sub_0205F394(LMO *obj);
extern AppriState *sub_0205F40C(LMO *obj);
extern int sub_0205F330(LMO *obj);
extern int MapObject_GetParam(LMO *obj, int idx);
extern int MapObject_GetType(LMO *obj);
extern int MapObject_GetFacingDirection(LMO *obj);
extern void MapObject_SetFacingDirection(LMO *obj, int dir);
extern int MapObject_CheckSingleMovement(LMO *obj);
extern void MapObject_ForceSetHeldMovement(LMO *obj, int mv);
extern void MapObject_SetSpriteID(LMO *obj, u32 id);
extern void MapObject_SetFlagsBits(LMO *obj, u32 bits);
extern void MapObject_ClearFlagsBits(LMO *obj, u32 bits);
extern FSYS *MapObject_GetFieldSystem(LMO *obj);
extern int MapObject_GetScriptID(LMO *obj);
extern int MapObject_GetTrainerNum(LMO *obj);
extern int sub_02063A94(LMO *obj);
extern int sub_02063AC8(LMO *obj);
extern int sub_0206234C(int a0, int a1);
extern int sub_02062428(LMO *obj);
extern void GF_AssertFail(void);
extern int sub_02055780(FSYS *fsys, LMO *obj);
extern int FieldSystem_ApricornTree_TryGetApricorn(FSYS *fsys, LMO *obj);
extern int ov01_021FA2D4(LMO *obj);
extern void ov01_021F94C0(LMO *obj, void *a1, u32 a2);
extern void ov01_021F95CC(LMO *obj, void *a1, u32 a2);
extern void ov01_021F9610(void *a0, void *a1);
extern void ov01_021F9630(void *a0, void *a1);
extern void ov01_021FE66C(LMO *obj);
extern void ov01_021FA3E8(LMO *obj, void *a1);
extern int ov01_021F9344(LMO *obj);
extern void ov01_021FA40C(LMO *obj, void *a1);
extern int sub_02023EF4(void *a0);
extern void sub_02023EE0(void *a0, int a1);
extern void sub_02023F40(void *a0, int a1);
extern void sub_02023F04(void *a0, int a1);
extern void StartMapSceneScript(FSYS *fsys, int scr, LMO *obj);
extern void FieldSystem_SetEngagedTrainer(FSYS *fsys, LMO *obj, int x, int z, int scriptId, int trainerNum, int a6, int a7);
extern LMO *MapObjectManager_GetNextObjectWithFlagFromIndex(MOM *man, LMO **outObj, int *outIdx, int flag);
extern int TrainerFlagCheck(void *save, u16 trainerNum);
extern int ScriptNumToTrainerNum(u16 scriptNum);
extern int TrainerNumIsDouble(u16 trainerNum);
extern int sub_02064520(FSYS *fsys, MOM *man, LMO *obj, int trainerNum);
extern int sub_02064468(LMO *obj, int dir, int dist);
extern int PlayerAvatar_GetXCoord(PAV *pav);
extern int PlayerAvatar_GetZCoord(PAV *pav);
extern u32 ov01_02207274[];
extern int (*const _020FE194[])(LMO *obj, int a2, int a3, int a4, int a5);

void sub_02063AFC(LMO *obj);
int sub_02063B00(LMO *obj);
int sub_02063B04(LMO *obj);
void sub_02063B08(LMO *obj);
BOOL sub_02063B20(LMO *obj);
BOOL sub_02063B9C(LMO *obj);
void sub_02063C88(LMO *obj);
BOOL sub_02063CB4(LMO *obj);
BOOL sub_02063D30(LMO *obj);
void sub_02063E50(LMO *obj);
void sub_02063E70(LMO *obj);
void sub_02063FE4(LMO *obj);
void sub_02063FFC(LMO *obj);
void sub_0206402C(LMO *obj);
void *sub_02064084(LMO *obj);
u32 sub_020640A4(int a0, int a1);
BOOL TryGetSeenByNpcTrainers(FSYS *fsys, BOOL doublesEligible);
BOOL CheckSeenByNpcTrainers(FSYS *fsys, MOM *man, PAV *pav, LMO *exclude, EngageParams *out);
void GetEngagingTrainerParams(EngageParams *out, LMO *obj, int x, int z);
int sub_02064298(LMO *obj);
int sub_020642C4(LMO *obj, PAV *pav, int *outDir);
int sub_0206439C(LMO *obj, int dir, int a2, int a3, int a4, int a5);

#endif
