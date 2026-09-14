#include "overlay95_pokepic_setup_private.h"

void ov95_021E623C(Ov95WorkR7 *work) {
    Pokemon *mon = *(Pokemon **)((u8 *)work->app + 0xC);
    u32 species = GetMonData(mon, 5, NULL);
    u32 y = sub_0207083C(mon, 2);
    u32 zero = 0;
    PokepicTemplate template;
    PokepicAnimScript anim;

    SetMonData(mon, 0x4C, &zero);
    GetPokemonSpriteCharAndPlttNarcIds(&template, mon, 2);
    NARC_ReadPokepicAnimScript(work->narc, &anim, (u16)species, 1);
    work->pokepic = PokepicManager_CreatePokepic(work->pokepicManager, &template, 0x80, y + 0x60, 0, 0, &anim, NULL);
}

void ov95_021E62A4(Ov95WorkR7 *work) {
    u32 species = GetMonData(*(Pokemon **)((u8 *)work->app + 0xC), 5, NULL);

    GetMonNature(*(Pokemon **)((u8 *)work->app + 0xC));
    Pokepic_StartAnim(work->pokepic, 1);
    sub_0207294C(work->narc, work->animData, work->pokepic, (u16)species, 2, 0, 0);
}
