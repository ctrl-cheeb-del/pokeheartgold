#include "map_object_movement_commands.h"

#include "global.h"

#include "field_effects.h"
#include "field_emote_mark.h"
#include "field_trainer_reveal.h"
#include "heap.h"
#include "map_object.h"
#include "map_object_follow_internal.h"
#include "map_object_movement_commands_internal.h"
#include "map_object_movement_utilities.h"
#include "map_object_movement_utilities_internal.h"
#include "math_util.h"
#include "sound_playback.h"
#include "sys_task_api.h"

struct EventObjectMovementWork {
    u32 state;
    BOOL finished;
    s32 index;
    LocalMapObject *object;
    const MovementScriptCommand *command;
};

typedef BOOL (*MovementScriptStateFunc)(EventObjectMovementWork *work);

typedef struct WalkMovementWork {
    u16 animation;
    s16 timer;
    u32 direction;
    u32 distance;
} WalkMovementWork;

typedef struct WalkInPlaceMovementWork {
    s16 animation;
    s16 timer;
    u8 unused[8];
} WalkInPlaceMovementWork;

typedef struct JumpMovementWork {
    s32 distance;
    s32 progress;
    u16 heightStep;
    u16 heightPos;
    s8 direction;
    s8 timer;
    u8 animation;
    s8 heightTable;
} JumpMovementWork;

typedef struct RiseMovementWork {
    s32 height;
    s32 delta;
} RiseMovementWork;

typedef struct EmoteMovementWork {
    u32 type;
    FieldEffect *effect;
} EmoteMovementWork;

typedef struct JumpOffsetData {
    u8 angleStep;
    s8 dx;
    s8 dy;
    s8 dz;
    fx32 stepX;
    fx32 stepY;
    fx32 stepZ;
    VecFx32 origin;
} JumpOffsetData;

typedef struct JumpByOffsetWork {
    s8 direction;
    s8 timer;
    u8 step;
    u8 animation;
    fx32 height;
    JumpOffsetData *data;
} JumpByOffsetWork;

typedef struct VariableSpeedWalkWork {
    s16 direction;
    s16 animation;
    s16 count;
    s16 index;
} VariableSpeedWalkWork;

enum MovementScriptMachineState {
    MOVEMENT_SCRIPT_INIT,
    MOVEMENT_SCRIPT_WAIT_READY,
    MOVEMENT_SCRIPT_SET_COMMAND,
    MOVEMENT_SCRIPT_WAIT_COMMAND,
    MOVEMENT_SCRIPT_LOOP_CHECK,
    MOVEMENT_SCRIPT_DONE,
};

extern const MovementScriptStateFunc gMovementScriptMachineStateFuncs[];

static void MapObject_StartWalkMovement(LocalMapObject *object, u32 direction, u32 distance, s32 duration, u16 animation);
static void MapObject_StartWalkInPlaceMovement(LocalMapObject *object, u32 direction, int duration, int animation);
static void MapObject_StartJumpMovement(LocalMapObject *object, s8 direction, int distance, s8 duration, u16 animation, s16 heightTable, u16 heightStep);
static void MapObject_StartDelayMovement(LocalMapObject *object, s32 duration);
static void MapObject_StartEmoteMovement(LocalMapObject *object, u32 type);
static void MapObject_StartVariableSpeedWalk(LocalMapObject *object, u32 direction, u32 count, u32 animation);
static BOOL MapObject_UpdateVariableSpeedWalk(LocalMapObject *object, const u32 *distances);
static void MapObject_StartJumpByOffsetMovement(LocalMapObject *object, int dx, int dy, s16 dz, s8 direction, s16 duration, u16 animation);

BOOL MapObject_AreBitsSetForMovementScriptInit(LocalMapObject *object) {
    if (!MapObject_TestFlagsBits(object, MAPOBJECTFLAG_ACTIVE)) {
        return FALSE;
    }
    if (MapObject_TestFlagsBits(object, MAPOBJECTFLAG_SINGLE_MOVEMENT) == TRUE) {
        return FALSE;
    }
    if (MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK4) == TRUE
        && !MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK5)) {
        return FALSE;
    }
    return TRUE;
}

void MapObject_SetHeldMovement(LocalMapObject *object, u32 movement) {
    GF_ASSERT((int)movement < 0x71);
    MapObject_SetMovementCommand(object, movement);
    MapObject_SetMovementStep(object, 0);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK4);
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK5);
}

void MapObject_ForceSetHeldMovement(LocalMapObject *object, u32 movement) {
    MapObject_SetMovementCommand(object, movement);
    MapObject_SetMovementStep(object, 0);
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK5);
}

BOOL MapObject_IsMovementPaused(LocalMapObject *object) {
    if (!MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK4)) {
        return TRUE;
    }
    if (MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK5)) {
        return TRUE;
    }
    return FALSE;
}

BOOL MapObject_ClearHeldMovementIfActive(LocalMapObject *object) {
    if (!MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK4)) {
        return TRUE;
    }
    if (!MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK5)) {
        return FALSE;
    }
    MapObject_ClearFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_UNK4 | MAPOBJECTFLAG_UNK5));
    return TRUE;
}

void MapObject_ClearHeldMovement(LocalMapObject *object) {
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK4);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK5);
    MapObject_SetMovementCommand(object, MOVEMENT_NONE);
    MapObject_SetMovementStep(object, 0);
}

EventObjectMovementMan *EventObjectMovementMan_Create(LocalMapObject *object, const MovementScriptCommand *command) {
    EventObjectMovementWork *work;
    SysTask *task;

    work = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(EventObjectMovementWork));
    GF_ASSERT(work != NULL);
    {
        u8 *dest = (u8 *)work;
        u32 size = sizeof(EventObjectMovementWork);
        while (size != 0) {
            *dest++ = 0;
            size--;
        }
    }
    {
        u32 priority = MapObjectManager_GetPriority(MapObject_GetManager(object)) - 1;
        task = SysTask_CreateOnMainQueue(MovementScriptMachine, work, priority);
    }
    GF_ASSERT(task != NULL);
    work->object = object;
    work->command = command;
    return (EventObjectMovementMan *)task;
}

