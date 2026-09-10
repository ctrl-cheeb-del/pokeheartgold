#include "dynamic_terrain_height_manager_internal.h"

BOOL ov01_021FB368(s32 x, s32 z, const DynamicTerrainHeightEntry *entry) {
    s32 minX;
    s32 width;
    s32 minZ;
    s32 depth;

    if (entry->active == FALSE) {
        return FALSE;
    }
    minX = entry->x;
    width = entry->width;
    minZ = entry->z;
    depth = entry->depth;
    width = minX + width - 1;
    depth = minZ + depth - 1;
    if (minX <= x && x <= width && minZ <= z && z <= depth) {
        return TRUE;
    }
    return FALSE;
}

DynamicTerrainHeightManager *DynamicTerrainHeightManager_New(u32 count, u32 heapId) {
    DynamicTerrainHeightManager *manager = Heap_Alloc(heapId, sizeof(DynamicTerrainHeightManager));
    u8 i;

    manager->entries = Heap_Alloc(heapId, count * sizeof(DynamicTerrainHeightEntry));
    manager->count = count;
    for (i = 0; i < count; i++) {
        manager->entries[i].active = FALSE;
    }
    return manager;
}

void ov01_021FB3E4(u32 index, s32 x, s32 z, s32 width, s32 depth, s32 height, DynamicTerrainHeightManager *manager) {
    manager->entries[index].x = x;
    manager->entries[index].z = z;
    manager->entries[index].width = width;
    manager->entries[index].depth = depth;
    manager->entries[index].height = height;
    manager->entries[index].active = TRUE;
}

void DynamicTerrainHeightManager_Free(DynamicTerrainHeightManager *manager) {
    Heap_Free(manager->entries);
    Heap_Free(manager);
}

BOOL ov01_021FB42C(s32 x, s32 z, DynamicTerrainHeightManager *manager, u8 *index) {
    u8 i;

    if (index == NULL) {
        GF_AssertFail();
    }
    for (i = 0; i < manager->count; i++) {
        if (ov01_021FB368(x, z, &manager->entries[i])) {
            *index = i;
            return TRUE;
        }
    }
    return FALSE;
}

s32 ov01_021FB474(s32 index, DynamicTerrainHeightManager *manager) {
    if (index >= manager->count) {
        GF_AssertFail();
    }
    if (manager->entries[index].active == FALSE) {
        GF_AssertFail();
    }
    return manager->entries[index].height;
}

void ov01_021FB4A0(s32 index, s32 height, DynamicTerrainHeightManager *manager) {
    if (index >= manager->count) {
        GF_AssertFail();
    }
    manager->entries[index].height = height;
}
