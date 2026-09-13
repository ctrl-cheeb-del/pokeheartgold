#include "r40_overlay_40_residual_12_middle_private.h"

void ov40_0222EED0(void *p, void *owner, void *cfg, void **items) {
    void *window = (u8 *)p + 0x18;
    int i;
    int count;
    WORD(p, 4) = WORD(cfg, 4);
    WORD(p, 0) = 0;
    WORD(p, 0xC) = 0;
    WORD(p, 0x10) = WORD(cfg, 0x24);
    PTR(p, 0x28) = cfg;
    PTR(p, 0x34) = PTR(owner, 0x48);
    WORD(p, 0x14) = SWORD(p, 4) / SWORD(p, 0x10) + 1;
    SWORD(p, 0x40) = SWORD(p, 0x10) / 2;
    SWORD(p, 0x44) = SWORD(p, 0x10) / 2;
    count = SWORD(p, 4);
    if (count < SWORD(p, 0x10)) {
        SWORD(p, 0x10) = count;
        SWORD(p, 0x40) = count - 1;
        SWORD(p, 0x44) = SWORD(p, 0x10) - 1;
    }
    WORD(p, 0x48) = 1;
    InitWindow(window);
    AddWindowParameterized(PTR(owner, 0x24), window, (u8)WORD(cfg, 0x20), (u8)WORD(cfg, 0x0C), (u8)WORD(cfg, 0x10), (u8)WORD(cfg, 0x14), (u8)WORD(cfg, 0x18), 14, (u16)WORD(cfg, 0x1C));
    FillWindowPixelBuffer(window, 0);
    for (i = 0; i < SWORD(p, 0x10); i++, items += 2) {
        AddTextPrinterParameterizedWithColor(window, 0, items[0], 0, SWORD(cfg, 8) * 8 * i + 4, 0xFF, 0x000F0D00, NULL);
        AddTextPrinterParameterizedWithColor(window, 0, items[1], 0x88, SWORD(cfg, 8) * 8 * i + 4, 0xFF, 0x000F0D00, NULL);
    }
    ScheduleWindowCopyToVram(window);
}
