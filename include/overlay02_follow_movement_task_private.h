#ifndef TO45_OV02_RESIDUAL51_PRIVATE_H
#define TO45_OV02_RESIDUAL51_PRIVATE_H

#include "global.h"

#include "field_system.h"
#include "map_object.h"
#include "task.h"

typedef struct Ov02FollowMovementTaskEnv {
    u32 state;
    LocalMapObject *object1;
    LocalMapObject *object2;
    s32 object1X;
    s32 object1Z;
    s32 object1Direction;
    s32 object2X;
    s32 object2Z;
} Ov02FollowMovementTaskEnv;

void GF_AssertFail(void);
void Heap_Free(void *ptr);
void MapObject_PauseMovement(LocalMapObject *object);
void MapObject_UnpauseMovement(LocalMapObject *object);
BOOL MapObject_AreBitsSetForMovementScriptInit(LocalMapObject *object);
void MapObject_SetHeldMovement(LocalMapObject *object, u32 movement);
void MapObject_ClearHeldMovementIfActive(LocalMapObject *object);
u32 MapObject_GetXCoord(LocalMapObject *object);
u32 MapObject_GetZCoord(LocalMapObject *object);
u32 MapObject_GetFacingDirection(LocalMapObject *object);

BOOL ov02_0224E0EC(TaskManager *taskManager);
u32 ov02_0224E224(const s32 *object1Position, const s32 *object2Position);
u32 ov02_0224E26C(u8 direction);
u32 ov02_0224E2A0(u8 direction);
u32 ov02_0224E2D4(u32 movement);

#endif
