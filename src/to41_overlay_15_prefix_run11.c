#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

s32 ov15_021FBD28(s32 current, s32 maximum, s32 delta) {
    if (delta > 0) {
        if (current == maximum) {
            return 1;
        }
        current += delta;
        if (current > maximum) {
            current = maximum;
        }
    } else {
        if (current == 1) {
            return maximum;
        }
        current += delta;
        if (current <= 0) {
            current = 1;
        }
    }
    return current;
}
