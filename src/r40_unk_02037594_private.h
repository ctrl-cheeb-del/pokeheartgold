#ifndef COMMUNICATION_MANAGER_R40_37594_PRIVATE_H
#define COMMUNICATION_MANAGER_R40_37594_PRIVATE_H

#include "global.h"

typedef struct CommManagerR40 {
    u8 initialized;
    u8 updateLock;
    u8 padding02[2];
    void *allocation;
    u8 *work;
} CommManagerR40;

extern CommManagerR40 _021D4140;
s32 sub_02035FF0(void);
s32 sub_020376E0(s32 kind, void *data);
s32 sub_02037108(s32 kind, void *data, s32 value);
void sub_02035FA8(s32 value);
void sub_02037594(void);

#endif
