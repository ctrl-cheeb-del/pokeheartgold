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

void ov80_0222AEF8(u32 sender, u32 a1, void *payload, void *ctx) {
    u8 *p = ctx;
    p[0xD90]++;
    if (sender != sub_0203769C()) {
        return;
    }
}

BOOL ov80_0222AF10(void *ctx) {
    u8 *p = ctx;
    Save_PlayerData_GetProfile(*(void **)(p + 0x6FC));
    return sub_02037030(0x22, p + 0x72C, 0x2C) == 1;
}

void ov80_0222AF3C(u32 sender, u32 a1, void *payload, void *ctx) {
    u8 *p = ctx;
    p[0xD90]++;
    if (sender != sub_0203769C()) {
        return;
    }
}

BOOL ov80_0222AF54(void *ctx) {
    u8 *p = ctx;
    u16 *packet = (u16 *)(p + 0x72C);
    u16 *dst = packet;
    int i;
    for (i = 0; i < 20; i++) {
        *dst++ = *(u16 *)(p + 0x18);
        p += 2;
    }
    return sub_02037030(0x23, packet, 0x2C) == 1;
}

void ov80_0222AF84(u32 sender, u32 a1, const u16 *payload, void *ctx) {
    u8 *p = ctx;
    int i;
    p[0xD90]++;
    if (sender != sub_0203769C() && sub_0203769C() != 0) {
        for (i = 0; i < 20; i++) {
            *(u16 *)(p + 0x18) = *payload++;
            p += 2;
        }
    }
}

BOOL ov80_0222AFB8(void *ctx) {
    u8 *p = ctx;
    u16 *packet = (u16 *)(p + 0x72C);
    int i = 0;
    u16 *dst = packet;
    while (i < 20) {
        *dst++ = *(u16 *)(p + 0x268);
        p += 2;
        i++;
    }
    return sub_02037030(0x24, packet, 0x2C) == 1;
}

void ov80_0222AFEC(u32 sender, u32 a1, const u16 *payload, void *ctx) {
    u8 *p = ctx;
    int i;
    p[0xD90]++;
    if (sender != sub_0203769C() && sub_0203769C() != 0) {
        for (i = 0; i < 20; i++) {
            *(u16 *)(p + 0x268) = *payload++;
            p += 2;
        }
    }
}

BOOL ov80_0222B024(void *ctx, u16 value) {
    u8 *p = ctx;
    *(u16 *)(p + 0x72C) = value;
    return sub_02037030(0x25, p + 0x72C, 0x2C) == 1;
}

void ov80_0222B048(u32 sender, u32 a1, const u16 *payload, void *ctx) {
    u8 *p = ctx;
    p[0xD90]++;
    if (sender != sub_0203769C()) {
        p[0xD88] = *payload;
    }
}

BOOL ov80_0222B070(void *ctx) {
    u8 *p = ctx;
    u32 size = SizeOfStructPokemon();
    void *mon = Party_GetMonByIndex(SaveArray_Party_Get(*(void **)(p + 0x6FC)), p[0x260]);
    MI_CpuCopy8(mon, p + 0x784, size);
    return sub_02036FD8(0x26, p + 0x784, 0x200) == 1;
}

void ov80_0222B0B8(u32 sender, u32 a1, const void *payload, void *ctx) {
    u8 *p = ctx;
    p[0xD90]++;
    if (sender != sub_0203769C()) {
        MI_CpuCopy8(payload, *(void **)(p + 0xD8C), SizeOfStructPokemon());
    }
}

void *ov80_0222B0E8(u32 index, void *ctx, s32 size) {
    u8 *p = ctx;
    GF_ASSERT(size <= 0x200);
    return p + 0x984 + index * 0x200;
}

BOOL ov80_0222B108(void *ctx) {
    u8 *p = ctx;
    u8 *packet = p + 0x504;
    Save_PlayerData_GetProfile(*(void **)(p + 0x4F8));
    *(u16 *)(packet + 2) = *(u16 *)(p + 8);
    *(u16 *)(packet + 4) = *(u16 *)(p + 0xC);
    *(u16 *)(packet + 6) = *(u16 *)(p + 0xE);
    return sub_02037030(0x16, packet, 0x3C) == 1;
}

void ov80_0222B140(u32 sender, u32 a1, const u16 *payload, void *ctx) {
    u8 *p = ctx;
    p[0x702]++;
    if (sender != sub_0203769C()) {
        *(u16 *)(p + 0x580) = payload[1];
        *(u16 *)(p + 0x582) = payload[2];
        *(u16 *)(p + 0x57E) = payload[3];
    }
}

BOOL ov80_0222B174(void *ctx) {
    u8 *p = ctx;
    u16 *packet = (u16 *)(p + 0x504);
    u16 *dst = packet;
    int i;
    for (i = 0; i < 14; i++) {
        *dst++ = *(u16 *)(p + 0x18);
        p += 2;
    }
    return sub_02037030(0x17, packet, 0x3C) == 1;
}

void ov80_0222B1A4(u32 sender, u32 a1, const u16 *payload, void *ctx) {
    u8 *p = ctx;
    int i;
    p[0x702]++;
    if (sender != sub_0203769C() && sub_0203769C() != 0) {
        for (i = 0; i < 14; i++) {
            *(u16 *)(p + 0x18) = *payload++;
            p += 2;
        }
    }
}
