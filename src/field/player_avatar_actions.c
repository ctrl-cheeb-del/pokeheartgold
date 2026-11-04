#include "player_avatar_actions.h"

#include "global.h"

#include "constants/flags.h"
#include "constants/global_fieldmap.h"
#include "constants/maps.h"
#include "constants/player_avatar.h"
#include "constants/pokemon.h"
#include "constants/sndseq.h"
#include "constants/sprites.h"
#include "constants/std_script.h"

#include "field/field_3d_object_task.h"
#include "field/field_control.h"
#include "field/field_effect_manager.h"
#include "field/field_follow_mon.h"
#include "field/field_move_cut_in.h"
#include "field/field_move_effects.h"
#include "field/map_object_render.h"

#include "field_bgm.h"
#include "field_metatile_query_internal.h"
#include "field_rock_climb_effect.h"
#include "field_surf_mount.h"
#include "field_system.h"
#include "field_terrain.h"
#include "follow_mon.h"
#include "heap.h"
#include "map_object.h"
#include "map_object_movement_commands.h"
#include "map_object_movement_commands_internal.h"
#include "map_object_movement_utilities.h"
#include "map_object_movement_utilities_internal.h"
#include "metatile_behavior.h"
#include "overlay_01.h"
#include "overlay_02.h"
#include "party.h"
#include "player_avatar.h"
#include "player_avatar_movement.h"
#include "pokemon.h"
#include "save_vars_flags.h"
#include "script_manager.h"
#include "sound_playback.h"
#include "sound_radio.h"
#include "sys_flags.h"
#include "sys_task.h"
#include "sys_task_api.h"
#include "task.h"

// The Pokemon shown using a field move: either the cut-in animation of the party Pokemon (FieldMoveCutIn_Start), or the
// following Pokemon, which is recalled first.
typedef struct FieldMoveAnim {
    BOOL useCutIn;
    u32 gender;
    Pokemon *mon;
    SysTask *cutIn;
} FieldMoveAnim;

enum PushBoulderState {
    PUSH_BOULDER_STATE_START,
    PUSH_BOULDER_STATE_WAIT,
    PUSH_BOULDER_STATE_END,
};

enum SurfState {
    SURF_STATE_START_BGM,
    SURF_STATE_WAIT,
    SURF_STATE_START_ANIM,
    SURF_STATE_PLAY_CRY,
    SURF_STATE_WAIT_CRY,
    SURF_STATE_WAIT_CUT_IN,
    SURF_STATE_CREATE_MOUNT,
    SURF_STATE_WAIT_MOUNT,
    SURF_STATE_JUMP_ON,
    SURF_STATE_WAIT_JUMP,
};

enum StopSurfingState {
    STOP_SURFING_STATE_JUMP_OFF,
    STOP_SURFING_STATE_WAIT_JUMP,
    STOP_SURFING_STATE_WAIT_RADIO,
};

typedef struct PushBoulderWork {
    u32 state;
    u32 direction;
    FieldSystem *fieldSystem;
    PlayerAvatar *playerAvatar;
    LocalMapObject *boulder;
} PushBoulderWork;

typedef struct SurfWork {
    int state;
    u32 direction;
    int timer;
    FieldMoveAnim anim;
    FieldSystem *fieldSystem;
    PlayerAvatar *playerAvatar;
    LocalMapObject *mapObject;
    FieldEffect *surfMount;
} SurfWork;

typedef struct StopSurfingWork {
    u16 state;
    u16 timer;
    u32 direction;
    FieldSystem *fieldSystem;
    PlayerAvatar *playerAvatar;
    LocalMapObject *mapObject;
    FieldEffect *surfMount;
} StopSurfingWork;

typedef struct RockClimbWork {
    u16 state;
    u16 climbState; // step to resume at while the next tile is rock climb too
    u32 direction;
    int timer;
    FieldSystem *fieldSystem;
    PlayerAvatar *playerAvatar;
    LocalMapObject *mapObject;
    FieldEffect *effect;
    FieldMoveAnim anim;
    Field3dObjectTask *debris;
} RockClimbWork;

// Waterfall (up and down) and Whirlpool.
typedef struct WaterfallWork {
    int state;
    u32 direction;
    int counter;
    int targetX;
    int targetY;
    int targetZ;
    int progress;
    VecFx32 step;
    VecFx32 targetPos;
    FieldSystem *fieldSystem;
    PlayerAvatar *playerAvatar;
    LocalMapObject *mapObject;
    FieldMoveAnim anim;
    Field3dObjectTask *effect;
} WaterfallWork;

typedef struct PlayerSavingPoseWork {
    int unk_00;
    int state;
    FieldSystem *fieldSystem;
    PlayerAvatar *playerAvatar;
} PlayerSavingPoseWork;

// Ice Path B1F boulders and the flag of the boulder that appears on the floor below once one is pushed into its hole.
typedef struct BoulderHole {
    u16 mapId;
    u16 x;
    u16 z;
    u16 objectId;
    u16 belowFlag;
} BoulderHole;

// Return values of the rock climb, waterfall and whirlpool step functions.
enum FieldMoveTaskStepResult {
    FIELD_MOVE_TASK_STEP_WAIT, // run the current step again next frame
    FIELD_MOVE_TASK_STEP_DONE, // the task is over
    FIELD_MOVE_TASK_STEP_NEXT, // run the (new) current step now
};

typedef enum FieldMoveTaskStepResult (*RockClimbStepFunc)(RockClimbWork *work, TaskManager *taskManager);
typedef enum FieldMoveTaskStepResult (*WaterfallStepFunc)(WaterfallWork *work);

void SurfMountEffect_SetBobbing(FieldEffect *effect, BOOL bobbing);

