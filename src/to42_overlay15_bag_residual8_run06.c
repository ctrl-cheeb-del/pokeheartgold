#include "to42_overlay15_bag_residual8_private.h"

void ov15_021FB518(void *work) {
    u8 *state;
    u8 *slot;
    ov15_021F9F08(work);
    state = PTR(work, 0x234);
    slot = state + 4 + U8_AT(state, 0x64) * 12;
    ov15_021FD574(work, 0, ov15_021FA074(work), 0);
    ov15_021FF364(work, S16_AT(slot, 6), -1, 0);
    ov15_02200030(work, U8_AT(PTR(work, 0x234), 0x64));
    ov15_021FD404(work, 1, U8_AT(PTR(work, 0x234), 0x64));
    ov15_021FF6BC(work, U8_AT(slot, 9), S16_AT(slot, 6), 0);
    ov15_02200140(work, slot, ov15_021FA074(work), 0);
    ov15_021FFECC(work, U32_AT(work, 0x644));
    ov15_021F9C78(work, 1);
}
