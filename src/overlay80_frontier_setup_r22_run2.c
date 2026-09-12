#include "overlay80_frontier_setup_r22_private.h"

u8 ov80_02237820(Ov80Battle *p, u32 i) {
    u32 v = p->mons[i].personality;
    if (v > 0x3D0A9) {
        p->mons[i].personality = v - 0x3D0A9;
    } else {
        p->mons[i].personality = v + 0x3D0A9;
    }
    return CalcShininessByOtIdAndPersonality(p->mons[i].otId, p->mons[i].personality);
}

u32 ov80_02237850(u32 a) {
    switch (a) {
    case 0:
        return 0x81;
    case 1:
        return 0x83;
    case 2:
        return 0x8F;
    case 3:
        return 0x8F;
    }
    return 0x81;
}

int ov80_0223787C(int a) {
    if (a == 1) {
        return 2;
    }
    return 1;
}

int ov80_02237888(int a) {
    if (a == 1) {
        return 2;
    }
    return 1;
}

void ov80_02237894(Ov80Mon *a, u32 b, u32 c, u16 *d, int e, u32 f, u32 g) {
    int i;
    int ability;

    if (c == 0x133) {
        ability = 0x1F;
    } else if (c == 0x134) {
        ability = 0x1F;
    } else {
        ability = ov80_0223796C(b);
    }
    for (i = 0; i < e; i++) {
        ov80_0222A4EC(&a[i], d[i], i, ability, 0, f, g);
    }
}

u16 ov80_022378F8(Ov80Battle *p, u32 unused) {
    if ((u16)(p->species[p->slot * 2] + 0xFECD) <= 1) {
        return ov80_022379C8(p);
    }
    return p->unk7;
}

u8 ov80_02237920(u32 a) {
    return ov80_0223D4C0[a];
}

BOOL ov80_0223792C(int a) {
    switch (a) {
    case 2:
    case 3:
        return TRUE;
    }
    return FALSE;
}

u8 ov80_0223793C(Ov80Battle *p) {
    return (s32)GetMonData(Party_GetMonByIndex(SaveArray_Party_Get(p->save), p->order[0]), 0xA1, NULL) / 10;
}

u8 ov80_0223796C(u32 a) {
    return ov80_0223C5B8[ov80_022379C0(a) * 4];
}

int ov80_02237980(Ov80Battle *p, u32 idx, int c) {
    int r;

    c++;
    if (c >= 8) {
        r = 7;
    } else if (c >= 4) {
        r = 1;
    } else {
        r = 0;
    }
    if (p->mode == 0) {
        if ((u16)(p->species[(idx & 0x7f) * 2] + 0xFECD) <= 1) {
            r = 7;
        }
    }
    if (p->mode == 2) {
        r = 7;
    }
    return r;
}

u32 ov80_022379C0(u32 a) {
    if (a >= 10) {
        a = 9;
    }
    return a;
}

u16 ov80_022379C8(Ov80Battle *p) {
    void *party;
    u16 lvl;
    u16 other;

    party = SaveArray_Party_Get(p->save);
    lvl = GetMonData(Party_GetMonByIndex(party, p->order[0]), 0xA1, NULL);
    if (ov80_0223787C(p->mode) == 2) {
        other = GetMonData(Party_GetMonByIndex(party, p->order[1]), 0xA1, NULL);
        if (lvl <= other) {
            lvl = other;
        }
        return lvl;
    }
    if (ov80_0223792C(p->mode) == TRUE) {
        other = p->fD84;
        if (lvl <= other) {
            lvl = other;
        }
        return lvl;
    }
    return lvl;
}

u32 ov80_02237A40(u32 a) {
    float v;

    if (a != 0) {
        v = 0.5f + (float)(a << 12);
    } else {
        v = (float)(a << 12) - 0.5f;
    }
    return FX_Sqrt((fx32)v);
}
