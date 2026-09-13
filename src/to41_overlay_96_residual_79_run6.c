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

void ov96_022003E8(void *w, const Ov96ParticipantView *e) {
    Ov96PokepicTemplate tmpl;
    int i;
    u8 *q;
    for (i = 0, q = (u8 *)w; i < 3; i++, e++, q += 8) {
        GetMonSpriteCharAndPlttNarcIdsEx(&tmpl, e->species, e->field7, 2, e->kind, (u8)e->field2, e->fieldC);
        PTR(q, 0x128) = sub_0201457C(tmpl.narcID, tmpl.charDataID, WORD(w, 0), e->fieldC, FALSE, 2, e->species);
        PTR(q, 0x12c) = sub_02014450(tmpl.narcID, tmpl.palDataID, WORD(w, 0));
    }
}

void ov96_02200454(void *w, u32 a, u32 b) {
    Work454 *p = (Work454 *)w;
    if (a >= 2) {
        GF_AssertFail();
    }
    if (b >= 3) {
        GF_AssertFail();
    }
    DC_FlushRange(p->objs[b].gfx, 0x32 * 64);
    GXS_LoadOBJ(p->objs[b].gfx, p->sizes[a], 0x32 * 64);
    DC_FlushRange(p->objs[b].pltt, 0x20);
    GXS_LoadOBJPltt(p->objs[b].pltt, p->plttSizes[a], 0x20);
}

void ov96_022004B4(void *w, int i, int j) {
    void *sprite = ov96_021EB5B8(PTR(U8P(w, i * 0x20), 0x48));
    int idx = j + i * 3;
    DC_FlushRange(PTR(PTR(U8P(w, 0xec), idx * 4), 0x14), 0x200);
    GXS_LoadOBJ(PTR(PTR(U8P(w, 0xec), idx * 4), 0x14), i * 0x200 + 0x600, 0x200);
    Sprite_SetPaletteOverride(sprite, *((u8 *)w + idx + 0x11c));
}
