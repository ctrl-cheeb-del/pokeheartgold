#include "overlay_resource_actor_internal.h"

void sub_020771A0(void *bg) {
    GfGfx_EngineATogglePlanes(1, 0);
    GfGfx_EngineATogglePlanes(2, 0);
    FreeBgTilemapBuffer(bg, 1);
    FreeBgTilemapBuffer(bg, 2);
    FreeBgTilemapBuffer(bg, 3);
    FreeBgTilemapBuffer(bg, 4);
    FreeBgTilemapBuffer(bg, 5);
    FreeBgTilemapBuffer(bg, 6);
}

void sub_020771E8(Work *work) {
    PokemonSpriteIds ids;
    void *mon;
    GetPokemonSpriteCharAndPlttNarcIds(&ids, work->pokemon, 2);
    work->pokepic1 = PokepicManager_CreatePokepic(work->pokepicMgr, &ids, 0x80, 0x50, 0, 0, 0, 0);
    mon = AllocMonZeroed(work->heapId);
    CopyPokemonToPokemon(work->pokemon, mon);
    SetMonData(mon, 5, &work->flag62);
    CalcMonLevelAndStats(mon);
    GetPokemonSpriteCharAndPlttNarcIds(&ids, mon, 2);
    Heap_Free(mon);
    work->pokepic2 = PokepicManager_CreatePokepic(work->pokepicMgr, &ids, 0x80, 0x50, 0, 0, 0, 0);
    Pokepic_SetAttr(work->pokepic2, 0xc, 0);
    Pokepic_SetAttr(work->pokepic2, 0xd, 0);
}
