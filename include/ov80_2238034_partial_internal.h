#ifndef TO30_OVERLAY_80_02238034_PRIVATE_H
#define TO30_OVERLAY_80_02238034_PRIVATE_H

#include "global.h"

#define U8AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(void **)((u8 *)(p) + (o)))

extern const u16 ov80_0223D514[];
extern const u16 ov80_0223D516[];
extern const u16 ov80_0223D518[];
extern const u16 ov80_0223D51A[];

u16 LCRandom(void);
void GF_AssertFail(void);
void *Save_PlayerData_GetProfile(void *save);
void sub_0207217C(void *mon, void *profile, u32, u32, u32, u32);
void *SaveArray_Party_Init(void *save);
void *AllocMonZeroed(u32 heapId);
void Heap_Free(void *ptr);
void ov80_0222A140(void *src, void *mon, u32 level);
void Party_AddMon(void *party, void *mon);
void *Party_GetMonByIndex(void *party, s32 slot);
void SetMonData(void *mon, u32 attr, const void *value);

u32 ov80_02238034(u32 a0, u32 row, u32 column);
void ov80_022380A0(u32 a0, u32 row, u16 *out, s32 count);
u8 BattleArcade_GetMonCount(u8 type, int mode);
u8 BattleArcade_GetOpponentMonCount(u8 type, int mode);
void *BattleArcade_NewBattleSetup(void *ctx, void *args);
u32 ov80_02238344(u32 type);
u32 ov80_02238370(void);
BOOL BattleArcade_MultiplayerCheck(u8 type);
void ov80_02238384(void *ctx, void *mon);
void ov80_022383A8(void *ctx, void *party, void *mon);
typedef struct ArcadeCtx38034 ArcadeCtx38034;
void ov80_022383C0(ArcadeCtx38034 *ctx);
u32 ov80_02238430(void *ctx, u8 value);
u32 ov80_02238444(void *ctx);
s32 ov80_02238498(void *ctx);
u32 ov80_022384BC(u8 value);

#endif
