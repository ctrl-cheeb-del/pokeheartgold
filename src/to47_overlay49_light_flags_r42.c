#include "to47_overlay49_light_flags_r42_private.h"

void ov49_0225D4A0(void *p, void *entry, u32 flags)
{
    if (*(u16 *)((u8 *)entry + 2) >= 0x12) {
        GF_AssertFail();
    }
    NNS_G3dMdlSetMdlLightEnableFlagAll(*(void **)((u8 *)p + *(u16 *)((u8 *)entry + 2) * 0x10 + 0x2A4), flags);
}
