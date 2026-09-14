#ifndef POKEHEARTGOLD_OVERLAY82_BG_SETUP_5_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY82_BG_SETUP_5_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"

typedef struct Ov82R5Work {
    u8 pad000[9];
    u8 mode;
    u8 pad00A[0x3E];
    BgConfig *bgConfig;
    u8 pad04C[0x1D4];
    NARC *narc;
} Ov82R5Work;

extern const GraphicsModes ov82_0223FE28;
extern const BgTemplate ov82_0223FE38;
extern const BgTemplate ov82_0223FE54;
extern const BgTemplate ov82_0223FE70;
extern const BgTemplate ov82_0223FE8C;
extern const BgTemplate ov82_0223FEA8;

BOOL ov80_0223792C(u8 mode);

void ov82_0223EC68(BgConfig *bgConfig);
void ov82_0223ED94(Ov82R5Work *work);
void ov82_0223EDF0(Ov82R5Work *work, u8 bgId);

#endif
