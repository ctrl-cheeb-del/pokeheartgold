#include "overlay18_pokedex_search_ui_private.h"

BOOL ov18_021F6258(void *p, u32 x, u32 y);
BOOL ov18_021F62B4(void *p, u32 x, u32 y);
BOOL ov18_021F6310(void *p, int unused, u32 v);
BOOL ov18_021F63DC(void *p, int unused, u32 v);
u32 ov18_021F6540(void *p, int idx, u32 v, u32 div);
void ov18_021F6578(void *p, int idx, s16 dy);
void ov18_021F662C(void *p);
void ov18_021F6684(void *p);
void ov18_021F6714(void *p);
void ov18_021F67D0(void *p);
void ov18_021F6984(void *p, int a1, int a2);
void ov18_021F69C0(void *p, int variant);
void ov18_021F6AB0(void *p, int a1, int a2);
void ov18_021F6DE0(void *p, int a1);
void ov18_021F6E2C(void *p);

BOOL ov18_021F6258(void *p, u32 x, u32 y);
BOOL ov18_021F62B4(void *p, u32 x, u32 y);
BOOL ov18_021F6310(void *p, int unused, u32 v);
BOOL ov18_021F63DC(void *p, int unused, u32 v);
void ov18_021F684C(void *p, int a1, int a2, int a3);
void ov18_021F6984(void *p, int a1, int a2);
void ov18_021F6990(void *p);
void ov18_021F69C0(void *p, int variant);
void ov18_021F6AB0(void *p, int a1, int a2);
void ov18_021F6DE0(void *p, int a1);
void ov18_021F6E2C(void *p);
void ov18_021F6E58(void *p, int a1);

u32 ov18_021F64A4(void *p, int idx) {
    u32 lo;
    u32 v;
    int n;
    u32 q;
    u32 t;
    lo = ov18_021F6230(p, 5, ov18_021FA310, 0x40, 0x56);
    v = ov18_021F6244(p, 5, ov18_021FA310, 0x40, 0x56);
    n = *(s8 *)((u8 *)p + 0x18C4) - 1;
    if (idx != n) {
        q = ((v - lo) << 8) / n;
        t = q * idx;
        v = lo + (t >> 8);
    }
    return v;
}

u32 ov18_021F64F4(void *p, int idx) {
    u32 lo;
    u32 v;
    int n;
    u32 q;
    u32 t;
    lo = ov18_021F6230(p, 5, ov18_021FA304, 0x60, 0x56);
    v = ov18_021F6244(p, 5, ov18_021FA304, 0x60, 0x56);
    n = *(int *)((u8 *)p + 0x1900) - 1;
    if (idx != n) {
        q = ((v - lo) << 8) / n;
        t = q * idx;
        v = lo + (t >> 8);
    }
    return v;
}

u32 ov18_021F6540(void *p, int idx, u32 v, u32 div) {
    s16 sx;
    s16 sy;
    ManagedSprite_GetPositionXY(*(ManagedSprite **)((u8 *)p + idx * 4 + 0x670), &sx, &sy);
    if (v >= sy) {
        return (v - sy) / div;
    } else {
        return (sy - v) / div;
    }
}

void ov18_021F6578(void *p, int idx, s16 dy) {
    s16 sx;
    s16 sy;
    ManagedSprite **base = (ManagedSprite **)((u8 *)p + 0x670);
    ManagedSprite_GetPositionXY(base[idx], &sx, &sy);
    ManagedSprite_SetPositionXY(base[idx], sx, sy + dy);
}

void ov18_021F65AC(void *p) {
    s16 sx;
    s16 sy;
    ManagedSprite_GetPositionXY(*(ManagedSprite **)((u8 *)p + 0x684), &sx, &sy);
    ManagedSprite_SetPositionXY(*(ManagedSprite **)((u8 *)p + 0x684), sx, ov18_021F64A4(p, *(s8 *)((u8 *)p + 0x18C5)));
}

void ov18_021F65EC(void *p) {
    s16 sx;
    s16 sy;
    ManagedSprite_GetPositionXY(*(ManagedSprite **)((u8 *)p + 0x684), &sx, &sy);
    ManagedSprite_SetPositionXY(*(ManagedSprite **)((u8 *)p + 0x684), sx, ov18_021F64F4(p, *(s8 *)((u8 *)p + 0x18CA)));
}

void ov18_021F662C(void *p) {
    ov18_021F5EFC(p, *(s8 *)((u8 *)p + 0x18C5), 1);
    ov18_021F6038(p);
    ov18_021F65AC(p);
    ov18_021F619C(p, *(s8 *)((u8 *)p + 0x18C5), *(s8 *)((u8 *)p + 0x18C4), 6);
    ov18_021F11C0(p, 5, 1);
    ov18_021F11C0(p, 6, 1);
    ov18_021F11C0(p, 7, 1);
    ov18_021F11C0(p, 8, 1);
}

void ov18_021F6684(void *p) {
    ov18_021F11C0(p, 5, 0);
    ov18_021F11C0(p, 6, 0);
    ov18_021F11C0(p, 7, 0);
    ov18_021F11C0(p, 8, 0);
    ov18_021F11C0(p, 14, 0);
    ov18_021F11C0(p, 15, 0);
    ov18_021F11C0(p, 16, 0);
    ov18_021F11C0(p, 17, 0);
    ov18_021F11C0(p, 18, 0);
    ov18_021F11C0(p, 19, 0);
    ov18_021F11C0(p, 1, 0);
    ov18_021F11C0(p, 2, 0);
    ov18_021F11C0(p, 3, 0);
    ov18_021F11C0(p, 4, 0);
}

void ov18_021F6714(void *p) {
    if (*(s8 *)((u8 *)p + 0x18C4) >= 3) {
        ov18_021F11C0(p, 9, 1);
        ov18_021F11C0(p, 10, 1);
        ov18_021F11C0(p, 11, 1);
        ov18_021F11C0(p, 12, 1);
        ov18_021F11C0(p, 13, 1);
    }
    ov18_021F6844(p, 14, *(s8 *)((u8 *)p + 0x18C5));
    ov18_021F6844(p, 15, *(s8 *)((u8 *)p + 0x18C6));
    ov18_021F1294(p, 14, 0x40, 0x50, 0);
    ov18_021F1294(p, 15, 0xC0, 0x50, 0);
    ov18_021F684C(p, 1, *(s8 *)((u8 *)p + 0x18C5), 1);
    ov18_021F684C(p, 2, *(s8 *)((u8 *)p + 0x18C6), 1);
    ov18_021F6990(p);
    ov18_021F11C0(p, 14, 1);
    ov18_021F11C0(p, 15, 1);
}

void ov18_021F67D0(void *p) {
    ov18_021F11C0(p, 9, 0);
    ov18_021F11C0(p, 10, 0);
    ov18_021F11C0(p, 11, 0);
    ov18_021F11C0(p, 12, 0);
    ov18_021F11C0(p, 13, 0);
    ov18_021F11C0(p, 14, 0);
    ov18_021F11C0(p, 15, 0);
    ov18_021F11C0(p, 1, 0);
    ov18_021F11C0(p, 2, 0);
    ov18_021F11C0(p, 3, 0);
    ov18_021F11C0(p, 4, 0);
}

void ov18_021F6844(void *p, int idx, int value) {
    ov18_021F5FFC(p, idx, value);
}
