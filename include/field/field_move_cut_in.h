#ifndef POKEHEARTGOLD_FIELD_FIELD_MOVE_CUT_IN_H
#define POKEHEARTGOLD_FIELD_FIELD_MOVE_CUT_IN_H

#include "field/field_3d_model.h"
#include "field/field_effect_manager.h"

#include "field_system.h"
#include "pokemon.h"
#include "sprite.h"
#include "sprite_resource.h"
#include "sys_task.h"

// The field move cut-in: the banner with the Pokemon flying across the screen when a field move is used, and the
// Fly take-off animations (the trainer, alone or with another map object, carried away by the flying Pokemon).

// FieldMoveCutIn_Start kinds; FIELD_MOVE_CUT_IN_FLY_WITH_OBJECT is FieldMoveCutIn_StartFlyWithObject
enum FieldMoveCutInKind {
    FIELD_MOVE_CUT_IN_BANNER, // the banner only (field moves)
    FIELD_MOVE_CUT_IN_FLY,
    FIELD_MOVE_CUT_IN_FLY_WITH_FOLLOWER,
    FIELD_MOVE_CUT_IN_FLY_WITH_OBJECT,
};

// The 3D model shown at the second map object when it disappears (Fly with another object).
typedef struct FieldMoveCutInModel {
    NNSFndAllocator allocator;
    void *modelData;
    Field3dModel model;
    Field3dObject object;
    Field3DModelAnimation animations[2];
} FieldMoveCutInModel;

typedef struct FieldMoveCutIn {
    int state; // index into the kind's step table
    BOOL done;
    int timer;
    u16 playerGender;
    u16 trainerGraphics; // player gender, or 2 for no trainer
    BOOL drawSprites;
    int scrollSpriteMode; // 1: banner sprites hidden, 2: drawn inside the window only
    BOOL fadeStarted;
    BOOL flyStarted; // the trainer sprite is no longer clipped to the window
    int kind;        // FieldMoveCutInKind
    u16 bg0Priority;
    u16 bg3Priority;
    int unk_28;
    BOOL windowUpdate; // the HBlank window task writes the registers
    BOOL windowEnabled;
    int windowInsidePlanes;
    BOOL windowInsideEffects;
    int windowOutsidePlanes;
    BOOL windowOutsideEffects;
    fx32 windowLeft;
    fx32 windowRight;
    fx32 windowTop;
    fx32 windowBottom;
    fx32 windowSpeed;
    fx32 monSpeed;
    Pokemon *mon;
    FieldSystem *fieldSystem;
    NNSG2dScreenData *bannerScreen;
    NNSG2dCharacterData *bannerChar;
    NNSG2dPaletteData *bannerPltt;
    SpriteList *spriteList;
    G2dRenderer renderer;
    GF_2DGfxResMan *resMan[4]; // char, pltt, cell, anim
    SpriteResource *charResources[4];
    SpriteResource *plttResources[3];
    SpriteResource *cellResources[4];
    SpriteResource *animResources[2];
    FieldEffectPool *effectPool;
    Sprite *trainerSprite;
    Sprite *monSprite;
    FieldEffect *flyerEffect;
    FieldEffect *modelEffect;
    FieldEffect *trainerClipEffect;
    PokepicTemplate pokepicTemplate;
    LocalMapObject *playerObject;
    LocalMapObject *otherObject;
    int transferStep;
    BOOL transferDone;
    void *monCharData;
    void *monPlttData;
    SysTask *transferTask;
    SysTask *windowTask;
    FieldMoveCutInModel model;
    VecFx32 otherObjectOffset; // x and z: screen offset of the second map object
} FieldMoveCutIn;

// The first half of the cut-in (state machines, banner, sprite resources).
Sprite *FieldMoveCutIn_CreateSprite(FieldMoveCutIn *cutIn, VecFx32 *pos, int charId, int plttId, int cellId, int animId, int priority, int drawPriority);
Sprite *FieldMoveCutIn_CreateEffectSprite(FieldMoveCutIn *cutIn, VecFx32 *pos, int drawPriority, int animSeq);
Sprite *FieldMoveCutIn_CreateFlyerSprite(FieldMoveCutIn *cutIn, VecFx32 *pos, int drawPriority, int unused);

