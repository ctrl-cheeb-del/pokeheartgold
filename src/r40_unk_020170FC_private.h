#ifndef SOL_R40_FOLLOWUP_UNK020170FC_PRIVATE_H
#define SOL_R40_FOLLOWUP_UNK020170FC_PRIVATE_H
#include "global.h"
typedef struct Unk020170FCState Unk020170FCState;
typedef struct Unk020170FCEntry Unk020170FCEntry;
typedef void (*Unk020170FCEntryCallback)(Unk020170FCEntry *, Unk020170FCState *);
typedef void (*Unk020170FCCommand)(Unk020170FCState *);
struct Unk020170FCEntry {
    u32 active;
    u8 pad04[0x29];
    u8 delay;
    u8 pad2E[0x22];
    Unk020170FCEntryCallback callback;
};
struct Unk020170FCState {
    void *pokepic;
    u8 pad04[8];
    u32 *script;
    u8 pad10[8];
    u32 field18;
    u32 field1C;
    u8 pad20[0x24];
    s32 counter;
    u8 pad48[0x34];
    Unk020170FCEntry entries[4];
    u8 pad1CC;
    u8 activeFlag;
    u8 pad1CE;
    u8 paletteFlag;
};
extern Unk020170FCCommand _020F61F8[];
void sub_020179D4(Unk020170FCState *);
void sub_02017A1C(Unk020170FCState *);
int Pokepic_ResumePaletteFade(void *);
void sub_020170FC(Unk020170FCState *);
#endif
