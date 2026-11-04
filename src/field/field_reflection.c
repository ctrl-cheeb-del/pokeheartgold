#include "field_reflection.h"

#include "global.h"

#include "constants/field/field_effect_renderer.h"
#include "constants/global_fieldmap.h"
#include "constants/scrcmd.h"
#include "constants/sprites.h"

#include "field/field_effect_helpers.h"
#include "field/field_effect_manager.h"
#include "field/field_follow_mon.h"
#include "field/map_object_billboard_motion.h"
#include "field/map_object_render.h"
#include "field/map_object_render_internal.h"

#include "billboard_lists.h"
#include "field_effects.h"
#include "field_system.h"
#include "map_object.h"
#include "map_object_movement_utilities.h"
#include "player_avatar.h"

// Map object reflections: an upside-down copy of the object's billboard below it while it stands on a puddle, other
// water or a reflective floor. Only water reflections ripple.

#define REFLECTION_RESOURCE       2
#define REFLECTION_RESOURCE_LARGE 13

#define REFLECTION_SCALE_STEP 0x40
#define REFLECTION_SCALE_MIN  0xE00
#define REFLECTION_SCALE_MAX  0x1200

struct Reflection {
    FieldEffectManager *manager;
};

typedef struct ReflectionEffectArgs {
    FieldSystem *fieldSystem;
    FieldEffectManager *manager;
    Reflection *reflection;
    LocalMapObject *mapObject;
} ReflectionEffectArgs;

typedef struct ReflectionEffect {
    u32 objectId;
    u32 mapId;
    u32 spriteId;
    BOOL hasBillboard;
    u32 kind;
    ReflectionEffectArgs args;
    BillboardObject *billboard;
    VecFx32 scale;
    fx32 scaleStep;
} ReflectionEffect;

// The reflection of a billboard that is not (or no longer) drawn by a map object, at a fixed position.
typedef struct BillboardReflectionArgs {
    FieldSystem *fieldSystem;
    FieldEffectManager *manager;
    Reflection *reflection;
    BillboardResource record;
    BillboardObject *source;
} BillboardReflectionArgs;

// Only the first sizeof(ReflectionEffect) bytes are cleared: the template is shared in size with the
// map object reflection.
typedef struct BillboardReflectionEffect {
    int kind;
    BillboardReflectionArgs args;
    BillboardObject *billboard;
    VecFx32 scale;
    fx32 scaleStep;
    VecFx32 position;
} BillboardReflectionEffect;

// How far below the object's ground the reflection is drawn, per kind.
typedef struct ReflectionDepths {
    fx32 depth[REFLECTION_KIND_COUNT];
} ReflectionDepths;

static void Reflection_LoadGfx(Reflection *reflection);
static void Reflection_FreeGfx(Reflection *reflection);
static BOOL ReflectionEffect_Init(FieldEffect *effect, void *state);
static void ReflectionEffect_Destroy(FieldEffect *effect, void *state);
static void ReflectionEffect_Update(FieldEffect *effect, void *state);
static void ReflectionEffect_Draw(FieldEffect *effect, void *state);
static void ReflectionEffect_CalcPosition(ReflectionEffect *work, LocalMapObject *mapObject, VecFx32 *position);
static void ReflectionEffect_CreateBillboard(FieldEffect *effect, ReflectionEffect *work);
static void BillboardReflectionEffect_CreateBillboard(FieldEffect *effect, BillboardReflectionEffect *work);
static void BillboardReflectionEffect_CalcPosition(BillboardReflectionEffect *work, VecFx32 *position);
static BOOL BillboardReflectionEffect_Init(FieldEffect *effect, void *state);
static void BillboardReflectionEffect_Destroy(FieldEffect *effect, void *state);
static void BillboardReflectionEffect_Update(FieldEffect *effect, void *state);
static void BillboardReflectionEffect_Draw(FieldEffect *effect, void *state);
static BOOL FollowerReflectionEffect_Init(FieldEffect *effect, void *state);
static void FollowerReflectionEffect_Update(FieldEffect *effect, void *state);
static void FollowerReflectionEffect_Draw(FieldEffect *effect, void *state);
static void FollowerReflectionEffect_CreateBillboard(FieldEffect *effect, ReflectionEffect *work);

static const ReflectionDepths sReflectionDepths = {
    { 14 * FX32_ONE, 20 * FX32_ONE, 14 * FX32_ONE, 14 * FX32_ONE, 20 * FX32_ONE, 14 * FX32_ONE }
};

