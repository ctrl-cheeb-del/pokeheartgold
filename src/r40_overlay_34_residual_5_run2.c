#include "r40_overlay_34_residual_5_private.h"

int ov34_0225E020(Ov34State *state) {
    u32 x;
    u32 y;
    int hit = TouchscreenHitbox_FindRectAtTouchHeld(ov34_0225E6AC);
    if (hit != -1) {
        if (hit == 0) {
            int count;
            int width;
            int i;
            int lo;
            int hi;
            ov34_0225E5DC(state, NULL);
            System_GetTouchHeldCoords(&x, &y);
            ov34_0225DDB8(PTR_AT(state, 0x1A0), y);
            if (U16_AT(state, 0x284) > 3) {
                count = U16_AT(state, 0x284) - 2;
                width = 0x60 / count;
                i = 0;
                if (count > 0) {
                    u32 touchY = y;
                    lo = i;
                    hi = i;
                    do {
                        if (touchY >= lo + 0x30 && touchY < hi + width + 0x30) {
                            U16_AT(state, 0x288) = i;
                            break;
                        }
                        i++;
                        lo += width;
                        hi += width;
                    } while (i < count);
                }
            }
        } else if (S32_AT(PTR_AT(state, 0x270), 0x348) >= hit && S32_AT(state, 0x1C4) == hit - 1) {
            s32 *entry = (s32 *)((u8 *)state + 0x1FC + (hit - 1) * 0x38);
            if (*entry < 5) {
                (*entry)++;
            }
        }
    } else {
        ov34_0225E5DC(state, (void *)1);
    }
    return hit;
}
