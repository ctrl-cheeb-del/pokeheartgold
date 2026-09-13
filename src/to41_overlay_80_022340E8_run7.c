#include "to41_overlay_80_022340E8_private.h"

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

void ov80_02234E50(void *ctx, u32 state, u32 value) {
    switch (state) {
    case 0:
        ov80_0222BA7C(ctx);
        break;
    case 1:
        ov80_0222BAE0(ctx);
        break;
    case 2:
        ov80_0222BB54(ctx);
        break;
    case 3:
        ov80_0222BC48(ctx, value);
        break;
    case 4:
        ov80_0222BC94(ctx, value);
        break;
    case 5:
        ov80_0222BCE0(ctx);
        break;
    }
}

void ov80_02234E98(void *ctx, u32 state) {
    u8 *p = ctx;
    void *party;
    u32 count;
    if (state < 9) {
        party = *(void **)(p + 0x74);
        count = BattleArcade_GetOpponentMonCount(p[0x10], 1);
    } else {
        party = *(void **)(p + 0x70);
        count = BattleArcade_GetMonCount(p[0x10], 1);
    }
    ov80_0223DCB8[state](ctx, party, count);
}

void ov80_02234ECC(void *ctx, void *party, s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        void *mon = Party_GetMonByIndex(party, i);
        u32 hp = GetMonData(mon, 0xA4, NULL);
        u32 value = (u32)((double)hp * 1.2);
        value -= hp;
        value = hp - value;
        SetMonData(mon, 0xA3, &value);
    }
}
