#include "overlay81_sprite_graphics_r16_private.h"

void ov81_0224276C(Ov81SpriteWorkR16 *work) {
    int i;

    ov81_02242B90();
    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 0x80, 0, 0x20, 0, 0x80, 0, 0x20, HEAP_ID_100);
    work->spriteList = G2dRenderer_Init(0x20, (G2dRenderer *)&work->rendererAndPadding, HEAP_ID_100);
    G2dRenderer_SetSubSurfaceCoords((G2dRenderer *)&work->rendererAndPadding, 0, 2 << 20);

    for (i = 0; i < 4; i++) {
        work->resourceManagers[i] = Create2DGfxResObjMan(ov81_02243594[i], (GfGfxResType)i, HEAP_ID_100);
    }

    work->resourceObjects[1][0] = AddCharResObjFromNarc(work->resourceManagers[0], (NarcId)0xB8, 0x28, TRUE, 1, 1, HEAP_ID_100);
    work->resourceObjects[1][1] = AddPlttResObjFromNarc(work->resourceManagers[1], (NarcId)0xB8, 0x3E, FALSE, 1, 1, 4, HEAP_ID_100);
    work->resourceObjects[1][2] = AddCellOrAnimResObjFromNarc(work->resourceManagers[2], (NarcId)0xB8, 0x29, TRUE, 1, GF_GFX_RES_TYPE_CELL, HEAP_ID_100);
    work->resourceObjects[1][3] = AddCellOrAnimResObjFromNarc(work->resourceManagers[3], (NarcId)0xB8, 0x2A, TRUE, 1, GF_GFX_RES_TYPE_ANIM, HEAP_ID_100);

    work->resourceObjects[2][0] = AddCharResObjFromNarc(work->resourceManagers[0], (NarcId)0xB8, 0x2B, TRUE, 2, 1, HEAP_ID_100);
    work->resourceObjects[2][1] = AddPlttResObjFromNarc(work->resourceManagers[1], (NarcId)0xB8, 0x3F, FALSE, 2, 1, 1, HEAP_ID_100);
    work->resourceObjects[2][2] = AddCellOrAnimResObjFromNarc(work->resourceManagers[2], (NarcId)0xB8, 0x2C, TRUE, 2, GF_GFX_RES_TYPE_CELL, HEAP_ID_100);
    work->resourceObjects[2][3] = AddCellOrAnimResObjFromNarc(work->resourceManagers[3], (NarcId)0xB8, 0x2D, TRUE, 2, GF_GFX_RES_TYPE_ANIM, HEAP_ID_100);

    work->resourceObjects[0][0] = AddCharResObjFromNarc(work->resourceManagers[0], (NarcId)0xB8, 0, TRUE, 0, 2, HEAP_ID_100);
    work->resourceObjects[0][1] = AddPlttResObjFromNarc(work->resourceManagers[1], (NarcId)0xB8, 0x34, FALSE, 0, 2, 8, HEAP_ID_100);
    work->resourceObjects[0][2] = AddCellOrAnimResObjFromNarc(work->resourceManagers[2], (NarcId)0xB8, 2, TRUE, 0, GF_GFX_RES_TYPE_CELL, HEAP_ID_100);
    work->resourceObjects[0][3] = AddCellOrAnimResObjFromNarc(work->resourceManagers[3], (NarcId)0xB8, 1, TRUE, 0, GF_GFX_RES_TYPE_ANIM, HEAP_ID_100);

    work->resourceObjects[3][0] = AddCharResObjFromNarc(work->resourceManagers[0], (NarcId)0xB8, 0x2B, TRUE, 3, 2, HEAP_ID_100);
    work->resourceObjects[3][1] = AddPlttResObjFromNarc(work->resourceManagers[1], (NarcId)0xB8, 0x3F, FALSE, 3, 2, 1, HEAP_ID_100);
    work->resourceObjects[3][2] = AddCellOrAnimResObjFromNarc(work->resourceManagers[2], (NarcId)0xB8, 0x2C, TRUE, 3, GF_GFX_RES_TYPE_CELL, HEAP_ID_100);
    work->resourceObjects[3][3] = AddCellOrAnimResObjFromNarc(work->resourceManagers[3], (NarcId)0xB8, 0x2D, TRUE, 3, GF_GFX_RES_TYPE_ANIM, HEAP_ID_100);

    for (i = 0; i < 2; i++) {
        work->resourceObjects[i + 4][0] = AddCharResObjFromNarc(work->resourceManagers[0], (NarcId)0xB8, 0x2E, TRUE, i + 4, 2, HEAP_ID_100);
        work->resourceObjects[i + 4][1] = AddPlttResObjFromNarc(work->resourceManagers[1], (NarcId)0x14, sub_02074490(), FALSE, i + 4, 2, 3, HEAP_ID_100);
        work->resourceObjects[i + 4][2] = AddCellOrAnimResObjFromNarc(work->resourceManagers[2], (NarcId)0xB8, 0x2F, TRUE, i + 4, GF_GFX_RES_TYPE_CELL, HEAP_ID_100);
        work->resourceObjects[i + 4][3] = AddCellOrAnimResObjFromNarc(work->resourceManagers[3], (NarcId)0xB8, 0x30, TRUE, i + 4, GF_GFX_RES_TYPE_ANIM, HEAP_ID_100);
    }

    for (i = 0; i < 6; i++) {
        SpriteTransfer_CreateCharTransferTask(work->resourceObjects[i][0]);
        SpriteTransfer_CreateExtPlttTransferTask(work->resourceObjects[i][1]);
    }

    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, TRUE);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, TRUE);
}

