#include "network_communication_state_internal.h"

void sub_02038508(void) {
    sub_0203528C();
    if (_021D4150->delay44 != 0) {
        _021D4150->delay44--;
        return;
    }
    if (sub_02034FE8()) {
        sub_020381C0(sub_02038550, 0);
    }
}

void sub_02038538(void) {
    if (sub_02034FE8()) {
        sub_020381C0(sub_02038550, 0);
    }
}
