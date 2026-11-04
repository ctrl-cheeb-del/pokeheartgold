#include "field2d/field2d_object.h"

#include "gf_gfx_loader.h"
#include "overlay_42.h"

// How a tilemap is split into 32x32-tile screen blocks (Field2DBgLayer_GetScreenBlockLayout)
enum Field2DScreenBlockLayout {
    SCREEN_BLOCKS_SINGLE, // up to 32x32 tiles
    SCREEN_BLOCKS_WIDE,   // two blocks side by side
    SCREEN_BLOCKS_TALL,   // two blocks, one above the other
    SCREEN_BLOCKS_2X2,
};

static const u8 sActionAnimKinds[] = { 0, 3, 2, 4, 0, 5, 6, 8, 7, 8, 2, 6 };
static const u8 sAnimKindKeepsFrame[] = { 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0 };
static const BgTemplate sField2DBgLayerBgTemplate = {
    .x = 0,
    .y = 0,
    .bufferSize = 4096,
    .baseTile = 0,
    .size = 3,
    .colorMode = 0,
    .screenBase = 0,
    .charBase = 0,
    .bgExtPltt = 0,
    .priority = 0,
    .areaOver = 0,
    .dummy = 0,
    .mosaic = 0,
};

s32 Field2DCommand_CheckStand(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move) {
    int action = Field2DObject_GetParam(object, FIELD2D_OBJECT_PARAM_ACTION);
    if ((action == FIELD2D_ACTION_STAND) || (action == FIELD2D_ACTION_PAUSE)) {
        Field2DMove_Init(move, object, command->action, command->objectId, command->direction);
        return 1;
    }
    return 0;
}

s32 Field2DCommand_CheckTurn(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move) {
    int action = Field2DObject_GetParam(object, FIELD2D_OBJECT_PARAM_ACTION);
    int direction = Field2DObject_GetParam(object, FIELD2D_OBJECT_PARAM_DIRECTION);
    if (action == 0 && direction != command->direction) {
        Field2DMove_Init(move, object, command->action, command->objectId, command->direction);
        return 1;
    }
    return 0;
}

s32 Field2DCommand_CheckWalk(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move) {
    int action = Field2DObject_GetParam(object, FIELD2D_OBJECT_PARAM_ACTION);
    if ((action == FIELD2D_ACTION_STAND) && (Field2DObject_IsMapBlockedInDirection(object, map, command->direction) != TRUE) && (Field2DObject_IsObjectInDirection(object, objectManager, command->direction) != TRUE)) {
        Field2DMove_Init(move, object, command->action, command->objectId, command->direction);
        return 1;
    }
    if ((action == FIELD2D_ACTION_STAND) && (Field2DObject_GetParam(object, FIELD2D_OBJECT_PARAM_STATE_FRAMES) >= 8)) {
        Field2DMove_Init(move, object, 5U, command->objectId, command->direction);
        return 1;
    }
    return 0;
}

s32 Field2DCommand_CheckRun(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move) {
    return Field2DCommand_CheckWalk(object, map, objectManager, command, move);
}

s32 Field2DCommand_CheckPause(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move) {
    if (Field2DObject_GetParam(object, FIELD2D_OBJECT_PARAM_ACTION) == FIELD2D_ACTION_STAND) {
        Field2DMove_Init(move, object, command->action, command->objectId, command->direction);
        return 1;
    }
    return 0;
}

s32 Field2DCommand_CheckBump(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move) {
    GF_ASSERT(FALSE);
    return 0;
}

s32 Field2DCommand_CheckWalkSlow(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move) {
    return Field2DCommand_CheckWalk(object, map, objectManager, command, move);
}

s32 Field2DCommand_CheckWalkInPlace(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move) {
    if (Field2DObject_GetParam(object, FIELD2D_OBJECT_PARAM_ACTION) == FIELD2D_ACTION_STAND) {
        Field2DMove_Init(move, object, command->action, command->objectId, command->direction);
        return TRUE;
    }
    return FALSE;
}

BOOL Field2DObject_IsMapBlockedInDirection(Field2DObject *object, Field2DMap *map, u8 direction) {
    Field2DPoint targetPos = Field2DObject_GetPos(object);
    targetPos = Field2D_StepInDirection(targetPos, direction);
    return Field2DMap_IsBlocked(map, targetPos.x / 16, targetPos.y / 16);
}

