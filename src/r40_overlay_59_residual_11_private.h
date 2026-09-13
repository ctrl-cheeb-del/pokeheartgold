#ifndef SOL_R40_NIGHT_OVERLAY59_RESIDUAL11_PRIVATE_H
#define SOL_R40_NIGHT_OVERLAY59_RESIDUAL11_PRIVATE_H

#include "global.h"

#include "party.h"
#include "pm_string.h"
#include "pokemon.h"
#include "sprite_system.h"

typedef struct Ov59MonEntry {
    Pokemon *mon;
    u16 species;
    u8 unk06;
    u8 unk07;
    u8 slot;
    u8 unk09;
    u8 padding[2];
    String *name;
    PartyExtraSub aprijuice;
    u8 padding15[9];
    struct PokeathlonTodayPerformance performance;
} Ov59MonEntry;

typedef struct Ov59WorkSprites {
    u8 padding[0x258];
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    Sprite *sprites[34];
} Ov59WorkSprites;

void ov59_0223B8E4(Ov59WorkSprites *work);
void ov59_0223BA44(Ov59WorkSprites *work);
void ov59_0223BA64(Ov59MonEntry *entry, Party *party, Pokemon *mon, u8 slot, enum HeapID heapId);

#endif
