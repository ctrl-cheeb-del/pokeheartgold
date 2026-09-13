#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov15_021FE154(void *work) {
    u16 i;
    for (i = 0; i < 8; i++) {
        RemoveWindow((u8 *)work + 4 + i * 16);
    }
    ov15_021FE3E0(work);
    ov15_021FE1D0(work);
}