static const FieldEffectBasicTemplate sBillboardReflectionTemplate = {
    56,
    BillboardReflectionEffect_Init,
    BillboardReflectionEffect_Destroy,
    BillboardReflectionEffect_Update,
    BillboardReflectionEffect_Draw,
};

static const FieldEffectBasicTemplate sMapObjectReflectionTemplate = {
    sizeof(ReflectionEffect),
    ReflectionEffect_Init,
    ReflectionEffect_Destroy,
    ReflectionEffect_Update,
    ReflectionEffect_Draw,
};

static const FieldEffectBasicTemplate sFollowerReflectionTemplate = {
    sizeof(ReflectionEffect),
    FollowerReflectionEffect_Init,
    ReflectionEffect_Destroy,
    FollowerReflectionEffect_Update,
    FollowerReflectionEffect_Draw,
};

static inline void Reflection_SpawnWithTemplate(LocalMapObject *mapObject, int kind, const FieldEffectBasicTemplate *template) {
    ReflectionEffectArgs args;
    VecFx32 position;
    args.fieldSystem = MapObject_GetFieldSystem(mapObject);
    args.manager = FieldEffectManager_GetFromMapObject(mapObject);
    args.reflection = FieldEffectManager_GetRendererData(args.manager, FIELD_EFFECT_RENDERER_REFLECTION);
    args.mapObject = mapObject;
    MapObject_CopyPositionVector(mapObject, &position);
    FieldEffectManager_CreateEffect(args.manager, template, &position, kind, &args, MapObject_GetPriorityPlusValue(mapObject, 2));
}

static inline BOOL ReflectionEffect_IsObjectGone(ReflectionEffect *work, LocalMapObject *mapObject) {
    return work->spriteId != MapObject_GetSpriteID(mapObject) || !MapObject_CheckIDAndMap(mapObject, work->objectId, work->mapId) || !MapObject_CheckFlag24(mapObject);
}

Reflection *Reflection_New(FieldEffectManager *manager) {
    Reflection *reflection = FieldEffectManager_HeapAllocAndFill(manager, sizeof(Reflection), FALSE, 0);
    reflection->manager = manager;
    Reflection_LoadGfx(reflection);
    return reflection;
}

void Reflection_Free(Reflection *reflection) {
    Reflection_FreeGfx(reflection);
    FieldEffectManager_HeapFree(reflection);
}

static void Reflection_LoadGfx(Reflection *reflection) {
    FieldEffectManager_LoadBillboardResource(reflection->manager, REFLECTION_RESOURCE, 0x23);
    FieldEffectManager_LoadBillboardResource(reflection->manager, REFLECTION_RESOURCE_LARGE, 0x69);
}

static void Reflection_FreeGfx(Reflection *reflection) {
    FieldEffectManager_FreeBillboardResource(reflection->manager, REFLECTION_RESOURCE);
    FieldEffectManager_FreeBillboardResource(reflection->manager, REFLECTION_RESOURCE_LARGE);
}

void Reflection_Spawn(LocalMapObject *mapObject, int kind) {
    Reflection_SpawnWithTemplate(mapObject, kind, &sMapObjectReflectionTemplate);
}

static BOOL ReflectionEffect_Init(FieldEffect *effect, void *state) {
    ReflectionEffect *work = state;
    VecFx32 position;
    ReflectionEffectArgs *args = FieldEffect_GetUserData(effect);
    work->args = *args;
    work->kind = FieldEffect_GetParam(effect);
    work->objectId = MapObject_GetID(work->args.mapObject);
    work->mapId = MapObject_GetMapID(work->args.mapObject);
    work->spriteId = MapObject_GetSpriteID(work->args.mapObject);
    work->scale.x = FX32_ONE;
    work->scale.y = FX32_ONE;
    work->scale.z = FX32_ONE;
    work->scaleStep = REFLECTION_SCALE_STEP;
    if (work->kind == REFLECTION_KIND_FLOOR) {
        work->scaleStep = 0;
    }
    ReflectionEffect_CalcPosition(work, work->args.mapObject, &position);
    FieldEffect_SetPosition(effect, &position);
    ReflectionEffect_CreateBillboard(effect, work);
    return TRUE;
}

static void ReflectionEffect_Destroy(FieldEffect *effect, void *state) {
    ReflectionEffect *work = state;
    if (work->hasBillboard == TRUE) {
        BillboardObject_Delete(work->billboard);
    }
}

