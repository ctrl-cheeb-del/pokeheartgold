#ifndef TO45_OVERLAY57_PRIVATE_H
#define TO45_OVERLAY57_PRIVATE_H

#include "global.h"

#include "overlay_manager.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32_AT(p, o) (*(s32 *)((u8 *)(p) + (o)))

void *OverlayManager_GetArgs(OverlayManager *);
void *NARC_New(int, int);
u32 MenuInputStateMgr_GetState(void *);
void *AllocMonZeroed(int);
int SealCase_CountUniqueSeals(void *);
u8 ov57_02237E78(void *);
void *SealCase_inventory_Get(void *);
void *SealCase_GetCapsuleI(void *, int);
u32 GetMonData(void *, int, void *);
void ov57_0223BB5C(void);
void *ov57_02238B28(void);
void *BgConfig_Alloc(int);
void GF_CreateVramTransferManager(int, int);
void *PaletteData_Init(int);
void PaletteData_SetAutoTransparent(void *, int);
void PaletteData_AllocBuffers(void *, int, int, int);
void ov57_02237CEC(void *);
void ov57_02238BCC(void);
void *PokepicManager_Create(int);
void *sub_02016EDC(int, int, int);
int Options_GetFrame(void *);
void ov57_022395B8(void *, void *, int);
void ov57_02239670(void *, void *, int);
void ov57_02239058(void *);
void sub_020210BC(void);
void sub_02021148(int);
void ov57_0223BB84(void *);
void ov57_02237E38(void *);
void ov57_022386F0(void *);

void *ov57_0223A0E0(void *);
void ov57_02238C0C(void);
void PokepicManager_DrawAll(void *);
void PokepicManager_Delete(void *);
void GfGfx_EngineATogglePlanes(int, BOOL);
void GfGfx_EngineBTogglePlanes(int, BOOL);
void FreeBgTilemapBuffer(void *, int);
void Heap_Free(void *);
void PaletteData_FreeBuffers(void *, int);
void PaletteData_Free(void *);
void ov57_02237E80(void *, u8);
void ov57_022383AC(void *);
void TouchHitboxController_Destroy(void *);
void sub_02016F2C(void *);
void ov57_02238714(void *);
void ov57_022390F4(void *);
void GF_DestroyVramTransferManager(void);
void GF_3DVramMan_Delete(void *);
void ov57_02237CDC(int);
void NARC_Delete(void *);
void MenuInputStateMgr_SetState(void *, u32);
void sub_02021238(void);
void UnloadOverlayByID(int);
void Main_SetVBlankIntrCB(void (*)(void *), void *);
void HBlankInterruptDisable(void);
void GfGfx_DisableEngineAPlanes(void);
void GfGfx_DisableEngineBPlanes(void);
extern char SDK_OVERLAY_OVY_6_ID[];
extern char SDK_OVERLAY_OVY_7_ID[];

int ov57_02237AF8(OverlayManager *, int *);
int ov57_02237B20(OverlayManager *, int *);
int ov57_022378DC(OverlayManager *, int *);
void ov57_02237CA8(int);

#endif
