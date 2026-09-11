#ifndef OVERLAY_73_PRIVATE_H
#define OVERLAY_73_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "gf_gfx_planes.h"

typedef struct OverlayManager OverlayManager;

typedef struct Ov73Anim {
    /* 0x00 */ u32 active;
    /* 0x04 */ u32 frame;
    /* 0x08 */ s32 timer;
    /* 0x0C */ void *unk_0C;
    /* 0x10 */ void *pltt;
} Ov73Anim;

typedef struct Ov73Pair {
    u32 a;
    u32 b;
} Ov73Pair;

typedef struct Ov73Quad {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} Ov73Quad;

typedef struct Ov73Work {
    /* 0x0000 */ BgConfig *bgConfig;
    /* 0x0004 */ u32 unk_04;
    /* 0x0008 */ void *args;
    /* 0x000C */ u32 unk_0C;
    /* 0x0010 */ u32 unk_10;
    /* 0x0014 */ u32 unk_14;
    /* 0x0018 */ void *unk_18;
    /* 0x001C */ void *unk_1C;
    /* 0x0020 */ void *task;
    /* 0x0024 */ void *msgFmt;
    /* 0x0028 */ void *msgData;
    /* 0x002C */ void *strings[5];
    /* 0x0040 */ u32 unk_40;
    /* 0x0044 */ void *str44;
    /* 0x0048 */ void *str48;
    /* 0x004C */ u32 unk_4C;
    /* 0x0050 */ void *spriteList;
    /* 0x0054 */ u8 pad_54[0x17C - 0x54];
    /* 0x017C */ void *resObjMan[4];
    /* 0x018C */ u8 pad_18C[0x1AC - 0x18C];
    /* 0x01AC */ void *charTransferTask;
    /* 0x01B0 */ void *plttTransferTask;
    /* 0x01B4 */ u8 pad_1B4[0x298 - 0x1B4];
    /* 0x0298 */ u8 unk_298[0x314 - 0x298];
    /* 0x0314 */ void *menuState;
    /* 0x0318 */ u32 unk_318;
    /* 0x031C */ u8 pad_31C[0x338 - 0x31C];
    /* 0x0338 */ Ov73Pair arr_338[5];
    /* 0x0360 */ u32 arr_360[5];
    /* 0x0374 */ u32 unk_374;
    /* 0x0378 */ u8 unk_378[4];
    /* 0x037C */ void *unk_37C;
    /* 0x0380 */ u8 pad_380[0x388 - 0x380];
    /* 0x0388 */ u8 unk_388[0x4A0C - 0x388];
    /* 0x4A0C */ void *unk_4A0C;
    /* 0x4A10 */ u32 unk_4A10;
    /* 0x4A14 */ u8 unk_4A14;
    /* 0x4A15 */ u8 unk_4A15;
    /* 0x4A16 */ u16 unk_4A16;
    /* 0x4A18 */ u32 unk_4A18;
    /* 0x4A1C */ u32 unk_4A1C;
    /* 0x4A20 */ u32 unk_4A20;
    /* 0x4A24 */ u32 unk_4A24;
    /* 0x4A28 */ u8 pad_4A28[0x4A3C - 0x4A28];
    /* 0x4A3C */ Ov73Quad arr_4A3C[5];
} Ov73Work;

extern const GraphicsBanks ov73_021EA5E8;
extern const GraphicsModes ov73_021EA540;
extern const BgTemplate ov73_021EA5B0;
extern const BgTemplate ov73_021EA5CC;
extern const BgTemplate ov73_021EA578;
extern const BgTemplate ov73_021EA594;
extern const u8 ov73_021EA52A[];
extern const u8 ov73_021EA52B[];
extern int (*_021EA7C0[])(Ov73Work *);

extern void HBlankInterruptDisable(void);
extern void Heap_Free(void *);
extern void *NARC_New(int, int);
extern void NARC_Delete(void *);
extern void *OverlayManager_CreateAndGetData(OverlayManager *, int, int);
extern void *OverlayManager_GetData(OverlayManager *);
extern void *OverlayManager_GetArgs(OverlayManager *);
extern void OverlayManager_FreeData(OverlayManager *);
extern void *MenuInputStateMgr_GetState(void *);
extern void MenuInputStateMgr_SetState(void *, void *);
extern void *MessageFormat_New(int);
extern void MessageFormat_Delete(void *);
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void DestroyMsgData(void *);
extern void ReadMsgDataIntoString(void *, u32, void *);
extern void FontID_Alloc(int, int);
extern void FontID_Release(int);
extern void SetKeyRepeatTimers(int, int);
extern void SetMasterBrightnessNeutral(int);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern int IsPaletteFadeFinished(void);
extern void *String_New(int, int);
extern void String_Delete(void *);
extern void *SysTask_CreateOnVBlankQueue(void *, void *, int);
extern void SysTask_Destroy(void *);
extern void SpriteList_RenderAndAnimateSprites(void *);
extern void SpriteList_Delete(void *);
extern void SpriteTransfer_DeleteCharTransferTask(void *);
extern void SpriteTransfer_DeletePlttTransferTask(void *);
extern void Destroy2DGfxResObjMan(void *);
extern void OamManager_Free(void);
extern void OamManager_ApplyAndResetBuffers(void);
extern void ObjCharTransfer_Destroy(void);
extern void ObjPlttTransfer_Destroy(void);
extern void GF_RunVramTransferTasks(void);
extern void DoScheduledBgGpuUpdates(BgConfig *);
extern void *GfGfxLoader_GetPlttDataFromOpenNarc(void *, int, void *, int);
extern void Sound_SetSceneAndPlayBGM(int, int, int);
extern void *sub_0205B4A4(int);
extern void sub_0205AD24(void *);
extern void sub_0205A904(int);
extern void sub_020210BC(void);
extern void sub_02021148(int);
extern void sub_02021238(void);
extern void sub_0208FB64(void *);
extern void sub_0203893C(void);
extern void sub_02038C1C(int);
extern int sub_0203769C(void);
extern void sub_0203A880(void);
extern void sub_02037FF0(void);
extern void sub_02037030(int, int, int);
extern u32 sub_02033250(void);

extern void ov73_021E5F38(Ov73Work *, void *);
extern void ov73_021E5F0C(BgConfig *);
extern void ov73_021E6060(void);
extern void ov73_021E6090(Ov73Work *, void *);
extern void ov73_021E6184(Ov73Work *);
extern void ov73_021E629C(Ov73Work *, OverlayManager *);
extern void ov73_021E7230(Ov73Work *);
extern void ov73_021E6400(Ov73Work *);
extern void ov73_021E6048(Ov73Work *);
extern void ov73_021EA374(void *, void *);
extern void ov73_021E72F4(void *);
extern int ov73_021E746C(void);
extern void ov73_021E735C(void *, int, u32, Ov73Work *);
extern void ov73_021E762C(Ov73Work *);
extern int ov73_021E7870(Ov73Work *, int);
extern void ov73_021E7740(Ov73Work *, void *);
extern void ov73_021E77E8(Ov73Work *);

int ov73_021E5900(OverlayManager *mgr, u32 *state);
int ov73_021E5AB8(OverlayManager *mgr, u32 *state);
int ov73_021E5BAC(OverlayManager *mgr, u32 *state);
void ov73_021E5C74(void *task, Ov73Work *work);
void ov73_021E5CD8(Ov73Work *work);
void ov73_021E5D00(void);
void ov73_021E5D20(BgConfig *bgConfig);
void ov73_021E5E0C(Ov73Work *work, void *narc);
void ov73_021E5ED4(Ov73Work *work);

#endif
