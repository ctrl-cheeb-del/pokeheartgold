#ifndef OV80_R40_RESIDUAL25_PRIVATE_H
#define OV80_R40_RESIDUAL25_PRIVATE_H

#include "global.h"

#define PTR(p, o)    (*(void **)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

u16 *FrontierScript_ReadVarPtr(void *);
u16 FrontierScript_ReadVar(void *);
void *Frontier_GetLaunchArgs(void *);
void *Frontier_GetData(void *);
void Frontier_SetData(void *, void *);
void *FrontierSystem_GetFrontierMap(void *);
void *Save_PlayerData_GetProfile(void *);
u32 PlayerProfile_GetTrainerGender(void *);
void *Heap_Alloc(u32, u32);
void Heap_Free(void *);
void sub_0200FBF4(int, int);
void ov80_0223B424(void *, u32);
void ov80_0223B440(void *, int, int, int, int, int, int, int, int);
void Sound_SetSceneAndPlayBGM(int, int, int);
void FrontierScriptContext_Pause(void *, BOOL (*)(void *));
void PaletteData_FillPaletteInBuffer(void *, int, int, int, int, int);

extern BOOL (*ov80_0223B9EC[])(void *);

typedef struct Ov80R40Particle {
    s16 start;
    s16 end;
    s16 x;
    s16 y;
    s16 offsetX;
    s16 offsetY;
    void *object;
} Ov80R40Particle;

typedef struct Ov80R40EffectData {
    Ov80R40Particle particles[96];
    void *allocation;
    u32 mode;
} Ov80R40EffectData;

typedef struct Ov80R40EffectWork {
    void *frontierSystem;
    u32 state;
    u32 unused08;
    u32 ready;
    u32 finished;
    u8 padding14[0x10];
    Ov80R40EffectData *data;
} Ov80R40EffectWork;

void MI_CpuFill8(void *, u8, u32);
void ov80_0223AC24(int, int, int, void *, int);
void *ov80_0223B544(u32, const void *, u32);
void *ov80_0222D63C(int, int);
void StartBrightnessTransition(int, int, int, int, int);
void *SysTask_CreateOnMainQueue(void (*)(void *, void *), void *, u32);
BOOL IsBrightnessTransitionActive(int);
void ToggleBgLayer(int, int);
void BgSetPosTextAndCommit(void *, int, int, int);
void ov80_0222D644(void *, void *);

BOOL FrtCmd_064(void *);
BOOL FrtCmd_063(void *);
BOOL ov80_0222DCF0(void *);
BOOL ov80_0222DC14(void *);
BOOL ov80_0222D968(void *);
BOOL ov80_0222DAAC(void *);

#endif
