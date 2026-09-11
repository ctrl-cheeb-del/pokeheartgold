#ifndef TO30_SOL_R5_UNK_0205DA34_PRIVATE_H
#define TO30_SOL_R5_UNK_0205DA34_PRIVATE_H

#include "global.h"

typedef struct LocalMapObject LocalMapObject;
typedef struct FieldSystem FieldSystem;

int MapObject_GetXCoord(LocalMapObject *);
int MapObject_GetYCoord(LocalMapObject *);
int MapObject_GetZCoord(LocalMapObject *);
FieldSystem *MapObject_GetFieldSystem(LocalMapObject *);
void MapObject_CopyPositionVector(LocalMapObject *, VecFx32 *);
int GetDeltaXByFacingDirection(int);
int GetDeltaYByFacingDirection(int);
u8 GetMetatileBehavior(FieldSystem *, int, int);
BOOL sub_020549F4(FieldSystem *, VecFx32 *, int, int, s8 *);
BOOL sub_02060BFC(LocalMapObject *, int, int, int);
BOOL sub_02060D94(LocalMapObject *, int, int, int);
BOOL sub_02060DEC(LocalMapObject *, int, int, int);
BOOL sub_0205DCA0(void *, LocalMapObject *, int);
BOOL sub_0205DCFC(void *, LocalMapObject *, int);
BOOL MetatileBehavior_IsJumpNorth(u8);
BOOL MetatileBehavior_IsJumpSouth(u8);
BOOL MetatileBehavior_IsJumpWest(u8);
BOOL MetatileBehavior_IsJumpEast(u8);
BOOL MetatileBehavior_IsWarpEntranceNorth(u8);
BOOL MetatileBehavior_IsWarpEntranceSouth(u8);
BOOL MetatileBehavior_IsWarpEntranceWest(u8);
BOOL MetatileBehavior_IsWarpEntranceEast(u8);
BOOL MetatileBehavior_IsDoor(u8);

u32 sub_0205DA34(void *, LocalMapObject *, int);
u32 sub_0205DAA8(void *, LocalMapObject *, int);
BOOL sub_0205DB68(void *, LocalMapObject *, int);
BOOL sub_0205DBF4(void *, LocalMapObject *, int);

#endif
