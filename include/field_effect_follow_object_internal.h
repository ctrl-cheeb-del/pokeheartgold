#ifndef POKEHEARTGOLD_FIELD_EFFECT_FOLLOW_OBJECT_INTERNAL_H
#define POKEHEARTGOLD_FIELD_EFFECT_FOLLOW_OBJECT_INTERNAL_H

/* Thumb comes from the SOURCE: global.h -> nitro/code16.h -> #pragma thumb on */
#include "global.h"

#include "map_object.h"
#include "overlay_01_021F1348.h"

/* ---- Not declared in any tracked header (private proposals) ---- */

/* 0x24-byte user-data block handed to ov01_021F1620 as a4 for bank ov01_02209138
 * and recovered via sub_02068D98 in ov01_021FF174. */
typedef struct FieldEffectFollowArgs {
    int x;                   /* 0x00 */
    int y;                   /* 0x04 */
    int z;                   /* 0x08 */
    TaskManager *taskman;    /* 0x0C */
    FieldSystem *fieldSys;   /* 0x10 */
    UnkOv01_021FFECC *unk14; /* 0x14 */
    LocalMapObject *object;  /* 0x18 */
    s16 dx;                  /* 0x1C */
    s16 dz;                  /* 0x1E */
    s8 dir;                  /* 0x20 */
} FieldEffectFollowArgs;     /* 0x24 */

/* 0x14-byte user-data block for bank ov01_0220914C (built by another overlay). */
typedef struct FieldEffectSimpleArgs {
    int x;                  /* 0x00 */
    int z;                  /* 0x04 */
    TaskManager *taskman;   /* 0x08 */
    UnkOv01_021FFECC *unkC; /* 0x0C */
    void *unk10;            /* 0x10 */
} FieldEffectSimpleArgs;    /* 0x14 */

typedef struct FieldEffectFollowWork {
    int state;                  /* 0x00 */
    u32 spriteId;               /* 0x04 */
    u32 objId;                  /* 0x08 */
    u32 mapId;                  /* 0x0C */
    u32 unk10;                  /* 0x10 */
    int unk14;                  /* 0x14 */
    FieldEffectFollowArgs args; /* 0x18 */
    void *sprite;               /* 0x3C */
} FieldEffectFollowWork;        /* 0x40 */

typedef struct FieldEffectSimpleWork {
    int state;                  /* 0x00 */
    BOOL unk4;                  /* 0x04 */
    u32 unk8;                   /* 0x08 */
    int unkC;                   /* 0x0C */
    FieldEffectSimpleArgs args; /* 0x10 */
    void *sprite;               /* 0x24 */
} FieldEffectSimpleWork;        /* 0x28 */

typedef struct FieldEffectAnimSpec {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
} FieldEffectAnimSpec; /* 0x18 */

typedef struct Ov01FieldEffectCtx {
    FieldEffectManager *manager;
} Ov01FieldEffectCtx;

void ov01_021F18D4(FieldEffectManager *manager, int a1, int a2);
void ov01_021F18C8(FieldEffectManager *manager, int a1);
void ov01_021F18FC(FieldEffectManager *manager, int a1);
void ov01_021F1908(FieldEffectManager *manager, int a1, int a2);
void ov01_021F1924(FieldEffectManager *manager, int a1);
void ov01_021F1930(FieldEffectManager *manager, int a1, int a2, int a3);
void ov01_021F1970(FieldEffectManager *manager, int a1);
void ov01_021F1758(FieldEffectManager *manager, int a1, int a2, int a3, int a4, int a5, const FieldEffectAnimSpec *a6);
void *ov01_021F1740(void *a0, int a1, const VecFx32 *pos);

int sub_02068D90(void *a0);
void sub_02068DA8(void *a0, VecFx32 *a1);
void sub_02068DB8(void *a0, VecFx32 *a1);
int sub_0206121C(TaskManager *taskman, VecFx32 *pos);
BOOL sub_0205F0F8(LocalMapObject *object, u32 spriteId, u32 objId, u32 mapId);
BOOL sub_02023DA4(void *sprite);
void sub_02023EA4(void *sprite, int a1);
BOOL sub_02023F04(void *sprite, fx32 a1);
void sub_02023F1C(void *sprite, fx32 a1);
void sub_02023E50(void *sprite, VecFx32 *pos);
fx32 sub_02023F70(void *sprite);

extern const UnkOv01_02209280 ov01_02209138;
extern const UnkOv01_02209280 ov01_0220914C;
extern const FieldEffectAnimSpec ov01_02209160;
extern const FieldEffectAnimSpec ov01_02209178;
extern const FieldEffectAnimSpec ov01_02209190;
extern const FieldEffectAnimSpec ov01_022091A8;

Ov01FieldEffectCtx *ov01_021FEEEC(FieldEffectManager *manager);
void ov01_021FEF08(Ov01FieldEffectCtx *ctx);
void ov01_021FEF18(Ov01FieldEffectCtx *ctx);
void ov01_021FEFF8(Ov01FieldEffectCtx *ctx);
void ov01_021FF070(LocalMapObject *object, int a1);
void ov01_021FF0E4(LocalMapObject *object, int a1, int a2, int a3, int a4);
BOOL ov01_021FF174(void *a0, FieldEffectFollowWork *work);
BOOL ov01_021FF228(void *a0, FieldEffectFollowWork *work);
void ov01_021FF234(void *a0, FieldEffectFollowWork *work);
void ov01_021FF35C(void *a0, FieldEffectFollowWork *work);
BOOL ov01_021FF394(void *a0, FieldEffectSimpleWork *work);
BOOL ov01_021FF418(void *a0, FieldEffectSimpleWork *work);
void ov01_021FF424(void *a0, FieldEffectSimpleWork *work);
void ov01_021FF44C(void *a0, FieldEffectSimpleWork *work);

#endif /* POKEHEARTGOLD_FIELD_EFFECT_FOLLOW_OBJECT_INTERNAL_H */
