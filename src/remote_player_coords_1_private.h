#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
typedef struct CommPlayerState { u8 raw[0xF4]; } CommPlayerState;
extern CommPlayerState *_021D41C4;
extern int sub_0203769C(void); extern int sub_02057A0C(void); extern int GetDeltaXByFacingDirection(int); extern int GetDeltaYByFacingDirection(int);
int sub_02057A34(int); int sub_02057A88(int); int sub_02057ADC(int); int sub_02057B14(int);
#endif
