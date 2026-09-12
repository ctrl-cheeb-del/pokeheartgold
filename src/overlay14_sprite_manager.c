#include "overlay14_sprite_manager_private.h"

void ov14_021F2A74(void *p, u32 slot, u32 priority) {
    U16_AT(p, 0x88d2) = 1;
    ManagedSprite_SetDrawPriority(PTR_AT(p, 0x2fc + slot * 4), priority);
    U16_AT(p, 0x88d2) = 0;
}

void ov14_021F2A9C(void *p, u32 slot, u32 enabled) {
    if (enabled == 1) {
        ManagedSprite_SetOamMode(PTR_AT(p, 0x2fc + slot * 4), 1);
    } else {
        ManagedSprite_SetOamMode(PTR_AT(p, 0x2fc + slot * 4), 0);
    }
}

void ov14_021F2AC8(void *p) {
    R50Counts counts;
    R50Transfer transfer;
    R50Oam oam;

    counts = ov14_021F80D4;
    PTR_AT(p, 0x2f4) = SpriteSystem_Alloc(0xa);
    PTR_AT(p, 0x2f8) = SpriteManager_New(PTR_AT(p, 0x2f4));
    transfer = ov14_021F80EC;
    oam = ov14_021F80A8;
    SpriteSystem_Init(PTR_AT(p, 0x2f4), &transfer, &oam, 0x20);
    SpriteSystem_InitSprites(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), 0x67);
    SpriteSystem_InitManagerWithCapacities(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8), &counts);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(PTR_AT(p, 0x2f4)), 0, 2 << 20);
}

void ov14_021F2B68(void *p) {
    SpriteSystem_FreeResourcesAndManager(PTR_AT(p, 0x2f4), PTR_AT(p, 0x2f8));
    SpriteSystem_Free(PTR_AT(p, 0x2f4));
}

void ov14_021F2B88(void *p) {
    ov14_021F41E4(p);
    ov14_021F42EC(p);
    ov14_021F2C84(p);
    ov14_021F3DE8(p);
    ov14_021F3714(p);
    ov14_021F34EC(p);
    ov14_021F3C08(p);
}

void ov14_021F2BB8(void *p) {
    ov14_021F4278(PTR_AT(p, 0x34));
    ov14_021F4380(PTR_AT(p, 0x34));
    ov14_021F2D1C(PTR_AT(p, 0x34));
    ov14_021F3E70(PTR_AT(p, 0x34));
    ov14_021F37F4(PTR_AT(p, 0x34));
    ov14_021F35BC(p);
    ov14_021F3CB4(PTR_AT(p, 0x34));
}

void ov14_021F2BE8(void *p, u32 slot) {
    u32 offset = slot * 4;
    void **sprites = (void **)((u8 *)p + 0x2fc);

    if (*(void **)((u8 *)sprites + offset) != NULL) {
        Sprite_DeleteAndFreeResources(*(void **)((u8 *)sprites + offset));
        *(void **)((u8 *)sprites + offset) = NULL;
    }
}
