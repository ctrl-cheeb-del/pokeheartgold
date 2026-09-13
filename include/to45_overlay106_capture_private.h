#ifndef TO45_OVERLAY_106_RESIDUAL_3_PRIVATE_H
#define TO45_OVERLAY_106_RESIDUAL_3_PRIVATE_H

#include "global.h"

typedef struct Ov106CaptureConfig {
    u32 words[11];
} Ov106CaptureConfig;

static inline void GX_SetCapture_Private(GXCaptureSize size, GXCaptureMode mode, GXCaptureSrcA srcA, GXCaptureSrcB srcB, GXCaptureDest dest, int eva, int evb) {
    reg_GX_DISPCAPCNT = REG_GX_DISPCAPCNT_FIELD(1, mode, 0, srcB, srcA, size, 0, dest, evb, eva);
}

extern void SysTask_Destroy(void *);
extern void DestroySysTaskAndEnvironment(void *);
extern void *CreateSysTaskAndEnvironment(void *, u32, u32, u32);
extern void *SysTask_GetData(void *);
extern u32 GX_GetBankForLCDC(void);
extern void *SysTask_CreateOnVWaitQueue(void *, void *, u32);

void *ov106_021E5E0C(void *);
void ov106_021E5E5C(void *, u32, u32, u32);
void ov106_021E5EE4(void *, s32 *);
void ov106_021E5F24(void *, s32 *);
void ov106_021E5F84(s32 *);

#endif
