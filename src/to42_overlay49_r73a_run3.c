#include "to42_overlay49_r73a_private.h"

#pragma require_prototypes off

u32 ov49_02267328(void *ctx, void *state) {
    VecFx32 v;
    int i;
    u32 result;

    for (i = 0; i < S8_AT(state, 0x955); i++) {
        ov49_0226789C(ctx, state, i);
    }
    switch (S8_AT(state, 0x954)) {
    case 0:
        ov49_02265668(ctx, state, 0x5A8);
        for (i = 0; i < S8_AT(state, 0x955); i++) {
            ov49_0226786C(ctx, state, i, 4);
        }
        U8_AT(state, 0x954) = 1;
        break;
    case 1:
        ov49_0225919C((void *)U32_AT(state, 8), 1);
        S16_AT(state, 0x956) = 8;
        U8_AT(state, 0x954) = 2;
        break;
    case 2:
        S16_AT(state, 0x956)
        --;
        if (S16_AT(state, 0x956) <= 0) {
            ov49_0225919C((void *)U32_AT(state, 8), 0);
            U8_AT(state, 0x954) = 3;
            S16_AT(state, 0x956) = 0;
            result = ov49_02258E60((void *)U32_AT(state, 8), 6);
            ov49_02259160((void *)U32_AT(state, 8), result);
        }
        break;
    case 3:
        result = ov49_02265434((u8 *)state + 0xA04, S16_AT(state, 0x956));
        S16_AT(state, 0x956)
        ++;
        ov49_02259154((void *)U32_AT(state, 8), &v);
        ov49_022655E0((u8 *)state + 0xA04, &v.x, &v.y, &v.z);
        ov49_02259148((void *)U32_AT(state, 8), &v);
        if (result == 1) {
            S16_AT(state, 0x956) = 0;
            U32_AT(state, 0x958) = v.y;
            ov49_02265668(ctx, state, 0x5C2);
            ov49_02259130((void *)U32_AT(state, 8), 1);
            if ((void *)U32_AT(state, 8) == ov49_02258DAC((void *)U32_AT(ctx, 4))) {
                ov49_0225CC40((void *)U32_AT(ctx, 8), (void *)U32_AT(state, 8));
            }
            return 1;
        }
        break;
    }
    return 0;
}