BOOL EventObjectMovementMan_IsFinish(EventObjectMovementMan *movementMan) {
    EventObjectMovementWork *work = SysTask_GetData((SysTask *)movementMan);
    return work->finished;
}

void EventObjectMovementMan_Delete(EventObjectMovementMan *movementMan) {
    SysTask *task = (SysTask *)movementMan;
    EventObjectMovementWork *work = SysTask_GetData(task);

    if (MapObject_IsMovementPaused(work->object) != TRUE) {
        GF_ASSERT(FALSE);
    }
    MapObject_ClearHeldMovementIfActive(work->object);
    Heap_FreeExplicit(HEAP_ID_FIELD1, work);
    SysTask_Destroy(task);
}

void MovementScriptMachine(SysTask *task, void *data) {
    EventObjectMovementWork *work = data;
    while (gMovementScriptMachineStateFuncs[work->state](work) == TRUE) {}
}

BOOL MovementScriptMachineSub_Init(EventObjectMovementWork *work) {
    work->index = 0;
    work->state = MOVEMENT_SCRIPT_WAIT_READY;
    return TRUE;
}

BOOL MovementScriptMachineSub_WaitReady(EventObjectMovementWork *work) {
    if (!MapObject_AreBitsSetForMovementScriptInit(work->object)) {
        return FALSE;
    }
    work->state = MOVEMENT_SCRIPT_SET_COMMAND;
    return TRUE;
}

BOOL MovementScriptMachineSub_SetMovementCommand(EventObjectMovementWork *work) {
    MapObject_SetHeldMovement(work->object, work->command->command);
    work->state = MOVEMENT_SCRIPT_WAIT_COMMAND;
    return FALSE;
}

BOOL MovementScriptMachineSub_WaitMovementCommand(EventObjectMovementWork *work) {
    if (!MapObject_IsMovementPaused(work->object)) {
        return FALSE;
    }
    work->state = MOVEMENT_SCRIPT_LOOP_CHECK;
    return TRUE;
}

BOOL MovementScriptMachineSub_LoopCheck(EventObjectMovementWork *work) {
    s32 index = work->index;
    const MovementScriptCommand *command = work->command;
    index++;
    work->index = index;
    if (index < command->length) {
        work->state = MOVEMENT_SCRIPT_WAIT_READY;
        return TRUE;
    }
    work->command = command + 1;
    if (command[1].command != MOVEMENT_STEP_END) {
        work->state = MOVEMENT_SCRIPT_INIT;
        return TRUE;
    }
    work->finished = TRUE;
    work->state = MOVEMENT_SCRIPT_DONE;
    return FALSE;
}

BOOL MovementScriptMachineSub_Done(EventObjectMovementWork *work) {
    return FALSE;
}

u32 GetMovementForDirection(s32 direction, u32 movement) {
    s32 i;
    const u32 *const *table;
    const u32 *scan;
    const u32 *entry;

    GF_ASSERT(direction < DIR_MAX);
    table = gMovementsByDirection;
    entry = *table;
    while (entry != NULL) {
        for (i = 0, scan = entry; i < DIR_MAX; i++, scan++) {
            if (movement == *scan) {
                return entry[direction];
            }
        }
        table++;
        entry = *table;
    }
    GF_ASSERT(FALSE);
    return movement;
}

s32 GetMovementDirection(u32 movement) {
    s32 i;
    const u32 *const *table = gMovementsByDirection;
    const u32 *entry = *table;

    while (entry != NULL) {
        for (i = 0; i < DIR_MAX; i++) {
            if (entry[i] == movement) {
                return i;
            }
        }
        table++;
        entry = *table;
    }
    return DIR_NONE;
}

BOOL IsMovement56To59(u32 movement) {
    movement -= 0x38;
    if (movement <= 3) {
        return TRUE;
    }
    return FALSE;
}

u32 GetMovement8ForDirection(s32 direction) {
    MovementList table = _020FDA28;

    GF_ASSERT(direction < DIR_MAX);
    return table.movements[direction];
}

void MapObject_ExecuteMovementCommand(LocalMapObject *object) {
    u32 command;
    do {
        command = MapObject_GetMovementCommand(object);
        if (command == MOVEMENT_NONE) {
            break;
        }
    } while (MapObject_RunMovementCommand(object, command, MapObject_GetMovementStep(object)));
}

BOOL MapObject_RunForcedMovement(LocalMapObject *object) {
    MapObject_ExecuteMovementCommand(object);
    if (!MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK5)) {
        return FALSE;
    }
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK5);
    MapObject_SetMovementCommand(object, MOVEMENT_NONE);
    MapObject_SetMovementStep(object, 0);
    return TRUE;
}

BOOL MapObject_RunMovementCommand(LocalMapObject *object, u32 command, u32 step) {
    return gMovementCmdTable[command][step](object);
}

BOOL MapObjectMovementCmd098_Step2(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK5);
    return FALSE;
}

void MapObject_StartFaceMovement(LocalMapObject *object, u32 direction) {
    MapObject_SetFacingDirection(object, direction);
    MapObject_SetAnimation(object, MAP_OBJECT_ANIM_STAND);
    MapObject_SetPreviousCoordsToCurrent(object);
    MapObject_IncrementMovementStep(object);
}

BOOL MapObjectMovementCmd000_Step0(LocalMapObject *object) {
    MapObject_StartFaceMovement(object, DIR_NORTH);
    return TRUE;
}

BOOL MapObjectMovementCmd001_Step0(LocalMapObject *object) {
    MapObject_StartFaceMovement(object, DIR_SOUTH);
    return TRUE;
}

