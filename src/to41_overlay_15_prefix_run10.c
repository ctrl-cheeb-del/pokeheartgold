#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

s32 ov15_021FBC6C(void *work) {
    ov15_021FED3C(work);
    sub_020880CC(1, 6);
    U16(PTR(work, 0x234), 0x68) = 1;
    return 0x25;
}

s32 ov15_021FBC8C(void *work) {
    ov15_021FED3C(work);
    sub_020880CC(1, 6);
    U16(PTR(work, 0x234), 0x68) = 3;
    return 0x25;
}
