#include "overlay96_r15_exact_private.h"

typedef struct Ov96ReadyState {
    u8 pad00[8];
    BOOL ready;
    void *pending;
} Ov96ReadyState;

u8 ov96_021E9180(const u8 *data, u32 offset) {
    u8 row = 0;
    u8 result = 0xff;

    data += offset;
    do {
        u8 column = 0;
        do {
            if (*data != 0) {
                result = row;
                break;
            }
            column++;
            data++;
        } while (column < 4);
        if (column != 4) {
            break;
        }
        row++;
    } while (row < 8);
    return result;
}

int ov96_021E91B8(int species, int form, int gender) {
    int model;

    if (species <= 0 || species > 493) {
        model = 1;
    } else {
        model = SpeciesToOverworldModelIndexOffset(species) + 297;
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

void ov96_021E9204(void *object, f32 x, f32 y) {
    Sprite *sprite;
    VecFx32 scale = { 0, 0, 0 };

    sprite = ov96_021E8BAC(object);
    scale.x = (fx32)(x > 0.0f ? x * 4096.0f + 0.5f : x * 4096.0f - 0.5f);
    scale.y = (fx32)(y > 0.0f ? y * 4096.0f + 0.5f : y * 4096.0f - 0.5f);
    Sprite_SetAffineScale(sprite, &scale);
}

void ov96_021E9290(void *arg) {
    Ov96ReadyState *state = arg;

    if (state == NULL) {
        GF_AssertFail();
    }
    if (state->pending != NULL) {
        GF_AssertFail();
    }
    state->ready = TRUE;
}
