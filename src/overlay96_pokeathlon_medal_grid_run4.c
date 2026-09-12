#include "overlay96_pokeathlon_medal_grid_private.h"

u32 ov96_021FB60C(u8 *p) {
    s32 i;
    u32 res = 0;
    for (i = 0; i < 3; i++) {
        if (U32AT(p, 0x108) != 4) {
            break;
        }
        p += 0x6C;
    }
    if (i == 3) {
        res = 1;
    }
    return res;
}
