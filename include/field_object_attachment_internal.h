#ifndef OV01_021F467C_PRIVATE_H
#define OV01_021F467C_PRIVATE_H

#include "global.h"

typedef struct Ov01BgConfig {
    u32 words[11];
} Ov01BgConfig;

extern void GfGfx_EngineATogglePlanes(u32, BOOL);
extern void *Heap_Alloc(u32, u32);
extern void Heap_FreeExplicit(u32, void *);
extern void *ov01_021F4464(Ov01BgConfig *);
extern void ov01_021F44B4(void *, u32, u32, u32);
extern const Ov01BgConfig ov01_02206B94;

void *ov01_021F467C(void *, void *);
void ov01_021F46DC(void *);

#endif
