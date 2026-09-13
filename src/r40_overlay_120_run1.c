#include "r40_overlay_120_private.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

int ov120_0225F08C(void *data) {
    int result;
    int halfWidth;
    int halfHeight;
    int x;
    int y;

    if (U8(data, 0x30) == 0) {
        return 1;
    }
    result = ov01_021EFE44(data);
    result |= ov01_021EFE44((u8 *)data + 0x14);
    halfWidth = S32(data, 0) / 2;
    x = S16(data, 0x2C);
    halfHeight = S32(data, 0x14) / 2;
    y = S16(data, 0x2E);
    ov01_021F0960(PTR(data, 0x28), (s16)(y - halfHeight), (s16)(y + halfHeight), (s16)(x - halfWidth), (s16)(x + halfWidth), U8(data, 0x31));
    return result;
}
