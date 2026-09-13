#include "r40_overlay_40_residual_14_private.h"

void ov40_0222F878(Ov40SpritePairR14 *d) {
    ManagedSprite_SetDrawFlag(d->sprite1, TRUE);
    ManagedSprite_SetDrawFlag(d->sprite2, TRUE);
    if (d->pad08 == 0) {
        ManagedSprite_SetDrawFlag(d->sprite1, FALSE);
    }
    if (d->pad08 + d->count >= d->limit) {
        ManagedSprite_SetDrawFlag(d->sprite2, FALSE);
    }
    ManagedSprite_TickTwoFrames(d->sprite1);
    ManagedSprite_TickTwoFrames(d->sprite2);
}

void ov40_0222F8C0(Ov40SpritePairR14 *d) {
    ManagedSprite_SetDrawFlag(d->sprite1, TRUE);
    ManagedSprite_SetDrawFlag(d->sprite2, TRUE);
    if (d->pad08 == 0) {
        ManagedSprite_SetDrawFlag(d->sprite1, FALSE);
    }
    if (d->pad08 + d->count >= d->limit) {
        ManagedSprite_SetDrawFlag(d->sprite2, FALSE);
    }
    if (d->count >= d->limit) {
        ManagedSprite_SetDrawFlag(d->sprite1, FALSE);
        ManagedSprite_SetDrawFlag(d->sprite2, FALSE);
    }
    ManagedSprite_TickTwoFrames(d->sprite1);
    ManagedSprite_TickTwoFrames(d->sprite2);
}

void ov40_0222F920(Ov40SpritePairR14 *d, void *work) {
    SpriteManager_UnloadCharObjById(PTR_AT(work, 0x1c), 0x30d40);
    SpriteManager_UnloadCellObjById(PTR_AT(work, 0x1c), 0x30d40);
    SpriteManager_UnloadAnimObjById(PTR_AT(work, 0x1c), 0x30d40);
    Sprite_DeleteAndFreeResources(d->sprite1);
    Sprite_DeleteAndFreeResources(d->sprite2);
}

void *ov40_0222F950(void *unused, void *work, u32 vram, u32 anim) {
    ManagedSpriteTemplateR14 template;
    void *sprite;
    template.x = 0x80;
    template.y = 0x60;
    template.z = 0;
    template.animation = 0;
    template.drawPriority = 1;
    template.bgPriority = 1;
    template.resIdList[4] = -1;
    template.resIdList[5] = -1;
    template.pal = 0;
    template.vram = vram;
    template.vramTransfer = 0;
    template.resIdList[0] = 0x2e94;
    template.resIdList[2] = 0x2e94;
    template.resIdList[3] = 0x2e94;
    if (vram == 1) {
        template.resIdList[1] = 0x270f;
    } else {
        template.resIdList[1] = 0x2710;
    }
    sprite = SpriteSystem_NewSprite(PTR_AT(work, 0x18), PTR_AT(work, 0x1c), &template);
    ManagedSprite_SetPaletteOverride(sprite, 2);
    ManagedSprite_SetAnim(sprite, anim);
    ManagedSprite_TickFrame(sprite);
    return sprite;
}
