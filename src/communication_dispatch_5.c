#include "communication_dispatch_internal.h"

u32 sub_020342B8(void) {
    return 0xFFFF;
}

u32 sub_020342C0(void) {
    return 0;
}

u32 sub_020342C4(void) {
    return 1;
}

u32 sub_020342C8(void) {
    return 2;
}

void sub_020342CC(int aid) {
    int i;
    if (sub_0203769C() == 0) {
        _021D412C->ready[aid] = 1;
        for (i = 0; i < 8; i++) {
            if (sub_020373B4((u16)i) != 0 && _021D412C->ready[i] == 0) {
                return;
            }
        }
        sub_02037108(14, 0, 0);
    }
}

void sub_02034310(int a, int b, void *arg) {
    _021D412C->table = NULL;
    _021D412C->count = 0;
    _021D412C->context = NULL;
    _021D412C->shutdown = 1;
    sub_020376E0(15, arg);
}

void sub_02034338(int aid) {
    if (sub_0203769C() == 0) {
        _021D412C->ready[aid] = 0;
    }
}
