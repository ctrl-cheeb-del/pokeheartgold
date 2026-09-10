#include "overlay80_palette_effect_internal.h"

Overlay80Pair *ov80_02239D74(void *first, void *second) {
    Overlay80Pair *pair = Heap_Alloc(0x65, sizeof(Overlay80Pair));
    MI_CpuFill8(pair, 0, sizeof(Overlay80Pair));
    pair->tiles = ov80_02239DD0(first);
    pair->palette = ov80_02239F48(second);
    G2x_SetBlendAlpha_(0x04000050, 4, 0x1F, 8, 9);
    return pair;
}

void ov80_02239DB8(Overlay80Pair *pair) {
    ov80_02239EC4(pair->tiles);
    ov80_02239F94(pair->palette);
    Heap_Free(pair);
}
