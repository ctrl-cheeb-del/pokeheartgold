#ifndef POKEHEARTGOLD_TO45_OVERLAY80_BATTLE_RECORD_R17_PRIVATE_H
#define POKEHEARTGOLD_TO45_OVERLAY80_BATTLE_RECORD_R17_PRIVATE_H

#include "global.h"

#define PTR_AT(object, offset) (*(void **)((u8 *)(object) + (offset)))
#define U16_AT(object, offset) (*(u16 *)((u8 *)(object) + (offset)))

u16 FrontierScriptContext_ReadHalfWord(void *context);
u16 FrontierScript_ReadVar(void *context);
u16 *FrontierScript_ReadVarPtr(void *context);
void FrontierScriptContext_Pause(void *context, BOOL (*callback)(void *));
void *Frontier_GetLaunchArgs(void *frontier);
int sub_0202FE14(void *saveData, int type, int arg, int index, u16 *state, u16 *writeState);
void *Heap_Alloc(u32 heapId, u32 size);
BOOL sub_0202FC90(void *saveData, int heapId, int *result, void *battleSetup, int index);
void Sound_SetSceneAndPlayBGM(u32 scene, u32 sequence, u32 arg);
void Frontier_LaunchApplication(void *frontier, const void *template, void *args, u32 arg, void *callback);
extern const u8 gOverlayTemplate_Battle[];

BOOL FrtCmd_109(void *context);
BOOL ov80_0222CC20(void *context);
u32 ov80_0222CC70(u32 type, u32 value);
BOOL FrtCmd_110(void *context);

#endif
