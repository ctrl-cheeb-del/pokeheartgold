#include "wireless_connection_state_internal.h"

void sub_02034D60(void *unused, int failed) {
    if (failed != 0) {
        OS_Terminate();
    }
    _021D4134.state = 2;
}

void sub_02034D78(void *unused) {
    _021D4134.state = 0;
    Sys_ClearSleepDisableFlag(4);
}

void sub_02034D8C(void) {
    Sys_SetSleepDisableFlag(4);
    _021D4134.state = 1;
    if (WVR_StartUpAsync(8, sub_02034D60, NULL) != 1) {
        OS_Terminate();
    }
}

BOOL sub_02034DB8(void) {
    return _021D4134.state == 2;
}

BOOL sub_02034DCC(void) {
    return _021D4134.state != 0;
}

void sub_02034DE0(void) {
    WVR_TerminateAsync(sub_02034D78, NULL);
}

void sub_02034DF0(int value) {
    u8 *buffer;
    u32 misalignment;

    *(u32 *)(_021D4134.work + 0xD70) = 0;
    buffer = *(u8 **)(_021D4134.work + 0xD64);
    misalignment = (u32)buffer & 0x1F;
    sub_02033528(buffer + (0x20 - misalignment), value);
    sub_02033234(*(void **)(_021D4134.work + 0xD80));
}

void sub_02034E2C(void) {
    int i;
    for (i = 0; i < 16; i++) {
        *(u16 *)(_021D4134.work + 0xD44 + i * 2) = 0;
    }
    MI_CpuFill8(_021D4134.work + 0x114, 0, 0xC00);
}

void sub_02034E64(BOOL value) {
    u8 bit = value;
    _021D4134.work[0xD95] = (_021D4134.work[0xD95] & ~8) | ((bit & 1) << 3);
}

void sub_02034E8C(void) {
    _021D4134.work[0xD74] = 0;
    _021D4134.work[0xD95] &= ~1;
    _021D4134.work[0xD95] &= ~4;
    _021D4134.work[0xD92] = 0;
    _021D4134.work[0xD95] &= ~0x10;
    _021D4134.work[0xD94] = 0;
    _021D4134.work[0xD93] = 0;
}

BOOL sub_02034EF0(int unused, BOOL active, BOOL flag) {
    u8 bit;
    (void)unused;
    sub_02034E8C();
    sub_02034E64(active);
    sub_02033A68();
    if (_021D4134.work[0xD93] == 0) {
        sub_020337D0(sub_02036904, 14);
        _021D4134.work[0xD93] = 1;
    }
    bit = flag;
    _021D4134.work[0xD95] = (_021D4134.work[0xD95] & ~0x20) | ((bit & 1) << 5);
    if (sub_02033298() == 1 && sub_020332C0() != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02034F64(int unused, BOOL configure) {
    Byte6 data;
    (void)unused;
    sub_02034E8C();
    if (configure) {
        sub_02034E2C();
    }
    if (_021D4134.work[0xD93] == 0) {
        sub_020337D0(sub_020367A8, 14);
        _021D4134.work[0xD93] = 1;
    }
    if (sub_02033298() == 1) {
        data = _020F6A88;
        if (sub_02032C1C((void (*)(void *))sub_02034C20, &data, 0) != 0) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL sub_02034FE8(void) {
    if (_021D4134.work == NULL) {
        return TRUE;
    }
    switch (_021D4134.work[0xD94]) {
    case 0:
        if (sub_02033990() != 0) {
            sub_02032E24();
            _021D4134.work[0xD94] = 1;
        } else if (sub_0203393C() == 0) {
            sub_02033858();
            _021D4134.work[0xD94] = 2;
        }
        break;
    case 1:
        if (sub_0203393C() == 0) {
            sub_02033858();
            _021D4134.work[0xD94] = 2;
        }
        break;
    case 2:
        if (sub_02033920() != 0) {
            return TRUE;
        }
        if (sub_02033958() != 0) {
            _021D4134.work[0xD94] = 1;
        }
        break;
    }
    return FALSE;
}

BOOL sub_0203507C(void) {
    if (_021D4134.work != NULL && _021D4134.work[0xD92] == 0) {
        _021D4134.work[0xD92] = 1;
        sub_02033858();
        return 1;
    }
    return 0;
}

void sub_020350A8(BOOL active) {
    if (_021D4134.work != NULL) {
        if (active) {
            _021D4134.work[0xD92] = 2;
        } else {
            _021D4134.work[0xD92] = 0;
            sub_02034DF0(1);
        }
    }
}

void sub_020350D4(void) {
    Heap_Free(*(void **)(_021D4134.work + 0xD7C));
    Heap_Free(*(void **)(_021D4134.work + 0xD64));
    Heap_Free(*(void **)(_021D4134.work + 0xD84));
    Heap_Free(_021D4134.work);
    _021D4134.work = NULL;
}