BOOL Field2DObject_IsObjectInDirection(Field2DObject *object, Field2DObjectManager *objectManager, u8 direction) {
    if (Field2DObject_FindObjectInDirection(object, objectManager, direction) != 0) {
        return TRUE;
    }
    return FALSE;
}

void Field2DMove_Init(Field2DMove *move, Field2DObject *object, u16 action, u8 objectId, s32 direction) {
    move->startPos = Field2DObject_GetPos(object);
    move->action = action;
    move->objectId = objectId;
    move->direction = direction;
}

Field2DObjectSpriteManager *Field2DObjectSpriteManager_New(SpriteList *spriteList, PaletteData *paletteData, u16 maxSprites, s8 vramType, enum HeapID heapID) {
    Field2DObjectSpriteManager *objectSpriteManager = Heap_Alloc(heapID, sizeof(Field2DObjectSpriteManager));
    objectSpriteManager->charSprites = CharSpriteManager_New(spriteList, paletteData, maxSprites, heapID);
    objectSpriteManager->maxSprites = maxSprites;
    Field2DObjectSprite *objectSprite = Heap_Alloc(heapID, sizeof(Field2DObjectSprite) * objectSpriteManager->maxSprites);
    objectSpriteManager->sprites = objectSprite;
    memset(objectSprite, 0, sizeof(Field2DObjectSprite) * objectSpriteManager->maxSprites);
    objectSpriteManager->bgPriority = 2;
    objectSpriteManager->vramType = vramType;
    return objectSpriteManager;
}

Field2DObjectSpriteManager *Field2DObjectSpriteManager_NewWithShadow(SpriteList *spriteList, PaletteData *paletteData, u16 maxSprites, s32 spriteId, s32 animSet, s32 vramType, enum HeapID heapID) {
    Field2DObjectSpriteManager *objectSpriteManager = Heap_Alloc(heapID, sizeof(Field2DObjectSpriteManager));
    objectSpriteManager->charSprites = CharSpriteManager_New(spriteList, paletteData, maxSprites, heapID);
    objectSpriteManager->maxSprites = maxSprites;
    Field2DObjectSprite *objectSprite = Heap_Alloc(heapID, sizeof(Field2DObjectSprite) * objectSpriteManager->maxSprites);
    objectSpriteManager->sprites = objectSprite;
    memset(objectSprite, 0, sizeof(Field2DObjectSprite) * objectSpriteManager->maxSprites);
    objectSpriteManager->bgPriority = 2;
    objectSpriteManager->vramType = vramType;
    CharSpriteManager_LoadChar(objectSpriteManager->charSprites, spriteId, objectSpriteManager->vramType, animSet, heapID);
    CharSpriteManager_LoadShadow(objectSpriteManager->charSprites, objectSpriteManager->vramType, 40001, heapID);
    return objectSpriteManager;
}

void Field2DObjectSpriteManager_Free(Field2DObjectSpriteManager *objectSpriteManager) {
    for (int i = 0; i < objectSpriteManager->maxSprites; i++) {
        if (Field2DObjectSprite_IsFree(&objectSpriteManager->sprites[i]) == 0) {
            Field2DObjectSprite_Delete(&objectSpriteManager->sprites[i]);
        }
    }
    CharSpriteManager_UnloadShadow(objectSpriteManager->charSprites);
    Field2DObjectSpriteManager_UnloadAllChars(objectSpriteManager);
    CharSpriteManager_Free(objectSpriteManager->charSprites);
    Heap_Free(objectSpriteManager->sprites);
    Heap_Free(objectSpriteManager);
}

void Field2DObjectSpriteManager_LoadChar(Field2DObjectSpriteManager *objectSpriteManager, s32 spriteId, s32 animSet, enum HeapID heapID) {
    if (CharSpriteManager_IsCharLoaded(objectSpriteManager->charSprites, spriteId) == FALSE) {
        CharSpriteManager_LoadChar(objectSpriteManager->charSprites, spriteId, objectSpriteManager->vramType, animSet, heapID);
    }
}

void Field2DObjectSpriteManager_UnloadChar(Field2DObjectSpriteManager *objectSpriteManager, s32 spriteId) {
    CharSpriteManager_UnloadChar(objectSpriteManager->charSprites, spriteId);
}

