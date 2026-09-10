#include "network_communication_state_internal.h"

int sub_02038C18(void) {
    return 6;
}

void sub_02038C1C(int mode) {
    if (_021D4150 != NULL) {
        _021D4150->mode4A = mode;
        sub_02033908(mode);
    }
}

void sub_02038C34(void) {
    sub_0203528C();
}
