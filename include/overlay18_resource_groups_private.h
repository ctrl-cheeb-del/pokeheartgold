#ifndef SOL_R40_NIGHT_OVERLAY18_RESIDUAL40_PRIVATE_H
#define SOL_R40_NIGHT_OVERLAY18_RESIDUAL40_PRIVATE_H
#include "global.h"
void *G2dRenderer_Init(int, void *, int);
void ClearMainOAM(int);
void GfGfx_EngineBTogglePlanes(u32, u32);
void SpriteTransfer_DeleteCharTransferTask(void *);
void DestroySingle2DGfxResObj(void *, void *);
void ov18_021F8F28(void *);
void ov18_021F8F60(void *);
void ov18_021F8FF8(void *);
void ov18_021F9068(void *);
void ov18_021F9150(void *);
void ov18_021F94BC(void *);
void ov18_021F9370(void *);
void ov18_021F9518(void *);
void ov18_021F92DC(void *, void *);
void ov18_021F922C(void *, void *, u32, void *, s32, s32, s32, s32, u32, u32, u32, u32, u32);
void *ov18_021F92AC(void *, u32, void *, s32, u32, u32);
u32 ov18_021F967C(u32);
u32 ov18_021E5900(void);
s32 ov18_021E5908(void);
void *NARC_New(u32, u32);
void NARC_Delete(void *);
u32 SpriteTransfer_GetPlttOffset(void *, u32);
void PaletteData_LoadPaletteSlotFromHardware(void *, u32, u16, u32);
void ov18_021F8FA0(void *);
void ov18_021F8FF8(void *);
void ov18_021F9054(void *);
void ov18_021F9068(void *);
void ov18_021F9108(void *);
void ov18_021F9150(void *);
void ov18_021F91DC(void *);
#endif
