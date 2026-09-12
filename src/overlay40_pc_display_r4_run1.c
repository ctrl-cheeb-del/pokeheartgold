#include "overlay40_pc_display_r4_private.h"

void ov40_0222C6C8(void *p, int layer, int alternate) {
    void *narc = PTR(p, 0x14);
    void *bg = PTR(p, 0x24);
    int screen = 2;

    if (alternate != 0) {
        screen = 0;
    }

    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0x2D, bg, layer, 0, 0, 0, 0x6D);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, screen, bg, layer, 0, 0, 0, 0x6D);
}

void ov40_0222C710(void *p, int layer) {
    void *narc = PTR(p, 0x14);
    void *bg = PTR(p, 0x24);

    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0x2D, bg, layer, 0, 0, 0, 0x6D);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 1, bg, layer, 0, 0, 0, 0x6D);
}
