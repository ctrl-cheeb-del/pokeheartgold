#include "overlay18_icon_grid_resources_internal.h"

void *ov18_021F148C(void *p, u32 species, u32 form, NNSG2dCharacterData **out) {
    u32 file = GetBattleMonIconNaixEx(species, FALSE, form);
    return GfGfxLoader_GetCharDataFromOpenNarc(PTR(p, 0x858, NARC), file, FALSE, out, (enum HeapID)0x25);
}

void ov18_021F14B4(void *p, void *data, int idx, int palette) {
    int offset = SpriteManager_FindPlttResourceOffset(PTR(p, 0x66C, SpriteManager), 0xC550, 1);
    ov18_021F111C(p, idx, data, 0x200, 1);
    ManagedSprite_SetPaletteOverride(SPR(p, idx), offset + palette);
}

void ov18_021F14FC(void *p, u32 species, u32 form, int idx) {
    NNSG2dCharacterData *data;
    void *raw = ov18_021F148C(p, species, form, &data);
    int palette = GetBattleMonIconPaletteEx(species, form, FALSE);
    ov18_021F14B4(p, data->pRawData, idx, palette);
    Heap_Free(raw);
}

void ov18_021F1534(void *p, u32 species, u32 form, int idx) {
    NNSG2dCharacterData *data;
    void *raw = ov18_021F148C(p, species, form, &data);
    int offset;
    ov18_021F111C(p, idx, data->pRawData, 0x200, 2);
    offset = SpriteManager_FindPlttResourceOffset(PTR(p, 0x66C, SpriteManager), 0xC551, 2);
    ManagedSprite_SetPaletteOverride(SPR(p, idx), offset + GetBattleMonIconPaletteEx(species, form, FALSE));
    Heap_Free(raw);
}
