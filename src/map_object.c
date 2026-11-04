#include "map_object.h"

#include "global.h"

#include "constants/sprites.h"

#include "filesystem.h"
#include "heap.h"
#include "field/map_object_render.h"
#include "player_avatar.h"
#include "script_manager.h"
#include "sys_task_api.h"
#include "map_object_movement_utilities.h"

extern MapObjectMovementCallbacks *gMapObjectMovementCallbacks[57];
extern MapObjectDrawCallbacks *gMapObjectDrawCallbacks[20];

extern void MapObject_UpdateHiddenMovement(LocalMapObject *object);
extern BOOL FieldSystem_SnapToTerrainHeightEx(FieldSystem *fieldSystem, VecFx32 *, BOOL);
extern void MapObject_ClearHeldMovement(LocalMapObject *object);
extern void MapObject_SetBillboardPending(LocalMapObject *object, BOOL set);
extern void MapObject_UpdateMovement(LocalMapObject *object);
extern void MapObject_TryUpdateDraw(LocalMapObject *object);
extern ObjectEventGraphicsInfo *ObjectEvent_GetGraphicsInfo(u32 spriteId);
extern void MapObject_SetPreviousCoordsToCurrent(LocalMapObject *object);
extern void MapObject_CallMovementAndBehaviorInit(LocalMapObject *object);

static MapObjectManager *MapObjectManager_New(u32 objectCount);
static LocalMapObject *MapObject_CreateFromObjectEvent(MapObjectManager *manager, ObjectEvent *objectEvent, u32 mapNo);
static void SavedMapObject_InitFromLocalMapObject(FieldSystem *fieldSystem, LocalMapObject *localObject, SavedMapObject *savedObject);
static void LocalMapObject_InitFromSavedMapObject(LocalMapObject *localObject, SavedMapObject *savedObject);
static void MapObjectManager_SetupRestoredObject(MapObjectManager *manager, LocalMapObject *object);
static void MapObject_ResetFlagsForRestore(LocalMapObject *object);
static void MapObject_ConvertXZToPositionVec(LocalMapObject *object);
static void MapObject_CreateFromInitArgs(MapObjectInitArgs *args);
static LocalMapObject *MapObjectManager_GetFirstInactiveObject(MapObjectManager *manager);
static LocalMapObject *MapObjectManager_GetFlag25ObjectByIDAndMap(MapObjectManager *manager, u32 id, u32 mapNo);
static void MapObject_CreateUpdateTask(MapObjectManager *manager, LocalMapObject *object);
static void MapObject_InitFromObjectEvent(LocalMapObject *object, ObjectEvent *objectEvent, FieldSystem *fieldSystem);
static void MapObject_SetPositionVectorFromObjectEvent(LocalMapObject *object, ObjectEvent *objectEvent);
static void MapObject_InitFlagsAndFacing(LocalMapObject *object, MapObjectManager *manager);
static void MapObject_SetMovementCallbacks(LocalMapObject *object);
static void MapObject_SetDrawCallbacks(LocalMapObject *object);
static void MapObject_Clear(LocalMapObject *object);
static u32 MapObject_MatchObjectEvents(LocalMapObject *object, u32 mapId, u32 objectEventCount, ObjectEvent *objectEvents);
static LocalMapObject *MapObjectManager_GetFirstObjectWithIDAndMap(MapObjectManager *manager, u32 objectId, u32 mapId);
static void MapObject_SetStartMovementAndClearFlags(LocalMapObject *object);
static void MapObject_ClearFlags15_20_24_26(LocalMapObject *object);
static void MapObject_UpdateHeightIfNeeded(LocalMapObject *object);
static void MapObject_NoOp(LocalMapObject *object);
static u32 FieldSystem_ResolveObjectSpriteID(FieldSystem *fieldSystem, s32 spriteId);
static void MapObject_InitMovement(LocalMapObject *object);
static void MapObject_InitDraw(LocalMapObject *object);
static BOOL MapObject_ScriptIDIsFFFF(LocalMapObject *object);
static void MapObject_ClearFlag25AndSetFromObjectEvent(LocalMapObject *object, ObjectEvent *objectEvent, u32 mapNo);
static void MapObject_SetFlag25FromObjectEvent(LocalMapObject *object, u32 mapNo, ObjectEvent *objectEvent);
static void MapObject_UpdateTask(SysTask *task, LocalMapObject *object);
static void MapObject_UpdateDrawIfRenderReady(LocalMapObject *object);
static MapObjectManager *MapObjectManager_Get(MapObjectManager *manager);
static void MapObjectManager_SetObjectCount(MapObjectManager *manager, u32 count);
static void MapObjectManager_IncrementActiveCount(MapObjectManager *manager);
static void MapObjectManager_DecrementActiveCount(MapObjectManager *manager);
static void MapObjectManager_SetPriority(MapObjectManager *manager, u32 priority);
static void MapObjectManager_SetObjects(MapObjectManager *manager, LocalMapObject *objects);
static LocalMapObject *MapObjectManager_GetObjects3(MapObjectManager *manager);
static void MapObjectManager_SetFieldSystem(MapObjectManager *manager, FieldSystem *fieldSystem);
static void MapObject_SetFlags(LocalMapObject *object, u32 flags);
static void MapObject_SetFlags2(LocalMapObject *object, u32 flags);
static u32 MapObject_GetFlags2(LocalMapObject *object);
static u32 MapObject_GetFlags2BitsMask(LocalMapObject *object, u32 bits);
static void MapObject_SetMapID(LocalMapObject *object, u32 mapId);
static void MapObject_SetMovement(LocalMapObject *object, u32 movement);
static void MapObject_SetInitialFacingDirection(LocalMapObject *object, u32 initialFacing);
static void MapObject_SetUpdateTask(LocalMapObject *object, SysTask *sysTask);
static SysTask *MapObject_GetUpdateTask(LocalMapObject *object);
static void MapObject_DestroyUpdateTask(LocalMapObject *object);
static void MapObject_SetManager(LocalMapObject *object, MapObjectManager *manager);
static MapObjectManager *MapObject_GetManagerFromManager(LocalMapObject *object);
static void MapObject_SetMovementInitCallback(LocalMapObject *object, LocalMapObject_Callback callback);
static void MapObject_SetMovementUpdateCallback(LocalMapObject *object, LocalMapObject_Callback callback);
static void MapObject_SetMovementDeleteCallback(LocalMapObject *object, LocalMapObject_Callback callback);
static void MapObject_CallMovementDelete(LocalMapObject *object);
static void MapObject_CallMovementRestore(LocalMapObject *object);
static void MapObject_SetDrawInitCallback(LocalMapObject *object, LocalMapObject_Callback callback);
static void MapObject_CallDrawInit(LocalMapObject *object);
static void MapObject_SetDrawDeleteCallback(LocalMapObject *object, LocalMapObject_Callback callback);
static void MapObject_CallDrawDelete(LocalMapObject *object);
static void MapObject_SetDrawPauseCallback(LocalMapObject *object, LocalMapObject_Callback callback);
static void MapObject_CallDrawPause(LocalMapObject *object);
static void MapObject_SetDrawResumeCallback(LocalMapObject *object, LocalMapObject_Callback callback);
static void MapObject_SetFlag14(LocalMapObject *object);
static void MapObject_SetFlag25(LocalMapObject *object, BOOL set);
static void MapObject_SetInitialX(LocalMapObject *object, u32 initialX);
static void MapObject_SetInitialY(LocalMapObject *object, u32 initialY);
static void MapObject_SetInitialZ(LocalMapObject *object, u32 initialZ);
static void ObjectEvent_SetID(ObjectEvent *objectEvent, u16 id);
static u16 ObjectEvent_GetID(ObjectEvent *objectEvent);
static void ObjectEvent_SetSpriteID(ObjectEvent *objectEvent, u32 spriteId);
static u16 ObjectEvent_GetSpriteID(ObjectEvent *objectEvent);
static void ObjectEvent_SetMovement(ObjectEvent *objectEvent, u32 movement);
static u16 ObjectEvent_GetMovement(ObjectEvent *objectEvent);
static void ObjectEvent_SetType(ObjectEvent *objectEvent, u16 type);
static u16 ObjectEvent_GetType(ObjectEvent *objectEvent);
static void ObjectEvent_SetEventFlag(ObjectEvent *objectEvent, u16 eventFlag);
static u16 ObjectEvent_GetEventFlag(ObjectEvent *objectEvent);
static void ObjectEvent_SetScriptID(ObjectEvent *objectEvent, u16 scriptId);
static u16 ObjectEvent_GetScriptID(ObjectEvent *objectEvent);
static void ObjectEvent_SetFacingDirection(ObjectEvent *objectEvent, u32 facingDirection);
static s16 ObjectEvent_GetFacingDirection(ObjectEvent *objectEvent);
static void ObjectEvent_SetParam(ObjectEvent *objectEvent, s32 value, u32 param);
static u16 ObjectEvent_GetParam(ObjectEvent *objectEvent, u32 param);
static void ObjectEvent_SetXRange(ObjectEvent *objectEvent, s16 xRange);
static s16 ObjectEvent_GetXRange(ObjectEvent *objectEvent);
static void ObjectEvent_SetYRange(ObjectEvent *objectEvent, s16 yRange);
static s16 ObjectEvent_GetYRange(ObjectEvent *objectEvent);
static void ObjectEvent_SetXCoord(ObjectEvent *objectEvent, u32 x);
static u16 ObjectEvent_GetXCoord(ObjectEvent *template);
static void ObjectEvent_SetYCoord(ObjectEvent *objectEvent, u32 y);
static u32 ObjectEvent_GetYCoord(ObjectEvent *objectEvent);
static void ObjectEvent_SetZCoord(ObjectEvent *objectEvent, u32 z);
static u16 ObjectEvent_GetZCoord(ObjectEvent *objectEvent);
static ObjectEvent *ObjectEvent_GetByID(u16 id, s32 objectEventCount, ObjectEvent *objectEvents);
static BOOL ObjectEvent_ScriptIDIsUnset(ObjectEvent *objectEvent);
static u16 ObjectEvent_GetEventFlag_AssertScriptIDIsUnset(ObjectEvent *template);
static MapObjectMovementCallbacks *MapObject_GetMovementCallbacks(u32 movement);
static LocalMapObject_Callback MovementCallbacks_GetInit(MapObjectMovementCallbacks *callbackStruct);
static LocalMapObject_Callback MovementCallbacks_GetUpdate(MapObjectMovementCallbacks *callbackStruct);
static LocalMapObject_Callback MovementCallbacks_GetDelete(MapObjectMovementCallbacks *callbackStruct);
static LocalMapObject_Callback DrawCallbacks_GetInit(MapObjectDrawCallbacks *callbackStruct);
static LocalMapObject_Callback DrawCallbacks_GetUpdate(MapObjectDrawCallbacks *callbackStruct);
static LocalMapObject_Callback DrawCallbacks_GetDelete(MapObjectDrawCallbacks *callbackStruct);
static LocalMapObject_Callback DrawCallbacks_GetPause(MapObjectDrawCallbacks *callbackStruct);
static LocalMapObject_Callback DrawCallbacks_GetResume(MapObjectDrawCallbacks *callbackStruct);
static MapObjectDrawCallbacks *MapObject_GetDrawCallbacksForSprite(u32 spriteId);

