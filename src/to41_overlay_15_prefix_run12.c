#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

s32 ov15_021FBF98(void *work) {
    ov15_021FEEA4(work);
    ov15_02200428(work);
    ov15_021FFF24(work);
    ov15_021FF834(work);
    ov15_021FD788(work, 0);
    return 8;
}
