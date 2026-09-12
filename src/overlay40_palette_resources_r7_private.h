#ifndef POKEHEARTGOLD_OVERLAY40_PALETTE_RESOURCES_R7_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY40_PALETTE_RESOURCES_R7_PRIVATE_H

#include "global.h"

typedef struct Ov40R7ValueTable {
    u32 values[7];
} Ov40R7ValueTable;

extern const u32 ov40_02244E5C[7];
extern const u32 ov40_02244E94[7];

void PaletteData_BlendPalettes(void *data, int buffer, u16 selected, u8 amount, u16 color);

u32 ov40_0222DAC0(u8 *work);
u32 ov40_0222DAF0(u8 *work);
void ov40_0222DD08(u8 *work);

#endif
