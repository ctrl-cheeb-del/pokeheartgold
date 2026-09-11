#include "overlay49_input_direction_private.h"

void ov49_02259410(Ov49R13Work *work, void *ctx)
{
    int pos = ov42_02228188(work->field, 6);
    int kind = ov42_02228188(work->field, 4);
    int other = ov42_02228188(work->field, 5);
    int mode;
    u32 input;
    if (other != 0) return;
    input = gSystem.input;
    mode = 2;
    if (input & 2) mode = 3;
    if (input & 0x40) {
        if (pos == 0) ov49_0225927C(ctx, mode, pos, kind);
        else ov49_0225927C(ctx, 1, 0, kind);
        return;
    }
    if (input & 0x80) {
        if (pos == 1) ov49_0225927C(ctx, mode, pos, kind);
        else ov49_0225927C(ctx, 1, 1, kind);
        return;
    }
    if (input & 0x20) {
        if (pos == 2) ov49_0225927C(ctx, mode, pos, kind);
        else ov49_0225927C(ctx, 1, 2, kind);
        return;
    }
    if (input & 0x10) {
        if (pos == 3) ov49_0225927C(ctx, mode, pos, kind);
        else ov49_0225927C(ctx, 1, 3, kind);
    }
}
