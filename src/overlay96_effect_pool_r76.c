#include "overlay96_effect_pool_r76_private.h"

void ov96_021FC698(Ov96EffectPoolRow *rows, u32 row, const VecFx32 *position) {
    Ov96EffectPoolRow *selected;
    Ov96EffectPoolEntry *entry;

    if (row >= 3) {
        GF_AssertFail();
    }
    selected = &rows[row];
    entry = &selected->entries[selected->next];
    if (entry->active == 0) {
        ov96_021EB52C(entry->handle, 1, 1);
        ov96_021EB564(entry->handle, 1);
        ov96_021EB588(entry->handle, position);
        entry->active = 1;
        selected->next = (selected->next + 1) % 5;
    } else {
        GF_AssertFail();
    }
}

void ov96_021FC6EC(Ov96EffectPoolRow *rows, u32 row, u32 yOffset) {
    Ov96EffectPoolRow *selected;
    u8 i;
    VecFx32 position;

    if (row >= 3) {
        GF_AssertFail();
    }
    selected = &rows[row];
    for (i = 0; i < 5; i++) {
        Ov96EffectPoolEntry *entry = &selected->entries[i];
        if (entry->active != 0) {
            position = *ov96_021EB594(entry->handle);
            position.y += yOffset << 12;
            ov96_021EB588(entry->handle, &position);
            if (ov96_021EB57C(entry->handle) == 0) {
                ov96_021FC758(entry);
            }
        }
    }
}

void ov96_021FC758(Ov96EffectPoolEntry *entry) {
    entry->active = 0;
    ov96_021EB52C(entry->handle, 1, 0);
}
