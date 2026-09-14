#include "overlay49_3d_cleanup_r47.h"

void ov49_0225DA70(Ov49State *state, void *resources) {
    int i;
    int offset;
    u8 *slot;
    u8 *anim;
    void *target;

    slot = state->raw;
    anim = state->raw;
    offset = (i = 0);
    anim += 0x8C;
    for (; i < 4; i++) {
        if (PTR(slot, 0x7C) != NULL) {
            switch (i) {
            case 0:
            case 2:
                target = (u8 *)resources + 0x38 + U8(state, 2) * 0x50 + offset;
                ov49_0225D57C(anim, target, 0x1000);
                break;
            case 1:
            case 3:
                target = (u8 *)resources + 0x38 + U8(state, 2) * 0x50 + offset;
                if (ov49_0225D5A0(anim, target, 0x1000) == 1) {
                    PTR(slot, 0x7C) = NULL;
                    PTR(slot, 0x8C) = NULL;
                }
                break;
            default:
                GF_AssertFail();
                break;
            }
        }
        slot += 4;
        offset += 0x14;
        anim += 4;
    }
}
