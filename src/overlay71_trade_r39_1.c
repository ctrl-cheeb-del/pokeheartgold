#include "overlay71_trade_r39_private.h"

BOOL ov71_02247DEC(Ov71TradeWorkR39 *work, u32 *state) {
    switch (*state) {
    case 0:
        PlaySE(0x6a7);
        ov71_022480C0(work, 0, 0x10, 0xc);
        (*state)++;
        break;
    case 1:
        if (ov71_02248110(work)) {
            Pokepic_Delete(work->pokepic);
            Sprite_SetAnimCtrlSeq(work->sprite1, 0);
            Sprite_SetDrawFlag(work->sprite1, TRUE);
            (*state)++;
        }
        break;
    case 2:
        if (!Sprite_IsAnimated(work->sprite1)) {
            ov71_02247704(work->camera, 1);
            ov71_022480C0(work, 0x10, 0, 0x10);
            ov71_0224817C(work);
            (*state)++;
        }
        break;
    case 3:
        if (ov71_022481D8(work) >= 2 || ov71_022481C8(work) == 1) {
            BeginNormalPaletteFade(0, 0, 0, 0, 0x18, 1, 0x39);
            (*state)++;
        }
        break;
    case 4:
        if (IsPaletteFadeFinished() && ov71_022481C8(work)) {
            return TRUE;
        }
        break;
    default:
        break;
    }
    return FALSE;
}
