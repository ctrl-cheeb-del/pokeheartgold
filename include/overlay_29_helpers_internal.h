#ifndef OVERLAY_29_PRIVATE_H
#define OVERLAY_29_PRIVATE_H

#include "global.h"

typedef void BgConfigPrivate;
typedef void SysTaskPrivate;
typedef void SpritePrivate;
typedef void SpriteListPrivate;
typedef void GfxManagerPrivate;
typedef void GridInputPrivate;

typedef struct BgTemplatePrivate {
    u32 values[7];
} BgTemplatePrivate;

typedef struct SpriteTemplatePrivate {
    SpriteListPrivate *spriteList;
    const void *resourceHeader;
    s32 x;
    s32 y;
    s32 z;
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    u16 rotation;
    u16 pad22;
    u32 priority;
    u32 vramType;
    u32 heapId;
} SpriteTemplatePrivate;

typedef struct SpritePlacementPrivate {
    u8 x;
    u8 y;
    u8 priority;
    u8 animation;
} SpritePlacementPrivate;

typedef struct Ov29OwnerPrivate {
    u32 heapId;
    void *field4;
    void *field8;
} Ov29OwnerPrivate;

typedef struct Ov29AnimPrivate {
    u8 enabled : 1;
    u8 kind : 7;
    u8 from;
    u8 to;
    u8 phase : 3;
    u8 delay : 5;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
} Ov29AnimPrivate;

typedef struct Ov29StatePrivate {
    BgConfigPrivate *bgConfig;
    u8 pad004[0x0c];
    void *output;
    u8 pad014[4];
    SpriteListPrivate *spriteList;
    u8 renderer[0x128];
    GfxManagerPrivate *resourceManagers[4];
    void *resources[8];
    SpritePrivate *sprites[11];
    u8 pad1a0[0x30];
    GridInputPrivate *gridInput;
    Ov29AnimPrivate anim;
    u32 digits[6];
    s32 selection;
    u16 state;
    u16 pending;
    u32 count;
    u32 computed;
} Ov29StatePrivate;

void GF_AssertFail(void);
void *SysTask_GetData(SysTaskPrivate *);
void DestroySysTaskAndEnvironment(SysTaskPrivate *);
void Heap_Destroy(u32);
void FreeBgTilemapBuffer(BgConfigPrivate *, u32);
void SpriteSystem_DrawSprites(void *);
void *SpriteSystem_NewSprite(void *, void *, const void *);
void RemoveWindow(void *);
void *G2dRenderer_Init(u32, void *, u32);
void G2dRenderer_SetSubSurfaceCoords(void *, s32, s32);
void SpriteList_Delete(SpriteListPrivate *);
GfxManagerPrivate *Create2DGfxResObjMan(u32, u32, u32);
void Destroy2DGfxResObjMan(GfxManagerPrivate *);
void Sprite_Delete(SpritePrivate *);
void SpriteTransfer_DeleteCharTransferTask(void *);
void SpriteTransfer_DeletePlttTransferTask(void *);
void Sprite_UpdateAnim(SpritePrivate *, s32);
void GridInputHandler_Free(GridInputPrivate *);
void Sprite_SetAnimCtrlSeq(SpritePrivate *, u32);
void BgTilemapRectChangePalette(BgConfigPrivate *, u32, u32, u32, u32, u32, u32);
void ScheduleBgTilemapBufferTransfer(BgConfigPrivate *, u32);
void InitBgFromTemplate(BgConfigPrivate *, u32, const BgTemplatePrivate *, u32);
void BG_ClearCharDataRange(u32, u32, u32, u32);
void BgClearTilemapBufferAndCommit(BgConfigPrivate *, u32);
SpritePrivate *Sprite_CreateAffine(const SpriteTemplatePrivate *);
s32 GF2DGfxResObj_GetResID(void *);
void CreateSpriteResourcesHeader(void *, s32, s32, s32, s32, s32, s32, u32, u32, GfxManagerPrivate *, GfxManagerPrivate *, GfxManagerPrivate *, GfxManagerPrivate *, void *, void *);
void *AddCharResObjFromOpenNarc(GfxManagerPrivate *, void *, u32, u32, u32, u32, u32);
void *AddPlttResObjFromOpenNarc(GfxManagerPrivate *, void *, u32, u32, u32, u32, u32, u32);
void *AddCellOrAnimResObjFromOpenNarc(GfxManagerPrivate *, void *, u32, u32, u32, u32, u32);
void SpriteTransfer_CreateCharTransferTask_AllocAtEnd(void *);
void SpriteTransfer_CreatePlttTransferTask(void *);
void sub_0200A740(void *);
void Sprite_SetMatrix(SpritePrivate *, const void *);
const u8 *GridInputHandler_GetDpadBox(GridInputPrivate *);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, u32, void *, u32, u32, u32, u32, u32);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, u32, void *, u32, u32, u32, u32, u32);
void GfGfxLoader_GXLoadPalFromOpenNarc(void *, u32, u32, u32, u32, u32);
GridInputPrivate *GridInputHandler_Create(const void *, const void *, const void *, void *, u32, u32, u32);

extern const u8 ov29_0225E248[];
extern const u8 ov29_0225E280[];
extern const void *ov29_0225E13C[];
extern const u8 *const ov29_0225E1E4[];
extern const BgTemplatePrivate ov29_0225E1C8;
extern const BgTemplatePrivate ov29_0225E200;

void ov29_0225DC34(Ov29StatePrivate *);
void ov29_0225D828(Ov29StatePrivate *);
void ov29_0225D7D4(Ov29StatePrivate *);
void ov29_0225D6B4(BgConfigPrivate *);
void ov29_0225DB38(Ov29StatePrivate *);
void ov29_0225D864(Ov29StatePrivate *);
void ov29_0225D840(Ov29StatePrivate *);
void ov29_0225D9C8(Ov29StatePrivate *, void *);
void ov29_0225DC84(Ov29StatePrivate *);
void ov29_0225DB9C(Ov29StatePrivate *, s32);
void ov29_0225DC50(Ov29StatePrivate *);
void ov29_0225D5EC(void *, SysTaskPrivate *);
BOOL ov29_0225D61C(void);
void ov29_0225D7F0(Ov29StatePrivate *, void *);
void ov29_0225D620(void);
void ov29_0225D648(BgConfigPrivate *);
void ov29_0225D970(Ov29StatePrivate *, u32, const void *, const SpritePlacementPrivate *);
void ov29_0225D910(void **, GfxManagerPrivate **, void *, u32);
void ov29_0225D880(void **, GfxManagerPrivate **, void *, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void ov29_0225D6C8(Ov29StatePrivate *, void *);
void ov29_0225DB7C(Ov29StatePrivate *);
void ov29_0225DC44(void);
void ov29_0225DC48(Ov29StatePrivate *, s32);
void ov29_0225DBF0(Ov29StatePrivate *);
void ov29_0225DC50(Ov29StatePrivate *);
void ov29_0225DC84(Ov29StatePrivate *);
void ov29_0225DB9C(Ov29StatePrivate *, s32);
BOOL ov29_0225DEB8(Ov29StatePrivate *, s32);
void ov29_0225DEF4(Ov29StatePrivate *, s32);
void ov29_0225E0E0(Ov29StatePrivate *);
void ov29_0225E028(Ov29StatePrivate *, u8, u8, u8, u16);
void ov29_0225E078(Ov29StatePrivate *, u8, u8, u16);
void ov29_0225DF18(Ov29StatePrivate *, u32);
BOOL ov29_0225DF74(Ov29StatePrivate *);

#endif
