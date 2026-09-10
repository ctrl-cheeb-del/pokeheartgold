#include "overlay_27_helpers_internal.h"

u8 ov27_0225AA60(const u8 *data, int size) {
    int i;
    int sum = 0;
    for (i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}
