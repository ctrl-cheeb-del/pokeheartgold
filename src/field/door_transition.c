#include "field/door_transition.h"

#include "global.h"

#include "constants/buildmodel.h"
#include "constants/movements.h"
#include "constants/sndseq.h"

#include "field/area_data.h"
#include "field/field_follow_mon.h"
#include "field/fieldmap.h"
#include "field/map_prop.h"
#include "field/map_prop_animation.h"

#include "camera.h"
#include "camera_translation.h"
#include "field_metatile_query_internal.h"
#include "field_terrain.h"
#include "field_transition_effects.h"
#include "follow_mon.h"
#include "heap.h"
#include "map_header.h"
#include "map_object.h"
#include "map_object_movement_commands.h"
#include "overlay_01.h"
#include "player_avatar.h"
#include "screen_fade.h"
#include "sound_playback.h"

// Door prop slot used by the one-shot animation manager for front doors and for side doors.
#define DOOR_ANIM_TAG      1
#define SIDE_DOOR_ANIM_TAG 2

enum WalkIntoDoorState {
    WALK_INTO_DOOR_STATE_LOAD,
    WALK_INTO_DOOR_STATE_OPEN,
    WALK_INTO_DOOR_STATE_WAIT_OPEN,
    WALK_INTO_DOOR_STATE_STEP_IN,
    WALK_INTO_DOOR_STATE_WAIT_STEP,
    WALK_INTO_DOOR_STATE_END,
    WALK_INTO_DOOR_STATE_CAMERA_PAN = 100,
    WALK_INTO_DOOR_STATE_WAIT_CAMERA_PAN,
};

enum WalkOutOfDoorState {
    WALK_OUT_OF_DOOR_STATE_LOAD,
    WALK_OUT_OF_DOOR_STATE_OPEN,
    WALK_OUT_OF_DOOR_STATE_WAIT_OPEN,
    WALK_OUT_OF_DOOR_STATE_STEP_OUT,
    WALK_OUT_OF_DOOR_STATE_WAIT_STEP,
    WALK_OUT_OF_DOOR_STATE_WAIT_CLOSE,
    WALK_OUT_OF_DOOR_STATE_WAIT_FADE,
};

enum ArriveState {
    ARRIVE_STATE_INIT,
    ARRIVE_STATE_STEP_OUT,
    ARRIVE_STATE_WAIT_STEP,
    ARRIVE_STATE_WAIT_FADE,
    ARRIVE_STATE_OPEN_DOOR,
    ARRIVE_STATE_WAIT_DOOR_OPEN,
    ARRIVE_STATE_STEP_OUT_OF_DOOR,
    ARRIVE_STATE_WAIT_STEP_OUT_OF_DOOR,
    ARRIVE_STATE_WAIT_DOOR_CLOSE,
};

enum StairsFadeState {
    STAIRS_FADE_STATE_START,
    STAIRS_FADE_STATE_WAIT,
};

typedef struct DoorTransitionWork {
    int state;
    int x;
    int z;
    u8 animTag;
    u8 cameraStep;
    u16 cameraAngle;
    BOOL adjustCamera;
    u32 unk_14;
    GFCameraTranslationWrapper *translation;
    u16 translationDone;
    u16 cameraPathIndex;
} DoorTransitionWork;

typedef struct DoorTransitionTaskWork {
    u8 state;
    u8 cameraStep;
    u16 cameraAngle;
    BOOL adjustCamera;
} DoorTransitionTaskWork;

// A nonzero door type marks a prop as a door and selects its sound effects.
typedef struct DoorAnimListEntry {
    u32 unk_00;
    u8 doorType;
    u8 padding_05[0x13];
} DoorAnimListEntry;

typedef struct DoorModelList {
    int ids[4];
} DoorModelList;

static const DoorModelList sSideDoorEntryModels = {
    .ids = { BUILD_MODEL_EN_H01A, BUILD_MODEL_EN_DOOR1, BUILD_MODEL_EN_H01B, BUILD_MODEL_EN_DOOR2 },
};

static const DoorModelList sSideDoorExitModels = {
    .ids = { BUILD_MODEL_EN_H01A, BUILD_MODEL_EN_DOOR1, BUILD_MODEL_EN_H01B, BUILD_MODEL_EN_DOOR2 },
};

static const CameraTranslationPathTemplate sDoorCameraPaths[2] = {
    {
     .angleX = 0xE882,
     .perspectiveAngle = 0x5C1,
     .position = { 0, FX32_CONST(93.297607421875), -FX32_CONST(35.983642578125) },
     .distance = FX32_CONST(666.922119140625),
     },
    {
     .angleX = 0xE262,
     .perspectiveAngle = 0x5C1,
     .position = { 0, FX32_CONST(82.037841796875), -FX32_CONST(57.25927734375) },
     .distance = FX32_CONST(711.922119140625),
     },
};

static void DoorTransition_StepCameraZoomIn(Camera *camera, u8 *step);
static void DoorTransition_StepCameraZoomOut(Camera *camera, u8 *step);
static int GetDoorSE(FieldSystem *fieldSystem, int modelId, BOOL opening);
static int DoorTransition_GetCameraPathIndex(int modelId);
static BOOL Task_WaitDoorAnimation(TaskManager *taskman);
static BOOL DoorTransition_ModelSkipsCameraZoom(FieldSystem *fieldSystem, int modelId);

