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
void ov18_021EF764(void *p);
void ov18_021EF848(void *p);
void ov18_021EF91C(void *p);
void ov18_021EF9B4(void *p);
void ov18_021EFA50(void *p);
void ov18_021EFB88(void *p);
void ov18_021EFBE8(void *p, u32 index);
void ov18_021EFC3C(void *p, u32 index);
void ov18_021EFC9C(void *p, u32 entry, u32 index, s32 x);
void ov18_021EFD00(void *p, u32 height, u32 index);
void ov18_021EFDB4(void *p, u32 weight, u32 index);
void ov18_021EFE70(void *p, u32 index);
void ov18_021EFEC4(void *p);
void ov18_021EFFEC(void *p);
void ov18_021F006C(void *p, u32 index);

void ov18_021EF45C(void *p) {
    u32 i;
    u8 *window;
    ov18_021E613C(p, 0);
    FillWindowPixelBuffer((u8 *)p + 0x14c, 0);
    FillWindowPixelBuffer((u8 *)p + 0x15c, 0);
    FillWindowPixelBuffer((u8 *)p + 0x16c, 0);
    FillWindowPixelBuffer((u8 *)p + 0x17c, 0);
    FillWindowPixelBuffer((u8 *)p + 0x18c, 0);
    FillWindowPixelBuffer((u8 *)p + 0x19c, 0);
    FillWindowPixelBuffer((u8 *)p + 0x1ac, 0);
    ov18_021EF1E4(p, 0x14);
    ov18_021EF220(p, 0x15);
    ov18_021EF25C(p, 0x16);
    ov18_021EF298(p, 0x17);
    ov18_021EF2D4(p, 0x18);
    ov18_021EF310(p, 0x19);
    ov18_021EF34C(p, 0x1a);
    ov18_021EF388(p, 0x11, 0x23);
    ov18_021EF388(p, 0x12, 0x24);
    ov18_021EF388(p, 0x13, 0x25);
    i = 0x14;
    window = (u8 *)p + 0x14c;
    for (; i <= 0x1a; i++) {
        ScheduleWindowCopyToVram(window);
        window += 0x10;
    }
}

void ov18_021EF528(void *p) {
    u32 i;
    u8 *window;
    ov18_021EFBE8(p, 0x1b);
    ov18_021EFC3C(p, 0x1c);
    ov18_021EFC9C(p, U32(p, 0x1870), 0x1d, 0x1d);
    ov18_021EFC9C(p, U32(p, 0x1874), 0x1e, 0x1d);
    ov18_021EFD00(p, ((Dims18 *)PTR(p, 0x1850))[U32(p, 0x1878)].height, 0x1f);
    ov18_021EFD00(p, ((Dims18 *)PTR(p, 0x1850))[U32(p, 0x187c)].height, 0x20);
    ov18_021EFDB4(p, ((Dims18 *)PTR(p, 0x1850))[U32(p, 0x1880)].weight, 0x21);
    ov18_021EFDB4(p, ((Dims18 *)PTR(p, 0x1850))[U32(p, 0x1884)].weight, 0x22);
    ov18_021EFE70(p, 0x23);
    i = 0x1b;
    window = (u8 *)p + 0x1bc;
    for (; i <= 0x23; i++) {
        ScheduleWindowCopyToVram(window);
        window += 0x10;
    }
}

void ov18_021EF5D8(void *p) {
    u32 i;
    u8 *window;
    ov18_021E613C(p, 0);
    FillWindowPixelBuffer((u8 *)p + 0x24c, 0);
    FillWindowPixelBuffer((u8 *)p + 0x26c, 0);
    FillWindowPixelBuffer((u8 *)p + 0x27c, 0);
    FillWindowPixelBuffer((u8 *)p + 0x28c, 0);
    FillWindowPixelBuffer((u8 *)p + 0x29c, 0);
    FillWindowPixelBuffer((u8 *)p + 0x2ac, 0);
    FillWindowPixelBuffer((u8 *)p + 0x2bc, 0);
    ov18_021F9648((u8 *)p + 0x24c, PTR(p, 0x65c), 0x1a, 0x2c, 0, 0, 0x20100, 2);
    ov18_021F9648((u8 *)p + 0x26c, PTR(p, 0x65c), 0x29, 0x2c, 0, 4, 0x20100, 2);
    ov18_021F9648((u8 *)p + 0x27c, PTR(p, 0x65c), 0x2a, 0x2c, 0, 4, 0x20100, 2);
    ov18_021F9648((u8 *)p + 0x28c, PTR(p, 0x65c), 0x2b, 0x2c, 0, 4, 0x20100, 2);
    ov18_021F9648((u8 *)p + 0x29c, PTR(p, 0x65c), 0x2c, 0x2c, 0, 4, 0x20100, 2);
    ov18_021F9648((u8 *)p + 0x2ac, PTR(p, 0x65c), 0x2d, 0x2c, 0, 4, 0x20100, 2);
    ov18_021F9648((u8 *)p + 0x2bc, PTR(p, 0x65c), 0x2e, 0x2c, 0, 4, 0x20100, 2);
    ov18_021EF388(p, 0x11, 0x27);
    ov18_021EF388(p, 0x13, 0x28);
    ov18_021EFBE8(p, 0x25);
    i = 0x24;
    window = (u8 *)p + 0x24c;
    for (; i <= 0x2b; i++) {
        ScheduleWindowCopyToVram(window);
        window += 0x10;
    }
}
