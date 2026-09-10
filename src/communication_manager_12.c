#include "communication_manager_internal.h"

void sub_02037618(void *a, void *b, const u8 *data) {
    if (sub_0203769C() == 0) {
        _021D4140.work[0x6AB] = 1;
        _021D4140.work[0x6AC] = *data;
    }
}

void sub_02037640(void *a, void *b, const u8 *data) {
    if (sub_0203769C() != 0) {
        _021D4140.work[0x6AC] = *data;
        _021D4140.work[0x6AB] = 3;
    }
}

void sub_02037668(void *a, void *b, const u8 *data) {
    if (sub_0203769C() == 0 && _021D4140.work[0x6AB] == 2) {
        sub_02035FA8(*data);
        _021D4140.work[0x6AB] = 0;
    }
}

int sub_0203769C(void) {
    if (_021D4140.work != NULL) {
        if (sub_02034044(sub_0203993C())) {
            int id = ov00_021E6964();
            if (id != -1) {
                return (u16)id;
            }
        } else {
            return sub_020338F4();
        }
    }
    return 0;
}

int sub_020376D4(void *a, void *b) {
    return sub_02036FD8(a, b, 0);
}

int sub_020376E0(void *a, void *b) {
    return sub_02037030(a, b, 0);
}

int sub_020376EC(void *a) {
    return sub_02037030(a, NULL, 0);
}

int sub_020376F8(void) {
    return sub_0203567C();
}

int sub_02037700(void) {
    if (_021D4140.work != NULL && _021D4140.work[0x6B8] != 0) {
        sub_020398D4(1, 1);
        return 1;
    }
    return sub_0203569C();
}

int sub_0203772C(u16 trainerId) {
    if ((u32)sub_02033FC4(trainerId) >= 5) {
        return 12;
    }
    if (sub_02035FF0() == 0) {
        return 12;
    }
    return 0x26;
}

int sub_0203774C(int value) {
    return sub_02033FC4((u16)value) + 1;
}

int sub_0203775C(int value) {
    return sub_02033FF0((u16)value) + 1;
}

void sub_0203776C(void) {
    u8 value;
    if (!sub_020357FC() && !sub_0203769C()) {
        sub_02037184((void *)2, &value);
    }
    sub_0203581C();
}
