#include "render_window_internal.h"

void sub_0200F6D4(void *owner, u32 species, u32 form) {
    u32 ids[4];
    void *manager = PokepicManager_Create(*(u16 *)((u8 *)owner + 0x162));
    GetMonSpriteCharAndPlttNarcIdsEx(ids, species, form, 2, 0, 0, 0);
    sub_0200F748(owner, ids);
    PokepicManager_Delete(manager);
}

void sub_0200F714(void *owner, u32 species) {
    u32 ids[4];
    void *manager = PokepicManager_Create(*(u16 *)((u8 *)owner + 0x162));
    GetPokemonSpriteCharAndPlttNarcIds(ids, species, 2);
    sub_0200F748(owner, ids);
    PokepicManager_Delete(manager);
}