BOOL Field2DObjectSpriteManager_IsCharLoaded(Field2DObjectSpriteManager *objectSpriteManager, s32 spriteId) {
    return CharSpriteManager_IsCharLoaded(objectSpriteManager->charSprites, spriteId);
}

void Field2DObjectSpriteManager_UnloadAllChars(Field2DObjectSpriteManager *objectSpriteManager) {
    CharSpriteManager_UnloadAllChars(objectSpriteManager->charSprites);
}

void Field2DObjectSpriteManager_LoadAvatarChars(Field2DObjectSpriteManager *objectSpriteManager, s32 animSet, enum HeapID heapID) {
    CharSpriteManager_LoadAvatarChars(objectSpriteManager->charSprites, objectSpriteManager->vramType, animSet, heapID);
}

Field2DObjectSprite *Field2DObjectSpriteManager_CreateSprite(Field2DObjectSpriteManager *objectSpriteManager, Field2DObject *object, u32 priorityMode, enum HeapID heapID) {
    Field2DObjectSprite *objectSprite = Field2DObjectSpriteManager_GetFreeSprite(objectSpriteManager);
    objectSprite->action = Field2DObject_GetParam(object, FIELD2D_OBJECT_PARAM_ACTION);
    objectSprite->direction = Field2DObject_GetParam(object, FIELD2D_OBJECT_PARAM_DIRECTION);
    objectSprite->id = Field2DObject_GetParam(object, FIELD2D_OBJECT_PARAM_ID);
    objectSprite->object = object;
    objectSprite->priorityMode = priorityMode;
    objectSprite->autoUpdate = 1;
    objectSprite->savedAnimFrame = 0;
    objectSprite->savedAnimKind = 0;

    s16 spriteParams[4];
    spriteParams[0] = Field2DObject_GetParam(object, FIELD2D_OBJECT_PARAM_X);
    spriteParams[1] = Field2DObject_GetParam(object, FIELD2D_OBJECT_PARAM_Y);
    spriteParams[2] = Field2DObjectSprite_CalcDrawPriority(spriteParams[1], objectSprite->priorityMode);
    spriteParams[3] = objectSpriteManager->bgPriority;
    objectSprite->charSprite = CharSpriteManager_CreateSprite(objectSpriteManager->charSprites, spriteParams, Field2DObject_GetParam(object, FIELD2D_OBJECT_PARAM_SPRITE_ID), heapID);
    Field2DObjectSprite_Update(objectSprite);
    return objectSprite;
}

void Field2DObjectSprite_Delete(Field2DObjectSprite *objectSprite) {
    CharSprite_Delete(objectSprite->charSprite);
    memset(objectSprite, 0, sizeof(Field2DObjectSprite));
}

void Field2DObjectSpriteManager_Update(Field2DObjectSpriteManager *objectSpriteManager) {
    for (int i = 0; i < objectSpriteManager->maxSprites; i++) {
        if (Field2DObjectSprite_IsFree(&objectSpriteManager->sprites[i]) == 0) {
            Field2DObjectSprite_Update(&objectSpriteManager->sprites[i]);
        }
    }
}

void Field2DObjectSprite_Update(Field2DObjectSprite *objectSprite) {
    if (objectSprite->autoUpdate != 0) {
        s32 action = Field2DObject_GetParam(objectSprite->object, FIELD2D_OBJECT_PARAM_ACTION);
        s32 direction = Field2DObject_GetParam(objectSprite->object, FIELD2D_OBJECT_PARAM_DIRECTION);
        s16 actionFrame = Field2DObject_GetParam(objectSprite->object, FIELD2D_OBJECT_PARAM_ACTION_FRAME);
        if ((objectSprite->action != action) || (objectSprite->direction != direction) || (actionFrame == 0)) {
            objectSprite->action = action;
            objectSprite->direction = direction;
            Field2DObjectSprite_StartAnim(objectSprite, Field2DObjectSprite_GetAnimKindForAction(objectSprite->charSprite, action), direction);
        }
        s16 x, y;
        Field2DObjectSprite_GetDrawPos(objectSprite, &x, &y);
        CharSprite_SetPosition(objectSprite->charSprite, x, y);
        u16 drawPriority = Field2DObjectSprite_CalcDrawPriority(y, objectSprite->priorityMode);
        CharSprite_SetDrawPriority(objectSprite->charSprite, drawPriority);
        CharSprite_UpdateAnim(objectSprite->charSprite);
    }
}

