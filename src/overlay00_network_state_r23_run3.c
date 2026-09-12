#include "overlay00_network_state_r23_private.h"

int ov00_021E6790(void) {
    int i;
    int found = 0;
    i = found;
    if (_0221A680->playerCount > 0) {
        do {
            if (i != ov00_021EE490() && ov00_021EE530((u8)i) != 0) {
                found = 1;
                if (ov00_021F9580((u8)i) == 0) {
                    return 0;
                }
            }
            i++;
        } while (i < _0221A680->playerCount);
    }
    return found;
}

int ov00_021E67E0(int index) {
    if (_0221A680->busy == 0 && ov00_021E6790() != 0) {
        u32 mask = (u32)ov00_021EE4FC();
        if ((mask & 0xFFFE) != 0) {
            _0221A680->busy = 1;
            *(u32 *)_0221A680 = 2 | ((u32)_0221A680->localId << 8);
            ov00_021F9750(ov00_021EE4FC(), _0221A680, 4);
            _0221A680->timer[index] = 0;
            return 1;
        }
    }
    return 0;
}
