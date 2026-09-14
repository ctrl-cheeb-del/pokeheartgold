#include "global.h"

typedef struct StringState {
    u32 values[4];
    void *primary;
    void *strings[3];
} StringState;

typedef struct State {
    u8 raw[0x220];
} State;

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern void *String_New(u32, int);
extern u32 ov45_0222F544(int);
extern const u16 *ov45_0222F628(int);
extern void GF_AssertFail(void);
extern void CopyU16ArrayToString(void *, const u16 *);

void ov47_02259C8C(StringState *state, int mode, int heapId);

void ov47_02259C8C(StringState *state, int mode, int heapId) {
    int base;
    int i;
    State *cursor;
    const u16 *text;

    state->primary = String_New(0x100, heapId);
    base = 0;
    do {
        state->strings[base] = String_New(0x100, heapId);
        base++;
    } while (base < 3);
    base = mode == 1 ? 0 : 4;
    state->values[2] = ov45_0222F544(base + 2);
    state->values[0] = ov45_0222F544(base + 1);
    state->values[1] = ov45_0222F544(base);
    state->values[3] = ov45_0222F544(base + 3);
    if (state->values[3] == 1) {
        text = ov45_0222F628(base);
        if (text == NULL) {
            GF_AssertFail();
        }
        CopyU16ArrayToString(state->primary, text);
        cursor = (State *)state;
        for (i = 0; i < 3; i++, cursor = (State *)((u8 *)cursor + 4)) {
            text = ov45_0222F628(base + 1 + i);
            if (text == NULL) {
                GF_AssertFail();
            }
            CopyU16ArrayToString(PTR(cursor, 0x14), text);
        }
    }
}