void Field2DObjectSprite_SetAutoUpdate(Field2DObjectSprite *objectSprite, s8 autoUpdate) {
    objectSprite->autoUpdate = autoUpdate;
}

void Field2DObjectSprite_StartLoopAnim(Field2DObjectSprite *objectSprite) {
    Field2DObjectSprite_StartAnim(objectSprite, 1U, objectSprite->direction);
}

void Field2DObjectSprite_UpdateAnim(Field2DObjectSprite *objectSprite) {
    CharSprite_UpdateAnim(objectSprite->charSprite);
}

void Field2DObjectSprite_SyncAnim(Field2DObjectSprite *objectSprite) {
    Field2DObjectSprite_StartAnim(objectSprite, Field2DObjectSprite_GetAnimKindForAction(objectSprite->charSprite, objectSprite->action), objectSprite->direction);
    Field2DObjectSprite_Update(objectSprite);
}

void Field2DObjectSprite_SetPosition(Field2DObjectSprite *objectSprite, Field2DPoint pos) {
    CharSprite_SetPosition(objectSprite->charSprite, pos.x, pos.y);
}

BOOL Field2DObjectSprite_IsVisible(Field2DObjectSprite *objectSprite) {
    return CharSprite_IsVisible(objectSprite->charSprite);
}

void Field2DObjectSprite_SetVisible(Field2DObjectSprite *objectSprite, u16 visible) {
    CharSprite_SetVisible(objectSprite->charSprite, visible);
}

u16 Field2DObjectSprite_GetDrawPriority(Field2DObjectSprite *objectSprite) {
    return CharSprite_GetDrawPriority(objectSprite->charSprite);
}

void Field2DObjectSprite_FaceDirection(Field2DObjectSprite *objectSprite, s32 direction) {
    Field2DObjectSprite_StartAnim(objectSprite, 0, direction);
    CharSprite_UpdateAnim(objectSprite->charSprite);
}

u32 Field2DObjectSprite_CalcDrawPriority(s16 y, u8 priorityMode) {
    if (priorityMode == 1) {
        return 40000 - (y * 2);
    }
    return 40001 - (y * 2);
}

u8 Field2DObjectSprite_GetPaletteOffset(Field2DObjectSprite *objectSprite) {
    return Sprite_GetPalOffset(CharSprite_GetSprite(objectSprite->charSprite));
}

void Field2DObjectSprite_SetShadowPosition(Field2DObjectSprite *objectSprite, Field2DPoint pos) {
    CharSprite_SetShadowPosition(objectSprite->charSprite, pos.x, pos.y);
}

s32 Field2DObjectSprite_IsFree(Field2DObjectSprite *objectSprite) {
    if (objectSprite->charSprite == 0) {
        return 1;
    }
    return 0;
}

Field2DObjectSprite *Field2DObjectSpriteManager_GetFreeSprite(Field2DObjectSpriteManager *objectSpriteManager) {
    for (int i = 0; i < objectSpriteManager->maxSprites; i++) {
        if (Field2DObjectSprite_IsFree(&objectSpriteManager->sprites[i]) == 1) {
            return &objectSpriteManager->sprites[i];
        }
    }
    GF_ASSERT(FALSE);
    return NULL;
}

u8 Field2DObjectSprite_GetAnimKindForAction(CharSprite *charSprite, s32 action) {
    if (CharSprite_GetAnimSet(charSprite) == 2) {
        return 0;
    }
    return sActionAnimKinds[action];
}

void Field2DObjectSprite_GetDrawPos(Field2DObjectSprite *objectSprite, s16 *x, s16 *y) {
    Field2DPoint drawPos = Field2DObject_GetDrawPos(objectSprite->object);
    *x = drawPos.x;
    *y = drawPos.y;
}

void Field2DObjectSprite_StartAnim(Field2DObjectSprite *objectSprite, u8 animKind, s32 direction) {
    u16 prevAnimKind;
    u16 prevAnimFrame;

    prevAnimFrame = CharSprite_GetAnimFrame(objectSprite->charSprite);
    prevAnimKind = CharSprite_GetAnimKind(objectSprite->charSprite);
    CharSprite_StartAnim(objectSprite->charSprite, animKind, direction);
    if (prevAnimKind != animKind) {
        if ((sAnimKindKeepsFrame[animKind] == 1) && (objectSprite->savedAnimKind == animKind)) {
            CharSprite_SetAnimFrame(objectSprite->charSprite, objectSprite->savedAnimFrame);
        }
        if (sAnimKindKeepsFrame[prevAnimKind] == 1) {
            objectSprite->savedAnimKind = prevAnimKind;
            objectSprite->savedAnimFrame = prevAnimFrame;
        }
    }
}

