#include "palette_fade_effects_internal.h"

void sub_02011068(void *work, int a, int b, int useHardware) {
    if (useHardware == 0) {
        sub_020131F4(a, b);
    } else {
        sub_02013424(work, a);
    }
}
