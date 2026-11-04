#ifndef POKEHEARTGOLD_OVY_42_H
#define POKEHEARTGOLD_OVY_42_H

#include "global.h"

#include "field2d/field2d_object.h"

#include "bg_window.h"
#include "palette.h"
#include "sprite.h"
#include "sprite_resource_header.h"

typedef struct Field2DPoint {
    s16 x;
    s16 y;
} Field2DPoint;

typedef struct Field2DCommand {
    u16 action;
    u8 direction;
    u8 objectId;
} Field2DCommand;

typedef struct Field2DMove {
    Field2DPoint startPos;
    u16 action;
    u8 direction;
    u8 objectId;
} Field2DMove;

typedef struct Field2DCommandQueue {
    Field2DCommand *entries;
    u32 capacity;
    u16 head;
    u16 tail;
} Field2DCommandQueue;

typedef struct Field2DBgLayer {
    G2dRenderer *g2dRenderer;
    BgConfig *bgConfig;
    void *screenFile;
    NNSG2dScreenData *nnsg2dScreenData;
    u32 screen;
    u32 bgLayer;
    u16 tileX;
    u16 tileY;
} Field2DBgLayer;

typedef struct Field2DMoveQueue {
    Field2DMove *entries;
    u32 capacity;
    u16 head;
    u16 tail;
} Field2DMoveQueue;

typedef struct Field2DObject {
    BOOL active;
    Field2DPoint pos;
    Field2DPoint prevPos;
    u16 id;
    u16 spriteId;
    u16 actionFrame;
    u16 actionDuration;
    u8 direction;
    u8 action;
    u16 stateFrames;
} Field2DObject;

typedef struct Field2DObjectManager {
    Field2DObject *objects;
    u32 capacity;
} Field2DObjectManager;

typedef struct Field2DMap {
    u16 width;
    u16 height;
    u32 *cells;
} Field2DMap;

typedef struct Field2DObjectTemplate {
    s16 x;
    s16 y;
    u16 id;
    u16 action;
    u16 direction;
    u16 spriteId;
} Field2DObjectTemplate;

typedef struct CharSprite {
    u32 *resource;
    Sprite *sprite;
    Sprite *shadow;
    u32 animKind;
    u32 direction;
    s16 animFrames;
    u8 unk16[2];
} CharSprite;

typedef struct Field2DObjectSprite {
    Field2DObject *object;
    CharSprite *charSprite;
    u16 action;
    u16 direction;
    s16 id;
    u16 savedAnimFrame;
    u16 savedAnimKind;
    u8 priorityMode;
    u8 autoUpdate;
} Field2DObjectSprite;

typedef struct CharSpriteResource {
    u32 sharedPalette;
    SpriteResource *charResource;
    SpriteResource *plttResource;
    u32 vramType;
    u32 animSet;
    SpriteResourcesHeader header;
} CharSpriteResource;

typedef struct CharSpriteCellAnim {
    SpriteResource *cell;
    SpriteResource *anim;
    u8 unk8[8];
} CharSpriteCellAnim;

typedef struct CharSpriteManager {
    SpriteList *spriteList;
    PaletteData *paletteData;
    CharSprite *sprites;
    u32 maxSprites;
    CharSpriteResource chars[0x99];
    SpriteResource *cellAnims[4];
    u8 unk2198[0x20];
    CharSpriteCellAnim avatarCellAnims[0x10];
    SpriteResource *shadowResources[4];
    SpriteResourcesHeader shadowHeader;
    u32 shadowDrawPriority;
    GF_2DGfxResMan *resManagers[4];
    SpriteResource *avatarPalette;
    NARC *charNarc;
    NARC *avatarNarc;
} CharSpriteManager;

typedef struct Field2DObjectSpriteManager {
    CharSpriteManager *charSprites;
    Field2DObjectSprite *sprites;
    u16 maxSprites;
    u8 bgPriority;
    u8 vramType;
} Field2DObjectSpriteManager;

