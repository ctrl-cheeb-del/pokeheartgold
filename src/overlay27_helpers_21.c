#include "overlay_27_helpers_internal.h"

u32 ov27_0225CC90(Ov27Work *work) {
    if (!Sprite_IsAnimated(work->unk388)) {
        Sprite_SetDrawFlag(work->unk388, FALSE);
        ov27_0225C6F8(work);
        work->unk00 = 10;
    }
    return 0;
}

u32 ov27_0225CCBC(Ov27Work *work) {
    Ov27Entry *entries = ov01_021EEF58(work->unk0C);
    *(u16 *)work->unk04 = entries[work->unk394].unk04;
    work->unk00 = 1;
    return 0;
}

void ov27_0225CCE0(Ov27Work *work, s32 a1) {
    Ov27Vec vec;
    vec.x = ov27_0225D118[a1 * 2] << 12;
    vec.y = (ov27_0225D11A[a1 * 2] + 0x100) << 12;
    vec.z = 0;
    Sprite_SetMatrix(work->unk388, &vec);
}
