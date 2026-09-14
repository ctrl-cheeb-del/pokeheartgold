#include "global.h"

typedef struct ResourceEntry {
    u32 loaded;
    u32 id;
    void *manager;
} ResourceEntry;

typedef struct RenderState {
    s16 count;
    u8 padding02[4];
    u16 busy;
    void *objects;
    u8 padding0C[4];
    ResourceEntry *resources;
} RenderState;

typedef struct RenderSystem {
    u8 padding00[0x100];
    RenderState *state;
} RenderSystem;

void GF3dGfxRawResMan_LoadObjTexById(void *, u32);
void GF3dGfxRawResMan_FreeObjVramAndSecondaryHeaderById(void *, u32);
void ov01_021FA6E0(void *unused, RenderSystem *sys);
void ov01_021FA71C(void *unused, RenderSystem *sys);

void ov01_021FA6E0(void *unused, RenderSystem *sys) {
    int i;
    RenderState *state = sys->state;
    u8 *entry;

    if (state->busy != 1) {
        entry = (u8 *)state->resources;
        for (i = 0; i < state->count; i++, entry += 12) {
            if (*(u32 *)entry == 0 && *(void **)(entry + 8) != NULL) {
                GF3dGfxRawResMan_LoadObjTexById(*(void **)(entry + 8), *(u32 *)(entry + 4));
                *(u32 *)entry = 1;
            }
        }
    }
}

void ov01_021FA71C(void *unused, RenderSystem *sys) {
    int i;
    RenderState *state = sys->state;
    u8 *entry;

    i = 0;
    entry = (u8 *)state->resources;
    state->busy = 1;
    if (state->count > 0) {
        do {
            if (*(u32 *)entry == 1 && *(void **)(entry + 8) != NULL) {
                GF3dGfxRawResMan_FreeObjVramAndSecondaryHeaderById(*(void **)(entry + 8), *(u32 *)(entry + 4));
                *(u32 *)entry = 0;
                *(void **)(entry + 8) = NULL;
            }
            i++;
            entry += 12;
        } while (i < state->count);
    }
    state->busy = 0;
}
