#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
typedef struct Work{u8 pad0[0x1f8];void **save;u8 pad1[0x1f4];u8 records[1];}Work;u32 ov96_021E5F24(Work*);void *Save_Pokeathlon_FriendshipRecords_Get(void*);void ov96_021E7F48(Work*);
#endif
