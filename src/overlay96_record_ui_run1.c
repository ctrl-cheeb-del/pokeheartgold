#include "overlay96_record_ui_private.h"

u16 ov96_0220B79C(R22Scene *p) {
    if (!p) {
        GF_AssertFail();
    }
    return p->f44.b.a;
}

u8 ov96_0220B7B4(R22Scene *p) {
    if (!p) {
        GF_AssertFail();
    }
    return p->f40.b.g;
}

u32 ov96_0220B7CC(R22Scene *p) {
    u32 v, r;
    if (!p) {
        GF_AssertFail();
    }
    r = 1;
    v = p->f40.b.h;
    if (v != 0 && (v != 1 || p->f44.b.c < 2)) {
        r = 0;
    }
    return r;
}

void *ov96_0220B7F4(u32 heapId, void *a1, void *a2, void *course, void *arg5) {
    u32 narc[0xf];
    u32 tmp[3];
    void *w;
    u8 *entry;
    u32 self;
    s32 i;
    s32 k;
    u32 *q;
    self = (u8)ov96_021E5F24(course);
    ReadWholeNarcMemberByIdPair(narc, 0xaa, 5);
    w = Heap_Alloc(heapId, 0xc8);
    MI_CpuFill8(w, 0, 0xc8);
    U32(w, 0) = heapId;
    PTR(w, 4) = a1;
    PTR(w, 8) = a2;
    PTR(w, 0xc) = course;
    PTR(w, 0x10) = arg5;
    ov96_0220C844(arg5, self);
    entry = (u8 *)w + 0x14;
    for (i = 0; i < 4; i++) {
        if (i == self) {
            continue;
        }
        for (k = 0, q = tmp; k < 3; k++, q++) {
            *q = *(u32 *)((u8 *)narc + ((u8 *)ov96_021E60D8(course, i, k))[3] * 4 + 0x14);
        }
        ov96_0220BE28(entry, a1, a2, PTR(w, 0x10), (u8)i, course, tmp);
        entry += 0x3c;
    }
    return w;
}

void ov96_0220B8A0(u8 *p) {
    s32 i;
    u8 *r;
    u8 *q;
    s32 j;
    if (!p) {
        GF_AssertFail();
    }
    q = p;
    for (j = 0; j < 3; j++, q += 0x3c) {
        for (i = 0, r = q; i < 6; i++, r += 4) {
            if (PTR(r, 0x30)) {
                Sprite_DeleteAndFreeResources(PTR(r, 0x30));
            }
        }
    }
    Heap_Free(p);
}

void ov96_0220B8D8(u8 *p) {
    s32 i;
    u8 *q;
    for (i = 0, q = p + 0x14; i < 3; i++, q += 0x3c) {
        ov96_0220C40C(q);
    }
}

void ov96_0220B8F0(u8 *p) {
    s32 i;
    u8 *r;
    u8 *q;
    s32 j;
    for (j = 0, q = p + 0x14; j < 3; j++, q += 0x3c) {
        ov96_021EAC5C(PTR(q + ((U32(q, 0x38) << 7) >> 30) * 4, 4), 0xc);
        if (PTR(q, 0x34)) {
            SysTask_Destroy(PTR(q, 0x34));
            PTR(q, 0x34) = NULL;
        }
        for (i = 0, r = q; i < 6; i++, r += 4) {
            ManagedSprite_SetAnimateFlag(PTR(r, 0x1c), 0);
        }
    }
}

void ov96_0220B940(void *p, int f) {
    if (f == 0 && !ManagedSprite_IsAnimated(PTR(p, 0x10))) {
        ManagedSprite_SetAnim(PTR(p, 0x10), 1);
    }
}

void ov96_0220B95C(R22Scene *p) {
    p->f44.b.c++;
    if (p->f44.b.c >= 10) {
        ov96_0220C578(p, 0);
    }
}

void ov96_0220B988(R22Scene *p) {
    if (p->slot[p->f40.b.g].b.k >= 8) {
        ov96_0220C578(p, 0);
    }
}
