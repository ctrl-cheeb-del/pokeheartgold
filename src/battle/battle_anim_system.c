#include "global.h"

#include "constants/battle.h"
#include "constants/moves.h"

#include "battle/battle_anim_ball.h"
#include "battle/battle_anim_emitter.h"
#include "battle/battle_anim_internal.h"
#include "battle/battle_controller.h"
#include "battle/battle_system.h"

#include "assert.h"
#include "bg_window.h"
#include "brightness.h"
#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "obj_pltt_transfer.h"
#include "overlay_06.h"
#include "palette.h"
#include "particle_system.h"
#include "pokemon.h"
#include "pokepic.h"
#include "sound_playback.h"
#include "sound_playback_internal.h"
#include "sprite.h"
#include "sprite_resource_header.h"
#include "sprite_system.h"
#include "sys_task.h"
#include "sys_task_api.h"
#include "system.h"
#include "vram_transfer_manager.h"

// The particle systems are held as SPLEmitter handles (see BattleAnimContext)
void ParticleSystem_GetCameraUp(SPLEmitter *particleSystem, VecFx32 *out);
void ParticleSystem_SetCameraUp(SPLEmitter *particleSystem, VecFx32 *up);

// What a battle animation task is counted as (BattleAnimSystem.taskCount / soundTaskCount)
enum BattleAnimTaskKind {
    BATTLE_ANIM_TASK_NORMAL = 1,
    BATTLE_ANIM_TASK_SOUND,
};