MapObjectManager *MapObjectManager_Init(FieldSystem *fieldSystem, u32 objectCount, u32 priority) {
    MapObjectManager *ret = MapObjectManager_New(objectCount);
    MapObjectManager_SetFieldSystem(ret, fieldSystem);
    MapObjectManager_SetObjectCount(ret, objectCount);
    MapObjectManager_SetPriority(ret, priority);

    return ret;
}

void MapObjectManager_Delete(MapObjectManager *manager) {
    Heap_FreeExplicit(HEAP_ID_FIELD2, MapObjectManager_GetObjects(manager));
    Heap_FreeExplicit(HEAP_ID_FIELD2, manager);
}

void MapObjectManager_RemoveObjectsNotOnMap(MapObjectManager *manager, u32 unused, u32 mapId, u32 objectCount, ObjectEvent *objectEvents) {
    u32 count = MapObjectManager_GetObjectCount(manager);
    LocalMapObject *objects = MapObjectManager_GetObjects(manager);

    for (; count != 0; count--) {
        if (MapObject_CheckActive(objects) == TRUE) {
            switch (MapObject_MatchObjectEvents(objects, mapId, objectCount, objectEvents)) {
            case 0:
                if (MapObject_GetMapID(objects) != mapId && !MapObject_TestFlagsBits(objects, MAPOBJECTFLAG_KEEP)) {
                    MapObject_Remove(objects);
                }
                break;

            case 1:
            case 2:
                break;
            }
        }
        objects++;
    }

    MapObjectRender_ReleaseUnused(manager, MapObjectManager_GetRender(manager));
}

static MapObjectManager *MapObjectManager_New(u32 objectCount) {
    LocalMapObject *objects;
    MapObjectManager *manager = Heap_Alloc(HEAP_ID_FIELD2, sizeof(MapObjectManager));
    GF_ASSERT(manager != NULL);
    memset(manager, 0, sizeof(MapObjectManager));

    objects = Heap_Alloc(HEAP_ID_FIELD2, objectCount * sizeof(LocalMapObject));
    GF_ASSERT(objects != NULL);
    memset(objects, 0, objectCount * sizeof(LocalMapObject));

    MapObjectManager_SetObjects(manager, objects);

    return manager;
}

static LocalMapObject *MapObject_CreateFromObjectEvent(MapObjectManager *manager, ObjectEvent *objectEvent, u32 mapNo) {
    LocalMapObject *ret;
    ObjectEvent event = *objectEvent;
    ObjectEvent *eventPtr = &event;

    u32 objectId = ObjectEvent_GetID(eventPtr);
    if (!ObjectEvent_ScriptIDIsUnset(eventPtr)) {
        ret = MapObjectManager_GetFlag25ObjectByIDAndMap(manager, objectId, mapNo);
        if (ret != NULL) {
            MapObject_ClearFlag25AndSetFromObjectEvent(ret, eventPtr, mapNo);
            return ret;
        }
    } else {
        ret = MapObjectManager_GetFirstObjectWithIDAndMap(manager, objectId, ObjectEvent_GetEventFlag_AssertScriptIDIsUnset(eventPtr));
        if (ret != NULL) {
            MapObject_SetFlag25FromObjectEvent(ret, mapNo, eventPtr);
            return ret;
        }
    }

    ret = MapObjectManager_GetFirstInactiveObject(manager);
    if (ret == NULL) {
        return ret;
    }

    MapObject_InitFromObjectEvent(ret, eventPtr, MapObjectManager_GetFieldSystem(manager));
    MapObject_InitFlagsAndFacing(ret, manager);
    MapObject_SetMapID(ret, mapNo);
    MapObject_InitMovement(ret);
    MapObject_InitDraw(ret);
    MapObject_SetFlagsBits(ret, MAPOBJECTFLAG_START_MOVEMENT);
    MapObject_CreateUpdateTask(manager, ret);
    MapObjectManager_IncrementActiveCount(MapObjectManager_Get(manager));
    return ret;
}

LocalMapObject *MapObject_Create(MapObjectManager *manager, u32 x, u32 y, u32 direction, u32 sprite, u32 movement, u32 mapNo) {
    return MapObject_CreateWithParams(manager, x, y, direction, sprite, movement, mapNo, 0, 0, 0);
}

LocalMapObject *MapObject_CreateWithParams(MapObjectManager *manager, u32 x, u32 y, u32 direction, u32 sprite, u32 movement, u32 mapNo, u32 param0, u32 param1, u32 param2) {
    ObjectEvent objectEvent;
    ObjectEvent_SetID(&objectEvent, 0);
    ObjectEvent_SetSpriteID(&objectEvent, sprite);
    ObjectEvent_SetMovement(&objectEvent, movement);
    ObjectEvent_SetType(&objectEvent, 0);
    ObjectEvent_SetEventFlag(&objectEvent, 0);
    ObjectEvent_SetScriptID(&objectEvent, 0);
    ObjectEvent_SetFacingDirection(&objectEvent, direction);
    ObjectEvent_SetParam(&objectEvent, param0, 0);
    ObjectEvent_SetParam(&objectEvent, param1, 1);
    ObjectEvent_SetParam(&objectEvent, param2, 2);
    ObjectEvent_SetXRange(&objectEvent, 0);
    ObjectEvent_SetYRange(&objectEvent, 0);
    ObjectEvent_SetXCoord(&objectEvent, x);
    ObjectEvent_SetZCoord(&objectEvent, y);
    ObjectEvent_SetYCoord(&objectEvent, 0);

    return MapObject_CreateFromObjectEvent(manager, &objectEvent, mapNo);
}

LocalMapObject *MapObject_CreateFromObjectEventWithId(MapObjectManager *manager, u16 id, u32 objectEventCount, u32 mapNo, const ObjectEvent *events) {
    LocalMapObject *ret = NULL;
    ObjectEvent *objectEvent = ObjectEvent_GetByID(id, objectEventCount, (ObjectEvent *)events);
    if (objectEvent != NULL) {
        // casts and typing required to match
        u32 eventFlag = ObjectEvent_GetEventFlag(objectEvent);
        FieldSystem *fieldSystem = MapObjectManager_GetFieldSystem(manager);
        if (FieldSystem_FlagCheck(fieldSystem, (u16)eventFlag) == FALSE) {
            ret = MapObject_CreateFromObjectEvent(manager, objectEvent, mapNo);
        }
    }

    return ret;
}

void MapObject_SetSpriteAndInitDraw(LocalMapObject *object, u32 sprite) {
    MapObject_SetSpriteID(object, sprite);
    MapObject_SetStartMovementAndClearFlags(object);
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK14);
    MapObject_InitDraw(object);
}

void MapObject_ChangeSprite(LocalMapObject *object, u32 sprite) {
    if (MapObject_IsDrawInitialized(object) == TRUE) {
        MapObject_ClearSprite(object);
    }
    MapObject_SetSpriteAndInitDraw(object, sprite);
}

void MapObject_Remove(LocalMapObject *object) {
    if (MapObjectManager_IsRenderInitialized(MapObject_GetManager(object)) == TRUE) {
        MapObject_CallDrawDelete(object);
    }
    MapObject_CallMovementDelete(object);
    MapObject_DestroyUpdateTask(object);
    MapObjectManager_DecrementActiveCount(MapObject_GetManagerFromManager(object));
    MapObject_Clear(object);
}

void MapObject_Delete(LocalMapObject *object) {
    u32 eventFlag = MapObject_GetEventFlag(object);
    FieldSystem *fieldSystem = MapObject_GetFieldSystem(object);
    FieldSystem_FlagSet(fieldSystem, eventFlag);
    MapObject_Remove(object);
}

void MapObject_ClearSprite(LocalMapObject *object) {
    if (MapObjectManager_IsRenderInitialized(MapObject_GetManager(object)) == TRUE) {
        if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK14) != 0) {
            MapObject_CallDrawDelete(object);
        }
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK14);
    }
    MapObject_SetSpriteID(object, MAP_OBJECT_GFX_ID_INVALID);
    MapObject_SetDrawInitCallback(object, MapObjectDraw_NoOpInit);
    MapObject_SetDrawUpdateCallback(object, MapObjectDraw_NoOpUpdate);
    MapObject_SetDrawDeleteCallback(object, MapObjectDraw_NoOpUpdate);
    MapObject_SetDrawPauseCallback(object, MapObjectDraw_NoOpPause);
    MapObject_SetDrawResumeCallback(object, MapObjectDraw_NoOpResume);
}

void MapObjectManager_RemoveAllActiveObjects(MapObjectManager *manager) {
    s32 i = 0;
    s32 count = MapObjectManager_GetObjectCount(manager);
    LocalMapObject *objects = MapObjectManager_GetObjects(manager);

    do { // BUG: does not check for if count is zero, and will always execute at least once
        if (MapObject_GetFlagsBitsMask(objects, MAPOBJECTFLAG_ACTIVE) != 0) {
            MapObject_Remove(objects);
        }

        i++;
        objects++;
    } while (i < count);
}

void MapObjectManager_PauseAllDraw(MapObjectManager *manager) {
    GF_ASSERT(MapObjectManager_IsRenderInitialized(manager) == TRUE);

    s32 i = 0;
    s32 count = MapObjectManager_GetObjectCount(manager);
    LocalMapObject *objects = MapObjectManager_GetObjects(manager);

    do {
        if (MapObject_GetFlagsBitsMask(objects, MAPOBJECTFLAG_ACTIVE) != 0 && MapObject_GetFlagsBitsMask(objects, MAPOBJECTFLAG_UNK14) != 0) {
            MapObject_CallDrawPause(objects);
            MapObject_NoOp(objects);
        }

        i++;
        objects++;
    } while (i < count);
}

