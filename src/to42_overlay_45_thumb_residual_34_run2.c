#include "global.h"

typedef struct FWork {
    u8 data[0x600];
} FWork;

extern u32 ov45_0222F7B0(u32);
extern void ov45_0222FA40(FWork *, u32);
extern void ov45_0222FA74(FWork *, s32, u32);
extern s32 ov45_0222FB5C(FWork *, s32, s32);
void ov45_0222FB84(FWork *, u32);

#define U16(p, o) (*(u16 *)((p)->data + (o)))
#define U32(p, o) (*(u32 *)((p)->data + (o)))

void ov45_0222FB84(FWork *work, u32 state) {
    s32 i;
    u32 value = ov45_0222F7B0(state);
    ov45_0222FA40(work, 1);
    for (i = 0; i < U16(work, 0x11e); i++) {
        s32 key = ov45_0222FB5C(work, i, 0);
        if (key != -1 && value == U32((FWork *)(work->data + 12 * i), 0x34)) {
            ov45_0222FA74(work, key, 1);
        }
    }
}
