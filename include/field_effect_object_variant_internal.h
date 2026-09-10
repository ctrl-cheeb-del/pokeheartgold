#ifndef POKEHEARTGOLD_OVERLAY_01_021FE780_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY_01_021FE780_PRIVATE_H

// Thumb comes from the SOURCE: global.h -> nitro/code16.h -> #pragma thumb on
#include "global.h"

#include "map_object.h"
#include "overlay_01_021F1348.h"
#include "unk_020689C8.h"
#include "unk_02069660.h"
#include "unk_0206979C.h"

// ---- not declared in any tracked header (private proposals; see report.md) ----
void sub_020699AC(void *a0, VecFx32 *pos, VecFx32 *scale, MtxFx33 *mtx);
void sub_02020DA4(MtxFx33 *mtx, u16 x, u16 y, u16 z);
void *sub_02068D74(void *a0);
void *sub_02068D90(void *a0);
void sub_02068DA8(void *a0, VecFx32 *a1);
BOOL sub_0206121C(void *fieldSystem, VecFx32 *position);

// The 0x6c renderer context allocated by ov01_021FE780 and recovered through
// ov01_021F1450(fieldSystem, 4). Same shape as FieldEffectRenderer.
typedef struct Ov01FE780Ctx {
    void *manager;             /* 0x00 */
    UnkOv01_021FFECC_sub unk4; /* 0x04 */
    NNSG3dRenderObj unk18;     /* 0x18 */
} Ov01FE780Ctx;                /* 0x6c */

// The 0x10-byte user-data block handed to ov01_021F1620 as a4 and recovered
// via sub_02068D98 in ov01_021FE868.
typedef struct Ov01FE780Args {
    u32 dir;                /* 0x00 */
    FieldSystem *fieldSys;  /* 0x04 */
    Ov01FE780Ctx *ctx;      /* 0x08 */
    LocalMapObject *object; /* 0x0C */
} Ov01FE780Args;            /* 0x10 */

// The per-instance work block; 0x34 is the first word of ov01_022090DC.
typedef struct Ov01FE780Work {
    int unk00;          /* 0x00 */
    int unk04;          /* 0x04 */
    u32 unk08;          /* 0x08 */
    u32 objId;          /* 0x0C */
    u32 mapId;          /* 0x10 */
    int unk14;          /* 0x14 */
    void *unk18;        /* 0x18 */
    fx32 unk1C;         /* 0x1C */
    fx32 unk20;         /* 0x20 */
    Ov01FE780Args args; /* 0x24 */
} Ov01FE780Work;        /* 0x34 */

#endif // POKEHEARTGOLD_OVERLAY_01_021FE780_PRIVATE_H
