#ifndef PRIVATE_OVERLAY_80_02235900_H
#define PRIVATE_OVERLAY_80_02235900_H

#include "global.h"

typedef struct ArcadeScriptBackup {
    u32 words[0xB4 / sizeof(u32)];
} ArcadeScriptBackup;

void *Frontier_GetLaunchArgs(void *ctx);
void *Frontier_GetData(void *ctx);
void Frontier_SetData(void *ctx, void *data);
u32 FrontierScript_ReadVar(void *ctx);
u16 *FrontierScript_ReadVarPtr(void *ctx);
u16 FrontierScriptContext_ReadHalfWord(void *ctx);
void FrontierScriptContext_Pause(void *ctx, BOOL (*callback)(void *));
void *ov80_02235FC8(void *arg);
void ov80_02235FEC(void *data);
u16 ov80_02235FF8(void *data, u32 a, u32 b, u32 c);
void ov80_02236040(void *ctx, void *data, u32 value);
u32 sub_0203769C(void);
u32 sub_02037B5C(u32 value);
void Heap_Free(void *ptr);
u32 sub_02096998(void *data);
void FrontierFieldSystem_Free(void *data);
void *FrontierFieldSystem_New(void *fieldSystem, u32 mode, u32 facility);
void ov80_0222A840(void *fieldSystem);
void FrontierFieldSystem_SetRandomFrontierTrainers(void *data, void *fieldSystem);
void *SaveArray_Party_Get(void *save);
void HealParty(void *party);
void sub_02096910(void *data);

BOOL FrtCmd_170(void *ctx);
BOOL FrtCmd_171(void *ctx);
BOOL FrtCmd_172(void *ctx);
BOOL FrtCmd_173(void *ctx);
BOOL ov80_02235990(void *ctx);
BOOL FrtCmd_202(void *ctx);
BOOL ov80_022359D4(void *ctx);
BOOL FrtCmd_174(void *ctx);
BOOL FrtCmd_175(void *ctx);
BOOL FrtCmd_176(void *ctx);
BOOL FrtCmd_177(void *ctx);
BOOL FrtCmd_179(void *ctx);
BOOL FrtCmd_180(void *ctx);
BOOL FrtCmd_181(void *ctx);
BOOL ov80_02235F90(void *ctx);
BOOL FrtCmd_182(void *ctx);

#endif
