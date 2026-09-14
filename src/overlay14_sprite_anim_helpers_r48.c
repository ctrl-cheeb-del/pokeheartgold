#include "global.h"

#include "overlay14_sprite_anim_helpers_r48_private.h"
#include "sprite_system.h"

void ov14_021F29C4(void *work) {
    u8 *ptr = work;
    u32 i;

    for (i = 0; i < 15; i++, ptr += sizeof(ManagedSprite *)) {
        ManagedSprite *sprite = *(ManagedSprite **)(ptr + 0x2FC);

        if (sprite != NULL) {
            ManagedSprite_TickFrame(sprite);
        }
    }
}

void ov14_021F29E4(void *work, u32 index, u32 anim) {
    ManagedSprite **sprites = (ManagedSprite **)((u8 *)work + 0x2FC);

    ManagedSprite_SetAnimationFrame(sprites[index], 0);
    ManagedSprite_SetAnim(sprites[index], anim);
}
