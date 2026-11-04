#include "field_tall_grass.h"

#include "global.h"

#include "constants/field/field_effect_renderer.h"

#include "field/field_effect_helpers.h"
#include "field/field_effect_manager.h"

#include "billboard_lists.h"
#include "field_effects.h"
#include "map_object.h"
#include "map_object_movement_utilities.h"
#include "overlay_01.h"

// The tall grass a map object stands in: a billboard over the tile that rustles when the object walks in, then holds
// its last frame until the object leaves the tile.

#define TALL_GRASS_RECORD 0

enum TallGrassEffectState {
    TALL_GRASS_STATE_SHAKE,
    TALL_GRASS_STATE_STOP,
    TALL_GRASS_STATE_WAIT,
};

struct TallGrass {
    FieldEffectManager *manager;
};

typedef struct TallGrassEffectArgs {
    int x;
    int y;
    int z;
    FieldSystem *fieldSystem;
    FieldEffectManager *manager;
    TallGrass *grass;
    LocalMapObject *mapObject;
    s16 dx; // tile offset of the map object from the grass tile
    s16 dz;
    s8 direction; // -1: any facing
} TallGrassEffectArgs;

typedef struct TallGrassEffect {
    enum TallGrassEffectState state;
    u32 spriteId;
    u32 objectId;
    u32 mapId;
    u8 unk_10[4];
    BOOL onGround;
    TallGrassEffectArgs args;
    BillboardObject *billboard;
} TallGrassEffect;

typedef struct TallGrassUnusedEffectArgs {
    int x;
    int z;
    FieldSystem *fieldSystem;
    FieldEffectManager *manager;
    u8 unk_10[4];
} TallGrassUnusedEffectArgs;

typedef struct TallGrassUnusedEffect {
    int state;
    BOOL done;
    u8 unk_08[4];
    int kind;
    TallGrassUnusedEffectArgs args;
    BillboardObject *billboard;
} TallGrassUnusedEffect;

static void TallGrass_LoadGfx(TallGrass *grass);
static void TallGrass_FreeGfx(TallGrass *grass);
BOOL TallGrassEffect_Init(FieldEffect *effect, TallGrassEffect *work);
BOOL TallGrassEffect_Destroy(FieldEffect *effect, TallGrassEffect *work);
void TallGrassEffect_Update(FieldEffect *effect, TallGrassEffect *work);
void TallGrassEffect_Draw(FieldEffect *effect, TallGrassEffect *work);
BOOL TallGrassUnusedEffect_Init(FieldEffect *effect, TallGrassUnusedEffect *work);
BOOL TallGrassUnusedEffect_Destroy(FieldEffect *effect, TallGrassUnusedEffect *work);
void TallGrassUnusedEffect_Update(FieldEffect *effect, TallGrassUnusedEffect *work);
void TallGrassUnusedEffect_Draw(FieldEffect *effect, TallGrassUnusedEffect *work);

static const BillboardSequenceRange sTallGrassRecord5Ranges[2] = {
    { 0, 40, 1 },
    { 0, 0,  2 },
};

static const BillboardSequenceRange sTallGrassRanges[2] = {
    { 0, 12, 0 },
    { 0, 0,  2 },
};

static const BillboardSequenceRange sTallGrassRecord6Ranges[2] = {
    { 0, 24, 1 },
    { 0, 0,  2 },
};

static const BillboardSequenceRange sTallGrassRecord7Ranges[2] = {
    { 0, 40, 1 },
    { 0, 0,  2 },
};

TallGrass *TallGrass_New(FieldEffectManager *manager) {
    TallGrass *grass = FieldEffectManager_HeapAllocAndFill(manager, sizeof(TallGrass), FALSE, 0);
    grass->manager = manager;
    TallGrass_LoadGfx(grass);
    return grass;
}

void TallGrass_Free(TallGrass *grass) {
    TallGrass_FreeGfx(grass);
    FieldEffectManager_HeapFree(grass);
}

static void TallGrass_LoadGfx(TallGrass *grass) {
    FieldEffectManager_LoadBillboardResource(grass->manager, 0, 0x7E);
    FieldEffectManager_LoadBillboardResource(grass->manager, 5, 0x7F);
    FieldEffectManager_LoadBillboardSequence(grass->manager, 0, 0x8C);
    FieldEffectManager_LoadBillboardSequence(grass->manager, 3, 0x8D);
    FieldEffectManager_LoadBillboardSequence(grass->manager, 4, 0x8E);
    FieldEffectManager_LoadBillboardSequence(grass->manager, 5, 0x8F);
    FieldEffectManager_LoadTexResource(grass->manager, 0, 0x19, TRUE);
    FieldEffectManager_LoadTexResource(grass->manager, 4, 0x10, TRUE);
    FieldEffectManager_LoadTexResource(grass->manager, 5, 0, TRUE);
    FieldEffectManager_LoadTexResource(grass->manager, 6, 1, TRUE);
    FieldEffectManager_AddRecord(grass->manager, TALL_GRASS_RECORD, 0, 0, 0, 0, sTallGrassRanges);
    FieldEffectManager_AddRecord(grass->manager, 5, 5, 3, 4, 0, sTallGrassRecord5Ranges);
    FieldEffectManager_AddRecord(grass->manager, 6, 5, 4, 5, 0, sTallGrassRecord6Ranges);
    FieldEffectManager_AddRecord(grass->manager, 7, 5, 5, 6, 0, sTallGrassRecord7Ranges);
}

