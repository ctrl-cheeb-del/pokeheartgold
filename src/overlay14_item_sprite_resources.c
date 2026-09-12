#include "overlay14_item_sprite_resources_private.h"

void ov14_021F34EC(void *p) {
    SpriteSystem_LoadCharResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 8, 0x4c, 0, 2, 0xc11d);
    SpriteSystem_LoadCharResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 8, 0x4c, 0, 2, 0xc11e);
    SpriteSystem_LoadPlttResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 8, 0x4b, 0, 1, 2, 0xc0fa);
    SpriteSystem_LoadPlttResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 8, 0x4b, 0, 1, 2, 0xc0fb);
    SpriteSystem_LoadCellResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 8, 0x4d, 0, 0xc0fa);
    SpriteSystem_LoadAnimResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 8, 0x4e, 0, 0xc0fa);
}

void ov14_021F35BC(void *p) {
    void *q = PTR_AT(p, 0x34);
    PTR_AT(q, 0x304) = SpriteSystem_NewSpriteWithYOffset(PTR_AT(q, 0x2f4), PTR_AT(q, 0x2f8), ov14_021F8210, 2 << 20);
    PTR_AT(q, 0x308) = SpriteSystem_NewSpriteWithYOffset(PTR_AT(q, 0x2f4), PTR_AT(q, 0x2f8), ov14_021F8244, 2 << 20);
    ManagedSprite_SetDrawFlag(PTR_AT(q, 0x304), 0);
    ManagedSprite_SetDrawFlag(PTR_AT(q, 0x308), 0);
}

void ov14_021F3614(void *p, void *monData, u32 slot) {
    R53PokepicTemplate pic;
    R53Dims dims = *(const R53Dims *)ov14_021F8098;
    void *buf;
    u8 *sprites;
    u32 offset;
    u32 location;
    u16 species;
    buf = Heap_AllocAtEnd(0xa, 0xc80);
    GetBoxmonSpriteCharAndPlttNarcIds(&pic, PTR_AT(monData, 0), 2, 0);
    if ((((u32)U8_AT(monData, 0x12) << 24) >> 31) == 1 && U16_AT(monData, 4) == 0x147) {
        species = 0x1ee;
    } else {
        species = U16_AT(monData, 4);
    }
    sub_02014510(pic.narcID, pic.charDataID, 0xa, &dims, buf, U32_AT(monData, 8), 0, 2, species);
    sprites = (u8 *)p + 0x2fc;
    offset = slot * 4;
    location = NNS_G2dGetImageLocation(Sprite_GetImageProxy(PTR_AT(PTR_AT(sprites + offset, 0), 0)), (NNS_G2D_VRAM_TYPE)2);
    DC_FlushRange(buf, 0xc80);
    GXS_LoadOBJ(buf, location, 0xc80);
    location = NNS_G2dGetImagePaletteLocation(Sprite_GetPaletteProxy(PTR_AT(PTR_AT(sprites + offset, 0), 0)), (NNS_G2D_VRAM_TYPE)2);
    GfGfxLoader_GXLoadPal(pic.narcID, pic.palDataID, 5, location, 0x20, 0xa);
    Heap_Free(buf);
}

void ov14_021F36DC(void *p, void *boxmon, u32 slot) {
    slot += U16_AT(PTR_AT(p, 0x34), 0x88d0);
    ov14_021F3614(PTR_AT(p, 0x34), boxmon, slot);
    ManagedSprite_SetDrawFlag(PTR_AT(PTR_AT(p, 0x34), 0x2fc + slot * 4), 1);
    U16_AT(PTR_AT(p, 0x34), 0x88d0) ^= 1;
}

void ov14_021F3714(void *p) {
    u32 map;
    SpriteSystem_LoadCharResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x4f, 1, 1, 0xc11f);
    map = GetItemIndexMapping(0, 2);
    SpriteSystem_LoadPlttResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x12, map, 0, 1, 1, 0xc0fc);
    SpriteSystem_LoadCharResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x4f, 1, 2, 0xc120);
    map = GetItemIndexMapping(0, 2);
    SpriteSystem_LoadPlttResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x12, map, 0, 1, 2, 0xc0fd);
    SpriteSystem_LoadCellResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x50, 1, 0xc0fb);
    SpriteSystem_LoadAnimResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x51, 1, 0xc0fb);
}

void ov14_021F37F4(void *p) {
    PTR_AT(p, 0x328) = SpriteSystem_NewSprite(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), ov14_021F83E4);
    ManagedSprite_SetDrawFlag(PTR_AT(p, 0x328), 0);
    PTR_AT(p, 0x32c) = SpriteSystem_NewSpriteWithYOffset(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), ov14_021F8418, 2 << 20);
    ManagedSprite_SetDrawFlag(PTR_AT(p, 0x32c), 0);
}

void ov14_021F3844(void *p, u32 item) {
    void *charData;
    void *buf;
    u32 pal;
    buf = GfGfxLoader_GetCharData(0x12, GetItemIndexMapping(item, 1), 0, &charData, 0xa);
    ov14_021F2C1C(p, 11, PTR_AT(charData, 0x14), 0x200);
    Heap_Free(buf);
    pal = NNS_G2dGetImagePaletteLocation(Sprite_GetPaletteProxy(PTR_AT(PTR_AT(p, 0x328), 0)), (NNS_G2D_VRAM_TYPE)1);
    GfGfxLoader_GXLoadPal(0x12, GetItemIndexMapping(item, 2), 1, pal, 0x20, 0xa);
}

void ov14_021F38B0(void *p, u32 item) {
    void *charData;
    void *buf;
    u32 pal;
    buf = GfGfxLoader_GetCharData(0x12, GetItemIndexMapping(item, 1), 0, &charData, 0xa);
    ov14_021F2C50(p, 12, PTR_AT(charData, 0x14), 0x200);
    Heap_Free(buf);
    pal = NNS_G2dGetImagePaletteLocation(Sprite_GetPaletteProxy(PTR_AT(PTR_AT(p, 0x32c), 0)), (NNS_G2D_VRAM_TYPE)2);
    GfGfxLoader_GXLoadPal(0x12, GetItemIndexMapping(item, 2), 5, pal, 0x20, 0xa);
}

void ov14_021F391C(void *p, u32 on) {
    if (on == 1) {
        ManagedSprite_SetAffineOverwriteMode(PTR_AT(p, 0x328), 1);
        ManagedSprite_SetAffineTranslation(PTR_AT(p, 0x328), 12, 12);
    } else {
        ManagedSprite_SetAffineTranslation(PTR_AT(p, 0x328), 0, 0);
        ManagedSprite_SetAffineOverwriteMode(PTR_AT(p, 0x328), 0);
    }
}
