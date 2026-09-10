#include "frontier_map_helpers_internal.h"

void ov80_022389C4(FrontierMap *m) {
    s32 i;
    FrontierMapEntry *e;

    for (i = 0; i < 32; i++) {
        e = sub_0209686C(m->unk08, i);
        if (e->unk00 != NULL) {
            e->unk12 = (u8)ov42_02228188(e->unk00, 6);
            e->unk0A = ov42_02228188(e->unk00, 5);
            e->unk0E = ov42_02228188(e->unk00, 0);
            e->unk10 = ov42_02228188(e->unk00, 1);
            e->unk13 = ov42_022291F4(e->unk04);
        }
    }
    ov80_02239740(m);
}
