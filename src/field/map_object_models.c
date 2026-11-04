#include "field/map_object_models.h"

#include "global.h"

#include "field/field_effect_helpers.h"
#include "field/field_follow_mon.h"
#include "field/map_object_render.h"

#include "billboard_lists.h"
#include "field_shadow.h"
#include "filesystem.h"
#include "filesystem_files_def.h"
#include "heap.h"

// The work of the Ho-Oh / Lugia objects (SPRITE_HOU_OBJ01, SPRITE_LUG_OBJ01): two looping sequences picked by the
// object's animation number.
typedef struct LegendaryBirdObject {
    BillboardObject *billboard;
    BillboardState savedState;
    u32 sequence;
} LegendaryBirdObject;

typedef void (*LegendaryBirdAnimateFunc)(LocalMapObject *object, BillboardObject *billboard, LegendaryBirdObject *work);

static BOOL FollowMonBillboard_IsBobFrame(u8 direction, LocalMapObject *object, BillboardObject *billboard);
static void LegendaryBirdObject_CreateBillboard(LocalMapObject *object);
static void LegendaryBirdObject_AnimateIdle(LocalMapObject *object, BillboardObject *billboard, LegendaryBirdObject *work);
static void LegendaryBirdObject_AnimateFlap(LocalMapObject *object, BillboardObject *billboard, LegendaryBirdObject *work);
static void LegendaryBirdObject_UpdateVisibility(LocalMapObject *object, BillboardObject *billboard);
static void LegendaryBirdObject_DeleteBillboard(LocalMapObject *object);

// Per sprite id: the graphics info (terminated by spriteId MAP_OBJECT_GFX_ID_INVALID) and the effect flags
// its effectFlagsIdx field selects.

static const LegendaryBirdAnimateFunc sLegendaryBirdAnimateFuncs[] = {
    LegendaryBirdObject_AnimateIdle,
    LegendaryBirdObject_AnimateFlap,
};

static void FldObjSys_OpenMModelNarc(MapObjectManager *manager);
static void FldObjSys_CloseMModelNarc(MapObjectManager *manager);
static const MapObjectEffectFlags *SpriteId_GetEffectFlags(u32 spriteId);

void FollowMonBillboard_Update(LocalMapObject *object, BillboardObject *billboard, FollowMonBillboardWork *billboardWork, u32 direction, BOOL addFacingOffset) {
    BOOL flag4;
    BOOL hasFollowMonSprite;
    BOOL paused;
    VecFx32 offset;

    paused = MapObject_IsBillboardAnimPaused(object);
    flag4 = MapObject_CheckFlag4(object);
    hasFollowMonSprite = MapObject_HasFollowMonSprite(object);
    if (billboardWork->shadowAnchored) {
        MapObject_CopyFacingVector(object, &offset);
        offset.y = billboardWork->height << 12;
    } else {
        if (paused || flag4 || hasFollowMonSprite) {
            MapObject_CopyFacingVector(object, &offset);
            offset.x = 0;
            offset.z = 0;
        } else {
            offset.x = 0;
            offset.y = 0;
            offset.z = 0;
        }
        if (addFacingOffset) {
            FollowMonBillboard_AddFacingOffset(object, direction, &offset);
        }
        offset.y += FollowMon_GetHopHeight(object);
    }
    if (direction != billboardWork->direction) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(direction));
        BillboardObject_SetSequenceFrame(billboard, 0);
        billboardWork->bobbing = 0;
    }
    if (!paused && !flag4) {
        BillboardObject_AdvanceFrame(billboard, FX32_ONE);
        if (FollowMonBillboard_IsBobFrame(direction, object, billboard)) {
            offset.y -= 2 * FX32_ONE;
            billboardWork->bobbing = 1;
        } else {
            billboardWork->bobbing = 0;
        }
    }
    if (flag4) {
        BillboardObject_AdvanceFrame(billboard, FX32_ONE);
    }
    MapObject_SetFacingVector(object, &offset);
}

