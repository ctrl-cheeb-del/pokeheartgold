#include "to42_overlay15_r16_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

typedef struct Ov15PocketEntry {
    u8 filler[10];
    s16 cursor;
} Ov15PocketEntry;

typedef struct Ov15PocketState {
    Ov15PocketEntry entries[8];
    u8 filler[4];
    u8 current;
} Ov15PocketState;

s32 ov15_021FC784(void *work) {
    if (!TextPrinterCheckActive(U8(work, 0x616))) {
        if ((U32(gSystem, 0x48) & 3) || U16(gSystem, 0x64)) {
            Ov15PocketState *state;
            ClearFrameAndWindow2((u8 *)work + 0x34, TRUE);
            ClearWindowTilemapAndScheduleTransfer((u8 *)work + 0x34);
            state = PTR(work, 0x234);
            ov15_021FF364(work, state->entries[state->current].cursor, -1, 0);
            return 14;
        }
    }
    return 15;
}
