#ifndef TRAINER_AI_STATE_QUERIES_R9_PRIVATE_H
#define TRAINER_AI_STATE_QUERIES_R9_PRIVATE_H

#include "global.h"

typedef struct {
    u8 pad_00[2];
    u16 hp;
    u16 maxHp;
    u16 stat3;
    u16 stat4;
    u16 stat5;
    u8 pad_0C[0x0C];
    s8 stages[8];
    u8 pad_20[0x2C];
    s32 value0;
    u8 pad_50[0x2E];
    u8 flags : 4;
    u8 flagsHigh : 4;
    u8 pad_7F[0x15];
    s32 value1;
    u8 pad_98[0x28];
} AiBattleMon;

typedef union {
    u8 data[0x3200];
    struct {
        u8 pad_0000[0x2D40];
        AiBattleMon mons[4];
    } fields;
} AiState;

void ov10_0221EF24(AiState *, int);
int ov10_0221EEF0(AiState *);
int ov10_0221EF34(AiState *, u8);
int ov10_0221FD34(void *, AiState *, int, int);
int BattleSystem_GetMaxBattlers(void *);
int CheckSortSpeed(void *, AiState *, int, int, int);
void GF_AssertFail(void);
u32 MaskOfFlagNo(int);

void ov10_0221E19C(void *, AiState *);
void ov10_0221E1CC(void *, AiState *);
void ov10_0221E290(void *, AiState *);
void ov10_0221E460(void *, AiState *);
void ov10_0221E5B0(void *, AiState *);
void ov10_0221E600(void *, AiState *);
void ov10_0221E650(void *, AiState *);
void ov10_0221E6A4(void *, AiState *);
void ov10_0221E6F8(void *, AiState *);
void ov10_0221E74C(AiState *, int, int *, int *, int);
void ov10_0221E9A4(void *, AiState *);
void ov10_0221E9F4(void *, AiState *);
void ov10_0221EA44(void *, AiState *);
void ov10_0221EA7C(void *, AiState *);

#endif
