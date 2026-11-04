#include "global.h"

#include "constants/global_fieldmap.h"
#include "constants/pokemon.h"
#include "constants/sndseq.h"

#include "field/field_3d_object_task.h"
#include "field/field_camera_zoom.h"
#include "field/field_follow_mon.h"
#include "field/field_move_cut_in.h"

#include "field_system.h"
#include "field_warp_tasks.h"
#include "follow_mon.h"
#include "heap.h"
#include "map_object.h"
#include "map_object_movement_commands.h"
#include "overlay_02.h"
#include "player_avatar.h"
#include "pokemon.h"
#include "save_local_field_data.h"
#include "screen_fade.h"
#include "sound_chatot.h"
#include "sound_playback.h"
#include "spawn_warp.h"
#include "task.h"

// Escape Rope, Dig and Teleport: the player (and the following Pokemon) spin away while the screen fades out, then
// warp. Dig and Teleport are performed by the following Pokemon when it knows the move, else after the cut-in.

// Return values of the state functions.
enum FieldMoveStepResult {
    FIELD_MOVE_STEP_WAIT, // run the same state again next frame
    FIELD_MOVE_STEP_NEXT, // run the next state now
    FIELD_MOVE_STEP_DONE, // the task is over (warp started): free the environment
};

// What JumpTask_FieldMoveWarp is told about the warp, and which animation the arrival task plays.
enum FieldMoveWarpKind {
    FIELD_MOVE_WARP_ESCAPE_ROPE,
    FIELD_MOVE_WARP_DIG,
    FIELD_MOVE_WARP_TELEPORT,
};

enum FieldMoveWarpTaskState {
    WARP_TASK_STATE_WAIT_FOLLOW_MON,
    WARP_TASK_STATE_FOLLOW_MON_JUMP,
    WARP_TASK_STATE_PLAY_CRY,
    WARP_TASK_STATE_RUN_STEPS,
};

struct FieldMoveTaskEnvironment {
    int state;
    int spinCount;
    BOOL withFollowMon; // Escape Rope: the following Pokemon spins along; Dig/Teleport: it performs the move
    int kind;           // enum FieldMoveWarpKind
    EventObjectMovementMan *playerMovement;
    EventObjectMovementMan *followMonMovement;
    SysTask *cutIn; // FieldMoveCutIn_Start
    SysTask *cameraZoom;
    LocalMapObject *playerObject;
    FieldSystem *fieldSystem;
    Pokemon *mon;
    Field3dObjectTask *digEffect;
};

typedef enum FieldMoveStepResult (*FieldMoveStepFunc)(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);

// Step tables and movement scripts
extern const FieldMoveStepFunc gFieldMoveArrivalSteps[];
extern const FieldMoveStepFunc gEscapeRopeSteps[];
extern const FieldMoveStepFunc gDigWithFollowMonSteps[];
extern const FieldMoveStepFunc gTeleportSteps[]; // Teleport after the cut-in
extern const FieldMoveStepFunc gTeleportWithFollowMonSteps[];
extern const FieldMoveStepFunc gDigSteps[]; // Dig after the cut-in
extern const MovementScriptCommand gTeleportFollowMonSpinMovement[];
extern const MovementScriptCommand gEscapeRopeSpinMovement[];
extern const MovementScriptCommand gDigHoleMovement[];
extern const MovementScriptCommand gDigSinkMovement[];
extern const MovementScriptCommand gEscapeRopeSpinStartMovement[];
extern const MovementScriptCommand gArrivalSpinMovement[];

static FieldMoveTaskEnvironment *FieldMoveTaskEnvironment_New(enum HeapID heapID, u32 size);

