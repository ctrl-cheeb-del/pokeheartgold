#include "field_unused_billboard_effect.h"

#include "global.h"

#include "field/field_effect_helpers.h"
#include "field/field_effect_manager.h"

#include "billboard_lists.h"
#include "field_effects.h"
#include "map_object.h"
#include "map_object_movement_utilities.h"

// A billboard over a map object's tile in the style of the grass effects. Nothing creates it.

#define UNUSED_BILLBOARD_RECORD   10
#define UNUSED_BILLBOARD_RESOURCE 8
#define UNUSED_BILLBOARD_SEQUENCE 8
#define UNUSED_BILLBOARD_TEXTURE  9

enum UnusedBillboardEffectState {
    UNUSED_BILLBOARD_STATE_ANIMATE,
    UNUSED_BILLBOARD_STATE_STOP,
    UNUSED_BILLBOARD_STATE_WAIT,
};

struct UnusedBillboard {
    FieldEffectManager *manager;
};

typedef struct UnusedBillboardEffectArgs {
    int x;
    int y;
    int z;
    FieldSystem *fieldSystem;
    FieldEffectManager *manager;
    UnusedBillboard *renderer;
    LocalMapObject *mapObject;
    s16 dx;
    s16 dz;
    s8 direction; // -1: any facing
} UnusedBillboardEffectArgs;

typedef struct UnusedBillboardEffect {
    enum UnusedBillboardEffectState state;
    u32 spriteId;
    u32 objectId;
    u32 mapId;
    u8 unk_10[4];
    BOOL onGround;
    UnusedBillboardEffectArgs args;
    BillboardObject *billboard;
} UnusedBillboardEffect;

static void UnusedBillboard_LoadGfx(UnusedBillboard *renderer);
static void UnusedBillboard_FreeGfx(UnusedBillboard *renderer);
BOOL UnusedBillboardEffect_Init(FieldEffect *effect, UnusedBillboardEffect *work);
void UnusedBillboardEffect_Destroy(FieldEffect *effect, UnusedBillboardEffect *work);
void UnusedBillboardEffect_Update(FieldEffect *effect, UnusedBillboardEffect *work);
void UnusedBillboardEffect_Draw(FieldEffect *effect, UnusedBillboardEffect *work);

static const BillboardSequenceRange sUnusedBillboardRanges[2] = {
    { 0, 2, 0 },
    { 0, 0, 2 },
};

UnusedBillboard *UnusedBillboard_New(FieldEffectManager *manager) {
    UnusedBillboard *renderer = FieldEffectManager_HeapAllocAndFill(manager, sizeof(UnusedBillboard), FALSE, 0);
    renderer->manager = manager;
    UnusedBillboard_LoadGfx(renderer);
    return renderer;
}

void UnusedBillboard_Free(UnusedBillboard *renderer) {
    UnusedBillboard_FreeGfx(renderer);
    FieldEffectManager_HeapFree(renderer);
}

static void UnusedBillboard_LoadGfx(UnusedBillboard *renderer) {
    FieldEffectManager_LoadBillboardResource(renderer->manager, UNUSED_BILLBOARD_RESOURCE, 0x7B);
    FieldEffectManager_LoadBillboardSequence(renderer->manager, UNUSED_BILLBOARD_SEQUENCE, 0x93);
    FieldEffectManager_LoadTexResource(renderer->manager, UNUSED_BILLBOARD_TEXTURE, 0x16, TRUE);
    FieldEffectManager_AddRecord(renderer->manager, UNUSED_BILLBOARD_RECORD, UNUSED_BILLBOARD_RESOURCE, UNUSED_BILLBOARD_SEQUENCE, UNUSED_BILLBOARD_TEXTURE, 0, sUnusedBillboardRanges);
}

static void UnusedBillboard_FreeGfx(UnusedBillboard *renderer) {
    FieldEffectManager_FreeBillboardResource(renderer->manager, UNUSED_BILLBOARD_RESOURCE);
    FieldEffectManager_FreeBillboardSequence(renderer->manager, UNUSED_BILLBOARD_SEQUENCE);
    FieldEffectManager_FreeTexResource(renderer->manager, UNUSED_BILLBOARD_TEXTURE);
    FieldEffectManager_ReleaseRecord(renderer->manager, UNUSED_BILLBOARD_RECORD);
}

