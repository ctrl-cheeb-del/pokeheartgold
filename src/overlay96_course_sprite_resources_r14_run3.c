#include "global.h"

#include "overlay96_course_sprite_resources_r14_private.h"

void ov96_02203F50(Ov96R31Work *sprites, void *p) {
    void *chr = *ov96_021EB5EC(sprites, 0x65, 0);
    void *pal = *ov96_021EB5EC(sprites, 0x65, 1);
    void *image = SpriteTransfer_GetCharProxy(chr);
    void *palette = SpriteTransfer_GetPaletteProxy(pal, image);
    u8 i;

    for (i = 0; i < 3; i++) {
        u8 *dst = (u8 *)p + i * 4;
        u32 offset = i;
        offset *= 0xd00;
        U32_AT(dst, 0x3c) = offset + 0x300 + NNS_G2dGetImageLocation(image, NNS_G2D_VRAM_TYPE_2DSUB);
        {
            u32 offset = i << 5;
            offset += 0x20;
            U32_AT(dst, 0x48) = offset + NNS_G2dGetImagePaletteLocation(palette, NNS_G2D_VRAM_TYPE_2DSUB);
        }
    }
}

void ov96_02203FBC(Ov96CourseUiGfx *gfx) {
    AddWindow(gfx->bgConfig, &gfx->window, &ov96_0221CA28);
    BG_FillCharDataRange(gfx->bgConfig, GF_BG_LYR_SUB_0, 0, 1, 0);
    LoadFontPal0(4, 0x1e0, gfx->heapId);
    FillWindowPixelBuffer(&gfx->window, 0);
}

void ov96_02203FFC(Ov96CourseUiGfx *gfx) {
    u8 self = (u8)ov96_021E5F24(gfx->unk04);
    PlayerProfile *profile = PokeathlonCourse_GetPlayerProfileFromData(gfx->unk04, self);
    String *name = PlayerProfile_GetPlayerName_NewString(profile, gfx->heapId);

    AddTextPrinterParameterizedWithColor(&gfx->window, 0, name, 0, 0, 0xff, 0x000f0e00, NULL);
    String_Delete(name);
    CopyWindowToVram(&gfx->window);
}
