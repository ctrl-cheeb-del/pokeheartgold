#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov15_021FA070(void) {
}

s32 ov15_021FA074(void *work) {
    u8 *state = PTR(work, 0x234);
    u8 cur = U8(state, 0x64);
    s32 n = U8(state + cur * 12, 13) - (s16)U16(state + cur * 12, 10);
    if (n > 6) {
        n = 6;
    }
    return n;
}
