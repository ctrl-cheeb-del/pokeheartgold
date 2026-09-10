#ifndef PRIVATE_OVERLAY_80_022384D8_H
#define PRIVATE_OVERLAY_80_022384D8_H

#include "global.h"

typedef struct TileBlinkTask {
    void *task;
    void *bgConfig;
    u16 state;
    u16 timer;
} TileBlinkTask;

typedef struct TileBlinkManager {
    u32 unused;
    TileBlinkTask *task;
} TileBlinkManager;

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void sub_02014DA0(void);
void *SysTask_CreateOnMainQueue(void (*callback)(void *, void *), void *data, u32 priority);
void SysTask_Destroy(void *task);
void LoadRectToBgTilemapRect(void *bgConfig, u32 bgId, const void *src, u32 x, u32 y, u32 width, u32 height);
void ScheduleBgTilemapBufferTransfer(void *bgConfig, u32 bgId);

TileBlinkManager *ov80_022384D8(void *bgConfig);
TileBlinkTask *ov80_022384FC(void *bgConfig);
void ov80_02238530(void *task, void *data);
void ov80_0223857C(u16 *tiles, u32 state);
void ov80_022385B0(TileBlinkManager *manager);
void ov80_022385C4(TileBlinkTask *task);
u32 ov80_022385D8(u32 value);
u32 ov80_02238610(u32 value);

#endif
