#include "to45_overlay102_navigation_r6_private.h"

BOOL ov102_021E8600(Ov102InputState *state) {
    u16 current = state->current;
    u16 index = current;

    if (current == 0xFE) {
        index = 12;
    }
    if (current != 0xFE) {
        state->previous = current;
        if (state->keys & 0x40) {
            state->current = ov102_021EC65C[index * 4];
            return TRUE;
        }
        if (state->keys & 0x80) {
            state->current = ov102_021EC65D[index * 4];
            return TRUE;
        }
        if (state->keys & 0x20) {
            state->current = ov102_021EC65E[index * 4];
            return TRUE;
        }
        if (state->keys & 0x10) {
            state->current = ov102_021EC65F[index * 4];
            return TRUE;
        }
    } else {
        if (state->keys & 0x40) {
            state->current = state->previous % 3 + 9;
            return TRUE;
        }
        if (state->keys & 0x80) {
            state->current = state->previous % 3;
            return TRUE;
        }
    }
    return FALSE;
}

BOOL ov102_021E86B8(Ov102InputState *state) {
    u16 current = state->current;

    if (current != 0xFE) {
        u16 next = 0xFF;

        if (state->keys & 0x40) {
            next = ov102_021EC4F8(current);
        } else if (state->keys & 0x80) {
            next = ov102_021EC514(current);
        } else if (state->keys & 0x10) {
            next = ov102_021EC54C(current);
        } else if (state->keys & 0x20) {
            next = ov102_021EC530(current);
        }
        if (next != 0xFF) {
            state->previous = state->current;
            state->current = next;
            return TRUE;
        }
    } else {
        if (state->keys & 0x40) {
            state->current = ov102_021EC584(state->previous);
            return TRUE;
        }
        if (state->keys & 0x80) {
            state->current = ov102_021EC568(state->previous);
            return TRUE;
        }
    }
    return FALSE;
}

void ov102_021E874C(Ov102CursorState *state, u32 value) {
    state->unk00 = 0;
    state->unk06 = 0;
    state->unk07 = 0;
    state->converted = ov102_021E8FD8(value);
    state->unk08 = NULL;
    state->unk0C = 0;
    state->unk0E = 0xFFFF;
    if (state->converted > 10) {
        state->unk02 = (state->converted - 10) / 2 + (state->converted & 1);
    } else {
        state->unk02 = 0;
    }
}
