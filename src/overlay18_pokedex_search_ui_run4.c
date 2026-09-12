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
void ov18_021F6DE0(void *p, int a1);
void ov18_021F6E2C(void *p);
void ov18_021F6E58(void *p, int a1);

void ov18_021F6AB0(void *p, int a1, int a2) {
    fx32 mtx[4];
    fx32 v = FX_Inv(FX_Div(0x100000, a2 << 12));
    mtx[0] = v;
    mtx[3] = v;
    mtx[1] = 0;
    mtx[2] = 0;
    Bg_SetTextDimAndAffineParams(*(void **)((u8 *)p + 4), 7, 0, 0x38, mtx, 0x80, 0x80);
    Bg_SetTextDimAndAffineParams(*(void **)((u8 *)p + 4), 7, 3, 0x10 - a1, mtx, 0x80, 0x80);
}
