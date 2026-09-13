#ifndef SOL_R40_NIGHT_OV80_R2_PRIVATE_H
#define SOL_R40_NIGHT_OV80_R2_PRIVATE_H
#include "global.h"
typedef struct {
    void *task;
    void *bgConfig;
    u8 screens[0x2000];
    u8 chars[0x20000];
    u8 timer;
    u8 index;
    u8 pad[2];
} TileTask;
void BG_LoadCharTilesData(void *, int, const void *, u32, u32);
void BG_LoadScreenTilemapData(void *, int, const void *, u32);
void ScheduleBgTilemapBufferTransfer(void *, int);
void ov80_02239ED8(void *, TileTask *);
#endif
