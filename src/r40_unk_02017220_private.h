#ifndef SOL_R40_FOLLOWUP_UNK02017220_PRIVATE_H
#define SOL_R40_FOLLOWUP_UNK02017220_PRIVATE_H
#include "global.h"
typedef struct Unk02017220Entry {
    u32 active;
    u8 pad04[0x4c];
    u32 value;
} Unk02017220Entry;
typedef struct Unk02017220Root {
    u8 pad00[0x7c];
    Unk02017220Entry entries[4];
} Unk02017220Root;
typedef struct Unk02017220TableEntry {
    u32 value;
    u8 pad04[8];
} Unk02017220TableEntry;
extern const Unk02017220TableEntry _020F61BC[];
Unk02017220Entry *sub_02017220(Unk02017220Root *, int);
#endif
