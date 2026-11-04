#include "field_transition_effects.h"

#include "constants/sndseq.h"

#include "field/fieldmap.h"
#include "field/hblank_system.h"
#include "field/map_load_manager.h"

#include "camera.h"
#include "field_bgm.h"
#include "field_warp_tasks.h"
#include "follow_mon.h"
#include "heap.h"
#include "map_header.h"
#include "map_preview_graphic.h"
#include "metatile_behavior.h"
#include "overlay_01.h"
#include "field/door_transition.h"
#include "player_avatar_actions.h"
#include "field_follow_mon_ball.h"
#include "field/field_follow_mon.h"
#include "player_avatar.h"
#include "save_follow_mon.h"
#include "script.h"
#include "sound.h"
#include "sound_playback.h"
#include "field_terrain.h"
#include "field_overworld_transition.h"
#include "field_overworld_restore.h"
#include "field_transition_tasks.h"
#include "map_object_movement_commands.h"

typedef void (*FieldSystemFunc)(FieldSystem *);

BOOL Task_FieldTransition(TaskManager *man);
BOOL RoutineFieldFade(TaskManager *man);

// All three tables are indexed by FieldTransitionEnvironment.transitionNo.
static const TaskFunc sMapExitRoutines[] = {
    FieldTransition_ExitWithFade,
    FieldTransition_ExitThroughDoor,
    FieldTransition_ExitThroughSideDoor,
    FieldTransition_ExitOnWarpStairs,
    FieldTransition_ExitStairsFadeOut,
    FieldTransition_ExitStairsFadeToWhite,
    FieldTransition_ExitWithFade,
    FieldTransition_ExitRising,
    FieldTransition_ExitSinking,
};

static const TaskFunc sMapEnterRoutines[] = {
    FieldTransition_EnterWithDirectionalFade,
    FieldTransition_EnterWithFade,
    FieldTransition_EnterThroughSideDoor,
    FieldTransition_EnterFromWarpStairs,
    FieldTransition_EnterWithFade,
    FieldTransition_EnterWithDoorExit,
    FieldTransition_EnterWithFade,
    FieldTransition_EnterRising,
    FieldTransition_EnterSinking,
};

// Places the player and camera before the enter routine runs, where the transition needs it.
static const FieldSystemFunc sMapEnterPlacementRoutines[] = {
    NULL,
    NULL,
    FieldTransition_PlaceInsideSideDoor,
    FieldTransition_PlaceOffWarpStairs,
    NULL,
    NULL,
    NULL,
    FieldTransition_PlaceBelowFloor,
    FieldTransition_PlaceAboveFloor,
};

void NewFieldFadeEnvironment(TaskManager *man, enum FadeMode fadeMode, enum FadeType typeTop, enum FadeType typeBottom, u16 colour, int duration, int framesPer, enum HeapID heapID) {
    FieldFadeEnvironment *sfenv = Heap_Alloc(heapID, sizeof(FieldFadeEnvironment));
    sfenv->fadeMode = fadeMode;
    sfenv->typeTop = typeTop;
    sfenv->typeBottom = typeBottom;
    sfenv->colour = colour;
    sfenv->duration = duration;
    sfenv->framesPer = framesPer;
    sfenv->heapID = heapID;
    sfenv->state = 0;
    TaskManager_Call(man, RoutineFieldFade, sfenv);
}

BOOL RoutineFieldFade(TaskManager *man) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(man);
    FieldFadeEnvironment *fenv = TaskManager_GetEnvironment(man);
    switch (fenv->state) {
    case 0:
        HBlankSystem_Stop(fieldSystem->mapSystems->hBlankSystem);
        BeginNormalPaletteFade(fenv->fadeMode, fenv->typeTop, fenv->typeBottom, fenv->colour, fenv->duration, fenv->framesPer, fenv->heapID);
        fenv->state++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            HBlankSystem_Start(fieldSystem->mapSystems->hBlankSystem);
            Heap_Free(fenv);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

void NewFieldTransitionEnvironment(FieldSystem *fieldSystem, int mapID, int warpID, int x, int y, int dir, u32 transNo) {
    FieldTransitionEnvironment *fenv = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(FieldTransitionEnvironment));
    fenv->state = 0;
    fenv->transitionState = 0;
    fenv->delayTimer = 0;
    fenv->location.mapId = mapID;
    fenv->location.warpId = warpID;
    fenv->location.x = x;
    fenv->location.y = y;
    fenv->location.direction = dir;
    fenv->transitionNo = transNo;
    FieldSystem_CreateTask(fieldSystem, Task_FieldTransition, fenv);
}

