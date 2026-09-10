#include "link_lobby_internal.h"

void sub_02058328(void) {
}

void sub_0205832C(void) {
    if (sub_02034DB8()) {
        ov03_02255BEC();
        sub_020582F4(sub_02058348, 0);
    }
}

void sub_02058348(void) {
}

void sub_0205834C(void) {
    sub_02037E1C(_021D41C8->mode);
    sub_020582F4(sub_0205836C, 0);
}

void sub_0205836C(void) {
    if (sub_02037EC8()) {
        sub_02034434();
        sub_020582F4(sub_02058388, 0);
    }
}

void sub_02058388(void) {
}

void sub_0205838C(void) {
    if (sub_02037B38(98)) {
        void *data = Heap_Alloc((enum HeapID)15, sub_02057180());
        sub_02056D7C(data, _021D41C8->fieldSystem, 0);
        sub_02057F80();
        sub_02037504();
        sub_02037AC0(92);
        sub_020582F4(sub_020583EC, 0);
        return;
    }
    if (_021D41C8->timer) {
        _021D41C8->timer--;
        return;
    }
    _021D41C8->timer = 30;
    sub_02037AC0(98);
}

void sub_020583EC(void) {
    if (sub_0203769C() == 0) {
        sub_02034638();
    }
    if (sub_02037B38(92)) {
        BeginNormalPaletteFade((enum FadeMode)0, (enum FadeType)1, (enum FadeType)1, 0, 6, 1, (enum HeapID)4);
        ResetVisibleHardwareWindows((PMLCDTarget)0);
        ResetVisibleHardwareWindows((PMLCDTarget)1);
        sub_02056E60();
        sub_0205701C(0);
        sub_020582F4(sub_02058478, 1);
    }
}

void sub_02058444(void) {
    if (_021D41C8->timer) {
        _021D41C8->timer--;
        return;
    }
    if (sub_02037B38(30)) {
        sub_020374E4();
        sub_020582F4(sub_02058608, 0);
    }
}

void sub_02058478(void) {
    if (_021D41C8->timer) {
        _021D41C8->timer--;
        return;
    }
    if (sub_0203769C() == 0) {
        if (sub_02057E50() == 0) {
            return;
        }
        sub_02037AC0(30);
    } else {
        sub_02037AC0(30);
    }
    sub_020582F4(sub_02058444, 20);
}

void sub_020584BC(void) {
    if (sub_02037B38(98)) {
        void *data = Heap_Alloc((enum HeapID)15, sub_02057180());
        sub_02056D7C(data, _021D41C8->fieldSystem, 0);
        sub_02057F80();
        sub_02037AC0(92);
        sub_020582F4(sub_02058518, 0);
        return;
    }
    if (_021D41C8->timer) {
        _021D41C8->timer--;
        return;
    }
    _021D41C8->timer = 30;
    sub_02037AC0(98);
}

void sub_02058518(void) {
    if (sub_0203769C() == 0) {
        sub_02034638();
    }
    if (sub_02037B38(92)) {
        u8 flag;
        sub_02056E60();
        sub_0205701C(0);
        flag = 1;
        sub_020376E0(94, &flag);
        BeginNormalPaletteFade((enum FadeMode)0, (enum FadeType)1, (enum FadeType)1, 0, 6, 1, (enum HeapID)4);
        ResetVisibleHardwareWindows((PMLCDTarget)0);
        ResetVisibleHardwareWindows((PMLCDTarget)1);
        sub_020582F4(sub_020586EC, 0);
    }
}
