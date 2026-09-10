#include "network_communication_state_internal.h"

void sub_0203986C(void) {
    if (ov45_0222F464() == 1) {
        ov45_0222F154();
    }
    ov45_0222F70C();
    sub_020381C0(sub_02039E30, 0);
}

int sub_0203988C(void) {
    if (_021D4150 != NULL) {
        if (_021D4150->callback == sub_02039DC4) {
            return 2;
        }
        if (_021D4150->callback == sub_02039DE4) {
            return 1;
        }
        if (_021D4150->callback == sub_02039E30) {
            return 3;
        }
    }
    return 0;
}

void *sub_020398C8(void) {
    return _021D4150->allocation;
}

void sub_020398D4(int active, int flag) {
    if (_021D4150 != NULL) {
        _021D4150->flag53 = active;
        _021D4150->flag54 = flag;
        if (active) {
            _021D4150->pad4B = sub_02037454();
        } else {
            _021D4150->pad4B = 0;
        }
    }
    sub_020356C0(active);
    sub_020356EC(active);
}
