#include "network_communication_state_internal.h"

void sub_02038CE8(void) {
    if (sub_02034DB8()) {
        sub_02034B0C(_021D4150->profile, 0);
        sub_02034354(_021D4150->saveData, 0);
        sub_02033A7C(sub_02038C3C);
        sub_020381C0(sub_02038CC4, 0);
    }
}

void sub_02038D28(void *saveData) {
    if (sub_02037474() == 0) {
        Heap_CreateAtEnd(3, 15, 0x7000);
        sub_02037C98(saveData, 0x11);
        _021D4150->parameter4F = 0;
        sub_020381C0(sub_02038CE8, 0);
    }
}

void sub_02038D64(void) {
    if (_021D4150 != NULL) {
        sub_020381C0(sub_0203847C, 5);
    }
}

u8 sub_02038D80(void) {
    return _021D4150->result58;
}
