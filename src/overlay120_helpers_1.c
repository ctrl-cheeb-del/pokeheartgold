#include "overlay120_helpers_internal.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern const u32 ov120_022601F4[];
extern const u32 ov120_022601F8[];
extern const u32 ov120_022601FC[];
extern const u32 ov120_02260200[];

void *ov120_0225F020(u32 heap) {
    void *p = Heap_Alloc(heap, 0x34);
    memset(p, 0, 0x34);
    return p;
}

void ov120_0225F038(void *p) {
    Heap_Free(p);
}

void ov120_0225F040(void *data, u16 x, u16 y, int shared, void *target, void *a, void *b, void *c, void *d, u8 palette) {
    if (U8(data, 0x30) != 0) {
        GF_AssertFail();
    }
    ov01_021EFE34(data, a, c, shared);
    ov01_021EFE34((u8 *)data + 0x14, b, d, shared);
    PTR(data, 0x28) = target;
    U16(data, 0x2c) = x;
    U16(data, 0x2e) = y;
    U8(data, 0x31) = palette;
    U8(data, 0x30) = 1;
}
