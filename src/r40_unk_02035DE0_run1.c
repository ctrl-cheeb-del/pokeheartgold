#include "r40_unk_02035DE0_private.h"

void sub_02035DE0(int slot) {
    int count;
    u8 *work;
    int chunkSize;
    int offset = slot;
    int ringOffset = slot;

    (_021D4140.work + slot)[0x696] = 0;
    (_021D4140.work + slot)[0x69E] = 1;
    *(int *)(_021D4140.work + slot * 4 + 0x66C) = 0;
    count = sub_02033FC4((u16)sub_0203993C());
    work = _021D4140.work;
    work = (u8 *)work;
    chunkSize = _s32_div_f(*(int *)(work + 0x68C), count + 1);
    offset *= chunkSize;
    ringOffset *= 12;
    sub_02033AE0((LocalByteRing *)(work + 0x4B0 + ringOffset), *(u8 **)(work + 0x488) + offset, chunkSize);
    work = _021D4140.work;
    sub_02033AE0((LocalByteRing *)(work + 0x51C + ringOffset), *(u8 **)(work + 0x48C) + offset, chunkSize);
    (_021D4140.work + ringOffset)[0x5CA] = 0xEE;
    *(u16 *)(_021D4140.work + ringOffset + 0x5C8) = 0xFFFF;
    *(int *)(_021D4140.work + ringOffset + 0x5C4) = 0;
    *(int *)(_021D4140.work + ringOffset + 0x5C0) = 0;
}
