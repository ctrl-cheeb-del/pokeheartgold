#include "overlay49_state_internal.h"
#pragma require_prototypes off
void ov49_0225D224(Ov49DParent *p, Ov49DState *s, s32 i, s32 type, u32 value) {
    if (i >= 3) {
        GF_AssertFail();
    }
    if (type >= 7) {
        GF_AssertFail();
    }
    if (s->index >= 18) {
        GF_AssertFail();
    }
    if (p->available[s->index][i] != 0) {
        if (s->active[i] == 0) {
            sub_020181D4(s->object, s->slots[i]);
        }
        s->active[i] = 1;
        s->type[i] = type;
        s->value[i] = value;
        s->random[i] = 0;
        switch (type) {
        case 0:
        case 1:
        case 2:
            s->resource[i] = 0;
            break;
        case 3:
        case 4:
            s->resource[i] = sub_020181A4(s->slots[i]);
            break;
        case 5:
            s->resource[i] = 0;
            s->random[i] = MTRandom() % s->modulus;
            break;
        case 6:
            s->resource[i] = 0;
            s->random[i] = MTRandom() % s->modulus;
            break;
        }
        sub_02018198(s->slots[i], s->resource[i]);
    }
}
void ov49_0225D328(Ov49DParent *p, Ov49DState *s, s32 i) {
    u8 *active;
    u32 offset;
    u32 zero;
    if (i >= 3) {
        GF_AssertFail();
    }
    if (s->index >= 18) {
        GF_AssertFail();
    }
    if (p->available[s->index][i] != 0) {
        active = (u8 *)s + 0xb8;
        if (active[i] == 1) {
            sub_020181E0((u8 *)s + 4, (u8 *)s + 0x7c + 0x14 * i);
            u8 *indexed;
            offset = i << 2;
            zero = 0;
            active[i] = zero;
            indexed = (u8 *)s + offset;
            *(u32 *)(indexed + 0xc0) = zero;
            s->type[i] = zero;
            s->random[i] = zero;
            *(u32 *)(indexed + 0xd0) = zero;
        }
    }
}
