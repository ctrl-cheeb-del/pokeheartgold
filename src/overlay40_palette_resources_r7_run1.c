#include "overlay40_palette_resources_r7_private.h"

u32 ov40_0222DAC0(u8 *work) {
    Ov40R7ValueTable table = *(const Ov40R7ValueTable *)ov40_02244E5C;
    return table.values[work[0x5C]];
}

u32 ov40_0222DAF0(u8 *work) {
    Ov40R7ValueTable table = *(const Ov40R7ValueTable *)ov40_02244E94;
    if (*(u32 *)work != 0) {
        return 0x7E05;
    }
    return table.values[work[0x5C]];
}
