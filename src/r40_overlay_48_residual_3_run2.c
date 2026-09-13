#include "r40_overlay_48_residual_3_private.h"

extern u16 ov48_02259AD0(void *p, u16 a, u16 b, void *out);
extern void ov48_022598CC(void *p, VecFx32 *out);
extern void ov48_022598DC(void *p, const VecFx32 *value);
extern void *NARC_New(u32 narcId, u32 heapId);
extern void GF_CreateVramTransferManager(u32 count, u32 heapId);
extern void GfGfx_SetBanks(const void *banks);
extern const u8 ov48_0225B210[];
extern void ov48_022594F0(void *work, void *config, u32 heapId);
extern void ov48_02259688(void *work, u32 heapId);
extern void ov48_02259750(void *work, u32 heapId);

void ov48_02259464(u8 *work, void *config, u32 heapId) {
    *(void **)(work + 0x144) = NARC_New(0xC0, heapId);
    GF_CreateVramTransferManager(0x40, heapId);
    GfGfx_SetBanks(ov48_0225B210);
    ov48_022594F0(work, config, heapId);
    ov48_02259688(work, heapId);
    ov48_02259750(work, heapId);
}
