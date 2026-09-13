#include "to41_overlay_40_residual_29_unmatched_2_private.h"

#define BLEND(p, w) PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 0x1AC), (u16)WORD(p, 0x58))

int ov40_02236C64(void *p) {
    void *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        sub_020879E0(PTR(p, 0x6F4), 0);
        ov40_02236FE0(p);
        GfGfx_EngineBTogglePlanes(4, 0);
        WORD(p, 8)
        ++;
    case 1:
        ov40_0222DA84((u8 *)w + 0x1AC, 1);
        if (ov40_0222DA00((u8 *)w + 0x1A4, (u8 *)w + 0x1A8, 1, 2)) {
            ov40_022368EC(p, 0);
            GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x14), 0x4D, PTR(p, 0x24), 7, 0, 0, 0, 0x6D);
            WORD(p, 8)
            ++;
        }
        BLEND(p, w);
        break;
    case 2:
        ov40_0222DA84((u8 *)w + 0x1AC, 0);
        if (ov40_0222DA00((u8 *)w + 0x1A4, (u8 *)w + 0x1A8, 0, 2)) {
            ov40_02237030(p, 0x10E);
            ov40_0222BF80(p, 3);
        }
        BLEND(p, w);
        break;
    default:
        break;
    }
    return 0;
}
