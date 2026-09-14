#include "overlay70_menu_input_r13_private.h"
#include "sprite.h"
#include "system.h"

extern const u16 ov70_02245240[];
extern const u16 ov70_02245242[];
extern int ov70_02239730(void);
extern void ov70_02239740(void *work, int selection);
extern void ov70_02238D8C(Sprite *sprite, int x, int y);
extern int ov70_02238E64(void *work);
extern void ov70_02239BDC(void *work, int a1, int a2, int a3, int a4);
extern void ov70_02238D84(void *work, int a1, int a2);
extern void PlaySE(int seqNo);

int ov70_02239834(void *work) {
    u8 *p = work;
    int selection = ov70_02239730();
    int index;

    if (selection != -1) {
        *(u16 *)(p + 0x11C) = selection;
        PlaySE(0x5DC);
        index = *(u16 *)(p + 0x11C);
        ov70_02238D8C(*(Sprite **)(p + 0xDCC), ov70_02245240[index * 2], ov70_02245242[index * 2]);
        ov70_02239740(work, selection);
        return 3;
    }

    if (gSystem.newKeys & 2) {
        ov70_02239BDC(work, 7, ov70_02238E64(work), 0, 0xF0F);
        ov70_02238D84(work, 10, 12);
        Sprite_SetAnimActiveFlag(*(Sprite **)(p + 0xDCC), FALSE);
    } else if (gSystem.newKeys & 1) {
        ov70_02239740(work, *(u16 *)(p + 0x11C));
    } else if (gSystem.newKeys & 0x40) {
        if (*(u16 *)(p + 0x11C) != 0) {
            *(u16 *)(p + 0x11C) -= 1;
            PlaySE(0x5DC);
            selection = *(u16 *)(p + 0x11C);
            ov70_02238D8C(*(Sprite **)(p + 0xDCC), ov70_02245240[selection * 2], ov70_02245242[selection * 2]);
        }
    } else if ((gSystem.newKeys & 0x80) && *(u16 *)(p + 0x11C) < 2) {
        *(u16 *)(p + 0x11C) += 1;
        PlaySE(0x5DC);
        selection = *(u16 *)(p + 0x11C);
        ov70_02238D8C(*(Sprite **)(p + 0xDCC), ov70_02245240[selection * 2], ov70_02245242[selection * 2]);
    }

    return 3;
}