typedef struct Field2DMapCell {
    u32 value;
} Field2DMapCell;

typedef struct Field2DBgLayerTemplate {
    u8 screen;
    u8 bgLayer;
    u8 colorMode;
    u8 screenBase;
    u8 charBase;
    u8 bgExtPltt;
    u8 priority;
    u8 mosaic;
    u8 narcId;
    u8 fileId;
    u8 compressed;
} Field2DBgLayerTemplate;

typedef s32 (*Field2DCommandCheckFunc)(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move);
typedef void (*Field2DObjectStartFunc)(Field2DObject *object, Field2DPoint pos, u32 direction);
typedef s32 (*Field2DObjectUpdateFunc)(Field2DObject *object);
typedef void (*CharSpriteAnimUpdateFunc)(CharSprite *charSprite);
typedef void (*CharSpriteAnimStartFunc)(CharSprite *charSprite, s32 direction);

CharSpriteManager *CharSpriteManager_New(SpriteList *spriteList, PaletteData *paletteData, s32 maxSprites, enum HeapID heapID);
void CharSpriteManager_Free(CharSpriteManager *charSpriteManager);
void CharSpriteManager_LoadChar(CharSpriteManager *charSpriteManager, s32 spriteId, u8 vramType, s32 animSet, enum HeapID heapID);
void CharSpriteManager_UnloadChar(CharSpriteManager *charSpriteManager, s32 spriteId);
BOOL CharSpriteManager_IsCharLoaded(CharSpriteManager *charSpriteManager, s32 spriteId);
void CharSpriteManager_UnloadAllChars(CharSpriteManager *charSpriteManager);
void CharSpriteManager_LoadAvatarChars(CharSpriteManager *charSpriteManager, u8 vramType, s32 animSet, enum HeapID heapID);
void CharSpriteManager_UnloadAvatarChars(CharSpriteManager *charSpriteManager);
void CharSpriteManager_LoadShadow(CharSpriteManager *charSpriteManager, u8 vramType, s32 drawPriority, enum HeapID heapID);
void CharSpriteManager_UnloadShadow(CharSpriteManager *charSpriteManager);
CharSprite *CharSpriteManager_CreateSprite(CharSpriteManager *charSpriteManager, s16 *spriteParams, s32 spriteId, enum HeapID heapID);
void CharSprite_Delete(CharSprite *charSprite);
Sprite *CharSprite_GetSprite(CharSprite *charSprite);
void CharSprite_SetPosition(CharSprite *charSprite, s16 x, s16 y);
void CharSprite_SetDrawPriority(CharSprite *charSprite, u16 drawPriority);
u16 CharSprite_GetDrawPriority(CharSprite *charSprite);
void CharSprite_SetVisible(CharSprite *charSprite, u16 visible);
BOOL CharSprite_IsVisible(CharSprite *charSprite);
s32 CharSprite_GetAnimSet(CharSprite *charSprite);
u32 CharSprite_GetAnimKind(CharSprite *charSprite);
void CharSprite_SetAnimFrame(CharSprite *charSprite, u16 frame);
u16 CharSprite_GetAnimFrame(CharSprite *charSprite);
void CharSprite_SetShadowPosition(CharSprite *charSprite, s16 x, s16 y);
void CharSprite_StartAnim(CharSprite *charSprite, s32 animKind, s32 direction);
void CharSprite_UpdateAnim(CharSprite *charSprite);
void CharSpriteManager_LoadCellAnims(CharSpriteManager *charSpriteManager, s32 animSet, enum HeapID heapID);
void CharSpriteManager_UnloadCellAnims(CharSpriteManager *charSpriteManager, s32 animSet);
u16 CharSprite_GetCharIndex(s32 spriteId);
s32 CharSprite_IsAnimSetAllowed(u32 spriteId, s32 animSet);
s32 CharSprite_GetCellAnimResId(s32 animSet, s32 resType, s32 nonStandardSize);
void CharSpriteManager_LoadCharResources(CharSpriteManager *charSpriteManager, s32 charIndex, u8 vramType, s32 animSet, enum HeapID heapID, s32 sharedPalette);
void CharSpriteManager_LoadCharWithPalette(CharSpriteManager *charSpriteManager, s32 charIndex, s32 vramType, s32 animSet, enum HeapID heapID);
void CharSpriteManager_LoadSharedPaletteChar(CharSpriteManager *charSpriteManager, s32 charIndex, s32 vramType, s32 animSet, enum HeapID heapID);
void CharSpriteManager_UnloadCharResources(CharSpriteManager *charSpriteManager, s32 charIndex);
void CharSpriteManager_UnloadCharWithPalette(CharSpriteManager *charSpriteManager, s32 charIndex);
void CharSpriteManager_UnloadSharedPaletteChar(CharSpriteManager *charSpriteManager, s32 charIndex);
BOOL CharSpriteManager_IsCharIndexLoaded(CharSpriteManager *charSpriteManager, s32 charIndex);
void CharSpriteManager_LoadShadowResources(CharSpriteManager *charSpriteManager, s32 vramType, enum HeapID heapID);
void CharSpriteManager_UnloadShadowResources(CharSpriteManager *charSpriteManager);
BOOL CharSprite_HasShadowResources(SpriteResource **spriteResources);
void CharSpriteManager_LoadAvatarPalette(CharSpriteManager *charSpriteManager, s32 vramType, enum HeapID heapID);
void CharSpriteManager_UnloadAvatarPalette(CharSpriteManager *charSpriteManager);
void CharSpriteManager_LoadAvatarCellAnims(CharSpriteManager *charSpriteManager, enum HeapID heapID);
void CharSpriteManager_UnloadAvatarCellAnims(CharSpriteManager *charSpriteManager);
CharSprite *CharSpriteManager_GetFreeSprite(CharSpriteManager *charSpriteManager);
void CharSprite_StepAnim(CharSprite *charSprite);