void MapObjectManager_ResumeAllDraw(MapObjectManager *manager) {
    GF_ASSERT(MapObjectManager_IsRenderInitialized(manager) == TRUE);

    s32 i = 0;
    s32 count = MapObjectManager_GetObjectCount(manager);
    LocalMapObject *objects = MapObjectManager_GetObjects(manager);

    do {
        if (MapObject_CheckActive(objects) == TRUE) {
            if (MapObject_CheckFlag14(objects) == TRUE) {
                MapObject_CallDrawResume(objects);
            } else {
                MapObject_InitDraw(objects);
            }

            MapObject_SetStartMovementAndClearFlags(objects);
            MapObject_UpdateHiddenMovement(objects);
        }

        i++;
        objects++;
    } while (i < count);
}

// exactly the same as above, except it checks if object id is 0xFF
void MapObjectManager_ResumePlayerDraw(MapObjectManager *manager) {
    GF_ASSERT(MapObjectManager_IsRenderInitialized(manager) == TRUE);

    s32 i = 0;
    s32 count = MapObjectManager_GetObjectCount(manager);
    LocalMapObject *objects = MapObjectManager_GetObjects(manager);

    do {
        if (MapObject_CheckActive(objects) == TRUE && MapObject_GetID(objects) == 0xFF) { // todo: const (is this invalid ID? or just max?)
            if (MapObject_CheckFlag14(objects) == TRUE) {
                MapObject_CallDrawResume(objects);
            } else {
                MapObject_InitDraw(objects);
            }

            MapObject_SetStartMovementAndClearFlags(objects);
            MapObject_UpdateHiddenMovement(objects);

            return;
        }

        i++;
        objects++;
    } while (i < count);
}

void FieldSystem_SyncMapObjectsToSaveEx(FieldSystem *fieldSystem, MapObjectManager *manager, SavedMapObject *savedObjects, s32 count) {
    s32 index = 0;
    LocalMapObject *object;

    while (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &object, &index, MAPOBJECTFLAG_ACTIVE)) { // MapObjectManager_GetNextActiveObject? this is an iterator however
        SavedMapObject_InitFromLocalMapObject(fieldSystem, object, savedObjects);

        count--;
        savedObjects++;

        GF_ASSERT(count > 0);
    }

    if (count != 0) {
        memset(savedObjects, 0, count * sizeof(SavedMapObject));
    }
}

void MapObjectManager_RestoreFromSave(MapObjectManager *manager, SavedMapObject *savedObjects, u32 objectCount) {
    while (objectCount > 0) {
        if (savedObjects->flags & MAPOBJECTFLAG_ACTIVE) {
            LocalMapObject *localObject = MapObjectManager_GetFirstInactiveObject(manager);
            GF_ASSERT(localObject != NULL);

            LocalMapObject_InitFromSavedMapObject(localObject, savedObjects);
            MapObjectManager_SetupRestoredObject(manager, localObject);
        }
        savedObjects++;
        objectCount--;
    }
}

static void SavedMapObject_InitFromLocalMapObject(FieldSystem *fieldSystem, LocalMapObject *localObject, SavedMapObject *savedObject) {
    savedObject->flags = MapObject_GetFlags(localObject);
    savedObject->flags2 = MapObject_GetFlags2(localObject);
    savedObject->objId = MapObject_GetID(localObject);
    savedObject->mapId = MapObject_GetMapID(localObject);
    savedObject->spriteId = MapObject_GetSpriteID(localObject);
    savedObject->movement = MapObject_GetMovement(localObject);
    savedObject->type = MapObject_GetType(localObject);
    savedObject->eventFlag = MapObject_GetEventFlag(localObject);
    savedObject->script = MapObject_GetScriptID(localObject);
    savedObject->initialFacing = MapObject_GetInitialFacingDirection(localObject);
    savedObject->currentFacing = MapObject_GetFacingDirection(localObject);
    savedObject->nextFacing = MapObject_GetNextFacingDirection(localObject);
    savedObject->param[0] = MapObject_GetParam(localObject, 0);
    savedObject->param[1] = MapObject_GetParam(localObject, 1);
    savedObject->param[2] = MapObject_GetParam(localObject, 2);
    savedObject->xRange = MapObject_GetXRange(localObject);
    savedObject->yRange = MapObject_GetYRange(localObject);
    savedObject->initialX = MapObject_GetInitialX(localObject);
    savedObject->initialY = MapObject_GetInitialY(localObject);
    savedObject->initialZ = MapObject_GetInitialZ(localObject);
    savedObject->currentX = MapObject_GetXCoord(localObject);
    savedObject->currentY = MapObject_GetYCoord(localObject);
    savedObject->currentZ = MapObject_GetZCoord(localObject);

    VecFx32 coords;
    SetPositionToTileCenter(savedObject->currentX, savedObject->currentZ, &coords); // some kind of x y vec copy with convertion between int and fx32
    coords.y = MapObject_GetPositionVectorYCoord(localObject);

    if (!FieldSystem_SnapToTerrainHeightEx(fieldSystem, &coords, MapObject_CheckFlag29(localObject))) {
        savedObject->vecY = MapObject_GetPositionVectorYCoord(localObject);
    } else {
        if (MapObject_CheckIgnoreHeights(localObject) == TRUE) {
            coords.y = MapObject_GetPositionVectorYCoord(localObject);
        }
        savedObject->vecY = coords.y;
    }

    memcpy(savedObject->movementData, MapObject_GetMovementData(localObject), 16);
    memcpy(savedObject->behaviorData, MapObject_GetBehaviorData(localObject), 16);
}

static void LocalMapObject_InitFromSavedMapObject(LocalMapObject *localObject, SavedMapObject *savedObject) {
    MapObject_SetFlags(localObject, savedObject->flags);
    MapObject_SetFlags2(localObject, savedObject->flags2);
    MapObject_SetID(localObject, savedObject->objId);
    MapObject_SetMapID(localObject, savedObject->mapId);
    MapObject_SetSpriteID(localObject, savedObject->spriteId);
    MapObject_SetMovement(localObject, savedObject->movement);
    MapObject_SetType(localObject, savedObject->type);
    MapObject_SetEventFlag(localObject, savedObject->eventFlag);
    MapObject_SetScriptID(localObject, savedObject->script);
    MapObject_SetInitialFacingDirection(localObject, savedObject->initialFacing);
    MapObject_SetFacingDirectionDirect(localObject, savedObject->currentFacing);
    MapObject_SetNextFacingDirection(localObject, savedObject->nextFacing);
    MapObject_SetParam(localObject, savedObject->param[0], 0);
    MapObject_SetParam(localObject, savedObject->param[1], 1);
    MapObject_SetParam(localObject, savedObject->param[2], 2);
    MapObject_SetXRange(localObject, savedObject->xRange);
    MapObject_SetYRange(localObject, savedObject->yRange);
    MapObject_SetInitialX(localObject, savedObject->initialX);
    MapObject_SetInitialY(localObject, savedObject->initialY);
    MapObject_SetInitialZ(localObject, savedObject->initialZ);
    MapObject_SetCurrentX(localObject, savedObject->currentX);
    MapObject_SetCurrentY(localObject, savedObject->currentY);
    MapObject_SetCurrentZ(localObject, savedObject->currentZ);

    VecFx32 coords = { };
    coords.y = savedObject->vecY;
    MapObject_SetPositionVector(localObject, &coords);

    memcpy(MapObject_GetMovementData(localObject), savedObject->movementData, 16);
    memcpy(MapObject_GetBehaviorData(localObject), savedObject->behaviorData, 16);
}

static void MapObjectManager_SetupRestoredObject(MapObjectManager *manager, LocalMapObject *object) {
    MapObject_ResetFlagsForRestore(object);
    MapObject_ConvertXZToPositionVec(object);
    MapObject_SetManager(object, manager);
    MapObject_SetMovementCallbacks(object);
    MapObject_ClearHeldMovement(object);
    MapObject_InitDraw(object);
    MapObject_CreateUpdateTask(manager, object);
    MapObject_CallMovementRestore(object);
    MapObjectManager_IncrementActiveCount(MapObjectManager_Get(manager));
}

static void MapObject_ResetFlagsForRestore(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_START_MOVEMENT | MAPOBJECTFLAG_ACTIVE));
    MapObject_ClearFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_IGNORE_HEIGHTS | MAPOBJECTFLAG_UNK22 | MAPOBJECTFLAG_UNK21 | MAPOBJECTFLAG_UNK19 | MAPOBJECTFLAG_UNK18 | MAPOBJECTFLAG_UNK17 | MAPOBJECTFLAG_UNK16 | MAPOBJECTFLAG_UNK14 | MAPOBJECTFLAG_INVISIBLE | MAPOBJECTFLAG_MOVEMENT_PAUSED | MAPOBJECTFLAG_END_MOVEMENT));
    MapObject_ClearFlags15_20_24_26(object);
}

static void MapObject_ConvertXZToPositionVec(LocalMapObject *object) {
    VecFx32 position;
    MapObject_CopyPositionVector(object, &position);

    u32 x = MapObject_GetXCoord(object);
    position.x = x * FX32_CONST(16) + FX32_CONST(8);
    MapObject_SetPreviousX(object, x);

    MapObject_SetPreviousY(object, MapObject_GetYCoord(object));

    u32 z = MapObject_GetZCoord(object);
    position.z = z * FX32_CONST(16) + FX32_CONST(8);
    MapObject_SetPreviousZ(object, z);

    MapObject_SetPositionVector(object, &position);
}

void MapObject_CreateFromMultipleObjectEvents(MapObjectManager *manager, u32 mapNo, u32 objectEventCount, ObjectEvent *objectEvents) {
    GF_ASSERT(objectEventCount != 0);

    ObjectEvent *objectEventsCopy = Heap_AllocAtEnd(HEAP_ID_FIELD2, objectEventCount * sizeof(ObjectEvent));
    GF_ASSERT(objectEventsCopy != NULL);
    memcpy(objectEventsCopy, objectEvents, objectEventCount * sizeof(ObjectEvent));

    MapObjectInitArgs *args = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(MapObjectInitArgs));
    GF_ASSERT(args != NULL);
    args->mapNo = mapNo;
    args->objectEventCount = objectEventCount;
    args->index = 0;
    args->manager = manager;
    args->objectEvents = objectEventsCopy;

    MapObject_CreateFromInitArgs(args);
}

