#include "frontier_map_helpers_internal.h"

void ov80_022394D8(FrontierMap *m, u16 id) {
    s32 i;
    FrontierMapMark *marks = sub_02096864(m->unk08);

    for (i = 0; i < 24; i++) {
        if (id == marks[i].unk00) {
            ov42_02229004(m->unk20, id);
            marks[i].unk00 = 0xFFFF;
            return;
        }
    }
}
