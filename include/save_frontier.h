#ifndef POKEHEARTGOLD_SAVE_FRONTIER_H
#define POKEHEARTGOLD_SAVE_FRONTIER_H

#include "global.h"

typedef struct FrontierSave {
    u16 unk_000[112];
    u16 unk_0E0[32][32];
    u8 filler_8E0[0xD48];
} FrontierSave; // size: 0x1628

#endif
