#ifndef TO40_OVERLAY_80_02235390_PRIVATE_H
#define TO40_OVERLAY_80_02235390_PRIVATE_H

#include "global.h"

typedef struct FrontierScriptContext35390 {
    u8 pad00[0x78];
    u16 soundId;
} FrontierScriptContext35390;

u16 FrontierScript_ReadVar(void *ctx);
u32 FrontierScriptContext_ReadHalfWord(void *ctx);
void FrontierScriptContext_Pause(void *ctx, BOOL (*callback)(void *));
BOOL PlaySE(u16 seq);
void StopSE(u16 seq, int fadeFrames);
BOOL IsSEPlaying(u16 seq);
BOOL PlayFanfare(u32 seq);
BOOL IsFanfarePlaying(void);
void Sound_SetFieldBGM(u16 seq);
BOOL PlayBGM(u16 seq);

BOOL FrtCmd_085(void *ctx);
BOOL FrtCmd_086(void *ctx);
BOOL FrtCmd_087(FrontierScriptContext35390 *ctx);
BOOL ov80_022353D0(FrontierScriptContext35390 *ctx);
BOOL FrtCmd_088(void *ctx);
BOOL FrtCmd_089(void *ctx);
BOOL ov80_02235408(void *ctx);
BOOL FrtCmd_090(void *ctx);

#endif
