#include "field_shallow_water_ripple.h"

#include "global.h"

#include "constants/field/field_effect_renderer.h"

#include "field/field_effect_helpers.h"
#include "field/field_effect_manager.h"

#include "billboard_lists.h"
#include "field_effects.h"
#include "map_object.h"

// The ripples around a map object standing in shallow water: a billboard
// that plays its 12 frames once, or keeps looping while the object stays in the water.

#define SHALLOW_WATER_RIPPLE_RECORD   3
#define SHALLOW_WATER_RIPPLE_RESOURCE 3
#define SHALLOW_WATER_RIPPLE_SEQUENCE 2
#define SHALLOW_WATER_RIPPLE_TEXTURE  2

struct ShallowWaterRipple {
    FieldEffectManager *manager;
};

typedef struct ShallowWaterRippleEffectArgs {
    FieldSystem *fieldSystem;
    FieldEffectManager *manager;
    ShallowWaterRipple *ripple;
    LocalMapObject *mapObject;
} ShallowWaterRippleEffectArgs;

typedef struct ShallowWaterRippleEffect {
    BOOL paused;
    u32 spriteId;
    u32 objectId;
    u32 mapId;
    u8 unk_10[4];
    ShallowWaterRippleEffectArgs args;
    BillboardObject *billboard;
} ShallowWaterRippleEffect;

static void ShallowWaterRipple_LoadGfx(ShallowWaterRipple *ripple);
static void ShallowWaterRipple_FreeGfx(ShallowWaterRipple *ripple);
static BOOL ShallowWaterRippleEffect_Init(FieldEffect *effect, void *state);
static void ShallowWaterRippleEffect_Destroy(FieldEffect *effect, void *state);
static void ShallowWaterRippleEffect_Update(FieldEffect *effect, void *state);
static void ShallowWaterRippleEffect_Draw(FieldEffect *effect, void *state);

static const FieldEffectBasicTemplate sShallowWaterRippleEffectTemplate = {
    sizeof(ShallowWaterRippleEffect),
    ShallowWaterRippleEffect_Init,
    ShallowWaterRippleEffect_Destroy,
    ShallowWaterRippleEffect_Update,
    ShallowWaterRippleEffect_Draw,
};

static const BillboardSequenceRange sShallowWaterRippleRanges[2] = {
    { 0, 12, 1 },
    { 0, 0,  2 },
};

ShallowWaterRipple *ShallowWaterRipple_New(FieldEffectManager *manager) {
    ShallowWaterRipple *ripple = FieldEffectManager_HeapAllocAndFill(manager, sizeof(ShallowWaterRipple), FALSE, 0);
    ripple->manager = manager;
    ShallowWaterRipple_LoadGfx(ripple);
    return ripple;
}

void ShallowWaterRipple_Free(ShallowWaterRipple *ripple) {
    ShallowWaterRipple_FreeGfx(ripple);
    FieldEffectManager_HeapFree(ripple);
}

static void ShallowWaterRipple_LoadGfx(ShallowWaterRipple *ripple) {
    FieldEffectManager_LoadBillboardResource(ripple->manager, SHALLOW_WATER_RIPPLE_RESOURCE, 0x77);
    FieldEffectManager_LoadBillboardSequence(ripple->manager, SHALLOW_WATER_RIPPLE_SEQUENCE, 0x90);
    FieldEffectManager_LoadTexResource(ripple->manager, SHALLOW_WATER_RIPPLE_TEXTURE, 0x12, TRUE);
    FieldEffectManager_AddRecord(ripple->manager, SHALLOW_WATER_RIPPLE_RECORD, SHALLOW_WATER_RIPPLE_RESOURCE, SHALLOW_WATER_RIPPLE_SEQUENCE, SHALLOW_WATER_RIPPLE_TEXTURE, 0, sShallowWaterRippleRanges);
}

