#ifndef OV95_R9_PRIVATE_H
#define OV95_R9_PRIVATE_H

#include "global.h"

#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define PTR_AT(p, n) (*(void **)((u8 *)(p) + (n)))

extern u32 ov95_021E5EDC();
extern u32 ov95_021E6150();
extern void ov95_021E5EC0();
extern void ManagedSprite_SetAnimationFrame();
extern BOOL PlaySE(u16);

extern void Main_SetVBlankIntrCB();
extern void HBlankInterruptDisable(void);
extern void Heap_Create();
extern void Heap_Destroy();
extern void *OverlayManager_CreateAndGetData();
extern void *OverlayManager_GetArgs();
extern void *OverlayManager_GetData();
extern void OverlayManager_FreeData();
extern u32 Options_GetTextFrameDelay();
extern u32 Options_GetFrame();
extern void *ov95_021E5954();
extern void *PokepicManager_Create();
extern void PokepicManager_Delete();
extern void *NARC_New();
extern void NARC_Delete();
extern void *BgConfig_Alloc();
extern void *GF_CreateVramTransferManager();
extern void GF_DestroyVramTransferManager(void);
extern void *sub_02016EDC();
extern void sub_02016F2C();
extern void *PaletteData_Init();
extern void PaletteData_SetAutoTransparent();
extern void PaletteData_AllocBuffers();
extern void PaletteData_LoadNarc();
extern void PaletteData_FreeBuffers();
extern void PaletteData_Free();
extern void ov95_021E5900(void);
extern void ov95_021E5928(void);
extern void ov95_021E59F8(void);
extern void ov95_021E5A38();
extern void ov95_021E6FC4();
extern void ov95_021E619C();
extern void TextFlags_SetCanTouchSpeedUpPrint();
extern void *ov95_021E7020();
extern void Sound_Stop(void);
extern void ov95_021E5B24(void);
extern u32 IsPaletteFadeFinished(void);
extern u32 GetMonData();
extern void sub_020729A4();
extern u32 ov95_021E6300();
extern void PokepicManager_DrawAll();
extern void ov95_021E5B58(void);
extern void ov95_021E7078();
extern void GF_3DVramMan_Delete();
extern void GfGfx_EngineATogglePlanes();
extern void GfGfx_EngineBTogglePlanes();
extern void FreeBgTilemapBuffer();
extern void Heap_Free();
extern void ov95_021E6228();
extern void Field_SetEnvironmentSoundState_None_Unk2(void);

BOOL ov95_021E6838(void *work);
BOOL ov95_021E68A8(void *work);
BOOL ov95_021E6900(void *work);
BOOL HatchEggApp_Init(void *manager, int *state);
BOOL HatchEggApp_Main(void *manager, int *state);
BOOL HatchEggApp_Exit(void *manager, int *state);

#endif
