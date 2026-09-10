#include "communication_manager_internal.h"

void sub_02035DA4(void) {
    _021D4140.work[0x6AF] = 0;
    _021D4140.work[0x6B0] = 0;
    *(u32 *)(_021D4140.work + 0x664) = 1;
    sub_02035AE0();
    _0210F900[0] = 4;
    _0210F900[1] = 4;
}

void sub_02035DD8(void) {
    sub_02035AE0();
}
