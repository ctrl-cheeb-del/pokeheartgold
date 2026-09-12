#include "overlay14_box_sprite_setup_private.h"

void ov14_021F3B3C(void *p) {
    u32 i;
    for (i = 0; i < 8; i++) {
        ManagedSprite_SetDrawFlag(PTR_AT((u8 *)p + i * 4, 0x3f0), TRUE);
    }
}

void ov14_021F3B5C(void *p) {
    s16 pos[2];
    u32 i;
    ManagedSprite_GetPositionXY(PTR_AT(p, 0x328), &pos[1], &pos[0]);
    if (PTR_AT(p, 0x3f0) != NULL) {
        for (i = 0; i < 8; i++) {
            ManagedSprite_SetPositionXY(PTR_AT((u8 *)p + i * 4, 0x3f0), pos[1] + ov14_021F8070[i], pos[0] + ov14_021F8078[i]);
        }
    }
}

void ov14_021F3BC0(void *p) {
    s8 pos[2];
    sub_02019B1C(PTR_AT(p, 0x2f0), 0x10, &pos[1], &pos[0]);
    ManagedSprite_SetPositionXY(PTR_AT(p, 0x32c), 0x12, pos[0] * 8 + 0x168);
    ManagedSprite_SetDrawFlag(PTR_AT(p, 0x32c), TRUE);
}

void ov14_021F3C08(void *p) {
    SpriteSystem_LoadCharResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x52, TRUE, 2, 0xc121);
    SpriteSystem_LoadCharResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x52, TRUE, 2, 0xc122);
    SpriteSystem_LoadPlttResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 8, 0x4a, FALSE, 3, 2, 0xc0fe);
    SpriteSystem_LoadCellResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x53, TRUE, 0xc0fc);
    SpriteSystem_LoadAnimResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x54, TRUE, 0xc0fc);
}

void ov14_021F3CB4(void *p) {
    PTR_AT(p, 0x330) = SpriteSystem_NewSpriteWithYOffset(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), ov14_021F844C, 2 << 20);
    PTR_AT(p, 0x334) = SpriteSystem_NewSpriteWithYOffset(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), ov14_021F8480, 2 << 20);
    ManagedSprite_SetDrawFlag(PTR_AT(p, 0x330), FALSE);
    ManagedSprite_SetDrawFlag(PTR_AT(p, 0x334), FALSE);
}

void ov14_021F3D0C(void *p, u32 a1, u32 index, u32 resourceId) {
    void *charData;
    void *data;
    data = sub_020776B4(p);
    data = GfGfxLoader_GetCharData(data, sub_02077678((void *)a1), TRUE, &charData, 0xa);
    ov14_021F2C50(p, index, PTR_AT(charData, 0x14), 0x100);
    Heap_Free(data);
    {
        u32 palette;
        p = (u8 *)p + 0x2fc;
        index *= 4;
        palette = ManagedSprite_GetPaletteOverrideOffset(PTR_AT(p, index));
        ManagedSprite_SetPaletteOverride(PTR_AT(p, index), palette + sub_0207769C((void *)a1));
    }
}

void ov14_021F3D70(void *p, void *entry) {
    typedef struct Entry {
        u8 pad[0x12];
        u8 unused : 7;
        u8 hidden : 1;
    } Entry;
    if (((Entry *)entry)->hidden != 0) {
        ManagedSprite_SetDrawFlag(PTR_AT(p, 0x330), FALSE);
        ManagedSprite_SetDrawFlag(PTR_AT(p, 0x334), FALSE);
        return;
    }
    ov14_021F3D0C(p, U8_AT(entry, 0xc), 0xd, 0xc121);
    ManagedSprite_SetDrawFlag(PTR_AT(p, 0x330), TRUE);
    if (U8_AT(entry, 0xd) != 0 && U8_AT(entry, 0xc) != U8_AT(entry, 0xd)) {
        ov14_021F3D0C(p, U8_AT(entry, 0xd), 0xe, 0xc122);
        ManagedSprite_SetDrawFlag(PTR_AT(p, 0x334), TRUE);
    } else {
        ManagedSprite_SetDrawFlag(PTR_AT(p, 0x334), FALSE);
    }
}

void ov14_021F3DE8(void *p) {
    SpriteSystem_LoadCharResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x42, TRUE, 1, 0xc12d);
    SpriteSystem_LoadPlttResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x45, FALSE, 3, 1, 0xc101);
    SpriteSystem_LoadCellResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x43, TRUE, 0xc0ff);
    SpriteSystem_LoadAnimResObj(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x13, 0x44, TRUE, 0xc0ff);
}

void ov14_021F3E70(void *p) {
    PTR_AT(p, 0x2fc) = SpriteSystem_NewSprite(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), ov14_021F81A8);
    PTR_AT(p, 0x300) = SpriteSystem_NewSprite(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), ov14_021F81DC);
    PTR_AT(p, 0x30c) = SpriteSystem_NewSprite(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), ov14_021F8278);
    PTR_AT(p, 0x310) = SpriteSystem_NewSprite(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), ov14_021F82AC);
    PTR_AT(p, 0x314) = SpriteSystem_NewSprite(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), ov14_021F82E0);
    PTR_AT(p, 0x318) = SpriteSystem_NewSprite(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), ov14_021F8314);
    PTR_AT(p, 0x31c) = SpriteSystem_NewSprite(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), ov14_021F8348);
    PTR_AT(p, 0x320) = SpriteSystem_NewSprite(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), ov14_021F837C);
    PTR_AT(p, 0x324) = SpriteSystem_NewSprite(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), ov14_021F83B0);
    ov14_021F2A18(p, 0xa, 0);
}
