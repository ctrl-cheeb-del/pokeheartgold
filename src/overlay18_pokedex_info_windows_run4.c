#include "overlay18_pokedex_info_windows_internal.h"

void ov18_021F0838(void *p) {
    u32 i;
    u8 *window = p;
    i = 0;
    window += 0xC;
    for (; i < 13; i++) {
        ClearWindowTilemapAndScheduleTransfer((Window *)window);
        window += 0x10;
    }
    ov18_021EE388(p);
}

void ov18_021F0858(void *p) {
    u32 i;
    u8 *window;
    ov18_021EE35C(p, ov18_021F9DB0, 2);
    i = 0;
    window = p;
    window += 0xC;
    for (; i < 2; i++) {
        FillWindowPixelBuffer((Window *)window, 0);
        window += 0x10;
    }
    ov18_021F9648((u8 *)p + 0xC, PTR(p, 0x65C), 0xAD, 0, 0, 4, 0x20100, 0);
    ov18_021F9648((u8 *)p + 0x1C, PTR(p, 0x65C), 0xAE, 0x3C, 0, 4, 0xF0C00, 2);
    i = 0;
    window = p;
    window += 0xC;
    for (; i < 2; i++) {
        ScheduleWindowCopyToVram((Window *)window);
        window += 0x10;
    }
}

void ov18_021F08E0(void *p) {
    u32 i;
    u8 *window = p;
    i = 0;
    window += 0xC;
    for (; i < 2; i++) {
        ClearWindowTilemapAndScheduleTransfer((Window *)window);
        window += 0x10;
    }
    ov18_021EE388(p);
}

void ov18_021F0900(void *p) {
    ov18_021EE35C(p, ov18_021F9EBC, 0x10);
    ov18_021F0928(p);
}
