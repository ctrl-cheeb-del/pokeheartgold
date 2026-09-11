#include "ov80_2237a70_partial_internal.h"

int ov80_02237A70(int kind, u32 rank, int slot) {
    int lower;
    int range;

    if (kind == 0) {
        int addend = slot + 1;
        int number = 7 * rank + addend;
        if (number == 0x15) {
            return 0x139;
        }
        if (number == 0x31) {
            return 0x13A;
        }
    }
    if (rank >= 8) {
        rank = 7;
    }
    if (slot == 6 || slot == 13) {
        lower = ov80_0223D4D8[rank * 4];
        range = ov80_0223D4DA[rank * 4] - lower;
    } else {
        lower = ov80_0223D4D4[rank * 4];
        range = ov80_0223D4D6[rank * 4] - lower;
    }
    return lower + LCRandom() % range;
}
