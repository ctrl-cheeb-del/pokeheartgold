#include "to42_overlay_45_thumb_residual_24_private.h"

void ov45_0222CA7C(Ov45Timer *p, int start, int end) {
    p->active = 0;
    p->elapsed = 0;
    p->duration = (end - start) * 30;
}

void ov45_0222CA8C(Ov45Timer *p) {
    p->active = 1;
    p->elapsed = 0;
    ov45_0222ECB8(&p->start);
}

void ov45_0222CAA0(Ov45Timer *p) {
    s64 now;
    s64 delta;
    int accum;
    u32 i;
    if (p->active != 0) {
        ov45_0222ECB8(&now);
        delta = (now - p->start) * 30;
        if ((s64)p->elapsed < delta) {
            p->elapsed = (s32)delta;
        }
        if (p->elapsed < p->duration) {
            u32 value;
            p->elapsed++;
            value = (p->elapsed << 8) / p->duration;
            accum = 0;
            for (i = 0; i < 5; i++) {
                accum += _02254A28[i][1];
                if ((u32)accum >= value) {
                    if (p->phase != _02254A28[i][0]) {
                        p->phase = _02254A28[i][0];
                        p->counter = 0;
                    }
                    break;
                }
            }
        } else {
            if (p->phase != 5) {
                p->phase = 5;
                p->counter = 0;
            }
            if (p->counter >= 120) {
                p->phase = 0;
                p->active = 0;
            }
        }
        p->counter++;
    }
}
