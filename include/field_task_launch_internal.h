#ifndef TO40_UNK_02059B64_PRIVATE_H
#define TO40_UNK_02059B64_PRIVATE_H
#include "global.h"

#include "field_system.h"
#include "task.h"
typedef struct TrainerCardTaskEnv {
    u8 pad00[0x24];
    u32 player;
    u32 state;
    u8 pad2C[0x67C];
} TrainerCardTaskEnv;
u32 sub_0203769C(void);
int sub_02057ADC(void);
int sub_02057B14(int player);
int sub_02037454(void);
int sub_02057A34(int player);
int sub_02057A88(int player);
void sub_0203E2F4(void);
void sub_02059D44(FieldSystem *fieldSystem);
BOOL sub_02059B64(TaskManager *taskManager);
#endif
