#include "r40_unk_0203511C_private.h"

int sub_0203511C(void) {
    int i;
    u8 *ptr;
    int count;

    if (!sub_02037474()) {
        return 0;
    }
    count = 0;
    ptr = _021D4134.data;
    for (i = 0; i < 16; i++, ptr += 2) {
        if (*(u16 *)(ptr + 0xD44) != 0) {
            count++;
        }
    }
    return count;
}

int sub_02035150(int target) {
    int i;
    int count = 0;
    u8 *ptr;

    ptr = _021D4134.data;
    for (i = 0; i < 16; i++, ptr += 2) {
        if (*(u16 *)(ptr + 0xD44) != 0) {
            if (count == target) {
                return i;
            }
            count++;
        }
    }
    GF_AssertFail();
    return 0;
}
