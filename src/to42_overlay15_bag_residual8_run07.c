#include "to42_overlay15_bag_residual8_private.h"

int ov15_021FB604(void *work) {
    u8 *state;
    u8 *slot;
    int count;
    ov15_02200294(work);
    ov15_021FF560(work);
    ov15_021FF7AC((u8 *)work + 0x184);
    state = PTR(work, 0x234);
    count = ov15_021FA074(work);
    slot = state + 4 + U8_AT(state, 0x64) * 12;
    ov15_02200140(work, slot, count, 0);
    ov15_021FE868(work);
    ov15_021FED3C(work);
    ov15_021FB518(work);
    return 1;
}

void ov15_021FB654(void *work) {
    void (*func)(void *);
    ov15_02200294(work);
    ov15_021FF7AC((u8 *)work + 0x184);
    func = *(void (**)(void *))((u8 *)work + 0x7f0 + U32_AT(work, 0x948) * 4);
    func(work);
}

int ov15_021FB680(void *work) {
    void *func;
    int result;
    ov15_021FD788(work, 0);
    ov15_021FFF24(work);
    func = GetItemFieldUseFunc(2, GetItemAttr(U16_AT(PTR(work, 0x234), 0x66), 6, 6));
    if (func != NULL && (result = ((int (*)(void *))func)(PTR(PTR(work, 0x234), 0x70))) != 0) {
        GetItemUseErrorMessage(PTR(work, 0x23c), PTR(work, 0x5e4), U16_AT(PTR(work, 0x234), 0x66), result, 6);
        U8_AT(work, 0x616) = ov15_021FEF48(work, 0);
        return 12;
    }
    return ov15_021FB784(work);
}

int ov15_021FB700(void *work) {
    if (!TextPrinterCheckActive(U8_AT(work, 0x616))) {
        if ((gSystem.newKeys & 3) || gSystem.touchNew) {
            if (U8_AT(PTR(work, 0x234), 0x65) != 3) {
                ov15_021FED3C(work);
            }
            ClearFrameAndWindow2((u8 *)work + 0x34, 1);
            ClearWindowTilemapAndScheduleTransfer((u8 *)work + 0x34);
            ScheduleWindowCopyToVram((u8 *)work + 4);
            ov15_021FD788(work, 1);
            ov15_021FB518(work);
            return U8_AT(PTR(work, 0x234), 0x65) == 3 ? 26 : 1;
        }
    }
    return 12;
}

int ov15_021FB784(void *work) {
    u8 *slot = (u8 *)PTR(work, 0x234) + 4 + U8_AT(PTR(work, 0x234), 0x64) * 12;
    U8_AT(work, 0x67b) = 0;
    if (U8_AT(slot, 8) == 3) {
        PTR(work, 0x67c) = ov15_021FB830;
        return 13;
    }
    if (TryFormatRegisteredKeyItemUseMessage(PTR(PTR(work, 0x234), 0), PTR(work, 0x5e4), U16_AT(PTR(work, 0x234), 0x66), 6) == TRUE) {
        U8_AT(work, 0x616) = ov15_021FEF48(work, 0);
        return 12;
    }
    if (BagApp_TryUseItemInPlace(work, U16_AT(PTR(work, 0x234), 0x66)) == TRUE) {
        PTR(work, 0x67c) = ov15_021FBBB0;
        return 13;
    }
    sub_020880CC(1, 6);
    U16_AT(PTR(work, 0x234), 0x68) = 0;
    return 0x25;
}
