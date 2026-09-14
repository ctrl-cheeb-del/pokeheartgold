#include "to45_overlay49_r73_private.h"

#pragma require_prototypes off

u32 ov49_02266978(void *ctx, void *state) {
    u8 phase = U8_AT(state, 1);
    switch (phase) {
    case 0:
        if (ov49_02266D60(ctx, state) != 0) {
            U8_AT(state, 1) = 1;
            ov49_02266EF8(ctx, state);
        }
        break;
    case 1:
        if (ov49_022670B8(ctx, state) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
