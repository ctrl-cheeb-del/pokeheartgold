#include "field_very_tall_grass.h"

#include "global.h"

#include "constants/field/field_effect_renderer.h"

#include "field/field_effect_helpers.h"
#include "field/field_effect_manager.h"

#include "billboard_lists.h"
#include "field_effects.h"
#include "map_object.h"
#include "map_object_movement_utilities.h"
#include "overlay_01.h"

// The very tall grass a map object stands in: like the tall grass, a billboard over the tile that rustles when the
// object walks in, then holds its last frame until the object leaves the tile.

#define VERY_TALL_GRASS_RECORD   9
#define VERY_TALL_GRASS_RESOURCE 7
#define VERY_TALL_GRASS_SEQUENCE 7
#define VERY_TALL_GRASS_TEXTURE  8

enum VeryTallGrassEffectState {
    VERY_TALL_GRASS_STATE_SHAKE,
    VERY_TALL_GRASS_STATE_STOP,
    VERY_TALL_GRASS_STATE_WAIT,
};

struct VeryTallGrass {
    FieldEffectManager *manager;
};

typedef struct VeryTallGrassEffectArgs {
    int x;
    int y;
    int z;
    FieldSystem *fieldSystem;
    FieldEffectManager *manager;
    VeryTallGrass *grass;
    LocalMapObject *mapObject;
    s16 dx; // tile offset of the map object from the grass tile
    s16 dz;
    s8 direction; // -1: any facing
} VeryTallGrassEffectArgs;

typedef struct VeryTallGrassEffect {
    enum VeryTallGrassEffectState state;
    u32 spriteId;
    u32 objectId;
    u32 mapId;
    u8 unk_10[4];
    BOOL onGround;
    VeryTallGrassEffectArgs args;
    BillboardObject *billboard;
} VeryTallGrassEffect;

static void VeryTallGrass_LoadGfx(VeryTallGrass *grass);
static void VeryTallGrass_FreeGfx(VeryTallGrass *grass);
static BOOL VeryTallGrassEffect_Init(FieldEffect *effect, void *state);
static void VeryTallGrassEffect_Destroy(FieldEffect *effect, void *state);
static void VeryTallGrassEffect_Update(FieldEffect *effect, void *state);
static void VeryTallGrassEffect_Draw(FieldEffect *effect, void *state);

static const FieldEffectBasicTemplate sVeryTallGrassEffectTemplate = {
    sizeof(VeryTallGrassEffect),
    VeryTallGrassEffect_Init,
    VeryTallGrassEffect_Destroy,
    VeryTallGrassEffect_Update,
    VeryTallGrassEffect_Draw,
};

VeryTallGrass *VeryTallGrass_New(FieldEffectManager *manager) {
    VeryTallGrass *grass = FieldEffectManager_HeapAllocAndFill(manager, sizeof(VeryTallGrass), FALSE, 0);
    grass->manager = manager;
    VeryTallGrass_LoadGfx(grass);
    return grass;
}

void VeryTallGrass_Free(VeryTallGrass *grass) {
    VeryTallGrass_FreeGfx(grass);
    FieldEffectManager_HeapFree(grass);
}

static void VeryTallGrass_LoadGfx(VeryTallGrass *grass) {
    FieldEffectManager_LoadBillboardResource(grass->manager, VERY_TALL_GRASS_RESOURCE, 0x7A);
    FieldEffectManager_LoadBillboardSequence(grass->manager, VERY_TALL_GRASS_SEQUENCE, 0x92);
    FieldEffectManager_LoadTexResource(grass->manager, VERY_TALL_GRASS_TEXTURE, 0x15, TRUE);
    FieldEffectManager_AddRecord(grass->manager, VERY_TALL_GRASS_RECORD, VERY_TALL_GRASS_RESOURCE, VERY_TALL_GRASS_SEQUENCE, VERY_TALL_GRASS_TEXTURE, 0, gVeryTallGrassRecordParams);
}

static void VeryTallGrass_FreeGfx(VeryTallGrass *grass) {
    FieldEffectManager_FreeBillboardResource(grass->manager, VERY_TALL_GRASS_RESOURCE);
    FieldEffectManager_FreeBillboardSequence(grass->manager, VERY_TALL_GRASS_SEQUENCE);
    FieldEffectManager_FreeTexResource(grass->manager, VERY_TALL_GRASS_TEXTURE);
    FieldEffectManager_ReleaseRecord(grass->manager, VERY_TALL_GRASS_RECORD);
}

