#include "overlay49_sprite_resources_r34_private.h"

void ov49_0225C180(void *p, void *mgr, NARC *narc, enum HeapID heapId, u32 key) {
    Ov49Files files;
    SpriteResourcesHeader hdr;
    u16 sub, x;
    u16 y;
    u32 i;

    GF_ASSERT(PTR(p, 0x68) == NULL);
    for (i = 0; i < 0x12; i++) {
        if (key == ov49_0226988C[i].key) {
            sub = ov49_0226988C[i].a;
            x = ov49_0226988C[i].b;
            y = ov49_0226988C[i].c;
        }
    }
    sub_02070D84(sub, 2, &files);

    PTR(p, 0x6c) = AddCharResObjFromNarc(PTR(mgr, 0x130), (NarcId)files.narcId, files.charFile, FALSE, 0x65, (GfGfxResType)2, heapId);
    GF_ASSERT(SpriteTransfer_CreateCharTransferTask_AllocAtEnd(PTR(p, 0x6c)));
    PTR(p, 0x70) = AddPlttResObjFromNarc(PTR(mgr, 0x134), (NarcId)files.narcId, files.plttFile, FALSE, 0x65, 2, 1, heapId);
    ov49_0225C368(GF2DGfxResObj_GetPlttDataPtr(PTR(p, 0x70)));
    GF_ASSERT(SpriteTransfer_CreatePlttTransferTask(PTR(p, 0x70)));
    sub_0200A740(PTR(p, 0x70));
    PTR(p, 0x74) = AddCellOrAnimResObjFromNarc(PTR(mgr, 0x138), (NarcId)files.narcId, files.cellFile, FALSE, 0x65, (GfGfxResType)2, heapId);
    PTR(p, 0x78) = AddCellOrAnimResObjFromNarc(PTR(mgr, 0x13c), (NarcId)files.narcId, files.animFile, FALSE, 0x65, (GfGfxResType)3, heapId);

    SimpleSpriteTemplate tmpl = { 0 };
    CreateSpriteResourcesHeader(&hdr, 0x65, 0x65, 0x65, 0x65, -1, -1, 1, 3, PTR(mgr, 0x130), PTR(mgr, 0x134), PTR(mgr, 0x138), PTR(mgr, 0x13c), NULL, NULL);
    tmpl.spriteList = PTR(mgr, 4);
    tmpl.header = &hdr;
    tmpl.priority = 0x20;
    tmpl.whichScreen = (NNS_G2D_VRAM_TYPE)2;
    tmpl.heapID = heapId;
    tmpl.position.x = FX32_CONST(x);
    tmpl.position.y = FX32_CONST(y) + 0x100000;
    PTR(p, 0x68) = Sprite_Create(&tmpl);
}
