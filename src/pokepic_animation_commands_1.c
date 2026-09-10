#include "pokepic_animation_commands_internal.h"

void sub_02017808(AnimState *state) {
    u8 variable;
    s32 angle;
    s32 amplitude;
    sub_020173C8(state, &variable, &angle, &amplitude);
    state->variables[variable] = (FX_SinCosTable_[(angle >> 4) * 2] * amplitude) >> 12;
}

void sub_0201783C(AnimState *state) {
    u8 variable;
    s32 angle;
    s32 amplitude;
    sub_020173C8(state, &variable, &angle, &amplitude);
    state->variables[variable] = (FX_CosIdx(angle) * amplitude) >> 12;
}

void sub_02017874(AnimState *state) {
    u8 args[2];
    sub_02017294(state, &args[1]);
    sub_02017280(state, &args[0]);
    if (args[0] == 8) {
        state->x = state->variables[args[1]];
    } else if (args[0] == 9) {
        state->y = state->variables[args[1]];
    } else {
        GF_AssertFail();
    }
}

void sub_020178BC(AnimState *state) {
    u8 args[2];
    sub_02017294(state, &args[1]);
    sub_02017280(state, &args[0]);
    if (args[0] == 8) {
        state->x += state->variables[args[1]];
    } else if (args[0] == 9) {
        state->y += state->variables[args[1]];
    } else {
        GF_AssertFail();
    }
}

void sub_0201790C(AnimState *state) {
    s32 value;
    u8 args[4];
    s32 *target;
    sub_02017280(state, &args[3]);
    if (args[3] == 8) {
        target = &state->x;
    } else if (args[3] == 9) {
        target = &state->y;
    } else if (args[3] == 10) {
        target = &state->dx;
    } else if (args[3] == 11) {
        target = &state->dy;
    } else if (args[3] == 12) {
        target = &state->scaleX;
    } else if (args[3] == 13) {
        target = &state->scaleY;
    } else if (args[3] == 14) {
        target = &state->rotation;
    } else {
        GF_AssertFail();
    }
    sub_02017280(state, &args[1]);
    if (args[1] == 20) {
        sub_0201726C(state, &value);
    } else if (args[1] == 21) {
        sub_02017294(state, &args[2]);
        value = state->variables[args[2]];
    } else {
        GF_AssertFail();
    }
    sub_02017280(state, &args[0]);
    if (args[0] == 22) {
        *target = value;
    } else if (args[0] == 23) {
        *target += value;
    } else {
        GF_AssertFail();
    }
}

void sub_020179D4(AnimState *state) {
    if (state->reverseX != 0) {
        Pokepic_SetAttr(state->pic, 0, state->baseX - (state->x + state->dx));
    } else {
        Pokepic_SetAttr(state->pic, 0, state->baseX + state->x + state->dx);
    }
    Pokepic_SetAttr(state->pic, 1, state->baseY + state->y + state->dy);
}

void sub_02017A1C(AnimState *state) {
    Pokepic_SetAttr(state->pic, 12, state->scaleX + 0x100);
    Pokepic_SetAttr(state->pic, 13, state->scaleY + 0x100);
    Pokepic_SetAttr(state->pic, 9, (u16)state->rotation);
    if (state->opcode == 0x1b) {
        if (state->scaleY < 0) {
            sub_02017488(state);
        }
    } else if (state->opcode == 0x1d) {
        if (state->scaleY != 0) {
            sub_02017488(state);
        }
    } else if (state->opcode != 0x1c) {
        GF_AssertFail();
    }
}

void sub_02017A84(AnimState *state) {
    u8 variable;
    u8 opcode;
    sub_02017294(state, &variable);
    state->cursor += 4;
    opcode = (u8)(sub_02017214(state->cursor) & 0xff);
    if (opcode == 8 || opcode == 10) {
        state->dx = state->variables[variable];
    } else if (opcode == 9 || opcode == 11) {
        state->dy = state->variables[variable];
    } else {
        GF_AssertFail();
    }
}

void sub_02017AD8(AnimState *state) {
    sub_0201726C(state, &state->variables[12]);
    state->complete = 1;
}

void sub_02017AEC(AnimState *state) {
    s32 duration;
    u8 args[4];
    sub_02017280(state, &args[2]);
    sub_02017280(state, &args[1]);
    sub_02017280(state, &args[0]);
    sub_0201726C(state, &duration);
    Pokepic_StartPaletteFade(state->pic, args[2], args[1], args[0], duration);
}

void sub_02017B2C(AnimState *state) {
    if (Pokepic_ResumePaletteFade(state->pic)) {
        state->fadeDone = 1;
        state->complete = 1;
    }
}
