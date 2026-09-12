#ifndef POKEHEARTGOLD_OVERLAY49_BATTLE_CONFIG_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY49_BATTLE_CONFIG_INTERNAL_H

#include "global.h"

#pragma require_prototypes off

typedef struct Ov49BattleConfig {
    u8 padding_00[3];
    u8 index;
    u8 valueA;
    u8 valueB;
    u8 timer;
    u8 action;
    u16 unk8;
    u16 unkA;
} Ov49BattleConfig;

extern const u16 ov49_02269EC4[];
extern const u16 ov49_02269EC6[];

void *ov49_02259FE8(void *ctx);
int ov45_0222AB28(void *object, void *value);
void *ov49_0225A30C(void *ctx, u32 type, u32 value);
u32 ov45_0222A53C(void *object);
void *ov45_0222A5C0(void *object);
void *ov45_0222A578(void *object, u8 index);
void *ov45_0222A9C8(void *state);

int ov49_02264B94(void *state);

#endif