static void TallGrass_FreeGfx(TallGrass *grass) {
    FieldEffectManager_FreeBillboardResource(grass->manager, 0);
    FieldEffectManager_FreeBillboardResource(grass->manager, 5);
    FieldEffectManager_FreeBillboardSequence(grass->manager, 0);
    FieldEffectManager_FreeBillboardSequence(grass->manager, 3);
    FieldEffectManager_FreeBillboardSequence(grass->manager, 4);
    FieldEffectManager_FreeBillboardSequence(grass->manager, 5);
    FieldEffectManager_FreeTexResource(grass->manager, 0);
    FieldEffectManager_FreeTexResource(grass->manager, 4);
    FieldEffectManager_FreeTexResource(grass->manager, 5);
    FieldEffectManager_FreeTexResource(grass->manager, 6);
    FieldEffectManager_ReleaseRecord(grass->manager, TALL_GRASS_RECORD);
    FieldEffectManager_ReleaseRecord(grass->manager, 5);
    FieldEffectManager_ReleaseRecord(grass->manager, 6);
    FieldEffectManager_ReleaseRecord(grass->manager, 7);
}

void TallGrass_Spawn(LocalMapObject *mapObject, BOOL animate) {
    VecFx32 position;
    TallGrassEffectArgs args;
    FieldEffectManager *manager = FieldEffectManager_GetFromMapObject(mapObject);

    args.x = MapObject_GetXCoord(mapObject);
    args.y = MapObject_GetYCoord(mapObject);
    args.z = MapObject_GetZCoord(mapObject);
    args.dx = 0;
    args.dz = 0;
    args.direction = -1;
    args.manager = manager;
    args.fieldSystem = FieldEffectManager_GetFieldSystem(manager);
    args.grass = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_TALL_GRASS);
    args.mapObject = mapObject;
    MapObject_CopyPositionVector(mapObject, &position);
    FieldEffectManager_CreateEffect(manager, &gTallGrassEffectTemplate, &position, animate, &args, MapObject_GetPriorityPlusValue(mapObject, 2));
}

FieldEffect *TallGrass_SpawnAt(LocalMapObject *mapObject, BOOL animate, int x, int z, BOOL checkFacing) {
    VecFx32 position;
    TallGrassEffectArgs args;
    FieldEffectManager *manager = FieldEffectManager_GetFromMapObject(mapObject);

    args.x = x;
    args.y = MapObject_GetYCoord(mapObject);
    args.z = z;
    args.dx = MapObject_GetXCoord(mapObject) - x;
    args.dz = MapObject_GetZCoord(mapObject) - z;
    if (checkFacing) {
        args.direction = MapObject_GetFacingDirection(mapObject);
    } else {
        args.direction = -1;
    }
    args.manager = manager;
    args.fieldSystem = FieldEffectManager_GetFieldSystem(manager);
    args.grass = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_TALL_GRASS);
    args.mapObject = mapObject;
    MapObject_CopyPositionVector(mapObject, &position);
    return FieldEffectManager_CreateEffect(manager, &gTallGrassEffectTemplate, &position, animate, &args, MapObject_GetPriorityPlusValue(mapObject, 2));
}

BOOL TallGrassEffect_Init(FieldEffect *effect, TallGrassEffect *work) {
    VecFx32 position;

    TallGrassEffectArgs *args = FieldEffect_GetUserData(effect);

    work->args = *args;
    work->spriteId = MapObject_GetSpriteID(work->args.mapObject);
    work->objectId = MapObject_GetID(work->args.mapObject);
    work->mapId = MapObject_GetMapID(work->args.mapObject);
    position.x = work->args.x << 16;
    position.z = work->args.z << 16;
    position.y = MapObject_GetPositionVectorYCoord(work->args.mapObject);
    work->onGround = FieldSystem_SnapToTerrainHeight(work->args.fieldSystem, &position);
    position.x = position.x + FX32_CONST(8);
    position.z = position.z + FX32_CONST(18);
    FieldEffect_SetPosition(effect, &position);
    work->billboard = FieldEffectManager_CreateBillboardFromRecord(work->args.manager, TALL_GRASS_RECORD, &position);
    if (MapObject_TestFlagsBits(work->args.mapObject, MAPOBJECTFLAG_INVISIBLE) == TRUE) {
        BillboardObject_SetVisible(work->billboard, FALSE);
    }
    if (!FieldEffect_GetParam(effect)) {
        BillboardObject_SetFrame(work->billboard, 12 * FX32_ONE);
        work->state = TALL_GRASS_STATE_WAIT;
    }
    return TRUE;
}

