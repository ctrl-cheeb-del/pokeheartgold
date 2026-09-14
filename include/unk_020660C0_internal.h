#ifndef UNK_020660C0_PRIVATE_H
#define UNK_020660C0_PRIVATE_H

#include "global.h"

#include "map_object.h"

typedef struct FollowState660C0 {
    u8 state;
    u8 found;
    s16 x;
    s16 z;
    u16 unk6;
    LocalMapObject *other;
} FollowState660C0;

u32 sub_02064518(LocalMapObject *object);
void sub_020661CC(LocalMapObject *object, FollowState660C0 *state, LocalMapObject *other);
LocalMapObject *sub_020660C0(LocalMapObject *object);
int sub_02066150(LocalMapObject *object, FollowState660C0 *state);

#endif
