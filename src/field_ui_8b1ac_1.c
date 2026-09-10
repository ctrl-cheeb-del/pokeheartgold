#include "field_ui_8b1ac_internal.h"

void sub_0208B258(u8 *work) {
    SpriteSystem_DestroySpriteManager(*(void **)(work + 0x3FC), *(void **)(work + 0x400));
    SpriteSystem_Free(*(void **)(work + 0x3FC));
}

void sub_0208B278(u8 *work) {
    Sprite_UpdateAnim(*(void **)(work + 0x458), 0x1000);
    Sprite_UpdateAnim(*(void **)(work + 0x45C), 0x1000);
    Sprite_UpdateAnim(*(void **)(work + 0x504), 0x1000);
    Sprite_UpdateAnim(*(void **)(work + 0x508), 0x1000);
}
