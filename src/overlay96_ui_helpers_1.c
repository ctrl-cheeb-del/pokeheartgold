#include "overlay96_ui_helpers_private.h"

int ov96_021EE264(const u32 *values, u32 key) {
    int i = 0;
    const u32 *p = values;
    while (i < 4) {
        if (key == ((*p << 4) >> 28)) return (values[i] << 8) >> 24;
        i++;
        p++;
    }
    return -1;
}
