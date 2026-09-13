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

void ov80_0223509C(void *ctx, void *party, s32 count) {
    u8 *p = ctx;
    s32 skipped = 0;
    u8 index = *(u16 *)(p + 0x20) % count;
    s32 i;
    for (i = 0; i < count; i++) {
        void *mon = Party_GetMonByIndex(party, index);
        u32 species = GetMonData(mon, 0xA, NULL);
        if (species == 0xF || species == 0x48) {
            index++;
            skipped++;
            if (index >= (u32)count) {
                index = 0;
            }
        } else {
            u32 value = LCRandom() % 4 + 2;
            SetMonData(mon, 0xA0, &value);
            break;
        }
    }
    if (skipped >= count) {
        p[0x1F] = 1;
    }
}

void ov80_02235118(void *ctx, void *party, s32 count) {
    u8 *p = ctx;
    s32 skipped = 0;
    u8 index = *(u16 *)(p + 0x20) % count;
    s32 i;
    for (i = 0; i < count; i++) {
        void *mon = Party_GetMonByIndex(party, index);
        u32 a = GetMonData(mon, 0xB1, NULL);
        u32 b = GetMonData(mon, 0xB2, NULL);
        u32 species = GetMonData(mon, 0xA, NULL);
        if (a == 0xF || b == 0xF || species == 0x28) {
            index++;
            skipped++;
            if (index >= (u32)count) {
                index = 0;
            }
        } else {
            u32 value = 0x20;
            SetMonData(mon, 0xA0, &value);
            break;
        }
    }
    if (skipped >= count) {
        p[0x1F] = 1;
    }
}

void ov80_022351AC(void *ctx, void *party, s32 count) {
    u32 rank = ov80_02238498(ctx);
    const u16 *table;
    s32 divisor;
    u16 value;
    s32 i;
    if (rank < 3) {
        table = ov80_0223DCA0[0];
        divisor = 8;
    } else if (rank < 6) {
        table = ov80_0223DCA0[1];
        divisor = 20;
    } else {
        table = ov80_0223DCA0[2];
        divisor = 10;
    }
    value = table[*(u16 *)((u8 *)ctx + 0x20) % divisor];
    for (i = 0; i < count; i++) {
        SetMonData(Party_GetMonByIndex(party, i), 6, &value);
    }
}

void ov80_02235208(void *ctx, void *party, s32 count) {
    u32 rank = ov80_02238498(ctx);
    const u16 *table;
    s32 divisor;
    u16 value;
    s32 i;
    if (rank < 3) {
        table = ov80_0223DCA0[3];
        divisor = 11;
    } else if (rank < 6) {
        table = ov80_0223DCA0[4];
        divisor = 13;
    } else {
        table = ov80_0223DCA0[5];
        divisor = 11;
    }
    value = table[*(u16 *)((u8 *)ctx + 0x20) % divisor];
    for (i = 0; i < count; i++) {
        SetMonData(Party_GetMonByIndex(party, i), 6, &value);
    }
}

void ov80_02235264(void *ctx, void *party, s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        void *mon = Party_GetMonByIndex(party, i);
        u32 level = GetMonData(mon, 0xA1, NULL) + 3;
        u32 exp;
        if (level > 100) {
            GF_AssertFail();
            level = 100;
        }
        exp = GetMonExpBySpeciesAndLevel(GetMonData(mon, 5, NULL), level);
        SetMonData(mon, 8, &exp);
        CalcMonLevelAndStats(mon);
    }
}

void ov80_022352BC(void *ctx) {
    *(u32 *)((u8 *)ctx + 0x14) = 1001;
}

void ov80_022352C8(void *ctx) {
    *(u32 *)((u8 *)ctx + 0x14) = 1;
}

void ov80_022352D0(void *ctx) {
    *(u32 *)((u8 *)ctx + 0x14) = 7;
}

void ov80_022352D8(void *ctx) {
    *(u32 *)((u8 *)ctx + 0x14) = 4;
}

void ov80_022352E0(void *ctx) {
    *(u32 *)((u8 *)ctx + 0x14) = 9;
}

void ov80_022352E8(void *ctx) {
    *(u32 *)((u8 *)ctx + 0x14) = 1002;
}

void ov80_022352F4(void *ctx) {
    u8 *p = ctx;
    if (p[0x1C] < 7) {
        p[0x1C]++;
    }
}

void ov80_02235300(void *ctx) {
    u8 *p = ctx;
    if (p[0x1C] != 0) {
        p[0x1C]--;
    }
}

void ov80_0223530C(void *ctx) {
    ((u8 *)ctx)[0x12] = 1;
}

void ov80_02235314(void *ctx) {
}

void ov80_02235318(void *ctx) {
}

void ov80_0223531C(void *ctx) {
}

void ov80_02235320(void *ctx) {
}

u32 ov80_02235324(const void *ctx) {
    const u8 *p = ctx;
    u32 mode = p[0x10];
    u32 round = *(const u16 *)(p + 0x1A);
    u32 result;
    if (mode <= 1) {
        result = round >= 8 ? 6 : ov80_0223C01C[round];
    } else {
        result = round >= 8 ? 0x11 : ov80_0223C028[round];
    }
    if (mode == 0) {
        u16 value = *(const u16 *)(p + 0x18);
        if (value == 0x15 || value == 0x31) {
            result = 0x14;
        }
    }
    return result;
}

void ov80_02235364(void *unused, void *dstParty, u32 srcIndex, u32 dstIndex) {
    u16 species = GetMonData(Party_GetMonByIndex(unused, srcIndex), 6, NULL);
    SetMonData(Party_GetMonByIndex(dstParty, dstIndex), 6, &species);
}
