#include "overlay49_sprite_resources_r34_private.h"

void ov49_0225BFF0(void *p, void *mgr, NARC *narc, enum HeapID heapId, u32 idx, BOOL draw) {
    SpriteResourcesHeader hdr;
    u32 q, r;

    GF_ASSERT(idx < 0x1b);
    GF_ASSERT(PTR(p, 0x54) == NULL);
    q = idx / 3;
    r = idx % 3;

    PTR(p, 0x58) = AddCharResObjFromOpenNarc(PTR(mgr, 0x130), narc, q * 3 + 0x3d, FALSE, 0x64, (GfGfxResType)2, heapId);
    GF_ASSERT(SpriteTransfer_CreateCharTransferTask_AllocAtEnd(PTR(p, 0x58)));
    sub_0200A740(PTR(p, 0x58));
    PTR(p, 0x5c) = AddPlttResObjFromOpenNarc(PTR(mgr, 0x134), narc, 0x59, FALSE, 0x64, 2, 3, heapId);
    GF_ASSERT(SpriteTransfer_CreatePlttTransferTask(PTR(p, 0x5c)));
    sub_0200A740(PTR(p, 0x5c));
    PTR(p, 0x60) = AddCellOrAnimResObjFromOpenNarc(PTR(mgr, 0x138), narc, q * 3 + 0x3c, FALSE, 0x64, (GfGfxResType)2, heapId);
    PTR(p, 0x64) = AddCellOrAnimResObjFromOpenNarc(PTR(mgr, 0x13c), narc, q * 3 + 0x3b, FALSE, 0x64, (GfGfxResType)3, heapId);

    SimpleSpriteTemplate tmpl = { 0 };
    CreateSpriteResourcesHeader(&hdr, 0x64, 0x64, 0x64, 0x64, -1, -1, 0, 0, PTR(mgr, 0x130), PTR(mgr, 0x134), PTR(mgr, 0x138), PTR(mgr, 0x13c), NULL, NULL);
    tmpl.spriteList = PTR(mgr, 4);
    tmpl.header = &hdr;
    tmpl.priority = 0x10;
    tmpl.whichScreen = (NNS_G2D_VRAM_TYPE)2;
    tmpl.position.x = 0xd0000;
    tmpl.position.y = 0x198000;
    tmpl.heapID = heapId;
    PTR(p, 0x54) = Sprite_Create(&tmpl);
    Sprite_SetAnimCtrlSeq(PTR(p, 0x54), r);
    Sprite_SetDrawFlag(PTR(p, 0x54), draw);
}
