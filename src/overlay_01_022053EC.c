#include "overlay_01_022053EC_internal.h"
u32 ov01_022054E0(void *obj) {
    Overlay01AngleTable table = ov01_02209750;
    void *saved = obj;
    u8 row = ov01_02205584(saved);
    s32 index;
    u8 column;
    if (row != 0) {
        return 0;
    }
    column = sub_020659A8(saved);
    if (column == 0) {
        return 0;
    }
    index = sub_0206599C(saved);
    if (index >= 16) {
        GF_AssertFail();
    }
    column--;
    return table.values[column][index];
}
