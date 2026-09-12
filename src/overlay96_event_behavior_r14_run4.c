#include "global.h"

#include "overlay96_event_behavior_r14_private.h"

u8 ov96_0221A61C(float v) {
    u32 n = (u32)v;
    if ((double)n > 200.0) {
        n = 200;
    }
    return (u8)n;
}
