#ifndef TO30_OVERLAY_80_02230B8C_PRIVATE_H
#define TO30_OVERLAY_80_02230B8C_PRIVATE_H

#include "global.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define SYS(c)    PTR(PTR((c), 0), 0)

extern u16 FrontierScript_ReadVar(void *);
extern u16 *FrontierScript_ReadVarPtr(void *);
extern u16 FrontierScriptContext_ReadHalfWord(void *);
extern void FrontierScriptContext_Pause(void *, BOOL (*)(void *));
extern void *Frontier_GetLaunchArgs(void *);
extern void *Frontier_GetData(void *);
extern void Frontier_SetData(void *, u32);
extern void Frontier_LaunchApplication(void *, const void *, void *, int, void *);
extern void *Heap_Alloc(int, u32);
extern void Heap_Free(void *);
extern void MI_CpuFill8(void *, u8, u32);
extern void SaveArray_Party_Init(void *);
extern void *SaveArray_Party_Get(void *);
extern void *Party_GetMonByIndex(void *, int);
extern void Party_AddMon(void *, void *);
extern int IsBattleResultWin(u32);
extern void BattleSetup_Delete(void *);
extern void Sound_SetSceneAndPlayBGM(int, int, int);
extern const u8 gOverlayTemplate_Battle[];
extern const u8 ov80_0223BDEC[];

extern u32 ov80_022310C4(void *, u32, u8, u8, u8);
extern void ov80_022313C0(void *, u32);
extern void ov80_022314A0(void *);
extern void ov80_022314DC(void *, void *);
extern void *ov80_022375D0(void *, void *);
extern u32 ov80_02231844(void *, u32, u32);
extern void ov80_0222BE9C(void *, u16);
extern void ov80_0222F44C(void *, void *);
extern void ov80_0223151C(void *, u16 *);
extern void OS_ResetSystem(u32);
extern u32 sub_02030B14(void *);
extern void ov80_0223157C(void *, int);
extern u32 ov80_022317C0(void *);
extern u32 ov80_022317D0(void *, u8);
extern void ov80_02231804(void *);
extern void ov80_02231828(void *);
extern u32 ov80_022317CC(void *);
extern int ov80_0223787C(u8);
extern void SetMonData(void *, int, const void *);
extern u32 sub_02030BD0(u8, void *);
extern void sub_02030BF4(u8, void *, u8);
extern void sub_02096910(void);
extern u32 ov80_0223792C(u8);
extern void GfGfx_EngineATogglePlanes(int, int);
extern void ov80_0222A474(void *, u16, int, int);
extern u32 ov80_02231888(void *);
extern u32 GetMonData(void *, int, void *);
extern void ov80_022319B0(void *);
extern void ov80_02231A04(void *);

void ov80_02230D5C(void *);
BOOL ov80_02231040(void *);
int FrtCmd_139(void *);
int FrtCmd_140(void *);
int FrtCmd_141(void *);
int FrtCmd_142(void *);
int FrtCmd_143(void *);
int FrtCmd_144(void *);
int FrtCmd_145(void *);
int FrtCmd_146(void *);
int FrtCmd_147(void *);
int FrtCmd_148(void *);
int FrtCmd_149(void *);
int FrtCmd_118(void *);
int FrtCmd_199(void *);

#endif
