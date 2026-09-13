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

void ov96_021FFD4C(void *w) {
    AddWindow((void *)WORD(w, 0), (u8 *)w + 4, ov96_0221C5C4);
    BG_FillCharDataRange((void *)WORD(w, 0), 3, 0, 1, 0);
    LoadFontPal0(0, 0x1e0, (enum HeapID)WORD(w, 0x14));
}

void ov96_021FFD80(void *w, int a, int b) {
    void *msgData;
    void *fmt;
    void *str;
    int n;
    FillWindowPixelBuffer(U8P(w, 4), 0);
    n = (int)(b * 10 / 1024.0);
    if (n > 9) {
        GF_AssertFail();
    }
    msgData = NewMsgDataFromNarc(1, 0x1b, 0x135, WORD(w, 0x14));
    fmt = MessageFormat_New(WORD(w, 0x14));
    BufferIntegerAsString(fmt, 0, a, 2, 2, 1);
    BufferIntegerAsString(fmt, 1, n, 1, 2, 1);
    str = ReadMsgData_ExpandPlaceholders(fmt, msgData, 0xa2, WORD(w, 0x14));
    AddTextPrinterParameterizedWithColor(U8P(w, 4), 4, str, 0, 0, 0xff, 0xf0e00, NULL);
    String_Delete(str);
    MessageFormat_Delete(fmt);
    DestroyMsgData(msgData);
    CopyWindowToVram(U8P(w, 4));
}

void ov96_021FFE38(int a, int b, int c) {
    if (a >= 0 && a < 0x100) {
        sub_0200606C((u16)b, c ? 3 : 4);
    }
}

void ov96_021FFE5C(void *w, int i, int c) {
    u8 *dst = (u8 *)w + 0x644;
    u8 *p = (u8 *)w + i * 0xd4;
    u8 r = 0;
    u8 v = *(p + *(p + 0xbb) * 0x1c + 0x60);
    if (*(p + 0xcd) != 0) {
        r = 3;
    } else if (*(p + 0xd9) != 0) {
        r = 3;
    } else if (v == 2) {
        r = 3;
    } else if (v == 1) {
        r = 1;
    }
    if (c == 0) {
        dst[i] = r;
        return;
    }
    if (WORD((u8 *)w + i * 0xc, 0x380) != 0) {
        if (r <= 1) {
            dst[i] = 2;
            return;
        }
        if (r == 3) {
            dst[i] = 4;
            return;
        }
        GF_AssertFail();
        return;
    }
    if (WORD((u8 *)w + i * 0xc, 0x384) == 0) {
        dst[i] = r;
    }
}

void ov96_021FFEE8(void *p) {
    void *q = ov96_021E8A20((u8 *)PokeathlonCourse_GetDataCopyArea(p) + 0xf0);
    void *heap = PokeathlonCourse_GetHeapAllocPtr4(p);
    u8 idx = (u8)ov96_021E5F24(p);
    u8 v = (u8)(*((u8 *)q + idx + 0x10) & 0x7f);
    u16 t = HALF(q, idx * 2);
    if (v > 0x3c) {
        v = 0x3c;
    }
    ov96_021E8318(p, (u16)(t + (v << 10)));
    ov96_021FFD80(heap, v, t);
}

void *ov96_021FFF3C(u32 heapId, void *a2, void *a3) {
    void *w = Heap_Alloc(heapId, 0x1a0);
    int i;
    u8 *q;
    u8 *p;
    MI_CpuFill8(w, 0, 0x1a0);
    WORD(w, 0) = heapId;
    WORD(w, 8) = (u32)a2;
    WORD(w, 4) = (u32)a3;
    ov96_02200DF8(w);
    PTR(w, 0x2c) = NewMsgDataFromNarc(1, 0x1b, 0x135, heapId);
    PTR(w, 0x30) = MessageFormat_New(heapId);
    for (i = 0, p = w; i < 3; i++, p += 4) {
        PTR(p, 0x170) = String_New(0xb, heapId);
    }
    q = PokeathlonCourse_GetParticipantUnk04(a3, ov96_021E5F24(a3));
    {
        int m;
        for (m = 0, p = w; m < 3; m++) {
            CopyU16ArrayToString(PTR(p, 0x170), (const u16 *)(q + 0x12));
            q += 0x28;
            p += 4;
        }
    }
    ov96_02200BD8(w, 1);
    ov96_02200C40(w);
    HALF(w, 0x160) = 1;
    HALF(w, 0x162) = 2;
    return w;
}

void ov96_021FFFE8(void *arg) {
    Ov96FreeWork *work = arg;
    int i;

    for (i = 0; i < 3; i++) {
        Heap_Free(work->pairs[i].a);
        Heap_Free(work->pairs[i].b);
    }
    for (i = 0; i < 12; i++) {
        Heap_Free(work->blocks[i]);
    }
    Heap_Free(work->unk34);
    for (i = 0; i < 3; i++) {
        String_Delete(work->strings[i]);
    }
    MessageFormat_Delete(work->format);
    DestroyMsgData(work->msgData);
    RemoveWindow(work->window0);
    RemoveWindow(work->window1);
    Heap_Free(work);
}

void ov96_02200068(void *w) {
    GfGfxLoader_LoadCharData(0xb2, 6, PTR(w, 8), 6, 0, 0, 0, WORD(w, 0));
    GfGfxLoader_LoadScrnData(0xb2, 7, PTR(w, 8), 6, 0, 0, 0, WORD(w, 0));
    GfGfxLoader_LoadScrnData(0xb2, 8, PTR(w, 8), 5, 0, 0, 0, WORD(w, 0));
    WORD(w, 0x34) = (u32)GfGfxLoader_GetScrnData(0xb2, 9, 0, U8P(w, 0x38), WORD(w, 0));
    GfGfxLoader_GXLoadPal(0xb2, 5, 4, 0, 0x40, WORD(w, 0));
}

void ov96_022000E4(int unused, void *p) {
    u32 v[2];
    u32 *q = v;
    int i;
    v[0] = ov96_0221C728[4];
    v[1] = ov96_0221C728[5];
    for (i = 0; i < 2; i++, q++) {
        ov96_021EB2BC(p, 0x5d, 9, *q, 2);
        ov96_021EB2F4(p, 0x5d, 6, *q, 2, 1);
        ov96_021EB334(p, 0x5d, 0xa, *q);
        ov96_021EB36C(p, 0x5d, 0xa, *q);
    }
    ov96_021EB2BC(p, 0xb2, 0xd, 0x65, 2);
    ov96_021EB2F4(p, 0xb2, 0xa, 0x65, 2, 5);
    ov96_021EB334(p, 0xb2, 0xc, 0x65);
    ov96_021EB36C(p, 0xb2, 0xb, 0x65);
}
