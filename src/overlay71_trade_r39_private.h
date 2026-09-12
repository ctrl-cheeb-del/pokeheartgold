#ifndef OVERLAY_71_RESIDUAL_14_R39_PRIVATE_H
#define OVERLAY_71_RESIDUAL_14_R39_PRIVATE_H

#include "global.h"

#include "filesystem.h"
#include "gf_3d_vramman.h"
#include "gf_gfx_loader.h"
#include "pokemon.h"
#include "pokepic.h"
#include "sprite.h"

typedef struct Ov71TradeWorkR39 {
    void *ctx;
    u8 pad04[0x0c - 0x04];
    PokepicManager *pokepicManager;
    Pokepic *pokepic;
    PokepicAnimScript animScript;
    u8 pad18[0x3c - 0x18];
    Sprite *sprite0;
    Sprite *sprite1;
    u8 pad44[0x74 - 0x44];
    void *camera;
    u8 pad78[0x80 - 0x78];
    NARC *narc;
} Ov71TradeWorkR39;

BoxPokemon *ov71_02247390(void *ctx);
u16 ov71_022473A8(void *ctx);
Pokepic *ov71_02247F9C(Ov71TradeWorkR39 *work);
BOOL ov71_02247DEC(Ov71TradeWorkR39 *work, u32 *state);
void PlaySE(u16 seqNo);
void ov71_022480C0(Ov71TradeWorkR39 *work, s32 a1, s32 a2, s32 a3);
BOOL ov71_02248110(Ov71TradeWorkR39 *work);
void Pokepic_Delete(Pokepic *pokepic);
void ov71_02247704(void *camera, s32 value);
void ov71_0224817C(Ov71TradeWorkR39 *work);
s32 ov71_022481D8(Ov71TradeWorkR39 *work);
BOOL ov71_022481C8(Ov71TradeWorkR39 *work);
void BeginNormalPaletteFade(u32, u32, u32, u16, u16, u8, u32);
BOOL IsPaletteFadeFinished(void);
void ov71_022472C4(void *dst, s32 narcId, s32 a2, s32 a3);
void ov71_02247320(void *dst, void *src, NNSG2dImageProxy *image, NNSG2dImagePaletteProxy *palette, u8 a4);
Sprite *ov71_02247340(void *ctx, void *config, s32 x, s32 y, s32 a4, s32 a5);
void ov71_02247FF8(Ov71TradeWorkR39 *work);
void ov71_02247ED0(Ov71TradeWorkR39 *work);

#endif
