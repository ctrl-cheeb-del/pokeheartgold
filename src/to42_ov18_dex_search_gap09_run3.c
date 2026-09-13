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
void ov18_021EF848(void *p);
void ov18_021EF91C(void *p);
void ov18_021EF9B4(void *p);
void ov18_021EFA50(void *p);
void ov18_021EFB88(void *p);
void ov18_021EFBE8(void *p, u32 index);
void ov18_021EFC3C(void *p, u32 index);
void ov18_021EFEC4(void *p);
void ov18_021EFFEC(void *p);
void ov18_021F006C(void *p, u32 index);

void ov18_021EFC9C(void *p, u32 entry, u32 index, s32 x) {
    u8 *base = (u8 *)p + 0xc;
    u32 offset = index * 0x10;
    FillWindowPixelBuffer(base + offset, 0);
    if (x == -1) {
        x = GetWindowWidth(base + offset) * 8 / 2;
    }
    ov18_021F9648(base + offset, PTR(p, 0x65c), ((const u16 *)ov18_021F9DC0)[entry], x, 0, 4, 0x20100, 2);
}

void ov18_021EFD00(void *p, u32 height, u32 index) {
    u32 value;
    u8 *base;
    u32 offset;
    if (height == 999) {
        value = 1188;
    } else {
        value = (10000 * height / 254 + 5) / 10;
    }
    base = (u8 *)p + 0xc;
    offset = index * 0x10;
    FillWindowPixelBuffer(base + offset, 0);
    BufferIntegerAsString(PTR(p, 0x660), 0, value / 12, 3, 0, 1);
    BufferIntegerAsString(PTR(p, 0x660), 1, value % 12, 2, 2, 1);
    ov18_021EE3AC(p, PTR(p, 0x65c), index, 0xaf, GetWindowWidth(base + offset) * 8 / 2, 0, 4, 0x20100, 2);
}

void ov18_021EFDB4(void *p, u32 weight, u32 index) {
    u32 value;
    u8 *base;
    u32 offset;
    if (weight == 9999) {
        value = 99990;
    } else {
        value = (220462 * weight + 50000) / 100000;
    }
    base = (u8 *)p + 0xc;
    offset = index * 0x10;
    FillWindowPixelBuffer(base + offset, 0);
    BufferIntegerAsString(PTR(p, 0x660), 0, value / 10, 4, 0, 1);
    BufferIntegerAsString(PTR(p, 0x660), 1, value % 10, 1, 2, 1);
    ov18_021EE3AC(p, PTR(p, 0x65c), index, 0x26, GetWindowWidth(base + offset) * 8 / 2, 0, 4, 0x20100, 2);
}

void ov18_021EFE70(void *p, u32 index) {
    u8 *base = (u8 *)p + 0xc;
    u32 offset = index * 0x10;
    FillWindowPixelBuffer(base + offset, 0);
    ov18_021F9648(base + offset, PTR(p, 0x65c), U32(p, 0x1888) + 0x41, GetWindowWidth(base + offset) * 8 / 2, 0, 4, 0x20100, 2);
}
