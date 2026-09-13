#ifndef PLAYER_AVATAR_MOVEMENT_R40_5D450_PRIVATE_H
#define PLAYER_AVATAR_MOVEMENT_R40_5D450_PRIVATE_H

#include "global.h"

typedef struct PlayerAvatar PlayerAvatar;
void PlayerAvatar_SetMoveState(PlayerAvatar *avatar, u32 state);
u32 PlayerAvatar_GetFacingDirection(PlayerAvatar *avatar);
u32 PlayerAvatar_GetMoveState(PlayerAvatar *avatar);
s32 sub_0205D450(PlayerAvatar *avatar, s32 direction);

#endif
