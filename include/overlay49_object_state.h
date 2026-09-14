#ifndef POKEHEARTGOLD_OVERLAY49_OBJECT_STATE_H
#define POKEHEARTGOLD_OVERLAY49_OBJECT_STATE_H

#include "global.h"

typedef struct Ov49State {
    u8 pad_000[0x11C];
    void *objects180;
    void *objects228;
    u8 count180;
    u8 count228;
    u8 pad_126[2];
    void *resource;
    u8 embedded12C[0x98];
    u8 embedded1C4[0xD8];
    u8 embedded29C[0x208];
} Ov49State;

#endif
