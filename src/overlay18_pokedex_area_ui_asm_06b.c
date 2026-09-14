#include "overlay18_pokedex_area_ui_asm_06b_private.h"

void ov18_021F2A2C(void *data, int index, int draw) {
    if (draw == 1 && Pokedex_GetInternationalViewFlag(*(void **)*(void **)data) == 1) {
        ManagedSprite_SetDrawFlag(*((void **)((u8 *)data + 0x670) + index), 1);
        ManagedSprite_SetDrawFlag(*((void **)((u8 *)data + 0x674) + index), 1);
    } else {
        ManagedSprite_SetDrawFlag(*((void **)((u8 *)data + 0x670) + index), 0);
        ManagedSprite_SetDrawFlag(*((void **)((u8 *)data + 0x674) + index), 0);
    }
}
