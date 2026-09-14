#ifndef POKEHEARTGOLD_OVERLAY81_LIFECYCLE_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY81_LIFECYCLE_PRIVATE_H

#include "global.h"

FS_EXTERN_OVERLAY(OVY_80);

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define BIT(x, n) ((u32)(x) << (31 - (n)) >> 31)

typedef struct Ov81WorkR2 {
    u8 padding_000[0x458];
    u16 transition;
} Ov81WorkR2;

extern void HandleLoadOverlay(u32, int);
extern void UnloadOverlayByID(u32);
extern void *OverlayManager_CreateAndGetData(void *, u32, int);
extern void *OverlayManager_GetData(void *);
extern void *OverlayManager_GetArgs(void *);
extern void OverlayManager_FreeData(void *);
extern void Heap_Create(int, int, u32);
extern void Heap_Destroy(int);
extern void *GF_3DVramMan_Create(int, int, int, int, int, void *);
extern void *BgConfig_Alloc(int);
extern void *Save_PlayerData_GetOptionsAddr(void *);
extern u32 Options_GetFrame(void *);
extern void TextFlags_SetCanTouchSpeedUpPrint(int);
extern void Main_SetVBlankIntrCB(void *, void *);
extern void BgSetPosTextAndCommit(void *, int, int, int);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern BOOL IsPaletteFadeFinished(void);
extern void GfGfx_EngineATogglePlanes(int, int);
extern void PlaySE(int);
extern void StopSE(int, int);
extern void FillWindowPixelBuffer(void *, int);
extern void ScheduleWindowCopyToVram(void *);
extern void SpriteList_RenderAndAnimateSprites(void *);
extern int PaletteData_GetSelectedBuffersBitmask(void *);
extern void PaletteData_ScheduleFadeTaskEndIfNoSelectedBuffers(void *);
extern void Pokepic_SetAttr(void *, int, int);
extern void Pokepic_StartPaletteFadeAll(void *, int, int, int, int);
extern void Pokepic_ResumePaletteFade(void *);
extern void sub_020196E8(void *, int, int, int);
extern void sub_02037AC0(int);
extern BOOL sub_02037B38(int);
extern void sub_02037BEC(void);
extern void sub_02096910(void *);
extern int ov80_02236DD4(int);
extern BOOL ov80_02237254(int);

extern void ov81_02242BC8(void);
extern void ov81_02240D2C(void);
extern void ov81_02240D64(void *);
extern void *ov81_02243240(void *, int);
extern void *ov81_022432DC(void *, int);
extern void *ov81_022432AC(void *, int);
extern void ov81_02241BB8(void **);
extern BOOL ov81_02240F08(u8 *, u8);
extern int ov81_02240F18(int);
extern BOOL ov81_02240F28(u8 *);
extern void ov81_02240F38(u8 *, u8);
extern void ov81_022404AC(u8 *, u32 *, u32);
extern void ov81_02242514(void *);
extern void ov81_02241144(void *);
extern BOOL ov81_0223EC88(void *);
extern BOOL ov81_0223ECE4(void *);
extern BOOL ov81_0223F1A4(void *);
extern BOOL ov81_0223F314(void *);
extern BOOL ov81_0223F38C(void *);
extern BOOL ov81_0223F6A8(void *);
extern BOOL ov81_0223F770(void *);
extern BOOL ov81_0223FBAC(void *);
extern BOOL ov81_0223FC74(void *);
extern BOOL ov81_02240008(void *);
extern BOOL ov81_02240048(void *);
extern BOOL ov81_02240088(void *);
extern BOOL ov81_022400D0(void *);
extern void ov81_0223E8BC(void *);
extern void ov81_0223EA98(void *);
extern void ov81_02242C48(void *);
extern void ov81_02241BC8(void *);
extern void ov81_02243220(void *);
extern void ov81_02240BB0(void *);
extern void *ov81_02242F30(void **);
extern void ov81_02242F60(void *);
extern void ov81_02242F94(void *, int);
extern void ov81_02242F48(void *);
extern void ov81_02242FB0(void *, int);
extern BOOL ov81_02242DD8(void *);
extern void ov81_02242EB8(void *, int);
extern void *ov81_022412C4(void *, int);
extern BOOL ov81_022404B4(void);
extern void ov81_02240658(void *, int);
extern void ov81_02241398(void *);
extern void ov81_0224093C(void *, void *, int, int, int);
extern void ov81_02241524(void *);
extern void ov81_02243228(void *, void *, int *, int *);
extern void *ov81_02242D18(void *, int, int, int, int, int, int);
extern void ov81_02241CA0(void *, int *, int *);
extern void *ov81_02242CBC(void *, int, int, int, int, int, int);
extern void ov81_02241F50(void *);
extern void ov81_02241FEC(void *);
extern void ov81_022420B4(void *);
extern void ov81_0224218C(void *);
extern void ov81_02242218(void *, void *, void *, int);
extern void ov81_02242300(void *, void *, int);
extern void ov81_022408C4(void *, void *, int, int, int);
extern void ov81_02243028(void *, u32);
extern void ov81_022408A0(void *, int, int);
extern int ov81_0224086C(void *, int);
extern void *ov81_02241D0C(void *);
extern void ov81_02241E68(void *, int, void *, int);
extern void ov81_02241C84(int, int, int *, int *);
extern void ov81_02242D94(void *, int, int);
extern void ov81_02241450(void *);
extern void ov81_022414E0(void *);
extern void ov81_02240AD8(void *, void *, int, int, int, int, int, int, int, int);

BOOL ov81_0223DD60(void *, u32 *);
BOOL ov81_0223DEA8(void *, u32 *);
BOOL ov81_0223E234(void *, u32 *);
BOOL ov81_0223E318(u8 *);
BOOL ov81_0223E520(u8 *);
void ov81_0223E5B4(u8 *);
void ov81_0223E87C(u8 *);

#endif
