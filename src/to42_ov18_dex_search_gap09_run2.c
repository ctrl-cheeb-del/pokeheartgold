#include "sol_r9_ov18_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8_(p, o) (*(u8 *)((u8 *)(p) + (o)))

typedef struct Dims18 {
    u16 height;
    u16 weight;
} Dims18;

void *GfGfxLoader_GetCharDataFromOpenNarc(void *narc, s32 memberNo, BOOL isCompressed, void **ppCharData, u32 heapID);
void BlitBitmapRect(void *window, void *src, u16 srcX, u16 srcY, u16 srcWidth, u16 srcHeight, u16 destX, u16 destY, u16 destWidth, u16 destHeight, u16 colorKey);
void Heap_Free(void *ptr);
u8 GetWindowWidth(void *window);
u8 GetWindowHeight(void *window);
u8 GetWindowX(void *window);
u8 GetWindowY(void *window);
u16 GetWindowBaseTile(void *window);
void CopyWindowPixelsToVram_TextMode(void *window);
u16 *sub_02019B08(void *, u32);
void BufferIntegerAsString(void *fmt, u32 field, u32 value, u32 digits, u32 mode, u32 charset);
void ov18_021EE3AC(void *, void *, u32, u32, s32, u32, u32, u32, u32);
u16 ov18_021E7698(u32);

void ov18_021EF5D8(void *);
void ov18_021EF764(void *);
void ov18_021EF848(void *);
void ov18_021EF91C(void *);
void ov18_021EF9B4(void *);
void ov18_021EFA50(void *);
void ov18_021EFBE8(void *, u32);
void ov18_021EFC3C(void *, u32);
void ov18_021EFC9C(void *, u32, u32, s32);
void ov18_021EFD00(void *, u32, u32);
void ov18_021EFDB4(void *, u32, u32);
void ov18_021EFE70(void *, u32);
void ov18_021EFEC4(void *);
void ov18_021EFFEC(void *);
void ov18_021F006C(void *, u32);

extern const u8 ov18_021F9DC0[];
extern const u8 ov18_021F9DE4[];

void ov18_021EF388(void *p, u32 index, u32 message);
void ov18_021EF45C(void *p);
void ov18_021EF528(void *p);
void ov18_021EF5D8(void *p);
void ov18_021EF764(void *p);
void ov18_021EFC3C(void *p, u32 index);
void ov18_021EFC9C(void *p, u32 entry, u32 index, s32 x);
void ov18_021EFD00(void *p, u32 height, u32 index);
void ov18_021EFDB4(void *p, u32 weight, u32 index);
void ov18_021EFE70(void *p, u32 index);
void ov18_021EFEC4(void *p);
void ov18_021EFFEC(void *p);
void ov18_021F006C(void *p, u32 index);

void ov18_021EF848(void *p) {
    u32 i;
    u8 *window;
    const u16 *q;
    ov18_021E613C(p, 0);
    FillWindowPixelBuffer((u8 *)p + 0x2cc, 0);
    ov18_021F9648((u8 *)p + 0x2cc, PTR(p, 0x65c), 0x1c, 0x1c, 0, 0, 0x20100, 2);
    q = (const u16 *)(ov18_021F9DE4 + 7 * 8 + 2);
    i = 0x2f;
    window = (u8 *)p + 0x2fc;
    for (; i <= 0x40; i++) {
        FillWindowPixelBuffer(window, 0);
        ov18_021F9648(window, PTR(p, 0x65c), q[-0x2f], 0x20, 0, 4, 0x20100, 2);
        window += 0x10;
        q++;
    }
    ov18_021EF388(p, 0x11, 0x27);
    ov18_021EF388(p, 0x13, 0x28);
    ov18_021EFC9C(p, U32(p, 0x1870), 0x2d, 0x1d);
    ov18_021EFC9C(p, U32(p, 0x1874), 0x2e, 0x23);
    i = 0x2c;
    window = (u8 *)p + 0x2cc;
    for (; i <= 0x40; i++) {
        ScheduleWindowCopyToVram(window);
        window += 0x10;
    }
}

