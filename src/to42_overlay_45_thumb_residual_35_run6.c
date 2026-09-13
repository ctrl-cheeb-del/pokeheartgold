#include "to42_overlay_45_thumb_residual_35_private.h"
void ov45_02230378(void *, const u32 *);
void ov45_02230378(void *dst, const u32 *src) {
    *(Ov45Pair *)((u8 *)dst + 0x10) = *(const Ov45Pair *)src;
}
void ov45_02230384(const void *src, u32 *dst) {
    *(Ov45Pair *)dst = *(const Ov45Pair *)((const u8 *)src + 0x10);
}
