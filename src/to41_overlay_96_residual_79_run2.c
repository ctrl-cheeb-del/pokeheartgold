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

BOOL ov96_021FF574(const s32 *point, const s32 *cell) {
    s32 px = point[0];
    s32 py = point[1];
    s32 x = cell[1] << 12;
    s32 y = cell[2] << 12;

    if (x < px && px < x + (1 << 18) && y < py && py < y + (1 << 18)) {
        return TRUE;
    }
    return FALSE;
}
