#ifndef SOL_R40_UNK_0205CB48_PRIVATE_H
#define SOL_R40_UNK_0205CB48_PRIVATE_H

#include "global.h"

#include "unk_0205CB48.h"

int sub_0205CBEC(PlayerAvatar *avatar, int direction);
int sub_0205CBE4(PlayerAvatar *avatar, int direction, int a2, int a3);
int sub_0205DDD4(PlayerAvatar *avatar, u16 keys, u16 heldKeys);
void sub_0205CC4C(PlayerAvatar *avatar, int direction, u16 keys, u16 heldKeys);
void Field_PlayerAvatar_ApplyTransitionFlags(PlayerAvatar *avatar);
BOOL sub_0205D004(PlayerAvatar *avatar, int direction);
void ov01_021F2F24(PlayerAvatar *avatar);
BOOL sub_0205D40C(PlayerAvatar *avatar, int direction);
void ov01_021F2EDC(PlayerAvatar *avatar);
void sub_0205D340(PlayerAvatar *avatar, MapLoadManager *mapLoadManager, int direction, u16 keys, u16 heldKeys);
void sub_0205CC74(PlayerAvatar *avatar);
void sub_0205CC94(PlayerAvatar *avatar);
BOOL MapObject_AreBitsSetForMovementScriptInit(LocalMapObject *mapObject);
u32 MapObject_GetMovementCommand(LocalMapObject *mapObject);
BOOL sub_0205DE64(int command);
int sub_0205DA34(PlayerAvatar *avatar, LocalMapObject *mapObject, int direction);

#endif
