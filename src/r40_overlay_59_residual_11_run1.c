#include "r40_overlay_59_residual_11_private.h"
#include "sprite.h"

extern const u32 ov59_0223C99C[];
extern const UnmanagedSpriteTemplate ov59_0223CA90[];
extern const UnmanagedSpriteTemplate ov59_0223CB08;
extern const UnmanagedSpriteTemplate ov59_0223CB30;

void ov59_0223BA44(Ov59WorkSprites *work) {
    int i;

    for (i = 0; i < 34; i++) {
        if (work->sprites[i] != NULL) {
            Sprite_Delete(work->sprites[i]);
        }
    }
}

void ov59_0223BA64(Ov59MonEntry *entry, Party *party, Pokemon *mon, u8 slot, enum HeapID heapId) {
    entry->mon = mon;
    entry->slot = slot;
    entry->species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    entry->unk07 = GetMonData(mon, 0x6F, NULL);
    entry->unk06 = GetMonData(mon, 0xA1, NULL);
    entry->unk09 = GetMonBaseStat_HandleAlternateForm(entry->species, GetMonData(mon, 0x70, NULL), 0x1C) ^ 1;
    entry->name = String_New(12, heapId);
    GetMonData(mon, 0x77, entry->name);
    CalcMonPokeathlonPerformance(entry->mon, &entry->performance);
    Party_GetMonAprijuiceModifiers(party, &entry->aprijuice, entry->slot);
}