FieldTransitionWork *DoorTransition_New(void) {
    DoorTransitionWork *work = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(DoorTransitionWork));
    work->state = 0;
    work->translationDone = 0;
    return (FieldTransitionWork *)work;
}

void DoorTransition_Free(FieldTransitionWork *work) {
    Heap_Free(work);
}

void DoorTransition_SetPosition(u32 x, u32 z, FieldTransitionWork *arg) {
    DoorTransitionWork *work = (DoorTransitionWork *)arg;
    work->x = x;
    work->z = z;
}

BOOL DoorTransition_WalkIntoDoor(FieldSystem *fieldSystem, FieldTransitionWork *arg) {
    DoorTransitionWork *work = (DoorTransitionWork *)arg;
    fx32 rect[4];
    DoorAnimListEntry entry;
    MapProp *prop;
    BOOL found;
    int modelId0;
    NARC *narc;
    int *props;

    int animationCount;
    NNSG3dResTex *texture;
    NNSG3dRenderObj *renderObj;
    NNSG3dResMdl *model;
    int i;

    switch (work->state) {
    case WALK_INTO_DOOR_STATE_LOAD:
        work->adjustCamera = FALSE;
        work->cameraStep = 0;
        Terrain_MakeTileRect(work->x, work->z, -1, -1, 3, 1, rect);
        work->animTag = DOOR_ANIM_TAG;
        found = FALSE;
        narc = AreaDataManager_GetMapPropAnimListNarc(fieldSystem->areaDataManager);
        props = FieldSystem_CollectMapPropModelsInRect(fieldSystem, HEAP_ID_FIELD1, 4, rect, 0);
        for (i = 0; i < 4; i++) {
            if (props[i] != 0) {
                NARC_ReadWholeMember(narc, props[i], &entry);
                if (entry.doorType != 0) {
                    FieldSystem_FindMapPropInRect(fieldSystem, props[i], rect, &prop);
                    found = TRUE;
                    modelId0 = props[i];
                    break;
                }
            }
        }
        Heap_Free(props);
        if (found) {
            animationCount = MapPropAnimationManager_GetPropAnimationCount(fieldSystem->mapPropAnimationManager, modelId0);
            if (animationCount == 0) {
                return TRUE;
            }
            texture = AreaDataManager_GetMapPropTexture(fieldSystem->areaDataManager);
            renderObj = MapProp_GetRenderSurface(prop);
            model = MapProp_GetResModel(prop);
            MapPropOneShotAnimationManager_LoadPropAnimations(fieldSystem->mapPropAnimationManager, fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG, modelId0, renderObj, model, texture, animationCount, 1, FALSE);
            MapPropOneShotAnimationManager_SetAnimationField35(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG, 1);
        } else {
            return TRUE;
        }
        work->cameraPathIndex = DoorTransition_GetCameraPathIndex(modelId0);
        if (work->cameraPathIndex != 0xFFFF) {
            work->state = WALK_INTO_DOOR_STATE_CAMERA_PAN;
        } else {
            work->state++;
        }
        break;
    case WALK_INTO_DOOR_STATE_OPEN: {
        int modelId;
        modelId = MapPropOneShotAnimationManager_GetAnimationMapPropModelID(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG);
        if (!DoorTransition_ModelSkipsCameraZoom(fieldSystem, modelId)) {
            Camera_ClearFixedTarget(fieldSystem->camera);
            work->adjustCamera = TRUE;
        }
        MapPropOneShotAnimationManager_PlayAnimationWithSoundEffect(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG, 0, GetDoorSE(fieldSystem, modelId, TRUE));
        work->state++;
        break;
    }
    case WALK_INTO_DOOR_STATE_WAIT_OPEN:
        if (MapPropOneShotAnimationManager_IsAnimationLoopFinished(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG)) {
            work->state++;
        }
        break;
    case WALK_INTO_DOOR_STATE_STEP_IN: {
        LocalMapObject *obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        MapObject_SetHeldMovement(obj, MOVEMENT_STEP_UP);
        if (FollowMon_IsActive(fieldSystem) && !FollowMon_CheckVisibleFlag(fieldSystem)) {
            int x = MapObject_GetPreviousXCoord(obj);
            int z = MapObject_GetPreviousZCoord(obj);
            FollowMon_QueuePlayerStep(MOVEMENT_STEP_UP, x, z, &fieldSystem->followMon);
        }
        work->state++;
        break;
    }
    case WALK_INTO_DOOR_STATE_WAIT_STEP: {
        LocalMapObject *obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_IsMovementPaused(obj) == TRUE) {
            if (FollowMon_IsActive(fieldSystem)) {
                LocalMapObject *mon = FollowMon_GetMapObject(fieldSystem);
                if (MapObject_IsMovementPaused(mon) != TRUE) {
                    break;
                }
                MapObject_ClearHeldMovementIfActive(obj);
                MapObject_ClearHeldMovementIfActive(mon);
                work->state++;
            } else {
                work->state++;
            }
        }
        break;
    }
    case WALK_INTO_DOOR_STATE_END:
        MapObject_SetInvisible(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar), TRUE);
        return TRUE;
    case WALK_INTO_DOOR_STATE_CAMERA_PAN: {
        Camera_SetPerspectiveClippingPlane(FX32_CONST(150), FX32_CONST(1110), fieldSystem->camera);
        work->translation = CreateCameraTranslationWrapper(HEAP_ID_FIELD1, fieldSystem->camera);
        SetCameraTranslationPath(work->translation, (CameraTranslationPathTemplate *)&sDoorCameraPaths[work->cameraPathIndex], 24);
        work->state++;
        break;
    }
    case WALK_INTO_DOOR_STATE_WAIT_CAMERA_PAN:
        if (IsCameraTranslationFinished(work->translation)) {
            DeleteCameraTranslationWrapper(work->translation);
            work->translationDone = 1;
            work->state = WALK_INTO_DOOR_STATE_OPEN;
        }
        break;
    }
    if (work->adjustCamera && !work->translationDone) {
        DoorTransition_StepCameraZoomIn(fieldSystem->camera, &work->cameraStep);
    }
    return FALSE;
}

