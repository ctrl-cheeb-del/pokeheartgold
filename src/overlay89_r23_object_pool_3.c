#include "overlay89_r23_object_pool.h"

void ov89_0225AF7C(u8 *work, int id) {
    int value;
    if (id != 0xFF) {
        u8 *base = work + 0x53D;
        int offset = id * 4;
        value = base[offset] - 1;
        if (value < 0) {
            GF_AssertFail();
            value = 0;
        }
        base[offset] = value;
    }
}
