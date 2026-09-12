#include "overlay40_pc_display_r4_private.h"

void ov40_0222CED8(void *p) {
    int i;
    u8 *row = p;

    for (i = 0; i < 5; i++, row += 0x28) {
        sub_02013FD0(PTR(row, 0x610), *(void **)PTR(row, 0x5FC));
        sub_02013FD0(PTR(row, 0x548), *(void **)PTR(row, 0x534));
    }
}
