#include "to42_overlay49_r73a_private.h"

#pragma require_prototypes off

void ov49_02266EF8(void *ctx, void *state) {
    if (U8_AT(state, 0x965) == 0) {
        ov49_02266F14(ctx, state);
        return;
    }
    ov49_02267074(ctx, state);
}
