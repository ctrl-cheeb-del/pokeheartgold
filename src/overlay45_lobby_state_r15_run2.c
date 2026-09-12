#include "overlay45_lobby_state_r15_private.h"

void ov45_0222B470(int player, Ov45State *state) {
    int slot;
    if (player == ov45_0222E9E0()) {
        return;
    }
    slot = ov45_0222EC68(player);
    if (ov45_0222AFF8(state) == 1 && slot == ov45_0222B020(state)) {
        ov45_0222BD5C(&state->data[0x1c0]);
    }
    if (ov45_0222D8D4(*(void **)&state->data[4], slot) != 0) {
        ov45_0222D8F0(*(void **)&state->data[4], ov45_0222EC68(ov45_0222EAD4(player)));
    }
    ov45_0222C944(&state->data[0x3cc], slot, 0);
    ov45_0222BDE8(&state->data[0x1c0], slot);
    ov45_0222BDB0(&state->data[0x1c0], slot);
    if (ov45_0222CBD0(&state->data[0x4bc], player, -1) != 0) {
        ov45_0222BA3C(state);
    }
    ov45_0222C9A0(&state->data[0x3e4], slot, 0, 0);
    *(u32 *)&state->data[0xfc] |= 1 << ov45_0222EC68(player);
}

void ov45_0222B530(int player, void *obj, Ov45State *state) {
    int slot = ov45_0222EC68(player);
    *(u32 *)&state->data[0x104] |= 1 << slot;
    switch (ov45_0222A920(obj)) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        ov45_0222BDE8(&state->data[0x1c0], slot);
        break;
    }
    if (ov45_0222AADC(obj) == 1) {
        ov45_0222C8C8(&state->data[0x3ac], ov45_0222AAC8(obj), slot);
    }
}
