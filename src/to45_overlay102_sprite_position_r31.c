#include "to45_overlay102_sprite_position_r31_private.h"

#define PTR(base, offset) (*(void **)((u8 *)(base) + (offset)))

void ov102_021EB950(u8 *work) {
    u32 resource[9];

    ov102_021EA270(PTR(work, 0), (u8 *)resource, 0, 0);
    PTR(work, 0x5c) = ov102_021EA2B4(PTR(work, 0), resource, 0x30, 0x40, 2, 1);
    Sprite_SetAnimCtrlSeq(PTR(work, 0x5c), 4);
    Sprite_SetDrawFlag(PTR(work, 0x5c), 0);
}

void ov102_021EB98C(u8 *work, int draw) {
    if (draw != 0) {
        Sprite_SetDrawFlag(PTR(work, 0x5c), 1);
        if (ov102_021E8F7C(PTR(work, 4)) == 0) {
            Sprite_SetAnimCtrlSeq(PTR(work, 0x5c), 4);
        } else {
            Sprite_SetAnimCtrlSeq(PTR(work, 0x5c), 6);
        }
    } else {
        Sprite_SetDrawFlag(PTR(work, 0x5c), 0);
    }
}

void ov102_021EB9C0(Ov102SpriteWork31 *work, u32 index) {
    Ov102SpriteWork31 *state;
    u32 selection;
    u32 column;
    u32 row;
    VecFx32 position;
    u32 mode;

    state = work;
    mode = ov102_021E8F7C(state->args);
    selection = index;

    position.z = 0;
    if (selection == 0xfe) {
        position.x = 0xe0;
        position.y = 0xb0;
        selection = 0x10;
    } else if (mode == 0) {
        position.x = (selection % 3) * 0x50 + 0x30;
        position.y = (selection / 3) * 0x18 + 0x40;
        selection = 4;
    } else {
        ov102_021EC4CC(selection, &column, &row);
        position.x = column + 0x1a;
        position.y = row + 0x48;
        selection = 6;
    }
    position.x <<= FX32_SHIFT;
    position.y <<= FX32_SHIFT;
    Sprite_SetMatrix(state->sprite, &position);
    Sprite_SetAnimCtrlSeq(state->sprite, selection);
}
