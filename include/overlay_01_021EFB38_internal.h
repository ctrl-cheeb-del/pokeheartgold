#ifndef PRIVATE_OVERLAY_01_021EFB38_H
#define PRIVATE_OVERLAY_01_021EFB38_H

#include <nitro/os/tick.h>

#include "global.h"

#include "poke_overlay.h"

typedef void (*OverlayEffectCallback)(void *, void *);
typedef struct OverlayEffectGlobal {
    void *unk0;
    s32 callbackIndex;
    u32 callCount;
} OverlayEffectGlobal;

extern u8 SDK_OVERLAY_OVY_114_ID;
extern u8 SDK_OVERLAY_OVY_115_ID;
extern u8 SDK_OVERLAY_OVY_116_ID;
extern u8 SDK_OVERLAY_OVY_117_ID;
extern u8 SDK_OVERLAY_OVY_118_ID;
extern u8 SDK_OVERLAY_OVY_119_ID;
extern u8 SDK_OVERLAY_OVY_120_ID;
#define LOCAL_OVERLAY_ID(name) ((FSOverlayID) & SDK_OVERLAY_##name##_ID)

extern OverlayEffectGlobal ov01_02209B64;
extern const OverlayEffectCallback ov01_022068C4[];

void ov01_021EFB38(void *, void *);
void ov01_021EFB64(s32);
void ov01_021EFC04(s32);

#endif
