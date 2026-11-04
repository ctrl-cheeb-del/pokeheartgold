#include "field_warp_arrow.h"

#include "global.h"

#include "constants/field/field_effect_renderer.h"

#include "field/field_effect_helpers.h"
#include "field/field_effect_manager.h"

#include "field_effects.h"
#include "field_system.h"
#include "geometry_math.h"
#include "map_object.h"
#include "map_object_movement_utilities.h"
#include "metatile_behavior.h"
#include "player_avatar.h"
#include "render_animation.h"
#include "render_model.h"

// The arrow shown on the tile ahead of the player while it stands on a warp entrance facing the way out; it steps
// towards the exit and back every 16 frames.

#define WARP_ARROW_FRAME_TIME 16

struct WarpArrow {
    FieldEffectManager *manager;
    RenderModel model;
    NNSG3dRenderObj renderObj;
};

typedef struct WarpArrowEffectArgs {
    FieldEffectManager *manager;
    WarpArrow *arrow;
    PlayerAvatar *playerAvatar;
} WarpArrowEffectArgs;

typedef struct WarpArrowEffect {
    BOOL hidden;
    int direction; // of the warp the player stands on, -1 if none
    u8 behavior;
    u8 unk_09[0xB];
    u32 objectId;
    u32 mapId;
    int timer;
    int frame;
    WarpArrowEffectArgs args;
} WarpArrowEffect;

static void WarpArrow_LoadModel(WarpArrow *arrow);
static void WarpArrow_FreeModel(WarpArrow *arrow);
static BOOL WarpArrowEffect_Init(FieldEffect *effect, void *state);
static void WarpArrowEffect_Destroy(FieldEffect *effect, void *state);
static void WarpArrowEffect_Update(FieldEffect *effect, void *state);
static void WarpArrowEffect_Draw(FieldEffect *effect, void *state);
static int WarpArrow_GetWarpDirection(u8 behavior);

static const VecFx32 sWarpArrowScale = { FX32_ONE, FX32_ONE, FX32_ONE };

static const FieldEffectBasicTemplate sWarpArrowTemplate = {
    sizeof(WarpArrowEffect),
    WarpArrowEffect_Init,
    WarpArrowEffect_Destroy,
    WarpArrowEffect_Update,
    WarpArrowEffect_Draw,
};

// The arrow's two positions per direction: on the tile, then 2 units towards the exit.
static const VecFx32 sWarpArrowOffsets[4][2] = {
    { { 0, 0, 0 }, { 0, 0, -FX32_CONST(2) } },
    { { 0, 0, 0 }, { 0, 0, FX32_CONST(2) }  },
    { { 0, 0, 0 }, { -FX32_CONST(2), 0, 0 } },
    { { 0, 0, 0 }, { FX32_CONST(2), 0, 0 }  },
};

WarpArrow *WarpArrow_New(FieldEffectManager *manager) {
    WarpArrow *arrow = FieldEffectManager_HeapAllocAndFill(manager, sizeof(WarpArrow), FALSE, 0);
    arrow->manager = manager;
    WarpArrow_LoadModel(arrow);
    return arrow;
}

void WarpArrow_Free(WarpArrow *arrow) {
    WarpArrow_FreeModel(arrow);
    FieldEffectManager_HeapFree(arrow);
}

static void WarpArrow_LoadModel(WarpArrow *arrow) {
    FieldEffectManager_LoadRenderModel(arrow->manager, &arrow->model, 0, 0x55, FALSE);
    RenderObj_InitFromModel(&arrow->renderObj, &arrow->model);
}

static void WarpArrow_FreeModel(WarpArrow *arrow) {
    RenderModel_Free(&arrow->model);
}

void WarpArrow_Spawn(PlayerAvatar *playerAvatar) {
    WarpArrowEffectArgs args;
    VecFx32 position = { 0, 0, 0 };

    LocalMapObject *mapObject = PlayerAvatar_GetMapObject(playerAvatar);
    FieldEffectManager *manager = FieldEffectManager_GetFromMapObject(mapObject);
    args.manager = manager;
    args.arrow = FieldEffectManager_GetRendererData(manager, FIELD_EFFECT_RENDERER_WARP_ARROW);
    args.playerAvatar = playerAvatar;
    FieldEffectManager_CreateEffect(manager, &sWarpArrowTemplate, &position, 0, &args, MapObject_GetPriorityPlusValue(mapObject, 2));
}

