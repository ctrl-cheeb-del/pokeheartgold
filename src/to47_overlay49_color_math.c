#include "to47_overlay49_color_math_private.h"

void ov49_02268640(s8 *dest, const u16 *src) {
    dest[0] = src[0] & 0x1F;
    dest[1] = (src[0] & (0x1F << 5)) >> 5;
    dest[2] = (src[0] & (0x1F << 10)) >> 10;
}

void ov49_02268664(const s8 *start, const s8 *end, s8 *dest, s32 step, s32 total) {
    s32 dy = end[1] - start[1];
    s32 dz = end[2] - start[2];
    s32 x = start[0];
    dest[0] = x + (end[0] - x) * step / total;
    dest[1] = start[1] + step * dy / total;
    dest[2] = start[2] + step * dz / total;
}

void ov49_022686C0(s8 *dest, const u16 *src) {
    int i;
    ov49_02268640(dest, src);
    i = 0;
    src++;
    dest += 8;
    while (i < 4) {
        ov49_02268640(dest, src);
        i++;
        src++;
        dest += 4;
    }
}
