#include "network_communication_state_internal.h"

void sub_02038918(int request) {
    _021D4150->request4D = request;
    _021D4150->state48 = 3;
    sub_020381C0(sub_020389BC, 0);
}

void sub_0203893C(void) {
    _021D4150->activity4E = 7;
}

void sub_0203894C(int request) {
    _021D4150->request4D = request;
    _021D4150->activity4E = 7;
    _021D4150->state48 = 3;
    sub_0203A880();
    sub_020381C0(sub_02038668, 0);
}

void sub_0203897C(void) {
    _021D4150->activity4E = 0x1A;
}

void sub_0203898C(int request) {
    _021D4150->request4D = request;
    _021D4150->activity4E = 0x1A;
    _021D4150->state48 = 3;
    sub_0203A880();
    sub_020381C0(sub_02038668, 0);
}

void sub_020389BC(void) {
    if (sub_02034FE8()) {
        sub_020381C0(sub_020389D4, 0);
    }
}

void sub_020389D4(void) {
    if (sub_02035664()) {
        _021D4150->activity4E = 13;
        if (sub_02035F14(0, 0, 0x200)) {
            sub_02035FE4();
            sub_020381C0(sub_02038A10, 100);
        }
    }
}
