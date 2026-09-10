#include "network_communication_state_internal.h"

BOOL sub_02038070(void) {
    NetworkState *state = _021D4150;
    if (state == NULL) {
        return TRUE;
    }
    if (state->callback != sub_02038538) {
        return TRUE;
    }
    return FALSE;
}

void sub_02038094(void) {
    if (_021D4150 != NULL) {
        sub_020381C0(sub_0203847C, 5);
    }
}

void sub_020380B0(void) {
    if (_021D4150 != NULL) {
        _021D4150->cancel57 = 1;
        sub_02033AA4(1);
    }
}

void sub_020380CC(void) {
    if (_021D4150 != NULL) {
        _021D4150->cancel57 = 1;
        sub_02033AA4(1);
        sub_020381C0(sub_020388A8, 0);
    }
}

void sub_020380F4(void) {
    _021D4150->activity4E = 0x12;
}

void sub_02038104(void) {
    _021D4150->activity4E = 9;
}

void sub_02038114(void *saveData, int mode) {
    if (sub_02037474() == 0) {
        Heap_CreateAtEnd(3, 15, 0x7080);
        sub_02037C98(saveData, mode);
        sub_020381C0(sub_02038E00, 0);
    }
}

void sub_02038148(void *saveData, int mode) {
    if (sub_02037474() == 0) {
        Heap_CreateAtEnd(3, 15, 0x7080);
        sub_02037C98(saveData, mode);
        sub_020381C0(sub_02038E48, 0);
    }
}

void sub_0203817C(void) {
    if (_021D4150 != NULL && _021D4150->callback != NULL) {
        _021D4150->callback();
    }
    if (sub_02039998()) {
        sub_0203A930(3 - ov00_021EC9D4());
    } else if (sub_02035650()) {
        sub_0203A930(3 - WM_GetLinkLevel());
    }
}

void sub_020381C0(NetworkStateFunc callback, int delay) {
    _021D4150->callback = callback;
    _021D4150->delay44 = delay;
}

void sub_020381D0(void) {
    if (sub_02039998() != 0 || (sub_02035664() != 0 && (sub_020374E4(), sub_020350A8(1), TRUE))) {
        sub_020381C0(sub_02038404, 0);
    }
}

void sub_020381FC(void) {
    if (sub_02034FE8()) {
        sub_0203622C();
        sub_020381C0(sub_020381D0, 0);
    }
}

void sub_02038218(void) {
    if (sub_02034DB8()) {
        sub_02034B0C(_021D4150->profile, 1);
        sub_02034354(_021D4150->saveData, _021D4150->userData);
        if (sub_02035ED8(1, 1, 0x200, 1)) {
            sub_02035FD8();
            sub_020381C0(sub_02038260, 0);
        }
    }
}

void sub_02038260(void) {
    sub_0203769C();
    if (sub_020373B4()) {
        sub_020381C0(sub_0203827C, 0);
    }
}

void sub_0203827C(void) {
    if (sub_02037474() == 0) {
        sub_020381C0(sub_02038408, 0);
    }
}

void sub_02038294(void) {
    if (sub_02034DB8()) {
        sub_02034B0C(_021D4150->profile, 1);
        sub_02034354(_021D4150->saveData, _021D4150->userData);
        if (sub_02035F14(1, 1, 0x200)) {
            sub_02035FD8();
            sub_020381C0(sub_020382DC, 0);
        }
    }
}

void sub_020382DC(void) {
    sub_0203528C();
}

void sub_020382E4(void) {
    sub_0203528C();
    if (sub_020360E4(_021D4150->request4D)) {
        sub_020381C0(sub_0203830C, 10);
    }
}

void sub_0203830C(void) {
    if (sub_02037700()) {
        sub_020381C0(sub_02038344, 0);
    }
    sub_0203769C();
    if (sub_020373B4() && sub_0203769C()) {
        sub_020381C0(sub_02038398, 0);
    }
}

void sub_02038344(void) {
    sub_02034FE8();
    sub_020381C0(sub_02038358, 2);
}

void sub_02038358(void) {
    if (_021D4150->delay44 != 0) {
        _021D4150->delay44--;
        return;
    }
    if (sub_02035664() && sub_02035F14(0, 1, 0x200)) {
        sub_02035FD8();
        sub_020381C0(sub_020382E4, 10);
    }
}

void sub_02038398(void) {
    if (sub_02037474() == 0) {
        sub_020381C0(sub_02038408, 0);
    }
}

void sub_020383B0(void) {
    sub_02034FE8();
    sub_020381C0(sub_020383C4, 2);
}

void sub_020383C4(void) {
    if (_021D4150->delay44 != 0) {
        _021D4150->delay44--;
        return;
    }
    if (sub_02035664() && sub_02035F14(0, 1, 0x200)) {
        sub_02035FD8();
        sub_020381C0(sub_020382DC, 10);
    }
}

void sub_02038404(void) {
}

void sub_02038408(void) {
    if (sub_02037474() == 0) {
        sub_02037D2C();
    }
}

void sub_02038418(void) {
    if (sub_02037454() <= 1) {
        sub_02033ACC(0);
        sub_0203624C();
        sub_020381C0(sub_02038538, 0);
    }
    if (_021D4150->delay44 != 0) {
        _021D4150->delay44--;
        return;
    }
    sub_02033ACC(0);
    sub_0203624C();
    sub_020381C0(sub_02038538, 0);
}

void sub_02038460(void) {
    if (sub_02034FE8()) {
        sub_0203622C();
        sub_020381C0(sub_02038538, 0);
    }
}

void sub_0203847C(void) {
    if (_021D4150->delay44 != 0) {
        _021D4150->delay44--;
    }
    if (sub_02034FE8() && _021D4150->delay44 == 0) {
        sub_02036024();
        sub_020381C0(sub_02038408, 0);
    }
}
