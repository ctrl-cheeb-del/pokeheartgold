#include "overlay96_course_feedback_r71u6_private.h"

void ov96_021FBCB8(void *sys, u8 *p) {
    void *sprite;

    if (p[9] < 4) {
        sprite = ov96_021EB5B8(PAT(p, 0x4C));
        p[9]++;

        if (p[9] == 1) {
            sub_0200606C(0x8A6, ov96_0221DC2C[p[0x18]]);
            sub_020061D0(ov96_0221DC2C[p[0x18]], ov96_0221DC28[p[0x18]]);
            ov96_021EAC0C(PAT(p, 0x24), 5);
            Sprite_SetAnimCtrlSeq(sprite, 1);
        } else if (p[9] == 4) {
            sub_0200606C(0x8A9, ov96_0221DC2C[p[0x18]]);
            sub_020061D0(ov96_0221DC2C[p[0x18]], ov96_0221DC28[p[0x18]]);
            ov96_021EAC0C(PAT(p, 0x24), 6);
            Sprite_SetAnimCtrlSeq(sprite, 2);
        } else if ((u8)(p[9] + 0xFE) <= 1) {
            sub_0200606C(0x8A7, ov96_0221DC2C[p[0x18]]);
            sub_020061D0(ov96_0221DC2C[p[0x18]], ov96_0221DC28[p[0x18]]);
        }

        if (F32AT(p, 0xC) < 10.0) {
            F32AT(p, 0xC) = F32AT(p, 0x50) + ov96_0221C444[p[9] - 1];
        } else {
            GF_AssertFail();
        }
    }

    ov96_021E8228(sys, (u8)ov96_021E5F24(sys), p[0x18], 6, 1);
}
