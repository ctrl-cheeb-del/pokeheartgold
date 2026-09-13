#ifndef POKEHEARTGOLD_R40_UNK_0205D0A8_PRIVATE_H
#define POKEHEARTGOLD_R40_UNK_0205D0A8_PRIVATE_H
#include "player_avatar_movement_control_internal.h"
void MapObject_SetFlagsBits(MapObject *, u32);
int MapObject_GetNextFacingDirection(MapObject *);
u32 sub_0205DA34(PlayerAvatar *, MapObject *, int);
int sub_020611F4(int);
BOOL sub_0206D494(void *);
BOOL sub_0205D0A8(PlayerAvatar *, int);
BOOL sub_0205D190(PlayerAvatar *);
#endif