// Cut-in window and Pokemon picture
void Task_FieldMoveCutIn_UpdateWindow(SysTask *task, void *data);
void FieldMoveCutIn_GetMonPicIds(FieldMoveCutIn *cutIn, PokepicTemplate *template);
void *FieldMoveCutIn_LoadMonChar(Pokemon *mon, PokepicTemplate *template, enum HeapID heapID);
void *FieldMoveCutIn_LoadMonPltt(PokepicTemplate *template, enum HeapID heapID);
SpriteResource *FieldMoveCutIn_AddMonCharResource(FieldMoveCutIn *cutIn, NARC *narc);
void FieldMoveCutIn_TransferMonChar(FieldMoveCutIn *cutIn, void *data);
SpriteResource *FieldMoveCutIn_AddMonPlttResource(FieldMoveCutIn *cutIn, NARC *narc);
void FieldMoveCutIn_TransferMonPltt(FieldMoveCutIn *cutIn, void *data);
void FieldMoveCutIn_FreeMonResources(FieldMoveCutIn *cutIn);
Sprite *FieldMoveCutIn_CreateMonSprite(FieldMoveCutIn *cutIn, VecFx32 *pos);
void FieldMoveCutIn_CreateScrollSprites(FieldMoveCutIn *cutIn, int mode);
void FieldMoveCutIn_CreateFlyer(FieldMoveCutIn *cutIn);
u8 FieldMoveCutIn_GetFlyerStatus(FieldMoveCutIn *cutIn);
void FieldMoveCutIn_DestroyFlyer(FieldMoveCutIn *cutIn);
void FieldMoveCutIn_StartFlyerTakeOff(FieldMoveCutIn *cutIn);
void FieldMoveCutIn_StartFlyerPickUp(FieldMoveCutIn *cutIn);
FieldEffect *FieldMoveCutIn_CreateTrainerJumpEffect(FieldEffectPool *effectPool, Sprite *trainerSprite);
void TrainerJumpEffect_StartHop(FieldEffect *effect);
void FieldMoveCutIn_SetPlayerInvisible(FieldMoveCutIn *cutIn, BOOL invisible);
void FieldMoveCutIn_CreateTrainerClipEffect(FieldMoveCutIn *cutIn);
void FieldMoveCutIn_DestroyTrainerClipEffect(FieldMoveCutIn *cutIn);

// Steps of the cut-in kinds, run in order by the cut-in tasks.
BOOL FieldMoveCutIn_StepLoadBannerGraphics(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepLoadSpriteGraphics(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepCreateSprites(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepInitWindow(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepWidenWindow(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepOpenWindow(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepWaitBeforeMon(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepMonSlideIn(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepMonSlowDown(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepWaitBeforeMonExit(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepMonSlideOut(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepCloseWindow(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepFreeBannerGraphics(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepFreeSpriteGraphics(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepEndWindow(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepFinish(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepCreateFlySprites(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepCreateFlyTrainerSprite(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepFreeMonGraphics(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepLoadFlyGraphics(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepWaitFlyGraphics(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepStartFly(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepWaitTakeOff(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepWaitBeforeFlyAway(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepWaitBeforePickUp(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepWaitFlyAway(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepCloseFlyWindow(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepWaitFlyEnd(FieldMoveCutIn *cutIn);
BOOL FieldMoveCutIn_StepWaitPaletteFade(FieldMoveCutIn *cutIn);

// Allocates a zeroed block at the end of the heap.
void *FlyLanding_AllocZeroed(enum HeapID heapID, u32 size);

extern const FieldEffectBasicTemplate gCutInScrollSpriteEffectTemplate;
extern const FieldEffectBasicTemplate gCutInFlyerEffectTemplate;
extern const FieldEffectBasicTemplate gTrainerJumpEffectTemplate;
extern const FieldEffectBasicTemplate gTrainerClipEffectTemplate;
extern const FieldEffectBasicTemplate gCutInModelEffectTemplate;
extern const VecFx32 gCutInFlyerTakeOffOrigin;
extern const VecFx32 gCutInFlyerTakeOffScale;
extern const VecFx32 gCutInFlyerPickUpPos;
extern const VecFx32 gCutInFlyerPickUpScale;
extern const VecFx32 gCutInFlyerTrainerScale;
extern const fx32 gTrainerJumpOffsets[12];
extern const fx32 gTrainerHopOffsets[4];

extern const VecFx32 gCutInTrainerPos;
extern const VecFx32 gCutInMonPos;
extern const VecFx32 gCutInFlyTrainerPos;
extern const VecFx32 gCutInFlyMonPos;
extern const VecFx32 gCutInFlyWithObjectTrainerPos;
extern const VecFx32 gCutInFlyerScale;
extern const u16 gCutInTrainerCharFiles[];
extern const u16 gCutInTrainerAnimFiles[];
extern const u16 gCutInTrainerCellFiles[];
extern const u16 gCutInTrainerPlttFiles[];

#endif // POKEHEARTGOLD_FIELD_FIELD_MOVE_CUT_IN_H
