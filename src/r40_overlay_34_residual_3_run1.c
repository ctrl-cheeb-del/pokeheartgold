#include "r40_overlay_34_residual_3_private.h"

void ov34_0225D924(void *bg) {
    BgTemplate template4;
    BgTemplate template5;
    BgTemplate template6;
    BgTemplate template7;
    ov34_0225D900(bg);
    template4 = ov34_0225E714;
    InitBgFromTemplate(bg, 4, &template4, 0);
    BgClearTilemapBufferAndCommit(bg, 4);
    GfGfx_EngineBTogglePlanes(1, 0);
    template5 = ov34_0225E6F8;
    InitBgFromTemplate(bg, 5, &template5, 0);
    BgClearTilemapBufferAndCommit(bg, 5);
    GfGfx_EngineBTogglePlanes(2, 0);
    template6 = ov34_0225E6C0;
    InitBgFromTemplate(bg, 6, &template6, 0);
    BgClearTilemapBufferAndCommit(bg, 6);
    GfGfx_EngineBTogglePlanes(4, 0);
    template7 = ov34_0225E6DC;
    InitBgFromTemplate(bg, 7, &template7, 0);
    GfGfx_EngineBTogglePlanes(8, 0);
    GfGfxLoader_GXLoadPal(0x49, 0, 4, 0, 0x60, 4);
    GfGfxLoader_LoadCharData(0x49, 2, bg, 7, 0, 0x1400, 1, 4);
    GfGfxLoader_LoadScrnData(0x49, 4, bg, 7, 0, 0x600, 1, 4);
    FieldMessage_LoadTextPalettes(4, 0);
}

void ov34_0225DA50(Ov34State *state) {
    int i;
    Ov34State *cursor;
    PTR_AT(state, 0x28) = G2dRenderer_Init(10, (G2dRenderer *)(state->raw + 0x2C), (enum HeapID)4);
    i = 0;
    cursor = state;
    while (i < 4) {
        PTR_AT(cursor, 0x154) = Create2DGfxResObjMan(1, (GfGfxResType)i, (enum HeapID)4);
        i++;
        cursor = (Ov34State *)((u8 *)cursor + 4);
    }
    PTR_AT(state, 0x164) = AddCharResObjFromNarc((GF_2DGfxResMan *)PTR_AT(state, 0x154), (NarcId)0x49, 5, 1, 0x3E7, 2, (enum HeapID)4);
    PTR_AT(state, 0x168) = AddPlttResObjFromNarc((GF_2DGfxResMan *)PTR_AT(state, 0x158), (NarcId)0x49, 1, 0, 0x3E7, 2, 1, (enum HeapID)4);
    PTR_AT(state, 0x16C) = AddCellOrAnimResObjFromNarc((GF_2DGfxResMan *)PTR_AT(state, 0x15C), (NarcId)0x49, 6, 1, 0x3E7, (GfGfxResType)2, (enum HeapID)4);
    PTR_AT(state, 0x170) = AddCellOrAnimResObjFromNarc((GF_2DGfxResMan *)PTR_AT(state, 0x160), (NarcId)0x49, 7, 1, 0x3E7, (GfGfxResType)3, (enum HeapID)4);
    SpriteTransfer_CreateCharTransferTask_AllocAtEnd((SpriteResource *)PTR_AT(state, 0x164));
    SpriteTransfer_CreatePlttTransferTask((SpriteResource *)PTR_AT(state, 0x168));
}

void ov34_0225DB20(Ov34State *state) {
    SpriteTemplate template;
    int i;
    Ov34State *cursor;
    CreateSpriteResourcesHeader((SpriteResourcesHeader *)(state->raw + 0x174), 0x3E7, 0x3E7, 0x3E7, 0x3E7, -1, -1, 0, 0, PTR_AT(state, 0x154), PTR_AT(state, 0x158), PTR_AT(state, 0x15C), PTR_AT(state, 0x160), NULL, NULL);
    template.spriteList = PTR_AT(state, 0x28);
    template.header = (SpriteResourcesHeader *)(state->raw + 0x174);
    template.position.z = 0;
    template.scale.x = FX32_ONE;
    template.scale.y = FX32_ONE;
    template.scale.z = FX32_ONE;
    template.rotation = 0;
    template.drawPriority = 0;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DSUB;
    template.heapID = (enum HeapID)4;
    i = 0;
    cursor = state;
    while (i < 3) {
        float adjusted;
        template.position.x = 0xE8000;
        if (ov34_0225E6A0[i] > 0) {
            adjusted = (float)(ov34_0225E6A0[i] << FX32_SHIFT) + 0.5f;
        } else {
            adjusted = (float)(ov34_0225E6A0[i] << FX32_SHIFT) - 0.5f;
        }
        template.position.y = (s32)adjusted + 0xC0000;
        PTR_AT(cursor, 0x198) = Sprite_CreateAffine(&template);
        Sprite_SetAnimActiveFlag(PTR_AT(cursor, 0x198), TRUE);
        Sprite_SetAnimCtrlSeq(PTR_AT(cursor, 0x198), i);
        i++;
        cursor = (Ov34State *)((u8 *)cursor + 4);
    }
}
