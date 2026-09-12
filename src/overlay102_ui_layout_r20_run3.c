#include "overlay102_ui_layout_r20_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov102_021EA71C(u8 *work, u8 direction) {
    U8(work, 0x1E4) = 0;
    U8(work, 0x1E5) = direction;
    if (U8(work, 0x1E5) == 1) {
        volatile u16 *reg = (volatile u16 *)0x04000048;
        *reg = (*reg & ~0x3F) | 0x1B;
    }
    Main_SetHBlankIntrCB(ov102_021EA644, work);
}
