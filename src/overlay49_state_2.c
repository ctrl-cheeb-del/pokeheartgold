#include "overlay49_state_internal.h"
#pragma require_prototypes off
void ov49_0225D224(Ov49DParent *, Ov49DState *, s32, s32, u32);
void ov49_0225D328(Ov49DParent *, Ov49DState *, s32);
u32 ov49_0225D450(Ov49DState *, s32);

void ov49_0225D394(Ov49DParent *p, Ov49DState *s) {
    int i;
    for (i = 0; i < 3; i++) {
        if (ov49_0225D450(s, i) == 1) {
            ov49_0225D328(p, s, i);
        }
    }
}

u32 ov49_0225D3BC(Ov49DParent *p, Ov49DState *s, s32 i) {
    if (i >= 3) {
        GF_AssertFail();
    }
    if (s->index >= 18) {
        GF_AssertFail();
    }
    if (p->available[s->index][i] != 0) {
        return s->active[i];
    }
    return 0;
}
