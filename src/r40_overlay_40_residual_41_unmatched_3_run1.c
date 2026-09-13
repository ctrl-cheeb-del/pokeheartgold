#include "r40_overlay_40_residual_41_unmatched_3_private.h"

void ov40_02244060(Ov40State *state) {
    int i;
    u8 *entry;
    i = 0;
    if (S32(state, 0x204) > 0) {
        entry = state->raw;
        do {
            if (i >= S32(state, 0x210) && i < S32(state, 0x214)) {
                S32(entry, 8) = 1;
            } else {
                S32(entry, 8) = 0;
            }
            i++;
            entry += 0x1C;
        } while (i < S32(state, 0x204));
    }
}
