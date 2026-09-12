#ifndef POKEHEARTGOLD_TRAINER_AI_TAIL_HELPERS_R12_PRIVATE_H
#define POKEHEARTGOLD_TRAINER_AI_TAIL_HELPERS_R12_PRIVATE_H

#include "global.h"

typedef struct TrainerAITailState {
    u8 data[0x3200];
} TrainerAITailState;

u8 ov10_0221EF34(TrainerAITailState *state, u32 battler);
BOOL ov10_0221F5F4(TrainerAITailState *state, int battler);
BOOL ov10_0222036C(void *battleSystem, TrainerAITailState *state, int battler);

#endif // POKEHEARTGOLD_TRAINER_AI_TAIL_HELPERS_R12_PRIVATE_H
