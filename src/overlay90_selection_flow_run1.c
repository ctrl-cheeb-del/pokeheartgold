#include "math_util.h"
#include "overlay90_selection_flow_internal.h"

void ov90_02259B18(void *unused, Ov90SelectionWork *work) {
    ov90_022590C0((u8 *)work + 0x30);
    ov90_0225917C((u8 *)work + 0x84);
    ov90_0225A198((u8 *)work + 0x2E4);
}

u32 ov90_02259B38(const u8 *weights, u32 count) {
    u32 random = MTRandom() % 100;
    u32 sum = 0;
    u32 i;

    for (i = 0; i < count; i++) {
        sum += weights[i];
        if (sum > random) {
            return i;
        }
    }
    GF_AssertFail();
    return count - 1;
}
