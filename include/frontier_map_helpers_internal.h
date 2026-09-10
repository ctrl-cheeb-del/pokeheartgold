#ifndef POKEHEARTGOLD_FRONTIER_MAP_PRIVATE_H
#define POKEHEARTGOLD_FRONTIER_MAP_PRIVATE_H

#include "global.h"

typedef struct FrontierMapEntry {
    /* 0x00 */ void *unk00;
    /* 0x04 */ void *unk04;
    /* 0x08 */ u16 unk08;
    /* 0x0A */ u16 unk0A;
    /* 0x0C */ u16 unk0C;
    /* 0x0E */ u16 unk0E;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14[0x38 - 0x14];
    /* 0x38 */ void *unk38;
} FrontierMapEntry;

typedef struct FrontierMapMark {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
} FrontierMapMark;

typedef struct FrontierMapSub1C {
    /* 0x00 */ u32 unk00;
} FrontierMapSub1C;

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
    /* 0x90 */ u8 unk90[0xAA - 0x90];
    /* 0xAA */ s16 unkAA;
    /* 0xAC */ u8 unkAC[0xC1 - 0xAC];
    /* 0xC1 */ u8 unkC1;
    /* 0xC2 */ u8 unkC2[0xC4 - 0xC2];
} FrontierMap;

void GF_AssertFail(void);
void GF_RunVramTransferTasks(void);
void SpriteSystem_TransferOam(void);
void PaletteData_PushTransparentBuffers(void *plttData);
void DoScheduledBgGpuUpdates(void *bgConfig);
void *GF_3DVramMan_Create(u32 heapId, u32 a1, u32 a2, u32 a3, u32 a4, void (*a5)(void));
void GF_3DVramMan_Delete(void *vramMan);
FrontierMapEntry *sub_02096868(void *a0);
FrontierMapEntry *sub_0209686C(void *a0, u32 idx);
FrontierMapMark *sub_02096864(void *a0);
u16 ov42_02228188(void *a0, u32 a1);
u8 ov42_022291F4(void *a0);
void ov42_02228100(void *a0);
void ov42_02228050(void *a0);
void ov42_02227F28(void *a0);
void ov42_02228F94(void *a0);
void ov42_0222940C(void *a0);
void ov42_02229A78(void *a0);
void ov42_022299AC(void *a0);
void ov42_02229004(void *a0, u16 a1);
void ov42_02228FE0(void *a0, u16 a1, u8 a2, u32 a3);
void ov42_0222807C(void *a0);
u16 ov42_022293A8(FrontierMapSub1C *a0);
u16 ov42_022293B0(FrontierMapSub1C *a0);
void ov80_02238C78(FrontierMap *m);
void ov80_02239BE8(void *a0);
void ov80_02239740(FrontierMap *m);
void MI_CpuFill8(void *dst, u8 val, u32 size);
void ov42_022290C4(void *a0);
void *ov80_02239BB8(void *a0, void *a1, u16 a2);
void ov80_02239B7C(void *a0, u16 a1);
void *SpriteSystem_Alloc(u32 heapId);
void SpriteSystem_Init(void *a0, const void *a1, const void *a2, u32 a3);
void G2dRenderer_SetObjCharTransferReservedRegion(u32 a0, u32 a1);
void G2dRenderer_SetPlttTransferReservedRegion(u32 a0);
void *SpriteManager_New(void *a0);
void SpriteSystem_InitSprites(void *a0, void *a1, u32 a2);
void SpriteSystem_InitManagerWithCapacities(void *a0, void *a1, const void *a2);
void *SpriteSystem_GetRenderer(void *a0);
void G2dRenderer_SetSubSurfaceCoords(void *a0, u32 a1, u32 a2);
void Sprite_DeleteAndFreeResources(void *a0);
void SpriteManager_UnloadCharObjById(void *a0, u32 a1);
void SpriteManager_UnloadPlttObjById(void *a0, u32 a1);
void SpriteManager_UnloadCellObjById(void *a0, u32 a1);
void SpriteManager_UnloadAnimObjById(void *a0, u32 a1);
void SpriteSystem_FreeResourcesAndManager(void *a0, void *a1);
void SpriteSystem_Free(void *a0);
extern const u8 ov80_0223D5B8[];
extern const u8 ov80_0223D570[];
extern const u8 ov80_0223D584[];

void ov80_02239384(FrontierMap *m);
void ov80_022393E8(FrontierMap *m);
void ov80_02239590(FrontierMap *m, void *a1);
void *ov80_0223968C(FrontierMap *m, u32 idx, u16 a2);

void ov80_02238AAC(void);
void ov80_02238AB0(u32 a0, FrontierMap *m);
void ov80_02238ABC(u32 a0, FrontierMap *m);
void FrontierMap_VBlank(FrontierMap *m);
void ov80_022389C4(FrontierMap *m);
void ov80_0223927C(FrontierMap *m);
void *ov80_022392DC(u32 heapId);
void ov80_022392F8(void);
void ov80_0223937C(void *vramMan);
void ov80_0223947C(FrontierMap *m, const FrontierMapMark *src);
void ov80_022394D8(FrontierMap *m, u16 id);
void ov80_022395E8(FrontierMap *m, u16 id, void **outA, void **outB);
void ov80_0223962C(FrontierMap *m, u16 id);
void ov80_0223965C(FrontierMap *m, u16 id);
void ov80_022396D8(FrontierMap *m, u32 idx);
void *ov80_02239700(FrontierMap *m, u32 idx);
void ov80_02239708(FrontierMap *m, u32 idx, u32 on);
u32 ov80_02239734(FrontierMap *m, u32 idx);
void ov80_022398E4(FrontierMap *m, u16 *outA, u16 *outB);
void ov80_02239900(FrontierMapEntry *e, u16 *dst);
void ov80_02239914(void *a0, u32 idx, void *a2, void *a3, const u16 *src);
FrontierMapEntry *ov80_02239938(void *a0, u16 id);

#endif
