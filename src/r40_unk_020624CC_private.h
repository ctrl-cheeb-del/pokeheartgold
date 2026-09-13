#ifndef UNK_020624CC_PRIVATE_H
#define UNK_020624CC_PRIVATE_H

#include "global.h"

typedef struct Movement090Work {
    u16 parameter;
    s16 timer;
    u32 direction;
    u32 distance;
} Movement090Work;

void *sub_0205F3C0(void *object, u32 size);
void *sub_0205F3E4(void *object);
void sub_02060F24(void *object, u32 direction);
void MapObject_SetOrQueueFacing(void *object, u32 direction);
void sub_0205F328(void *object, u32 parameter);
void MapObject_SetFlagsBits(void *object, u32 bits);
void MapObject_IncrementMovementStep(void *object);
void sub_0206101C(void *object, u32 direction, u32 distance);
void sub_02061070(void *object);
void sub_02060F78(void *object);
void sub_0205F484(void *object);

void sub_020624CC(void *object, u32 direction, u32 distance, s32 timer, u16 parameter);
BOOL MapObjectMovementCmd090_Step1(void *object);

#endif
