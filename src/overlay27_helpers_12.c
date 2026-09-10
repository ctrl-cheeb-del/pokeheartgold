#include "overlay_27_helpers_internal.h"

void ov27_0225BEB0(Ov27Sub *sub) {
    if (sub->unk1C != 0) {
        ov27_0225B630(&sub->window, 2);
        ClearWindowTilemapAndCopyToVram(&sub->window);
        RemoveWindow(&sub->window);
    }
}