static void Field_PlayerAvatar_TransitionToWalking(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionToCycling(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionToSurfing(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionToRocket(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionX0008(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionToWatering(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionToFishing(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionToPoketch(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionToSaving(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionToHeal(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionToLadder(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionToRocketHeal(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionToPokeathlon(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionToApricornShake(PlayerAvatar *playerAvatar);
static void Field_PlayerAvatar_TransitionToRocketSaving(PlayerAvatar *playerAvatar);
static BOOL Field_PlayerAvatar_TryFieldMoveInDirection(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, u32 direction, int playerEvents);
static BOOL Field_PlayerAvatar_TryPushBoulder(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, u32 direction, int collision);
static void Field_StartPushBoulderTask(u32 direction, FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, LocalMapObject *boulder);
static BOOL Task_PushBoulder(TaskManager *taskManager);
static BOOL Field_TryDropBoulderIntoHole(FieldSystem *fieldSystem, LocalMapObject *boulder);
static BOOL PushBoulder_Finish(TaskManager *taskManager, FieldSystem *fieldSystem, LocalMapObject *boulder);
static void Field_StartSurfTask(FieldSystem *fieldSystem, u32 direction, FieldMoveAnim *anim);
static BOOL Task_Surf(TaskManager *taskManager);
static BOOL Field_PlayerAvatar_TryStopSurfing(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, u32 direction, int collision);
static void Field_StartStopSurfingTask(u32 direction, FieldSystem *fieldSystem, PlayerAvatar *playerAvatar);
static BOOL Task_StopSurfing(TaskManager *taskManager);
static BOOL Field_PlayerAvatar_TryWaterfallUp(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, u32 direction, int collision);
static BOOL Field_PlayerAvatar_HandleForcedMovement(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int playerEvents);
static void Field_StartRockClimbTask(FieldSystem *fieldSystem, u32 direction, FieldMoveAnim *anim);
static BOOL Task_RockClimb(TaskManager *taskManager);
static enum FieldMoveTaskStepResult RockClimb_StartCutIn(RockClimbWork *work, TaskManager *taskManager);
static enum FieldMoveTaskStepResult RockClimb_WaitCutIn(RockClimbWork *work, TaskManager *taskManager);
static enum FieldMoveTaskStepResult RockClimb_FollowMonReact(RockClimbWork *work, TaskManager *taskManager);
static enum FieldMoveTaskStepResult RockClimb_PlayFollowMonCry(RockClimbWork *work, TaskManager *taskManager);
static enum FieldMoveTaskStepResult RockClimb_WaitFollowMonCry(RockClimbWork *work, TaskManager *taskManager);
static enum FieldMoveTaskStepResult RockClimb_CreateEffect(RockClimbWork *work, TaskManager *taskManager);
static enum FieldMoveTaskStepResult RockClimb_StartJump(RockClimbWork *work, TaskManager *taskManager);
static enum FieldMoveTaskStepResult RockClimb_WaitJump(RockClimbWork *work, TaskManager *taskManager);
static enum FieldMoveTaskStepResult RockClimb_StartStep(RockClimbWork *work, TaskManager *taskManager);
static enum FieldMoveTaskStepResult RockClimb_CheckNextTile(RockClimbWork *work, TaskManager *taskManager);
static enum FieldMoveTaskStepResult RockClimb_Finish(RockClimbWork *work, TaskManager *taskManager);
static WaterfallWork *Waterfall_NewWork(FieldSystem *fieldSystem, int direction, FieldMoveAnim *anim);
static void Field_StartWaterfallTask(FieldSystem *fieldSystem, u32 direction);
static BOOL Task_Waterfall(TaskManager *taskManager);
static enum FieldMoveTaskStepResult WaterfallUp_StartCutIn(WaterfallWork *work);
static enum FieldMoveTaskStepResult WaterfallUp_WaitCutIn(WaterfallWork *work);
static enum FieldMoveTaskStepResult WaterfallUp_Init(WaterfallWork *work);
static enum FieldMoveTaskStepResult WaterfallUp_Rise(WaterfallWork *work);
static enum FieldMoveTaskStepResult WaterfallUp_Climb(WaterfallWork *work);
static enum FieldMoveTaskStepResult WaterfallDown_StartCutIn(WaterfallWork *work);
static enum FieldMoveTaskStepResult WaterfallDown_WaitCutIn(WaterfallWork *work);
static enum FieldMoveTaskStepResult WaterfallDown_Init(WaterfallWork *work);
static enum FieldMoveTaskStepResult WaterfallDown_Advance(WaterfallWork *work);
static enum FieldMoveTaskStepResult WaterfallDown_Descend(WaterfallWork *work);
static void Field_StartWhirlpoolTask(FieldSystem *fieldSystem, u32 direction, FieldMoveAnim *anim);
static BOOL Task_Whirlpool(TaskManager *taskManager);
static enum FieldMoveTaskStepResult Whirlpool_StartCutIn(WaterfallWork *work);
static enum FieldMoveTaskStepResult Whirlpool_WaitCutIn(WaterfallWork *work);
static enum FieldMoveTaskStepResult Whirlpool_CreateEffect(WaterfallWork *work);
static enum FieldMoveTaskStepResult Whirlpool_StartStep(WaterfallWork *work);
static enum FieldMoveTaskStepResult Whirlpool_CheckNextTile(WaterfallWork *work);
static void PlayerMovementSaving_Update(SysTask *task, void *data);
static void FieldMoveAnim_Init(FieldSystem *fieldSystem, Pokemon *mon, FieldMoveAnim *anim);
static void FieldMoveAnim_Start(FieldSystem *fieldSystem, FieldMoveAnim *anim);
static BOOL FieldMoveAnim_CheckFinished(FieldMoveAnim *anim);
static void Field_PlayerAvatar_SetSprite(PlayerAvatar *playerAvatar, u32 sprite);
static LocalMapObject *Field_PlayerAvatar_GetFacingMapObject(PlayerAvatar *playerAvatar, int direction);
static void *FieldMoveTask_AllocWork(u32 size);
static void FieldMoveTask_FreeWork(void *work);
static Pokemon *Field_GetPartyMon(FieldSystem *fieldSystem, int partySlot);

static const WaterfallStepFunc sWaterfallDownSteps[5] = {
    WaterfallDown_StartCutIn,
    WaterfallDown_WaitCutIn,
    WaterfallDown_Init,
    WaterfallDown_Advance,
    WaterfallDown_Descend,
};

static const WaterfallStepFunc sWaterfallUpSteps[5] = {
    WaterfallUp_StartCutIn,
    WaterfallUp_WaitCutIn,
    WaterfallUp_Init,
    WaterfallUp_Rise,
    WaterfallUp_Climb,
};

static const WaterfallStepFunc sWhirlpoolSteps[5] = {
    Whirlpool_StartCutIn,
    Whirlpool_WaitCutIn,
    Whirlpool_CreateEffect,
    Whirlpool_StartStep,
    Whirlpool_CheckNextTile,
};

static const RockClimbStepFunc sRockClimbCutInSteps[8] = {
    RockClimb_StartCutIn,
    RockClimb_WaitCutIn,
    RockClimb_CreateEffect,
    RockClimb_StartJump,
    RockClimb_WaitJump,
    RockClimb_StartStep,
    RockClimb_CheckNextTile,
    RockClimb_Finish,
};

static const RockClimbStepFunc sRockClimbFollowMonSteps[9] = {
    RockClimb_FollowMonReact,
    RockClimb_PlayFollowMonCry,
    RockClimb_WaitFollowMonCry,
    RockClimb_CreateEffect,
    RockClimb_StartJump,
    RockClimb_WaitJump,
    RockClimb_StartStep,
    RockClimb_CheckNextTile,
    RockClimb_Finish,
};

static const BoulderHole sIcePathBoulderHoles[4] = {
    { MAP_ICE_PATH_B1F, 11, 10, 0, FLAG_HIDE_ICE_PATH_BOULDER_1_FALLEN },
    { MAP_ICE_PATH_B1F, 10, 18, 1, FLAG_HIDE_ICE_PATH_BOULDER_2_FALLEN },
    { MAP_ICE_PATH_B1F, 18, 7,  2, FLAG_HIDE_ICE_PATH_BOULDER_3_FALLEN },
    { MAP_ICE_PATH_B1F, 19, 19, 3, FLAG_HIDE_ICE_PATH_BOULDER_4_FALLEN },
};

static void (*const sPlayerAvatarBitUpdateFuncs[15])(PlayerAvatar *) = {
    Field_PlayerAvatar_TransitionToWalking,
    Field_PlayerAvatar_TransitionToCycling,
    Field_PlayerAvatar_TransitionToSurfing,
    Field_PlayerAvatar_TransitionX0008,
    Field_PlayerAvatar_TransitionToWatering,
    Field_PlayerAvatar_TransitionToFishing,
    Field_PlayerAvatar_TransitionToPoketch,
    Field_PlayerAvatar_TransitionToSaving,
    Field_PlayerAvatar_TransitionToHeal,
    Field_PlayerAvatar_TransitionToLadder,
    Field_PlayerAvatar_TransitionToRocket,
    Field_PlayerAvatar_TransitionToRocketHeal,
    Field_PlayerAvatar_TransitionToPokeathlon,
    Field_PlayerAvatar_TransitionToApricornShake,
    Field_PlayerAvatar_TransitionToRocketSaving,
};

void Field_PlayerAvatar_OrrTransitionFlags(PlayerAvatar *playerAvatar, int flags) {
    PlayerAvatar_SetTransitionFlagsBits(playerAvatar, flags);
}

void Field_PlayerAvatar_ApplyTransitionFlags(PlayerAvatar *avatar) {
    u32 i = 0;
    u32 flags = PlayerAvatar_GetTransitionFlags(avatar);
    for (; i < 15; i++) {
        if (flags & 1) {
            sPlayerAvatarBitUpdateFuncs[i](avatar);
        }
        flags >>= 1;
    }
    PlayerAvatar_SetTransitionFlags(avatar, 0);
}

static void Field_PlayerAvatar_TransitionToWalking(PlayerAvatar *playerAvatar) {
    FieldEffect *surfMount;
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_WALKING, PlayerAvatar_GetGender(playerAvatar)));
    PlayerAvatar_SetState(playerAvatar, PLAYER_STATE_WALKING);
    PlayerAvatar_ClearSpeedAndFlag2(playerAvatar);
    surfMount = PlayerAvatar_GetSurfMountEffect(playerAvatar);
    if (surfMount != NULL) {
        FieldEffectManager_DestroyEffect(surfMount);
    }
    PlayerAvatar_SetSurfMountEffect(playerAvatar, NULL);
}

static void Field_PlayerAvatar_TransitionToCycling(PlayerAvatar *playerAvatar) {
    FieldEffect *surfMount;
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_CYCLING, PlayerAvatar_GetGender(playerAvatar)));
    PlayerAvatar_SetState(playerAvatar, PLAYER_STATE_CYCLING);
    PlayerAvatar_ClearSpeedAndFlag2(playerAvatar);
    surfMount = PlayerAvatar_GetSurfMountEffect(playerAvatar);
    if (surfMount != NULL) {
        FieldEffectManager_DestroyEffect(surfMount);
    }
    PlayerAvatar_SetSurfMountEffect(playerAvatar, NULL);
    PlaySE(SEQ_SE_DP_JITENSYA);
}

static void Field_PlayerAvatar_TransitionToSurfing(PlayerAvatar *playerAvatar) {
    FieldEffect *surfMount;
    u32 direction;
    LocalMapObject *mapObject;
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_SURFING, PlayerAvatar_GetGender(playerAvatar)));
    PlayerAvatar_SetState(playerAvatar, PLAYER_STATE_SURFING);
    PlayerAvatar_ClearSpeedAndFlag2(playerAvatar);
    surfMount = PlayerAvatar_GetSurfMountEffect(playerAvatar);
    if (surfMount != NULL) {
        FieldEffectManager_DestroyEffect(surfMount);
    }
    PlayerAvatar_SetSurfMountEffect(playerAvatar, NULL);
    direction = PlayerAvatar_GetFacingDirection(playerAvatar);
    mapObject = PlayerAvatar_GetMapObject(playerAvatar);
    MapObject_GetFieldSystem(mapObject);
    PlayerAvatar_SetSurfMountEffect(playerAvatar, SurfMountEffect_Create(mapObject, 0, 0, direction, TRUE));
}

static void Field_PlayerAvatar_TransitionToRocket(PlayerAvatar *playerAvatar) {
    FieldEffect *surfMount;
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_ROCKET, PlayerAvatar_GetGender(playerAvatar)));
    PlayerAvatar_SetState(playerAvatar, PLAYER_STATE_ROCKET);
    PlayerAvatar_ClearSpeedAndFlag2(playerAvatar);
    surfMount = PlayerAvatar_GetSurfMountEffect(playerAvatar);
    if (surfMount != NULL) {
        FieldEffectManager_DestroyEffect(surfMount);
    }
    PlayerAvatar_SetSurfMountEffect(playerAvatar, NULL);
}

static void Field_PlayerAvatar_TransitionX0008(PlayerAvatar *playerAvatar) {
    PlayerAvatar_SetFlag1(playerAvatar, TRUE);
}

static void Field_PlayerAvatar_TransitionToWatering(PlayerAvatar *playerAvatar) {
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_WATERING, PlayerAvatar_GetGender(playerAvatar)));
}

static void Field_PlayerAvatar_TransitionToFishing(PlayerAvatar *playerAvatar) {
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_FISHING, PlayerAvatar_GetGender(playerAvatar)));
}

static void Field_PlayerAvatar_TransitionToPoketch(PlayerAvatar *playerAvatar) {
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_POKETCH, PlayerAvatar_GetGender(playerAvatar)));
}

