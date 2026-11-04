#ifndef POKEHEARTGOLD_SAVE_GTS_H
#define POKEHEARTGOLD_SAVE_GTS_H

#include "pokemon_types_def.h"
#include "save.h"

typedef struct GtsSave {
    u8 storedMon[0xEC]; // the deposited Pokemon (party format), kept until it is traded or taken back
    u16 hasStoredMon;
    u16 storedMonBox;
    u32 depositDate; // packed RTCDate: year << 24 | month << 16 | day << 8 | week
    u32 tradeDate;
} GtsSave;

GtsSave *Save_Gts_Get(SaveData *saveData);
u32 Save_Gts_sizeof(void);
void Save_Gts_Init(GtsSave *);
u16 GtsSave_HasStoredMon(GtsSave *);
void GtsSave_SetHasStoredMon(GtsSave *, u16);
void GtsSave_GetStoredMon(GtsSave *, Pokemon *);
void GtsSave_SetStoredMon(GtsSave *, Pokemon *, int);
u32 GtsSave_GetDepositDate(GtsSave *);
void GtsSave_SetDepositDate(GtsSave *, u32);
u32 GtsSave_GetTradeDate(GtsSave *);
void GtsSave_SetTradeDate(GtsSave *, u32);
u16 GtsSave_GetStoredMonBox(GtsSave *);

#endif // POKEHEARTGOLD_SAVE_GTS_H
