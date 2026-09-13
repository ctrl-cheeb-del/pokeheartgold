#ifndef POKEHEARTGOLD_R40_OV64_R3_PRIVATE_H
#define POKEHEARTGOLD_R40_OV64_R3_PRIVATE_H
#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
typedef struct Ov64InitWork {
    void *args;
    BgConfig *bgConfig;
} Ov64InitWork;
extern const GraphicsModes ov64_021E6E88;
extern const BgTemplate ov64_021E6F50, ov64_021E6EFC, ov64_021E6F18, ov64_021E6F34;
void ov64_021E5B10(Ov64InitWork *);
#endif
