#include "overlay96_pokeathlon_medal_grid_private.h"

void ov96_021FBDBC(u8 *p) {
    s32 i;
    U32AT(p, 0x230)
    ++;
    for (i = 0; i < 3; i++) {
        if (p[i * 0x6C + 0xE8] == 0) {
            U32AT(p, 0x22C)
            ++;
            return;
        }
    }
}

s32 ov96_021FBDEC(s32 x) {
    return x / 30 * 30 + 10 * (x % 30) / 30 * 30 / 10;
}

void *ov96_021FBE20(u32 n, u32 heapId) {
    u32 size = n * 0x10;
    void *p = Heap_Alloc(heapId, size);
    MIi_CpuClearFast(0, p, size);
    return p;
}
