#include "battle_controller_partial_internal.h"

void BattleController_EmitPrintMessage(BattleSystem *bsys, BattleMsgCtx *ctx, BattleMsgBuf *buf) {
    buf->command = 21;
    ov12_02262240(bsys, 1, ctx->battlerId, buf, 0x24);
}

void BattleController_SetMoveAnimation(BattleSystem *bsys, BattleContext *ctx, int a2) {
    u8 buf[0x58];
    ov12_022643C8(bsys, ctx, buf, 0, 0, ctx->battlerId, ctx->unk_6C, a2);
    ov12_02262240(bsys, 1, ctx->battlerId, buf, sizeof(buf));
}

void ov12_0226343C(BattleSystem *bsys, BattleContext *ctx, int a2, int a3, int a4) {
    u8 buf[0x58];
    ov12_022643C8(bsys, ctx, buf, 0, 0, a3, a4, a2);
    ov12_02262240(bsys, 1, a3, buf, sizeof(buf));
}

void BattleController_EmitMonFlicker(BattleSystem *bsys, int battlerId) {
    u32 buf = 23;
    ov12_02262240(bsys, 1, battlerId, &buf, sizeof(buf));
}
