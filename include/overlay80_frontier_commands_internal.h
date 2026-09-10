#include "global.h"
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define SYS(c)    PTR(PTR((c), 0), 0)
extern u16 FrontierScript_ReadVar(void *);
extern u16 *FrontierScript_ReadVarPtr(void *);
extern u16 FrontierScriptContext_ReadHalfWord(void *);
extern void *Frontier_GetLaunchArgs(void *);
extern void *Frontier_GetData(void *);
extern void Frontier_SetData(void *, u32);
extern u32 ov80_0222FD08(void *, u32, u8, u8);
extern void ov80_0222FEEC(void *, u32);
extern void ov80_02230424(void *);
extern int IsBattleResultWin(u32);
extern void BattleSetup_Delete(void *);
extern void ov80_02230460(void *, void *);
extern void Heap_Free(void *);
extern void ov80_022307F0(void *);
extern void ov80_022308C4(void *);
extern void ov80_022309F8(void *);
extern void ov80_02230A60(void *);
extern s32 Bg_GetYpos(void *, int);
extern void ScheduleSetBgPosText(void *, int, int, int);
extern u32 ov80_02230AF8(void *, u32, u32);
extern void FrontierScriptContext_Pause(void *, BOOL (*)(void *));
extern void ov80_0222BE9C(void *, u16);
extern void ov80_0222F44C(void *, void *);
extern void *ov80_02236F24(void *, void *);
extern void Frontier_LaunchApplication(void *, const void *, void *, int, void *);
extern const u8 gOverlayTemplate_Battle[];
extern void *Heap_Alloc(int, u32);
extern void MI_CpuFill8(void *, u8, u32);
extern const u8 ov80_0223BDB4[];
extern const u8 ov80_0223BDC4[];
int FrtCmd_092(void *);
int FrtCmd_093(void *);
int FrtCmd_094(void *);
int FrtCmd_096(void *);
void ov80_0222F7CC(void *);
int FrtCmd_099(void *);
int FrtCmd_100(void *);
int FrtCmd_101(void *);
int FrtCmd_102(void *);
void ov80_0222FC08(void *, void *);
int FrtCmd_104(void *);
int FrtCmd_105(void *);
int FrtCmd_106(void *);
BOOL ov80_0222FCA0(void *);
int FrtCmd_107(void *);
int FrtCmd_097(void *);
int FrtCmd_095(void *);
int FrtCmd_098(void *);
