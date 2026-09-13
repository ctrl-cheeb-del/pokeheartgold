#ifndef UNK_02066370_PRIVATE_H
#define UNK_02066370_PRIVATE_H

#include "global.h"

#include "map_object.h"

typedef struct MapObjectFollowState66370 {
    u8 state;
    u8 unk01;
    u8 fixedFacing;
    u8 unk03;
    s32 facing;
} MapObjectFollowState66370;

extern const VecFx32 _020FE3E8;
int sub_02066420(LocalMapObject *object, int value);
void sub_02066370(LocalMapObject *object);

#endif
