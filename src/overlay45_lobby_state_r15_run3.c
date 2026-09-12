#include "overlay45_lobby_state_r15_private.h"

void ov45_0222B75C(const u8 *a, int b, Ov45State *state) {
    if (ov45_0222BADC(&state->data[0x108], *(void **)state->data) == 0) {
        *(u32 *)&state->data[0x52c] = 1;
        return;
    }
    ov45_0222BB00(&state->data[0x108], a, b);
    ov45_0222BAC4(&state->data[0x108], *(void **)state->data);
}
