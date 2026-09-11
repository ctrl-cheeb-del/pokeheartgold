#include "overlay14_scene_internal.h"

void ov14_021E8020(void *p) {
    sub_020198FC(p, 1, 1, 0, 0x13);
    sub_020198FC(p, 10, 1, 0, 0x13);
}

void ov14_021E8048(void *p) {
    sub_020198FC(p, 1, 1, 0, 0x13);
}

void ov14_021E805C(void *p) {
    sub_020198FC(p, 1, -1, 0, 0x13);
    sub_020196E8(p, 10, 0x2B, 0x15);
    sub_020198FC(p, 10, -1, 0, 0x13);
}

void ov14_021E8094(void *p) {
    sub_020198FC(p, 1, -1, 0, 0x13);
}

u32 ov14_021E80A8(void *p) {
    s8 a[4];
    u32 x, y;
    sub_02019B1C(PP(PP(p, 0x34), 0x2F0), 1, &a[3], &a[2]);
    x = sub_02019978(PP(PP(p, 0x34), 0x2F0), 1);
    y = sub_02019978(PP(PP(p, 0x34), 0x2F0), 10);
    sub_02019978(PP(PP(p, 0x34), 0x2F0), 15);
    sub_02019B1C(PP(PP(p, 0x34), 0x2F0), 1, &a[1], &a[0]);
    if (a[3] != a[1] || a[2] != a[0]) {
        ov14_021F32E0(p);
    }
    if (x == 0 && y == 0) {
        return 0;
    }
    return 1;
}

u32 ov14_021E813C(void *p) {
    s8 a[4];
    u32 x;
    sub_02019B1C(PP(PP(p, 0x34), 0x2F0), 1, &a[3], &a[2]);
    x = sub_02019978(PP(PP(p, 0x34), 0x2F0), 1);
    sub_02019B1C(PP(PP(p, 0x34), 0x2F0), 1, &a[1], &a[0]);
    if (a[3] != a[1] || a[2] != a[0]) {
        ov14_021F32E0(p);
    }
    if (x != 0) {
        return 1;
    }
    return 0;
}
