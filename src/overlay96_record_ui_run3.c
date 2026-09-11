#include "overlay96_record_ui_private.h"

void ov96_0220BFB4(u8 *e, int anim) {
    s16 y;
    void *spr;
    s16 x;
    x = (s16)(EW38(e).b.h * 64 + 0x48);
    spr = ESPR(e, 2);
    y = 0x28;
    if (ov96_021E8BB0(ov96_021EAA20(EA(e, EW38(e).b.f)))[2] != 0) {
        y -= 0x10;
    }
    ManagedSprite_SetPositionXY(spr, x, y);
    ManagedSprite_SetAnimNoRestart(spr, anim);
    ManagedSprite_SetDrawFlag(spr, 1);
}

void ov96_0220C004(u8 *e, RSlot *s) {
    u32 q;
    if (s->b.t) {
        ManagedSprite_SetAnimNoRestart(ESPR(e, 3), 0x10);
        ManagedSprite_SetDrawFlag(ESPR(e, 3), 1);
    } else if (s->b.r >= 0x32) {
        ov96_0220C8B8(ESPR(e, 3), (u16)s->b.r, 0);
    } else {
        ManagedSprite_SetDrawFlag(ESPR(e, 3), 0);
    }
    q = s->b.q;
    if (q == 0) {
        ov96_0220BFB4(e, 0x1a);
        ManagedSprite_SetDrawFlag(ESPR(e, 3), 0);
        ov96_021EAC5C(EA(e, EW38(e).b.f), 0xc);
        return;
    }
    if (ov96_0220C768(ESPR(e, 2), q << 12, EB(e, EW38(e).b.f) << 12)) {
        ov96_0220BFB4(e, 0x18);
        ov96_021EAC5C(EA(e, EW38(e).b.f), 0);
        return;
    }
    if (s->b.t) {
        ov96_021EAC5C(EA(e, EW38(e).b.f), 8);
        return;
    }
    ManagedSprite_SetDrawFlag(ESPR(e, 2), 0);
    ov96_021EAC5C(EA(e, EW38(e).b.f), 4);
}

void ov96_0220C0DC(u8 *e, RSlot *s) {
    u32 h;
    u32 rem;
    s32 anim;
    if (EW38(e).b.e != s->b.p) {
        rem = s->b.p % 10;
        h = rem >> 1;
        anim = 12 - h;
        if (rem != 0) {
            ManagedSprite_SetAnimNoRestart(ESPR(e, 0), anim);
        } else {
            ManagedSprite_SetAnimNoRestart(ESPR(e, 0), 13);
        }
        ManagedSprite_SetPositionXY(ESPR(e, 1), EW38(e).b.h * 64 + 0x48, h * 3 + 0x30);
        ManagedSprite_SetAnim(ESPR(e, 1), 5);
        ManagedSprite_SetDrawFlag(ESPR(e, 1), 1);
        EW38(e).b.e = s->b.p;
    }
}
