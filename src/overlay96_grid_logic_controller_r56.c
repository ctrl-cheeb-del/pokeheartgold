#include "overlay96_grid_logic_r56_private.h"

s32 ov96_021F342C(void *work, void *arg) {
    s32 result = 12;
    s32 value;

    if (R17_U8(work, 0x4EA) == 4) {
        return result;
    }
    R17_U8(work, 0x4E6)
    ++;
    if (R17_U8(work, 0x4E6) >= R17_U8(work, 0x4E7)) {
        u8 i;
        R17_S32(work, 0x4B0) = 1;
        R17_U8(work, 0x4E6) = 0;
        for (i = 0; i < R17_U8(work, 0x4E4); i++) {
            R17_S32((u8 *)work + i * 4, 0x4B4) = 0;
        }
    }
    if (R17_S32(work, 0x4B0) != 0) {
        u8 slot = R17_U8(work, 0x4E9);
        value = 2 - R17_U8(work, 0x4E8) + (slot + R17_U8(work, 0x4E5)) * 3;
        if (value / 3 < slot) {
            GF_AssertFail();
        }
        ov96_021F350C(work, (u8)value, arg);
        result = (u8)value;
        R17_U8(work, 0x4E5)
        ++;
        if (R17_U8(work, 0x4E5) >= R17_U8(work, 0x4E4)) {
            R17_U8(work, 0x4E5) = 0;
            R17_U8(work, 0x4E8) = (R17_U8(work, 0x4E8) + 1) % 3;
            R17_S32(work, 0x4B0) = 0;
        }
    }
    return result;
}
