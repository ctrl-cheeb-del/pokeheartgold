#ifndef SOL_R40_NIGHT_OVERLAY27_RESIDUAL3_PRIVATE_H
#define SOL_R40_NIGHT_OVERLAY27_RESIDUAL3_PRIVATE_H
#include "global.h"
extern u8 gSystem[];
extern const u8 ov27_0225D108[];
BOOL ov27_0225BDC8(void *);
int PlayerAvatar_GetState(void *);
void Sprite_SetDrawFlag(void *, BOOL);
int Sprite_GetAnimationNumber(void *);
BOOL Sprite_GetDrawFlag(void *);
BOOL System_GetTouchNew(void);
void Sprite_SetAnimCtrlSeq(void *, int);
BOOL ov27_0225BD44(void *);
BOOL FieldSystem_IsPlayerMovementAllowed(void *);
void *FieldSystem_GetPlayerAvatar(void *);
void *PlayerAvatar_GetMapObject(void *);
int sub_0205F330(void *);
u32 MapObject_GetSpriteID(void *);
int ov01_021E7F54(void *);
BOOL FieldSystem_GetFacingObject(void *, void **);
int MapObject_GetScriptID(void *);
BOOL ov01_021F6BD0(int);
BOOL ov01_021F6BB0(u32);
void FillWindowPixelBuffer(void *, u8);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, int);
BOOL ov27_0225A4D0(void *);
void ov27_0225A530(void *, int);
s32 ov27_0225A594(void *);
void ov27_0225A61C(void *, s32);
#endif
