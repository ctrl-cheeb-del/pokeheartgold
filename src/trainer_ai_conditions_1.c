#include "trainer_ai_conditions_private.h"

#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define S8(p,o) (*(s8 *)((u8 *)(p)+(o)))
#define U8(p,o) (*(u8 *)((u8 *)(p)+(o)))

void ov10_0221C384(BattleSystem *bsys, BattleContext *ctx) { s32 a,b;
 ov10_0221EF24(ctx,1); a=ov10_0221EEF0(ctx); b=ov10_0221EEF0(ctx);
 if ((s32)BattleSystem_Random(bsys) % 256 < a) ov10_0221EF24(ctx,b); }

void ov10_0221C3C4(BattleSystem *bsys, BattleContext *ctx) { s32 a,b;
 ov10_0221EF24(ctx,1); a=ov10_0221EEF0(ctx); b=ov10_0221EEF0(ctx);
 if ((s32)BattleSystem_Random(bsys) % 256 > a) ov10_0221EF24(ctx,b); }

void ov10_0221C404(BattleSystem *bsys, BattleContext *ctx) { s32 a,b;
 ov10_0221EF24(ctx,1); a=ov10_0221EEF0(ctx); b=ov10_0221EEF0(ctx);
 if ((s32)BattleSystem_Random(bsys) % 256 == a) ov10_0221EF24(ctx,b); }

void ov10_0221C444(BattleSystem *bsys, BattleContext *ctx) { s32 a,b;
 ov10_0221EF24(ctx,1); a=ov10_0221EEF0(ctx); b=ov10_0221EEF0(ctx);
 if ((s32)BattleSystem_Random(bsys) % 256 != a) ov10_0221EF24(ctx,b); }

void ov10_0221C484(BattleSystem *bsys, BattleContext *ctx) {
    s32 amount; RawCtx *raw = (RawCtx *)ctx; (void)bsys;
    ov10_0221EF24(ctx, 1);
    amount = ov10_0221EEF0(ctx);
    raw->scores[raw->battler] += amount;
    if (raw->scores[raw->battler] < 0) raw->scores[raw->battler] = 0;
}

void ov10_0221C4B8(BattleSystem *bsys, BattleContext *ctx) {
 s32 battler, rhs, out; u32 lhs, idx; (void)bsys;
 ov10_0221EF24(ctx,1); battler=ov10_0221EEF0(ctx); rhs=ov10_0221EEF0(ctx); out=ov10_0221EEF0(ctx);
 idx=ov10_0221EF34(ctx,(u8)battler); lhs=100 * U32(ctx, 0x2D8C + 0xC0 * idx) / U32(ctx, 0x2D90 + 0xC0 * idx);
 if (lhs < (u32)rhs) ov10_0221EF24(ctx,out);
}

void ov10_0221C510(BattleSystem *bsys, BattleContext *ctx) {
 s32 battler, rhs, out; u32 lhs, idx; (void)bsys;
 ov10_0221EF24(ctx,1); battler=ov10_0221EEF0(ctx); rhs=ov10_0221EEF0(ctx); out=ov10_0221EEF0(ctx);
 idx=ov10_0221EF34(ctx,(u8)battler); lhs=100 * U32(ctx, 0x2D8C + 0xC0 * idx) / U32(ctx, 0x2D90 + 0xC0 * idx);
 if (lhs > (u32)rhs) ov10_0221EF24(ctx,out);
}

void ov10_0221C568(BattleSystem *bsys, BattleContext *ctx) {
 s32 battler, rhs, out; u32 lhs, idx; (void)bsys;
 ov10_0221EF24(ctx,1); battler=ov10_0221EEF0(ctx); rhs=ov10_0221EEF0(ctx); out=ov10_0221EEF0(ctx);
 idx=ov10_0221EF34(ctx,(u8)battler); lhs=100 * U32(ctx, 0x2D8C + 0xC0 * idx) / U32(ctx, 0x2D90 + 0xC0 * idx);
 if (lhs == (u32)rhs) ov10_0221EF24(ctx,out);
}

void ov10_0221C5C0(BattleSystem *bsys, BattleContext *ctx) {
 s32 battler, rhs, out; u32 lhs, idx; (void)bsys;
 ov10_0221EF24(ctx,1); battler=ov10_0221EEF0(ctx); rhs=ov10_0221EEF0(ctx); out=ov10_0221EEF0(ctx);
 idx=ov10_0221EF34(ctx,(u8)battler); lhs=100 * U32(ctx, 0x2D8C + 0xC0 * idx) / U32(ctx, 0x2D90 + 0xC0 * idx);
 if (lhs != (u32)rhs) ov10_0221EF24(ctx,out);
}

