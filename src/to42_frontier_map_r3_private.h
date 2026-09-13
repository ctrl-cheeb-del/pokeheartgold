#ifndef POKEHEARTGOLD_FRONTIER_MAP_RESIDUAL_3_H
#define POKEHEARTGOLD_FRONTIER_MAP_RESIDUAL_3_H

#include "global.h"

typedef struct BgTemplate {
    u32 x;
    u32 y;
    u32 bufferSize;
    u32 baseTile;
    u8 size;
    u8 colorMode;
    u8 screenBase;
    u8 charBase;
    u8 bgExtPltt;
    u8 priority;
    u8 areaOver;
    u8 dummy;
    u32 mosaic;
} BgTemplate;

typedef struct GraphicsModes {
    u32 dispMode;
    u32 bgMode;
    u32 subMode;
    u32 _2d3dMode;
} GraphicsModes;

typedef struct GraphicsBanks {
    u32 bg;
    u32 bgextpltt;
    u32 subbg;
    u32 subbgextpltt;
    u32 obj;
    u32 objextpltt;
    u32 subobj;
    u32 subobjextpltt;
    u32 tex;
    u32 texpltt;
} GraphicsBanks;

typedef struct FrontierMapSub1C {
    u32 unk00;
} FrontierMapSub1C;

typedef struct FrontierMapEntry {
    void *unk00;
    void *unk04;
} FrontierMapEntry;

typedef struct FrontierMap {
    /* 0x00 */ void *bgConfig;
    /* 0x04 */ void *plttData;
    /* 0x08 */ void *unk08;
    /* 0x0C */ void *unk0C;
    /* 0x10 */ void *unk10;
    /* 0x14 */ void *unk14;
    /* 0x18 */ void *unk18;
    /* 0x1C */ FrontierMapSub1C unk1C;
    /* 0x20 */ void *unk20;
    /* 0x24 */ void *unk24;
    /* 0x28 */ void *unk28;
    /* 0x2C */ void *unk2C;
    /* 0x30 */ void *unk30;
    /* 0x34 */ void *unk34;
    /* 0x38 */ void *unk38;
    /* 0x3C */ void *unk3C[8];
    /* 0x5C */ u16 unk5C[8];
    /* 0x6C */ u32 unk6C;
    /* 0x70 */ u16 unk70[8];
    /* 0x80 */ void *unk80[4];
    /* 0x90 */ u8 unk90[0xA8 - 0x90];
    /* 0xA8 */ s16 unkA8;
    /* 0xAA */ s16 unkAA;
    /* 0xAC */ u8 unkAC[0xC1 - 0xAC];
    /* 0xC1 */ u8 unkC1;
    /* 0xC2 */ u8 unkC2[0xC4 - 0xC2];
} FrontierMap;

typedef struct FrontierMapUnk11 {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
    u8 f08;
    u8 f09;
    u8 f0A;
} FrontierMapUnk11;

typedef struct FrontierMapEvtA {
    u32 unk00;
    u32 unk04;
} FrontierMapEvtA;

typedef struct FrontierMapEvtB {
    u32 unk00;
} FrontierMapEvtB;

typedef struct FmPlttData {
    u32 unk00;
    u32 unk04;
    u32 szByte;
    void *pRawData;
} FmPlttData;

/* ---- data owned by assembly ---- */
extern const GraphicsBanks ov80_0223D5D8;
extern const GraphicsModes ov80_0223D560;
extern const BgTemplate ov80_0223D600[3];
extern const BgTemplate ov80_0223D59C;
extern const FrontierMapUnk11 ov80_0223D554;
extern const u8 ov80_0223D654[];

/* ---- callees ---- */
void *Frontier_GetLaunchArgs(void *ctx);
u32 ov80_0222ACA0(u32 a0, u32 a1);
int ov80_0222A7EC(void *profile);
u32 ov80_02239A38(void);

FrontierMapEntry *sub_0209686C(void *a0, u32 idx);

