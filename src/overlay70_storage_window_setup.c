#include "overlay70_storage_window_setup_private.h"

void ov70_0223A0D4(Ov70Work *work) {
    int i;
    int baseTile;

    AddWindowParameterized(*(void **)((u8 *)work + 4), work->windowF18, 0, 2, 0x15, 0x1B, 2, 0xD, 0x28);
    FillWindowPixelBuffer(work->windowF18, 0);
    AddWindowParameterized(*(void **)((u8 *)work + 4), work->windowF58, 0, 0x15, 0xF, 0xA, 4, 0xD, 0x5E);

    baseTile = 0x86;
    for (i = 0; i < 14; i++) {
        AddWindowParameterized(*(void **)((u8 *)work + 4), work->windows1058[i], 3, ov70_022453B8[i].bgId, ov70_022453B8[i].x, ov70_022453B8[i].y, ov70_022453B8[i].width, 0xD, baseTile);
        FillWindowPixelBuffer(work->windows1058[i], 0);
        baseTile += ov70_022453B8[i].y * ov70_022453B8[i].width;
    }
    ov70_02239D44(work, 2);
}

void ov70_0223A1A0(Ov70Work *work) {
    int i;

    RemoveWindow(work->window1198);
    RemoveWindow(work->windowF18);
    RemoveWindow(work->windowF58);
    for (i = 0; i < 14; i++) {
        RemoveWindow(work->windows1058[i]);
    }
}
