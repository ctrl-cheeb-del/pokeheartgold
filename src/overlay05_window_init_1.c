#include "overlay05_window_init_internal.h"

u32 ov05_0221DB4C(u32 size, BOOL is4x4) {
    NNSGfdTexKey key = NNS_GfdDefaultFuncAllocTexVram(size, is4x4, 0);
    sub_02015354(key);
    if (key == 0) {
        GF_AssertFail();
    }
    return NNS_GfdGetTexKeyAddr(key);
}

u32 ov05_0221DB70(u32 size, BOOL is4x4) {
    NNSGfdPlttKey key = NNS_GfdDefaultFuncAllocPlttVram(size, is4x4, 1);
    sub_02015394(key);
    if (key == 0) {
        GF_AssertFail();
    }
    return NNS_GfdGetPlttKeyAddr(key);
}

void ov05_0221DB94(Ov05WorkResidual *work) {
    GraphicsModes modes;
    BgTemplate bg1;
    BgTemplate bg2;
    BgTemplate bg3;
    modes = ov05_0221EA88;
    SetBothScreensModesAndDisable(&modes);
    bg1 = ov05_0221EB8C;
    InitBgFromTemplate(work->bgConfig, 1, &bg1, 0);
    BgClearTilemapBufferAndCommit(work->bgConfig, 1);
    bg2 = ov05_0221EB38;
    InitBgFromTemplate(work->bgConfig, 2, &bg2, 0);
    BgClearTilemapBufferAndCommit(work->bgConfig, 2);
    bg3 = ov05_0221EBC4;
    InitBgFromTemplate(work->bgConfig, 3, &bg3, 0);
}
