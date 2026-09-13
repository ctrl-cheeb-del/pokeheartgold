#ifndef MAP_OBJECT_FOLLOW_R40_6633C_PRIVATE_H
#define MAP_OBJECT_FOLLOW_R40_6633C_PRIVATE_H

#include "global.h"

#include "map_object.h"

typedef BOOL (*FollowStateFuncR40)(LocalMapObject *, u8 *);
extern FollowStateFuncR40 _020FE3CC[];
void sub_0206633C(LocalMapObject *object);

#endif
