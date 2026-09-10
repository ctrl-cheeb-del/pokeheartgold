#include "frontier_map_helpers_internal.h"

void ov80_02239590(FrontierMap *m, void *a1) {
    s32 i;
    FrontierMapEntry *base = sub_02096868(m->unk08);

    for (i = 0; i < 32; i++) {
        if (base[i].unk00 == a1) {
            ov42_02228100(base[i].unk00);
            ov42_022290C4(base[i].unk04);
            if (base[i].unk38 != NULL) {
                GF_AssertFail();
            }
            MI_CpuFill8(&base[i], 0, sizeof(FrontierMapEntry));
            base[i].unk0C = 0xFFFF;
            return;
        }
    }
}

void ov80_022395E8(FrontierMap *m, u16 id, void **outA, void **outB) {
    s32 i;
    FrontierMapEntry *base = sub_02096868(m->unk08);

    for (i = 0; i < 32; i++) {
        if (id == base[i].unk0C) {
            if (outA != NULL) {
                *outA = base[i].unk00;
            }
            if (outB != NULL) {
                *outB = base[i].unk04;
            }
            return;
        }
    }
    GF_AssertFail();
}

void ov80_0223962C(FrontierMap *m, u16 id) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (m->unk70[i] == 0xFFFF) {
            m->unk70[i] = id;
            return;
        }
    }
    GF_AssertFail();
}

void ov80_0223965C(FrontierMap *m, u16 id) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (id == m->unk70[i]) {
            m->unk70[i] = 0xFFFF;
            return;
        }
    }
}

void *ov80_0223968C(FrontierMap *m, u32 idx, u16 a2) {
    void *sprite;

    if (idx >= 8) {
        GF_AssertFail();
    }
    if (m->unk3C[idx] != NULL) {
        GF_AssertFail();
    }
    sprite = ov80_02239BB8(m->unk34, m->unk38, a2);
    m->unk3C[idx] = sprite;
    m->unk5C[idx] = a2;
    ov80_02239708(m, idx, 0);
    return sprite;
}

void ov80_022396D8(FrontierMap *m, u32 idx) {
    if (idx >= 8) {
        GF_AssertFail();
    }
    if (m->unk3C[idx] == NULL) {
        GF_AssertFail();
    }
    ov80_02239BE8(m->unk3C[idx]);
    m->unk3C[idx] = NULL;
}

void *ov80_02239700(FrontierMap *m, u32 idx) {
    return m->unk3C[idx];
}

void ov80_02239708(FrontierMap *m, u32 idx, u32 on) {
    if (on == 1) {
        m->unk6C = m->unk6C | (1 << idx);
    } else {
        m->unk6C = ((1 << idx) ^ 0xFFFFFFFF) & m->unk6C;
    }
}

u32 ov80_02239734(FrontierMap *m, u32 idx) {
    return (m->unk6C >> idx) & 1;
}
