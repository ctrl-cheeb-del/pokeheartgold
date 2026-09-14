#include "global.h"

typedef struct To45State {
    fx32 value;
    u16 timer;
    u8 state;
    u8 padding;
    u8 params[0x10];
} To45State;

void sub_020182C4(void *, fx32, fx32, fx32);
void sub_020182B0(void *, fx32 *, fx32 *, fx32 *);
void sub_020182A8(void *, fx32, fx32, fx32);
void ov89_0225ADA4(void *, void *, void *, int);
BOOL ov89_0225BDD4(void *, u8 *);

BOOL ov89_0225BDD4(void *unused, u8 *work) {
    fx32 x;
    fx32 y;
    fx32 z;
    To45State *state;
    int offset;

    state = (To45State *)(work + 0x94);
    switch (state->state) {
    case 0:
        state->value = FX32_ONE;
        state->state++;
    case 1:
        state->timer++;
        if (state->timer > 30) {
            return TRUE;
        }
        state->value += 384;
        sub_020182C4(work + 0x1C, FX32_ONE, state->value, FX32_ONE);
        offset = -(((state->value - FX32_ONE) << FX32_SHIFT) / FX32_ONE);
        sub_020182B0(work + 0x1C, &x, &y, &z);
        sub_020182A8(work + 0x1C, x, y + offset, z);
        break;
    }
    ov89_0225ADA4(work + 0x1C, work, state->params, 1);
    return FALSE;
}
