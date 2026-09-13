#include "r40_overlay_90_residual_17_private.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

void ov90_0225A1B8(void *work);
void ov90_0225A204(void *dst, void *src);
BOOL ov90_0225A258(const u8 *work, const u8 *values);
u32 ov90_0225A28C(u32 value);
void ov90_0225A2B0(void *, void **, void *, int, void *, u32);

void ov90_0225A1B8(void *work) {
    s16 *values;
    s32 line = *(volatile u16 *)0x04000006;

    if (line < 192) {
        values = sub_02014A60(PTR_AT(work, 0x304));
        if ((*(volatile u16 *)0x04000004 & 2) != 0) {
            BgSetPosTextAndCommit(*(void **)PTR_AT(work, 0), 0, 0, values[line]);
            BgSetPosTextAndCommit(*(void **)PTR_AT(work, 0), 1, 0, values[line]);
        }
    }
}
