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
void ov18_021F6AB0(void *p, int a1, int a2);
void ov18_021F6E2C(void *p);
void ov18_021F6E58(void *p, int a1);

void ov18_021F6DE0(void *p, int a1) {
    *(void **)((u8 *)p + 0x1864) = GridInputHandler_Create(ov18_021FB878, ov18_021FB9F0, ov18_021FB688, p, TRUE, a1, 0x25);
    ov18_021F11C0(p, 0, 1);
    ov18_021F6E58(p, a1);
}
