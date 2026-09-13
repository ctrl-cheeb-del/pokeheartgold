#ifndef POKEHEARTGOLD_SYSTEM_FLAG_QUERY_R40_H
#define POKEHEARTGOLD_SYSTEM_FLAG_QUERY_R40_H
#include "global.h"
typedef struct FlagStateR40 {
    u8 pad[0xD95];
    u8 active : 1;
    u8 rest : 7;
} FlagStateR40;
typedef struct FlagOwnerR40 {
    u8 pad[8];
    FlagStateR40 *state;
} FlagOwnerR40;
extern FlagOwnerR40 _021D4134;
#endif
