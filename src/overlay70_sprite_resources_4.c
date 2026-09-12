#include "overlay70_sprite_resources_4_private.h"

void ov70_02238880(void) {
    vu32 *main;
    vu32 *sub = (vu32 *)0x04001000;
    u32 mask = 0xFFFF1FFF;
    u32 value;

    main = (vu32 *)((u32)sub << 14);
    *sub = *sub & mask;
    value = *main;
    value &= mask;
    *main = value | ((u32)sub >> 13);
    G2_SetWnd0InsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, FALSE);
    G2_SetWndOutsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, TRUE);
    G2_SetWnd0Position(0xF0, 0, 0xFF, 0x10);
}

void ov70_022388D0(void) {
    ObjCharTransferTemplate template = ov70_02245208;
    ObjCharTransfer_Init(&template);
    ObjPlttTransfer_Init(0x14, HEAP_ID_61);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
}

void ov70_02238900(Ov70WorkR4 *work) {
    NARC *narc = NARC_New((NarcId)0x64, HEAP_ID_61);
    int i;
    void *rawPalette;
    NNSG2dPaletteData *palette;

    NNS_G2dInitOamManagerModule();
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    GXS_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    OamManager_Create(0, 0x7A, 0, 0x20, 0, 0x7E, 0, 0x20, HEAP_ID_61);
    work->spriteList = G2dRenderer_Init(0x54, &work->renderer, HEAP_ID_61);
    G2dRenderer_SetSubSurfaceCoords(&work->renderer, 0, FX32_CONST(0x100));
    for (i = 0; i < 4; i++) {
        work->resourceManagers[i] = Create2DGfxResObjMan(3, (GfGfxResType)i, HEAP_ID_61);
    }

    work->resources[0] = AddCharResObjFromOpenNarc(work->resourceManagers[0], narc, 0x15, TRUE, 0, NNS_G2D_VRAM_TYPE_2DMAIN, HEAP_ID_61);
    work->resources[1] = AddPlttResObjFromOpenNarc(work->resourceManagers[1], narc, 0xA, FALSE, 0, NNS_G2D_VRAM_TYPE_2DMAIN, 3, HEAP_ID_61);
    work->resources[2] = AddCellOrAnimResObjFromOpenNarc(work->resourceManagers[2], narc, 0x16, TRUE, 0, GF_GFX_RES_TYPE_CELL, HEAP_ID_61);
    work->resources[3] = AddCellOrAnimResObjFromOpenNarc(work->resourceManagers[3], narc, 0x17, TRUE, 0, GF_GFX_RES_TYPE_ANIM, HEAP_ID_61);
    work->resources[4] = AddCharResObjFromOpenNarc(work->resourceManagers[0], narc, 0x2B, TRUE, 1, NNS_G2D_VRAM_TYPE_2DSUB, HEAP_ID_61);
    work->resources[5] = AddPlttResObjFromOpenNarc(work->resourceManagers[1], narc, 9, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 10, HEAP_ID_61);
    work->resources[6] = AddCellOrAnimResObjFromOpenNarc(work->resourceManagers[2], narc, 0x2C, TRUE, 1, GF_GFX_RES_TYPE_CELL, HEAP_ID_61);
    work->resources[7] = AddCellOrAnimResObjFromOpenNarc(work->resourceManagers[3], narc, 0x2D, TRUE, 1, GF_GFX_RES_TYPE_ANIM, HEAP_ID_61);

    SpriteTransfer_CreateCharTransferTask(work->resources[0]);
    SpriteTransfer_CreateCharTransferTask(work->resources[4]);
    SpriteTransfer_CreateExtPlttTransferTask(work->resources[1]);
    SpriteTransfer_CreateExtPlttTransferTask(work->resources[5]);

    rawPalette = GfGfxLoader_GetPlttData((NarcId)0x14, sub_02074490(), &palette, HEAP_ID_61);
    DC_FlushRange(palette->pRawData, 0x60);
    GX_LoadOBJPltt(palette->pRawData, 0x60, 0x60);
    {
        u16 *colors = palette->pRawData;
        int j;
        int red;
        int green;
        int blue;
        for (j = 0; j < 0x30; j++) {
            int color = colors[j];
            red = color & 0x1F;
            green = (color >> 5) & 0x1F;
            blue = (color >> 10) & 0x1F;
            red /= 2;
            green /= 2;
            blue /= 2;
            colors[j] = (blue << 10) | (green << 5) | red;
        }
    }
    DC_FlushRange(palette->pRawData, 0x60);
    GX_LoadOBJPltt(palette->pRawData, 0xC0, 0x60);
    Heap_Free(rawPalette);
    NARC_Delete(narc);
}