static void ShallowWaterRipple_FreeGfx(ShallowWaterRipple *ripple) {
    FieldEffectManager_FreeBillboardResource(ripple->manager, SHALLOW_WATER_RIPPLE_RESOURCE);
    FieldEffectManager_FreeBillboardSequence(ripple->manager, SHALLOW_WATER_RIPPLE_SEQUENCE);
    FieldEffectManager_FreeTexResource(ripple->manager, SHALLOW_WATER_RIPPLE_TEXTURE);
    FieldEffectManager_ReleaseRecord(ripple->manager, SHALLOW_WATER_RIPPLE_RECORD);
}

void ShallowWaterRipple_Spawn(LocalMapObject *mapObject, BOOL loop) {
    ShallowWaterRippleEffectArgs args;
    FieldEffectManager *manager = FieldEffectManager_GetFromMapObject(mapObject);
    args.fieldSystem = MapObject_GetFieldSystem(mapObject);
    args.manager = manager;
    args.ripple = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_SHALLOW_WATER_RIPPLE);
    {
        VecFx32 position = { 0, 0, 0 };
        args.mapObject = mapObject;
        FieldEffectManager_CreateEffect(manager, &sShallowWaterRippleEffectTemplate, &position, loop, &args, MapObject_GetPriorityPlusValue(mapObject, 2));
    }
}

static BOOL ShallowWaterRippleEffect_Init(FieldEffect *effect, void *state) {
    ShallowWaterRippleEffect *work = state;
    VecFx32 position = { 0, 0, 0 };
    ShallowWaterRippleEffectArgs *args = FieldEffect_GetUserData(effect);
    work->args = *args;
    work->spriteId = MapObject_GetSpriteID(work->args.mapObject);
    work->objectId = MapObject_GetID(work->args.mapObject);
    work->mapId = MapObject_GetMapID(work->args.mapObject);
    FieldEffect_SetPosition(effect, &position);
    work->billboard = FieldEffectManager_CreateBillboardFromRecord(work->args.manager, SHALLOW_WATER_RIPPLE_RECORD, &position);
    if (MapObject_TestFlagsBits(work->args.mapObject, MAPOBJECTFLAG_INVISIBLE) == TRUE) {
        BillboardObject_SetVisible(work->billboard, FALSE);
    }
    return TRUE;
}

static void ShallowWaterRippleEffect_Destroy(FieldEffect *effect, void *state) {
    ShallowWaterRippleEffect *work = state;
    BillboardObject_Delete(work->billboard);
}

static void ShallowWaterRippleEffect_Update(FieldEffect *effect, void *state) {
    ShallowWaterRippleEffect *work = state;
    BOOL loop;
    LocalMapObject *mapObject = work->args.mapObject;

    if (!MapObject_CheckSpriteIDAndMap(mapObject, work->spriteId, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    loop = FieldEffect_GetParam(effect);
    if (loop == TRUE && !MapObject_CheckFlag26(mapObject)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    if (MapObject_TestFlagsBits(mapObject, MAPOBJECTFLAG_INVISIBLE) == TRUE) {
        BillboardObject_SetVisible(work->billboard, FALSE);
    } else {
        BillboardObject_SetVisible(work->billboard, TRUE);
    }
    if (!work->paused) {
        BillboardObject_AdvanceFrame(work->billboard, FX32_ONE);
        if (BillboardObject_GetSequenceFrame(work->billboard) / FX32_ONE >= 12) {
            if (!loop) {
                FieldEffectManager_DestroyEffect(effect);
                return;
            }
            BillboardObject_SetFrame(work->billboard, 0);
        }
    }
}

static void ShallowWaterRippleEffect_Draw(FieldEffect *effect, void *state) {
    ShallowWaterRippleEffect *work = state;

    struct {
        VecFx32 facing;
        VecFx32 position;
    } vecs;

    LocalMapObject *mapObject = work->args.mapObject;

    if (!MapObject_CheckSpriteIDAndMap(mapObject, work->spriteId, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    MapObject_CopyPositionVector(mapObject, &vecs.position);
    MapObject_CopyFacingVector(mapObject, &vecs.facing);
    vecs.position.x += vecs.facing.x;
    vecs.position.z += vecs.facing.z;
    vecs.position.z += FX32_CONST(8);
    BillboardObject_SetPosition(work->billboard, &vecs.position);
}
