#ifndef POKEHEARTGOLD_OVERLAY27_R13_VALUE_WINDOWS_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY27_R13_VALUE_WINDOWS_PRIVATE_H

#include "global.h"

typedef struct MessageFormat MessageFormat;
typedef struct Pokemon Pokemon;

typedef struct Ov27WorkR13 {
    u8 padding00[0x4AC];
    MessageFormat *messageFormat;
} Ov27WorkR13;

typedef struct Ov27PokemonSlotR13 {
    u8 padding00[0x10];
    Pokemon *mon;
} Ov27PokemonSlotR13;

void BufferIntegerAsString(MessageFormat *, u32, s32, u32, u32, u32);
u32 GetMonData(Pokemon *, u32, void *);
void ov27_0225BED8(Ov27WorkR13 *, u32, u32, u32, u8, u8, u16, s32, s16);
void ov27_0225BF84(Ov27WorkR13 *, u32, u32, u16);
void ov27_0225BFCC(Ov27WorkR13 *, Ov27PokemonSlotR13 *);

#endif