static void MapObject_CreateFromInitArgs(MapObjectInitArgs *args) {
    FieldSystem *fieldSystem = MapObjectManager_GetFieldSystem(args->manager);
    ObjectEvent *objectEvents = args->objectEvents;

    do {
        GF_ASSERT((ObjectEvent_ScriptIDIsUnset(objectEvents) != TRUE && FieldSystem_FlagCheck(fieldSystem, objectEvents->eventFlag) != FALSE) || MapObject_CreateFromObjectEvent(args->manager, objectEvents, args->mapNo) != NULL);

        objectEvents++;
        args->index++;
    } while (args->index < args->objectEventCount);

    Heap_FreeExplicit(HEAP_ID_FIELD2, args->objectEvents);
    Heap_FreeExplicit(HEAP_ID_FIELD2, args);
}

static LocalMapObject *MapObjectManager_GetFirstInactiveObject(MapObjectManager *manager) {
    s32 i = 0;
    s32 count = MapObjectManager_GetObjectCount(manager);
    LocalMapObject *objects = MapObjectManager_GetObjects(manager);

    do {
        if (MapObject_GetFlagsBitsMask(objects, MAPOBJECTFLAG_ACTIVE) == 0) {
            return objects;
        }

        i++;
        objects++;
    } while (i < count);

    return NULL;
}

static LocalMapObject *MapObjectManager_GetFlag25ObjectByIDAndMap(MapObjectManager *manager, u32 id, u32 mapNo) { // find corresponding LMO with ID and mapNo?
    s32 index = 0;
    LocalMapObject *object;

    while (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &object, &index, MAPOBJECTFLAG_ACTIVE) == TRUE) {
        if (MapObject_CheckFlag25(object) == TRUE && MapObject_GetID(object) == id && MapObject_GetFlag25MapID(object) == mapNo) {
            return object;
        }
    }

    return NULL;
}

static void MapObject_CreateUpdateTask(MapObjectManager *manager, LocalMapObject *object) {
    u32 priority = MapObjectManager_GetPriority(manager);
    u32 movement = MapObject_GetMovement(object);
    if (movement == 48 || movement == 50) {
        priority += 2;
    }

    SysTask *task = SysTask_CreateOnMainQueue((SysTaskFunc)MapObject_UpdateTask, object, priority);
    GF_ASSERT(task != NULL);

    MapObject_SetUpdateTask(object, task);
}

static void MapObject_InitFromObjectEvent(LocalMapObject *object, ObjectEvent *objectEvent, FieldSystem *fieldSystem) {
    MapObject_SetID(object, ObjectEvent_GetID(objectEvent));
    MapObject_SetSpriteID(object, FieldSystem_ResolveObjectSpriteID(fieldSystem, ObjectEvent_GetSpriteID(objectEvent)));
    MapObject_SetMovement(object, ObjectEvent_GetMovement(objectEvent));
    MapObject_SetType(object, ObjectEvent_GetType(objectEvent));
    MapObject_SetEventFlag(object, ObjectEvent_GetEventFlag(objectEvent));
    MapObject_SetScriptID(object, ObjectEvent_GetScriptID(objectEvent));
    MapObject_SetInitialFacingDirection(object, ObjectEvent_GetFacingDirection(objectEvent));
    MapObject_SetParam(object, ObjectEvent_GetParam(objectEvent, 0), 0);
    MapObject_SetParam(object, ObjectEvent_GetParam(objectEvent, 1), 1);
    MapObject_SetParam(object, ObjectEvent_GetParam(objectEvent, 2), 2);
    MapObject_SetXRange(object, ObjectEvent_GetXRange(objectEvent));
    MapObject_SetYRange(object, ObjectEvent_GetYRange(objectEvent));

    MapObject_SetPositionVectorFromObjectEvent(object, objectEvent);
}

static void MapObject_SetPositionVectorFromObjectEvent(LocalMapObject *object, ObjectEvent *objectEvent) {
    VecFx32 coords;

    u16 x = ObjectEvent_GetXCoord(objectEvent);
    coords.x = x * FX32_CONST(16) + FX32_CONST(8);
    MapObject_SetInitialX(object, x);
    MapObject_SetPreviousX(object, x);
    MapObject_SetCurrentX(object, x);

    coords.y = ObjectEvent_GetYCoord(objectEvent);
    u32 y = (coords.y >> 3) / FX32_ONE;
    MapObject_SetInitialY(object, y);
    MapObject_SetPreviousY(object, y);
    MapObject_SetCurrentY(object, y);

    u16 z = ObjectEvent_GetZCoord(objectEvent);
    coords.z = z * FX32_CONST(16) + FX32_CONST(8);
    MapObject_SetInitialZ(object, z);
    MapObject_SetPreviousZ(object, z);
    MapObject_SetCurrentZ(object, z);

    MapObject_SetPositionVector(object, &coords);
}

static void MapObject_InitFlagsAndFacing(LocalMapObject *object, MapObjectManager *manager) { // setup facing and flags? also sets manager?
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_UNK12 | MAPOBJECTFLAG_UNK11 | MAPOBJECTFLAG_ACTIVE));
    if (MapObject_ScriptIDIsFFFF(object) == TRUE) {
        MapObject_SetFlag25(object, TRUE);
    }
    MapObject_SetManager(object, manager);
    MapObject_SetFacingDirectionDirect(object, MapObject_GetInitialFacingDirection(object));
    MapObject_SetNextFacingDirection(object, MapObject_GetInitialFacingDirection(object));
    MapObject_ClearHeldMovement(object);
}

static void MapObject_SetMovementCallbacks(LocalMapObject *object) {
    MapObjectMovementCallbacks *callbacks = MapObject_GetMovementCallbacks(MapObject_GetMovement(object));
    MapObject_SetMovementInitCallback(object, MovementCallbacks_GetInit(callbacks));
    MapObject_SetMovementUpdateCallback(object, MovementCallbacks_GetUpdate(callbacks));
    MapObject_SetMovementDeleteCallback(object, MovementCallbacks_GetDelete(callbacks));
}

extern const MapObjectDrawCallbacks gCameraFocusObjectDrawCallbacks;

static void MapObject_SetDrawCallbacks(LocalMapObject *object) {
    u32 spriteId = MapObject_GetSpriteID(object);
    MapObjectDrawCallbacks *callbacks = (spriteId == SPRITE_CAMERA_FOCUS) ? (MapObjectDrawCallbacks *)&gCameraFocusObjectDrawCallbacks : MapObject_GetDrawCallbacksForSprite(spriteId);

    MapObject_SetDrawInitCallback(object, DrawCallbacks_GetInit(callbacks));
    MapObject_SetDrawUpdateCallback(object, DrawCallbacks_GetUpdate(callbacks));
    MapObject_SetDrawDeleteCallback(object, DrawCallbacks_GetDelete(callbacks));
    MapObject_SetDrawPauseCallback(object, DrawCallbacks_GetPause(callbacks));
    MapObject_SetDrawResumeCallback(object, DrawCallbacks_GetResume(callbacks));
}

static void MapObject_Clear(LocalMapObject *object) {
    memset(object, 0, sizeof(LocalMapObject));
}

static u32 MapObject_MatchObjectEvents(LocalMapObject *object, u32 mapId, u32 objectEventCount, ObjectEvent *objectEvents) {
    for (; objectEventCount != 0; objectEventCount--, objectEvents++) {
        if (ObjectEvent_GetID(objectEvents) != MapObject_GetID(object)) {
            continue;
        }

        if (ObjectEvent_ScriptIDIsUnset(objectEvents) == TRUE) {
            u16 eventFlag = ObjectEvent_GetEventFlag_AssertScriptIDIsUnset(objectEvents);
            if (MapObject_CheckFlag25(object) == TRUE) { // this and the one below cannot be combined as it doesn't match
                if (MapObject_GetFlag25MapID(object) == eventFlag) {
                    return 1;
                }
                // I'm assume that sometimes the ObjectEvent flags equals the mapId to signify that
                // this is a map-wide event etc.
            } else if (MapObject_GetMapID(object) == eventFlag) {
                return 2;
            }
            // this is indeed a weird comparsion, but I checked, it's correct
        } else if (MapObject_CheckFlag25(object) == TRUE && MapObject_GetFlag25MapID(object) == mapId) {
            return 2;
        }
    }

    return 0;
}

static LocalMapObject *MapObjectManager_GetFirstObjectWithIDAndMap(MapObjectManager *manager, u32 objectId, u32 mapId) {
    s32 index = 0;
    LocalMapObject *object;

    while (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &object, &index, MAPOBJECTFLAG_ACTIVE) == TRUE) {
        if (MapObject_GetID(object) == objectId && MapObject_GetMapID(object) == mapId) {
            return object;
        }
    }

    return NULL;
}

LocalMapObject *MapObjectManager_GetFirstActiveObjectByID(MapObjectManager *manager, u32 id) {
    GF_ASSERT(manager != NULL);

    s32 count = MapObjectManager_GetObjectCount(manager);
    LocalMapObject *objects = MapObjectManager_GetObjects3(manager);
    do {
        if (MapObject_TestFlagsBits(objects, MAPOBJECTFLAG_ACTIVE) == TRUE && MapObject_CheckFlag25(objects) == FALSE && MapObject_GetID(objects) == id) {
            return objects;
        }

        count--;
        objects++;
    } while (count > 0);

    return NULL;
}

LocalMapObject *MapObjectManager_GetFirstActiveObjectWithMovement(MapObjectManager *manager, u32 movement) {
    s32 count = MapObjectManager_GetObjectCount(manager);
    LocalMapObject *objects = MapObjectManager_GetObjects3(manager);

    do {
        if (MapObject_TestFlagsBits(objects, MAPOBJECTFLAG_ACTIVE) == TRUE && MapObject_GetMovement(objects) == movement) {
            return objects;
        }

        count--;
        objects++;
    } while (count > 0);

    return NULL;
}

