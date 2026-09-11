#include "overlay_80_0222AEF8_internal.h"

typedef struct {
    u16 a[6];
    u16 b[6];
    u16 lo[6];
    u16 hi[6];
} Ov80Packet6;
typedef struct {
    u8 pad0[0x254];
    u16 a[6];
    u8 b[6];
    u8 pad266[2];
    u32 c[6];
    u8 pad280[0x482];
    u8 count;
} Ov80Work6;
typedef struct {
    u16 a[4];
    u16 b[4];
    u16 lo[4];
    u16 hi[4];
} Ov80Packet4;
typedef struct {
    u8 pad0[0x3D2];
    u16 a[4];
    u8 b[4];
    u8 pad3DE[2];
    u32 c[4];
    u8 pad3F0[0x312];
    u8 count;
} Ov80Work4;

BOOL ov80_0222B1DC(void *ctx) {
    u8 *base = ctx;
    u8 *packet = base + 0x504;
    {
        int i = 0;
        u8 *src = base;
        u8 *dst = packet;
        for (; i < 6; i++) {
            *(u16 *)dst = *(u16 *)(src + 0x584);
            src += 2;
            dst += 2;
        }
    }
    {
        u8 *dst;
        int i = 0;
        dst = packet;
        for (; i < 6; i++) {
            *(u16 *)(dst + 0xC) = base[0x590 + i];
            dst += 2;
        }
    }
    {
        u8 *dst;
        int i;
        u8 *src = base;
        dst = packet;
        i = 0;
        dst += 0x18;
        for (; i < 6; i++) {
            *(u16 *)dst = *(u32 *)(src + 0x598);
            *(u16 *)(dst + 0xC) = *(u32 *)(src + 0x598) >> 16;
            src += 4;
            dst += 2;
        }
    }
    return sub_02037030(0x18, packet, 0x3C) == 1;
}

void ov80_0222B24C(u32 sender, u32 a1, const u16 *payload, void *ctx) {
    Ov80Work6 *work = ctx;
    const Ov80Packet6 *packet = (const Ov80Packet6 *)payload;
    int i;
    work->count++;
    if (sender == sub_0203769C() || sub_0203769C() == 0) {
        return;
    }
    for (i = 0; i < 6; i++) {
        work->a[i] = packet->a[i];
    }
    for (i = 0; i < 6; i++) {
        work->b[i] = packet->b[i];
    }
    i = 0;
    payload += 12;
    for (; i < 6; i++) {
        *(u32 *)((u8 *)work + 0x268) = payload[0];
        *(u32 *)((u8 *)work + 0x268) |= payload[6] << 16;
        payload++;
        work = (Ov80Work6 *)((u8 *)work + 4);
    }
}

BOOL ov80_0222B2C4(void *ctx) {
    u8 *base = ctx;
    u8 *packet = base + 0x504;
    {
        int i = 0;
        u8 *src = base;
        u8 *dst = packet;
        for (; i < 4; i++) {
            *(u16 *)dst = *(u16 *)(src + 0x3D2);
            src += 2;
            dst += 2;
        }
    }
    {
        u8 *dst;
        int i = 0;
        dst = packet;
        for (; i < 4; i++) {
            *(u16 *)(dst + 8) = base[0x3DA + i];
            dst += 2;
        }
    }
    {
        u8 *dst;
        int i;
        u8 *src = base;
        dst = packet;
        i = 0;
        dst += 0x10;
        for (; i < 4; i++) {
            *(u16 *)dst = *(u32 *)(src + 0x3E0);
            *(u16 *)(dst + 8) = *(u32 *)(src + 0x3E0) >> 16;
            src += 4;
            dst += 2;
        }
    }
    return sub_02037030(0x19, packet, 0x3C) == 1;
}

void ov80_0222B334(u32 sender, u32 a1, const u16 *payload, void *ctx) {
    Ov80Work4 *work = ctx;
    const Ov80Packet4 *packet = (const Ov80Packet4 *)payload;
    int i;
    work->count++;
    if (sender == sub_0203769C() || sub_0203769C() == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        work->a[i] = packet->a[i];
    }
    for (i = 0; i < 4; i++) {
        work->b[i] = packet->b[i];
    }
    i = 0;
    payload += 8;
    for (; i < 4; i++) {
        *(u32 *)((u8 *)work + 0x3E0) = payload[0];
        *(u32 *)((u8 *)work + 0x3E0) |= payload[4] << 16;
        payload++;
        work = (Ov80Work4 *)((u8 *)work + 4);
    }
}
