#ifndef POKEHEARTGOLD_UNK_020355DC_PRIVATE_H
#define POKEHEARTGOLD_UNK_020355DC_PRIVATE_H

#include "global.h"

typedef struct NetworkState355DC {
    u16 localId;
    u16 padding02;
    int state;
    u8 *work;
} NetworkState355DC;

extern NetworkState355DC _021D4134;
BOOL sub_020355DC(u16 index);
extern u16 sub_02033250(void);
extern u32 sub_02033298(void);

#endif
