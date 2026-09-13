#include "global.h"

#include "r40_overlay_41_residual_41_private.h"

int ov41_02248E10(int value, int divisor) {
    int d = divisor;
    int v = value;
    int rem = v % d;
    return (d - rem + v) / d;
}

void ov41_02248E28(void *data) {
    u8 *p = data;
    u32 n = 0x1C;
    while (n != 0) {
        *p++ = 0;
        n--;
    }
    *(void (**)(void *))((u8 *)data + 4) = ov41_02248E80;
    *(void (**)(void *))((u8 *)data + 8) = ov41_02248E80;
    *(void (**)(void *))((u8 *)data + 0xC) = ov41_02248E80;
}

void ov41_02248E44(void *data) {
    if (*(u16 *)(gSystem + 0x64) != 0) {
        (*(void (**)(void *))((u8 *)data + 4))(data);
    } else if (*(u16 *)(gSystem + 0x66) != 0) {
        (*(void (**)(void *))((u8 *)data + 0xC))(data);
    } else if (*((u8 *)data + 0x18) != 0) {
        (*(void (**)(void *))((u8 *)data + 8))(data);
    }
    *(u16 *)((u8 *)data + 0x14) = *(u16 *)(gSystem + 0x60);
    *(u16 *)((u8 *)data + 0x16) = *(u16 *)(gSystem + 0x62);
    *((u8 *)data + 0x18) = *(u16 *)(gSystem + 0x66);
}
