#include "global.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern s32 _s32_div_f(s32, s32);
extern void CopyRectToBgTilemapRect(void *, u8, u8, u8, u8, u8, const void *, u8, u8, u8, u8);

void ov96_021F4EF8(u8 *, void *);
void ov96_021F4FD8(int, u8 *);

void ov96_021F4EF8(u8 *work, void *bg) {
    u8 remainder[3];
    u8 quotient[3];
    u8 value;
    u8 part;
    u8 i;

    value = U8(work, 0xe8);
    part = _s32_div_f(value, 100);
    remainder[0] = part % 5 * 4;
    quotient[0] = part / 5 * 8;
    part = (u8)(_s32_div_f(value, 10) - 10 * part);
    remainder[1] = part % 5 * 4;
    quotient[1] = part / 5 * 8;
    part = value % 10;
    remainder[2] = part % 5 * 4;
    quotient[2] = part / 5 * 8;

    for (i = 0; i < 3; i++) {
        CopyRectToBgTilemapRect(bg, 6, i * 4 + 3, 7, 4, 8, (u8 *)*(void **)(work + 0xb0) + 0xc, remainder[i], quotient[i], 0x14, 0x10);
    }
    U8(work, 0xe9) = U8(work, 0xe8);
}

void ov96_021F4FD8(int base, u8 *data) {
    u16 count = U32(data, 8) / 2;
    u16 *tiles = (u16 *)(data + 0xc);
    int i;

    for (i = 0; i < count; i++) {
        u16 tile = *tiles;
        u16 low = tile & 0x0fff;
        u8 high = tile - low;
        *tiles++ = high + (u16)(low + base);
    }
}
