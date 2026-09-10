#ifndef PRIVATE_OVERLAY_80_02235438_H
#define PRIVATE_OVERLAY_80_02235438_H

#include "global.h"

u16 FrontierScriptContext_ReadHalfWord(void *ctx);
u32 FrontierScript_ReadVar(void *ctx);
u16 *FrontierScript_ReadVarPtr(void *ctx);
void FrontierScriptContext_Pause(void *ctx, BOOL (*callback)(void *));
void *Frontier_GetLaunchArgs(void *ctx);
void *Frontier_GetData(void *ctx);
u32 GF_GetCurrentPlayingBGM(void);
void StopBGM(u32 sequence, u32 fade);
void FrontierFieldSystem_Free(void *data);
u32 ov80_02236B18(u32 mode);
void ov80_0222F458(void *ctx, void *data, u32 value);
void *ov80_0223690C(void *data, void *args);
void Sound_SetSceneAndPlayBGM(u32 scene, u32 sequence, u32 arg);
void Frontier_LaunchApplication(void *ctx, const void *template, void *args, u32 arg, u32 arg2);
extern const u8 gOverlayTemplate_Battle[];
u32 IsBattleResultWin(u32 result);
void BattleSetup_Delete(void *setup);
void ov80_02236ABC(void *data, u32 value);
void GF_AssertFail(void);
u32 sub_0203769C(void);
u32 sub_02037C0C(u32 value, void *data);
void *sub_02037C44(u32 side);
u16 *ov80_0222BE24(void *ctx, u32 value);
u32 ov80_02236AD8(void *data, void *remote);
extern const u16 ov80_0223C034[];
void ResetSystem(void);
u32 FrontierFieldSystem_AwardTowerBattlePoints(void *data);
void *Save_GameStats_Get(void *saveData);
void GameStats_Add(void *stats, u32 stat, u32 value);
u32 FrontierFieldSystem_GetFrontierBattleNumber(void *data);
u32 ov80_022358C4(void *data);
u32 FrontierFieldSystem_0204AC7C(void *data);
u32 ov80_022358E8(void *data);
u32 FrontierFieldSystem_GetBattleTowerMode(void *data);
void ov80_022357B4(void *data, void *saveData);
u32 ov80_02235898(void *data, u32 value);
void ov80_022358B0(void *data, u32 value);
void FrontierFieldSystem_0204AD04(void *data, void *saveData);
void FrontierFieldSystem_0204AE20(void *data, void *saveData);
void FrontierFieldSystem_0204AF2C(void *data);

BOOL FrtCmd_091(void *ctx);
BOOL FrtCmd_132(void *ctx);
BOOL FrtCmd_133(void *ctx);
BOOL FrtCmd_134(void *ctx);
BOOL FrtCmd_135(void *ctx);
BOOL FrtCmd_136(void *ctx);
BOOL FrtCmd_137(void *ctx);
BOOL FrtCmd_138(void *ctx);
u32 ov80_0223558C(void *data, u32 mode);
BOOL ov80_0223573C(void *ctx);
BOOL ov80_02235774(void *ctx, void *data, void *fieldSystem, u32 mode, u16 value);

#endif
