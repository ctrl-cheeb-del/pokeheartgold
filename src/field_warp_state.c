#include "field_warp_state.h"

#include "constants/movements.h"
#include "constants/pokemon.h"

#include "field/field_follow_mon.h"
#include "field/field_move_cut_in.h"

#include "field_roamer.h"
#include "field_system.h"
#include "field_warp_reset.h"
#include "field_warp_reset_suppress.h"
#include "field_warp_tasks.h"
#include "follow_mon.h"
#include "heap.h"
#include "map_header.h"
#include "map_object_movement_commands.h"
#include "overlay_01.h"
#include "overlay_02.h"
#include "party.h"
#include "player_avatar.h"
#include "pokemon.h"
#include "roamer.h"
#include "save_local_field_data.h"
#include "save_vars_flags.h"
#include "script_pokemon_util.h"
#include "sound_chatot.h"
#include "sound_playback.h"
#include "spawn_warp.h"
#include "spawn_warp_lookup_internal.h"
#include "sys_flags.h"
#include "sys_vars.h"
#include "task.h"

struct FlyTaskEnv {
    FieldSystem *fieldSystem;
    u16 state;
    u16 flag;
    u16 mapNo;
    s16 x;
    s16 y;
    u16 partySlot;
    Pokemon *mon;
    SysTask *effect;
    EventObjectMovementMan *movement;
};

enum FlyTaskState {
    FLY_TASK_WAIT_FOLLOW_MON,
    FLY_TASK_CHECK_FOLLOW_MON,
    FLY_TASK_PLAY_CRY,
    FLY_TASK_WAIT_CRY,
    FLY_TASK_START_MOVEMENT,
    FLY_TASK_START_CUT_IN,
    FLY_TASK_WARP,
};

static const MovementScriptCommand sFollowMovement[] = {
    { MOVEMENT_UNK_73,   1 },
    { 33,                1 },
    { MOVEMENT_UNK_74,   1 },
    { MOVEMENT_STEP_END, 0 },
};

struct BattleSetupSub_134 *BattleSetupSub134_New(enum HeapID heapId) {
    struct BattleSetupSub_134 *sub = Heap_Alloc(heapId, 0x24);
    MI_CpuClearFast(sub, 0x24);
    return sub;
}

void BattleSetupSub134_Delete(struct BattleSetupSub_134 *sub) {
    Heap_Free(sub);
}

void FieldSystem_SetWarpResetSuppressed(FieldSystem *fieldSystem, u8 value) {
    fieldSystem->warpResetSuppressed = value;
}

void FieldSystem_ResetStateOnMapConnection(FieldSystem *fieldSystem) {
    SaveVarsFlags *flags;
    RoamerSaveData *roamers;
    flags = Save_VarsFlags_Get(fieldSystem->saveData);
    StrengthFlagAction(flags, 0);
    FlypointFlagAction(fieldSystem, fieldSystem->location->mapId);
    roamers = Save_Roamers_Get(fieldSystem->saveData);
    RoamerSave_SetFlute(roamers, 0);
    fieldSystem->encounterInhibitSteps = 0;
    fieldSystem->reverseTurnFrameSteps = 0;
    flags = Save_VarsFlags_Get(fieldSystem->saveData);
    if (!Save_VarsFlags_CheckSafariSysFlag(flags)) {
        roamers = Save_Roamers_Get(fieldSystem->saveData);
        UpdatePlayerLocationHistoryIfAnyRoamersActive(roamers, fieldSystem->location->mapId);
        Save_UpdateRoamersLocation(roamers);
    }
}

void FieldSystem_ResetStateOnWarp(FieldSystem *fieldSystem) {
    SaveVarsFlags *flags;
    RoamerSaveData *roamers;
    PlayerSaveData *player;
    if (fieldSystem->warpResetSuppressed == 1) {
        return;
    }
    flags = Save_VarsFlags_Get(fieldSystem->saveData);
    ClearFlag972(flags);
    flags = Save_VarsFlags_Get(fieldSystem->saveData);
    StrengthFlagAction(flags, 0);
    FlypointFlagAction(fieldSystem, fieldSystem->location->mapId);
    roamers = Save_Roamers_Get(fieldSystem->saveData);
    RoamerSave_SetFlute(roamers, 0);
    fieldSystem->encounterInhibitSteps = 0;
    fieldSystem->reverseTurnFrameSteps = 0;
    roamers = Save_Roamers_Get(fieldSystem->saveData);
    UpdatePlayerLocationHistoryIfAnyRoamersActive(roamers, fieldSystem->location->mapId);
    if (!MapHeader_IsCave(fieldSystem->location->mapId)) {
        flags = Save_VarsFlags_Get(fieldSystem->saveData);
        SysFlagFlashClear(flags);
        SysFlagDefogClear(flags);
    }
    player = LocalFieldData_GetPlayer(Save_LocalFieldData_Get(fieldSystem->saveData));
    if (player->state == PLAYER_STATE_CYCLING && !MapHeader_IsBikeAllowed(fieldSystem->location->mapId)) {
        player->state = PLAYER_STATE_WALKING;
    } else if (player->state == PLAYER_STATE_SURFING) {
        player->state = PLAYER_STATE_WALKING;
    }
}

void FieldSystem_ResetStateOnFlyWarp(FieldSystem *fieldSystem) {
    Save_VarsFlags_ClearSafariSysFlag(Save_VarsFlags_Get(fieldSystem->saveData));
    Save_RandomizeRoamersLocation(Save_Roamers_Get(fieldSystem->saveData));
}

