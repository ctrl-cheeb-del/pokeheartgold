#ifndef POKEHEARTGOLD_FIELD_EFFECT_GROUND_MARKER_INTERNAL_H
#define POKEHEARTGOLD_FIELD_EFFECT_GROUND_MARKER_INTERNAL_H

// Thumb comes from the SOURCE: global.h -> nitro/code16.h -> #pragma thumb on
#include "global.h"

#include "constants/sndseq.h"

#include "nnsys/g3d/binres/res_struct_accessor.h"

#include "field_system.h"
#include "heap.h"
#include "map_object.h"
#include "overlay_01_021F1348.h"
#include "task.h"
#include "unk_02023694.h"
#include "unk_020689C8.h"
#include "vram_transfer_manager.h"

// Not declared in any tracked header (field_effect_manager_4.c declares these
// locally; field_effect_animation_internal.h has only K&R `extern void f();`
// forms which conflict with overlay_01_021F1348.h, so we re-declare here).
void ov01_021F18D4(FieldEffectManager *manager, int a1, int a2);
void ov01_021F1908(FieldEffectManager *manager, int a1, int a2);
void ov01_021F1930(FieldEffectManager *manager, int id, u32 fileId, BOOL copyWithoutTex);
void *ov01_021F1758(FieldEffectManager *manager, u32 key, int a2, int a3, int objId, int a5, const void *a6);
void *ov01_021F18FC(FieldEffectManager *manager, int a1);
void *ov01_021F1924(FieldEffectManager *manager, int a1);
void ov01_021F1970(FieldEffectManager *manager, int id);
void ov01_021F18C8(FieldEffectManager *manager, u32 id);
void *ov01_021F1740(FieldSystem *fieldSystem, u32 id, const VecFx32 *position);
void *ov01_021F14B4(FieldSystem *fieldSystem, u32 fileId, int atEnd);
NNSG3dResTex *ov01_021F1AD4(FieldSystem *fieldSystem, int id);

void *sub_02023DA4(void *a0);
void sub_02023E50(void *a0, const VecFx32 *a1);
void sub_02026E18(void *a0, void *a1);
void *sub_02068D90(void *a0);
void sub_02068DA8(void *a0, VecFx32 *a1);
void *sub_02020838(NNSG3dResTex *tex, int a1);
void *sub_02020888(NNSG3dResTex *tex, int a1);
u32 sub_02020910(NNSG3dResTex *tex, int a1);
u32 sub_020209AC(NNSG3dResTex *tex, int a1);
void GF_AssertFail(void);
void PlaySE(u16 seq);

// The 8-byte module object, allocated by ov01_02203A18 and recovered from the
// field-effect manager slot 0x12 by ov01_021F1450.
typedef struct Ov01_02203A18_Work {
    FieldEffectManager *unk0;
    BOOL unk4;
} Ov01_02203A18_Work;

// The user-data block handed to ov01_021F1620 as a4 and recovered via sub_02068D98.
typedef struct Ov01_02203A18_Args {
    FieldSystem *unk0;
    Ov01_02203A18_Work *unk4;
    LocalMapObject *unk8;
} Ov01_02203A18_Args; // 0xc

// TaskManager_Call environment built by ov01_02203AB4.
typedef struct Ov01_02203A18_TaskEnv {
    int unk0;
    LocalMapObject *unk4;
} Ov01_02203A18_TaskEnv; // 0x8

// Texture-animation state, initialised by sub_02026E18.
typedef struct Ov01_02203A18_TexAnim {
    u16 *unk0;
    u8 *unk4;
    u32 unk8;
    u32 unkC;
    NNSG3dResTex *unk10;
    void *unk14;
    void *unk18;
    u32 unk1C;
    u32 unk20;
    u16 unk24;
    u16 unk26;
} Ov01_02203A18_TexAnim; // 0x28

// The per-instance work block; size 0x68 is the first word of ov01_02209518.
typedef struct Ov01_02203A18_Inst {
    int unk0;
    int unk4;
    u32 unk8;
    u32 unkC;
    int unk10;
    int unk14;
    VecFx32 unk18;
    u8 unk24[4];
    fx32 unk28;
    u8 unk2C[4];
    Ov01_02203A18_Args unk30;
    void *unk3C;
    Ov01_02203A18_TexAnim unk40;
} Ov01_02203A18_Inst; // 0x68

// The animation-advance state read by ov01_02203DF8.
typedef struct Ov01_02203A18_Anim {
    u16 *durations;
    u8 *frames;
    u32 unk8;
    u32 frameCount;
    NNSG3dResTex *tex;
    void *unk14;
    void *unk18;
    u32 unk1C;
    u32 unk20;
    u16 timer;
    u16 index;
} Ov01_02203A18_Anim; // 0x28

typedef struct Ov01_02203A18_FileIds {
    u32 unk0;
    u32 unk4;
} Ov01_02203A18_FileIds; // 0x8

#endif // POKEHEARTGOLD_FIELD_EFFECT_GROUND_MARKER_INTERNAL_H
