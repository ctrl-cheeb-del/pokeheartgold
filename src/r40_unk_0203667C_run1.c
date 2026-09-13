#include "r40_unk_0203667C_private.h"

void sub_0203667C(void) {
    int count = sub_02033FC4((u16)sub_0203993C()) + 1;
    int i;

    if (sub_02034044(sub_0203993C())) {
        if (!sub_020373B4(0)) {
            return;
        }
        if (*(int *)(_021D4140.work + 0x664) != 0) {
            if (!sub_02036630()) {
                return;
            }
            if (_0210F900[0] == 4) {
                if (sub_02035FF0() == 1) {
                    sub_02036438(0);
                }
                _0210F900[0] = 2;
            }
        } else {
            if (_0210F900[0] == 4) {
                if (sub_02035FF0() == 1) {
                    if (!sub_02036438(0)) {
                        return;
                    }
                }
            }
            _0210F900[0] = 2;
        }
        if (!ov00_021E602C(_021D4140.work + 0x80, 0xC0)) {
            return;
        }
        _0210F900[0] = 4;
        for (i = 0; i < count; i++) {
            if (sub_020373B4((u16)i)) {
                (*(int *)(_021D4140.work + i * 4 + 0x66C))++;
            }
        }
    } else {
        if (sub_02033298() != 4 || _0210F900[0] != 4 || !sub_02036630()) {
            return;
        }
        if (sub_02035FF0() == 0) {
            sub_02036F30(_021D4140.work + 0x80 + _021D4140.work[0x6B0] * 0xC0);
            sub_02036F30(_021D4140.work + 0x80 + (1 - _021D4140.work[0x6B0]) * 0xC0);
        }
        _0210F900[0] = 0;
        sub_02036508();
    }
}
