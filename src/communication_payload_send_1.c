#include "communication_manager_internal.h"

typedef struct CommWork369 {
    u8 padding[0x69E];
    u8 received[1];
} CommWork369;

void sub_020369CC(int slot, const u8 *data);

void sub_0203690C(int slot, const u8 *data) {
    int remaining;
    u8 *received;

    remaining = --*(int *)(_021D4140.work + 0x66C + slot * 4);
    if (data == NULL) {
        return;
    }
    received = _021D4140.work + 0x69E;
    if (received[slot] != 0 && (data[0] & 1) != 0) {
        return;
    }
    received[slot] = 0;
    if (sub_02035FF0() == 1) {
        remaining = sub_0203772C((u16)sub_0203993C());
        sub_02033FC4((u16)sub_0203993C());
        if ((data[0] & 2) == 0) {
            sub_02033AF0(_021D4140.work + 0x4B0 + slot * 12, data, remaining, 0x5A5);
        }
        received = _021D4140.work + 0x696;
        received[slot]++;
    } else {
        sub_02036D14(data, slot);
        if ((data[0] & 2) == 0) {
            sub_02033AF0(_021D4140.work + 0x51C + slot * 12, data + 1, 11, 0x5AE);
        }
    }
}

void sub_020369CC(int slot, const u8 *data) {
    int remaining;

    remaining = --*(int *)(_021D4140.work + 0x66C + slot * 4);
    if (data == NULL) {
        return;
    }
    {
        u8 *received = _021D4140.work + 0x69E;
        if (received[slot] != 0 && (data[0] & 1) != 0) {
            return;
        }
        received[slot] = 0;
    }
    if (sub_02035FF0() != 1) {
        return;
    }
    remaining = sub_0203772C((u16)sub_0203993C());
    sub_02033FC4((u16)sub_0203993C());
    if (data[0] == 0xFF) {
        *(u16 *)(_021D4140.work + 0x694) &= ~(1 << slot);
    } else {
        *(u16 *)(_021D4140.work + 0x694) |= 1 << slot;
    }
    if (data[0] == 0xFF || data[0] == 2 || data[0] == 0xE) {
        return;
    }
    {
        CommWork369 *work = (CommWork369 *)_021D4140.work;
        if (work->received[slot] != 0 && (data[0] & 1) != 0) {
            return;
        }
    }
    sub_02033AF0(_021D4140.work + 0x51C + slot * 12, data + 1, remaining - 1, 0x5E7);
    {
        CommWork369 *work = (CommWork369 *)_021D4140.work;
        work->received[slot] = 0;
    }
}
