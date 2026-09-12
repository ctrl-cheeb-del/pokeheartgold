#include "overlay71_trade_r39_private.h"

void ov71_02247FF8(Ov71TradeWorkR39 *work) {
    NNSG2dImagePaletteProxy palette;
    NNSG2dImageProxy image;
    u8 config[0x24];

    ov71_022472C4((u8 *)work + 0x44, 0x59, 7, 8);
    NNS_G2dInitImagePaletteProxy(&palette);
    NNS_G2dInitImageProxy(&image);
    GfGfxLoader_LoadImageMapping((NarcId)0x59, 9, TRUE, GF_BG_LYR_MAIN_0, 0, NNS_G2D_VRAM_TYPE_2DMAIN, 0, HEAP_ID_57, &image);
    GfGfxLoader_PartiallyLoadPalette((NarcId)0x59, 0xa, NNS_G2D_VRAM_TYPE_2DMAIN, 0, HEAP_ID_57, &palette);
    ov71_02247320(config, (u8 *)work + 0x44, &image, &palette, 2);
    work->sprite0 = ov71_02247340(work->ctx, config, 0x80, 0x64, 0, 1);
    work->sprite1 = ov71_02247340(work->ctx, config, 0x80, 0x5a, 0, 1);
    Sprite_SetPriority(work->sprite1, 1);
    Sprite_SetDrawFlag(work->sprite0, FALSE);
    Sprite_SetDrawFlag(work->sprite1, FALSE);
}
