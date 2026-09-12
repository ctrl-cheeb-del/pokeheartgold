#include "overlay96_pokeathlon_medal_grid_private.h"

u32 ov96_021FAAE0(s32 a, s32 b, const Ov96R71Rect *r) {
    s32 hi = a + b;
    s32 lo = a - b;
    u32 res = 0;
    if (lo <= r->y + r->h && r->y <= hi) {
        res = 1;
    }
    return res;
}

u32 ov96_021FAB04(s32 a, const Ov96R71Rect *r) {
    u32 res = 0;
    if (a >= r->y + r->h && a - 0x18 < r->y + r->h) {
        res = 1;
    }
    return res;
}
