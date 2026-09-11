#ifndef TO30_SOL_R5_UNK_02060BFC_PRIVATE_H
#define TO30_SOL_R5_UNK_02060BFC_PRIVATE_H

#include "global.h"

typedef struct LocalMapObject LocalMapObject;
typedef struct MapObjectManager MapObjectManager;
typedef BOOL (*BehaviorPredicate)(int);

MapObjectManager *MapObject_GetManager(LocalMapObject *);
LocalMapObject *MapObjectManager_GetObjects2(MapObjectManager *);
int MapObjectManager_GetObjectCount(MapObjectManager *);
void MapObjectArray_NextObject(LocalMapObject **);
int MapObject_GetFlagsBitsMask(LocalMapObject *, u32);
int MapObject_GetXCoord(LocalMapObject *);
int MapObject_GetYCoord(LocalMapObject *);
int MapObject_GetZCoord(LocalMapObject *);
int MapObject_GetPreviousXCoord(LocalMapObject *);
int MapObject_GetPreviousZCoord(LocalMapObject *);
int MapObject_GetID(LocalMapObject *);
BOOL MapObject_CheckVisible(LocalMapObject *);
u8 ov01_022055DC(LocalMapObject *);
void ov01_02205664(LocalMapObject *, int *, int *);
int MapObject_GetInitialX(LocalMapObject *);
int MapObject_GetInitialZ(LocalMapObject *);
int MapObject_GetXRange(LocalMapObject *);
int MapObject_GetYRange(LocalMapObject *);
BOOL sub_0205F8D0(LocalMapObject *);
void *MapObject_GetFieldSystem(LocalMapObject *);
u32 sub_0205F504(LocalMapObject *);
int GetMetatileBehavior(void *, int, int);
int GetMetatileBehavior_None(void);

extern const BehaviorPredicate _020FD4BC[];
extern const BehaviorPredicate _020FD4CC[];

BOOL sub_02060BFC(LocalMapObject *, int, int, int);
BOOL sub_02060CA8(LocalMapObject *, int, int, int);
BOOL sub_02060D94(LocalMapObject *, int, int, int);
BOOL sub_02060DEC(LocalMapObject *, int, int, int);

#endif
