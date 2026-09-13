#include "ov45_r12_private.h"

void ov45_0222ACB8(int unused, int mode, u8 kind, u32 a, u32 b, u32 c, u32 d) {
    Ov45Packet20 p;
    u32 *dst = (u32 *)&p;
    dst[0] = 0;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    switch (mode) {
    case 0:
    case 1:
    case 2:
        p.flag = 8;
        p.words[0] = ov45_0222EC90(a);
        p.words[1] = ov45_0222EC90(b);
        p.words[2] = ov45_0222EC90(c);
        p.words[3] = ov45_0222EC90(d);
        p.kind = kind;
        p.bits = (p.bits & ~0x7F) | ((u8)mode & 0x7F);
        p.bits &= ~0x80;
        ov45_0222EEF0(4, &p, sizeof(p));
        break;
    }
}

int ov45_0222AD2C(void) {
    int value = ov45_0222ECDC(3);
    if ((u32)value >= 5) {
        value = 0;
    }
    return value;
}

int ov45_0222AD3C(void) {
    int value = ov45_0222ECDC(2);
    if ((u32)value >= 5) {
        value = 0;
    }
    return value;
}

int ov45_0222AD4C(void) {
    return ov45_0222ECDC(5) + 30;
}

u8 ov45_0222AD58(void *work, u32 index) {
    if (index >= 20) {
        GF_AssertFail();
    }
    return *(u8 *)((u32)work + index + 0x1E8);
}

void ov45_0222AD70(int unused, u32 value) {
    u32 local[1];
    local[0] = value;
    ov45_0222EEF0(5, local, sizeof(local));
}

int ov45_0222AD80(void *work, int arg) {
    return ov45_0222C4E4((u8 *)work + 0x20C, arg);
}

int ov45_0222AD90(void *work, int arg) {
    return ov45_0222C4FC((u8 *)work + 0x20C, arg);
}