BOOL DoorTransition_WalkOutOfDoor(FieldSystem *fieldSystem, FieldTransitionWork *arg) {
    DoorTransitionWork *work = (DoorTransitionWork *)arg;
    fx32 rect[4];
    DoorAnimListEntry entry;
    MapProp *prop;
    BOOL found;
    int modelId0;
    NARC *narc;
    int *props;
    int zero;
    int animationCount;
    NNSG3dResTex *texture;
    NNSG3dRenderObj *renderObj;
    NNSG3dResMdl *model;
    int i;

    switch (work->state) {
    case WALK_OUT_OF_DOOR_STATE_LOAD:
        zero = FALSE;
        work->adjustCamera = zero;
        work->cameraStep = zero;
        Terrain_MakeTileRect(work->x, work->z, -1, 0, 3, 1, rect);
        work->animTag = DOOR_ANIM_TAG;
        found = FALSE;
        narc = AreaDataManager_GetMapPropAnimListNarc(fieldSystem->areaDataManager);
        props = FieldSystem_CollectMapPropModelsInRect(fieldSystem, HEAP_ID_FIELD1, 4, rect, 0);
        for (i = 0; i < 4; i++) {
            if (props[i] != 0) {
                NARC_ReadWholeMember(narc, props[i], &entry);
                if (entry.doorType != 0) {
                    FieldSystem_FindMapPropInRect(fieldSystem, props[i], rect, &prop);
                    found = TRUE;
                    modelId0 = props[i];
                    break;
                }
            }
        }
        Heap_Free(props);
        if (found) {
            animationCount = MapPropAnimationManager_GetPropAnimationCount(fieldSystem->mapPropAnimationManager, modelId0);
            if (animationCount == 0) {
                FieldMap_FadeScreen(FADE_TYPE_BRIGHTNESS_IN);
                work->state = WALK_OUT_OF_DOOR_STATE_WAIT_FADE;
                return FALSE;
            }
            texture = AreaDataManager_GetMapPropTexture(fieldSystem->areaDataManager);
            renderObj = MapProp_GetRenderSurface(prop);
            model = MapProp_GetResModel(prop);
            MapPropOneShotAnimationManager_LoadPropAnimations(fieldSystem->mapPropAnimationManager, fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG, modelId0, renderObj, model, texture, animationCount, 1, FALSE);
        } else {
            FieldMap_FadeScreen(FADE_TYPE_BRIGHTNESS_IN);
            work->state = WALK_OUT_OF_DOOR_STATE_WAIT_FADE;
            return FALSE;
        }
        work->cameraAngle = Camera_GetPerspectiveAngle(fieldSystem->camera);
        if (!DoorTransition_ModelSkipsCameraZoom(fieldSystem, modelId0)) {
            Camera_AdjustPerspectiveAngle(-96, fieldSystem->camera);
        }
        work->state++;
        break;
    case WALK_OUT_OF_DOOR_STATE_OPEN: {
        int modelId;
        NewFieldFadeEnvironment(fieldSystem->taskman, FADE_BOTH_SCREENS, FADE_TYPE_UNK_9, FADE_TYPE_BRIGHTNESS_IN, 0, 6, 1, HEAP_ID_FIELD2);
        modelId = MapPropOneShotAnimationManager_GetAnimationMapPropModelID(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG);
        if (!DoorTransition_ModelSkipsCameraZoom(fieldSystem, modelId)) {
            work->adjustCamera = TRUE;
        }
        MapPropOneShotAnimationManager_PlayAnimationWithSoundEffect(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG, 0, GetDoorSE(fieldSystem, modelId, TRUE));
        work->state++;
        break;
    }
    case WALK_OUT_OF_DOOR_STATE_WAIT_OPEN:
        if (MapPropOneShotAnimationManager_IsAnimationLoopFinished(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG)) {
            MapObject_SetInvisible(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar), FALSE);
            work->state++;
        }
        break;
    case WALK_OUT_OF_DOOR_STATE_STEP_OUT:
        MapObject_SetHeldMovement(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar), MOVEMENT_STEP_DOWN);
        work->state++;
        break;
    case WALK_OUT_OF_DOOR_STATE_WAIT_STEP: {
        int modelId;
        LocalMapObject *obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_IsMovementPaused(obj) == TRUE) {
            MapObject_ClearHeldMovementIfActive(obj);
            FollowMon_MoveToPlayer(fieldSystem, DIR_SOUTH);
            modelId = MapPropOneShotAnimationManager_GetAnimationMapPropModelID(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG);
            MapPropOneShotAnimationManager_PlayAnimationWithSoundEffect(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG, 1, GetDoorSE(fieldSystem, modelId, FALSE));
            work->state++;
        }
        break;
    }
    case WALK_OUT_OF_DOOR_STATE_WAIT_CLOSE:
        if (MapPropOneShotAnimationManager_IsAnimationLoopFinished(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG) && IsPaletteFadeFinished() && work->cameraAngle == Camera_GetPerspectiveAngle(fieldSystem->camera)) {
            MapPropOneShotAnimationManager_UnloadAnimation(fieldSystem->mapPropAnimationManager, fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG);
            return TRUE;
        }
        break;
    case WALK_OUT_OF_DOOR_STATE_WAIT_FADE:
        if (IsPaletteFadeFinished()) {
            return TRUE;
        }
        break;
    }
    if (work->adjustCamera) {
        DoorTransition_StepCameraZoomOut(fieldSystem->camera, &work->cameraStep);
    }
    return FALSE;
}