void NewFieldTransitionEnvironmentByMapType(FieldSystem *fieldSystem, int mapID, int warpID, int x, int y, int dir) {
    FieldTransitionEnvironment *fenv = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(FieldTransitionEnvironment));
    fenv->state = 0;
    fenv->transitionState = 0;
    fenv->delayTimer = 0;
    fenv->location.mapId = mapID;
    fenv->location.warpId = warpID;
    fenv->location.x = x;
    fenv->location.y = y;
    fenv->location.direction = dir;
    int var = 0;
    int otherID = fieldSystem->location->mapId;
    if (MapHeader_IsCave(otherID)) {
        if (MapHeader_IsCave(mapID)) {
            var = 6;
        } else {
            if (MapHeader_IsOutdoors(mapID)) {
                var = 5;
            } else if (MapHeader_IsInBuilding(mapID)) {
                var = 6;
            } else {
                GF_ASSERT(FALSE);
            }
        }
    } else {
        if (MapHeader_IsOutdoors(otherID)) {
            if (MapHeader_IsCave(mapID)) {
                var = 4;
            } else if (MapHeader_IsInBuilding(mapID)) {
                var = 6;
            } else {
                GF_ASSERT(FALSE);
            }
        } else if (MapHeader_IsInBuilding(otherID)) {
            if (!MapHeader_IsOutdoors(mapID)) {
                if (MapHeader_IsInBuilding(mapID)) {
                    var = 6;
                } else if (!MapHeader_IsCave(mapID)) {
                    GF_ASSERT(FALSE);
                }
            }
        } else {
            GF_ASSERT(FALSE);
        }
    }
    fenv->transitionNo = var;
    FieldSystem_CreateTask(fieldSystem, Task_FieldTransition, fenv);
}

// this function handles transition routines between maps
BOOL Task_FieldTransition(TaskManager *man) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(man);
    FieldTransitionEnvironment *env = TaskManager_GetEnvironment(man);
    switch (env->state) {
    case 0:
        env->transitionState = 0;
        env->followMonBall = NULL;
        env->delayTimer = 0;
        if (FollowMon_IsActive(fieldSystem) && FollowMon_CheckVisibleFlag(fieldSystem) && PlayerAvatar_GetState(fieldSystem->playerAvatar) != PLAYER_STATE_CYCLING) {
            env->state = 9;
            break;
        }
    case 1:
        if (FollowMon_IsActive(fieldSystem) && !FollowMon_CheckVisibleFlag(fieldSystem) && PlayerAvatar_GetState(fieldSystem->playerAvatar) != PLAYER_STATE_CYCLING) {
            LocalMapObject *followMon = FollowMon_GetMapObject(fieldSystem);
            int species = FollowMon_GetSpecies(followMon);
            if (!FollowMon_GetPermissionBySpeciesAndMap(species, env->location.mapId)) {
                env->followMonBall = FollowMonBall_Spawn(followMon, FOLLOW_MON_BALL_RECALL_WHITE);
            }
        }
        env->state++;
        break;
    case 2:
        if (env->followMonBall && FieldEffect_IsActive(env->followMonBall)) {
            break;
        }
        FieldBGM_TryFadeIn(fieldSystem, env->location.mapId);
        TaskManager_Call(man, sMapExitRoutines[env->transitionNo], env);
        if (FollowMon_IsActive(fieldSystem) && FollowMon_CheckVisibleFlag(fieldSystem) && !FollowMon_GetPermission(fieldSystem)) {
            FollowMon_SetNoBallEffect(fieldSystem);
        }
        Save_FollowMon_SetMapID(fieldSystem->location->mapId, Save_FollowMon_Get(fieldSystem->saveData));
        env->destinationMapID = fieldSystem->location->mapId;
        env->state++;
        break;
    case 3:
        CallTask_LeaveOverworld(man);
        env->state++;
        break;
    case 4:
        CallTask_ChangeMap(man, &env->location);
        env->state++;
        break;
    case 5:
        CallTask_RestoreOverworld(man);
        env->state++;
        break;
    case 6:
        if (sMapEnterPlacementRoutines[env->transitionNo]) {
            Camera_SetHistoryEnabled(fieldSystem->camera, 0);
            sMapEnterPlacementRoutines[env->transitionNo](fieldSystem);
        }
        env->state++;
        break;
    case 7:
        if (GF_SndGetFadeTimer() == 0) {
            FieldBGM_PlayForMapHeader(fieldSystem, env->location.mapId, TRUE);
            if (!MapHeader_IsCave(env->destinationMapID)) {                  // this has gotta be for the pre-entering images right?
                int index = MapPreviewGraphic_GetIndex(env->location.mapId); // this gets the index of the location in the list of maps that have map icons
                if (index != 255) {
                    int parity = 0;
                    if (env->transitionNo == 8) {
                        parity = 1;
                    }
                    TIMEOFDAY time = GF_RTC_GetTimeOfDay();
                    MapPreviewGraphic_BeginShowImage(man, index, time, parity); // this should set the specific map icon based on time?
                    env->state++;
                    FieldSystem_DrawMapNameAnimation(fieldSystem);
                    break;
                }
            }
            FieldSystem_DrawMapNameAnimation(fieldSystem);
            env->transitionState = 0;
            TaskManager_Call(man, sMapEnterRoutines[env->transitionNo], env);
            LocalMapObject *followerMon = FollowMon_GetMapObject(fieldSystem);
            if (FollowMon_IsActive(fieldSystem) && !FollowMon_GetPermission(fieldSystem)) {
                FollowMon_SetReleaseBallPending(followerMon, 1);
                FollowMon_MoveToPlayer(fieldSystem, (u8)PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar));
            }
            env->state++;
            break;
        }
        break;
    case 8:
        Camera_SetHistoryEnabled(fieldSystem->camera, 1);
        Heap_Free(env);
        return TRUE;
    case 9:
        env->delayTimer++;
        if (env->delayTimer >= 2) {
            env->state = 1;
        }
        break;
    }
    return FALSE;
}

