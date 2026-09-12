#include "overlay96_pokeathlon_shop_ui_private.h"

u32 ov96_021F22FC(void *unused, void *b, u32 group, const VecFx32 *dir) {
    VecFx32 diff;
    u8 i = 0;
    u8 *e = &_0221DCA0[group * 0xc0];
#pragma unused(unused)
    for (; i < 12; i++) {
        if (U32(e, i * 0x10) != 0) {
            VEC_Subtract((VecFx32 *)((u8 *)PTR((u8 *)e + i * 0x10, 8) + 0x28), (VecFx32 *)((u8 *)b + 0x28), &diff);
            if (VEC_DotProduct(dir, &diff) > 0) {
                return 0;
            }
        }
    }
    return 1;
}
