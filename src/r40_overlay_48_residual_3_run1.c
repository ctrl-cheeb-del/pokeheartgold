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

BOOL ov48_022593B4(u8 *work, u16 a1, u16 a2) {
    struct {
        VecFx32 current;
        VecFx32 next;
    } local;

    if (ov48_02259AD0(work + 0x224, a1, a2, &local.next) != 3) {
        ov48_022598CC(work + 0x178, &local.current);
        local.next.z = local.current.z;
        ov48_022598DC(work + 0x178, &local.next);
        return TRUE;
    }
    return FALSE;
}
