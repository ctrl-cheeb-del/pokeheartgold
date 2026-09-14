#include "global.h"

#include "math_util.h"
#include "to45_overlay85_orbit_transform_r11_private.h"

#define S32(p, o)               (*(s32 *)((u8 *)(p) + (o)))
#define U16(p, o)               (*(u16 *)((u8 *)(p) + (o)))
#define FX_TO_INT(value)        ((value + ((u32)((value) >> 11) >> 20)) >> 12)
#define FX_TO_INT_SIGNED(value) ((s32)((value) + ((u32)((value) >> 11) >> 20)) >> 12)

void ov85_021E78D8(void *work, const VecFx32 *offset) {
    s32 angle = S32(work, 0x1C);
    u16 degrees;

    ov85_021E8530(&angle, S32(work, 0x20));
    degrees = (u16)FX_TO_INT(angle);
    S32(work, 0x44) = S32(work, 0x50) + offset->x + GF_CosDegNoWrap(degrees) * 0x16;
    S32(work, 0x48) = S32(work, 0x54) - (6 << 12) + offset->y;
    S32(work, 0x4C) = S32(work, 0x58) + offset->z + GF_SinDegNoWrap(degrees) * 0x16;
    U16(work, 0x24) = FX_TO_INT_SIGNED(S32(work, 0x2C));
    U16(work, 0x26) = FX_TO_INT_SIGNED(S32(work, 0x30));
    U16(work, 0x28) = FX_TO_INT_SIGNED(S32(work, 0x34));
}
