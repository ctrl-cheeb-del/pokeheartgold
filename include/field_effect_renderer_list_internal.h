#ifndef POKEHEARTGOLD_OVERLAY_01_021FD1B8_H
#define POKEHEARTGOLD_OVERLAY_01_021FD1B8_H

// Thumb comes from the SOURCE: global.h -> nitro/code16.h -> #pragma thumb on
#include "global.h"

#include "field/overlay_01_021FD1B8.h"

#include "map_object.h"
#include "overlay_01_021F1348.h"
#include "unk_020689C8.h"
#include "unk_02069660.h"
#include "unk_0206979C.h"

// Not declared in any tracked header.
void sub_02068DA8(void *a0, VecFx32 *a1);
void GF_AssertFail(void);

#define FIELD_EFFECT_RENDERER_SLOT_EMPTY 0xFFFF

// The user-data block handed to ov01_021F1620 as a4 and recovered via sub_02068D98.
typedef struct FieldEffectRendererArgs {
    u32 unk0;
    FieldSystem *unk4;
    LocalMapObject *unk8;
} FieldEffectRendererArgs; // 0xc

// One renderer slot. unk0 == 0xFFFF marks the slot free.
typedef struct FieldEffectRenderer {
    u32 unk0;
    UnkOv01_021FFECC_sub unk4;
    NNSG3dRenderObj unk18;
} FieldEffectRenderer; // 0x6c

typedef struct FieldEffectRendererList {
    void *unk0;
    u32 count;
    FieldEffectRenderer *renderers;
} FieldEffectRendererList; // 0xc

// The per-instance work block; size 0x28 is the first word of ov01_02208E1C.
typedef struct FieldEffectRendererWork {
    int unk0;
    u32 unk4;
    u32 unk8;
    VecFx32 unkC;
    NNSG3dRenderObj *unk18;
    FieldEffectRendererArgs unk1C;
} FieldEffectRendererWork; // 0x28

typedef struct FieldEffectRendererInit {
    u32 unk0;
    int unk4;
} FieldEffectRendererInit; // 0x8

#endif // POKEHEARTGOLD_OVERLAY_01_021FD1B8_H
