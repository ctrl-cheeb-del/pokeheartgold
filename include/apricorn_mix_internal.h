#ifndef POKEHEARTGOLD_APRICORN_MIX_INTERNAL_H
#define POKEHEARTGOLD_APRICORN_MIX_INTERNAL_H
#include "apricorn_internal.h"

void sub_02032588(u16 *out, u8 *pair, int type);

int sub_02031D80(UnkStruct_02031CEC *data);
void sub_02031DA0(void *a0, void *a1);

struct PackedMix {
    u16 index : 4;
    u16 strength : 4;
    u16 amount : 8;
};

typedef struct ApricornPair {
    u8 index;
    u8 value;
} ApricornPair;

typedef struct ApricornJuice {
    u16 mixes[3];
    u8 indices[5];
    u8 unk_0B;
    u8 unk_0C;
    u8 unk_0D;
} ApricornJuice;

int sub_02031D80(UnkStruct_02031CEC *data);
void sub_02031DA0(void *a0, void *a1);

#endif
