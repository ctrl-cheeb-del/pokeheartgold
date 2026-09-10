#include "global.h"

typedef struct Overlay01CaptureConfigPrivate {
    u32 words[11];
} Overlay01CaptureConfigPrivate;

static inline void GX_SetCapture_Private(GXCaptureSize size, GXCaptureMode mode, GXCaptureSrcA srcA, GXCaptureSrcB srcB, GXCaptureDest dest, int eva, int evb) {
    reg_GX_DISPCAPCNT = REG_GX_DISPCAPCNT_FIELD(1, mode, 0, srcB, srcA, size, 0, dest, evb, eva);
}

extern void SysTask_Destroy(void *);
extern void DestroySysTaskAndEnvironment(void *);
extern void *CreateSysTaskAndEnvironment(void *, u32, u32, u32);
extern void *SysTask_GetData(void *);
extern u32 GX_GetBankForLCDC(void);
extern void *SysTask_CreateOnVWaitQueue(void *, void *, u32);

void *ov01_021F4464(void *);
void ov01_021F44B4(void **, u32, u32, u32);
void ov01_021F4544(void *, s32 *);
void ov01_021F4584(void *, s32 *);
void ov01_021F45E4(s32 *);
