#include "overlay00_network_state_r23_private.h"

void ov00_021E644C(u32 value) {
    sub_0203993C();
    if (sub_02034084() == 0) {
        if (value & 0x100) {
            _0221A680->modeFlag = 1;
        } else {
            _0221A680->modeFlag = 0;
        }
    }
}