BOOL UnusedBillboardEffect_Init(FieldEffect *effect, UnusedBillboardEffect *work) {
    VecFx32 position;

    UnusedBillboardEffectArgs *args = FieldEffect_GetUserData(effect);

    work->args = *args;
    work->spriteId = MapObject_GetSpriteID(work->args.mapObject);
    work->objectId = MapObject_GetID(work->args.mapObject);
    work->mapId = MapObject_GetMapID(work->args.mapObject);
    position.x = work->args.x << 16;
    position.z = work->args.z << 16;
    position.y = MapObject_GetPositionVectorYCoord(work->args.mapObject);
    work->onGround = FieldSystem_SnapToTerrainHeight(work->args.fieldSystem, &position);
    position.x += 0x1E << 10;
    position.y -= 2 << 14;
    position.z += 0xD << 12;
    FieldEffect_SetPosition(effect, &position);
    work->billboard = FieldEffectManager_CreateBillboardFromRecord(work->args.manager, UNUSED_BILLBOARD_RECORD, &position);
    if (MapObject_TestFlagsBits(work->args.mapObject, MAPOBJECTFLAG_INVISIBLE) == TRUE) {
        BillboardObject_SetVisible(work->billboard, FALSE);
    }
    if (FieldEffect_GetParam(effect) == 0) {
        BillboardObject_SetFrame(work->billboard, 2 * FX32_ONE);
        work->state = UNUSED_BILLBOARD_STATE_WAIT;
    }
    return TRUE;
}

void UnusedBillboardEffect_Destroy(FieldEffect *effect, UnusedBillboardEffect *work) {
    BillboardObject_Delete(work->billboard);
}

void UnusedBillboardEffect_Update(FieldEffect *effect, UnusedBillboardEffect *work) {
    struct {
        VecFx32 target;
        VecFx32 current;
    } vecs;
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
        FieldEffect_GetPosition(effect, &vecs.current);
        vecs.target.x = work->args.x << 16;
        vecs.target.z = work->args.z << 16;
        vecs.target.y = vecs.current.y;
        work->onGround = FieldSystem_SnapToTerrainHeight(work->args.fieldSystem, &vecs.target);
        if (work->onGround == TRUE) {
            vecs.current.y = vecs.target.y;
            FieldEffect_SetPosition(effect, &vecs.current);
        }
    }
    switch (work->state) {
    case UNUSED_BILLBOARD_STATE_ANIMATE:
        BillboardObject_AdvanceFrame(work->billboard, FX32_ONE);
        if (BillboardObject_GetSequenceFrame(work->billboard) / FX32_ONE >= 2) {
            work->state = UNUSED_BILLBOARD_STATE_STOP;
        }
        break;
    case UNUSED_BILLBOARD_STATE_STOP:
        BillboardObject_SetFrame(work->billboard, 2 * FX32_ONE);
        BillboardObject_AdvanceFrame(work->billboard, 0);
        work->state = UNUSED_BILLBOARD_STATE_WAIT;
        // fallthrough
    case UNUSED_BILLBOARD_STATE_WAIT:
        if (!MapObject_CheckSpriteIDAndMap(mapObject, work->spriteId, work->objectId, work->mapId)) {
            FieldEffectManager_DestroyEffect(effect);
            return;
        }
        x = MapObject_GetXCoord(mapObject);
        z = MapObject_GetZCoord(mapObject);
        if (work->args.x != x || work->args.z != z) {
            FieldEffectManager_DestroyEffect(effect);
            return;
        }
        if (work->args.direction != -1 && work->args.direction != MapObject_GetFacingDirection(mapObject)) {
            FieldEffectManager_DestroyEffect(effect);
        }
        break;
    }
}

void UnusedBillboardEffect_Draw(FieldEffect *effect, UnusedBillboardEffect *work) {
    VecFx32 position;

    if (!MapObject_CheckIDAndMap(work->args.mapObject, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    FieldEffect_GetPosition(effect, &position);
    BillboardObject_SetPosition(work->billboard, &position);
}
