#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov15_021FA0D8(void *work) {
    U32(work, 0x348) = 0;
}

void ov15_021FA0E4(void *work, s32 value) {
    u8 *state;
    u8 cur;
    if (value >= 8 && value < 14) {
        state = PTR(work, 0x234);
        cur = U8(state, 0x64);
        U16(state + cur * 12, 8) = value - 8;
    }
}

BOOL ov15_021FA104(void *work, s32 value) {
    if (value == 14 || value == 15) {
        return FALSE;
    }
    if (value <= 7 && (s32)U32(work, 0x644) >= 8 && (s32)U32(work, 0x644) <= 13) {
        return FALSE;
    }
    return TRUE;
}
