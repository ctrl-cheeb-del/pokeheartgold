#include "to47_overlay49_periodic_effects_r78_internal.h"

void ov49_02268B0C(void *p, u32 tick) {
    u8 *work = p;
    if (tick % 14 != 0) {
        return;
    }
    {
        u32 i;
        const u8 *value;
        int result;
        value = ov49_0226A8B4;
        i = 0;
        do {
            int flag;
            int active = 0;
            if ((i & 3) == ov49_0226A894[WORD(work, 0xC)][0]) {
                flag = 1;
                active = 1;
            } else if ((i & 3) == ov49_0226A894[WORD(work, 0xC)][1]) {
                flag = 0;
                active = 1;
            }
            if (active == 1) {
                if (i < 0x11) {
                    result = ov49_0225E85C(PTR(work, 4), *value, flag, 0x1000);
                    if (result != 1) {
                        GF_AssertFail();
                    }
                } else {
                    result = 0;
                }
            } else {
                result = 1;
            }
            value++;
            i++;
        } while (result == 1);
    }
    WORD(work, 0xC) = (WORD(work, 0xC) + 1) & 3;
}

void ov49_02268B90(void *p, u32 tick) {
    Ov49List list;
    u32 id;
    u32 i;
    if (tick % 6 != 0) {
        return;
    }
    id = ov49_0226A83C[WORD(p, 0xC) * 2];
    ov49_02268D0C(ov49_0226A83D[WORD(p, 0xC) * 2], &list);
    for (i = 0; i < list.count; i++) {
        if (ov49_0225E85C(PTR(p, 4), list.items[i], 0, 0x1000) != 1) {
            GF_AssertFail();
        }
    }
    ov49_02268D0C(id, &list);
    for (i = 0; i < list.count; i++) {
        if (ov49_0225E85C(PTR(p, 4), list.items[i], 1, 0x1000) != 1) {
            GF_AssertFail();
        }
    }
    WORD(p, 0xC) = (WORD(p, 0xC) + 1) % 7;
}

void ov49_02268C2C(void *p, u32 value) {
    u32 index = WORD(p, 0xC);
    if (index < 3 && ov49_0226A864[index * 2] < value) {
        ov49_0225E894(PTR(p, 4), ov49_0226A868[index * 2]);
        ov49_0225E6E0(PTR(p, 4), ov49_0226A868[WORD(p, 0xC) * 2]);
        PlaySE(0x5B4);
        WORD(p, 0xC)
        ++;
    }
}

void ov49_02268C74(void *p, u32 index, void *arg) {
    u8 *bytes = p;
    if (index >= 6) {
        GF_AssertFail();
    }
    if (index < 6) {
        u8 *state = bytes + 0xC;
        state[0] = 0;
        state[1] = 0;
        state[2] = 0;
        state[3] = 0;
        ov49_0226A87C[index](p, arg);
        bytes[8] = index;
    }
}
