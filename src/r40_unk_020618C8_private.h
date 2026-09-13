#ifndef SOL40_FOLLOWUP_UNK_020618C8_PRIVATE_H
#define SOL40_FOLLOWUP_UNK_020618C8_PRIVATE_H

#include "global.h"

#include "map_object_movement_internal.h"

typedef struct MovementState618C8 {
    s8 state;
    u8 pad01;
    u8 flag;
} MovementState618C8;

extern const int _020FD77C[5];
extern const int _020FD7A4[5];
BOOL sub_020618C8(LocalMapObject *object, MovementState618C8 *state);

#endif