// Narrows the field of view by 12 per call, 0x60 in total.
static void DoorTransition_StepCameraZoomIn(Camera *camera, u8 *step) {
    u8 delta = 12;
    int total = *step * delta;
    if (total > 0x60) {
        return;
    }
    if ((u16)total > 0x60) {
        delta = (u16)total - 0x60;
    }
    if ((u16)(Camera_GetPerspectiveAngle(camera) - delta) != 0) {
        Camera_AdjustPerspectiveAngle(-delta, camera);
    }
    (*step)++;
}

// Widens the field of view by 16 per call, 0x60 in total.
static void DoorTransition_StepCameraZoomOut(Camera *camera, u8 *step) {
    int total = *step << 4;
    u8 delta;
    int angle;
    if (total >= 0x60) {
        return;
    }
    if ((u16)total > 0x60) {
        delta = (u16)total - 0x60;
    } else {
        delta = 16;
    }
    angle = Camera_GetPerspectiveAngle(camera);
    angle += delta;
    if ((u16)angle != 0) {
        Camera_AdjustPerspectiveAngle(delta, camera);
    }
    (*step)++;
}

static int GetDoorSE(FieldSystem *fieldSystem, int modelId, BOOL opening) {
    DoorAnimListEntry entry;

    NARC_ReadWholeMember(AreaDataManager_GetMapPropAnimListNarc(fieldSystem->areaDataManager), modelId, &entry);
    if (opening) {
        switch (entry.doorType) {
        case 1:
            return SEQ_SE_DP_DOOR_OPEN;
        case 2:
            return SEQ_SE_DP_DOOR10;
        case 3:
            return SEQ_SE_PL_DOOR_OPEN5;
        case 4:
            return SEQ_SE_GS_HIKIDO_OPEN;
        }
        GF_ASSERT(FALSE);
        return SEQ_SE_DP_DOOR_OPEN;
    }
    switch (entry.doorType) {
    case 1:
        return SEQ_SE_DP_DOOR_CLOSE2;
    case 2:
        return 0;
    case 3:
        return 0;
    case 4:
        return SEQ_SE_GS_HIKIDO_CLOSE;
    }
    GF_ASSERT(FALSE);
    return SEQ_SE_DP_DOOR_CLOSE2;
}

// Doors whose entry plays a camera path from sDoorCameraPaths; 0xFFFF for all others.
static int DoorTransition_GetCameraPathIndex(int modelId) {
    int ret = 0xFFFF;
    switch (modelId) {
    case BUILD_MODEL_KK_DOOR3:
        ret = 0;
        break;
    case BUILD_MODEL_POKE_C_DOOR:
        ret = 1;
        break;
    }
    return ret;
}