static void ReflectionEffect_Update(FieldEffect *effect, void *state) {
    ReflectionEffect *work = state;
    VecFx32 position;
    LocalMapObject *mapObject = work->args.mapObject;
    if (ReflectionEffect_IsObjectGone(work, mapObject)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    work->scale.x += work->scaleStep;
    if (work->scale.x >= REFLECTION_SCALE_MAX) {
        work->scale.x = REFLECTION_SCALE_MAX;
        work->scaleStep = -work->scaleStep;
    } else if (work->scale.x <= REFLECTION_SCALE_MIN) {
        work->scale.x = REFLECTION_SCALE_MIN;
        work->scaleStep = -work->scaleStep;
    }
    ReflectionEffect_CalcPosition(work, mapObject, &position);
    FieldEffect_SetPosition(effect, &position);
    if (!work->hasBillboard) {
        ReflectionEffect_CreateBillboard(effect, work);
    }
}

static void ReflectionEffect_Draw(FieldEffect *effect, void *state) {
    ReflectionEffect *work = state;
    VecFx32 facing;
    VecFx32 position;
    LocalMapObject *mapObject = work->args.mapObject;
    BillboardObject *source;
    BOOL hidden = FALSE;

    if (ReflectionEffect_IsObjectGone(work, mapObject)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    if (!work->hasBillboard) {
        return;
    }
    MapObject_CopyFacingVector(work->args.mapObject, &facing);
    if (facing.y != 0) {
        hidden = TRUE;
    }
    if (MapObject_CheckInvisible(mapObject) == TRUE) {
        hidden = TRUE;
    }
    if (hidden) {
        BillboardObject_SetVisible(work->billboard, FALSE);
    } else {
        BillboardObject_SetVisible(work->billboard, TRUE);
    }
    FieldEffect_GetPosition(effect, &position);
    BillboardObject_SetPosition(work->billboard, &position);
    BillboardObject_SetScale(work->billboard, &work->scale);
    source = MapObject_GetBillboard(work->args.mapObject);
    BillboardObject_SetSequence(work->billboard, BillboardObject_GetSequence(source));
    BillboardObject_SetFrame(work->billboard, BillboardObject_GetFrame(source));
}

static void ReflectionEffect_CalcPosition(ReflectionEffect *work, LocalMapObject *mapObject, VecFx32 *position) {
    const ReflectionDepths depths = {
        { 14 * FX32_ONE, 20 * FX32_ONE, 14 * FX32_ONE, 14 * FX32_ONE, 20 * FX32_ONE, 14 * FX32_ONE }
    };
    VecFx32 facing;
    ReflectionDepths depthTable;
    fx32 xOffset;
    fx32 zOffset;
    fx32 yOffset;
    BOOL onGround;

    depthTable = depths;
    MapObject_CopyFacingVector(mapObject, &facing);
    xOffset = facing.x;
    if (MapObject_GetID(mapObject) == obj_player && MapObject_GetSpriteID(mapObject) == SPRITE_FISHINGHERO) {
        fx32 base;
        u32 direction;
        direction = MapObject_GetFacingDirection(mapObject);
        base = 2;
        base <<= 10;
        if (direction == DIR_SOUTH) {
            zOffset = base;
            zOffset += base << 1;
            zOffset -= facing.z;
        } else {
            zOffset = facing.z;
        }
    } else {
        zOffset = facing.z;
    }
    yOffset = -(facing.y / 6);
    if (MapObject_GetID(mapObject) == obj_partner_poke && MapObject_GetSpriteID(PlayerAvatar_GetMapObject(work->args.fieldSystem->playerAvatar)) == SPRITE_FISHINGHERO) {
        yOffset = 0;
    }
    MapObject_CopyPositionVector(mapObject, position);
    onGround = FieldSystem_SnapToTerrainHeight(work->args.fieldSystem, position);
    position->x += xOffset;
    position->z += zOffset - 7 * FX32_ONE;
    if (!onGround) {
        position->y = 0;
    } else {
        position->y -= depthTable.depth[work->kind];
    }
    position->y += yOffset;
}

static void ReflectionEffect_CreateBillboard(FieldEffect *effect, ReflectionEffect *work) {
    VecFx32 position;
    BillboardResource record;
    if (MapObjectRender_GetBillboardResource(MapObject_GetManager(work->args.mapObject), work->spriteId, &record) && MapObject_IsBillboardPending(work->args.mapObject) != TRUE) {
        record.modelFile = FieldEffectManager_GetBillboardResource(work->args.manager, REFLECTION_RESOURCE);
        FieldEffect_GetPosition(effect, &position);
        work->billboard = FieldEffectManager_CreateBillboard(work->args.manager, &record, &position);
        work->hasBillboard = TRUE;
    }
}

static void BillboardReflectionEffect_CreateBillboard(FieldEffect *effect, BillboardReflectionEffect *work) {
    VecFx32 position;
    BillboardResource record;
    BillboardObject *source;

    record = work->args.record;
    record.modelFile = FieldEffectManager_GetBillboardResource(work->args.manager, REFLECTION_RESOURCE);
    FieldEffect_GetPosition(effect, &position);
    work->billboard = FieldEffectManager_CreateBillboard(work->args.manager, &record, &position);
    source = work->args.source;
    BillboardObject_SetSequence(work->billboard, BillboardObject_GetSequence(source));
    BillboardObject_SetSequenceFrame(work->billboard, BillboardObject_GetSequenceFrame(source));
    BillboardObject_SetFrame(work->billboard, BillboardObject_GetFrame(source));
    BillboardObject_AdvanceFrame(work->billboard, 0);
    BillboardObject_UpdateTextureAnimation(work->billboard);
}

static void BillboardReflectionEffect_CalcPosition(BillboardReflectionEffect *work, VecFx32 *position) {
    ReflectionDepths depths = sReflectionDepths;
    BOOL onGround;
    *position = work->position;
    onGround = FieldSystem_SnapToTerrainHeight(work->args.fieldSystem, position);
    position->z -= 7 * FX32_ONE;
    if (!onGround) {
        position->y = 0;
    } else {
        position->y -= depths.depth[work->kind];
    }
}

FieldEffect *Reflection_SpawnForBillboard(FieldEffectManager *manager, const BillboardResource *record, BillboardObject *source, const VecFx32 *position, int kind, u32 priority) {
    BillboardReflectionArgs args;
    args.fieldSystem = FieldEffectManager_GetFieldSystem(manager);
    args.manager = manager;
    args.reflection = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_REFLECTION);
    args.record = *record;
    args.source = source;
    return FieldEffectManager_CreateEffect(manager, &sBillboardReflectionTemplate, position, kind, &args, priority);
}

static BOOL BillboardReflectionEffect_Init(FieldEffect *effect, void *state) {
    BillboardReflectionEffect *work = state;
    VecFx32 position;
    BillboardReflectionArgs *args = FieldEffect_GetUserData(effect);
    work->args = *args;
    work->kind = FieldEffect_GetParam(effect);
    work->scale.x = FX32_ONE;
    work->scale.y = FX32_ONE;
    work->scale.z = FX32_ONE;
    work->scaleStep = REFLECTION_SCALE_STEP;
    if (work->kind == REFLECTION_KIND_FLOOR) {
        work->scaleStep = 0;
    }
    FieldEffect_GetPosition(effect, &work->position);
    BillboardReflectionEffect_CalcPosition(work, &position);
    FieldEffect_SetPosition(effect, &position);
    BillboardReflectionEffect_CreateBillboard(effect, work);
    FieldEffect_RunUpdate(effect);
    return TRUE;
}

static void BillboardReflectionEffect_Destroy(FieldEffect *effect, void *state) {
    BillboardReflectionEffect *work = state;
    BillboardObject_Delete(work->billboard);
}

static void BillboardReflectionEffect_Update(FieldEffect *effect, void *state) {
    BillboardReflectionEffect *work = state;
    VecFx32 position;
    work->scale.x += work->scaleStep;
    if (work->scale.x >= REFLECTION_SCALE_MAX) {
        work->scale.x = REFLECTION_SCALE_MAX;
        work->scaleStep = -work->scaleStep;
    } else if (work->scale.x <= REFLECTION_SCALE_MIN) {
        work->scale.x = REFLECTION_SCALE_MIN;
        work->scaleStep = -work->scaleStep;
    }
    BillboardReflectionEffect_CalcPosition(work, &position);
    FieldEffect_SetPosition(effect, &position);
}

static void BillboardReflectionEffect_Draw(FieldEffect *effect, void *state) {
    BillboardReflectionEffect *work = state;
    VecFx32 position;
    FieldEffect_GetPosition(effect, &position);
    BillboardObject_SetPosition(work->billboard, &position);
    BillboardObject_SetScale(work->billboard, &work->scale);
}

void Reflection_SpawnForFollower(LocalMapObject *mapObject, int kind) {
    Reflection_SpawnWithTemplate(mapObject, kind, &sFollowerReflectionTemplate);
}

static BOOL FollowerReflectionEffect_Init(FieldEffect *effect, void *state) {
    ReflectionEffect *work = state;
    VecFx32 position;
    ReflectionEffectArgs *args = FieldEffect_GetUserData(effect);
    work->args = *args;
    work->kind = FieldEffect_GetParam(effect);
    work->objectId = MapObject_GetID(work->args.mapObject);
    work->mapId = MapObject_GetMapID(work->args.mapObject);
    work->spriteId = MapObject_GetSpriteID(work->args.mapObject);
    work->scale.x = FX32_ONE;
    work->scale.y = FX32_ONE;
    work->scale.z = FX32_ONE;
    work->scaleStep = REFLECTION_SCALE_STEP;
    if (work->kind == REFLECTION_KIND_FLOOR || work->kind == REFLECTION_KIND_LARGE_FLOOR) {
        work->scaleStep = 0;
    }
    ReflectionEffect_CalcPosition(work, work->args.mapObject, &position);
    position.y -= 0x514;
    FieldEffect_SetPosition(effect, &position);
    FollowerReflectionEffect_CreateBillboard(effect, work);
    return TRUE;
}

static void FollowerReflectionEffect_Update(FieldEffect *effect, void *state) {
    ReflectionEffect *work = state;
    VecFx32 position;
    LocalMapObject *mapObject = work->args.mapObject;
    if (ReflectionEffect_IsObjectGone(work, mapObject)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    work->scale.x += work->scaleStep;
    if (work->scale.x >= REFLECTION_SCALE_MAX) {
        work->scale.x = REFLECTION_SCALE_MAX;
        work->scaleStep = -work->scaleStep;
    } else if (work->scale.x <= REFLECTION_SCALE_MIN) {
        work->scale.x = REFLECTION_SCALE_MIN;
        work->scaleStep = -work->scaleStep;
    }
    ReflectionEffect_CalcPosition(work, mapObject, &position);
    position.y -= 0x514;
    FieldEffect_SetPosition(effect, &position);
    if (!work->hasBillboard) {
        FollowerReflectionEffect_CreateBillboard(effect, work);
    }
}

static void FollowerReflectionEffect_Draw(FieldEffect *effect, void *state) {
    ReflectionEffect *work = state;
    VecFx32 position;
    LocalMapObject *mapObject = work->args.mapObject;
    BillboardObject *source;

    if (ReflectionEffect_IsObjectGone(work, mapObject)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    if (!work->hasBillboard) {
        return;
    }
    if (MapObject_CheckInvisible(mapObject) == TRUE) {
        BillboardObject_SetVisible(work->billboard, FALSE);
    } else {
        BillboardObject_SetVisible(work->billboard, TRUE);
    }
    FieldEffect_GetPosition(effect, &position);
    position.z -= FX32_ONE;
    BillboardObject_SetPosition(work->billboard, &position);
    BillboardObject_SetScale(work->billboard, &work->scale);
    source = MapObject_GetBillboard(work->args.mapObject);
    BillboardObject_SetSequence(work->billboard, BillboardObject_GetSequence(source));
    BillboardObject_SetFrame(work->billboard, BillboardObject_GetFrame(source));
}

static void FollowerReflectionEffect_CreateBillboard(FieldEffect *effect, ReflectionEffect *work) {
    VecFx32 position;
    BillboardResource record;
    void *resource;
    if (MapObjectRender_GetBillboardResource(MapObject_GetManager(work->args.mapObject), work->spriteId, &record) && MapObject_IsBillboardPending(work->args.mapObject) != TRUE) {
        if (work->kind <= REFLECTION_KIND_FLOOR) {
            resource = FieldEffectManager_GetBillboardResource(work->args.manager, REFLECTION_RESOURCE);
        } else {
            resource = FieldEffectManager_GetBillboardResource(work->args.manager, REFLECTION_RESOURCE_LARGE);
        }
        record.modelFile = resource;
        if (MapObject_IsShinyPokemon(work->args.mapObject)) {
            FollowMonBillboard_InitSequence(TRUE, work->args.mapObject, work->billboard, &record);
        }
        FieldEffect_GetPosition(effect, &position);
        work->billboard = FieldEffectManager_CreateBillboard(work->args.manager, &record, &position);
        work->hasBillboard = TRUE;
    }
}
