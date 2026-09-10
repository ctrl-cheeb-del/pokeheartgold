#ifndef POKEHEARTGOLD_OV01_021FE200_POKEHEARTGOLD_FIELD_EFFECT_MODEL_BANK_H
#define POKEHEARTGOLD_OV01_021FE200_POKEHEARTGOLD_FIELD_EFFECT_MODEL_BANK_H

// Thumb comes from the SOURCE: global.h -> nitro/code16.h -> #pragma thumb on
#include "global.h"

#include "map_object.h"
#include "overlay_01_021F1348.h"
#include "unk_020689C8.h"
#include "unk_02069660.h"
#include "unk_0206979C.h"

// Per-module renderer bank. The tracked UnkOv01_021FFECC in
// overlay_01_021F1348.h is the 4-renderer instantiation (0x1a4); this module
// allocates 0x824, i.e. the 10-renderer double-bank form. See report.md.
#define OV01_021FE200_COUNT 10

typedef struct UnkOv01_021FE200 {
    void *unk0;                                      // 0x000
    UnkOv01_021FFECC_sub unk4[OV01_021FE200_COUNT];  // 0x004 .. 0x0cc
    UnkOv01_021FFECC_sub unkCC[OV01_021FE200_COUNT]; // 0x0cc .. 0x194
    NNSG3dRenderObj unk194[OV01_021FE200_COUNT];     // 0x194 .. 0x4dc
    NNSG3dRenderObj unk4DC[OV01_021FE200_COUNT];     // 0x4dc .. 0x824
} UnkOv01_021FE200;

// Work area handed to the callback table. sizeof == 0x1c, which is the value
// stored in the first word of ov01_02208FE0.
typedef struct UnkOv01_021FE200_Work {
    int unk0;                    // 0x00 state
    int unk4;                    // 0x04 counter
    int unk8;                    // 0x08
    int unkC;                    // 0x0c alpha
    void *unk10;                 // 0x10
    UnkOv01_021FFECC_sub *unk14; // 0x14
    int unk18;                   // 0x18
} UnkOv01_021FE200_Work;

typedef BOOL (*UnkOv01_021FE200_Cb1)(void *, UnkOv01_021FE200_Work *);
typedef void (*UnkOv01_021FE200_Cb2)(void *, UnkOv01_021FE200_Work *);

typedef struct UnkOv01_021FE200_Callbacks {
    int size;
    UnkOv01_021FE200_Cb1 unk4;
    UnkOv01_021FE200_Cb2 unk8;
    UnkOv01_021FE200_Cb2 unkC;
    UnkOv01_021FE200_Cb2 unk10;
} UnkOv01_021FE200_Callbacks;

// 12-byte argument block passed as ov01_021F1620's a4 in ov01_021FE3F8.
typedef struct UnkOv01_021FE200_Args {
    u32 unk0;
    UnkOv01_021FFECC_sub *unk4;
    NNSG3dRenderObj *unk8;
} UnkOv01_021FE200_Args;

// Field view of sub_02068D98's return. The tracked UnkOv01_021FFFCC wraps a
// UnkOv01_021FFFCC_common whose 0x4 is a u8[8]; this module reads 0x4/0x8 as
// words. See report.md.
typedef struct UnkOv01_021FE200_Mdl {
    void *unk0;
    UnkOv01_021FFECC_sub *unk4;
    int unk8;
} UnkOv01_021FE200_Mdl;

void sub_020611C8(int x, int z, VecFx32 *position);
void *sub_02068D90(void *a0);
void NNS_G3dMdlSetMdlAlphaAll(NNSG3dResMdl *pMdl, u32 alpha);

#endif // POKEHEARTGOLD_OV01_021FE200_POKEHEARTGOLD_FIELD_EFFECT_MODEL_BANK_H
