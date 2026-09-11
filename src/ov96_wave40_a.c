#include "ov96_wave40_a_private.h"
void ov96_021F30C4(void *a, void *b) {
    int i;
    for (i = 0; i < 8; i++, a = (u8 *)a + 0x10) {
        PTR(a, 0xc) = ov96_021EB4F4(b, 0x65, 2);
        void *s = ov96_021EB5B8(PTR(a, 0xc));
        Sprite_SetOamMode(s, 1);
        Sprite_SetDrawPriority(s, 0x64);
    }
}
u8 ov96_021F30F8(u8 a, int b) {
    u8 lo, x;
    int n, c;
    if (a == 15) {
        return 0;
    }
    if (a < 1) {
        c = 0;
    } else if (a < 6) {
        c = 1;
    } else if (a < 10) {
        c = 2;
    } else {
        c = 3;
    }
    if (b == 1) {
        lo = 1;
        n = 5;
    } else if (b == 2) {
        lo = 6;
        n = 4;
    } else {
        lo = 10;
        n = 5;
    }
    if (b == c) {
        u32 rnd;
        GF_ASSERT(a >= lo);
        rnd = LCRandom() % (n - 1);
        x = (u8)(a - lo + 1);
        x = (u8)(x + rnd);
        x = (u8)(x % (u32)n);
        return (u8)(x + lo);
    }
    return (u8)(lo + LCRandom() % n);
}
int ov96_021F3180(int a, int b, int c, u8 *out, u16 limit) {
    u8 i;
    u32 ret;
    if (a == 15) {
        return 0;
    }
    i = 0;
    ret = 0;
    for (; i < 4; i++) {
        u8 *base = (u8 *)ov96_0221DBC8[a];
        u8 *p = base + i * 8;
        u32 id = *(u32 *)p;
        if (!id) {
            break;
        }
        {
            u16 *q = (u16 *)ov96_0221DBB8[id - 1];
            if (ov96_021F32FC(b, c, U16(p, 4), U16(p, 6), q[0])) {
                ret = (u8)q[1];
                *out = i;
                break;
            }
        }
    }
    return ret;
}
void ov96_021F31F0(void *p, int idx) {
    volatile int saved = idx;
    int i = 0;
    u8 *r = (u8 *)ov96_0221DBC8[saved];
    for (; i < 4; i++, r += 8) {
        if (*(u32 *)r) {
            void *sprite;
            VecFx32 v;
            {
                u8 *e = (u8 *)p + U32(p, 0x80) * 16;
                GF_ASSERT(*(u32 *)e != 1);
                *(u32 *)e = 1;
                U32(e, 8) = saved;
                PTR(e, 4) = r;
            }
            sprite = ov96_021EB5B8(PTR((u8 *)p + U32(p, 0x80) * 16, 0xc));
            ov96_021EB52C(PTR((u8 *)p + U32(p, 0x80) * 16, 0xc), 1, 1);
            Sprite_SetAnimCtrlSeq(sprite, *(u32 *)r - 1);
            v.z = 0;
            v.x = U16(r, 4) << 12;
            v.y = U16(r, 6) << 12;
            Sprite_SetMatrix(sprite, &v);
            {
                s32 next = *(volatile s32 *)((u8 *)p + 0x80) + 1;
                U32(p, 0x80) = next % 8;
            }
        }
    }
}
void ov96_021F3298(void *p, int x) {
    int i;
    for (i = 0; i < 8; i++, p = (u8 *)p + 0x10) {
        if (x == U32(p, 8)) {
            U32(p, 8) = 15;
            U32(p, 4) = 0;
            U32(p, 0) = 0;
            ov96_021EB52C(PTR(p, 0xc), 0, 0);
        }
    }
}
int ov96_021F32C4(int x) {
    int r = 0;
    switch (x) {
    case 1:
        r = 1;
        break;
    case 2:
        r = 2;
        break;
    case 3:
        r = 3;
        break;
    case 5:
        r = 4;
        break;
    default:
        GF_ASSERT(FALSE);
    }
    return r;
}
int ov96_021F32FC(int ax, int ay, int bx, int by, u16 lim) {
    VecFx32 a, b;
    a.x = ax << 12;
    a.y = ay << 12;
    a.z = 0;
    b.x = bx << 12;
    b.y = by << 12;
    b.z = 0;
    VEC_Subtract(&a, &b, &a);
    if ((lim << 12) > VEC_Mag(&a)) {
        return 1;
    }
    return 0;
}
int ov96_021F333C(int x, void *out) {
    int i;
    u8 count;
    int off;
    int tableoff;
    count = 0;
    i = count;
    off = count;
    tableoff = x << 2;
    for (; i < 4; i++, off += 8, out = (u8 *)out + 8) {
        u8 *base = *(u8 *volatile *)((u8 *)ov96_0221DBC8 + tableoff);
        u8 *p = base + off;
        u32 id = *(u32 *)p;
        if (!id) {
            U32(out, 0) = 0;
            U16(out, 4) = 0;
            U16(out, 6) = 0;
        } else {
            u16 *q = *(u16 *volatile *)((u8 *)ov96_0221DBB8 + id * 4 - 4);
            U32(out, 0) = q[0];
            U16(out, 4) = U16(p, 4);
            U16(out, 6) = U16(p, 6);
            count = (u8)(count + 1);
        }
    }
    return count;
}
void *ov96_021F3390(int heap, u8 a, int b) {
    SolR37Work *p = Heap_Alloc(heap, 0x4ec);
    MI_CpuFill8(p, 0, 0x4ec);
    p->f4e4 = a;
    p->f4ea = 4 - a;
    p->f4e9 = p->f4ea;
    if (b == 0) {
        p->f4e7 = 20;
    } else {
        p->f4e7 = 10;
    }
    p->f4e6 = p->f4e7;
    return p;
}
void ov96_021F33E0(void *p, int i, void *a, void *b, void *c, void *d, void *e, void *f) {
    SolR37Slot *slots = (SolR37Slot *)p;
    slots[i].a = a;
    slots[i].idx = (s32)b;
    slots[i].sprite = c;
    slots[i].b = d;
    slots[i].state = -1;
    slots[i].slot = i;
    slots[i].e = f;
    if (i / 3 >= U8(p, 0x4e9)) {
        slots[i].f = e;
    } else {
        slots[i].f = 0;
    }
}
