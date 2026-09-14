#ifndef COMMUNICATION_POSITION_SYNC_PRIVATE_H
#define COMMUNICATION_POSITION_SYNC_PRIVATE_H
#include "global.h"

typedef struct CommState {
    u8 raw[0x100];
} CommState;
extern CommState *_021D41C4;
extern const u16 _0210FAB4[];
extern const u16 _0210FABC[];

int sub_0203993C(void);
int sub_0203774C(void);
int sub_0203769C(void);
int sub_02057A34(void);
void sub_02057F28(int);
int sub_0206234C(int, int);
void sub_0205DFD4(void *, int);
void sub_02058024(void);
int sub_02057B4C(u8);
int sub_02057B9C(u8);
void sub_02037184(int, u8 *);
int sub_02057EEC(int);
int GetDeltaXByFacingDirection(int);
int GetDeltaYByFacingDirection(int);
void sub_02057C5C(int, int);

void sub_02057D74(void);
void sub_02057E08(void);
BOOL sub_02057E50(void);
#endif
