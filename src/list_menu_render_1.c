#include "list_menu_render_internal.h"

void sub_0205993C(void *arg, int selected) {
    u8 *data = arg;
    void *window = data + 0x64;
    int i;
    int y;

    if (!WindowIsInUse(window)) {
        AddWindowParameterized(*(void **)(*(u8 **)(data + 0x24) + 8), window, 3, 0x14, 0xB, 0xB, 6, 0xD, 0x5A);
        LoadUserFrameGfx1(*(void **)(*(u8 **)(data + 0x24) + 8), 3, 1, 0xB, 0, 4);
        FillWindowPixelBuffer(window, 0xF);
        for (i = 0, y = 0; i < 3; i++, y += 0x10) {
            ReadMsgDataIntoString(*(void **)(data + 0x2C), i + 0x16, *(void **)(data + 0xC));
            AddTextPrinterParameterized(window, 0, *(void **)(data + 0xC), 0x10, y, 0xFF, NULL);
        }
    }
    data[0x80] = 3;
    *(void **)(data + 0x7C) = window;
    data[0x81] = selected;
    FillWindowPixelRect(window, 0xF, 0, 0, 0x10, ((u32)((u8 *)window)[8] << 19) >> 16);
    ListMenuUpdateCursorObj(*(void **)(data + 0x78), *(void **)(data + 0x7C), 0, selected * 0x10);
    DrawFrameAndWindow1(*(void **)(data + 0x7C), 0, 1, 0xB);
}
