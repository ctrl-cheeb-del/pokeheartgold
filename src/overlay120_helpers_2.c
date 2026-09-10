#include "overlay120_helpers_internal.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern const u32 ov120_022601F4[];
extern const u32 ov120_022601F8[];
extern const u32 ov120_022601FC[];
extern const u32 ov120_02260200[];

void *ov120_0225F0FC(u32 heap) {
    void *p = Heap_Alloc(heap, 0x114);
    memset(p, 0, 0x114);
    return p;
}

void ov120_0225F118(void *p) {
    Heap_Free(p);
}

void ov120_0225F120(void *data, u8 delay, void *window, u8 palette) {
    U32(data, 0) = (u32)window;
    U8(data, 0x10f) = palette;
    U8(data, 0x10d) = delay;
    U8(data, 0x10c) = 0;
    U8(data, 0x10e) = 0;
    U8(data, 0x110) = 1;
    ov120_0225F1E8((u16 *)((u8 *)data + 4), 0x30);
}

int ov120_0225F14C(void *data) {
    int value;
    int quotient;
    int remainder;
    s16 x;
    s16 y;
    if (data == 0) {
        GF_AssertFail();
    }
    if (U8(data, 0x110) == 0) {
        return 1;
    }
    if (U8(data, 0x10c) < 0x30) {
        *(s8 *)((u8 *)data + 0x10e) -= 1;
        if (*(s8 *)((u8 *)data + 0x10e) <= 0) {
            *(s8 *)((u8 *)data + 0x10e) = U8(data, 0x10d);
            value = ov120_0225F240((u8 *)data + 4);
            remainder = value % 8;
            quotient = (u32)value / 8;
            x = (s16)(remainder * 32);
            y = (s16)(quotient * 32);
            ov01_021F0960(PTR(data, 0), y, (s16)(y + 32), x, (s16)(x + 32), U8(data, 0x10f));
            U8(data, 0x10c)
            ++;
        }
    }
    if (U8(data, 0x10c) >= 0x30) {
        U8(data, 0x110) = 0;
        return 1;
    }
    return 0;
}

void ov120_0225F1E8(u16 *data, u32 count) {
    u32 i;
    u16 tmp;
    if (count >= 0x80) {
        GF_AssertFail();
    }
    for (i = 0; i < count; i++) {
        data[i] = i;
    }
    for (i = 0; i < count - 1; i++) {
        u32 index = LCRandom() % count;
        tmp = data[i];
        data[i] = data[index];
        data[index] = tmp;
    }
    U32(data, 0x100) = 0;
    U32(data, 0x104) = count;
}

int ov120_0225F240(void *data) {
    u32 old = U32(data, 0x100);
    u32 next = old + 1;
    u16 result;
    u32 count;
    U32(data, 0x100) = next;
    result = U16(data, old * 2);
    count = U32(data, 0x104);
    next = U32(data, 0x100);
    if (next <= count) {
        count = next;
    }
    U32(data, 0x100) = count;
    return result;
}

void *ov120_0225F268(u32 heap) {
    u8 *p = Heap_Alloc(heap, 0xcc);
    int i;
    u8 *cursor;
    memset(p, 0, 0xcc);
    i = 0;
    cursor = p;
    do {
        PTR(cursor, 4) = ov120_0225F020(heap);
        i++;
        cursor += 4;
    } while (i < 0x30);
    return p;
}

void ov120_0225F294(void *data) {
    int i;
    u8 *p;
    if (data == 0) {
        GF_AssertFail();
    }
    i = 0;
    p = data;
    do {
        ov120_0225F038(PTR(p, 4));
        i++;
        p += 4;
    } while (i < 0x30);
    Heap_Free(data);
}

void ov120_0225F2B8(void *data, u8 delay, u8 alternateDelay, void *target, u8 palette, BOOL reverse) {
    if (target == 0) {
        GF_AssertFail();
    }
    PTR(data, 0) = target;
    U8(data, 0xc9) = palette;
    U8(data, 0xc6) = delay;
    U8(data, 0xc7) = alternateDelay;
    U8(data, 0xc4) = 0;
    U8(data, 0xc5) = 0;
    U8(data, 0xc8) = delay;
    U8(data, 0xca) = 1;
    U8(data, 0xcb) = (U8(data, 0xcb) & ~1) | ((u8)reverse & 1);
}