// state functions (referenced by the state tables)
enum FieldMoveStepResult FieldEscapeRope_SpinStart(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldEscapeRope_SpinAndFadeOut(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldEscapeRope_WaitFadeOut(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldEscapeRope_Warp(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldMoveArrival_FadeIn(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldMoveArrival_WaitFadeIn(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldMoveArrival_Spin(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldMoveArrival_Finish(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldMove_ShowCutIn(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldMove_WaitCutIn(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldTeleport_FollowMonFlash(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldTeleport_FollowMonSpinStart(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldTeleport_FollowMonWaitSpin(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldTeleport_SpinStart(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldTeleport_SpinAndFadeOut(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldTeleport_WaitFadeOut(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldTeleport_Warp(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldDig_SinkStart(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldDig_DigHole(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldDig_SpinAndFadeOut(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldDig_WaitFadeOut(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);
enum FieldMoveStepResult FieldDig_Warp(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env);

FieldMoveTaskEnvironment *CreateFieldEscapeRopeTaskEnv(FieldSystem *fieldSystem, enum HeapID heapID) {
    FieldMoveTaskEnvironment *env = FieldMoveTaskEnvironment_New(heapID, sizeof(FieldMoveTaskEnvironment));
    int state;

    env->kind = FIELD_MOVE_WARP_ESCAPE_ROPE;
    env->fieldSystem = fieldSystem;
    env->playerObject = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    state = PlayerAvatar_GetState(fieldSystem->playerAvatar);
    if (state == PLAYER_STATE_CYCLING || state == PLAYER_STATE_SURFING) {
        env->withFollowMon = FALSE;
    } else if (FollowMon_IsActive(fieldSystem)) {
        env->withFollowMon = TRUE;
    } else {
        env->withFollowMon = FALSE;
    }
    return env;
}

BOOL Task_FieldEscapeRope(TaskManager *taskManager) {
    enum FieldMoveStepResult result;
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FieldMoveTaskEnvironment *env = TaskManager_GetEnvironment(taskManager);

    do {
        result = gEscapeRopeSteps[env->state](taskManager, fieldSystem, env);
        if (result == FIELD_MOVE_STEP_DONE) {
            Heap_Free(env);
        }
    } while (result == FIELD_MOVE_STEP_NEXT);
    return FALSE;
}

enum FieldMoveStepResult FieldEscapeRope_SpinStart(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    SysTask *cameraZoom = FieldCameraZoom_Start(fieldSystem, HEAP_ID_FIELD1);

    env->cameraZoom = cameraZoom;
    FieldCameraZoom_Set(cameraZoom, FIELD_CAMERA_ZOOM_BY, FX32_CONST(-150), 15);
    env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gEscapeRopeSpinStartMovement);
    if (env->withFollowMon) {
        env->followMonMovement = EventObjectMovementMan_Create(fieldSystem->followMon.mapObject, gEscapeRopeSpinStartMovement);
    }
    env->state++;
    PlaySE(SEQ_SE_DP_KAIDAN2);
    return FIELD_MOVE_STEP_WAIT;
}

enum FieldMoveStepResult FieldEscapeRope_SpinAndFadeOut(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (!EventObjectMovementMan_IsFinish(env->playerMovement)) {
        return FIELD_MOVE_STEP_WAIT;
    }
    EventObjectMovementMan_Delete(env->playerMovement);
    env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gEscapeRopeSpinMovement);
    if (env->withFollowMon) {
        EventObjectMovementMan_Delete(env->followMonMovement);
        env->followMonMovement = EventObjectMovementMan_Create(fieldSystem->followMon.mapObject, gEscapeRopeSpinMovement);
    }
    env->spinCount++;
    if (env->spinCount < 8) {
        return FIELD_MOVE_STEP_WAIT;
    }
    if (env->kind == FIELD_MOVE_WARP_TELEPORT) {
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_FIELD1);
    } else {
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_WHITE, 6, 1, HEAP_ID_FIELD1);
    }
    env->state++;
    return FIELD_MOVE_STEP_WAIT;
}

enum FieldMoveStepResult FieldEscapeRope_WaitFadeOut(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (EventObjectMovementMan_IsFinish(env->playerMovement) == TRUE) {
        EventObjectMovementMan_Delete(env->playerMovement);
        env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gEscapeRopeSpinMovement);
        if (env->withFollowMon) {
            EventObjectMovementMan_Delete(env->followMonMovement);
            env->followMonMovement = EventObjectMovementMan_Create(fieldSystem->followMon.mapObject, gEscapeRopeSpinMovement);
        }
    }
    if (!IsPaletteFadeFinished()) {
        return FIELD_MOVE_STEP_WAIT;
    }
    EventObjectMovementMan_Delete(env->playerMovement);
    if (env->withFollowMon) {
        EventObjectMovementMan_Delete(env->followMonMovement);
    }
    FieldCameraZoom_End(env->cameraZoom);
    env->state++;
    return FIELD_MOVE_STEP_NEXT;
}

// Escape Rope warps to the special spawn point of the last cave entrance.
enum FieldMoveStepResult FieldEscapeRope_Warp(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    JumpTask_FieldMoveWarp(taskManager, LocalFieldData_GetSpecialSpawnWarpPtr(Save_LocalFieldData_Get(fieldSystem->saveData)), env->kind);
    return FIELD_MOVE_STEP_DONE;
}

// Arrival after the warp; kind is the warp's FieldMoveWarpKind.
FieldMoveTaskEnvironment *FieldMoveTask_CreateArrivalEnvironment(FieldSystem *fieldSystem, enum HeapID heapID, int kind) {
    FieldMoveTaskEnvironment *env = FieldMoveTaskEnvironment_New(heapID, sizeof(FieldMoveTaskEnvironment));
    env->kind = kind;
    env->fieldSystem = fieldSystem;
    env->playerObject = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    return env;
}

BOOL Task_FieldMoveArrival(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FieldMoveTaskEnvironment *env = TaskManager_GetEnvironment(taskManager);
    enum FieldMoveStepResult result;

    do {
        result = gFieldMoveArrivalSteps[env->state](taskManager, fieldSystem, env);
        if (result == FIELD_MOVE_STEP_DONE) {
            Heap_Free(env);
            return TRUE;
        }
    } while (result == FIELD_MOVE_STEP_NEXT);
    return FALSE;
}

enum FieldMoveStepResult FieldMoveArrival_FadeIn(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    SysTask *cameraZoom;

    if (env->kind == FIELD_MOVE_WARP_TELEPORT) {
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_FIELD1);
    } else {
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_WHITE, 6, 1, HEAP_ID_FIELD1);
    }
    cameraZoom = FieldCameraZoom_Start(fieldSystem, HEAP_ID_FIELD1);
    env->cameraZoom = cameraZoom;
    FieldCameraZoom_Set(cameraZoom, FIELD_CAMERA_ZOOM_BY, FX32_CONST(-150), 1);
    env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gEscapeRopeSpinMovement);
    env->state++;
    return FIELD_MOVE_STEP_WAIT;
}

enum FieldMoveStepResult FieldMoveArrival_WaitFadeIn(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (EventObjectMovementMan_IsFinish(env->playerMovement) == TRUE) {
        EventObjectMovementMan_Delete(env->playerMovement);
        env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gEscapeRopeSpinMovement);
    }
    if (!IsPaletteFadeFinished()) {
        return FIELD_MOVE_STEP_WAIT;
    }
    FieldCameraZoom_Set(env->cameraZoom, FIELD_CAMERA_ZOOM_BACK, 0, 60);
    env->state++;
    return FIELD_MOVE_STEP_NEXT;
}

enum FieldMoveStepResult FieldMoveArrival_Spin(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (!EventObjectMovementMan_IsFinish(env->playerMovement)) {
        return FIELD_MOVE_STEP_WAIT;
    }
    EventObjectMovementMan_Delete(env->playerMovement);
    if (++env->spinCount < 4) {
        env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gEscapeRopeSpinMovement);
        return FIELD_MOVE_STEP_WAIT;
    }
    env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gArrivalSpinMovement);
    env->state++;
    return FIELD_MOVE_STEP_WAIT;
}

enum FieldMoveStepResult FieldMoveArrival_Finish(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (!EventObjectMovementMan_IsFinish(env->playerMovement)) {
        return FIELD_MOVE_STEP_WAIT;
    }
    if (!FieldCameraZoom_IsDone(env->cameraZoom)) {
        return FIELD_MOVE_STEP_WAIT;
    }
    FieldCameraZoom_End(env->cameraZoom);
    EventObjectMovementMan_Delete(env->playerMovement);
    return FIELD_MOVE_STEP_DONE;
}

FieldMoveTaskEnvironment *FieldMoveTask_CreateDigEnvironment(FieldSystem *fieldSystem, Pokemon *mon, u8 slotno, enum HeapID heapID) {
    FieldMoveTaskEnvironment *env = FieldMoveTaskEnvironment_New(heapID, sizeof(FieldMoveTaskEnvironment));
    env->kind = FIELD_MOVE_WARP_DIG;
    env->fieldSystem = fieldSystem;
    env->playerObject = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    env->mon = mon;
    if (FollowMon_IsNextToPlayer(fieldSystem) && slotno == FieldSystem_GetLeadMonIndex(fieldSystem)) {
        env->withFollowMon = TRUE;
    } else {
        env->withFollowMon = FALSE;
    }
    return env;
}

BOOL Task_FieldDig(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FieldMoveTaskEnvironment *env = TaskManager_GetEnvironment(taskManager);
    u32 *state = TaskManager_GetStatePtr(taskManager);
    enum FieldMoveStepResult result;

    switch (*state) {
    case WARP_TASK_STATE_WAIT_FOLLOW_MON:
        if (env->withFollowMon) {
            TaskManager_Call(taskManager, Task_WaitFollowMonMovement, NULL);
        }
        (*state)++;
        break;
    case WARP_TASK_STATE_FOLLOW_MON_JUMP:
        (*state)++;
        if (env->withFollowMon) {
            u8 count;
            if (FieldSystem_FirstAliveMonHasType(fieldSystem, TYPE_GROUND)) {
                count = 2;
                FollowMonMood_Add(fieldSystem->followMonMood, 1);
            } else {
                count = 1;
            }
            FollowMon_JumpOnSpot(fieldSystem, count);
            break;
        }
        // fallthrough
    case WARP_TASK_STATE_PLAY_CRY:
        if (env->withFollowMon) {
            u32 species = GetMonData(env->mon, MON_DATA_SPECIES, NULL);
            u32 form = GetMonData(env->mon, MON_DATA_FORM, NULL);
            PlayCry(species, form);
        }
        (*state)++;
        // fallthrough
    case WARP_TASK_STATE_RUN_STEPS:
        do {
            if (env->withFollowMon) {
                if (IsCryPlaying()) {
                    result = FIELD_MOVE_STEP_WAIT;
                } else {
                    result = gDigWithFollowMonSteps[env->state](taskManager, fieldSystem, env);
                }
            } else {
                result = gDigSteps[env->state](taskManager, fieldSystem, env);
            }
            if (result == FIELD_MOVE_STEP_DONE) {
                Heap_Free(env);
            }
        } while (result == FIELD_MOVE_STEP_NEXT);
        break;
    }
    return FALSE;
}

// Dig / Teleport without the following Pokemon: the cut-in of the Pokemon using the move first.
enum FieldMoveStepResult FieldMove_ShowCutIn(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    u32 gender = PlayerAvatar_GetGender(fieldSystem->playerAvatar);
    env->cutIn = FieldMoveCutIn_Start(fieldSystem, FIELD_MOVE_CUT_IN_BANNER, env->mon, gender);
    env->state++;
    return FIELD_MOVE_STEP_WAIT;
}

enum FieldMoveStepResult FieldMove_WaitCutIn(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (!FieldMoveCutIn_IsFinished(env->cutIn)) {
        return FIELD_MOVE_STEP_WAIT;
    }
    FieldMoveCutIn_Delete(env->cutIn);
    FollowMon_StartRecall(env->fieldSystem);
    env->state++;
    return FIELD_MOVE_STEP_WAIT;
}

FieldMoveTaskEnvironment *FieldMoveTask_CreateTeleportEnvironment(FieldSystem *fieldSystem, Pokemon *mon, u8 slotno, enum HeapID heapID) {
    FieldMoveTaskEnvironment *env = FieldMoveTaskEnvironment_New(heapID, sizeof(FieldMoveTaskEnvironment));
    env->kind = FIELD_MOVE_WARP_TELEPORT;
    env->fieldSystem = fieldSystem;
    env->playerObject = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    env->mon = mon;
    if ((u32)(PlayerAvatar_GetState(fieldSystem->playerAvatar) - PLAYER_STATE_CYCLING) <= PLAYER_STATE_SURFING - PLAYER_STATE_CYCLING) {
        env->withFollowMon = FALSE;
    } else if (FollowMon_IsNextToPlayer(fieldSystem) && slotno == FieldSystem_GetLeadMonIndex(fieldSystem)) {
        env->withFollowMon = TRUE;
    } else {
        env->withFollowMon = FALSE;
    }
    return env;
}

BOOL Task_FieldTeleport(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FieldMoveTaskEnvironment *env = TaskManager_GetEnvironment(taskManager);
    u32 *state = TaskManager_GetStatePtr(taskManager);

    switch (*state) {
    case WARP_TASK_STATE_WAIT_FOLLOW_MON:
        if (env->withFollowMon) {
            TaskManager_Call(taskManager, Task_WaitFollowMonMovement, NULL);
        }
        ++*state;
        break;
    case WARP_TASK_STATE_FOLLOW_MON_JUMP:
        ++*state;
        if (env->withFollowMon) {
            u8 count;
            if (FieldSystem_FirstAliveMonHasType(fieldSystem, TYPE_PSYCHIC)) {
                count = 2;
                FollowMonMood_Add(fieldSystem->followMonMood, 1);
            } else {
                count = 1;
            }
            FollowMon_JumpOnSpot(fieldSystem, count);
            break;
        }
        // fallthrough
    case WARP_TASK_STATE_PLAY_CRY:
        if (env->withFollowMon) {
            u32 species = GetMonData(env->mon, MON_DATA_SPECIES, NULL);
            u32 form = GetMonData(env->mon, MON_DATA_FORM, NULL);
            PlayCry(species, form);
        }
        ++*state;
        // fallthrough
    case WARP_TASK_STATE_RUN_STEPS: {
        enum FieldMoveStepResult result;
        do {
            if (env->withFollowMon) {
                if (IsCryPlaying()) {
                    result = FIELD_MOVE_STEP_WAIT;
                } else {
                    result = gTeleportWithFollowMonSteps[env->state](taskManager, fieldSystem, env);
                }
            } else {
                result = gTeleportSteps[env->state](taskManager, fieldSystem, env);
            }
            if (result == FIELD_MOVE_STEP_DONE) {
                Heap_Free(env);
            }
        } while (result == FIELD_MOVE_STEP_NEXT);
    } break;
    }
    return FALSE;
}

static FieldMoveTaskEnvironment *FieldMoveTaskEnvironment_New(enum HeapID heapID, u32 size) {
    FieldMoveTaskEnvironment *env = Heap_AllocAtEnd(heapID, size);
    GF_ASSERT(env != NULL);
    memset(env, 0, size);
    return env;
}

// Teleport by the following Pokemon: it flashes, spins and vanishes, then the player spins away.
enum FieldMoveStepResult FieldTeleport_FollowMonFlash(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    FollowMon_StartFlash(fieldSystem, 2, 1);
    env->state++;
    return FIELD_MOVE_STEP_WAIT;
}

enum FieldMoveStepResult FieldTeleport_FollowMonSpinStart(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    SysTask *cameraZoom = FieldCameraZoom_Start(fieldSystem, HEAP_ID_FIELD1);
    env->cameraZoom = cameraZoom;
    FieldCameraZoom_Set(cameraZoom, FIELD_CAMERA_ZOOM_BY, FX32_CONST(-150), 15);
    env->followMonMovement = EventObjectMovementMan_Create(fieldSystem->followMon.mapObject, gTeleportFollowMonSpinMovement);
    env->state++;
    PlaySE(SEQ_SE_DP_TELE);
    return FIELD_MOVE_STEP_WAIT;
}

enum FieldMoveStepResult FieldTeleport_FollowMonWaitSpin(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (!EventObjectMovementMan_IsFinish(env->followMonMovement)) {
        return FIELD_MOVE_STEP_WAIT;
    }
    EventObjectMovementMan_Delete(env->followMonMovement);
    env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gEscapeRopeSpinStartMovement);
    env->followMonMovement = EventObjectMovementMan_Create(fieldSystem->followMon.mapObject, gEscapeRopeSpinStartMovement);
    env->state++;
    return FIELD_MOVE_STEP_WAIT;
}

// Teleport after the cut-in.
enum FieldMoveStepResult FieldTeleport_SpinStart(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    SysTask *cameraZoom = FieldCameraZoom_Start(fieldSystem, HEAP_ID_FIELD1);
    env->cameraZoom = cameraZoom;
    FieldCameraZoom_Set(cameraZoom, FIELD_CAMERA_ZOOM_BY, FX32_CONST(-150), 15);
    env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gEscapeRopeSpinStartMovement);
    env->state++;
    PlaySE(SEQ_SE_DP_TELE);
    return FIELD_MOVE_STEP_WAIT;
}

enum FieldMoveStepResult FieldTeleport_SpinAndFadeOut(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (!EventObjectMovementMan_IsFinish(env->playerMovement)) {
        return FIELD_MOVE_STEP_WAIT;
    }
    EventObjectMovementMan_Delete(env->playerMovement);
    env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gEscapeRopeSpinMovement);
    if (env->withFollowMon) {
        EventObjectMovementMan_Delete(env->followMonMovement);
        env->followMonMovement = EventObjectMovementMan_Create(fieldSystem->followMon.mapObject, gEscapeRopeSpinMovement);
    }
    env->spinCount++;
    if (env->spinCount < 8) {
        return FIELD_MOVE_STEP_WAIT;
    }
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_FIELD1);
    env->state++;
    return FIELD_MOVE_STEP_WAIT;
}

enum FieldMoveStepResult FieldTeleport_WaitFadeOut(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (EventObjectMovementMan_IsFinish(env->playerMovement) == TRUE) {
        EventObjectMovementMan_Delete(env->playerMovement);
        env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gEscapeRopeSpinMovement);
        if (env->withFollowMon) {
            EventObjectMovementMan_Delete(env->followMonMovement);
            env->followMonMovement = EventObjectMovementMan_Create(fieldSystem->followMon.mapObject, gEscapeRopeSpinMovement);
        }
    }
    if (!IsPaletteFadeFinished()) {
        return FIELD_MOVE_STEP_WAIT;
    }
    EventObjectMovementMan_Delete(env->playerMovement);
    if (env->withFollowMon) {
        EventObjectMovementMan_Delete(env->followMonMovement);
    }
    FieldCameraZoom_End(env->cameraZoom);
    env->state++;
    return FIELD_MOVE_STEP_NEXT;
}

// Teleport warps to the last Pokemon Center (the blackout spawn point).
enum FieldMoveStepResult FieldTeleport_Warp(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    Location warp;
    LocalFieldData *localFieldData = Save_LocalFieldData_Get(fieldSystem->saveData);
    u16 spawnId = LocalFieldData_GetBlackoutSpawn(localFieldData);
    GetFlyWarpData(spawnId, &warp);
    GetSpecialSpawnWarpData(spawnId, LocalFieldData_GetSpecialSpawnWarpPtr(localFieldData));
    JumpTask_FieldMoveWarp(taskManager, &warp, env->kind);
    return FIELD_MOVE_STEP_DONE;
}

// Dig: the player (and the following Pokemon) spin down into the ground.
enum FieldMoveStepResult FieldDig_SinkStart(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    SysTask *cameraZoom = FieldCameraZoom_Start(fieldSystem, HEAP_ID_FIELD1);
    env->cameraZoom = cameraZoom;
    FieldCameraZoom_Set(cameraZoom, FIELD_CAMERA_ZOOM_BY, FX32_CONST(-150), 15);
    env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gDigSinkMovement);
    if (env->withFollowMon) {
        env->followMonMovement = EventObjectMovementMan_Create(fieldSystem->followMon.mapObject, gDigSinkMovement);
    }
    env->state++;
    PlaySE(SEQ_SE_DP_KAIDAN2);
    return FIELD_MOVE_STEP_WAIT;
}

enum FieldMoveStepResult FieldDig_DigHole(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (!EventObjectMovementMan_IsFinish(env->playerMovement)) {
        return FIELD_MOVE_STEP_WAIT;
    }
    EventObjectMovementMan_Delete(env->playerMovement);
    env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gDigHoleMovement);
    if (env->withFollowMon) {
        EventObjectMovementMan_Delete(env->followMonMovement);
        env->followMonMovement = EventObjectMovementMan_Create(fieldSystem->followMon.mapObject, gDigHoleMovement);
    }
    if (PlayerAvatar_GetState(fieldSystem->playerAvatar) != PLAYER_STATE_SURFING) {
        if (env->withFollowMon) {
            env->digEffect = RockDebris_CreateWithFollower(env->fieldSystem);
        } else {
            env->digEffect = RockDebris_Create(env->fieldSystem);
        }
    }
    env->state++;
    return FIELD_MOVE_STEP_WAIT;
}

enum FieldMoveStepResult FieldDig_SpinAndFadeOut(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (!EventObjectMovementMan_IsFinish(env->playerMovement)) {
        return FIELD_MOVE_STEP_WAIT;
    }
    EventObjectMovementMan_Delete(env->playerMovement);
    env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gEscapeRopeSpinMovement);
    if (env->withFollowMon) {
        EventObjectMovementMan_Delete(env->followMonMovement);
        env->followMonMovement = EventObjectMovementMan_Create(fieldSystem->followMon.mapObject, gEscapeRopeSpinMovement);
    }
    env->spinCount++;
    if (env->spinCount < 8) {
        return FIELD_MOVE_STEP_WAIT;
    }
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_WHITE, 6, 1, HEAP_ID_FIELD1);
    env->state++;
    return FIELD_MOVE_STEP_WAIT;
}

