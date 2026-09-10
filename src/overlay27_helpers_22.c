#include "overlay_27_helpers_internal.h"

void ov27_0225CD74(Ov27Work *work, s32 a1) {
    s32 idx = a1 - 2;
    Sprite_SetAnimCtrlSeq(work->unk388, ov27_0225D3C6[idx * 24] + 2);
}
