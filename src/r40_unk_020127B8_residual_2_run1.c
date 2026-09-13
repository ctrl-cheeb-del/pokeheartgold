#include "r40_unk_020127B8_residual_2_private.h"

void sub_02012940(u8 *dst, const FadeParam8 *param, int a2, int a3, u32 a4, void *a5, u32 a6, u32 heapId) {
    sub_02011080(dst, a4, 1, 0, 0);
    if (param->unk6 == 0) {
        memset(dst, 1, 0xC0);
        memset(dst + 0xC0, 1, 0xC0);
    } else {
        memset(dst, 0, 0xC0);
        memset(dst + 0xC0, 0, 0xC0);
    }
    *(u32 *)(dst + 0x30C) = (u32)param->unk0;
    *(u32 *)(dst + 0x310) = param->unk4;
    *(u32 *)(dst + 0x324) = param->unk6;
    *(u32 *)(dst + 0x328) = heapId;
    *(u32 *)(dst + 0x314) = a2;
    *(u32 *)(dst + 0x318) = 0;
    *(u32 *)(dst + 0x31C) = a3;
    *(u32 *)(dst + 0x320) = 0;
    *(void **)(dst + 0x32C) = a5;
    *(u32 *)(dst + 0x330) = a6;
    sub_020110DC((void *)a6, dst, heapId);
    if (param->unk6 == 1) {
        sub_02010F84(a5, 0x20, 0x3F, 0, a4, 0, 0, 0, 0, param->unk6);
    } else {
        sub_02010F84(a5, 0x3F, 0x20, 0, a4, 0, 0, 0, 0, param->unk6);
    }
    sub_02011068(a5, 1, a4, *(u32 *)(dst + 0x324));
}