BOOL DoorTransition_WalkOutOfSideDoor(FieldSystem *fieldSystem, FieldTransitionWork *arg, u8 direction) {
    DoorTransitionWork *work = (DoorTransitionWork *)arg;
    NNSG3dResTex *texture;
    NNSG3dRenderObj *renderObj;
    NNSG3dResMdl *model;
    LocalMapObject *obj;

    switch (work->state) {
    case 0: {
        fx32 rect[4];
        DoorModelList models = sSideDoorExitModels;
        MapProp *prop;
        int modelId;
        if (direction == DIR_WEST) {
            Terrain_MakeTileRect(work->x, work->z, -1, 0, 2, 1, rect);
        } else {
            Terrain_MakeTileRect(work->x, work->z, 0, 0, 2, 1, rect);
        }
        work->animTag = SIDE_DOOR_ANIM_TAG;
        if (FieldSystem_FindMapPropOfModelsInRect(fieldSystem, models.ids, NELEMS(models.ids), rect, &prop, &modelId)) {
            texture = AreaDataManager_GetMapPropTexture(fieldSystem->areaDataManager);
            renderObj = MapProp_GetRenderSurface(prop);
            model = MapProp_GetResModel(prop);
            MapPropOneShotAnimationManager_LoadPropAnimations(fieldSystem->mapPropAnimationManager, fieldSystem->mapPropOneShotAnimationManager, SIDE_DOOR_ANIM_TAG, modelId, renderObj, model, texture, 1, 1, TRUE);
        } else {
            GF_ASSERT(FALSE);
            return TRUE;
        }
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_AreBitsSetForMovementScriptInit(obj) == TRUE) {
            MapObject_SetHeldMovement(obj, MOVEMENT_UNK_73);
        } else {
            GF_ASSERT(FALSE);
        }
        work->state++;
        break;
    }
    case 1:
        FieldMap_FadeScreen(FADE_TYPE_BRIGHTNESS_IN);
        MapPropOneShotAnimationManager_PlayAnimationWithSoundEffect(fieldSystem->mapPropOneShotAnimationManager, SIDE_DOOR_ANIM_TAG, 0, SEQ_SE_DP_ESUKA);
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_AreBitsSetForMovementScriptInit(obj) == TRUE) {
            MapObject_SetHeldMovement(obj, direction == DIR_EAST ? 0xB : 0xA);
        } else {
            GF_ASSERT(FALSE);
        }
        work->state++;
        break;
    case 2:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_AreBitsSetForMovementScriptInit(obj) == TRUE) {
            MapObject_SetHeldMovement(obj, MOVEMENT_UNK_74);
            work->state++;
        }
        break;
    case 3:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_AreBitsSetForMovementScriptInit(obj) == TRUE) {
            MapObject_SetHeldMovement(obj, direction == DIR_EAST ? 0xB : 0xA);
            work->state++;
        }
        break;
    case 4:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_IsMovementPaused(obj) == TRUE) {
            MapObject_ClearHeldMovementIfActive(obj);
            FollowMon_MoveToPlayer(fieldSystem, direction);
            work->state++;
        }
        break;
    case 5:
        if (MapPropOneShotAnimationManager_IsAnimationLoopFinished(fieldSystem->mapPropOneShotAnimationManager, SIDE_DOOR_ANIM_TAG) && IsPaletteFadeFinished()) {
            MapPropOneShotAnimationManager_UnloadAnimation(fieldSystem->mapPropAnimationManager, fieldSystem->mapPropOneShotAnimationManager, SIDE_DOOR_ANIM_TAG);
            StopSE(SEQ_SE_DP_ESUKA, 0);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL DoorTransition_WalkIntoSideDoor(FieldSystem *fieldSystem, FieldTransitionWork *arg, u8 direction) {
    DoorTransitionWork *work = (DoorTransitionWork *)arg;
    NNSG3dResTex *texture;
    NNSG3dRenderObj *renderObj;
    NNSG3dResMdl *model;
    LocalMapObject *obj;
    int movement;
    int x;

    switch (work->state) {
    case 0: {
        fx32 rect[4];
        DoorModelList models = sSideDoorEntryModels;
        MapProp *prop;
        int modelId;
        if (direction == DIR_WEST) {
            Terrain_MakeTileRect(work->x, work->z, -1, 0, 2, 1, rect);
        } else {
            Terrain_MakeTileRect(work->x, work->z, 0, 0, 2, 1, rect);
        }
        work->animTag = SIDE_DOOR_ANIM_TAG;
        if (FieldSystem_FindMapPropOfModelsInRect(fieldSystem, models.ids, NELEMS(models.ids), rect, &prop, &modelId)) {
            texture = AreaDataManager_GetMapPropTexture(fieldSystem->areaDataManager);
            renderObj = MapProp_GetRenderSurface(prop);
            model = MapProp_GetResModel(prop);
            MapPropOneShotAnimationManager_LoadPropAnimations(fieldSystem->mapPropAnimationManager, fieldSystem->mapPropOneShotAnimationManager, SIDE_DOOR_ANIM_TAG, modelId, renderObj, model, texture, 1, 1, FALSE);
        } else {
            GF_ASSERT(FALSE);
            return TRUE;
        }
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_AreBitsSetForMovementScriptInit(obj) == TRUE) {
            MapObject_SetHeldMovement(obj, MOVEMENT_UNK_73);
        } else {
            GF_ASSERT(FALSE);
        }
        work->state++;
        break;
    }
    case 1:
        MapPropOneShotAnimationManager_PlayAnimationWithSoundEffect(fieldSystem->mapPropOneShotAnimationManager, SIDE_DOOR_ANIM_TAG, 0, SEQ_SE_DP_ESUKA);
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_AreBitsSetForMovementScriptInit(obj) == TRUE) {
            movement = direction == DIR_WEST ? 0xA : 0xB;
            MapObject_SetHeldMovement(obj, movement);
            if (FollowMon_IsActive(fieldSystem)) {
                x = MapObject_GetPreviousXCoord(obj);
                FollowMon_QueuePlayerStep(movement, x, MapObject_GetPreviousZCoord(obj), &fieldSystem->followMon);
            }
        } else {
            GF_ASSERT(FALSE);
        }
        work->state++;
        break;
    case 2:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_AreBitsSetForMovementScriptInit(obj) == TRUE) {
            MapObject_SetHeldMovement(obj, MOVEMENT_UNK_74);
            FieldMap_FadeScreen(FADE_TYPE_BRIGHTNESS_OUT);
            work->state++;
        }
        break;
    case 3:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_IsMovementPaused(obj) == TRUE) {
            MapObject_ClearHeldMovementIfActive(obj);
            work->state++;
        }
        break;
    case 4:
        if (MapPropOneShotAnimationManager_IsAnimationLoopFinished(fieldSystem->mapPropOneShotAnimationManager, SIDE_DOOR_ANIM_TAG) && IsPaletteFadeFinished()) {
            MapPropOneShotAnimationManager_UnloadAnimation(fieldSystem->mapPropAnimationManager, fieldSystem->mapPropOneShotAnimationManager, SIDE_DOOR_ANIM_TAG);
            StopSE(SEQ_SE_DP_ESUKA, 0);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static BOOL Task_WaitDoorAnimation(TaskManager *taskman) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskman);
    u8 *tag = TaskManager_GetEnvironment(taskman);
    if (MapPropOneShotAnimationManager_IsAnimationLoopFinished(fieldSystem->mapPropOneShotAnimationManager, *tag)) {
        Heap_Free(tag);
        return TRUE;
    }
    return FALSE;
}

