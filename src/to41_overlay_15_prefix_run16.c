#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

s32 ov15_021FD0E8(void *work) {
    if (!TextPrinterCheckActive(U8(work, 0x616))) {
        ov15_021FF004(work);
        return 22;
    }
    return 21;
}
