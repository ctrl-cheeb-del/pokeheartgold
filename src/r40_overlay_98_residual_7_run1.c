#include "r40_overlay_98_residual_7_private.h"

u32 ov98_0221F024(const u8 *data) {
    int i;
    u16 count = 0;
    GF_ASSERT(data != NULL);
    for (i = 0; i < 0x1ED; i++) {
        if (MATH_CountPopulation(data[i]) == 5) {
            count++;
        }
    }
    return count;
}

u8 ov98_0221F058(const u16 (*records)[22]) {
    u8 i;
    u8 count = 0;
    for (i = 0; i < 10; i++) {
        u16 value = ov98_0221F01C(&records[i], 0);
        if (ov98_0221EFE8(i, 1, value)) {
            count++;
        }
    }
    return count;
}
