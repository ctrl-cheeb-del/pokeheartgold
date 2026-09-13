#include "r40_overlay_40_residual_28_private.h"

#define PTR(p, off) (*(void **)((u8 *)(p) + (off)))

void ov40_0223615C(void *p, const u32 *state) {
    void *inner = PTR(p, 0x860);

    if (*state != 1) {
        PTR(inner, 0x2E4) = ov39_02227E8C(ov40_0223D540(p), (u8 *)inner + 0x23C, 5);
    }
}

void ov40_02236184(void *p, int index) {
    void *inner = PTR(p, 0x860);
    void *entry;

    PTR(inner, 0x2ED8) = sub_020314A4(0x6D);
    entry = (u8 *)inner + index * 4;
    ov39_022271C0(PTR(entry, 0x38C), PTR(inner, 0x2ED8));
}

void ov40_022361B0(void *p) {
    sub_020314BC(PTR(PTR(p, 0x860), 0x2ED8));
}
