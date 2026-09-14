#include "to47r5_overlay57_capsule_state_private.h"



BOOL ov57_0223A104(void *w) {
    void *narc;
    void *cb;

    switch (U32(w, 0x3fc)) {
    case 0:
        narc = NARC_New(87, 52);
        ov57_02238DD0(w);
        ov57_02238E48(w);
        ov57_02238F48(w);
        ov57_02239BEC(w, narc);
        ov57_02239C88(w, narc);
        ov57_02239CE8(w, narc);
        ov57_02239014(w);
        ov57_022392F4(w, narc);
        ov57_022385DC(w);
        ov57_02237F3C(w);
        ov57_022383D0(w, TRUE);
        ov57_02237F14(w);
        ov57_02239D48(w, narc);
        ov57_02239EB4(w);
        ov57_02239114(w, narc);
        ov57_02239184(w);
        ov57_0223B75C(w);
        ov57_0223B78C(w);
        ov57_022388E4(w, U32(w, 0x448));
        ov57_02238958(w);
        ov57_02238A00(w);
        ov57_0223A034(w, FALSE);
        ov57_02239240(w, FALSE);
        ov57_02238794(w);
        ov57_022387C0(w, FALSE);
        ov57_02239728((u8 *)w + 0x11c, 3, 7, 0);
        ov57_02239B94();
        ov57_0223B948(w, FALSE);
        ov57_0223866C(w, TRUE);
        *(vu16 *)0x04000304 &= ~0x8000;
        NARC_Delete(narc);
        U32(w, 0x3fc)++;
        break;
    case 1:
        ov57_02239BAC();
        U32(w, 0x3fc)++;
        break;
    case 2:
        if (IsPaletteFadeFinished() != TRUE) {
            break;
        }
        U32(w, 0x3fc)++;
        // fallthrough
    case 3:
        U32(w, 0x3fc) = ov57_0223B180(w);
        break;
    case 4:
        cb = TouchscreenListMenu_HandleInput(PTR(w, 0x24c));
        switch ((s32)cb) {
        case -2:
            ov57_0223B700(w);
            ov57_02239728((u8 *)w + 0x11c, 3, 7, 0);
            U32(w, 0x3fc) = 3;
            break;
        case -1:
            break;
        default:
            if (cb != NULL) {
                if (((Ov57ListCallback)cb)(w) != TRUE) {
                    ov57_0223B700(w);
                } else {
                    ov57_02239728((u8 *)w + 0x11c, 3, 7, 0);
                    U32(w, 0x3fc) = 3;
                }
            }
            break;
        }
        break;
    case 5:
        ov57_02239BCC();
        U32(w, 0x3fc)++;
        break;
    case 6:
        if (IsPaletteFadeFinished() == TRUE) {
            ov57_0223864C(w);
            ov57_02239588(w);
            ov57_02238FEC(w);
            ov57_0223A05C(w);
            ov57_02239260(w);
            ov57_02238AC0(w);
            return FALSE;
        }
        break;
    }
    ov57_02238FC4(w);
    ov57_02239558(w);
    return TRUE;
}

BOOL ov57_0223A31C(void *w) {
    u32 x;
    u32 y;
    u32 offset;
    int i;
    u32 sealId;
    void *base;
    void *mon;
    BOOL touched;
    BOOL held;

    switch (U32(w, 0x3fc)) {
    case 0:
        U32(w, 0x3fc) = ov57_0223A6B8(w);
        break;
    case 4:
        U32(w, 0x3fc) = ov57_0223B620(w);
        break;
    case 5:
        U32(w, 0x3fc) = ov57_0223AB58(w);
        break;
    case 6:
        ov57_02239728((u8 *)w + 0xec, 0, 12, 0);
        offset = 0x41;
        *(u32 *)((u8 *)w + (offset << 4)) = 20;
        if (ov57_022384C0(w) == TRUE) {
            offset = 0xa2;
            ((u32 *)w)[offset] = 1;
        }
        ov57_0223853C(w);
        ov57_022394AC(w);
        GameStats_AddScore(Save_GameStats_Get(PTR(PTR(w, 0), 0x28)), 7);
        i = U32(w, 0x3ec);
        sealId = U32((u8 *)w + i * 12, 0x28c);
        if (sealId != 0xff) {
            base = PTR(w, 0);
            mon = PTR((u8 *)base + sealId * 4, 4);
            SetMonData(mon, 171, SealCase_GetCapsuleI(PTR(base, 0x20), i));
        }
        U32(w, 0x3fc) = 11;
        break;
    case 7:
        U32(w, 0x3fc) = ov57_0223A8FC(w);
        break;
    case 11:
        if (ov57_0223A7DC(w)) {
            return TRUE;
        }
        break;
    }
    if (U32(w, 0x3fc) == 4 || U32(w, 0x3fc) == 0) {
        i = U32(w, 0xd4);
        if (i == 0xff) {
            TouchHitboxController_IsTriggered(PTR(w, 0x1ec));
        } else {
            touched = System_GetTouchHeldCoords(&x, &y);
            if (U32(w, 0x3fc) != 4) {
                touched = FALSE;
            }
            if (touched) {
                ov57_02239B2C((u8 *)w + 0xec, sub_0209106C((*(u8 *)((u8 *)w + 0x350 + i * 16))));
                ManagedSprite_SetPositionXY((*(void **)((u8 *)w + 0x354 + i * 16)), x, y);
                ov57_0223848C(w, i);
                ov57_02238508(w, i);
            } else {
                held = ov57_022383F8(w, i);
                ov57_02237EB8((*(u32 *)((u8 *)w + 0x358 + i * 16)), (*(void **)((u8 *)w + 0x354 + i * 16)), 0);
                if (held == FALSE) {
                    GiveOrTakeSeal2(PTR(PTR(w, 0), 0x20), (*(u8 *)((u8 *)w + 0x350 + i * 16)), 1);
                    ov57_022399F8(w);
                    ov57_02238438(w, i);
                }
                PlaySE(0x5ea);
                U32(w, 0xd4) = 0xff;
                ov57_02239B2C((u8 *)w + 0xec, 0xffff);
            }
        }
    }
    ov57_0223A058(w);
    ov57_0223921C(w);
    ov57_02238FC4(w);
    ov57_02239558(w);
    return TRUE;
}
