#include "overlay72_residual7_private.h"

void ov72_02238B18(void *arg, int variant) {
    NARC *narc;
    u8 *work = arg;
    BgConfig *bgConfig = *(BgConfig **)(work + 4);

    if (variant == 0) {
        narc = NARC_New(0x58, 0x43);
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 3, 4, 0, 0x100, 0x43);
        GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0xB, bgConfig, 5, 0, 0, 0, 0x43);
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0xC, bgConfig, 5, 0, 0x600, 0, 0x43);
        *(u32 *)(work + 0x1304) = 0;
        NARC_Delete(narc);
        return;
    } else {
        narc = NARC_New(0xEE, 0x43);
        *(u32 *)(work + 0x1304) = 1;
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 8, 4, 0, 0x40, 0x43);
        GfGfxLoader_LoadCharDataFromOpenNarc(narc, 9, bgConfig, 5, 0, 0, 0, 0x43);
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0xA, bgConfig, 5, 0, 0x600, 0, 0x43);
        NARC_Delete(narc);
        return;
    }
}
