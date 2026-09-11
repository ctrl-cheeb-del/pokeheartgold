#ifndef UNK_020351AC_PRIVATE_H
#define UNK_020351AC_PRIVATE_H

#include "wireless_connection_state_internal.h"

extern void PlayerProfile_Copy(const void *src, void *dst);
extern u32 PlayerProfile_sizeof(void);
extern u32 PlayerProfile_GetTrainerID(const void *profile);
extern int sub_02039954(void);
extern int sub_02033AB8(void);

typedef struct Unk020351Entry {
    u8 padding[0xAA];
    u8 flag;
    u8 paddingAB[0x15];
} Unk020351Entry;

#endif
