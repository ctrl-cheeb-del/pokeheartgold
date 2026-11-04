#include "field_mud_splash.h"

#include "global.h"

#include "constants/field/field_effect_renderer.h"

#include "field/field_effect_helpers.h"
#include "field/field_effect_manager.h"

#include "field_effects.h"
#include "map_object.h"
#include "map_object_movement_utilities.h"
#include "render_animation.h"
#include "render_model.h"

// The mud a map object splashes up when it steps into mud: one animated model
// played once at the tile, then the effect ends.

struct MudSplash {
    FieldEffectManager *manager;
    RenderModel model;
    RenderAnimation animation;
};

typedef struct MudSplashEffectArgs {
    FieldEffectManager *manager;
    MudSplash *splash;
} MudSplashEffectArgs;

typedef struct MudSplashEffect {
    RenderAnimation animation;
    NNSG3dRenderObj renderObj;
    MudSplashEffectArgs args;
} MudSplashEffect;

static void MudSplash_LoadGfx(MudSplash *splash);
static void MudSplash_FreeGfx(MudSplash *splash);
static BOOL MudSplashEffect_Init(FieldEffect *effect, void *state);
static void MudSplashEffect_Destroy(FieldEffect *effect, void *state);
static void MudSplashEffect_Update(FieldEffect *effect, void *state);
static void MudSplashEffect_Draw(FieldEffect *effect, void *state);

static const FieldEffectBasicTemplate sMudSplashEffectTemplate = {
    sizeof(MudSplashEffect),
    MudSplashEffect_Init,
    MudSplashEffect_Destroy,
    MudSplashEffect_Update,
    MudSplashEffect_Draw,
};

MudSplash *MudSplash_New(FieldEffectManager *manager) {
    MudSplash *splash = FieldEffectManager_HeapAllocAndFill(manager, sizeof(MudSplash), FALSE, 0);
    splash->manager = manager;
    MudSplash_LoadGfx(splash);
    return splash;
}

void MudSplash_Free(MudSplash *splash) {
    MudSplash_FreeGfx(splash);
    FieldEffectManager_HeapFree(splash);
}

static void MudSplash_LoadGfx(MudSplash *splash) {
    FieldEffectManager_LoadRenderModel(splash->manager, &splash->model, 0, 0x1E, FALSE);
    FieldEffectManager_LoadRenderAnimation(splash->manager, &splash->animation, 0, 0x87, FALSE);
}

static void MudSplash_FreeGfx(MudSplash *splash) {
    RenderModel_Free(&splash->model);
    RenderAnimation_Free(&splash->animation);
}

void MudSplash_Spawn(LocalMapObject *mapObject, int x, int y, int z) {
    MudSplashEffectArgs args;
    VecFx32 position;
    args.manager = FieldEffectManager_GetFromMapObject(mapObject);
    args.splash = FieldEffectManager_GetRendererData(args.manager, FIELD_EFFECT_RENDERER_MUD_SPLASH);
    SetPositionToTileCenter(x, z, &position);
    position.z += y * 8;
    position.y = MapObject_GetPreviousYCoord(mapObject) * FX32_CONST(8) - FX32_CONST(8);
    FieldEffectManager_CreateEffect(args.manager, &sMudSplashEffectTemplate, &position, 0, &args, MapObject_GetPriorityPlusValue(mapObject, 2));
}

static BOOL MudSplashEffect_Init(FieldEffect *effect, void *state) {
    MudSplashEffect *work = state;
    MudSplashEffectArgs *args = FieldEffect_GetUserData(effect);
    work->args = *args;
    FieldEffectManager_InitRenderAnimation(work->args.manager, &work->animation, &work->args.splash->model, &work->args.splash->animation, 0);
    RenderObj_InitWithAnimation(&work->renderObj, &work->args.splash->model, &work->animation);
    return TRUE;
}

static void MudSplashEffect_Destroy(FieldEffect *effect, void *state) {
    MudSplashEffect *work = state;
    RenderAnimation_Free(&work->animation);
}

static void MudSplashEffect_Update(FieldEffect *effect, void *state) {
    MudSplashEffect *work = state;
    if (RenderAnimation_IsDone(&work->animation) == TRUE) {
        FieldEffectManager_DestroyEffect(effect);
    } else {
        RenderAnimation_Advance(&work->animation, FX32_ONE, FALSE);
    }
}

static void MudSplashEffect_Draw(FieldEffect *effect, void *state) {
    MudSplashEffect *work = state;
    VecFx32 position;
    FieldEffect_GetPosition(effect, &position);
    RenderObj_DrawAt(&work->renderObj, &position);
}
