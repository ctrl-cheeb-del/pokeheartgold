#include "global.h"

extern const s16 FX_SinCosTable_[];
extern void ov49_0225E4F8(void *, int, int);
extern void ov49_0225E3F4(void *, int, const VecFx32 *);
extern int ov45_0222AE34(void *, int);
extern void ov45_0222AE24(void *, int, int);
extern void ov49_0225E420(void *, int, int, VecFx32 *);

typedef struct PhaseState {
    s16 unk0;
    s16 unk2;
    s16 frame;
    s16 duration;
    u16 amplitude;
    s16 vertical;
    s16 repeats;
} PhaseState;

typedef struct Work {
    u32 unk0;
    void *levels;
    void *objects;
    u8 pad0C[0x9E];
    struct {
        s16 value;
        s16 pad;
    } thresholds[3];
} Work;

int ov49_022694B4(PhaseState *state, void *objects, int index);

int ov49_022694B4(PhaseState *state, void *objects, int index) {
    VecFx32 vec = { 0, 0, 0 };
    int done = FALSE;
    int next = state->frame + 1;
    u16 angle;
    int amplitude;
    float rounded;
    s64 product;
    s16 sine;

    if (next < state->duration) {
        state->frame = next;
    } else {
        state->frame = 0;
        if (state->repeats - 1 > 0) {
            state->repeats--;
        } else {
            done = TRUE;
        }
    }

    angle = (u16)((state->frame * 0xFFFF) / state->duration);
    if (state->amplitude != 0) {
        rounded = (float)(state->amplitude << 12) + 0.5f;
    } else {
        rounded = (float)(state->amplitude << 12) - 0.5f;
    }
    amplitude = (int)rounded;
    sine = FX_SinCosTable_[(angle >> 4) * 2];
    product = (s64)sine * amplitude;
    amplitude = (int)((product + 0x800) >> 12);
    angle = (u32)amplitude >> 12;

    if (state->vertical > 0) {
        rounded = (float)(state->vertical << 12) + 0.5f;
    } else {
        rounded = (float)(state->vertical << 12) - 0.5f;
    }
    amplitude = (int)rounded;
    product = (s64)sine * amplitude;
    vec.y = (fx32)((product + 0x800) >> 12);
    ov49_0225E4F8(objects, index, angle);
    ov49_0225E3F4(objects, index, &vec);
    return done;
}
