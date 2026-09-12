#ifndef POKEHEARTGOLD_OVERLAY102_GRAPHICS_R14_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY102_GRAPHICS_R14_PRIVATE_H

#include "global.h"

typedef struct Ov102StateR14 {
    void *work;
    void *arg1;
    void *arg2;
    u32 unused;
    u32 index;
    u32 state;
} Ov102StateR14;

void SysTask_Destroy(void *task);
void Heap_Free(void *ptr);
void GfGfx_DisableEngineAPlanes(void);
void GfGfx_DisableEngineBPlanes(void);
void *NARC_New(u32 id, u32 heapId);
void NARC_Delete(void *narc);
void GfGfx_EngineATogglePlanes(u32 planes, BOOL enable);
void GfGfx_EngineBTogglePlanes(u32 planes, BOOL enable);
void GX_DispOn(void);
void ov102_021E91C4(void *work);
void *ov102_021EA314(void *work, void *arg1, void *arg2);
void ov102_021EA41C(void *work, void *narc);
void *ov102_021EB1A4(void *work, void *arg1, void *arg2);
void ov102_021EB1F8(void *work, void *narc);
void *ov102_021EB694(void *work, void *arg1, void *arg2);
void ov102_021EB6E0(void *work, void *narc);
void *ov102_021EBC34(void *work, void *arg1, void *arg2);
void ov102_021EBD00(void *work);
void *ov102_021EC20C(void *work, void *arg1, void *arg2);
void ov102_021EC248(void *work, void *narc);
void GX_SetGraphicsMode(GXDispMode dispMode, GXBGMode bgMode, GXBG0As bg0As);
void GfGfx_SetBanks(const void *banks);
void SetBothScreensModesAndDisable(const void *modes);
void InitBgFromTemplate(void *bg, u32 layer, const void *template, u32 unused);
void BgClearTilemapBufferAndCommit(void *bg, u8 layer);
void FontID_Alloc(u32 fontId, u32 heapId);
BOOL IsPaletteFadeFinished(void);
void BeginNormalPaletteFade(u32 mask, s32 delay, s32 start, s32 end, u16 color, u32 duration, u32 heapId);

extern const u8 ov102_021EC760[];
extern const u8 ov102_021EC6A8[];
extern const u8 ov102_021EC728[];
extern const u8 ov102_021EC6D4[];
extern const u8 ov102_021EC6B8[];
extern const u8 ov102_021EC70C[];
extern const u8 ov102_021EC744[];
extern const u8 ov102_021EC6F0[];

void ov102_021E94A4(void *state);
void ov102_021E94CC(void *task, void *state);
void ov102_021E95E0(void *state, void *narc);
void ov102_021E978C(void *state);
void ov102_021E983C(void *task, void *state);

#endif
