#include "frontier_save_data_helpers_internal.h"

void ov80_022357B4(void *data, void *saveData) {
    u8 *p = data;
    s32 index;
    u16 *source;
    u16 *out1;
    u32 temp;
    u16 values1[2];
    u16 values2[2];
    u8 *entry;
    u16 *out2;

    switch (p[0xF]) {
    case 4:
    case 5:
        ov80_02236698(saveData, p + 0x78, (u8)(p[0xC] - 1));
        return;
    case 2:
    case 3:
    case 6:
        ov80_02236450(data, p + 0x78, *(u16 *)(p + 0x3E + (p[0xC] - 1) * 4), p[0xE], NULL, NULL, 0, *(u32 *)(p + 4));
        index = 0;
        if (index < p[0xE]) {
            source = (u16 *)(p + 0xA8);
            out1 = values1;
            entry = p;
            out2 = values2;
            do {
                temp = (u32)(*source << 21);
                *out1 = temp >> 21;
                *out2 = *(u16 *)(entry + 0xAA);
                source += 0x1C;
                out1++;
                entry += 0x38;
                out2++;
                index++;
            } while (index < p[0xE]);
        }
        ov80_02236450(data, p + 0x188, *(u16 *)(p + 0x3E + (((p[0xC] - 1) * 2 + 1) * 2)), p[0xE], values1, values2, 0, *(u32 *)(p + 4));
        return;
    default:
        ov80_02236450(data, p + 0x78, *(u16 *)(p + 0x3E + (p[0xC] - 1) * 2), p[0xE], NULL, NULL, 0, *(u32 *)(p + 4));
        return;
    }
}

u32 ov80_02235898(void *data, u32 index) {
    u8 *p = data;
    return ov80_0222A30C((u8) * (u16 *)(p + index * 0x110 + 0x7C));
}

void ov80_022358B0(void *data, u32 value) {
    ((Overlay80Bits *)data)->value = (u8)value;
}

u32 ov80_022358C4(void *data) {
    u8 *p = data;
    p[0xD]++;
    if (p[0xF] != 6) {
        *(u32 *)(p + 8) = sub_020674A4(*(u32 *)(p + 8));
    }
    p[0xC]++;
    return p[0xC];
}

u32 ov80_022358E8(void *data) {
    Overlay80Counter *p = data;
    u32 byte = *(volatile u8 *)&p->count;
    u32 result = p->base + byte;
    u32 ret = 0xFFFF;
    if (result <= ret) {
        ret = (u16)result;
    }
    return ret;
}
