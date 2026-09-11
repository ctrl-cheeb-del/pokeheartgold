#include "overlay_93_arm_opus_partial_internal.h"
#include <nitro/code32.h>

s32 ov93_0225F94C(Ov93Work *work) {
    s32 mid;
    s32 span;

    mid = work->f020 + (work->f010 - work->f020) / 2;
    span = (work->f01c - work->f00c) + (work->f0e4 - work->f0d4);
    return FX_Mul(span, -(work->f0d8 - mid)) / 2;
}

s32 ov93_0225F9AC(Ov93Work *work) {
    return (s32)((s64)ov93_0225F94C(work) * 100 / 0x3200000);
}

void ov93_0225F9D8(Ov93Work *work) {
    NARC *narc = NARC_New((NarcId)0xc9, (enum HeapID)0x75);

    SpriteSystem_LoadPaletteBufferFromOpenNarc(work->plttData, (PaletteBufferId)2, work->spriteSystem, work->spriteManager, narc, 0x3a, FALSE, 1, 1, 0x2715);
    SpriteSystem_LoadCharResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 0x37, FALSE, 1, 0x2713);
    SpriteSystem_LoadCellResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 0x39, FALSE, 0x2713);
    SpriteSystem_LoadAnimResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 0x38, FALSE, 0x2713);
    NARC_Delete(narc);
}

void ov93_0225FABC(Ov93Work *work) {
    SpriteManager_UnloadCharObjById(work->spriteManager, 0x2713);
    SpriteManager_UnloadCellObjById(work->spriteManager, 0x2713);
    SpriteManager_UnloadAnimObjById(work->spriteManager, 0x2713);
    SpriteManager_UnloadPlttObjById(work->spriteManager, 0x2715);
}

ManagedSprite *ov93_0225FB00(Ov93Work *work) {
    ManagedSpriteTemplate tmpl = ov93_02262C38;
    ManagedSprite *sprite;

    sprite = SpriteSystem_NewSprite(work->spriteSystem, work->spriteManager, &tmpl);
    ManagedSprite_SetDrawFlag(sprite, FALSE);
    Sprite_TickFrame(sprite->sprite);
    return sprite;
}

void ov93_0225FB6C(Ov93Work *work, ManagedSprite *sprite) {
    s32 anim;

    if (work->f238 != 0) {
        anim = ov93_0225F8AC(work, 0) + 1;
    } else {
        anim = 0;
    }
    ManagedSprite_SetPositionXYWithSubscreenOffset(sprite, (s16)work->f21c, (s16)(ov93_02262C07[work->f270 * 4] + (work->f230 >> 12)), 0x160000);
    ManagedSprite_SetAnim(sprite, anim);
    Sprite_TickFrame(sprite->sprite);
}

void ov93_0225FBE4(ManagedSprite *sprite) {
    Sprite_DeleteAndFreeResources(sprite);
}