// Large billboards (billboard kind 10) sit further out to the side and slightly forward / back.
void FollowMonBillboard_AddFacingOffset(LocalMapObject *object, u32 direction, VecFx32 *offset) {
    VecFx32 unused;

    MapObject_CopyFacingVector(object, &unused);
    if (MapObjectRender_GetSpriteModelId(MapObject_GetSpriteID(object)) == 10) {
        switch (direction) {
        case DIR_NORTH:
            offset->z += FX32_ONE;
            break;
        case DIR_SOUTH:
            offset->z -= FX32_ONE;
            break;
        case DIR_WEST:
            offset->x += 10 * FX32_ONE;
            break;
        case DIR_EAST:
            offset->x -= 10 * FX32_ONE;
            break;
        }
    } else {
        switch (direction) {
        case DIR_WEST:
            offset->x += 2 * FX32_ONE;
            break;
        case DIR_EAST:
            offset->x -= 2 * FX32_ONE;
            break;
        }
    }
}

void FollowMonBillboard_SetShadowAnchored(LocalMapObject *object, BOOL anchored) {
    FollowMonBillboardWork *work;
    VecFx32 offset;
    fx32 *coords;

    work = MapObject_GetDrawData(object);
    if (anchored) {
        coords = (fx32 *)&offset;
        coords[0] = 0;
        coords[1] = 0;
        coords[2] = 0;
        work->shadowAnchored = TRUE;
        FieldShadow_OffsetByFacing(MapObject_GetFacingDirection(object), &offset);
        work->shadowOffsetX = offset.x / FX32_ONE;
        work->shadowOffsetZ = offset.z / FX32_ONE;
    } else {
        work->shadowAnchored = FALSE;
        work->shadowOffsetX = 0;
        work->shadowOffsetZ = 0;
    }
}

void FollowMonBillboard_SetHeight(LocalMapObject *object, s8 height) {
    ((FollowMonBillboardWork *)MapObject_GetDrawData(object))->height = height;
}

void FollowMonBillboard_AddHeight(LocalMapObject *object, s8 delta) {
    FollowMonBillboardWork *work = MapObject_GetDrawData(object);
    work->height = work->height + delta;
}

BOOL FollowMonBillboard_IsShadowFollowing(LocalMapObject *object) {
    FollowMonBillboardWork *work = MapObject_GetDrawData(object);
    if (work->shadowAnchored) {
        return FALSE;
    }
    return TRUE;
}

void FollowMonBillboard_GetShadowOffset(LocalMapObject *object, VecFx32 *offset) {
    FollowMonBillboardWork *work = MapObject_GetDrawData(object);
    offset->x = work->shadowOffsetX << 12;
    offset->z = work->shadowOffsetZ << 12;
    offset->y = 0;
}

// Each facing has a 20-frame walk sequence; the billboard dips on some of its frames.
static BOOL FollowMonBillboard_IsBobFrame(u8 direction, LocalMapObject *object, BillboardObject *billboard) {
    int frame = BillboardObject_GetFrame(billboard) / FX32_ONE;

    switch (direction) {
    case DIR_NORTH:
        break;
    case DIR_SOUTH:
        frame -= 20;
        break;
    case DIR_WEST:
        frame -= 40;
        break;
    case DIR_EAST:
        frame -= 60;
        break;
    }
    if (FollowMon_GetShapeParamLow(object)) {
        if (direction == DIR_SOUTH) {
            if (frame < 5 || frame >= 15) {
                return TRUE;
            }
        } else if (frame < 10) {
            return TRUE;
        }
    } else if ((frame >= 5 && frame < 10) || frame >= 15) {
        return TRUE;
    }
    return FALSE;
}

void FollowMonBillboard_LoadSequence(BOOL alternate, LocalMapObject *object) {
    FollowMonBillboardWork *work = MapObject_GetDrawData(object);
    FollowMonBillboard_SetResource(alternate, object, work->billboard);
}

void FollowMonBillboard_ResetPalette(LocalMapObject *object) {
    FollowMonBillboardWork *work = MapObject_GetDrawData(object);
    work->paletteApplied = FALSE;
}

void LegendaryBirdObject_Init(LocalMapObject *object) {
    VecFx32 offset;

    LegendaryBirdObject_CreateBillboard(object);
    offset.x = 0;
    offset.y = 0;
    offset.z = 0;
    MapObject_SetDrawOffset(object, &offset);
}

void LegendaryBirdObject_Update(LocalMapObject *object) {
    LegendaryBirdObject *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;

    if (MapObject_IsBillboardPending(object) == TRUE) {
        return;
    }
    if (billboard == NULL) {
        return;
    }
    sLegendaryBirdAnimateFuncs[MapObject_GetAnimation(object)](object, billboard, work);
    work->sequence = MapObject_GetAnimation(object);
    MapObject_UpdateBillboardPosition(object, billboard);
    LegendaryBirdObject_UpdateVisibility(object, billboard);
}

