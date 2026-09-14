#include "to45_overlay92_tail_private.h"

typedef struct FourU16 {
    u16 values[4];
} FourU16;

void ov92_0225F878(Ov92Work14 *work) {
    FourU16 values = ((const FourU16 *)ov92_02263C34)[2];

    work->accumulator += values.values[work->index];
}

void ov92_0225F8B0(Ov92Work14 *work) {
    FourU16 values = ((const FourU16 *)ov92_02263C34)[3];
    u32 index = work->index;

    index--;
    work->accumulator += values.values[index];
}
