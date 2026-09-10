#include "communication_manager_internal.h"

BOOL sub_02036FA8(void) {
    int divisor = _021D4140.work[0x6BB];
    if (divisor == 0) {
        return FALSE;
    }
    if (_021D4140.work[0x6BC] % divisor == 0) {
        return TRUE;
    }
    return FALSE;
}

int sub_02036FD8(void *data, void *size, int arg) {
    if (!sub_020373B4(sub_0203769C())) {
        return 0;
    }
    if (sub_02033DF0(_021D4140.work + 0x580, data, (int)size, arg, 1, 0)) {
        return 1;
    }
    if (sub_0203993C() == 10) {
        sub_02037974();
    }
    return 0;
}

int sub_02037030(void *data, void *size, int arg) {
    if (!sub_020373B4(sub_0203769C())) {
        return 0;
    }
    if (sub_02033DF0(_021D4140.work + 0x580, data, (int)size, arg, 1, 1)) {
        return 1;
    }
    if (sub_0203993C() == 10) {
        sub_02037974();
    }
    return 0;
}

int sub_02037088(void *data, void *size, int arg) {
    if (sub_0203769C() != 0) {
        GF_AssertFail();
        return 0;
    }
    if (!sub_020373B4(0)) {
        return 0;
    }
    if (sub_02035FF0() == 1) {
        return sub_02036FD8(data, size, arg);
    }
    if (sub_02033DF0(_021D4140.work + 0x5A0, data, (int)size, arg, 1, 0)) {
        return 1;
    }
    if (sub_0203993C() == 10) {
        sub_02037974();
    }
    return 0;
}

int sub_02037108(void *data, void *size, int arg) {
    if (sub_0203769C() != 0) {
        sub_02037974();
        return 0;
    }
    if (!sub_020373B4(0)) {
        return 0;
    }
    if (sub_02035FF0() == 1) {
        return sub_02037030(data, size, arg);
    }
    if (sub_02033DF0(_021D4140.work + 0x5A0, data, (int)size, arg, 1, 1)) {
        return 1;
    }
    if (sub_0203993C() == 10) {
        sub_02037974();
    }
    return 0;
}

int sub_02037184(void *a, void *b) {
    return sub_02037108(a, b, 0);
}

int sub_02037190(void) {
    return sub_02033BE4(_021D4140.work + 0x498);
}

void sub_020371A8(void *a, int b, int c, void *d, PacketCursor *cursor) {
    sub_02034170(a, b, c, d);
    cursor->type = 0xEE;
    cursor->size = 0xFFFF;
    cursor->buffer = NULL;
    cursor->pos = 0;
}
