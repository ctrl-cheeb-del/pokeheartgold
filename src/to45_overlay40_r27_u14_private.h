#ifndef TO45_OV40_R27_U14_PRIVATE_H
#define TO45_OV40_R27_U14_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))

void BgClearTilemapBufferAndCommit(void *, int);
void G2x_SetBlendAlpha_(u32, int, int, int, int);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void GfGfx_EngineATogglePlanes(int, int);
void GfGfx_EngineBTogglePlanes(int, int);
void HandleLoadOverlay(u32, int);
void *Heap_Alloc(int, u32);
void Heap_Free(void *);
void Main_SetVBlankIntrCB(void (*)(void *), void *);
void PaletteData_BlendPalettes(void *, int, u16, u8, u16);
void PaletteData_LoadPaletteSlotFromHardware(void *, int, int, u32);
void PlaySE(int);
void RequestSwap3DBuffers(int, int);
void *Save_FashionData_Get(void *);
void SetBgPriority(int, int);
void Thunk_G3X_Reset(void);
void *memset(void *, int, u32);
void ov40_0222BC44(int);
void ov40_0222BF64(void *, int, int, u32);
void ov40_0222BF80(void *, int);
void ov40_0222D874(void *);
void ov40_0222D88C(void *);
void ov40_0222D9E8(void *, void *, int);
BOOL ov40_0222DA00(void *, void *, int, int);
BOOL ov40_0222DA84(void *, int);
void ov40_0222DAA8(void *);
void ov40_0222DD08(void *);
void ov40_0222FB90(void *, int);
BOOL ov40_0222FBB4(void *);
void ov40_022307DC(void *, int, int);
void ov40_02230964(void *, int);
void ov40_0223320C(void *);
void ov40_022338D0(void *);
BOOL ov40_02233AEC(void *);
void ov40_02235900(void *);
void ov40_02235940(void *);
void ov40_02235A30(void *);
void ov40_02235B4C(void *);
void *ov41_0224B530(void *, void *);
void ov41_0224B554(void *);
void ov41_0224B5D0(void *, int);
void *sub_0202B998(int);
void *sub_0202B9B8(void *, int);
void *sub_020314A4(int);
void sub_020879E0(void *, int);
extern u32 SDK_OVERLAY_OVY_41_ID;

int ov40_02233F28(void *);
int ov40_0223414C(void *);
int ov40_022341E0(void *);
int ov40_02234330(void *);

#endif
