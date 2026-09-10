#include "overlay80_tile_blink_internal.h"

TileBlinkManager *ov80_022384D8(void *bgConfig) {
    TileBlinkManager *manager;
    manager = Heap_Alloc(0x65, sizeof(TileBlinkManager));
    MI_CpuFill8(manager, 0, sizeof(TileBlinkManager));
    manager->task = ov80_022384FC(bgConfig);
    return manager;
}

TileBlinkTask *ov80_022384FC(void *bgConfig) {
    TileBlinkTask *state = Heap_Alloc(0x65, sizeof(TileBlinkTask));
    MI_CpuFill8(state, 0, sizeof(TileBlinkTask));
    state->bgConfig = bgConfig;
    state->state = 0;
    state->task = SysTask_CreateOnMainQueue(ov80_02238530, state, 0x1368C);
    return state;
}

void ov80_02238530(void *task, void *data) {
    TileBlinkTask *state = data;
    u16 tiles[4];
    if (state->timer < 2) {
        state->timer++;
        return;
    }
    state->timer = 0;
    state->state ^= 1;
    ov80_0223857C(tiles, (u8)state->state);
    LoadRectToBgTilemapRect(state->bgConfig, 3, tiles, 14, 2, 2, 2);
    ScheduleBgTilemapBufferTransfer(state->bgConfig, 3);
}
