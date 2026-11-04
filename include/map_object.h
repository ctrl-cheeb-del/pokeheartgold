#ifndef POKEHEARTGOLD_MAP_OBJECT_H
#define POKEHEARTGOLD_MAP_OBJECT_H

#include "field_types_def.h"

typedef struct SavedMapObject {
    u32 flags;
    u32 flags2;
    u8 objId;
    u8 movement;
    s8 xRange;
    s8 yRange;
    s8 initialFacing;
    s8 currentFacing;
    s8 nextFacing;
    u16 mapId;
    u16 spriteId;
    u16 type;
    u16 eventFlag;
    u16 script;
    s16 param[3];
    s16 initialX;
    s16 initialY;
    s16 initialZ;
    s16 currentX;
    s16 currentY;
    s16 currentZ;
    fx32 vecY;
    u8 movementData[16];
    u8 behaviorData[16];
} SavedMapObject;

struct MapObjectManager { // declared field_system.h
    u32 flags;
    u32 objectCount;
    u32 activeCount;
    u32 priority;
    u8 unk10[4];
    NARC *mapModelNarc;
    u32 render;
    u8 unk1C[0x108];
    LocalMapObject *objects;
    FieldSystem *fieldSystem;
}; // size: 0x12c

typedef void (*LocalMapObject_Callback)(LocalMapObject *object);

struct LocalMapObject { // declared field_system.h
    /*0x000*/ u32 flags;
    /*0x004*/ u32 flags2;
    /*0x008*/ u32 id;
    /*0x00C*/ u32 mapId;
    /*0x010*/ u32 spriteId;
    /*0x014*/ u32 movement;
    /*0x018*/ u32 type;
    /*0x01C*/ u32 eventFlag;
    /*0x020*/ u32 scriptId;
    /*0x024*/ u32 initialFacing;
    /*0x028*/ u32 currentFacing;
    /*0x02C*/ u32 nextFacing;
    /*0x030*/ u32 previousFacing;
    /*0x034*/ u32 nextFacingBackup;
    /*0x038*/ s32 param[3];
    /*0x044*/ s32 xRange;
    /*0x048*/ s32 yRange;
    /*0x04C*/ u32 initialX;
    /*0x050*/ u32 initialY;
    /*0x054*/ u32 initialZ;
    /*0x058*/ u32 previousX;
    /*0x05C*/ u32 previousY;
    /*0x060*/ u32 previousZ;
    /*0x064*/ u32 currentX;
    /*0x068*/ s32 currentY;
    /*0x06C*/ u32 currentZ;
    /*0x070*/ VecFx32 positionVector;
    /*0x07C*/ VecFx32 facingVector;
    /*0x088*/ VecFx32 drawOffset;
    /*0x094*/ VecFx32 tileDrawOffset;
    /*0x0A0*/ u32 animation;
    /*0x0A4*/ u32 movementCmd;
    /*0x0A8*/ u32 movementStep;
    /*0x0AC*/ u16 currentBehavior;
    /*0x0AE*/ u16 previousBehavior;
    /*0x0B0*/ SysTask *updateTask;
    /*0x0B4*/ MapObjectManager *manager;
    /*0x0B8*/ LocalMapObject_Callback movementInit;
    /*0x0BC*/ LocalMapObject_Callback movementUpdate;
    /*0x0C0*/ LocalMapObject_Callback movementDelete;
    /*0x0C4*/ LocalMapObject_Callback drawInit;
    /*0x0C8*/ LocalMapObject_Callback drawUpdate;
    /*0x0CC*/ LocalMapObject_Callback drawDelete;
    /*0x0D0*/ LocalMapObject_Callback drawPause;
    /*0x0D4*/ LocalMapObject_Callback drawResume;
    /*0x0D8*/ u8 movementData[0x10];
    /*0x0E8*/ u8 behaviorData[0x10];
    /*0x0F8*/ u8 movementCmdData[0x10];
    /*0x108*/ u8 drawData[0x20];
    /*0x128*/ u16 savedPreviousBehavior;
};

typedef struct MapObjectMovementCallbacks {
    u32 unk0;
    LocalMapObject_Callback init;
    LocalMapObject_Callback update;
    LocalMapObject_Callback delete;
    LocalMapObject_Callback restore;
} MapObjectMovementCallbacks;

typedef struct MapObjectDrawCallbacks {
    LocalMapObject_Callback init;
    LocalMapObject_Callback update;
    LocalMapObject_Callback delete;
    LocalMapObject_Callback pause;
    LocalMapObject_Callback resume;
} MapObjectDrawCallbacks;

