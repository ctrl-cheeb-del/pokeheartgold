#include "global.h"

#include "r40_unk_02035724_private.h"

u32 sub_02035724(u32 kind) {
    u16 period = WM_GetDispersionBeaconPeriod();

    GF_ASSERT(kind < 41);
    if (kind == 10) {
        return ((u32)period << 14) >> 16;
    }
    if (kind == 9 || kind == 13) {
        return ((u32)period << 14) >> 16;
    }
    return period;
}