BOOL MapObjectMovementCmd002_Step0(LocalMapObject *object) {
    MapObject_StartFaceMovement(object, DIR_WEST);
    return TRUE;
}

BOOL MapObjectMovementCmd003_Step0(LocalMapObject *object) {
    MapObject_StartFaceMovement(object, DIR_EAST);
    return TRUE;
}

static void MapObject_StartWalkMovement(LocalMapObject *object, u32 direction, u32 distance, s32 duration, u16 animation) {
    WalkMovementWork *work = MapObject_InitMovementCmdData(object, sizeof(WalkMovementWork));

    work->animation = animation;
    work->timer = duration;
    work->direction = direction;
    work->distance = distance;
    MapObject_MoveCoordsInDirection(object, direction);
    MapObject_SetOrQueueFacing(object, direction);
    MapObject_SetAnimation(object, animation);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_START_MOVEMENT);
    MapObject_IncrementMovementStep(object);
}

BOOL MapObjectMovementCmd090_Step1(LocalMapObject *object) {
    WalkMovementWork *work = MapObject_GetMovementCmdData(object);

    MapObject_OffsetPositionInDirection(object, work->direction, work->distance);
    MapObject_UpdateHeight(object);
    work->timer--;
    if (work->timer > 0) {
        return FALSE;
    }
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_END_MOVEMENT | MAPOBJECTFLAG_UNK5));
    MapObject_SetPreviousCoordsToCurrent(object);
    MapObject_CallDrawUpdate(object);
    MapObject_SetAnimation(object, MAP_OBJECT_ANIM_STAND);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd004_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_NORTH, FX32_CONST(0.5), 32, MAP_OBJECT_ANIM_WALK_SLOWER);
    return TRUE;
}

BOOL MapObjectMovementCmd005_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_SOUTH, FX32_CONST(0.5), 32, MAP_OBJECT_ANIM_WALK_SLOWER);
    return TRUE;
}

BOOL MapObjectMovementCmd006_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_WEST, FX32_CONST(0.5), 32, MAP_OBJECT_ANIM_WALK_SLOWER);
    return TRUE;
}

BOOL MapObjectMovementCmd007_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_EAST, FX32_CONST(0.5), 32, MAP_OBJECT_ANIM_WALK_SLOWER);
    return TRUE;
}

BOOL MapObjectMovementCmd008_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_NORTH, FX32_ONE, 16, MAP_OBJECT_ANIM_WALK_SLOW);
    return TRUE;
}

BOOL MapObjectMovementCmd009_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_SOUTH, FX32_ONE, 16, MAP_OBJECT_ANIM_WALK_SLOW);
    return TRUE;
}

BOOL MapObjectMovementCmd010_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_WEST, FX32_ONE, 16, MAP_OBJECT_ANIM_WALK_SLOW);
    return TRUE;
}

BOOL MapObjectMovementCmd011_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_EAST, FX32_ONE, 16, MAP_OBJECT_ANIM_WALK_SLOW);
    return TRUE;
}

BOOL MapObjectMovementCmd012_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_NORTH, FX32_CONST(2), 8, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd013_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_SOUTH, FX32_CONST(2), 8, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd014_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_WEST, FX32_CONST(2), 8, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd015_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_EAST, FX32_CONST(2), 8, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd016_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_NORTH, FX32_CONST(4), 4, MAP_OBJECT_ANIM_WALK_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd017_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_SOUTH, FX32_CONST(4), 4, MAP_OBJECT_ANIM_WALK_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd018_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_WEST, FX32_CONST(4), 4, MAP_OBJECT_ANIM_WALK_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd019_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_EAST, FX32_CONST(4), 4, MAP_OBJECT_ANIM_WALK_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd020_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_NORTH, FX32_CONST(8), 2, MAP_OBJECT_ANIM_WALK_FASTER);
    return TRUE;
}

BOOL MapObjectMovementCmd021_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_SOUTH, FX32_CONST(8), 2, MAP_OBJECT_ANIM_WALK_FASTER);
    return TRUE;
}

BOOL MapObjectMovementCmd022_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_WEST, FX32_CONST(8), 2, MAP_OBJECT_ANIM_WALK_FASTER);
    return TRUE;
}

BOOL MapObjectMovementCmd023_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_EAST, FX32_CONST(8), 2, MAP_OBJECT_ANIM_WALK_FASTER);
    return TRUE;
}

BOOL MapObjectMovementCmd084_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_NORTH, FX32_CONST(16), 1, MAP_OBJECT_ANIM_STAND);
    return TRUE;
}

BOOL MapObjectMovementCmd085_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_SOUTH, FX32_CONST(16), 1, MAP_OBJECT_ANIM_STAND);
    return TRUE;
}

BOOL MapObjectMovementCmd086_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_WEST, FX32_CONST(16), 1, MAP_OBJECT_ANIM_STAND);
    return TRUE;
}

BOOL MapObjectMovementCmd087_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_EAST, FX32_CONST(16), 1, MAP_OBJECT_ANIM_STAND);
    return TRUE;
}

BOOL MapObjectMovementCmd088_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_NORTH, FX32_CONST(4), 4, MAP_OBJECT_ANIM_RUN);
    return TRUE;
}

BOOL MapObjectMovementCmd089_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_SOUTH, FX32_CONST(4), 4, MAP_OBJECT_ANIM_RUN);
    return TRUE;
}

BOOL MapObjectMovementCmd090_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_WEST, FX32_CONST(4), 4, MAP_OBJECT_ANIM_RUN);
    return TRUE;
}

BOOL MapObjectMovementCmd091_Step0(LocalMapObject *object) {
    MapObject_StartWalkMovement(object, DIR_EAST, FX32_CONST(4), 4, MAP_OBJECT_ANIM_RUN);
    return TRUE;
}

