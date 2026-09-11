#include "overlay96_record_ui_private.h"

void ov96_0220C3E0(u8 *e) {
    EW38(e).b.b = 0;
    EW38(e).b.c = 0;
    EW38(e).b.d = 1;
    ETASK(e) = SysTask_CreateOnMainQueue(ov96_0220C15C, e, 1);
}

void ov96_0220C40C(u8 *e) {
    RSlot *arr;
    u32 g;
    arr = (RSlot *)ov96_021E8A20(PokeathlonCourse_GetDataCopyArea(ECOURSE(e)) + 0xf0);
    g = EW38(e).b.g;
    if (EW38(e).b.f == arr[g].b.s) {
        ov96_0220C004(e, &arr[g]);
    } else {
        ManagedSprite_SetDrawFlag(ESPR(e, 2), 0);
        ManagedSprite_SetDrawFlag(ESPR(e, 3), 0);
    }
    ov96_0220C0DC(e, &arr[g]);
    if (EW38(e).b.d == 0 && EW38(e).b.f != arr[g].b.s) {
        if (arr[g].b.s >= 3) {
            GF_AssertFail();
        }
        EW38(e).b.a = arr[g].b.s;
        ov96_0220C3E0(e);
    }
}

void ov96_0220C490(void **out, void *ss, void *sm) {
    SprTmpl t = { 0 };
    s32 i;
    int py;
    if (!ss) {
        GF_AssertFail();
    }
    if (!sm) {
        GF_AssertFail();
    }
    t.resIdList[0] = 0x2712;
    t.resIdList[1] = 0x2713;
    t.resIdList[2] = 0x2712;
    t.resIdList[3] = 0x2712;
    t.vram = 1;
    t.x = 0x88;
    t.y = 0x70;
    t.drawPriority = 0x1b;
    t.bgPriority = 2;
    out[0] = SpriteSystem_NewSpriteWithYOffset(ss, sm, &t, 0x100000);
    ManagedSprite_SetAnimateFlag(out[0], 1);
    for (i = 0, py = 0x30; i < 2; i++, py += 0x58, out++) {
        t.resIdList[0] = 0x2713 + i;
        t.resIdList[1] = 0x2714 + i;
        t.resIdList[2] = 0x2712;
        t.resIdList[3] = 0x2712;
        t.vram = 2;
        t.x = 0x28;
        t.y = (s16)py;
        t.drawPriority = i + 1;
        out[5] = SpriteSystem_NewSpriteWithYOffset(ss, sm, &t, 0x100000);
        ManagedSprite_SetAnimateFlag(out[5], 1);
    }
}

void ov96_0220C54C(void *p, int i, u8 a, u8 b, int e) {
    u32 t[4];
    void *ctx;
    void *spr;
    ctx = PTR(p, 0);
    spr = SPRA(p, i);
    ov96_021E6168(PTR(p, 0xc), a, b, t);
    ov96_021EEBE4(spr, t, e, 0, ctx);
}

void ov96_0220C578(R22Scene *p, int mode) {
    s32 n;
    switch (mode) {
    case 2:
        ov96_021E8228(p->ctx, (u8)ov96_021E5F24(p->ctx), (u8)p->f40.b.g, 1, 1);
        p->slot[p->f40.b.g].b.k = 0;
        p->f40.b.i = 0;
        break;
    case 3:
        ov96_021E8228(p->ctx, (u8)ov96_021E5F24(p->ctx), (u8)p->f40.b.g, 7, 1);
        p->f44.b.d = 0;
        n = p->f44.b.a - 10;
        if (n > 0x64) {
            n = 0x64;
        } else if (n < 0) {
            n = 0;
        }
        p->f44.b.a = n;
        if (p->f44.b.e) {
            ov96_0220C7FC(p);
        }
        p->f40.b.g = p->f40.b.g + 1;
        if (p->f40.b.g >= 3) {
            p->f40.b.g = 0;
        }
        break;
    }
    p->f40.b.h = mode;
    p->f44.b.s = 0;
    p->f44.b.c = 0;
}

void ov96_0220C680(R22Scene *p) {
    if (p->f40.b.h == 3) {
        return;
    }
    if (p->f44.b.e) {
        p->f40.b.j++;
        if (p->f40.b.j >= 0x5a) {
            ov96_0220C7FC(p);
        }
    } else if (p->f44.b.a != 0) {
        p->f40.b.j++;
        if (p->f40.b.j >= 2) {
            p->f40.b.j = 0;
            p->f44.b.a--;
        }
        if (p->f44.b.a >= 0x32) {
            ov96_0220C8B8(p->spr[1], p->f44.b.a, 1);
        }
    } else {
        ManagedSprite_SetDrawFlag(p->spr[1], 0);
    }
}

void ov96_0220C714(R22Scene *p, int f) {
    if (p->f44.b.e) {
        GF_AssertFail();
    }
    if (f) {
        p->f44.b.a += 0x1e;
    }
    if (p->f44.b.a > 0x64) {
        p->f44.b.a = 0x64;
    }
    if (p->f44.b.a >= 0x64) {
        ov96_0220C7C4(p);
    }
}

BOOL ov96_0220C768(void *spr, fx32 a, fx32 b) {
    s32 t;
    s32 v = FX_Div(a, b) * 100 >> 12;
    if (v <= 0x28) {
        t = (100 - v) * 2;
        ManagedSprite_SetAnimSpeed(spr, FX32_CONST(t) / 100);
        return TRUE;
    }
    return FALSE;
}

void ov96_0220C7C4(R22Scene *p) {
    p->f44.b.e = 1;
    p->f40.b.j = 0;
    ManagedSprite_SetAnim(p->spr[1], 0x10);
    ManagedSprite_SetAnimSpeed(p->spr[1], 0x1000);
    PlaySE(0x8BF);
}

void ov96_0220C7FC(R22Scene *p) {
    p->f44.b.e = 0;
    p->f40.b.j = 0;
    p->f44.b.a = 0;
    p->slot[p->f40.b.g].b.k = 10;
    ManagedSprite_SetDrawFlag(p->spr[1], 0);
}

void ov96_0220C844(void *a, u32 self) {
    void *o;
    u32 base;
    s32 i;
    int pos;
    s32 j;
    for (j = 0, base = 0, pos = 0x48; j < 4; j++) {
        if (j == self) {
            continue;
        }
        for (i = 0; i < 3; i++) {
            o = ov96_021EAA04(a, (u8)(i + base));
            ov96_021EABA8(o, 0x20);
            ov96_021EAF94(o, pos, 0x30);
            ov96_021EAC0C(o, 2);
            ov96_021EAB38(o, (u8)(i == 0));
            ov96_021EAB74(o, 0);
        }
        base += 3;
        pos += 0x40;
    }
}

void ov96_0220C8B8(void *s, u16 v, int f) {
    s32 sp = 0;
    s32 d = v - 0x32;
    if (d) {
        sp = (d << 12) / 10;
    }
    if (sp < 0x99A) {
        sp = 0x99A;
    }
    ManagedSprite_SetAnimSpeed(s, sp);
    ManagedSprite_SetAnimNoRestart(s, 0x11);
    if (f && !ManagedSprite_GetDrawFlag(s)) {
        PlaySE(0x8C0);
    }
    ManagedSprite_SetDrawFlag(s, 1);
}

void ov96_0220C90C(void *p, int i, s16 x, s16 y) {
    ManagedSprite_SetPositionXYWithSubscreenOffset(SPRA(p, i), x, y, 0x100000);
    ManagedSprite_SetPositionXYWithSubscreenOffset(SPRB(p, i), x, y - 0x18, 0x100000);
}
