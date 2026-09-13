#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

s32 ov15_021FC3E0(void *work) {
    ov15_021FAC48(work);
    return 3;
}

s32 ov15_021FC3EC(void *work) {
    ov15_021FED3C(work);
    ov15_021FD788(work, 0);
    ov15_021FFF24(work);
    sub_020880CC(1, 6);
    U16(PTR(work, 0x234), 0x68) = 2;
    return 0x25;
}
