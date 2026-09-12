#include "network_state_handshake_private.h"

void sub_02038A10(void) {
    if (sub_020351AC(_021D4150->request4D) && sub_020360E4(_021D4150->request4D)) {
        sub_020381C0(sub_02038A94, 100);
        return;
    }

    if (sub_02037700() || _021D4150->delay44 == 0) {
        _021D4150->state48--;
        if (_021D4150->state48 == 0) {
            sub_020381C0(sub_02038800, 0);
        } else {
            sub_020381C0(sub_020389BC, 0);
        }
    } else {
        if (_021D4150->delay44 != 0) {
            _021D4150->delay44--;
        }
    }
}

void sub_02038A94(void) {
    if (_021D4150->delay44 > 90) {
        _021D4150->delay44--;
        return;
    }

    if (sub_02037700()) {
        _021D4150->state48--;
        if (_021D4150->state48 == 0) {
            sub_020381C0(sub_02038800, 0);
        } else {
            sub_020381C0(sub_020389BC, 0);
        }
        return;
    }

    sub_0203769C();
    if (sub_020373B4()) {
        sub_020381C0(sub_020387E8, 0);
        return;
    }

    if (_021D4150->delay44 != 0) {
        _021D4150->delay44--;
    } else {
        _021D4150->state48--;
        if (_021D4150->state48 == 0) {
            sub_020381C0(sub_02038800, 0);
        } else {
            sub_020381C0(sub_020389BC, 0);
        }
    }
}
