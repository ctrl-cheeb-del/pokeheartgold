#include "overlay49_sol_r9_60_private.h"

BOOL ov49_02262AC4(void *state, void *ctx) {
    switch (ov49_0225EF88(state)) {
    case 0:
        sub_020398D4(0, 0);
        if (sub_020392A0() == 0) {
            sub_020343E4();
            sub_0203986C();
        }
        ov49_0225A018(ctx, 1);
        ov49_0225EF8C(state, 1);
        break;
    case 1:
        if (sub_020392A0() == 1) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL ov49_02262B14(void *state, void *ctx) {
    void *object = ov49_0225EF84(state);
    u32 index;
    u32 value;
    void *task;

    switch (ov49_0225EF88(state)) {
    case 0:
        task = ov49_0225EF40(state, 8);
        switch (ov49_0225A040(ctx)) {
        case 0x27:
            value = 0x2A;
            index = 0;
            break;
        case 0x28:
            value = 0x29;
            index = 1;
            break;
        case 0x29:
            value = 0x2B;
            index = 2;
            break;
        default:
            GF_AssertFail();
            return TRUE;
        }
        ov49_0225A37C(ctx, index, 0);
        ov49_0225A0FC(ctx, ov49_0225A30C(ctx, 1, value));
        ov49_02262D70(task, ctx, index, 0, 0);
        ov49_02262E04(task, ctx, 1);
        ov49_0225EF90(state);
        break;
    case 1:
        if ((*(u32 *)(gSystem + 0x48) & 0xF3) != 0) {
            ov49_02262DB8(object, ctx);
            ov49_0225A0EC(ctx);
            object = ov49_02259FF0(ctx);
            ov49_02258EEC(object, ov49_02258DAC(object), 1);
            ov49_0225EF68(state);
            return TRUE;
        }
        ov49_02262E04(object, ctx, 0);
        break;
    }
    return FALSE;
}

void ov49_02262BF8(Ov49Residual60Work *work, void *state, void *ctx, u32 value, u32 next) {
    ov49_0225A08C(ctx, ov49_0225A30C(ctx, 0, value));
    work->state4 = next;
    ov49_0225EF8C(state, 0x19);
}

void ov49_02262C20(Ov49Residual60Work *work, void *state, u8 value, u8 index) {
    work->state4 = value;
    work->value6 = index;
    work->timer5 = 0;
    work->counterA = 0;
    ov49_0225EF8C(state, 0x1A);
}

void ov49_02262C38(Ov49Residual60Work *work, void *ctx, u32 count, u32 first) {
    u32 i;

    ov49_0225A10C(ctx, count);
    work->count38 = count;
    for (i = 0; i < count; i++) {
        ov49_0225A144(ctx, ov49_0225A30C(ctx, 0, first + i), i);
    }
    *(Ov49Residual60CopyBlock *)&work->copied18 = *(Ov49Residual60CopyBlock *)ov49_02269DFC;
    work->count28 = work->count38;
    if (work->limit2A > work->count38) {
        work->limit2A = work->count38;
    }
    work->copied18[0] = (u32)ov49_0225A154(ctx);
}
