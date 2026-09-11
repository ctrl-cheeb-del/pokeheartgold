#ifndef POKEHEARTGOLD_SCRATCH_UNK_02036AD8_H
#define POKEHEARTGOLD_SCRATCH_UNK_02036AD8_H
#include "global.h"
typedef struct CommGlobalPrivate {
    u8 pad[8];
    u8 *work;
} CommGlobalPrivate;
extern CommGlobalPrivate _021D4140;
int sub_02036D14(const u8 *data, int slot);
#endif
