#include "overlay02_gfx_res_mgr_private.h"

static inline void FillSlotIds(ResSlot *p, int n, int v);
void ov02_02248728(GfxWork *work, int numSprites, int numChar, int numPltt, int numCell, int numAnim, int charNone, int plttNone, int cellNone, int animNone);

void ov02_0224886C(GfxWork *work) {
    int i;

    for (i = 0; i < work->charCount; i++) {
        if (work->charNone != work->charRes[i].id) {
            SpriteTransfer_DeleteCharTransferTask(work->charRes[i].res);
        }
    }
    for (i = 0; i < work->plttCount; i++) {
        if (work->plttNone != work->plttRes[i].id) {
            SpriteTransfer_DeletePlttTransferTask(work->plttRes[i].res);
        }
    }
    for (i = 0; i < work->cellCount; i++) {
        if (work->cellNone != work->cellRes[i].id) {
            sub_0200A740(work->cellRes[i].res);
        }
    }
    for (i = 0; i < work->animCount; i++) {
        if (work->animNone != work->animRes[i].id) {
            sub_0200A740(work->animRes[i].res);
        }
    }
    Destroy2DGfxResObjMan(work->charMan);
    Destroy2DGfxResObjMan(work->plttMan);
    Destroy2DGfxResObjMan(work->cellMan);
    Destroy2DGfxResObjMan(work->animMan);
    Heap_Free(work->charRes);
    Heap_Free(work->plttRes);
    Heap_Free(work->cellRes);
    Heap_Free(work->animRes);
    SpriteList_DeleteAllSprites(work->list);
    SpriteList_Delete(work->list);
}

void ov02_02248980(GfxWork *work, NARC *narc, int fileId, int id) {
    int i;

    for (i = 0; i < work->charCount; i++) {
        if (work->charNone == work->charRes[i].id) {
            work->charRes[i].id = id;
            work->charRes[i].unk2 = 0;
            work->charRes[i].res = AddCharResObjFromOpenNarc(work->charMan, narc, fileId, FALSE, id, 1, HEAP_ID_FIELD1);
            return;
        }
    }
    GF_AssertFail();
}

void ov02_022489F0(GfxWork *work, int id) {
    int i;

    for (i = 0; i < work->charCount; i++) {
        if (id == work->charRes[i].id) {
            SpriteTransfer_CreateCharTransferTask_AllocAtEnd(work->charRes[i].res);
            return;
        }
    }
    GF_AssertFail();
}

void ov02_02248A24(GfxWork *work, int id) {
    int i;

    for (i = 0; i < work->charCount; i++) {
        if (id == work->charRes[i].id) {
            sub_0200A740(work->charRes[i].res);
            return;
        }
    }
    GF_AssertFail();
}

void ov02_02248A58(GfxWork *work, NARC *narc, int fileId, int id) {
    int i;

    for (i = 0; i < work->charCount; i++) {
        if (work->plttNone == work->plttRes[i].id) {
            work->plttRes[i].id = id;
            work->plttRes[i].unk2 = 0;
            work->plttRes[i].res = AddPlttResObjFromOpenNarc(work->plttMan, narc, fileId, FALSE, id, 1, 1, HEAP_ID_FIELD1);
            return;
        }
    }
    GF_AssertFail();
}

void ov02_02248AC8(GfxWork *work, int id) {
    int i;

    for (i = 0; i < work->plttCount; i++) {
        if (id == work->plttRes[i].id) {
            SpriteTransfer_CreatePlttTransferTask(work->plttRes[i].res);
            return;
        }
    }
    GF_AssertFail();
}

void ov02_02248AFC(GfxWork *work, int id) {
    int i;

    for (i = 0; i < work->plttCount; i++) {
        if (id == work->plttRes[i].id) {
            sub_0200A740(work->plttRes[i].res);
            return;
        }
    }
    GF_AssertFail();
}

void ov02_02248B30(GfxWork *work, NARC *narc, int fileId, int id) {
    int i;

    for (i = 0; i < work->charCount; i++) {
        if (work->cellNone == work->cellRes[i].id) {
            work->cellRes[i].id = id;
            work->cellRes[i].unk2 = 0;
            work->cellRes[i].res = AddCellOrAnimResObjFromOpenNarc(work->cellMan, narc, fileId, FALSE, id, GF_GFX_RES_TYPE_CELL, HEAP_ID_FIELD1);
            return;
        }
    }
    GF_AssertFail();
}

void ov02_02248BA0(GfxWork *work, NARC *narc, int fileId, int id) {
    int i;

    for (i = 0; i < work->charCount; i++) {
        if (work->animNone == work->animRes[i].id) {
            work->animRes[i].id = id;
            work->animRes[i].unk2 = 0;
            work->animRes[i].res = AddCellOrAnimResObjFromOpenNarc(work->animMan, narc, fileId, FALSE, id, GF_GFX_RES_TYPE_ANIM, HEAP_ID_FIELD1);
            return;
        }
    }
    GF_AssertFail();
}

Sprite *ov02_02248C10(GfxWork *work, const VecFx32 *pos, int charId, int plttId, int cellId, int animId, int priority, u32 drawPriority) {
    SpriteResourcesHeader header;
    SimpleSpriteTemplate template;
    Sprite *sprite;

    if (animId == work->animNone) {
        animId = -1;
    }
    CreateSpriteResourcesHeader(&header, charId, plttId, cellId, animId, -1, -1, 0, priority, work->charMan, work->plttMan, work->cellMan, work->animMan, NULL, NULL);
    template.spriteList = work->list;
    template.header = &header;
    template.position = *pos;
    template.priority = drawPriority;
    template.whichScreen = (NNS_G2D_VRAM_TYPE)1;
    template.heapID = HEAP_ID_FIELD1;
    sprite = Sprite_Create(&template);
    if (sprite == NULL) {
        GF_AssertFail();
    }
    return sprite;
}
