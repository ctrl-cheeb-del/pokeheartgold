#include "network_communication_state_internal.h"

void sub_02038E00(void) {
    if (sub_02034DB8()) {
        sub_02034B0C(_021D4150->profile, 1);
        sub_02034354(_021D4150->saveData, 0);
        if (sub_02035ED8(1, 1, 0x200, 1)) {
            sub_02035FD8();
            sub_020381C0(sub_02038260, 0);
        }
    }
}

void sub_02038E48(void) {
    if (sub_02034DB8()) {
        sub_02034B0C(_021D4150->profile, 1);
        sub_02034354(_021D4150->saveData, 0);
        if (sub_02035F14(1, 1, 0x200)) {
            sub_02035FD8();
            sub_020381C0(sub_020382DC, 0);
        }
    }
}

void sub_02038E90(void) {
}

void sub_02038E94(void) {
    if (ov00_021E5E54(0) < 0) {
        sub_020381C0(sub_02038E90, 0);
    }
}

void sub_02038EB0(void) {
}

void sub_02038EB4(void) {
}
