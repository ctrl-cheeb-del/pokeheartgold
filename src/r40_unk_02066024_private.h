#ifndef SOL_R40_UNK_02066024_PRIVATE_H
#define SOL_R40_UNK_02066024_PRIVATE_H

#include "map_object_follow_internal.h"

typedef BOOL (*FollowStateHandlerR40)(LocalMapObject *object, FollowState *state);

extern const FollowStateHandlerR40 _020FE3D4[];
void sub_02066024(LocalMapObject *object);

#endif
