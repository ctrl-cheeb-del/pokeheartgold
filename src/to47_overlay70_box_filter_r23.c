#include "to47_overlay70_box_filter_r23.h"

int ov70_0223E4FC(void *m) {
    int sum = 0;
    int lock = AcquireBoxMonLock(m);
    int i;
    for (i = 0; i < 10; i++) {
        sum += GetBoxMonData(m, ov70_02245700[i], 0);
    }
    ReleaseBoxMonLock(m, lock);
    return sum != 0;
}

int ov70_0223E538(void *m) {
    int lock = AcquireBoxMonLock(m);
    int species = GetBoxMonData(m, 5, 0);
    int v = GetBoxMonData(m, 0x70, 0);
    ReleaseBoxMonLock(m, lock);
    if (v > 0) {
        switch (species) {
        case 0x1df:
        case 0x1e7:
        case 0x1ec:
            return 1;
        case 0xac:
            return 2;
        }
    }
    return 0;
}
