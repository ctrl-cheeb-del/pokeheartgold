#include "field_puddle_splash.h"

#include "global.h"

#include "constants/field/field_effect_renderer.h"

#include "field/field_effect_helpers.h"
#include "field/field_effect_manager.h"

#include "field_effects.h"
#include "map_object.h"
#include "map_object_movement_utilities.h"
#include "render_animation.h"
#include "render_model.h"

// The splash a map object kicks up when it steps into a puddle: one animated
// model played once at the tile, then the effect ends.

struct PuddleSplash {
    FieldEffectManager *manager;
    RenderModel model;
    RenderAnimation animation;
};

typedef struct PuddleSplashEffectArgs {
    FieldEffectManager *manager;
    PuddleSplash *splash;
} PuddleSplashEffectArgs;

typedef struct PuddleSplashEffect {
    RenderAnimation animation;
    NNSG3dRenderObj renderObj;
    PuddleSplashEffectArgs args;
} PuddleSplashEffect;

static void PuddleSplash_LoadGfx(PuddleSplash *splash);
static void PuddleSplash_FreeGfx(PuddleSplash *splash);
static BOOL PuddleSplashEffect_Init(FieldEffect *effect, void *state);
static void PuddleSplashEffect_Destroy(FieldEffect *effect, void *state);
static void PuddleSplashEffect_Update(FieldEffect *effect, void *state);
static void PuddleSplashEffect_Draw(FieldEffect *effect, void *state);

static const FieldEffectBasicTemplate sPuddleSplashEffectTemplate = {
    sizeof(PuddleSplashEffect),
    PuddleSplashEffect_Init,
    PuddleSplashEffect_Destroy,
    PuddleSplashEffect_Update,
    PuddleSplashEffect_Draw,
};

PuddleSplash *PuddleSplash_New(FieldEffectManager *manager) {
    PuddleSplash *splash = FieldEffectManager_HeapAllocAndFill(manager, sizeof(PuddleSplash), FALSE, 0);
    splash->manager = manager;
    PuddleSplash_LoadGfx(splash);
    return splash;
}

void PuddleSplash_Free(PuddleSplash *splash) {
    PuddleSplash_FreeGfx(splash);
    FieldEffectManager_HeapFree(splash);
}

static void PuddleSplash_LoadGfx(PuddleSplash *splash) {
    FieldEffectManager_LoadRenderModel(splash->manager, &splash->model, 0, 0x1D, FALSE);
    FieldEffectManager_LoadRenderAnimation(splash->manager, &splash->animation, 0, 0x86, FALSE);
}

static void PuddleSplash_FreeGfx(PuddleSplash *splash) {
    RenderModel_Free(&splash->model);
    RenderAnimation_Free(&splash->animation);
}

void PuddleSplash_Spawn(LocalMapObject *mapObject, int x, int y, int z) {
    PuddleSplashEffectArgs args;
    VecFx32 position;

    if (MapObject_TestFlagsBits(mapObject, MAPOBJECTFLAG_INVISIBLE) == TRUE) {
        return;
    }
    args.manager = FieldEffectManager_GetFromMapObject(mapObject);
    args.splash = FieldEffectManager_GetRendererData(args.manager, FIELD_EFFECT_RENDERER_PUDDLE_SPLASH);
    SetPositionToTileCenter(x, z, &position);
    position.z += y * 8 + FX32_ONE;
    position.y = (MapObject_GetPreviousYCoord(mapObject) << 15) - FX32_CONST(8);
    FieldEffectManager_CreateEffect(args.manager, &sPuddleSplashEffectTemplate, &position, 0, &args, MapObject_GetPriorityPlusValue(mapObject, 2));
}

static BOOL PuddleSplashEffect_Init(FieldEffect *effect, void *state) {
    PuddleSplashEffect *work = state;
    PuddleSplashEffectArgs *args = FieldEffect_GetUserData(effect);
    work->args = *args;
    FieldEffectManager_InitRenderAnimation(work->args.manager, &work->animation, &work->args.splash->model, &work->args.splash->animation, 0);
    RenderObj_InitWithAnimation(&work->renderObj, &work->args.splash->model, &work->animation);
    return TRUE;
}

static void PuddleSplashEffect_Destroy(FieldEffect *effect, void *state) {
    PuddleSplashEffect *work = state;
    RenderAnimation_Free(&work->animation);
}

static void PuddleSplashEffect_Update(FieldEffect *effect, void *state) {
    PuddleSplashEffect *work = state;
    if (RenderAnimation_IsDone(&work->animation) == TRUE) {
        FieldEffectManager_DestroyEffect(effect);
        return;
    }
    RenderAnimation_Advance(&work->animation, FX32_ONE, FALSE);
}

static void PuddleSplashEffect_Draw(FieldEffect *effect, void *state) {
    PuddleSplashEffect *work = state;
    VecFx32 position;
    FieldEffect_GetPosition(effect, &position);
    RenderObj_DrawAt(&work->renderObj, &position);
}
