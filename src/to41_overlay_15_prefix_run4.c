#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov15_021FA008(void *work) {
    u32 i;
    u8 *ptr = work;
    for (i = 0; i < 0xa5; i++) {
        PTR(ptr, 0x350) = String_New(0x12, 6);
        ptr += 4;
    }
}

void ov15_021FA028(void *work) {
    u32 i;
    u8 *ptr = work;
    for (i = 0; i < 0xa5; i++) {
        String_Delete(PTR(ptr, 0x350));
        ptr += 4;
    }
}
