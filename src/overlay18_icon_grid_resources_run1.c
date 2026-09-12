#include "overlay18_icon_grid_resources_internal.h"

void ov18_021F1324(void *p, u32 count) {
    u32 i;
    for (i = 0; i < count; i++) {
        SpriteSystem_LoadCharResObjFromOpenNarc(PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), PTR(p, 0x854, NARC), 0x4C, TRUE, 1, 0xC550 + i);
    }
    SpriteSystem_LoadPaletteBufferFromOpenNarc(PTR(p, 0x850, PaletteData), (PaletteBufferId)2, PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), PTR(p, 0x858, NARC), sub_02074490(), FALSE, 3, 1, 0xC550);
    SpriteSystem_LoadCellResObjFromOpenNarc(PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), PTR(p, 0x858, NARC), sub_0207449C(), FALSE, 0xC550);
    SpriteSystem_LoadAnimResObjFromOpenNarc(PTR(p, 0x668, SpriteSystem), PTR(p, 0x66C, SpriteManager), PTR(p, 0x858, NARC), sub_020744A8(), FALSE, 0xC550);
}

void ov18_021F13DC(void *p, u32 count) {
    u32 i;
    for (i = 0; i < count; i++) {
        SpriteManager_UnloadCharObjById(PTR(p, 0x66C, SpriteManager), 0xC550 + i);
    }
    SpriteManager_UnloadPlttObjById(PTR(p, 0x66C, SpriteManager), 0xC550);
    SpriteManager_UnloadCellObjById(PTR(p, 0x66C, SpriteManager), 0xC550);
    SpriteManager_UnloadAnimObjById(PTR(p, 0x66C, SpriteManager), 0xC550);
}
