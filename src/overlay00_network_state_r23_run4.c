#include "overlay00_network_state_r23_private.h"

int ov00_021E6964(void) {
    if (_0221A680 != NULL && (_0221A680->state == 7 || _0221A680->state == 8 || _0221A680->state == 0x10)) {
        return ov00_021EE490();
    }
    return -1;
}