void CharSprite_StartAnimStand(CharSprite *charSprite, s32 direction);
void CharSprite_StartAnimLoop(CharSprite *charSprite, s32 direction);
void CharSprite_StartAnimWalk(CharSprite *charSprite, s32 direction);
void CharSprite_StartAnimTurn(CharSprite *charSprite, s32 direction);
void CharSprite_StartAnimRun(CharSprite *charSprite, s32 direction);
void CharSprite_StartAnimBump(CharSprite *charSprite, s32 direction);
void CharSprite_StartAnimWalkSlow(CharSprite *charSprite, s32 direction);
void CharSprite_StartAnimWalkVeryFast(CharSprite *charSprite, s32 direction);
void CharSprite_StartAnimWalkFast(CharSprite *charSprite, s32 direction);
void CharSprite_UpdateAnimLoop(CharSprite *charSprite);
void CharSprite_UpdateAnimWalk(CharSprite *charSprite);
void CharSprite_UpdateAnimTurn(CharSprite *charSprite);
void CharSprite_UpdateAnimRun(CharSprite *charSprite);
void CharSprite_UpdateAnimBump(CharSprite *charSprite);
void CharSprite_UpdateAnimWalkSlow(CharSprite *charSprite);
void CharSprite_UpdateAnimWalkVeryFast(CharSprite *charSprite);
void CharSprite_UpdateAnimWalkFast(CharSprite *charSprite);
s32 CharSprite_IsFree(CharSprite *charSprite);
void CharSpriteManager_LoadPaletteToBuffer(CharSpriteManager *charSpriteManager, SpriteResource *spriteResource, s32 numPalettes);
Field2DMap *Field2DMap_New(u16 width, u16 height, enum HeapID heapID);
void Field2DMap_Free(Field2DMap *map);
u16 Field2DMap_GetWidth(Field2DMap *map);
u16 Field2DMap_GetHeight(Field2DMap *map);
void Field2DMap_Load(Field2DMap *map, const void *cells);