typedef enum MapObjectFlagBits {
    MAPOBJECTFLAG_NONE = 0,
    MAPOBJECTFLAG_ACTIVE = (1 << 0),
    MAPOBJECTFLAG_SINGLE_MOVEMENT = (1 << 1),
    MAPOBJECTFLAG_START_MOVEMENT = (1 << 2),
    MAPOBJECTFLAG_END_MOVEMENT = (1 << 3),
    MAPOBJECTFLAG_UNK4 = (1 << 4),
    MAPOBJECTFLAG_UNK5 = (1 << 5),
    MAPOBJECTFLAG_MOVEMENT_PAUSED = (1 << 6),
    MAPOBJECTFLAG_UNK7 = (1 << 7),
    MAPOBJECTFLAG_UNK8 = (1 << 8),
    MAPOBJECTFLAG_INVISIBLE = (1 << 9),
    MAPOBJECTFLAG_KEEP = (1 << 10),
    MAPOBJECTFLAG_UNK11 = (1 << 11),
    MAPOBJECTFLAG_UNK12 = (1 << 12),
    MAPOBJECTFLAG_UNK13 = (1 << 13),
    MAPOBJECTFLAG_UNK14 = (1 << 14),
    MAPOBJECTFLAG_UNK15 = (1 << 15),
    MAPOBJECTFLAG_UNK16 = (1 << 16),
    MAPOBJECTFLAG_UNK17 = (1 << 17),
    MAPOBJECTFLAG_UNK18 = (1 << 18),
    MAPOBJECTFLAG_UNK19 = (1 << 19),
    MAPOBJECTFLAG_UNK20 = (1 << 20),
    MAPOBJECTFLAG_UNK21 = (1 << 21),
    MAPOBJECTFLAG_UNK22 = (1 << 22),
    MAPOBJECTFLAG_IGNORE_HEIGHTS = (1 << 23),
    MAPOBJECTFLAG_UNK24 = (1 << 24),
    MAPOBJECTFLAG_UNK25 = (1 << 25),
    MAPOBJECTFLAG_UNK26 = (1 << 26),
    MAPOBJECTFLAG_UNK27 = (1 << 27),
    MAPOBJECTFLAG_UNK28 = (1 << 28),
    MAPOBJECTFLAG_UNK29 = (1 << 29),
    MAPOBJECTFLAG_UNK30 = (1 << 30),
    MAPOBJECTFLAG_UNK31 = (1 << 31),
} MapObjectFlagBits;

#define MAP_OBJECT_GFX_ID_INVALID 0xFFFF

typedef struct MapObjectInitArgs {
    u32 mapNo;
    int objectEventCount;
    int index;
    MapObjectManager *manager;
    ObjectEvent *objectEvents;
} MapObjectInitArgs;

typedef struct ObjectEventGraphicsInfo {
    u16 spriteId;
    u16 mapModelId;
    u16 effectFlagsIdx : 5; // Unknown actual size
    u16 drawCallbacksIdx : 5;
    u16 billboardInfoIdx : 6; // Unknown actual size
} ObjectEventGraphicsInfo;

