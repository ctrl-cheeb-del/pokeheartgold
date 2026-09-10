#include "field_texture_manager_internal.h"

void FieldTextureManager_FreeAllSlots(FieldTextureManagerPrivate *manager) {
    s32 i;
    if (manager == NULL) {
        return;
    }
    for (i = 0; i < 16; i++) {
        ov01_021EB18C(manager, i);
    }
    Heap_Free(manager->archiveData);
}

void FieldTextureManager_Destroy(FieldTextureManagerPrivate *manager) {
    if (manager != NULL) {
        Heap_Free(manager);
    }
}
