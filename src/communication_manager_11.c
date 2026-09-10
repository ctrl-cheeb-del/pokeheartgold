#include "communication_manager_internal.h"

int sub_020373B4(int slot) {
    if (_021D4140.work == NULL) {
        return 0;
    }
    if (sub_02034044(sub_0203993C())) {
        if (_021D4140.work[0x6B6] != 0) {
            u16 mask = ov00_021EE4FC();
            if ((mask & (1 << slot)) != 0) {
                return 1;
            }
        }
        return 0;
    }
    if (!sub_02037474()) {
        return 0;
    }
    if (sub_02033298() != 4) {
        return 0;
    }
    if (slot == sub_0203769C()) {
        return 1;
    }
    if (sub_0203769C() == 0) {
        if ((sub_02033250() & (1 << slot)) != 0) {
            return 1;
        }
    } else if ((*(u16 *)(_021D4140.work + 0x694) & (1 << slot)) != 0) {
        return 1;
    }
    return 0;
}

int sub_02037454(void) {
    int count = 0;
    int i;
    for (i = 0; i < 8; i++) {
        if (sub_020373B4((u16)i)) {
            count++;
        }
    }
    return count;
}

int sub_02037474(void) {
    if (_021D4140.work != NULL && sub_02034044(sub_0203993C())) {
        return 1;
    }
    return sub_02035650();
}

void sub_02037498(int value) {
    _021D4140.work[0x65F] = value;
}

int sub_020374AC(int slot) {
    u8 *entry = _021D4140.work + slot;
    return entry[0x654];
}

u16 sub_020374C0(int slot) {
    u16 value;
    if (_021D4140.work == NULL) {
        return 0;
    }
    value = ((u16 *)(_021D4140.work + 0x644))[slot];
    ((u16 *)(_021D4140.work + 0x644))[slot] = 0;
    return value;
}

void sub_020374E4(void) {
    if (_021D4140.work != NULL) {
        *(u16 *)(_021D4140.work + 0x65C) |= 0x8000;
    }
}

void sub_02037504(void) {
    if (_021D4140.work != NULL) {
        *(u16 *)(_021D4140.work + 0x65C) = 0;
    }
}

int sub_0203751C(void) {
    if (_021D4140.work != NULL) {
        return *(u16 *)(_021D4140.work + 0x65C) & 0x8000;
    }
    return 1;
}

int sub_0203753C(void *data, void *size, int arg) {
    if (sub_02035FF0() == 1) {
        return sub_02033DF0(_021D4140.work + 0x580, data, (int)size, arg, 1, 0);
    }
    return sub_02033DF0(_021D4140.work + 0x5A0, data, (int)size, arg, 1, 0);
}
