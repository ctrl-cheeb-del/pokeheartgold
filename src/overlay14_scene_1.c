#include "overlay14_scene_internal.h"

void ov14_021E7E40(void *p) {
    sub_020196E8(p, 2, 0x15, 0x18);
    sub_020198FC(p, 2, 0, -1, 0x12);
}

void ov14_021E7E64(void *p) {
    sub_020198FC(p, 2, 0, 1, 0x12);
}

void ov14_021E7E78(void *p) {
    sub_020196E8(p, 1, 2, 6);
}

void ov14_021E7E88(void *p) {
    sub_020196E8(p, 1, 0x15, 6);
}

void ov14_021E7E98(void *p) {
    void *w = PP(p, 0x34);
    FillBgTilemapRect(PP(w, 0x14), 1, 0, 2, 0x15, 0x0B, 0x12, 0x10);
}

void ov14_021E7EC0(void *p) {
    sub_020196E8(p, 1, 2, 0x18);
}

void ov14_021E7ED0(void *p) {
    sub_020196E8(p, 1, 0x15, 0x18);
}

void ov14_021E7EE0(void *p) {
    s8 xy[2];
    sub_02019B1C(p, 1, &xy[1], &xy[0]);
    if (xy[0] != 6) {
        sub_020198FC(p, 1, 0, -1, (u8)(xy[0] - 6));
        if (xy[1] == 2) {
            sub_020196E8(p, 10, 0x18, (s8)(xy[0] + 15));
            sub_020198FC(p, 10, 0, -1, (u8)(xy[0] - 6));
        }
    }
}

void ov14_021E7F4C(void *p) {
    s8 xy[2];
    sub_02019B1C(p, 1, &xy[1], &xy[0]);
    if (xy[0] != 0x18) {
        sub_020198FC(p, 1, 0, 1, (u8)(0x18 - xy[0]));
        if (xy[1] == 2) {
            sub_020196E8(p, 10, 0x18, (s8)(xy[0] + 15));
            sub_020198FC(p, 10, 0, 1, (u8)(0x18 - xy[0]));
        }
    }
}
