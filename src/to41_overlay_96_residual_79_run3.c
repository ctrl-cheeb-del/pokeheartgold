#include "to41_overlay_96_residual_79_private.h"

typedef struct {
    u8 pad[0x158];
    void *unk158;
    void *unk15C;
} WorkA18;

typedef struct {
    u16 a;
    u16 b;
} Rec900;

typedef struct {
    u8 pad[0x194];
    Rec900 arr[3];
} Work900;

typedef struct {
    u8 pad[0x128];
    struct {
        void *gfx;
        void *pltt;
    } objs[3];
    u32 sizes[2];
    u32 plttSizes[2];
} Work454;

/* ================= round 4 ================= */

void probe_050C_c(void *w, int i, int a);

void probe_EFE8_b(void *a, const int (*tbl)[5], int b, int i, Ov96Out *out);

typedef struct Ov96Work6BC {
    u8 pad6BC[0x150];
    void *p150[2];
    void *p158[2];
    u16 h160[2];
    u32 state;
    s32 idx;
} Ov96Work6BC;

BOOL ov96_022006BC(void *wp, int b);

typedef struct Ov96FreePair {
    void *a;
    void *b;
} Ov96FreePair;

typedef struct Ov96FreeWork {
    u8 pad00[0xc];
    u8 window0[0x10];
    u8 window1[0x10];
    void *msgData;
    void *format;
    void *unk34;
    u8 pad38[0x84];
    void *blocks[12];
    u8 padEC[0x3c];
    Ov96FreePair pairs[3];
    u8 pad140[0x30];
    void *strings[3];
} Ov96FreeWork;

fx32 ov96_021FF67C(const VecFx32 *a, const VecFx32 *b, const VecFx32 *c, fx32 r) {
    VecFx32 d;
    fx32 s, t, lenSq, dot, m, u;
    VEC_Subtract(b, a, &d);
    lenSq = VEC_Mag(&d);
    lenSq = lenSq * lenSq;
    dot = VEC_DotProduct(&d, c);
    m = VEC_Mag((VecFx32 *)c);
    s = FX_Sqrt(dot - (m * m - r * r) * lenSq);
    t = FX_Div(s - dot, lenSq);
    u = FX_Div(-(dot + s), lenSq);
    return t > u ? u : t;
}

float ov96_021FF6DC(void *w, int i) {
    if (BYTE(w, 0xa5) != 0) {
        return (float)*((u8 *)w + i * 0x1c + 0x2c);
    }
    if (*(float *)((u8 *)w + i * 0x1c + 0x24) <= 40.0) {
        return (float)*((u8 *)w + i * 0x1c + 0x2d);
    }
    return (float)*((u8 *)w + i * 0x1c + 0x2e);
}

void ov96_021FF72C(const VecFx32 *a, const VecFx32 *b, VecFx32 *out) {
    out->x = a->x + b->x;
    if (FX_Mul(a->y, b->y) >= 0) {
        out->y = a->y + b->y;
    } else {
        out->y = b->y;
    }
}