BOOL TallGrassEffect_Destroy(FieldEffect *effect, TallGrassEffect *work) {
    return BillboardObject_Delete(work->billboard);
}

void TallGrassEffect_Update(FieldEffect *effect, TallGrassEffect *work) {
    VecFx32 current;
    VecFx32 position;
    LocalMapObject *mapObject = work->args.mapObject;
    int x;
    int z;

    if (!MapObject_CheckSpriteIDAndMap(mapObject, work->spriteId, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    if (MapObject_TestFlagsBits(mapObject, MAPOBJECTFLAG_INVISIBLE) == TRUE) {
        BillboardObject_SetVisible(work->billboard, FALSE);
    } else {
        BillboardObject_SetVisible(work->billboard, TRUE);
    }
    if (!work->onGround) {
        FieldEffect_GetPosition(effect, &current);
        position.x = work->args.x << 16;
        position.z = work->args.z << 16;
        position.y = current.y;
        work->onGround = FieldSystem_SnapToTerrainHeight(work->args.fieldSystem, &position);
        if (work->onGround == TRUE) {
            current.y = position.y;
            FieldEffect_SetPosition(effect, &current);
        }
    }
    switch (work->state) {
    case TALL_GRASS_STATE_SHAKE:
        if (BillboardObject_AdvanceFrame(work->billboard, FX32_ONE) == TRUE) {
        }
        if (BillboardObject_GetSequenceFrame(work->billboard) / FX32_ONE >= 12) {
            work->state = TALL_GRASS_STATE_STOP;
        }
        return;
    case TALL_GRASS_STATE_STOP:
        BillboardObject_SetFrame(work->billboard, 12 * FX32_ONE);
        work->state = TALL_GRASS_STATE_WAIT;
        // fallthrough
    case TALL_GRASS_STATE_WAIT:
        if (!MapObject_CheckSpriteIDAndMap(mapObject, work->spriteId, work->objectId, work->mapId)) {
            FieldEffectManager_DestroyEffect(effect);
            return;
        }
        x = MapObject_GetXCoord(mapObject) - work->args.dx;
        z = MapObject_GetZCoord(mapObject) - work->args.dz;
        if (work->args.x != x || work->args.z != z) {
            FieldEffectManager_DestroyEffect(effect);
            return;
        }
        if (work->args.direction == -1) {
            return;
        }
        if (work->args.direction == MapObject_GetFacingDirection(mapObject)) {
            return;
        }
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
}

void TallGrassEffect_Draw(FieldEffect *effect, TallGrassEffect *work) {
    VecFx32 position;

    if (!MapObject_CheckSpriteIDAndMap(work->args.mapObject, work->spriteId, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    FieldEffect_GetPosition(effect, &position);
    BillboardObject_SetPosition(work->billboard, &position);
}

BOOL TallGrassUnusedEffect_Init(FieldEffect *effect, TallGrassUnusedEffect *work) {
    VecFx32 position;
    int record;

    TallGrassUnusedEffectArgs *args = FieldEffect_GetUserData(effect);

    work->args = *args;
    work->kind = FieldEffect_GetParam(effect);
    position.x = (work->args.x << 16) + FX32_CONST(8);
    position.z = (work->args.z << 16) + FX32_CONST(9);
    position.y = 0;
    FieldSystem_SnapToTerrainHeight(work->args.fieldSystem, &position);
    position.y += FX32_ONE;
    FieldEffect_SetPosition(effect, &position);
    switch (work->kind) {
    case 0:
        record = 5;
        break;
    case 1:
        record = 6;
        break;
    case 2:
    default:
        record = 7;
        break;
    }
    work->billboard = FieldEffectManager_CreateBillboardFromRecord(work->args.manager, record, &position);
    return TRUE;
}

BOOL TallGrassUnusedEffect_Destroy(FieldEffect *effect, TallGrassUnusedEffect *work) {
    return BillboardObject_Delete(work->billboard);
}

void TallGrassUnusedEffect_Update(FieldEffect *effect, TallGrassUnusedEffect *work) {
    switch (work->state) {
    case 0:
        if (BillboardObject_AdvanceFrame(work->billboard, FX32_ONE) == TRUE) {
            work->done = TRUE;
            work->state++;
        }
        break;
    case 1:
        break;
    }
}

void TallGrassUnusedEffect_Draw(FieldEffect *effect, TallGrassUnusedEffect *work) {
    VecFx32 position;

    FieldEffect_GetPosition(effect, &position);
    BillboardObject_SetPosition(work->billboard, &position);
}
