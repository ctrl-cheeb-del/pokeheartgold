#include "global.h"

#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "sprite_system.h"

typedef struct Ov111GraphicsWorkR4 {
    enum HeapID heapId;
    u8 filler04[4];
    BgConfig *bg;
    u8 filler0C[0x10];
    NARC *narc;
} Ov111GraphicsWorkR4;

typedef struct Ov111GraphicsWork2R4 {
    enum HeapID heapId;
    u8 filler04[8];
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
} Ov111GraphicsWork2R4;

extern const OamCharTransferParam ov111_021E6B8C;
extern const SpriteResourceCountsListUnion ov111_021E6BA0;
extern const OamManagerParam ov111_021E6BB8;

void ov111_021E6000(Ov111GraphicsWorkR4 *);
void ov111_021E60D4(Ov111GraphicsWork2R4 *);

void ov111_021E6000(Ov111GraphicsWorkR4 *work) {
    if (work->bg == NULL) {
        GF_AssertFail();
    }
    GfGfxLoader_GXLoadPalFromOpenNarc(work->narc, 0, (enum GFPalLoadLocation)0, (enum GFPalSlotOffset)0, 0x200, work->heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 1, work->bg, (GFBgLayer)0, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 2, work->bg, (GFBgLayer)0, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 4, work->bg, (GFBgLayer)2, 1, 0, TRUE, work->heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 4, work->bg, (GFBgLayer)3, 1, 0, TRUE, work->heapId);
    GfGfxLoader_GXLoadPalFromOpenNarc(work->narc, 0, (enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0, 0x200, work->heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 1, work->bg, (GFBgLayer)4, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 3, work->bg, (GFBgLayer)4, 0, 0, TRUE, work->heapId);
}

void ov111_021E60D4(Ov111GraphicsWork2R4 *work) {
    OamManagerParam oam;
    OamCharTransferParam transfer;
    SpriteResourceCountsListUnion counts;

    work->spriteSystem = SpriteSystem_Alloc(work->heapId);
    work->spriteManager = SpriteManager_New(work->spriteSystem);
    oam = ov111_021E6BB8;
    transfer = ov111_021E6B8C;
    transfer.maxTasks = 0x20;
    SpriteSystem_Init(work->spriteSystem, &oam, &transfer, 0x20);
    SpriteSystem_InitSprites(work->spriteSystem, work->spriteManager, 0x20);
    counts = ov111_021E6BA0;
    SpriteSystem_InitManagerWithCapacities(work->spriteSystem, work->spriteManager, &counts);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(work->spriteSystem), 0, 0x20c000);
    GfGfx_EngineATogglePlanes(0x10, TRUE);
    GfGfx_EngineBTogglePlanes(0x10, TRUE);
}
