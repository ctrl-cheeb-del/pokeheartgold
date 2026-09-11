#include "ov80_2aef8_partial_internal.h"

void ov80_0222AEF8(u32 sender, u32 a1, void *payload, void *ctx);
BOOL ov80_0222AF10(void *ctx);
void ov80_0222AF3C(u32 sender, u32 a1, void *payload, void *ctx);
BOOL ov80_0222AF54(void *ctx);
void ov80_0222AF84(u32 sender, u32 a1, const u16 *payload, void *ctx);
BOOL ov80_0222AFB8(void *ctx);
void ov80_0222AFEC(u32 sender, u32 a1, const u16 *payload, void *ctx);
BOOL ov80_0222B024(void *ctx, u16 value);
void ov80_0222B048(u32 sender, u32 a1, const u16 *payload, void *ctx);
void *ov80_0222B0E8(u32 index, void *ctx, s32 size);
BOOL ov80_0222B070(void *ctx);
void ov80_0222B0B8(u32 sender, u32 a1, const void *payload, void *ctx);
BOOL ov80_0222B108(void *ctx);
void ov80_0222B140(u32 sender, u32 a1, const u16 *payload, void *ctx);
BOOL ov80_0222B3B0(void *ctx, u16 value);
void ov80_0222B3D4(u32 sender, u32 a1, const u16 *payload, void *ctx);
BOOL ov80_0222B3FC(void *ctx, u16 value);
void ov80_0222B420(u32 sender, u32 a1, const u16 *payload, void *ctx);
BOOL ov80_0222B174(void *ctx);
void ov80_0222B1A4(u32 sender, u32 a1, const u16 *payload, void *ctx);
BOOL ov80_0222B1DC(void *ctx);
BOOL ov80_0222B2C4(void *ctx);
void ov80_0222B24C(u32 sender, u32 a1, const u16 *payload, void *ctx);
void ov80_0222B334(u32 sender, u32 a1, const u16 *payload, void *ctx);
BOOL ov80_0222B65C(void *ctx);
void ov80_0222B690(u32 sender, u32 a1, const u16 *payload, void *ctx);
void ov80_0222B628(u32 sender, u32 a1, const u16 *payload, void *ctx);
BOOL ov80_0222B5C8(void *ctx);
BOOL ov80_0222B6C8(void *ctx);
BOOL ov80_0222B7E4(void *ctx);
void ov80_0222B860(u32 sender, u32 a1, const u16 *payload, void *ctx);
void ov80_0222B740(u32 sender, u32 a1, const u16 *payload, void *ctx);
BOOL ov80_0222B8D8(void *ctx, u16 value);
void ov80_0222B8F8(u32 sender, u32 a1, const u16 *payload, void *ctx);
BOOL ov80_0222B920(void *ctx, u16 value);
void ov80_0222B940(u32 sender, u32 a1, const u16 *payload, void *ctx);
void *ov80_0222BA5C(u32 index, void *ctx, s32 size);
BOOL ov80_0222BA7C(void *ctx);
void ov80_0222BAB0(u32 sender, u32 a1, const u16 *payload, void *ctx);
BOOL ov80_0222BAE0(void *ctx);
void ov80_0222BB18(u32 sender, u32 a1, const u16 *payload, void *ctx);
BOOL ov80_0222BC48(void *ctx, u16 value);
void ov80_0222BC6C(u32 sender, u32 a1, const u16 *payload, void *ctx);
BOOL ov80_0222BC94(void *ctx, u16 value);
void ov80_0222BCB8(u32 sender, u32 a1, const u16 *payload, void *ctx);
void *ov80_0222BDD4(u32 index, void *ctx, s32 size);
BOOL ov80_0222B968(void *ctx);
BOOL ov80_0222BCE0(void *ctx);
void ov80_0222B9CC(u32 sender, u32 a1, const void *payload, void *ctx);
void ov80_0222BD44(u32 sender, u32 a1, const void *payload, void *ctx);

BOOL ov80_0222B3B0(void *ctx, u16 value) {
    u8 *p = ctx;
    *(u16 *)(p + 0x504) = value;
    return sub_02037030(0x1A, p + 0x504, 0x3C) == 1;
}

void ov80_0222B3D4(u32 sender, u32 a1, const u16 *payload, void *ctx) {
    u8 *p = ctx;
    p[0x702]++;
    if (sender != sub_0203769C()) {
        p[0x57C] = *payload;
    }
}

BOOL ov80_0222B3FC(void *ctx, u16 value) {
    u8 *p = ctx;
    *(u16 *)(p + 0x504) = value;
    return sub_02037030(0x1B, p + 0x504, 0x3C) == 1;
}

void ov80_0222B420(u32 sender, u32 a1, const u16 *payload, void *ctx) {
    u8 *p = ctx;
    p[0x702]++;
    if (sender != sub_0203769C()) {
        p[0x57D] = *payload;
    }
}
