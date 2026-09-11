#include "overlay49_animation_helpers_private.h"

void ov49_0226639C(void *ctx, u8 *state) { int i; const u8 *mapping = ov49_0226A7A8; for (i = 0; i < 16; i++, mapping++) ov49_02265980(ctx, state, i, &ov49_0226A70C[*mapping]); ov49_02267D98(state + 0x954, ov49_0226A454, 2, 0x21, 0, state); ; }

void ov49_022663EC(void *ctx, u8 *state) { int i; const u8 *mapping = ov49_0226A7B8; for (i = 0; i < 16; i++, mapping++) ov49_02265980(ctx, state, i, &ov49_0226A70C[*mapping]); ov49_02267D98(state + 0x954, ov49_0226A46C, 2, 0x21, 0, state); ; }

void ov49_0226643C(void *ctx, u8 *state) { int i; const u8 *mapping = ov49_0226A7C8; for (i = 0; i < 16; i++, mapping++) ov49_02265980(ctx, state, i, &ov49_0226A70C[*mapping]); ov49_02267D98(state + 0x954, ov49_0226A4B4, 3, 0x21, 0, state); ; }

void ov49_0226648C(void *ctx, u8 *state) { int i; const u8 *mapping = ov49_0226A7A8; for (i = 0; i < 16; i++, mapping++) ov49_02265980(ctx, state, i, &ov49_0226A70C[*mapping]); ov49_02267D98(state + 0x954, ov49_0226A464, 2, 0x21, 1, state); ; }

void ov49_022664DC(void *ctx, u8 *state) { int i; const u8 *mapping = ov49_0226A7B8; for (i = 0; i < 16; i++, mapping++) ov49_02265980(ctx, state, i, &ov49_0226A70C[*mapping]); ov49_02267D98(state + 0x954, ov49_0226A49C, 3, 0x29, 1, state); ; }

void ov49_0226652C(void *ctx, u8 *state) { int i; const u8 *mapping = ov49_0226A7C8; for (i = 0; i < 16; i++, mapping++) ov49_02265980(ctx, state, i, &ov49_0226A70C[*mapping]); ov49_02267D98(state + 0x954, ov49_0226A4C0, 3, 0x21, 1, state); ; }

void ov49_0226657C(void *ctx, u8 *state) { int i; const u8 *mapping = ov49_0226A7A8; for (i = 0; i < 16; i++, mapping++) ov49_02265980(ctx, state, i, &ov49_0226A70C[*mapping]); ov49_02267D98(state + 0x954, ov49_0226A47C, 2, 0x21, 2, state); ov49_02267C8C(ctx,state); }

void ov49_022665D0(void *ctx, u8 *state) { int i; const u8 *mapping = ov49_0226A7B8; for (i = 0; i < 16; i++, mapping++) ov49_02265980(ctx, state, i, &ov49_0226A70C[*mapping]); ov49_02267D98(state + 0x954, ov49_0226A45C, 2, 0x21, 2, state); ov49_02267C8C(ctx,state); }

void ov49_02266624(void *ctx, u8 *state) { int i; const u8 *mapping = ov49_0226A7C8; for (i = 0; i < 16; i++, mapping++) ov49_02265980(ctx, state, i, &ov49_0226A70C[*mapping]); ov49_02267D98(state + 0x954, ov49_0226A474, 2, 0x21, 2, state); ov49_02267C8C(ctx,state); }

int ov49_02266678(void *ctx, Ov49R72State *state)
{
    int limit;
    int phase;
    int i;
    int result;

    int next = state->progress + 1;
    if (next <= 54) {
        state->progress = next;
    }
    limit = state->progress * 6 / 54;
    for (phase = state->phase; (u32)phase < (u32)limit; phase++) {
        int row = phase % 3;
        if ((u32)row < (u32)state->count) {
            sub_020182A0(&state->entries[row], 1);
        }
    }
    state->phase = limit;
    result = 1;
    i = 0;
    if (state->count > 0) {
        Ov49R72Entry *entry = state->entries;
        Ov49R72Entry *entry2 = state->entries;
        do {
        if (sub_020182A4(entry) == 1) {
            result = ov49_02265B28(ctx, state, i, 0);
            if (result != 0) {
                sub_020182A0(entry2, 0);
                ov49_02265BE8(ctx, state, i, 0, 0);
            }
        }
        i++;
        entry++;
        entry2++;
        } while (i < state->count);
    }
    if (state->phase >= 6 && result == 1) {
        return 1;
    }
    return 0;
}
