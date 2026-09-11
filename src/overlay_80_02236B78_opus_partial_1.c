#include "overlay_80_02236B78_opus_partial_internal.h"

int ov80_02236B78(int a0, u32 a1, int a2) {
    u16 lo;
    int range;
    if (a1 >= 8) {
        a1 = 7;
    }
    if (a0 == 0) {
        int v = (a2 + 1) + a1 * 7;
        if (v == 0x15) {
            return 0x135;
        }
        if (v == 0x31) {
            return 0x136;
        }
    }
    if (a2 == 6 || a2 == 13) {
        lo = ov80_0223C478[a1].unk4;
        range = ov80_0223C478[a1].unk6 - lo;
    } else {
        lo = ov80_0223C478[a1].unk0;
        range = ov80_0223C478[a1].unk2 - lo;
    }
    return lo + LCRandom() % range;
}

void ov80_02236BE4(int a0, int a1, u16 *a2, int a3) {
    int i = 0;
    int j;
    u16 *p = a2;
    do {
        *p = ov80_02236B78(a0, a1, i);
        for (j = 0; j < i; j++) {
            if (a2[j] == a2[i]) {
                break;
            }
        }
        if (j == i) {
            p++;
            i++;
        }
    } while (i < a3);
}

const Ov80LevelRange *ov80_02236C2C(int a0, int a1) {
    int count;
    int i;
    if (a1 == 0) {
        ov80_0223DD38 = ov80_0223C508;
        count = 10;
    } else {
        ov80_0223DD38 = ov80_0223C558;
        count = 10;
    }
    for (i = 0; i < count; i++) {
        if (a0 < ov80_0223DD38[i].unk0) {
            break;
        }
    }
    if (i >= count) {
        GF_AssertFail();
        i = count - 1;
    }
    return &ov80_0223DD38[i];
}

const Ov80LevelRange *ov80_02236C78(int a0, int a1) {
    if (a0 >= 8) {
        a0 = 7;
    }
    if (a1 == 0) {
        return &ov80_0223C508[a0];
    }
    return &ov80_0223C4B8[a0];
}
