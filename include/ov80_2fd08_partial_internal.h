#ifndef PRIVATE_OVERLAY_80_0222FD08_H
#define PRIVATE_OVERLAY_80_0222FD08_H
#include "global.h"
typedef struct TrainerRecordR20 {
    u32 id;
    u16 species;
    u8 rest[0x2A];
} TrainerRecordR20;
void ov80_0222FF00(void *);
void ov80_02230270(void *);
void ov80_0223049C(void *, int);
void GF_AssertFail(void);
void *ov80_02229F04(TrainerRecordR20 *, int, int, int);
void *Heap_Free(void *);
int ov80_0222A30C(int);
void *Party_GetMonByIndex(void *, int);
void Party_SafeCopyMonToSlot_ResetAprijuiceModifiers(void *, int, void *);
int ov80_02236DD4(int);
int ov80_02236DF8(int, int);
int ov80_02237120(void *);
void SaveArray_Party_Init(void *);
void *AllocMonZeroed(int);
void ov80_0222A140(void *, void *, int);
void ov80_0222A3BC(void *, void *, void *);
void ov80_0222B108(void *);
void ov80_0222B174(void *);
void ov80_0222B1DC(void *);
void ov80_0222B2C4(void *);
void ov80_0222B3B0(void *, u8);
void ov80_0222B3FC(void *, u8);
void ov80_0222B448(void *);
extern const u8 ov80_0223BDD4[];
extern const u8 ov80_0223BDE0[];
void ov80_02230AE4(void *);
void *Save_GameStats_Get(void *);
void GameStats_Inc(void *, int);
void ov80_0222FEEC(void *, int);
void ov80_02230424(void *);
void ov80_02230460(void *, void *);
int ov80_02230484(void *, u32);
u8 ov80_02230784(void *);
u8 ov80_02230790(void *);
int ov80_02230794(void *, int);
void ov80_022307C8(void *);
void ov80_022307D4(void *);
void ov80_022309F8(void *);
void ov80_02230A60(void *);
void ov80_02230AF8(void *, u32, int);
int ov80_02230B4C(void *);
#endif
