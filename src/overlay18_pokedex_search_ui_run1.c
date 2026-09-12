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

BOOL ov18_021F6310(void *p, int unused, u32 v);
BOOL ov18_021F63DC(void *p, int unused, u32 v);
u32 ov18_021F64A4(void *p, int idx);
u32 ov18_021F64F4(void *p, int idx);
u32 ov18_021F6540(void *p, int idx, u32 v, u32 div);
void ov18_021F6578(void *p, int idx, s16 dy);
void ov18_021F65AC(void *p);
void ov18_021F65EC(void *p);
void ov18_021F662C(void *p);
void ov18_021F6684(void *p);
void ov18_021F6714(void *p);
void ov18_021F67D0(void *p);
void ov18_021F6844(void *p, int idx, int value);
void ov18_021F684C(void *p, int a1, int a2, int a3);
void ov18_021F6984(void *p, int a1, int a2);
void ov18_021F6990(void *p);
void ov18_021F69C0(void *p, int variant);
void ov18_021F6AB0(void *p, int a1, int a2);
void ov18_021F6DE0(void *p, int a1);
void ov18_021F6E2C(void *p);
void ov18_021F6E58(void *p, int a1);

BOOL ov18_021F6258(void *p, u32 x, u32 y) {
    s16 sx;
    s16 sy;
    u32 w;
    ManagedSprite_GetPositionXY(*(ManagedSprite **)((u8 *)p + 0x684), &sx, &sy);
    w = ov18_021F6214(p, 5, ov18_021FA310);
    if (x >= sx - 11 && x <= sx + 11 && y >= sy - (w >> 1) && y <= sy + (w >> 1)) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov18_021F62B4(void *p, u32 x, u32 y) {
    s16 sx;
    s16 sy;
    u32 w;
    ManagedSprite_GetPositionXY(*(ManagedSprite **)((u8 *)p + 0x684), &sx, &sy);
    w = ov18_021F6214(p, 5, ov18_021FA304);
    if (x >= sx - 11 && x <= sx + 11 && y >= sy - (w >> 1) && y <= sy + (w >> 1)) {
        return TRUE;
    }
    return FALSE;
}
