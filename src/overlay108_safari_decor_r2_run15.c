#include "overlay108_safari_decor_r2_private.h"

u8 ov108_021EA700(u8 a, u8 b) {
    if (a == 1) {
        if (b != 1) {
            return 1;
        }
        return 0;
    }
    if (b == 1) {
        return 2;
    }
    return 3;
}
