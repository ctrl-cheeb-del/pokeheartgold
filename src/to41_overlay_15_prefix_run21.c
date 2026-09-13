#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov15_021FDD54(void *anim) {
    s32 value = U32(anim, 0) + 0x1000;
    if (value < (U16(PTR(anim, 8), 4) << 12)) {
        U32(anim, 0) = value;
    } else {
        U32(anim, 0) = 0;
    }
}
