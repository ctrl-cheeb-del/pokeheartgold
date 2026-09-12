#ifndef POKEHEARTGOLD_OVERLAY80_FRONTIER_SETUP_R22_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY80_FRONTIER_SETUP_R22_PRIVATE_H

#include "global.h"

typedef struct Ov80Mon {
    /* 0x00 */ u8 _p0[0xC];
    /* 0x0C */ u32 otId;
    /* 0x10 */ u32 personality;
    /* 0x14 */ u8 _p14[0x24];
} Ov80Mon; /* size 0x38 */

typedef struct Ov80Battle {
    /* 0x000 */ u8 _p0[4];
    /* 0x004 */ u8 mode;
    /* 0x005 */ u8 slot : 7;
    /* 0x006 */ u8 _p6;
    /* 0x007 */ u8 unk7;
    /* 0x008 */ u8 _p8[0x10];
    /* 0x018 */ u16 species[0x124];
    /* 0x260 */ u8 order[8];
    /* 0x268 */ u16 arr268[0x14];
    /* 0x290 */ Ov80Mon mons[4];
    /* 0x370 */ u8 _p370[0x385];
    /* 0x6F5 */ u8 f6F5;
    /* 0x6F6 */ u8 _p6F6[6];
    /* 0x6FC */ void *save;
    /* 0x700 */ u8 _p700[4];
    /* 0x704 */ u8 f704[4][9];
    /* 0x728 */ u8 _p728[0xD84 - 0x728];
    /* 0xD84 */ u16 fD84;
} Ov80Battle;

typedef struct TrHouseWork {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u8 pad8[0x30 - 0x08];
} TrHouseWork;

typedef struct Ov80Battler {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u8 _p4[0x2C];
    /* 0x30 */ void *profile;
} Ov80Battler; /* size 0x34 */

typedef struct Ov80Setup {
    /* 0x000 */ u8 _p0[4];
    /* 0x004 */ void *party0;
    /* 0x008 */ void *party1;
    /* 0x00C */ u8 _pC[4];
    /* 0x010 */ void *party2;
    /* 0x014 */ u8 _p14[0x20];
    /* 0x034 */ Ov80Battler battlers[4];
    /* 0x104 */ u8 _p104[0x48];
    /* 0x14C */ u32 unk14C;
    /* 0x150 */ u32 unk150;
} Ov80Setup;

typedef struct Ov80Arg {
    /* 0x00 */ u8 _p0[8];
    /* 0x08 */ u32 f8;
    /* 0x0C */ u32 fC;
    /* 0x10 */ u8 _p10[8];
    /* 0x18 */ u32 f18;
    /* 0x1C */ u32 f1C;
} Ov80Arg;

extern const u16 ov80_0223C5A8[];
extern const u16 ov80_0223C5B4[];
extern const u8 ov80_0223C5B8[];
extern const u16 ov80_0223C5E0[];
extern const u16 ov80_0223C608[];
extern const u16 ov80_0223C698[];
extern const u16 ov80_0223C738[];
extern const u16 ov80_0223C990[];
extern const u16 ov80_0223CD4A[];
extern const u8 ov80_0223D4C0[];

u16 LCRandom(void);
void *SaveArray_Party_Get(void *saveData);
void *Party_GetMonByIndex(void *party, int slot);
u32 GetMonData(void *mon, int field, void *dest);
void HealParty(void *party);
void *AllocMonZeroed(u32 heapId);
void CopyPokemonToPokemon(void *src, void *dst);
void UpdateMonAbility(void *mon);
void Heap_Free(void *ptr);
void Party_InitWithMaxSize(void *party, int maxSize);
Ov80Setup *BattleSetup_New(u32 heapId, u32 flags);
void BattleSetup_AddMonToParty(Ov80Setup *setup, void *mon, int side);
void BattleSetup_SetAllySideBattlersToPlayer(Ov80Setup *setup);
void PlayerProfile_Copy(void *dst, void *src);
u8 CalcShininessByOtIdAndPersonality(u32 otId, u32 personality);
fx32 FX_Sqrt(fx32 x);
u32 sub_02030BD0(u32 a, void *b);
void *sub_02034818(int a);
int sub_0203769C(void);
void sub_02051D18(Ov80Setup *setup, int a, u32 b, u32 c, u32 d, u32 e);
void *ov80_02229F04(TrHouseWork *dst, u32 species, u32 heapId, u32 d);
void ov80_0222A140(Ov80Mon *a, void *b, u8 c);
void ov80_0222A480(Ov80Setup *a, TrHouseWork *b, int c, int d, u32 e);
void ov80_0222A4EC(Ov80Mon *a, u16 b, int c, u8 d, int e, u32 f, u32 g);

void ov80_022372D8(u32 a, int n, u32 c, u32 d, u16 *out);
void ov80_02237334(int a, int b, int c, u32 d, u8 e, u16 *f);
void ov80_02237448(int a, int b, u32 c, u32 d, u32 e, u16 *f, int g);
Ov80Setup *ov80_022375D0(Ov80Battle *p, Ov80Arg *q);
u8 ov80_02237820(Ov80Battle *p, u32 i);
u32 ov80_02237850(u32 a);
int ov80_0223787C(int a);
int ov80_02237888(int a);
void ov80_02237894(Ov80Mon *a, u32 b, u32 c, u16 *d, int e, u32 f, u32 g);
u16 ov80_022378F8(Ov80Battle *p, u32 unused);
u8 ov80_02237920(u32 a);
BOOL ov80_0223792C(int a);
u8 ov80_0223793C(Ov80Battle *p);
u8 ov80_0223796C(u32 a);
int ov80_02237980(Ov80Battle *p, u32 idx, int c);
u32 ov80_022379C0(u32 a);
u16 ov80_022379C8(Ov80Battle *p);
u32 ov80_02237A40(u32 a);

#endif
