#include "overlay45_state_transition_r13_private.h"

BOOL ov45_0222AFF8(void *state);
BOOL ov45_0222B00C(void *state);

void ov45_0222AF80(void *state) {
    int value;

    if (*((u8 *)state + 0x1C6) != 0 && *((u8 *)state + 0x1CA) == 1) {
        *(u16 *)((u8 *)state + 0x1E2) = 0;
        value = ov45_0222EC90(*(u16 *)((u8 *)state + 0x1C4));
        ov45_0222EF4C(3, value, (u8 *)state + 0x1E0, 4);
        ov45_0222BD4C((u8 *)state + 0x1C0);
    }
}

void ov45_0222AFC4(void *state) {
    int value;

    if (*((u8 *)state + 0x1C6) != 0) {
        value = ov45_0222EC90(*(u16 *)((u8 *)state + 0x1C4));
        *((u8 *)state + 0x1C6) = 4;
        *(u16 *)((u8 *)state + 0x1E2) = 4;
        ov45_0222EF4C(2, value, (u8 *)state + 0x1E0, 4);
    }
}

BOOL ov45_0222AFF8(void *state) {
    return *((u8 *)state + 0x1CA) != 0;
}

BOOL ov45_0222B00C(void *state) {
    return *((u8 *)state + 0x1CA) == 2;
}
