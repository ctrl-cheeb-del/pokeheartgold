#include "overlay49_state_helpers_private.h"
#pragma require_prototypes off

void ov49_02265668(void *p, Ov49Actor *a, u32 sound) {
    void *object = a->object;
    u32 snd = sound;
    u32 cur = ov49_02258DAC(*(void **)((u8 *)p + 4));
    if ((u32)object == cur) sub_0200606C((u16)snd, 5);
    else if (ov49_02258F70(object) == 0) PlaySE((u16)snd);
}