enum FieldMoveStepResult FieldDig_WaitFadeOut(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (EventObjectMovementMan_IsFinish(env->playerMovement) == TRUE) {
        EventObjectMovementMan_Delete(env->playerMovement);
        env->playerMovement = EventObjectMovementMan_Create(env->playerObject, gEscapeRopeSpinMovement);
        if (env->withFollowMon) {
            EventObjectMovementMan_Delete(env->followMonMovement);
            env->followMonMovement = EventObjectMovementMan_Create(fieldSystem->followMon.mapObject, gEscapeRopeSpinMovement);
        }
    }
    if (!IsPaletteFadeFinished()) {
        return FIELD_MOVE_STEP_WAIT;
    }
    EventObjectMovementMan_Delete(env->playerMovement);
    if (PlayerAvatar_GetState(fieldSystem->playerAvatar) != PLAYER_STATE_SURFING) {
        RockDebris_Delete(env->digEffect);
        env->digEffect = NULL;
    }
    if (env->withFollowMon) {
        EventObjectMovementMan_Delete(env->followMonMovement);
    }
    FieldCameraZoom_End(env->cameraZoom);
    env->state++;
    return FIELD_MOVE_STEP_NEXT;
}

// Dig warps to the special spawn point of the last cave entrance, like Escape Rope.
enum FieldMoveStepResult FieldDig_Warp(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    JumpTask_FieldMoveWarp(taskManager, LocalFieldData_GetSpecialSpawnWarpPtr(Save_LocalFieldData_Get(fieldSystem->saveData)), env->kind);
    return FIELD_MOVE_STEP_DONE;
}
