#ifndef OV01_021FEA0C_PRIVATE_H
#define OV01_021FEA0C_PRIVATE_H
#include <string.h>

#include "global.h"
typedef struct Vec3 {
    s32 x, y, z;
} Vec3;
typedef struct Copy20 {
    u32 v[5];
} Copy20;
typedef struct SpawnSmall {
    u32 kind;
    void *ctx;
    void *fieldSystem;
    void *member;
    void *mapObj;
} SpawnSmall;
typedef struct Rot9 {
    s32 v[9];
} Rot9;
typedef struct EffectCtx {
    u8 raw[0x28];
} EffectCtx;
typedef struct EffectWork {
    s32 state;
    s32 dir;
    s32 counter;
    u8 pad[0x10];
    EffectCtx *ctx;
} EffectWork;
extern void *ov01_021F1430(u32, u32, u32, u32);
extern void ov01_021F1448(void *);
extern void GF_AssertFail(void);
extern void ov01_021F19F4(void *, void *, u32, u32, u32);
extern void sub_02069978(void *, void *);
extern void sub_02069784(void *);
extern void *sub_02068D74(void *);
extern Copy20 *sub_02068D98(void *);
extern void *sub_02068D90(void *);
extern void sub_02068DA8(void *, Vec3 *);
extern void sub_0205F9A0(void *, Vec3 *);
extern void MapObject_CopyPositionVector(void *, Vec3 *);
extern void *ov01_021F146C(void *);
extern void *MapObject_GetFieldSystem(void *);
extern void *ov01_021F1450(void *, u32);
extern void sub_0206121C(void *, Vec3 *);
extern s32 MapObject_GetPriorityPlusValue(void *, s32);
extern void ov01_021F1620(void *, const void *, Vec3 *, u32, SpawnSmall *, s32);
extern const u8 ov01_022090FC[];
extern const Vec3 ov01_022090F0;
extern void sub_02020DA4(Rot9 *, u16, u16, u16);
extern void sub_020699AC(void *, Vec3 *, Vec3 *, Rot9 *);
extern void sub_02068DB8(void *, Vec3 *);
void *ov01_021FEA0C(u32);
void ov01_021FEA20(void *);
void ov01_021FEA30(void *);
void ov01_021FEA38(void *);
void ov01_021FEA48(void *);
void ov01_021FEA7C(void *);
void ov01_021FEA90(void *);
void ov01_021FEAA0(void *);
void ov01_021FEB30(void *, void *);
BOOL ov01_021FEB3C(void *, void *);
void ov01_021FEB78(void *, void *);
void ov01_021FEB8C(void *, void *);
void ov01_021FEAB0(void *, s32, s32, u32, u32);
void ov01_021FEBC0(void *task, EffectWork *data);
#endif
