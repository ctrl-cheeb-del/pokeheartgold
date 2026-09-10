#include "palette_fade_effects_internal.h"

void sub_020121F4(PointerAt0C *work) {
    Heap_Free(work->allocation);
    work->allocation = 0;
}
