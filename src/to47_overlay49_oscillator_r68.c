#include "to47_overlay49_oscillator_r68.h"

void ov49_022655F4(SolOsc49 *p, int angle, int step, int amplitude) {
    s32 wave;
    p->angle = angle;
    wave = FX_SinCosTable_[(angle >> 4) * 2];
    p->step = step;
    p->amplitude = amplitude;
    p->value = (s32)(((s64)wave * p->amplitude + 0x800) >> 12);
}

void ov49_02265628(SolOsc49 *p) {
    s32 wave;
    p->angle += p->step;
    wave = FX_SinCosTable_[(p->angle >> 4) * 2];
    p->value = (s32)(((s64)wave * p->amplitude + 0x800) >> 12);
}
