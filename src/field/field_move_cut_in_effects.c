#include "global.h"

#include "constants/std_script.h"

#include "application/choose_starter/choose_starter_sub_res.naix"
#include "field/field_3d_model.h"
#include "field/field_camera_zoom.h"
#include "field/field_effect_helpers.h"
#include "field/field_move_cut_in.h"
#include "field/fly_landing_effect.h"
#include "field/map_prop_anims.h"
#include "field/sprite_gfx_manager.h"
#include "overlay_2/overlay_02_field_utils.h"

#include "char_tiles.h"
#include "field_effects.h"
#include "field_roamer.h"
#include "field_system.h"
#include "field_terrain.h"
#include "filesystem.h"
#include "heap.h"
#include "map_matrix.h"
#include "map_object.h"
#include "math_util.h"
#include "overlay_02.h"
#include "party.h"
#include "pokemon.h"
#include "roamer.h"
#include "save_vars_flags.h"
#include "script_manager.h"
#include "sprite.h"
#include "sprite_transfer.h"
#include "sys_task_api.h"
#include "sys_vars.h"
#include "task.h"

// The effects drawn in the field move cut-in (banner sprites, the Pokemon flying off with the trainer, the trainer's
// jump, the 3D model at a second map object), the Fly landing task, and the roamer updates after a battle.

// Effect state of the sprites scrolling across the banner, one row of the template table (two copies 256 px apart).
typedef struct CutInScrollSpriteTemplate {
    fx32 x;
    fx32 y;
    fx32 speed;
    u32 drawPriority;
    u32 animSeq;
} CutInScrollSpriteTemplate;

typedef struct CutInScrollSpriteArgs {
    u32 drawPriority;
    int mode; // 1: drawn only inside the cut-in window
    FieldMoveCutIn *cutIn;
    VecFx32 velocity;
} CutInScrollSpriteArgs;

typedef struct CutInScrollSprite {
    u32 unk_00;
    int animSeq;
    Sprite *sprite;
    CutInScrollSpriteArgs args;
} CutInScrollSprite;

enum CutInFlyerMode {
    CUT_IN_FLYER_HIDDEN,
    CUT_IN_FLYER_TAKE_OFF,
    CUT_IN_FLYER_PICK_UP,
};

// The flying Pokemon (FieldMoveCutIn.flyerEffect): a small state machine per mode (step tables gCutInFlyerModeSteps).
typedef struct CutInFlyer {
    u8 mode;
    u8 step;
    u8 status; // read by FieldMoveCutIn_GetFlyerStatus
    int timer;
    VecFx32 origin;
    VecFx32 offset;
    u8 padding_20[0xC];
    VecFx32 scale;
    fx32 rotation; // degrees
    int unk_3C;
    fx32 angle; // degrees, direction of the motion
    int unk_44;
    fx32 distance;
    fx32 speed;
    fx32 scaleSpeed;
    fx32 trainerOffsetY;
    Sprite *sprite;
    FieldMoveCutIn *cutIn;
    FieldEffect *trainerJumpEffect;
    SysTask *cameraZoom;
} CutInFlyer;

typedef BOOL (*CutInFlyerStep)(CutInFlyer *flyer);

// The trainer sprite's jump onto the flying Pokemon (FieldMoveCutIn_CreateTrainerJumpEffect).
typedef struct TrainerJumpArgs {
    void *unused;
    Sprite *sprite;
} TrainerJumpArgs;

enum TrainerJumpMode {
    TRAINER_JUMP_IDLE,
    TRAINER_JUMP_JUMP,
    TRAINER_JUMP_HOP,
};

enum CutInModelEffectStep {
    CUT_IN_MODEL_STEP_START,
    CUT_IN_MODEL_STEP_SHOW,
    CUT_IN_MODEL_STEP_ANIMATE,
    CUT_IN_MODEL_STEP_DONE,
};

typedef struct TrainerJump {
    enum TrainerJumpMode mode;
    int step;
    BOOL done;
    int frame;
    int unk_10;
    fx32 offsetY;
    int unk_18;
    void *unused; // TrainerJumpArgs.unused, never set
    Sprite *sprite;
} TrainerJump;

// Shows the trainer sprite only inside the cut-in window until the flyer has picked it up.
typedef struct TrainerClip {
    Sprite *sprite;
    FieldMoveCutIn *cutIn;
} TrainerClip;

typedef struct CutInModelEffect {
    FieldMoveCutIn *cutIn;
    enum CutInModelEffectStep step;
    BOOL done;
} CutInModelEffect;

// The Fly landing task (FlyLanding_Start): the flying Pokemon drops the trainer at the destination.
typedef struct FlyLanding {
    int state;
    BOOL done;
    int unk_08;
    u32 gender;
    BOOL drawSprites;
    FieldSystem *fieldSystem;
    SpriteGfxManager gfx;
    Sprite *trainerSprite;
    FieldEffectPool *effectPool;
    FieldEffect *landingEffect;
    int unk_178;
} FlyLanding;

typedef BOOL (*FlyLandingStep)(FlyLanding *landing);

extern const CutInScrollSpriteTemplate gCutInScrollSpriteTemplates[];
extern CutInFlyerStep *const gCutInFlyerModeSteps[3];
extern FlyLandingStep const gFlyLandingTaskSteps[6];

