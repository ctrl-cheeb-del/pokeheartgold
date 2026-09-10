#include "communication_manager_internal.h"

void sub_020372E4(void) {
    u8 *work = _021D4140.work;
    if (work != NULL && work[0x6BA] == 0) {
        sub_02033C28(work + 0x4A4);
        if (sub_02033BC4(_021D4140.work + 0x4A4) > 0) {
            work = _021D4140.work;
            sub_020371C4(work + 0x4A4, 0, *(void **)(work + 0x494), work + 0x620);
        }
    }
}
