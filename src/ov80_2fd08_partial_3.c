#include "ov80_2fd08_partial_internal.h"

u8 ov80_02230784(void *work) {
    u8 *p = work;
    p[6]++;
    return p[6];
}

u8 ov80_02230790(void *work) {
    return ((u8 *)work)[6];
}

int ov80_02230794(void *work, int row) {
    u8 *p = work;
    TrainerRecordR20 trainer;
    void *raw;
    int index = (u8)(p[6] + row * 7);
    raw = ov80_02229F04(&trainer, *(u16 *)(p + 0x18 + index * 2), 11, 0xCC);
    Heap_Free(raw);
    return ov80_0222A30C((u8)trainer.species);
}

void ov80_022307C8(void *work) {
    ov80_0223049C(work, 1);
}

void ov80_022307D4(void *work) {
    u8 *p = work;
    p[0xA] = 1;
    if (*(u16 *)(p + 0xE) < 8) {
        (*(u16 *)(p + 0xE))++;
    }
    p[6] = 0;
    ov80_0223049C(work, 0);
}
