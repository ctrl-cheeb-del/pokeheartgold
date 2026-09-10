#include "touch_sampling_internal.h"

void sub_02021528(TouchOutput *out) {
    int i;
    out->count = 0;
    for (i = 0; i < 8; i++) {
        out->samples[i].validity = 0;
        out->samples[i].touch = 0;
        out->samples[i].x = 0;
        out->samples[i].y = 0;
    }
}
