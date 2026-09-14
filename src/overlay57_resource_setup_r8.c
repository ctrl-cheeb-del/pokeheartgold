#include "overlay57_resource_setup_r8_private.h"

void ov57_02239BEC(Ov57R8Work *work, NARC *narc) {
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 8, *(BgConfig **)((u8 *)work + 0xE4), (GFBgLayer)2, 0, 0, TRUE, HEAP_ID_52);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 12, *(BgConfig **)((u8 *)work + 0xE4), (GFBgLayer)2, 0, 0, TRUE, HEAP_ID_52);
    PaletteData_LoadNarc(work->paletteData, (NarcId)87, 2, HEAP_ID_52, (PaletteBufferId)0, 0x60, 0);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 9, *(BgConfig **)((u8 *)work + 0xE4), (GFBgLayer)3, 0, 0, TRUE, HEAP_ID_52);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 13, *(BgConfig **)((u8 *)work + 0xE4), (GFBgLayer)3, 0, 0, TRUE, HEAP_ID_52);
}

void ov57_02239C88(Ov57R8Work *work, NARC *narc) {
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 7, *(BgConfig **)((u8 *)work + 0xE4), (GFBgLayer)5, 0, 0, TRUE, HEAP_ID_52);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 11, *(BgConfig **)((u8 *)work + 0xE4), (GFBgLayer)5, 0, 0, TRUE, HEAP_ID_52);
    PaletteData_LoadNarc(work->paletteData, (NarcId)87, 1, HEAP_ID_52, (PaletteBufferId)1, 0x40, 0);
}

void ov57_02239CE8(Ov57R8Work *work, NARC *narc) {
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 7, *(BgConfig **)((u8 *)work + 0xE4), (GFBgLayer)7, 0, 0, TRUE, HEAP_ID_52);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 10, *(BgConfig **)((u8 *)work + 0xE4), (GFBgLayer)7, 0, 0, TRUE, HEAP_ID_52);
    PaletteData_LoadNarc(work->paletteData, (NarcId)87, 1, HEAP_ID_52, (PaletteBufferId)1, 0x40, 0);
}

void ov57_02239D48(Ov57R8Work *work, NARC *narc) {
    SpriteSystem *system = work->spriteSystem;
    SpriteManager *manager = work->spriteManager;
    PaletteBufferId buffer = (PaletteBufferId)3;

    SpriteSystem_LoadPaletteBufferFromOpenNarc(work->paletteData, buffer, system, manager, narc, 4, FALSE, 3, 2, 0x6594);
    SpriteSystem_LoadCharResObjFromOpenNarc(system, manager, narc, 0x1A, TRUE, 2, 0x61C2);
    SpriteSystem_LoadCellResObjFromOpenNarc(system, manager, narc, 0x1C, TRUE, 0x6994);
    SpriteSystem_LoadAnimResObjFromOpenNarc(system, manager, narc, 0x1B, TRUE, 0x6D7B);
    SpriteSystem_LoadCharResObjFromOpenNarc(system, manager, narc, 0x1D, TRUE, 2, 0x61C5);
    SpriteSystem_LoadCellResObjFromOpenNarc(system, manager, narc, 0x1F, TRUE, 0x6997);
    SpriteSystem_LoadAnimResObjFromOpenNarc(system, manager, narc, 0x1E, TRUE, 0x6D7E);
    SpriteSystem_LoadCharResObjFromOpenNarc(system, manager, narc, 0x14, TRUE, 2, 0x61BC);
    SpriteSystem_LoadCellResObjFromOpenNarc(system, manager, narc, 0x16, TRUE, 0x698E);
    SpriteSystem_LoadAnimResObjFromOpenNarc(system, manager, narc, 0x15, TRUE, 0x6D75);
    SpriteSystem_LoadCharResObjFromOpenNarc(system, manager, narc, 0x17, TRUE, 2, 0x88CF);
    SpriteSystem_LoadCellResObjFromOpenNarc(system, manager, narc, 0x19, TRUE, 0x6991);
    SpriteSystem_LoadAnimResObjFromOpenNarc(system, manager, narc, 0x18, TRUE, 0x6D78);
}
