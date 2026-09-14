#ifndef POKEHEARTGOLD_OVERLAY49_WINDOW_SETUP_TEARDOWN_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY49_WINDOW_SETUP_TEARDOWN_INTERNAL_H

#include "global.h"

#include "bg_window.h"
#include "gf_gfx_loader.h"
#include "heap.h"

typedef struct Ov49WindowGroup {
    BgConfig *bgConfig;
    Window windows[5];
    void *handler;
} Ov49WindowGroup;

extern const WindowTemplate ov49_022697F4[];

void ov49_0225BB14(void *owner, NARC *narc, int member, int bgId, int tileOffset, enum HeapID heapId);
void ov49_0225BB84(Ov49WindowGroup *windows, void *display);
void ov49_0225BBA8(Ov49WindowGroup *windows, void *unused, void *context);
void ov49_0225BF80(void *state, void *unused, void *context);

#endif