void ov18_021EF91C(void *p) {
    u32 i;
    u8 *window;
    ov18_021E613C(p, 0);
    FillWindowPixelBuffer((u8 *)p + 0x44c, 0);
    ov18_021F9648((u8 *)p + 0x44c, PTR(p, 0x65c), 0x1d, 0x14, 0, 0, 0x20100, 2);
    ov18_021EF388(p, 0x11, 0x27);
    ov18_021EF388(p, 0x13, 0x28);
    ov18_021EFD00(p, ((Dims18 *)PTR(p, 0x1850))[U32(p, 0x1878)].height, 0x45);
    ov18_021EFD00(p, ((Dims18 *)PTR(p, 0x1850))[U32(p, 0x187c)].height, 0x46);
    i = 0x44;
    window = (u8 *)p + 0x44c;
    for (; i <= 0x46; i++) {
        ScheduleWindowCopyToVram(window);
        window += 0x10;
    }
}

void ov18_021EF9B4(void *p) {
    u32 i;
    u8 *window;
    ov18_021E613C(p, 0);
    FillWindowPixelBuffer((u8 *)p + 0x47c, 0);
    ov18_021F9648((u8 *)p + 0x47c, PTR(p, 0x65c), 0x1e, 0x18, 0, 0, 0x20100, 2);
    ov18_021EF388(p, 0x11, 0x27);
    ov18_021EF388(p, 0x13, 0x28);
    ov18_021EFDB4(p, ((Dims18 *)PTR(p, 0x1850))[U32(p, 0x1880)].weight, 0x48);
    ov18_021EFDB4(p, ((Dims18 *)PTR(p, 0x1850))[U32(p, 0x1884)].weight, 0x49);
    i = 0x47;
    window = (u8 *)p + 0x47c;
    for (; i <= 0x49; i++) {
        ScheduleWindowCopyToVram(window);
        window += 0x10;
    }
}

void ov18_021EFA50(void *p) {
    u32 i;
    u8 *window;
    ov18_021E613C(p, 0);
    FillWindowPixelBuffer((u8 *)p + 0x4ac, 0);
    FillWindowPixelBuffer((u8 *)p + 0x4cc, 0);
    FillWindowPixelBuffer((u8 *)p + 0x4dc, 0);
    FillWindowPixelBuffer((u8 *)p + 0x4ec, 0);
    FillWindowPixelBuffer((u8 *)p + 0x4fc, 0);
    ov18_021F9648((u8 *)p + 0x4ac, PTR(p, 0x65c), 0x1f, 0x18, 0, 0, 0x20100, 2);
    ov18_021F9648((u8 *)p + 0x4cc, PTR(p, 0x65c), 0x41, 0x1c, 0, 4, 0x20100, 2);
    if (U32(p, 0x1860) == 1) {
        ov18_021F9648((u8 *)p + 0x4dc, PTR(p, 0x65c), 0x42, 0x1c, 0, 4, 0x20100, 2);
    }
    ov18_021F9648((u8 *)p + 0x4ec, PTR(p, 0x65c), 0x43, 0x1c, 0, 4, 0x20100, 2);
    ov18_021F9648((u8 *)p + 0x4fc, PTR(p, 0x65c), 0x44, 0x1c, 0, 4, 0x20100, 2);
    ov18_021EF388(p, 0x11, 0x27);
    ov18_021EF388(p, 0x13, 0x28);
    ov18_021EFE70(p, 0x4b);
    i = 0x4a;
    window = (u8 *)p + 0x4ac;
    for (; i <= 0x4f; i++) {
        ScheduleWindowCopyToVram(window);
        window += 0x10;
    }
}

void ov18_021EFB88(void *p) {
    ov18_021E613C(p, 0);
    FillWindowPixelBuffer((u8 *)p + 0x50c, 0);
    ov18_021F9648((u8 *)p + 0x50c, PTR(p, 0x65c), 0x20, 0x18, 0, 0, 0x20100, 2);
    ov18_021EF388(p, 0x11, 0x27);
    ov18_021EF388(p, 0x13, 0x28);
    ScheduleWindowCopyToVram((u8 *)p + 0x50c);
}

void ov18_021EFBE8(void *p, u32 index) {
    u8 *base = (u8 *)p + 0xc;
    u32 offset = index * 0x10;
    FillWindowPixelBuffer(base + offset, 0);
    ov18_021F9648(base + offset, PTR(p, 0x65c), U32(p, 0x1868) + 0x29, GetWindowWidth(base + offset) * 8 / 2, 0, 4, 0x20100, 2);
}
