#include "overlay90_selection_flow_internal.h"

void ov90_02259D50(void *ctx, void *state, int value, int kind, s16 coord, int mode) {
    ov90_02259200(state, value);
    if (mode == 1) {
        ov90_02259350(state, 10, ctx, (u8)kind, (u8)coord, 0x50600);
    } else {
        ov90_022592A8(state, 10, ctx, (u8)kind, (u8)coord);
    }
}

void ov90_02259DAC(void *ctx, void *state, int direction, void *data, int value, s16 coord) {
    if (direction != 0) {
        if (data != NULL) {
            ov90_022591F4(state);
            ov90_02259210(state, data);
            ov90_022592A8(state, 11, ctx, (u8)coord, 16);
        }
    } else {
        if (data != NULL) {
            ov90_022591F4(state);
            ov90_02259220(state, data, value);
            ov90_022592A8(state, 12, ctx, (u8)coord, 16);
        }
    }
}

void ov90_02259E18(Ov90SelectionEntry *entry, int anim) {
    Sprite_SetDrawFlag(entry->sprite14, TRUE);
    Sprite_SetAnimCtrlSeq(entry->sprite14, anim + 4);
    Sprite_SetAnimActiveFlag(entry->sprite14, TRUE);
}

void ov90_02259E38(void *ctx, void *state, int value, int kind, s16 coord, int mode) {
    ov90_02259234(state, value, mode);
    if (mode == 5) {
        ov90_022592C4(state, 14, ctx, (u8)kind, (u8)coord);
    } else {
        ov90_022592C4(state, 13, ctx, (u8)kind, (u8)coord);
    }
}
