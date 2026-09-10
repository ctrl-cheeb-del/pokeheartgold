#ifndef PRIVATE_UNK_02061284_H
#define PRIVATE_UNK_02061284_H
#include "map_object_movement_internal.h"
typedef struct LocalMovementState {
    s16 state;
    s16 delay;
    u32 restrictToRange;
    u32 heldMovement;
    u32 directionTable;
} LocalMovementState;
typedef struct LocalMovementBounds {
    s32 minX;
    s32 minZ;
    s32 maxX;
    s32 maxZ;
} LocalMovementBounds;
BOOL sub_02060BB8(LocalMapObject *, int);
int GetDeltaXByFacingDirection(int);
int GetDeltaYByFacingDirection(int);
void sub_020613F8(LocalMapObject *);
void sub_020614F4(LocalMapObject *, LocalMovementBounds *);
BOOL sub_020615F0(LocalMapObject *, int);
#endif
