#include "overlay18_sprite_resource_setup_r41_private.h"

#define PTR_AT(p, offset) (*(void **)((u8 *)(p) + (offset)))
#define U32_AT(p, offset) (*(u32 *)((u8 *)(p) + (offset)))

void ov18_021F922C(SpriteResource **resources, GF_2DGfxResMan **managers, enum HeapID heapId, NARC *narc, int charFileId, int plttFileId, int cellFileId, int animFileId, int plttNum, int charId, int plttId, int cellId, int animId) {
    resources[0] = AddCharResObjFromOpenNarc(managers[0], narc, charFileId, TRUE, charId, 1, heapId);
    SpriteTransfer_CreateCharTransferTask_AllocAtEnd(resources[0]);
    sub_0200A740(resources[0]);
    if (plttFileId != -1) {
        resources[1] = ov18_021F92AC(managers[1], heapId, narc, plttFileId, plttNum, plttId);
    }
    resources[2] = AddCellOrAnimResObjFromOpenNarc(managers[2], narc, cellFileId, TRUE, cellId, GF_GFX_RES_TYPE_CELL, heapId);
    resources[3] = AddCellOrAnimResObjFromOpenNarc(managers[3], narc, animFileId, TRUE, animId, GF_GFX_RES_TYPE_ANIM, heapId);
}

SpriteResource *ov18_021F92AC(GF_2DGfxResMan *manager, enum HeapID heapId, NARC *narc, int fileId, int plttNum, int id) {
    SpriteResource *resource = AddPlttResObjFromOpenNarc(manager, narc, fileId, FALSE, id, 1, plttNum, heapId);
    SpriteTransfer_CreatePlttTransferTask(resource);
    sub_0200A740(resource);
    return resource;
}

void ov18_021F92DC(SpriteResource **resources, GF_2DGfxResMan **managers) {
    SpriteTransfer_DeleteCharTransferTask(resources[0]);
    SpriteTransfer_DeletePlttTransferTask(resources[1]);
    DestroySingle2DGfxResObj(managers[0], resources[0]);
    DestroySingle2DGfxResObj(managers[1], resources[1]);
    DestroySingle2DGfxResObj(managers[2], resources[2]);
    DestroySingle2DGfxResObj(managers[3], resources[3]);
}

void ov18_021F9310(SpriteResource **resources, GF_2DGfxResMan **managers, SpriteResourcesHeader *header, int priority) {
    int charId = GF2DGfxResObj_GetResID(resources[0]);
    int plttId = GF2DGfxResObj_GetResID(resources[1]);
    int cellId = GF2DGfxResObj_GetResID(resources[2]);
    int animId = GF2DGfxResObj_GetResID(resources[3]);

    CreateSpriteResourcesHeader(header, charId, plttId, cellId, animId, -1, -1, 0, priority, managers[0], managers[1], managers[2], managers[3], NULL, NULL);
}

void ov18_021F9370(void *work) {
    SimpleSpriteTemplate template;
    SpriteResourcesHeader header;
    int charId;
    int plttId;
    int cellId;
    int animId;

    ov18_021F9310((SpriteResource **)((u8 *)work + 0x208), (GF_2DGfxResMan **)((u8 *)work + 0x1E0), &header, 1);
    template.spriteList = PTR_AT(work, 0xB4);
    template.header = &header;
    template.whichScreen = (NNS_G2D_VRAM_TYPE)1;
    template.priority = 0;
    template.heapID = (enum HeapID)U32_AT(work, 0x14);
    template.position.x = 0xA8000;
    template.position.y = 0x48000;
    PTR_AT(work, 0x204) = Sprite_Create(&template);
    Sprite_SetPalIndexRespectVramOffset(PTR_AT(work, 0x204), ov18_021F9688(PTR_AT(work, 0x24C)));

    charId = GF2DGfxResObj_GetResID(PTR_AT(work, 0x21C));
    plttId = GF2DGfxResObj_GetResID(PTR_AT(work, 0x20C));
    cellId = GF2DGfxResObj_GetResID(PTR_AT(work, 0x224));
    animId = GF2DGfxResObj_GetResID(PTR_AT(work, 0x228));
    CreateSpriteResourcesHeader(&header, charId, plttId, cellId, animId, -1, -1, 0, 1, PTR_AT(work, 0x1E0), PTR_AT(work, 0x1E4), PTR_AT(work, 0x1E8), PTR_AT(work, 0x1EC), NULL, NULL);
    template.spriteList = PTR_AT(work, 0xB4);
    template.header = &header;
    template.whichScreen = (NNS_G2D_VRAM_TYPE)1;
    template.priority = 0;
    template.heapID = (enum HeapID)U32_AT(work, 0x14);
    template.position.x = 0xD9000;
    template.position.y = 0x48000;
    PTR_AT(work, 0x218) = Sprite_Create(&template);
    if (PTR_AT(work, 0x250) == NULL || PTR_AT(work, 0x24C) == PTR_AT(work, 0x250)) {
        Sprite_SetDrawFlag(PTR_AT(work, 0x218), FALSE);
    } else {
        Sprite_SetPalIndexRespectVramOffset(PTR_AT(work, 0x218), ov18_021F9688(PTR_AT(work, 0x250)));
    }
}
