#include "to42_overlay_45_thumb_residual_24_private.h"

void ov45_0222C83C(void *a, void *b, void *c, u8 *work) {
    int i = ov45_0222EC68(a);
    if (i != -1) {
        u8 *dest = work + i;
        u32 offset = 0x1E8;
        u32 one = 1;
        dest[offset] = one;
    }
}

void ov45_0222C858(void *a, void *b, u32 c, u8 *work) {
    int i = ov45_0222EC68(a), j;
    if (i != -1) {
        for (j = 0; j < 3; j++) {
            if (ov45_0222C408((Ov45Grid *)(work + 0x20C), i, j) != -1) {
                break;
            }
        }
    }
}

void ov45_0222C88C(void *a, void *b, void *c, u8 *work) {
    int i = ov45_0222EC68(a);
    if (i != -1) {
        ov45_0222C514((Ov45Grid *)(work + 0x20C), i);
    }
}

void ov45_0222C8AC(Ov45WordSet *p) {
    int i;
    memset(p, 0, 0x20);
    for (i = 0; i < 9; i++) {
        p->flags[i] = 100;
    }
}

void ov45_0222C8C8(Ov45WordSet *p, u32 index, u32 flag) {
    if (flag >= 20) {
        GF_AssertFail();
    }
    if (index >= 27) {
        GF_AssertFail();
    }
    if (p->flags[12 + flag] == 0) {
        p->flags[index / 3] >>= 1;
        p->flags[12 + flag] = 1;
    }
}

u32 ov45_0222C900(Ov45WordSet *p) {
    int sum = 0;
    int i = 0;
    u32 target;
    u32 accum;
    while (i < 9) {
        sum += p->flags[i];
        i++;
    }
    target = MTRandom() % (u32)sum;
    accum = 0;
    i = 0;
    while (i < 9) {
        if (accum <= target && accum + p->flags[i] > target) {
            return i * 3;
        }
        accum += p->flags[i];
        i++;
    }
    GF_AssertFail();
    return 0;
}

void ov45_0222C944(Ov45WordSet *p, u32 i, u8 x) {
    if (i >= 20) {
        GF_AssertFail();
    }
    if (i < 20) {
        p->flags[i] = x;
    }
}

u32 ov45_0222C95C(Ov45WordSet *p, u32 i) {
    if (i >= 20) {
        GF_AssertFail();
    }
    if (i < 20) {
        return p->flags[i];
    }
    return 0;
}

void ov45_0222C978(Ov45WordSet *p, enum HeapID heap) {
    MI_CpuFill8(p, 0, 0xB8);
    p->bank = WallpaperPasswordBank_Create(heap);
}

void ov45_0222C994(Ov45WordSet *p) {
    WallpaperPasswordBank_Delete(p->bank);
}

void ov45_0222C9A0(Ov45WordSet *p, u32 i, u8 value, u32 seed) {
    if (i >= 20) {
        GF_AssertFail();
    }
    if (i < 20) {
        p->flags[i] = value;
        if (value == 1) {
            ov45_0222CA10(p->bank, seed, p->words[i]);
        }
    }
}

u32 ov45_0222C9D0(Ov45WordSet *p, u32 i) {
    if (i >= 20) {
        GF_AssertFail();
    }
    if (i < 20) {
        return p->flags[i];
    }
    return 0;
}

u16 *ov45_0222C9EC(Ov45WordSet *p, u32 i) {
    if (i >= 20) {
        GF_AssertFail();
    }
    if (i < 20 && p->flags[i]) {
        return p->words[i];
    }
    return NULL;
}