void Field2DCamera_CenterOnObject(Field2DPoint *camera, Field2DObject *object) {
    Field2DPoint drawPos = Field2DObject_GetDrawPos(object);
    Field2DCamera_Set(camera, drawPos.y - 96, drawPos.x - 112);
}

// The camera's scroll is kept in a Field2DPoint the other way round from object positions: the vertical scroll in
// its x field, the horizontal scroll in its y field.
void Field2DCamera_Init(Field2DPoint *camera) {
    memset(camera, 0, sizeof(Field2DPoint));
}

void Field2DCamera_Set(Field2DPoint *camera, s16 y, s16 x) {
    camera->x = y;
    camera->y = x;
}

s16 Field2DCamera_GetY(Field2DPoint *camera) {
    return camera->x;
}

s16 Field2DCamera_GetX(Field2DPoint *camera) {
    return camera->y;
}

Field2DBgLayer *Field2DBgLayer_New(G2dRenderer *g2dRenderer, BgConfig *bgConfig, const Field2DBgLayerTemplate *template, enum HeapID heapID) {
    Field2DBgLayer *layer = Heap_Alloc(heapID, sizeof(Field2DBgLayer));
    memset(layer, 0, sizeof(Field2DBgLayer));
    layer->g2dRenderer = g2dRenderer;
    layer->bgConfig = bgConfig;
    layer->screen = template->screen;
    layer->bgLayer = template->bgLayer;
    Field2DBgLayer_InitBg(layer->bgConfig, layer->bgLayer, template);
    layer->screenFile = GfGfxLoader_GetScrnData((NarcId) template->narcId, template->fileId, template->compressed, &layer->nnsg2dScreenData, heapID);
    return layer;
}

void Field2DBgLayer_Free(Field2DBgLayer *layer) {
    Heap_Free(layer->screenFile);
    Heap_Free(layer);
}

void Field2DBgLayer_SetCamera(Field2DBgLayer *layer, Field2DPoint *camera) {
    s16 x;
    s16 y;
    y = Field2DCamera_GetY(camera);
    x = Field2DCamera_GetX(camera);
    if (layer->screen == 0) {
        f32 mainY;
        f32 mainX;
        if (y > 0) {
            mainY = 0.5f + (y << 12);
        } else {
            mainY = (y << 12) - 0.5f;
        }
        if (x > 0) {
            mainX = 0.5f + (x << 12);
        } else {
            mainX = (x << 12) - 0.5f;
        }
        G2dRenderer_SetMainSurfaceCoords(layer->g2dRenderer, mainX, mainY);
    } else {
        f32 subY;
        f32 subX;
        if (y > 0) {
            subY = 0.5f + (y << 12);
        } else {
            subY = (y << 12) - 0.5f;
        }
        if (x > 0) {
            subX = 0.5f + (x << 12);
        } else {
            subX = (x << 12) - 0.5f;
        }
        G2dRenderer_SetSubSurfaceCoords(layer->g2dRenderer, subX, (fx32)subY + 0xC0000);
    }
    Field2DBgLayer_Scroll(layer, x, y);
}

void Field2DBgLayer_InitBg(BgConfig *bgConfig, s32 bgId, const Field2DBgLayerTemplate *template) {
    BgTemplate bgTemplate = sField2DBgLayerBgTemplate;
    bgTemplate.colorMode = template->colorMode;
    bgTemplate.screenBase = template->screenBase;
    bgTemplate.charBase = template->charBase;
    bgTemplate.bgExtPltt = template->bgExtPltt;
    bgTemplate.priority = template->priority;
    bgTemplate.areaOver = 0;
    bgTemplate.mosaic = template->mosaic;
    FreeBgTilemapBuffer(bgConfig, bgId);
    InitBgFromTemplate(bgConfig, bgId, &bgTemplate, GF_BG_TYPE_TEXT);
}

