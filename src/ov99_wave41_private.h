#ifndef OV99_R2_H
#define OV99_R2_H
#include "global.h"
extern u8 SDK_OVERLAY_OVY_98_ID;
typedef u8 R99;
#define P(w, o)   (*(void **)((w) + (o)))
#define U16(w, o) (*(u16 *)((w) + (o)))
#define U32(w, o) (*(u32 *)((w) + (o)))
extern const u8 ov99_021E9600[];
extern const u8 _021E954C[];
extern const u8 ov99_021E9D88[];
extern const u8 ov99_021E9650[];
typedef struct Ov99Pos {
    u32 sprite, x, y;
} Ov99Pos;
extern const Ov99Pos ov99_021E9690[];
extern void NARC_Delete(void *);
extern void FreeBgTilemapBuffer(void *, u32);
extern void Heap_Free(void *);
extern void ov98_0221EC08(void *, u32, u32, u32, u32);
extern void ov98_0221EBEC(void *, u32, u32, u32, u32, u32);
extern void ov98_0221EBD8(void *, u32, u32, u32);
extern void ov99_021E6188(R99 *);
extern void ov99_021E607C(R99 *, u32);
extern void ov99_021E6144(R99 *, u32);
extern void ov99_021E6218(R99 *);
extern void ov99_021E5EB4(R99 *, u32, u32);
extern void ManagedSprite_SetDrawFlag(void *, u32);
extern void BgClearTilemapBufferAndCommit(void *, u32);
extern void SpriteSystem_TransferOam(void *);
extern void DoScheduledBgGpuUpdates(void *);
extern void ov98_0221EE28(void *, u32, u32);
extern void ov98_0221EE84(void *, u32);
extern void FillWindowPixelBuffer(void *, u32);
extern void ScheduleWindowCopyToVram(void *);
extern void *ov98_0221E5C0(void *);
extern void *ov98_0221E5D0(void *);
extern void ov98_0221E784(void *, void *, const void *, u32);
extern void GfGfxLoader_GXLoadPalFromOpenNarc(void *, u32, u32, u32, u32, u32);
extern void GfGfxLoader_LoadCharDataFromOpenNarc(void *, u32, void *, u32, u32, u32, u32, u32);
extern void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, u32, void *, u32, u32, u32, u32, u32);
extern s32 Bg_GetXpos(void *, u32);
extern void ScheduleSetBgPosText(void *, u32, u32, s32);
extern void ManagedSprite_SetPositionXY(void *, s16, s16);
extern void *OverlayManager_GetData(void *);
extern void OverlayManager_FreeData(void *);
extern void ov99_021E7060(void *);
extern void ov98_0221E684(void *, void *, u32);
extern void ov98_0221EB84(void *, u32);
extern void ov98_0221F0EC(void);
extern void Heap_Destroy(u32);
extern void UnloadOverlayByID(u32);
u16 ov99_021E5B90(R99 *, s32);
BOOL ov99_021E5BB4(R99 *, s32);
u16 ov99_021E5BD8(R99 *, s32, s32);
u8 ov99_021E5C20(R99 *, s32, u32);
u16 ov99_021E5C4C(R99 *, u32, u32);
void ov99_021E5D2C(R99 *);
void ov99_021E5F74(R99 *);
void ov99_021E5FE8(R99 *, u32);
void ov99_021E6018(R99 *);
void ov99_021E6050(R99 *, u32);
void ov99_021E6144(R99 *, u32);
void ov99_021E6218(R99 *);
void ov99_021E6250(R99 *);
void ov99_021E6400(R99 *);
void ov99_021E64E0(R99 *, u32);
u32 ov99_021E6840(void *);
void ov99_021E6938(R99 *);
void ov99_021E69D8(R99 *);
void ov99_021E6A70(R99 *);
#endif
