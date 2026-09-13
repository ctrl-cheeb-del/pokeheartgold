#include "ov45_r12_private.h"

int ov45_0222AB28(void *work, int arg) {
    return ov45_0222C95C((u8 *)work + 0x3CC, arg);
}

void ov45_0222AB38(void *work, void *dst) {
    MI_CpuCopy8((u8 *)work + 0x3CC, dst, 0x14);
}

int ov45_0222AB48(void *work, int arg) {
    return ov45_0222C9D0((u8 *)work + 0x3E4, arg);
}

int ov45_0222AB58(void *work, int arg) {
    return ov45_0222C9EC((u8 *)work + 0x3E4, arg);
}

u32 ov45_0222AB68(void) {
    u32 pair[2];
    ov45_0222EC3C(pair);
    return pair[0];
}

int ov45_0222AB78(int unused, int value) {
    int index = ov45_0222ECA4(value);
    int result = -1;
    if (index != -1) {
        result = ov45_0222EC68(index);
    }
    return result;
}

void ov45_0222AB94(int unused, u32 a, u32 b) {
    Ov45Packet20 p;
    u32 *dst = (u32 *)&p;
    dst[0] = 0;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    p.flag = 0;
    p.words[0] = ov45_0222EC90(a);
    p.words[1] = ov45_0222EC90(b);
    p.kind = 2;
    ov45_0222EEF0(4, &p, sizeof(p));
}

void ov45_0222ABD0(int unused, u32 a, u32 b, u8 value) {
    Ov45Packet20 p = { 0 };
    p.flag = 1;
    p.words[0] = ov45_0222EC90(b);
    p.words[1] = ov45_0222EC90(a);
    p.kind = 2;
    p.value = value;
    ov45_0222EEF0(4, &p, sizeof(p));
}
