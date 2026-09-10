#include "screen_window_effect_internal.h"

BOOL sub_02012F54(void *work) {
    s32 *w = work;
    w[11]++;
    if (w[11] >= w[10]) {
        w[11] = 0;
        if (w[9] - 1 > 0) {
            w[7] += w[8];
            w[9]--;
            while (w[7] >= 0xFFFF) {
                w[7] -= 0xFFFF;
            }
            while (w[7] < 0) {
                w[7] += 0xFFFF;
            }
            if (w[7] >= 0x7FFF && w[7] < w[6] && w[16] == 1) {
                sub_02010FEC((void *)w[17], w[14], w[15], w[13]);
                w[16] = 0;
            }
            sub_020131AC(work);
            SysTask_CreateOnVWaitQueue(sub_02010F00, work, 0x3FF);
        } else {
            sub_0200FFB4((struct FadeBlankPair *)w[18], w[2], (enum HeapID)w[12]);
            return TRUE;
        }
    }
    return FALSE;
}
