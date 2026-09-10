#include "overlay80_palette_effect_internal.h"

void ov80_02239EC4(void *object) {
    SysTask_Destroy(*(void **)object);
    Heap_Free(object);
}