static void Task_FlyLanding(SysTask *task, void *data);
static Roamer *Roamers_GetActiveRoamerBySpecies(RoamerSaveData *roamerSave, u32 species);
static void Roamers_RelocateFromMap(RoamerSaveData *roamerSave, u32 mapId);
BOOL CutInScrollSprite_Init(FieldEffect *effect, CutInScrollSprite *work);
void CutInScrollSprite_Destroy(FieldEffect *effect, CutInScrollSprite *work);
void CutInScrollSprite_Update(FieldEffect *effect, CutInScrollSprite *work);
void CutInScrollSprite_Draw(FieldEffect *effect, CutInScrollSprite *work);
BOOL CutInFlyer_Init(FieldEffect *effect, CutInFlyer *flyer);
void CutInFlyer_Destroy(FieldEffect *effect, CutInFlyer *flyer);
void CutInFlyer_Update(FieldEffect *effect, CutInFlyer *flyer);
void CutInFlyer_Draw(FieldEffect *effect, CutInFlyer *flyer);
BOOL CutInFlyer_Hide(CutInFlyer *flyer);
BOOL CutInFlyer_TakeOff(CutInFlyer *flyer);
BOOL CutInFlyer_Idle(CutInFlyer *flyer);
BOOL CutInFlyer_SwoopDown(CutInFlyer *flyer);
BOOL CutInFlyer_PickUpTrainer(CutInFlyer *flyer);
BOOL CutInFlyer_FlyAway(CutInFlyer *flyer);
BOOL CutInFlyer_Done(CutInFlyer *flyer);
BOOL TrainerJumpEffect_Init(FieldEffect *effect, TrainerJump *jump);
static void TrainerJumpEffect_Jump(FieldEffect *effect, TrainerJump *jump);
static void TrainerJumpEffect_Hop(FieldEffect *effect, TrainerJump *jump);
void TrainerJumpEffect_Update(FieldEffect *effect, TrainerJump *jump);
BOOL FlyLanding_SetPlayerVisible(FlyLanding *landing);
BOOL FlyLanding_LoadGraphics(FlyLanding *landing);
BOOL FlyLanding_CreateSprites(FlyLanding *landing);
BOOL FlyLanding_WaitLanding(FlyLanding *landing);
BOOL FlyLanding_FreeGraphics(FlyLanding *landing);
BOOL FlyLanding_Idle(FlyLanding *landing);
BOOL TrainerClipEffect_Init(FieldEffect *effect, TrainerClip *clip);
void TrainerClipEffect_Update(FieldEffect *effect, TrainerClip *clip);
BOOL CutInModelEffect_Init(FieldEffect *effect, CutInModelEffect *work);
void CutInModelEffect_Destroy(FieldEffect *effect, CutInModelEffect *work);
void CutInModelEffect_Update(FieldEffect *effect, CutInModelEffect *work);
void CutInModelEffect_Draw(FieldEffect *effect, CutInModelEffect *work);
BOOL FieldMoveCutIn_StepShowOtherObject(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepWaitModelEffect(FieldMoveCutIn *cutIn);

static void FieldMoveCutIn_CreateScrollSprite(FieldMoveCutIn *cutIn, const VecFx32 *position, const VecFx32 *velocity, u32 drawPriority, u32 animSeq, int mode);
static void TrainerJumpEffect_Stop(FieldEffect *effect);
static void TrainerJumpEffect_StartJump(FieldEffect *effect);
static void FieldMoveCutIn_CreateModelEffect(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_LoadModel(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_UnloadModel(FieldMoveCutIn *cutIn);

void Task_FieldMoveCutIn_UpdateWindow(SysTask *task, void *data) {
    FieldMoveCutIn *cutIn = data;
    int winin;
    int winout;

    if (!cutIn->windowUpdate) {
        return;
    }
    GX_SetVisibleWnd(cutIn->windowEnabled);
    winin = (reg_G2_WININ & ~0x3f) | cutIn->windowInsidePlanes;
    if (cutIn->windowInsideEffects) {
        winin |= 0x20;
    }
    reg_G2_WININ = winin;
    winout = (reg_G2_WINOUT & ~0x3f) | cutIn->windowOutsidePlanes;
    if (cutIn->windowOutsideEffects) {
        winout |= 0x20;
    }
    reg_G2_WINOUT = winout;
    {
        int bottom = cutIn->windowBottom / FX32_ONE;
        int top = cutIn->windowTop / FX32_ONE;
        reg_G2_WIN0H = (cutIn->windowLeft / FX32_ONE) << 8 & 0xff00 | (u8)(cutIn->windowRight / FX32_ONE);
        reg_G2_WIN0V = top << 8 & 0xff00 | (u8)bottom;
    }
}

void FieldMoveCutIn_GetMonPicIds(FieldMoveCutIn *cutIn, PokepicTemplate *template) {
    GetPokemonSpriteCharAndPlttNarcIds(template, cutIn->mon, 2);
}

void *FieldMoveCutIn_LoadMonChar(Pokemon *mon, PokepicTemplate *template, enum HeapID heapID) {
    void *buffer = Heap_Alloc(HEAP_ID_FIELD1, 0xc80);
    GF_ASSERT(buffer);
    CharTiles_LoadMonPicAsObjFromNarc((NarcId) template->narcID, template->charDataID, heapID, buffer, GetMonData(mon, MON_DATA_PERSONALITY, NULL), FALSE, 2, template->species);
    return buffer;
}

void *FieldMoveCutIn_LoadMonPltt(PokepicTemplate *template, enum HeapID heapID) {
    return AllocAndLoadPltt16FromNarc((NarcId) template->narcID, template->palDataID, heapID);
}

SpriteResource *FieldMoveCutIn_AddMonCharResource(FieldMoveCutIn *cutIn, NARC *narc) {
    return AddCharResObjFromOpenNarc(cutIn->resMan[GF_GFX_RES_TYPE_CHAR], narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000009_NCGR, FALSE, 3, NNS_G2D_VRAM_TYPE_2DMAIN, HEAP_ID_FIELD1);
}

void FieldMoveCutIn_TransferMonChar(FieldMoveCutIn *cutIn, void *data) {
    SpriteResource *res = SpriteResourceCollection_Find(cutIn->resMan[GF_GFX_RES_TYPE_CHAR], 3);
    NNSG2dImageProxy *proxy = SpriteTransfer_GetCharProxy(res);
    u32 dst = NNS_G2dGetImageLocation(proxy, NNS_G2D_VRAM_TYPE_2DMAIN);
    DC_FlushRange(data, 0xc80);
    GX_LoadOBJ(data, dst, 0xc80);
}

SpriteResource *FieldMoveCutIn_AddMonPlttResource(FieldMoveCutIn *cutIn, NARC *narc) {
    return AddPlttResObjFromOpenNarc(cutIn->resMan[GF_GFX_RES_TYPE_PLTT], narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000006_NCLR, FALSE, 3, NNS_G2D_VRAM_TYPE_2DMAIN, 1, HEAP_ID_FIELD1);
}

void FieldMoveCutIn_TransferMonPltt(FieldMoveCutIn *cutIn, void *data) {
    SpriteResource *charRes = SpriteResourceCollection_Find(cutIn->resMan[GF_GFX_RES_TYPE_CHAR], 3);
    NNSG2dImageProxy *charProxy = SpriteTransfer_GetCharProxy(charRes);
    SpriteResource *plttRes = SpriteResourceCollection_Find(cutIn->resMan[GF_GFX_RES_TYPE_PLTT], 3);
    NNSG2dImagePaletteProxy *plttProxy = SpriteTransfer_GetPaletteProxy(plttRes, charProxy);
    u32 dst = NNS_G2dGetImagePaletteLocation(plttProxy, NNS_G2D_VRAM_TYPE_2DMAIN);
    DC_FlushRange(data, 0x20);
    GX_LoadOBJPltt(data, dst, 0x20);
}

void FieldMoveCutIn_FreeMonResources(FieldMoveCutIn *cutIn) {
    int i;

    {
        SpriteResource *res = SpriteResourceCollection_Find(cutIn->resMan[GF_GFX_RES_TYPE_CHAR], 3);
        SpriteTransfer_DeleteCharTransferTask(res);
        DestroySingle2DGfxResObj(cutIn->resMan[GF_GFX_RES_TYPE_CHAR], res);
        for (i = 0; i < 4; i++) {
            if (cutIn->charResources[i] == res) {
                cutIn->charResources[i] = NULL;
                break;
            }
        }
        GF_ASSERT(i < 4);
    }
    {
        SpriteResource *res = SpriteResourceCollection_Find(cutIn->resMan[GF_GFX_RES_TYPE_PLTT], 3);
        SpriteTransfer_DeletePlttTransferTask(res);
        DestroySingle2DGfxResObj(cutIn->resMan[GF_GFX_RES_TYPE_PLTT], res);
        for (i = 0; i < 3; i++) {
            if (cutIn->plttResources[i] == res) {
                cutIn->plttResources[i] = NULL;
                break;
            }
        }
        GF_ASSERT(i < 3);
    }
    {
        SpriteResource *res = SpriteResourceCollection_Find(cutIn->resMan[GF_GFX_RES_TYPE_CELL], 3);
        GF2DGfxResObj_FreeData(res);
        DestroySingle2DGfxResObj(cutIn->resMan[GF_GFX_RES_TYPE_CELL], res);
        for (i = 0; i < 4; i++) {
            if (cutIn->cellResources[i] == res) {
                cutIn->cellResources[i] = NULL;
                break;
            }
        }
        GF_ASSERT(i < 4);
    }
}

Sprite *FieldMoveCutIn_CreateMonSprite(FieldMoveCutIn *cutIn, VecFx32 *pos) {
    return FieldMoveCutIn_CreateSprite(cutIn, pos, 3, 3, 3, -1, 0, 0x81);
}

void FieldMoveCutIn_CreateScrollSprites(FieldMoveCutIn *cutIn, int mode) {
    int i;
    const CutInScrollSpriteTemplate *template = gCutInScrollSpriteTemplates;
    VecFx32 position;
    VecFx32 velocity;
    u32 animSeq;
    u32 drawPriority;
    cutIn->scrollSpriteMode = 2;

    for (i = 0; i < 13; i++, template ++) {
        position.x = template->x;
        position.y = template->y;
        position.z = 0;
        velocity.x = template->speed;
        velocity.y = 0;
        velocity.z = 0;
        drawPriority = template->drawPriority;
        animSeq = template->animSeq;
        FieldMoveCutIn_CreateScrollSprite(cutIn, &position, &velocity, drawPriority, animSeq, mode);
        position.x += FX32_CONST(256);
        FieldMoveCutIn_CreateScrollSprite(cutIn, &position, &velocity, drawPriority, animSeq, mode);
    }
}

static void FieldMoveCutIn_CreateScrollSprite(FieldMoveCutIn *cutIn, const VecFx32 *position, const VecFx32 *velocity, u32 drawPriority, u32 animSeq, int mode) {
    CutInScrollSpriteArgs args;

    args.drawPriority = drawPriority;
    args.mode = mode;
    args.cutIn = cutIn;
    args.velocity = *velocity;
    FieldEffectPool_AddBasicEffect(cutIn->effectPool, &gCutInScrollSpriteEffectTemplate, position, animSeq, &args, 0x85);
}

BOOL CutInScrollSprite_Init(FieldEffect *effect, CutInScrollSprite *work) {
    VecFx32 position;
    CutInScrollSpriteArgs *args = FieldEffect_GetUserData(effect);
    work->args = *args;
    work->animSeq = FieldEffect_GetParam(effect);
    FieldEffect_GetPosition(effect, &position);
    work->sprite = FieldMoveCutIn_CreateEffectSprite(work->args.cutIn, &position, work->args.drawPriority, work->animSeq);
    Sprite_SetDrawFlag(work->sprite, FALSE);
    return TRUE;
}

void CutInScrollSprite_Destroy(FieldEffect *effect, CutInScrollSprite *work) {
    Sprite_Delete(work->sprite);
}

void CutInScrollSprite_Update(FieldEffect *effect, CutInScrollSprite *work) {
    VecFx32 pos;
    FieldEffect_GetPosition(effect, &pos);
    pos.x += work->args.velocity.x;
    pos.x %= 1 << 21;
    FieldEffect_SetPosition(effect, &pos);
    Sprite_SetMatrix(work->sprite, &pos);
    if (work->args.mode == 1) {
        FieldMoveCutIn *cutIn = work->args.cutIn;
        if (cutIn->scrollSpriteMode == 2) {
            BOOL visible = FALSE;
            int top = cutIn->windowTop, bottom = cutIn->windowBottom;
            int spriteTop = pos.y - FX32_CONST(2);
            if (spriteTop >= top && spriteTop <= bottom && pos.y + FX32_CONST(2) >= top && pos.y + FX32_CONST(2) <= bottom) {
                visible = TRUE;
            }
            Sprite_SetDrawFlag(work->sprite, visible);
        } else if (cutIn->scrollSpriteMode == 1) {
            Sprite_SetDrawFlag(work->sprite, FALSE);
        }
    }
}

void CutInScrollSprite_Draw(FieldEffect *effect, CutInScrollSprite *work) {
}

void FieldMoveCutIn_CreateFlyer(FieldMoveCutIn *cutIn) {
    VecFx32 pos = { 0, 0, 0 };
    FieldMoveCutIn *userData = cutIn;
    cutIn->flyerEffect = FieldEffectPool_AddBasicEffect(cutIn->effectPool, &gCutInFlyerEffectTemplate, &pos, 0, &userData, 0x82);
}

u8 FieldMoveCutIn_GetFlyerStatus(FieldMoveCutIn *cutIn) {
    CutInFlyer *flyer = FieldEffect_GetState(cutIn->flyerEffect);
    return flyer->status;
}

void FieldMoveCutIn_DestroyFlyer(FieldMoveCutIn *cutIn) {
    CutInFlyer *flyer = FieldEffect_GetState(cutIn->flyerEffect);
    if (flyer->trainerJumpEffect) {
        FieldEffect_Destroy(flyer->trainerJumpEffect);
    }
    if (flyer->cameraZoom) {
        FieldCameraZoom_End(flyer->cameraZoom);
    }
    FieldEffect_Destroy(cutIn->flyerEffect);
}

BOOL CutInFlyer_Init(FieldEffect *effect, CutInFlyer *flyer) {
    VecFx32 pos;
    FieldMoveCutIn **userData = FieldEffect_GetUserData(effect);
    flyer->cutIn = *userData;
    FieldEffect_GetPosition(effect, &pos);
    flyer->sprite = FieldMoveCutIn_CreateFlyerSprite(flyer->cutIn, &pos, 0, 0);
    return TRUE;
}

void CutInFlyer_Destroy(FieldEffect *effect, CutInFlyer *flyer) {
    Sprite_Delete(flyer->sprite);
}

void CutInFlyer_Update(FieldEffect *effect, CutInFlyer *flyer) {
    CutInFlyerStep *steps = gCutInFlyerModeSteps[flyer->mode];
    while (steps[flyer->step](flyer) == TRUE) {
    }
}

void CutInFlyer_Draw(FieldEffect *effect, CutInFlyer *flyer) {
}

BOOL CutInFlyer_Hide(CutInFlyer *flyer) {
    flyer->status = 0;
    Sprite_SetDrawFlag(flyer->sprite, FALSE);
    return FALSE;
}

void FieldMoveCutIn_StartFlyerTakeOff(FieldMoveCutIn *cutIn) {
    VecFx32 origin;
    VecFx32 scale;
    CutInFlyer *flyer;
    origin = gCutInFlyerTakeOffOrigin;
    scale = gCutInFlyerTakeOffScale;
    flyer = FieldEffect_GetState(cutIn->flyerEffect);
    flyer->mode = CUT_IN_FLYER_TAKE_OFF;
    flyer->step = 0;
    flyer->status = 0;
    flyer->origin = origin;
    flyer->offset.x = 0;
    flyer->offset.y = 0;
    flyer->offset.z = 0;
    flyer->rotation = FX32_CONST(60);
    flyer->scale = scale;
    flyer->scaleSpeed = FX32_CONST(0.125);
    flyer->angle = FX32_CONST(180);
    flyer->distance = 0;
    flyer->speed = FX32_CONST(2);
    Sprite_SetMatrix(flyer->sprite, &origin);
    Sprite_SetAffineScale(flyer->sprite, &scale);
    Sprite_SetAffineZRotation(flyer->sprite, GF_DegreeToSinCosIdx(flyer->rotation / FX32_ONE));
    Sprite_SetDrawFlag(flyer->sprite, TRUE);
}

BOOL CutInFlyer_TakeOff(CutInFlyer *flyer) {
    Sprite *sprite = flyer->sprite;
    VecFx32 mtx;
    flyer->distance = flyer->distance + flyer->speed;
    if (flyer->speed < FX32_CONST(16)) {
        flyer->speed += FX32_CONST(4);
    }
    flyer->offset.x = GF_CosDeg(315) * (flyer->distance / FX32_ONE);
    flyer->offset.y = GF_SinDeg(flyer->angle / FX32_ONE) * (flyer->distance / FX32_ONE);
    if (flyer->angle / FX32_ONE < 270) {
        flyer->angle += FX32_CONST(4);
    }
    flyer->scale.x = flyer->scale.x + flyer->scaleSpeed;
    if (flyer->scale.x > FX32_ONE) {
        flyer->scale.x = FX32_ONE;
    }
    flyer->scale.y = flyer->scale.y + flyer->scaleSpeed;
    if (flyer->scale.y > FX32_ONE) {
        flyer->scale.y = FX32_ONE;
    }
    Sprite_SetAffineScale(sprite, &flyer->scale);
    flyer->rotation -= FX32_CONST(6);
    if (flyer->rotation / FX32_ONE < 0) {
        flyer->rotation = 0;
    }
    Sprite_SetAffineZRotation(sprite, GF_DegreeToSinCosIdx(flyer->rotation / FX32_ONE));
    mtx.x = flyer->origin.x + flyer->offset.x;
    mtx.y = flyer->origin.y + flyer->offset.y;
    Sprite_SetMatrix(sprite, &mtx);
    if (mtx.y < -FX32_CONST(64)) {
        Sprite_SetDrawFlag(sprite, FALSE);
        flyer->status = 2;
        flyer->step++;
    }
    return FALSE;
}

BOOL CutInFlyer_Idle(CutInFlyer *flyer) {
    return FALSE;
}

void FieldMoveCutIn_StartFlyerPickUp(FieldMoveCutIn *cutIn) {
    VecFx32 position = gCutInFlyerPickUpPos;
    VecFx32 scale = gCutInFlyerPickUpScale;
    VecFx32 matrix;
    VecFx32 trainerScale;
    CutInFlyer *flyer = FieldEffect_GetState(cutIn->flyerEffect);
    Sprite *sprite;

    flyer->mode = CUT_IN_FLYER_PICK_UP;
    flyer->step = 0;
    flyer->status = 1;
    flyer->timer = 0;
    position.x += cutIn->otherObjectOffset.x;
    position.y += cutIn->otherObjectOffset.z;
    flyer->origin = position;
    flyer->offset.x = 0;
    flyer->offset.y = 0;
    flyer->offset.z = 0;
    flyer->rotation = FX32_CONST(315);
    flyer->scale = scale;
    flyer->scaleSpeed = 0x100;
    flyer->angle = FX32_CONST(225);
    flyer->distance = FX32_CONST(192);
    flyer->speed = FX32_CONST(32);
    flyer->offset.x = GF_CosDeg(315) * (flyer->distance / FX32_ONE);
    flyer->offset.y = GF_SinDeg(flyer->angle / FX32_ONE) * (flyer->distance / FX32_ONE);
    position.x = flyer->origin.x + flyer->offset.x;
    position.y = flyer->origin.y + flyer->offset.y;
    Sprite_SetMatrix(flyer->sprite, &position);
    Sprite_SetAffineScale(flyer->sprite, &scale);
    Sprite_SetAffineZRotation(flyer->sprite, GF_DegreeToSinCosIdx(flyer->rotation / FX32_ONE));
    Sprite_SetDrawFlag(flyer->sprite, TRUE);
    flyer->trainerJumpEffect = FieldMoveCutIn_CreateTrainerJumpEffect(cutIn->effectPool, cutIn->trainerSprite);
    cutIn->flyStarted = TRUE;
    flyer->cameraZoom = FieldCameraZoom_Start(cutIn->fieldSystem, HEAP_ID_FIELD1);
    FieldCameraZoom_Set(flyer->cameraZoom, FIELD_CAMERA_ZOOM_BY, FX32_CONST(-120), 12);
    {
        fx32 *values = (fx32 *)&matrix;
        values[0] = 0;
        values[1] = 0;
        values[2] = 0;
    }
    trainerScale = gCutInFlyerTrainerScale;
    sprite = flyer->cutIn->trainerSprite;
    Sprite_SetAffineOverwriteMode(sprite, NNS_G2D_RND_AFFINE_OVERWRITE_DOUBLE);
    Sprite_SetAffineMatrix(sprite, &matrix);
    Sprite_SetAffineScale(sprite, &trainerScale);
    Sprite_SetAffineZRotation(sprite, GF_DegreeToSinCosIdx(0));
}

BOOL CutInFlyer_SwoopDown(CutInFlyer *flyer) {
    Sprite *sprite = flyer->sprite;
    VecFx32 matrix;
    VecFx32 scale;

    flyer->distance -= flyer->speed;
    if (flyer->distance < 0) {
        flyer->distance = 0;
    }
    if (flyer->speed > FX32_CONST(0.5)) {
        flyer->speed -= FX32_CONST(1.5);
    }
    if (flyer->speed < FX32_ONE) {
        flyer->speed = FX32_ONE;
    }
    flyer->offset.x = GF_CosDeg(315) * (flyer->distance / FX32_ONE);
    flyer->offset.y = GF_SinDeg(flyer->angle / FX32_ONE) * (flyer->distance / FX32_ONE);
    if (flyer->angle / FX32_ONE < 270) {
        flyer->angle += FX32_CONST(4);
    }
    flyer->scale.x += flyer->scaleSpeed;
    if (flyer->scale.x > FX32_CONST(1.5)) {
        flyer->scale.x = FX32_CONST(1.5);
    }
    flyer->scale.y += flyer->scaleSpeed;
    if (flyer->scale.y > FX32_CONST(1.5)) {
        flyer->scale.y = FX32_CONST(1.5);
    }
    Sprite_SetAffineScale(sprite, &flyer->scale);
    flyer->rotation += FX32_CONST(8);
    if (flyer->rotation / FX32_ONE > 360) {
        flyer->rotation = FX32_CONST(360);
    }
    Sprite_SetAffineZRotation(sprite, GF_DegreeToSinCosIdx(flyer->rotation / FX32_ONE));
    matrix.x = flyer->origin.x + flyer->offset.x;
    matrix.y = flyer->origin.y + flyer->offset.y;
    Sprite_SetMatrix(sprite, &matrix);
    if (flyer->distance == 0) {
        flyer->timer = 0;
        flyer->step++;
    } else {
        flyer->timer++;
    }
    if (flyer->timer == 0xc) {
        TrainerJumpEffect_StartJump(flyer->trainerJumpEffect);
    }
    sprite = flyer->cutIn->trainerSprite;
    scale = *Sprite_GetScalePtr(sprite);
    scale.x += 0x80;
    if (scale.x > FX32_CONST(1.25)) {
        scale.x = FX32_CONST(1.25);
    }
    scale.y += 0x80;
    if (scale.y > FX32_CONST(1.25)) {
        scale.y = FX32_CONST(1.25);
    }
    Sprite_SetAffineScale(sprite, &scale);
    return FALSE;
}

BOOL CutInFlyer_PickUpTrainer(CutInFlyer *flyer) {
    Sprite *sprite = flyer->cutIn->trainerSprite;
    s32 y;

    Sprite_SetAnimCtrlSeq(sprite, 3);
    Sprite_SetDrawFlag(sprite, TRUE);
    FieldMoveCutIn_SetPlayerVisible(flyer->cutIn, TRUE);
    MapObject_CallDrawUpdate(flyer->cutIn->playerObject);
    y = Sprite_GetMatrixPtr(sprite)->y;
    flyer->trainerOffsetY = y - Sprite_GetMatrixPtr(flyer->sprite)->y;
    TrainerJumpEffect_Stop(flyer->trainerJumpEffect);
    FieldCameraZoom_Set(flyer->cameraZoom, FIELD_CAMERA_ZOOM_BACK, 0, 12);
    flyer->scaleSpeed = 0x100;
    flyer->angle = FX32_CONST(128);
    flyer->distance = 0;
    flyer->speed = FX32_CONST(0.5);
    flyer->status = 3;
    flyer->step++;
    return TRUE;
}

BOOL CutInFlyer_FlyAway(CutInFlyer *flyer) {
    Sprite *sprite = flyer->sprite;
    Sprite *trainer;
    VecFx32 *scalePtr;
    VecFx32 matrix;
    VecFx32 trainerMatrix;
    VecFx32 scale;

    flyer->distance += flyer->speed;
    flyer->speed += FX32_ONE;
    if (flyer->speed > FX32_CONST(16)) {
        flyer->speed = FX32_CONST(16);
    }
    flyer->offset.x = GF_CosDeg(flyer->angle / FX32_ONE) * (flyer->distance / FX32_ONE);
    flyer->offset.y = GF_SinDeg(128) * (flyer->distance / FX32_ONE);
    if (flyer->angle < FX32_CONST(135)) {
        flyer->angle += FX32_ONE;
    }
    flyer->scale.x += flyer->scaleSpeed;
    if (flyer->scale.x > FX32_CONST(2)) {
        flyer->scale.x = FX32_CONST(2);
    }
    flyer->scale.y += flyer->scaleSpeed;
    if (flyer->scale.y > FX32_CONST(2)) {
        flyer->scale.y = FX32_CONST(2);
    }
    matrix.x = flyer->origin.x + flyer->offset.x;
    matrix.y = flyer->origin.y + flyer->offset.y;
    if (matrix.y / FX32_ONE >= 230) {
        flyer->status = 2;
        flyer->step++;
    }
    trainer = flyer->cutIn->trainerSprite;
    scalePtr = Sprite_GetScalePtr(trainer);
    trainerMatrix = matrix;
    scale = *scalePtr;
    flyer->trainerOffsetY -= FX32_ONE;
    trainerMatrix.y += flyer->trainerOffsetY;
    Sprite_SetMatrix(trainer, &trainerMatrix);
    scale.x += 0x100;
    if (scale.x > FX32_CONST(2)) {
        scale.x = FX32_CONST(2);
    }
    scale.y += 0x100;
    if (scale.y > FX32_CONST(2)) {
        scale.y = FX32_CONST(2);
    }
    Sprite_SetAffineScale(trainer, &scale);
    Sprite_SetAffineScale(sprite, &flyer->scale);
    Sprite_SetMatrix(sprite, &matrix);
    return FALSE;
}

BOOL CutInFlyer_Done(CutInFlyer *flyer) {
    return FALSE;
}

FieldEffect *FieldMoveCutIn_CreateTrainerJumpEffect(FieldEffectPool *effectPool, Sprite *trainerSprite) {
    VecFx32 pos = { 0, 0, 0 };
    TrainerJumpArgs args;

    args.sprite = trainerSprite;
    return FieldEffectPool_AddBasicEffect(effectPool, &gTrainerJumpEffectTemplate, &pos, 0, &args, 0x81);
}

static void TrainerJumpEffect_Stop(FieldEffect *effect) {
    TrainerJump *jump = FieldEffect_GetState(effect);
    jump->mode = TRAINER_JUMP_IDLE;
}

static void TrainerJumpEffect_StartJump(FieldEffect *effect) {
    VecFx32 pos;
    TrainerJump *jump = FieldEffect_GetState(effect);
    jump->mode = TRAINER_JUMP_JUMP;
    jump->step = 0;
    jump->frame = 0;
    jump->done = FALSE;
    jump->unk_10 = 0;
    jump->offsetY = 0;
    jump->unk_18 = 0;
    pos = *Sprite_GetMatrixPtr(jump->sprite);
    FieldEffect_SetPosition(effect, &pos);
    Sprite_SetAnimCtrlSeq(jump->sprite, 5);
}

void TrainerJumpEffect_StartHop(FieldEffect *effect) {
    VecFx32 pos;
    TrainerJump *jump = FieldEffect_GetState(effect);
    jump->mode = TRAINER_JUMP_HOP;
    jump->step = 0;
    jump->frame = 0;
    jump->done = FALSE;
    jump->unk_10 = 0;
    jump->offsetY = 0;
    jump->unk_18 = 0;
    Sprite_CopyPositionVector(jump->sprite, &pos);
    FieldEffect_SetPosition(effect, &pos);
    Sprite_SetAnimCtrlSeq(jump->sprite, 4);
}

BOOL TrainerJumpEffect_Init(FieldEffect *effect, TrainerJump *jump) {
    TrainerJumpArgs *args = FieldEffect_GetUserData(effect);
    jump->unused = args->unused;
    jump->sprite = args->sprite;
    return TRUE;
}

static void TrainerJumpEffect_Jump(FieldEffect *effect, TrainerJump *jump) {
    VecFx32 pos;
    if (jump->step == 0) {
        jump->offsetY = gTrainerJumpOffsets[jump->frame];
        FieldEffect_GetPosition(effect, &pos);
        pos.y = pos.y + jump->offsetY;
        Sprite_SetMatrix(jump->sprite, &pos);
        if (++jump->frame >= 0xc) {
            jump->frame = 0;
            jump->done = TRUE;
            jump->step++;
        }
    }
}

static void TrainerJumpEffect_Hop(FieldEffect *effect, TrainerJump *jump) {
    VecFx32 pos;
    if (jump->step == 0) {
        jump->offsetY = gTrainerHopOffsets[jump->frame];
        FieldEffect_GetPosition(effect, &pos);
        pos.y = pos.y + jump->offsetY;
        Sprite_SetMatrix(jump->sprite, &pos);
        if (++jump->frame >= 4) {
            jump->frame = 0;
            jump->done = TRUE;
            jump->step++;
        }
    }
}

void TrainerJumpEffect_Update(FieldEffect *effect, TrainerJump *jump) {
    switch (jump->mode) {
    case TRAINER_JUMP_JUMP:
        TrainerJumpEffect_Jump(effect, jump);
        break;
    case TRAINER_JUMP_HOP:
        TrainerJumpEffect_Hop(effect, jump);
        break;
    }
}

SysTask *FlyLanding_Start(FieldSystem *fieldSystem, u32 gender) {
    FlyLanding *landing = FlyLanding_AllocZeroed(HEAP_ID_FIELD1, sizeof(FlyLanding));
    landing->gender = gender;
    landing->fieldSystem = fieldSystem;
    return SysTask_CreateOnMainQueue(Task_FlyLanding, landing, 0x86);
}

BOOL FlyLanding_IsDone(SysTask *task) {
    FlyLanding *landing = SysTask_GetData(task);
    return landing->done;
}

void FlyLanding_Delete(SysTask *task) {
    Heap_Free(SysTask_GetData(task));
    SysTask_Destroy(task);
}

static void Task_FlyLanding(SysTask *task, void *data) {
    FlyLanding *landing = data;
    FlyLandingStep const *steps = gFlyLandingTaskSteps;
    while (steps[landing->state](landing) == TRUE) {
    }
    if (landing->drawSprites) {
        if (landing->effectPool != NULL) {
            FieldEffectPool_DrawAll(landing->effectPool);
        }
        if (landing->gfx.spriteList != NULL) {
            SpriteList_RenderAndAnimateSprites(landing->gfx.spriteList);
        }
    }
}

BOOL FlyLanding_SetPlayerVisible(FlyLanding *landing) {
    FieldMove_SetPlayerVisible(landing->fieldSystem, TRUE);
    landing->state++;
    return FALSE;
}

BOOL FlyLanding_LoadGraphics(FlyLanding *landing) {
    NARC *narc;
    landing->effectPool = FieldEffectPool_New(HEAP_ID_FIELD1, 0x20);
    SpriteGfxManager_Init(&landing->gfx, 0x20, 2, 2, 2, 1, 4, 4, 4, 2);
    narc = FlyLanding_OpenNarc();
    SpriteGfxManager_LoadChar(&landing->gfx, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000011_NCGR, 0);
    SpriteGfxManager_LoadPltt(&landing->gfx, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000006_NCLR, 0);
    SpriteGfxManager_LoadCell(&landing->gfx, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000012_NCER, 0);
    SpriteGfxManager_TransferChar(&landing->gfx, 0);
    SpriteGfxManager_TransferPltt(&landing->gfx, 0);
    SpriteGfxManager_ReleaseCharData(&landing->gfx, 0);
    SpriteGfxManager_ReleasePlttData(&landing->gfx, 0);
    if (landing->gender == PLAYER_GENDER_MALE) {
        SpriteGfxManager_LoadChar(&landing->gfx, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000017_NCGR, 2);
        SpriteGfxManager_LoadCell(&landing->gfx, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000018_NCER, 2);
        SpriteGfxManager_LoadAnim(&landing->gfx, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000019_NANR, 1);
        SpriteGfxManager_TransferChar(&landing->gfx, 2);
        SpriteGfxManager_ReleaseCharData(&landing->gfx, 2);
    } else {
        SpriteGfxManager_LoadChar(&landing->gfx, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000020_NCGR, 2);
        SpriteGfxManager_LoadPltt(&landing->gfx, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000007_NCLR, 1);
        SpriteGfxManager_LoadCell(&landing->gfx, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000021_NCER, 2);
        SpriteGfxManager_LoadAnim(&landing->gfx, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000022_NANR, 1);
        SpriteGfxManager_TransferChar(&landing->gfx, 2);
        SpriteGfxManager_TransferPltt(&landing->gfx, 1);
        SpriteGfxManager_ReleaseCharData(&landing->gfx, 2);
        SpriteGfxManager_ReleasePlttData(&landing->gfx, 1);
    }
    NARC_Delete(narc);
    landing->state++;
    return FALSE;
}

BOOL FlyLanding_CreateSprites(FlyLanding *landing) {
    landing->trainerSprite = FlyLanding_CreateTrainerSprite(&landing->gfx, landing->gender);
    Sprite_SetDrawFlag(landing->trainerSprite, TRUE);
    landing->landingEffect = FlyLandingEffect_Create(landing->fieldSystem, landing->effectPool, &landing->gfx, landing->trainerSprite);
    FlyLandingEffect_Start(landing->landingEffect);
    landing->state++;
    landing->drawSprites = TRUE;
    return FALSE;
}

BOOL FlyLanding_WaitLanding(FlyLanding *landing) {
    if (FlyLandingEffect_GetStatus(landing->landingEffect) != FLY_LANDING_DONE) {
        return FALSE;
    }
    FlyLandingEffect_Delete(landing->landingEffect);
    landing->state = landing->state + 1;
    return FALSE;
}

BOOL FlyLanding_FreeGraphics(FlyLanding *landing) {
    FieldEffectPool_Delete(landing->effectPool);
    SpriteGfxManager_Free(&landing->gfx);
    landing->drawSprites = FALSE;
    landing->done = TRUE;
    landing->state++;
    return FALSE;
}

BOOL FlyLanding_Idle(FlyLanding *landing) {
    return FALSE;
}

void *FlyLanding_AllocZeroed(enum HeapID heapID, u32 size) {
    void *ptr = Heap_AllocAtEnd(heapID, size);
    GF_ASSERT(ptr);
    memset(ptr, 0, size);
    return ptr;
}

void FieldMoveCutIn_SetPlayerVisible(FieldMoveCutIn *cutIn, BOOL visible) {
    MapObject_UnpauseMovement(cutIn->playerObject);
    MapObject_SetInvisible(cutIn->playerObject, visible);
}

BOOL TrainerClipEffect_Init(FieldEffect *effect, TrainerClip *clip) {
    TrainerClip *args = FieldEffect_GetUserData(effect);
    *clip = *args;
    return TRUE;
}

void TrainerClipEffect_Update(FieldEffect *effect, TrainerClip *clip) {
    fx32 y = Sprite_GetMatrixPtr(clip->sprite)->y;
    FieldMoveCutIn *cutIn = clip->cutIn;
    fx32 top = cutIn->windowTop;
    fx32 bottom = cutIn->windowBottom;
    if (!cutIn->flyStarted) {
        if (y - FX32_CONST(8) >= top && y + FX32_CONST(8) <= bottom) {
            Sprite_SetDrawFlag(clip->sprite, TRUE);
        } else {
            Sprite_SetDrawFlag(clip->sprite, FALSE);
        }
    } else {
        Sprite_SetDrawFlag(clip->sprite, TRUE);
    }
}

void FieldMoveCutIn_CreateTrainerClipEffect(FieldMoveCutIn *cutIn) {
    VecFx32 pos = { 0, 0, 0 };
    TrainerClip userData;

    userData.sprite = cutIn->trainerSprite;
    userData.cutIn = cutIn;
    cutIn->trainerClipEffect = FieldEffectPool_AddBasicEffect(cutIn->effectPool, &gTrainerClipEffectTemplate, &pos, 0, &userData, 0x87);
}

void FieldMoveCutIn_DestroyTrainerClipEffect(FieldMoveCutIn *cutIn) {
    if (cutIn->trainerClipEffect) {
        FieldEffect_Destroy(cutIn->trainerClipEffect);
        cutIn->trainerClipEffect = NULL;
    }
}

static void FieldMoveCutIn_CreateModelEffect(FieldMoveCutIn *cutIn) {
    VecFx32 pos = { 0, 0, 0 };
    FieldMoveCutIn *userData = cutIn;
    FieldMoveCutIn_LoadModel(cutIn);
    MapObject_CopyPositionVector(cutIn->otherObject, &pos);
    cutIn->modelEffect = FieldEffectPool_AddBasicEffect(cutIn->effectPool, &gCutInModelEffectTemplate, &pos, 0, &userData, 0x83);
}

BOOL CutInModelEffect_Init(FieldEffect *effect, CutInModelEffect *work) {
    VecFx32 pos;
    FieldMoveCutIn **userData = FieldEffect_GetUserData(effect);
    FieldMoveCutInModel *model;
    work->cutIn = *userData;
    model = &(*userData)->model;
    FieldEffect_GetPosition(effect, &pos);
    Field3dObject_SetPos(&model->object, &pos);
    Field3dObject_SetActiveFlag(&model->object, FALSE);
    return TRUE;
}

void CutInModelEffect_Destroy(FieldEffect *effect, CutInModelEffect *work) {
}

void CutInModelEffect_Update(FieldEffect *effect, CutInModelEffect *work) {
    FieldMoveCutInModel *model = &work->cutIn->model;
    switch (work->step) {
    case CUT_IN_MODEL_STEP_START:
        work->step = CUT_IN_MODEL_STEP_SHOW;
        break;
    case CUT_IN_MODEL_STEP_SHOW:
        Field3dObject_SetActiveFlag(&model->object, TRUE);
        Field3dModelAnimation_FrameSet(&model->animations[0], 0);
        Field3dModelAnimation_FrameSet(&model->animations[1], 0);
        work->step = CUT_IN_MODEL_STEP_ANIMATE;
        // fallthrough
    case CUT_IN_MODEL_STEP_ANIMATE:
        Field3dModelAnimation_FrameAdvanceAndCheck(&model->animations[0], FX32_ONE);
        if (Field3dModelAnimation_FrameAdvanceAndCheck(&model->animations[1], FX32_ONE)) {
            work->done = TRUE;
            work->step = CUT_IN_MODEL_STEP_DONE;
        }
        break;
    case CUT_IN_MODEL_STEP_DONE:
        break;
    }
}

void CutInModelEffect_Draw(FieldEffect *effect, CutInModelEffect *work) {
    Field3dObject_Draw(&work->cutIn->model.object);
}

static void FieldMoveCutIn_LoadModel(FieldMoveCutIn *cutIn) {
    FieldMoveCutInModel *model = &cutIn->model;
    HeapExp_FndInitAllocator(&model->allocator, HEAP_ID_FIELD1, 0x20);
    model->modelData = AllocAtEndAndReadWholeNarcMemberByIdPair(NARC_a_1_0_3, 0x83, HEAP_ID_FIELD1);
    Field3dModel_LoadFromData(&model->model, model->modelData);
    Field3dObject_InitFromModel(&model->object, &model->model);
    Field3dModelAnimation_LoadFromFilesystem(&model->animations[0], &model->model, NARC_a_1_0_3, 0xa7, HEAP_ID_FIELD1, &model->allocator);
    Field3dModelAnimation_LoadFromFilesystem(&model->animations[1], &model->model, NARC_a_1_0_3, 0xa5, HEAP_ID_FIELD1, &model->allocator);
    Field3dObject_AddAnimation(&model->object, &model->animations[0]);
    Field3dObject_AddAnimation(&model->object, &model->animations[1]);
}

static void FieldMoveCutIn_UnloadModel(FieldMoveCutIn *cutIn) {
    FieldMoveCutInModel *model = &cutIn->model;
    Field3dModel_UnloadKeepData(&model->model);
    FieldEffectManager_HeapFree(model->modelData);
    Field3dModelAnimation_Unload(&model->animations[0], &model->allocator);
    Field3dModelAnimation_Unload(&model->animations[1], &model->allocator);
}

BOOL FieldMoveCutIn_StepShowOtherObject(FieldMoveCutIn *cutIn) {
    MapObject_SetInvisible(cutIn->otherObject, TRUE);
    MapObject_CallDrawUpdate(cutIn->otherObject);
    FieldMoveCutIn_CreateModelEffect(cutIn);
    cutIn->state++;
    return TRUE;
}

BOOL FieldMoveCutIn_StepWaitModelEffect(FieldMoveCutIn *cutIn) {
    CutInModelEffect *modelEffect = FieldEffect_GetState(cutIn->modelEffect);
    if (modelEffect->done == TRUE) {
        FieldEffect_Destroy(cutIn->modelEffect);
        FieldMoveCutIn_UnloadModel(cutIn);
        cutIn->state++;
        return FALSE;
    }
    return FALSE;
}

void Roamers_UpdateAfterBattle(FieldSystem *fieldSystem, BattleSetup *setup) {
    Pokemon *mon = Party_GetMonByIndex(setup->party[BATTLER_ENEMY], 0);
    RoamerSaveData *roamerSave = Save_Roamers_Get(fieldSystem->saveData);
    u32 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    Roamer *roamer = Roamers_GetActiveRoamerBySpecies(roamerSave, species);
    if (roamer != NULL) {
        u32 roamerIdx = SpeciesToRoamerIdx(species);
        u16 hp = (u16)GetMonData(mon, MON_DATA_HP, NULL);
        u8 status = (u8)GetMonData(mon, MON_DATA_STATUS, NULL);
        u32 winFlag = setup->winFlag;
        if (winFlag == BATTLE_OUTCOME_WIN && hp == 0) {
            RoamerMon_Init(&roamer);
            Save_VarsFlags_SetRoamerStatus(Save_VarsFlags_Get(fieldSystem->saveData), roamerIdx, 2);
        } else if (winFlag == BATTLE_OUTCOME_MON_CAUGHT) {
            RoamerMon_Init(&roamer);
            Save_VarsFlags_SetRoamerStatus(Save_VarsFlags_Get(fieldSystem->saveData), roamerIdx, 1);
        } else {
            SetRoamerData(roamer, ROAMER_DATA_HP, hp);
            SetRoamerData(roamer, ROAMER_DATA_STATUS, status);
        }
        Roamers_RelocateFromMap(roamerSave, fieldSystem->location->mapId);
    } else if ((u16)((s32)LCRandom() % 100) < 30) {
        Roamers_RelocateFromMap(roamerSave, fieldSystem->location->mapId);
    }
}

static void Roamers_RelocateFromMap(RoamerSaveData *roamerSave, u32 mapId) {
    u8 i;
    for (i = 0; i < ROAMER_MAX; i++) {
        if (GetRoamerIsActiveByIndex(roamerSave, i) && mapId == GetRoamMapByLocationIdx(Roamer_GetLocation(roamerSave, i))) {
            RoamerLocationUpdateRand(roamerSave, i);
        }
    }
}

static Roamer *Roamers_GetActiveRoamerBySpecies(RoamerSaveData *roamerSave, u32 species) {
    u8 i;
    for (i = 0; i < ROAMER_MAX; i++) {
        if (GetRoamerIsActiveByIndex(roamerSave, i)) {
            Roamer *roamer = Roamers_GetRoamMonStats(roamerSave, i);
            if (species == GetRoamerData(roamer, ROAMER_DATA_SPECIES)) {
                return roamer;
            }
        }
    }
    return NULL;
}

BOOL PlayerStepEvent_RepelCounterDecrement(SaveData *saveData, FieldSystem *fieldSystem) {
    u8 *repel = RoamerSave_GetRepelAddr(Save_Roamers_Get(saveData));
    if (*repel != 0) {
        (*repel)--;
        if (*repel == 0) {
            StartMapSceneScript(fieldSystem, std_repel_wore_off, NULL);
            return TRUE;
        }
    }
    return FALSE;
}

void PokecenterAnimCreate(FieldSystem *fieldSystem, u8 kind) {
    VecFx32 delta, trans;
    MapProp *prop;
    int idx;
    if (FieldSystem_FindMapProp(fieldSystem, 0x24, &prop, &idx)) {
        PokecenterAnim *anim = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(PokecenterAnim));
        anim->ballCount = kind;
        anim->ballIndex = 0;
        anim->timer = 0;
        anim->state = 0;
        Terrain_GetChunkOrigin(idx, MapMatrix_GetWidth(fieldSystem->mapMatrix), &delta);
        MapProp_GetTranslation(&trans, prop);
        anim->machinePos = trans;
        anim->machinePos.x += delta.x;
        anim->machinePos.z += delta.z;
        TaskManager_Call(fieldSystem->taskman, PokecenterAnimRun, anim);
    } else {
        GF_ASSERT(FALSE);
    }
}
