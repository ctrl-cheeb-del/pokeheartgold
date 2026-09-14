#include "overlay72_residual7_private.h"

void ov72_02238E3C(void *task, Overlay72Residual7Work *work) {
    if (work->active != 0) {
        work->tick ^= 1;
        if (work->tick & 1) {
            return;
        }
        if (work->mode <= 1) {
            GX_LoadBGPltt(work->pal + work->idx * 0x20, 0, 0x20);
        }
        if (work->mode == 0 || work->mode == 2) {
            GXS_LoadBGPltt(work->pal + work->idx * 0x20, 0, 0x20);
        }
        if (work->dir == 0) {
            work->idx++;
            if (work->idx >= 0x15) {
                work->idx = 0x13;
                work->dir ^= 1;
            }
        } else {
            work->idx--;
            if (work->idx < 0) {
                work->idx = 1;
                work->dir ^= 1;
            }
        }
    }
}

void ov72_02238EE4(void *arg) {
    u8 *p = arg;
    AddWindowParameterized(*(void **)(p + 4), p + 0xE58, 0, 4, 4, 0x17, 0x10, 0xD, 0xA4);
    FillWindowPixelBuffer(p + 0xE58, 0);
    AddWindowParameterized(*(void **)(p + 4), p + 0xE38, 0, 0x1A, 0xE, 4, 2, 0xD, 0x94);
    FillWindowPixelBuffer(p + 0xE38, 0xF);
    AddWindowParameterized(*(void **)(p + 4), p + 0xE28, 0, 0x1A, 0xE, 4, 2, 0xD, 0x9C);
    FillWindowPixelBuffer(p + 0xE28, 0xF);
    AddWindowParameterized(*(void **)(p + 4), p + 0xE48, 0, 4, 1, 0x18, 2, 0xD, 0x214);
    FillWindowPixelBuffer(p + 0xE48, 0);
    ov72_0223A3E0(p + 0xE48, *(void **)(p + 0xBE4), 0, 1, 1, 0xF0E00);
    AddWindowParameterized(*(void **)(p + 4), p + 0xE18, 0, 2, 0x13, 0x1B, 4, 0xD, 0x28);
    FillWindowPixelBuffer(p + 0xE18, 0xF);
}
