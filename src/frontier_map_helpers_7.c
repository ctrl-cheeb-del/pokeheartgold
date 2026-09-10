#include "frontier_map_helpers_internal.h"

void ov80_022398E4(FrontierMap *m, u16 *outA, u16 *outB) {
    *outB = ov42_022293A8(&m->unk1C);
    *outA = ov42_022293B0(&m->unk1C);
}

void ov80_02239900(FrontierMapEntry *e, u16 *dst) {
    u16 *src = &e->unk08;
    u32 i = 15;

    do {
        *dst++ = *src++;
    } while (--i != 0);
}