static void Field_PlayerAvatar_TransitionToSaving(PlayerAvatar *playerAvatar) {
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_SAVING, PlayerAvatar_GetGender(playerAvatar)));
}

static void Field_PlayerAvatar_TransitionToHeal(PlayerAvatar *playerAvatar) {
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_HEAL, PlayerAvatar_GetGender(playerAvatar)));
}

static void Field_PlayerAvatar_TransitionToLadder(PlayerAvatar *playerAvatar) {
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_LADDER, PlayerAvatar_GetGender(playerAvatar)));
}

static void Field_PlayerAvatar_TransitionToRocketHeal(PlayerAvatar *playerAvatar) {
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_ROCKET_HEAL, PlayerAvatar_GetGender(playerAvatar)));
}

static void Field_PlayerAvatar_TransitionToPokeathlon(PlayerAvatar *playerAvatar) {
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_POKEATHLON, PlayerAvatar_GetGender(playerAvatar)));
}

static void Field_PlayerAvatar_TransitionToApricornShake(PlayerAvatar *playerAvatar) {
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_APRICORN_SHAKE, PlayerAvatar_GetGender(playerAvatar)));
}

static void Field_PlayerAvatar_TransitionToRocketSaving(PlayerAvatar *playerAvatar) {
    Field_PlayerAvatar_SetSprite(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_ROCKET_SAVING, PlayerAvatar_GetGender(playerAvatar)));
}

BOOL Field_PlayerAvatar_TryFieldMoveStep(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int direction, int playerEvents) {
    if (PlayerAvatar_CheckForcedMovement(playerAvatar) == TRUE) {
        if (Field_PlayerAvatar_HandleForcedMovement(fieldSystem, playerAvatar, playerEvents) == TRUE) {
            return TRUE;
        }
        return FALSE;
    }
    if (!PlayerAvatar_CheckReadyToMove(playerAvatar, direction)) {
        return FALSE;
    }
    if (direction == -1) {
        return FALSE;
    }
    if (Field_PlayerAvatar_TryFieldMoveInDirection(fieldSystem, playerAvatar, direction, playerEvents) == TRUE) {
        return TRUE;
    }
    return FALSE;
}

static BOOL Field_PlayerAvatar_TryFieldMoveInDirection(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, u32 direction, int playerEvents) {
    int collision = PlayerAvatar_GetMoveStateForDirection(playerAvatar, direction);
    if (playerEvents & PLAYER_EVENT_USED_STRENGTH) {
        if (Field_PlayerAvatar_TryPushBoulder(fieldSystem, playerAvatar, direction, collision) == TRUE) {
            return TRUE;
        }
    }
    if (playerEvents & PLAYER_EVENT_USED_WATERFALL) {
        if (Field_PlayerAvatar_TryWaterfallUp(fieldSystem, playerAvatar, direction, collision) == TRUE) {
            return TRUE;
        }
    }
    if (Field_PlayerAvatar_TryStopSurfing(fieldSystem, playerAvatar, direction, collision) == TRUE) {
        return TRUE;
    }
    return FALSE;
}

static BOOL Field_PlayerAvatar_TryPushBoulder(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, u32 direction, int collision) {
    LocalMapObject *boulder;
    if (collision != 1) {
        return FALSE;
    }
    boulder = Field_PlayerAvatar_GetFacingMapObject(playerAvatar, direction);
    if (boulder == NULL) {
        return FALSE;
    }
    if (MapObject_GetSpriteID(boulder) != SPRITE_ROCK) {
        return FALSE;
    }
    if ((MapObject_CheckCollisionInDirection(boulder, direction) & ~1) != 0) {
        return FALSE;
    }
    Field_StartPushBoulderTask(direction, fieldSystem, playerAvatar, boulder);
    return TRUE;
}

static void Field_StartPushBoulderTask(u32 direction, FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, LocalMapObject *boulder) {
    PushBoulderWork *work = FieldMoveTask_AllocWork(sizeof(PushBoulderWork));
    work->direction = direction;
    work->fieldSystem = fieldSystem;
    work->boulder = boulder;
    work->playerAvatar = playerAvatar;
    FieldSystem_CreateTask(fieldSystem, Task_PushBoulder, work);
}