Field2DMapCell Field2DMap_GetCell(Field2DMap *map, u32 x, u32 y);
BOOL Field2DMap_IsBlocked(Field2DMap *map, u16 x, u16 y);
u32 Field2DMap_GetTag(Field2DMap *map, u16 x, u16 y);
Field2DObjectManager *Field2DObjectManager_New(u32 capacity, enum HeapID heapID);
void Field2DObjectManager_Free(Field2DObjectManager *objectManager);
void Field2DObjectManager_StartMove(Field2DObjectManager *objectManager, Field2DMove *move);
void Field2DObjectManager_Update(Field2DObjectManager *objectManager);
u32 Field2DObjectManager_GetCapacity(Field2DObjectManager *objectManager);
Field2DObject *Field2DObjectManager_AddObject(Field2DObjectManager *objectManager, Field2DObjectTemplate *template);
void Field2DObject_Delete(Field2DObject *object);
Field2DObject *Field2DObjectManager_FindById(Field2DObjectManager *objectManager, u8 id);
Field2DObject *Field2DObjectManager_GetSlot(Field2DObjectManager *objectManager, u16 index);
Field2DObject *Field2DObjectManager_GetById(Field2DObjectManager *objectManager, u8 id);
Field2DObject *Field2DObjectManager_GetByIndex(Field2DObjectManager *objectManager, u16 index);
s32 Field2DObject_GetParam(Field2DObject *object, enum Field2DObjectParam param);
void Field2DObject_SetParam(Field2DObject *object, enum Field2DObjectParam param, s32 value);
Field2DPoint Field2D_StepInDirection(Field2DPoint pos, s32 direction);
u8 Field2D_GetOppositeDirection(s32 direction);
Field2DObject *Field2DObjectManager_GetFreeSlot(Field2DObjectManager *objectManager);
Field2DPoint Field2DObject_GetPos(Field2DObject *object);
Field2DPoint Field2DObject_GetPrevPos(Field2DObject *object);
Field2DPoint Field2DObject_GetDrawPos(Field2DObject *object);
void Field2DObject_SetPos(Field2DObject *object, Field2DPoint pos);
void Field2DObject_SetPrevPos(Field2DObject *object, Field2DPoint prevPos);
Field2DObject *Field2DObject_FindObjectInDirection(Field2DObject *object, Field2DObjectManager *objectManager, s32 direction);
Field2DObject *Field2DObjectManager_FindObjectAt(Field2DObjectManager *objectManager, Field2DPoint pos);
void Field2DObject_StartMove(Field2DObject *object, Field2DMove *move);
void Field2DObject_Update(Field2DObject *object);
void Field2DObject_StartStand(Field2DObject *object, Field2DPoint pos, u32 direction);
void Field2DObject_StartTurn(Field2DObject *object, Field2DPoint pos, u32 direction);
void Field2DObject_StartWalk(Field2DObject *object, Field2DPoint pos, u32 direction);
void Field2DObject_StartRun(Field2DObject *object, Field2DPoint pos, u32 direction);
void Field2DObject_StartPause(Field2DObject *object, Field2DPoint pos, u32 direction);
void Field2DObject_StartBump(Field2DObject *object, Field2DPoint pos, u32 direction);
void Field2DObject_StartWalkSlow(Field2DObject *object, Field2DPoint pos, u32 direction);
void Field2DObject_StartWalkFast(Field2DObject *object, Field2DPoint pos, u32 direction);
void Field2DObject_StartWalkInPlaceVeryFast(Field2DObject *object, Field2DPoint pos, u32 direction);
void Field2DObject_StartWalkInPlaceFast(Field2DObject *object, Field2DPoint pos, u32 direction);
void Field2DObject_StartWalkInPlace(Field2DObject *object, Field2DPoint pos, u32 direction);
void Field2DObject_StartWalkInPlaceSlow(Field2DObject *object, Field2DPoint pos, u32 direction);
s32 Field2DObject_UpdateStand(Field2DObject *object);
s32 Field2DObject_UpdateTurn(Field2DObject *object);
s32 Field2DObject_UpdateWalk(Field2DObject *object);
s32 Field2DObject_UpdateRun(Field2DObject *object);
s32 Field2DObject_UpdatePause(Field2DObject *object);
s32 Field2DObject_UpdateBump(Field2DObject *object);
s32 Field2DObject_UpdateWalkInPlace(Field2DObject *object);
Field2DPoint Field2D_GetStepTarget(Field2DPoint pos, s32 direction);
s32 Field2DObject_AdvanceActionFrame(Field2DObject *object);
void Field2DObject_EndAction(Field2DObject *object);
s32 Field2DObjectManager_TryCommand(Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move);

