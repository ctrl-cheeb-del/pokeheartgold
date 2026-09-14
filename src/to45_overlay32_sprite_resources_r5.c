#include "to45_overlay32_sprite_resources_r5_private.h"

void ov32_0225DB1C(SpriteResource **resObjs, GF_2DGfxResMan **resMans, NARC *narc, int charFileId, int plttFileId, int cellFileId, int animFileId, int plttNum, int charId, int plttId, int cellId, int animId) {
    resObjs[GF_GFX_RES_TYPE_CHAR] = AddCharResObjFromOpenNarc(resMans[GF_GFX_RES_TYPE_CHAR], narc, charFileId, TRUE, charId, NNS_G2D_VRAM_TYPE_2DSUB, HEAP_ID_8);
    SpriteTransfer_CreateCharTransferTask_AllocAtEnd(resObjs[GF_GFX_RES_TYPE_CHAR]);
    sub_0200A740(resObjs[GF_GFX_RES_TYPE_CHAR]);

    resObjs[GF_GFX_RES_TYPE_PLTT] = AddPlttResObjFromOpenNarc(resMans[GF_GFX_RES_TYPE_PLTT], narc, plttFileId, FALSE, plttId, NNS_G2D_VRAM_TYPE_2DSUB, plttNum, HEAP_ID_8);
    SpriteTransfer_CreatePlttTransferTask(resObjs[GF_GFX_RES_TYPE_PLTT]);
    sub_0200A740(resObjs[GF_GFX_RES_TYPE_PLTT]);

    resObjs[GF_GFX_RES_TYPE_CELL] = AddCellOrAnimResObjFromOpenNarc(resMans[GF_GFX_RES_TYPE_CELL], narc, cellFileId, TRUE, cellId, GF_GFX_RES_TYPE_CELL, HEAP_ID_8);
    resObjs[GF_GFX_RES_TYPE_ANIM] = AddCellOrAnimResObjFromOpenNarc(resMans[GF_GFX_RES_TYPE_ANIM], narc, animFileId, TRUE, animId, GF_GFX_RES_TYPE_ANIM, HEAP_ID_8);
}

void ov32_0225DBAC(SpriteResource **resObjs, GF_2DGfxResMan **resMans, SpriteResourcesHeader *header, int priority) {
    int charId = GF2DGfxResObj_GetResID(resObjs[GF_GFX_RES_TYPE_CHAR]);
    int plttId = GF2DGfxResObj_GetResID(resObjs[GF_GFX_RES_TYPE_PLTT]);
    int cellId = GF2DGfxResObj_GetResID(resObjs[GF_GFX_RES_TYPE_CELL]);
    int animId = GF2DGfxResObj_GetResID(resObjs[GF_GFX_RES_TYPE_ANIM]);

    CreateSpriteResourcesHeader(header, charId, plttId, cellId, animId, -1, -1, 0, priority, resMans[GF_GFX_RES_TYPE_CHAR], resMans[GF_GFX_RES_TYPE_PLTT], resMans[GF_GFX_RES_TYPE_CELL], resMans[GF_GFX_RES_TYPE_ANIM], NULL, NULL);
}

void ov32_0225DC0C(NamePickerDataPartial *data, int index, SpriteResourcesHeader *header, const u8 *spec) {
    SpriteTemplate template;

    template.spriteList = data->spriteList;
    template.header = header;
    template.position.x = spec[0] << FX32_SHIFT;
    template.position.y = (spec[1] << FX32_SHIFT) + FX32_CONST(256);
    template.position.z = 0;
    template.scale.x = FX32_ONE;
    template.scale.y = FX32_ONE;
    template.scale.z = FX32_ONE;
    template.rotation = 0;
    template.drawPriority = spec[2];
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DSUB;
    template.heapID = HEAP_ID_8;
    data->sprites[index] = Sprite_CreateAffine(&template);
    Sprite_SetAnimCtrlSeq(data->sprites[index], spec[3]);
}

void ov32_0225DC68(NamePickerDataPartial *data, NARC *narc) {
    SpriteResourcesHeader header;
    u32 i;

    ov32_0225DB1C(data->resObjs, data->resMans, narc, 4, 7, 5, 6, 1, 0x781, 0x781, 0x781, 0x781);
    ov32_0225DBAC(data->resObjs, data->resMans, &header, 1);
    for (i = 0; i < NAME_PICKER_NUM_SPRITES; i++) {
        ov32_0225DC0C(data, i, &header, ov32_0225E178[i]);
    }
}
