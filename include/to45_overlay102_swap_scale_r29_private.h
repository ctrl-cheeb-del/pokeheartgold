#ifndef OVERLAY102_SWAP_SCALE_R29_PRIVATE_H
#define OVERLAY102_SWAP_SCALE_R29_PRIVATE_H

#include "global.h"

#include "sprite.h"

typedef void BgConfig;

typedef struct Ov102ScreenData {
    u16 width;
    u16 height;
    u8 padding04[8];
    u8 pixels[];
} Ov102ScreenData;

typedef struct Ov102Owner {
    u8 padding00[0x0C];
    Sprite *sprite;
    BgConfig *bgConfig;
    u8 padding14[0x4C];
    Ov102ScreenData *screen;
    void *task;
} Ov102Owner;

typedef struct Ov102SwapWork {
    u8 *owner;
    u32 state;
    u16 timer;
    u16 selection;
    u16 count;
} Ov102SwapWork;

void ov102_021EB570(Ov102Owner *work, u32 selection, u32 side);
void ov102_021EB530(Ov102Owner *work, u16 selection);
void ov102_021EB5B8(void *task, void *data);

#endif
