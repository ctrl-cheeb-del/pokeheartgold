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
void ov18_021EFC9C(void *p, u32 entry, u32 index, s32 x);
void ov18_021EFD00(void *p, u32 height, u32 index);
void ov18_021EFDB4(void *p, u32 weight, u32 index);
void ov18_021EFE70(void *p, u32 index);
void ov18_021EFEC4(void *p);
void ov18_021F006C(void *p, u32 index);

void ov18_021EFFEC(void *p) {
    sub_02019B08(PTR(p, 8), 0xf);
    ov18_021EE44C(p, 0x5f, 0);
    ov18_021EE44C(p, 0x60, 1);
    ov18_021EE520(p, U8_(p, 0x185d) + 0x61, U16(p, 0x102c));
    ov18_021EE520(p, U8_(p, 0x185d) + 0x63, U16(p, 0x102e));
    ov18_021F006C(p, 0x5f);
    ov18_021F006C(p, 0x60);
    ov18_021F006C(p, U8_(p, 0x185d) + 0x61);
    ov18_021F006C(p, U8_(p, 0x185d) + 0x63);
    U8_(p, 0x185d) = 1 ^ U8_(p, 0x185d);
}
