#include "r40_overlay_40_residual_41_unmatched_5_private.h"

int ov40_02244514(void *p) {
    void *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        if (ov40_0222DA84((u8 *)w + 8, 1)) {
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 1, 2, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
        break;
    case 1:
        SetBgPriority(0, 0);
        SetBgPriority(1, 3);
        SetBgPriority(2, 0);
        SetBgPriority(3, 2);
        SetBgPriority(4, 0);
        SetBgPriority(5, 3);
        SetBgPriority(6, 1);
        SetBgPriority(7, 2);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3E, PTR(p, 0x24), 3, 0, 0, 0, 0x6D);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3E, PTR(p, 0x24), 7, 0, 0, 0, 0x6D);
        ov40_02230964(p, 1);
        ov40_0222D874(p);
        ov40_02230964(p, 0);
        WORD(p, 8)
        ++;
        break;
    default:
        ov40_0222FB90(p, 0);
        ov40_0222BF80(p, 2);
        break;
    }
    return 0;
}