static BOOL WarpArrowEffect_Init(FieldEffect *effect, void *state) {
    WarpArrowEffect *work = state;
    WarpArrowEffectArgs *args = FieldEffect_GetUserData(effect);
    work->args = *args;
    LocalMapObject *mapObject = PlayerAvatar_GetMapObject(args->playerAvatar);
    work->direction = -1;
    work->objectId = MapObject_GetID(mapObject);
    work->mapId = MapObject_GetMapID(mapObject);
    return TRUE;
}

static void WarpArrowEffect_Destroy(FieldEffect *effect, void *state) {
    WarpArrowEffect *work = state;
}

static void WarpArrowEffect_Update(FieldEffect *effect, void *state) {
    WarpArrowEffect *work = state;
    VecFx32 objectPos;
    VecFx32 position;

    PlayerAvatar *playerAvatar = work->args.playerAvatar;
    LocalMapObject *mapObject = PlayerAvatar_GetMapObject(playerAvatar);
    if (!MapObject_CheckIDAndMap(mapObject, work->objectId, work->mapId)) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    int prevDirection = work->direction;
    work->behavior = MapObject_GetCurrentMetatileBehavior(mapObject);
    work->direction = WarpArrow_GetWarpDirection(work->behavior);
    work->hidden = FALSE;
    if (work->direction == -1 || work->direction != (int)PlayerAvatar_GetFacingDirection(playerAvatar)) {
        work->timer = 0;
        work->frame = 0;
        work->hidden = TRUE;
        return;
    }
    if (prevDirection != work->direction) {
        work->timer = 0;
        work->frame = 0;
    }
    int x = MapObject_GetXCoord(mapObject);
    int dx = GetDeltaXByFacingDirection(work->direction);
    int z = MapObject_GetZCoord(mapObject);
    int dz = GetDeltaYByFacingDirection(work->direction);
    SetPositionToTileCenter(x + dx, z + dz, &position);
    MapObject_CopyPositionVector(mapObject, &objectPos);
    position.y = objectPos.y;
    FieldEffect_SetPosition(effect, &position);
    work->timer++;
    if (work->timer > WARP_ARROW_FRAME_TIME - 1) {
        work->timer = 0;
        work->frame = (work->frame + 1) % 2;
    }
}

static void WarpArrowEffect_Draw(FieldEffect *effect, void *state) {
    WarpArrowEffect *work = state;
    MtxFx33 rotation;
    VecFx32 position;
    VecFx32 scale;
    const VecFx32 *offset;
    NNSG3dRenderObj *renderObj;
    int angle;

    if (work->hidden == TRUE || work->direction == -1) {
        return;
    }
    angle = 0;
    scale = sWarpArrowScale;
    renderObj = &work->args.arrow->renderObj;
    offset = &sWarpArrowOffsets[work->direction][work->frame];
    switch (work->direction) {
    case 0:
        angle = 180;
        break;
    case 1:
        break;
    case 2:
        angle = 270;
        break;
    case 3:
        angle = 90;
        break;
    }
    Math_CalcRotationMatrixXYZDeg(&rotation, 0, angle, 0);
    FieldEffect_GetPosition(effect, &position);
    position.x += offset->x;
    position.y += offset->y;
    position.z += offset->z;
    RenderObj_Draw(renderObj, &position, &scale, &rotation);
}

// The way out of a warp entrance tile (DIR_NORTH..DIR_EAST), -1 for other tiles.
static int WarpArrow_GetWarpDirection(u8 behavior) {
    if (MetatileBehavior_IsWarpEntranceNorth(behavior)) {
        return 0;
    }
    if (MetatileBehavior_IsWarpEntranceSouth(behavior)) {
        return 1;
    }
    if (MetatileBehavior_IsWarpEntranceWest(behavior)) {
        return 2;
    }
    if (MetatileBehavior_IsWarpEntranceEast(behavior)) {
        return 3;
    }
    return -1;
}
