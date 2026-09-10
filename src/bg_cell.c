#include "bg_cell_internal.h"

UnkStruct_0201956C *sub_0201956C(BgConfig *bgConfig, int count, int mode, enum HeapID heapId) {
    UnkStruct_0201956C *ret = Heap_Alloc(heapId, sizeof(UnkStruct_0201956C));
    ret->bgConfig = bgConfig;
    ret->count = mode;
    ret->heapId = heapId;
    ret->value = count;
    ret->flag = 0;
    ret->cells = Heap_Alloc(heapId, mode * sizeof(BgCell));
    MI_CpuFill8(ret->cells, 0, mode * sizeof(BgCell));
    return ret;
}

void sub_020195C0(UnkStruct_0201956C *mgr) {
    u32 i;
    for (i = 0; i < mgr->count; i++) {
        if (mgr->cells[i].data != NULL) {
            Heap_Free(mgr->cells[i].data);
        }
    }
    Heap_Free(mgr->cells);
    Heap_Free(mgr);
}

void sub_020195F4(UnkStruct_0201956C *mgr, int index, int bgId, int width, int height) {
    BgCell *cell = &mgr->cells[index];
    cell->data = Heap_Alloc(mgr->heapId, width * height * 2);
    cell->width = width;
    cell->height = height;
    cell->bgId = bgId;
    cell->x = 0;
    cell->y = 0;
    cell->state = 0;
    cell->active = 1;
    cell->left = 0;
    cell->top = 32;
    cell->right = 0;
    cell->bottom = 24;
}

void sub_02019668(UnkStruct_0201956C *mgr, int index, u16 *src) {
    BgCell *cell = &mgr->cells[index];
    MIi_CpuCopy16(src, cell->data, cell->width * cell->height * 2);
}

void sub_02019688(UnkStruct_0201956C *mgr, int index, int narcId, int fileId, int compressed) {
    NNSG2dScreenData *screen;
    void *raw = GfGfxLoader_GetScrnData((NarcId)narcId, fileId, compressed, &screen, mgr->heapId);
    sub_02019668(mgr, index, (u16 *)((u8 *)screen + 0xC));
    Heap_Free(raw);
}

void sub_020196B8(UnkStruct_0201956C *mgr, int index, NARC *narc, int fileId, int compressed) {
    NNSG2dScreenData *screen;
    void *raw = GfGfxLoader_GetScrnDataFromOpenNarc(narc, fileId, compressed, &screen, mgr->heapId);
    sub_02019668(mgr, index, (u16 *)((u8 *)screen + 0xC));
    Heap_Free(raw);
}