static void MapObject_StartWalkInPlaceMovement(LocalMapObject *object, u32 direction, int duration, int animation) {
    WalkInPlaceMovementWork *work = MapObject_InitMovementCmdData(object, sizeof(WalkInPlaceMovementWork));

    work->animation = animation;
    work->timer = duration + 1;
    MapObject_SetFacingDirection(object, direction);
    MapObject_SetAnimation(object, animation);
    MapObject_SetPreviousCoordsToCurrent(object);
    MapObject_IncrementMovementStep(object);
}

BOOL MapObjectMovementCmd040_Step1(LocalMapObject *object) {
    WalkInPlaceMovementWork *work = MapObject_GetMovementCmdData(object);

    work->timer--;
    if (work->timer > 0) {
        return FALSE;
    }
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK5);
    MapObject_SetAnimation(object, MAP_OBJECT_ANIM_STAND);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd024_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_NORTH, 32, MAP_OBJECT_ANIM_WALK_SLOWER);
    return TRUE;
}

BOOL MapObjectMovementCmd025_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_SOUTH, 32, MAP_OBJECT_ANIM_WALK_SLOWER);
    return TRUE;
}

BOOL MapObjectMovementCmd026_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_WEST, 32, MAP_OBJECT_ANIM_WALK_SLOWER);
    return TRUE;
}

BOOL MapObjectMovementCmd027_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_EAST, 32, MAP_OBJECT_ANIM_WALK_SLOWER);
    return TRUE;
}

BOOL MapObjectMovementCmd028_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_NORTH, 16, MAP_OBJECT_ANIM_WALK_SLOW);
    return TRUE;
}

BOOL MapObjectMovementCmd029_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_SOUTH, 16, MAP_OBJECT_ANIM_WALK_SLOW);
    return TRUE;
}

BOOL MapObjectMovementCmd030_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_WEST, 16, MAP_OBJECT_ANIM_WALK_SLOW);
    return TRUE;
}

BOOL MapObjectMovementCmd031_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_EAST, 16, MAP_OBJECT_ANIM_WALK_SLOW);
    return TRUE;
}

BOOL MapObjectMovementCmd032_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_NORTH, 8, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd033_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_SOUTH, 8, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd034_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_WEST, 8, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd035_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_EAST, 8, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd036_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_NORTH, 4, MAP_OBJECT_ANIM_WALK_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd037_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_SOUTH, 4, MAP_OBJECT_ANIM_WALK_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd038_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_WEST, 4, MAP_OBJECT_ANIM_WALK_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd039_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_EAST, 4, MAP_OBJECT_ANIM_WALK_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd040_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_NORTH, 2, MAP_OBJECT_ANIM_WALK_FASTER);
    return TRUE;
}

BOOL MapObjectMovementCmd041_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_SOUTH, 2, MAP_OBJECT_ANIM_WALK_FASTER);
    return TRUE;
}

BOOL MapObjectMovementCmd042_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_WEST, 2, MAP_OBJECT_ANIM_WALK_FASTER);
    return TRUE;
}

BOOL MapObjectMovementCmd043_Step0(LocalMapObject *object) {
    MapObject_StartWalkInPlaceMovement(object, DIR_EAST, 2, MAP_OBJECT_ANIM_WALK_FASTER);
    return TRUE;
}

static void MapObject_StartJumpMovement(LocalMapObject *object, s8 direction, int distance, s8 duration, u16 animation, s16 heightTable, u16 heightStep) {
    JumpMovementWork *work = MapObject_InitMovementCmdData(object, sizeof(JumpMovementWork));

    work->direction = direction;
    work->distance = distance;
    work->timer = duration;
    work->animation = animation;
    work->heightTable = heightTable;
    work->heightStep = heightStep;
    if (distance == 0) {
        MapObject_SetPreviousCoordsToCurrent(object);
    } else {
        MapObject_MoveCoordsInDirection(object, direction);
    }
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_UNK16 | MAPOBJECTFLAG_START_MOVEMENT));
    MapObject_SetOrQueueFacing(object, direction);
    MapObject_SetAnimation(object, animation);
    MapObject_IncrementMovementStep(object);
    if (!MapObject_CheckInvisible(object)) {
        PlaySE(SEQ_SE_DP_DANSA);
    }
}

BOOL MapObjectMovementCmd092_Step1(LocalMapObject *object) {
    JumpMovementWork *work = MapObject_GetMovementCmdData(object);
    VecFx32 offset;

    if (work->distance) {
        MapObject_OffsetPositionInDirection(object, work->direction, work->distance);
        MapObject_UpdateHeight(object);
        if (work->progress >= FX32_ONE * 16) {
            work->progress = 0;
            MapObject_MoveCoordsInDirection(object, work->direction);
            MapObject_SetFlagsBits(object, MAPOBJECTFLAG_START_MOVEMENT);
        }
        work->progress += (work->distance < 0) ? -work->distance : work->distance;
    }
    work->heightPos += work->heightStep;
    if (work->heightPos > 0xF00) {
        work->heightPos = 0xF00;
    }
    {
        int heightTable;
        int heightPos;
        u16 index;
        const fx32 *heights;

        heightTable = work->heightTable;
        heightPos = work->heightPos;
        index = (u16)(heightPos / 256);
        heights = gJumpHeightTables[heightTable];
        offset.x = 0;
        offset.y = heights[index];
        offset.z = 0;
    }
    MapObject_SetFacingVector(object, &offset);
    work->timer--;
    if (work->timer > 0) {
        return FALSE;
    }
    {
        VecFx32 zero = { 0, 0, 0 };
        MapObject_SetFacingVector(object, &zero);
    }
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_UNK17 | MAPOBJECTFLAG_END_MOVEMENT | MAPOBJECTFLAG_UNK5));
    MapObject_SetPreviousCoordsToCurrent(object);
    MapObject_CallDrawUpdate(object);
    MapObject_SetAnimation(object, MAP_OBJECT_ANIM_STAND);
    MapObject_IncrementMovementStep(object);
    if (!MapObject_CheckInvisible(object)) {
        PlaySE(SEQ_SE_DP_SUTYA2);
    }
    return TRUE;
}

