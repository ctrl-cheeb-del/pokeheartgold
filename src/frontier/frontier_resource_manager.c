#include "frontier_resource_manager_internal.h"

void *ov80_02239960(u32 heapId) {
    u8 *manager = Heap_Alloc(heapId, 0x24);
    MI_CpuFill8(manager, 0, 0x24);
    *(u16 *)(manager + 0x20) = heapId;
    sub_02014DA0();
    return manager;
}

void ov80_02239980(void *manager) {
    void **objects = manager;
    s32 i;
    for (i = 0; i < 8; i++) {
        if (objects[i] != NULL) {
            ov80_02239A98(objects[i]);
        }
    }
    Heap_Free(manager);
}

void *ov80_022399A4(void *manager, u32 index, u32 member, void *camera) {
    u8 *p = manager;
    void *buffer;
    void *object;
    void *resource;
    void *projection;
    if (*(void **)(p + index * 4) != NULL) {
        GF_AssertFail();
    }
    buffer = Heap_Alloc(*(u16 *)(p + 0x20), 0x4800);
    object = sub_02014DB4(ov80_02239AB0, ov80_02239AD4, buffer, 0x4800, 1, *(u16 *)(p + 0x20));
    projection = sub_02015524(object);
    Camera_SetPerspectiveClippingPlane(0x1000, 0x384000, projection);
    sub_02015528(object, camera);
    resource = sub_02015264(0xBC, member, *(u16 *)(p + 0x20));
    sub_0201526C(object, resource, 10, 1);
    *(void **)(p + index * 4) = object;
    return object;
}

void ov80_02239A1C(void *manager, u32 index) {
    void **objects = manager;
    if (objects[index] == NULL) {
        GF_AssertFail();
    }
    ov80_02239A98(objects[index]);
    objects[index] = NULL;
}

BOOL ov80_02239A38(void) {
    Thunk_G3X_Reset();
    if (sub_02015420() == 0) {
        return FALSE;
    }
    if (sub_0201543C() > 0) {
        Thunk_G3X_Reset();
    }
    sub_02015460();
    return TRUE;
}

void *ov80_02239A60(void *manager, u32 index) {
    void **objects = manager;
    if (objects[index] == NULL) {
        GF_AssertFail();
    }
    return objects[index];
}

BOOL ov80_02239A74(void *manager) {
    void **objects = manager;
    s32 i;
    for (i = 0; i < 8; i++) {
        if (objects[i] != NULL && sub_020154B0(objects[i]) > 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void ov80_02239A98(void *object) {
    void *buffer = sub_020154D0(object);
    sub_02014EBC(object);
    Heap_Free(buffer);
}

u32 ov80_02239AB0(u32 size, int flag) {
    u32 key = NNS_GfdDefaultFuncAllocTexVram(size, flag, 0);
    if (key == 0) {
        GF_AssertFail();
    }
    sub_02015354(key);
    return (u16)key << 3;
}

u32 ov80_02239AD4(u32 size, int flag) {
    u32 key = NNS_GfdDefaultFuncAllocPlttVram(size, flag, 1);
    if (key == 0) {
        GF_AssertFail();
    }
    sub_02015394(key);
    return (u16)key << 3;
}
