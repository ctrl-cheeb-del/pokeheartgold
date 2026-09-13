#ifndef SOL40_FOLLOWUP_UNK_020659A8_PRIVATE_H
#define SOL40_FOLLOWUP_UNK_020659A8_PRIVATE_H

#include "global.h"

#include "map_object.h"

u32 sub_020659A8(LocalMapObject *object);

typedef struct MapObjectState659A8 {
    u8 pad00[10];
    u16 unk0A_0 : 1;
    u16 unk0A_1 : 2;
} MapObjectState659A8;

#endif
