#include "overlay96_ui_helpers_private.h"

BOOL ov96_021EE54C(void *course) {
    void *area = PokeathlonCourse_GetDataCopyArea(course);
    u8 *p = ov96_021E8A20((u8 *)area + 0xF0);
    if (course == NULL) GF_AssertFail();
    if (area == NULL) GF_AssertFail();
    if (p == NULL) GF_AssertFail();
    return ((u32)p[0x21] << 30) >> 31;
}

BOOL ov96_021EE580(void *course) {
    void *area = PokeathlonCourse_GetDataCopyArea(course);
    u8 *p = ov96_021E8A20((u8 *)area + 0xF0);
    if (course == NULL) GF_AssertFail();
    if (area == NULL) GF_AssertFail();
    if (p == NULL) GF_AssertFail();
    return (*(u32 *)(p + 8) << 2) >> 31;
}

void *ov96_021EE5B4(void *owner, enum HeapID heapId) {
    u8 *p = Heap_Alloc(heapId, 0x30);
    MI_CpuFill8(p, 0, 0x30);
    *(u32 *)p = heapId;
    *(void **)(p + 8) = owner;
    *(void **)(p + 0xC) = NARC_New(0xDD, heapId);
    return p;
}

void ov96_021EE5E0(u8 *p) {
    int i = 0;
    u8 *window = p;
    window += 0x10;
    while (i < 2) {
        ClearWindowTilemapAndCopyToVram(window);
        RemoveWindow(window);
        i++;
        window += 0x10;
    }
    NARC_Delete(*(void **)(p + 0xC));
    Heap_Free(p);
}

void ov96_021EE60C(u8 *p, void *bg) {
    const u8 *template = ov96_0221B19A;
    u8 *window = p;
    *(void **)(p + 4) = bg;
    int i = 0;
    window += 0x10;
    while (i < 2) {
        AddWindow(*(void **)(p + 4), window, template);
        FillWindowPixelBuffer(window, 0);
        ClearWindowTilemap(window);
        i++;
        template += 8;
        window += 0x10;
    }
}
