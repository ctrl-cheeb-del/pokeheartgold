/* overlay_96_residual_96 -- replacement for asm/overlay_96_residual_96_unmatched_2.o
   Single function: ov96_0220BE28 (396 bytes, EXACT against the frozen original.o). */
#include "overlay96_pokeathlon_record_ui_unmatched2_private.h"

void ov96_0220BE28(u8 *e, void *a1, void *a2, void *a3, u8 a4, void *course, u32 *tmp) {
    s32 n;
    s32 x;
    u32 v;
    MI_CpuFill8(e, 0, 0x3c);
    v = a4;
    EW38(e).b.g = v;
    ECOURSE(e) = course;
    EW38(e).b.h = v;
    if (EW38(e).b.g > ov96_021E5F24(course)) {
        EW38(e).b.h = EW38(e).b.h - 1;
    }
    for (n = 0; n < 3; n++) {
        EA(e + n * 4, 0) = ov96_021EAA04(a3, (u8)(n + EW38(e).b.h * 3));
        EB(e + n * 4, 0) = tmp[n];
    }
    ((RSlot *)ov96_021E8A20(PokeathlonCourse_GetDataCopyArea(course) + 0x50 + v * 0x28))->b.q = tmp[0];
    x = EW38(e).b.h * 64 + 0x48;
    ESPR(e, 0) = ov96_0220D13C(a1, a2, x, 0x38, 0xc, 0x1d);
    ESPR(e, 1) = ov96_0220D13C(a1, a2, x, 0x38, 5, 0x1c);
    ManagedSprite_SetDrawFlag(ESPR(e, 1), 0);
    ESPR(e, 3) = ov96_0220D13C(a1, a2, x, 0x28, 0x10, 0x1f);
    ManagedSprite_SetAffineOverwriteMode(ESPR(e, 3), 1);
    ManagedSprite_SetAffineScale(ESPR(e, 3), 0.7f, 0.7f);
    ManagedSprite_SetDrawFlag(ESPR(e, 3), 0);
    ESPR(e, 2) = ov96_0220D13C(a1, a2, x, 0x28, 0x18, 0x1f);
    ManagedSprite_SetDrawFlag(ESPR(e, 2), 0);
    ESPR(e, 4) = ov96_0220D13C(a1, a2, x, 0x28, 0xe, 0x1e);
    ManagedSprite_SetDrawFlag(ESPR(e, 4), 0);
    ESPR(e, 5) = ov96_0220D13C(a1, a2, x, 0x28, 0x1b, 0x1e);
    ManagedSprite_SetDrawFlag(ESPR(e, 5), 0);
}
