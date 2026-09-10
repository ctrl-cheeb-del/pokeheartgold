#include "frontier_map_helpers_internal.h"

FrontierMapEntry *ov80_02239938(void *a0, u16 id) {
    s32 i;
    FrontierMapEntry *e = sub_02096868(a0);

    for (i = 0; i < 32; i++) {
        if (e->unk00 != NULL && e->unk0C == id) {
            return e;
        }
        e++;
    }
    GF_AssertFail();
    return NULL;
}
