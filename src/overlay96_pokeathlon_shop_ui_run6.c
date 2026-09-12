#include "overlay96_pokeathlon_shop_ui_private.h"

u8 ov96_021F2780(void *p, u8 v) {
    s32 n;
    if (S32(p, 0xc) >= 12) {
        GF_AssertFail();
    }
    n = S32(p, 0xc);
    if (n >= 12) {
        return 0xff;
    }
    S32(p, 0xc) = n + 1;
    U8(p, (u8)n) = v;
    return (u8)n;
}
