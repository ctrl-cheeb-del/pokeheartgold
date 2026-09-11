#include "global.h"

#define U8P(p, o) ((u8 *)(p) + (o))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern void GF_AssertFail(void);
extern void ov96_021EB52C(void *p, int a, int b);
extern void ov96_021EB564(void *p, int v);
extern void *ov96_021EB5B8(void *p);
extern void ov96_021EB630(void *p, int v);
extern void ov96_022004B4(void *w, int i, int j);
extern void Sprite_SetAnimCtrlSeq(void *sprite, int seq);
extern void Sprite_SetDrawPriority(void *sprite, int priority);

typedef struct {
    u16 a;
    u16 b;
} Rec900;

typedef struct {
    u8 pad[0x194];
    Rec900 arr[3];
} Work900;

typedef struct {
    u8 pad[0x158];
    void *unk158;
    void *unk15C;
} WorkA18;

typedef struct Ov96P20 {
    void *p;
    u8 p20pad[0x1c];
} Ov96P20;
typedef struct Ov96B20 {
    u8 b;
    u8 b20pad[0x1f];
} Ov96B20;
#define A48(w) ((Ov96P20 *)((u8 *)(w) + 0x48))
#define A4C(w) ((Ov96P20 *)((u8 *)(w) + 0x4c))
#define A50(w) ((Ov96P20 *)((u8 *)(w) + 0x50))
#define A58(w) ((Ov96B20 *)((u8 *)(w) + 0x58))

BOOL ov96_02200900(void *w, u32 n);
void ov96_02200950(void *w, int i, int a, int b, int c);
void ov96_02200A18(void *w, int a, int b);
void ov96_02200A64(void *w, int v);
void ov96_02200B04(void *w, int n);

BOOL ov96_02200900(void *w, u32 n) {
    Work900 *p = (Work900 *)w;
    u32 i;
    if (n == 0 || n >= 4) {
        GF_AssertFail();
    }
    i = n - 1;
    p->arr[i].a += 0x20;
    if (p->arr[i].a >= 0x58) {
        p->arr[i].a = 0;
        p->arr[i].b++;
    }
    if (p->arr[i].b >= 3) {
        p->arr[i].b = 0;
        return TRUE;
    }
    return FALSE;
}

void ov96_02200950(void *w, int i, int a, int b, int c) {
    u8 *f = (u8 *)w + 0x16c;
    if (a != f[i]) {
        f[i] = (u8)a;
        ov96_022004B4(w, i, a);
    }
    if (b != 0) {
        ov96_021EB52C(A48(w)[i].p, 1, 0);
        ov96_021EB52C(A50(w)[i].p, 1, 1);
        ov96_021EB52C(A4C(w)[i].p, 1, 0);
    } else {
        ov96_021EB52C(A48(w)[i].p, 1, 1);
        ov96_021EB52C(A50(w)[i].p, 1, 0);
        switch (c) {
        case 1:
            if (c != A58(w)[i].b) {
                ov96_021EB52C(A4C(w)[i].p, 1, 1);
                ov96_021EB564(A4C(w)[i].p, 8);
            }
            break;
        case 2:
            if (c != A58(w)[i].b) {
                ov96_021EB52C(A4C(w)[i].p, 1, 1);
                ov96_021EB564(A4C(w)[i].p, 9);
            }
            break;
        default:
            ov96_021EB52C(A4C(w)[i].p, 1, 0);
            break;
        }
    }
    A58(w)
    [i].b
        = (u8)c;
}

void ov96_02200A18(void *w, int a, int b) {
    if (a == 1) {
        ov96_021EB52C(((WorkA18 *)w)->unk158, TRUE, TRUE);
    } else {
        ov96_021EB52C(((WorkA18 *)w)->unk158, TRUE, FALSE);
    }
    if (b == 1) {
        ov96_021EB52C(((WorkA18 *)w)->unk15C, TRUE, TRUE);
    } else {
        ov96_021EB52C(((WorkA18 *)w)->unk15C, TRUE, FALSE);
    }
}

void ov96_02200A64(void *w, int v) {
    u8 a;
    u8 b;
    a = v / 30;
    b = (u8)(v % 30);
    b = 100 * b / 30;
    Sprite_SetAnimCtrlSeq(PTR(w, 0x17c), (u8)(a / 60) + 1);
    a = a % 60;
    Sprite_SetAnimCtrlSeq(PTR(w, 0x184), (u8)(a / 10) + 1);
    Sprite_SetAnimCtrlSeq(PTR(w, 0x188), (u8)(a % 10) + 1);
    Sprite_SetAnimCtrlSeq(PTR(w, 0x190), (u8)(b / 10) + 1);
}

void ov96_02200B04(void *w, int n) {
    u8 buf[4];
    u8 *p;
    int i;
    u8 k;
    for (i = 0, p = w; i < 6; i++) {
        Sprite_SetDrawPriority(PTR(p, 0x17c), 2);
        p += 4;
    }
    for (i = 0, p = w; i < 2; i++) {
        Sprite_SetDrawPriority(ov96_021EB5B8(PTR(p, 0x150)), 2);
        p += 4;
    }
    k = 1;
    for (i = 0; i < 4; i++) {
        if (i == n) {
            buf[0] = (u8)i;
        }
    }
    for (i = 0; i < 4; i++) {
        if (buf[0] != i) {
            buf[k++] = (u8)i;
        }
    }
    for (i = 0; i < 4; i++) {
        ov96_021EB630(PTR(U8P(w, buf[i] * 0x20), 0x4c), i * 2 + 3);
        ov96_021EB630(PTR(U8P(w, buf[i] * 0x20), 0x50), i * 2 + 3);
        ov96_021EB630(PTR(U8P(w, buf[i] * 0x20), 0x48), i * 2 + 4);
        ov96_021EB630(PTR(U8P(w, buf[i] * 0x20), 0x54), i + 0xb);
    }
}
