#include "pokemon_picture_scene_internal.h"

void sub_0208E3AC(UnkStruct_0208DE40 *a) {
    u32 sp10[4];
    int species;

    a->unk_2A0 = PokepicManager_Create(0x13);
    species = sub_0208A520(a);
    if (((struct UnkStruct22C *)a->unk_22C)->unk_11 == 2) {
        GetBoxmonSpriteCharAndPlttNarcIds(sp10, species, 2, 0);
    } else {
        GetPokemonSpriteCharAndPlttNarcIds(sp10, species, 2);
    }
    NARC_ReadPokepicAnimScript(a->unk_7B8, a->unk_2A4, a->unk_23C, 1);
    a->unk_2D4 = 0;
    a->unk_2D0 = PokepicManager_CreatePokepic(a->unk_2A0, sp10, 0xd0, 0x68, 0, 0, a->unk_2A4, 0);
    Pokepic_SetAttr(a->unk_2D0, 6, 1);
    Pokepic_SetAttr(a->unk_2D0, 0x23, 0);
}

void sub_0208E444(UnkStruct_0208DE40 *a) {
    if (a->unk_280_28) {
        sub_0207294C(a->unk_7B8, a->unk_2CC, a->unk_2D0, 0, 2, a->unk_2D4, 0);
    } else {
        Pokepic_StartAnim(a->unk_2D0, 1);
        sub_0207294C(a->unk_7B8, a->unk_2CC, a->unk_2D0, a->unk_23C, 2, a->unk_2D4, 0);
    }
}

void sub_0208E4B4(UnkStruct_0208DE40 *a) {
    sub_02017088(a->unk_2CC, 0);
    PokepicManager_Delete(a->unk_2A0);
    sub_0208E3AC(a);
    sub_0208E444(a);
}

int sub_0208E4DC(UnkStruct_0208DE40 *a) {
    int r;

    if (a->unk_7BF_0 == 0xF) {
        return -1;
    }
    if (((struct UnkStruct22C *)a->unk_22C)->unk_11 != 2) {
        r = TouchscreenHitbox_FindRectAtTouchNew(_02104FFC);
        if (r != -1) {
            r = _02104FD0[r][0];
        }
        return r;
    } else {
        r = TouchscreenHitbox_FindRectAtTouchNew(_02104FFC);
        if (r >= 4 && r <= 9) {
            return -1;
        }
        if (r != -1) {
            r = _02104FD0[r][0];
        }
        return r;
    }
}

u8 sub_0208E544(UnkStruct_0208DE40 *a) {
    int r = sub_0208E4DC(a);
    if (r != -1) {
        return (u8)r;
    }
    return 0xFF;
}
