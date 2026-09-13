#ifndef SOL_R40_UNK_02063290_PRIVATE_H
#define SOL_R40_UNK_02063290_PRIVATE_H

#include "global.h"

typedef struct LocalMapObject LocalMapObject;

u8 *sub_0205F3E4(LocalMapObject *object);
void MapObject_IncrementMovementStep(LocalMapObject *object);
BOOL MapObjectMovementCmd102_Step1(LocalMapObject *object);

#endif
