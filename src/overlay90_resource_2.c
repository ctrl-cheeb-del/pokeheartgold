#include "overlay90_resource_internal.h"

void ov90_02258FB8(Ov90ResWork *work, Ov90ResRec *rec) {
    int i;
    if (rec->active != 1) {
        GF_AssertFail();
    }
    rec->active = 0;
    SpriteTransfer_DeleteCharTransferTask(rec->obj[0]);
    SpriteTransfer_DeletePlttTransferTask(rec->obj[1]);
    for (i = 0; i < 4; i++) {
        DestroySingle2DGfxResObj(work->man[i], rec->obj[i]);
    }
}

void ov90_02258FF0(Ov90BgWork *work, const GraphicsModes *modes, Ov90BgTemplate *templates, u32 count, enum HeapID heap) {
    u32 i;
    Ov90BgTemplate *templateIt;
    Ov90BgTemplate *idIt;
    SetBothScreensModesAndDisable(modes);
    work->bg = BgConfig_Alloc(heap);
    work->templates = templates;
    work->count = count;
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    templateIt = templates;
    for (i = 0; i < count; i++) {
        idIt = &templates[i];
        InitBgFromTemplate(work->bg, (u8)idIt->bgId, &templateIt->template, 0);
        BG_ClearCharDataRange((u8)idIt->bgId, 0x20, 0, heap);
        BgClearTilemapBufferAndCommit(work->bg, (u8)idIt->bgId);
        BgSetPosTextAndCommit(work->bg, (u8)idIt->bgId, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(work->bg, (u8)idIt->bgId, BG_POS_OP_SET_Y, 0);
        templateIt++;
    }
}

void ov90_02259084(Ov90BgWork *work) {
    u32 i;
    BgSetPosTextAndCommit(work->bg, 3, BG_POS_OP_SET_Y, 0);
    for (i = 0; i < work->count; i++) {
        FreeBgTilemapBuffer(work->bg, (u8)work->templates[i].bgId);
    }
    Heap_Free(work->bg);
}
