#include "sol_r12_ov01_windowfx6_private.h"

void ov01_021F010C(SysTask *task, Ov01WindowEffect *effect) {
    s32 value;
    volatile u16 *win = (volatile u16 *)0x04000040;

    switch (effect->state) {
    case 0:
        if (ov01_021EFF28(effect)) {
            effect->state++;
        }
        value = effect->value >> 12;
        if (value >= 0) {
            win[0] = 0xff - value;
            win[2] = 0xc0;
            win[1] = (u8)(value + 1);
            win[3] = 0xc0;
        } else {
            win[0] = (u8)(value + 0xff);
            win[2] = 0xc0;
            win[1] = (u8)(1 - value);
            win[3] = 0xc0;
        }
        break;
    case 1:
        ov01_021F0174(effect);
        break;
    }
}

void ov01_021F0174(Ov01WindowEffect *effect) {
    G2_SetWnd0InsidePlane(0x1f, TRUE);
    G2_SetWndOutsidePlane(0, FALSE);
    G2_SetWnd0Position(0, 0, 0, 0);
    GX_SetVisibleWnd(GX_WNDMASK_W0);
    *effect->done = 1;
    ov01_021FB554(effect->hblankTask);
    effect->hblankTask = NULL;
    SysTask_Destroy(effect->task);
    effect->task = NULL;
}