BOOL MapObjectMovementCmd044_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_NORTH, 0, 16, MAP_OBJECT_ANIM_WALK_SLOW, 0, 0x100);
    return TRUE;
}

BOOL MapObjectMovementCmd045_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_SOUTH, 0, 16, MAP_OBJECT_ANIM_WALK_SLOW, 0, 0x100);
    return TRUE;
}

BOOL MapObjectMovementCmd046_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_WEST, 0, 16, MAP_OBJECT_ANIM_WALK_SLOW, 0, 0x100);
    return TRUE;
}

BOOL MapObjectMovementCmd047_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_EAST, 0, 16, MAP_OBJECT_ANIM_WALK_SLOW, 0, 0x100);
    return TRUE;
}

BOOL MapObjectMovementCmd048_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_NORTH, 0, 8, MAP_OBJECT_ANIM_WALK_NORMAL, 0, 0x200);
    return TRUE;
}

BOOL MapObjectMovementCmd049_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_SOUTH, 0, 8, MAP_OBJECT_ANIM_WALK_NORMAL, 0, 0x200);
    return TRUE;
}

BOOL MapObjectMovementCmd050_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_WEST, 0, 8, MAP_OBJECT_ANIM_WALK_NORMAL, 0, 0x200);
    return TRUE;
}

BOOL MapObjectMovementCmd051_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_EAST, 0, 8, MAP_OBJECT_ANIM_WALK_NORMAL, 0, 0x200);
    return TRUE;
}

BOOL MapObjectMovementCmd052_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_NORTH, FX32_CONST(2), 8, MAP_OBJECT_ANIM_WALK_NORMAL, 0, 0x200);
    return TRUE;
}

BOOL MapObjectMovementCmd053_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_SOUTH, FX32_CONST(2), 8, MAP_OBJECT_ANIM_WALK_NORMAL, 0, 0x200);
    return TRUE;
}

BOOL MapObjectMovementCmd054_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_WEST, FX32_CONST(2), 8, MAP_OBJECT_ANIM_WALK_NORMAL, 0, 0x200);
    return TRUE;
}

BOOL MapObjectMovementCmd055_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_EAST, FX32_CONST(2), 8, MAP_OBJECT_ANIM_WALK_NORMAL, 0, 0x200);
    return TRUE;
}

BOOL MapObjectMovementCmd056_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_NORTH, FX32_CONST(2), 16, MAP_OBJECT_ANIM_WALK_NORMAL, 0, 0x100);
    return TRUE;
}

BOOL MapObjectMovementCmd057_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_SOUTH, FX32_CONST(2), 16, MAP_OBJECT_ANIM_WALK_NORMAL, 0, 0x100);
    return TRUE;
}

BOOL MapObjectMovementCmd058_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_WEST, FX32_CONST(2), 16, MAP_OBJECT_ANIM_WALK_NORMAL, 0, 0x100);
    return TRUE;
}

BOOL MapObjectMovementCmd059_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_EAST, FX32_CONST(2), 16, MAP_OBJECT_ANIM_WALK_NORMAL, 0, 0x100);
    return TRUE;
}

BOOL MapObjectMovementCmd092_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_WEST, FX32_ONE, 16, MAP_OBJECT_ANIM_JUMP_NEAR_SLOW, 0, 0xF0);
    return TRUE;
}

BOOL MapObjectMovementCmd093_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_EAST, FX32_ONE, 16, MAP_OBJECT_ANIM_JUMP_NEAR_SLOW, 0, 0xF0);
    return TRUE;
}

BOOL MapObjectMovementCmd094_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_WEST, FX32_CONST(4), 12, MAP_OBJECT_ANIM_JUMP_FARTHER, 0, 0x140);
    return TRUE;
}

BOOL MapObjectMovementCmd095_Step0(LocalMapObject *object) {
    MapObject_StartJumpMovement(object, DIR_EAST, FX32_CONST(4), 12, MAP_OBJECT_ANIM_JUMP_FARTHER, 0, 0x140);
    return TRUE;
}

static void MapObject_StartDelayMovement(LocalMapObject *object, s32 duration) {
    s32 *timer = MapObject_InitMovementCmdData(object, sizeof(s32));

    *timer = duration;
    MapObject_IncrementMovementStep(object);
}

