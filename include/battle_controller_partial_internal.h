#ifndef OV12_BATTLE_CONTROLLER_PRIVATE_H
#define OV12_BATTLE_CONTROLLER_PRIVATE_H

#include "global.h"

typedef struct BattleSystem BattleSystem;

typedef struct BattleMsgBuf {
    u8 command;
    u8 unk1;
    u16 unk2;
} BattleMsgBuf;

typedef struct BattleMsgCtx {
    u8 filler_00[0x64];
    u32 battlerId;
} BattleMsgCtx;

void ov12_02262240(BattleSystem *bsys, int a1, int battlerId, const void *buf, int size);

void BattleController_EmitDeletePokemon(BattleSystem *bsys, int battlerId);
void BattleController_EmitTrainerSlideOut(BattleSystem *bsys, int battlerId);
void BattleController_EmitHealthbarSlideOut(BattleSystem *bsys, int battlerId);
void BattleController_EmitMonFlicker(BattleSystem *bsys, int battlerId);
void ov12_0226399C(BattleSystem *bsys, int battlerId);
void BattleController_EmitBackgroundSlideIn(BattleSystem *bsys, int battlerId);
void ov12_02263CCC(BattleSystem *bsys, int battlerId);
void BattleController_EmitSetBattleBackground(BattleSystem *bsys, int battlerId);
void ov12_02263E18(BattleSystem *bsys, int battlerId);
void ov12_02264038(BattleSystem *bsys, int battlerId);
void ov12_02264054(BattleSystem *bsys, int battlerId);
void ov12_02263A00(BattleSystem *bsys, int battlerId);

void BattleController_EmitFadeOutBattle(BattleSystem *bsys);
void BattleController_EmitLoadBallGfx(BattleSystem *bsys);
void BattleController_EmitDeleteBallGfx(BattleSystem *bsys);
void BattleController_EmitPrintResultMessage(BattleSystem *bsys);
void BattleController_EmitBlankMessage(BattleSystem *bsys);

void BattleController_EmitPrintEncounterMessage(BattleSystem *bsys, int a1, int battlerId);

void BattleController_EmitHealthbarStatus(BattleSystem *bsys, int battlerId, int a2);
void BattleController_EmitPrintTrainerMessage(BattleSystem *bsys, int battlerId, int a2);
void BattleController_EmitPlaySong(BattleSystem *bsys, int battlerId, int a2);
void BattleController_EmitPlaySE(BattleSystem *bsys, int a1, int a2, int battlerId);

void BattleController_EmitPrintMessage(BattleSystem *bsys, BattleMsgCtx *ctx, BattleMsgBuf *buf);

void ov12_02262F24(BattleSystem *bsys, int battlerId, u32 msg);
void ov12_02262FE0(BattleSystem *bsys, int battlerId, u32 msg);
void ov12_0226311C(BattleSystem *bsys, int battlerId, u32 msg);
void ov12_022632C0(BattleSystem *bsys, int battlerId, u32 msg);
void ov12_02263360(BattleSystem *bsys, int battlerId, u32 msg);

typedef struct BattleContext BattleContext;

struct BattleContext {
    u8 filler_00[0x64];
    u32 battlerId;
    u8 filler_68[0x6C - 0x68];
    u32 unk_6C;
};

struct BattleSystem {
    u8 filler_00[0x30];
    BattleContext *ctx;
};

typedef struct BattleMsgBuf8 {
    u8 command;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} BattleMsgBuf8;

void ov12_022645F8(BattleSystem *bsys, BattleContext *ctx, void *buf, int cmd, int battlerId);
void ov12_022643C8(BattleSystem *bsys, BattleContext *ctx, void *buf, int a3, int a4, int a5, int a6, int a7);
BattleContext *BattleSystem_GetBattleContext(BattleSystem *bsys);
void BattleBuffer_Clear(BattleContext *ctx, int battlerId);
u8 sub_0203769C(void);

void BattleController_EmitInitStartBallGauge(BattleSystem *bsys, int battlerId);
void BattleController_EmitDeleteStartBallGauge(BattleSystem *bsys, int battlerId);
void BattleController_EmitInitBallGauge(BattleSystem *bsys, int battlerId);
void BattleController_EmitDeleteBallGauge(BattleSystem *bsys, int battlerId);
void BattleController_EmitPlayMosaicAnimation(BattleSystem *bsys, int battlerId, int a2, int a3);
void BattleController_EmitIncrementGameStat(BattleSystem *bsys, int battlerId, int a2, int a3);
void ov12_0226430C(BattleSystem *bsys, int battlerId, int a2);
void ov12_022645C8(BattleSystem *bsys, int a1, int a2);
void BattleController_EmitSetStatus2Effect(BattleSystem *bsys, BattleContext *ctx, int battlerId, int a3);
void BattleController_EmitCopyStatus2Effect(BattleSystem *bsys, BattleContext *ctx, int battlerId, int a3, int a4);
void BattleController_SetMoveAnimation(BattleSystem *bsys, BattleContext *ctx, int a2);
void ov12_0226343C(BattleSystem *bsys, BattleContext *ctx, int a2, int a3, int a4);
void ov12_02263D14(BattleSystem *bsys, int battlerId, int a2, int a3);

#endif
