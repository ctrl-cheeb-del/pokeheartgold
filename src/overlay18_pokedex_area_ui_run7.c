#include "overlay18_pokedex_area_ui_private.h"

void ov18_021F1D58(void *p);
void ov18_021F1D98(void *p, int idx);
void ov18_021F1DE4(void *p, int species, int idx, int spriteIdx);
void ov18_021F1F74(void *p);
void ov18_021F1FDC(void *p, int idx);
void ov18_021F2308(void *p);
void ov18_021F2348(void *p);
void ov18_021F23E4(void *p);
void ov18_021F2424(void *p, int idx, const ManagedSpriteTemplate *tmpl);
void ov18_021F2468(void *p);
void ov18_021F24E0(void *p, int a1, int idx);
void ov18_021F2530(void *p, int a1, int a2);
void ov18_021F2270(void *p);
void ov18_021F1CB4(void *p);
void ov18_021F1E70(void *p);
void ov18_021F209C(void *p, int a1, int a2, int a3);
void ov18_021F2648(void *p);
void ov18_021F26E4(void *p);
void ov18_021F2724(void *p);
void ov18_021F281C(void *p);
void ov18_021F2880(void *p);
void ov18_021F2964(void *p);
void ov18_021F299C(void *p);
void ov18_021F2A2C(void *p, int idx, int draw);
void ov18_021F2A84(void *p, int idx, int draw);
void ov18_021F2AC0(void *p, int idx);
BOOL ov18_021F2AF8(void *p, u32 x, u32 y);
void ov18_021F2B3C(void *p, int idx, s16 dx);
void ov18_021F2B70(void *p, int idx, s16 x);

void ov18_021F2B3C(void *p, int idx, s16 dx) {
    s16 sx;
    s16 sy;
    ManagedSprite **base = (ManagedSprite **)((u8 *)p + 0x670);
    ManagedSprite_GetPositionXY(base[idx], &sx, &sy);
    ManagedSprite_SetPositionXY(base[idx], sx + dx, sy);
}

void ov18_021F2B70(void *p, int idx, s16 x) {
    s16 sx;
    s16 sy;
    ManagedSprite **base = (ManagedSprite **)((u8 *)p + 0x670);
    ManagedSprite_GetPositionXY(base[idx], &sx, &sy);
    ManagedSprite_SetPositionXY(base[idx], x, sy);
}
