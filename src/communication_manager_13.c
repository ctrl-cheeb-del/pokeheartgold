#include "communication_manager_internal.h"

int sub_02037824(int value) {
    return sub_02033F9C(_021D4140.work + 0x5A0, value);
}

int sub_0203783C(void) {
    return sub_02033C50(_021D4140.work + 0x5A0);
}

int sub_02037854(void) {
    return sub_02033C50(_021D4140.work + 0x580);
}

void sub_0203786C(int value) {
    _021D4140.work[0x6B6] = value;
}

int sub_02037880(void) {
    return _021D4140.work[0x6B6];
}

void sub_02037894(int value, int slot) {
    if (_021D4140.work != NULL) {
        u8 *entry = _021D4140.work + slot;
        entry[0x6A6] = value;
    }
}

int sub_020378AC(int slot) {
    if (_021D4140.work != NULL) {
        u8 *entry = _021D4140.work + slot;
        if (entry[0x6A6] != 0xFF) {
            return entry[0x6A6];
        }
    }
    return slot;
}

int sub_020378CC(void) {
    if (sub_02034044(sub_0203993C())) {
        return ov00_021E7080();
    }
    return 0;
}

void sub_020378E4(int value) {
    int i;
    if (sub_02034044(sub_0203993C()) && *(int *)(_021D4140.work + 0x664) != value) {
        *(int *)(_021D4140.work + 0x664) = value;
        if (value != 0) {
            *(int *)(_021D4140.work + 0x668) = 0;
            for (i = 0; i < 8; i++) {
                *(int *)(_021D4140.work + 0x66C + i * 4) = 0;
            }
        }
    }
}

void sub_02037930(int value) {
    sub_020378E4(value);
    if (sub_02034044(sub_0203993C())) {
        if (value != 0) {
            ov00_021E70CC(0);
        } else {
            ov00_021E70CC(1);
        }
    }
}

BOOL sub_02037958(void) {
    return _021D4140.work[0x6B1] != 0;
}

void sub_02037974(void) {
    _021D4140.work[0x6B8] = 1;
}

void sub_02037988(void) {
    if (_021D4140.work != NULL) {
        _021D4140.work[0x6B9] = 1;
    }
}
