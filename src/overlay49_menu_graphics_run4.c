#include "overlay49_menu_graphics_private.h"

void ov49_0225A98C(void *work) {
    u32 flag;
    ov49_02258B44(PTR_AT(work, 0x3E0));
    flag = FLAGS_AT(work);
    if (flag == 0 && U8_AT(work, 6) == 0) {
        ov49_0225EF24(PTR_AT(work, 0x3F0));
    }
    ov49_0225E318(PTR_AT(work, 0x3E4));
    flag = FLAGS_AT(work);
    if (flag == 0 && U8_AT(work, 6) == 0) {
        ov49_02258B5C(PTR_AT(work, 0x3E0));
        ov49_0225EF30(PTR_AT(work, 0x3F0));
        ov49_02268870(PTR_AT(work, 0x3DC));
    }
    ov49_0225AA70(work);
    if (U8_AT(work, 3) == 0) {
        u32 value;
        flag = FLAGS_AT(work);
        if (flag == 1 || U8_AT(work, 6) == 1 || U8_AT(work, 0) == 1) {
            value = 1;
        } else {
            value = 0;
        }
        ov49_0225B518(P_AT(work, 0x184), work, value, 0x77);
    }
    ov49_02265378(PTR_AT(work, 0x3D4));
}

void ov49_0225AA2C(void *work) {
    Thunk_G3X_Reset();
    ov49_0225CBF4(PTR_AT(work, 0x3EC));
    ov49_0225E3A0(PTR_AT(work, 0x3E4));
    ov49_02258BD4(PTR_AT(work, 0x3E0));
    ov49_02265398(PTR_AT(work, 0x3D4));
    RequestSwap3DBuffers(0, 0);
    ov49_0225A7C0(P_AT(work, 0x3C));
}

void ov49_0225AA70(void *work) {
    int i;
    u32 state;
    u32 enabled;
    void *value = ov45_0222A394(PTR_AT(work, 0x34));
    for (i = 0; i < 3; i++) {
        state = ov45_0222F274(i);
        if (state == 1) {
            if (ov45_0222F294(i) == 0) {
                enabled = 1;
            } else {
                enabled = 0;
            }
        } else {
            enabled = 0;
        }
        ov49_0225E8C4(PTR_AT(work, 0x3E4), i, ov45_0222F314(i), state, enabled, value);
    }
}

void ov49_0225AAC8(void *window, void **bgConfig, void *saveData, u32 heapId) {
    AddWindowParameterized(*bgConfig, window, 1, 2, 0x13, 0x1B, 4, 4, 0x5E);
    FillWindowPixelBuffer(window, 0xF);
    PTR_AT(window, 0x18) = String_New(0x180, heapId);
    U32_AT(window, 0x14) = Options_GetTextFrameDelay(Save_PlayerData_GetOptionsAddr(saveData));
}

void ov49_0225AB14(void *window) {
    if (TextPrinterCheckActive((u8)U32_AT(window, 0x10))) {
        RemoveTextPrinter((u8)U32_AT(window, 0x10));
    }
    ov49_0225AC38(window);
    String_Delete(PTR_AT(window, 0x18));
    RemoveWindow(window);
}

void ov49_0225AB44(void *window, void *string) {
    if (TextPrinterCheckActive((u8)U32_AT(window, 0x10))) {
        RemoveTextPrinter((u8)U32_AT(window, 0x10));
    }
    FillWindowPixelBuffer(window, 0xF);
    String_Copy(PTR_AT(window, 0x18), string);
    U32_AT(window, 0x10) = AddTextPrinterParameterizedWithColor(window, 1, PTR_AT(window, 0x18), 0, 0, U32_AT(window, 0x14), 0x0001020F, NULL);
    DrawFrameAndWindow2(window, 1, 1, 1);
}

void ov49_0225ABA4(void *window, void *string) {
    if (TextPrinterCheckActive((u8)U32_AT(window, 0x10))) {
        RemoveTextPrinter((u8)U32_AT(window, 0x10));
    }
    FillWindowPixelBuffer(window, 0xF);
    String_Copy(PTR_AT(window, 0x18), string);
    AddTextPrinterParameterizedWithColor(window, 1, PTR_AT(window, 0x18), 0, 0, 0xFF, 0x0001020F, NULL);
    DrawFrameAndWindow2(window, 1, 1, 1);
    ScheduleWindowCopyToVram(window);
}

void ov49_0225AC08(void *window) {
    if (PTR_AT(window, 0x1C) != NULL) {
        GF_AssertFail();
    }
    PTR_AT(window, 0x1C) = WaitingIcon_New(window, 1);
}
