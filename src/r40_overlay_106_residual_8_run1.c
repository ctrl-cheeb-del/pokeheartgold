#include "r40_overlay_106_residual_8_private.h"

int ov106_021E66B0(int species, int form, int gender) {
    int model;
    if (species <= 0 || species > NATIONAL_DEX_COUNT) {
        model = MMODEL_BABYGIRL1;
    } else {
        model = SpeciesToOverworldModelIndexOffset(species) + MMODEL_FOLLOWER_MON_BULBASAUR;
        if (OverworldModelLookupHasFemaleForm(species)) {
            if (gender == 1) {
                model++;
            }
        } else {
            if (form > OverworldModelLookupFormCount(species)) {
                form = 0;
            }
            model += form;
        }
    }
    return model;
}
