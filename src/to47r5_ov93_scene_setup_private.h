#ifndef OV93_TO41_RESIDUAL_5_PRIVATE_H
#define OV93_TO41_RESIDUAL_5_PRIVATE_H

/* global.h MUST come first: it pulls <nitro/code16.h>, which selects Thumb
   for this translation unit.  Do not reorder, and do not add an SDK/NNS
   header above it -- an equivalent reorder silently flipped an Overlay 93
   unit's instruction set at the 46% link. */
#include "global.h"

#include "bg_window.h"
#include "camera.h"
#include "gf_gfx_planes.h"

/* Raw byte-offset accessors: no invented struct sizes. */
#define PAT(p, o) (*(void **)((u8 *)(p) + (o)))
#define BAT(p, o) ((u8 *)(p) + (o))

extern void MTX_Identity33_(MtxFx33 *);
extern void Thunk_G3X_Reset(void);
extern void RequestSwap3DBuffers(u32 sortMode, u32 bufferMode);
extern void SpriteSystem_DrawSprites(void *spriteManager);
extern void SpriteSystem_UpdateTransfer(void);
extern void FillWindowPixelBuffer(Window *window, u8 fillValue);
extern s32 sub_0201543C(void);
extern void sub_02015460(void);
extern void sub_020181EC(void *);
extern void sub_020399FC(u32 a, void *b);

/* Defined in sibling objects of overlay 93. */
extern void ov93_02262034(void *, void *);
extern void ov93_02261354(void *, void *);
extern void ov93_02261D1C(void *, void *);
extern void ov93_0225FFF8(void *);
extern void ov93_0225FE80(void *, void *, void *);
extern void ov93_02260660(void *);
extern void ov93_0225E03C(void *);
extern void ov93_02260A30(void *);
extern void ov93_0225E898(void *, void *);
extern void ov93_0225E0A4(void *);

/* Assembly-owned constant tables: one extern per public label. */
extern const GraphicsBanks ov93_02262AC8;
extern const GraphicsModes ov93_02262A44;
extern const BgTemplate ov93_02262B40[3];
extern const BgTemplate ov93_02262B94[4];

void ov93_0225D07C(void *unused, void *p);
void ov93_0225D1D8(BgConfig *bgConfig);
void ov93_0225D380(void *p);

#endif // OV93_TO41_RESIDUAL_5_PRIVATE_H