void LegendaryBirdObject_Delete(LocalMapObject *object) {
    LegendaryBirdObject_DeleteBillboard(object);
}

void LegendaryBirdObject_Pause(LocalMapObject *object) {
    LegendaryBirdObject *work = MapObject_GetDrawData(object);

    if (work->billboard != NULL) {
        BillboardObject_SaveState(work->billboard, &work->savedState);
    }
    MapObject_DeleteBillboard(object, &work->billboard);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK21);
}

void LegendaryBirdObject_Resume(LocalMapObject *object) {
    LegendaryBirdObject *work = MapObject_GetDrawData(object);

    if (MapObject_IsBillboardPending(object) == TRUE) {
        return;
    }
    if (work->billboard == NULL) {
        MapObject_CreateBillboard(object, &work->billboard);
    }
    if (work->billboard != NULL) {
        BillboardObject_RestoreState(work->billboard, &work->savedState);
        MapObject_UpdateBillboardPosition(object, work->billboard);
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK21);
    }
}

static void LegendaryBirdObject_CreateBillboard(LocalMapObject *object) {
    LegendaryBirdObject *work = MapObject_InitDrawData(object, sizeof(LegendaryBirdObject));
    MapObject_CreateBillboard(object, &work->billboard);
}

static void LegendaryBirdObject_AnimateIdle(LocalMapObject *object, BillboardObject *billboard, LegendaryBirdObject *work) {
    if (work->sequence != 0) {
        BillboardObject_SetSequence(billboard, 0);
        BillboardObject_SetSequenceFrame(billboard, 0);
    }
    BillboardObject_AdvanceFrame(billboard, FX32_ONE);
}

static void LegendaryBirdObject_AnimateFlap(LocalMapObject *object, BillboardObject *billboard, LegendaryBirdObject *work) {
    if (work->sequence != 1) {
        BillboardObject_SetSequence(billboard, 1);
        BillboardObject_SetSequenceFrame(billboard, 0);
    }
    BillboardObject_AdvanceFrame(billboard, FX32_ONE);
}

static void LegendaryBirdObject_UpdateVisibility(LocalMapObject *object, BillboardObject *billboard) {
    int visible = TRUE;

    if (MapObject_TestFlagsBits(object, MAPOBJECTFLAG_INVISIBLE) == TRUE) {
        visible = FALSE;
    }
    if (MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK12) == TRUE && !MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK13)) {
        visible = FALSE;
    }
    BillboardObject_SetVisible(billboard, visible);
}

static void LegendaryBirdObject_DeleteBillboard(LocalMapObject *object) {
    LegendaryBirdObject *work = MapObject_GetDrawData(object);
    MapObject_DeleteBillboard(object, &work->billboard);
}

// Manager flag 1: the render data exists.
void MapObjectManager_InitRender(MapObjectManager *mapObjectManager, int textureCount, int objectsToPreload, const int *objectIDs, int loadsPerFrame) {
    u32 count;
    u32 priority;

    if (MapObjectManager_GetFlagsBitsMask(mapObjectManager, MAPOBJECTFLAG_ACTIVE) != 0) {
        GF_ASSERT(FALSE);
    }
    FldObjSys_OpenMModelNarc(mapObjectManager);
    count = MapObjectManager_GetObjectCount(mapObjectManager);
    priority = MapObjectManager_GetPriority(mapObjectManager) - 1;
    MapObjectRender_Init(MapObjectManager_GetRender(mapObjectManager), mapObjectManager, count, priority, textureCount, objectsToPreload, objectIDs, loadsPerFrame);
    MapObjectManager_SetFlagsBits(mapObjectManager, MAPOBJECTFLAG_ACTIVE);
}

void MapObjectManager_FreeRender(MapObjectManager *mapObjectManager) {
    if (MapObjectManager_IsRenderInitialized(mapObjectManager) != TRUE) {
        GF_ASSERT(FALSE);
    }
    MapObjectRender_Free(MapObjectManager_GetRender(mapObjectManager));
    MapObjectManager_ClearFlagsBits(mapObjectManager, MAPOBJECTFLAG_ACTIVE);
    FldObjSys_CloseMModelNarc(mapObjectManager);
}

