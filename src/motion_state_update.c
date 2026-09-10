#include "motion_state_update_internal.h"

void sub_02017BF8(u8 kind, MotionState *state, MotionConfig *config) {
    switch (kind) {
    case 0x23:
        state->valuePtr = (int *)((u8 *)state + 0x3c);
        state->object = &config->raw[0x68];
        state->initial = *(int *)&config->raw[0x68];
        break;
    case 0x24:
        state->valuePtr = (int *)((u8 *)state + 0x40);
        state->object = &config->raw[0x6c];
        state->initial = *(int *)&config->raw[0x6c];
        break;
    case 0x25:
        state->valuePtr = (int *)((u8 *)state + 0x44);
        state->object = &config->raw[0x70];
        state->initial = *(int *)&config->raw[0x70];
        break;
    case 0x26:
        state->valuePtr = (int *)((u8 *)state + 0x48);
        state->object = &config->raw[0x74];
        state->initial = *(int *)&config->raw[0x74];
        break;
    case 0x27:
        state->valuePtr = (int *)((u8 *)state + 0x4c);
        state->object = &config->raw[0x78];
        state->initial = *(int *)&config->raw[0x78];
        break;
    default:
        GF_AssertFail();
        break;
    }
}

void sub_02017C78(void *ctx, int index, void *unused2, void *unused3) {
    MotionState *state = sub_02017220(ctx, (u8)index);
    u8 i;
    int offset;
    sub_02017280(ctx, (u8 *)state + 0x2c);
    sub_02017280(ctx, (u8 *)state + 0x2d);
    offset = index * 12;
    i = 0;
    if (*(const int *)((const u8 *)_020F61C0 + offset) > 0) {
        int *values;
        const MotionEntry *entry;
        entry = (const MotionEntry *)((const u8 *)_020F61BC + offset);
        values = (int *)((u8 *)state + 4);
        do {
            sub_0201726C(ctx, &values[i]);
            i = (u8)(i + 1);
        } while (i < entry->count);
    }
    {
        int selector = *(const int *)((const u8 *)_020F61C4 + offset);
        u8 *selected = (u8 *)state + selector * 4;
        sub_02017BF8(*(int *)(selected + 4), state, (MotionConfig *)ctx);
    }
    if (state->counter == 0) {
        void (*callback)(MotionState *, void *) = *(void (**)(MotionState *, void *))((u8 *)state + 0x50);
        callback(state, ctx);
    } else {
        state->counter--;
    }
}

void sub_02017D20(MotionState *state) {
    u16 angle = state->value14 + state->value10 * (state->value1C + 1);
    switch (state->kind) {
    case 0x1e:
        *state->valuePtr = (FX_SinCosTable_[(angle >> 4) * 2] * state->valueC) >> 12;
        break;
    case 0x1f:
        *state->valuePtr = (FX_SinCosTable_[(angle >> 4) * 2 + 1] * state->valueC) >> 12;
        break;
    case 0x20:
        *state->valuePtr = -((FX_SinCosTable_[(angle >> 4) * 2] * state->valueC) >> 12);
        break;
    case 0x21:
        *state->valuePtr = -((FX_SinCosTable_[(angle >> 4) * 2 + 1] * state->valueC) >> 12);
        break;
    default:
        GF_AssertFail();
        break;
    }
    sub_02017BC8(state->type, &state->initial, state->valuePtr, state->object);
    state->value1C++;
    if (state->value1C >= state->value18) {
        state->active = 0;
    }
}

void sub_02017DD8(MotionState *state) {
    u16 angle = state->value14 + _s32_div_f(state->value10 * (state->value1C + 1), state->value18);
    switch (state->kind) {
    case 0x1e:
        *state->valuePtr = (FX_SinCosTable_[(angle >> 4) * 2] * state->valueC) >> 12;
        break;
    case 0x1f:
        *state->valuePtr = (FX_SinCosTable_[(angle >> 4) * 2 + 1] * state->valueC) >> 12;
        break;
    case 0x20:
        *state->valuePtr = -((FX_SinCosTable_[(angle >> 4) * 2] * state->valueC) >> 12);
        break;
    case 0x21:
        *state->valuePtr = -((FX_SinCosTable_[(angle >> 4) * 2 + 1] * state->valueC) >> 12);
        break;
    default:
        GF_AssertFail();
        break;
    }
    sub_02017BC8(state->type, &state->initial, state->valuePtr, state->object);
    state->value1C++;
    if (state->value1C >= state->value18) {
        state->active = 0;
    }
}

void sub_02017E98(MotionState *state) {
    int delta = state->value8 + state->valueC * state->value14;
    *state->valuePtr += delta;
    sub_02017BC8(state->type, &state->initial, state->valuePtr, state->object);
    state->value14++;
    if (state->value14 >= state->value10) {
        state->active = 0;
    }
}

void sub_02017ED4(MotionState *state) {
    *state->valuePtr = _s32_div_f((state->value10 + 1) * state->value8, state->valueC);
    sub_02017BC8(state->type, &state->initial, state->valuePtr, state->object);
    state->value10++;
    if (state->value10 >= state->valueC) {
        state->active = 0;
    }
}

void sub_02017F10(MotionState *state) {
    int delta = state->value8 + state->valueC * state->value14;
    *state->valuePtr += delta;
    if (state->type == 0x18 || state->type == 0x1a) {
        if (delta < 0) {
            int target = state->value10;
            int *ptr = state->valuePtr;
            if (*ptr <= target) {
                *ptr = target;
                state->active = 0;
            }
        } else {
            int target = state->value10;
            int *ptr = state->valuePtr;
            if (*ptr >= target) {
                *ptr = target;
                state->active = 0;
            }
        }
    } else if (state->type == 0x19) {
        int total = state->initial + *state->valuePtr;
        if (delta < 0) {
            if (total <= state->value10) {
                *state->valuePtr += state->value10 - total;
                state->active = 0;
            }
        } else {
            if (total >= state->value10) {
                *state->valuePtr -= total - state->value10;
                state->active = 0;
            }
        }
    } else {
        GF_AssertFail();
    }
    sub_02017BC8(state->type, &state->initial, state->valuePtr, state->object);
    state->value14++;
}
