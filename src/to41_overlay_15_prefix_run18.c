#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov15_021FD774(void *work, u32 state) {
    void *input = PTR(PTR(work, 0x234), 0x78);
    if (input != NULL) {
        MenuInputStateMgr_SetState(input, state);
    }
}
