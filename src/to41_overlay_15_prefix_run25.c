#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov15_021FE868(void *work) {
    ClearWindowTilemapAndScheduleTransfer((u8 *)work + 0x14);
}

void ov15_021FE874(void *work) {
    PTR(work, 0x5e8) = NewString_ReadMsgData(PTR(work, 0x2f0), 39);
    PTR(work, 0x5ec) = NewString_ReadMsgData(PTR(work, 0x2f0), 38);
}

void ov15_021FE8A4(void *work) {
    String_Delete(PTR(work, 0x5e8));
    String_Delete(PTR(work, 0x5ec));
}
