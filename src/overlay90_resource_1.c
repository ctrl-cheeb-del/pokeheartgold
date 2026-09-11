#include "overlay90_resource_internal.h"

void ov90_02258DD0(Ov90ResWork *work, int count, enum HeapID heap) {
    int i;
    for (i = 0; i < 4; i++) {
        work->man[i] = Create2DGfxResObjMan(count, (GfGfxResType)i, heap);
    }
    work->records = Heap_Alloc(heap, count * sizeof(Ov90ResRec));
    memset(work->records, 0, count * sizeof(Ov90ResRec));
    work->count = count;
}

void ov90_02258E10(Ov90ResWork *work) {
    u32 i;
    for (i = 0; i < work->count; i++) {
        if (work->records[i].active == 1) {
            ov90_02258FB8(work, &work->records[i]);
        }
    }
    {
        int j;
        for (j = 0; j < 4; j++) {
            Destroy2DGfxResObjMan(work->man[j]);
        }
    }
    Heap_Free(work->records);
}

Ov90ResRec *ov90_02258E54(Ov90ResWork *work, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
    u32 i;
    Ov90ResRec *rec = NULL;
    for (i = 0; i < work->count; i++) {
        if (work->records[i].active == 0) {
            rec = &work->records[i];
            break;
        }
    }
    if (rec == NULL) {
        GF_AssertFail();
    }
    ov90_02258EE0(work, rec, a1, a2, a3, a4, a5, a6, a7, a8);
    return rec;
}

Sprite *ov90_02258EB4(void *work, SpriteList *list, int x, int y, u16 priority, enum HeapID heap) {
    SimpleSpriteTemplate template;
    template.spriteList = list;
    template.header = (const SpriteResourcesHeader *)((u8 *)work + 0x14);
    template.position.x = x << FX32_SHIFT;
    template.position.y = y << FX32_SHIFT;
    template.priority = priority;
    template.whichScreen = (NNS_G2D_VRAM_TYPE)1;
    template.heapID = heap;
    return Sprite_Create(&template);
}