BOOL FieldTransition_ExitWithFade(TaskManager *man) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(man);
    FieldTransitionEnvironment *fenv = TaskManager_GetEnvironment(man);
    switch (fenv->transitionState) {
    case 0:
        PlaySE(SEQ_SE_DP_KAIDAN2);
        PaletteFadeUntilFinished(man);
        fenv->transitionState++;
        break;
    case 1:
        return TRUE;
    }
    return FALSE;
}

BOOL FieldTransition_ExitThroughDoor(TaskManager *man) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(man);
    FieldTransitionEnvironment *fenv = TaskManager_GetEnvironment(man);
    switch (fenv->transitionState) {
    case 0:
        fenv->transitionWork = DoorTransition_New();
        DoorTransition_SetPosition(PlayerAvatar_GetXCoord(fieldSystem->playerAvatar), PlayerAvatar_GetZCoord(fieldSystem->playerAvatar), fenv->transitionWork);
        fenv->transitionState++;
        break;
    case 1:
        if (DoorTransition_WalkIntoDoor(fieldSystem, fenv->transitionWork)) {
            DoorTransition_Free(fenv->transitionWork);
            fenv->transitionState++;
        }
        break;
    case 2:
        PaletteFadeUntilFinished(man);
        fenv->transitionState++;
        break;
    case 3:
        return TRUE;
    }
    return FALSE;
}

BOOL FieldTransition_ExitThroughSideDoor(TaskManager *man) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(man);
    FieldTransitionEnvironment *fenv = TaskManager_GetEnvironment(man);
    switch (fenv->transitionState) {
    case 0:
        fenv->transitionWork = DoorTransition_New();
        DoorTransition_SetPosition(PlayerAvatar_GetXCoord(fieldSystem->playerAvatar), PlayerAvatar_GetZCoord(fieldSystem->playerAvatar), fenv->transitionWork);
        fenv->transitionState++;
        break;
    case 1: {
        FieldTransitionWork *info = fenv->transitionWork;
        if (DoorTransition_WalkIntoSideDoor(fieldSystem, info, PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar))) {
            DoorTransition_Free(fenv->transitionWork);
            fenv->transitionState++;
        }
        break;
    }
    case 2:
        return TRUE;
    }
    return FALSE;
}

