#include "overlay_29_helpers_internal.h"

void ov29_0225DB38(Ov29StatePrivate *state) {
    u32 i;
    for (i = 0; i < 11; i++) {
        Sprite_Delete(state->sprites[i]);
    }
    SpriteTransfer_DeleteCharTransferTask(state->resources[4]);
    SpriteTransfer_DeletePlttTransferTask(state->resources[5]);
    SpriteTransfer_DeleteCharTransferTask(state->resources[0]);
    SpriteTransfer_DeletePlttTransferTask(state->resources[1]);
}

void ov29_0225DB7C(Ov29StatePrivate *state) {
    u32 i;
    for (i = 0; i < 11; i++) {
        Sprite_UpdateAnim(state->sprites[i], 1 << 12);
    }
}

void ov29_0225DB9C(Ov29StatePrivate *state, s32 selection) {
    s32 position[3];
    const u8 *box = GridInputHandler_GetDpadBox(state->gridInput);
    position[0] = box[0] << 12;
    position[1] = (box[1] << 12) + (1 << 20);
    Sprite_SetMatrix(state->sprites[0], position);
    if ((u32)selection <= 9) {
        Sprite_SetAnimCtrlSeq(state->sprites[0], 1);
    } else {
        Sprite_SetAnimCtrlSeq(state->sprites[0], 2);
    }
}

void ov29_0225DBF0(Ov29StatePrivate *state) {
    state->gridInput = GridInputHandler_Create(ov29_0225E248, ov29_0225E280, ov29_0225E13C, state, 1, 0, 8);
    ov29_0225DB9C(state, 0);
    ov29_0225DC50(state);
}

void ov29_0225DC34(Ov29StatePrivate *state) {
    GridInputHandler_Free(state->gridInput);
}

void ov29_0225DC44(void) {
}

void ov29_0225DC48(Ov29StatePrivate *state, s32 selection) {
    ov29_0225DB9C(state, selection);
}

void ov29_0225DC50(Ov29StatePrivate *state) {
    s32 position[3];
    const u8 *values = ov29_0225E1E4[state->count];
    position[0] = values[state->selection] << 12;
    position[1] = 0x49 << 14;
    Sprite_SetMatrix(state->sprites[1], position);
}

void ov29_0225DC84(Ov29StatePrivate *state) {
    s32 position[3];
    const u8 *values = ov29_0225E1E4[state->count];
    u32 i;
    position[1] = 0x46 << 14;
    for (i = 0; i < state->count; i++) {
        position[0] = values[i] << 12;
        Sprite_SetMatrix(state->sprites[i + 5], position);
    }
}
