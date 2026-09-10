#include "field_ui_8b1ac_internal.h"

int sub_0208B85C(u8 *dst, int first, int second, u8 value, int sign) {
    int i;
    value += 2;
    for (i = 0; i < 5; i++) {
        if (i > first) {
            dst[i] = 0;
        } else if (i > second) {
            dst[i] = 1;
        } else {
            dst[i] = value;
        }
    }
    if (sign > 0) {
        return 1;
    }
    if (sign < 0) {
        return -1;
    }
    return 0;
}
