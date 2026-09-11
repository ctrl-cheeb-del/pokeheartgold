#ifndef SOL40_UNK_02056EF4_PRIVATE_H
#define SOL40_UNK_02056EF4_PRIVATE_H
#include "global.h"
#include "player_avatar.h"
typedef struct CommPlayerState { u8 raw[0xF4]; } CommPlayerState;
extern CommPlayerState *_021D41C4;
u32 sub_0203769C(void);
void sub_02056EF4(void);
#endif
