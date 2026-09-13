#include "to42_overlay15_bag_residual8_private.h"

void ov15_021FB114(void *work) {
    u8 *state = PTR(work, 0x234);
    u8 *slot = state + 4 + U8_AT(state, 0x64) * 12;
    if (U8_AT(work, 0x671) != 0) {
        ManagedSprite_SetPositionXY(PTR(work, 0x250), 177, (U16_AT(slot, 4) - 1) * 16 + 16);
    }
}
