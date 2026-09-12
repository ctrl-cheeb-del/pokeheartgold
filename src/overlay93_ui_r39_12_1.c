#include "overlay93_ui_r39_12_private.h"

void ov93_02261BBC(void *sys, void *slots) {
    ManagedSpriteTemplate template = ov93_02262E9C;
    int i;
    u8 *slot;

    for (i = 0, slot = slots; i < 3; i++, slot += 0x18) {
        ManagedSprite *sprite;

        sprite = SpriteSystem_NewSprite(PAT(sys, 0x24), PAT(sys, 0x28), &template);
        PAT(slot, 0) = sprite;
        ManagedSprite_SetPositionXYWithSubscreenOffset(sprite, 0, 0, 0x160000);
        ManagedSprite_SetDrawFlag(PAT(slot, 0), FALSE);

        sprite = SpriteSystem_NewSprite(PAT(sys, 0x24), PAT(sys, 0x28), &ov93_02262ED0);
        PAT(slot, 4) = sprite;
        ManagedSprite_SetPositionXYWithSubscreenOffset(sprite, 0, 0, 0x160000);
        ManagedSprite_SetAnim(PAT(slot, 4), 0x21);
        Sprite_TickFrame(PAT(PAT(slot, 4), 0));
        ManagedSprite_SetDrawFlag(PAT(slot, 4), FALSE);
    }
}
