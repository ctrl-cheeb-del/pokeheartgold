#include "r40_overlay_27_residual_15_private.h"

int ov27_0225C170(u8 *ctx, int index) {
    int result = -1;
    int i;
    if ((u32)(index - 7) <= 1) {
        return index;
    }
    for (i = 0; i < index + 1; i++, ctx += 8) {
        if (*(u8 *)(ctx + 0x470) != 0) {
            result++;
        }
    }
    if (result == -1) {
        GF_AssertFail();
    }
    return result;
}