BOOL MapObjectManager_GetNextObjectWithFlagFromIndex(MapObjectManager *manager, LocalMapObject **objectDest, s32 *index, MapObjectFlagBits flag) {
    s32 count = MapObjectManager_GetObjectCount(manager);
    if (*index >= count) {
        return FALSE;
    }

    LocalMapObject *objects = MapObjectManager_GetObjects3(manager);
    LocalMapObject *object = objects + *index;
    do {
        (*index)++;

        if (flag == (MapObjectFlagBits)MapObject_GetFlagsBitsMask(object, flag)) {
            *objectDest = object;
            return TRUE;
        }

        object++;
    } while (*index < count);

    return FALSE;
}

static void MapObject_SetStartMovementAndClearFlags(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_START_MOVEMENT);
    MapObject_ClearFlags15_20_24_26(object);
}

static void MapObject_ClearFlags15_20_24_26(LocalMapObject *object) {
    MapObject_ClearFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_UNK26 | MAPOBJECTFLAG_UNK24 | MAPOBJECTFLAG_UNK20 | MAPOBJECTFLAG_UNK15));
}

static void MapObject_NoOp(LocalMapObject *object) {
    // NoOp
}

static u32 FieldSystem_ResolveObjectSpriteID(FieldSystem *fieldSystem, s32 spriteId) {
    // BUG: index out of range, should be < not <=
    // TODO: check these with sprite constants, these should be variable sprites but this starts at 101 not 100
    if (spriteId >= 101 && spriteId <= 117) {
        spriteId = FieldSystem_VarGetObjectEventGraphicsId(fieldSystem, (u16)(spriteId - 101));
    }
    return spriteId;
}

static void MapObject_UpdateHeightIfNeeded(LocalMapObject *object) {
    if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK12) != 0) {
        MapObject_UpdateHeight(object);
    }
}

static void MapObject_InitMovement(LocalMapObject *object) {
    MapObject_SetMovementCallbacks(object);
    MapObject_CallMovementAndBehaviorInit(object);
}

static void MapObject_InitDraw(LocalMapObject *object) {
    if (!MapObjectManager_IsRenderInitialized(MapObject_GetManager(object))) {
        return;
    }

    MapObject_UpdateHeightIfNeeded(object);
    MapObject_SetAnimation(object, 0);
    MapObject_SetBillboardPending(object, FALSE);
    if (!MapObject_CheckFlag14(object)) {
        MapObject_SetDrawCallbacks(object);
        MapObject_CallDrawInit(object);
        MapObject_SetFlag14(object);
    }
}

static BOOL MapObject_ScriptIDIsFFFF(LocalMapObject *object) {
    u16 script = MapObject_GetScriptID(object);
    return script == 0xFFFF;
}

static void MapObject_ClearFlag25AndSetFromObjectEvent(LocalMapObject *object, ObjectEvent *objectEvent, u32 mapNo) {
    GF_ASSERT(MapObject_CheckFlag25(object) == TRUE);

    MapObject_SetFlag25(object, FALSE);
    MapObject_SetMapID(object, mapNo);
    MapObject_SetScriptID(object, ObjectEvent_GetScriptID(objectEvent));
    MapObject_SetEventFlag(object, ObjectEvent_GetEventFlag(objectEvent));
}

static void MapObject_SetFlag25FromObjectEvent(LocalMapObject *object, u32 mapNo, ObjectEvent *objectEvent) {
    GF_ASSERT(ObjectEvent_ScriptIDIsUnset(objectEvent) == TRUE);

    MapObject_SetFlag25(object, TRUE);
    MapObject_SetScriptID(object, ObjectEvent_GetScriptID(objectEvent));
    MapObject_SetEventFlag(object, ObjectEvent_GetEventFlag_AssertScriptIDIsUnset(objectEvent));
    MapObject_SetMapID(object, mapNo);
}

u32 MapObject_GetPriorityPlusValue(LocalMapObject *object, u32 value) {
    return (u32)((void *)MapObject_GetPriority(object) + value); // MUST be cast to void * to match
}

BOOL MapObject_CheckIDAndMap(LocalMapObject *object, u32 objectId, u32 mapId) {
    if (!MapObject_TestFlagsBits(object, MAPOBJECTFLAG_ACTIVE)) {
        return FALSE;
    }

    if (MapObject_GetID(object) != objectId) {
        return FALSE;
    }

    if (MapObject_GetMapID(object) != mapId) {
        if (!MapObject_CheckFlag25(object)) {
            return FALSE;
        }

        if (MapObject_GetFlag25MapID(object) != mapId) {
            return FALSE;
        }
    }

    return TRUE;
}

BOOL MapObject_CheckSpriteIDAndMap(LocalMapObject *object, u32 spriteId, u32 objectId, u32 mapId) {
    if (!MapObject_TestFlagsBits(object, MAPOBJECTFLAG_ACTIVE)) {
        return FALSE;
    }

    u32 objectSpriteId = MapObject_GetSpriteID(object);
    if (objectSpriteId != spriteId) {
        return FALSE;
    }

    return MapObject_CheckIDAndMap(object, objectId, mapId);
}

static void MapObject_UpdateTask(SysTask *task, LocalMapObject *object) {
    MapObject_UpdateMovement(object);
    if (MapObject_CheckActive(object)) {
        MapObject_UpdateDrawIfRenderReady(object);
    }
}

static void MapObject_UpdateDrawIfRenderReady(LocalMapObject *object) {
    if (MapObjectManager_IsRenderInitialized(MapObject_GetManager(object)) == TRUE) {
        MapObject_TryUpdateDraw(object);
    }
}

// Likely a scrubbed debug func, but WTF is GF smoking?
static MapObjectManager *MapObjectManager_Get(MapObjectManager *manager) {
    return manager;
}

static void MapObjectManager_SetObjectCount(MapObjectManager *manager, u32 count) {
    manager->objectCount = count;
}

u32 MapObjectManager_GetObjectCount(MapObjectManager *manager) {
    return manager->objectCount;
}

static void MapObjectManager_IncrementActiveCount(MapObjectManager *manager) {
    manager->activeCount++;
}

static void MapObjectManager_DecrementActiveCount(MapObjectManager *manager) {
    manager->activeCount--;
}

void MapObjectManager_SetFlagsBits(MapObjectManager *manager, MapObjectFlagBits bits) {
    manager->flags |= bits;
}

void MapObjectManager_ClearFlagsBits(MapObjectManager *manager, MapObjectFlagBits bits) {
    manager->flags &= ~bits;
}

u32 MapObjectManager_GetFlagsBitsMask(MapObjectManager *manager, MapObjectFlagBits bits) {
    return manager->flags & bits;
}

static void MapObjectManager_SetPriority(MapObjectManager *manager, u32 priority) {
    manager->priority = priority;
}

u32 MapObjectManager_GetPriority(MapObjectManager *manager) {
    return manager->priority;
}

// type of unk18 is unknown, it's a u32 in MapObjectManager, but unsure what it's supposed to be
// leaving return as a void * to reflect this
void *MapObjectManager_GetRender(MapObjectManager *manager) {
    return &manager->render;
}

static void MapObjectManager_SetObjects(MapObjectManager *manager, LocalMapObject *objects) {
    manager->objects = objects;
}

// the 2 here is bad, however this is *exactly* the same as the lower GetObjects
LocalMapObject *MapObjectManager_GetObjects2(MapObjectManager *manager) {
    return manager->objects;
}

// same as above
static LocalMapObject *MapObjectManager_GetObjects3(MapObjectManager *manager) {
    return manager->objects;
}

// this one is the original because it's used the most
LocalMapObject *MapObjectManager_GetObjects(MapObjectManager *manager) {
    return manager->objects;
}

void MapObjectArray_NextObject(LocalMapObject **objects) {
    (*objects)++;
}

// exactly the same as GetObjects2, bad naming, but exactly the same as the other one
void MapObjectArray_NextObject2(LocalMapObject **objects) {
    (*objects)++;
}

static void MapObjectManager_SetFieldSystem(MapObjectManager *manager, FieldSystem *fieldSystem) {
    manager->fieldSystem = fieldSystem;
}

FieldSystem *MapObjectManager_GetFieldSystem(MapObjectManager *manager) {
    return manager->fieldSystem;
}

void MapObjectManager_SetMapModelNarc(MapObjectManager *manager, NARC *mapModelNarc) {
    manager->mapModelNarc = mapModelNarc;
}

NARC *MapObjectManager_GetMapModelNarc(MapObjectManager *manager) {
    GF_ASSERT(manager->mapModelNarc != NULL);
    return manager->mapModelNarc;
}

static void MapObject_SetFlags(LocalMapObject *object, u32 flags) {
    object->flags = flags;
}

u32 MapObject_GetFlags(LocalMapObject *object) {
    return object->flags;
}

void MapObject_SetFlagsBits(LocalMapObject *object, MapObjectFlagBits bits) {
    object->flags |= bits;
}

void MapObject_ClearFlagsBits(LocalMapObject *object, MapObjectFlagBits bits) {
    object->flags &= ~bits;
}

u32 MapObject_GetFlagsBitsMask(LocalMapObject *object, MapObjectFlagBits bits) {
    return object->flags & bits;
}

BOOL MapObject_TestFlagsBits(LocalMapObject *object, MapObjectFlagBits bits) {
    return (object->flags & bits) != 0;
}

static void MapObject_SetFlags2(LocalMapObject *object, u32 flags) {
    object->flags2 = flags;
}

static u32 MapObject_GetFlags2(LocalMapObject *object) {
    return object->flags2;
}

static u32 MapObject_GetFlags2BitsMask(LocalMapObject *object, u32 bits) {
    return object->flags2 & bits;
}

void MapObject_SetID(LocalMapObject *object, u32 id) {
    object->id = id;
}

u32 MapObject_GetID(LocalMapObject *object) {
    return object->id;
}

static void MapObject_SetMapID(LocalMapObject *object, u32 mapId) {
    object->mapId = mapId;
}

u32 MapObject_GetMapID(LocalMapObject *object) {
    return object->mapId;
}

void MapObject_SetSpriteID(LocalMapObject *object, u32 spriteId) {
    object->spriteId = spriteId;
}

u32 MapObject_GetSpriteID(LocalMapObject *object) {
    return object->spriteId;
}

static void MapObject_SetMovement(LocalMapObject *object, u32 movement) {
    object->movement = movement;
}

u32 MapObject_GetMovement(LocalMapObject *object) {
    return object->movement;
}

void MapObject_SetType(LocalMapObject *object, u32 type) {
    object->type = type;
}

u32 MapObject_GetType(LocalMapObject *object) {
    return object->type;
}

