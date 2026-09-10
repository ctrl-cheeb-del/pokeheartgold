#include "overlay_02_legendary_internal.h"

void ov02_02245D18(void *data) {
    u8 *p = data;
    HeapExp_FndInitAllocator(p + 0xBC, *(u32 *)p, 0x20);
    Field3dModel_LoadFromFilesystem(p + 0xC, 0xAE, 0, *(u32 *)p);
    Field3dModelAnimation_LoadFromFilesystem(p + 0x1C, p + 0xC, 0xAE, 1, *(u32 *)p, p + 0xBC);
    Field3dModelAnimation_LoadFromFilesystem(p + 0x30, p + 0xC, 0xAE, 2, *(u32 *)p, p + 0xBC);
    Field3dObject_InitFromModel(p + 0x44, p + 0xC);
    Field3dObject_AddAnimation(p + 0x44, p + 0x1C);
    Field3dObject_AddAnimation(p + 0x44, p + 0x30);
    Field3dObject_SetPosEx(p + 0x44, 0x88000, 0, 0xA0000);
    Field3dObject_SetActiveFlag(p + 0x44, 1);
}

void ov02_02245DB0(void *data) {
    u8 *p = data;
    Field3dObject_SetActiveFlag(p + 0x44, 0);
    Field3dModelAnimation_Unload(p + 0x30, p + 0xBC);
    Field3dModelAnimation_Unload(p + 0x1C, p + 0xBC);
    Field3dModel_Unload(p + 0xC);
}

void ov02_02245DE0(void *data) {
    u8 *p = data;
    Field3dModelAnimation_FrameAdvanceAndLoop(p + 0x1C, 0x1000);
    Field3dModelAnimation_FrameAdvanceAndLoop(p + 0x30, 0x1000);
    Field3dObject_Draw(p + 0x44);
}

void *ov02_02245E04(void *descriptor, int heap) {
    u8 *d = descriptor;
    u8 *p = Heap_Alloc(heap, 0xA4);
    MI_CpuFill8(p, 0, 0xA4);
    *(u32 *)(p + 0xA0) = heap;
    HeapExp_FndInitAllocator(p + 0x8C, heap, 0x20);
    Field3dModel_LoadFromFilesystem(p, *(u16 *)d, d[2], heap);
    Field3dObject_InitFromModel(p + 0x10, p);
    ov02_02245ED8(p, *(u16 *)d, *(void **)(d + 4), d[3]);
    Field3dObject_SetActiveFlag(p + 0x10, 1);
    *(u16 *)(p + 0x9E) = 1;
    return p;
}