BOOL FieldTransition_ExitOnWarpStairs(TaskManager *man) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(man);
    FieldTransitionEnvironment *fenv = TaskManager_GetEnvironment(man);
    LocalMapObject *obj;
    switch (fenv->transitionState) {
    case 0:
        if (FollowMon_IsActive(fieldSystem) && FollowMon_IsVisible(fieldSystem)) {
            if (MapObject_IsMovementPaused(FollowMon_GetMapObject(fieldSystem))) {
                MapObject_ChangeMovement(FollowMon_GetMapObject(fieldSystem), 55);
                fenv->transitionState++;
            }
        } else {
            fenv->transitionState++;
        }
        break;
    case 1: {
        int dir = PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar);
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (dir == DIR_WEST) {
            MapObject_SetHeldMovement(obj, 10);
        } else if (dir == DIR_EAST) {
            MapObject_SetHeldMovement(obj, 11);
        } else {
            GF_ASSERT(FALSE);
        }
        fenv->transitionState++;
        break;
    }
    case 2: {
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_IsMovementPaused(obj) == TRUE) {
            MapObject_ClearHeldMovementIfActive(obj);
            fenv->transitionState++;
        }
        break;
    }
    case 3:
        PlaySE(SEQ_SE_DP_KAIDAN2);
        FieldMap_FadeScreen(FADE_TYPE_BRIGHTNESS_OUT);
        fenv->transitionState++;
        break;
    case 4:
        if (IsPaletteFadeFinished()) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL FieldTransition_ExitStairsFadeOut(TaskManager *man) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(man);
    FieldTransitionEnvironment *fenv = TaskManager_GetEnvironment(man);
    PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    switch (fenv->transitionState) {
    case 0:
        TaskManager_Call(man, Task_StairsFadeOut, DoorTransition_NewTaskWork());
        fenv->transitionState++;
        break;
    case 1:
        return TRUE;
    }
    return FALSE;
}

BOOL FieldTransition_ExitStairsFadeToWhite(TaskManager *man) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(man);
    FieldTransitionEnvironment *fenv = TaskManager_GetEnvironment(man);
    PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    switch (fenv->transitionState) {
    case 0:
        TaskManager_Call(man, Task_StairsFadeToWhite, DoorTransition_NewTaskWork());
        fenv->transitionState++;
        break;
    case 1:
        return TRUE;
    }
    return FALSE;
}

BOOL FieldTransition_ExitRising(TaskManager *man) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(man);
    FieldTransitionEnvironment *fenv = TaskManager_GetEnvironment(man);
    LocalMapObject *obj;
    FieldTransitionWork *fenv18;
    switch (fenv->transitionState) {
    case 0:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        MapObject_ClearHeldMovementIfActive(obj);
        Field_PlayerAvatar_OrrTransitionFlags(fieldSystem->playerAvatar, 512);
        Field_PlayerAvatar_ApplyTransitionFlags(fieldSystem->playerAvatar);
        MapObject_SetAnimation(obj, 0);
        fenv->transitionWork = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(FieldTransitionWork));
        fenv18 = fenv->transitionWork;
        fenv18->state = 0;
        fenv18->direction = PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar);
        PlayerAvatar_ToggleAutomaticHeightUpdating(fieldSystem->playerAvatar, FALSE);
        MapLoadManager_ForgetTrackedTarget(fieldSystem->mapLoadManager);
        if (FollowMon_IsActive(fieldSystem)) {
            BOOL flag = TRUE;
            int var;
            switch (MapObject_GetFacingDirection(FollowMon_GetMapObject(fieldSystem))) {
            case DIR_NORTH:
                var = 12;
                break;
            case DIR_SOUTH:
                var = 13;
                break;
            case DIR_WEST:
                var = 14;
                break;
            case DIR_EAST:
                var = 15;
                break;
            default:
                GF_ASSERT(FALSE);
                flag = FALSE;
                break;
            }
            if (flag) {
                FollowMon_QueuePlayerStep(var, MapObject_GetPreviousXCoord(obj), MapObject_GetPreviousZCoord(obj), &fieldSystem->followMon);
            }
        }
        fenv->transitionState++;
        break;
    case 1:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        VecFx32 pos;
        fenv18 = fenv->transitionWork;
        u32 state = fenv18->state;
        fenv18->state++;
        MapObject_CopyPositionVector(obj, &pos);
        if (fenv18->direction == DIR_SOUTH) { // Ladders
            pos.y += 2048;
            pos.z -= 6144;
        } else {
            pos.y += 8192;
        }
        MapObject_SetPositionVector(obj, &pos);
        if (fenv18->state >= 16) {
            fenv->transitionState++;
        }
        break;
    case 2:
        PlaySE(SEQ_SE_DP_KAIDAN2);
        FieldMap_FadeScreen(FADE_TYPE_BRIGHTNESS_OUT);
        fenv->transitionState++;
        break;
    case 3:
        if (IsPaletteFadeFinished()) {
            PlayerAvatar_ToggleAutomaticHeightUpdatingImmediate(fieldSystem->playerAvatar, TRUE);
            Heap_Free(fenv->transitionWork);
            return TRUE;
        }
    }
    return FALSE;
}

