#include "to45_overlay27_r8_private.h"

s32 ov27_0225B360(s32 a0, s32 a1, const u8 *a2) {
    s32 i;
    s32 ret = -1;

    for (i = 0; i < 3; i++) {
        u8 value = ov27_0225D0B4[a0][a1][i];
        if (a2[value * 8] != 0) {
            ret = value;
            break;
        }
    }
    return ret;
}

void ov27_0225B398(Ov27WorkR8 *work, int selection) {
    GF_ASSERT(selection < 7);
    int i = 0;
    int offset = i;

    while (i < 7) {
        u8 entry = ov27_0225CFC8[work->bits.mode][i];
        u16 member = ov27_0225CF94[entry][0];
        int palette = 0;
        if (entry != 13 && member != 0xFFFF) {
            if (i == selection) {
                palette = 0x10;
            }
            GXS_LoadOBJPltt(&work->paletteData[palette * 2], offset, 0x20);
        }
        offset += 0x20;
        i++;
    }
}
