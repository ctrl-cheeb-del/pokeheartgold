#include "r40_unk_0208B0B0_private.h"

void sub_0208B0B0(void *data, int which, u8 a2) {
    if (which == 0) {
        sub_0208AFE8(data, 6, 0x18, 5, 6, 3, 1, 0, a2);
    } else {
        sub_0208AFE8(data, 6, 0x18, 0xD, 6, 3, 1, 0, a2);
    }
}