BOOL FieldTransition_ExitSinking(TaskManager *man) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(man);
    FieldTransitionEnvironment *fenv = TaskManager_GetEnvironment(man);
    LocalMapObject *obj;
    FieldTransitionWork *fenv18;
    switch (fenv->transitionState) {
    case 0:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_AreBitsSetForMovementScriptInit(obj)) {
            MapObject_SetHeldMovement(obj, 0);
            fenv->transitionState++;
        }
        break;
    case 1:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_AreBitsSetForMovementScriptInit(obj)) {
            MapObject_ClearHeldMovementIfActive(obj);
            Field_PlayerAvatar_OrrTransitionFlags(fieldSystem->playerAvatar, 512);
            Field_PlayerAvatar_ApplyTransitionFlags(fieldSystem->playerAvatar);
            MapObject_SetAnimation(obj, 0);
            fenv->transitionWork = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(FieldTransitionWork));
            fenv->transitionWork->state = 0;
            PlayerAvatar_ToggleAutomaticHeightUpdating(fieldSystem->playerAvatar, FALSE);
            fenv->transitionState++;
        }
        break;
    case 2:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        fenv18 = fenv->transitionWork;
        fenv18->state++;
        VecFx32 pos;
        MapObject_CopyPositionVector(obj, &pos);
        pos.y -= 8192;
        MapObject_SetPositionVector(obj, &pos);
        if (fenv18->state >= 16) {
            fenv->transitionState++;
        }
        break;
    case 3:
        PlaySE(SEQ_SE_DP_KAIDAN2);
        FieldMap_FadeScreen(FADE_TYPE_BRIGHTNESS_OUT);
        fenv->transitionState++;
        break;
    case 4:
        if (IsPaletteFadeFinished()) {
            PlayerAvatar_ToggleAutomaticHeightUpdatingImmediate(fieldSystem->playerAvatar, TRUE);
            Heap_Free(fenv->transitionWork);
            return TRUE;
        }
    }
    return FALSE;
}

BOOL FieldTransition_EnterWithDirectionalFade(TaskManager *man) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(man);
    FieldTransitionEnvironment *fenv = TaskManager_GetEnvironment(man);
    LocalMapObject *obj;
    switch (fenv->transitionState) {
    case 0:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MetatileBehavior_IsDoor(GetMetatileBehavior(fieldSystem, PlayerAvatar_GetXCoord(fieldSystem->playerAvatar), PlayerAvatar_GetZCoord(fieldSystem->playerAvatar)))) {
            MapObject_SetInvisible(obj, TRUE);
            fenv->transitionState = 1;
            break;
        }
        TaskManager_Call(man, Task_ArriveWithDirectionalFade, DoorTransition_NewTaskWork());
        fenv->transitionState = 3;
        break;
    case 1:
        fenv->transitionWork = DoorTransition_New();
        DoorTransition_SetPosition(PlayerAvatar_GetXCoord(fieldSystem->playerAvatar), PlayerAvatar_GetZCoord(fieldSystem->playerAvatar), fenv->transitionWork);
        fenv->transitionState++;
        break;
    case 2: {
        FieldTransitionWork *unk = fenv->transitionWork;
        if (DoorTransition_WalkOutOfDoor(fieldSystem, unk)) {
            DoorTransition_Free(unk);
            MapObject_SetInvisible(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar), FALSE);
            return TRUE;
        }
        break;
    }
    case 3:
        return TRUE;
    }
    return FALSE;
}

BOOL FieldTransition_EnterWithFade(TaskManager *man) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(man);
    FieldTransitionEnvironment *fenv = TaskManager_GetEnvironment(man);
    switch (fenv->transitionState) {
    case 0: {
        LocalMapObject *mapObj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MetatileBehavior_IsDoor(GetMetatileBehavior(fieldSystem, PlayerAvatar_GetXCoord(fieldSystem->playerAvatar), PlayerAvatar_GetZCoord(fieldSystem->playerAvatar)))) {
            MapObject_SetInvisible(mapObj, TRUE);
            fenv->transitionState = 1;
            TaskManager_Jump(man, FieldTransition_EnterWithDirectionalFade, fenv);
            break;
        } else {
            TaskManager_Call(man, Task_ArriveWithFade, DoorTransition_NewTaskWork());
            fenv->transitionState++;
            break;
        }
    }
    case 1:
        return TRUE;
    }
    return FALSE;
}
