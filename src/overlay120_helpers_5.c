#include "overlay120_helpers_internal.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern const u32 ov120_022601F4[];
extern const u32 ov120_022601F8[];
extern const u32 ov120_022601FC[];
extern const u32 ov120_02260200[];

void ov120_0225FBAC(void *a, void *b) {
    ov120_0225FBC4(a, b, 1);
}

void ov120_0225FBB8(void *a, void *b) {
    ov120_0225FBC4(a, b, 0);
}
