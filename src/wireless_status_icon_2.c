#include "wireless_status_icon_internal.h"

void sub_0203A86C(void) {
    if (_021D4154 != NULL) {
        sub_0203A700(_021D4154);
    }
}

void sub_0203A880(void) {
    int a = 0;

    if (sub_02039998() != 0) {
        a = 1;
    }
    sub_0203A8CC(0xF0, 0, a, 1, 0x1C0);
}

void sub_0203A8A8(int a0) {
    int a = 0;

    if (sub_02039998() != 0) {
        a = 1;
    }
    sub_0203A8CC(0xF0, 0, a, a0, 0x1E0);
}

void sub_0203A8CC(int a0, int a1, int a2, int a3, u32 a4) {
    if (sub_02034DCC() != 0) {
        if (_021D4154 != NULL) {
            sub_0203A914();
        }
        _021D4154 = sub_0203A3B0(0, (enum HeapID)0x59, a0, a1, a2, _0210F91C, a3, a4);
    }
}

void sub_0203A914(void) {
    if (_021D4154 != NULL) {
        sub_0203A444(_021D4154);
        _021D4154 = NULL;
    }
}

void sub_0203A930(s32 a0) {
    if (_021D4154 != NULL) {
        sub_0203A438(_021D4154, a0);
    }
}

void sub_0203A948(int a0, enum HeapID a1) {
    if (_021D4154 != NULL) {
        sub_0203A478(_021D4154, a0, a1);
    }
}

void sub_0203A964(void) {
    if (sub_02037474()) {
        if (sub_02037454() > 1 || sub_02039998() != 0) {
            sub_0203A880();
        }
    } else if (sub_02039998() != 0) {
        sub_0203A880();
    }
}

void sub_0203A994(int a0) {
    if (sub_02037474()) {
        if (sub_02037454() > 1 || sub_02039998() != 0) {
            sub_0203A8A8(a0);
        }
    } else if (sub_02039998() != 0) {
        sub_0203A8A8(a0);
    }
}

void sub_0203A9C8(void) {
    if (_021D4154 != NULL) {
        _021D4154->unk22 = 1;
    }
}
