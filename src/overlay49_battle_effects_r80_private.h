#ifndef POKEHEARTGOLD_OVERLAY49_BATTLE_EFFECTS_R80_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY49_BATTLE_EFFECTS_R80_PRIVATE_H

#include "global.h"

typedef BOOL (*Ov49R80StartFunc)(u16 *state, void *a, void *b);
typedef BOOL (*Ov49R80UpdateFunc)(u16 *state, void *a, int index);

extern const Ov49R80StartFunc ov49_0226A8D4[];
extern const Ov49R80UpdateFunc ov49_0226A8CC[];

void GF_AssertFail(void);
void PlaySE(u16 seqNo);
void PlayCry(u16 species, int form);
void sub_0200606C(u16 seqNo, int player);
u16 GF_DegreeToSinCosIdx(int degrees);

u8 ov49_02269154(u8 *work, u32 row, int column);
void ov49_022693A4(BOOL suppress, BOOL special, BOOL player, u32 value);
void ov49_022693D4(BOOL suppress, BOOL special, BOOL unused, u32 species);
BOOL ov49_022693F8(u16 *state, u32 index, void *a, void *b);
BOOL ov49_02269430(u16 *state, void *a, int index);
void ov49_02269474(s16 *state);
void ov49_02269494(s16 *state);

#endif