void MapObject_SetEventFlag(LocalMapObject *object, u32 eventFlag) {
    object->eventFlag = eventFlag;
}

u32 MapObject_GetEventFlag(LocalMapObject *object) {
    return object->eventFlag;
}

void MapObject_SetScriptID(LocalMapObject *object, u32 scriptId) {
    object->scriptId = scriptId;
}

u32 MapObject_GetScriptID(LocalMapObject *object) {
    return object->scriptId;
}

static void MapObject_SetInitialFacingDirection(LocalMapObject *object, u32 initialFacing) {
    object->initialFacing = initialFacing;
}

u32 MapObject_GetInitialFacingDirection(LocalMapObject *object) {
    return object->initialFacing;
}

void MapObject_SetFacingDirectionDirect(LocalMapObject *object, u32 direction) {
    object->previousFacing = object->currentFacing;
    object->currentFacing = direction;
}

void MapObject_SetFacingDirection(LocalMapObject *object, u32 direction) {
    if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK7) == 0) {
        object->previousFacing = object->currentFacing;
        object->currentFacing = direction;
    }
}

u32 MapObject_GetFacingDirection(LocalMapObject *object) {
    return object->currentFacing;
}

u32 MapObject_GetPreviousFacingDirection(LocalMapObject *object) {
    return object->previousFacing;
}

void MapObject_SetNextFacingDirection(LocalMapObject *object, u32 direction) {
    object->nextFacingBackup = object->nextFacing;
    object->nextFacing = direction;
}

u32 MapObject_GetNextFacingDirection(LocalMapObject *object) {
    return object->nextFacing;
}

void MapObject_SetOrQueueFacing(LocalMapObject *object, u32 direction) {
    MapObject_SetFacingDirection(object, direction);
    MapObject_SetNextFacingDirection(object, direction);
}

void MapObject_SetParam(LocalMapObject *object, s32 value, u32 param) {
    switch (param) {
    case 0:
        object->param[0] = value;
        return;
    case 1:
        object->param[1] = value;
        return;
    case 2:
        object->param[2] = value;
        return;
    default:
        GF_ASSERT(FALSE);
        return;
    }
}

s32 MapObject_GetParam(LocalMapObject *object, u32 param) {
    switch (param) {
    case 0:
        return object->param[0];
    case 1:
        return object->param[1];
    case 2:
        return object->param[2];
    default:
        GF_ASSERT(FALSE);
        return 0;
    }
}

void MapObject_SetXRange(LocalMapObject *object, s32 xRange) {
    object->xRange = xRange;
}

s32 MapObject_GetXRange(LocalMapObject *object) {
    return object->xRange;
}

void MapObject_SetYRange(LocalMapObject *object, s32 yRange) {
    object->yRange = yRange;
}

s32 MapObject_GetYRange(LocalMapObject *object) {
    return object->yRange;
}

void MapObject_SetAnimation(LocalMapObject *object, u32 animation) {
    object->animation = animation;
}

u32 MapObject_GetAnimation(LocalMapObject *object) {
    return object->animation;
}

static void MapObject_SetUpdateTask(LocalMapObject *object, SysTask *sysTask) {
    object->updateTask = sysTask;
}

static SysTask *MapObject_GetUpdateTask(LocalMapObject *object) {
    return object->updateTask;
}

static void MapObject_DestroyUpdateTask(LocalMapObject *object) {
    SysTask_Destroy(MapObject_GetUpdateTask(object));
}

static void MapObject_SetManager(LocalMapObject *object, MapObjectManager *manager) {
    object->manager = manager;
}

MapObjectManager *MapObject_GetManager(LocalMapObject *object) {
    return object->manager;
}

static MapObjectManager *MapObject_GetManagerFromManager(LocalMapObject *object) {
    return MapObjectManager_Get(object->manager);
}

void *MapObject_InitMovementData(LocalMapObject *object, s32 size) {
    GF_ASSERT(size <= 16);

    u8 *ret = MapObject_GetMovementData(object);
    memset(ret, 0, size);
    return ret;
}

void *MapObject_GetMovementData(LocalMapObject *object) {
    return object->movementData;
}

void *MapObject_InitBehaviorData(LocalMapObject *object, s32 size) {
    GF_ASSERT(size <= 16);

    u8 *ret = MapObject_GetBehaviorData(object);
    memset(ret, 0, size);
    return ret;
}

void *MapObject_GetBehaviorData(LocalMapObject *object) {
    return object->behaviorData;
}

void *MapObject_InitMovementCmdData(LocalMapObject *object, s32 size) {
    GF_ASSERT(size <= 16);

    u8 *ret = MapObject_GetMovementCmdData(object);
    memset(ret, 0, size);
    return ret;
}

void *MapObject_GetMovementCmdData(LocalMapObject *object) {
    return object->movementCmdData;
}

void *MapObject_InitDrawData(LocalMapObject *object, s32 size) {
    GF_ASSERT(size <= 32);

    u8 *ret = MapObject_GetDrawData(object);
    memset(ret, 0, size);
    return ret;
}

void *MapObject_GetDrawData(LocalMapObject *object) {
    return object->drawData;
}

static void MapObject_SetMovementInitCallback(LocalMapObject *object, LocalMapObject_Callback callback) {
    object->movementInit = callback;
}

void MapObject_CallMovementInit(LocalMapObject *object) {
    object->movementInit(object);
}

static void MapObject_SetMovementUpdateCallback(LocalMapObject *object, LocalMapObject_Callback callback) {
    object->movementUpdate = callback;
}

void MapObject_CallMovementUpdate(LocalMapObject *object) {
    object->movementUpdate(object);
}

static void MapObject_SetMovementDeleteCallback(LocalMapObject *object, LocalMapObject_Callback callback) {
    object->movementDelete = callback;
}

static void MapObject_CallMovementDelete(LocalMapObject *object) {
    object->movementDelete(object);
}

static void MapObject_CallMovementRestore(LocalMapObject *object) {
    MapObjectMovementCallbacks *callbacks = MapObject_GetMovementCallbacks(MapObject_GetMovement(object));
    callbacks->restore(object);
}

static void MapObject_SetDrawInitCallback(LocalMapObject *object, LocalMapObject_Callback callback) {
    object->drawInit = callback;
}

static void MapObject_CallDrawInit(LocalMapObject *object) {
    object->drawInit(object);
}

void MapObject_SetDrawUpdateCallback(LocalMapObject *object, LocalMapObject_Callback callback) {
    object->drawUpdate = callback;
}

void MapObject_CallDrawUpdate(LocalMapObject *object) {
    object->drawUpdate(object);
}

static void MapObject_SetDrawDeleteCallback(LocalMapObject *object, LocalMapObject_Callback callback) {
    object->drawDelete = callback;
}

static void MapObject_CallDrawDelete(LocalMapObject *object) {
    object->drawDelete(object);
}

static void MapObject_SetDrawPauseCallback(LocalMapObject *object, LocalMapObject_Callback callback) {
    object->drawPause = callback;
}

static void MapObject_CallDrawPause(LocalMapObject *object) {
    object->drawPause(object);
}

static void MapObject_SetDrawResumeCallback(LocalMapObject *object, LocalMapObject_Callback callback) {
    object->drawResume = callback;
}

void MapObject_CallDrawResume(LocalMapObject *object) {
    object->drawResume(object);
}

void MapObject_SetMovementCommand(LocalMapObject *object, u32 command) {
    object->movementCmd = command;
}

u32 MapObject_GetMovementCommand(LocalMapObject *object) {
    return object->movementCmd;
}

void MapObject_SetMovementStep(LocalMapObject *object, u32 step) {
    object->movementStep = step;
}

void MapObject_IncrementMovementStep(LocalMapObject *object) {
    object->movementStep++;
}

u32 MapObject_GetMovementStep(LocalMapObject *object) {
    return object->movementStep;
}

void MapObject_SetCurrentMetatileBehavior(LocalMapObject *object, u16 behavior) {
    object->currentBehavior = behavior;
}

u16 MapObject_GetCurrentMetatileBehavior(LocalMapObject *object) {
    return object->currentBehavior;
}

void MapObject_SetPreviousMetatileBehavior(LocalMapObject *object, u16 behavior) {
    object->previousBehavior = behavior;
}

u16 MapObject_GetPreviousMetatileBehavior(LocalMapObject *object) {
    return object->previousBehavior;
}

void MapObject_SetSavedPreviousBehavior(LocalMapObject *object, u16 behavior) {
    object->savedPreviousBehavior = behavior;
}

u16 MapObject_GetSavedPreviousBehavior(LocalMapObject *object) {
    return object->savedPreviousBehavior;
}

FieldSystem *MapObject_GetFieldSystem(LocalMapObject *object) {
    return MapObjectManager_GetFieldSystem(MapObject_GetManagerFromManager(object));
}

u32 MapObject_GetPriority(LocalMapObject *object) {
    return MapObjectManager_GetPriority(MapObject_GetManager(object));
}

u32 MapObject_GetFlag25MapID(LocalMapObject *object) {
    GF_ASSERT(MapObject_CheckFlag25(object) == TRUE);
    return MapObject_GetEventFlag(object);
}

void MapObjectManager_SuspendMovement(MapObjectManager *manager) {
    MapObjectManager_SetFlagsBits(manager, (MapObjectFlagBits)(MAPOBJECTFLAG_START_MOVEMENT | MAPOBJECTFLAG_SINGLE_MOVEMENT));
}

void MapObjectManager_ResumeMovement(MapObjectManager *manager) {
    MapObjectManager_ClearFlagsBits(manager, (MapObjectFlagBits)(MAPOBJECTFLAG_START_MOVEMENT | MAPOBJECTFLAG_SINGLE_MOVEMENT));
}

void MapObjectManager_PauseAllMovement(MapObjectManager *manager) {
    u32 count = MapObjectManager_GetObjectCount(manager);
    LocalMapObject *objects = MapObjectManager_GetObjects(manager);
    do {
        if (MapObject_CheckActive(objects)) {
            MapObject_PauseMovement(objects);
        }

        objects++;
        count--;
    } while (count > 0);
}

void MapObjectManager_UnpauseAllMovement(MapObjectManager *manager) {
    u32 count = MapObjectManager_GetObjectCount(manager);
    LocalMapObject *objects = MapObjectManager_GetObjects(manager);
    do {
        if (MapObject_CheckActive(objects)) {
            MapObject_UnpauseMovement(objects);
        }

        objects++;
        count--;
    } while (count > 0);
}

