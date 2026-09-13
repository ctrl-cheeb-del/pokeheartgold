#ifndef POKEHEARTGOLD_MOVEMENT_CMD_040_R40_H
#define POKEHEARTGOLD_MOVEMENT_CMD_040_R40_H
#include "global.h"

#include "map_object.h"
typedef struct Movement040Work {
    s16 movement;
    s16 timer;
    u8 pad[8];
} Movement040Work;
void sub_02060F78(LocalMapObject *);
#endif
