#ifndef PRIVATE_OVERLAY_80_02239D74_H
#define PRIVATE_OVERLAY_80_02239D74_H

#include "global.h"

typedef struct Overlay80Effect {
    void *task;
    void *owner;
    u8 palettes[0x60];
    u8 paletteIndex;
    u8 timer;
    u8 padding[2];
} Overlay80Effect;

typedef struct Overlay80Pair {
    void *tiles;
    Overlay80Effect *palette;
    u32 unused;
} Overlay80Pair;

typedef struct Overlay80TileTask {
    void *task;
    void *bgConfig;
    u8 screens[0x2000];
    u8 chars[0x20000];
    u8 timer;
    u8 index;
    u8 padding[2];
} Overlay80TileTask;

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void *SysTask_CreateOnMainQueue(void (*callback)(void *, void *), void *data, u32 priority);
void SysTask_Destroy(void *task);
void *PaletteData_GetUnfadedBuf(void *paletteData, u32 bufferId);
void PaletteData_LoadPalette(void *paletteData, const void *src, u32 bufferId, u32 offset, u32 size);
void BG_LoadCharTilesData(void *bgConfig, const void *src, u32 bgId, u32 size, u32 offset);
void BG_LoadScreenTilemapData(void *bgConfig, const void *src, u32 bgId, u32 size);
void ScheduleBgTilemapBufferTransfer(void *bgConfig, u32 bgId);
void *ov80_02239DD0(void *owner);
void ov80_02239EC4(void *object);
void ov80_02239ED8(void *task, void *data);
Overlay80Effect *ov80_02239F48(void *owner);
void ov80_02239F94(Overlay80Effect *effect);
void ov80_02239FA8(void *task, void *data);

Overlay80Pair *ov80_02239D74(void *first, void *second);
void ov80_02239DB8(Overlay80Pair *pair);

#endif