void VeryTallGrass_Spawn(LocalMapObject *mapObject, BOOL animate) {
    VecFx32 position;
    VeryTallGrassEffectArgs args;
    FieldEffectManager *manager = FieldEffectManager_GetFromMapObject(mapObject);

    args.x = MapObject_GetXCoord(mapObject);
    args.y = MapObject_GetYCoord(mapObject);
    args.z = MapObject_GetZCoord(mapObject);
    args.dx = 0;
    args.dz = 0;
    args.direction = -1;
    args.manager = manager;
    args.fieldSystem = FieldEffectManager_GetFieldSystem(manager);
    args.grass = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_VERY_TALL_GRASS);
    args.mapObject = mapObject;
    MapObject_CopyPositionVector(mapObject, &position);
    FieldEffectManager_CreateEffect(manager, &sVeryTallGrassEffectTemplate, &position, animate, &args, MapObject_GetPriorityPlusValue(mapObject, 2));
}

void VeryTallGrass_SpawnAt(LocalMapObject *mapObject, BOOL animate, int x, int z, BOOL checkFacing) {
    VecFx32 position;
    VeryTallGrassEffectArgs args;
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
    args.grass = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_VERY_TALL_GRASS);
    args.mapObject = mapObject;
    MapObject_CopyPositionVector(mapObject, &position);
    FieldEffectManager_CreateEffect(manager, &sVeryTallGrassEffectTemplate, &position, animate, &args, MapObject_GetPriorityPlusValue(mapObject, 2));
}

static BOOL VeryTallGrassEffect_Init(FieldEffect *effect, void *state) {
    VeryTallGrassEffect *work = state;
    VecFx32 position;

    VeryTallGrassEffectArgs *args = FieldEffect_GetUserData(effect);

    work->args = *args;
    work->spriteId = MapObject_GetSpriteID(work->args.mapObject);
    work->objectId = MapObject_GetID(work->args.mapObject);
    work->mapId = MapObject_GetMapID(work->args.mapObject);
    position.x = work->args.x << 16;
    position.z = work->args.z << 16;
    position.y = MapObject_GetPositionVectorYCoord(work->args.mapObject);
    work->onGround = FieldSystem_SnapToTerrainHeight(work->args.fieldSystem, &position);
    position.x += 2 << 14;
    position.z += 0x12 << 12;
    FieldEffect_SetPosition(effect, &position);
    work->billboard = FieldEffectManager_CreateBillboardFromRecord(work->args.manager, VERY_TALL_GRASS_RECORD, &position);
    if (MapObject_TestFlagsBits(work->args.mapObject, MAPOBJECTFLAG_INVISIBLE) == TRUE) {
        BillboardObject_SetVisible(work->billboard, FALSE);
    }
    if (!FieldEffect_GetParam(effect)) {
        BillboardObject_SetFrame(work->billboard, 12 * FX32_ONE);
        BillboardObject_AdvanceFrame(work->billboard, 0);
        work->state = VERY_TALL_GRASS_STATE_WAIT;
    }
    return TRUE;
}

static void VeryTallGrassEffect_Destroy(FieldEffect *effect, void *state) {
    VeryTallGrassEffect *work = state;
    BillboardObject_Delete(work->billboard);
}

static void VeryTallGrassEffect_Update(FieldEffect *effect, void *state) {
    VeryTallGrassEffect *work = state;
    VecFx32 current;
    VecFx32 position;
    LocalMapObject *mapObject = work->args.mapObject;

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
    case VERY_TALL_GRASS_STATE_SHAKE:
        BillboardObject_AdvanceFrame(work->billboard, FX32_ONE);
        if (BillboardObject_GetSequenceFrame(work->billboard) / FX32_ONE < 12) {
            return;
        }
        work->state = VERY_TALL_GRASS_STATE_STOP;
        return;
    case VERY_TALL_GRASS_STATE_STOP:
        BillboardObject_SetFrame(work->billboard, 12 * FX32_ONE);
        BillboardObject_AdvanceFrame(work->billboard, 0);
        work->state = VERY_TALL_GRASS_STATE_WAIT;
        // fallthrough
    case VERY_TALL_GRASS_STATE_WAIT: {
        int x = MapObject_GetXCoord(mapObject) - work->args.dx;
        int z = MapObject_GetZCoord(mapObject) - work->args.dz;
        if (work->args.x != x || work->args.z != z) {
            FieldEffectManager_DestroyEffect(effect);
            return;
        }
        if (work->args.direction != -1 && work->args.direction != MapObject_GetFacingDirection(mapObject)) {
            FieldEffectManager_DestroyEffect(effect);
        }
    }
        return;
    }
}

static void VeryTallGrassEffect_Draw(FieldEffect *effect, void *state) {
    VeryTallGrassEffect *work = state;
    VecFx32 position;

    if (!MapObject_CheckSpriteIDAndMap(work->args.mapObject, work->spriteId, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    FieldEffect_GetPosition(effect, &position);
    BillboardObject_SetPosition(work->billboard, &position);
}
