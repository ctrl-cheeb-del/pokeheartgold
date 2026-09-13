#include "r40_unk_02036144_private.h"

BOOL sub_02036144(void) {
    u8 *work;

    sub_0203817C();
    work = _021D4140.work;
    if (work != NULL) {
        if (work[0x6B9] == 0) {
            work[0x6BC]++;
            _021D4140.updateLock = 0;
            sub_02035F4C();
            work = _021D4140.work;
            *(u16 *)(work + 0x65C) |= gSystem.heldKeys & 0x7FFF;
            sub_02036BE4();
            sub_02036298();
            work = _021D4140.work;
            *(u16 *)(work + 0x65C) &= 0x8000;
            if (sub_02035FF0() == 0) {
                sub_020372E4();
            }
            if (sub_0203769C() == 0 && sub_020373B4(0) != 0) {
                sub_0203993C();
                if (sub_02034084() == 0) {
                    sub_0203667C();
                }
            }
            if (sub_0203769C() == 0 || sub_02035FF0() == 1) {
                sub_02037334();
            }
            _021D4140.updateLock = 1;
        }
        sub_020355C8(*(u16 *)(_021D4140.work + 0x694));
        if (sub_0203769C() == 0) {
            sub_02035E9C();
        }
        sub_0203611C();
    } else {
        sub_020355C8(0);
    }
    sub_02039A00(0);
    sub_02037ADC();
    return TRUE;
}