void ov10_0221C618(BattleSystem *bsys, BattleContext *ctx) { s32 battler; u32 mask; s32 out; (void)bsys;
 ov10_0221EF24(ctx,1); battler=ov10_0221EEF0(ctx); mask=ov10_0221EEF0(ctx); out=ov10_0221EEF0(ctx);
 if ((U32(ctx,(0x2DAC)+0xC0*ov10_0221EF34(ctx,(u8)battler)) & mask) != 0) ov10_0221EF24(ctx,out); }

void ov10_0221C664(BattleSystem *bsys, BattleContext *ctx) { s32 battler; u32 mask; s32 out; (void)bsys;
 ov10_0221EF24(ctx,1); battler=ov10_0221EEF0(ctx); mask=ov10_0221EEF0(ctx); out=ov10_0221EEF0(ctx);
 if ((U32(ctx,(0x2DAC)+0xC0*ov10_0221EF34(ctx,(u8)battler)) & mask) == 0) ov10_0221EF24(ctx,out); }

void ov10_0221C6B0(BattleSystem *bsys, BattleContext *ctx) { s32 battler; u32 mask; s32 out; (void)bsys;
 ov10_0221EF24(ctx,1); battler=ov10_0221EEF0(ctx); mask=ov10_0221EEF0(ctx); out=ov10_0221EEF0(ctx);
 if ((U32(ctx,(0x2DB0)+0xC0*ov10_0221EF34(ctx,(u8)battler)) & mask) != 0) ov10_0221EF24(ctx,out); }

void ov10_0221C6FC(BattleSystem *bsys, BattleContext *ctx) { s32 battler; u32 mask; s32 out; (void)bsys;
 ov10_0221EF24(ctx,1); battler=ov10_0221EEF0(ctx); mask=ov10_0221EEF0(ctx); out=ov10_0221EEF0(ctx);
 if ((U32(ctx,(0x2DB0)+0xC0*ov10_0221EF34(ctx,(u8)battler)) & mask) == 0) ov10_0221EF24(ctx,out); }

void ov10_0221C748(BattleSystem *bsys, BattleContext *ctx) { s32 battler; u32 mask; s32 out; (void)bsys;
 ov10_0221EF24(ctx,1); battler=ov10_0221EEF0(ctx); mask=ov10_0221EEF0(ctx); out=ov10_0221EEF0(ctx);
 if ((U32(ctx,(0x2DC0)+0xC0*ov10_0221EF34(ctx,(u8)battler)) & mask) != 0) ov10_0221EF24(ctx,out); }

void ov10_0221C790(BattleSystem *bsys, BattleContext *ctx) { s32 battler; u32 mask; s32 out; (void)bsys;
 ov10_0221EF24(ctx,1); battler=ov10_0221EEF0(ctx); mask=ov10_0221EEF0(ctx); out=ov10_0221EEF0(ctx);
 if ((U32(ctx,(0x2DC0)+0xC0*ov10_0221EF34(ctx,(u8)battler)) & mask) == 0) ov10_0221EF24(ctx,out); }

void ov10_0221C7D8(BattleSystem *bsys, BattleContext *ctx) { s32 battler; u32 mask; s32 out;
 ov10_0221EF24(ctx,1); battler=ov10_0221EEF0(ctx); mask=ov10_0221EEF0(ctx); out=ov10_0221EEF0(ctx);
 if ((U32(ctx,0x1BC+4*BattleSystem_GetFieldSide(bsys,ov10_0221EF34(ctx,(u8)battler))) & mask) != 0) ov10_0221EF24(ctx,out); }

void ov10_0221C828(BattleSystem *bsys, BattleContext *ctx) { s32 battler; u32 mask; s32 out;
 ov10_0221EF24(ctx,1); battler=ov10_0221EEF0(ctx); mask=ov10_0221EEF0(ctx); out=ov10_0221EEF0(ctx);
 if ((U32(ctx,0x1BC+4*BattleSystem_GetFieldSide(bsys,ov10_0221EF34(ctx,(u8)battler))) & mask) == 0) ov10_0221EF24(ctx,out); }

void ov10_0221C878(BattleSystem *bsys, BattleContext *ctx) { s32 a,b; (void)bsys; ov10_0221EF24(ctx,1); a=ov10_0221EEF0(ctx); b=ov10_0221EEF0(ctx); if (*(s32 *)((u8 *)ctx+0x35C) < a) ov10_0221EF24(ctx,b); }

void ov10_0221C8A8(BattleSystem *bsys, BattleContext *ctx) { s32 a,b; (void)bsys; ov10_0221EF24(ctx,1); a=ov10_0221EEF0(ctx); b=ov10_0221EEF0(ctx); if (*(s32 *)((u8 *)ctx+0x35C) > a) ov10_0221EF24(ctx,b); }
