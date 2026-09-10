#include "overlay_27_helpers_internal.h"

void ov27_0225C5E4(Ov27Work *work) {
    BgClearTilemapBufferAndCommit(work->unk18, 4);
    BgClearTilemapBufferAndCommit(work->unk18, 5);
    if (work->window28.pixelBuffer != NULL) {
        RemoveWindow(&work->window28);
    }
    if (work->window38.pixelBuffer != NULL) {
        RemoveWindow(&work->window38);
    }
}
