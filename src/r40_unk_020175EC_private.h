#ifndef SOL_R40_FOLLOWUP_UNK020175EC_PRIVATE_H
#define SOL_R40_FOLLOWUP_UNK020175EC_PRIVATE_H
#include "global.h"
typedef struct Unk020175ECState {
    u8 pad00[0x24];
    void *entries[];
} Unk020175ECState;
void sub_02017280(Unk020175ECState *, u8 *);
void sub_02017294(Unk020175ECState *, u8 *);
void sub_020172B4(Unk020175ECState *, u8 *, u8 *);
void sub_0201726C(Unk020175ECState *, void **);
int sub_02017470(void **, void **);
void sub_020175EC(Unk020175ECState *);
#endif
