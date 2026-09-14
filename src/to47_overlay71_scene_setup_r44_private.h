#ifndef TO47_R4_OVERLAY71_R44_PRIVATE_H
#define TO47_R4_OVERLAY71_R44_PRIVATE_H

#include "global.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

typedef BOOL (*Ov71DisplayStateFunc)(void *work, u32 *substate);
typedef struct Ov71Rotation {
    u16 x;
    u16 y;
    u16 z;
} Ov71Rotation;

extern void *Heap_Alloc(u32 heapId, u32 size);
extern void Heap_Free(void *ptr);
extern void *String_New(u32 size, u32 heapId);
extern void String_Delete(void *string);
extern void *NARC_New(u32 narcId, u32 heapId);
extern void NARC_Delete(void *narc);
extern void *PokepicManager_Create(u32 heapId);
extern void PokepicManager_Delete(void *manager);
extern void Pokepic_Delete(void *pokepic);
extern void FreeBgTilemapBuffer(void *bgConfig, u32 layer);
extern void RemoveWindow(void *window);
extern void G3X_Reset(void);
extern void NNS_G3dGeFlushBuffer(void);
extern void NNS_G2dSetupSoftwareSpriteCamera(void);
extern void PokepicManager_HandleLoadImgAndOrPltt(void *manager);
extern void PokepicManager_DrawAll(void *manager);
extern void RequestSwap3DBuffers(u32, u32);

extern void *ov71_02247384(void *ctx);
extern void ov71_02247498(void *camera);
extern void ov71_022474CC(void *camera);
extern void ov71_0224B970(void *work);
extern void ov71_0224B8EC(void *work);
extern void ov71_0224BA48(void *task);
extern Ov71DisplayStateFunc ov71_0224BF84[4];
extern u8 ov71_0224BFDC[];
extern u8 ov71_0224BF94[];
extern u8 ov71_0224BFA4[];
extern u8 ov71_0224BFC0[];
extern const Ov71Rotation ov71_0224BF7C;

extern void GfGfx_SetBanks(const void *banks);
extern void SetBothScreensModesAndDisable(const void *modes);
extern void InitBgFromTemplate(void *bg, u32 layer, const void *template, u32 unused);
extern void GfGfx_EngineATogglePlanes(u8 planes, u8 enable);
extern void GfGfx_EngineBTogglePlanes(u8 planes, u8 enable);
extern void BG_FillCharDataRange(void *bg, u32 layer, u32 value, u32 count, u32 offset);
extern void FillBgTilemapRect(void *bg, u32 layer, u32 value, u32 x, u32 y, u32 width, u32 height, u32 palette);
extern u32 ov71_022473D0(void *ctx);
extern void LoadUserFrameGfx2(void *bg, u32 layer, u32 tile, u32 palette, u8 frame, u32 heapId);
extern void AddWindowParameterized(void *bg, void *window, u32 layer, u32 palette, u32 x, u32 y, u32 width, u32 height, u32 baseTile);
extern void FillWindowPixelBuffer(void *window, u32 value);
extern void GfGfxLoader_GXLoadPal(u32 narc, u32 member, u32 location, u32 offset, u32 size, u32 heapId);
extern void BgCommitTilemapBufferToVram(void *bg, u32 layer);
extern void GfGfxLoader_LoadCharData(u32 narc, u32 member, void *bg, u32 layer, u32 tileStart, u32 size, u32 compressed, u32 heapId);
extern void GfGfxLoader_LoadScrnData(u32 narc, u32 member, void *bg, u32 layer, u32 tileStart, u32 size, u32 compressed, u32 heapId);
extern void ov71_0224B720(void *work);
extern void *ov71_0224744C(u32, u32, u32, u32);
extern void *ov71_0224B7EC(void *work);
extern void Pokepic_SetAttr(void *pic, u32 attr, u32 value);
extern void *ov71_02247610(void *camera, u32, u32, u32, u32, u32, u32, u32);
extern void ov71_022476EC(void *camera, const void *rotation);
extern void ov71_0224B848(void *work);
extern void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);

void *ov71_0224B138(void *ctx);
void ov71_0224B198(void *work);
BOOL ov71_0224B1FC(void *work, u32 *state);
void ov71_0224B234(void *work);
BOOL ov71_0224B280(void *work);

#endif
