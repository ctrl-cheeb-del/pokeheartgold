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

void ov96_021FFAEC(void *w, const VecFx32 *src, void *sprite) {
    VecFx32 v = *src;
    switch (BYTE(w, 8)) {
    case 1:
        v.y -= 0x14000;
        break;
    case 2:
        v.y -= 0x20000;
        break;
    case 3:
        v.y -= 0x28000;
        break;
    default:
        GF_AssertFail();
        break;
    }
    ov96_021EB588(sprite, &v);
}

void ov96_021FFB44(void *w) {
    int v;
    if (BYTE(w, 0xb) == 3) {
        ov96_021EB630((void *)WORD(w, 4), 0x96 * 4);
        return;
    }
    v = 0xa0 - (BYTE(w, 0xa) + 0x20);
    if (v < 0) {
        v = 0;
    }
    ov96_021EB630((void *)WORD(w, 4), 0x1e * (v / 8 + 1) + 3);
}

void ov96_021FFB7C(u8 *w, int a, int b) {
    int v = 0xa8 - a;
    int n;
    if (v < 0) {
        v = 0;
    }
    v = v / 8;
    if (b != 0) {
        n = 0x1e * v + 4;
    } else {
        n = 0x1e * v + 7;
    }
    ov96_021EB630(PTR(w, 0x70), n);
    ov96_021EB630(PTR(w, 0x78), n + 1);
    ov96_021EB630(PTR(w, 0x6c), n + 1);
    ov96_021EB630(PTR(w, 0x74), n + 2);
    {
        int i;
        for (i = 0; i < 3; i++) {
            ov96_021EABA8(PTR(w, 0), n + 2);
            w += 4;
        }
    }
}

void ov96_021FFBD8(void *bgConfig, int v) {
    if (v > 0x110 && v < 0x300) {
        FillBgTilemapRect(bgConfig, 0, 1, 0xa, 3, 2, 0x15, 0x10);
    } else {
        FillBgTilemapRect(bgConfig, 0, 0x20, 0xa, 3, 2, 0x15, 0x10);
    }
    ScheduleBgTilemapBufferTransfer(bgConfig, 0);
}