void FieldSystem_ClearSafariAndRandomizeRoamers(FieldSystem *fieldSystem) {
    Save_VarsFlags_ClearSafariSysFlag(Save_VarsFlags_Get(fieldSystem->saveData));
    Save_RandomizeRoamersLocation(Save_Roamers_Get(fieldSystem->saveData));
}

void FieldSystem_ClearSafariSysFlag(FieldSystem *fieldSystem) {
    Save_VarsFlags_ClearSafariSysFlag(Save_VarsFlags_Get(fieldSystem->saveData));
}

void FieldSystem_ClearFollowingTrainer(FieldSystem *fieldSystem) {
    SaveVarsFlags *flags = Save_VarsFlags_Get(fieldSystem->saveData);
    Save_VarsFlags_ClearHaveFollowerFlag(flags);
    Save_VarsFlags_SetFollowerTrainerNum(flags, 0);
}

void FieldSystem_RandomizeRoamers(FieldSystem *fieldSystem) {
    Save_RandomizeRoamersLocation(Save_Roamers_Get(fieldSystem->saveData));
}

struct FlyTaskEnv *FlyTaskEnv_New(enum HeapID heapId, FieldSystem *fieldSystem, Pokemon *mon, u16 partySlot, u16 mapNo, s16 x, s16 y) {
    struct FlyTaskEnv *env = Heap_AllocAtEnd(heapId, sizeof(struct FlyTaskEnv));
    memset(env, 0, sizeof(struct FlyTaskEnv));
    env->fieldSystem = fieldSystem;
    env->mon = mon;
    env->mapNo = mapNo;
    env->x = x;
    env->y = y;
    env->partySlot = partySlot;
    return env;
}

BOOL FieldTask_Fly(TaskManager *task) {
    Location warp;
    u8 kind;
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(task);
    struct FlyTaskEnv *env = TaskManager_GetEnvironment(task);
    switch (env->state) {
    case FLY_TASK_WAIT_FOLLOW_MON:
        TaskManager_Call(task, Task_WaitFollowMonMovement, NULL);
        env->state++;
        break;
    case FLY_TASK_CHECK_FOLLOW_MON: {
        int avatarState = PlayerAvatar_GetState(fieldSystem->playerAvatar);
        if (avatarState == PLAYER_STATE_CYCLING || avatarState == PLAYER_STATE_SURFING) {
            env->state = FLY_TASK_START_MOVEMENT;
            env->flag = 0;
            break;
        }
    }
        if (env->partySlot != GetIdxOfFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(fieldSystem->saveData))) {
            FollowMon_StartRecall(env->fieldSystem);
            env->state = FLY_TASK_START_MOVEMENT;
            env->flag = 0;
            break;
        }
        if (FollowMon_IsVisible(fieldSystem)) {
            if (FieldSystem_FirstAliveMonHasType(fieldSystem, TYPE_FLYING)) {
                kind = 2;
                FollowMonMood_Add(fieldSystem->followMonMood, 1);
            } else {
                kind = 1;
            }
            FollowMon_JumpOnSpot(fieldSystem, kind);
            env->flag = 1;
            env->state = FLY_TASK_PLAY_CRY;
        } else {
            env->state = FLY_TASK_START_MOVEMENT;
            env->flag = 0;
        }
        break;
    case FLY_TASK_PLAY_CRY: {
        u32 species = GetMonData(env->mon, MON_DATA_SPECIES, NULL);
        u32 form = GetMonData(env->mon, MON_DATA_FORM, NULL);
        PlayCry(species, form);
        env->state++;
        break;
    }
    case FLY_TASK_WAIT_CRY:
        if (!IsCryPlaying()) {
            env->state++;
        }
        break;
    case FLY_TASK_START_MOVEMENT:
        env->movement = EventObjectMovementMan_Create(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar), sFollowMovement);
        env->state++;
        break;
    case FLY_TASK_START_CUT_IN:
        if (EventObjectMovementMan_IsFinish(env->movement)) {
            EventObjectMovementMan_Delete(env->movement);
            if (env->flag == 0) {
                env->effect = FieldMoveCutIn_Start(env->fieldSystem, FIELD_MOVE_CUT_IN_FLY, env->mon, PlayerAvatar_GetGender(env->fieldSystem->playerAvatar));
            } else {
                env->effect = FieldMoveCutIn_Start(env->fieldSystem, FIELD_MOVE_CUT_IN_FLY_WITH_FOLLOWER, env->mon, PlayerAvatar_GetGender(env->fieldSystem->playerAvatar));
            }
            env->state++;
        }
        break;
    case FLY_TASK_WARP:
        if (FieldMoveCutIn_IsFinished(env->effect)) {
            LocalFieldData *local;
            u16 map;
            FieldMoveCutIn_Delete(env->effect);
            local = Save_LocalFieldData_Get(fieldSystem->saveData);
            map = GetSpawnIdForFlyMap(env->mapNo);
            GF_ASSERT(map != 0);
            GetFlyWarpData(map, &warp);
            GetSpecialSpawnWarpData(map, LocalFieldData_GetSpecialSpawnWarpPtr(local));
            JumpTask_FlyWarp(task, warp.mapId, -1, warp.x, warp.y, 1);
            Heap_Free(env);
        }
        break;
    }
    return FALSE;
}
