#include "overlay40_pc_box_grid_private.h"

void ov40_022334F8(u16 *buf, int start, int count) {
    int i;
    for (i = 0; i < start; i++) {
        buf++;
    }
    for (; i < start + count; i++) {
        int c = *buf;
        int gray = ((c & 0x1F) * 0x4C + ((c >> 5) & 0x1F) * 0x97 + ((c >> 10) & 0x1F) * 0x1D) >> 8;
        *buf = (u16)((gray << 10) | (gray << 5) | gray);
        buf++;
    }
}