void Field2DBgLayer_Scroll(Field2DBgLayer *layer, s16 x, s16 y) {
    s16 tileX = x / 8;
    s16 tileY = y / 8;
    s16 fineX = x % 8;
    s16 fineY = y % 8;

    if ((tileX != layer->tileX) || (tileY != layer->tileY)) {
        layer->tileX = tileX;
        layer->tileY = tileY;
        Field2DBgLayer_CopyVisibleTiles(layer->bgConfig, layer->bgLayer, layer->nnsg2dScreenData, -tileX, -tileY);
        ScheduleBgTilemapBufferTransfer(layer->bgConfig, layer->bgLayer);
    }
    ScheduleSetBgPosText(layer->bgConfig, layer->bgLayer, BG_POS_OP_SET_X, fineX);
    ScheduleSetBgPosText(layer->bgConfig, layer->bgLayer, BG_POS_OP_SET_Y, fineY);
}

void Field2DBgLayer_CopyVisibleTiles(BgConfig *bgConfig, s32 bgId, NNSG2dScreenData *nnsg2dScreenData, s16 x, s16 y) {
    s16 screenWidth = nnsg2dScreenData->screenWidth / 8;
    s16 screenHeight = nnsg2dScreenData->screenHeight / 8;

    s16 srcX;
    if (x < 0) {
        srcX = -x;
    } else {
        srcX = 0;
    }
    s16 srcY;
    if (y < 0) {
        srcY = -y;
    } else {
        srcY = 0;
    }
    if (x <= 0) {
        x = 0;
    }
    if (y <= 0) {
        y = 0;
    }
    s16 width = 33 - x;
    s16 height = 25 - y;
    s32 srcRight = srcX + width;
    if (screenWidth < srcRight) {
        width -= srcRight - screenWidth;
    }
    s32 srcBottom = srcY + height;
    if (screenHeight < srcBottom) {
        height -= srcBottom - screenHeight;
    }
    FillBgTilemapRect(bgConfig, bgId, 0, 0, 0, 33, 25, 17);
    Field2DBgLayer_CopyTilemapRect(bgConfig, bgId, x, y, width, height, nnsg2dScreenData->rawData, srcX, srcY, screenWidth, screenHeight);
}

void Field2DBgLayer_CopyTilemapRect(BgConfig *bgConfig, u8 bgId, u8 destX, u8 destY, u8 destWidth, u8 destHeight, void *buffer, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight) {
    s8 rowsLeft;
    s8 rows;
    u8 layout = Field2DBgLayer_GetScreenBlockLayout(srcWidth, srcHeight);
    if (layout == SCREEN_BLOCKS_SINGLE) {
        CopyToBgTilemapRect(bgConfig, bgId, destX, destY, destWidth, destHeight, buffer, srcX, srcY, srcWidth, srcHeight);
        return;
    }
    rowsLeft = destHeight;
    while (rowsLeft > 0) {
        int blockSrcY = srcY % 32;
        if (blockSrcY + rowsLeft <= 32) {
            rows = rowsLeft;
            rowsLeft = 0;
        } else {
            rows = 32 - blockSrcY;
            rowsLeft -= rows;
        }
        s8 blockY = srcY / 32;
        s8 colsLeft = destWidth;
        s8 curSrcX = srcX;
        s8 curDestX = destX;
        while (colsLeft > 0) {
            s8 cols;
            if ((curSrcX % 32) + colsLeft <= 32) {
                cols = colsLeft;
                colsLeft = 0;
            } else {
                cols = 32 - (curSrcX % 32);
                colsLeft = colsLeft - cols;
            }
            Field2DPoint blockSize;
            void *block = Field2DBgLayer_GetScreenBlock(buffer, (s8)(curSrcX / 32), blockY, layout, srcWidth, srcHeight, &blockSize);
            CopyToBgTilemapRect(bgConfig, bgId, curDestX, destY, cols, rows, block, curSrcX % 32, blockSrcY, blockSize.x, blockSize.y);
            curSrcX += cols;
            curDestX += cols;
        }
        srcY += rows;
        destY += rows;
    }
}

u8 Field2DBgLayer_GetScreenBlockLayout(u8 width, u8 height) {
    GF_ASSERT(width <= 64);
    GF_ASSERT(height <= 64);
    if (width <= 32) {
        if (height <= 32) {
            return SCREEN_BLOCKS_SINGLE;
        }
        return SCREEN_BLOCKS_TALL;
    }
    if (height <= 32) {
        return SCREEN_BLOCKS_WIDE;
    }
    return SCREEN_BLOCKS_2X2;
}