BOOL MapObjectMovementCmd064_Step1(LocalMapObject *object) {
    s32 *timer = MapObject_GetMovementCmdData(object);

    if (*timer != 0) {
        (*timer)--;
        return FALSE;
    }
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd060_Step0(LocalMapObject *object) {
    MapObject_StartDelayMovement(object, 1);
    return TRUE;
}

BOOL MapObjectMovementCmd061_Step0(LocalMapObject *object) {
    MapObject_StartDelayMovement(object, 2);
    return TRUE;
}

BOOL MapObjectMovementCmd062_Step0(LocalMapObject *object) {
    MapObject_StartDelayMovement(object, 4);
    return TRUE;
}

BOOL MapObjectMovementCmd063_Step0(LocalMapObject *object) {
    MapObject_StartDelayMovement(object, 8);
    return TRUE;
}

BOOL MapObjectMovementCmd064_Step0(LocalMapObject *object) {
    MapObject_StartDelayMovement(object, 15);
    return TRUE;
}

BOOL MapObjectMovementCmd065_Step0(LocalMapObject *object) {
    MapObject_StartDelayMovement(object, 16);
    return TRUE;
}

BOOL MapObjectMovementCmd066_Step0(LocalMapObject *object) {
    MapObject_StartDelayMovement(object, 32);
    return TRUE;
}

BOOL MapObjectMovementCmd067_Step0(LocalMapObject *object) {
    RiseMovementWork *work = MapObject_InitMovementCmdData(object, sizeof(RiseMovementWork));
    work->delta = FX32_ONE * 16;
    MapObject_SetAnimation(object, MAP_OBJECT_ANIM_STAND);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd067_Step1(LocalMapObject *object) {
    RiseMovementWork *work = MapObject_GetMovementCmdData(object);
    work->height += work->delta;
    VecFx32 offset = { 0, 0, 0 };
    offset.y = work->height;
    MapObject_SetFacingVector(object, &offset);
    if ((work->height / (FX32_ONE * 8)) < 40) {
        return FALSE;
    }
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd068_Step0(LocalMapObject *object) {
    RiseMovementWork *work = MapObject_InitMovementCmdData(object, sizeof(RiseMovementWork));
    work->height = FX32_ONE * 320;
    work->delta = -FX32_ONE * 16;
    MapObject_SetAnimation(object, MAP_OBJECT_ANIM_STAND);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd068_Step1(LocalMapObject *object) {
    RiseMovementWork *work = MapObject_GetMovementCmdData(object);
    work->height += work->delta;
    if (work->height < 0) {
        work->height = 0;
    }
    VecFx32 offset = { 0, 0, 0 };
    offset.y = work->height;
    MapObject_SetFacingVector(object, &offset);
    if (work->height > 0) {
        return FALSE;
    }
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd069_Step0(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_INVISIBLE);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd070_Step0(LocalMapObject *object) {
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_INVISIBLE);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd071_Step0(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK7);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd072_Step0(LocalMapObject *object) {
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK7);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd073_Step0(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK8);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd074_Step0(LocalMapObject *object) {
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK8);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

static void MapObject_StartEmoteMovement(LocalMapObject *object, u32 type) {
    EmoteMovementWork *work = MapObject_InitMovementCmdData(object, sizeof(EmoteMovementWork));
    work->type = type;
    work->effect = EmoteMark_Spawn(object, type, TRUE);
    MapObject_IncrementMovementStep(object);
}

BOOL MapObjectMovementCmd075_Step1(LocalMapObject *object) {
    EmoteMovementWork *work = MapObject_GetMovementCmdData(object);
    if (EmoteMark_IsDone(work->effect) == TRUE) {
        FieldEffect_Destroy(work->effect);
        MapObject_IncrementMovementStep(object);
        return TRUE;
    }
    return FALSE;
}

BOOL MapObjectMovementCmd075_Step0(LocalMapObject *object) {
    MapObject_StartEmoteMovement(object, 0);
    return FALSE;
}

BOOL MapObjectMovementCmd103_Step0(LocalMapObject *object) {
    MapObject_StartEmoteMovement(object, 1);
    return FALSE;
}

static void MapObject_StartVariableSpeedWalk(LocalMapObject *object, u32 direction, u32 count, u32 animation) {
    VariableSpeedWalkWork *work = MapObject_InitMovementCmdData(object, sizeof(VariableSpeedWalkWork));
    work->direction = direction;
    work->animation = animation;
    work->count = count;
    MapObject_MoveCoordsInDirection(object, direction);
    MapObject_SetOrQueueFacing(object, direction);
    MapObject_SetAnimation(object, animation);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_START_MOVEMENT);
    MapObject_IncrementMovementStep(object);
}

static BOOL MapObject_UpdateVariableSpeedWalk(LocalMapObject *object, const u32 *distances) {
    VariableSpeedWalkWork *work = MapObject_GetMovementCmdData(object);
    MapObject_OffsetPositionInDirection(object, work->direction, distances[work->index]);
    MapObject_UpdateHeight(object);
    work->index++;
    if (work->index < work->count) {
        return FALSE;
    }
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_END_MOVEMENT | MAPOBJECTFLAG_UNK5));
    MapObject_SetPreviousCoordsToCurrent(object);
    MapObject_CallDrawUpdate(object);
    MapObject_SetAnimation(object, MAP_OBJECT_ANIM_STAND);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd076_Step0(LocalMapObject *object) {
    MapObject_StartVariableSpeedWalk(object, DIR_NORTH, 6, MAP_OBJECT_ANIM_WALK_SLIGHTLY_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd077_Step0(LocalMapObject *object) {
    MapObject_StartVariableSpeedWalk(object, DIR_SOUTH, 6, MAP_OBJECT_ANIM_WALK_SLIGHTLY_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd078_Step0(LocalMapObject *object) {
    MapObject_StartVariableSpeedWalk(object, DIR_WEST, 6, MAP_OBJECT_ANIM_WALK_SLIGHTLY_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd079_Step0(LocalMapObject *object) {
    MapObject_StartVariableSpeedWalk(object, DIR_EAST, 6, MAP_OBJECT_ANIM_WALK_SLIGHTLY_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd076_Step1(LocalMapObject *object) {
    if (MapObject_UpdateVariableSpeedWalk(object, gVariableSpeedWalk_Cmd076) == TRUE) {
        return TRUE;
    }
    return FALSE;
}

BOOL MapObjectMovementCmd080_Step0(LocalMapObject *object) {
    MapObject_StartVariableSpeedWalk(object, DIR_NORTH, 3, MAP_OBJECT_ANIM_WALK_SLIGHTLY_FASTER);
    return TRUE;
}

BOOL MapObjectMovementCmd081_Step0(LocalMapObject *object) {
    MapObject_StartVariableSpeedWalk(object, DIR_SOUTH, 3, MAP_OBJECT_ANIM_WALK_SLIGHTLY_FASTER);
    return TRUE;
}

BOOL MapObjectMovementCmd082_Step0(LocalMapObject *object) {
    MapObject_StartVariableSpeedWalk(object, DIR_WEST, 3, MAP_OBJECT_ANIM_WALK_SLIGHTLY_FASTER);
    return TRUE;
}

BOOL MapObjectMovementCmd083_Step0(LocalMapObject *object) {
    MapObject_StartVariableSpeedWalk(object, DIR_EAST, 3, MAP_OBJECT_ANIM_WALK_SLIGHTLY_FASTER);
    return TRUE;
}

BOOL MapObjectMovementCmd082_Step1(LocalMapObject *object) {
    if (MapObject_UpdateVariableSpeedWalk(object, gVariableSpeedWalk_Cmd082) == TRUE) {
        return TRUE;
    }
    return FALSE;
}

BOOL MapObjectMovementCmd096_Step0(LocalMapObject *object) {
    MapObject_StartVariableSpeedWalk(object, DIR_NORTH, 7, MAP_OBJECT_ANIM_WALK_EVER_SO_SLIGHTLY_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd097_Step0(LocalMapObject *object) {
    MapObject_StartVariableSpeedWalk(object, DIR_SOUTH, 7, MAP_OBJECT_ANIM_WALK_EVER_SO_SLIGHTLY_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd098_Step0(LocalMapObject *object) {
    MapObject_StartVariableSpeedWalk(object, DIR_WEST, 7, MAP_OBJECT_ANIM_WALK_EVER_SO_SLIGHTLY_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd099_Step0(LocalMapObject *object) {
    MapObject_StartVariableSpeedWalk(object, DIR_EAST, 7, MAP_OBJECT_ANIM_WALK_EVER_SO_SLIGHTLY_FAST);
    return TRUE;
}

BOOL MapObjectMovementCmd098_Step1(LocalMapObject *object) {
    if (MapObject_UpdateVariableSpeedWalk(object, gVariableSpeedWalk_Cmd098) == TRUE) {
        return TRUE;
    }
    return FALSE;
}

BOOL MapObjectMovementCmd100_Step0(LocalMapObject *object) {
    MapObject_InitMovementCmdData(object, sizeof(s32));
    MapObject_SetAnimation(object, MAP_OBJECT_ANIM_NURSE_BOW);
    MapObject_IncrementMovementStep(object);
    return FALSE;
}

BOOL MapObjectMovementCmd100_Step1(LocalMapObject *object) {
    s32 *timer = MapObject_GetMovementCmdData(object);
    (*timer)++;
    if (*timer >= 8) {
        MapObject_SetFacingDirection(object, DIR_SOUTH);
        MapObject_SetAnimation(object, MAP_OBJECT_ANIM_STAND);
        MapObject_IncrementMovementStep(object);
    }
    return FALSE;
}

BOOL MapObjectMovementCmd101_Step0(LocalMapObject *object) {
    FieldEffect *effect;

    MapObject_InitMovementCmdData(object, sizeof(s32));
    effect = HiddenObjectMovement_GetCoverEffect(object);
    if (effect) {
        FieldEffect_Destroy(effect);
    }
    VecFx32 offset = { 0, 0, 0 };
    MapObject_SetFacingVector(object, &offset);
    TrainerReveal_Spawn(object);
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_UNK16 | MAPOBJECTFLAG_START_MOVEMENT));
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK20);
    MapObject_IncrementMovementStep(object);
    return FALSE;
}

BOOL MapObjectMovementCmd101_Step1(LocalMapObject *object) {
    s32 *index = MapObject_GetMovementCmdData(object);
    const fx32 *heights = gJumpHeightTables[0];
    VecFx32 offset = { 0, 0, 0 };

    offset.y = heights[*index];
    MapObject_SetFacingVector(object, &offset);
    *index += 2;
    if ((u32)*index < 16) {
        return FALSE;
    }
    offset.y = 0;
    MapObject_SetFacingVector(object, &offset);
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_UNK17 | MAPOBJECTFLAG_END_MOVEMENT | MAPOBJECTFLAG_UNK5));
    HiddenObjectMovement_SetRevealed(object);
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd102_Step0(LocalMapObject *object) {
    MapObject_InitMovementCmdData(object, sizeof(u32));
    MapObject_SetAnimation(object, MAP_OBJECT_ANIM_STAND);
    MapObject_IncrementMovementStep(object);
    return FALSE;
}

BOOL MapObjectMovementCmd104_Step0(LocalMapObject *object) {
    MapObject_InitMovementCmdData(object, sizeof(u32));
    MapObject_SetAnimation(object, MAP_OBJECT_ANIM_WALK_SLOWER);
    MapObject_IncrementMovementStep(object);
    return FALSE;
}

BOOL MapObjectMovementCmd102_Step1(LocalMapObject *object) {
    u32 *timer = MapObject_GetMovementCmdData(object);
    (*timer)++;
    if (*timer < 21) {
        return FALSE;
    }
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

static void MapObject_StartJumpByOffsetMovement(LocalMapObject *object, int dx, int dy, s16 dz, s8 direction, s16 duration, u16 animation) {
    fx32 time;
    JumpByOffsetWork *work;

    work = MapObject_InitMovementCmdData(object, sizeof(JumpByOffsetWork));
    work->data = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(JumpOffsetData));
    MI_CpuFill8(work->data, 0, sizeof(JumpOffsetData));
    work->direction = direction;
    work->timer = duration;
    work->animation = animation;
    time = FX32_CONST(duration);
    work->data->dx = dx;
    work->data->dy = dy;
    work->data->dz = dz;
    work->data->stepX = FX_Div(FX32_CONST(dx * 16), time);
    work->data->stepY = FX_Div(FX32_CONST(dy * 16), time);
    work->data->stepZ = FX_Div(FX32_CONST(dz * 16), time);
    work->data->angleStep = 180 / duration;
    MapObject_CopyPositionVector(object, &work->data->origin);
    work->height = work->data->origin.y;
    MapObject_SetPreviousCoordsToCurrent(object);
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_UNK16 | MAPOBJECTFLAG_START_MOVEMENT));
    MapObject_SetOrQueueFacing(object, direction);
    MapObject_SetAnimation(object, animation);
    MapObject_IncrementMovementStep(object);
    if (!MapObject_CheckInvisible(object)) {
        PlaySE(SEQ_SE_DP_DANSA);
    }
}

BOOL MapObjectMovementCmd108_Step1(LocalMapObject *object) {
    VecFx32 position;
    JumpByOffsetWork *work = MapObject_GetMovementCmdData(object);
    s64 progress;
    fx32 sine;
    fx32 targetY;
    float rounded;

    if (work->step != 0) {
        rounded = (float)(work->step << 12) + 0.5f;
    } else {
        rounded = (float)(work->step << 12) - 0.5f;
    }
    progress = (int)rounded;
    position.x = work->data->origin.x + FX_MUL(work->data->stepX, progress);
    position.y = 0;
    position.z = work->data->origin.z + FX_MUL(work->data->stepZ, progress);
    if (FieldSystem_SnapToTerrainHeightEx(MapObject_GetFieldSystem(object), &position, MapObject_CheckFlag29(object))) {
        work->height = position.y;
    } else {
        position.y = work->height;
    }
    MapObject_SetPositionVector(object, &position);
    sine = GF_SinDegNoWrap(work->data->angleStep * work->step);
    targetY = work->data->origin.y + FX_MUL(work->data->stepY, progress);
    targetY += FX_MUL(sine, FX32_CONST(16));
    position.y = targetY - position.y;
    position.x = 0;
    position.z = 0;
    MapObject_SetDrawOffset(object, &position);
    work->timer--;
    work->step++;
    if (work->timer > 0) {
        return FALSE;
    }
    position.x = position.y = position.z = 0;
    MapObject_SetFacingVector(object, &position);
    MapObject_SetDrawOffset(object, &position);
    MapObject_AddCurrentX(object, work->data->dx);
    MapObject_AddCurrentY(object, work->data->dy);
    MapObject_AddCurrentZ(object, work->data->dz);
    if (work->data->dx << 4 > 0) {
        rounded = (float)(work->data->dx << 16) + 0.5f;
    } else {
        rounded = (float)(work->data->dx << 16) - 0.5f;
    }
    position.x = work->data->origin.x + (int)rounded;
    if (work->data->dy << 4 > 0) {
        rounded = (float)(work->data->dy << 16) + 0.5f;
    } else {
        rounded = (float)(work->data->dy << 16) - 0.5f;
    }
    position.y = work->data->origin.y + (int)rounded;
    if (work->data->dz << 4 > 0) {
        rounded = (float)(work->data->dz << 16) + 0.5f;
    } else {
        rounded = (float)(work->data->dz << 16) - 0.5f;
    }
    position.z = work->data->origin.z + (int)rounded;
    MapObject_SetPositionVector(object, &position);
    MapObject_UpdateHeight(object);
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_UNK17 | MAPOBJECTFLAG_END_MOVEMENT));
    MapObject_SetPreviousCoordsToCurrent(object);
    MapObject_CallDrawUpdate(object);
    MapObject_SetAnimation(object, MAP_OBJECT_ANIM_STAND);
    MapObject_IncrementMovementStep(object);
    if (!MapObject_CheckInvisible(object)) {
        PlaySE(SEQ_SE_DP_SUTYA2);
    }
    Heap_Free(work->data);
    return FALSE;
}

BOOL MapObjectMovementCmd105_Step0(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 0, 1, 5, DIR_SOUTH, 15, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd105_Step2(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 4, 0, 0, DIR_EAST, 12, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd105_Step4(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 0, 0, -5, DIR_NORTH, 15, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd105_Step6(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, -2, 0, -3, DIR_NORTH, 9, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd105_Step8(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, -4, 1, -4, DIR_WEST, 12, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd106_Step0(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 2, 1, 0, DIR_EAST, 6, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd106_Step2(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, -1, 0, 5, DIR_SOUTH, 12, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd106_Step4(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, -3, 0, 0, DIR_WEST, 6, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd106_Step6(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, -3, 0, 0, DIR_WEST, 9, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd107_Step0(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 3, 1, -1, DIR_EAST, 6, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd107_Step2(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 0, 0, 4, DIR_SOUTH, 9, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd107_Step4(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, -4, 0, 0, DIR_WEST, 12, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd107_Step6(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 0, -1, -4, DIR_NORTH, 6, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd107_Step8(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 1, 1, -3, DIR_NORTH, 9, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd107_Step10(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 3, 0, 0, DIR_EAST, 9, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd107_Step12(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 0, 0, 4, DIR_SOUTH, 12, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd109_Step12(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 0, 0, 5, DIR_SOUTH, 12, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd108_Step0(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 2, 1, 5, DIR_SOUTH, 9, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd110_Step0(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 2, 1, 4, DIR_SOUTH, 9, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd108_Step2(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 1, 0, 5, DIR_SOUTH, 12, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd111_Step0(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 0, 0, 2, DIR_SOUTH, 6, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd111_Step2(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 2, 0, 0, DIR_EAST, 6, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd111_Step4(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 3, 0, 0, DIR_EAST, 9, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd111_Step6(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 0, 0, 2, DIR_SOUTH, 6, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd111_Step10(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, -3, 0, 0, DIR_WEST, 9, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd111_Step14(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 0, 0, -2, DIR_NORTH, 6, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd111_Step16(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 0, 0, -3, DIR_NORTH, 9, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd111_Step18(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 3, 0, 1, DIR_SOUTH, 9, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}

BOOL MapObjectMovementCmd112_Step0(LocalMapObject *object) {
    MapObject_StartJumpByOffsetMovement(object, 4, 0, 0, DIR_EAST, 9, MAP_OBJECT_ANIM_WALK_NORMAL);
    return TRUE;
}
