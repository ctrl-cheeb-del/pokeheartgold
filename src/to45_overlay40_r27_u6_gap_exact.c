#include "to45_overlay40_r27_u6_gap_private.h"

int ov40_02231EA4(void *p) {
    switch (WORD(p, 8)) {
    case 0:
        WORD(p, 0x54) = 0;
        if (*(volatile u8 *)((u8 *)p + 0x5C) != 0) {
            BYTE(p, 0x5C) = BYTE(p, 0x5C) - 1;
        } else {
            BYTE(p, 0x5C) = 6;
        }
        WORD(p, 0x58) = ov40_0222DAC0(p);
        WORD(p, 8)
        ++;
        break;
    case 1:
        if (ov40_0222DA84((u8 *)p + 0x54, 1)) {
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 0, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 1, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        break;
    case 2:
        GfGfx_EngineATogglePlanes(0x10, 0);
        GfGfx_EngineBTogglePlanes(0x10, 0);
        ov40_0222DBEC(p, BYTE(p, 0x5C));
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 0, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 1, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        WORD(p, 8)
        ++;
        break;
    case 3:
        GfGfx_EngineATogglePlanes(0x10, 1);
        GfGfx_EngineBTogglePlanes(0x10, 1);
        WORD(p, 8)
        ++;
        break;
    case 4:
        if (ov40_0222DA84((u8 *)p + 0x54, 0)) {
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 0, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 1, 0xFFFF, WORD(p, 0x54), WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 0);
        break;
    }
    return 0;
}
