#include "field_render_capture_internal.h"

void *ov01_021F4464(void *source) {
    u8 *src = source;
    void *task = CreateSysTaskAndEnvironment(ov01_021F4544, 0x38, 5, *(u32 *)(src + 0x28));
    u8 *env = SysTask_GetData(task);
    *(Overlay01CaptureConfigPrivate *)(env + 4) = *(Overlay01CaptureConfigPrivate *)src;
    *(void **)(env + 0x34) = task;
    *(u32 *)(env + 0x30) = 0;
    *(u32 *)env = GX_GetBankForLCDC();
    ov01_021F45E4((s32 *)(env + 4));
    SysTask_CreateOnVWaitQueue(ov01_021F4584, env, 0);
    return env;
}

void ov01_021F44B4(void **handle, u32 a, u32 b, u32 c) {
    GX_SetGraphicsMode((GXDispMode)a, (GXBGMode)b, (GXBG0As)c);
    GX_SetBankForLCDC((GXVRamLCDC)(*(s32 **)handle)[0]);
    switch ((*(s32 **)handle)[1]) {
    case 2:
        MIi_CpuClearFast(0, (void *)0x06800000, 0x20000);
        break;
    case 6:
        MIi_CpuClearFast(0, (void *)0x06820000, 0x20000);
        break;
    case 10:
        MIi_CpuClearFast(0, (void *)0x06840000, 0x20000);
        break;
    case 14:
        MIi_CpuClearFast(0, (void *)0x06860000, 0x20000);
        break;
    default:
        GX_SetBankForLCDC((GXVRamLCDC)0);
        break;
    }
    DestroySysTaskAndEnvironment((*(void ***)handle)[13]);
    *handle = NULL;
}

void ov01_021F4544(void *unused, s32 *p) {
    if (p[12] != 0) {
        GX_SetCapture_Private((GXCaptureSize)p[4], (GXCaptureMode)p[5], (GXCaptureSrcA)p[6], (GXCaptureSrcB)p[7], (GXCaptureDest)p[8], p[9], p[10]);
    }
}

void ov01_021F4584(void *task, s32 *p) {
    switch (p[1]) {
    case 2:
        GX_SetBankForLCDC((GXVRamLCDC)1);
        break;
    case 6:
        GX_SetBankForLCDC((GXVRamLCDC)2);
        break;
    case 10:
        GX_SetBankForLCDC((GXVRamLCDC)4);
        break;
    case 14:
        GX_SetBankForLCDC((GXVRamLCDC)8);
        break;
    default:
        GX_SetBankForLCDC((GXVRamLCDC)0);
        break;
    }
    GX_SetGraphicsMode((GXDispMode)p[1], (GXBGMode)p[2], (GXBG0As)p[3]);
    p[12] = 1;
    SysTask_Destroy(task);
}

void ov01_021F45E4(s32 *p) {
    switch (p[0]) {
    case 2:
        MIi_CpuClearFast(0, (void *)0x06800000, 0x20000);
        break;
    case 6:
        MIi_CpuClearFast(0, (void *)0x06820000, 0x20000);
        break;
    case 10:
        MIi_CpuClearFast(0, (void *)0x06840000, 0x20000);
        break;
    case 14:
        MIi_CpuClearFast(0, (void *)0x06860000, 0x20000);
        break;
    }
    GX_SetCapture_Private((GXCaptureSize)p[3], (GXCaptureMode)p[4], (GXCaptureSrcA)p[5], (GXCaptureSrcB)p[6], (GXCaptureDest)p[7], 16, 0);
}