// Loads the animations of the door prop in front of (x, z) into the one-shot animation slot tag.
void DoorAnimation_Load(FieldSystem *fieldSystem, int x, int z, u8 tag) {
    fx32 rect[4];

    struct {
        MapProp *prop;
        DoorAnimListEntry entry;
    } door;

    NARC *narc;
    BOOL found;
    int modelId;
    int *props;
    int i;
    int *cursor;

    Terrain_MakeTileRect(x, z, -1, 0, 3, 1, rect);
    narc = AreaDataManager_GetMapPropAnimListNarc(fieldSystem->areaDataManager);
    props = FieldSystem_CollectMapPropModelsInRect(fieldSystem, HEAP_ID_FIELD1, 4, rect, 0);
    found = FALSE;
    for (i = 0, cursor = props; i < 4; i++, cursor++) {
        if (*cursor) {
            NARC_ReadWholeMember(narc, *cursor, &door.entry);
            if (door.entry.doorType) {
                FieldSystem_FindMapPropInRect(fieldSystem, props[i], rect, &door.prop);
                found = TRUE;
                modelId = props[i];
                break;
            }
        }
    }
    Heap_Free(props);
    if (found) {
        u8 count = MapPropAnimationManager_GetPropAnimationCount(fieldSystem->mapPropAnimationManager, modelId);
        if (count) {
            NNSG3dResTex *texture = AreaDataManager_GetMapPropTexture(fieldSystem->areaDataManager);
            NNSG3dRenderObj *renderObj = MapProp_GetRenderSurface(door.prop);
            NNSG3dResMdl *model = MapProp_GetResModel(door.prop);
            MapPropOneShotAnimationManager_LoadPropAnimations(fieldSystem->mapPropAnimationManager, fieldSystem->mapPropOneShotAnimationManager, tag, modelId, renderObj, model, texture, count, 1, FALSE);
        }
    } else {
        GF_ASSERT(FALSE);
    }
}

void DoorAnimation_PlayOpen(FieldSystem *fieldSystem, u8 tag) {
    int se = GetDoorSE(fieldSystem, MapPropOneShotAnimationManager_GetAnimationMapPropModelID(fieldSystem->mapPropOneShotAnimationManager, tag), TRUE);
    MapPropOneShotAnimationManager_PlayAnimationWithSoundEffect(fieldSystem->mapPropOneShotAnimationManager, tag, FALSE, se);
}

void DoorAnimation_PlayClose(FieldSystem *fieldSystem, u8 tag) {
    int se = GetDoorSE(fieldSystem, MapPropOneShotAnimationManager_GetAnimationMapPropModelID(fieldSystem->mapPropOneShotAnimationManager, tag), FALSE);
    MapPropOneShotAnimationManager_PlayAnimationWithSoundEffect(fieldSystem->mapPropOneShotAnimationManager, tag, TRUE, se);
}

void DoorAnimation_WaitForEnd(FieldSystem *fieldSystem, u8 tag) {
    u8 *env = Heap_AllocAtEnd(HEAP_ID_FIELD1, 1);
    *env = tag;
    TaskManager_Call(fieldSystem->taskman, Task_WaitDoorAnimation, env);
}

void DoorAnimation_Unload(FieldSystem *fieldSystem, u8 tag) {
    MapPropOneShotAnimationManager_UnloadAnimation(fieldSystem->mapPropAnimationManager, fieldSystem->mapPropOneShotAnimationManager, tag);
}

void *DoorTransition_NewTaskWork(void) {
    DoorTransitionTaskWork *work = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(DoorTransitionTaskWork));
    work->state = 0;
    return work;
}

