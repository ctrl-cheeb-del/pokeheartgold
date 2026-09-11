#include "unk_02039BA0_internal.h"

void sub_02039BA0(void) {
    if (sub_02034DB8()) {
        Heap_CreateAtEnd(3, 0x30, 0x60000);
        if (sub_02035ED8(1, 1, 0x200, 1)) {
            int value = sub_02033FC4(_021D4150->activity4E);
            ov00_021E5900(_021D4150->saveData, 0x30, 0x58000, value + 1);
            ov00_021E6CA4(sub_020399DC);
            sub_02035FD8();
            ov00_021E70B8(0);
            sub_020378E4(0);
            sub_020381C0(sub_0203960C, 0xE10);
        }
    }
}

void sub_02039C14(void) {
    _021D4150->delay44--;
    if (_021D4150->delay44 <= 0) {
        sub_020381C0(sub_02038E90, 0);
        return;
    }
    sub_0203786C(1);
    if (sub_02039D3C() && ov45_0222E8F4()) {
        sub_020381C0((NetworkStateFunc)sub_02039C60, 0);
    }
}

void sub_02039C60(void) {
    if (sub_02039D3C() == FALSE) {
        return;
    }
}

BOOL sub_02039C6C(int value) {
    BOOL result = TRUE;
    if (value >= 10 && value < 20) {
        sub_020381C0(sub_02038EB4, 0);
        result = FALSE;
    } else if (value < 0) {
        sub_020381C0(sub_02038E90, 0);
        result = FALSE;
    } else if (value == 23) {
        sub_020381C0(sub_02039E7C, 0);
        result = FALSE;
    } else if (value == 24) {
        result = FALSE;
        if (_021D4150->flag53 != 0) {
            sub_020381C0(sub_02038E90, result);
        } else {
            sub_020381C0(sub_02038EB0, result);
        }
    }
    if (_021D4150->flag53 != 0 && _021D4150->comparison4B != sub_02037454()) {
        sub_020381C0(sub_02038E90, 0);
        result = FALSE;
    }
    return result;
}

BOOL sub_02039D08(void) {
    BOOL result = TRUE;
    switch (ov45_0222E6C8()) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        sub_020381C0(sub_02039DC0, 0);
        result = FALSE;
        break;
    }
    return result;
}

BOOL sub_02039D3C(void) {
    BOOL result = sub_02039C6C(ov00_021E5E54(0));
    if (result != FALSE) {
        result = sub_02039D08();
    }
    return result;
}

void sub_02039D54(int *value) {
    int state;
    state = ov00_021E5E54(0);
    if (state >= 20) {
        *value = state;
    } else {
        *value = 0;
        if (!sub_02039C6C(state)) {
            return;
        }
    }
    sub_02039D08();
}
