#include "to47_overlay18_pokedex_area_ui_03_private.h"

void ov18_021F21FC(void *p, int idx, u32 resource) {
    NNSG2dCharacterData *charData;
    void *loaded;
    int palette;

    loaded = GfGfxLoader_GetCharDataFromOpenNarc(*(NARC **)((u8 *)p + 0x854), ov18_021F967C(resource), TRUE, &charData, HEAP_ID_POKEDEX_APP);
    ov18_021F111C(p, idx, charData->pRawData, 0x180, 2);
    palette = SpriteManager_FindPlttResourceOffset(*(SpriteManager **)((u8 *)p + 0x66C), 0xC558, 2);
    ManagedSprite_SetPaletteOverride(*(ManagedSprite **)((u8 *)p + 0x670 + idx * 4), palette + ov18_021F9688(resource));
    Heap_Free(loaded);
}

void ov18_021F2270(void *p) {
    SpriteSystem_LoadCharResObjFromOpenNarc(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 53, TRUE, 1, 0xC597);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(*(PaletteData **)((u8 *)p + 0x850), PLTTBUF_MAIN_OBJ, *(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 56, FALSE, 1, 1, 0xC559);
    SpriteSystem_LoadCellResObjFromOpenNarc(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 54, TRUE, 0xC556);
    SpriteSystem_LoadAnimResObjFromOpenNarc(*(SpriteSystem **)((u8 *)p + 0x668), *(SpriteManager **)((u8 *)p + 0x66C), *(NARC **)((u8 *)p + 0x854), 55, TRUE, 0xC556);
}
