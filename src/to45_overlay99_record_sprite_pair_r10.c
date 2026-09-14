#include "global.h"

#include "overlay_98_remaining_internal.h"
#include "sprite_system.h"
#include "to45_overlay99_record_sprite_pair_r10_private.h"

#define P(base, off) (*(void **)((u8 *)(base) + (off)))

void ov99_021E8D5C(void *work) {
    const ManagedSpriteTemplate *template = ov99_021EA3F4;
    int i = 0;
    u8 *cursor = work;

    do {
        ManagedSprite *sprite = ov98_0221E6E0(P(work, 0x14), template);
        P(cursor, 0x18) = sprite;
        ManagedSprite_SetAnimateFlag(sprite, TRUE);
        template++;
        cursor += 4;
        i++;
    } while (i < 2);
}
