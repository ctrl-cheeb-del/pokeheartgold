#ifndef POKEHEARTGOLD_FIELD_FLY_LANDING_EFFECT_H
#define POKEHEARTGOLD_FIELD_FLY_LANDING_EFFECT_H

#include "field/field_effect_manager.h"
#include "field/sprite_gfx_manager.h"
#include "field_system.h"
#include "filesystem.h"
#include "sprite.h"

// Fly arrival: the flying Pokemon swoops in carrying the trainer sprite, drops them and flies off, then the trainer
// sprite is swapped for the player object. The update runs the current phase's steps until one returns FALSE.

enum FlyLandingStatus {
    FLY_LANDING_RUNNING = 0,
    FLY_LANDING_STARTED,
    FLY_LANDING_DONE,
};

// Effect user data, copied into the state by FlyLandingEffect_Init.
typedef struct FlyLandingEffectArgs {
    FieldEffectPool *effectPool; // the pool the effect runs in
    FieldSystem *fieldSystem;
    Sprite *trainerSprite;
    SpriteGfxManager *gfxManager;
} FlyLandingEffectArgs;

typedef struct FlyLandingEffect {
    u8 phase; // 0: idle, 1: animating
    u8 step;
    u8 status; // enum FlyLandingStatus
    int timer;
    VecFx32 center;
    VecFx32 offset; // from center, along the flight arc
    u8 unused_20[0xC];
    VecFx32 scale;
    fx32 rotation; // degrees
    u8 unused_3C[4];
    fx32 angle; // degrees, direction of the arc
    u8 unused_44[4];
    fx32 radius;
    fx32 radiusSpeed;
    fx32 scaleSpeed;
    u8 unused_54[4];
    FlyLandingEffectArgs args;
    Sprite *flyerSprite;
    FieldEffect *trainerJumpEffect;
    SysTask *cameraZoom;
} FlyLandingEffect;

Sprite *FlyLanding_CreateTrainerSprite(SpriteGfxManager *gfxManager, u32 gender);
FieldEffect *FlyLandingEffect_Create(FieldSystem *fieldSystem, FieldEffectPool *effectPool, SpriteGfxManager *gfxManager, Sprite *trainerSprite);
u8 FlyLandingEffect_GetStatus(FieldEffect *effect);
void FlyLandingEffect_Delete(FieldEffect *effect);
void FlyLandingEffect_Start(FieldEffect *effect);
NARC *FlyLanding_OpenNarc(void);
void FieldMove_FadeOutToWhite(void);
void FieldMove_SetPlayerInvisible(FieldSystem *fieldSystem, BOOL invisible);

// Callbacks of the Fly landing effect and the steps of its phases.
BOOL FlyLandingEffect_Init(FieldEffect *effect, FlyLandingEffect *landing);
void FlyLandingEffect_Destroy(FieldEffect *effect, FlyLandingEffect *landing);
void FlyLandingEffect_Update(FieldEffect *effect, FlyLandingEffect *landing);
BOOL FlyLandingEffect_Idle(FlyLandingEffect *landing);
BOOL FlyLandingEffect_SwoopIn(FlyLandingEffect *landing);
BOOL FlyLandingEffect_StartClimb(FlyLandingEffect *landing);
BOOL FlyLandingEffect_Climb(FlyLandingEffect *landing);
BOOL FlyLandingEffect_HideFlyer(FlyLandingEffect *landing);
BOOL FlyLandingEffect_StartFlyAway(FlyLandingEffect *landing);
BOOL FlyLandingEffect_FlyAway(FlyLandingEffect *landing);
BOOL FlyLandingEffect_ShowPlayer(FlyLandingEffect *landing);
BOOL FlyLandingEffect_Done(FlyLandingEffect *landing);

extern const VecFx32 gFlyLandingFlyerScale;
extern const FieldEffectBasicTemplate gFlyLandingEffectTemplate;
extern const VecFx32 gFlyLandingSwoopCenter;
extern const VecFx32 gFlyLandingSwoopScale;
extern const VecFx32 gFlyLandingTrainerScale;
extern const VecFx32 gFlyLandingFlyAwayCenter;
extern const VecFx32 gFlyLandingFlyAwayScale;

#endif // POKEHEARTGOLD_FIELD_FLY_LANDING_EFFECT_H
