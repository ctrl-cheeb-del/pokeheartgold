#include "summary_screen_helpers_internal.h"

void sub_02089D40(void *p, const u8 *values) {
    u8 i = 0;
    *((u8 *)p + 0x15) = 0;
    do {
        u8 bit = values[i];
        if (bit == 4) {
            break;
        }
        *((u8 *)p + 0x15) |= 1 << bit;
        i++;
    } while (i < 4);
}
