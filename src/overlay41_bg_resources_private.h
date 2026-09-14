#ifndef TO45_OVERLAY41_BG_RESOURCES_PRIVATE_H
#define TO45_OVERLAY41_BG_RESOURCES_PRIVATE_H

#include <string.h>

#include "global.h"

#include "bg_window.h"

typedef struct Ov41R14State {
    u8 pad00[0x34];
    void *rawResMan;
    void *rawResources;
    int rawResourceCount;
    BgConfig *bgConfig;
} Ov41R14State;

void *GF2dGfxRawResMan_Create(int count, int heapId);
void ov41_022468FC(Ov41R14State *);
void ov41_02246A20(Ov41R14State *);
void ov41_02246A50(Ov41R14State *);
extern const BgTemplate ov41_0224BFE0, ov41_0224BFFC, ov41_0224C034;
extern const BgTemplate ov41_0224BFC4, ov41_0224C050;

#endif
