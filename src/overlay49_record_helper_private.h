#ifndef SOL40_OV49_R48_PRIVATE_H
#define SOL40_OV49_R48_PRIVATE_H
#include "global.h"
typedef struct {u8 p0[4];void *owner;void *objects[312];u8 p4e8[0x123];u8 countA;u8 p60c[6];u8 countB;} Ov49R48;
void ov49_0225ECD4(void*,void*);int ov49_0225D1C0(void*);void ov49_0225D4A0(void*,void*,int);
void ov49_0225E6E0(Ov49R48*,void*);void ov49_0225E714(Ov49R48*);
#endif
