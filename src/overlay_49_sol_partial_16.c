#include "overlay_49_sol_partial_internal.h"

#pragma require_prototypes off

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))

extern u32 ov42_02227FA4(void *);
extern u32 ov42_02229A8C(void *);
extern u32 ov45_022306B4(void *);
extern u32 ov45_022306F4(void *);
extern u32 ov45_022308B8(void *);
extern u32 ov45_0223089C(void *);
extern u32 ov45_022308C0(void *);
extern u32 ov45_022308E4(void *);
extern u32 ov45_02230908(void *);
extern u32 ov45_02230920(void *);
extern u32 ov45_022308B0(void *);
extern u32 ov45_02230978(void *);
extern u32 ov45_02230994(void *);
extern void ov49_02259764(void *, u32, u32);
extern void ov49_0225AB14(void *, u32, u32);
extern void ov49_0225B124(void *);
extern void ov49_0225CD58(void *);
extern void ov49_0225CED0(void *);
extern void ov49_0225CEFC(void *);
extern void ov49_0225F018(void *, u32);
extern void ov49_0225A134(void *);
extern void ov49_02262E10(void *, u32, u32, u32);
extern void ov49_02267A84(void *, u32, u32);
extern void ov49_02267C20(void *, u32, u32);
extern void ov49_02266B28(void *, u32, u32);
extern void ov49_02267908(void *, u32, u32);
extern void ov49_02267AF0(void *, u32, u32);
extern void ov49_02268640(void *);
extern void ov49_02269154(void *);
extern void ov49_0225E82C(void *, u32, u32);
extern void sub_020182A0();
extern void sub_020182C4(void *);
extern void sub_020182E0(void *, u32, u32);
extern void sub_02018068(void *);
extern void ov42_02227F28(void *);
extern u32 ov42_02227FDC(void *);
extern void ov45_0223093C(void *, u32);
extern void ov45_02230968(void *, u32);
extern void GF_AssertFail(void);
extern void sub_0200F450(void *);
extern void sub_0200F478(void *);
extern void ListMenuItems_Delete(void *);
extern void PlaySE(u32);
extern void ov49_0225BF80(void *);
extern void ov49_0225CAA8(void *);
extern void Camera_UnsetStaticPtr(void *);
extern void Camera_Delete(void *);

u32 ov49_02259FE8(void *p) {
    return U32_AT(p, 0x34);
}

u32 ov49_02259FEC(void *p) {
    return U32_AT(p, 0x38);
}

u32 ov49_02259FF0(void *p) {
    return U32_AT(p, 0x3E0);
}

u32 ov49_02259FF8(void *p) {
    return U32_AT(p, 0x3E4);
}

u32 ov49_0225A000(void *p) {
    return U32_AT(p, 0x3E8);
}

u32 ov49_0225A008(void *p) {
    return U32_AT(p, 0x3EC);
}

u32 ov49_0225A010(void *p) {
    return U32_AT(p, 0x3F0);
}

void ov49_0225A018(void *p, u32 v) {
    u8 t = v;
    U8_AT(p, 4) = (U8_AT(p, 4) & ~0xF) | (t & 0xF);
}

u8 ov49_0225A02C(void *p) {
    return U8_AT(p, 2);
}

u8 ov49_0225A030(void *p) {
    return U8_AT(p, 3);
}

void ov49_0225A034(void *p, u8 v) {
    U8_AT(p, 0) = v;
}

void ov49_0225A038(void *p, u8 v) {
    U8_AT(p, 1) = v;
}

void ov49_0225A03C(void *p, u8 v) {
    U8_AT(p, 5) = v;
}

u8 ov49_0225A040(void *p) {
    return U8_AT(p, 5);
}

void ov49_0225A044(void *p) {
    U8_AT(p, 7) = 1;
}

void ov49_0225A04C(void *p, u32 i, u8 v) {
    if (i >= 20) {
        GF_AssertFail();
    }
    U8_AT(p, i + 0xC) = v;
}

u8 ov49_0225A064(void *p, u32 i) {
    return U8_AT(p, i + 0xC);
}
