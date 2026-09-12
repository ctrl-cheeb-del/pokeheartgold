#include "ov70_wave34_menu_private.h"

int ov70_022421D0(Ov70MenuState *state, const u8 *enabled) {
    int old = state->cursor;
    u32 result;
    u32 keys;

    if (old < 9) {
        state->savedCursor = old;
    }
    keys = *(u32 *)(gSystem + 0x4c);
    if (keys & 0x40) {
        state->cursor = ov70_02245EA8[state->cursor * 4];
    } else if (keys & 0x80) {
        state->cursor = ov70_02245EA8[state->cursor * 4 + 1];
    } else if (keys & 0x20) {
        state->cursor = ov70_02245EA8[state->cursor * 4 + 2];
    } else if (keys & 0x10) {
        state->cursor = ov70_02245EA8[state->cursor * 4 + 3];
    }

    if (old >= 9 && state->cursor < 9) {
        keys = *(u32 *)(gSystem + 0x4c);
        if (keys & 0x40) {
            state->cursor = state->savedCursor;
            if (state->cursor + 4 < 9) {
                do {
                    state->cursor += 4;
                } while (state->cursor + 4 < 9);
            }
        } else if (keys & 0x80) {
            state->cursor = state->savedCursor;
            if (state->cursor - 4 >= 0) {
                do {
                    state->cursor -= 4;
                } while (state->cursor - 4 >= 0);
            }
        }
    }

    if (old != state->cursor) {
        PlaySE(0x5dc);
        ov70_02238F9C(state->sprite,
            (ov70_02245E26[state->cursor * 2] + 0x10) * 8,
            ov70_02245E26[state->cursor * 2 + 1] * 8);
        if (state->cursor == 9) {
            Sprite_SetAnimCtrlSeq(state->sprite, 0x30);
        } else {
            Sprite_SetAnimCtrlSeq(state->sprite, 0x3d);
        }
    }

    result = ov70_02242164(state, 4);
    if (result != -1) {
        if (result == 9) {
            PlaySE(0x5dc);
            return -2;
        }
        if (result >= 9) {
            GF_AssertFail();
        }
        if (enabled == NULL || enabled[result] != 0) {
            PlaySE(0x5dc);
            return result;
        }
        goto no_selection;
    }

    keys = *(u32 *)(gSystem + 0x48);
    if (keys & 1) {
        if (state->cursor == 9) {
            return -2;
        }
        if (state->cursor >= 9) {
            GF_AssertFail();
        }
        if (enabled == NULL || enabled[state->cursor] != 0) {
            PlaySE(0x5dc);
            return state->cursor;
        }
    } else if (keys & 2) {
        PlaySE(0x5dc);
        return -2;
    }
no_selection:
    return -1;
}
