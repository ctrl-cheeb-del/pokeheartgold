#ifndef OV70_RESIDUAL3_PRIVATE_H
#define OV70_RESIDUAL3_PRIVATE_H

#include <string.h>

#include "global.h"

typedef struct Ov70Pair8 {
    u32 a;
    u32 b;
} Ov70Pair8;

typedef struct Ov70Mac6 {
    u8 b[6];
} Ov70Mac6;

typedef struct Ov70Req8 {
    u8 b[6];
    s8 f6;
    s8 f7;
} Ov70Req8;

typedef struct Ov70Buf8 {
    u8 b[8];
} Ov70Buf8;

typedef struct Ov70Modes {
    u32 v[4];
} Ov70Modes;

typedef struct Ov70Banks {
    u32 v[10];
} Ov70Banks;

typedef struct Ov70Disp {
    int (*a)(void *);
    int (*b)(void *);
    int (*c)(void *, int);
} Ov70Disp;

extern u8 _02246800[];
extern u8 ov70_02246814[];
extern u8 ov70_022460A0[];
extern u8 ov70_022460EC[];
extern u8 ov70_0224613C[];
extern u8 ov70_02246184[];
extern u8 ov70_022461D0[];
extern u8 ov70_0224621C[];
extern u8 ov70_02246268[];
extern u8 ov70_022462B4[];
extern u8 ov70_02246304[];
extern u8 ov70_02246358[];
extern u8 ov70_022463A4[];
extern const Ov70Pair8 ov70_0224680C;
extern u8 ov70_02246900[];
extern u8 ov70_0224693C[];
extern u8 ov70_02246944[];
extern const Ov70Modes ov70_022451F8;
extern const Ov70Banks ov70_02245218;
extern const Ov70Disp ov70_022463EC[];

extern void ov38_0221BE84(void);
extern void ov38_0221BFEC(void);
extern int ov38_0221BEA8(void *, void *, void *, int, void *, int);

extern void GF_RunVramTransferTasks(void);
extern void DoScheduledBgGpuUpdates(void *);
extern void OamManager_ApplyAndResetBuffers(void);
extern void GfGfx_SetBanks(const void *);
extern void SetBothScreensModesAndDisable(const void *);
extern int WCM_GetPhase(void);
extern void ov00_021EC210(void);
extern void ov00_021ECB40(void);
extern void ov00_021EC294(void *, void *);
extern void Main_SetVBlankIntrCB(void *, void *);
extern void HBlankInterruptDisable(void);
extern void GfGfx_DisableEngineAPlanes(void);
extern void GfGfx_DisableEngineBPlanes(void);
extern void *Heap_Create(int, int, u32);
extern void Heap_Destroy(int);
extern void *Heap_Alloc(int, u32);
extern void Heap_Free(void *);
extern void LoadDwcOverlay(void);
extern void LoadOVY38(void);
extern void UnloadDwcOverlay(void);
extern void UnloadOVY38(void);
extern void sub_02039FD8(int);
extern void *OverlayManager_CreateAndGetData(void *, u32, int);
extern void *OverlayManager_GetData(void *);
extern void *OverlayManager_GetArgs(void *);
extern void OverlayManager_FreeData(void *);
extern void *BgConfig_Alloc(int);
extern void FontID_Alloc(int, int);
extern void FontID_Release(int);
extern void *MessageFormat_New_Custom(int, int, int);
extern void MessageFormat_Delete(void *);
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void DestroyMsgData(void *);
extern void SetKeyRepeatTimers(int, int);
extern void Sound_SetSceneAndPlayBGM(int, int, int);

extern void sub_02034D8C(void);
extern void sub_02034DE0(void);
extern int sub_02034DB8(void);
extern void TextFlags_SetCanTouchSpeedUpPrint(int);
extern int IsPaletteFadeFinished(void);
extern int PlayerProfile_GetTrainerGender(void *);
extern void SpriteList_RenderAndAnimateSprites(void);

extern void ov70_022378DC(void);
extern void ov70_02238880(void);
extern void ov70_0223887C(void *);
extern void ov70_02238DF8(void);
extern void ov70_02238E20(void);
extern void ov70_02238E50(void *, int, int);
extern void ov70_02238E70(void *);
extern void ov70_02238E98(void *);
extern void ov70_02238F04(void *);
extern void ov70_02238F24(void *);
extern void ov70_02239C6C(void *);
extern void ov70_02239CF8(void *);
extern void ov70_02240D74(void *, int);
extern void ov70_02241184(void *, void *, int);

void ov70_02237F64(void *a);
void ov70_02237FB4(void);
void ov70_02238008(void *b);
void ov70_02238058(void *b);
void ov70_022380A8(void);
void ov70_022380EC(void);
void ov70_02238130(void *src, int n, void *c);
void ov70_022381A4(void *src, void *c);
void ov70_02238208(void *a, void *b, void *c);
void ov70_0223826C(void);
void ov70_022382C0(void);
void ov70_02238304(void *a, void *b);
int ov70_02238360(void *a, void *b, int c, void *d, int e);
int ov70_02238398(int x);
int ov70_02238430(void *ovy, u32 *state);
int ov70_022385C0(void *ovy, u32 *state);
int ov70_022386F4(void *ovy);
void ov70_022387AC(u8 *work);
void ov70_022387F8(void);
void ov70_02238818(u8 *work, void *ovy);

#endif