s32 Field2DCommand_CheckStand(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move);
s32 Field2DCommand_CheckTurn(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move);
s32 Field2DCommand_CheckWalk(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move);
s32 Field2DCommand_CheckRun(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move);
s32 Field2DCommand_CheckPause(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move);
s32 Field2DCommand_CheckBump(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move);
s32 Field2DCommand_CheckWalkSlow(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move);
s32 Field2DCommand_CheckWalkInPlace(Field2DObject *object, Field2DMap *map, Field2DObjectManager *objectManager, Field2DCommand *command, Field2DMove *move);
BOOL Field2DObject_IsMapBlockedInDirection(Field2DObject *object, Field2DMap *map, u8 direction);
BOOL Field2DObject_IsObjectInDirection(Field2DObject *object, Field2DObjectManager *objectManager, u8 direction);
void Field2DMove_Init(Field2DMove *move, Field2DObject *object, u16 action, u8 objectId, s32 direction);
Field2DObjectSpriteManager *Field2DObjectSpriteManager_New(SpriteList *spriteList, PaletteData *paletteData, u16 maxSprites, s8 vramType, enum HeapID heapID);
Field2DObjectSpriteManager *Field2DObjectSpriteManager_NewWithShadow(SpriteList *spriteList, PaletteData *paletteData, u16 maxSprites, s32 spriteId, s32 animSet, s32 vramType, enum HeapID heapID);
void Field2DObjectSpriteManager_Free(Field2DObjectSpriteManager *objectSpriteManager);
void Field2DObjectSpriteManager_LoadChar(Field2DObjectSpriteManager *objectSpriteManager, s32 spriteId, s32 animSet, enum HeapID heapID);
void Field2DObjectSpriteManager_UnloadChar(Field2DObjectSpriteManager *objectSpriteManager, s32 spriteId);
BOOL Field2DObjectSpriteManager_IsCharLoaded(Field2DObjectSpriteManager *objectSpriteManager, s32 spriteId);
void Field2DObjectSpriteManager_UnloadAllChars(Field2DObjectSpriteManager *objectSpriteManager);
void Field2DObjectSpriteManager_LoadAvatarChars(Field2DObjectSpriteManager *objectSpriteManager, s32 animSet, enum HeapID heapID);
Field2DObjectSprite *Field2DObjectSpriteManager_CreateSprite(Field2DObjectSpriteManager *objectSpriteManager, Field2DObject *object, u32 priorityMode, enum HeapID heapID);
void Field2DObjectSprite_Delete(Field2DObjectSprite *objectSprite);
void Field2DObjectSpriteManager_Update(Field2DObjectSpriteManager *objectSpriteManager);
void Field2DObjectSprite_Update(Field2DObjectSprite *objectSprite);
void Field2DObjectSprite_SetAutoUpdate(Field2DObjectSprite *objectSprite, s8 autoUpdate);
void Field2DObjectSprite_StartLoopAnim(Field2DObjectSprite *objectSprite);
void Field2DObjectSprite_UpdateAnim(Field2DObjectSprite *objectSprite);
void Field2DObjectSprite_SyncAnim(Field2DObjectSprite *objectSprite);
void Field2DObjectSprite_SetPosition(Field2DObjectSprite *objectSprite, Field2DPoint pos);
BOOL Field2DObjectSprite_IsVisible(Field2DObjectSprite *objectSprite);
void Field2DObjectSprite_SetVisible(Field2DObjectSprite *objectSprite, u16 visible);
u16 Field2DObjectSprite_GetDrawPriority(Field2DObjectSprite *objectSprite);
void Field2DObjectSprite_FaceDirection(Field2DObjectSprite *objectSprite, s32 direction);
u32 Field2DObjectSprite_CalcDrawPriority(s16 y, u8 priorityMode);
u8 Field2DObjectSprite_GetPaletteOffset(Field2DObjectSprite *objectSprite);
void Field2DObjectSprite_SetShadowPosition(Field2DObjectSprite *objectSprite, Field2DPoint pos);
s32 Field2DObjectSprite_IsFree(Field2DObjectSprite *objectSprite);
Field2DObjectSprite *Field2DObjectSpriteManager_GetFreeSprite(Field2DObjectSpriteManager *objectSpriteManager);
u8 Field2DObjectSprite_GetAnimKindForAction(CharSprite *charSprite, s32 action);
void Field2DObjectSprite_GetDrawPos(Field2DObjectSprite *objectSprite, s16 *x, s16 *y);
void Field2DObjectSprite_StartAnim(Field2DObjectSprite *objectSprite, u8 animKind, s32 direction);
void Field2DCamera_CenterOnObject(Field2DPoint *camera, Field2DObject *object);
void Field2DCamera_Init(Field2DPoint *camera);
void Field2DCamera_Set(Field2DPoint *camera, s16 y, s16 x);
s16 Field2DCamera_GetY(Field2DPoint *camera);
s16 Field2DCamera_GetX(Field2DPoint *camera);
Field2DBgLayer *Field2DBgLayer_New(G2dRenderer *g2dRenderer, BgConfig *bgConfig, const Field2DBgLayerTemplate *template, enum HeapID heapID);
void Field2DBgLayer_Free(Field2DBgLayer *layer);
void Field2DBgLayer_SetCamera(Field2DBgLayer *layer, Field2DPoint *camera);
void Field2DBgLayer_InitBg(BgConfig *bgConfig, s32 bgId, const Field2DBgLayerTemplate *template);
void Field2DBgLayer_Scroll(Field2DBgLayer *layer, s16 x, s16 y);
void Field2DBgLayer_CopyVisibleTiles(BgConfig *bgConfig, s32 bgId, NNSG2dScreenData *nnsg2dScreenData, s16 x, s16 y);
void Field2DBgLayer_CopyTilemapRect(BgConfig *bgConfig, u8 bgId, u8 destX, u8 destY, u8 destWidth, u8 destHeight, void *buffer, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight);
u8 Field2DBgLayer_GetScreenBlockLayout(u8 width, u8 height);
void *Field2DBgLayer_GetScreenBlock(void *buffer, u8 blockX, u8 blockY, u8 layout, u8 width, u8 height, Field2DPoint *blockSize);
Field2DMoveQueue *Field2DMoveQueue_New(s32 maxEntries, enum HeapID heapID);
void Field2DMoveQueue_Free(Field2DMoveQueue *queue);
void Field2DMoveQueue_Push(Field2DMoveQueue *queue, Field2DMove *entry);
s32 Field2DMoveQueue_Pop(Field2DMoveQueue *queue, Field2DMove *entry);
Field2DCommandQueue *Field2DCommandQueue_New(s32 maxEntries, enum HeapID heapID);
void Field2DCommandQueue_Free(Field2DCommandQueue *queue);
void Field2DCommandQueue_Push(Field2DCommandQueue *queue, Field2DCommand *command);
u32 Field2DCommandQueue_Pop(Field2DCommandQueue *queue, Field2DCommand *command);

#endif // POKEHEARTGOLD_OVY_42_H
