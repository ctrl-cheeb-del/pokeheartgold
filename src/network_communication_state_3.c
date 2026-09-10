#include "network_communication_state_internal.h"

void sub_02037E9C(void) {
    if (_021D4150 != NULL) {
        _021D4150->timeout40 = 0x708;
        sub_020381C0(sub_02037E4C, 5);
    }
}

int sub_02037EC0(void) {
    return sub_02033A0C();
}
