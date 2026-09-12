#include "global.h"

#include "overlay96_event_behavior_r14_private.h"

void ov96_0221A57C(void *p, int which) {
    R123Unary fn = ov96_0221D9C8[which];
    u8 i;
    if (fn != NULL) {
        for (i = 0; i < 4; i++) {
            u8 *r = ov96_021E94EC(p, i);
            U16(r, 0xa) = (u16)fn((u16)U32(r, 0xc));
        }
    } else {
        GF_AssertFail();
    }
}

void ov96_0221A5B8(void *p, int which) {
    if (ov96_0221D9C8[which] == NULL) {
        ov96_0221A730(p);
    } else {
        GF_AssertFail();
    }
}