void *Field2DBgLayer_GetScreenBlock(void *buffer, u8 blockX, u8 blockY, u8 layout, u8 width, u8 height, Field2DPoint *blockSize) {
    switch (layout) {
    case SCREEN_BLOCKS_SINGLE:
        blockSize->x = width;
        blockSize->y = height;
        return buffer;
    case SCREEN_BLOCKS_WIDE:
        int blockWidth;
        if (((blockX + 1) << 5) <= width) {
            blockWidth = 32;
        } else {
            blockWidth = width - (blockX << 5);
        }
        blockSize->x = blockWidth;
        blockSize->y = height;
        return buffer + blockX * ((s16)(height << 6));
    case SCREEN_BLOCKS_TALL:
        blockSize->x = width;
        int blockHeight;
        if (((blockY + 1) << 5) <= height) {
            blockHeight = 32;
        } else {
            blockHeight = height - (blockY << 5);
        }
        blockSize->y = blockHeight;
        return buffer + blockY * ((s16)(width << 6));
    case SCREEN_BLOCKS_2X2:
        int extent;
        if (((blockX + 1) << 5) <= width) {
            extent = 32;
        } else {
            extent = width - (blockX << 5);
        }
        blockSize->x = extent;
        if (((blockY + 1) << 5) <= height) {
            extent = 32;
        } else {
            extent = height - (blockY << 5);
        }
        blockSize->y = extent;
        u16 offset;
        if (blockY == 0) {
            offset = 0;
            if (blockX != 0) {
                offset += 2048;
            }
        } else {
            offset = (width << 6);
            if (blockX != 0) {
                offset = offset + (height << 6);
            }
        }
        return buffer + offset;
    default:
        GF_ASSERT(FALSE);
    }
    GF_ASSERT(FALSE);
    return NULL;
}

Field2DMoveQueue *Field2DMoveQueue_New(s32 maxEntries, enum HeapID heapID) {
    Field2DMoveQueue *queue = Heap_Alloc(heapID, sizeof(Field2DMoveQueue));
    GF_ASSERT(queue);
    s32 capacity = maxEntries + 1;
    queue->capacity = capacity;
    Field2DMove *entries = Heap_Alloc(heapID, capacity * sizeof(Field2DMove));
    queue->entries = entries;
    memset(entries, 0, queue->capacity * sizeof(Field2DMove));
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

void Field2DMoveQueue_Free(Field2DMoveQueue *queue) {
    Heap_Free(queue->entries);
    Heap_Free(queue);
}

void Field2DMoveQueue_Push(Field2DMoveQueue *queue, Field2DMove *entry) {
    Field2DMove dropped;
    if (queue->head == ((queue->tail + 1) % queue->capacity)) {
        Field2DMoveQueue_Pop(queue, &dropped);
    }
    queue->entries[queue->tail] = *entry;
    queue->tail = (queue->tail + 1) % queue->capacity;
}

s32 Field2DMoveQueue_Pop(Field2DMoveQueue *queue, Field2DMove *entry) {
    if (queue->tail == queue->head) {
        return 0;
    }
    *entry = queue->entries[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    return 1;
}

Field2DCommandQueue *Field2DCommandQueue_New(s32 maxEntries, enum HeapID heapID) {
    Field2DCommandQueue *queue = Heap_Alloc(heapID, sizeof(Field2DCommandQueue));
    GF_ASSERT(queue);
    queue->capacity = maxEntries + 1;
    queue->entries = Heap_Alloc(heapID, (maxEntries + 1) * sizeof(Field2DCommand));
    memset(queue->entries, 0, queue->capacity * sizeof(Field2DCommand));
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

void Field2DCommandQueue_Free(Field2DCommandQueue *queue) {
    Heap_Free(queue->entries);
    Heap_Free(queue);
}

void Field2DCommandQueue_Push(Field2DCommandQueue *queue, Field2DCommand *command) {
    Field2DCommand dropped;
    if (queue->head == ((queue->tail + 1) % queue->capacity)) {
        Field2DCommandQueue_Pop(queue, &dropped);
    }
    queue->entries[queue->tail] = command[0];
    queue->tail = (queue->tail + 1) % queue->capacity;
}

u32 Field2DCommandQueue_Pop(Field2DCommandQueue *queue, Field2DCommand *command) {
    if (queue->tail == queue->head) {
        return 0;
    }
    *command = queue->entries[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    return 1;
}
