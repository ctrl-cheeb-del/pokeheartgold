#include "field_ui_8b1ac_internal.h"

void sub_0208B448(u8 *work) {
    u8 *original = work;
    void **sprites;
    u8 i;
    int zero;
    sprites = (void **)(original + 0x404);
    i = 0;
    zero = i;
    for (; i < 8; i++) {
        Sprite_SetDrawFlag(sprites[i], zero);
    }
    Sprite_SetDrawFlag(*(void **)(original + 0x458), 0);
    Sprite_SetDrawFlag(*(void **)(original + 0x45C), 0);
}

void sub_0208B48C(u8 *work) {
    int value = ((u32)work[0x243] << 24) >> 26;
    int charValue = value == 0 ? 25 : value + 24;
    SpriteSystem_ReplaceCharResObj(*(void **)(work + 0x3FC), *(void **)(work + 0x400), 0xA2, charValue, 0, 0);
    SpriteSystem_ReplacePlttResObj(*(void **)(work + 0x3FC), *(void **)(work + 0x400), 0xA2, _02104C68[((u32)work[0x243] << 24) >> 26] + 0x31, 0, 6);
}
