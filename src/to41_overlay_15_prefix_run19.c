#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov15_021FDAD0(void *work) {
    U32(work, 0x11c) = 0;
    U32(work, 0x120) = 0;
    U32(work, 0x124) = -1;
    U16(work, 0x128) = 7;
    U16(work, 0x12a) = 7;
}