MapObjectManager *MapObjectManager_Init(FieldSystem *fieldSystem, u32 objectCount, u32 priority);
void MapObjectManager_Delete(MapObjectManager *manager);
void MapObjectManager_RemoveObjectsNotOnMap(MapObjectManager *manager, u32 unused, u32 mapId, u32 objectCount, ObjectEvent *objectEvents);
LocalMapObject *MapObject_Create(MapObjectManager *manager, u32 x, u32 z, u32 direction, u32 sprite, u32 movement, u32 mapNo);
LocalMapObject *MapObject_CreateWithParams(MapObjectManager *manager, u32 x, u32 y, u32 direction, u32 sprite, u32 movement, u32 mapNo, u32 param0, u32 param1, u32 param2);
LocalMapObject *MapObject_CreateFromObjectEventWithId(MapObjectManager *mapObjectManager, u16 objectId, u32 numObjects, u32 mapId, const ObjectEvent *templates);
void MapObject_SetSpriteAndInitDraw(LocalMapObject *object, u32 sprite);
void MapObject_ChangeSprite(LocalMapObject *object, u32 sprite);
void MapObject_Remove(LocalMapObject *object);
void MapObject_Delete(LocalMapObject *object);
void MapObject_ClearSprite(LocalMapObject *object);
void MapObjectManager_RemoveAllActiveObjects(MapObjectManager *manager);
void MapObjectManager_PauseAllDraw(MapObjectManager *manager);
void MapObjectManager_ResumeAllDraw(MapObjectManager *manager);
void MapObjectManager_ResumePlayerDraw(MapObjectManager *manager);
void FieldSystem_SyncMapObjectsToSaveEx(FieldSystem *fieldSystem, MapObjectManager *manager, SavedMapObject *savedObjects, s32 count);
void MapObjectManager_RestoreFromSave(MapObjectManager *mapObjectManager, SavedMapObject *savedObjects, u32 objectCount);
void MapObject_CreateFromMultipleObjectEvents(MapObjectManager *manager, u32 mapNo, u32 objectEventCount, ObjectEvent *objectEvents);
LocalMapObject *MapObjectManager_GetFirstActiveObjectByID(MapObjectManager *manager, u32 id);
LocalMapObject *MapObjectManager_GetFirstActiveObjectWithMovement(MapObjectManager *manager, u32 movement);
BOOL MapObjectManager_GetNextObjectWithFlagFromIndex(MapObjectManager *manager, LocalMapObject **objectDest, s32 *index, MapObjectFlagBits flag);
u32 MapObject_GetPriorityPlusValue(LocalMapObject *object, u32 value);
BOOL MapObject_CheckIDAndMap(LocalMapObject *object, u32 objectId, u32 mapId);
BOOL MapObject_CheckSpriteIDAndMap(LocalMapObject *object, u32 spriteId, u32 objectId, u32 mapId);
u32 MapObjectManager_GetObjectCount(MapObjectManager *manager);
void MapObjectManager_SetFlagsBits(MapObjectManager *manager, MapObjectFlagBits bits);
void MapObjectManager_ClearFlagsBits(MapObjectManager *manager, MapObjectFlagBits bits);
u32 MapObjectManager_GetFlagsBitsMask(MapObjectManager *manager, MapObjectFlagBits bits);
u32 MapObjectManager_GetPriority(MapObjectManager *manager);
void *MapObjectManager_GetRender(MapObjectManager *manager);
LocalMapObject *MapObjectManager_GetObjects2(MapObjectManager *manager);
LocalMapObject *MapObjectManager_GetObjects(MapObjectManager *manager);
void MapObjectArray_NextObject(LocalMapObject **objects);
void MapObjectArray_NextObject2(LocalMapObject **objects);
FieldSystem *MapObjectManager_GetFieldSystem(MapObjectManager *manager);
void MapObjectManager_SetMapModelNarc(MapObjectManager *manager, NARC *mapModelNarc);
NARC *MapObjectManager_GetMapModelNarc(MapObjectManager *manager);
u32 MapObject_GetFlags(LocalMapObject *object);
void MapObject_SetFlagsBits(LocalMapObject *object, MapObjectFlagBits bits);
void MapObject_ClearFlagsBits(LocalMapObject *object, MapObjectFlagBits bits);
u32 MapObject_GetFlagsBitsMask(LocalMapObject *object, MapObjectFlagBits bits);
BOOL MapObject_TestFlagsBits(LocalMapObject *object, MapObjectFlagBits bits);
void MapObject_SetID(LocalMapObject *object, u32 id);
u32 MapObject_GetID(LocalMapObject *object);
u32 MapObject_GetMapID(LocalMapObject *object);
void MapObject_SetSpriteID(LocalMapObject *object, u32 spriteId);
u32 MapObject_GetSpriteID(LocalMapObject *object);
u32 MapObject_GetMovement(LocalMapObject *object);
void MapObject_SetType(LocalMapObject *object, u32 type);
u32 MapObject_GetType(LocalMapObject *object);
void MapObject_SetEventFlag(LocalMapObject *object, u32 eventFlag);
u32 MapObject_GetEventFlag(LocalMapObject *object);
void MapObject_SetScriptID(LocalMapObject *object, u32 scriptId);
u32 MapObject_GetScriptID(LocalMapObject *object);
u32 MapObject_GetInitialFacingDirection(LocalMapObject *object);
void MapObject_SetFacingDirectionDirect(LocalMapObject *object, u32 direction);
void MapObject_SetFacingDirection(LocalMapObject *object, u32 direction);
u32 MapObject_GetFacingDirection(LocalMapObject *object);
u32 MapObject_GetPreviousFacingDirection(LocalMapObject *object);
void MapObject_SetNextFacingDirection(LocalMapObject *object, u32 direction);
u32 MapObject_GetNextFacingDirection(LocalMapObject *object);
void MapObject_SetOrQueueFacing(LocalMapObject *object, u32 direction);
void MapObject_SetParam(LocalMapObject *object, s32 value, u32 param);
s32 MapObject_GetParam(LocalMapObject *object, u32 param);
void MapObject_SetXRange(LocalMapObject *object, s32 xRange);
s32 MapObject_GetXRange(LocalMapObject *object);
void MapObject_SetYRange(LocalMapObject *object, s32 yRange);
s32 MapObject_GetYRange(LocalMapObject *object);
void MapObject_SetAnimation(LocalMapObject *object, u32 animation);
u32 MapObject_GetAnimation(LocalMapObject *object);
MapObjectManager *MapObject_GetManager(LocalMapObject *object);
void *MapObject_InitMovementData(LocalMapObject *object, s32 size);
void *MapObject_GetMovementData(LocalMapObject *object);
void *MapObject_InitBehaviorData(LocalMapObject *object, s32 size);
void *MapObject_GetBehaviorData(LocalMapObject *object);
void *MapObject_InitMovementCmdData(LocalMapObject *object, s32 size);
void *MapObject_GetMovementCmdData(LocalMapObject *object);
void *MapObject_InitDrawData(LocalMapObject *object, s32 size);
void *MapObject_GetDrawData(LocalMapObject *object);
void MapObject_CallMovementInit(LocalMapObject *object);
void MapObject_CallMovementUpdate(LocalMapObject *object);
void MapObject_SetDrawUpdateCallback(LocalMapObject *object, LocalMapObject_Callback callback);
void MapObject_CallDrawUpdate(LocalMapObject *object);
void MapObject_CallDrawResume(LocalMapObject *object);
void MapObject_SetMovementCommand(LocalMapObject *object, u32 command);
u32 MapObject_GetMovementCommand(LocalMapObject *object);
void MapObject_SetMovementStep(LocalMapObject *object, u32 step);
void MapObject_IncrementMovementStep(LocalMapObject *object);
u32 MapObject_GetMovementStep(LocalMapObject *object);
void MapObject_SetCurrentMetatileBehavior(LocalMapObject *object, u16 behavior);
u16 MapObject_GetCurrentMetatileBehavior(LocalMapObject *object);
void MapObject_SetPreviousMetatileBehavior(LocalMapObject *object, u16 behavior);
u16 MapObject_GetPreviousMetatileBehavior(LocalMapObject *object);
void MapObject_SetSavedPreviousBehavior(LocalMapObject *object, u16 behavior);
u16 MapObject_GetSavedPreviousBehavior(LocalMapObject *object);
FieldSystem *MapObject_GetFieldSystem(LocalMapObject *object);
u32 MapObject_GetPriority(LocalMapObject *object);
u32 MapObject_GetFlag25MapID(LocalMapObject *object);
void MapObjectManager_SuspendMovement(MapObjectManager *manager);
void MapObjectManager_ResumeMovement(MapObjectManager *manager);
void MapObjectManager_PauseAllMovement(MapObjectManager *manager);
void MapObjectManager_UnpauseAllMovement(MapObjectManager *manager);
BOOL MapObjectManager_IsRenderInitialized(MapObjectManager *manager);
u32 MapObject_GetManagerFlagsBitsMask(LocalMapObject *object, MapObjectFlagBits bits);
void MapObjectManager_SetEndMovement(MapObjectManager *manager, BOOL clear);
BOOL MapObjectManager_NotEndMovement(MapObjectManager *manager);
BOOL MapObject_CheckActive(LocalMapObject *object);
void MapObject_SetSingleMovement(LocalMapObject *object);
void MapObject_ClearSingleMovement(LocalMapObject *object);
BOOL MapObject_CheckSingleMovement(LocalMapObject *object);
void MapObject_SetStartMovement(LocalMapObject *object);
void MapObject_ClearEndMovement(LocalMapObject *object);
BOOL MapObject_CheckFlag14(LocalMapObject *object);
BOOL MapObject_CheckInvisible(LocalMapObject *object);
void MapObject_SetInvisible(LocalMapObject *object, BOOL invisible);
void MapObject_ClearFlag18(LocalMapObject *object, BOOL clear);
BOOL MapObject_CheckFlag19Disabled(LocalMapObject *object);
void MapObject_SetFlag19(LocalMapObject *object, BOOL set);
void MapObject_PauseMovement(LocalMapObject *object);
void MapObject_UnpauseMovement(LocalMapObject *object);
BOOL MapObject_CheckMovementPaused(LocalMapObject *object);
BOOL MapObject_IsDrawInitialized(LocalMapObject *object);
void MapObject_SetIgnoreHeights(LocalMapObject *object, BOOL set);
BOOL MapObject_CheckIgnoreHeights(LocalMapObject *object);
void MapObject_SetKeep(LocalMapObject *object, BOOL set);
BOOL MapObject_CheckFlag25(LocalMapObject *object);
void MapObject_SetFlag26(LocalMapObject *object, BOOL set);
BOOL MapObject_CheckFlag26(LocalMapObject *object);
void MapObject_SetFlag28(LocalMapObject *object, BOOL set);
BOOL MapObject_CheckFlag28(LocalMapObject *object);
void MapObject_SetFlag24(LocalMapObject *object, BOOL set);
BOOL MapObject_CheckFlag24(LocalMapObject *object);
BOOL MapObject_CheckFlag4(LocalMapObject *object);
void MapObject_SetFlag29(LocalMapObject *object, BOOL set);
BOOL MapObject_CheckFlag29(LocalMapObject *object);
BOOL MapObject_CheckIgnoreMetatileBehaviors(LocalMapObject *object);
u32 MapObject_GetInitialX(LocalMapObject *object);
u32 MapObject_GetInitialY(LocalMapObject *object);
u32 MapObject_GetInitialZ(LocalMapObject *object);
u32 MapObject_GetPreviousXCoord(LocalMapObject *object);
void MapObject_SetPreviousX(LocalMapObject *object, u32 previousX);
u32 MapObject_GetPreviousYCoord(LocalMapObject *object);
void MapObject_SetPreviousY(LocalMapObject *object, u32 previousY);
u32 MapObject_GetPreviousZCoord(LocalMapObject *object);
void MapObject_SetPreviousZ(LocalMapObject *object, u32 previousZ);
u32 MapObject_GetXCoord(LocalMapObject *object);
void MapObject_SetCurrentX(LocalMapObject *object, u32 currentX);
void MapObject_AddCurrentX(LocalMapObject *object, u32 currentX);
s32 MapObject_GetYCoord(LocalMapObject *object);
void MapObject_SetCurrentY(LocalMapObject *object, s32 currentY);
void MapObject_AddCurrentY(LocalMapObject *object, s32 currentY);
u32 MapObject_GetZCoord(LocalMapObject *object);
void MapObject_SetCurrentZ(LocalMapObject *object, u32 currentZ);
void MapObject_AddCurrentZ(LocalMapObject *object, u32 currentZ);
void MapObject_CopyPositionVector(LocalMapObject *object, VecFx32 *positionVector);
void MapObject_SetPositionVector(LocalMapObject *object, VecFx32 *positionVector);
VecFx32 *MapObject_GetPositionVector(LocalMapObject *object);
fx32 MapObject_GetPositionVectorYCoord(LocalMapObject *object);
void MapObject_CopyFacingVector(LocalMapObject *object, VecFx32 *facingVector);
void MapObject_SetFacingVector(LocalMapObject *object, VecFx32 *facingVector);
VecFx32 *MapObject_GetFacingVector(LocalMapObject *object);
void MapObject_CopyDrawOffset(LocalMapObject *object, VecFx32 *vector);
void MapObject_SetDrawOffset(LocalMapObject *object, VecFx32 *vector);
void MapObject_CopyTileDrawOffset(LocalMapObject *object, VecFx32 *vector);
void MapObject_SetTileDrawOffset(LocalMapObject *object, VecFx32 *vector);
u32 MapObject_GetPositionVectorYCoordUInt(LocalMapObject *object);
LocalMapObject *MapObjectManager_GetFirstObjectWithXAndZ(MapObjectManager *manager, u32 x, u32 z, BOOL checkPrevious);
void MapObject_SetPositionFromVectorAndDirection(LocalMapObject *object, VecFx32 *positionVector, u32 direction);
void MapObject_SetPositionFromXYZAndDirection(LocalMapObject *object, u32 x, u32 y, u32 z, u32 direction);
void MapObject_ChangeMovement(LocalMapObject *object, u32 movement);
void MapObjectMovement_NoOpInit(LocalMapObject *object);
void MapObjectMovement_NoOpUpdate(LocalMapObject *object);
void MapObjectMovement_NoOpDelete(LocalMapObject *object);
void MapObjectMovement_NoOpRestore(LocalMapObject *object);
void MapObjectDraw_NoOpInit(LocalMapObject *object);
void MapObjectDraw_NoOpUpdate(LocalMapObject *object);
void MapObjectDraw_NoOpPause(LocalMapObject *object);
void MapObjectDraw_NoOpResume(LocalMapObject *object);
void MapObject_RestoreDrawUpdateCallback(LocalMapObject *object);
SavedMapObject *SaveMapObject_GetFirstObjectWithSpriteID(SavedMapObject *list, u32 num_objects, u16 sprite_id);

#endif // POKEHEARTGOLD_MAP_OBJECT_H
