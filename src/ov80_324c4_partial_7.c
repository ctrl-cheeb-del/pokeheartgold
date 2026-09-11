#include "ov80_324c4_partial_internal.h"

void ov80_02232ABC(void *ctx);
u16 ov80_02232B44(const void *data, u32 index);
u8 ov80_02232E58(void *ctx);
u8 ov80_02232E64(const void *ctx);
void ov80_02232EE0(void *ctx);
void ov80_02232F00(void *ctx);
void ov80_022333D0(void *unused, void *window);
u32 ov80_02233648(const void *ctx);
void ov80_02232824(void *ctx, u32 mode);
void ov80_02232E68(void *ctx, u32 index);
void ov80_02232E9C(void *ctx);
void ov80_02232F08(void *ctx);
void ov80_02233280(void *ctx, u32 state, u16 value);
void ov80_022331E8(void *save, u32 mode, s32 amount);
void ov80_02232AEC(void *ctx, const void *data);
void ov80_02232F60(void *ctx);
void ov80_022333F0(void *data, const void *ctx);
void ov80_02233594(void *ctx, void *window, const void *profile, u32 value);

u32 ov80_02233648(const void *ctx) {
    const u8 *p = ctx;
    u32 mode = p[0x10];
    u32 round = *(const u16 *)(p + 0x16);
    u32 result;
    if (mode <= 1) {
        result = round >= 8 ? 7 : ov80_0223BE54[round];
    } else {
        result = round >= 8 ? 0x12 : ov80_0223BE60[round];
    }
    if (mode == 0) {
        u16 value = *(const u16 *)(p + 0x14);
        if (value == 0x15 || value == 0x31) {
            result = 0x14;
        }
    }
    return result;
}
