#include "field/field_move_cut_in.h"

#include "global.h"

#include "constants/sndseq.h"

#include "application/choose_starter/choose_starter_sub_res.naix"
#include "field/field_effect_helpers.h"
#include "field/fly_landing_effect.h"

#include "assert.h"
#include "bg_window.h"
#include "dialog_box.h"
#include "field_system.h"
#include "filesystem.h"
#include "follow_mon.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "map_object.h"
#include "math_util.h"
#include "overlay_02.h"
#include "player_avatar.h"
#include "pokemon.h"
#include "screen_fade.h"
#include "sound_chatot.h"
#include "sound_playback.h"
#include "sprite.h"
#include "sprite_resource.h"
#include "sprite_resource_header.h"
#include "sprite_transfer.h"
#include "sys_task_api.h"

// A step of the cut-in's step table: TRUE to run the next step in the same frame.
typedef BOOL (*FieldMoveCutInStep)(FieldMoveCutIn *cutIn);

static FieldMoveCutIn *FieldMoveCutIn_New(FieldSystem *fieldSystem);
static void FieldMoveCutIn_Free(FieldMoveCutIn *cutIn);
static void Task_FieldMoveCutIn(SysTask *task, void *data);
static void Task_FieldMoveCutInFly(SysTask *task, void *data);
static void Task_FieldMoveCutInFlyWithObject(SysTask *task, void *data);
static void FieldMoveCutIn_StartSpriteTransfer(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_StartFlySpriteTransfer(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_EndSpriteTransfer(FieldMoveCutIn *cutIn);
static void Task_FieldMoveCutIn_TransferSprites(SysTask *task, void *data);
static void Task_FieldMoveCutIn_ReleaseSpriteData(SysTask *task, void *data);
static void Task_FieldMoveCutIn_TransferFlySprites(SysTask *task, void *data);
static void Task_FieldMoveCutIn_ReleaseFlySpriteData(SysTask *task, void *data);
static void FieldMoveCutIn_InitBannerGraphics(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_InitSpriteGraphics(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_FreeBannerGraphics(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_FreeSpriteGraphics(FieldMoveCutIn *cutIn);
static NARC *FieldMoveCutIn_OpenNarc(void);
static void FieldMoveCutIn_LoadSpriteResources(FieldMoveCutIn *cutIn, NARC *narc);
static void FieldMoveCutIn_FreeSpriteResources(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_DrawSprites(FieldMoveCutIn *cutIn);
static Sprite *FieldMoveCutIn_CreateTrainerSprite(FieldMoveCutIn *cutIn, VecFx32 *pos);
static void CutInSprite_StartAnimation(Sprite *sprite);
static void FieldMoveCutIn_LoadFlyResources(FieldMoveCutIn *cutIn);
static void CutInBanner_LoadPalette(NARC *narc, u32 fileId, NNSG2dPaletteData **pltt);
static void CutInBanner_LoadChar(BgConfig *bgConfig, NARC *narc, u32 fileId, NNSG2dCharacterData **chars);
static void CutInBanner_LoadScreen(BgConfig *bgConfig, NARC *narc, u32 fileId, NNSG2dScreenData **screen);
static void CutInBanner_Clear(BgConfig *bgConfig);
static void FieldMoveCutIn_StartWindow(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_EnableWindow(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_DisableWindow(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_SetWindowPlanes(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_SetWindowOutsidePlanes(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_SetWindowRect(FieldMoveCutIn *cutIn, fx32 left, fx32 top, fx32 right, fx32 bottom);
static void FieldMoveCutIn_CreateWindowTask(FieldMoveCutIn *cutIn);
static void FieldMoveCutIn_DestroyWindowTask(FieldMoveCutIn *cutIn);

extern const FieldMoveCutInStep gFieldMoveCutInSteps[];
extern const FieldMoveCutInStep gFieldMoveCutInFlySteps[];
extern const FieldMoveCutInStep gFieldMoveCutInFlyWithObjectSteps[];

// The trainer graphics are the gender's.
SysTask *FieldMoveCutIn_Start(FieldSystem *fieldSystem, enum FieldMoveCutInKind kind, Pokemon *mon, u32 gender) {
    FieldMoveCutIn *cutIn = FieldMoveCutIn_New(fieldSystem);
    cutIn->mon = mon;
    cutIn->playerGender = gender;
    cutIn->trainerGraphics = cutIn->playerGender;
    cutIn->kind = kind;
    cutIn->playerObject = PlayerAvatar_GetMapObject(cutIn->fieldSystem->playerAvatar);
    if (kind == FIELD_MOVE_CUT_IN_BANNER) {
        return SysTask_CreateOnMainQueue(Task_FieldMoveCutIn, cutIn, 0x86);
    } else if (kind == FIELD_MOVE_CUT_IN_FLY_WITH_FOLLOWER) {
        cutIn->otherObject = FollowMon_GetMapObject(fieldSystem);
        return SysTask_CreateOnMainQueue(Task_FieldMoveCutInFlyWithObject, cutIn, 0x86);
    } else {
        return SysTask_CreateOnMainQueue(Task_FieldMoveCutInFly, cutIn, 0x86);
    }
}

// Fly take-off of a map object other than the player, with otherObject as the flying Pokemon's object (FIELD_MOVE_CUT_IN_FLY_WITH_OBJECT, no
// trainer graphics; Lance on his Dragonite). The sprites are shifted by object's offset from the player.
SysTask *FieldMoveCutIn_StartFlyWithObject(FieldSystem *fieldSystem, Pokemon *mon, LocalMapObject *object, LocalMapObject *otherObject) {
    VecFx32 playerPos;
    VecFx32 otherPos;
    FieldMoveCutIn *cutIn = FieldMoveCutIn_New(fieldSystem);
    cutIn->mon = mon;
    cutIn->playerGender = 0;
    cutIn->trainerGraphics = 2;
    cutIn->kind = FIELD_MOVE_CUT_IN_FLY_WITH_OBJECT;
    cutIn->playerObject = object;
    cutIn->otherObject = otherObject;
    MapObject_CopyPositionVector(PlayerAvatar_GetMapObject(cutIn->fieldSystem->playerAvatar), &playerPos);
    MapObject_CopyPositionVector(cutIn->playerObject, &otherPos);
    cutIn->otherObjectOffset.x = cutIn->otherObjectOffset.x + FX_Div(otherPos.x - playerPos.x, FX32_CONST(2));
    cutIn->otherObjectOffset.z = otherPos.z - playerPos.z;
    return SysTask_CreateOnMainQueue(Task_FieldMoveCutInFlyWithObject, cutIn, 0x86);
}

BOOL FieldMoveCutIn_IsFinished(SysTask *task) {
    FieldMoveCutIn *cutIn = SysTask_GetData(task);
    return cutIn->done;
}

void FieldMoveCutIn_Delete(SysTask *task) {
    FieldMoveCutIn *cutIn = SysTask_GetData(task);
    FieldMoveCutIn_Free(cutIn);
    SysTask_Destroy(task);
}

static FieldMoveCutIn *FieldMoveCutIn_New(FieldSystem *fieldSystem) {
    FieldMoveCutIn *cutIn = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(FieldMoveCutIn));
    memset(cutIn, 0, sizeof(FieldMoveCutIn));
    cutIn->fieldSystem = fieldSystem;
    return cutIn;
}

static void FieldMoveCutIn_Free(FieldMoveCutIn *cutIn) {
    Heap_Free(cutIn);
}

static void Task_FieldMoveCutIn(SysTask *task, void *data) {
    FieldMoveCutIn *cutIn = data;
    const FieldMoveCutInStep *steps = gFieldMoveCutInSteps;
    while (steps[cutIn->state](cutIn) == TRUE) {
    }
    if (cutIn->drawSprites == TRUE) {
        if (cutIn->effectPool != NULL) {
            FieldEffectPool_DrawAll(cutIn->effectPool);
        }
        FieldMoveCutIn_DrawSprites(cutIn);
    }
}

BOOL FieldMoveCutIn_StepLoadBannerGraphics(FieldMoveCutIn *cutIn) {
    FieldMoveCutIn_InitBannerGraphics(cutIn);
    FieldMoveCutIn_StartSpriteTransfer(cutIn);
    cutIn->state++;
    return FALSE;
}

BOOL FieldMoveCutIn_StepLoadSpriteGraphics(FieldMoveCutIn *cutIn) {
    FieldMoveCutIn_InitSpriteGraphics(cutIn);
    FieldMoveCutIn_StartSpriteTransfer(cutIn);
    cutIn->state++;
    return FALSE;
}

BOOL FieldMoveCutIn_StepCreateSprites(FieldMoveCutIn *cutIn) {
    VecFx32 trainerPos;
    VecFx32 monPos;

    if (!cutIn->transferDone) {
        return FALSE;
    }
    trainerPos = gCutInTrainerPos;
    monPos = gCutInMonPos;
    cutIn->trainerSprite = FieldMoveCutIn_CreateTrainerSprite(cutIn, &trainerPos);
    cutIn->monSprite = FieldMoveCutIn_CreateMonSprite(cutIn, &monPos);
    FieldMoveCutIn_CreateScrollSprites(cutIn, 1);
    FieldMoveCutIn_EndSpriteTransfer(cutIn);
    cutIn->drawSprites = TRUE;
    cutIn->state++;
    return TRUE;
}

// The window starts as a 2 pixel high line at the right edge of the screen.
BOOL FieldMoveCutIn_StepInitWindow(FieldMoveCutIn *cutIn) {
    FieldMoveCutIn_CreateTrainerClipEffect(cutIn);
    cutIn->windowUpdate = FALSE;
    cutIn->windowSpeed = FX32_CONST(-64);
    cutIn->windowLeft = FX32_CONST(254);
    cutIn->windowRight = FX32_CONST(255);
    cutIn->windowTop = FX32_CONST(95);
    cutIn->windowBottom = FX32_CONST(97);
    cutIn->windowUpdate = TRUE;
    cutIn->state++;
    return FALSE;
}

BOOL FieldMoveCutIn_StepWidenWindow(FieldMoveCutIn *cutIn) {
    cutIn->windowUpdate = FALSE;
    cutIn->windowLeft += cutIn->windowSpeed;
    if (cutIn->windowLeft <= 0) {
        cutIn->windowLeft = 0;
        cutIn->windowSpeed = FX32_CONST(2);
        cutIn->state++;
    }
    FieldMoveCutIn_SetWindowRect(cutIn, cutIn->windowLeft, cutIn->windowTop, cutIn->windowRight, cutIn->windowBottom);
    cutIn->windowUpdate = TRUE;
    return FALSE;
}

BOOL FieldMoveCutIn_StepOpenWindow(FieldMoveCutIn *cutIn) {
    cutIn->windowUpdate = FALSE;
    cutIn->windowTop -= cutIn->windowSpeed;
    cutIn->windowBottom += cutIn->windowSpeed;
    cutIn->windowSpeed += FX32_CONST(2);
    if (cutIn->windowSpeed > FX32_CONST(32)) {
        cutIn->windowSpeed = FX32_CONST(32);
    }
    if (cutIn->windowTop < FX32_CONST(56)) {
        cutIn->windowTop = FX32_CONST(56);
    }
    if (cutIn->windowBottom > FX32_CONST(136)) {
        cutIn->windowBottom = FX32_CONST(136);
    }
    FieldMoveCutIn_SetWindowRect(cutIn, cutIn->windowLeft, cutIn->windowTop, cutIn->windowRight, cutIn->windowBottom);
    cutIn->windowUpdate = TRUE;
    if (cutIn->windowTop == FX32_CONST(56) && cutIn->windowBottom == FX32_CONST(136)) {
        CutInSprite_StartAnimation(cutIn->trainerSprite);
        cutIn->state++;
    }
    return FALSE;
}

BOOL FieldMoveCutIn_StepWaitBeforeMon(FieldMoveCutIn *cutIn) {
    if (++cutIn->timer >= 15) {
        cutIn->timer = 0;
        cutIn->monSpeed = FX32_CONST(-64);
        cutIn->state++;
    }
    return FALSE;
}

BOOL FieldMoveCutIn_StepMonSlideIn(FieldMoveCutIn *cutIn) {
    VecFx32 pos;

    pos = *Sprite_GetMatrixPtr(cutIn->monSprite);
    pos.x += cutIn->monSpeed;
    if (pos.x <= FX32_CONST(160)) {
        pos.x = FX32_CONST(192);
        cutIn->state++;
    }
    Sprite_SetMatrix(cutIn->monSprite, &pos);
    return FALSE;
}

BOOL FieldMoveCutIn_StepMonSlowDown(FieldMoveCutIn *cutIn) {
    VecFx32 pos;

    cutIn->monSpeed /= 2;
    if (cutIn->monSpeed > FX32_CONST(-2)) {
        cutIn->monSpeed = FX32_CONST(-2);
        cutIn->state++;
        PlayCry(GetMonData(cutIn->mon, MON_DATA_SPECIES, NULL), GetMonData(cutIn->mon, MON_DATA_FORM, NULL));
    }
    pos = *Sprite_GetMatrixPtr(cutIn->monSprite);
    pos.x += cutIn->monSpeed;
    Sprite_SetMatrix(cutIn->monSprite, &pos);
    return FALSE;
}

BOOL FieldMoveCutIn_StepWaitBeforeMonExit(FieldMoveCutIn *cutIn) {
    if (++cutIn->timer >= 8) {
        cutIn->timer = 0;
        cutIn->monSpeed = FX32_CONST(-1);
        cutIn->state++;
    }
    return FALSE;
}

BOOL FieldMoveCutIn_StepMonSlideOut(FieldMoveCutIn *cutIn) {
    VecFx32 pos;

    cutIn->monSpeed *= 2;
    if (cutIn->monSpeed < FX32_CONST(-64)) {
        cutIn->monSpeed = FX32_CONST(-64);
    }
    pos = *Sprite_GetMatrixPtr(cutIn->monSprite);
    pos.x += cutIn->monSpeed;
    Sprite_SetMatrix(cutIn->monSprite, &pos);
    if (pos.x <= FX32_CONST(-40)) {
        cutIn->windowSpeed = FX32_ONE;
        cutIn->state++;
    }
    return FALSE;
}

BOOL FieldMoveCutIn_StepCloseWindow(FieldMoveCutIn *cutIn) {
    cutIn->windowUpdate = FALSE;
    cutIn->windowTop += cutIn->windowSpeed;
    cutIn->windowBottom -= cutIn->windowSpeed;
    cutIn->windowSpeed += FX32_CONST(4);
    if (cutIn->windowSpeed > FX32_CONST(16)) {
        cutIn->windowSpeed = FX32_CONST(16);
    }
    if (cutIn->windowTop >= FX32_CONST(95)) {
        cutIn->windowTop = FX32_CONST(95);
    }
    if (cutIn->windowBottom <= FX32_CONST(97)) {
        cutIn->windowBottom = FX32_CONST(97);
    }
    FieldMoveCutIn_SetWindowRect(cutIn, cutIn->windowLeft, cutIn->windowTop, cutIn->windowRight, cutIn->windowBottom);
    cutIn->windowUpdate = TRUE;
    if (cutIn->windowTop == FX32_CONST(95) && cutIn->windowBottom == FX32_CONST(97)) {
        FieldMoveCutIn_DestroyTrainerClipEffect(cutIn);
        cutIn->windowInsidePlanes = GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_OBJ;
        cutIn->state++;
    }
    return FALSE;
}

BOOL FieldMoveCutIn_StepFreeBannerGraphics(FieldMoveCutIn *cutIn) {
    FieldMoveCutIn_FreeBannerGraphics(cutIn);
    cutIn->drawSprites = FALSE;
    cutIn->state++;
    return FALSE;
}

BOOL FieldMoveCutIn_StepFreeSpriteGraphics(FieldMoveCutIn *cutIn) {
    FieldMoveCutIn_FreeSpriteGraphics(cutIn);
    cutIn->drawSprites = FALSE;
    cutIn->state++;
    return FALSE;
}

BOOL FieldMoveCutIn_StepEndWindow(FieldMoveCutIn *cutIn) {
    FieldMoveCutIn_DestroyWindowTask(cutIn);
    cutIn->state++;
    return FALSE;
}

BOOL FieldMoveCutIn_StepFinish(FieldMoveCutIn *cutIn) {
    cutIn->done = TRUE;
    return FALSE;
}

static void Task_FieldMoveCutInFly(SysTask *task, void *data) {
    FieldMoveCutIn *cutIn = data;
    const FieldMoveCutInStep *steps = gFieldMoveCutInFlySteps;
    while (steps[cutIn->state](cutIn) == TRUE) {
    }
    if (cutIn->drawSprites == TRUE) {
        if (cutIn->effectPool != NULL) {
            FieldEffectPool_DrawAll(cutIn->effectPool);
        }
        FieldMoveCutIn_DrawSprites(cutIn);
    }
}

static void Task_FieldMoveCutInFlyWithObject(SysTask *task, void *data) {
    FieldMoveCutIn *cutIn = data;
    const FieldMoveCutInStep *steps = gFieldMoveCutInFlyWithObjectSteps;
    while (steps[cutIn->state](cutIn) == TRUE) {
    }
    if (cutIn->drawSprites == TRUE) {
        if (cutIn->effectPool != NULL) {
            FieldEffectPool_DrawAll(cutIn->effectPool);
        }
        FieldMoveCutIn_DrawSprites(cutIn);
    }
}

BOOL FieldMoveCutIn_StepCreateFlySprites(FieldMoveCutIn *cutIn) {
    VecFx32 trainerPos;
    VecFx32 monPos;

    if (!cutIn->transferDone) {
        return FALSE;
    }
    trainerPos = gCutInFlyTrainerPos;
    monPos = gCutInFlyMonPos;
    cutIn->trainerSprite = FieldMoveCutIn_CreateTrainerSprite(cutIn, &trainerPos);
    cutIn->monSprite = FieldMoveCutIn_CreateMonSprite(cutIn, &monPos);
    FieldMoveCutIn_CreateScrollSprites(cutIn, 1);
    FieldMoveCutIn_EndSpriteTransfer(cutIn);
    cutIn->drawSprites = TRUE;
    cutIn->state++;
    return TRUE;
}

BOOL FieldMoveCutIn_StepCreateFlyTrainerSprite(FieldMoveCutIn *cutIn) {
    VecFx32 pos;

    if (!cutIn->transferDone) {
        return FALSE;
    }
    pos = gCutInFlyWithObjectTrainerPos;
    pos.x = pos.x + cutIn->otherObjectOffset.x;
    pos.y = pos.y + cutIn->otherObjectOffset.z;
    cutIn->trainerSprite = FieldMoveCutIn_CreateTrainerSprite(cutIn, &pos);
    Sprite_SetAnimCtrlSeq(cutIn->trainerSprite, 1);
    FieldMoveCutIn_EndSpriteTransfer(cutIn);
    cutIn->drawSprites = TRUE;
    cutIn->state++;
    return TRUE;
}

BOOL FieldMoveCutIn_StepFreeMonGraphics(FieldMoveCutIn *cutIn) {
    FieldMoveCutIn_FreeMonResources(cutIn);
    cutIn->state++;
    return FALSE;
}

BOOL FieldMoveCutIn_StepLoadFlyGraphics(FieldMoveCutIn *cutIn) {
    FieldMoveCutIn_LoadFlyResources(cutIn);
    FieldMoveCutIn_StartFlySpriteTransfer(cutIn);
    cutIn->state++;
    return FALSE;
}

BOOL FieldMoveCutIn_StepWaitFlyGraphics(FieldMoveCutIn *cutIn) {
    if (!cutIn->transferDone) {
        return FALSE;
    }
    FieldMoveCutIn_EndSpriteTransfer(cutIn);
    cutIn->state++;
    return TRUE;
}

BOOL FieldMoveCutIn_StepStartFly(FieldMoveCutIn *cutIn) {
    FieldMoveCutIn_CreateFlyer(cutIn);
    FieldMoveCutIn_StartFlyerTakeOff(cutIn);
    FieldMoveCutIn_SetWindowOutsidePlanes(cutIn);
    FieldMoveCutIn_SetPlayerInvisible(cutIn, TRUE);
    cutIn->state++;
    return FALSE;
}

BOOL FieldMoveCutIn_StepWaitTakeOff(FieldMoveCutIn *cutIn) {
    if (FieldMoveCutIn_GetFlyerStatus(cutIn) != 2) {
        return FALSE;
    }
    Sprite_SetAnimCtrlSeq(cutIn->trainerSprite, 1);
    cutIn->state++;
    return FALSE;
}

BOOL FieldMoveCutIn_StepWaitBeforeFlyAway(FieldMoveCutIn *cutIn) {
    cutIn->timer++;
    if (cutIn->timer >= 20) {
        cutIn->timer = 0;
        cutIn->state++;
        FieldMoveCutIn_StartFlyerPickUp(cutIn);
    }
    return TRUE;
}

BOOL FieldMoveCutIn_StepWaitBeforePickUp(FieldMoveCutIn *cutIn) {
    cutIn->timer++;
    if (cutIn->timer >= 20) {
        cutIn->timer = 0;
        cutIn->state++;
        FieldMoveCutIn_CreateFlyer(cutIn);
        FieldMoveCutIn_StartFlyerPickUp(cutIn);
    }
    return TRUE;
}

BOOL FieldMoveCutIn_StepWaitFlyAway(FieldMoveCutIn *cutIn) {
    if (FieldMoveCutIn_GetFlyerStatus(cutIn) != 3) {
        return FALSE;
    }
    PlaySE(SEQ_SE_DP_FW019);
    cutIn->windowSpeed = FX32_CONST(0.5);
    cutIn->scrollSpriteMode = 2;
    cutIn->state++;
    return TRUE;
}

BOOL FieldMoveCutIn_StepCloseFlyWindow(FieldMoveCutIn *cutIn) {
    cutIn->windowUpdate = FALSE;
    cutIn->windowTop += cutIn->windowSpeed;
    cutIn->windowBottom -= cutIn->windowSpeed;
    cutIn->windowSpeed += FX32_CONST(0.5);
    if (cutIn->windowSpeed > FX32_CONST(16)) {
        cutIn->windowSpeed = FX32_CONST(16);
    }
    if (cutIn->windowTop >= FX32_CONST(95)) {
        cutIn->windowTop = FX32_CONST(95);
    }
    if (cutIn->windowBottom <= FX32_CONST(97)) {
        cutIn->windowBottom = FX32_CONST(97);
    }
    FieldMoveCutIn_SetWindowRect(cutIn, cutIn->windowLeft, cutIn->windowTop, cutIn->windowRight, cutIn->windowBottom);
    cutIn->windowUpdate = TRUE;
    if (!cutIn->fadeStarted && FieldMoveCutIn_GetFlyerStatus(cutIn) == 4) {
        cutIn->fadeStarted = TRUE;
        FieldMove_FadeOutToWhite();
    }
    if (cutIn->windowTop == FX32_CONST(95) && cutIn->windowBottom == FX32_CONST(97)) {
        cutIn->windowInsidePlanes = GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_OBJ;
        cutIn->scrollSpriteMode = 1;
        cutIn->state++;
    }
    return FALSE;
}

BOOL FieldMoveCutIn_StepWaitFlyEnd(FieldMoveCutIn *cutIn) {
    if (cutIn->kind == FIELD_MOVE_CUT_IN_FLY_WITH_OBJECT) {
        if (FieldMoveCutIn_GetFlyerStatus(cutIn) == 2) {
            FieldMoveCutIn_DestroyFlyer(cutIn);
            cutIn->state += 2;
        }
        return FALSE;
    }
    if (!cutIn->fadeStarted && FieldMoveCutIn_GetFlyerStatus(cutIn) == 4) {
        cutIn->fadeStarted = TRUE;
        FieldMove_FadeOutToWhite();
    }
    if (FieldMoveCutIn_GetFlyerStatus(cutIn) != 2) {
        return FALSE;
    }
    if (!cutIn->fadeStarted) {
        cutIn->fadeStarted = TRUE;
        FieldMove_FadeOutToWhite();
    }
    FieldMoveCutIn_DestroyFlyer(cutIn);
    cutIn->state++;
    return FALSE;
}

BOOL FieldMoveCutIn_StepWaitPaletteFade(FieldMoveCutIn *cutIn) {
    if (IsPaletteFadeFinished()) {
        cutIn->state++;
    }
    return FALSE;
}

// The sprite resources go to VRAM in the next VBlank; transferDone is set once their data is released.
static void FieldMoveCutIn_StartSpriteTransfer(FieldMoveCutIn *cutIn) {
    cutIn->transferStep = 0;
    cutIn->transferDone = FALSE;
    cutIn->transferTask = SysTask_CreateOnVBlankQueue(Task_FieldMoveCutIn_TransferSprites, cutIn, 0x80);
}

static void FieldMoveCutIn_StartFlySpriteTransfer(FieldMoveCutIn *cutIn) {
    cutIn->transferStep = 0;
    cutIn->transferDone = FALSE;
    cutIn->transferTask = SysTask_CreateOnVBlankQueue(Task_FieldMoveCutIn_TransferFlySprites, cutIn, 0x80);
}

static void FieldMoveCutIn_EndSpriteTransfer(FieldMoveCutIn *cutIn) {
    if (cutIn->transferTask != NULL) {
        SysTask_Destroy(cutIn->transferTask);
        cutIn->transferTask = NULL;
    }
}

static void Task_FieldMoveCutIn_TransferSprites(SysTask *task, void *data) {
    FieldMoveCutIn *cutIn = data;
    int i;

    if (cutIn->transferStep == 0) {
        for (i = 0; i < 4; i++) {
            if (cutIn->charResources[i] != NULL) {
                SpriteTransfer_CreateCharTransferTask_AllocAtEnd(cutIn->charResources[i]);
            }
        }
        for (i = 0; i < 3; i++) {
            if (cutIn->plttResources[i] != NULL) {
                SpriteTransfer_CreatePlttTransferTask(cutIn->plttResources[i]);
            }
        }
        if (cutIn->monCharData != NULL) {
            FieldMoveCutIn_TransferMonChar(cutIn, cutIn->monCharData);
        }
        if (cutIn->monPlttData != NULL) {
            FieldMoveCutIn_TransferMonPltt(cutIn, cutIn->monPlttData);
        }
        cutIn->transferStep++;
        SysTask_CreateOnVWaitQueue(Task_FieldMoveCutIn_ReleaseSpriteData, cutIn, 0x80);
    }
}

static void Task_FieldMoveCutIn_ReleaseSpriteData(SysTask *task, void *data) {
    FieldMoveCutIn *cutIn = data;
    int i;

    if (cutIn->transferStep == 1) {
        for (i = 0; i < 4; i++) {
            if (cutIn->charResources[i] != NULL) {
                GF2DGfxResObj_FreeData(cutIn->charResources[i]);
            }
        }
        for (i = 0; i < 3; i++) {
            if (cutIn->plttResources[i] != NULL) {
                GF2DGfxResObj_FreeData(cutIn->plttResources[i]);
            }
        }
        if (cutIn->monCharData != NULL) {
            Heap_Free(cutIn->monCharData);
            cutIn->monCharData = NULL;
        }
        if (cutIn->monPlttData != NULL) {
            Heap_Free(cutIn->monPlttData);
            cutIn->monPlttData = NULL;
        }
        cutIn->transferDone = TRUE;
        SysTask_Destroy(task);
    }
}

static void Task_FieldMoveCutIn_TransferFlySprites(SysTask *task, void *data) {
    FieldMoveCutIn *cutIn = data;
    SpriteResource *res = SpriteResourceCollection_Find(cutIn->resMan[GF_GFX_RES_TYPE_CHAR], 0);
    if (cutIn->transferStep == 0) {
        SpriteTransfer_CreateCharTransferTask_AllocAtEnd(res);
        SysTask_CreateOnVWaitQueue(Task_FieldMoveCutIn_ReleaseFlySpriteData, cutIn, 0x80);
        cutIn->transferStep = cutIn->transferStep + 1;
    }
}

static void Task_FieldMoveCutIn_ReleaseFlySpriteData(SysTask *task, void *data) {
    FieldMoveCutIn *cutIn = data;
    SpriteResource *res = SpriteResourceCollection_Find(cutIn->resMan[GF_GFX_RES_TYPE_CHAR], 0);
    if (cutIn->transferStep == 1) {
        GF2DGfxResObj_FreeData(res);
        cutIn->transferDone = TRUE;
        SysTask_Destroy(task);
    }
}

// The banner on BG3 inside the window, above BG1; BG0 and BG3's priorities are restored by FreeBannerGraphics.
static void FieldMoveCutIn_InitBannerGraphics(FieldMoveCutIn *cutIn) {
    NARC *narc = FieldMoveCutIn_OpenNarc();
    FieldMoveCutIn_SetWindowRect(cutIn, 0, FX32_CONST(192), FX32_ONE, FX32_CONST(192));
    FieldMoveCutIn_StartWindow(cutIn);
    cutIn->bg0Priority = GetBgPriority(cutIn->fieldSystem->bgConfig, GF_BG_LYR_MAIN_0);
    cutIn->bg3Priority = GetBgPriority(cutIn->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3);
    G2_SetBG1Priority(1);
    G2_SetBG3Priority(0);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
#ifdef HEARTGOLD
    CutInBanner_LoadPalette(narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000002_NCLR, &cutIn->bannerPltt);
    CutInBanner_LoadChar(cutIn->fieldSystem->bgConfig, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000000_NCGR, &cutIn->bannerChar);
    CutInBanner_LoadScreen(cutIn->fieldSystem->bgConfig, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000001_NSCR, &cutIn->bannerScreen);
#else
    CutInBanner_LoadPalette(narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000005_NCLR, &cutIn->bannerPltt);
    CutInBanner_LoadChar(cutIn->fieldSystem->bgConfig, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000003_NCGR, &cutIn->bannerChar);
    CutInBanner_LoadScreen(cutIn->fieldSystem->bgConfig, narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000004_NSCR, &cutIn->bannerScreen);
#endif
    FieldMoveCutIn_LoadSpriteResources(cutIn, narc);
    NARC_Delete(narc);
    cutIn->effectPool = FieldEffectPool_New(HEAP_ID_FIELD1, 32);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_ON);
}

static void FieldMoveCutIn_InitSpriteGraphics(FieldMoveCutIn *cutIn) {
    NARC *narc = FieldMoveCutIn_OpenNarc();
    cutIn->bg0Priority = GetBgPriority(cutIn->fieldSystem->bgConfig, GF_BG_LYR_MAIN_0);
    cutIn->bg3Priority = GetBgPriority(cutIn->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3);
    G2_SetBG1Priority(1);
    G2_SetBG3Priority(0);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
    FieldMoveCutIn_LoadSpriteResources(cutIn, narc);
    NARC_Delete(narc);
    cutIn->effectPool = FieldEffectPool_New(HEAP_ID_FIELD1, 32);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_ON);
}

static void FieldMoveCutIn_FreeBannerGraphics(FieldMoveCutIn *cutIn) {
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
    FieldEffectPool_Delete(cutIn->effectPool);
    CutInBanner_Clear(cutIn->fieldSystem->bgConfig);
    FieldMoveCutIn_FreeSpriteResources(cutIn);
    G2_SetBG0Priority(cutIn->bg0Priority);
    G2_SetBG3Priority(cutIn->bg3Priority);
    FieldMessage_LoadTextPalettes(GF_PAL_LOCATION_MAIN_BG, TRUE);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_ON);
}

static void FieldMoveCutIn_FreeSpriteGraphics(FieldMoveCutIn *cutIn) {
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
    FieldEffectPool_Delete(cutIn->effectPool);
    FieldMoveCutIn_FreeSpriteResources(cutIn);
    G2_SetBG0Priority(cutIn->bg0Priority);
    G2_SetBG3Priority(cutIn->bg3Priority);
    FieldMessage_LoadTextPalettes(GF_PAL_LOCATION_MAIN_BG, TRUE);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_ON);
}

static NARC *FieldMoveCutIn_OpenNarc(void) {
    return NARC_New(NARC_application_choose_starter_choose_starter_sub_res, HEAP_ID_FIELD1);
}

// Sprite resource ids: char 1 effects, 2 trainer, 3 Pokemon; pltt 0 effects, then trainer (unless male), then
// Pokemon; cell 1 effects, 2 trainer, 3 clouds; anim 0 effects, 1 trainer.
static void FieldMoveCutIn_LoadSpriteResources(FieldMoveCutIn *cutIn, NARC *narc) {
    int i;

    FieldMoveCutIn_GetMonPicIds(cutIn, &cutIn->pokepicTemplate);
    cutIn->spriteList = G2dRenderer_Init(32, &cutIn->renderer, HEAP_ID_FIELD1);
    G2dRenderer_SetSubSurfaceCoords(&cutIn->renderer, 0, FX32_CONST(512));

    cutIn->resMan[GF_GFX_RES_TYPE_CHAR] = Create2DGfxResObjMan(4, GF_GFX_RES_TYPE_CHAR, HEAP_ID_FIELD1);
    cutIn->resMan[GF_GFX_RES_TYPE_PLTT] = Create2DGfxResObjMan(3, GF_GFX_RES_TYPE_PLTT, HEAP_ID_FIELD1);
    cutIn->resMan[GF_GFX_RES_TYPE_CELL] = Create2DGfxResObjMan(4, GF_GFX_RES_TYPE_CELL, HEAP_ID_FIELD1);
    cutIn->resMan[GF_GFX_RES_TYPE_ANIM] = Create2DGfxResObjMan(2, GF_GFX_RES_TYPE_ANIM, HEAP_ID_FIELD1);

    cutIn->charResources[0] = AddCharResObjFromOpenNarc(cutIn->resMan[GF_GFX_RES_TYPE_CHAR], narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000014_NCGR, FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, HEAP_ID_FIELD1);
    cutIn->charResources[1] = AddCharResObjFromOpenNarc(cutIn->resMan[GF_GFX_RES_TYPE_CHAR], narc, gCutInTrainerCharFiles[cutIn->trainerGraphics], FALSE, 2, NNS_G2D_VRAM_TYPE_2DMAIN, HEAP_ID_FIELD1);
    cutIn->charResources[2] = FieldMoveCutIn_AddMonCharResource(cutIn, narc);

    i = 0;
    cutIn->plttResources[i] = AddPlttResObjFromOpenNarc(cutIn->resMan[GF_GFX_RES_TYPE_PLTT], narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000006_NCLR, FALSE, 0, NNS_G2D_VRAM_TYPE_2DMAIN, 1, HEAP_ID_FIELD1);
    i++;
    if (cutIn->trainerGraphics != 0) {
        cutIn->plttResources[i] = AddPlttResObjFromOpenNarc(cutIn->resMan[GF_GFX_RES_TYPE_PLTT], narc, gCutInTrainerPlttFiles[cutIn->trainerGraphics - 1], FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 1, HEAP_ID_FIELD1);
        i++;
    }
    cutIn->plttResources[i] = FieldMoveCutIn_AddMonPlttResource(cutIn, narc);

    cutIn->cellResources[0] = AddCellOrAnimResObjFromOpenNarc(cutIn->resMan[GF_GFX_RES_TYPE_CELL], narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000015_NCER, FALSE, 1, GF_GFX_RES_TYPE_CELL, HEAP_ID_FIELD1);
    cutIn->cellResources[1] = AddCellOrAnimResObjFromOpenNarc(cutIn->resMan[GF_GFX_RES_TYPE_CELL], narc, gCutInTrainerCellFiles[cutIn->trainerGraphics], FALSE, 2, GF_GFX_RES_TYPE_CELL, HEAP_ID_FIELD1);
    cutIn->cellResources[2] = AddCellOrAnimResObjFromOpenNarc(cutIn->resMan[GF_GFX_RES_TYPE_CELL], narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000010_NCER, FALSE, 3, GF_GFX_RES_TYPE_CELL, HEAP_ID_FIELD1);
    cutIn->animResources[0] = AddCellOrAnimResObjFromOpenNarc(cutIn->resMan[GF_GFX_RES_TYPE_ANIM], narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000016_NANR, FALSE, 0, GF_GFX_RES_TYPE_ANIM, HEAP_ID_FIELD1);
    cutIn->animResources[1] = AddCellOrAnimResObjFromOpenNarc(cutIn->resMan[GF_GFX_RES_TYPE_ANIM], narc, gCutInTrainerAnimFiles[cutIn->trainerGraphics], FALSE, 1, GF_GFX_RES_TYPE_ANIM, HEAP_ID_FIELD1);

    cutIn->monCharData = FieldMoveCutIn_LoadMonChar(cutIn->mon, &cutIn->pokepicTemplate, HEAP_ID_FIELD1);
    cutIn->monPlttData = FieldMoveCutIn_LoadMonPltt(&cutIn->pokepicTemplate, HEAP_ID_FIELD1);
}

static void FieldMoveCutIn_FreeSpriteResources(FieldMoveCutIn *cutIn) {
    int i;

    for (i = 0; i < 4; i++) {
        if (cutIn->charResources[i] != NULL) {
            SpriteTransfer_DeleteCharTransferTask(cutIn->charResources[i]);
        }
    }
    for (i = 0; i < 3; i++) {
        if (cutIn->plttResources[i] != NULL) {
            SpriteTransfer_DeletePlttTransferTask(cutIn->plttResources[i]);
        }
    }
    for (i = 0; i < 4; i++) {
        if (cutIn->cellResources[i] != NULL) {
            GF2DGfxResObj_FreeData(cutIn->cellResources[i]);
        }
    }
    for (i = 0; i < 2; i++) {
        if (cutIn->animResources[i] != NULL) {
            GF2DGfxResObj_FreeData(cutIn->animResources[i]);
        }
    }
    Destroy2DGfxResObjMan(cutIn->resMan[GF_GFX_RES_TYPE_CHAR]);
    Destroy2DGfxResObjMan(cutIn->resMan[GF_GFX_RES_TYPE_PLTT]);
    Destroy2DGfxResObjMan(cutIn->resMan[GF_GFX_RES_TYPE_CELL]);
    Destroy2DGfxResObjMan(cutIn->resMan[GF_GFX_RES_TYPE_ANIM]);
    SpriteList_DeleteAllSprites(cutIn->spriteList);
    SpriteList_Delete(cutIn->spriteList);
}

static void FieldMoveCutIn_DrawSprites(FieldMoveCutIn *cutIn) {
    if (cutIn->spriteList != NULL) {
        SpriteList_RenderAndAnimateSprites(cutIn->spriteList);
    }
}

Sprite *FieldMoveCutIn_CreateSprite(FieldMoveCutIn *cutIn, VecFx32 *pos, int charId, int plttId, int cellId, int animId, int priority, int drawPriority) {
    SpriteResourcesHeader header;
    SimpleSpriteTemplate template;
    Sprite *sprite;

    if (animId == 4) {
        CreateSpriteResourcesHeader(&header, charId, plttId, cellId, -1, -1, -1, 0, priority, cutIn->resMan[GF_GFX_RES_TYPE_CHAR], cutIn->resMan[GF_GFX_RES_TYPE_PLTT], cutIn->resMan[GF_GFX_RES_TYPE_CELL], NULL, NULL, NULL);
    } else {
        CreateSpriteResourcesHeader(&header, charId, plttId, cellId, animId, -1, -1, 0, priority, cutIn->resMan[GF_GFX_RES_TYPE_CHAR], cutIn->resMan[GF_GFX_RES_TYPE_PLTT], cutIn->resMan[GF_GFX_RES_TYPE_CELL], cutIn->resMan[GF_GFX_RES_TYPE_ANIM], NULL, NULL);
    }
    template.spriteList = cutIn->spriteList;
    template.header = &header;
    template.position = *pos;
    template.priority = drawPriority;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.heapID = HEAP_ID_FIELD1;
    sprite = Sprite_Create(&template);
    GF_ASSERT(sprite != NULL);
    return sprite;
}

Sprite *FieldMoveCutIn_CreateEffectSprite(FieldMoveCutIn *cutIn, VecFx32 *pos, int drawPriority, int animSeq) {
    Sprite *sprite = FieldMoveCutIn_CreateSprite(cutIn, pos, 1, 0, 1, 0, 0, drawPriority);
    Sprite_SetAnimCtrlSeq(sprite, animSeq);
    return sprite;
}

static Sprite *FieldMoveCutIn_CreateTrainerSprite(FieldMoveCutIn *cutIn, VecFx32 *pos) {
    int plttId = 0;
    Sprite *sprite;
    if (cutIn->trainerGraphics != 0) {
        plttId = 1;
    }
    sprite = FieldMoveCutIn_CreateSprite(cutIn, pos, 2, plttId, 2, 1, 0, 0x83);
    Sprite_SetDrawFlag(sprite, FALSE);
    Sprite_SetAnimCtrlSeq(sprite, 6);
    return sprite;
}

static void CutInSprite_StartAnimation(Sprite *sprite) {
    Sprite_SetAnimActiveFlag(sprite, TRUE);
    Sprite_SetAnimSpeed(sprite, FX32_ONE);
}

Sprite *FieldMoveCutIn_CreateFlyerSprite(FieldMoveCutIn *cutIn, VecFx32 *pos, int drawPriority, int unused) {
    VecFx32 affineMatrix = { 0, 0, 0 };
    VecFx32 affineScale;
    Sprite *sprite;

    affineScale = gCutInFlyerScale;
    sprite = FieldMoveCutIn_CreateSprite(cutIn, pos, 0, 0, 0, -1, 0, drawPriority);
    Sprite_SetAffineOverwriteMode(sprite, NNS_G2D_RND_AFFINE_OVERWRITE_DOUBLE);
    Sprite_SetAffineMatrix(sprite, &affineMatrix);
    Sprite_SetAffineScale(sprite, &affineScale);
    Sprite_SetAffineZRotation(sprite, GF_DegreeToSinCosIdx(0));
    return sprite;
}

// The flyer's char (id 0) and cell (id 0) take the first free slots, freed by FreeMonGraphics.
static void FieldMoveCutIn_LoadFlyResources(FieldMoveCutIn *cutIn) {
    NARC *narc = FieldMoveCutIn_OpenNarc();
    int i;
    for (i = 0; i < 4; i++) {
        if (cutIn->charResources[i] == NULL) {
            cutIn->charResources[i] = AddCharResObjFromOpenNarc(cutIn->resMan[GF_GFX_RES_TYPE_CHAR], narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000011_NCGR, FALSE, 0, NNS_G2D_VRAM_TYPE_2DMAIN, HEAP_ID_FIELD1);
            break;
        }
    }
    GF_ASSERT(i < 4);
    for (i = 0; i < 4; i++) {
        if (cutIn->cellResources[i] == NULL) {
            cutIn->cellResources[i] = AddCellOrAnimResObjFromOpenNarc(cutIn->resMan[GF_GFX_RES_TYPE_CELL], narc, NARC_choose_starter_sub_res_choose_starter_sub_res_00000012_NCER, FALSE, 0, GF_GFX_RES_TYPE_CELL, HEAP_ID_FIELD1);
            break;
        }
    }
    GF_ASSERT(i < 4);
    NARC_Delete(narc);
}

static void CutInBanner_LoadPalette(NARC *narc, u32 fileId, NNSG2dPaletteData **pltt) {
    void *data = NARC_AllocAndReadWholeMember(narc, fileId, HEAP_ID_FIELD1);
    NNS_G2dGetUnpackedPaletteData(data, pltt);
    BG_LoadPlttData(GF_BG_LYR_MAIN_3, (*pltt)->pRawData, 0x20, 12 * 0x20);
    Heap_Free(data);
}

static void CutInBanner_LoadChar(BgConfig *bgConfig, NARC *narc, u32 fileId, NNSG2dCharacterData **chars) {
    void *data = NARC_AllocAndReadWholeMember(narc, fileId, HEAP_ID_FIELD1);
    NNS_G2dGetUnpackedCharacterData(data, chars);
    BG_LoadCharTilesData(bgConfig, GF_BG_LYR_MAIN_3, (*chars)->pRawData, (*chars)->szByte, 0);
    Heap_Free(data);
}

static void CutInBanner_LoadScreen(BgConfig *bgConfig, NARC *narc, u32 fileId, NNSG2dScreenData **screen) {
    void *data;
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_Y, 0);
    data = NARC_AllocAndReadWholeMember(narc, fileId, HEAP_ID_FIELD1);
    NNS_G2dGetUnpackedScreenData(data, screen);
    BG_LoadScreenTilemapData(bgConfig, GF_BG_LYR_MAIN_3, (*screen)->rawData, (*screen)->szByte);
    BgTilemapRectChangePalette(bgConfig, GF_BG_LYR_MAIN_3, 0, 0, 32, 32, 12);
    BgCommitTilemapBufferToVram(bgConfig, GF_BG_LYR_MAIN_3);
    Heap_Free(data);
}

static void CutInBanner_Clear(BgConfig *bgConfig) {
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
}

static void FieldMoveCutIn_StartWindow(FieldMoveCutIn *cutIn) {
    FieldMoveCutIn_CreateWindowTask(cutIn);
    cutIn->windowUpdate = FALSE;
    FieldMoveCutIn_DisableWindow(cutIn);
    FieldMoveCutIn_SetWindowPlanes(cutIn);
    FieldMoveCutIn_EnableWindow(cutIn);
    cutIn->windowUpdate = TRUE;
}

static void FieldMoveCutIn_EnableWindow(FieldMoveCutIn *cutIn) {
    cutIn->windowEnabled = TRUE;
}

static void FieldMoveCutIn_DisableWindow(FieldMoveCutIn *cutIn) {
    cutIn->windowEnabled = FALSE;
}

// Inside the window: the banner (BG3) and sprites. Outside: everything else, with blending.
static void FieldMoveCutIn_SetWindowPlanes(FieldMoveCutIn *cutIn) {
    cutIn->windowInsidePlanes = GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ;
    cutIn->windowInsideEffects = FALSE;
    cutIn->windowOutsidePlanes = GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_OBJ;
    cutIn->windowOutsideEffects = TRUE;
}

static void FieldMoveCutIn_SetWindowOutsidePlanes(FieldMoveCutIn *cutIn) {
    cutIn->windowOutsidePlanes = GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_OBJ;
    cutIn->windowOutsideEffects = TRUE;
}

static void FieldMoveCutIn_SetWindowRect(FieldMoveCutIn *cutIn, fx32 left, fx32 top, fx32 right, fx32 bottom) {
    cutIn->windowLeft = left;
    cutIn->windowRight = right;
    cutIn->windowTop = top;
    cutIn->windowBottom = bottom;
}

static void FieldMoveCutIn_CreateWindowTask(FieldMoveCutIn *cutIn) {
    GF_ASSERT(cutIn->windowTask == NULL);
    cutIn->windowTask = SysTask_CreateOnVBlankQueue(Task_FieldMoveCutIn_UpdateWindow, cutIn, 0x81);
}

static void FieldMoveCutIn_DestroyWindowTask(FieldMoveCutIn *cutIn) {
    GF_ASSERT(cutIn->windowTask != NULL);
    SysTask_Destroy(cutIn->windowTask);
    GX_SetVisibleWnd(GX_WNDMASK_NONE);
}
