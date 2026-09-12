#include "overlay18_map_grid_r19_internal.h"

void ov18_021F42E4(void *p, u32 index, s16 *outX, s16 *outY, u8 *kind) {
    u32 value;

    *outX = (((u8 *)PTR_AT(p, 0x1908))[index * 4] - S8_AT(p, 0x18C8) * 22) * 8 + 68;
    *outY = ((u8 *)PTR_AT(p, 0x1908))[index * 4 + 1] * 8 + 44;
    value = ov18_021E8B18(index);

    if (value == 0x7C || value == 0xB2 || value == 0xB3) {
        *kind = 6;
        *outY += 4;
        return;
    }
    if (value == 0x60 || value == 0x1E7) {
        *kind = 0;
        *outX += 4;
        *outY += 4;
        return;
    }
    if (value == 0x71 || value == 0x13B || (u32)(value - 0x1EA) <= 2) {
        *kind = 6;
        *outY += 4;
        return;
    }
    *kind = 0;
}
