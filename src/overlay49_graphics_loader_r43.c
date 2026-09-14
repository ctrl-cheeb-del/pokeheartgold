#include "overlay49_graphics_loader_r43_private.h"

void ov49_0225D4F0(void *ptr, fx32 x, fx32 y, fx32 z)
{
    sub_020182C4((u8 *)ptr + 4, x, y, z);
}

void ov49_0225D4FC(u32 a0, u32 a1, enum HeapID heapId)
{
    u32 memberNo = a0 + a1 * 5;

    GF_ASSERT(memberNo < 25);
    GfGfxLoader_LoadFromNarc(NARC_a_2_0_0, memberNo + 1, FALSE, heapId, TRUE);
}
