#ifndef POKEHEARTGOLD_TO45_OV96_R102_GAP2_PRIVATE_H
#define POKEHEARTGOLD_TO45_OV96_R102_GAP2_PRIVATE_H

#include "global.h"

BOOL ov96_0220FCB0(const s16 *point, int value);
typedef struct Ov96Gap2Group {
    u8 padding[8];
    void *sprite;
    u8 padding_0C[0xD4];
    u32 low : 2;
    u32 score : 16;
    u32 rest : 14;
} Ov96Gap2Group;
u32 ov96_0220F3BC(const void *object);
void ov96_021E8228(void *sprite, u8 row, u8 column, u32 kind, u32 value);
void ov96_0220FD28(void *object, void *groups, const u8 *input);

#endif
