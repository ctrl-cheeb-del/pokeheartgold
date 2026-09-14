#ifndef TO46_OV88_RESIDUAL_3_PRIVATE_H
#define TO46_OV88_RESIDUAL_3_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "sprite.h"
#include "system.h"
#include "unk_02009D48.h"
#include "unk_0200A090.h"
#include "unk_0200B150.h"
#include "unk_0203A3B0.h"

typedef struct Ov88R3Work {
    BgConfig *bg;
    SpriteList *sprites;
    G2dRenderer renderer;
    GF_2DGfxResMan *managers[4];
    NARC *narc;
} Ov88R3Work;

extern const GraphicsModes ov88_02259934;
extern const u32 ov88_02259944[5];
extern const ObjCharTransferTemplate ov88_02259914;
extern const BgTemplate ov88_022599C0[5];

void ov88_02258B34(Ov88R3Work *work, enum HeapID heapID);
void ov88_02258C60(Ov88R3Work *work);
void ov88_02258C98(Ov88R3Work *work, enum HeapID heapID);
void ov88_02258D38(Ov88R3Work *work);
#endif
