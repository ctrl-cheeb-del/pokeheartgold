#include "r40_overlay_40_residual_41_unmatched_2_private.h"

void ov40_02243F88(void *work) {
    u8 *entry;
    int i;

    ManagedSprite_TickFrame(PTR(work, 0x194));
    ManagedSprite_TickFrame(PTR(work, 0x1B0));
    ManagedSprite_TickFrame(PTR(work, 0x1CC));

    for (i = 1, entry = (u8 *)work + 0x1C; i < 3; i++, entry += 0x1C) {
        u32 anim = ManagedSprite_GetActiveAnim(PTR(entry, 0x194));
        if (anim == 3) {
            if (ManagedSprite_IsAnimated(PTR(entry, 0x194)) == 0) {
                ManagedSprite_SetAnim(PTR(entry, 0x194), WORD(entry, 0x188));
                if (WORD(work, 0x298) == 1) {
                    ov40_02243E80(work, 1, 0);
                } else {
                    ov40_02243E80(work, 1, 1);
                }
                ov40_02243E80(work, 2, 0);
            }
        } else {
            if (anim != WORD(entry, 0x188)) {
                ManagedSprite_SetAnim(PTR(entry, 0x194), WORD(entry, 0x188));
            }
            if (ManagedSprite_GetActiveAnim(PTR(work, 0x1CC)) != 3) {
                if (WORD(work, 0x298) == 1) {
                    ov40_02243E80(work, 1, 0);
                } else {
                    ov40_02243E80(work, 1, 1);
                }
            }
        }
    }
}
