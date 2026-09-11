#ifndef OVERLAY_32_PRIVATE_H
#define OVERLAY_32_PRIVATE_H

#include "global.h"

#include "gf_gfx_loader.h"

typedef struct Ov32Window {
    u32 raw[4];
} Ov32Window;

extern const BgTemplate ov32_0225E1A4;
extern const BgTemplate ov32_0225E1C0;
extern const BgTemplate ov32_0225E188;

extern void GF_AssertFail(void);
extern void *NewMsgDataFromNarc();
extern void *MessageFormat_New();
extern void MessageFormat_Delete();
extern void DestroyMsgData();
extern void RemoveWindow();
extern void SpriteList_Delete();
extern void *Create2DGfxResObjMan();
extern void Destroy2DGfxResObjMan();
extern void GridInputHandler_Free();
extern void Sprite_Delete();
extern void Sprite_UpdateAnim();
extern void SpriteTransfer_DeleteCharTransferTask();
extern void SpriteTransfer_DeletePlttTransferTask();
extern void *SysTask_GetData();
extern void DestroySysTaskAndEnvironment();
extern void FontID_Release();
extern void Heap_Destroy();
extern void *CreateSysTaskAndEnvironment();
extern void *sub_0202C6F4();
extern void FontID_Alloc();
extern void ov32_0225D788();
extern void ov32_0225DA88();
extern void ov32_0225DD74();
extern int ov32_0225DE34();
extern void ov32_0225D84C();
extern void ov32_0225D988();
extern void SpriteList_RenderAndAnimateSprites();

int ov32_0225D608(void);
void *ov32_0225D520(void *, void *, void *, void *);
void ov32_0225D60C(void);
void ov32_0225D634(BgConfig *);
void ov32_0225D5CC(void *, void *);
void ov32_0225D6C4(BgConfig *);
void ov32_0225D6E0(u8 *, NARC *);
void ov32_0225D748(u8 *);
void ov32_0225D76C(u8 *);
void ov32_0225D834(u8 *);
void ov32_0225DAC0(u8 *);
void ov32_0225DADC(u8 *);
void ov32_0225DB00(u8 *);
void ov32_0225DCD4(u8 *);
void ov32_0225DD04(u8 *);
void ov32_0225DDAC(u8 *);
void ov32_0225DDB8(void);
void ov32_0225DDBC(u8 *);
int ov32_0225DF80(u8 *);
int ov32_0225E048(u8 *);
void ov32_0225DFE8(u8 *, u8);
int ov32_0225DD24(u8 *);
void ov32_0225DDC4(u8 *, u8 *);
void ov32_0225DF9C(u8 *, int);
int ov32_0225E0A8(u8 *, u8, u8, u8, u8);

#endif
