#include "wireless_connection_state_internal.h"

void sub_020356C0(BOOL value) {
    if (_021D4134.work != NULL) {
        u8 bit = value;
        _021D4134.work[0xD95] = (_021D4134.work[0xD95] & ~4) | ((bit & 1) << 2);
    }
}

void sub_020356EC(BOOL value) {
    if (_021D4134.work != NULL) {
        u8 bit = value;
        _021D4134.work[0xD95] = (_021D4134.work[0xD95] & ~2) | ((bit & 1) << 1);
        *(u16 *)(_021D4134.work + 0xD8E) = 0xFFFF;
    }
}
