#include "global.h"

#include "sprite_system.h"

typedef struct Ov93PositionR4 {
    s16 x;
    s16 y;
    u16 animation;
    u8 priority;
} Ov93PositionR4;

extern const ManagedSpriteTemplate ov93_02262DCC;

ManagedSprite *ov93_0226027C(void *sys, const Ov93PositionR4 *position);

ManagedSprite *ov93_0226027C(void *sys, const Ov93PositionR4 *position) {
    ManagedSpriteTemplate template = ov93_02262DCC;
    ManagedSprite *sprite;

    template.x = position->x;
    template.y = position->y;
    template.pal = position->priority;
    sprite = SpriteSystem_NewSprite(*(SpriteSystem **)((u8 *)sys + 0x24), *(SpriteManager **)((u8 *)sys + 0x28), &template);
    ManagedSprite_SetPositionXYWithSubscreenOffset(sprite, position->x, position->y, 0x160000);
    ManagedSprite_SetAnim(sprite, position->animation);
    ManagedSprite_SetAffineOverwriteMode(sprite, 2);
    Sprite_TickFrame(sprite->sprite);
    return sprite;
}
