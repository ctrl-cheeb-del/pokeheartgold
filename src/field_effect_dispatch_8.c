#include "field_effect_dispatch_internal.h"

u32 ov01_022062CC(void *p) {
    return GetIdxOfFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(*(void **)((u8 *)p + 0xc)));
}
