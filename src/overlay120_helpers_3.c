#include "overlay120_helpers_internal.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern const u32 ov120_022601F4[];
extern const u32 ov120_022601F8[];
extern const u32 ov120_022601FC[];
extern const u32 ov120_02260200[];

void ov120_0225F6AC(void *data, u16 start, u16 end, u16 step) {
    U16(data, 0) = start;
    U16(data, 2) = start;
    U16(data, 4) = end - start;
    U16(data, 6) = step;
    U16(data, 8) = 0;
}

void ov120_0225F6BC(void *data) {
    s32 delta;
    u32 angle = U16(data, 8) >> 4;
    U16(data, 0) = (s16)(*(s16 *)((u8 *)data + 2) + ((FX_SinCosTable_[angle * 2] * *(s16 *)((u8 *)data + 4)) >> 12));
    delta = (*(s16 *)((u8 *)data + 6) * 0xffff) / 360;
    U16(data, 8) += delta;
}

void ov120_0225F6FC(void *data, void *callback) {
    PTR(data, 0) = callback;
    U32(data, 4) = 0;
}

int ov120_0225F704(void *data, void *arg) {
    return ((int (*)(void *, void *))PTR(data, 0))(arg, (u8 *)data + 4);
}
