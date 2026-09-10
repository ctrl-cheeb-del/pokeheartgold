#ifndef POKEHEARTGOLD_FIELD_WARP_ENTRANCE_EFFECT_INTERNAL_H
#define POKEHEARTGOLD_FIELD_WARP_ENTRANCE_EFFECT_INTERNAL_H

// Thumb comes from the SOURCE: global.h -> nitro/code16.h -> #pragma thumb on
#include "global.h"

#include "field_system.h"
#include "map_object.h"
#include "metatile_behavior.h"
#include "overlay_01_021F1348.h"
#include "player_avatar.h"
#include "unk_0205FD20.h"
#include "unk_020689C8.h"
#include "unk_02069660.h"
#include "unk_0206979C.h"

// ---- not declared in any tracked header (see report.md) ----
void sub_020699AC(void *a0, VecFx32 *pos, VecFx32 *scale, MtxFx33 *mtx);
void sub_02020DA4(MtxFx33 *mtx, u16 x, u16 y, u16 z);
void sub_02068DA8(void *a0, VecFx32 *a1);

// The 0x6c module object allocated by ov01_02200858 and recovered from the
// field-effect manager slot 3 by ov01_021F1450.
typedef struct Ov01_02200858_Work {
    FieldEffectManager *unk0;
    UnkOv01_021FFECC_sub unk4;
    NNSG3dRenderObj unk18;
} Ov01_02200858_Work; // 0x6c

// The user-data block handed to ov01_021F1620 as a4 and recovered via sub_02068D98.
typedef struct Ov01_02200858_Args {
    FieldSystem *unk0;
    Ov01_02200858_Work *unk4;
    PlayerAvatar *unk8;
} Ov01_02200858_Args; // 0xc

// The per-instance work block; size 0x30 is the first word of ov01_02209340.
typedef struct Ov01_02200858_Inst {
    int unk0;
    int unk4;
    u8 unk8;
    u8 unk9[0xb];
    u32 unk14;
    u32 unk18;
    int unk1C;
    int unk20;
    Ov01_02200858_Args unk24;
} Ov01_02200858_Inst; // 0x30

#endif // POKEHEARTGOLD_FIELD_WARP_ENTRANCE_EFFECT_INTERNAL_H
