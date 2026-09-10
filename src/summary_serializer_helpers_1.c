#include "summary_serializer_helpers_internal.h"

int sub_02089698(void *v) {
    u8 *w = v;
    switch (w[0x7be]) {
    case 0:
        BgTilemapRectChangePalette(*(void **)w, w[0x7cd], w[0x7c8], w[0x7c9], w[0x7ca], w[0x7cb], (u32)(w[0x7cc] << 28) >> 28);
        ScheduleBgTilemapBufferTransfer(*(void **)w, w[0x7cd]);
        w[0x7be]++;
        break;
    case 1:
        w[0x7ce]++;
        if (w[0x7ce] == 4) {
            BgTilemapRectChangePalette(*(void **)w, w[0x7cd], w[0x7c8], w[0x7c9], w[0x7ca], w[0x7cb], (u32)(w[0x7cc] << 24) >> 28);
            ScheduleBgTilemapBufferTransfer(*(void **)w, w[0x7cd]);
            w[0x7ce] = 0;
            w[0x7be]++;
        }
        break;
    case 2:
        w[0x7ce]++;
        if (w[0x7ce] == 2) {
            w[0x7be] = 0;
            return w[0x7cf];
        }
        break;
    }
    return 15;
}

int sub_02089794(void *v) {
    u8 *w = v;
    if (w[0x7c9] == 5) {
        sub_0208A2C0(v, -1);
    } else {
        sub_0208A2C0(v, 1);
    }
    sub_0208B118(v);
    return 0x13;
}

void sub_020897C0(void *v) {
    u8 *w = v;
    void *mon = sub_0208A520(v);
    if (*((u8 *)*(void **)(w + 0x22c) + 0x11) == 2) {
        sub_020897F0(v, mon, w + 0x230);
    } else {
        sub_0208981C(v, mon, w + 0x230);
    }
}

void sub_020897F0(void *v, void *boxMon, void *out) {
    void *mon = AllocMonZeroed(0x13);
    CopyBoxPokemonToPokemon(boxMon, mon);
    sub_0208981C(v, mon, out);
    Heap_Free(mon);
}
