#ifndef SOL_R40_FOLLOWUPS_UNK_0205D83C_PRIVATE_H
#define SOL_R40_FOLLOWUPS_UNK_0205D83C_PRIVATE_H

#include "global.h"

typedef struct PlayerAvatar PlayerAvatar;
typedef struct LocalMapObject LocalMapObject;

u32 sub_0205DA34(PlayerAvatar *, LocalMapObject *, int);
int sub_0206234C(int, int);
BOOL sub_0205D684(PlayerAvatar *);
void sub_0205E048(PlayerAvatar *);
void PlayerAvatar_SetFlag6(PlayerAvatar *);
int PlayerAvatar_GetUnk24(PlayerAvatar *);
int sub_0205D658(PlayerAvatar *, int);
void PlayerAvatar_SetForcedMovement(PlayerAvatar *, BOOL);
void MapObject_SetNextFacingDirection(LocalMapObject *, int);
void PlayerAvatar_ClearUnk24ClearFlag2(PlayerAvatar *);
int MapObject_GetNextFacingDirection(LocalMapObject *);
void PlayerAvatar_SetUnk28Unk2C(PlayerAvatar *, int, int);
void sub_0205DA1C(PlayerAvatar *, LocalMapObject *, int);
BOOL PlaySE(u16);
void sub_0205D83C(PlayerAvatar *, LocalMapObject *, int);

#endif
