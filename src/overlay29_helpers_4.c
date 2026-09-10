#include "overlay_29_helpers_internal.h"

BOOL ov29_0225DEB8(Ov29StatePrivate *state, s32 delta) {
    s32 old = state->selection;
    state->selection += delta;
    if (state->selection < 0) {
        state->selection = 0;
    } else if ((u32)state->selection >= state->count) {
        state->selection = state->count - 1;
    }
    if (state->selection == old) {
        return FALSE;
    }
    ov29_0225DC50(state);
    return TRUE;
}

void ov29_0225DEF4(Ov29StatePrivate *state, s32 value) {
    *(s32 *)((u8 *)state + 0x1dc + state->selection * 4) = value;
    Sprite_SetAnimCtrlSeq(*(SpritePrivate **)((u8 *)state + 0x188 + state->selection * 4), value + 1);
}

void ov29_0225DF18(Ov29StatePrivate *state, u32 palette) {
    if (!state->anim.enabled) {
        Sprite_SetAnimCtrlSeq(state->sprites[state->anim.kind], palette);
        return;
    }
    BgTilemapRectChangePalette(state->bgConfig, state->anim.kind, state->anim.x, state->anim.y, state->anim.width, state->anim.height, palette);
    ScheduleBgTilemapBufferTransfer(state->bgConfig, state->anim.kind);
}

BOOL ov29_0225DF74(Ov29StatePrivate *state) {
    Ov29AnimPrivate *anim = &state->anim;
    switch (anim->phase) {
    case 0:
        ov29_0225DF18(state, anim->from);
        anim->phase++;
        break;
    case 1:
        anim->delay++;
        if (anim->delay == 4) {
            ov29_0225DF18(state, anim->to);
            anim->delay = 0;
            anim->phase++;
        }
        break;
    case 2:
        anim->delay++;
        if (anim->delay == 2) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

void ov29_0225E028(Ov29StatePrivate *state, u8 kind, u8 from, u8 to, u16 value) {
    state->anim.enabled = 0;
    state->anim.delay = 0;
    state->anim.phase = 0;
    state->anim.kind = kind;
    state->anim.from = from;
    state->anim.to = to;
    state->pending = value;
    state->state = 1;
}

void ov29_0225E078(Ov29StatePrivate *state, u8 x, u8 y, u16 value) {
    state->anim.enabled = 1;
    state->anim.delay = 0;
    state->anim.phase = 0;
    state->anim.kind = 5;
    state->anim.from = 1;
    state->anim.to = 0;
    state->anim.x = x;
    state->anim.y = y;
    state->anim.width = 6;
    state->anim.height = 6;
    state->pending = value;
    state->state = 1;
}

void ov29_0225E0E0(Ov29StatePrivate *state) {
    u32 value = 0;
    u32 i;
    for (i = 0; i < state->count; i++) {
        value = value * 10 + state->digits[i];
    }
    state->computed = value;
}
