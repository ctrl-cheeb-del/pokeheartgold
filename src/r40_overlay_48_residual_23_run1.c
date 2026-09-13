#include "r40_overlay_48_residual_23_private.h"

void ov48_0225A768(void *p) {
    int i = 0;
    void *window;

    window = ADD(p, 0x168);
    for (; i < 3; i++) {
        RemoveWindow(window);
        window = ADD(window, 0x10);
    }
    RemoveWindow(ADD(p, 0x198));
}

void ov48_0225A790(void *p, u32 index, void *record, void *strings) {
    void *window;
    void *string;
    u32 colorIndex;

    if (index >= 3) {
        GF_AssertFail();
    }
    window = ADD(ADD(p, 0x168), index * 0x10);
    FillWindowPixelBuffer(window, 0);
    colorIndex = ov48_0225B038(U32AT(record, 0));
    string = ov48_0225B0C4(strings, 2);
    AddTextPrinterParameterizedWithColor(window, 1, string, 0, 0, 0xFF, ov48_0225B1D8[colorIndex], NULL);
    string = ov48_0225B0E0(strings, U32AT(record, 4));
    AddTextPrinterParameterizedWithColor(window, 1, string, 0, 0x10, 0xFF, 0x10200, NULL);
    string = ov48_0225B108(strings, U32AT(record, 4), U32AT(record, 8));
    AddTextPrinterParameterizedWithColor(window, 1, string, 0, 0x20, 0xFF, 0x10200, NULL);
}
