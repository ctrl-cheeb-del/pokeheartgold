#ifndef POKEHEARTGOLD_OVERLAY67_FLOW_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY67_FLOW_INTERNAL_H

#include "global.h"

typedef struct OverlayManager OverlayManager;
typedef struct {
    u8 raw[0x4AC];
} Ov67State;

void *OverlayManager_GetData(OverlayManager *manager);
void BeginNormalPaletteFade(u32, u32, u32, u16, u8, u8, u32);
BOOL IsPaletteFadeFinished(void);
void Main_SetVBlankIntrCB(void (*callback)(void *), void *arg);
void HBlankInterruptDisable(void);
void GfGfx_DisableEngineAPlanes(void);
void GfGfx_DisableEngineBPlanes(void);
void ResetVisibleHardwareWindows(u8 engine);

BOOL ov67_021E5984(OverlayManager *manager, int *step);
BOOL ov67_021E5A6C(Ov67State *state);
BOOL ov67_021E5B44(Ov67State *state);
void ov67_021E5BC0(void);
void ov67_021E5BE0(void *state);
int ov67_021E5C04(Ov67State *state);
int ov67_021E5C44(Ov67State *state);
void ov67_021E5DA0(Ov67State *state);
void ov67_021E5E84(Ov67State *state);
void ov67_021E5EB0(Ov67State *state);
void ov67_021E6008(Ov67State *state);
void ov67_021E6080(Ov67State *state);
void ov67_021E60B4(Ov67State *state);
void ov67_021E60F4(Ov67State *state);
void ov67_021E6220(Ov67State *state);
void ov67_021E63E8(Ov67State *state);
void ov67_021E6474(Ov67State *state);
void ov67_021E65C0(Ov67State *state);
void ov67_021E681C(Ov67State *state);
void ov67_021E6820(Ov67State *state);
void ov67_021E6990(Ov67State *state);
void ov67_021E69D8(Ov67State *state);
BOOL ov67_021E6A40(Ov67State *state);
void ov67_021E6BC4(Ov67State *state);
void ov67_021E6C04(Ov67State *state);

#endif
