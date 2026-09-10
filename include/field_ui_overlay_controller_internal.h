#ifndef UNK_020850F4_PRIVATE_H
#define UNK_020850F4_PRIVATE_H

#include "global.h"

#include "system.h"

typedef struct SummaryOverlayArgs {
    u32 words[13];
} SummaryOverlayArgs;

typedef struct SummaryAppData {
    u8 pad000[0x2EC];
    void *narc;
    void *spriteSystem;
    void *spriteManager;
    void *bgConfig;
    void *paletteData;
    void *touchController;
    u8 pad304[0xB4];
    SummaryOverlayArgs args;
    u8 tail3EC[8];
} SummaryAppData;

typedef struct SummaryStringData {
    u32 length;
    u32 values[5];
    u32 pad18;
    void *string;
    u32 param20;
    u32 param24;
    u32 param28;
    u32 param2C;
    u32 param30;
} SummaryStringData;

typedef struct SummaryGfxBanks {
    u32 words[10];
} SummaryGfxBanks;

typedef struct SummaryBgTemplate {
    u32 words[7];
} SummaryBgTemplate;

typedef struct SummaryBgTemplates3 {
    SummaryBgTemplate items[3];
} SummaryBgTemplates3;

typedef struct SummaryBgTemplates4 {
    SummaryBgTemplate items[4];
} SummaryBgTemplates4;

extern void *OverlayManager_GetData(void *);
extern void OverlayManager_FreeData(void *);
extern void *OverlayManager_CreateAndGetData(void *, u32, enum HeapID);
extern SummaryOverlayArgs *OverlayManager_GetArgs(void *);
extern BOOL sub_02085BEC(SummaryAppData *);
extern int ov00_021EC9D4(void *);
extern void sub_0203A930(int);
extern void *String_New(u32, u32);
extern void String_Delete(void *);
extern void GF_AssertFail(void);
extern void GF_RunVramTransferTasks(void);
extern void SpriteSystem_TransferOam(void);
extern void PaletteData_PushTransparentBuffers(void *);
extern void DoScheduledBgGpuUpdates(void *);
extern void sub_0203A914(void *);
extern void sub_020866CC(SummaryAppData *);
extern void GfGfx_EngineATogglePlanes(u32, BOOL);
extern void GfGfx_EngineBTogglePlanes(u32, BOOL);
extern void FreeBgTilemapBuffer(void *, u32);
extern void PaletteData_FreeBuffers(void *, u32);
extern void PaletteData_Free(void *);
extern void NARC_Delete(void *);
extern void sub_02021238(void);
extern void SpriteSystem_FreeResourcesAndManager(void *, void *);
extern void SpriteSystem_Free(void *);
extern void TouchHitboxController_Destroy(void *);
extern void GfGfx_DisableEngineAPlanes(void);
extern void GfGfx_SetBanks(const void *);
extern void InitBgFromTemplate(void *, u32, const SummaryBgTemplate *, u32);
extern void BgClearTilemapBufferAndCommit(void *, u32);
extern void GfGfx_SwapDisplay(void);
extern void Main_SetVBlankIntrCB(void (*)(void *), void *);
extern void HBlankInterruptDisable(void);
extern void GfGfx_DisableEngineBPlanes(void);
extern void *NARC_New(u32, enum HeapID);
extern void *BgConfig_Alloc(enum HeapID);
extern void *PaletteData_Init(enum HeapID);
extern void PaletteData_SetAutoTransparent(void *, BOOL);
extern void PaletteData_AllocBuffers(void *, u32, u32, enum HeapID);
extern void sub_020863F4(SummaryAppData *);
extern void sub_02085688(SummaryAppData *);
extern void sub_020210BC(void);
extern void sub_02021148(u32);
extern void sub_020860B8(SummaryAppData *);
extern void sub_0203A880(void *);
extern void sub_0203A948(u32, enum HeapID);
extern const SummaryGfxBanks _02102630;
extern const SummaryBgTemplates3 _02102658;
extern const SummaryBgTemplates4 _021026AC;

int sub_0208524C(void *);
int sub_0208527C(void *);
SummaryStringData *sub_020853B4(enum HeapID, u32, const u32 *, u32, u32, u32);
SummaryStringData *sub_02085400(enum HeapID, u32, const u32 *, u32, u32, u32);
SummaryStringData *sub_0208541C(enum HeapID, u32, const u32 *, u32, u32, u32, u32, u32);
void sub_02085438(SummaryStringData *);
void sub_0208545C(void *);
void sub_020855CC(SummaryAppData *);

#endif
int sub_020850F4(void *);