BOOL MapObjectManager_IsRenderInitialized(MapObjectManager *manager) {
    return MapObjectManager_GetFlagsBitsMask(manager, MAPOBJECTFLAG_ACTIVE) != 0;
}

u32 MapObject_GetManagerFlagsBitsMask(LocalMapObject *object, MapObjectFlagBits bits) {
    return MapObjectManager_GetFlagsBitsMask(MapObject_GetManager(object), bits);
}

void MapObjectManager_SetEndMovement(MapObjectManager *manager, BOOL clear) {
    if (clear == FALSE) {
        MapObjectManager_SetFlagsBits(manager, MAPOBJECTFLAG_END_MOVEMENT);
    } else {
        MapObjectManager_ClearFlagsBits(manager, MAPOBJECTFLAG_END_MOVEMENT);
    }
}

BOOL MapObjectManager_NotEndMovement(MapObjectManager *manager) {
    return MapObjectManager_GetFlagsBitsMask(manager, MAPOBJECTFLAG_END_MOVEMENT) == FALSE;
}

BOOL MapObject_CheckActive(LocalMapObject *object) {
    return MapObject_TestFlagsBits(object, MAPOBJECTFLAG_ACTIVE);
}

void MapObject_SetSingleMovement(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_SINGLE_MOVEMENT);
}

void MapObject_ClearSingleMovement(LocalMapObject *object) {
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_SINGLE_MOVEMENT);
}

BOOL MapObject_CheckSingleMovement(LocalMapObject *object) {
    return MapObject_TestFlagsBits(object, MAPOBJECTFLAG_SINGLE_MOVEMENT);
}

void MapObject_SetStartMovement(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_START_MOVEMENT);
}

void MapObject_ClearEndMovement(LocalMapObject *object) {
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_END_MOVEMENT);
}

static void MapObject_SetFlag14(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK14);
}

BOOL MapObject_CheckFlag14(LocalMapObject *object) {
    return MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK14);
}

BOOL MapObject_CheckInvisible(LocalMapObject *object) {
    return MapObject_TestFlagsBits(object, MAPOBJECTFLAG_INVISIBLE);
}

void MapObject_SetInvisible(LocalMapObject *object, BOOL invisible) {
    if (invisible == TRUE) {
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_INVISIBLE);
    } else {
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_INVISIBLE);
    }
}

void MapObject_ClearFlag18(LocalMapObject *object, BOOL clear) {
    if (clear == TRUE) {
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK18);
    } else {
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK18);
    }
}

BOOL MapObject_CheckFlag19Disabled(LocalMapObject *object) {
    return MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK19) != TRUE;
}

void MapObject_SetFlag19(LocalMapObject *object, BOOL set) {
    if (set == TRUE) {
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK19);
    } else {
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK19);
    }
}

void MapObject_PauseMovement(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_MOVEMENT_PAUSED);
}

void MapObject_UnpauseMovement(LocalMapObject *object) {
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_MOVEMENT_PAUSED);
}

BOOL MapObject_CheckMovementPaused(LocalMapObject *object) {
    if (MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK30) == TRUE) {
        return TRUE;
    }

    if (MapObject_TestFlagsBits(object, MAPOBJECTFLAG_MOVEMENT_PAUSED) == TRUE) {
        return TRUE;
    }

    return FALSE;
}

BOOL MapObject_IsDrawInitialized(LocalMapObject *object) {
    if (!MapObjectManager_IsRenderInitialized(MapObject_GetManager(object))) {
        return FALSE;
    }

    if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK14) != 0) {
        return TRUE;
    }

    return FALSE;
}

void MapObject_SetIgnoreHeights(LocalMapObject *object, BOOL set) {
    if (set == TRUE) {
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_IGNORE_HEIGHTS);
    } else {
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_IGNORE_HEIGHTS);
    }
}

BOOL MapObject_CheckIgnoreHeights(LocalMapObject *object) {
    return MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_IGNORE_HEIGHTS) != 0;
}

void MapObject_SetKeep(LocalMapObject *object, BOOL set) {
    if (set == TRUE) {
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_KEEP);
    } else {
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_KEEP);
    }
}

static void MapObject_SetFlag25(LocalMapObject *object, BOOL set) {
    if (set == TRUE) {
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK25);
    } else {
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK25);
    }
}

BOOL MapObject_CheckFlag25(LocalMapObject *object) {
    return MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK25) != 0;
}

void MapObject_SetFlag26(LocalMapObject *object, BOOL set) {
    if (set == TRUE) {
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK26);
    } else {
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK26);
    }
}

BOOL MapObject_CheckFlag26(LocalMapObject *object) {
    return MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK26) != 0;
}

void MapObject_SetFlag28(LocalMapObject *object, BOOL set) {
    if (set == TRUE) {
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK28);
    } else {
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK28);
    }
}

BOOL MapObject_CheckFlag28(LocalMapObject *object) {
    return MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK28) != 0;
}

void MapObject_SetFlag24(LocalMapObject *object, BOOL set) {
    if (set == TRUE) {
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK24);
    } else {
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK24);
    }
}

BOOL MapObject_CheckFlag24(LocalMapObject *object) {
    return MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK24) != 0;
}

BOOL MapObject_CheckFlag4(LocalMapObject *object) {
    return MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK4) != 0;
}

void MapObject_SetFlag29(LocalMapObject *object, BOOL set) {
    if (set == TRUE) {
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK29);
    } else {
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK29);
    }
}

BOOL MapObject_CheckFlag29(LocalMapObject *object) {
    return MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK29) != 0;
}

BOOL MapObject_CheckIgnoreMetatileBehaviors(LocalMapObject *object) {
    return MapObject_GetFlags2BitsMask(object, 1 << 2) != FALSE;
}

u32 MapObject_GetInitialX(LocalMapObject *object) {
    return object->initialX;
}

static void MapObject_SetInitialX(LocalMapObject *object, u32 initialX) {
    object->initialX = initialX;
}

u32 MapObject_GetInitialY(LocalMapObject *object) {
    return object->initialY;
}

static void MapObject_SetInitialY(LocalMapObject *object, u32 initialY) {
    object->initialY = initialY;
}

u32 MapObject_GetInitialZ(LocalMapObject *object) {
    return object->initialZ;
}

static void MapObject_SetInitialZ(LocalMapObject *object, u32 initialY) {
    object->initialZ = initialY;
}

u32 MapObject_GetPreviousXCoord(LocalMapObject *object) {
    return object->previousX;
}

void MapObject_SetPreviousX(LocalMapObject *object, u32 previousX) {
    object->previousX = previousX;
}

u32 MapObject_GetPreviousYCoord(LocalMapObject *object) {
    return object->previousY;
}

void MapObject_SetPreviousY(LocalMapObject *object, u32 previousY) {
    object->previousY = previousY;
}

u32 MapObject_GetPreviousZCoord(LocalMapObject *object) {
    return object->previousZ;
}

void MapObject_SetPreviousZ(LocalMapObject *object, u32 previousZ) {
    object->previousZ = previousZ;
}

u32 MapObject_GetXCoord(LocalMapObject *object) {
    return object->currentX;
}

void MapObject_SetCurrentX(LocalMapObject *object, u32 currentX) {
    object->currentX = currentX;
}

void MapObject_AddCurrentX(LocalMapObject *object, u32 currentX) {
    object->currentX += currentX;
}

s32 MapObject_GetYCoord(LocalMapObject *object) {
    return object->currentY;
}

void MapObject_SetCurrentY(LocalMapObject *object, s32 currentY) {
    object->currentY = currentY;
}

void MapObject_AddCurrentY(LocalMapObject *object, s32 currentY) {
    object->currentY += currentY;
}

u32 MapObject_GetZCoord(LocalMapObject *object) {
    return object->currentZ;
}

void MapObject_SetCurrentZ(LocalMapObject *object, u32 currentZ) {
    object->currentZ = currentZ;
}

void MapObject_AddCurrentZ(LocalMapObject *object, u32 currentZ) {
    object->currentZ += currentZ;
}

void MapObject_CopyPositionVector(LocalMapObject *object, VecFx32 *positionVector) {
    *positionVector = object->positionVector;
}

void MapObject_SetPositionVector(LocalMapObject *object, VecFx32 *pos_vec) {
    object->positionVector = *pos_vec;
}

VecFx32 *MapObject_GetPositionVector(LocalMapObject *object) {
    return &object->positionVector;
}

fx32 MapObject_GetPositionVectorYCoord(LocalMapObject *object) {
    return object->positionVector.y;
}

void MapObject_CopyFacingVector(LocalMapObject *object, VecFx32 *facingVector) {
    *facingVector = object->facingVector;
}

void MapObject_SetFacingVector(LocalMapObject *object, VecFx32 *facingVector) {
    object->facingVector = *facingVector;
}

VecFx32 *MapObject_GetFacingVector(LocalMapObject *object) {
    return &object->facingVector;
}

void MapObject_CopyDrawOffset(LocalMapObject *object, VecFx32 *vector) {
    *vector = object->drawOffset;
}

void MapObject_SetDrawOffset(LocalMapObject *object, VecFx32 *vector) {
    object->drawOffset = *vector;
}

void MapObject_CopyTileDrawOffset(LocalMapObject *object, VecFx32 *vector) {
    *vector = object->tileDrawOffset;
}

void MapObject_SetTileDrawOffset(LocalMapObject *object, VecFx32 *vector) {
    object->tileDrawOffset = *vector;
}

u32 MapObject_GetPositionVectorYCoordUInt(LocalMapObject *object) {
    fx32 y = MapObject_GetPositionVectorYCoord(object);
    return (y >> 3) / FX32_ONE;
}

static void ObjectEvent_SetID(ObjectEvent *objectEvent, u16 id) {
    objectEvent->id = id;
}

static u16 ObjectEvent_GetID(ObjectEvent *objectEvent) {
    return objectEvent->id;
}

static void ObjectEvent_SetSpriteID(ObjectEvent *objectEvent, u32 spriteId) {
    objectEvent->spriteId = spriteId;
}

static u16 ObjectEvent_GetSpriteID(ObjectEvent *objectEvent) {
    return objectEvent->spriteId;
}

static void ObjectEvent_SetMovement(ObjectEvent *objectEvent, u32 movement) {
    objectEvent->movement = movement;
}

