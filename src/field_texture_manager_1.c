#include "field_texture_manager_internal.h"

FieldTextureManagerPrivate *FieldTextureManager_Init(void) {
    FieldTextureManagerPrivate *manager = Heap_Alloc(4, sizeof(FieldTextureManagerPrivate));
    s32 i;
    if (manager == NULL) {
        GF_AssertFail();
    }
    for (i = 0; i < 16; i++) {
        manager->slots[i].frame = 0;
        manager->slots[i].timer = 0;
        manager->slots[i].textureData = NULL;
        manager->slots[i].texture = NULL;
        manager->slots[i].record = NULL;
        manager->slots[i].animation = NULL;
    }
    manager->busy = 0;
    return manager;
}

u32 FieldTextureManager_LoadTexture(FieldTextureManagerPrivate *manager, void *resource) {
    void *narc;
    u32 loaded = 0;
    u32 i;
    narc = NARC_New(0x8b, 4);
    manager->archiveData = NARC_AllocAndReadWholeMember(narc, 0, 4);
    manager->records = manager->archiveData;
    i = loaded;
    while (i < *(u32 *)manager->records) {
        if (ov01_021EB058(manager, resource, i, narc) >= 0) {
            loaded++;
        }
        i++;
    }
    NARC_Delete(narc);
    return loaded;
}
