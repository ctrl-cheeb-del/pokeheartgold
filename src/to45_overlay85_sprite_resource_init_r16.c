#include "global.h"

#include "filesystem.h"
#include "heap.h"
#include "palette.h"
#include "sprite_system.h"

typedef struct Ov85R16Work {
    u8 pad[0xd94];
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    PaletteData *paletteData;
} Ov85R16Work;

extern const OamManagerParam ov85_021EA6B8;
extern const OamCharTransferParam ov85_021EA56C;
extern const SpriteResourceCountsListUnion ov85_021EA594;

void sub_0203A880(void);
void *sub_0203A4AC(enum HeapID heapId);
void ov85_021E6ECC(Ov85R16Work *work);
void ov85_021E6F6C(Ov85R16Work *work);

void ov85_021E6ECC(Ov85R16Work *work) {
    OamManagerParam oam = ov85_021EA6B8;
    OamCharTransferParam transfer = ov85_021EA56C;
    SpriteResourceCountsListUnion counts;

    work->spriteSystem = SpriteSystem_Alloc((enum HeapID)0x66);
    SpriteSystem_Init(work->spriteSystem, &oam, &transfer, 0x20);
    counts = ov85_021EA594;
    work->spriteManager = SpriteManager_New(work->spriteSystem);
    if (!SpriteSystem_InitSprites(work->spriteSystem, work->spriteManager, 0xff)) {
        GF_AssertFail();
    }
    if (!SpriteSystem_InitManagerWithCapacities(work->spriteSystem, work->spriteManager, &counts)) {
        GF_AssertFail();
    }
}

void ov85_021E6F6C(Ov85R16Work *work) {
    SpriteSystem *spriteSystem = work->spriteSystem;
    SpriteManager *spriteManager = work->spriteManager;
    PaletteData *paletteData = work->paletteData;
    NARC *narc;
    void *raw;
    NNSG2dPaletteData *unpacked;

    G2dRenderer_SetPlttTransferReservedRegion((NNS_G2D_VRAM_TYPE)1);
    narc = NARC_New((NarcId)0xd9, (enum HeapID)0x66);
    SpriteSystem_LoadCharResObjFromOpenNarc(spriteSystem, spriteManager, narc, 0x10, FALSE, 1, 4);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(paletteData, (PaletteBufferId)2, spriteSystem, spriteManager, narc, 0xf, FALSE, 1, 1, 5);
    SpriteSystem_LoadCellResObjFromOpenNarc(spriteSystem, spriteManager, narc, 0x11, FALSE, 6);
    SpriteSystem_LoadAnimResObjFromOpenNarc(spriteSystem, spriteManager, narc, 0x12, FALSE, 7);
    NARC_Delete(narc);
    sub_0203A880();
    raw = sub_0203A4AC((enum HeapID)0x66);
    NNS_G2dGetUnpackedPaletteData(raw, &unpacked);
    PaletteData_LoadPalette(paletteData, unpacked->pRawData, (PaletteBufferId)2, 0xe0, 0x20);
    Heap_Free(raw);
}
