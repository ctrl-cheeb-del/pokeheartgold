#ifndef SOL_UNK_0205D340_PRIVATE_H
#define SOL_UNK_0205D340_PRIVATE_H
#include "global.h"
typedef struct PlayerAvatar PlayerAvatar;
typedef struct LocalMapObject MapObject;
extern int PlayerAvatar_GetState(PlayerAvatar *);
extern MapObject *PlayerAvatar_GetMapObject(PlayerAvatar *);
extern void GF_AssertFail(void);
extern int sub_0205D40C(PlayerAvatar *, int);
extern void sub_0205D494(PlayerAvatar *, MapObject *, int, int, u16);
extern void sub_0205D4B4(PlayerAvatar *, MapObject *, int, int, u16);
extern void sub_0205D610(PlayerAvatar *, MapObject *, int, int, u16);
extern void sub_0205D640(PlayerAvatar *, MapObject *, int, int, int, u16);
void sub_0205D340(PlayerAvatar *, int, int, int, u16);
void sub_0205D3A8(PlayerAvatar *, MapObject *, int, int, u16, u16);
#endif
