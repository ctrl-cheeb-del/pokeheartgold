#include "r40_unk_020367B0_private.h"

void sub_020367B0(int unused, const u8 *data) {
    u8 *work;
    int stride;
    int count;
    int i;
    int offset;

    work = _021D4140.work;
    (*(int *)(work + 0x668))--;
    if (data == NULL) {
        return;
    }
    if (data[0] == 0xB) {
        if (sub_02035FF0() == 1) {
            return;
        }
        data++;
    } else if (sub_02035FF0() == 0) {
        return;
    }
    work = _021D4140.work;
    if (work[0x6B2] != 0 && (data[0] & 1)) {
        return;
    }
    work[0x6B2] = 0;
    if (sub_02035FF0() == 1) {
        stride = sub_0203772C((u16)sub_0203993C());
        count = sub_02033FC4((u16)sub_0203993C()) + 1;
        i = 0;
        if (count <= 0) {
            return;
        }
        offset = i;
        do {
            if (data[0] == 0xFF) {
                work = _021D4140.work;
                *(u16 *)(work + 0x694) &= ~(1 << i);
            } else {
                work = _021D4140.work;
                *(u16 *)(work + 0x694) |= 1 << i;
            }
            if (data[0] == 0xFF) {
                data += stride;
                goto next;
            }
            if (data[0] == 0xE) {
                data += stride;
                goto next;
            }
            work = _021D4140.work;
            if (work[0x69E + i] != 0 && (data[0] & 1)) {
                data += stride;
                goto next;
            }
            data++;
            sub_02033AF0(work + 0x51C + offset, data, stride - 1, i + 0x54C);
            data += stride - 1;
            work = _021D4140.work;
            work[0x69E + i] = 0;
next:
            i++;
            offset += 12;
        } while (i < count);
    } else {
        *(u16 *)(_021D4140.work + 0x694) = data[1];
        *(u16 *)(_021D4140.work + 0x694) <<= 8;
        *(u16 *)(_021D4140.work + 0x694) += data[2];
        sub_02033AF0(_021D4140.work + 0x4A4, data + 4, data[3], 0x560);
    }
}
