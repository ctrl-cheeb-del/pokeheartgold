#include "frontier_map_helpers_internal.h"

void ov80_0223927C(FrontierMap *m) {
    s32 i;
    FrontierMapEntry *e = sub_02096868(m->unk08);

    for (i = 0; i < 32; i++) {
        if (e->unk00 != NULL) {
            ov42_02228100(e->unk00);
            if (e->unk38 != NULL) {
                GF_AssertFail();
            }
        }
        e++;
    }
    ov42_02228050(m->unk14);
    ov42_02227F28(m->unk18);
    ov42_02228F94(m->unk20);
    if (m->unk24 != NULL) {
        ov42_0222940C(m->unk24);
    }
    if (m->unk28 != NULL) {
        ov42_0222940C(m->unk28);
    }
    ov42_02229A78(m->unk2C);
    ov42_022299AC(m->unk30);
}

void *ov80_022392DC(u32 heapId) {
    return GF_3DVramMan_Create(heapId, 0, 1, 0, 1, ov80_022392F8);
}
