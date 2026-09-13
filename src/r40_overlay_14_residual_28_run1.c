#include "r40_overlay_14_residual_28_private.h"

void ov14_021ED62C(Ov14R28Data *data) {
    ov14_021F6070(data);
    ov14_021E875C(*(void **)((u8 *)data->unk34 + 0x2f0));
    ov14_021F0234(data, ov14_021E9618, 0x38);
}

u32 ov14_021ED650(Ov14R28Data *data) {
    ov14_021F6AC0(data, 9, data->unk2c);
    if (data->unk2c <= 5) {
        ov14_021F29E4(data->unk34, 9, 0xe);
    } else {
        ov14_021F29E4(data->unk34, 9, 8);
    }
    ov14_021F6844(data, 0, 0x27);
    return 0x3d;
}

void ov14_021ED684(Ov14R28Data *data) {
    ov14_021F2A18(data->unk34, 9, 0);
    ov14_021F6654(data->unk34, 0x27);
    ov14_021F10DC(data, 0x3a);
}

void ov14_021ED6A4(Ov14R28Data *data) {
    ov14_021E87BC(*(void **)((u8 *)data->unk34 + 0x2f0));
    ov14_021F0234(data, ov14_021E9618, 0x3b);
}