void ov70_02238B54(SpriteTemplate *template, Ov70WorkR4 *work, const SpriteResourcesHeader *header, NNS_G2D_VRAM_TYPE screen) {
    template->spriteList = work->spriteList;
    template->header = header;
    template->position.z = 0;
    template->scale.x = FX32_ONE;
    template->scale.y = FX32_ONE;
    template->scale.z = FX32_ONE;
    template->rotation = 0;
    template->drawPriority = 1;
    template->whichScreen = screen;
    template->heapID = HEAP_ID_61;
}

void ov70_02238B80(Ov70WorkR4 *work) {
    CreateSpriteResourcesHeader(&work->headers[0], 0, 0, 0, 0, -1, -1, 0, 0, work->resourceManagers[0], work->resourceManagers[1], work->resourceManagers[2], work->resourceManagers[3], NULL, NULL);
    CreateSpriteResourcesHeader(&work->headers[1], 1, 1, 1, 1, -1, -1, 0, 0, work->resourceManagers[0], work->resourceManagers[1], work->resourceManagers[2], work->resourceManagers[3], NULL, NULL);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, TRUE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, TRUE);
}

YesNoPrompt *ov70_02238C14(BgConfig *bgConfig, u8 y, int tileStart, u32 palette, u8 playSound) {
    return ov70_02238C2C(bgConfig, y, tileStart, palette, 0, playSound);
}
YesNoPrompt *ov70_02238C2C(BgConfig *bgConfig, u8 y, int tileStart, u32 palette, int bgId, u8 playSound) {
    YesNoPrompt *prompt = YesNoPrompt_Create(HEAP_ID_61);
    YesNoPromptTemplate template;

    if (playSound) {
        int flag = 0;
        if (bgId <= 3) {
            flag = 1;
        }
        ov70_02238FB4(flag);
    }
    template.bgConfig = bgConfig;
    template.bgId = bgId;
    template.tileStart = tileStart;
    template.plttSlot = palette;
    template.x = 0x18;
    template.y = y;
    template.ignoreTouchFlag = 0;
    template.initialCursorPos = 0;
    template.shapeParam = 0;
    YesNoPrompt_InitFromTemplate(prompt, &template);
    return prompt;
}
YesNoResponse ov70_02238C8C(Ov70WorkR4 *work) {
    YesNoResponse response = YesNoPrompt_HandleInput(work->yesNoPrompt);
    if (response == YESNORESPONSE_YES || response == YESNORESPONSE_NO) {
        ov70_02238FE0();
    }
    return response;
}
TouchscreenListMenu *ov70_02238CAC(Ov70WorkR4 *work, u8 numWindows, int y) {
    TouchscreenListMenuHeader header;
    TouchscreenListMenu *menu;

    work->menuSpawner = TouchscreenListMenuSpawner_Create(HEAP_ID_61, NULL);
    MI_CpuFill8(&header, 0, sizeof(header));
    header.template = _022451EC;
    header.listMenuItems = work->listItems;
    header.bgConfig = work->bgConfig;
    header.numWindows = numWindows;
    menu = TouchscreenListMenu_CreateWithCallback(work->menuSpawner, &header, FALSE, 0x14, y, 10, 0, ov70_02238D38, NULL, TRUE);
    ov70_02238FB4(1);
    return menu;
}
void ov70_02238D38(TouchscreenListMenu *menu, u8 cursorPos, void *callbackArg, int event) {
    switch (event) {
    case 0:
        break;
    case 1:
    case 2:
    case 3:
        PlaySE(0x5DC);
        break;
    }
}
