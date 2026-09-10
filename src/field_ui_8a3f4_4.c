#include "field_ui_8a3f4_internal.h"

u8 sub_0208ACDC(u8 *work, u8 ordinal) {
    u16 i;
    u8 target;
    u8 found;
    found = 0;
    i = found;
    target = work[0x7C5] * 9 + ordinal;
    for (; i < 80; i++) {
        if ((*(u32 *)(work + 0x284 + ((u32)i >> 5) * 4) & (1 << (i & 31))) != 0) {
            if (target == found) {
                return (u8)i;
            }
            found++;
        }
    }
    return 0;
}
