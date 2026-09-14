#ifndef TO46_OVERLAY64_R9_PRIVATE_H
#define TO46_OVERLAY64_R9_PRIVATE_H

#include "global.h"

void ManagedSprite_SetPaletteOverride(void *sprite, int palette);

typedef struct Ov64ShowcaseWork {
    u8 filler000[0x138];
    void *sprites[33];
    u32 selected;
    u32 paletteTimer;
} Ov64ShowcaseWork;

int ov64_021E6B84(Ov64ShowcaseWork *work);

#endif
