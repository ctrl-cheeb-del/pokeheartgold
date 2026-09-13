#include "to42_overlay_45_thumb_residual_24_private.h"

void ov45_0222C79C(void *a, u16 *event, void *c, u8 *work) {
    int id;
    if (work[0x1CA] != 0) {
        id = ov45_0222EC68(a);
        if (*(u16 *)(work + 0x1C4) == id) {
            if ((u16)(event[1] + 0xFFFE) <= 1) {
                work[0x1C6] = event[1];
                *(u16 *)(work + 0x1C8) = event[0];
                ov45_0222BE54(work + 0x1C0);
                return;
            }
            ov45_0222BD5C(work + 0x1C0);
            return;
        }
        if (id == -1) {
            ov45_0222BD5C(work + 0x1C0);
        }
    }
}

void ov45_0222C800(void *a, void *b, void *c, u8 *work) {
    u32 offset = 0x1C6;
    if (work[offset] != 0) {
        int id = ov45_0222EC68(a);
        if (*(u16 *)(work + 0x1C4) == id) {
            ov45_0222BD4C(work + 0x1C0);
        }
    }
}
