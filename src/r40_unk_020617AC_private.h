#ifndef POKEHEARTGOLD_UNK_020617AC_PRIVATE_H
#define POKEHEARTGOLD_UNK_020617AC_PRIVATE_H
#include "global.h"

#include "map_object.h"
typedef struct DirectionList617AC {
    int value[5];
} DirectionList617AC;
extern const DirectionList617AC _020FD754;
extern const DirectionList617AC _020FD768;
BOOL sub_020617AC(LocalMapObject *object, s8 *state);
#endif
