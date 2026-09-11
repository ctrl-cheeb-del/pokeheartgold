#ifndef PRIVATE_OVERLAY_80_02236450_H
#define PRIVATE_OVERLAY_80_02236450_H
#include "global.h"

/* 0x10-byte NARC record read by ov80_02229EF4 */
typedef struct FrontierMonSrc {
    /* 0x00 */ u16 species;
    /* 0x02 */ u16 moves[4];
    /* 0x0a */ u8 evFlags;
    /* 0x0b */ u8 nature;
    /* 0x0c */ u16 item;
    /* 0x0e */ u16 unk_0e;
} FrontierMonSrc;

/* 0x38-byte built mon entry */
typedef struct FrontierMon {
    /* 0x00 */ u16 species : 11;
    /* 0x00 */ u16 form : 5;
    /* 0x02 */ u16 item;
    /* 0x04 */ u16 moves[4];
    /* 0x0c */ u32 unk_0c;
    /* 0x10 */ u32 personality;
    /* 0x14 */ u32 iv0 : 5;
    /* 0x14 */ u32 iv1 : 5;
    /* 0x14 */ u32 iv2 : 5;
    /* 0x14 */ u32 iv3 : 5;
    /* 0x14 */ u32 iv4 : 5;
    /* 0x14 */ u32 iv5 : 5;
    /* 0x14 */ u32 pad_14 : 2;
    /* 0x18 */ u8 evs[6];
    /* 0x1e */ u8 unk_1e;
    /* 0x1f */ u8 language;
    /* 0x20 */ u8 ability;
    /* 0x21 */ u8 unk_21;
    /* 0x22 */ u16 name[11];
} FrontierMon;

typedef struct Ov80Flags {
    u8 unk_0 : 3;
    u8 unk_3 : 1;
    u8 unk_4 : 1;
    u8 unk_5 : 3;
} Ov80Flags;

typedef struct Ov80C050 {
    u16 unk_00;
    u8 unk_02[4];
} Ov80C050;

extern const u8 ov80_0223C048[];
extern const u8 ov80_0223C050[];
extern const u8 ov80_0223C07C[];
extern const u8 ov80_0223C0AC[];
extern const u8 gGameLanguage;

void GF_AssertFail(void);
void *Heap_Free(void *);
void MI_CpuFill8(void *, u8, u32);
void MI_CpuCopy8(const void *, void *, u32);
void *sub_02034818(int);
int PlayerProfile_GetVersion(void *);
void *sub_0202D928(void *);
int sub_0202D7B0(void);
void sub_0202D804(void *, void *, int);
u16 FrontierFieldSystem_0204B510(void *);
int GetNatureFromPersonality(u32);
int CalcShininessByOtIdAndPersonality(u32, u32);
u8 MaskOfFlagNo(int);
int GetMonBaseStat(int, int);
void GetSpeciesNameIntoArray(int, int, u16 *);
int GetFrontierTrainerIVs(int);
void *AllocMonZeroed(int);
void *BattleSetup_New(int, int);
void BattleSetup_AddMonToParty(void *, void *, int);
void BattleSetup_SetAllySideBattlersToPlayer(void *);
void *SaveArray_Party_Get(void *);
void *Party_GetMonByIndex(void *, int);
void Party_InitWithMaxSize(void *, int);
BOOL Party_AddMon(void *, void *);
void CopyPokemonToPokemon(void *, void *);
u32 GetMonData(void *, int, void *);
void SetMonData(void *, int, void *);
int GetMonExpBySpeciesAndLevel(int, int);
void CalcMonLevelAndStats(void *);
void sub_02051D18(void *, int, void *, int, int, int);
int _s32_div_f(int, int);

void ov80_02229EF4(void *, int, int);
void *ov80_02229F04(void *, int, int, int);
void ov80_0222A140(void *, void *, int);
void ov80_0222A480(void *, u8 *, int, int, int);

u32 ov80_02236450(void *, void *, int, u32, u32, u32, u32, int);
u32 ov80_022364A4(void *, void *, int, void *, u8, u32, u32, u32, int);
void ov80_02236698(void *, void *, int);
void ov80_022366D4(u8 *, int);
u32 ov80_02236734(void *, FrontierMon *, u16, u32, u32, u8, u8, u32, int);
void *ov80_0223690C(void *, void *);
void ov80_02236A34(void *, u8 *, int, int, int);
u32 ov80_02236A88(u32);
void ov80_02236ABC(void *, u16);
BOOL ov80_02236AD8(void *, const u16 *);
u32 ov80_02236AF0(u32);
u32 ov80_02236B04(u32);
u32 ov80_02236B18(u32);
BOOL ov80_02236B30(u32);


/* Generated integration prototypes. */
u32 ov80_02236450(void *work, void *record, int trainerId, u32 index, u32 a4, u32 a5, u32 a6, int heapId);
void ov80_02236698(void *a0, void *dst, int index);
void ov80_022366D4(u8 *dst, int index);
u32 ov80_02236734(void *work, FrontierMon *dst, u16 trainerMonId, u32 otId, u32 personality, u8 ivs, u8 index, u32 useFixedItem, int heapId);
void *ov80_0223690C(void *work, void *a1);
void ov80_02236A34(void *bs, u8 *mons, int count, int idx, int heapId);
u32 ov80_02236A88(u32 mode);
void ov80_02236ABC(void *work, u16 value);
BOOL ov80_02236AD8(void *work, const u16 *arg);
u32 ov80_02236AF0(u32 mode);
u32 ov80_02236B04(u32 mode);
u32 ov80_02236B18(u32 mode);
BOOL ov80_02236B30(u32 mode);
#endif
