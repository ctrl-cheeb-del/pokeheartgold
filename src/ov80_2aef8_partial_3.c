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

BOOL ov80_0222B5C8(void *ctx) {
    u8 *p = ctx;
    void *frontier;
    u32 stat;
    u32 substat;
    sub_02030E08(*(void **)(p + 4));
    *(u16 *)(p + 0x3C2) = *(u16 *)(p + 0x14);
    *(u16 *)(p + 0x3C4) = *(u16 *)(p + 0x16);
    frontier = Save_Frontier_GetStatic(*(void **)(p + 4));
    stat = sub_0205C1F0(p[0x10]);
    substat = sub_0205C268(sub_0205C1F0(p[0x10]));
    *(u16 *)(p + 0x3D6) = FrontierSave_GetStat(frontier, stat, substat);
    return sub_02037030(0x2A, p + 0x3C0, 0x28) == 1;
}

void ov80_0222B628(u32 sender, u32 a1, const u16 *payload, void *ctx) {
    u8 *p = ctx;
    p[0xA1A]++;
    if (sender != sub_0203769C()) {
        *(u16 *)(p + 0xA16) = payload[1];
        *(u16 *)(p + 0xA12) = payload[2];
        *(u16 *)(p + 0xA1C) = payload[11];
    }
}

BOOL ov80_0222B65C(void *ctx) {
    u8 *base = ctx;
    int i = 0;
    u8 *p = base;
    while (i < 14) {
        *(u16 *)(p + 0x3C0) = *(u16 *)(p + 0x30);
        p += 2;
        i++;
    }
    return sub_02037030(0x2B, base + 0x3C0, 0x28) == 1;
}

void ov80_0222B690(u32 sender, u32 a1, const u16 *payload, void *ctx) {
    u8 *p = ctx;
    int i;
    p[0xA1A]++;
    if (sender != sub_0203769C() && sub_0203769C() != 0) {
        for (i = 0; i < 14; i++) {
            *(u16 *)(p + 0x30) = *payload++;
            p += 2;
        }
    }
}

BOOL ov80_0222B6C8(void *ctx) {
    u8 *p = ctx;
    *(u16 *)(p + 0x3C0) = p[0xA18];
    if (sub_0203769C() == 0) {
        if (p[0xA1B] == 0) {
            p[0xA1B] = p[0xA18];
        } else if (p[0xA1B] - 6 == 4 && p[0xA18] != 4) {
            p[0xA1B] = p[0xA18];
        }
    } else if (p[0xA1B] == 4 && p[0xA18] != 4) {
        p[0xA1B] = p[0xA18] + 6;
    }
    *(u16 *)(p + 0x3C2) = p[0xA1B];
    return sub_02037030(0x2C, p + 0x3C0, 0x28) == 1;
}
