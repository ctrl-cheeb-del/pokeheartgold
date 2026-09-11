#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
typedef struct BattleSystem BattleSystem;
typedef struct BattleContext BattleContext;
typedef struct RawCtx { u8 pad[0x355]; u8 battler; u8 pad356[2]; s8 scores[4]; } RawCtx;
u32 BattleSystem_Random(BattleSystem *bsys);
s32 BattleSystem_GetFieldSide(BattleSystem *bsys, u32 battler);
void ov10_0221EF24(BattleContext *ctx, s32 value);
s32 ov10_0221EEF0(BattleContext *ctx);
u32 ov10_0221EF34(BattleContext *ctx, u8 battler);

void ov10_0221C384(BattleSystem *, BattleContext *);
void ov10_0221C3C4(BattleSystem *, BattleContext *);
void ov10_0221C404(BattleSystem *, BattleContext *);
void ov10_0221C444(BattleSystem *, BattleContext *);
void ov10_0221C484(BattleSystem *, BattleContext *);
void ov10_0221C4B8(BattleSystem *, BattleContext *);
void ov10_0221C510(BattleSystem *, BattleContext *);
void ov10_0221C568(BattleSystem *, BattleContext *);
void ov10_0221C5C0(BattleSystem *, BattleContext *);
void ov10_0221C618(BattleSystem *, BattleContext *);
void ov10_0221C664(BattleSystem *, BattleContext *);
void ov10_0221C6B0(BattleSystem *, BattleContext *);
void ov10_0221C6FC(BattleSystem *, BattleContext *);
void ov10_0221C748(BattleSystem *, BattleContext *);
void ov10_0221C790(BattleSystem *, BattleContext *);
void ov10_0221C7D8(BattleSystem *, BattleContext *);
void ov10_0221C828(BattleSystem *, BattleContext *);
void ov10_0221C878(BattleSystem *, BattleContext *);
void ov10_0221C8A8(BattleSystem *, BattleContext *);
#endif
