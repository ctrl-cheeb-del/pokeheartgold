#include "to46_overlay_57_state_entry_private.h"

int ov57_0223A6B8(void *work) {
    Ov57Part1Work *w = work;
    u32 offset;

    switch (w->state) {
    case 0:
        ov57_0223B948(work, FALSE);
        ov57_022398C4(work);
        ov57_022399F8(work);
        ov57_0223B75C(work);
        ov57_0223B78C(work);
        offset = 0xa2;
        ((u32 *)work)[offset] = 0;
        offset = 0x41;
        *(u32 *)((u8 *)work + (offset << 4)) = 0;
        ov57_02239BCC();
        w->state++;
        break;
    case 1:
        if (ov57_0223B940() == TRUE || IsPaletteFadeFinished() != TRUE) {
            break;
        }
        GfGfx_EngineATogglePlanes(0x10, FALSE);
        GfGfx_EngineBTogglePlanes(4, TRUE);
        SetBgPriority(7, 1);
        ov57_0223A034(work, TRUE);
        ov57_02239240(work, TRUE);
        ov57_022387C0(work, TRUE);
        ov57_02238AF0(work, TRUE);
        ManagedSprite_SetAnimationFrame(w->sprites[0], 0);
        ManagedSprite_SetAnimationFrame(w->sprites[1], 0);
        ManagedSprite_SetAnimationFrame(w->sprites[2], 0);
        SetBgPriority(3, 1);
        ClearWindowTilemapAndCopyToVram((u8 *)work + 0x11c);
        ov57_02239728((u8 *)work + 0xec, 0, 0xffff, 1);
        *(vu16 *)0x04000304 |= 0x8000;
        ov57_02239BAC();
        w->state++;
        break;
    case 2:
        if (IsPaletteFadeFinished() != TRUE) {
            break;
        }
        ov57_0223B948(work, TRUE);
        w->state = 0;
        return 4;
    }
    return 0;
}
