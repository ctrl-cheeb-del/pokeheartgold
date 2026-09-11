#include "overlay95_accessors_private.h"

u32 ov95_021E5D98(u32 size, BOOL is4x4) {
    u32 key = NNS_GfdDefaultFuncAllocTexVram(size, is4x4, 0);
    sub_02015354(key);
    return (key << 16) >> 13;
}

u32 ov95_021E5DB4(u32 size, BOOL is4pltt) {
    u32 key = NNS_GfdDefaultFuncAllocPlttVram(size, is4pltt, 0);
    sub_02015394(key);
    return (key << 16) >> 13;
}

void *ov95_021E5DD0(int heapId) {
    void *particleHeap = Heap_Alloc((enum HeapID)heapId, 0x4800);
    void *emitter = sub_02014DB4(ov95_021E5D98, ov95_021E5DB4, particleHeap, 0x4800, TRUE, heapId);
    void *camera = sub_02015524(emitter);
    if (camera != NULL) {
        Camera_SetPerspectiveClippingPlane(0x1000, 0x384000, camera);
    }
    return emitter;
}

void *ov95_021E5E18(int heapId, int narcId, int member) {
    void *emitter = ov95_021E5DD0(heapId);
    void *resource = sub_02015264(narcId, member, heapId);
    sub_0201526C(emitter, resource, 10, TRUE);
    return emitter;
}