Sprite *ov81_02242A8C(Ov81SpriteWorkR16 *work, int resourceId, int animSeq, int drawPriority, int priority, u8 screen) {
    SpriteResourcesHeader header;
    SpriteTemplate template;
    Sprite *sprite;

    CreateSpriteResourcesHeader(&header, resourceId, resourceId, resourceId, resourceId, -1, -1, 0, priority, work->resourceManagers[0], work->resourceManagers[1], work->resourceManagers[2], work->resourceManagers[3], NULL, NULL);

    template.spriteList = work->spriteList;
    template.header = &header;
    template.position.x = 0;
    template.position.y = 0;
    template.position.z = 0;
    template.scale.x = FX32_ONE;
    template.scale.y = FX32_ONE;
    template.scale.z = FX32_ONE;
    template.rotation = 0;
    template.drawPriority = drawPriority;
    if (screen == 0) {
        template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    } else {
        template.whichScreen = NNS_G2D_VRAM_TYPE_2DSUB;
    }
    template.heapID = HEAP_ID_100;
    if (screen == 1) {
        template.position.y += 2 << 20;
    }

    sprite = Sprite_CreateAffine(&template);
    Sprite_SetAnimActiveFlag(sprite, TRUE);
    Sprite_SetAnimCtrlSeq(sprite, animSeq);
    return sprite;
}

void ov81_02242B38(Ov81SpriteWorkR16 *work) {
    u8 i;

    for (i = 0; i < 6; i++) {
        SpriteTransfer_DeleteCharTransferTask(work->resourceObjects[i][0]);
        SpriteTransfer_DeletePlttTransferTask(work->resourceObjects[i][1]);
    }

    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(work->resourceManagers[i]);
    }

    SpriteList_Delete(work->spriteList);
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
}

void ov81_02242B90(void) {
    ObjCharTransferTemplate template = ov81_02243598;

    ObjCharTransfer_InitEx(&template, (GXOBJVRamModeChar)0x00100010, (GXOBJVRamModeChar)0x00100010);
    ObjPlttTransfer_Init(8, HEAP_ID_100);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
}

void ov81_02242BC8(void) {
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, TRUE);
    G2_SetBG0Priority(0);
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(TRUE);
    G3X_AlphaTest(FALSE, 0);
    G3X_AlphaBlend(TRUE);
    G3X_EdgeMarking(FALSE);
    G3X_SetFog(FALSE, GX_FOGBLEND_COLOR_ALPHA, GX_FOGSLOPE_0x8000, 0);
    G3X_SetClearColor(0, 0, 0x7FFF, 0x3F, FALSE);
    *(vu32 *)0x04000580 = 0xBFFF0000;
}

void ov81_02242C48(PokepicManager *manager) {
    vu32 *a = (vu32 *)0x04000440;
    vu32 *b = (vu32 *)0x04000454;

    Thunk_G3X_Reset();
    *a = 0;
    *b = 0;
    *a = 2;
    *b = 0;
    NNS_G3dGlbFlushP();
    NNS_G2dSetupSoftwareSpriteCamera();
    PokepicManager_DrawAll(manager);
    *(vu32 *)0x04000540 = 1;
}

Pokepic *ov81_02242C80(PokepicManager *manager, int polygonId, Pokemon *mon, int x, int y, int z) {
    PokepicTemplate template;

    GetPokemonSpriteCharAndPlttNarcIds(&template, mon, 2);
    return PokepicManager_CreatePokepic(manager, &template, x, y, z, polygonId, NULL, NULL);
}
