#include "follow_mon.h"
#include "overlay02_follow_movement_task_private.h"

BOOL ov02_0224E0EC(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    Ov02FollowMovementTaskEnv *env = TaskManager_GetEnvironment(taskManager);
    BOOL done = FALSE;

    switch (env->state) {
    case 0:
        MapObject_UnpauseMovement(FollowMon_GetMapObject(fieldSystem));
        env->state++;
    case 1:
        if (!MapObject_AreBitsSetForMovementScriptInit(env->object1)) {
            break;
        }
        if (!MapObject_AreBitsSetForMovementScriptInit(env->object2)) {
            break;
        }
        MapObject_PauseMovement(FollowMon_GetMapObject(fieldSystem));
        env->state++;
        break;
    case 2: {
        u32 movement;
        env->object1X = MapObject_GetXCoord(env->object1);
        env->object1Z = MapObject_GetZCoord(env->object1);
        env->object1Direction = MapObject_GetFacingDirection(env->object1);
        env->object2X = MapObject_GetXCoord(env->object2);
        env->object2Z = MapObject_GetZCoord(env->object2);
        movement = ov02_0224E224(&env->object1X, &env->object2X);
        MapObject_SetHeldMovement(env->object1, movement);
        MapObject_SetHeldMovement(env->object2, ov02_0224E2D4(movement));
        env->state++;
        break;
    }
    case 3:
        if (!MapObject_AreBitsSetForMovementScriptInit(env->object1)) {
            break;
        }
        if (!MapObject_AreBitsSetForMovementScriptInit(env->object2)) {
            break;
        }
        env->state++;
        break;
    case 4:
        MapObject_SetHeldMovement(env->object1, ov02_0224E2A0(MapObject_GetFacingDirection(env->object1)));
        MapObject_SetHeldMovement(env->object2, ov02_0224E26C(env->object1Direction));
        env->state++;
        break;
    case 5:
        if (!MapObject_AreBitsSetForMovementScriptInit(env->object1)) {
            break;
        }
        if (!MapObject_AreBitsSetForMovementScriptInit(env->object2)) {
            break;
        }
        MapObject_ClearHeldMovementIfActive(env->object1);
        MapObject_ClearHeldMovementIfActive(env->object2);
        done = TRUE;
        Heap_Free(env);
        break;
    }

    return done;
}

u32 ov02_0224E224(const s32 *object1Position, const s32 *object2Position) {
    u32 movement = 13;

    if (object1Position[0] == object2Position[0]) {
        if (object1Position[1] > object2Position[1]) {
            movement = 12;
        } else if (object1Position[1] >= object2Position[1]) {
            GF_AssertFail();
        }
    } else if (object1Position[1] == object2Position[1]) {
        if (object1Position[0] > object2Position[0]) {
            movement = 14;
        } else if (object1Position[0] < object2Position[0]) {
            movement = 15;
        } else {
            GF_AssertFail();
        }
    } else {
        GF_AssertFail();
    }
    return movement;
}

u32 ov02_0224E26C(u8 direction) {
    switch (direction) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    default:
        GF_AssertFail();
        return 0;
    }
}

u32 ov02_0224E2A0(u8 direction) {
    switch (direction) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 3;
    case 3:
        return 2;
    default:
        GF_AssertFail();
        return 0;
    }
}

u32 ov02_0224E2D4(u32 movement) {
    switch (movement) {
    case 12:
        return 13;
    case 13:
        return 12;
    case 14:
        return 15;
    case 15:
        return 14;
    default:
        GF_AssertFail();
        return 0;
    }
}
