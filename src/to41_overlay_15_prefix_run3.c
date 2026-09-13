#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov15_021F9D8C(void *msgData, void *dest, u32 msgId) {
    ReadMsgDataIntoString(msgData, msgId, dest);
}

void ov15_021F9D9C(void *msgData, void *dest, u32 itemId) {
    ReadMsgDataIntoString(msgData, TMHMGetMove(itemId), dest);
}
