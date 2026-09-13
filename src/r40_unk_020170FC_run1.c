#include "r40_unk_020170FC_private.h"

void sub_020170FC(Unk020170FCState *state) {
    u8 empty;
    u8 i;

    state->field18 = 0;
    state->counter = 0;
    empty = 0;
    for (i = 0; i < 4; i++) {
        Unk020170FCEntry *entry = &state->entries[i];
        if (entry->active != 0) {
            if (entry->delay == 0) {
                entry->callback(entry, state);
            } else {
                entry->delay--;
            }
        } else {
            empty++;
        }
    }
    if (empty == 4) {
        state->activeFlag = 0;
    }
    if (state->activeFlag != 0) {
        sub_020179D4(state);
        sub_02017A1C(state);
        return;
    }
    if (state->paletteFlag != 0) {
        if (Pokepic_ResumePaletteFade(state->pokepic) == 0) {
            state->paletteFlag = 0;
        } else {
            return;
        }
    }
    do {
        state->counter++;
        if (*state->script >= 0x22) {
            GF_AssertFail();
        }
        _020F61F8[*state->script](state);
        if (state->field1C != 0) {
            return;
        }
        state->script++;
        if (state->field18 != 0) {
            return;
        }
        if (state->activeFlag != 0) {
            sub_020179D4(state);
            sub_02017A1C(state);
            return;
        }
    } while (state->counter < 0x100);
    GF_AssertFail();
    state->field1C = 1;
}