void ov42_02229358(FrontierMapSub1C *a0, void *a1);
void ov42_022290DC(void *a0);
void ov42_02229420(void *a0, FrontierMapSub1C *a1);
u16 ov42_022293A8(FrontierMapSub1C *a0);
u16 ov42_022293B0(FrontierMapSub1C *a0);
void *ov42_022293B8(void *a0, void *a1, const FrontierMapUnk11 *a2, u32 heapId);
void ov42_02229394(FrontierMapSub1C *a0);
s32 ov42_02229A08(void *a0, FrontierMapEvtA *a1);
void ov42_02228068(void *a0, FrontierMapEvtA *a1);
u32 ov42_02229AC8(void *a0, FrontierMapEvtB *a1);
s32 ov42_02228C80(void *a0, void *a1, FrontierMapEvtB *a2, FrontierMapEvtA *a3);
void *ov42_02228010(u32 a0, u32 heapId);
void *ov42_02227EE0(u16 a0, u16 a1, u32 heapId);
void *ov42_02228F24(void *a0, void *a1, u16 a2, s32 a3, s32 a4, s32 a5, u32 heapId);
void *ov42_02229A40(s32 a0, u32 heapId);
void *ov42_02229974(s32 a0, u32 heapId);
void ov42_02227F48(void *a0, const void *a1);

void ManagedSprite_TickFrame(void *a0);
void SpriteSystem_DrawSprites(void *a0);
void SpriteSystem_UpdateTransfer(void);
void *SpriteSystem_GetRenderer(void *a0);
void *SpriteManager_GetSpriteList(void *a0);
void G2dRenderer_SetMainSurfaceCoords(void *a0, s32 x, s32 y);
void RequestSwap3DBuffers(u32 a0, u32 a1);

void GfGfx_DisableEngineAPlanes(void);
void GfGfx_SetBanks(const GraphicsBanks *banks);
void GfGfx_EngineATogglePlanes(u8 planeMask, u8 enable);
void SetBothScreensModesAndDisable(const GraphicsModes *modes);
void InitBgFromTemplate(void *bgConfig, u8 bgId, const BgTemplate *tmpl, u8 bgType);
void BgClearTilemapBufferAndCommit(void *bgConfig, u8 bgId);
void BgSetPosTextAndCommit(void *bgConfig, u8 bgId, u32 op, int val);
void ScheduleSetBgPosText(void *bgConfig, u8 bgId, u32 op, int val);
void ScheduleBgTilemapBufferTransfer(void *bgConfig, u8 bgId);

void PaletteData_LoadNarc(void *data, u32 narcId, s32 memberNo, u32 heapId, u32 bufferId, u32 size, u16 pos);
void PaletteData_LoadPaletteSlotFromHardware(void *data, u32 bufferId, u16 pos, u32 size);
void PaletteData_FillPaletteInBuffer(void *data, u32 bufferId, u32 which, u16 value, u16 begin, u16 end);
u32 Options_GetFrame(void *options);
void LoadUserFrameGfx1(void *bgConfig, u32 layer, u16 baseTile, u8 paletteNum, u8 frame, u32 heapId);
void LoadUserFrameGfx2(void *bgConfig, u32 layer, u16 baseTile, u8 paletteNum, u8 frame, u32 heapId);

void *NARC_New(u32 narcId, u32 heapId);
void NARC_Delete(void *narc);
u32 GfGfxLoader_LoadCharDataFromOpenNarc(void *narc, s32 memberNo, void *bgConfig, u32 layer, u32 tileStart, u32 szByte, int isCompressed, u32 heapId);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *narc, s32 memberNo, void *bgConfig, u32 layer, u32 tileStart, u32 szByte, int isCompressed, u32 heapId);
void *GfGfxLoader_GetPlttDataFromOpenNarc(void *narc, s32 memberNo, FmPlttData **ppPlttData, u32 heapId);
void Heap_Free(void *ptr);

void FrontierMap_Update(u32 a0, FrontierMap *m);
void FrontierMap_Scroll(FrontierMap *m);
void ov80_02238B7C(FrontierMap *m);
void ov80_02238C78(FrontierMap *m);
void FrontierMap_SetVramBank(void *bgConfig, u32 mode);
void FrontierMap_LoadPaletteData(FrontierMap *m);
void ov80_02238FA0(FrontierMap *m);
void ov80_02239004(FrontierMap *m, u32 mode, void *profile);

#endif
