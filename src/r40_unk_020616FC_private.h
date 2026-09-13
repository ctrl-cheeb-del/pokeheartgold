#ifndef MAP_OBJECT_MOVEMENT_R40_616FC_PRIVATE_H
#define MAP_OBJECT_MOVEMENT_R40_616FC_PRIVATE_H

#include "global.h"

#include "map_object.h"

typedef BOOL (*MovementStateFuncR40)(LocalMapObject *, u8 *);
extern MovementStateFuncR40 _020FD5D0[];
void sub_020616FC(LocalMapObject *object);

#endif
