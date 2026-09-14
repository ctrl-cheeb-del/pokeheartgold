#include "overlay41_bg_resources_private.h"

void ov41_022468FC(Ov41R14State *state) {
    {
        BgTemplate t = ov41_0224BFE0;
        InitBgFromTemplate(state->bgConfig, 1, &t, 0);
        BG_ClearCharDataRange(1, 0x20, 0, HEAP_ID_14);
        BgClearTilemapBufferAndCommit(state->bgConfig, 1);
    }
    {
        BgTemplate t = ov41_0224BFFC;
        InitBgFromTemplate(state->bgConfig, 2, &t, 0);
        BG_ClearCharDataRange(2, 0x20, 0, HEAP_ID_14);
        BgClearTilemapBufferAndCommit(state->bgConfig, 2);
    }
    {
        BgTemplate t = ov41_0224C034;
        InitBgFromTemplate(state->bgConfig, 3, &t, 0);
        BG_ClearCharDataRange(3, 0x20, 0, HEAP_ID_14);
        BgClearTilemapBufferAndCommit(state->bgConfig, 3);
    }
    {
        BgTemplate t = ov41_0224BFC4;
        InitBgFromTemplate(state->bgConfig, 4, &t, 0);
        BG_ClearCharDataRange(4, 0x20, 0, HEAP_ID_14);
        BgClearTilemapBufferAndCommit(state->bgConfig, 4);
    }
    {
        BgTemplate t = ov41_0224C050;
        InitBgFromTemplate(state->bgConfig, 5, &t, 0);
        BG_ClearCharDataRange(5, 0x20, 0, HEAP_ID_14);
        BgClearTilemapBufferAndCommit(state->bgConfig, 5);
    }
}

void ov41_02246A20(Ov41R14State *state) {
    FreeBgTilemapBuffer(state->bgConfig, 1);
    FreeBgTilemapBuffer(state->bgConfig, 2);
    FreeBgTilemapBuffer(state->bgConfig, 3);
    FreeBgTilemapBuffer(state->bgConfig, 4);
    FreeBgTilemapBuffer(state->bgConfig, 5);
}

void ov41_02246A50(Ov41R14State *state) {
    state->rawResMan = GF2dGfxRawResMan_Create(0x77, 0xE);
    state->rawResources = Heap_Alloc(HEAP_ID_14, 0x77 * sizeof(void *));
    memset(state->rawResources, 0, 0x77 * sizeof(void *));
    state->rawResourceCount = 0x77;
}