// After a warp: fades in from white with the camera zoomed in; facing south in front of a door, the door opens and
// the player steps out of it.
BOOL Task_WalkOutOfDoorAfterWarp(TaskManager *taskman) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskman);
    DoorTransitionWork *work = TaskManager_GetEnvironment(taskman);

    switch (work->state) {
    case ARRIVE_STATE_INIT: {
        fx32 rect[4];
        DoorAnimListEntry entry;
        MapProp *prop;
        NNSG3dResTex *texture;
        LocalMapObject *playerObj;
        int found;
        int modelId;
        NARC *narc;
        int *props;
        int i;
        int count;
        NNSG3dRenderObj *renderObj;
        NNSG3dResMdl *model;

        playerObj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        work->adjustCamera = FALSE;
        work->cameraStep = 0;
        work->cameraAngle = Camera_GetPerspectiveAngle(fieldSystem->camera);
        Camera_AdjustPerspectiveAngle(0xFFA0, fieldSystem->camera);
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_WHITE, 6, 1, HEAP_ID_FIELD2);
        work->adjustCamera = TRUE;
        if (PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar) == DIR_SOUTH) {
            work->animTag = DOOR_ANIM_TAG;
            found = FALSE;
            Terrain_MakeTileRect(work->x, work->z, -1, found, 3, 1, rect);
            narc = AreaDataManager_GetMapPropAnimListNarc(fieldSystem->areaDataManager);
            props = FieldSystem_CollectMapPropModelsInRect(fieldSystem, HEAP_ID_FIELD1, 4, rect, 0);
            for (i = 0; i < 4; i++) {
                if (props[i] != 0) {
                    NARC_ReadWholeMember(narc, props[i], &entry);
                    if (entry.doorType != 0) {
                        FieldSystem_FindMapPropInRect(fieldSystem, props[i], rect, &prop);
                        found = TRUE;
                        modelId = props[i];
                        break;
                    }
                }
            }
            Heap_Free(props);
            if (found) {
                count = MapPropAnimationManager_GetPropAnimationCount(fieldSystem->mapPropAnimationManager, modelId);
                if (count == 0) {
                    return FALSE;
                }
                texture = AreaDataManager_GetMapPropTexture(fieldSystem->areaDataManager);
                renderObj = MapProp_GetRenderSurface(prop);
                model = MapProp_GetResModel(prop);
                MapPropOneShotAnimationManager_LoadPropAnimations(fieldSystem->mapPropAnimationManager, fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG, modelId, renderObj, model, texture, count, 1, FALSE);
                work->state = ARRIVE_STATE_OPEN_DOOR;
                break;
            }
        }
        if (PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar) == DIR_SOUTH) {
            MapObject_SetInvisible(playerObj, TRUE);
            work->state = ARRIVE_STATE_STEP_OUT;
        } else {
            MapObject_SetInvisible(playerObj, FALSE);
            work->state = ARRIVE_STATE_WAIT_FADE;
        }
        break;
    }
    case ARRIVE_STATE_STEP_OUT: {
        LocalMapObject *obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        MapObject_SetInvisible(obj, FALSE);
        MapObject_SetHeldMovement(obj, MOVEMENT_STEP_DOWN);
        work->state++;
        break;
    }
    case ARRIVE_STATE_WAIT_STEP: {
        LocalMapObject *obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_IsMovementPaused(obj) == TRUE) {
            MapObject_ClearHeldMovementIfActive(obj);
            work->state++;
        }
        break;
    }
    case ARRIVE_STATE_WAIT_FADE:
        if (IsPaletteFadeFinished()) {
            if (work->cameraAngle == Camera_GetPerspectiveAngle(fieldSystem->camera)) {
                return TRUE;
            }
        }
        break;
    case ARRIVE_STATE_OPEN_DOOR:
        MapPropOneShotAnimationManager_PlayAnimationWithSoundEffect(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG, 0, GetDoorSE(fieldSystem, MapPropOneShotAnimationManager_GetAnimationMapPropModelID(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG), TRUE));
        work->state = ARRIVE_STATE_WAIT_DOOR_OPEN;
        break;
    case ARRIVE_STATE_WAIT_DOOR_OPEN:
        if (MapPropOneShotAnimationManager_IsAnimationLoopFinished(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG)) {
            MapObject_SetInvisible(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar), FALSE);
            work->state = ARRIVE_STATE_STEP_OUT_OF_DOOR;
        }
        break;
    case ARRIVE_STATE_STEP_OUT_OF_DOOR:
        MapObject_SetHeldMovement(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar), MOVEMENT_STEP_DOWN);
        work->state = ARRIVE_STATE_WAIT_STEP_OUT_OF_DOOR;
        break;
    case ARRIVE_STATE_WAIT_STEP_OUT_OF_DOOR: {
        LocalMapObject *obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_IsMovementPaused(obj) == TRUE) {
            MapObject_ClearHeldMovementIfActive(obj);
            FollowMon_MoveToPlayer(fieldSystem, DIR_SOUTH);
            MapPropOneShotAnimationManager_PlayAnimationWithSoundEffect(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG, 1, GetDoorSE(fieldSystem, MapPropOneShotAnimationManager_GetAnimationMapPropModelID(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG), FALSE));
            work->state++;
        }
        break;
    }
    case ARRIVE_STATE_WAIT_DOOR_CLOSE:
        if (MapPropOneShotAnimationManager_IsAnimationLoopFinished(fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG) && IsPaletteFadeFinished() && work->cameraAngle == Camera_GetPerspectiveAngle(fieldSystem->camera)) {
            MapPropOneShotAnimationManager_UnloadAnimation(fieldSystem->mapPropAnimationManager, fieldSystem->mapPropOneShotAnimationManager, DOOR_ANIM_TAG);
            return TRUE;
        }
        break;
    }
    if (work->adjustCamera) {
        DoorTransition_StepCameraZoomOut(fieldSystem->camera, &work->cameraStep);
    }
    return FALSE;
}

// Stairs: hides the player and fades to white while zooming in.
BOOL Task_StairsFadeToWhite(TaskManager *taskman) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskman);
    DoorTransitionTaskWork *work = TaskManager_GetEnvironment(taskman);
    switch (work->state) {
    case STAIRS_FADE_STATE_START:
        MapObject_SetInvisible(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar), TRUE);
        work->adjustCamera = FALSE;
        work->cameraStep = 0;
        PlaySE(SEQ_SE_DP_KAIDAN2);
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_WHITE, 6, 1, HEAP_ID_FIELD2);
        work->adjustCamera = TRUE;
        work->state++;
        break;
    case STAIRS_FADE_STATE_WAIT:
        if (IsPaletteFadeFinished()) {
            Heap_Free(work);
            return TRUE;
        }
        break;
    }
    if (work->adjustCamera) {
        DoorTransition_StepCameraZoomIn(fieldSystem->camera, &work->cameraStep);
    }
    return FALSE;
}