static void FldObjSys_OpenMModelNarc(MapObjectManager *manager) {
    MapObjectManager_SetMapModelNarc(manager, NARC_New(NARC_data_mmodel_mmodel, HEAP_ID_FIELD1));
}

static void FldObjSys_CloseMModelNarc(MapObjectManager *manager) {
    NARC_Delete(MapObjectManager_GetMapModelNarc(manager));
}

void MapObject_TryUpdateDraw(LocalMapObject *object) {
    if (MapObjectManager_GetFlagsBitsMask(MapObject_GetManager(object), MAPOBJECTFLAG_START_MOVEMENT) != 0) {
        return;
    }
    if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK14) == 0) {
        return;
    }
    if (!MapObject_CheckMovementPaused(object) || MapObject_CheckFlag4(object)) {
        MapObject_CallDrawUpdate(object);
    }
}

ObjectEventGraphicsInfo *ObjectEvent_GetGraphicsInfo(u32 spriteId) {
    ObjectEventGraphicsInfo *info = gObjectEventGraphicsInfos;

    do {
        if (info->spriteId == spriteId) {
            return info;
        }
        info++;
    } while (info->spriteId != MAP_OBJECT_GFX_ID_INVALID);
    GF_ASSERT(FALSE);
    return NULL;
}

int GetMoveModelNoBySpriteId(u32 spriteId) {
    ObjectEventGraphicsInfo *info = ObjectEvent_GetGraphicsInfo(spriteId);
    if (info == NULL) {
        return -1;
    }
    return info->mapModelId;
}

const MapObjectEffectFlags *MapObject_GetEffectFlags(LocalMapObject *object) {
    return SpriteId_GetEffectFlags(MapObject_GetSpriteID(object));
}

static const MapObjectEffectFlags *SpriteId_GetEffectFlags(u32 spriteId) {
    ObjectEventGraphicsInfo *info = ObjectEvent_GetGraphicsInfo(spriteId);
    if (info == NULL) {
        return NULL;
    }
    return &gSpriteEffectFlags[info->effectFlagsIdx];
}

BOOL MapObject_IsBillboardAnimPaused(LocalMapObject *object) {
    if (MapObject_CheckMovementPaused(object) == TRUE && !MapObject_CheckFlag4(object)) {
        return TRUE;
    }
    if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK8) != 0) {
        return TRUE;
    }
    return FALSE;
}

void *ReadMModelFromNarcInternal(MapObjectManager *manager, u32 memberIdx, BOOL atStart) {
    void *dest;
    NARC *narc = MapObjectManager_GetMapModelNarc(manager);
    u32 size = NARC_GetMemberSize(narc, memberIdx);

    if (atStart == TRUE) {
        dest = Heap_Alloc(HEAP_ID_FIELD1, size);
    } else {
        dest = Heap_AllocAtEnd(HEAP_ID_FIELD1, size);
    }
    NARC_ReadWholeMember(narc, memberIdx, dest);
    return dest;
}

void MapObject_GetDrawPosition(LocalMapObject *object, VecFx32 *dest) {
    VecFx32 position;
    VecFx32 facing;
    VecFx32 offset2;
    VecFx32 offset3;

    MapObject_CopyPositionVector(object, &position);
    MapObject_CopyFacingVector(object, &facing);
    MapObject_CopyDrawOffset(object, &offset2);
    MapObject_CopyTileDrawOffset(object, &offset3);
    dest->x = position.x + facing.x + offset2.x + offset3.x;
    dest->y = position.y + facing.y + offset2.y + offset3.y;
    dest->z = position.z + facing.z + offset2.z + offset3.z;
}

void MapObject_SetFacingAndUpdateDraw(LocalMapObject *object, u32 direction) {
    MapObject_SetFacingDirection(object, direction);
    if (MapObject_CheckFlag14(object) == TRUE) {
        MapObject_CallDrawUpdate(object);
    }
}

void CameraFocusObject_Init(LocalMapObject *object) {
    MapObject_SetInvisible(object, TRUE);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK20);
}

void CameraFocusObject_Update(LocalMapObject *object) {
}

void CameraFocusObject_Delete(LocalMapObject *object) {
}

void CameraFocusObject_Pause(LocalMapObject *object) {
}

void CameraFocusObject_Resume(LocalMapObject *object) {
}
