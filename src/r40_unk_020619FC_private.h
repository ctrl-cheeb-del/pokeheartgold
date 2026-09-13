#ifndef SOL_R40_FOLLOWUP_UNK020619FC_PRIVATE_H
#define SOL_R40_FOLLOWUP_UNK020619FC_PRIVATE_H
#include "global.h"
typedef struct Unk020619FCState {
    s16 state;
    s16 turn;
    u8 data[1];
} Unk020619FCState;
int MapObject_GetInitialX(void *);
int MapObject_GetInitialZ(void *);
int MapObject_GetXCoord(void *);
int MapObject_GetZCoord(void *);
int MapObject_GetNextFacingDirection(void *);
void MapObject_SetNextFacingDirection(void *, int);
void MapObject_SetFacingDirection(void *, int);
void MapObject_ForceSetHeldMovement(void *, int);
void MapObject_SetSingleMovement(void *);
int sub_020611F4(int);
int sub_02062050(void *);
int sub_02060BB8(void *, int);
int sub_0206234C(int, int);
void sub_0206207C(void *, void *);
int sub_020619FC(void *, Unk020619FCState *);
#endif
