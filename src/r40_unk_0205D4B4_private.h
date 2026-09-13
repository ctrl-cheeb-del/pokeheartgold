#ifndef PLAYER_MOVEMENT_COLLISION_R40_PRIVATE_H
#define PLAYER_MOVEMENT_COLLISION_R40_PRIVATE_H
#include "global.h"
typedef struct PlayerAvatar PlayerAvatar;
typedef struct MapObject MapObject;
int sub_0205DA34(PlayerAvatar *, MapObject *, int);
int PlayerAvatar_GetState(PlayerAvatar *);
void *MapObject_GetFieldSystem(MapObject *);
int FieldSystem_IsSaveGymmickTypeEqualTo(void *, int);
int MapObject_GetXCoord(MapObject *);
int MapObject_GetZCoord(MapObject *);
int GetDeltaXByFacingDirection(int);
int GetDeltaYByFacingDirection(int);
void FuchsiaGymmick_CheckCollision(void *, int, int);
void PlaySE(u16);
void MapObject_SetNextFacingDirection(MapObject *, int);
void *PlayerAvatar_GetPlayerSaveData(PlayerAvatar *);
BOOL PlayerSaveData_CheckRunningShoes(void *);
BOOL sub_0205DE88(PlayerAvatar *, u16);
int sub_0205F504(MapObject *);
int sub_0205D44C(MapObject *, u8, int);
void sub_0205E048(PlayerAvatar *);
void PlayerAvatar_SetFlag6(PlayerAvatar *);
int sub_0206234C(int, int);
void sub_0205DA1C(PlayerAvatar *, MapObject *, int);
int MapObject_GetPreviousXCoord(MapObject *);
int MapObject_GetPreviousZCoord(MapObject *);
void ov01_02205990(int, int, int, void *);
void sub_0205D4B4(PlayerAvatar *, MapObject *, int, int, u16);
#endif
