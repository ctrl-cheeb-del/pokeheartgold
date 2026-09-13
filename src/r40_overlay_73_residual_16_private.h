#ifndef SOL40_R40_OV73_16_PRIVATE_H
#define SOL40_R40_OV73_16_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
void ov73_021E7D74(void *, int, void *, void *, void *, void *, int);
void *OverlayManager_GetData(void *);
void Heap_Free(void *);
void UnloadOVY38(void);
void UnloadDwcOverlay(void);
void ov73_021E847C(void *);
void DestroyMsgData(void *);
void MessageFormat_Delete(void *);
void ov73_021E8164(void *);
void sub_02034DE0(void);
void OverlayManager_FreeData(void *);
void Main_SetVBlankIntrCB(void *, void *);
void Heap_Destroy(int);
void GF_RunVramTransferTasks(void);
void DoScheduledBgGpuUpdates(void *);
void OamManager_ApplyAndResetBuffers(void);
typedef struct {
    u32 v[10];
} SolBanks;
extern SolBanks ov73_021EA6AC;
void GfGfx_SetBanks(void *);
void ov00_021ECB40(void);
void ov72_022378DC(void);
int sub_02034DB8(void);
extern void *_021EA940[];
void *ov73_021E83F4(void *, u32, s32);
void ov73_021E841C(void *, void *);
void ov00_021EC294(void *, void *);
int IsPaletteFadeFinished(void);
void SpriteList_RenderAndAnimateSprites(void *);
typedef int (*SolFn1)(void *);
typedef int (*SolFn2)(void *, int);
typedef struct {
    SolFn1 f;
    u32 pad[2];
} SolTable1;
typedef struct {
    SolFn2 f;
    u32 pad[2];
} SolTable2;
extern SolTable1 ov73_021EA83C[];
extern SolTable1 ov73_021EA840[];
extern SolTable2 ov73_021EA844[];
#endif
