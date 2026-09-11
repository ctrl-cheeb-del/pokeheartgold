#ifndef R20_OVERLAY57_PRIVATE_H
#define R20_OVERLAY57_PRIVATE_H
#include "global.h"
#define R20_U8(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define R20_U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define R20_PTR(p,o) (*(void **)((u8 *)(p)+(o)))

void SpriteManager_UnloadCharObjById(void *, u32);
void Sprite_DeleteAndFreeResources(void *);
void ManagedSprite_OffsetPositionXY(void *, s16, s16);
void *GF_3DVramMan_Create(u32, u32, u32, u32, u32, void (*)(void));
void ov57_02238B48(void);
void GF_AssertFail(void);
void sub_02014DA0(void);
void Thunk_G3X_Reset(void);
s32 sub_0201543C(void);
void NNS_G2dSetupSoftwareSpriteCamera(void);
void sub_02015460(void);
void RequestSwap3DBuffers(u32,u32);
void TouchscreenListMenu_Destroy(void *);
void ListMenuItems_Delete(void *);
void ManagedSprite_SetDrawFlag(void *,u32);
void ManagedSprite_SetPositionXY(void *,s16,s16);
void ManagedSprite_TickFrame(void *);
void TouchscreenListMenuSpawner_Destroy(void *);
void SpriteSystem_FreeResourcesAndManager(void *,void *);
void SpriteSystem_Free(void *);

void ov57_02238AC0(void *);
void ov57_02238AF0(void *,s32);
void ov57_02238B28(void);
void ov57_02238BCC(void);
void ov57_02238C0C(void);
void ov57_02238D80(void *);
void ov57_02238DAC(s32,s16 *,s16 *);
void ov57_02238F48(void *);
void ov57_02238FC4(void *);
void ov57_02238FEC(void *);
void ov57_022390F4(void *);
void ov57_0223921C(void *);
#endif
