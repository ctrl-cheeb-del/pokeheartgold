#include "r40_overlay_39_thumb_residual_5_private.h"

extern BOOL ov39_02227DB8(void *work);
extern void *Save_PlayerData_GetIGTAddr(void *saveData);
extern void ov39_022271CC(void *saveData, void *src, void *dst);
extern u32 sub_0202FBCC(void);
extern void GF_AssertFail(void);
extern void *sub_0202FC74(void);
extern void ov40_02244B3C(void *saveData);
extern void *sub_020307DC(void);

BOOL ov39_022274D4(Ov39WorkResidual5 *work, void *src, const Ov39Pair *pairs) {
    s32 i;

    if (!ov39_02227DB8(work)) {
        return FALSE;
    }
    MI_CpuCopy8(Save_PlayerData_GetIGTAddr(work->saveData), &work->payloadOffset, 4);
    ov39_022271CC(work->saveData, src, &work->field190);
    for (i = 0; i < 3; i++) {
        work->pairs[i] = pairs[i];
    }
    work->command = 0x55F1;
    return TRUE;
}

BOOL ov39_02227534(Ov39WorkResidual5 *work, void *dst) {
    u32 size;

    if (!ov39_02227DB8(work)) {
        return FALSE;
    }
    size = sub_0202FBCC();
    if (size - 4 != 0x1D4C) {
        GF_AssertFail();
    }
    work->field190.ptr190 = sub_0202FC74();
    ov40_02244B3C(work->saveData);
    MI_CpuCopy8(dst, sub_020307DC(), 0x80);
    work->byte411 = 0x3C;
    work->command = 0x59D8;
    return TRUE;
}

BOOL ov39_02227590(Ov39WorkResidual5 *work, u16 value, u8 a2, u8 a3, u8 a4) {
    if (!ov39_02227DB8(work)) {
        return FALSE;
    }
    MI_CpuFill8(&work->field190, 0, 0x10);
    work->field190.value = value;
    ((u8 *)&work->field190)[2] = a2;
    ((u8 *)&work->field190)[3] = a3;
    work->byte194 = a4;
    work->payloadOffset = 0x140;
    work->unk3F0 = 0;
    work->command = 0x59D9;
    return TRUE;
}

BOOL ov39_022275E8(Ov39WorkResidual5 *work) {
    if (!ov39_02227DB8(work)) {
        return FALSE;
    }
    MI_CpuFill8(&work->field190, 0, 0x10);
    work->field190.value = 0xFFFF;
    ((u8 *)&work->field190)[2] = 0xFE;
    ((u8 *)&work->field190)[3] = 0xFF;
    work->byte194 = 0xFF;
    work->payloadOffset = 0x140;
    work->unk3F0 = 0;
    work->command = 0x59D9;
    return TRUE;
}

BOOL ov39_02227648(Ov39WorkResidual5 *work) {
    if (!ov39_02227DB8(work)) {
        return FALSE;
    }
    MI_CpuFill8(&work->field190, 0, 0x10);
    work->field190.value = 0xFFFF;
    ((u8 *)&work->field190)[2] = 0xFF;
    ((u8 *)&work->field190)[3] = 0xFF;
    work->byte194 = 0xFF;
    work->payloadOffset = 0x140;
    work->unk3F0 = 0;
    work->command = 0x59D9;
    return TRUE;
}
