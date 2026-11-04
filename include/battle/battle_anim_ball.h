#ifndef POKEHEARTGOLD_BATTLE_BATTLE_ANIM_BALL_H
#define POKEHEARTGOLD_BATTLE_BATTLE_ANIM_BALL_H

// Poke Ball throw / capture animation (BallThrow), the ball capsule seal and ball burst
// particles, a generic particle emitter manager and the battler pic graphic swap helpers.

#include "battle/battle.h"
#include "battle/battle_anim_util.h"

// Input of BallSealEffect_New: the particles shown when a Pokemon comes out of its ball
typedef struct BallSealEffectTemplate {
    int battlerType;
    int ball; // used instead of the Pokemon's own ball when nonzero
    Pokemon *mon;
} BallSealEffectTemplate;

// Input of BallBurstEffect_New: the particles of a ball bursting open at a screen position
typedef struct BallBurstEffectTemplate {
    s16 x;
    s16 y;
    int ball;
    enum HeapID heapId;
    int emitter;  // all emitters of the ball's burst (see BallBurstEffect_Start)
    BOOL generic; // the burst of ball 1027 with all its emitters
} BallBurstEffectTemplate;

typedef struct BattleAnimEmitterTemplate {
    int resourceId;  // particle resource (5..26)
    int perspective; // second argument of ParticleSystem_SetPerspectiveType
} BattleAnimEmitterTemplate;

struct BattleAnimBattlerPicParams;

typedef struct BallSealEffect BallSealEffect;
typedef struct BallBurstEffect BallBurstEffect;
typedef struct BattleAnimEmitter BattleAnimEmitter;
typedef struct BattleAnimEmitterManager BattleAnimEmitterManager;

struct BallThrow { // TODO: Give a better name.
    int ballAnim;
    int ballAnimStarted;
    int step;
    int stateFrames;
    int wobbleDir;
    int captureState;
    int shakeCount;
    int modeRunning;
    u8 fadeAlphaA;
    u8 fadeAlphaB;
    s8 randomDir;
    u8 unk23;
    BOOL animateSprite;
    int opened;
    SpriteManager *spriteManager;
    ManagedSprite *managedSprite;
    BattleAnimValueMotion rotation;
    BattleAnimLinearMotion arcMotion;
    BattleAnimSinMotion arcHeightMotion;
    BallThrowParams params;
    s16 x; // sprite position at the mode start
    s16 y;
    s16 targetX; // end of the throw arc
    s16 targetY;
    int arcDuration;
    int modeFrames;
    int arcHeight;
    SysTask *task;
    struct BallBurstEffect *burstEffect;
    struct BattleAnimPaletteBlend *paletteFlash;
    struct BattleAnimBattlerSprites *battlerSprites;
    int startDelay;
}; // Size: 0xe0

typedef BOOL (*BallThrowFunc)(BallThrow *data);

typedef struct BallThrowSpinningKinds {
    u32 kinds[11];
} BallThrowSpinningKinds;

typedef struct BallThrowFlashingKinds {
    u32 kinds[6];
} BallThrowFlashingKinds;

typedef struct BallThrowStaticSpriteKinds {
    u32 kinds[3];
} BallThrowStaticSpriteKinds;

typedef struct BallThrowBounceSound {
    int frame;
    int seqNo;
} BallThrowBounceSound;

typedef struct BallSealEmitDelays {
    u8 delays[7];
} BallSealEmitDelays;

// One frame of the capture bounce: y offset and animation frame
typedef struct BallThrowBounceStep {
    s16 dy;
    u16 frame;
    u16 unused;
} BallThrowBounceStep;

// Seal particle resource of a ball and its emitter count
typedef struct BallAnimSealParticles {
    u32 resource;
    u32 emitterCount;
} BallAnimSealParticles;

// Burst particle resource of a ball, the emitter it skips and its emitter count
typedef struct BallAnimBurstParticles {
    u32 resource;
    u32 skippedEmitter;
    u32 emitterCount;
} BallAnimBurstParticles;

typedef struct BattleAnimEmitterCounts {
    u32 counts[22];
} BattleAnimEmitterCounts;

extern const BallThrowStaticSpriteKinds gBallThrowStaticSpriteKinds;
extern const BallThrowFlashingKinds gBallThrowFlashingKinds;
extern const BallThrowFunc gBallThrowModeFuncs[];
extern const BallThrowFunc gBallThrowBallAnimFuncs[];
extern const BallThrowBounceSound gBallThrowBounceSounds[];
extern const BallThrowSpinningKinds gBallThrowSpinningKinds;
extern const s16 gBallThrowShakeOffsets[];
extern const BallThrowFunc gBallThrowCaptureStateFuncs[];
extern const BallThrowBounceStep gBallThrowBounceSteps[];
// Per ball (BallAnim_GetBallTableIndex) tables
extern const BallAnimSealParticles gBallAnimSealParticles[];
extern const BallAnimBurstParticles gBallAnimBurstParticles[];
extern const u32 gBallSpriteResources[][4];
extern const BallSealEmitDelays gBallSealEmitDelays;
extern const BattleAnimEmitterCounts gBattleAnimEmitterCounts;
extern const s16 gBattlerSlideInTargetX[][2];
// Pokemon/trainer positions (x, y, z) by battler type: [0] on the field, [1] off screen where a slide-in starts.
extern const s16 gBattlerPokepicPositions[2][6][3];

