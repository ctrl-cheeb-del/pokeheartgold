#include "r40_overlay_01_021EAFD4_residual_2_private.h"

void ov01_021EB18C(FieldTextureManagerPrivate *manager, u32 index) {
    if (manager != NULL) {
        if (manager->slots[index].animation != NULL) {
            Heap_Free(manager->slots[index].animation);
        }
        if (manager->slots[index].record != NULL) {
            manager->slots[index].record = NULL;
        }
        manager->slots[index].frame = 0;
        manager->slots[index].timer = 0;
    }
}
