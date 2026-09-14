#include "overlay49_object_state.h"

#include "global.h"

void *Heap_Alloc(int, u32);
void Heap_Free(void *);

void ov49_0225CE88(Ov49State *, void *);
void ov49_0225D7B8(Ov49State *, void *);
void ov49_0225DA70(void *, void *);
void ov49_0225DD68(Ov49State *, void *);
void ov49_0225D804(Ov49State *, void *);
void ov49_0225DD0C(void *, void *);
void ov49_0225DAFC(void *, void *);
Ov49State *ov49_0225CC4C(int, int, int);
void ov49_0225CCC0(Ov49State *);
void ov49_0225CCF0(Ov49State *);
void ov49_0225CD58(Ov49State *);

Ov49State *ov49_0225CC4C(int count180, int count228, int heapId) {
    Ov49State *state = Heap_Alloc(heapId, 0x4A4);
    memset(state, 0, 0x4A4);
    state->objects180 = Heap_Alloc(heapId, count180 * 0xB4);
    state->objects228 = Heap_Alloc(heapId, count228 * 0xE4);
    memset(state->objects180, 0, count180 * 0xB4);
    memset(state->objects228, 0, count228 * 0xE4);
    state->count180 = count180;
    state->count228 = count228;
    return state;
}

void ov49_0225CCC0(Ov49State *state) {
    if (state->resource != NULL) {
        ov49_0225CE88(state, state->resource);
    }
    Heap_Free(state->objects180);
    Heap_Free(state->objects228);
    Heap_Free(state);
}

void ov49_0225CCF0(Ov49State *state) {
    int i;
    ov49_0225D7B8(state, state->embedded12C);
    for (i = 0; i < state->count180; i++) {
        ov49_0225DA70((u8 *)state->objects180 + i * 0xB4, state->embedded1C4);
    }
    for (i = 0; i < state->count228; i++) {
        ov49_0225DD68(state, (u8 *)state->objects228 + i * 0xE4);
    }
}

void ov49_0225CD58(Ov49State *state) {
    int i;
    GF_ASSERT(state != NULL);
    GF_ASSERT(state->objects228 != NULL);
    GF_ASSERT(state->objects180 != NULL);
    ov49_0225D804(state, state->embedded12C);
    for (i = 0; i < state->count228; i++) {
        ov49_0225DD0C(state->embedded29C, (u8 *)state->objects228 + i * 0xE4);
    }
    for (i = 0; i < state->count180; i++) {
        ov49_0225DAFC((u8 *)state->objects180 + i * 0xB4, state->embedded1C4);
    }
}
