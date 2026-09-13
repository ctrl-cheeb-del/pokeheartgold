#include "to41_overlay_40_residual_29_unmatched_2_private.h"

#define BLEND(p, w) PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 0x1AC), (u16)WORD(p, 0x58))

int ov40_02236A58(void *p) {
    TouchHitboxController_IsTriggered(PTR(PTR(p, 0x860), 0x334));
    return 0;
}
