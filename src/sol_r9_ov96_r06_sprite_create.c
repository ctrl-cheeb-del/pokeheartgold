#include "sol_r9_ov96_r06_private.h"

ManagedSprite *ov96_022164EC(SpriteSystem *spriteSystem, SpriteManager *spriteManager, u16 x, u16 y, u16 animation, u16 drawPriority) {
    ManagedSpriteTemplate template = ov96_0221D79C;
    ManagedSprite *sprite;

    GF_ASSERT(spriteSystem != NULL);
    GF_ASSERT(spriteManager != NULL);
    template.x = x;
    template.y = y;
    template.animation = animation;
    template.drawPriority = drawPriority;
    sprite = SpriteSystem_NewSpriteWithYOffset(spriteSystem, spriteManager, &template, 0x1E0000);
    ManagedSprite_SetAnimateFlag(sprite, TRUE);
    return sprite;
}
