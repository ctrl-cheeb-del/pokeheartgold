#ifndef POKEHEARTGOLD_FIELD_EFFECT_ANIMATION_INTERNAL_H
#define POKEHEARTGOLD_FIELD_EFFECT_ANIMATION_INTERNAL_H

#include "global.h"

#include "constants/sndseq.h"
typedef struct Vec3 {
    s32 x, y, z;
} Vec3;
typedef struct Vec4 {
    s32 x, y, z, w;
} Vec4;
extern void *ov01_021F1430();
extern void ov01_021F1448();
extern void *ov01_021F146C();
extern void *ov01_021F1450();
extern void ov01_021F18D4();
extern void ov01_021F1908();
extern void ov01_021F1930();
extern void ov01_021F1758();
extern void ov01_021F18FC();
extern void ov01_021F1924();
extern void ov01_021F1970();
extern void ov01_021F18C8();
extern void *ov01_021F1740();
extern void *sub_02023F90();
extern void NNS_G3dMdlSetMdlFogEnableFlagAll();
extern u8 *sub_02068D74();
extern void sub_02023EA4();
extern Vec4 *sub_02068D98();
extern void sub_02068DB8();
extern int sub_02068D90();
extern void sub_02068DA8();
extern void *sub_02023DA4();
extern void sub_02023E50();
extern void PlaySE();
extern void MapObject_CopyPositionVector();
extern void MapObject_CopyFacingVector();
extern void VEC_Add();
extern int MapObject_GetPriority();
extern void ov01_021F1620();
extern int MapObject_GetID();
extern int MapObject_GetMapID();
extern int sub_0205F0A8();
extern void ov01_021F93AC();
extern void GF_AssertFail(void);
extern const int ov01_022092C0[2];
extern const u8 ov01_022092DC[];
extern const u8 ov01_022092F0[];
typedef struct Work Work;
void *ov01_022001E4(void *);
void ov01_022001F8(Work *);
void ov01_02200208(Work *);
void ov01_02200210(Work *);
void ov01_02200220(Work *);
void ov01_02200228(Work *);
void ov01_02200238(Work *, int);
void ov01_0220024C(Work *, int);
void ov01_02200260(Work *);
void ov01_022002AC(Work *);
void ov01_022002FC(Work *);
void ov01_0220032C(Work *);
void ov01_0220035C(Work *);
void ov01_0220036C(Work *);
void ov01_0220037C(Work *);
void ov01_0220038C(Work *);
void ov01_0220039C(Work *, int);
void ov01_022003B0(Work *, int);
void *ov01_022003C4(void *, int, Vec3 *);
void *ov01_022003F4(void);
void ov01_02200400(void);
typedef struct AnimWork AnimWork;
int ov01_02200418(void *, AnimWork *);
void ov01_02200480(void *, AnimWork *);
void ov01_022004EC(void *, AnimWork *);
void ov01_02200508(void *, AnimWork *);
int ov01_02200540(void *, int, int);
int ov01_0220059C(void *, AnimWork *);
void ov01_02200614(void *, AnimWork *);

#endif
