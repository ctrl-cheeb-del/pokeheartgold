#include "r40_unk_02037334_private.h"

void sub_02037334(void) {
    int count;
    int i;
    int offset;
    if (_021D4140.work == NULL || _021D4140.work[0x6BA] != 0) {
        return;
    }
    count = sub_02033FC4((u16)sub_0203993C()) + 1;
    i = 0;
    if (count > 0) {
        offset = i;
        do {
            sub_02033C28(_021D4140.work + 0x51C + offset);
            if (sub_02033BC4(_021D4140.work + 0x51C + offset) > 0) {
                sub_020371C4(_021D4140.work + 0x51C + offset,
                    i,
                    *(void **)(_021D4140.work + 0x494),
                    _021D4140.work + 0x5C0 + offset);
            }
            i++;
            offset += 0xC;
        } while (i < count);
    }
}