static BOOL Task_PushBoulder(TaskManager *taskManager) {
    PushBoulderWork *work = TaskManager_GetEnvironment(taskManager);
    LocalMapObject *player = PlayerAvatar_GetMapObject(work->playerAvatar);
    LocalMapObject *boulder = work->boulder;
    switch (work->state) {
    case PUSH_BOULDER_STATE_START:
        if (!MapObject_AreBitsSetForMovementScriptInit(boulder)) {
            break;
        }
        if (!MapObject_AreBitsSetForMovementScriptInit(player) && !PlayerAvatar_IsReadyOrBumpingWall(work->playerAvatar)) {
            break;
        }
        MapObject_SetHeldMovement(boulder, GetMovementForDirection(work->direction, 8));
        MapObject_SetHeldMovement(player, GetMovementForDirection(work->direction, 32));
        PlaySE(SEQ_SE_DP_UG_023);
        work->state++;
        break;
    case PUSH_BOULDER_STATE_WAIT:
        if (!MapObject_IsMovementPaused(boulder)) {
            break;
        }
        if (!MapObject_IsMovementPaused(player)) {
            break;
        }
        MapObject_ClearHeldMovementIfActive(boulder);
        MapObject_ClearHeldMovementIfActive(player);
        work->state++;
        // fallthrough
    case PUSH_BOULDER_STATE_END: {
        FieldSystem *fieldSystem = work->fieldSystem;
        FieldMoveTask_FreeWork(work);
        if (fieldSystem->location->mapId == MAP_ICE_PATH_B1F) {
            return PushBoulder_Finish(taskManager, fieldSystem, boulder);
        }
        return TRUE;
    }
    }
    return FALSE;
}

static BOOL Field_TryDropBoulderIntoHole(FieldSystem *fieldSystem, LocalMapObject *boulder) {
    u32 i;
    for (i = 0; i < NELEMS(sIcePathBoulderHoles); i++) {
        if (sIcePathBoulderHoles[i].mapId == MapObject_GetMapID(boulder) && sIcePathBoulderHoles[i].objectId == MapObject_GetID(boulder) && sIcePathBoulderHoles[i].x == MapObject_GetXCoord(boulder) && sIcePathBoulderHoles[i].z == MapObject_GetZCoord(boulder)) {
            FieldSystem_FlagSet(fieldSystem, MapObject_GetEventFlag(boulder));
            MapObject_Delete(boulder);
            {
                const BoulderHole *hole = sIcePathBoulderHoles + i;
                FieldSystem_FlagClear(fieldSystem, hole->belowFlag);
            }
            return TRUE;
        }
    }
    return FALSE;
}

static BOOL PushBoulder_Finish(TaskManager *taskManager, FieldSystem *fieldSystem, LocalMapObject *boulder) {
    if (!Field_TryDropBoulderIntoHole(fieldSystem, boulder)) {
        return TRUE;
    }
    StartScriptFromMenu(taskManager, std_boulder_fell_down, NULL);
    return FALSE;
}

static void Field_StartSurfTask(FieldSystem *fieldSystem, u32 direction, FieldMoveAnim *anim) {
    SurfWork *work = FieldMoveTask_AllocWork(sizeof(SurfWork));
    work->direction = direction;
    work->fieldSystem = fieldSystem;
    work->playerAvatar = fieldSystem->playerAvatar;
    work->mapObject = PlayerAvatar_GetMapObject(work->playerAvatar);
    work->anim = *anim;
    TaskManager_Call(fieldSystem->taskman, Task_Surf, work);
}

void CallFieldTask_Surf(TaskManager *taskManager, int direction, int partySlot) {
    u32 state;
    FieldMoveAnim anim;
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FieldMoveAnim_Init(fieldSystem, Field_GetPartyMon(fieldSystem, partySlot), &anim);
    state = PlayerAvatar_GetState(fieldSystem->playerAvatar);
    if (state - 1 <= 1) {
        anim.useCutIn = TRUE;
    } else if (FollowMon_IsNextToPlayer(fieldSystem) && partySlot == FieldSystem_GetLeadMonIndex(fieldSystem)) {
        anim.useCutIn = FALSE;
    }
    Field_StartSurfTask(fieldSystem, direction, &anim);
}

