#include "heap.h"
#include "math_util.h"
#include "overlay96_sprite_internal.h"

void ov96_021FC2B4(u8 *raw, BOOL draw) {
    SpriteWork *work = (SpriteWork *)raw;
    int i;
    for (i = 0; i < 12; i++) {
        Sprite_SetDrawFlag(work->sprites[i].a, draw);
        Sprite_SetDrawFlag(work->sprites[i].b, draw);
    }
}

void ov96_021FC2E0(u8 *raw, int index, BOOL draw) {
    SpriteWork *work = (SpriteWork *)raw;
    Sprite_SetDrawFlag(work->sprites[index].a, draw);
    Sprite_SetDrawFlag(work->sprites[index].b, draw);
    Sprite_SetDrawFlag(work->sprites[index].c, draw);
}
