#include "to46_overlay80_a00c_r2_private.h"

void ov80_0223A62C(Ov80TextContext *context, Ov80TextObject *output, String *string, u32 fontId, int color, int palette, int resourceId, int x, int y, int center, Ov80TextCache *cache) {
    TextOBJTemplate textObjTemplate;
    Window window;
    UnkStruct_02021AC8 charTransfer;
    int fontLength;
    int charLength;
    TextOBJ *textObj;
    BgConfig *bgConfig;
    SpriteManager *spriteManager;

    GF_ASSERT(output->textObj == NULL);
    bgConfig = context->bgConfig;
    spriteManager = context->spriteManager;

    if (cache == NULL) {
        ov80_0223A75C(string, fontId, &fontLength, &charLength);
    } else {
        fontLength = cache->fontLength;
        charLength = cache->charLength;
    }

    if (cache == NULL) {
        InitWindow(&window);
        AddTextWindowTopLeftCorner(bgConfig, &window, charLength, 2, 0, 0);
        AddTextPrinterParameterizedWithColorAndSpacing(&window, fontId, string, 0, 0, 0xFF, color, 0, 0, NULL);
    } else {
        window = cache->window;
    }

    sub_02021AC8(sub_02013688(&window, NNS_G2D_VRAM_TYPE_2DMAIN, 0x65), TRUE, NNS_G2D_VRAM_TYPE_2DMAIN, &charTransfer);
    if (center == 1) {
        x -= fontLength / 2;
    }

    textObjTemplate.fontSystem = context->fontSystem;
    textObjTemplate.window = &window;
    textObjTemplate.spriteList = SpriteManager_GetSpriteList(spriteManager);
    textObjTemplate.plttResourceProxy = SpriteManager_FindPlttResourceProxy(spriteManager, resourceId);
    textObjTemplate.sprite = NULL;
    textObjTemplate.offset = charTransfer.offset;
    textObjTemplate.x = x;
    textObjTemplate.y = y - 8;
    textObjTemplate.unk_20 = 0;
    textObjTemplate.unk_24 = 11;
    textObjTemplate.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
    textObjTemplate.heapID = HEAP_ID_101;

    textObj = sub_020135D8(&textObjTemplate);
    sub_020138E0(textObj, palette);
    sub_020136B4(textObj, x, y - 8);

    if (cache == NULL) {
        RemoveWindow(&window);
    }
    output->textObj = textObj;
    output->charTransfer = charTransfer;
    output->fontLength = fontLength;
}
