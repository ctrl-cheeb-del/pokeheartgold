#ifndef TO46_UNK_02065DF4_PRIVATE_H
#define TO46_UNK_02065DF4_PRIVATE_H

#include "global.h"

typedef struct LocalMapObject LocalMapObject;
typedef struct FieldSystem FieldSystem;
typedef struct PlayerAvatar PlayerAvatar;

FieldSystem *MapObject_GetFieldSystem(LocalMapObject *object);
PlayerAvatar *FieldSystem_GetPlayerAvatar(FieldSystem *fieldSystem);
int MapObject_GetXCoord(LocalMapObject *object);
int MapObject_GetZCoord(LocalMapObject *object);
int PlayerAvatar_GetPreviousXCoord(PlayerAvatar *avatar);
int PlayerAvatar_GetPreviousZCoord(PlayerAvatar *avatar);
int sub_02065DB4(LocalMapObject *object);
int sub_02061200(int x, int z, int previousX, int previousZ);
int sub_0206234C(int direction, int movement);
void MapObject_ForceSetHeldMovement(LocalMapObject *object, int movement);
void GF_AssertFail(void);

BOOL sub_02065F44(LocalMapObject *object);
BOOL sub_02065FBC(LocalMapObject *object);

#endif
