#include "overlay49_state_internal.h"
#pragma require_prototypes off
void ov49_0225D224(Ov49DParent *, Ov49DState *, s32, s32, u32);
void ov49_0225D328(Ov49DParent *, Ov49DState *, s32);
u32 ov49_0225D450(Ov49DState *, s32);

u32 ov49_0225D450(Ov49DState *s, s32 i) {
    if (i >= 3) {
        GF_AssertFail();
    }
    if (s->index >= 18) {
        GF_AssertFail();
    }
    return s->active[i];
}

u32 ov49_0225D470(Ov49DState *s, s32 i) {
    if (i >= 3) {
        GF_AssertFail();
    }
    if (s->index >= 18) {
        GF_AssertFail();
    }
    return s->resource[i];
}
