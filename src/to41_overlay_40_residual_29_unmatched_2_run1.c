#include "to41_overlay_40_residual_29_unmatched_2_private.h"

#define BLEND(p, w) PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 0x1AC), (u16)WORD(p, 0x58))

int ov40_022366CC(void *p) {
    void *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        if (ov40_0222DA84((u8 *)w + 0x1AC, 1)) {
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, (u8)WORD(w, 0x1AC), (u16)WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 0x1AC), (u16)WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 1, 2, (u8)WORD(w, 0x1AC), (u16)WORD(p, 0x58));
        break;
    case 1:
        ov40_02230964(p, 1);
        ov40_0222D874(p);
        ov40_02230964(p, 0);
        ov40_0222FB90(p, 0);
        sub_020879E0(PTR(p, 0x6F0), 0);
        WORD(p, 8)
        ++;
        break;
    case 2:
        if (ov40_0222FBB4(p)) {
            ov40_02230964(p, 1);
            ov40_022364D0(p);
            ov40_02230738(ov40_02230964(p, 0));
            WORD(p, 8)
            ++;
        }
        break;
    default:
        ov40_0222BF80(p, 2);
        break;
    }
    return 0;
}
