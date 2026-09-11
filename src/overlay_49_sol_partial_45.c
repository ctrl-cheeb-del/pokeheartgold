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

void ov49_0225D574(void *p) {
    sub_02018068(p);
}
