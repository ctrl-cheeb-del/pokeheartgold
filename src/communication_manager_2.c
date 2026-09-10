#include "communication_manager_internal.h"

void sub_02035E9C(void) {
    int i;
    for (i = 1; i < 8; i++) {
        if (!sub_020373B4((u16)i) && _021D4140.work[0x69E + i] == 0) {
            sub_02035DE0(i);
        }
    }
}

void sub_02035ED0(int slot) {
    sub_02035DE0(slot);
}

int sub_02035ED8(int a, int b, int c, int d) {
    int result = 1;
    if (!sub_02034044(sub_0203993C())) {
        result = sub_02034EF0(a, b, d);
        sub_02033A90(sub_02035ED0);
    }
    sub_02035900(a, c);
    return result;
}

int sub_02035F14(int a, int b, int c) {
    int result = 1;
    if (!sub_02034044(sub_0203993C())) {
        result = sub_02034F64(a, b);
    }
    sub_02035900(a, c);
    _0210F900[1] = 4;
    return result;
}

void sub_02035F4C(void) {
    int changed = 0;
    if (sub_0203769C() == 0) {
        if (_0210F900[0] != 4) {
            return;
        }
    } else if (_0210F900[1] != 4) {
        return;
    }
    if (_021D4140.work[0x6AD] == 2) {
        _021D4140.work[0x6AD] = 0;
        changed = 1;
    }
    if (_021D4140.work[0x6AD] == 3) {
        changed = 1;
        _021D4140.work[0x6AD] = 1;
    }
    if (changed) {
        sub_02035DD8();
    }
    sub_02037594();
}

void sub_02035FA8(int connected) {
    int state = _021D4140.work[0x6AD];
    if (state == 0 && connected == 1) {
        _021D4140.work[0x6AD] = 3;
        return;
    }
    if (state == 1 && connected == 0) {
        _021D4140.work[0x6AD] = 2;
    }
}

void sub_02035FD8(void) {
    sub_02035FA8(1);
}

void sub_02035FE4(void) {
    sub_02035FA8(0);
}

int sub_02035FF0(void) {
    int state = _021D4140.work[0x6AD];
    if (state == 2) {
        return 1;
    }
    if (state == 3) {
        return 0;
    }
    return state;
}

BOOL sub_02036010(void) {
    if (sub_02035FF0() == 1) {
        return TRUE;
    }
    return FALSE;
}

void sub_02036024(void) {
    int destroy = 0;
    if (_021D4140.work != NULL) {
        if (sub_02034044(sub_0203993C())) {
            ov00_021E6CB8();
            destroy = 1;
        } else if (sub_0203507C()) {
            destroy = 1;
        }
    }
    if (destroy) {
        sub_020379F8();
        sub_020343E4();
        _021D4140.updateLock = 0;
        SysTask_Destroy(*(void **)(_021D4140.work + 0x57C));
        *(void **)(_021D4140.work + 0x57C) = NULL;
        Heap_Free(*(void **)(_021D4140.work + 0x490));
        Heap_Free(*(void **)(_021D4140.work + 0x494));
        Heap_Free(*(void **)(_021D4140.work + 0x48C));
        Heap_Free(*(void **)(_021D4140.work + 0x488));
        sub_02033F90(_021D4140.work + 0x5A0);
        sub_02033F90(_021D4140.work + 0x580);
        Heap_Free(_021D4140.allocation);
        _021D4140.work = NULL;
        _021D4140.allocation = NULL;
    }
}

int sub_020360E4(int value) {
    return sub_02035218(value);
}

void sub_020360EC(void) {
    if (_021D4140.updateLock != 0) {
        sub_02036AD8();
        if (sub_0203769C() == 0 && sub_020373B4(0)) {
            sub_02036508();
        }
        _021D4140.updateLock = 0;
    }
}

void sub_0203611C(void) {
    if (sub_020357FC()) {
        if (sub_0203769C() == 0) {
            if (sub_0203567C() == 0) {
                sub_02036024();
            }
        } else {
            sub_02036024();
        }
    }
}
