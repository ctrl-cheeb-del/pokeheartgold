#include "overlay108_area_page_private.h"

u32 ov108_021E80F4(Ov108AreaPageWork *work) {
    int i;
    int delta;

    if (work->mode == 0) {
        work->x += 24;
        work->y += 24;
        delta = -24;
    } else {
        work->x -= 24;
        work->y -= 24;
        delta = 24;
    }
    work->flag0 = 1;
    for (i = 0; i < 6; i++) {
        ManagedSprite_OffsetPositionXY(work->movingSprites[work->flagB * 6 + i], 0, delta);
    }
    Sprite_OffsetPositionXY(work->sprite0, 0, delta);
    Sprite_OffsetPositionXY(work->sprite2, 0, delta);
    work->frame++;
    return work->frame >= 8;
}

void ov108_021E81A8(Ov108AreaPageWork *work) {
    int base;
    int delta;
    int i;

    if (work->bit1 == 0) {
        work->index++;
        delta = 256;
    } else {
        work->index--;
        delta = -256;
    }
    base = work->flagB * 6;
    for (i = 0; i < 6; i++) {
        ManagedSprite_SetPositionXY(work->movingSprites[base + i], 48 + 80 * (i % 3) + delta, 56 + 72 * (i / 3));
        ov108_021E84F8(work->sub, (u8)(i + base), (u8)(work->index * 6 + i));
        ManagedSprite_SetPriority(work->movingSprites[base + i], 3);
    }
    work->frame = 0;
}
