#include "r40_overlay_73_residual_6_private.h"

int ov73_021E671C(void *p, int result) {
    if (ov73_021E75FC(U32(p, 0x4C))) {
        U32(p, 0x318) = U32(p, 0x31C);
        if (U32(p, 0x31C) == 3) {
            if (sub_0203769C() == 0) {
                ov73_021E71E4(p, 0, 0);
            }
            U32(p, 0x4A38) = -1;
            ov73_021E71E4(p, 1, 0);
            ScheduleBgTilemapBufferTransfer(PTR(p, 0), 1);
        }
    }
    ov73_021E66F0(p);
    return result;
}

int ov73_021E6778(void *p, int result) {
    u32 data;
    if (sub_0203769C() == 0) {
        data = 0;
        sub_02037030(0x75, &data, 1);
    }
    U32(p, 0x318) = 3;
    ov73_021E66F0(p);
    return result;
}

void ov73_021E67A8(void *p) {
    SolYesNoTemplate6 t;
    MI_CpuFill8(&t, 0, sizeof(t));
    t.bg = PTR(p, 0);
    t.x = 0;
    t.y = 0x1F;
    t.z = 0xE;
    t.a = 0x19;
    t.b = 6;
    t.c = U32(p, 0x314);
    t.d = 0;
    YesNoPrompt_InitFromTemplate(PTR(p, 0x2E8), &t);
    U8(p, 0x4A15) = 1;
    if (sub_0203769C() == 0) {
        ov73_021E71E4(p, 0, 2);
    }
    ov73_021E71E4(p, 1, 2);
    ScheduleBgTilemapBufferTransfer(PTR(p, 0), 1);
}

void ov73_021E6830(void *p) {
    if (((SolOv73Large6 *)p)->field_4A15 != 0) {
        U32(p, 0x314) = YesNoPrompt_IsInTouchMode(PTR(p, 0x2E8));
        YesNoPrompt_Reset(PTR(p, 0x2E8));
        U8(p, 0x4A15) = 0;
        if (sub_0203769C() == 0) {
            ov73_021E71E4(p, 0, 0);
        }
        U32(p, 0x4A38) = -1;
        ov73_021E71E4(p, 1, 0);
        ScheduleBgTilemapBufferTransfer(PTR(p, 0), 1);
    }
}

int ov73_021E6890(void *p, int result) {
    ov73_021E67A8(p);
    U32(p, 0x318) = 5;
    ov73_021E66F0(p);
    return result;
}

int ov73_021E68AC(void *p, int result) {
    u32 noData;
    u8 data[4];
    int input;

    if (sub_0203769C() != 0) {
        if (U32(p, 0x4A10) != 0) {
            if (U32(gSystem, 0x48) & 0xC3) {
                PlaySE(0x5F2);
            }
            ov73_021E66F0(p);
            return result;
        }
    } else {
        if (U32(p, 0x4A24) != 0) {
            if (U32(gSystem, 0x48) & 0xC3) {
                PlaySE(0x5F2);
            }
            ov73_021E66F0(p);
            return result;
        }
    }
    if (ov73_021E746C() != sub_02037454()) {
        ov73_021E66F0(p);
        return result;
    }
    input = YesNoPrompt_HandleInput(PTR(p, 0x2E8));
    if (input != 0) {
        if (input == 2) {
            if (sub_0203769C() == 0) {
                noData = 0;
                sub_02037030(0x75, &noData, 1);
                ov73_021E781C(p, 1);
            }
            ov73_021E670C(p, 0);
        } else if (sub_0203769C() == 0) {
            ov73_021E670C(p, 0xB);
            ov73_021E756C(p, 0xE, 0);
        } else {
            MI_CpuFill8(data, 0, 4);
            data[2] = 0;
            data[0] = sub_0203769C();
            U8(p, 0x4A28) = 1;
            U16(p, 0x4A32) = 0;
            U32(p, 0x318) = 6;
            sub_02037030(0x70, data, 4);
        }
        ov73_021E6830(p);
    }
    ov73_021E66F0(p);
    return result;
}
