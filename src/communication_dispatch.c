#include "communication_dispatch_internal.h"

void sub_02033AE0(ByteRing *ring, u8 *data, u16 capacity) {
    ring->data = data;
    ring->capacity = capacity;
    ring->read = 0;
    ring->limit = 0;
    ring->write = 0;
}

void sub_02033AF0(ByteRing *ring, const u8 *src, int count) {
    int pos;
    int i;
    if (sub_02033BF4(ring) <= count) {
        sub_02037974();
        return;
    }
    pos = *(volatile s16 *)&ring->write;
    i = 0;
    while (pos < *(volatile s16 *)&ring->write + count) {
        GF_ASSERT(src != NULL);
        ring->data[sub_02033C14(ring, pos)] = src[i];
        pos++;
        i++;
    }
    ring->write = sub_02033C14(ring, pos);
}

int sub_02033B4C(ByteRing *ring, u8 *dst, int count) {
    int n = sub_02033B78(ring, dst, count);
    ring->read = sub_02033C14(ring, ring->read + n);
    return n;
}

u8 sub_02033B68(ByteRing *ring) {
    u8 value;
    sub_02033B4C(ring, &value, 1);
    return value;
}

int sub_02033B78(ByteRing *ring, u8 *dst, int count) {
    int pos = ring->read;
    int i = 0;
    for (; pos < ring->read + count; pos++) {
        int index = sub_02033C14(ring, pos);
        if (ring->limit == index) {
            return i;
        }
        dst[i++] = ring->data[sub_02033C14(ring, pos)];
    }
    return i;
}