BOOL Task_StairsFadeOut(TaskManager *taskman) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskman);
    DoorTransitionTaskWork *work = TaskManager_GetEnvironment(taskman);
    switch (work->state) {
    case STAIRS_FADE_STATE_START:
        work->adjustCamera = FALSE;
        work->cameraStep = 0;
        PlaySE(SEQ_SE_DP_KAIDAN2);
        NewFieldFadeEnvironment(taskman, FADE_BOTH_SCREENS, (enum FadeType)16, FADE_TYPE_BRIGHTNESS_OUT, 0, 6, 1, HEAP_ID_FIELD2);
        work->adjustCamera = TRUE;
        work->state++;
        break;
    case STAIRS_FADE_STATE_WAIT:
        if (IsPaletteFadeFinished()) {
            Heap_Free(work);
            return TRUE;
        }
        break;
    }
    if (work->adjustCamera) {
        DoorTransition_StepCameraZoomIn(fieldSystem->camera, &work->cameraStep);
    }
    return FALSE;
}

// After a warp that does not end on a door: fades in with a fade type chosen by the facing direction while the
// camera zooms out; facing south, the player steps forward.
BOOL Task_ArriveWithDirectionalFade(TaskManager *taskman) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskman);
    DoorTransitionTaskWork *work = TaskManager_GetEnvironment(taskman);
    LocalMapObject *obj;
    u8 direction;
    int fadeType;

    switch (work->state) {
    case ARRIVE_STATE_INIT:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        direction = PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar);
        if (direction == DIR_SOUTH) {
            MapObject_SetInvisible(obj, TRUE);
            work->state = ARRIVE_STATE_STEP_OUT;
        } else {
            MapObject_SetInvisible(obj, FALSE);
            work->state = ARRIVE_STATE_WAIT_FADE;
        }
        work->adjustCamera = FALSE;
        work->cameraStep = 0;
        work->cameraAngle = Camera_GetPerspectiveAngle(fieldSystem->camera);
        Camera_AdjustPerspectiveAngle(0xFFA0, fieldSystem->camera);
        switch (direction) {
        case DIR_NORTH:
            fadeType = 3;
            break;
        case DIR_SOUTH:
            fadeType = 5;
            break;
        case DIR_WEST:
            fadeType = 7;
            break;
        case DIR_EAST:
            fadeType = 39;
            break;
        default:
            GF_ASSERT(FALSE);
            break;
        }
        NewFieldFadeEnvironment(taskman, FADE_BOTH_SCREENS, (enum FadeType)fadeType, FADE_TYPE_BRIGHTNESS_IN, 0, 6, 1, HEAP_ID_FIELD2);
        work->adjustCamera = TRUE;
        break;
    case ARRIVE_STATE_STEP_OUT:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        MapObject_SetInvisible(obj, FALSE);
        MapObject_SetHeldMovement(obj, MOVEMENT_STEP_DOWN);
        work->state++;
        break;
    case ARRIVE_STATE_WAIT_STEP:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_IsMovementPaused(obj) == TRUE) {
            MapObject_ClearHeldMovementIfActive(obj);
            work->state++;
        }
        break;
    case ARRIVE_STATE_WAIT_FADE:
        if (IsPaletteFadeFinished() && work->cameraAngle == Camera_GetPerspectiveAngle(fieldSystem->camera)) {
            Heap_Free(work);
            return TRUE;
        }
        break;
    }
    if (work->adjustCamera) {
        DoorTransition_StepCameraZoomOut(fieldSystem->camera, &work->cameraStep);
    }
    return FALSE;
}

// As above without the camera zoom and with a plain fade in.
BOOL Task_ArriveWithFade(TaskManager *taskman) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskman);
    u8 *state = TaskManager_GetEnvironment(taskman);
    LocalMapObject *obj;

    switch (*state) {
    case ARRIVE_STATE_INIT:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if ((u8)PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar) == DIR_SOUTH) {
            MapObject_SetInvisible(obj, TRUE);
            *state = ARRIVE_STATE_STEP_OUT;
        } else {
            MapObject_SetInvisible(obj, FALSE);
            *state = ARRIVE_STATE_WAIT_FADE;
        }
        NewFieldFadeEnvironment(taskman, FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, 0, 6, 1, HEAP_ID_FIELD2);
        break;
    case ARRIVE_STATE_STEP_OUT:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        MapObject_SetInvisible(obj, FALSE);
        MapObject_SetHeldMovement(obj, MOVEMENT_STEP_DOWN);
        (*state)++;
        break;
    case ARRIVE_STATE_WAIT_STEP:
        obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        if (MapObject_IsMovementPaused(obj) == TRUE) {
            MapObject_ClearHeldMovementIfActive(obj);
            (*state)++;
        }
        break;
    case ARRIVE_STATE_WAIT_FADE:
        if (IsPaletteFadeFinished()) {
            Heap_Free(state);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

// Doors that keep the camera still: three models inside buildings, one outside.
static BOOL DoorTransition_ModelSkipsCameraZoom(FieldSystem *fieldSystem, int modelId) {
    if (MapHeader_IsInBuilding(fieldSystem->location->mapId)) {
        if (modelId == BUILD_MODEL_KK_FS || modelId == BUILD_MODEL_AR_SHRINE1_6 || modelId == BUILD_MODEL_SAF_RO03) {
            return TRUE;
        }
    } else if (modelId == BUILD_MODEL_ELE_DOOR_DUN) {
        return TRUE;
    }
    return FALSE;
}
