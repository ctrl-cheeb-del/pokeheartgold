#ifndef POKEHEARTGOLD_MAP_OBJECT_MOVEMENT_LOOKUP_INTERNAL_H
#define POKEHEARTGOLD_MAP_OBJECT_MOVEMENT_LOOKUP_INTERNAL_H

#include "global.h"

#include "map_object.h"
#include "player_avatar.h"

typedef struct MovementListEntry {
    int id;
    const int *list;
} MovementListEntry;

extern const MovementListEntry _020FD838[];

const int *sub_02061E6C(int id);
int sub_02061E90(LocalMapObject *object);
int sub_02061F5C(LocalMapObject *object, int tableId, int value);
int sub_02061E00(const int *list, int value);

#endif