BallSealEffect *BallSealEffect_New(enum HeapID heapId, const BallSealEffectTemplate *template);
void BallSealEffect_LoadResources(BallSealEffect *effect);
BOOL BallSealEffect_IsLoaded(BallSealEffect *effect);
void BallSealEffect_Start(BallSealEffect *effect);
BOOL BallSealEffect_IsActive(BallSealEffect *effect);
void BallSealEffect_Free(BallSealEffect *effect);
BallBurstEffect *BallBurstEffect_New(const BallBurstEffectTemplate *template);
void BallBurstEffect_Start(BallBurstEffect *effect);
BOOL BallThrow_BallAnimThrow(BallThrow *data);
BOOL BallThrow_BallAnimOpen(BallThrow *data);
BOOL BallThrow_BallAnimDeflect(BallThrow *data);
BOOL BallThrow_BallAnimFall(BallThrow *data);
BOOL BallThrow_BallAnimShake(BallThrow *data);
BOOL BallThrow_BallAnimSkip(BallThrow *data);
BOOL BallThrow_BallAnimClick(BallThrow *data);
BOOL BallThrow_BallAnimFade(BallThrow *data);
BOOL BallThrow_CaptureStateIdle(BallThrow *data);
BOOL BallThrow_CaptureStateThrow(BallThrow *data);
BOOL BallThrow_CaptureStateGoToOpen(BallThrow *data);
BOOL BallThrow_CaptureStateOpen(BallThrow *data);
BOOL BallThrow_CaptureStateOpenDone(BallThrow *data);
BOOL BallThrow_CaptureStateDeflect(BallThrow *data);
BOOL BallThrow_CaptureStateDeflectDone(BallThrow *data);
BOOL BallThrow_CaptureStateStartFall(BallThrow *data);
BOOL BallThrow_CaptureStateGoToFlash(BallThrow *data);
BOOL BallThrow_CaptureStateFlash(BallThrow *data);
BOOL BallThrow_CaptureStateGoToDrop(BallThrow *data);
BOOL BallThrow_CaptureStateDrop(BallThrow *data);
BOOL BallThrow_CaptureStateNone(BallThrow *data);
BOOL BallThrow_CaptureStateBounce(BallThrow *data);
BOOL BallThrow_CaptureStateBounceDone(BallThrow *data);
BOOL BallThrow_CaptureStateShakeWait(BallThrow *data);
BOOL BallThrow_CaptureStateGoToShake(BallThrow *data);
BOOL BallThrow_CaptureStateShake(BallThrow *data);
BOOL BallThrow_CaptureStateShakeDone(BallThrow *data);
BOOL BallThrow_CaptureStateGoToSkip(BallThrow *data);
BOOL BallThrow_CaptureStateSkip(BallThrow *data);
BOOL BallThrow_CaptureStateClick(BallThrow *data);
BOOL BallThrow_CaptureStateClickDone(BallThrow *data);
BOOL BallThrow_CaptureStateRestorePalette(BallThrow *data);
BOOL BallThrow_CaptureStateGoToFadeOut(BallThrow *data);
BOOL BallThrow_CaptureStateFadeOut(BallThrow *data);
BOOL BallThrow_CaptureStateGoToEnd(BallThrow *data);
BOOL BallThrow_CaptureStateEnd(BallThrow *data);
BOOL BallThrow_RunCaptureState(BallThrow *data);
BOOL BallThrow_RunThrowArc(BallThrow *data);
BOOL BallThrow_ThrowArcAndOpen(BallThrow *data);
BOOL BallThrow_OpenInPlace(BallThrow *data);
BOOL BallThrow_Wobble(BallThrow *data);
BOOL BallThrow_TrackPosition(BallThrow *data);
BOOL BallThrow_IsActive(BallThrow *data);
BOOL BallThrow_HasOpened(BallThrow *data);
void BallThrow_SetMode(BallThrow *data, int mode);
void BallThrow_SetDrawFlag(BallThrow *data, BOOL flag);
void BallThrow_SetPosition(BallThrow *data, s16 x, s16 y);
void BallThrow_SetAnimateSprite(BallThrow *data, BOOL animate);
void BallThrow_SetDrawPriority(BallThrow *data, u16 priority);
void BallThrow_SetPriority(BallThrow *data, int priority);
void BallThrow_SetDelay(BallThrow *data, int delay);
s32 BallSealEffect_GetDistance(s16 x0, s16 y0, s16 x1, s16 y1);
BattleAnimEmitterManager *BattleAnimEmitterManager_New(enum HeapID heapId, int *unk);
BattleAnimEmitter *BattleAnimEmitterManager_AddEmitter(BattleAnimEmitterManager *manager, BattleAnimEmitterTemplate *template);
void BattleAnimEmitterManager_Free(BattleAnimEmitterManager *manager);
void BattleAnimEmitterManager_StopAll(BattleAnimEmitterManager *manager);
void BattleAnimEmitter_Start(BattleAnimEmitter *emitter);
BOOL BattleAnimEmitter_IsActive(BattleAnimEmitter *emitter);
void BattleAnimUtil_LoadMonIntoPicSameFacing(struct BattleAnimBattlerPicParams *params, enum HeapID heapId);
void BattleAnimUtil_LoadMonIntoPicOppositeFacing(struct BattleAnimBattlerPicParams *params, enum HeapID heapId);
void BattleAnimUtil_RestorePic(struct BattleAnimBattlerPicParams *params, enum HeapID heapId);
void BattleAnimUtil_LoadSubstituteIntoPic(struct BattleAnimBattlerPicParams *params, enum HeapID heapId);
s16 BattleAnimUtil_GetBattlerTypeCoord(u32 battlerType, u32 index);

#endif // POKEHEARTGOLD_BATTLE_BATTLE_ANIM_BALL_H
