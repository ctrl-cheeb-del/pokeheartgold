#include "r40_overlay_47_residual_9_private.h"

void ov47_02259D74(State47 *state) {
    int i;
    state->total = 0;
    for (i = 0; i < 3; i++) {
        state->values[i] = ov45_0222F544(i + 8);
        state->total += state->values[i];
    }
}