static u16 ObjectEvent_GetMovement(ObjectEvent *objectEvent) {
    return objectEvent->movement;
}

static void ObjectEvent_SetType(ObjectEvent *objectEvent, u16 type) {
    objectEvent->type = type;
}

static u16 ObjectEvent_GetType(ObjectEvent *objectEvent) {
    return objectEvent->type;
}

static void ObjectEvent_SetEventFlag(ObjectEvent *objectEvent, u16 eventFlag) {
    objectEvent->eventFlag = eventFlag;
}

static u16 ObjectEvent_GetEventFlag(ObjectEvent *objectEvent) {
    return objectEvent->eventFlag;
}

static void ObjectEvent_SetScriptID(ObjectEvent *objectEvent, u16 scriptId) {
    objectEvent->scriptId = scriptId;
}

static u16 ObjectEvent_GetScriptID(ObjectEvent *objectEvent) {
    return objectEvent->scriptId;
}

static void ObjectEvent_SetFacingDirection(ObjectEvent *objectEvent, u32 facingDirection) {
    objectEvent->facingDirection = facingDirection;
}

static s16 ObjectEvent_GetFacingDirection(ObjectEvent *objectEvent) {
    return objectEvent->facingDirection;
}

static void ObjectEvent_SetParam(ObjectEvent *objectEvent, s32 value, u32 param) {
    switch (param) {
    case 0:
        objectEvent->param[0] = value;
        return;
    case 1:
        objectEvent->param[1] = value;
        return;
    case 2:
        objectEvent->param[2] = value;
        return;
    default:
        GF_ASSERT(FALSE);
        return;
    }
}

static u16 ObjectEvent_GetParam(ObjectEvent *objectEvent, u32 param) {
    switch (param) {
    case 0:
        return objectEvent->param[0];
    case 1:
        return objectEvent->param[1];
    case 2:
        return objectEvent->param[2];
    default:
        GF_ASSERT(FALSE);
        return 0;
    }
}

static void ObjectEvent_SetXRange(ObjectEvent *objectEvent, s16 xRange) {
    objectEvent->xRange = xRange;
}

static s16 ObjectEvent_GetXRange(ObjectEvent *objectEvent) {
    return objectEvent->xRange;
}

static void ObjectEvent_SetYRange(ObjectEvent *objectEvent, s16 yRange) {
    objectEvent->yRange = yRange;
}

static s16 ObjectEvent_GetYRange(ObjectEvent *objectEvent) {
    return objectEvent->yRange;
}

static void ObjectEvent_SetXCoord(ObjectEvent *objectEvent, u32 x) {
    objectEvent->x = x;
}

static u16 ObjectEvent_GetXCoord(ObjectEvent *objectEvent) {
    return objectEvent->x;
}

static void ObjectEvent_SetYCoord(ObjectEvent *objectEvent, u32 y) {
    objectEvent->y = y;
}

static u32 ObjectEvent_GetYCoord(ObjectEvent *objectEvent) {
    return objectEvent->y;
}

static void ObjectEvent_SetZCoord(ObjectEvent *objectEvent, u32 z) {
    objectEvent->z = z;
}

static u16 ObjectEvent_GetZCoord(ObjectEvent *objectEvent) {
    return objectEvent->z;
}

static ObjectEvent *ObjectEvent_GetByID(u16 id, s32 objectEventCount, ObjectEvent *objectEvents) {
    s32 i = 0;
    ObjectEvent *objectEvent = objectEvents;
    do {
        if (!ObjectEvent_ScriptIDIsUnset(objectEvent) && id == ObjectEvent_GetID(objectEvent)) {
            return objectEvents + i;
        }

        i++;
        objectEvent++;
    } while (i < objectEventCount);

    return NULL;
}

static BOOL ObjectEvent_ScriptIDIsUnset(ObjectEvent *objectEvent) {
    // casts required to match
    u16 script = (u16)(u32)ObjectEvent_GetScriptID(objectEvent);
    return script == 0xFFFF;
}

static u16 ObjectEvent_GetEventFlag_AssertScriptIDIsUnset(ObjectEvent *template) {
    GF_ASSERT(ObjectEvent_ScriptIDIsUnset(template) == TRUE);
    return ObjectEvent_GetEventFlag(template);
}

static MapObjectMovementCallbacks *MapObject_GetMovementCallbacks(u32 movement) {
    GF_ASSERT(movement < NELEMS(gMapObjectMovementCallbacks));
    return gMapObjectMovementCallbacks[movement];
}

static LocalMapObject_Callback MovementCallbacks_GetInit(MapObjectMovementCallbacks *callbackStruct) {
    return callbackStruct->init;
}

static LocalMapObject_Callback MovementCallbacks_GetUpdate(MapObjectMovementCallbacks *callbackStruct) {
    return callbackStruct->update;
}

static LocalMapObject_Callback MovementCallbacks_GetDelete(MapObjectMovementCallbacks *callbackStruct) {
    return callbackStruct->delete;
}

static LocalMapObject_Callback DrawCallbacks_GetInit(MapObjectDrawCallbacks *callbackStruct) {
    return callbackStruct->init;
}

static LocalMapObject_Callback DrawCallbacks_GetUpdate(MapObjectDrawCallbacks *callbackStruct) {
    return callbackStruct->update;
}

static LocalMapObject_Callback DrawCallbacks_GetDelete(MapObjectDrawCallbacks *callbackStruct) {
    return callbackStruct->delete;
}

static LocalMapObject_Callback DrawCallbacks_GetPause(MapObjectDrawCallbacks *callbackStruct) {
    return callbackStruct->pause;
}

static LocalMapObject_Callback DrawCallbacks_GetResume(MapObjectDrawCallbacks *callbackStruct) {
    return callbackStruct->resume;
}

static MapObjectDrawCallbacks *MapObject_GetDrawCallbacksForSprite(u32 spriteId) {
    ObjectEventGraphicsInfo *graphicsInfo = ObjectEvent_GetGraphicsInfo(spriteId);
    if (graphicsInfo == NULL) {
        return NULL;
    }

    return gMapObjectDrawCallbacks[graphicsInfo->drawCallbacksIdx];
}

LocalMapObject *MapObjectManager_GetFirstObjectWithXAndZ(MapObjectManager *manager, u32 x, u32 z, BOOL checkPrevious) {
    u32 count = MapObjectManager_GetObjectCount(manager);
    LocalMapObject *objects = MapObjectManager_GetObjects(manager);

    do {
        if (MapObject_GetFlagsBitsMask(objects, MAPOBJECTFLAG_ACTIVE) != 0) {
            if (checkPrevious && x == MapObject_GetPreviousXCoord(objects) && z == MapObject_GetPreviousZCoord(objects)) {
                return objects;
            }

            if (x == MapObject_GetXCoord(objects) && z == MapObject_GetZCoord(objects)) {
                return objects;
            }
        }

        objects++;
        count--;
    } while (count > 0);

    return NULL;
}

void MapObject_SetPositionFromVectorAndDirection(LocalMapObject *object, VecFx32 *positionVector, u32 direction) {
    MapObject_SetCurrentX(object, (positionVector->x >> 4) / FX32_ONE);
    MapObject_SetCurrentY(object, (positionVector->y >> 3) / FX32_ONE);
    MapObject_SetCurrentZ(object, (positionVector->z >> 4) / FX32_ONE);
    MapObject_SetPositionVector(object, positionVector);
    MapObject_SetPreviousCoordsToCurrent(object);
    MapObject_SetFacingDirectionDirect(object, direction);
    MapObject_ClearHeldMovement(object);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_START_MOVEMENT);
    MapObject_ClearFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_END_MOVEMENT | MAPOBJECTFLAG_SINGLE_MOVEMENT));
}

void MapObject_SetPositionFromXYZAndDirection(LocalMapObject *object, u32 x, u32 y, u32 z, u32 direction) {
    VecFx32 positionVector;
    positionVector.x = x * (16 * FX32_ONE) + (8 * FX32_ONE);
    MapObject_SetCurrentX(object, x);
    positionVector.y = y * (8 * FX32_ONE);
    MapObject_SetCurrentY(object, y);
    positionVector.z = z * (16 * FX32_ONE) + (8 * FX32_ONE);
    MapObject_SetCurrentZ(object, z);

    MapObject_SetPositionVector(object, &positionVector);
    MapObject_SetPreviousCoordsToCurrent(object);
    MapObject_SetFacingDirectionDirect(object, direction);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_START_MOVEMENT);
    MapObject_ClearFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_END_MOVEMENT | MAPOBJECTFLAG_SINGLE_MOVEMENT));
    MapObject_ClearHeldMovement(object);
}

void MapObject_ChangeMovement(LocalMapObject *object, u32 movement) {
    MapObject_CallMovementDelete(object);
    MapObject_SetMovement(object, movement);
    MapObject_SetMovementCallbacks(object);
    MapObject_CallMovementAndBehaviorInit(object);
}

void MapObjectMovement_NoOpInit(LocalMapObject *object) {
}

void MapObjectMovement_NoOpUpdate(LocalMapObject *object) {
}

void MapObjectMovement_NoOpDelete(LocalMapObject *object) {
}

void MapObjectMovement_NoOpRestore(LocalMapObject *object) {
}

void MapObjectDraw_NoOpInit(LocalMapObject *object) {
}

void MapObjectDraw_NoOpUpdate(LocalMapObject *object) {
}

void MapObjectDraw_NoOpPause(LocalMapObject *object) {
}

void MapObjectDraw_NoOpResume(LocalMapObject *object) {
}

void MapObject_RestoreDrawUpdateCallback(LocalMapObject *object) {
    u32 spriteId = MapObject_GetSpriteID(object);
    MapObjectDrawCallbacks *callbackStruct = (spriteId == 0x2000) ? (MapObjectDrawCallbacks *)&gCameraFocusObjectDrawCallbacks : MapObject_GetDrawCallbacksForSprite(spriteId);
    MapObject_SetDrawUpdateCallback(object, DrawCallbacks_GetUpdate(callbackStruct));
}

SavedMapObject *SaveMapObject_GetFirstObjectWithSpriteID(SavedMapObject *objects, u32 count, u16 spriteId) {
    for (; count > 0; objects++, count--) {
        if ((objects->flags & MAPOBJECTFLAG_ACTIVE) != 0 && objects->spriteId == spriteId) {
            return objects;
        }
    }

    return NULL;
}
