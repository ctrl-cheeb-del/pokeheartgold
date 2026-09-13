#include "r40_overlay_96_residual_124_private.h"

void ov96_0221A6B0(u32 value) {
    ov96_0221A61C((float)((double)(float)value / 3.5));
}

void ov96_0221A6D0(u32 value) {
    ov96_0221A61C((float)(((double)(float)value / 1024.0) * 10.0));
}

void ov96_0221A700(u32 value) {
    double scaled = (float)value;
    scaled *= 1.5;
    ov96_0221A61C((float)scaled);
}
