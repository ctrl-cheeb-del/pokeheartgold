#include "to45_overlay93_t2_r12_private.h"

u32 ov93_02261744(void *sys, void *work_, void *slot_) {
    u8 *work = work_;
    u8 *slot = slot_;
    s32 bob;
    s32 x;
    s32 y;
    float scale;

    if (U8AT(work, 0xf3) != 0) {
        ManagedSprite_TickNFrames(PAT(slot, 0), 0x2c000 / ov93_02262CC4[U8AT(work, 0xf4) * 4]);
    } else {
        ManagedSprite_SetAnimationFrame(PAT(slot, 0), 0);
    }

    bob = -FX_Mul(GF_SinDegFX32(((0xb4 * U8AT(work, 0xf3)) << FX32_SHIFT) / ov93_02262CC4[U8AT(work, 0xf4) * 4]),
              0xc000)
        / FX32_ONE;

    x = 0x80 + FX_Mul(GF_SinDegFX32(S32AT(work, 0xe4) + S32AT(slot, 0xc)), 0x4c);
    y = 0x62 - FX_Mul(GF_CosDegFX32(S32AT(work, 0xe4) + S32AT(slot, 0xc)), 0x44);

    ManagedSprite_SetPositionXYWithSubscreenOffset(PAT(slot, 0), (s16)x, (s16)(y - 0x18 + bob), 0x160000);
    ManagedSprite_SetPositionXYWithSubscreenOffset(PAT(slot, 8), (s16)x, (s16)y, 0x160000);
    scale = (float)(FX32_ONE - ((-bob / 3) << FX32_SHIFT) / 12) / (float)FX32_ONE;
    ManagedSprite_SetAffineScale(PAT(slot, 8), scale, scale);

    if (U8AT(work, 0xf3) == ov93_02262CC4[U8AT(work, 0xf4) * 4] - 1) {
        ov93_0226249C(sys, slot, slot + 0x30);
    }

    U8AT(slot, 0x15) = (((S32AT(work, 0xe4) + S32AT(slot, 0xc)) >> FX32_SHIFT) % 360 == 180);
    return 1;
}
