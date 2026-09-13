#include "r40_overlay_40_residual_27_unmatched_2_private.h"

BOOL ov40_02230D94(void *work, u64 value) {
    int i = 1;
    u8 *entry;

    entry = (u8 *)work + 4;
    do {
        void *summary = *(void **)(entry + 0x87c);
        if (summary != NULL && sub_0203088C(summary, 4, 0) == value) {
            return TRUE;
        }
        i++;
        entry += 4;
    } while (i < 4);
    return FALSE;
}
