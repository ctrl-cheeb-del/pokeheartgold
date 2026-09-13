#ifndef FIELD_APPLICATION_TASKS_R40_5A03C_PRIVATE_H
#define FIELD_APPLICATION_TASKS_R40_5A03C_PRIVATE_H

#include "global.h"

typedef void (*FieldCallbackR40)(void *);
typedef struct FieldApplicationDataR40 {
    u8 padding00[0x10];
    FieldCallbackR40 callback;
    u8 padding14[0xFC];
    void *entries[16];
} FieldApplicationDataR40;
extern u8 _021D41D8[0x40];
void SysTask_Destroy(void *task);
void *sub_02035754(s32 index);
void sub_0205A03C(void *task, FieldApplicationDataR40 *data);

#endif