static void BattleAnimSystem_ExecuteCommands(BattleAnimSystem *system);
static BOOL BattleAnimSystem_IsInitialized(BattleAnimSystem *system);
static void BattleAnimTask_Sound(SysTask *task, BattleAnimSoundTaskData *data);
static BOOL BattleAnimSoundFunc_None(BattleAnimSoundTaskData *data);
static BOOL BattleAnimSoundFunc_PanSweep(BattleAnimSoundTaskData *data);
static BOOL BattleAnimSoundFunc_PanSweep2(BattleAnimSoundTaskData *data);
static BOOL BattleAnimSoundFunc_PanSweep3(BattleAnimSoundTaskData *data);
static BOOL BattleAnimSoundFunc_RepeatSE(BattleAnimSoundTaskData *data);
static BOOL BattleAnimSoundFunc_DelayedSE(BattleAnimSoundTaskData *data);
static void BattleAnimScriptCmd_WaitForButtonCombo(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Wait(BattleAnimSystem *system);
static void BattleAnimScriptCmd_WaitForTasks(BattleAnimSystem *system);
static void BattleAnimScriptCmd_SetArg(BattleAnimSystem *system);
static void BattleAnimScriptCmd_ClearArgs(BattleAnimSystem *system);
static void BattleAnimScriptCmd_ChangeBattlerPic(BattleAnimSystem *system);
static void BattleAnimScriptCmd_RestoreBattlerPic(BattleAnimSystem *system);
static void BattleAnimScriptCmd_BeginLoop(BattleAnimSystem *system);
static void BattleAnimScriptCmd_EndLoop(BattleAnimSystem *system);
static void BattleAnimScriptCmd_End(BattleAnimSystem *system);
static void BattleAnimScriptCmd_CreateEmitter(BattleAnimSystem *system);
static void BattleAnimScriptCmd_CreateEmitterInSlot(BattleAnimSystem *system);
static void BattleAnimScriptCmd_CreateEmitterByPosition6(BattleAnimSystem *system);
static void BattleAnimScriptCmd_CreateEmitterByPosition4(BattleAnimSystem *system);
static void BattleAnimScriptCmd_WaitForParticles(BattleAnimSystem *system);
static void BattleAnimScriptCmd_LoadParticleSystem(BattleAnimSystem *system);
static void BattleAnimScriptCmd_LoadParticleSystemEx(BattleAnimSystem *system);
static void BattleAnimScriptCmd_FreeParticleSystem(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Call(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Return(BattleAnimSystem *system);
static void BattleAnimScriptCmd_JumpIfArgEqual(BattleAnimSystem *system);
static void BattleAnimScriptCmd_JumpIfContextField01(BattleAnimSystem *system);
static void BattleAnimScriptCmd_CallFunc(BattleAnimSystem *system);
static void BattleAnimScriptCmd_JumpByVariantBit0(BattleAnimSystem *system);
static void BattleAnimScriptCmd_JumpBySide(BattleAnimSystem *system);
static void BattleAnimScriptCmd_JumpByWeather(BattleAnimSystem *system);
static void BattleAnimScriptCmd_JumpIfContest(BattleAnimSystem *system);
static void BattleAnimScriptCmd_JumpIfAttackerActive(BattleAnimSystem *system);
static void BattleAnimScriptCmd_JumpIfSameSide(BattleAnimSystem *system);
static void BattleAnimScriptCmd_JumpIfVariantEqual(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Jump(BattleAnimSystem *system);
static void BattleAnimScriptCmd_BrightnessFlash(BattleAnimSystem *system);
static void BattleAnimSystem_StopFollowTask(BattleAnimSystem *system, u32 index);
static void BattleAnimScriptCmd_Nop6(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Nop7(BattleAnimSystem *system);
static void BattleAnimScriptCmd_CopyBattlerToBg(BattleAnimSystem *system);
static void BattleAnimScriptCmd_ClearBattlerBg(BattleAnimSystem *system);
static void BattleAnimScriptCmd_InitBattlerSpriteManager(BattleAnimSystem *system);
static void BattleAnimScriptCmd_LoadBattlerSpriteResources(BattleAnimSystem *system);
static void BattleAnimScriptCmd_CreateBattlerSprite(BattleAnimSystem *system);
static void BattleAnimScriptCmd_FreeBattlerSpriteManager(BattleAnimSystem *system);
static void BattleAnimScriptCmd_DeleteBattlerSprite(BattleAnimSystem *system);
static void BattleAnimScriptCmd_StartBattlerSpriteDraw(BattleAnimSystem *system);
static void BattleAnimScriptCmd_StopBattlerSpriteDraw(BattleAnimSystem *system);
static void BattleAnimScriptCmd_StopFollowTask(BattleAnimSystem *system);
static void BattleAnimScriptCmd_SetParticlePerspective(BattleAnimSystem *system);
static void BattleAnimScriptCmd_SetParticleFlipY(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Nop40(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Nop41(BattleAnimSystem *system);
static void BattleAnimSystem_StopBgEffects(BattleAnimBgEffect **effects, int kind);
static BOOL BattleAnimBackground_BlendIn(SysTask *task, BattleAnimBgSwitchWork *work);
static BOOL BattleAnimBackground_BlendOut(SysTask *task, BattleAnimBgSwitchWork *work);
static BOOL BattleAnimBackground_FadeIn(SysTask *task, BattleAnimBgSwitchWork *work);
static BOOL BattleAnimBackground_FadeOut(SysTask *task, BattleAnimBgSwitchWork *work);
static BOOL BattleAnimBackground_StartEffectsOnly(SysTask *task, BattleAnimBgSwitchWork *work);
static BOOL BattleAnimBackground_StartEffectsAndStopMarked(SysTask *task, BattleAnimBgSwitchWork *work);
static void BattleAnimBackground_StopMarkedEffects(BattleAnimBgSwitchWork *work);
static BOOL BattleAnimBackground_EffectNone(BattleAnimBgSwitchWork *work);
static BOOL BattleAnimBackground_StartScroll(BattleAnimBgSwitchWork *work);
static BOOL BattleAnimBackground_StartWave(BattleAnimBgSwitchWork *work);
static BOOL BattleAnimBackground_MarkWaveForStop(BattleAnimBgSwitchWork *work);
static void BattleAnimTask_BgWave(SysTask *task, void *data);
static BOOL BattleAnimBackground_StartPaletteCycle(BattleAnimBgSwitchWork *work);
static BOOL BattleAnimBackground_MarkPaletteCycleForStop(BattleAnimBgSwitchWork *work);
static void BattleAnimBackground_LoadBattleBgToLayer(BattleAnimSystem *system, GFBgLayer layer, int colorMode);
static BOOL BattleAnimBackground_MarkScrollForStop(BattleAnimBgSwitchWork *work);
static BOOL BattleAnimBackground_StopAllEffects(BattleAnimBgSwitchWork *work);
static void BattleAnimScriptCmd_SwitchBackground(BattleAnimSystem *system);
static void BattleAnimScriptCmd_SwitchBackgroundWithFadeWait(BattleAnimSystem *system);
static void BattleAnimScriptCmd_SetBgScroll(BattleAnimSystem *system);
static void BattleAnimScriptCmd_RestoreBackground(BattleAnimSystem *system);
static void BattleAnimScriptCmd_WaitForBackgroundLoaded(BattleAnimSystem *system);
static void BattleAnimScriptCmd_WaitForBackgroundSwitch(BattleAnimSystem *system);
static void BattleAnimScriptCmd_SetBackground(BattleAnimSystem *system);
static void BattleAnimScriptCmd_SwitchBackgroundBySide(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Nop37(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Nop38(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Nop39(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Nop42(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Nop43(BattleAnimSystem *system);
static void BattleAnimScriptCmd_PlaySE(BattleAnimSystem *system);
static void BattleAnimScriptCmd_StopSE(BattleAnimSystem *system);
static void BattleAnimScriptCmd_PlaySEWithPan(BattleAnimSystem *system);
static void BattleAnimScriptCmd_SetSEPan(BattleAnimSystem *system);
static void BattleAnimScriptCmd_PanSweepSE(BattleAnimSystem *system);
static void BattleAnimScriptCmd_PanSweepSERaw(BattleAnimSystem *system);
static void BattleAnimScriptCmd_PanSweepSEConverted(BattleAnimSystem *system);
static void BattleAnimScriptCmd_RepeatSE(BattleAnimSystem *system);
static void BattleAnimScriptCmd_DelayedSE(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Nop28(BattleAnimSystem *system);
static void BattleAnimScriptCmd_WaitForSoundTasks(BattleAnimSystem *system);
static void BattleAnimScriptCmd_SetSubScreenBlend(BattleAnimSystem *system);
static void BattleAnimScriptCmd_ResetBlend(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Nop27(BattleAnimSystem *system);
static void BattleAnimScriptCmd_InitSpriteManager(BattleAnimSystem *system);
static void BattleAnimScriptCmd_LoadCharResource(BattleAnimSystem *system);
static void BattleAnimScriptCmd_LoadPaletteResource(BattleAnimSystem *system);
static void BattleAnimScriptCmd_LoadCellResource(BattleAnimSystem *system);
static void BattleAnimScriptCmd_LoadAnimResource(BattleAnimSystem *system);
static void BattleAnimScriptCmd_CreateSpriteWithFunc(BattleAnimSystem *system);
static void BattleAnimScriptCmd_CreateSprite(BattleAnimSystem *system);
static void BattleAnimScriptCmd_FreeSpriteManager(BattleAnimSystem *system);
static void BattleAnimScriptCmd_SetBattlerSpriteVisible(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Invalid55(BattleAnimSystem *system);
static void BattleAnimScriptCmd_PlayCry(BattleAnimSystem *system);
static void BattleAnimScriptCmd_WaitForCry(BattleAnimSystem *system);
static void BattleAnimScriptCmd_Nop54(BattleAnimSystem *system);
static BattleAnimScriptCmd BattleAnimSystem_GetScriptCmd(u32 cmd);
static u8 BattleAnimContext_GetField01(BattleAnimContext *context);
static s8 BattleAnimSystem_ConvertPan(BattleAnimSystem *system, int pan);
static s8 BattleAnimSystem_GetPanStep(int start, int end, int step);
static void BattleAnimSystem_LoadBattleBgTiles(BattleAnimSystem *system, GFBgLayer layer);
static void BattleAnimSystem_LoadBattleBgPalette(BattleAnimSystem *system);
static SPLEmitter *BattleAnimSystem_CreateEmitter(SPLEmitter *particleSystem, int resId, int callback, BattleAnimSystem *system);

// SE pan sweep / repeat / delay task (sBattleAnimSoundFuncs[kind])
struct BattleAnimSoundTaskData {
    u8 kind;
    u8 unk_01[2];
    u8 interval; // repeat interval; the delay of DelayedSE
    u8 counter;
    int startPan;
    int endPan;
    int panStep;
    int pan;
    u8 repeatCount;
    u16 seqNo;
    u8 unk_1C[0x1C];
    BattleAnimSystem *system;
};

typedef BOOL (*BattleAnimSoundFunc)(BattleAnimSoundTaskData *data);

struct BattleAnimBrightnessFlashWork {
    BattleAnimSystem *system;
    u32 steps : 8;
    u32 fadingBack : 1;
    u32 unk_04_9 : 23;
};

// Work of a move background switch on BG3 (sBattleAnimBgSwitchFuncs[func])
struct BattleAnimBgSwitchWork {
    u32 unk_00;
    u8 unk_04;
    u8 step;
    u8 unk_06[3];
    u8 eva;
    u8 evb;
    u8 evaTarget;
    u8 evbTarget;
    u8 fadeToWhite;
    s8 switchFadeWait;
    s8 restoreFadeWait;
    u32 bgId;
    u32 func;
    u32 effectFlags;
    int args[10];
    u16 stopScroll : 1;
    u16 stopWave : 1;
    u16 stopPaletteCycle : 1;
    u16 unk_44_3 : 13;
    BattleAnimSystem *system;
};

typedef BOOL (*BattleAnimBgSwitchFunc)(SysTask *task, BattleAnimBgSwitchWork *work);
typedef BOOL (*BattleAnimBgEffectFunc)(BattleAnimBgSwitchWork *work);

// Background effect kind 1: BG scroll
typedef struct BattleAnimBgScroll {
    BgConfig *bgConfig;
    s16 x;
    s16 y;
    s16 dx;
    s16 dy;
    GFBgLayer layer;
    int unk_10;
    int unk_14;
    BOOL stop;
    int kind;
    u8 unk_20[8];
} BattleAnimBgScroll;

typedef struct BattleAnimBgWaveBand {
    s16 start;
    s16 end;
    s16 step;
    s16 offset;
    int scroll;
} BattleAnimBgWaveBand;

typedef struct BattleAnimBgWaveBands {
    BattleAnimBgWaveBand bands[16];
    BattleAnimScanline *scanline;
} BattleAnimBgWaveBands;

// Background effect kind 2: BG wave through the HBlank scanline buffer
typedef struct BattleAnimBgWave {
    u8 unk_00[0x18];
    BOOL stop;
    int kind;
    BattleAnimBgWaveBands *bands;
    u8 unk_24[4];
} BattleAnimBgWave;

typedef struct BattleAnimPaletteCycleData {
    enum HeapID heapId;
    PaletteData *paletteData;
    u8 offsets[128];
    u16 durations[128];
    u8 count;
    u8 member;
    u8 timer;
    u8 state;
    u8 index;
} BattleAnimPaletteCycleData;

// Background effect kind 3: palette cycle of the move background
typedef struct BattleAnimPaletteCycle {
    u8 unk_00[0x18];
    BOOL stop;
    int kind;
    u8 unk_20[4];
    BattleAnimPaletteCycleData *data;
} BattleAnimPaletteCycle;

struct BattleAnimIndexedBytes {
    u8 unk_00[4];
    u32 index;
    u8 unk_08[0x3C];
    u8 values[1];
};

struct BattleAnimBattlerSprites {
    enum HeapID heapId;
    int battler;
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    PaletteData *paletteData;
    int resIds[4];
    ManagedSprite *sprites[4];
    MonPicData *picData[4];
    u8 battlerTypes[4];
    Pokepic *pokepics[4];
};

static const u32 sBattleAnimBgMaskLayers[] = { 1, 2, 3 };

static const u32 sBattleAnimEmitterSelect6[6][6] = {
    { 255, 1,   255, 255, 255, 255 },
    { 4,   255, 255, 255, 255, 255 },
    { 255, 255, 255, 3,   255, 1   },
    { 255, 255, 6,   255, 4,   255 },
    { 255, 255, 255, 1,   255, 2   },
    { 255, 255, 4,   255, 5,   255 },
};

static const u32 sBattleAnimBgEffectMasks[6] = { 0x20000, 0x40000, 0x200000, 0x400000, 0x800000, 0x1000000 };

static const u32 sBattleAnimBgLayers[] = { GF_BG_LYR_MAIN_1, GF_BG_LYR_MAIN_2, GF_BG_LYR_MAIN_3 };

static const BattleAnimSoundFunc sBattleAnimSoundFuncs[] = {
    BattleAnimSoundFunc_None,
    BattleAnimSoundFunc_PanSweep,
    BattleAnimSoundFunc_PanSweep2,
    BattleAnimSoundFunc_PanSweep3,
    BattleAnimSoundFunc_RepeatSE,
    BattleAnimSoundFunc_DelayedSE,
};

static const SpriteResourceCountsListUnion sBattleAnimBattlerSpriteCapacities = {
    .numChar = 5,
    .numPltt = 5,
    .numCell = 5,
    .numAnim = 5,
    .numMcel = 0,
    .numManm = 0,
};

static const s16 sBattleAnimBgWaveSteps[16] = { 32, 28, 24, 20, 16, 12, 8, 4, 4, 8, 12, 16, 20, 24, 28, 32 };

static const BattleAnimBgEffectFunc sBattleAnimBgEffectFuncs[] = {
    BattleAnimBackground_EffectNone,
    BattleAnimBackground_StartScroll,
    BattleAnimBackground_MarkScrollForStop,
    BattleAnimBackground_StopAllEffects,
    BattleAnimBackground_EffectNone,
    BattleAnimBackground_StartWave,
    BattleAnimBackground_MarkWaveForStop,
    BattleAnimBackground_StartPaletteCycle,
    BattleAnimBackground_MarkPaletteCycleForStop,
};

static const u32 sBattleAnimEmitterSelect4[6][6] = {
    { 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 0,   255 },
    { 255, 255, 255, 255, 255, 1   },
    { 255, 255, 1,   255, 255, 255 },
    { 255, 255, 255, 0,   255, 255 },
};

static const BattleAnimBgSwitchFunc sBattleAnimBgSwitchFuncs[] = {
    BattleAnimBackground_BlendIn,
    BattleAnimBackground_FadeIn,
    BattleAnimBackground_StartEffectsOnly,
    BattleAnimBackground_BlendOut,
    BattleAnimBackground_FadeOut,
    BattleAnimBackground_StartEffectsAndStopMarked,
};

static const u32 sBattleAnimWeatherMasks[4] = { 0x03, 0x0C, 0x30, 0xC0 };

// Secret Power animation (a move) by battle terrain
static const u32 sSecretPowerTerrainAnims[25] = {
    MOVE_MUD_SLAP,
    MOVE_MUD_SLAP,
    MOVE_NEEDLE_ARM,
    MOVE_NEEDLE_ARM,
    MOVE_ROCK_THROW,
    MOVE_ROCK_THROW,
    MOVE_AVALANCHE,
    MOVE_WATER_PULSE,
    MOVE_ICE_SHARD,
    MOVE_BODY_SLAM,
    MOVE_MUD_SHOT,
    MOVE_GUST,
    MOVE_BODY_SLAM,
    MOVE_POUND,
    MOVE_POUND,
    MOVE_POUND,
    MOVE_POUND,
    MOVE_POUND,
    MOVE_POUND,
    MOVE_POUND,
    MOVE_POUND,
    MOVE_POUND,
    MOVE_POUND,
    MOVE_POUND,
    MOVE_POUND,
};

static const u32 sBattleAnimBattlerSpritePriorities[6] = { 0, 0, 20, 10, 10, 20 };

static const BattleAnimScriptCmd sBattleAnimScriptCmdTable[] = {
    BattleAnimScriptCmd_Wait,
    BattleAnimScriptCmd_WaitForTasks,
    BattleAnimScriptCmd_BeginLoop,
    BattleAnimScriptCmd_EndLoop,
    BattleAnimScriptCmd_End,
    BattleAnimScriptCmd_PlaySE,
    BattleAnimScriptCmd_Nop6,
    BattleAnimScriptCmd_Nop7,
    BattleAnimScriptCmd_SetSubScreenBlend,
    BattleAnimScriptCmd_ResetBlend,
    BattleAnimScriptCmd_Call,
    BattleAnimScriptCmd_Return,
    BattleAnimScriptCmd_SetArg,
    BattleAnimScriptCmd_JumpByVariantBit0,
    BattleAnimScriptCmd_JumpIfVariantEqual,
    BattleAnimScriptCmd_Jump,
    BattleAnimScriptCmd_SwitchBackground,
    BattleAnimScriptCmd_SetBgScroll,
    BattleAnimScriptCmd_RestoreBackground,
    BattleAnimScriptCmd_WaitForBackgroundLoaded,
    BattleAnimScriptCmd_WaitForBackgroundSwitch,
    BattleAnimScriptCmd_SetBackground,
    BattleAnimScriptCmd_PlaySEWithPan,
    BattleAnimScriptCmd_SetSEPan,
    BattleAnimScriptCmd_PanSweepSE,
    BattleAnimScriptCmd_RepeatSE,
    BattleAnimScriptCmd_DelayedSE,
    BattleAnimScriptCmd_Nop27,
    BattleAnimScriptCmd_Nop28,
    BattleAnimScriptCmd_WaitForSoundTasks,
    BattleAnimScriptCmd_JumpIfArgEqual,
    BattleAnimScriptCmd_CopyBattlerToBg,
    BattleAnimScriptCmd_ClearBattlerBg,
    BattleAnimScriptCmd_JumpIfContextField01,
    BattleAnimScriptCmd_SwitchBackgroundBySide,
    BattleAnimScriptCmd_PanSweepSERaw,
    BattleAnimScriptCmd_PanSweepSEConverted,
    BattleAnimScriptCmd_Nop37,
    BattleAnimScriptCmd_Nop38,
    BattleAnimScriptCmd_Nop39,
    BattleAnimScriptCmd_Nop40,
    BattleAnimScriptCmd_Nop41,
    BattleAnimScriptCmd_Nop42,
    BattleAnimScriptCmd_Nop43,
    BattleAnimScriptCmd_StopSE,
    BattleAnimScriptCmd_CallFunc,
    BattleAnimScriptCmd_CreateEmitter,
    BattleAnimScriptCmd_CreateEmitterInSlot,
    BattleAnimScriptCmd_CreateEmitterByPosition6,
    BattleAnimScriptCmd_CreateEmitterByPosition4,
    BattleAnimScriptCmd_WaitForParticles,
    BattleAnimScriptCmd_LoadParticleSystem,
    BattleAnimScriptCmd_LoadParticleSystemEx,
    BattleAnimScriptCmd_FreeParticleSystem,
    BattleAnimScriptCmd_Nop54,
    BattleAnimScriptCmd_Invalid55,
    BattleAnimScriptCmd_InitBattlerSpriteManager,
    BattleAnimScriptCmd_LoadBattlerSpriteResources,
    BattleAnimScriptCmd_CreateBattlerSprite,
    BattleAnimScriptCmd_FreeBattlerSpriteManager,
    BattleAnimScriptCmd_DeleteBattlerSprite,
    BattleAnimScriptCmd_StopFollowTask,
    BattleAnimScriptCmd_SetParticlePerspective,
    BattleAnimScriptCmd_SetParticleFlipY,
    BattleAnimScriptCmd_JumpBySide,
    BattleAnimScriptCmd_PlayCry,
    BattleAnimScriptCmd_WaitForCry,
    BattleAnimScriptCmd_ClearArgs,
    BattleAnimScriptCmd_ChangeBattlerPic,
    BattleAnimScriptCmd_RestoreBattlerPic,
    BattleAnimScriptCmd_JumpByWeather,
    BattleAnimScriptCmd_JumpIfContest,
    BattleAnimScriptCmd_JumpIfSameSide,
    BattleAnimScriptCmd_InitSpriteManager,
    BattleAnimScriptCmd_LoadCharResource,
    BattleAnimScriptCmd_LoadPaletteResource,
    BattleAnimScriptCmd_LoadCellResource,
    BattleAnimScriptCmd_LoadAnimResource,
    BattleAnimScriptCmd_CreateSpriteWithFunc,
    BattleAnimScriptCmd_CreateSprite,
    BattleAnimScriptCmd_FreeSpriteManager,
    BattleAnimScriptCmd_SetBattlerSpriteVisible,
    BattleAnimScriptCmd_StartBattlerSpriteDraw,
    BattleAnimScriptCmd_StopBattlerSpriteDraw,
    BattleAnimScriptCmd_WaitForButtonCombo,
    BattleAnimScriptCmd_BrightnessFlash,
    BattleAnimScriptCmd_SwitchBackgroundWithFadeWait,
    BattleAnimScriptCmd_JumpIfAttackerActive,
};

static const u32 sBattleAnimBackgroundFiles[][BATTLE_ANIM_BG_FILE_COUNT] = {
    { 59,  0x127, 56,  57,  58  },
    { 59,  0x127, 56,  57,  58  },
    { 119, 0x13F, 120, 120, 120 },
    { 59,  0x127, 56,  57,  58  },
    { 59,  0x127, 56,  57,  58  },
    { 59,  0x14A, 56,  57,  58  },
    { 63,  0x128, 60,  61,  62  },
    { 142, 0x14E, 143, 144, 143 },
    { 63,  0x151, 60,  61,  62  },
    { 64,  0x129, 65,  65,  65  },
    { 64,  0x129, 65,  65,  65  },
    { 119, 0x140, 120, 120, 120 },
    { 64,  0x149, 65,  65,  65  },
    { 64,  0x150, 65,  65,  65  },
    { 119, 0x13E, 120, 120, 120 },
    { 70,  0x12C, 66,  66,  66  },
    { 70,  0x134, 66,  66,  66  },
    { 119, 0x13D, 120, 120, 120 },
    { 70,  0x134, 66,  66,  66  },
    { 75,  0x12D, 76,  76,  74  },
    { 83,  0x12F, 80,  81,  82  },
    { 89,  0x131, 86,  87,  88  },
    { 93,  0x132, 90,  91,  92  },
    { 94,  0x133, 95,  95,  95  },
    { 99,  0x136, 100, 100, 100 },
    { 102, 0x137, 103, 103, 101 },
    { 108, 0x138, 107, 107, 107 },
    { 108, 0x15C, 107, 107, 107 },
    { 109, 0x139, 110, 110, 110 },
    { 111, 0x13A, 112, 112, 112 },
    { 109, 0x139, 110, 110, 110 },
    { 118, 0x13C, 115, 116, 117 },
    { 118, 0x13C, 115, 116, 117 },
    { 118, 0x13C, 115, 116, 117 },
    { 125, 0x144, 126, 126, 126 },
    { 130, 0x146, 131, 131, 129 },
    { 132, 0x147, 133, 133, 134 },
    { 139, 0x14C, 137, 138, 138 },
    { 140, 0x14D, 141, 141, 141 },
    { 145, 0x14F, 146, 146, 146 },
    { 150, 0x152, 147, 148, 149 },
    { 154, 0x153, 151, 152, 153 },
    { 155, 0x154, 156, 156, 156 },
    { 157, 0x155, 158, 158, 158 },
    { 159, 0x156, 160, 160, 160 },
    { 164, 0x157, 161, 162, 163 },
    { 165, 0x158, 166, 166, 166 },
    { 46,  0x122, 47,  47,  47  },
    { 167, 0x159, 168, 169, 168 },
    { 167, 0x15B, 168, 169, 168 },
    { 170, 0x15A, 172, 171, 171 },
    { 72,  0x12B, 73,  73,  73  },
    { 84,  0x130, 85,  85,  85  },
    { 79,  0x12E, 77,  78,  77  },
    { 113, 0x13B, 114, 114, 114 },
    { 123, 0x143, 124, 124, 124 },
    { 121, 0x142, 122, 122, 122 },
    { 135, 0x14B, 136, 136, 136 },
    { 98,  0x135, 96,  97,  96  },
};

static void BattleAnimSystem_WaitDelay(BattleAnimSystem *system) {
    if (system->delay == 0) {
        system->runner = BattleAnimSystem_ExecuteCommands;
    } else {
        system->delay--;
    }
}

static void BattleAnimSystem_ExecuteCommands(BattleAnimSystem *system) {
    do {
        BattleAnimScriptCmd cmd = BattleAnimSystem_GetScriptCmd(*system->scriptPtr);
        cmd(system);
    } while (system->delay == 0 && system->active == TRUE);
}

static SysTask *BattleAnimSystem_CreateTaskOfKind(enum BattleAnimTaskKind kind, BattleAnimSystem *system, SysTaskFunc func, void *data, u32 priority) {
    switch (kind) {
    case BATTLE_ANIM_TASK_NORMAL:
        system->taskCount++;
        break;
    case BATTLE_ANIM_TASK_SOUND:
        system->soundTaskCount++;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return SysTask_CreateOnMainQueue(func, data, priority);
}

static void BattleAnimSystem_DestroyTaskOfKind(enum BattleAnimTaskKind kind, BattleAnimSystem *system, SysTask *task) {
    switch (kind) {
    case BATTLE_ANIM_TASK_NORMAL:
        system->taskCount--;
        break;
    case BATTLE_ANIM_TASK_SOUND:
        system->soundTaskCount--;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    SysTask_Destroy(task);
}

BattleAnimSystem *BattleAnimSystem_New(enum HeapID heapId) {
    int i;
    BattleAnimSystem *system = Heap_Alloc(heapId, sizeof(BattleAnimSystem));
    if (system == NULL) {
        GF_ASSERT(system != NULL);
        return NULL;
    }

    memset(system, 0, sizeof(BattleAnimSystem));
    system->heapId = heapId;
    system->isContest = FALSE;
    system->context = Heap_Alloc(system->heapId, sizeof(BattleAnimContext));
    system->narcs[0] = NARC_New(NARC_a_0_0_7, heapId);
    system->narcs[1] = NARC_New(NARC_a_0_0_8, heapId);
    system->narcs[2] = NARC_New(NARC_a_0_2_2, heapId);
    system->narcs[3] = NARC_New(NARC_a_0_2_3, heapId);
    system->narcs[4] = NARC_New(NARC_a_0_2_4, heapId);
    system->narcs[5] = NARC_New(NARC_a_0_2_5, heapId);
    if (system->context == NULL) {
        GF_ASSERT(system->context != NULL);
        return NULL;
    }
    memset(system->context, 0, sizeof(BattleAnimContext));
    system->initialized = FALSE;
    system->scriptPtr = NULL;
    for (i = 0; i < 4; i++) {
        system->spriteManagers[i] = NULL;
    }
    for (i = 0; i < 5; i++) {
        system->followWorks[i] = NULL;
    }
    system->followWorks[5] = NULL;
    system->initialized = TRUE;
    return system;
}

BOOL BattleAnimSystem_IsContest(BattleAnimSystem *system) {
    GF_ASSERT(system != NULL);
    return system->isContest;
}

enum HeapID BattleAnimSystem_GetHeapID(BattleAnimSystem *system) {
    GF_ASSERT(system != NULL);
    return system->heapId;
}

BOOL BattleAnimSystem_Delete(BattleAnimSystem *system) {
    int i;
    if (!BattleAnimSystem_IsInitialized(system)) {
        return FALSE;
    }
    for (i = 0; i < 6; i++) {
        NARC_Delete(system->narcs[i]);
    }
    Heap_Free(system->context);
    Heap_Free(system);
    return TRUE;
}

BOOL BattleAnimSystem_StartMove(BattleAnimSystem *system, MoveAnimData *animData, u16 move, BattleAnimSetup *setup) {
    u32 terrainAnims[25];
    int i;
    int animId = move;

    BattleAnimSystem_InitBlend();
    if (!BattleAnimSystem_IsInitialized(system)) {
        return FALSE;
    }
    for (i = 0; i < 16; i++) {
        system->particlePerspective[i] = 1;
        system->particleFlipY[i] = 0;
    }
    for (i = 0; i < 10; i++) {
        system->args[i] = 0;
    }
    for (i = 0; i < 3; i++) {
        system->loops[i].active = FALSE;
        system->loops[i].start = NULL;
        system->loops[i].counter = 0;
        system->loops[i].count = 0;
    }
    system->context->command = animData->command;
    system->context->unk_01 = animData->unk_01;
    system->context->move = animData->move;
    system->context->damage = animData->damage;
    system->context->power = animData->power;
    system->context->friendship = animData->friendship;
    system->context->fieldCondition = animData->fieldCondition;
    system->context->moveAnimVariant = animData->moveAnimVariant;
    system->context->terrain = animData->terrain;
    system->context->attacker = animData->attacker;
    system->context->defender = animData->defender;
    system->context->isTransformed = animData->isTransformed;
    system->context->attackerActive = animData->attackerActive;
    system->context->defenderActive = animData->defenderActive;
    system->context->spriteSystem = setup->spriteSystem;
    GF_ASSERT(setup->spriteSystem != NULL);
    system->bgConfig = setup->bgConfig;
    system->paletteData = setup->paletteData;
    system->context->battleType = setup->battleType;
    for (i = 0; i < 4; i++) {
        system->context->picData[i] = setup->picData[i];
        system->context->battlerTypes[i] = setup->battlerTypes[i];
        system->context->pokepics[i] = setup->pokepics[i];
        system->context->species[i] = setup->species[i];
        system->context->genders[i] = setup->genders[i];
        system->context->shiny[i] = setup->shiny[i];
        system->context->forms[i] = setup->forms[i];
        system->context->personalities[i] = setup->personalities[i];
        system->context->moveEffectFlags[i] = setup->moveEffectFlags[i];
    }
    system->battleBg = setup->battleBg;
    system->context->chatotCry = setup->chatotCry;
    system->context->battleBgPalette = setup->battleBgPalette;
    system->context->battleBgTiles = setup->battleBgTiles;
    if (animId == MOVE_SECRET_POWER) {
        ARRAY_ASSIGN(terrainAnims, sSecretPowerTerrainAnims);
        if (system->context->terrain >= 24) {
            animId = MOVE_TRI_ATTACK;
        } else {
            animId = terrainAnims[system->context->terrain];
        }
    }
    if (animId == MOVE_NONE || animId > NUM_MOVES) {
        animId = MOVE_POUND;
    }
    system->scriptNarc = setup->scriptNarc;
    system->scriptData = AllocAndReadWholeNarcMemberByIdPair(system->scriptNarc, animId, system->heapId);
    if (system->scriptData == NULL) {
        GF_ASSERT(system->scriptData != NULL);
        return FALSE;
    }
    system->scriptPtr = system->scriptData;
    system->bgPriorities[0] = GetBgPriority(system->bgConfig, GF_BG_LYR_MAIN_0);
    system->bgPriorities[1] = GetBgPriority(system->bgConfig, GF_BG_LYR_MAIN_1);
    system->bgPriorities[2] = GetBgPriority(system->bgConfig, GF_BG_LYR_MAIN_2);
    system->bgPriorities[3] = GetBgPriority(system->bgConfig, GF_BG_LYR_MAIN_3);
    for (i = 0; i < 10; i++) {
        system->sprites[i] = NULL;
    }
    for (i = 0; i < 5; i++) {
        system->battlerSprites[i] = NULL;
        system->battlerSpriteActive[i] = FALSE;
    }
    for (i = 0; i < 4; i++) {
        system->bgEffects[i] = NULL;
    }
    system->runner = BattleAnimSystem_ExecuteCommands;
    system->delay = 0;
    system->battleBgPaletteMask = 0xFF;
    system->active = TRUE;
    return TRUE;
}

BOOL BattleAnimSystem_Execute(BattleAnimSystem *system) {
    if (!BattleAnimSystem_IsInitialized(system)) {
        return FALSE;
    }
    system->runner(system);
    return TRUE;
}

BOOL BattleAnimSystem_IsActive(BattleAnimSystem *system) {
    return system->active == TRUE;
}

BOOL BattleAnimSystem_EndMove(BattleAnimSystem *system) {
    if (system->scriptData == NULL) {
        GF_ASSERT(system->scriptData != NULL);
        return FALSE;
    }
    Heap_Free(system->scriptData);
    return TRUE;
}

static BOOL BattleAnimSystem_IsInitialized(BattleAnimSystem *system) {
    if (system == NULL) {
        return FALSE;
    }
    return system->initialized == TRUE;
}

SysTask *BattleAnimSystem_CreateTask(BattleAnimSystem *system, SysTaskFunc func, void *data, u32 priority) {
    return BattleAnimSystem_CreateTaskOfKind(BATTLE_ANIM_TASK_NORMAL, system, func, data, priority);
}

SysTask *BattleAnimSystem_CreateTaskDefaultPriority(BattleAnimSystem *system, SysTaskFunc func, void *data) {
    return BattleAnimSystem_CreateTaskOfKind(BATTLE_ANIM_TASK_NORMAL, system, func, data, 1100);
}

SysTask *BattleAnimSystem_CreateSoundTask(BattleAnimSystem *system, SysTaskFunc func, void *data, u32 priority) {
    return BattleAnimSystem_CreateTaskOfKind(BATTLE_ANIM_TASK_SOUND, system, func, data, priority);
}

void BattleAnimSystem_DestroyTask(BattleAnimSystem *system, SysTask *task) {
    BattleAnimSystem_DestroyTaskOfKind(BATTLE_ANIM_TASK_NORMAL, system, task);
}

void BattleAnimSystem_DestroySoundTask(BattleAnimSystem *system, SysTask *task) {
    BattleAnimSystem_DestroyTaskOfKind(BATTLE_ANIM_TASK_SOUND, system, task);
}

u16 BattleAnimSystem_GetAttacker(BattleAnimSystem *system) {
    return system->context->attacker;
}

u16 BattleAnimSystem_GetDefender(BattleAnimSystem *system) {
    return system->context->defender;
}

SPLEmitter *BattleAnimSystem_GetCurrentParticleSystem(BattleAnimSystem *system) {
    BattleAnimContext *context = system->context;
    return context->particleSystems[context->currentParticleSystem];
}

SPLEmitter *BattleAnimSystem_GetParticleSystem(BattleAnimSystem *system, int index) {
    return system->context->particleSystems[index];
}

SPLEmitter *BattleAnimSystem_GetEmitter(BattleAnimSystem *system, int index) {
    return system->context->emitters[index];
}

BgConfig *BattleAnimSystem_GetBgConfig(BattleAnimSystem *system) {
    return system->bgConfig;
}

u32 BattleAnimSystem_GetArg(BattleAnimSystem *system, int index) {
    GF_ASSERT(index < 10);
    return system->args[index];
}

ManagedSprite *BattleAnimSystem_GetSprite(BattleAnimSystem *system, int index) {
    GF_ASSERT(index < 10);
    GF_ASSERT(system != NULL);
    GF_ASSERT(system->sprites[index] != NULL);
    return system->sprites[index];
}

ManagedSprite *BattleAnimSystem_GetBattlerSprite(BattleAnimSystem *system, int index) {
    GF_ASSERT(index < 5);
    GF_ASSERT(system != NULL);
    GF_ASSERT(system->battlerSprites[index] != NULL);
    return system->battlerSprites[index];
}

SpriteManager *BattleAnimSystem_GetBattlerSpriteManager(BattleAnimSystem *system) {
    GF_ASSERT(system != NULL);
    return system->battlerSpriteManager;
}

SpriteManager *BattleAnimSystem_GetFirstSpriteManager(BattleAnimSystem *system) {
    return system->spriteManagers[0];
}

SpriteSystem *BattleAnimSystem_GetSpriteSystem(BattleAnimSystem *system) {
    return system->context->spriteSystem;
}

static BattleAnimSoundTaskData *BattleAnimSystem_NewSoundTaskData(BattleAnimSystem *system) {
    BattleAnimSoundTaskData *data = Heap_Alloc(system->heapId, sizeof(BattleAnimSoundTaskData));
    if (data == NULL) {
        GF_ASSERT(FALSE);
        return NULL;
    }
    memset(data, 0, sizeof(BattleAnimSoundTaskData));
    system->soundTaskCount++;
    return data;
}

static void BattleAnimSystem_StartSoundTask(BattleAnimSystem *system, BattleAnimSoundTaskData *data) {
    data->system = system;
    SysTask_CreateOnMainQueue((SysTaskFunc)BattleAnimTask_Sound, data, 1100);
}

static void BattleAnimTask_Sound(SysTask *task, BattleAnimSoundTaskData *data) {
    if (!sBattleAnimSoundFuncs[data->kind](data)) {
        BattleAnimSystem *system = data->system;
        if (system->soundTaskCount != 0) {
            system->soundTaskCount--;
        }
        Heap_Free(data);
        SysTask_Destroy(task);
    }
}

static BOOL BattleAnimSoundFunc_None(BattleAnimSoundTaskData *data) {
    return FALSE;
}

static BOOL BattleAnimSoundFunc_PanSweep(BattleAnimSoundTaskData *data) {
    BOOL result;
    if (data->counter++ < data->interval) {
        return TRUE;
    }
    data->counter = 0;
    data->pan += data->panStep;
    result = TRUE;
    if (data->panStep == 0) {
        result = FALSE;
    } else if (data->startPan < data->endPan) {
        if (data->pan >= data->endPan) {
            result = FALSE;
        }
    } else {
        if (data->pan <= data->endPan) {
            result = FALSE;
        }
    }
    SetAllSEPan(data->pan);
    if (!IsSEPlaying(data->seqNo)) {
        result = FALSE;
    }
    return result;
}

static BOOL BattleAnimSoundFunc_PanSweep2(BattleAnimSoundTaskData *data) {
    return BattleAnimSoundFunc_PanSweep(data);
}

static BOOL BattleAnimSoundFunc_PanSweep3(BattleAnimSoundTaskData *data) {
    return BattleAnimSoundFunc_PanSweep(data);
}

static BOOL BattleAnimSoundFunc_RepeatSE(BattleAnimSoundTaskData *data) {
    BOOL result;
    if (data->counter++ < data->interval) {
        return TRUE;
    }
    data->counter = 0;
    result = TRUE;
    data->repeatCount--;
    PlaySE(data->seqNo);
    SetSeqTrackPan(data->seqNo, 0xFFFF, data->pan);
    if (data->repeatCount == 0) {
        result = FALSE;
    }
    return result;
}

static BOOL BattleAnimSoundFunc_DelayedSE(BattleAnimSoundTaskData *data) {
    BOOL result = TRUE;
    if (data->interval-- == 0) {
        PlaySE(data->seqNo);
        SetSeqTrackPan(data->seqNo, 0xFFFF, data->pan);
        result = FALSE;
    }
    return result;
}

void BattleAnimSystem_InitBlend(void) {
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ | GX_BLEND_PLANEMASK_BD, 8, 8);
}

static void BattleAnimScriptCmd_WaitForButtonCombo(BattleAnimSystem *system) {
    system->delay = 1;
    if ((gSystem.heldKeys & PAD_BUTTON_L) && (gSystem.heldKeys & PAD_BUTTON_R) && (gSystem.newKeys & PAD_BUTTON_X)) {
        system->scriptPtr++;
        system->delay = 0;
    }
}

static void BattleAnimScriptCmd_Wait(BattleAnimSystem *system) {
    system->scriptPtr++;
    system->delay = *system->scriptPtr;
    system->scriptPtr++;
    system->runner = BattleAnimSystem_WaitDelay;
}

static void BattleAnimScriptCmd_WaitForTasks(BattleAnimSystem *system) {
    if (system->taskCount == 0) {
        system->scriptPtr++;
        system->delay = 0;
    } else {
        system->delay = 1;
    }
}

static void BattleAnimScriptCmd_SetArg(BattleAnimSystem *system) {
    u32 index, value;
    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    value = *system->scriptPtr;
    system->scriptPtr++;
    if (index < 10) {
        system->args[index] = value;
    }
}

static void BattleAnimScriptCmd_ClearArgs(BattleAnimSystem *system) {
    int i;
    system->scriptPtr++;
    for (i = 0; i < 10; i++) {
        system->args[i] = 0;
    }
}

u32 BattleAnimSystem_GetMoveParam(BattleAnimSystem *system, u32 param) {
    switch (param) {
    case 0:
        return system->context->damage;
    case 1:
        return system->context->power;
    case 2:
        return system->context->friendship;
    case 3:
        return system->context->fieldCondition;
    case 4:
        return system->context->moveAnimVariant;
    case 5:
        return system->context->terrain;
    default:
        return 0;
    }
}

void BattleAnimSystem_BuildBattlerPicParams(BattleAnimSystem *system, BattleAnimBattlerPicParams *params, u32 mode) {
    int i;
    for (i = 0; i < 4; i++) {
        params->picData[i] = system->context->picData[i];
        params->pokepics[i] = system->context->pokepics[i];
        params->species[i] = system->context->species[i];
        params->genders[i] = system->context->genders[i];
        params->shiny[i] = system->context->shiny[i];
        params->forms[i] = system->context->forms[i];
        params->personalities[i] = system->context->personalities[i];
        params->battlerTypes[i] = system->context->battlerTypes[i];
    }
    switch (mode) {
    case 0:
        params->battler = system->context->attacker;
        params->sourceBattler = system->context->defender;
        break;
    case 1:
        params->battler = system->context->attacker;
        params->sourceBattler = system->context->attacker;
        break;
    case 2:
        params->battler = system->context->attacker;
        params->sourceBattler = system->context->attacker;
        break;
    case 3:
        params->battler = system->context->attacker;
        params->sourceBattler = system->context->attacker;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

static void BattleAnimScriptCmd_ChangeBattlerPic(BattleAnimSystem *system) {
    u32 mode;
    BattleAnimBattlerPicParams params;
    system->scriptPtr++;
    mode = *system->scriptPtr;
    system->scriptPtr++;
    BattleAnimSystem_BuildBattlerPicParams(system, &params, mode);
    if (mode == 2) {
        BattleAnimUtil_LoadSubstituteIntoPic(&params, system->heapId);
    } else if (mode == 3) {
        BattleAnimUtil_LoadMonIntoPicOppositeFacing(&params, system->heapId);
    } else {
        BattleAnimUtil_LoadMonIntoPicSameFacing(&params, system->heapId);
    }
}

static void BattleAnimScriptCmd_RestoreBattlerPic(BattleAnimSystem *system) {
    u32 mode;
    BattleAnimBattlerPicParams params;
    system->scriptPtr++;
    mode = *system->scriptPtr;
    system->scriptPtr++;
    BattleAnimSystem_BuildBattlerPicParams(system, &params, mode);
    BattleAnimUtil_RestorePic(&params, system->heapId);
}

static void BattleAnimScriptCmd_BeginLoop(BattleAnimSystem *system) {
    int i;
    system->scriptPtr++;
    for (i = 0; i < 3; i++) {
        if (system->loops[i].active != TRUE) {
            system->loops[i].active = TRUE;
            system->loops[i].counter = 0;
            system->loops[i].count = *system->scriptPtr;
            system->scriptPtr++;
            system->loops[i].start = system->scriptPtr;
            return;
        }
    }
}

static void BattleAnimScriptCmd_EndLoop(BattleAnimSystem *system) {
    int i;
    system->scriptPtr++;
    for (i = 2; i >= 0; i--) {
        if (system->loops[i].active) {
            system->loops[i].counter++;
            if (system->loops[i].counter == system->loops[i].count) {
                system->loops[i].active = FALSE;
            } else {
                system->scriptPtr = system->loops[i].start;
            }
            return;
        }
    }
}

static void BattleAnimScriptCmd_End(BattleAnimSystem *system) {
    int i;
    int activeParticles = 0;

    if (system->endPhase < 1) {
        system->delay = 1;
        system->endPhase++;
        return;
    }
    for (i = 0; i < 16; i++) {
        if (system->context->particleSystems[i] != NULL) {
            activeParticles += ParticleSystem_GetActiveEmitterCount(system->context->particleSystems[i]);
        }
    }
    if (activeParticles != 0 || system->taskCount != 0 || system->soundTaskCount != 0) {
        system->delay = 1;
        system->seWaitTimer = 0;
        return;
    }
    if (GF_IsAnySEPlaying()) {
        system->seWaitTimer++;
        if (system->seWaitTimer > 90) {
            system->seWaitTimer = 0;
            system->delay = 0;
        } else {
            system->delay = 1;
            return;
        }
    }
    system->seWaitTimer = 0;
    system->endPhase = 0;
    for (i = 0; i < 3; i++) {
        system->returnStack[i] = NULL;
    }
    for (i = 0; i < 3; i++) {
        system->loops[i].start = NULL;
        system->loops[i].counter = 0;
        system->loops[i].count = 0;
        system->loops[i].active = FALSE;
    }
    for (i = 0; i < 4; i++) {
        if (system->spriteManagers[i] != NULL) {
            SpriteSystem_FreeResourcesAndManager(system->context->spriteSystem, system->spriteManagers[i]);
        }
        system->spriteManagers[i] = NULL;
    }
    for (i = 0; i < 5; i++) {
        BattleAnimSystem_StopFollowTask(system, i);
    }
    for (i = 0; i < 16; i++) {
        if (system->context->particleSystems[i] != NULL) {
            BattleAnimSystem_FreeParticleSystem(system->context->particleSystems[i]);
            system->context->particleSystems[i] = NULL;
        }
    }
    BattleAnimSystem_StopBgEffects(system->bgEffects, 5);
    BattleSystem_SetDefaultBlend();
    BG_ClearCharDataRange(BattleAnimSystem_GetBgLayer(system, BATTLE_ANIM_BG_EFFECT), 0x4000, 0, BattleAnimSystem_GetHeapID(system));
    BgClearTilemapBufferAndCommit(BattleAnimSystem_GetBgConfig(system), BattleAnimSystem_GetBgLayer(system, BATTLE_ANIM_BG_EFFECT));
    ToggleBgLayer(GF_BG_LYR_MAIN_2, GF_PLANE_TOGGLE_ON);
    SetBgPriority(GF_BG_LYR_MAIN_0, system->bgPriorities[0]);
    SetBgPriority(GF_BG_LYR_MAIN_1, system->bgPriorities[1]);
    SetBgPriority(GF_BG_LYR_MAIN_2, system->bgPriorities[2]);
    SetBgPriority(GF_BG_LYR_MAIN_3, system->bgPriorities[3]);
    BgSetPosTextAndCommit(system->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(system->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, 0);
    BgSetPosTextAndCommit(system->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(system->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_Y, 0);
    system->active = FALSE;
}

static void BattleAnimScriptCmd_CreateEmitter(BattleAnimSystem *system) {
    int index;
    u32 resId, callback;
    VecFx32 vec;

    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    resId = *system->scriptPtr;
    system->scriptPtr++;
    callback = *system->scriptPtr;
    system->scriptPtr++;
    system->context->currentParticleSystem = index;
    if (system->particleFlipY[index]) {
        ParticleSystem_GetCameraUp(system->context->particleSystems[index], &vec);
        vec.y *= -1;
        ParticleSystem_SetCameraUp(system->context->particleSystems[index], &vec);
    }
    ParticleSystem_SetPerspectiveType(system->context->particleSystems[index], system->particlePerspective[index]);
    system->context->emitters[0] = BattleAnimSystem_CreateEmitter(system->context->particleSystems[index], resId, callback, system);
}

static void BattleAnimScriptCmd_CreateEmitterInSlot(BattleAnimSystem *system) {
    int index, slot;
    u32 resId, callback;
    VecFx32 vec;

    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    slot = *system->scriptPtr;
    system->scriptPtr++;
    resId = *system->scriptPtr;
    system->scriptPtr++;
    callback = *system->scriptPtr;
    system->scriptPtr++;
    system->context->currentParticleSystem = index;
    if (system->particleFlipY[index]) {
        ParticleSystem_GetCameraUp(system->context->particleSystems[index], &vec);
        vec.y *= -1;
        ParticleSystem_SetCameraUp(system->context->particleSystems[index], &vec);
    }
    ParticleSystem_SetPerspectiveType(system->context->particleSystems[index], system->particlePerspective[index]);
    system->context->emitters[slot] = BattleAnimSystem_CreateEmitter(system->context->particleSystems[index], resId, callback, system);
}

static int BattleAnimSystem_SelectEmitterOf6(BattleAnimSystem *system) {
    u32 table[6][6];
    int attacker, defender, attackerType, defenderType, ret;

    ARRAY_ASSIGN(table, sBattleAnimEmitterSelect6);
    attacker = BattleAnimSystem_GetAttacker(system);
    defender = BattleAnimSystem_GetDefender(system);
    attackerType = BattleAnimUtil_GetBattlerType(system, attacker);
    defenderType = BattleAnimUtil_GetBattlerType(system, defender);
    ret = table[attackerType][defenderType];
    GF_ASSERT(ret != 0xFF);
    return ret - 1;
}

static int BattleAnimSystem_SelectEmitterOf4(BattleAnimSystem *system) {
    u32 table[6][6];
    int attacker, defender, attackerType, defenderType, ret;

    ARRAY_ASSIGN(table, sBattleAnimEmitterSelect4);
    attacker = BattleAnimSystem_GetAttacker(system);
    defender = BattleAnimSystem_GetDefender(system);
    attackerType = BattleAnimUtil_GetBattlerType(system, attacker);
    defenderType = BattleAnimUtil_GetBattlerType(system, defender);
    ret = table[attackerType][defenderType];
    GF_ASSERT(ret != 0xFF);
    return ret;
}

static void BattleAnimScriptCmd_CreateEmitterByPosition6(BattleAnimSystem *system) {
    int index, select, i;
    u32 resIds[6], callback;
    VecFx32 vec;

    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    for (i = 0; i < 6; i++) {
        resIds[i] = *system->scriptPtr;
        system->scriptPtr++;
    }
    callback = *system->scriptPtr;
    system->scriptPtr++;
    system->context->currentParticleSystem = index;
    if (system->particleFlipY[index]) {
        ParticleSystem_GetCameraUp(system->context->particleSystems[index], &vec);
        vec.y *= -1;
        ParticleSystem_SetCameraUp(system->context->particleSystems[index], &vec);
    }
    select = BattleAnimSystem_SelectEmitterOf6(system);
    ParticleSystem_SetPerspectiveType(system->context->particleSystems[index], system->particlePerspective[index]);
    system->context->emitters[0] = BattleAnimSystem_CreateEmitter(system->context->particleSystems[index], resIds[select], callback, system);
}

static void BattleAnimScriptCmd_CreateEmitterByPosition4(BattleAnimSystem *system) {
    int index, select, i;
    u32 resIds[4], callback;
    VecFx32 vec;

    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    for (i = 0; i < 4; i++) {
        resIds[i] = *system->scriptPtr;
        system->scriptPtr++;
    }
    callback = *system->scriptPtr;
    system->scriptPtr++;
    system->context->currentParticleSystem = index;
    if (system->particleFlipY[index]) {
        ParticleSystem_GetCameraUp(system->context->particleSystems[index], &vec);
        vec.y *= -1;
        ParticleSystem_SetCameraUp(system->context->particleSystems[index], &vec);
    }
    select = BattleAnimSystem_SelectEmitterOf4(system);
    ParticleSystem_SetPerspectiveType(system->context->particleSystems[index], system->particlePerspective[index]);
    system->context->emitters[0] = BattleAnimSystem_CreateEmitter(system->context->particleSystems[index], resIds[select], callback, system);
}

static void BattleAnimScriptCmd_WaitForParticles(BattleAnimSystem *system) {
    int activeParticles = 0;
    int i;
    for (i = 0; i < 16; i++) {
        if (system->context->particleSystems[i] != NULL) {
            activeParticles += ParticleSystem_GetActiveEmitterCount(system->context->particleSystems[i]);
        }
    }
    if (activeParticles == 0) {
        system->scriptPtr++;
        system->delay = 0;
    } else {
        system->delay = 1;
    }
}

static void BattleAnimScriptCmd_LoadParticleSystem(BattleAnimSystem *system) {
    u32 index;
    SPLEmitter *particleSystem;
    u32 resId;
    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    GF_ASSERT(system->context->particleSystems[index] == NULL);
    resId = *system->scriptPtr;
    system->scriptPtr++;
    particleSystem = BattleAnimSystem_NewParticleSystem(system->heapId, resId, FALSE);
    system->context->particleSystems[index] = particleSystem;
    system->delay = 2;
    system->runner = BattleAnimSystem_WaitDelay;
}

static void BattleAnimScriptCmd_LoadParticleSystemEx(BattleAnimSystem *system) {
    u32 index;
    SPLEmitter *particleSystem;
    u32 resId;
    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    system->scriptPtr++;
    GF_ASSERT(system->context->particleSystems[index] == NULL);
    resId = *system->scriptPtr;
    system->scriptPtr++;
    particleSystem = BattleAnimSystem_NewParticleSystemFromNarc(system->heapId, NARC_a_0_9_6, resId, FALSE);
    system->context->particleSystems[index] = particleSystem;
    system->delay = 2;
    system->runner = BattleAnimSystem_WaitDelay;
}

static void BattleAnimScriptCmd_FreeParticleSystem(BattleAnimSystem *system) {
    u32 index;
    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    BattleAnimSystem_FreeParticleSystem(system->context->particleSystems[index]);
    system->context->particleSystems[index] = NULL;
}

static void BattleAnimScriptCmd_Call(BattleAnimSystem *system) {
    int i;
    system->scriptPtr++;
    for (i = 0; i < 3; i++) {
        if (system->returnStack[i] == NULL) {
            system->returnStack[i] = system->scriptPtr + 1;
            system->scriptPtr += *system->scriptPtr;
            return;
        }
    }
}

static void BattleAnimScriptCmd_Return(BattleAnimSystem *system) {
    int i;
    system->scriptPtr++;
    for (i = 2; i >= 0; i--) {
        if (system->returnStack[i] != NULL) {
            system->scriptPtr = system->returnStack[i];
            system->returnStack[i] = NULL;
            return;
        }
    }
}

static void BattleAnimScriptCmd_JumpIfArgEqual(BattleAnimSystem *system) {
    u32 index, value;
    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    value = *system->scriptPtr;
    system->scriptPtr++;
    if (value == system->args[index]) {
        system->scriptPtr = (u32 *)*system->scriptPtr;
    } else {
        system->scriptPtr++;
    }
}

static void BattleAnimScriptCmd_JumpIfContextField01(BattleAnimSystem *system) {
    system->scriptPtr++;
    if (BattleAnimContext_GetField01(system->context)) {
        system->scriptPtr = (u32 *)*system->scriptPtr;
    } else {
        system->scriptPtr++;
    }
}

static void BattleAnimScriptCmd_CallFunc(BattleAnimSystem *system) {
    BattleAnimFunc func;
    int i;
    u32 count;
    u32 funcId;

    system->scriptPtr++;
    funcId = *system->scriptPtr;
    system->scriptPtr++;
    func = BattleAnimSystem_GetFunc(funcId);
    count = *system->scriptPtr;
    system->scriptPtr++;
    for (i = 0; i < count; i++) {
        system->args[i] = *system->scriptPtr;
        system->scriptPtr++;
    }
    for (; i < 10; i++) {
        system->args[i] = 0;
    }
    func(system);
}

static void BattleAnimScriptCmd_JumpByVariantBit0(BattleAnimSystem *system) {
    system->scriptPtr++;
    if (system->context->moveAnimVariant & 1) {
        system->scriptPtr++;
    }
    system->scriptPtr += *system->scriptPtr;
}

static void BattleAnimScriptCmd_JumpBySide(BattleAnimSystem *system) {
    u32 role;
    int side;
    system->scriptPtr++;
    role = *system->scriptPtr;
    system->scriptPtr++;
    if (role == 0) {
        side = BattleAnimUtil_GetBattlerSide(system, system->context->attacker);
    } else {
        side = BattleAnimUtil_GetBattlerSide(system, system->context->defender);
    }
    if (side == BATTLE_ANIM_SIDE_ENEMY) {
        system->scriptPtr++;
    }
    system->scriptPtr += *system->scriptPtr;
}

static void BattleAnimScriptCmd_JumpByWeather(BattleAnimSystem *system) {
    u32 masks[4];
    u32 fieldCondition, i;

    ARRAY_ASSIGN(masks, sBattleAnimWeatherMasks);
    system->scriptPtr++;
    fieldCondition = system->context->fieldCondition;
    if (fieldCondition != 0) {
        system->scriptPtr++;
        for (i = 0; i < 4; i++) {
            if (masks[i] & fieldCondition) {
                break;
            }
            system->scriptPtr++;
        }
    }
    system->scriptPtr += *system->scriptPtr;
}

static void BattleAnimScriptCmd_JumpIfContest(BattleAnimSystem *system) {
    system->scriptPtr++;
    if (BattleAnimSystem_IsContest(system) == TRUE) {
        system->scriptPtr += *system->scriptPtr;
    } else {
        system->scriptPtr++;
    }
}

static void BattleAnimScriptCmd_JumpIfAttackerActive(BattleAnimSystem *system) {
    system->scriptPtr++;
    if (system->context->attackerActive) {
        system->scriptPtr += *system->scriptPtr;
    } else {
        system->scriptPtr++;
    }
}

static void BattleAnimScriptCmd_JumpIfSameSide(BattleAnimSystem *system) {
    int attackerSide, defenderSide;
    system->scriptPtr++;
    attackerSide = BattleAnimUtil_GetBattlerSide(system, system->context->attacker);
    defenderSide = BattleAnimUtil_GetBattlerSide(system, system->context->defender);
    if (attackerSide == defenderSide) {
        system->scriptPtr += *system->scriptPtr;
    } else {
        system->scriptPtr++;
    }
}

static void BattleAnimScriptCmd_JumpIfVariantEqual(BattleAnimSystem *system) {
    u32 value;
    system->scriptPtr++;
    value = *system->scriptPtr;
    system->scriptPtr++;
    if (value == system->context->moveAnimVariant) {
        system->scriptPtr += *system->scriptPtr;
    } else {
        system->scriptPtr++;
    }
}

static void BattleAnimScriptCmd_Jump(BattleAnimSystem *system) {
    system->scriptPtr++;
    system->scriptPtr += *system->scriptPtr;
}

static void BattleAnimSystem_StartBrightnessFade(BattleAnimBrightnessFlashWork *work, BOOL fadeIn) {
    if (fadeIn) {
        StartBrightnessTransition((u8)work->steps, 16, 0, (GXBlendPlaneMask)(GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ | GX_BLEND_PLANEMASK_BD), SCREEN_MASK_MAIN);
    } else {
        StartBrightnessTransition((u8)work->steps, 0, 16, (GXBlendPlaneMask)(GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ | GX_BLEND_PLANEMASK_BD), SCREEN_MASK_MAIN);
    }
}

static void BattleAnimTask_BrightnessFlash(SysTask *task, BattleAnimBrightnessFlashWork *work) {
    DoAllScreenBrightnessTransitionStep();
    if (IsBrightnessTransitionActive(SCREEN_MASK_MAIN)) {
        if (work->fadingBack) {
            Heap_Free(work);
            SysTask_Destroy(task);
            BattleAnimSystem_InitBlend();
        } else {
            BattleAnimSystem_StartBrightnessFade(work, FALSE);
            work->fadingBack = TRUE;
        }
    }
}

static void BattleAnimScriptCmd_BrightnessFlash(BattleAnimSystem *system) {
    BattleAnimBrightnessFlashWork *work = Heap_Alloc(system->heapId, sizeof(BattleAnimBrightnessFlashWork));
    MI_CpuFill8(work, 0, sizeof(BattleAnimBrightnessFlashWork));
    work->system = system;
    system->scriptPtr++;
    work->steps = (u8)*system->scriptPtr;
    system->scriptPtr++;
    ScreenBrightnessData_InitAll();
    BattleAnimSystem_StartBrightnessFade(work, TRUE);
    SysTask_CreateOnMainQueue((SysTaskFunc)BattleAnimTask_BrightnessFlash, work, 0x1001);
}

static int BattleAnimSystem_GetBattlerByRole(BattleAnimSystem *system, u32 role) {
    int battler;
    int i;
    switch (role) {
    case 0:
        battler = system->context->attacker;
        break;
    case 1:
        battler = system->context->defender;
        break;
    case 2:
        battler = BattleAnimUtil_GetPartnerBattler(system, system->context->attacker);
        break;
    case 3:
        battler = BattleAnimUtil_GetPartnerBattler(system, system->context->defender);
        break;
    case 4:
        battler = 0xFF;
        for (i = 0; i < BATTLER_MAX; i++) {
            int type = BattleAnimSystem_GetBattlerType(system, i);
            if (type == BATTLER_TYPE_SOLO_PLAYER || type == BATTLER_TYPE_PLAYER_SIDE_SLOT_1) {
                battler = i;
                break;
            }
        }
        if (battler == 0xFF) {
            battler = 0;
        }
        break;
    case 5:
        battler = 0xFF;
        for (i = 0; i < BATTLER_MAX; i++) {
            int type = BattleAnimSystem_GetBattlerType(system, i);
            if (type == BATTLER_TYPE_SOLO_ENEMY || type == BATTLER_TYPE_ENEMY_SIDE_SLOT_1) {
                battler = i;
                break;
            }
        }
        if (battler == 0xFF) {
            battler = 0;
        }
        break;
    case 6:
        battler = 0xFF;
        for (i = 0; i < BATTLER_MAX; i++) {
            if (BattleAnimSystem_GetBattlerType(system, i) == BATTLER_TYPE_PLAYER_SIDE_SLOT_2) {
                battler = i;
                break;
            }
        }
        if (battler == 0xFF) {
            battler = 0;
        }
        break;
    case 7:
        battler = 0xFF;
        for (i = 0; i < BATTLER_MAX; i++) {
            if (BattleAnimSystem_GetBattlerType(system, i) == BATTLER_TYPE_ENEMY_SIDE_SLOT_2) {
                battler = i;
                break;
            }
        }
        if (battler == 0xFF) {
            battler = 0;
        }
        break;
    }
    return battler;
}

static void BattleAnimTask_SpriteFollowBattler(SysTask *task, void *data) {
    BattleAnimFollowWork *work = data;
    s16 x, y;
    if (work->interval != 0) {
        work->counter++;
        if (work->counter != work->interval) {
            return;
        }
        work->counter = 0;
    }
    x = Pokepic_GetAttr(work->pokepic, POKEPIC_X);
    y = Pokepic_GetAttr(work->pokepic, POKEPIC_Y);
    y -= Pokepic_GetAttr(work->pokepic, POKEPIC_SHADOW_H);
    ManagedSprite_SetPositionXY(work->target, x, y);
}

static void BattleAnimTask_BgFollowBattler(SysTask *task, void *data) {
    BattleAnimFollowWork *work = data;
    s16 x, y;
    if (work->interval != 0) {
        work->counter++;
        if (work->counter != work->interval) {
            return;
        }
        work->counter = 0;
    }
    x = Pokepic_GetAttr(work->pokepic, POKEPIC_X);
    y = Pokepic_GetAttr(work->pokepic, POKEPIC_Y);
    y -= Pokepic_GetAttr(work->pokepic, POKEPIC_SHADOW_H);
    BgSetPosTextAndCommit(work->target, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, -(x - 40));
    BgSetPosTextAndCommit(work->target, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, -(y - 40));
}

// index 4 stops the BG2 battler copy (slot 5)
static void BattleAnimSystem_StopFollowTask(BattleAnimSystem *system, u32 index) {
    if (index == 4) {
        if (system->followWorks[5] != NULL) {
            SysTask_Destroy(system->followWorks[5]->task);
            Heap_Free(system->followWorks[5]);
            system->followWorks[5] = NULL;
        }
    } else {
        if (system->followWorks[index] != NULL) {
            SysTask_Destroy(system->followWorks[index]->task);
            Heap_Free(system->followWorks[index]);
            system->followWorks[index] = NULL;
        }
    }
}

static void BattleAnimScriptCmd_Nop6(BattleAnimSystem *system) {
}

static void BattleAnimScriptCmd_Nop7(BattleAnimSystem *system) {
}

static void BattleAnimScriptCmd_CopyBattlerToBg(BattleAnimSystem *system) {
    u32 role, follow;
    int battler;
    u8 *tiles;
    NarcId paletteNarc;
    int paletteMember;
    s16 x, y;

    system->scriptPtr++;
    role = *system->scriptPtr;
    system->scriptPtr++;
    follow = *system->scriptPtr;
    system->scriptPtr++;
    battler = BattleAnimSystem_GetBattlerByRole(system, role);
    tiles = system->context->picData[battler]->charBuffer;
    paletteNarc = (NarcId)system->context->picData[battler]->narcId;
    paletteMember = system->context->picData[battler]->paletteId;
    MI_CpuFill8(BgGetCharPtr(GF_BG_LYR_MAIN_2), 0, 0x1900);
    ToggleBgLayer(GF_BG_LYR_MAIN_2, GF_PLANE_TOGGLE_OFF);
    BG_LoadCharTilesData(system->bgConfig, GF_BG_LYR_MAIN_2, tiles, 0xC80, 0);
    PaletteData_LoadNarc(system->paletteData, paletteNarc, paletteMember, system->heapId, PLTTBUF_MAIN_BG, 0, 0x80);
    GfGfxLoader_LoadScrnDataFromOpenNarc(system->narcs[0], 268, system->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, FALSE, system->heapId);
    if (follow == TRUE) {
        system->followWorks[5] = Heap_Alloc(system->heapId, sizeof(BattleAnimFollowWork));
        system->followWorks[5]->target = system->bgConfig;
        system->followWorks[5]->pokepic = BattleAnimSystem_GetBattlerPokepic(system, battler);
        system->followWorks[5]->counter = 0;
        system->followWorks[5]->interval = 0;
        system->followWorks[5]->task = SysTask_CreateOnMainQueue(BattleAnimTask_BgFollowBattler, system->followWorks[5], 0x1001);
    }
    x = Pokepic_GetAttr(BattleAnimSystem_GetBattlerPokepic(system, battler), POKEPIC_X);
    y = Pokepic_GetAttr(BattleAnimSystem_GetBattlerPokepic(system, battler), POKEPIC_Y);
    y -= Pokepic_GetAttr(BattleAnimSystem_GetBattlerPokepic(system, battler), POKEPIC_SHADOW_H);
    BgSetPosTextAndCommit(system->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, -(x - 40));
    BgSetPosTextAndCommit(system->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, -(y - 40));
    ToggleBgLayer(GF_BG_LYR_MAIN_2, GF_PLANE_TOGGLE_ON);
    SetBgPriority(GF_BG_LYR_MAIN_2, (u8)BattleAnimSystem_GetBasePriority(system));
}

static void BattleAnimScriptCmd_ClearBattlerBg(BattleAnimSystem *system) {
    system->scriptPtr++;
    system->scriptPtr++; // unused argument
    MI_CpuFill8(BgGetCharPtr(GF_BG_LYR_MAIN_2), 0, 0x1900);
    BattleAnimSystem_StopFollowTask(system, 4);
}

static void BattleAnimScriptCmd_InitBattlerSpriteManager(BattleAnimSystem *system) {
    SpriteResourceCountsListUnion capacities = sBattleAnimBattlerSpriteCapacities;
    system->scriptPtr++;
    system->battlerSpriteManager = SpriteManager_New(system->context->spriteSystem);
    SpriteSystem_InitSprites(system->context->spriteSystem, system->battlerSpriteManager, 5);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(system->context->spriteSystem), 0, FX32_CONST(272));
    SpriteSystem_InitManagerWithCapacities(system->context->spriteSystem, system->battlerSpriteManager, &capacities);
}

static void BattleAnimScriptCmd_LoadBattlerSpriteResources(BattleAnimSystem *system) {
    u32 index;
    u32 resId;
    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    resId = index + 20001 + system->context->attacker * 5000;
    SpriteSystem_LoadCharResObjFromOpenNarc(system->context->spriteSystem, system->battlerSpriteManager, system->narcs[1], 76, FALSE, 1, resId);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(system->paletteData, PLTTBUF_MAIN_OBJ, system->context->spriteSystem, system->battlerSpriteManager, system->narcs[1], 75, FALSE, 1, 1, resId);
    SpriteSystem_LoadCellResObjFromOpenNarc(system->context->spriteSystem, system->battlerSpriteManager, system->narcs[1], 77, FALSE, resId);
    SpriteSystem_LoadAnimResObjFromOpenNarc(system->context->spriteSystem, system->battlerSpriteManager, system->narcs[1], 78, FALSE, resId);
}

static inline u32 ReadScriptWord(BattleAnimSystem *system) {
    u32 *ptr = system->scriptPtr;
    u32 value = *ptr;
    system->scriptPtr = ptr + 1;
    return value;
}

static void BattleAnimScriptCmd_CreateBattlerSprite(BattleAnimSystem *system) {
    u8 *pixels;
    u32 role, follow, slot, resId;
    int battler;
    u32 resIds[6];
    ManagedSpriteTemplate template;
    Pokepic *pokepic;
    ManagedSprite *sprite;
    MonPicData *picData;
    u32 paletteNarc, paletteMember;
    s16 x, y;
    int i;

    system->scriptPtr++;
    role = ReadScriptWord(system);
    follow = ReadScriptWord(system);
    slot = ReadScriptWord(system);
    resId = ReadScriptWord(system);
    resIds[0] = resId + 20001 + 5000 * system->context->attacker;
    resIds[1] = resId + 20001 + 5000 * system->context->attacker;
    resIds[2] = resId + 20001 + 5000 * system->context->attacker;
    resIds[3] = resId + 20001 + 5000 * system->context->attacker;
    resIds[4] = 0;
    resIds[5] = 0;
    battler = BattleAnimSystem_GetBattlerByRole(system, role);
    picData = system->context->picData[battler];
    paletteNarc = picData->narcId;
    paletteMember = picData->paletteId;
    pixels = picData->charBuffer;
    pokepic = BattleAnimSystem_GetBattlerPokepic(system, battler);
    if (pokepic) {
        x = Pokepic_GetAttr(pokepic, POKEPIC_X);
        y = Pokepic_GetAttr(pokepic, POKEPIC_Y);
        y -= Pokepic_GetAttr(pokepic, POKEPIC_SHADOW_H);
    }
    template.x = x;
    template.y = y;
    template.z = 0;
    template.animation = 0;
    template.drawPriority = 100;
    template.pal = 0;
    template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.bgPriority = 1;
    template.vramTransfer = FALSE;
    for (i = 0; i < 6; i++) {
        template.resIdList[i] = resIds[i];
    }
    sprite = SpriteSystem_NewSprite(system->context->spriteSystem, system->battlerSpriteManager, &template);
    if (!pokepic) {
        ManagedSprite_SetDrawFlag(sprite, FALSE);
    } else if (Pokepic_GetAttr(pokepic, POKEPIC_VANISHED) == TRUE) {
        ManagedSprite_SetDrawFlag(sprite, FALSE);
    }
    if (BattleAnimSystem_GetBattlerPokepic(system, battler)) {
        NNSG2dImageProxy *proxy = Sprite_GetImageProxy(sprite->sprite);
        GF_CreateNewVramTransferTask(NNS_GFD_DST_2D_OBJ_CHAR_MAIN, proxy->vramLocation.baseAddrOfVram[NNS_G2D_VRAM_TYPE_2DMAIN], pixels, 3200);
    }
    if (BattleAnimSystem_GetBattlerPokepic(system, battler)) {
        u32 offset = ObjPlttTransfer_GetPaletteVramOffset(Sprite_GetPaletteProxy(sprite->sprite), NNS_G2D_VRAM_TYPE_2DMAIN);
        PaletteData_LoadNarc(system->paletteData, (NarcId)paletteNarc, paletteMember, system->heapId, PLTTBUF_MAIN_OBJ, 32, offset * 16);
    }
    GF_ASSERT(system->battlerSprites[slot] == NULL);
    system->battlerSprites[slot] = sprite;
    system->battlerSpriteActive[slot] = TRUE;
    if (follow == TRUE && BattleAnimSystem_GetBattlerPokepic(system, battler)) {
        system->followWorks[slot] = Heap_Alloc(system->heapId, sizeof(BattleAnimFollowWork));
        system->followWorks[slot]->target = sprite;
        system->followWorks[slot]->pokepic = BattleAnimSystem_GetBattlerPokepic(system, battler);
        system->followWorks[slot]->counter = 0;
        system->followWorks[slot]->interval = 0;
        system->followWorks[slot]->task = SysTask_CreateOnMainQueue(BattleAnimTask_SpriteFollowBattler, system->followWorks[slot], 0x1001);
    }
}

static void BattleAnimScriptCmd_FreeBattlerSpriteManager(BattleAnimSystem *system) {
    SpriteManager *manager;
    system->scriptPtr++;
    manager = system->battlerSpriteManager;
    if (manager != NULL) {
        SpriteSystem_FreeResourcesAndManager(system->context->spriteSystem, manager);
    }
    system->battlerSpriteManager = NULL;
}

static void BattleAnimScriptCmd_DeleteBattlerSprite(BattleAnimSystem *system) {
    u32 index;
    ManagedSprite **sprites;
    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    sprites = system->battlerSprites;
    if (sprites[index] != NULL) {
        Sprite_DeleteAndFreeResources(sprites[index]);
    }
    system->battlerSpriteActive[index] = FALSE;
    sprites[index] = NULL;
}

static void BattleAnimTask_DrawBattlerSprites(SysTask *task, void *data) {
    BattleAnimBattlerSpriteDraw *draw = data;
    if (!draw->active) {
        SysTask_Destroy(task);
        return;
    }
    if (draw->system->battlerSpriteManager != NULL) {
        SpriteSystem_DrawSprites(draw->manager);
    }
}

static void BattleAnimScriptCmd_StartBattlerSpriteDraw(BattleAnimSystem *system) {
    int attackerType, role, index, slot, defenderType, vanished;
    Pokepic *pokepic;

    system->scriptPtr++;
    role = *system->scriptPtr;
    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    slot = *system->scriptPtr;
    system->scriptPtr++;
    system->battlerSpriteDraws[index].system = system;
    system->battlerSpriteDraws[index].manager = system->battlerSpriteManager;
    system->battlerSpriteDraws[index].sprite = system->battlerSprites[slot];
    system->battlerSpriteDraws[index].active = TRUE;
    ManagedSprite_SetDrawFlag(system->battlerSpriteDraws[index].sprite, FALSE);
    if (BattleAnimSystem_IsDoubleBattle(system) == TRUE) {
        attackerType = BattleAnimUtil_GetBattlerType(system, BattleAnimSystem_GetAttacker(system));
        defenderType = BattleAnimUtil_GetBattlerType(system, BattleAnimSystem_GetDefender(system));
        pokepic = BattleAnimSystem_GetBattlerPokepic(system, BattleAnimSystem_GetBattlerByRole(system, role));
        vanished = pokepic ? Pokepic_GetAttr(pokepic, POKEPIC_VANISHED) : 0;
        if (vanished == TRUE) {
            ManagedSprite_SetDrawFlag(system->battlerSpriteDraws[index].sprite, FALSE);
        } else {
            ManagedSprite_SetDrawFlag(system->battlerSpriteDraws[index].sprite, TRUE);
        }
        switch (role) {
        case 0:
            if (attackerType == BATTLER_TYPE_ENEMY_SIDE_SLOT_1 || attackerType == BATTLER_TYPE_PLAYER_SIDE_SLOT_2) {
                ManagedSprite_SetDrawPriority(system->battlerSpriteDraws[index].sprite, 1);
            } else {
                ManagedSprite_SetDrawFlag(system->battlerSpriteDraws[index].sprite, FALSE);
                ManagedSprite_SetDrawPriority(system->battlerSpriteDraws[index].sprite, 255);
            }
            break;
        case 2:
            if (attackerType == BATTLER_TYPE_ENEMY_SIDE_SLOT_2 || attackerType == BATTLER_TYPE_PLAYER_SIDE_SLOT_1) {
                ManagedSprite_SetDrawPriority(system->battlerSpriteDraws[index].sprite, 1);
            } else {
                ManagedSprite_SetDrawFlag(system->battlerSpriteDraws[index].sprite, FALSE);
                ManagedSprite_SetDrawPriority(system->battlerSpriteDraws[index].sprite, 255);
            }
            break;
        case 1:
            switch (defenderType) {
            case BATTLER_TYPE_PLAYER_SIDE_SLOT_1:
                ManagedSprite_SetDrawPriority(system->battlerSpriteDraws[index].sprite, 255);
                break;
            case BATTLER_TYPE_ENEMY_SIDE_SLOT_1:
                ManagedSprite_SetDrawPriority(system->battlerSpriteDraws[index].sprite, 1);
                break;
            case BATTLER_TYPE_PLAYER_SIDE_SLOT_2:
                ManagedSprite_SetDrawPriority(system->battlerSpriteDraws[index].sprite, 1);
                break;
            case BATTLER_TYPE_ENEMY_SIDE_SLOT_2:
                ManagedSprite_SetDrawPriority(system->battlerSpriteDraws[index].sprite, 255);
                break;
            }
            break;
        case 3:
            switch (defenderType) {
            case BATTLER_TYPE_PLAYER_SIDE_SLOT_1:
                ManagedSprite_SetDrawPriority(system->battlerSpriteDraws[index].sprite, 1);
                break;
            case BATTLER_TYPE_ENEMY_SIDE_SLOT_1:
                ManagedSprite_SetDrawPriority(system->battlerSpriteDraws[index].sprite, 255);
                break;
            case BATTLER_TYPE_PLAYER_SIDE_SLOT_2:
                ManagedSprite_SetDrawPriority(system->battlerSpriteDraws[index].sprite, 255);
                break;
            case BATTLER_TYPE_ENEMY_SIDE_SLOT_2:
                ManagedSprite_SetDrawPriority(system->battlerSpriteDraws[index].sprite, 1);
                break;
            }
            break;
        }
        SysTask_CreateOnMainQueue(BattleAnimTask_DrawBattlerSprites, &system->battlerSpriteDraws[index], 0x1000);
    }
}

static void BattleAnimScriptCmd_StopBattlerSpriteDraw(BattleAnimSystem *system) {
    u32 index;
    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    system->battlerSpriteDraws[index].active = FALSE;
}

static void BattleAnimScriptCmd_StopFollowTask(BattleAnimSystem *system) {
    u32 index;
    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    BattleAnimSystem_StopFollowTask(system, index);
}

static void BattleAnimScriptCmd_SetParticlePerspective(BattleAnimSystem *system) {
    u32 index;
    u32 value;
    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    value = *system->scriptPtr;
    system->scriptPtr++;
    system->particlePerspective[index] = value;
}

static void BattleAnimScriptCmd_SetParticleFlipY(BattleAnimSystem *system) {
    u32 index;
    u32 value;
    system->scriptPtr++;
    index = *system->scriptPtr;
    system->scriptPtr++;
    value = *system->scriptPtr;
    system->scriptPtr++;
    system->particleFlipY[index] = value;
}

static void BattleAnimScriptCmd_Nop40(BattleAnimSystem *system) {
}

static void BattleAnimScriptCmd_Nop41(BattleAnimSystem *system) {
}

static void BattleAnimSystem_StopBgEffects(BattleAnimBgEffect **effects, int kind) {
    int i;
    for (i = 0; i < 4; i++, effects++) {
        BattleAnimBgEffect *effect = *effects;
        if (effect != NULL && (kind == 5 || kind == effect->kind)) {
            effect->stop = TRUE;
        }
    }
}

static void BattleAnimSystem_RegisterBgEffect(BattleAnimBgEffect **effects, void *effect, int kind) {
    u8 i;
    for (i = 0; i < 4; i++) {
        if (effects[i] != NULL) {
            GF_ASSERT(effects[i]->kind != kind);
        }
    }
    for (i = 0; i < 4; i++) {
        if (effects[i] == NULL) {
            effects[i] = effect;
            effects[i]->kind = kind;
            return;
        }
    }
    GF_ASSERT(gStr_HaikeiSubSystemLaunchLimit == NULL);
}

static void *BattleAnimSystem_FindBgEffect(BattleAnimBgEffect **effects, int kind) {
    u8 i;
    for (i = 0; i < 4; i++) {
        BattleAnimBgEffect *effect = effects[i];
        if (kind != effect->kind) {
            continue;
        }
        return effect;
    }
    return NULL;
}

static BOOL BattleAnimBackground_ShouldFlip(BattleAnimBgSwitchWork *work, BattleAnimSystem *system, int argIndex) {
    int attackerSide = BattleAnimUtil_GetBattlerSide(system, system->context->attacker);
    int defenderSide = BattleAnimUtil_GetBattlerSide(system, system->context->defender);
    int arg = work->args[argIndex];

    if (arg == 2) {
        if (attackerSide == defenderSide) {
            return defenderSide != BATTLE_ANIM_SIDE_PLAYER;
        }
        if (defenderSide == BATTLE_ANIM_SIDE_PLAYER) {
            return TRUE;
        }
    } else if (arg != 0 && defenderSide == BATTLE_ANIM_SIDE_PLAYER) {
        return TRUE;
    }
    return FALSE;
}

static void BattleAnimBackground_LoadGraphics(BattleAnimBgSwitchWork *work, BattleAnimSystem *system, GFBgLayer layer, u32 bgId) {
    int member;
    enum BattleAnimBgFile screen;

    member = BattleAnimSystem_GetBackgroundFile(bgId, BATTLE_ANIM_BG_FILE_CHAR);
    GfGfxLoader_LoadCharData(NARC_a_0_0_7, member, system->bgConfig, layer, 0, 0, TRUE, system->heapId);
    member = BattleAnimSystem_GetBackgroundFile(bgId, BATTLE_ANIM_BG_FILE_PALETTE);
    PaletteData_LoadNarc(system->paletteData, NARC_a_0_0_7, member, system->heapId, PLTTBUF_MAIN_BG, 0x20, 0x90);
    BgClearTilemapBufferAndCommit(system->bgConfig, layer);
    screen = BATTLE_ANIM_BG_FILE_SCREEN;
    if (BattleAnimSystem_IsContest(system) == TRUE) {
        screen = BATTLE_ANIM_BG_FILE_SCREEN_CONTEST;
    } else if (BattleAnimBackground_ShouldFlip(work, system, 7) == TRUE) {
        screen = BATTLE_ANIM_BG_FILE_SCREEN_FLIPPED;
    }
    member = BattleAnimSystem_GetBackgroundFile(bgId, screen);
    GfGfxLoader_LoadScrnData(NARC_a_0_0_7, member, system->bgConfig, layer, 0, 0, TRUE, system->heapId);
}

static BOOL BattleAnimBackground_HasEffectFlags(u32 flags, u32 mask) {
    return mask == (mask & (flags << 16));
}

static void BattleAnimBackground_StartEffects(BattleAnimBgSwitchWork *work) {
    u32 masks[6];
    u32 i;

    ARRAY_ASSIGN(masks, sBattleAnimBgEffectMasks);
    for (i = 0; i < 6; i++) {
        if (BattleAnimBackground_HasEffectFlags(work->effectFlags, masks[i])) {
            int bit = masks[i] >> 16;
            int index = 0;
            while (bit >= 2) {
                bit /= 2;
                index++;
            }
            sBattleAnimBgEffectFuncs[index](work);
        }
    }
}

static BattleAnimBgSwitchWork *BattleAnimBackground_NewSwitchWork(BattleAnimSystem *system) {
    BattleAnimBgSwitchWork *work = Heap_Alloc(system->heapId, sizeof(BattleAnimBgSwitchWork));
    int i;

    if (work == NULL) {
        GF_ASSERT(FALSE);
        return NULL;
    }
    memset(work, 0, sizeof(BattleAnimBgSwitchWork));
    work->unk_00 = 0;
    work->step = 0;
    work->restoreFadeWait = 0;
    work->switchFadeWait = 0;
    work->system = system;
    work->eva = 0;
    work->evb = 31;
    work->evaTarget = 29;
    work->evbTarget = 2;
    if ((s32)BattleAnimSystem_GetArg(system, 5) == 1) {
        work->eva = 0;
        work->evb = 31;
        work->evaTarget = 15;
        work->evbTarget = 7;
    }
    if ((s32)BattleAnimSystem_GetArg(system, 5) == 2) {
        work->eva = 7;
        work->evb = 15;
        work->evaTarget = 29;
        work->evbTarget = 2;
    }
    for (i = 0; i < 10; i++) {
        work->args[i] = system->args[i];
    }
    system->bgSwitchState = 1;
    return work;
}

#pragma push
#pragma opt_common_subs off

enum {
    BG_BLEND_IN_STEP_LOAD_BATTLE_BG,
    BG_BLEND_IN_STEP_LOAD_GRAPHICS,
    BG_BLEND_IN_STEP_BLEND,
};

static BOOL BattleAnimBackground_BlendIn(SysTask *task, BattleAnimBgSwitchWork *work) {
    int done;
    int priority;

    switch (work->step) {
    case BG_BLEND_IN_STEP_LOAD_BATTLE_BG:
        BattleAnimBackground_LoadBattleBgToLayerDefault(work->system, GF_BG_LYR_MAIN_2);
        priority = BattleAnimSystem_GetBgPriority(work->system, BATTLE_ANIM_BG_BATTLE);
        BattleAnimSystem_GetBgPriority(work->system, BATTLE_ANIM_BG_EFFECT);
        SetBgPriority(GF_BG_LYR_MAIN_3, (u8)priority);
        SetBgPriority(GF_BG_LYR_MAIN_2, (u8)priority);
        ToggleBgLayer(GF_BG_LYR_MAIN_2, GF_PLANE_TOGGLE_ON);
        work->step++;
        break;
    case BG_BLEND_IN_STEP_LOAD_GRAPHICS:
        SetBgControlParam(work->system->bgConfig, GF_BG_LYR_MAIN_3, GF_BG_CNT_SET_CHAR_BASE, GX_BG_CHARBASE_0x0c000);
        if (BattleAnimSystem_IsContest(work->system) != TRUE) {
            SetBgControlParam(work->system->bgConfig, GF_BG_LYR_MAIN_3, GF_BG_CNT_SET_COLOR_MODE, GX_BG_COLORMODE_16);
        }
        BattleAnimBackground_LoadGraphics(work, work->system, GF_BG_LYR_MAIN_3, work->bgId);
        G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG2, GX_BLEND_PLANEMASK_BG3, work->evb, work->eva);
        BattleAnimBackground_StartEffects(work);
        work->step++;
        // fallthrough
    case BG_BLEND_IN_STEP_BLEND:
        done = 0;
        if (work->eva < work->evaTarget) {
            work->eva += 2;
        } else {
            done++;
        }
        if (work->evb > work->evbTarget) {
            work->evb -= 2;
        } else {
            done++;
        }
        if (done == 2) {
            work->eva = work->evaTarget;
            work->evb = work->evbTarget;
            work->step++;
        }
        reg_G2_BLDALPHA = work->evb | (work->eva << 8);
        if (work->step == BG_BLEND_IN_STEP_BLEND) {
            break;
        }
        return FALSE;
    default:
        return FALSE;
    }
    return TRUE;
}

#pragma pop

enum {
    BG_BLEND_OUT_STEP_SHOW_LAYER,
    BG_BLEND_OUT_STEP_START_BLEND,
    BG_BLEND_OUT_STEP_BLEND,
    BG_BLEND_OUT_STEP_RESTORE_BATTLE_BG,
    BG_BLEND_OUT_STEP_RESET_LAYER,
};

static BOOL BattleAnimBackground_BlendOut(SysTask *task, BattleAnimBgSwitchWork *work) {
    int done;
    int priority3;
    int priority2;

    switch (work->step) {
    case BG_BLEND_OUT_STEP_SHOW_LAYER:
        ToggleBgLayer(GF_BG_LYR_MAIN_2, GF_PLANE_TOGGLE_ON);
        work->step++;
        // fallthrough
    case BG_BLEND_OUT_STEP_START_BLEND:
        priority3 = BattleAnimSystem_GetBgPriority(work->system, BATTLE_ANIM_BG_BATTLE);
        priority2 = BattleAnimSystem_GetBgPriority(work->system, BATTLE_ANIM_BG_EFFECT);
        SetBgPriority(GF_BG_LYR_MAIN_3, (u8)priority3);
        SetBgPriority(GF_BG_LYR_MAIN_2, (u8)priority2);
        G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG2, GX_BLEND_PLANEMASK_BG3, work->eva, work->evb);
        BattleAnimBackground_StartEffects(work);
        work->step++;
        // fallthrough
    case BG_BLEND_OUT_STEP_BLEND:
        done = 0;
        if (work->eva < work->evaTarget) {
            work->eva += 2;
        } else {
            done++;
        }
        if (work->evb > work->evbTarget) {
            work->evb -= 2;
        } else {
            done++;
        }
        if (done == 2) {
            work->eva = work->evaTarget + 2;
            work->evb = work->evbTarget - 2;
            work->step++;
        }
        reg_G2_BLDALPHA = work->eva | (work->evb << 8);
        break;
    case BG_BLEND_OUT_STEP_RESTORE_BATTLE_BG:
        BattleAnimBackground_StopMarkedEffects(work);
        BgSetPosTextAndCommit(work->system->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(work->system->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_Y, 0);
        SetBgControlParam(work->system->bgConfig, GF_BG_LYR_MAIN_3, GF_BG_CNT_SET_CHAR_BASE, GX_BG_CHARBASE_0x10000);
        if (!BattleAnimSystem_IsContest(work->system)) {
            SetBgControlParam(work->system->bgConfig, GF_BG_LYR_MAIN_3, GF_BG_CNT_SET_COLOR_MODE, GX_BG_COLORMODE_256);
            BattleAnimSystem_LoadBattleBgTiles(work->system, GF_BG_LYR_MAIN_3);
            BattleAnimSystem_LoadBattleBgPalette(work->system);
        } else {
            GfGfxLoader_LoadCharData(work->system->battleBg.narcId, work->system->battleBg.charMember, work->system->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, work->system->heapId);
            PaletteData_LoadNarc(work->system->paletteData, work->system->battleBg.narcId, work->system->battleBg.paletteMember, work->system->heapId, PLTTBUF_MAIN_BG, work->system->battleBg.paletteCount << 5, work->system->battleBg.palettePos);
        }
        GfGfxLoader_LoadScrnData(work->system->battleBg.narcId, work->system->battleBg.screenMember, work->system->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, work->system->heapId);
        work->step++;
        break;
    case BG_BLEND_OUT_STEP_RESET_LAYER:
        BattleSystem_SetDefaultBlend();
        ToggleBgLayer(GF_BG_LYR_MAIN_2, GF_PLANE_TOGGLE_OFF);
        BattleAnimBackground_ResetLayer(work->system, GF_BG_LYR_MAIN_2);
        work->step++;
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

enum {
    BG_FADE_IN_STEP_FADE_OUT,
    BG_FADE_IN_STEP_LOAD_GRAPHICS,
};

static BOOL BattleAnimBackground_FadeIn(SysTask *task, BattleAnimBgSwitchWork *work) {
    switch (work->step) {
    case BG_FADE_IN_STEP_FADE_OUT:
        if (!work->fadeToWhite) {
            PaletteData_ForceBeginPaletteFade(work->system->paletteData, PLTTBUF_MAIN_BG_F, work->system->battleBgPaletteMask, work->switchFadeWait, 0, 16, RGB_BLACK);
            PaletteData_BlendPalettes(work->system->paletteData, PLTTBUF_MAIN_BG, 0x200, 16, RGB_BLACK);
        } else {
            PaletteData_ForceBeginPaletteFade(work->system->paletteData, PLTTBUF_MAIN_BG_F, work->system->battleBgPaletteMask, work->switchFadeWait, 0, 16, 0xFFFF);
            PaletteData_BlendPalettes(work->system->paletteData, PLTTBUF_MAIN_BG, 0x200, 16, 0xFFFF);
        }
        work->step++;
        // fallthrough
    case BG_FADE_IN_STEP_LOAD_GRAPHICS:
        if (PaletteData_GetSelectedBuffersBitmask(work->system->paletteData) != 0) {
            break;
        }
        SetBgControlParam(work->system->bgConfig, GF_BG_LYR_MAIN_3, GF_BG_CNT_SET_COLOR_MODE, GX_BG_COLORMODE_16);
        BattleAnimBackground_LoadGraphics(work, work->system, GF_BG_LYR_MAIN_3, work->bgId);
        if (!work->fadeToWhite) {
            PaletteData_ForceBeginPaletteFade(work->system->paletteData, PLTTBUF_MAIN_BG_F, 0x200, work->switchFadeWait, 16, 0, RGB_BLACK);
        } else {
            PaletteData_ForceBeginPaletteFade(work->system->paletteData, PLTTBUF_MAIN_BG_F, 0x200, work->switchFadeWait, 16, 0, 0xFFFF);
        }
        BattleAnimBackground_StartEffects(work);
        work->system->bgSwitchState = 2;
        work->step++;
        break;
    default:
        if (PaletteData_GetSelectedBuffersBitmask(work->system->paletteData) == 0) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

enum {
    BG_FADE_OUT_STEP_START_EFFECTS,
    BG_FADE_OUT_STEP_FADE,
    BG_FADE_OUT_STEP_RESTORE_BG,
    BG_FADE_OUT_STEP_FADE_IN,
};

static BOOL BattleAnimBackground_FadeOut(SysTask *task, BattleAnimBgSwitchWork *work) {
    switch (work->step) {
    case BG_FADE_OUT_STEP_START_EFFECTS:
        BattleAnimBackground_StartEffects(work);
        work->step++;
        // fallthrough
    case BG_FADE_OUT_STEP_FADE:
        if (!work->fadeToWhite) {
            PaletteData_ForceBeginPaletteFade(work->system->paletteData, PLTTBUF_MAIN_BG_F, 0x200, work->restoreFadeWait, 0, 16, RGB_BLACK);
            PaletteData_BlendPalettes(work->system->paletteData, PLTTBUF_MAIN_BG, work->system->battleBgPaletteMask, 16, RGB_BLACK);
        } else {
            PaletteData_ForceBeginPaletteFade(work->system->paletteData, PLTTBUF_MAIN_BG_F, 0x200, work->restoreFadeWait, 0, 16, 0xFFFF);
            PaletteData_BlendPalettes(work->system->paletteData, PLTTBUF_MAIN_BG, work->system->battleBgPaletteMask, 16, 0xFFFF);
        }
        work->step++;
        // fallthrough
    case BG_FADE_OUT_STEP_RESTORE_BG:
        if (PaletteData_GetSelectedBuffersBitmask(work->system->paletteData) != 0) {
            goto running;
        }
        BattleAnimBackground_StopMarkedEffects(work);
        ToggleBgLayer(GF_BG_LYR_MAIN_3, GF_PLANE_TOGGLE_OFF);
        if (!BattleAnimSystem_IsContest(work->system)) {
            SetBgControlParam(work->system->bgConfig, GF_BG_LYR_MAIN_3, GF_BG_CNT_SET_COLOR_MODE, GX_BG_COLORMODE_256);
            BattleAnimSystem_LoadBattleBgTiles(work->system, GF_BG_LYR_MAIN_3);
            BattleAnimSystem_LoadBattleBgPalette(work->system);
        } else {
            GfGfxLoader_LoadCharData(work->system->battleBg.narcId, work->system->battleBg.charMember, work->system->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, work->system->heapId);
            PaletteData_LoadNarc(work->system->paletteData, work->system->battleBg.narcId, work->system->battleBg.paletteMember, work->system->heapId, PLTTBUF_MAIN_BG, work->system->battleBg.paletteCount << 5, work->system->battleBg.palettePos);
        }
        GfGfxLoader_LoadScrnData(work->system->battleBg.narcId, work->system->battleBg.screenMember, work->system->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, work->system->heapId);
        ToggleBgLayer(GF_BG_LYR_MAIN_3, GF_PLANE_TOGGLE_ON);
        work->step++;
        // fallthrough
    case BG_FADE_OUT_STEP_FADE_IN:
        BgSetPosTextAndCommit(work->system->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(work->system->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_Y, 0);
        if (!work->fadeToWhite) {
            PaletteData_ForceBeginPaletteFade(work->system->paletteData, PLTTBUF_MAIN_BG_F, work->system->battleBgPaletteMask, work->restoreFadeWait, 16, 0, RGB_BLACK);
        } else {
            PaletteData_ForceBeginPaletteFade(work->system->paletteData, PLTTBUF_MAIN_BG_F, work->system->battleBgPaletteMask, work->restoreFadeWait, 16, 0, 0xFFFF);
        }
        work->step++;
        // fallthrough
    default:
        break;
    }
    if (PaletteData_GetSelectedBuffersBitmask(work->system->paletteData) != 0) {
        goto running;
    }
    work->system->bgSwitchState = 2;
    work->step++;
    return FALSE;
running:
    return TRUE;
}

static BOOL BattleAnimBackground_StartEffectsOnly(SysTask *task, BattleAnimBgSwitchWork *work) {
    BattleAnimBackground_StartEffects(work);
    return FALSE;
}

static BOOL BattleAnimBackground_StartEffectsAndStopMarked(SysTask *task, BattleAnimBgSwitchWork *work) {
    BattleAnimBackground_StartEffects(work);
    BattleAnimBackground_StopMarkedEffects(work);
    return FALSE;
}

static void BattleAnimTask_BgScroll(SysTask *task, void *data) {
    BattleAnimBgScroll *scroll = data;
    if (scroll->stop == TRUE) {
        Heap_Free(scroll);
        SysTask_Destroy(task);
        return;
    }
    scroll->x += scroll->dx;
    scroll->y += scroll->dy;
    if (scroll->dx) {
        BgSetPosTextAndCommit(scroll->bgConfig, scroll->layer, BG_POS_OP_SET_X, scroll->x);
    }
    if (scroll->dy) {
        BgSetPosTextAndCommit(scroll->bgConfig, scroll->layer, BG_POS_OP_SET_Y, scroll->y);
    }
}

static void BattleAnimBackground_StopMarkedEffects(BattleAnimBgSwitchWork *work) {
    GF_ASSERT(work != NULL);
    GF_ASSERT(work->system != NULL);
    if (work->stopScroll == TRUE) {
        BattleAnimSystem_StopBgEffects(work->system->bgEffects, 1);
        return;
    }
    if (work->stopWave == TRUE) {
        BattleAnimSystem_StopBgEffects(work->system->bgEffects, 2);
        return;
    }
    if (work->stopPaletteCycle == TRUE) {
        BattleAnimSystem_StopBgEffects(work->system->bgEffects, 3);
    }
}

u32 BattleAnimSystem_GetBattleBgPaletteMask(BattleAnimSystem *system) {
    return system->battleBgPaletteMask;
}

static BOOL BattleAnimBackground_EffectNone(BattleAnimBgSwitchWork *work) {
    return FALSE;
}

static BOOL BattleAnimBackground_StartScroll(BattleAnimBgSwitchWork *work) {
    BattleAnimBgScroll *scroll = Heap_Alloc(work->system->heapId, sizeof(BattleAnimBgScroll));
    scroll->bgConfig = work->system->bgConfig;
    scroll->x = work->system->args[2];
    scroll->y = work->system->args[3];
    scroll->dx = work->system->args[0];
    scroll->dy = work->system->args[1];
    scroll->layer = GF_BG_LYR_MAIN_3;
    scroll->unk_10 = 3;
    if (BattleAnimBackground_ShouldFlip(work, work->system, 6) == TRUE) {
        scroll->dx *= -1;
        scroll->dy *= -1;
        scroll->x *= -1;
        scroll->y *= -1;
    }
    scroll->unk_14 = 1;
    scroll->stop = FALSE;
    BattleAnimSystem_RegisterBgEffect(work->system->bgEffects, scroll, 1);
    work->stopScroll = TRUE;
    SysTask_CreateOnMainQueue(BattleAnimTask_BgScroll, scroll, 0x1001);
    return FALSE;
}

static BOOL BattleAnimBackground_StartWave(BattleAnimBgSwitchWork *work) {
    BattleAnimSystem *system = work->system;
    BattleAnimBgWave *wave;
    int i;

    wave = Heap_Alloc(system->heapId, sizeof(BattleAnimBgWave));
    wave->bands = Heap_Alloc(system->heapId, sizeof(BattleAnimBgWaveBands));
    BattleAnimSystem_RegisterBgEffect(system->bgEffects, wave, 2);
    work->stopWave = TRUE;
    wave->stop = FALSE;
    wave->bands->scanline = BattleAnimScanline_New(BattleAnimUtil_GetBgOffsetRegister(BattleAnimSystem_GetBgMaskLayer(system, BATTLE_ANIM_BG_BATTLE)), BattleAnimUtil_PackXY(0, 0), system->heapId);
    for (i = 0; i < 16; i++) {
        wave->bands->bands[i].start = i * 8;
        wave->bands->bands[i].end = wave->bands->bands[i].start + 8;
        wave->bands->bands[i].step = sBattleAnimBgWaveSteps[i];
        wave->bands->bands[i].offset = 0;
        wave->bands->bands[i].scroll = BattleAnimUtil_PackXY(0, 0);
        if (BattleAnimBackground_ShouldFlip(work, work->system, 6) == TRUE) {
            wave->bands->bands[i].step *= -1;
        }
    }
    SysTask_CreateOnMainQueue(BattleAnimTask_BgWave, wave, 0x1000);
    return FALSE;
}

static BOOL BattleAnimBackground_MarkWaveForStop(BattleAnimBgSwitchWork *work) {
    work->stopWave = TRUE;
    return FALSE;
}

static void BattleAnimTask_BgWave(SysTask *task, void *data) {
    BattleAnimBgWave *wave = data;
    BattleAnimBgWaveBands *bands = wave->bands;
    int i, j;
    u32 *buffer;

    if (wave->stop == TRUE) {
        BattleAnimScanline_Free(bands->scanline);
        Heap_Free(wave->bands);
        Heap_Free(wave);
        SysTask_Destroy(task);
        return;
    }
    buffer = BattleAnimScanline_GetWriteBuffer(bands->scanline);
    for (i = 0; i < 16; i++) {
        BattleAnimBgWaveBand *band = &bands->bands[i];
        band->offset += band->step;
        for (j = band->start; j < band->end; j++) {
            buffer[j] = BattleAnimUtil_PackXY((s16)band->scroll + band->offset, (s16)(band->scroll >> 16));
        }
    }
}

static void BattleAnimTask_BgPaletteCycle(SysTask *task, void *data) {
    BattleAnimPaletteCycle *cycle = data;
    BattleAnimPaletteCycleData *cycleData = cycle->data;

    if (cycle->stop == TRUE) {
        Heap_Free(cycleData);
        Heap_Free(cycle);
        SysTask_Destroy(task);
        return;
    }
    switch (cycleData->state) {
    case 0:
        cycleData->timer = 255;
        cycleData->state++;
        // fallthrough
    case 1:
        if (cycleData->timer < cycleData->durations[cycleData->index] - 2) {
            cycleData->timer++;
        } else {
            PaletteData_LoadFromNarc(cycleData->paletteData, NARC_a_0_0_9, cycleData->member, cycleData->heapId, PLTTBUF_MAIN_BG, 32, 0x90, cycleData->offsets[cycleData->index] << 4);
            cycleData->timer = 0;
            if (cycleData->index >= cycleData->count - 1) {
                cycleData->index = 0;
            } else {
                cycleData->index++;
            }
        }
        break;
    }
}

static BOOL BattleAnimBackground_StartPaletteCycle(BattleAnimBgSwitchWork *work) {
    BattleAnimSystem *system = work->system;
    BattleAnimPaletteCycle *cycle = Heap_Alloc(system->heapId, sizeof(BattleAnimPaletteCycle));
    int member;
    u8 *file, *ptr;
    u16 *durations;
    u16 i;

    MI_CpuFill8(cycle, 0, sizeof(BattleAnimPaletteCycle));
    cycle->data = Heap_Alloc(system->heapId, sizeof(BattleAnimPaletteCycleData));
    MI_CpuFill8(cycle->data, 0, sizeof(BattleAnimPaletteCycleData));
    work->stopPaletteCycle = TRUE;
    cycle->stop = FALSE;
    cycle->data->heapId = system->heapId;
    cycle->data->paletteData = system->paletteData;
    BattleAnimSystem_RegisterBgEffect(system->bgEffects, cycle, 3);
    switch (work->bgId) {
    case 0:
    case 1:
    case 3:
    case 5:
        member = 0;
        break;
    case 4:
        member = 2;
        break;
    case 19:
        member = 4;
        break;
    case 53:
        member = 6;
        break;
    case 52:
        member = 8;
        break;
    case 22:
        member = 10;
        break;
    case 58:
        member = 12;
        break;
    case 28:
        member = 14;
        break;
    case 29:
        member = 16;
        break;
    case 57:
        member = 26;
        break;
    case 7:
        member = 28;
        break;
    case 14:
        member = 20;
        break;
    case 17:
        member = 18;
        break;
    case 2:
        member = 22;
        break;
    case 11:
        member = 24;
        break;
    case 44:
        member = 30;
        break;
    default:
        GF_ASSERT(gBattleAnimNoBgPaletteAnimMsg == NULL);
        member = 0;
        break;
    }
    // member: the palette offsets (0xFF-terminated) and the frame durations (0xFF98-terminated);
    // member + 1: the palettes
    file = GfGfxLoader_LoadFromNarc(NARC_a_0_0_9, member, FALSE, system->heapId, TRUE);
    GF_ASSERT(file != NULL);
    cycle->data->member = member + 1;
    i = 0;
    ptr = file;
    {
        u8 offset = *ptr;
        while (offset != 0xFF) {
            cycle->data->offsets[i] = offset;
            ptr++;
            i++;
            offset = *ptr;
        }
    }
    cycle->data->count = i;
    {
        u16 duration;
        u16 j = 0;
        durations = (u16 *)(file + 0x80);
        duration = *durations;
        while (duration != 0xFF98) {
            cycle->data->durations[j] = duration;
            durations++;
            j++;
            duration = *durations;
        }
    }
    Heap_Free(file);
    SysTask_CreateOnMainQueue(BattleAnimTask_BgPaletteCycle, cycle, 0x1001);
    return FALSE;
}

static BOOL BattleAnimBackground_MarkPaletteCycleForStop(BattleAnimBgSwitchWork *work) {
    work->stopPaletteCycle = TRUE;
    return FALSE;
}

void BattleAnimBackground_LoadBattleBgToLayerDefault(BattleAnimSystem *system, GFBgLayer layer) {
    BattleAnimBackground_LoadBattleBgToLayer(system, layer, 1);
}

static void BattleAnimBackground_LoadBattleBgToLayer(BattleAnimSystem *system, GFBgLayer layer, int colorMode) {
    SetBgPriority(layer, (u8)BattleAnimSystem_GetBgPriority(system, BATTLE_ANIM_BG_BATTLE));
    ToggleBgLayer(layer, GF_PLANE_TOGGLE_OFF);
    if (BattleAnimSystem_IsContest(system) == TRUE) {
        SetBgControlParam(system->bgConfig, layer, GF_BG_CNT_SET_CHAR_BASE, GX_BG_CHARBASE_0x10000);
    } else {
        SetBgControlParam(system->bgConfig, layer, GF_BG_CNT_SET_COLOR_MODE, colorMode);
        SetBgControlParam(system->bgConfig, layer, GF_BG_CNT_SET_CHAR_BASE, GX_BG_CHARBASE_0x10000);
    }
    BgClearTilemapBufferAndCommit(system->bgConfig, layer);
    if (BattleAnimSystem_IsContest(system) == TRUE) {
        GfGfxLoader_LoadCharData(system->battleBg.narcId, system->battleBg.charMember, system->bgConfig, layer, 0, 0, TRUE, system->heapId);
    } else {
        BattleAnimSystem_LoadBattleBgTiles(system, layer);
    }
    GfGfxLoader_LoadScrnData(system->battleBg.narcId, system->battleBg.screenMember, system->bgConfig, layer, 0, 0, TRUE, system->heapId);
}

void BattleAnimBackground_ResetLayer(BattleAnimSystem *system, GFBgLayer layer) {
    SetBgPriority(layer, (u8)BattleAnimSystem_GetBgPriority(system, BATTLE_ANIM_BG_EFFECT));
    if (BattleAnimSystem_IsContest(system) == TRUE) {
        SetBgControlParam(system->bgConfig, layer, GF_BG_CNT_SET_CHAR_BASE, GX_BG_CHARBASE_0x0c000);
    } else {
        SetBgControlParam(system->bgConfig, layer, GF_BG_CNT_SET_COLOR_MODE, GX_BG_COLORMODE_16);
        SetBgControlParam(system->bgConfig, layer, GF_BG_CNT_SET_CHAR_BASE, GX_BG_CHARBASE_0x0c000);
    }
    BgClearTilemapBufferAndCommit(system->bgConfig, layer);
}

static BOOL BattleAnimBackground_MarkScrollForStop(BattleAnimBgSwitchWork *work) {
    work->stopScroll = TRUE;
    return FALSE;
}

static BOOL BattleAnimBackground_StopAllEffects(BattleAnimBgSwitchWork *work) {
    BattleAnimSystem_StopBgEffects(work->system->bgEffects, 5);
    return FALSE;
}

static void BattleAnimTask_BackgroundSwitch(SysTask *task, void *data) {
    BattleAnimBgSwitchWork *work = data;
    if (!sBattleAnimBgSwitchFuncs[work->func](task, work)) {
        work->system->bgSwitchState = 0;
        Heap_Free(work);
        SysTask_Destroy(task);
    }
}

static void BattleAnimScriptCmd_SwitchBackground(BattleAnimSystem *system) {
    BattleAnimBgSwitchWork *work = BattleAnimBackground_NewSwitchWork(system);
    u32 word;

    work->fadeToWhite = BattleAnimSystem_GetArg(system, 4);
    system->scriptPtr++;
    work->bgId = *system->scriptPtr;
    system->scriptPtr++;
    word = *system->scriptPtr;
    system->scriptPtr++;
    work->func = (u16)word;
    work->effectFlags = (word & 0xFFFF0000) >> 16;
    SysTask_CreateOnMainQueue(BattleAnimTask_BackgroundSwitch, work, 1100);
}

static void BattleAnimScriptCmd_SwitchBackgroundWithFadeWait(BattleAnimSystem *system) {
    BattleAnimBgSwitchWork *work = BattleAnimBackground_NewSwitchWork(system);
    u32 word;
    s16 kind;
    s16 amount;

    work->fadeToWhite = BattleAnimSystem_GetArg(system, 4);
    system->scriptPtr++;
    work->bgId = *system->scriptPtr;
    system->scriptPtr++;
    word = *system->scriptPtr;
    system->scriptPtr++;
    work->func = (u16)word;
    work->effectFlags = (word & 0xFFFF0000) >> 16;
    word = *system->scriptPtr;
    system->scriptPtr++;
    kind = word;
    amount = (word & 0xFFFF0000) >> 16;
    switch (kind) {
    case 1:
        work->switchFadeWait += amount;
        break;
    case 2:
        work->switchFadeWait -= amount;
        break;
    case 3:
        work->restoreFadeWait += amount;
        break;
    case 4:
        work->restoreFadeWait -= amount;
        break;
    case 5:
        work->switchFadeWait += amount;
        work->restoreFadeWait += amount;
        break;
    case 6:
        work->switchFadeWait -= amount;
        work->restoreFadeWait -= amount;
        break;
    default:
        GF_ASSERT(gBattleAnimInvalidExFlagMsg == NULL);
        break;
    }
    SysTask_CreateOnMainQueue(BattleAnimTask_BackgroundSwitch, work, 1100);
}

static void BattleAnimScriptCmd_SetBgScroll(BattleAnimSystem *system) {
    u32 param;
    s16 value;
    BattleAnimBgScroll *scroll;

    system->scriptPtr++;
    param = *system->scriptPtr;
    system->scriptPtr++;
    value = *system->scriptPtr;
    system->scriptPtr++;
    scroll = BattleAnimSystem_FindBgEffect(system->bgEffects, 1);
    switch (param) {
    case 0:
        scroll->dx = value;
        break;
    case 1:
        scroll->dy = value;
        break;
    case 2:
        scroll->x = value;
        break;
    case 3:
        scroll->x = value; // sets x like case 2
        break;
    }
}

static void BattleAnimScriptCmd_RestoreBackground(BattleAnimSystem *system) {
    BattleAnimBgSwitchWork *work = BattleAnimBackground_NewSwitchWork(system);
    u32 word;

    work->fadeToWhite = BattleAnimSystem_GetArg(system, 4);
    system->scriptPtr++;
    work->bgId = *system->scriptPtr;
    system->scriptPtr++;
    word = *system->scriptPtr;
    system->scriptPtr++;
    work->func = (u16)word + 3;
    work->effectFlags = (word & 0xFFFF0000) >> 16;
    SysTask_CreateOnMainQueue(BattleAnimTask_BackgroundSwitch, work, 1100);
}

static void BattleAnimScriptCmd_WaitForBackgroundLoaded(BattleAnimSystem *system) {
    if (system->bgSwitchState == 2) {
        system->scriptPtr++;
        system->delay = 0;
    } else {
        system->delay = 1;
    }
}

static void BattleAnimScriptCmd_WaitForBackgroundSwitch(BattleAnimSystem *system) {
    if (system->bgSwitchState == 0) {
        system->scriptPtr++;
        system->delay = 0;
    } else {
        system->delay = 1;
    }
}

static void BattleAnimScriptCmd_SetBackground(BattleAnimSystem *system) {
    BattleAnimBgSwitchWork *work = BattleAnimBackground_NewSwitchWork(system);
    int bgId, member;
    enum BattleAnimBgFile screen;

    system->scriptPtr++;
    bgId = *system->scriptPtr;
    system->scriptPtr++;
    ToggleBgLayer(GF_BG_LYR_MAIN_3, GF_PLANE_TOGGLE_OFF);
    SetBgControlParam(system->bgConfig, GF_BG_LYR_MAIN_3, GF_BG_CNT_SET_COLOR_MODE, GX_BG_COLORMODE_16);
    member = BattleAnimSystem_GetBackgroundFile(bgId, BATTLE_ANIM_BG_FILE_CHAR);
    GfGfxLoader_LoadCharData(NARC_a_0_0_7, member, system->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, system->heapId);
    member = BattleAnimSystem_GetBackgroundFile(bgId, BATTLE_ANIM_BG_FILE_PALETTE);
    PaletteData_LoadNarc(system->paletteData, NARC_a_0_0_7, member, system->heapId, PLTTBUF_MAIN_BG, 32, 0x90);
    BgClearTilemapBufferAndCommit(system->bgConfig, GF_BG_LYR_MAIN_3);
    screen = BATTLE_ANIM_BG_FILE_SCREEN;
    if (BattleAnimBackground_ShouldFlip(work, system, 7) == TRUE) {
        screen = BATTLE_ANIM_BG_FILE_SCREEN_FLIPPED;
    }
    member = BattleAnimSystem_GetBackgroundFile(bgId, screen);
    GfGfxLoader_LoadScrnData(NARC_a_0_0_7, member, system->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, system->heapId);
    ToggleBgLayer(GF_BG_LYR_MAIN_3, GF_PLANE_TOGGLE_ON);
    Heap_Free(work);
}

static void BattleAnimScriptCmd_SwitchBackgroundBySide(BattleAnimSystem *system) {
    BattleAnimBgSwitchWork *work = BattleAnimBackground_NewSwitchWork(system);
    int playerSide, enemySide, unk08Set;

    system->scriptPtr++;
    playerSide = *system->scriptPtr;
    system->scriptPtr++;
    enemySide = *system->scriptPtr;
    system->scriptPtr++;
    unk08Set = *system->scriptPtr;
    system->scriptPtr++;
    if (BattleAnimSystem_IsContest(system) == TRUE) {
        work->bgId = unk08Set;
    } else if (BattleAnimUtil_GetBattlerSide(system, system->context->defender) == BATTLE_ANIM_SIDE_PLAYER) {
        work->bgId = enemySide;
    } else {
        work->bgId = playerSide;
    }
    SysTask_CreateOnMainQueue(BattleAnimTask_BackgroundSwitch, work, 1100);
}

static void BattleAnimScriptCmd_Nop37(BattleAnimSystem *system) {
}

static void BattleAnimScriptCmd_Nop38(BattleAnimSystem *system) {
}

static void BattleAnimScriptCmd_Nop39(BattleAnimSystem *system) {
}

static void BattleAnimScriptCmd_Nop42(BattleAnimSystem *system) {
}

static void BattleAnimScriptCmd_Nop43(BattleAnimSystem *system) {
}

static void BattleAnimScriptCmd_PlaySE(BattleAnimSystem *system) {
    u32 seqNo;
    system->scriptPtr++;
    seqNo = ReadScriptWord(system);
    PlaySE(seqNo);
}

static void BattleAnimScriptCmd_StopSE(BattleAnimSystem *system) {
    u32 seqNo;
    system->scriptPtr++;
    seqNo = ReadScriptWord(system);
    StopSE(seqNo, 0);
}

static void BattleAnimScriptCmd_PlaySEWithPan(BattleAnimSystem *system) {
    u16 seqNo;
    int pan;
    system->scriptPtr++;
    seqNo = *system->scriptPtr;
    system->scriptPtr++;
    pan = BattleAnimSystem_ConvertPan(system, (s8)ReadScriptWord(system));
    PlaySE(seqNo);
    SetSeqTrackPan(seqNo, 0xFFFF, pan);
}

static void BattleAnimScriptCmd_SetSEPan(BattleAnimSystem *system) {
    int pan;
    system->scriptPtr++;
    pan = BattleAnimSystem_ConvertPan(system, (s8)ReadScriptWord(system));
    SetAllSEPan(pan);
}

#define NEXT_ARG(system) (*++(system)->scriptPtr)

static void BattleAnimScriptCmd_PanSweepSE(BattleAnimSystem *system) {
    BattleAnimSoundTaskData *data = BattleAnimSystem_NewSoundTaskData(system);
    memset(data, 0, sizeof(BattleAnimSoundTaskData));
    data->kind = 1;
    data->seqNo = NEXT_ARG(system);
    data->startPan = NEXT_ARG(system);
    data->endPan = NEXT_ARG(system);
    data->panStep = NEXT_ARG(system);
    data->interval = NEXT_ARG(system);
    system->scriptPtr++;
    data->startPan = BattleAnimSystem_ConvertPan(system, (s8)data->startPan);
    data->endPan = BattleAnimSystem_ConvertPan(system, (s8)data->endPan);
    data->panStep = BattleAnimSystem_GetPanStep((s8)data->startPan, (s8)data->endPan, (s8)data->panStep);
    PlaySE(data->seqNo);
    SetSeqTrackPan(data->seqNo, 0xFFFF, data->startPan);
    BattleAnimSystem_StartSoundTask(system, data);
}

static void BattleAnimScriptCmd_PanSweepSERaw(BattleAnimSystem *system) {
    BattleAnimSoundTaskData *data = BattleAnimSystem_NewSoundTaskData(system);
    memset(data, 0, sizeof(BattleAnimSoundTaskData));
    data->kind = 2;
    data->seqNo = NEXT_ARG(system);
    data->startPan = (s8)NEXT_ARG(system);
    data->endPan = (s8)NEXT_ARG(system);
    data->panStep = (s8)NEXT_ARG(system);
    data->interval = NEXT_ARG(system);
    system->scriptPtr++;
    PlaySE(data->seqNo);
    SetSeqTrackPan(data->seqNo, 0xFFFF, data->startPan);
    BattleAnimSystem_StartSoundTask(system, data);
}

static void BattleAnimScriptCmd_PanSweepSEConverted(BattleAnimSystem *system) {
    BattleAnimSoundTaskData *data = BattleAnimSystem_NewSoundTaskData(system);
    memset(data, 0, sizeof(BattleAnimSoundTaskData));
    data->kind = 1;
    data->seqNo = NEXT_ARG(system);
    data->startPan = (s8)NEXT_ARG(system);
    data->endPan = (s8)NEXT_ARG(system);
    data->panStep = (s8)NEXT_ARG(system);
    data->interval = NEXT_ARG(system);
    system->scriptPtr++;
    data->startPan = BattleAnimSystem_ConvertPan(system, (s8)data->startPan);
    data->endPan = BattleAnimSystem_ConvertPan(system, (s8)data->endPan);
    data->panStep = BattleAnimSystem_ConvertPan(system, (s8)data->panStep);
    PlaySE(data->seqNo);
    SetSeqTrackPan(data->seqNo, 0xFFFF, data->startPan);
    BattleAnimSystem_StartSoundTask(system, data);
}

static void BattleAnimScriptCmd_RepeatSE(BattleAnimSystem *system) {
    BattleAnimSoundTaskData *data = BattleAnimSystem_NewSoundTaskData(system);
    memset(data, 0, sizeof(BattleAnimSoundTaskData));
    data->kind = 4;
    data->seqNo = NEXT_ARG(system);
    data->pan = (s8)NEXT_ARG(system);
    data->interval = NEXT_ARG(system);
    data->repeatCount = NEXT_ARG(system);
    system->scriptPtr++;
    data->counter = data->interval;
    data->pan = BattleAnimSystem_ConvertPan(system, (s8)data->pan);
    BattleAnimSystem_StartSoundTask(system, data);
}

static void BattleAnimScriptCmd_DelayedSE(BattleAnimSystem *system) {
    BattleAnimSoundTaskData *data = BattleAnimSystem_NewSoundTaskData(system);
    memset(data, 0, sizeof(BattleAnimSoundTaskData));
    data->kind = 5;
    data->seqNo = NEXT_ARG(system);
    data->pan = (s8)NEXT_ARG(system);
    data->interval = NEXT_ARG(system);
    system->scriptPtr++;
    data->pan = BattleAnimSystem_ConvertPan(system, (s8)data->pan);
    BattleAnimSystem_StartSoundTask(system, data);
}

static void BattleAnimScriptCmd_Nop28(BattleAnimSystem *system) {
}

static void BattleAnimScriptCmd_WaitForSoundTasks(BattleAnimSystem *system) {
    if (system->soundTaskCount) {
        system->delay = 1;
        system->seWaitTimer = 0;
        return;
    }
    if (GF_IsAnySEPlaying()) {
        system->seWaitTimer++;
        if (system->seWaitTimer > 90) {
            system->seWaitTimer = 0;
            return;
        }
        system->delay = 1;
        return;
    }
    system->delay = 0;
    system->seWaitTimer = 0;
    system->scriptPtr++;
}

static void BattleAnimScriptCmd_SetSubScreenBlend(BattleAnimSystem *system) {
    u32 ev1, ev2;
    system->scriptPtr++;
    ev1 = *system->scriptPtr;
    system->scriptPtr++;
    ev2 = *system->scriptPtr;
    system->scriptPtr++;
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_BG0, GX_BLEND_PLANEMASK_BG1, (u16)ev1, (u16)ev2);
}

static void BattleAnimScriptCmd_ResetBlend(BattleAnimSystem *system) {
    BattleAnimSystem_InitBlend();
}

static void BattleAnimScriptCmd_Nop27(BattleAnimSystem *system) {
}

static void BattleAnimScriptCmd_InitSpriteManager(BattleAnimSystem *system) {
    u32 index = NEXT_ARG(system);
    u32 maxSprites = NEXT_ARG(system);
    SpriteResourceCountsListUnion capacities;
    int i;

    system->scriptPtr++;
    GF_ASSERT(system->spriteManagers[index] == NULL);
    system->spriteManagers[index] = SpriteManager_New(system->context->spriteSystem);
    GF_ASSERT(system->spriteManagers[index] != NULL);
    SpriteSystem_InitSprites(system->context->spriteSystem, system->spriteManagers[index], maxSprites);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(system->context->spriteSystem), 0, FX32_CONST(272));
    for (i = 0; i < GF_GFX_RES_TYPE_MAX; i++) {
        capacities.asArray[i] = *system->scriptPtr;
        system->scriptPtr++;
    }
    SpriteSystem_InitManagerWithCapacities(system->context->spriteSystem, system->spriteManagers[index], &capacities);
}

static void BattleAnimScriptCmd_LoadCharResource(BattleAnimSystem *system) {
    u32 index = NEXT_ARG(system);
    u32 fileId = NEXT_ARG(system);
    system->scriptPtr++;
    SpriteSystem_LoadCharResObjFromOpenNarc(system->context->spriteSystem, system->spriteManagers[index], system->narcs[2], fileId, TRUE, 1, fileId + 5000);
}

static void BattleAnimScriptCmd_LoadPaletteResource(BattleAnimSystem *system) {
    u32 index = NEXT_ARG(system);
    u32 fileId = NEXT_ARG(system);
    u32 count = NEXT_ARG(system);
    system->scriptPtr++;
    SpriteSystem_LoadPaletteBufferFromOpenNarc(system->paletteData, PLTTBUF_MAIN_OBJ, system->context->spriteSystem, system->spriteManagers[index], system->narcs[3], fileId, FALSE, 1, count, fileId + 5000);
}

static void BattleAnimScriptCmd_LoadCellResource(BattleAnimSystem *system) {
    u32 index = NEXT_ARG(system);
    u32 fileId = NEXT_ARG(system);
    system->scriptPtr++;
    SpriteSystem_LoadCellResObjFromOpenNarc(system->context->spriteSystem, system->spriteManagers[index], system->narcs[4], fileId, TRUE, fileId + 5000);
}

static void BattleAnimScriptCmd_LoadAnimResource(BattleAnimSystem *system) {
    u32 index = NEXT_ARG(system);
    u32 fileId = NEXT_ARG(system);
    system->scriptPtr++;
    SpriteSystem_LoadAnimResObjFromOpenNarc(system->context->spriteSystem, system->spriteManagers[index], system->narcs[5], fileId, TRUE, fileId + 5000);
}

static void BattleAnimScriptCmd_CreateSpriteWithFunc(BattleAnimSystem *system) {
    ManagedSpriteTemplate template;
    ManagedSprite *sprite;
    u32 managerIndex = NEXT_ARG(system);
    u32 funcId = NEXT_ARG(system);
    int defender;
    int count;
    int i;
    BattleAnimSpriteFunc func;

    system->scriptPtr++;
    defender = BattleAnimSystem_GetDefender(system);
    template.x = BattleAnimSystem_GetBattlerScreenCoord(system, defender, BATTLE_ANIM_COORD_X);
    template.y = BattleAnimSystem_GetBattlerScreenCoord(system, defender, BATTLE_ANIM_COORD_Y);
    template.z = 0;
    template.animation = 0;
    template.drawPriority = 100;
    template.pal = 0;
    template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.bgPriority = 1;
    template.vramTransfer = FALSE;
    for (i = 0; i < 6; i++) {
        template.resIdList[i] = *system->scriptPtr + 5000;
        system->scriptPtr++;
    }
    system->spriteTemplate = template;
    sprite = SpriteSystem_NewSprite(system->context->spriteSystem, system->spriteManagers[managerIndex], &template);
    count = *system->scriptPtr;
    system->scriptPtr++;
    for (i = 0; i < count; i++) {
        system->args[i] = *system->scriptPtr;
        system->scriptPtr++;
    }
    for (; i < 10; i++) {
        system->args[i] = 0;
    }
    func = BattleAnimSystem_GetSpriteFunc(funcId);
    func(system, system->context->spriteSystem, system->spriteManagers[managerIndex], sprite);
}

static void BattleAnimScriptCmd_CreateSprite(BattleAnimSystem *system) {
    ManagedSpriteTemplate template;
    u32 managerIndex = NEXT_ARG(system);
    u32 spriteIndex = NEXT_ARG(system);
    int defender;
    ManagedSprite *sprite;
    int i;

    system->scriptPtr++;
    defender = BattleAnimSystem_GetDefender(system);
    template.x = BattleAnimSystem_GetBattlerScreenCoord(system, defender, BATTLE_ANIM_COORD_X);
    template.y = BattleAnimSystem_GetBattlerScreenCoord(system, defender, BATTLE_ANIM_COORD_Y);
    template.z = 0;
    template.animation = 0;
    template.drawPriority = 100;
    template.pal = 0;
    template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.bgPriority = 1;
    template.vramTransfer = FALSE;
    for (i = 0; i < 6; i++) {
        template.resIdList[i] = *system->scriptPtr + 5000;
        system->scriptPtr++;
    }
    system->spriteTemplate = template;
    sprite = SpriteSystem_NewSprite(system->context->spriteSystem, system->spriteManagers[managerIndex], &template);
    GF_ASSERT(system->sprites[spriteIndex] == NULL);
    system->sprites[spriteIndex] = sprite;
}

static void BattleAnimScriptCmd_FreeSpriteManager(BattleAnimSystem *system) {
    u32 index = NEXT_ARG(system);
    system->scriptPtr++;
    if (system->spriteManagers[index] != NULL) {
        SpriteSystem_FreeResourcesAndManager(system->context->spriteSystem, system->spriteManagers[index]);
    }
    system->spriteManagers[index] = NULL;
}

static void BattleAnimScriptCmd_SetBattlerSpriteVisible(BattleAnimSystem *system) {
    u32 index = NEXT_ARG(system);
    u32 draw = NEXT_ARG(system);
    system->scriptPtr++;
    ManagedSprite_SetDrawFlag(system->battlerSprites[index], draw);
}

static void BattleAnimScriptCmd_Invalid55(BattleAnimSystem *system) {
    GF_ASSERT(FALSE);
}

static void BattleAnimScriptCmd_PlayCry(BattleAnimSystem *system) {
    u32 mode, param;
    int pan;
    BattleAnimContext *context;

    system->scriptPtr++;
    mode = *system->scriptPtr;
    system->scriptPtr++;
    pan = BattleAnimSystem_ConvertPan(system, (s8)(s16)*system->scriptPtr);
    system->scriptPtr++;
    param = *system->scriptPtr;
    system->scriptPtr++;
    context = system->context;
    PlayCryHandleChatot(context->chatotCry, mode, context->species[context->attacker], context->forms[context->attacker], pan, param, context->isTransformed, system->heapId);
}

static void BattleAnimScriptCmd_WaitForCry(BattleAnimSystem *system) {
    if (!IsCryPlaying()) {
        u32 arg;
        system->scriptPtr++;
        arg = *system->scriptPtr;
        system->scriptPtr++;
        system->delay = 0;
        StopCry(arg);
    } else {
        system->delay = 1;
    }
}

static void BattleAnimScriptCmd_Nop54(BattleAnimSystem *system) {
}

static BattleAnimScriptCmd BattleAnimSystem_GetScriptCmd(u32 cmd) {
    if (cmd > 0x58) {
        return NULL;
    }
    return sBattleAnimScriptCmdTable[cmd];
}

static u8 BattleAnimContext_GetField01(BattleAnimContext *context) {
    return context->unk_01;
}

static s8 BattleAnimSystem_ConvertPan(BattleAnimSystem *system, int pan) {
    int attacker = BattleAnimSystem_GetAttacker(system);
    int defender = BattleAnimSystem_GetDefender(system);
    BattleAnimUtil_GetBattlerSide(system, attacker);
    BattleAnimUtil_GetBattlerSide(system, defender);
    if (BattleAnimUtil_GetBattlerSide(system, attacker) == BATTLE_ANIM_SIDE_PLAYER && BattleAnimUtil_GetBattlerSide(system, defender) == BATTLE_ANIM_SIDE_ENEMY) {
        // unchanged
    } else if (BattleAnimUtil_GetBattlerSide(system, attacker) == BATTLE_ANIM_SIDE_ENEMY && BattleAnimUtil_GetBattlerSide(system, defender) == BATTLE_ANIM_SIDE_PLAYER) {
        pan *= -1;
    } else if (BattleAnimUtil_GetBattlerSide(system, attacker) == BATTLE_ANIM_SIDE_PLAYER && BattleAnimUtil_GetBattlerSide(system, defender) == BATTLE_ANIM_SIDE_PLAYER) {
        if (pan > 0) {
            pan *= -1;
        }
    } else if (BattleAnimUtil_GetBattlerSide(system, attacker) == BATTLE_ANIM_SIDE_ENEMY && BattleAnimUtil_GetBattlerSide(system, defender) == BATTLE_ANIM_SIDE_ENEMY) {
        if (pan < 0) {
            pan *= -1;
        }
    }
    if (BattleAnimSystem_IsContest(system) == TRUE) {
        pan *= -1;
    }
    return pan;
}

static s8 BattleAnimSystem_GetPanStep(int start, int end, int step) {
    if (start < end) {
        return abs(step);
    } else if (start > end) {
        return -abs(step);
    }
    return 0;
}

BOOL BattleAnimSystem_ReadScriptArgs(BattleAnimSystem *system, void *out, int count) {
    u32 *words = out;
    u32 expected;
    int i;
    system->scriptPtr++;
    expected = *system->scriptPtr;
    system->scriptPtr++;
    if (expected != count) {
        GF_ASSERT(expected == count);
        return FALSE;
    }
    for (i = 0; i < count; i++) {
        *words = *system->scriptPtr;
        system->scriptPtr++;
        words++;
    }
    return TRUE;
}

void BattleAnimSystem_GetSpriteTemplate(ManagedSpriteTemplate *template, BattleAnimSystem *system) {
    *template = system->spriteTemplate;
}

u8 BattleAnimSystem_GetBattlerType(BattleAnimSystem *system, int battler) {
    return system->context->battlerTypes[battler];
}

u8 BattleAnimSystem_GetBattlerGender(BattleAnimSystem *system, int battler) {
    return system->context->genders[battler];
}

u16 BattleAnimSystem_GetBattlerSpecies(BattleAnimSystem *system, int battler) {
    return system->context->species[battler];
}

u8 BattleAnimSystem_GetBattlerForm(BattleAnimSystem *system, int battler) {
    return system->context->forms[battler];
}

u32 BattleAnimSystem_GetBattlerPersonality(BattleAnimSystem *system, int battler) {
    return system->context->personalities[battler];
}

Pokepic *BattleAnimSystem_GetBattlerPokepic(BattleAnimSystem *system, int battler) {
    Pokepic *pokepic = system->context->pokepics[battler];
    if (pokepic == NULL) {
        return NULL;
    }
    if (Pokepic_IsActive(pokepic)) {
        return system->context->pokepics[battler];
    }
    return NULL;
}

PaletteData *BattleAnimSystem_GetPaletteData(BattleAnimSystem *system) {
    return system->paletteData;
}

int BattleAnimSystem_GetBattlerPaletteId(BattleAnimSystem *system, int battler) {
    return system->context->picData[battler]->paletteId;
}

int BattleAnimSystem_GetBattlerNarcId(BattleAnimSystem *system, int battler) {
    return system->context->picData[battler]->narcId;
}

int BattleAnimSystem_GetBattlerHeight(BattleAnimSystem *system, int battler) {
    return system->context->picData[battler]->height;
}

BOOL BattleAnimSystem_IsDoubleBattle(BattleAnimSystem *system) {
    return (system->context->battleType & BATTLE_TYPE_DOUBLES) != 0;
}

BOOL BattleAnimSystem_IsBattlerSemiInvulnerable(BattleAnimSystem *system, int battler) {
    return (system->context->moveEffectFlags[battler] & MOVE_EFFECT_FLAG_SEMI_INVULNERABLE) != 0;
}

int BattleAnimSystem_GetBasePriority(BattleAnimSystem *system) {
    return 1;
}

u32 BattleAnimSystem_GetBgLayer(BattleAnimSystem *system, enum BattleAnimBg bg) {
    return sBattleAnimBgLayers[bg];
}

u32 BattleAnimSystem_GetBgMaskLayer(BattleAnimSystem *system, enum BattleAnimBg bg) {
    return sBattleAnimBgMaskLayers[bg];
}

int BattleAnimSystem_GetBgPriority(BattleAnimSystem *system, int kind) {
    switch (kind) {
    case BATTLE_ANIM_BG_WINDOW:
        return 0;
    case BATTLE_ANIM_BG_EFFECT:
        return 1;
    case BATTLE_ANIM_BG_BATTLE:
        return 3;
    case 3:
        return BattleAnimSystem_GetBasePriority(system);
    }
    // no return value for other kinds
}

static void BattleAnimSystem_LoadBattleBgTiles(BattleAnimSystem *system, GFBgLayer layer) {
    BG_LoadCharTilesData(system->bgConfig, layer, system->context->battleBgTiles, 0x10000, 0);
}

static void BattleAnimSystem_LoadBattleBgPalette(BattleAnimSystem *system) {
    PaletteData_LoadPalette(system->paletteData, system->context->battleBgPalette, PLTTBUF_MAIN_BG, 0, 0x200);
}

BOOL BattleAnimSystem_ShouldFlipSide(BattleAnimSystem *system, int side) {
    return FALSE;
}

u32 BattleAnimSystem_GetBackgroundFile(u32 bgId, int file) {
    return sBattleAnimBackgroundFiles[bgId][file];
}

BattleAnimBattlerSprites *BattleAnimBattlerSprites_New(BattleSystem *battleSystem, enum HeapID heapId, int battler) {
    u32 priorities[6];
    int resIds[6];
    ManagedSpriteTemplate template;
    BattleAnimBattlerSprites *sprites;
    int i;
    NARC *narc;
    int j;
    int slot;
    int resId;
    Pokepic *pokepic;
    MonPicData *picData;
    ManagedSprite *sprite;
    NarcId paletteNarc;
    int paletteMember;
    s16 y;
    int shiftedY;

    ARRAY_ASSIGN(priorities, sBattleAnimBattlerSpritePriorities);
    sprites = Heap_Alloc(heapId, sizeof(BattleAnimBattlerSprites));
    sprites->heapId = heapId;
    sprites->battler = battler;
    sprites->spriteSystem = BattleSystem_GetSpriteSystem(battleSystem);
    sprites->spriteManager = BattleSystem_GetSpriteManager(battleSystem);
    sprites->paletteData = BattleSystem_GetPaletteData(battleSystem);
    for (i = 0; i < 4; i++) {
        sprites->sprites[i] = NULL;
        sprites->picData[i] = BattleSystem_GetMonPicData(battleSystem, i);
    }
    BattleSystem_GetBattlerTypes(battleSystem, sprites->battlerTypes);
    BattleSystem_GetPokepics(battleSystem, sprites->pokepics);
    narc = NARC_New(NARC_a_0_0_8, heapId);
    for (i = 0; i < BATTLER_MAX; ++i) {
        if ((i == sprites->battler || sprites->battler == 0xFF) && sprites->pokepics[i] != NULL) {
            resId = i + 55555 + 5000 * sprites->battler;
            SpriteSystem_LoadCharResObjFromOpenNarc(sprites->spriteSystem, sprites->spriteManager, narc, 76, FALSE, 1, resId);
            SpriteSystem_LoadPaletteBufferFromOpenNarc(sprites->paletteData, PLTTBUF_MAIN_OBJ, sprites->spriteSystem, sprites->spriteManager, narc, 75, FALSE, 1, 1, resId);
            SpriteSystem_LoadCellResObjFromOpenNarc(sprites->spriteSystem, sprites->spriteManager, narc, 77, FALSE, resId);
            SpriteSystem_LoadAnimResObjFromOpenNarc(sprites->spriteSystem, sprites->spriteManager, narc, 78, FALSE, resId);
        }
    }
    NARC_Delete(narc);
    for (slot = 0; slot < 4; slot++) {
        u8 *pixels;
        int x;
        if (slot != sprites->battler && sprites->battler != 0xFF) {
            continue;
        }
        sprites->resIds[slot] = slot + 55555 + 5000 * sprites->battler;
        resIds[0] = slot + 55555 + 5000 * sprites->battler;
        resIds[1] = slot + 55555 + 5000 * sprites->battler;
        resIds[2] = 5000 * sprites->battler + (slot + 55555);
        resIds[3] = slot + 55555 + 5000 * sprites->battler;
        resIds[4] = 0;
        resIds[5] = 0;
        picData = sprites->picData[slot];
        paletteNarc = (NarcId)picData->narcId;
        paletteMember = picData->paletteId;
        pixels = picData->charBuffer;
        pokepic = sprites->pokepics[slot];
        if (pokepic == NULL) {
            continue;
        }
        x = Pokepic_GetAttr(pokepic, POKEPIC_X);
        y = Pokepic_GetAttr(pokepic, POKEPIC_Y);
        shiftedY = y - Pokepic_GetAttr(pokepic, POKEPIC_SHADOW_H);
        template.x = x;
        template.y = shiftedY;
        template.z = 0;
        template.animation = 0;
        template.drawPriority = priorities[sprites->battlerTypes[slot]];
        template.pal = 0;
        template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
        template.bgPriority = 1;
        template.vramTransfer = FALSE;
        for (j = 0; j < 6; j++) {
            template.resIdList[j] = resIds[j];
        }
        sprite = SpriteSystem_NewSprite(sprites->spriteSystem, sprites->spriteManager, &template);
        ManagedSprite_TickFrame(sprite);
        sprites->sprites[slot] = sprite;
        if (pokepic == NULL) {
            ManagedSprite_SetDrawFlag(sprite, FALSE);
        } else if (!Pokepic_IsActive(pokepic)) {
            ManagedSprite_SetDrawFlag(sprite, FALSE);
        } else if (Pokepic_GetAttr(pokepic, POKEPIC_VANISHED) == TRUE) {
            ManagedSprite_SetDrawFlag(sprite, FALSE);
        }
        if (pokepic != NULL) {
            GF_CreateNewVramTransferTask(NNS_GFD_DST_2D_OBJ_CHAR_MAIN, Sprite_GetImageProxy(sprite->sprite)->vramLocation.baseAddrOfVram[NNS_G2D_VRAM_TYPE_2DMAIN], pixels, 3200);
        }
        if (pokepic != NULL) {
            PaletteData_LoadNarc(sprites->paletteData, paletteNarc, paletteMember, sprites->heapId, PLTTBUF_MAIN_OBJ, 32, ObjPlttTransfer_GetPaletteVramOffset(Sprite_GetPaletteProxy(sprite->sprite), NNS_G2D_VRAM_TYPE_2DMAIN) * 16);
        }
    }
    return sprites;
}

BattleAnimBattlerSprites *BattleAnimBattlerSprites_NewAll(BattleSystem *battleSystem, enum HeapID heapId) {
    return BattleAnimBattlerSprites_New(battleSystem, heapId, 0xFF);
}

void BattleAnimBattlerSprites_Free(BattleAnimBattlerSprites *sprites) {
    int i;
    for (i = 0; i < 4; i++) {
        if (sprites->sprites[i]) {
            SpriteManager_UnloadCharObjById(sprites->spriteManager, sprites->resIds[i]);
            SpriteManager_UnloadPlttObjById(sprites->spriteManager, sprites->resIds[i]);
            Sprite_DeleteAndFreeResources(sprites->sprites[i]);
        }
    }
    Heap_Free(sprites);
}

void BattleAnimBattlerSprites_Free2(BattleAnimBattlerSprites *sprites, int battler) {
    int i;
    for (i = 0; i < 4; i++) {
        if (sprites->sprites[i]) {
            SpriteManager_UnloadCharObjById(sprites->spriteManager, sprites->resIds[i]);
            SpriteManager_UnloadPlttObjById(sprites->spriteManager, sprites->resIds[i]);
            Sprite_DeleteAndFreeResources(sprites->sprites[i]);
        }
    }
    Heap_Free(sprites);
}

u8 BattleAnimIndexedBytes_GetCurrentValue(BattleAnimIndexedBytes *data) {
    GF_ASSERT(data != NULL);
    return data->values[data->index];
}

void BattleAnimEmitterCb_None(SPLEmitter *emitter) {
}

SPLEmitter *BattleAnimSystem_NewParticleSystem(enum HeapID heapId, int resId, BOOL loadNow) {
    SPLEmitter *particleSystem = BattleParticleSystem_New(heapId);
    void *resource = ParticleSystem_LoadResourceFile(NARC_a_0_2_9, resId, heapId);
    ParticleSystem_SetResource(particleSystem, resource, 10, loadNow);
    return particleSystem;
}

SPLEmitter *BattleAnimSystem_NewParticleSystemFromNarc(enum HeapID heapId, NarcId narcId, int resId, BOOL loadNow) {
    SPLEmitter *particleSystem = BattleParticleSystem_New(heapId);
    void *resource = ParticleSystem_LoadResourceFile(narcId, resId, heapId);
    ParticleSystem_SetResource(particleSystem, resource, 10, loadNow);
    return particleSystem;
}

static void *BattleAnimSystem_ReadNarcMember(NARC *narc, int member, enum HeapID heapId) {
    return NARC_AllocAndReadWholeMember(narc, member, heapId);
}

SPLEmitter *BattleAnimSystem_NewParticleSystemFromOpenNarc(NARC *narc, enum HeapID heapId, int member, BOOL loadNow) {
    SPLEmitter *particleSystem = BattleParticleSystem_NewSmallHeap(heapId);
    void *resource;
    if (particleSystem == NULL) {
        return NULL;
    }
    resource = BattleAnimSystem_ReadNarcMember(narc, member, heapId);
    ParticleSystem_SetResource(particleSystem, resource, 10, loadNow);
    return particleSystem;
}

static SPLEmitter *BattleAnimSystem_CreateEmitter(SPLEmitter *particleSystem, int resId, int callback, BattleAnimSystem *system) {
    return ParticleSystem_CreateEmitterWithParam(particleSystem, resId, gBattleAnimEmitterCallbackTable[callback], system);
}

void BattleAnimSystem_FreeParticleSystem(SPLEmitter *particleSystem) {
    BattleParticleSystem_Free(particleSystem);
}

int BattleAnimSystem_GetSideSign(BattleAnimSystem *system, int battlerA, int battlerB) {
    int result = 1;
    u32 type = BattleAnimUtil_GetBattlerType(system, battlerA);
    BattleAnimUtil_GetBattlerType(system, battlerB);
    switch (type) {
    case BATTLER_TYPE_SOLO_PLAYER:
        break;
    case BATTLER_TYPE_PLAYER_SIDE_SLOT_1:
        break;
    case BATTLER_TYPE_PLAYER_SIDE_SLOT_2:
        break;
    case BATTLER_TYPE_SOLO_ENEMY:
        result -= 2;
        break;
    case BATTLER_TYPE_ENEMY_SIDE_SLOT_1:
        result -= 2;
        break;
    case BATTLER_TYPE_ENEMY_SIDE_SLOT_2:
        result -= 2;
        break;
    }
    return result;
}

void BattleAnimEmitterCb_Dummy(void) {
}
