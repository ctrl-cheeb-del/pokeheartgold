#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

s32 ov15_021FD3AC(void *work) {
    if ((s32)ov15_021FA650(work) == 1) {
        return 2;
    }
    return 0x1a;
}

s32 ov15_021FD3C0(void *work) {
    ov15_021FED3C(work);
    ov15_021FD788(work, 0);
    ov15_021FFF24(work);
    sub_020880CC(1, 6);
    U16(PTR(work, 0x234), 0x68) = 4;
    return 0x25;
}

BOOL ov15_021FD3F0(u32 pocket, u32 item) {
    if (pocket == 4 || (item >= 0x5f && item < 0x63)) {
        return TRUE;
    }
    return FALSE;
}
