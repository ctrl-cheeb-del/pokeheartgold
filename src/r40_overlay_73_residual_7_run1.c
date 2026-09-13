#include "r40_overlay_73_residual_7_private.h"

int ov73_021E6A70(void *p, int result) {
    U8(p, 0x4A28) = 0;
    ov73_021E670C(p, 0);
    ov73_021E66F0(p);
    return result;
}

int ov73_021E6A90(void *p, int result) {
    ov73_021E67A8(p);
    U32(p, 0x318) = 0x17;
    ov73_021E66F0(p);
    return result;
}

int ov73_021E6AAC(void *p, int result) {
    u32 data;
    int input;

    if (U32(p, 0x4A1C) != ov73_021E746C() || U32(p, 0x4A24) != 0) {
        if (U32(gSystem, 0x48) & 0xC3) {
            PlaySE(0x5F2);
        }
        ov73_021E66F0(p);
        return result;
    }
    input = YesNoPrompt_HandleInput(*(void **)((u8 *)p + 0x2E8));
    if (input != 0) {
        ov73_021E6830(p);
        if (input == 2) {
            data = 0;
            sub_02037030(0x75, &data, 1);
            ov73_021E781C(p, 1);
            ov73_021E670C(p, 0);
        } else {
            ov73_021E71E4(p, 1, 2);
            ov73_021E71E4(p, 0, 2);
            if (sub_0203769C() == 0) {
                U32(p, 0x318) = 0x18;
                U8(p, 0x4A2A) = ov73_021E746C();
            } else {
                GF_AssertFail();
            }
        }
    }
    ov73_021E66F0(p);
    return result;
}

int ov73_021E6B6C(void *p, int result) {
    if (((SolOv73Large *)p)->field_4A2B == 0 && sub_02037030(0x73, NULL, 0) == 1) {
        U8(p, 0x4A2B) = 1;
    }
    return result;
}
