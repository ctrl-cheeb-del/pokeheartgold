#include "r40_overlay_70_residual_13_private.h"
#include "sprite.h"

extern const TouchscreenHitbox ov70_0224524C[];
extern void ov70_02239B84(void *work, int a1, int a2, int a3, int a4);
extern void ov70_02238D84(void *work, int a1, int a2);
extern void ov70_02238F10(void *work);
extern void ov70_02238E50(void *work, int a1, int a2);
extern int ov70_02238E64(void *work);
extern void ov70_02239BDC(void *work, int a1, int a2, int a3, int a4);
extern void PlaySE(int seqNo);

int ov70_022396F4(void *work) {
    ov70_02239B84(work, 4, 1, 0, 0xF0F);
    ov70_02238D84(work, 10, 6);
    Sprite_SetAnimActiveFlag(*(Sprite **)((u8 *)work + 0xDCC), TRUE);
    ov70_02238F10(work);
    return 3;
}

int ov70_02239730(void) {
    return TouchscreenHitbox_FindRectAtTouchNew(ov70_0224524C);
}

void ov70_02239740(void *work, int selection) {
    u8 *p = work;

    switch (selection) {
    case 0:
        if (*(u16 *)(p + 0x36) == 0) {
            ov70_02238E50(work, 5, 5);
            *(u32 *)(p + 0x2C) = 9;
            PlaySE(0x5DC);
        } else if (*(u16 *)(p + 0x3A) == 0) {
            ov70_02238E50(work, 7, 0xB);
            *(u32 *)(p + 0x1C) = 2;
            *(u32 *)(p + 0x2C) = 9;
            *(u16 *)(p + 0x3A) = 0x708;
            PlaySE(0x5DC);
        } else {
            Sprite_SetAnimActiveFlag(*(Sprite **)(p + 0xDCC), FALSE);
            ov70_02239B84(work, 0x22, 1, 0, 0xF0F);
            ov70_02238D84(work, 0xB, 5);
            PlaySE(0x5F3);
            *(u32 *)(p + 0x11C0) = 0;
        }
        break;
    case 1:
        *(u16 *)(p + 0x11DE) = 0;
        ov70_02238E50(work, 4, 0xD);
        *(u32 *)(p + 0x2C) = 9;
        PlaySE(0x5DC);
        break;
    case 2:
        ov70_02239BDC(work, 7, ov70_02238E64(work), 0, 0xF0F);
        ov70_02238D84(work, 0xA, 0xC);
        Sprite_SetAnimActiveFlag(*(Sprite **)(p + 0xDCC), FALSE);
        PlaySE(0x5DC);
        break;
    }
}
