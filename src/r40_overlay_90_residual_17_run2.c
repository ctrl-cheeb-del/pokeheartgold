#include "r40_overlay_90_residual_17_private.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

void ov90_0225A1B8(void *work);
void ov90_0225A204(void *dst, void *src);
BOOL ov90_0225A258(const u8 *work, const u8 *values);
u32 ov90_0225A28C(u32 value);
void ov90_0225A2B0(void *, void **, void *, int, void *, u32);

u32 ov90_0225A28C(u32 value) {
    u32 remainder = value % 3;
    u32 quotient = value / 3;
    if (remainder + 1 < 3) {
        remainder++;
    }
    quotient += quotient * 2;
    quotient += remainder;
    return quotient;
}

void ov90_0225A2B0(void *window, void **holder, void *text, int msgNo, void *narc, u32 heapId) {
    AddWindowParameterized(*holder, window, 1, 6, 0xB, 0x14, 0xA, 8, 0x201);
    FillWindowPixelBuffer(window, 0);
    PTR_AT(window, 0x14) = String_New(0x80, heapId);
    ov90_0225927C(text, msgNo);
    ov90_0225928C(text, PTR_AT(window, 0x14), 0x10);
    PTR_AT(window, 0x10) = (void *)msgNo;
    GfGfx_EngineATogglePlanes(1, FALSE);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 7, *holder, 0, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0xA, *holder, 0, 0, 0, FALSE, heapId);
}