BOOL Field_PlayerCanSurfOnTile(PlayerAvatar *playerAvatar, int currentTile, int facingTile) {
    LocalMapObject *mapObject = PlayerAvatar_GetMapObject(playerAvatar);
    if (MetatileBehavior_IsSurfableWater(facingTile) == TRUE) {
        if (MetatileBehavior_IsBridge(currentTile) == TRUE || MetatileBehavior_IsBridgeStart(currentTile) == TRUE) {
            if (MapObject_CheckFlag28(mapObject) == TRUE) {
                return FALSE;
            }
        }
        if (MetatileBehavior_Is34(currentTile) == TRUE) {
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

static BOOL Task_Surf(TaskManager *taskManager) {
    SurfWork *work = TaskManager_GetEnvironment(taskManager);
    switch (work->state) {
    case SURF_STATE_START_BGM:
        if (!CheckFlag99A(Save_VarsFlags_Get(work->fieldSystem->saveData)) && !SndRadio_GetSeqNo()) {
            FieldBGM_SetOverride(work->fieldSystem, 0);
            FieldBGM_TryFadeOut(work->fieldSystem, SEQ_GS_NAMINORI, 1);
        }
        work->state++;
        work->state++;
        break;
    case SURF_STATE_WAIT:
        if (++work->timer > 10) {
            work->timer = 0;
            work->state++;
        }
        break;
    case SURF_STATE_START_ANIM:
        if (work->anim.useCutIn == TRUE) {
            FieldMoveAnim_Start(work->fieldSystem, &work->anim);
            work->state = SURF_STATE_WAIT_CUT_IN;
        } else {
            u8 count;
            if (FieldSystem_FirstAliveMonHasType(work->fieldSystem, TYPE_WATER)) {
                FollowMonMood_Add(work->fieldSystem->followMonMood, 1);
                count = 2;
            } else {
                count = 1;
            }
            FollowMon_JumpOnSpot(work->fieldSystem, count);
            work->state = SURF_STATE_PLAY_CRY;
        }
        break;
    case SURF_STATE_PLAY_CRY: {
        u32 species = GetMonData(work->anim.mon, MON_DATA_SPECIES, NULL);
        u32 form = GetMonData(work->anim.mon, MON_DATA_FORM, NULL);
        PlayCry(species, form);
        work->state = SURF_STATE_WAIT_CRY;
        break;
    }
    case SURF_STATE_WAIT_CRY:
        if (!IsCryPlaying()) {
            FollowMon_StartHideForFieldMove(taskManager);
            work->state = SURF_STATE_CREATE_MOUNT;
        }
        break;
    case SURF_STATE_WAIT_CUT_IN:
        if (FieldMoveAnim_CheckFinished(&work->anim) == TRUE) {
            FollowMon_StartRecall(work->fieldSystem);
            work->state = SURF_STATE_CREATE_MOUNT;
        }
        break;
    case SURF_STATE_CREATE_MOUNT: {
        int x = PlayerAvatar_GetXCoord(work->playerAvatar);
        int dx = GetDeltaXByFacingDirection(work->direction);
        int z = PlayerAvatar_GetZCoord(work->playerAvatar);
        int dz = GetDeltaYByFacingDirection(work->direction);
        work->surfMount = SurfMountEffect_Create(work->mapObject, x + dx, z + dz, work->direction, FALSE);
        PlayerAvatar_SetSurfMountEffect(work->playerAvatar, work->surfMount);
        PlayerAvatar_SetState(work->playerAvatar, PLAYER_STATE_SURFING);
        work->state++;
        break;
    }
    case SURF_STATE_WAIT_MOUNT:
        if (++work->timer > 10) {
            Field_PlayerAvatar_SetSprite(work->playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_WALKING, PlayerAvatar_GetGender(work->playerAvatar)));
            work->timer = 0;
            work->state++;
        }
        break;
    case SURF_STATE_JUMP_ON:
        if (MapObject_AreBitsSetForMovementScriptInit(work->mapObject) == TRUE) {
            MapObject_SetHeldMovement(work->mapObject, GetMovementForDirection(work->direction, 52));
            work->state++;
        }
        break;
    case SURF_STATE_WAIT_JUMP:
        if (MapObject_IsMovementPaused(work->mapObject)) {
            MapObject_ClearHeldMovementIfActive(work->mapObject);
            SurfMountEffect_SetBobbing(work->surfMount, TRUE);
            Field_PlayerAvatar_SetSprite(work->playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_SURFING, PlayerAvatar_GetGender(work->playerAvatar)));
            if (FollowMon_IsActive(work->fieldSystem)) {
                FollowMon_MoveToPlayer(work->fieldSystem, work->direction);
                MapObject_ChangeMovement(FollowMon_GetMapObject(work->fieldSystem), 56);
            }
            FieldSystem_ProcessSoundplate(work->fieldSystem, FALSE);
            FieldMoveTask_FreeWork(work);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static BOOL Field_PlayerAvatar_TryStopSurfing(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, u32 direction, int collision) {
    u32 result;

    if (collision != 1 || PlayerAvatar_GetState(playerAvatar) != PLAYER_STATE_SURFING) {
        return FALSE;
    }
    result = PlayerAvatar_CheckCollision(playerAvatar, PlayerAvatar_GetMapObject(playerAvatar), direction);
    if (result == PLAYER_COLLISION_WATER) {
        return FALSE;
    }
    if ((result & ~PLAYER_COLLISION_WATER) != 0) {
        return FALSE;
    }
    Field_StartStopSurfingTask(direction, fieldSystem, playerAvatar);
    return TRUE;
}

static void Field_StartStopSurfingTask(u32 direction, FieldSystem *fieldSystem, PlayerAvatar *playerAvatar) {
    StopSurfingWork *work;

    work = FieldMoveTask_AllocWork(sizeof(StopSurfingWork));
    work->direction = direction;
    work->fieldSystem = fieldSystem;
    work->playerAvatar = playerAvatar;
    work->mapObject = PlayerAvatar_GetMapObject(playerAvatar);
    work->surfMount = PlayerAvatar_GetSurfMountEffect(playerAvatar);
    GF_ASSERT(work->surfMount != NULL);
    FieldSystem_CreateTask(fieldSystem, Task_StopSurfing, work);
}

static BOOL Task_StopSurfing(TaskManager *taskManager) {
    StopSurfingWork *work = TaskManager_GetEnvironment(taskManager);

    switch (work->state) {
    case STOP_SURFING_STATE_JUMP_OFF:
        if (MapObject_AreBitsSetForMovementScriptInit(work->mapObject) == TRUE) {
            Field_PlayerAvatar_SetSprite(work->playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(PLAYER_STATE_WALKING, PlayerAvatar_GetGender(work->playerAvatar)));
            MapObject_SetHeldMovement(work->mapObject, GetMovementForDirection(work->direction, 0x34));
            SurfMountEffect_SetBobbing(work->surfMount, FALSE);
            work->state++;
        }
        break;
    case STOP_SURFING_STATE_WAIT_JUMP:
        if (MapObject_IsMovementPaused(work->mapObject)) {
            MapObject_ClearHeldMovementIfActive(work->mapObject);
            FieldEffectManager_DestroyEffect(work->surfMount);
            PlayerAvatar_SetSurfMountEffect(work->playerAvatar, NULL);
            PlayerAvatar_SetState(work->playerAvatar, PLAYER_STATE_WALKING);
            FieldSystem_ProcessSoundplate(work->fieldSystem, FALSE);
            if (FollowMon_IsActive(work->fieldSystem)) {
                FollowMon_MoveToPlayer(work->fieldSystem, work->direction);
                FollowMon_HideUntilStep(FollowMon_GetMapObject(work->fieldSystem), TRUE);
                FollowMon_SetFacingDirection(work->fieldSystem, DIR_SOUTH);
                MapObject_ChangeMovement(FollowMon_GetMapObject(work->fieldSystem), 0x30);
            }
            if (!CheckFlag99A(Save_VarsFlags_Get(work->fieldSystem->saveData))) {
                FieldBGM_TryFadeOut(work->fieldSystem, FieldBGM_GetForMapHeader(work->fieldSystem, work->fieldSystem->location->mapId), 4);
            }
            if (SndRadio_GetSeqNo() != 0) {
                work->timer = 0x28;
                work->state++;
            } else {
                FieldMoveTask_FreeWork(work);
                return TRUE;
            }
        }
        break;
    case STOP_SURFING_STATE_WAIT_RADIO:
        if (SndRadio_GetSeqNo() == 0) {
            FieldSystem_ProcessSoundplate(work->fieldSystem, TRUE);
            FieldMoveTask_FreeWork(work);
            return TRUE;
        }
        work->timer--;
        if (work->timer == 0) {
            FieldSystem_ProcessSoundplate(work->fieldSystem, TRUE);
            FieldMoveTask_FreeWork(work);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static BOOL Field_PlayerAvatar_TryWaterfallUp(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, u32 direction, int collision) {
    if (direction != 1 || collision != 1 || PlayerAvatar_GetState(playerAvatar) != PLAYER_STATE_SURFING) {
        return FALSE;
    }
    if (!MetatileBehavior_IsWaterfall(PlayerAvatar_GetMetatileBehaviorInDirection(playerAvatar, direction))) {
        return FALSE;
    }
    Field_StartWaterfallTask(fieldSystem, direction);
    return TRUE;
}

static BOOL Field_PlayerAvatar_HandleForcedMovement(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int playerEvents) {
    MapObject_AreBitsSetForMovementScriptInit(PlayerAvatar_GetMapObject(playerAvatar));
    return FALSE;
}

static void Field_StartRockClimbTask(FieldSystem *fieldSystem, u32 direction, FieldMoveAnim *anim) {
    PlayerAvatar *playerAvatar;
    RockClimbWork *work = FieldMoveTask_AllocWork(sizeof(RockClimbWork));
    work->direction = direction;
    work->fieldSystem = fieldSystem;
    playerAvatar = fieldSystem->playerAvatar;
    work->playerAvatar = playerAvatar;
    work->mapObject = PlayerAvatar_GetMapObject(playerAvatar);
    work->anim = *anim;
    if (work->anim.useCutIn == TRUE) {
        work->climbState = 5;
    } else {
        work->climbState = 6;
    }
    TaskManager_Call(fieldSystem->taskman, Task_RockClimb, work);
}

void CallFieldTask_RockClimb(TaskManager *taskManager, int direction, int partySlot) {
    u32 state;
    FieldMoveAnim anim;
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FieldMoveAnim_Init(fieldSystem, Field_GetPartyMon(fieldSystem, partySlot), &anim);
    state = PlayerAvatar_GetState(fieldSystem->playerAvatar);
    if (state - 1 <= 1) {
        anim.useCutIn = TRUE;
    } else if (FollowMon_IsNextToPlayer(fieldSystem) && partySlot == FieldSystem_GetLeadMonIndex(fieldSystem)) {
        anim.useCutIn = FALSE;
    }
    Field_StartRockClimbTask(fieldSystem, direction, &anim);
}

BOOL MetatileBehavior_IsRockClimbInDirection(int facingTile, int facingDirection) {
    switch (facingDirection) {
    case DIR_NORTH:
    case DIR_SOUTH:
        if (MetatileBehavior_IsRockClimbNorthSouth(facingTile) == TRUE) {
            return TRUE;
        }
        break;
    case DIR_WEST:
    case DIR_EAST:
        if (MetatileBehavior_IsRockClimbEastWest(facingTile) == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static BOOL Task_RockClimb(TaskManager *taskManager) {
    RockClimbWork *work = TaskManager_GetEnvironment(taskManager);
    enum FieldMoveTaskStepResult result;
    do {
        if (work->anim.useCutIn == TRUE) {
            result = sRockClimbCutInSteps[work->state](work, taskManager);
        } else {
            result = sRockClimbFollowMonSteps[work->state](work, taskManager);
        }
    } while (result == FIELD_MOVE_TASK_STEP_NEXT);
    if (result == FIELD_MOVE_TASK_STEP_DONE) {
        FollowMon_MoveToPlayer(work->fieldSystem, work->direction);
        FollowMon_HideUntilStep(FollowMon_GetMapObject(work->fieldSystem), TRUE);
        FollowMon_SetFacingDirection(work->fieldSystem, DIR_SOUTH);
        FieldMoveTask_FreeWork(work);
    }
    return result;
}

static enum FieldMoveTaskStepResult RockClimb_StartCutIn(RockClimbWork *work, TaskManager *taskManager) {
    FieldMoveAnim_Start(work->fieldSystem, &work->anim);
    work->state++;
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult RockClimb_WaitCutIn(RockClimbWork *work, TaskManager *taskManager) {
    if (FieldMoveAnim_CheckFinished(&work->anim) == TRUE) {
        FollowMon_StartRecall(work->fieldSystem);
        work->state++;
    }
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult RockClimb_FollowMonReact(RockClimbWork *work, TaskManager *taskManager) {
    u8 count;
    if (FieldSystem_FirstAliveMonHasType(work->fieldSystem, TYPE_NORMAL)) {
        FollowMonMood_Add(work->fieldSystem->followMonMood, 1);
        count = 2;
    } else {
        count = 1;
    }
    FollowMon_JumpOnSpot(work->fieldSystem, count);
    work->state++;
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult RockClimb_PlayFollowMonCry(RockClimbWork *work, TaskManager *taskManager) {
    u32 species = GetMonData(work->anim.mon, MON_DATA_SPECIES, NULL);
    u32 form = GetMonData(work->anim.mon, MON_DATA_FORM, NULL);
    PlayCry(species, form);
    work->state++;
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult RockClimb_WaitFollowMonCry(RockClimbWork *work, TaskManager *taskManager) {
    if (IsCryPlaying()) {
        return FIELD_MOVE_TASK_STEP_WAIT;
    }
    FollowMon_StartHideForFieldMove(taskManager);
    work->state++;
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult RockClimb_CreateEffect(RockClimbWork *work, TaskManager *taskManager) {
    int x = PlayerAvatar_GetXCoord(work->playerAvatar);
    int dx = GetDeltaXByFacingDirection(work->direction);
    int z = PlayerAvatar_GetZCoord(work->playerAvatar);
    int dz = GetDeltaYByFacingDirection(work->direction);
    work->effect = RockClimbEffect_Create(work->mapObject, x + dx, z + dz, work->direction, FALSE);
    if (FollowMon_IsActive(work->fieldSystem)) {
        MapObject_UnpauseMovement(FollowMon_GetMapObject(work->fieldSystem));
    }
    work->debris = RockClimbDebris_Create(work->fieldSystem);
    PlaySE(SEQ_SE_DP_UG_023);
    work->state++;
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult RockClimb_StartJump(RockClimbWork *work, TaskManager *taskManager) {
    if (MapObject_AreBitsSetForMovementScriptInit(work->mapObject) == TRUE) {
        MapObject_SetHeldMovement(work->mapObject, GetMovementForDirection(work->direction, 0x34));
        work->state++;
    }
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult RockClimb_WaitJump(RockClimbWork *work, TaskManager *taskManager) {
    if (MapObject_IsMovementPaused(work->mapObject) == TRUE) {
        work->state++;
        RockClimbEffect_SetFollow(work->effect, TRUE);
    }
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult RockClimb_StartStep(RockClimbWork *work, TaskManager *taskManager) {
    if (MapObject_AreBitsSetForMovementScriptInit(work->mapObject) == TRUE) {
        MapObject_SetHeldMovement(work->mapObject, GetMovementForDirection(work->direction, MOVEMENT_RUN_UP));
        work->state++;
    }
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult RockClimb_CheckNextTile(RockClimbWork *work, TaskManager *taskManager) {
    u32 direction;
    if (!MapObject_IsMovementPaused(work->mapObject)) {
        return FIELD_MOVE_TASK_STEP_WAIT;
    }
    direction = MapObject_GetNextFacingDirection(work->mapObject);
    if (MetatileBehavior_IsRockClimbInDirection((u8)MapObject_GetMetatileBehaviorInDirection(work->mapObject, direction), direction) == TRUE) {
        work->state = work->climbState;
        return FIELD_MOVE_TASK_STEP_NEXT;
    }
    MapObject_SetHeldMovement(work->mapObject, GetMovementForDirection(work->direction, 52));
    work->timer = 0;
    work->state++;
    RockClimbEffect_SetFollow(work->effect, FALSE);
    RockClimbDebris_Delete(work->debris);
    work->debris = NULL;
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult RockClimb_Finish(RockClimbWork *work, TaskManager *taskManager) {
    if (!MapObject_IsMovementPaused(work->mapObject)) {
        return FIELD_MOVE_TASK_STEP_WAIT;
    }
    MapObject_ClearHeldMovementIfActive(work->mapObject);
    FieldEffectManager_DestroyEffect(work->effect);
    return FIELD_MOVE_TASK_STEP_DONE;
}

static WaterfallWork *Waterfall_NewWork(FieldSystem *fieldSystem, int direction, FieldMoveAnim *anim) {
    WaterfallWork *work = FieldMoveTask_AllocWork(sizeof(WaterfallWork));
    work->direction = direction;
    work->fieldSystem = fieldSystem;
    work->playerAvatar = fieldSystem->playerAvatar;
    work->mapObject = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    if (anim != NULL) {
        work->anim = *anim;
    }
    return work;
}

static void Field_StartWaterfallTask(FieldSystem *fieldSystem, u32 direction) {
    FieldSystem_CreateTask(fieldSystem, Task_Waterfall, Waterfall_NewWork(fieldSystem, direction, NULL));
}

void CallFieldTask_Waterfall(TaskManager *taskManager, int direction, int partySlot) {
    FieldMoveAnim anim;
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FieldMoveAnim_Init(fieldSystem, Field_GetPartyMon(fieldSystem, partySlot), &anim);
    TaskManager_Call(taskManager, Task_Waterfall, Waterfall_NewWork(fieldSystem, direction, &anim));
}

static BOOL Task_Waterfall(TaskManager *taskManager) {
    WaterfallWork *work = TaskManager_GetEnvironment(taskManager);
    enum FieldMoveTaskStepResult result;
    do {
        if (work->direction == 0) {
            result = sWaterfallUpSteps[work->state](work);
        } else {
            result = sWaterfallDownSteps[work->state](work);
        }
    } while (result == FIELD_MOVE_TASK_STEP_NEXT);
    if (result == FIELD_MOVE_TASK_STEP_DONE) {
        FollowMon_MoveToPlayer(work->fieldSystem, work->direction);
        FieldMoveTask_FreeWork(work);
        return TRUE;
    }
    return FALSE;
}

static enum FieldMoveTaskStepResult WaterfallUp_StartCutIn(WaterfallWork *work) {
    if (work->anim.useCutIn == TRUE) {
        FieldMoveAnim_Start(work->fieldSystem, &work->anim);
        work->state++;
        return FIELD_MOVE_TASK_STEP_WAIT;
    }
    work->state = 2;
    return FIELD_MOVE_TASK_STEP_DONE;
}

static enum FieldMoveTaskStepResult WaterfallUp_WaitCutIn(WaterfallWork *work) {
    if (FieldMoveAnim_CheckFinished(&work->anim) == TRUE) {
        PlaySE(SEQ_SE_DP_FW463);
        work->state++;
    }
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult WaterfallUp_Init(WaterfallWork *work) {
    VecFx32 position;
    VecFx32 step;
    u8 kind;
    int x = MapObject_GetXCoord(work->mapObject) + (GetDeltaXByFacingDirection(DIR_NORTH) << 1);
    int z = MapObject_GetZCoord(work->mapObject) + (GetDeltaYByFacingDirection(DIR_NORTH) << 1);
    SetPositionToTileCenter(x, z, &work->targetPos);
    work->targetPos.y = Terrain_CalcHeightWithMode(work->fieldSystem, 1, work->targetPos.y, work->targetPos.x, work->targetPos.z, &kind);
    GF_ASSERT(kind != CALCULATED_HEIGHT_SOURCE_NONE);
    work->targetX = x;
    work->targetY = (work->targetPos.y >> 3) / FX32_ONE;
    work->targetZ = z;
    MapObject_CopyPositionVector(work->mapObject, &position);
    GF_ASSERT(position.z > work->targetPos.z);
    GF_ASSERT(position.y < work->targetPos.y);
    step.x = 0;
    step.y = work->targetPos.y - position.y;
    step.z = work->targetPos.z - position.z;
    step.y /= 64;
    step.z /= 64;
    work->step = step;
    work->effect = WaterfallEffect_Create(work->fieldSystem);
    work->state++;
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult WaterfallUp_Rise(WaterfallWork *work) {
    VecFx32 position;
    MapObject_CopyPositionVector(work->mapObject, &position);
    position.y += work->step.y;
    if (position.y > work->targetPos.y) {
        position.y = work->targetPos.y;
    }
    MapObject_SetPositionVector(work->mapObject, &position);
    work->counter++;
    if (work->counter >= 32) {
        work->counter = 0;
        work->state++;
    }
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult WaterfallUp_Climb(WaterfallWork *work) {
    VecFx32 position;
    MapObject_CopyPositionVector(work->mapObject, &position);
    position.y += work->step.y;
    if (position.y > work->targetPos.y) {
        position.y = work->targetPos.y;
    }
    position.z += work->step.z;
    if (position.z < work->targetPos.z) {
        position.z = work->targetPos.z;
    }
    MapObject_SetPositionVector(work->mapObject, &position);
    work->counter++;
    if (work->counter < 64) {
        return FIELD_MOVE_TASK_STEP_WAIT;
    }
    GF_ASSERT(position.z == work->targetPos.z);
    GF_ASSERT(position.y == work->targetPos.y);
    MapObject_SetCurrentX(work->mapObject, work->targetX);
    MapObject_SetCurrentY(work->mapObject, work->targetY);
    MapObject_SetCurrentZ(work->mapObject, work->targetZ);
    MapObject_SetPreviousCoordsToCurrent(work->mapObject);
    WaterfallEffect_Delete(work->effect);
    return FIELD_MOVE_TASK_STEP_DONE;
}

static enum FieldMoveTaskStepResult WaterfallDown_StartCutIn(WaterfallWork *work) {
    if (work->anim.useCutIn == TRUE) {
        FieldMoveAnim_Start(work->fieldSystem, &work->anim);
        work->state++;
        return FIELD_MOVE_TASK_STEP_WAIT;
    }
    work->state = 2;
    return FIELD_MOVE_TASK_STEP_NEXT;
}

static enum FieldMoveTaskStepResult WaterfallDown_WaitCutIn(WaterfallWork *work) {
    if (FieldMoveAnim_CheckFinished(&work->anim) == TRUE) {
        PlaySE(SEQ_SE_DP_FW463);
        work->state++;
    }
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult WaterfallDown_Init(WaterfallWork *work) {
    VecFx32 position;
    VecFx32 step;
    int x = MapObject_GetXCoord(work->mapObject) + (GetDeltaXByFacingDirection(DIR_SOUTH) << 1);
    int z = MapObject_GetZCoord(work->mapObject) + (GetDeltaYByFacingDirection(DIR_SOUTH) << 1);
    SetPositionToTileCenter(x, z, &work->targetPos);
    FieldSystem_SnapToTerrainHeight(work->fieldSystem, &work->targetPos);
    work->progress = 0;
    work->targetX = x;
    work->targetY = (work->targetPos.y >> 3) / FX32_ONE;
    work->targetZ = z;
    MapObject_CopyPositionVector(work->mapObject, &position);
    GF_ASSERT(position.z < work->targetPos.z);
    GF_ASSERT(position.y > work->targetPos.y);
    step.x = 0;
    step.y = work->targetPos.y - position.y;
    step.z = work->targetPos.z - position.z;
    step.y /= 64;
    step.z /= 64;
    work->step = step;
    work->effect = WaterfallEffect_Create(work->fieldSystem);
    work->state++;
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult WaterfallDown_Advance(WaterfallWork *work) {
    VecFx32 position;
    MapObject_CopyPositionVector(work->mapObject, &position);
    position.z += work->step.z;
    if (position.z > work->targetPos.z) {
        position.z = work->targetPos.z;
    } else {
        work->progress += work->step.z;
    }
    MapObject_SetPositionVector(work->mapObject, &position);
    work->counter++;
    if (work->counter >= 32) {
        work->counter = 0;
        work->state++;
    }
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult WaterfallDown_Descend(WaterfallWork *work) {
    VecFx32 position;
    MapObject_CopyPositionVector(work->mapObject, &position);
    position.y += work->step.y;
    if (position.y < work->targetPos.y) {
        position.y = work->targetPos.y;
    }
    position.z += work->step.z;
    if (position.z > work->targetPos.z) {
        position.z = work->targetPos.z;
    } else {
        work->progress += work->step.z;
    }
    MapObject_SetPositionVector(work->mapObject, &position);
    work->counter++;
    if (work->counter < 64) {
        return FIELD_MOVE_TASK_STEP_WAIT;
    }
    GF_ASSERT(position.z == work->targetPos.z);
    GF_ASSERT(position.y == work->targetPos.y);
    MapObject_SetCurrentX(work->mapObject, work->targetX);
    MapObject_SetCurrentY(work->mapObject, work->targetY);
    MapObject_SetCurrentZ(work->mapObject, work->targetZ);
    MapObject_SetPreviousCoordsToCurrent(work->mapObject);
    WaterfallEffect_Delete(work->effect);
    return FIELD_MOVE_TASK_STEP_DONE;
}

static void Field_StartWhirlpoolTask(FieldSystem *fieldSystem, u32 direction, FieldMoveAnim *anim) {
    WaterfallWork *work = FieldMoveTask_AllocWork(sizeof(WaterfallWork));
    work->direction = direction;
    work->fieldSystem = fieldSystem;
    work->playerAvatar = fieldSystem->playerAvatar;
    work->mapObject = PlayerAvatar_GetMapObject(work->playerAvatar);
    work->anim = *anim;
    TaskManager_Call(fieldSystem->taskman, Task_Whirlpool, work);
}

void CallFieldTask_Whirlpool(TaskManager *taskManager, int direction, int partySlot) {
    FieldMoveAnim anim;
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FieldMoveAnim_Init(fieldSystem, Field_GetPartyMon(fieldSystem, partySlot), &anim);
    Field_StartWhirlpoolTask(fieldSystem, direction, &anim);
}

static BOOL Task_Whirlpool(TaskManager *taskManager) {
    enum FieldMoveTaskStepResult result;
    WaterfallWork *work = TaskManager_GetEnvironment(taskManager);
    do {
        result = sWhirlpoolSteps[work->state](work);
    } while (result == FIELD_MOVE_TASK_STEP_NEXT);
    if (result == FIELD_MOVE_TASK_STEP_DONE) {
        FollowMon_MoveToPlayer(work->fieldSystem, work->direction);
        FieldMoveTask_FreeWork(work);
    }
    return result;
}

static enum FieldMoveTaskStepResult Whirlpool_StartCutIn(WaterfallWork *work) {
    FieldMoveAnim_Start(work->fieldSystem, &work->anim);
    work->state++;
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult Whirlpool_WaitCutIn(WaterfallWork *work) {
    if (FieldMoveAnim_CheckFinished(&work->anim) == TRUE) {
        work->state++;
    }
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult Whirlpool_CreateEffect(WaterfallWork *work) {
    if (FollowMon_IsActive(work->fieldSystem)) {
        MapObject_UnpauseMovement(FollowMon_GetMapObject(work->fieldSystem));
    }
    work->effect = WhirlpoolEffect_Create(work->fieldSystem);
    PlaySE(SEQ_SE_DP_FW463);
    work->state++;
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult Whirlpool_StartStep(WaterfallWork *work) {
    if (MapObject_AreBitsSetForMovementScriptInit(work->mapObject) == TRUE) {
        MapObject_SetHeldMovement(work->mapObject, GetMovementForDirection(work->direction, 4));
        work->state++;
    }
    return FIELD_MOVE_TASK_STEP_WAIT;
}

static enum FieldMoveTaskStepResult Whirlpool_CheckNextTile(WaterfallWork *work) {
    if (!MapObject_IsMovementPaused(work->mapObject)) {
        return FIELD_MOVE_TASK_STEP_WAIT;
    }
    MapObject_GetNextFacingDirection(work->mapObject);
    if (MetatileBehavior_IsWhirlpool(MapObject_GetCurrentMetatileBehavior(work->mapObject)) == TRUE) {
        work->state = 3;
        return FIELD_MOVE_TASK_STEP_NEXT;
    }
    WhirlpoolEffect_Delete(work->effect);
    work->effect = NULL;
    MapObject_ClearHeldMovementIfActive(work->mapObject);
    return FIELD_MOVE_TASK_STEP_DONE;
}

void Field_PlayerAvatar_TryEnterPoketchPose(PlayerAvatar *playerAvatar) {
    u32 flags;
    LocalMapObject *mapObject = PlayerAvatar_GetMapObject(playerAvatar);
    if (MapObject_IsDrawInitialized(mapObject) && PlayerAvatar_GetState(playerAvatar) == PLAYER_STATE_WALKING && MapObject_GetSpriteID(mapObject) - SPRITE_POKEHERO > 1) {
        flags = PlayerAvatar_GetTransitionFlags(playerAvatar);
        Field_PlayerAvatar_OrrTransitionFlags(playerAvatar, PLAYER_TRANSITION_POKETCH);
        Field_PlayerAvatar_ApplyTransitionFlags(playerAvatar);
        Field_PlayerAvatar_OrrTransitionFlags(playerAvatar, flags);
    }
}

void Field_PlayerAvatar_TryLeavePoketchPose(PlayerAvatar *playerAvatar) {
    u32 flags;
    LocalMapObject *mapObject = PlayerAvatar_GetMapObject(playerAvatar);
    if (MapObject_IsDrawInitialized(mapObject) && PlayerAvatar_GetState(playerAvatar) == PLAYER_STATE_WALKING) {
        switch (MapObject_GetSpriteID(mapObject)) {
        case SPRITE_POKEHERO:
        case SPRITE_POKEHEROINE:
            flags = PlayerAvatar_GetTransitionFlags(playerAvatar);
            Field_PlayerAvatar_OrrTransitionFlags(playerAvatar, PLAYER_TRANSITION_WALKING);
            Field_PlayerAvatar_ApplyTransitionFlags(playerAvatar);
            Field_PlayerAvatar_OrrTransitionFlags(playerAvatar, flags);
            break;
        }
    }
}

SysTask *Field_PlayerMovementSavingSet(FieldSystem *fieldSystem) {
    PlayerAvatar *playerAvatar = fieldSystem->playerAvatar;
    u32 state = PlayerAvatar_GetState(playerAvatar);
    PlayerSavingPoseWork *work;
    LocalMapObject *mapObject;
    SysTask *task;
    u32 flags;
    if (state != PLAYER_STATE_WALKING && state != PLAYER_STATE_ROCKET) {
        return NULL;
    }
    mapObject = PlayerAvatar_GetMapObject(playerAvatar);
    work = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(PlayerSavingPoseWork));
    work->unk_00 = 0;
    work->fieldSystem = fieldSystem;
    work->playerAvatar = playerAvatar;
    work->state = state;
    if (state == PLAYER_STATE_WALKING) {
        flags = PLAYER_TRANSITION_SAVING;
    } else if (state == PLAYER_STATE_ROCKET) {
        flags = PLAYER_TRANSITION_ROCKET_SAVING;
    } else {
        GF_ASSERT(FALSE);
        flags = PLAYER_TRANSITION_SAVING;
    }
    MapObject_UnpauseMovement(mapObject);
    Field_PlayerAvatar_OrrTransitionFlags(playerAvatar, flags);
    Field_PlayerAvatar_ApplyTransitionFlags(playerAvatar);
    task = SysTask_CreateOnMainQueue(PlayerMovementSaving_Update, work, 0xFFFF);
    GF_ASSERT(task != NULL);
    return task;
}

void Field_PlayerMovementSavingClear(SysTask *task) {
    PlayerSavingPoseWork *work;
    int state;
    PlayerAvatar *playerAvatar;
    if (task == NULL) {
        return;
    }
    work = SysTask_GetData(task);
    state = work->state;
    playerAvatar = work->playerAvatar;
    if (state == PLAYER_STATE_WALKING) {
        Field_PlayerAvatar_TransitionToWalking(playerAvatar);
    } else if (state == PLAYER_STATE_ROCKET) {
        Field_PlayerAvatar_TransitionToRocket(playerAvatar);
    } else {
        GF_ASSERT(FALSE);
        Field_PlayerAvatar_TransitionToWalking(playerAvatar);
    }
    Heap_Free(work);
    SysTask_Destroy(task);
}

static void PlayerMovementSaving_Update(SysTask *task, void *data) {
    PlayerSavingPoseWork *work = data;
    MapObject_CallDrawUpdate(PlayerAvatar_GetMapObject(work->playerAvatar));
}

static void FieldMoveAnim_Init(FieldSystem *fieldSystem, Pokemon *mon, FieldMoveAnim *anim) {
    anim->useCutIn = TRUE;
    anim->mon = mon;
    anim->gender = PlayerAvatar_GetGender(fieldSystem->playerAvatar);
}

static void FieldMoveAnim_Start(FieldSystem *fieldSystem, FieldMoveAnim *anim) {
    anim->cutIn = FieldMoveCutIn_Start(fieldSystem, FIELD_MOVE_CUT_IN_BANNER, anim->mon, anim->gender);
}

static BOOL FieldMoveAnim_CheckFinished(FieldMoveAnim *anim) {
    if (FieldMoveCutIn_IsFinished(anim->cutIn) == TRUE) {
        FieldMoveCutIn_Delete(anim->cutIn);
        return TRUE;
    }
    return FALSE;
}

static void Field_PlayerAvatar_SetSprite(PlayerAvatar *playerAvatar, u32 sprite) {
    MapObject_ChangeBillboardSprite(PlayerAvatar_GetMapObject(playerAvatar), sprite);
}

static LocalMapObject *Field_PlayerAvatar_GetFacingMapObject(PlayerAvatar *playerAvatar, int direction) {
    int x = PlayerAvatar_GetXCoord(playerAvatar);
    int dx = GetDeltaXByFacingDirection(direction);
    int z = PlayerAvatar_GetZCoord(playerAvatar);
    int dz = GetDeltaYByFacingDirection(direction);
    return MapObjectManager_GetFirstObjectWithXAndZ(MapObject_GetManager(PlayerAvatar_GetMapObject(playerAvatar)), x + dx, z + dz, FALSE);
}

static void *FieldMoveTask_AllocWork(u32 size) {
    void *work = Heap_AllocAtEnd(HEAP_ID_FIELD1, size);
    GF_ASSERT(work != NULL);
    memset(work, 0, size);
    return work;
}

static void FieldMoveTask_FreeWork(void *work) {
    Heap_FreeExplicit(HEAP_ID_FIELD1, work);
}

static Pokemon *Field_GetPartyMon(FieldSystem *fieldSystem, int partySlot) {
    return Party_GetMonByIndex(SaveArray_Party_Get(fieldSystem->saveData), partySlot);
}
