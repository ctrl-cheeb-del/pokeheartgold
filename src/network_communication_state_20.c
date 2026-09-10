#include "network_communication_state_internal.h"

void sub_020397C8(void) {
    if (_021D4150 != NULL) {
        sub_020381C0(sub_02039D78, 0);
    }
}

int sub_020397E4(void) {
    if (_021D4150 == NULL) {
        return 0;
    }
    return _021D4150->active64;
}

BOOL sub_020397FC(void) {
    NetworkState *state = _021D4150;
    if (state != NULL && state->callback == sub_02039DC0) {
        return TRUE;
    }
    return FALSE;
}
