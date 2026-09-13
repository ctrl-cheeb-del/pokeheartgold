#include "to41_overlay_96_residual_59_private.h"

#if 0
#endif

#if 0
#endif

void ov96_021F6F3C(Ov96R59Work *w, int v) {
    u8 t = (u8)(v / 30);
    Sprite_SetAnimCtrlSeq(w->unk084, (u8)(t / 10) + 1);
    Sprite_SetAnimCtrlSeq(w->unk088, (u8)(t % 10) + 1);
}
