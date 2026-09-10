#include "overlay_27_helpers_internal.h"

void ov27_0225C6F8(Ov27Work *work) {
    s32 n = ov01_021EEF60(work->unk0C);
    s32 i;
    BgClearTilemapBufferAndCommit(work->unk18, 4);
    BgClearTilemapBufferAndCommit(work->unk18, 5);
    for (i = 0; i < n; i++) {
        RemoveWindow(&work->windows[i]);
    }
}
