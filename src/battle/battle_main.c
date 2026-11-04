#include "battle/battle_main.h"

#include <nitro/wm/wm_internal.h>

#include "global.h"

#include "constants/battle.h"
#include "constants/battle_menu.h"
#include "constants/game_stats.h"
#include "constants/pokemon.h"
#include "constants/sndseq.h"
#include "constants/trainer_class.h"

#include "battle/battle.h"
#include "battle/battle_022378C0.h"
#include "battle/battle_controller_opponent.h"
#include "battle/battle_controller_packets.h"
#include "battle/battle_controller_player.h"
#include "battle/battle_input.h"
#include "battle/battle_recording_stop.h"
#include "battle/battle_setup.h"
#include "battle/battle_system.h"
#include "battle/battle_terrain.h"
#include "battle/battle_util.h"
#include "battle/link_battle_screen.h"
#include "dwc/net_common_internal.h"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0197.h"

#include "bag.h"
#include "bag_cursor.h"
#include "battle_link_comm.h"
#include "battle_record.h"
#include "comm_state.h"
#include "comm_state_internal.h"
#include "comm_wireless.h"
#include "communication_core.h"
#include "filesystem_files_def.h"
#include "font.h"
#include "game_stats.h"
#include "gf_3d_vramman.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "link_synchronization.h"
#include "math_util.h"
#include "message_printer.h"
#include "msgdata.h"
#include "overlay_06.h"
#include "overlay_07.h"
#include "palette.h"
#include "palette_blink.h"
#include "palette_vram_addr.h"
#include "particle_system.h"
#include "particle_system_internal.h"
#include "party.h"
#include "player_data.h"
#include "poke_overlay.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_mood.h"
#include "pokepic_anim_internal.h"
#include "render_text.h"
#include "render_window.h"
#include "screen_fade_legacy.h"
#include "sound_playback.h"
#include "sound_system.h"
#include "swap_3d_buffers.h"
#include "sys_task_api.h"
#include "system.h"
#include "text.h"
#include "touchpad.h"
#include "ui_util.h"
#include "vram_transfer_manager.h"
#include "wireless_status_icon.h"

static BOOL Battle_IsLeagueTrainerClass(int trainerClass);
static GF3DVramMan *Battle_Create3DVramMan(void);
static void Battle_Setup3D(void);
static void Battle_Delete3DVramMan(GF3DVramMan *vramMan);
static void Battle_ReserveTexAndPlttVram(void);
static void Task_DrawBattleGraphics(SysTask *task, void *data);
static void Task_UpdateCriticalHpMusic(SysTask *task, void *data);
static void VBlankTask_ScrollBattleBackground(SysTask *task, void *data);
static void BattleSystem_ChooseLinkServer(BattleSystem *battleSystem, BattleSetup *setup);
static void Battle_CreateWirelessStatusIcon(void);

FS_EXTERN_OVERLAY(OVY_5);
FS_EXTERN_OVERLAY(OVY_6);
FS_EXTERN_OVERLAY(OVY_18);

const BattleBgTemplateSet gBattleReinitBgTemplates = {
    .templates = {
        {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x0000,
            .charBase = GX_BG_CHARBASE_0x04000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
        {
            .x = 0,
            .y = 0,
            .bufferSize = 0x2000,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_512x512,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x1000,
            .charBase = GX_BG_CHARBASE_0x0c000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
        {
            .x = 0,
            .y = 0,
            .bufferSize = 0x1000,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_512x256,
            .colorMode = GX_BG_COLORMODE_256,
            .screenBase = GX_BG_SCRBASE_0x3000,
            .charBase = GX_BG_CHARBASE_0x10000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 3,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
    },
};

static const u8 sLinkSinglesBattlerTypes[4] = { 0, 1, 1, 0 };

static const u8 sSinglesBattlerTypes[4] = { 0, 1, 0, 0 };

static const u8 sLinkDoublesBattlerTypes[2][4] = { { 2, 3, 4, 5 }, { 3, 2, 5, 4 } };

static const GraphicsModes sBattleGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_3D,
};

static const GraphicsModes sLinkGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_3D,
};

static const u8 sLinkMultiBattlerTypes[4][4] = { { 2, 5, 4, 3 }, { 3, 4, 5, 2 }, { 2, 5, 4, 3 }, { 3, 4, 5, 2 } };

static const OamCharTransferParam sBattleOamCharTransferParam = {
    .maxTasks = 96,
    .sizeMain = 0x10000,
    .sizeSub = 0x4000,
    .charModeMain = GX_OBJVRAMMODE_CHAR_1D_64K,
    .charModeSub = GX_OBJVRAMMODE_CHAR_1D_32K,
};

static const SpriteResourceCountsListUnion sBattleSpriteResourceCounts = { 96, 32, 64, 64, 8, 8 };

static const BgTemplate sLinkBgTemplate = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0x0000,
    .charBase = GX_BG_CHARBASE_0x04000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const OamManagerParam sBattleOamManagerParam = {
    .fromOBJmain = 0,
    .numOBJmain = 128,
    .fromAffineMain = 0,
    .numAffineMain = 32,
    .fromOBJsub = 0,
    .numOBJsub = 128,
    .fromAffineSub = 0,
    .numAffineSub = 32,
};

static const GraphicsBanks sBattleGraphicsBanks = {
    .bg = GX_VRAM_BG_128_A,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_32_H,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_64_E,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_01_BC,
    .texpltt = GX_VRAM_TEXPLTT_01_FG,
};

static const GraphicsBanks sBattleRestoreGraphicsBanks = {
    .bg = GX_VRAM_BG_128_A,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_32_H,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_64_E,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_01_BC,
    .texpltt = GX_VRAM_TEXPLTT_01_FG,
};

static const GraphicsBanks sLinkGraphicsBanks = {
    .bg = GX_VRAM_BG_128_A,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_32_H,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_64_E,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_01_BC,
    .texpltt = GX_VRAM_TEXPLTT_01_FG,
};

static const GraphicsBanks sSubMenuGraphicsBanks = {
    .bg = GX_VRAM_BG_128_A,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_128_C,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_64_E,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_0_B,
    .texpltt = GX_VRAM_TEXPLTT_01_FG,
};

void Battle_BattleInit(OverlayManager *manager) {
    BattleSystem *battleSystem = OverlayManager_GetData(manager);
    BattleSetup *setup = OverlayManager_GetArgs(manager);
    NARC *archive7;
    NARC *archive8;
    int paletteSize;
    int i;
    int colorIndex;
    u32 gender;

    paletteSize = GetMainBgPlttSize();
    MIi_CpuClear16(0, GetMainBgPlttAddr(), paletteSize);
    paletteSize = GetSubBgPlttSize();
    MIi_CpuClear16(0, GetSubBgPlttAddr(), paletteSize);
    battleSystem->gf3dVramMan = Battle_Create3DVramMan();
    HBlankInterruptDisable();
    FontID_Alloc(4, HEAP_ID_BATTLE);
    battleSystem->hpNumPrinter = (void *)MessagePrinter_New(14, 2, 15, HEAP_ID_BATTLE);
    battleSystem->levelNumPrinter = battleSystem->hpNumPrinter;
    battleSystem->palette = PaletteData_Init(HEAP_ID_BATTLE);
    PaletteData_SetAutoTransparent(battleSystem->palette, TRUE);
    PaletteData_AllocBuffers(battleSystem->palette, PLTTBUF_MAIN_BG, 512, HEAP_ID_BATTLE);
    PaletteData_AllocBuffers(battleSystem->palette, PLTTBUF_SUB_BG, 512, HEAP_ID_BATTLE);
    PaletteData_AllocBuffers(battleSystem->palette, PLTTBUF_MAIN_OBJ, 448, HEAP_ID_BATTLE);
    PaletteData_AllocBuffers(battleSystem->palette, PLTTBUF_SUB_OBJ, 512, HEAP_ID_BATTLE);
    battleSystem->bgConfig = BgConfig_Alloc(HEAP_ID_BATTLE);
    battleSystem->window = AllocWindows(HEAP_ID_BATTLE, 3);
    for (i = 0; i < BATTLER_MAX; i++) {
        battleSystem->monPicData[i].charBuffer = Heap_Alloc(HEAP_ID_BATTLE, 3200);
    }
    GF_CreateVramTransferManager(64, HEAP_ID_BATTLE);

    archive7 = NARC_New(NARC_a_0_0_7, HEAP_ID_BATTLE);
    archive8 = NARC_New(NARC_a_0_0_8, HEAP_ID_BATTLE);
    gender = BattleSystem_GetTrainerGender(battleSystem, BattleSystem_GetNetworkId(battleSystem));
    battleSystem->battleInput = BattleInput_NewInit(archive7, archive8, battleSystem, gender, battleSystem->keyPressedSave);
    NARC_Delete(archive7);
    NARC_Delete(archive8);

    Battle_InitBackgrounds(battleSystem, battleSystem->bgConfig);
    AddWindowParameterized(battleSystem->bgConfig, battleSystem->window, GF_BG_LYR_MAIN_1, 2, 19, 27, 4, 11, 31);
    FillWindowPixelBuffer(battleSystem->window, 255);
    DrawFrameAndWindow2(battleSystem->window, FALSE, 1, 10);
    battleSystem->spriteRenderer = SpriteSystem_Alloc(HEAP_ID_BATTLE);
    SpriteSystem_Init(battleSystem->spriteRenderer, &sBattleOamManagerParam, &sBattleOamCharTransferParam, 32);
    G2dRenderer_SetObjCharTransferReservedRegion(NNS_G2D_VRAM_TYPE_2DMAIN, GX_OBJVRAMMODE_CHAR_1D_64K);
    G2dRenderer_SetPlttTransferReservedRegion(NNS_G2D_VRAM_TYPE_2DMAIN);
    battleSystem->gfxHandler = SpriteManager_New(battleSystem->spriteRenderer);
    SpriteSystem_InitSprites(battleSystem->spriteRenderer, battleSystem->gfxHandler, 128);
    SpriteSystem_InitManagerWithCapacities(battleSystem->spriteRenderer, battleSystem->gfxHandler, (SpriteResourceCountsListUnion *)&sBattleSpriteResourceCounts);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(battleSystem->spriteRenderer), 0, 0x110000);
    BattleInput_LoadDefaultResources(battleSystem->battleInput);

    archive7 = NARC_New(NARC_a_0_0_7, HEAP_ID_BATTLE);
    archive8 = NARC_New(NARC_a_0_0_8, HEAP_ID_BATTLE);
    BattleInput_ChangeMenu(archive7, archive8, battleSystem->battleInput, BATTLE_MENU_0, 1, NULL);
    BattleInput_LoadBallGaugeResources(archive8, battleSystem->battleInput);
    NARC_Delete(archive7);
    NARC_Delete(archive8);

    battleSystem->pokepicManager = PokepicManager_Create(HEAP_ID_BATTLE);
    PokepicManager_SetPlttBaseAddrAndSize(battleSystem->pokepicManager, 0, 192);
    BattleSystem_HpBar_Init(battleSystem);
    Battle_ReserveTexAndPlttVram();
    battleSystem->animSystem = BattleAnimSystem_New(HEAP_ID_BATTLE);
    BattleSystem_InitTerrainsAndBalls(battleSystem);
    GF_TouchpadResetSampling();
    GF_TouchpadStartSampling(4);
    battleSystem->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0197_bin, HEAP_ID_BATTLE);
    battleSystem->attackMsgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0003_EVERYWHERE_bin, HEAP_ID_BATTLE);
    battleSystem->msgFormat = MessageFormat_New(HEAP_ID_BATTLE);
    battleSystem->msgBuffer = String_New(320, HEAP_ID_BATTLE);
    MIi_CpuCopy16(PaletteData_GetUnfadedBuf(battleSystem->palette, PLTTBUF_MAIN_BG), battleSystem->bgPaletteBackup, 224);
    MIi_CpuCopy16(PaletteData_GetUnfadedBuf(battleSystem->palette, PLTTBUF_MAIN_OBJ), battleSystem->objPaletteBackup, 224);
    colorIndex = BattleSystem_GetBgTimeOfDay(battleSystem);
    PaletteData_FillPaletteInBuffer(battleSystem->palette, PLTTBUF_MAIN_BG, PLTTSEL_BOTH, gBattleBgFillColors[battleSystem->backgroundId][colorIndex], 0, 112);
    PaletteData_FillPaletteInBuffer(battleSystem->palette, PLTTBUF_MAIN_BG, PLTTSEL_BOTH, gBattleBgFillColors[battleSystem->backgroundId][colorIndex], 192, 256);
    PaletteData_FillPaletteInBuffer(battleSystem->palette, PLTTBUF_MAIN_OBJ, PLTTSEL_BOTH, gBattleBgFillColors[battleSystem->backgroundId][colorIndex], 0, 223);
    PaletteData_FillPaletteInBuffer(battleSystem->palette, PLTTBUF_MAIN_BG, PLTTSEL_TRANSPARENT, 0, 160, 192);
    PaletteData_FillPaletteInBuffer(battleSystem->palette, PLTTBUF_SUB_BG, PLTTSEL_TRANSPARENT, 0, 0, 255);
    PaletteData_FillPaletteInBuffer(battleSystem->palette, PLTTBUF_SUB_OBJ, PLTTSEL_TRANSPARENT, 65535, 0, 255);
    battleSystem->msgIcon = PaletteBlink_New(battleSystem->palette, PM_LCD_TOP, 11, HEAP_ID_BATTLE);
    PaletteBlink_SetState(battleSystem->msgIcon, 1);
    battleSystem->drawGraphicsTask = (u32)SysTask_CreateOnMainQueue(Task_DrawBattleGraphics, battleSystem, 60000);
    battleSystem->criticalHpMusicTask = (u32)SysTask_CreateOnMainQueue(Task_UpdateCriticalHpMusic, battleSystem, 50000);
    battleSystem->scrollBgTask = (u32)SysTask_CreateOnVBlankQueue(VBlankTask_ScrollBattleBackground, battleSystem, 1200);
    battleSystem->bgScrollY = -51;
    BattleSystem_SetupTextFlags(battleSystem);
    BagCursor_Battle_Init(BattleSystem_GetBagCursor(battleSystem));
    battleSystem->pokepicAnimManager = PokepicAnimManager_New(HEAP_ID_BATTLE, 4, FALSE);
    battleSystem->cellTransferState = CreateCellTransferStateManager(4, HEAP_ID_BATTLE);
    if (battleSystem->battleSpecial & BATTLE_SPECIAL_RECORDING) {
        for (i = 0; i < BATTLER_MAX; i++) {
            battleSystem->chatotVoiceParam[i] = setup->chatotVoiceParam[i];
        }
    }
}

BOOL Battle_BattleMain(OverlayManager *man) {
    BattleSystem *battleSystem = OverlayManager_GetData(man);
    int i;

    if ((battleSystem->battleType & BATTLE_TYPE_LINK) && !(battleSystem->battleSpecial & BATTLE_SPECIAL_RECORDING)) {
        if (battleSystem->isServer) {
            BattleContext_Main(battleSystem, battleSystem->ctx);
        }
        for (i = 0; i < battleSystem->maxBattlers; i++) {
            OpponentData_RunCommand(battleSystem, battleSystem->opponentData[i]);
        }
    } else {
        if (battleSystem->isServer) {
            battleSystem->battleFinished = BattleContext_Main(battleSystem, battleSystem->ctx);
            BattleController_ProcessQueue(battleSystem, BATTLE_PACKET_COMMAND);
        }
        for (i = 0; i < battleSystem->maxBattlers; i++) {
            OpponentData_RunCommand(battleSystem, battleSystem->opponentData[i]);
            BattleController_ProcessQueue(battleSystem, BATTLE_PACKET_REPLY);
        }
        if (!battleSystem->battleFinished) {
            if (battleSystem->isServer) {
                battleSystem->battleFinished = BattleContext_Main(battleSystem, battleSystem->ctx);
                BattleController_ProcessQueue(battleSystem, BATTLE_PACKET_COMMAND);
            }
            for (i = 0; i < battleSystem->maxBattlers; i++) {
                OpponentData_RunCommand(battleSystem, battleSystem->opponentData[i]);
                BattleController_ProcessQueue(battleSystem, BATTLE_PACKET_REPLY);
            }
        }
    }

    return battleSystem->battleFinished;
}

void Battle_BattleExit(OverlayManager *man) {
    BattleSystem *battleSystem = OverlayManager_GetData(man);
    BattleSetup *setup = OverlayManager_GetArgs(man);
    int color;
    int i;

    setup->randSeed = battleSystem->randTemp;
    setup->battleSpecial = battleSystem->battleSpecial;
    if (!(battleSystem->battleSpecial & BATTLE_SPECIAL_RECORDING)) {
        BattleRecord_StoreSetup(setup);
    }
    if (battleSystem->trainerAIOverlayLoaded) {
        BattleSystem_SetTrainerAIOverlayLoaded(battleSystem, 0);
    }
    if (setup->battleType & 0xAA4) {
        color = 0;
    } else if ((u8)(battleSystem->battleOutcomeFlag + 254) <= 1) {
        color = 0x7FFF;
    } else {
        color = 0;
    }
    SetMasterBrightnessByColor(PM_LCD_TOP, color);
    SetMasterBrightnessByColor(PM_LCD_BOTTOM, color);
    BattleSystem_TryChangeForm(battleSystem);
    if (battleSystem->battleOutcomeFlag != BATTLE_OUTCOME_MON_CAUGHT) {
        BattleSystem_EmptyMonFunc(battleSystem, Party_GetMonByIndex(battleSystem->trainerParty[1], 0));
    }
    for (i = 0; i < BATTLER_MAX; i++) {
        Party_Copy(battleSystem->trainerParty[i], setup->party[i]);
        Heap_Free(battleSystem->trainerParty[i]);
        PlayerProfile_Copy(battleSystem->playerProfile[i], setup->profile[i]);
        Heap_Free(battleSystem->playerProfile[i]);
    }
    PaletteBlink_Delete(battleSystem->msgIcon);
    Save_Bag_Copy(battleSystem->bag, setup->bag);
    Heap_Free(battleSystem->bag);
    Pokedex_Copy(battleSystem->pokedex, setup->pokedex);
    Heap_Free(battleSystem->pokedex);
    setup->storagePC = battleSystem->storage;
    setup->bagCursor = battleSystem->bagCursor;
    setup->keyPressedSave = battleSystem->keyPressedSave;
    setup->unk_128 = battleSystem->unk98;
    setup->unk_134 = battleSystem->unk9C;
    setup->safariBalls = battleSystem->safariBallCnt;
    setup->winFlag = battleSystem->battleOutcomeFlag & 0x3F;
    setup->caughtBattlerId = battleSystem->caughtBattlerId;
    setup->levelUpFlag = BattleContext_Get(battleSystem, battleSystem->ctx, 4, 0);
    setup->battleTotals.totalTurns += BattleContext_Get(battleSystem, battleSystem->ctx, 3, 0);
    setup->battleTotals.totalTimesFainted += BattleContext_Get(battleSystem, battleSystem->ctx, 6, 0) + BattleContext_Get(battleSystem, battleSystem->ctx, 6, 2);
    setup->battleTotals.totalDamage += BattleContext_Get(battleSystem, battleSystem->ctx, 7, 0) + BattleContext_Get(battleSystem, battleSystem->ctx, 7, 2);
    setup->totalTurns = BattleContext_Get(battleSystem, battleSystem->ctx, 3, 0);
    setup->isRecordingPaused = battleSystem->isRecordingPaused;
    for (i = 0; i < BATTLER_MAX; i++) {
        Heap_Free(battleSystem->monPicData[i].charBuffer);
    }
    Heap_Free(battleSystem->msgBuffer);
    PaletteData_FreeBuffers(battleSystem->palette, PLTTBUF_MAIN_BG);
    PaletteData_FreeBuffers(battleSystem->palette, PLTTBUF_SUB_BG);
    PaletteData_FreeBuffers(battleSystem->palette, PLTTBUF_MAIN_OBJ);
    PaletteData_FreeBuffers(battleSystem->palette, PLTTBUF_SUB_OBJ);
    PaletteData_Free(battleSystem->palette);
    DestroyMsgData(battleSystem->msgData);
    DestroyMsgData(battleSystem->attackMsgData);
    MessageFormat_Delete(battleSystem->msgFormat);
    PokepicAnimManager_Delete(battleSystem->pokepicAnimManager);
    ParticleSystem_FreeAll();
    BattleAnimSystem_Delete(battleSystem->animSystem);
    BattleContext_Delete(battleSystem->ctx);
    for (i = 0; i < battleSystem->maxBattlers; i++) {
        OpponentData_Free(battleSystem, battleSystem->opponentData[i], battleSystem->graphicsMode);
    }
    PokepicManager_Delete(battleSystem->pokepicManager);
    if (battleSystem->graphicsMode != 2) {
        BattleSystem_FreeGraphics(battleSystem);
    }
    TextFlags_SetCanABSpeedUpPrint(FALSE);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    WindowArray_Delete(battleSystem->window, 3);
    Heap_Free(battleSystem->bgConfig);
    Heap_Free(battleSystem->bgTiles);
    Heap_Free(battleSystem->bgPalette);
    MessagePrinter_Delete((MessagePrinter *)battleSystem->hpNumPrinter);
    SysTask_Destroy((SysTask *)battleSystem->drawGraphicsTask);
    SysTask_Destroy((SysTask *)battleSystem->criticalHpMusicTask);
    GF_TouchpadStopSampling();
    Battle_Delete3DVramMan(battleSystem->gf3dVramMan);
    SetLCRNGSeed(battleSystem->lcrngSeedBackup);
    if (BattleSystem_GetCriticalHpMusicFlag(battleSystem)) {
        StopSE(SEQ_SE_DP_HINSI, 0);
    }
    DestroyCellTransferStateManager(battleSystem->cellTransferState);
    if (BattleSystem_IsRecordingPaused(battleSystem)) {
        Sound_SetMasterVolume(127);
    }
    if (battleSystem->recordingStopTask) {
        BattleRecordingStop_DestroyTask(battleSystem->recordingStopTask);
    }
    Heap_Free(battleSystem);
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_6));
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_7));
    if (!CommState_IsWifi()) {
        UnloadOverlayByID(FS_OVERLAY_ID(OVY_18));
    }
}

void Battle_InitBackgrounds(BattleSystem *battleSystem, BgConfig *bgConfig) {
    BattleBgTemplateSet templates;
    GraphicsBanks banks;
    GraphicsModes modes;
    u32 frame;

    GfGfx_DisableEngineAPlanes();

    banks = sBattleGraphicsBanks;
    GfGfx_SetBanks(&banks);

    MI_CpuClear32((void *)HW_BG_VRAM, HW_BG_VRAM_SIZE);
    MI_CpuClear32((void *)HW_DB_BG_VRAM, HW_DB_BG_VRAM_SIZE);
    MI_CpuClear32((void *)HW_OBJ_VRAM, HW_OBJ_VRAM_SIZE);
    MI_CpuClear32((void *)HW_DB_OBJ_VRAM, HW_DB_OBJ_VRAM_SIZE);

    SetMasterBrightnessNeutral(PM_LCD_TOP);
    SetMasterBrightnessNeutral(PM_LCD_BOTTOM);

    modes = sBattleGraphicsModes;
    SetBothScreensModesAndDisable(&modes);

    battleSystem->resetBlendRequested = 1;

    templates = gBattleBgTemplates;

    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &templates.templates[0], GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &templates.templates[1], GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &templates.templates[2], GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);

    G2_SetBG0Priority(1);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);

    BgConfig_InitBattleMenuBackgrounds(bgConfig);

    frame = BattleSystem_GetFrame(battleSystem);
    LoadUserFrameGfx2WithFill(bgConfig, GF_BG_LYR_MAIN_1, 1, 10, frame, HEAP_ID_BATTLE);

    GfGfxLoader_LoadCharData(NARC_a_0_0_7, battleSystem->backgroundId + 3, bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_BATTLE);
    PaletteData_LoadNarc(battleSystem->palette, NARC_a_0_0_7, battleSystem->backgroundId * 3 + 0xB0 + BattleSystem_GetBgTimeOfDay(battleSystem), HEAP_ID_BATTLE, PLTTBUF_MAIN_BG, 0, 0);
    PaletteData_LoadNarc(battleSystem->palette, NARC_a_0_3_8, GetUserFrameGfx2PaletteMember(frame), HEAP_ID_BATTLE, PLTTBUF_MAIN_BG, 0x20, 0xA0);
    PaletteData_LoadNarc(battleSystem->palette, NARC_graphic_font, 8, HEAP_ID_BATTLE, PLTTBUF_MAIN_BG, 0x20, 0xB0);
    GfGfxLoader_LoadScrnData(NARC_a_0_0_7, 2, bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_BATTLE);

    GX_SetVisibleWnd(GX_WNDMASK_NONE);
    GXS_SetVisibleWnd(GX_WNDMASK_NONE);
    G2_SetWnd0InsidePlane(GX_WND_PLANEMASK_NONE, FALSE);
    G2_SetWndOutsidePlane(GX_WND_PLANEMASK_NONE, FALSE);

    GfGfx_BothDispOn();
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);

    Main_SetVBlankIntrCB(Battle_VBlankCallback, battleSystem);
}

void BattleSystem_InitTerrainsAndBalls(BattleSystem *battleSystem) {
    BattleContext *ctx;
    int i;
    Terrain terrain = BattleSystem_GetTerrainId(battleSystem);

    BattleTerrain_Init(&battleSystem->terrains[0], battleSystem, 0, terrain);
    BattleTerrain_Init(&battleSystem->terrains[1], battleSystem, 1, terrain);

    ctx = BattleSystem_GetBattleContext(battleSystem);

    for (i = 0; i < battleSystem->maxBattlers; i++) {
        int battlerId = BattleContext_Get(battleSystem, ctx, 2, i);
        OpponentData_CreateBallData(battleSystem, battleSystem->opponentData[i], BattleSystem_GetMonBall(battleSystem, BattleSystem_GetPartyMon(battleSystem, i, battlerId)), battlerId);
    }

    Battle_CreateWirelessStatusIcon();
}

void BgConfig_CleanupBattleBackgrounds(BgConfig *bgConfig) {
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_OFF);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_3);
    BgConfig_CleanupBattleMenuBackgrounds(bgConfig);
}

void BattleSystem_FreeGraphicsDummy(BattleSystem *battleSystem) {
}

static void BattleSystem_InitFromSetup(BattleSystem *battleSystem, BattleSetup *setup) {
    int i, slot;
    BattlerInitData battlerInitData;
    Pokemon *mon;

    battleSystem->battleType = setup->battleType;

    for (i = 0; i < BATTLER_MAX; i++) {
        battleSystem->playerProfile[i] = PlayerProfile_New(HEAP_ID_BATTLE);
        PlayerProfile_Copy(setup->profile[i], battleSystem->playerProfile[i]);
        battleSystem->chatotVoice[i] = setup->chatot[i];
    }

    battleSystem->networkId = setup->networkId;

    for (i = 0; i < BATTLER_MAX; i++) {
        battleSystem->linkPositions[i] = setup->linkPositions[i];
    }

    battleSystem->lcrngSeedBackup = GetLCRNGSeed();
    battleSystem->rand = setup->randSeed;
    battleSystem->randTemp = setup->randSeed;
    battleSystem->battleSpecial = setup->battleSpecial;
    battleSystem->bag = Save_Bag_New(HEAP_ID_BATTLE);
    Save_Bag_Copy(setup->bag, battleSystem->bag);
    battleSystem->pokedex = Pokedex_New(HEAP_ID_BATTLE);
    Pokedex_Copy(setup->pokedex, battleSystem->pokedex);

    battleSystem->storage = setup->storagePC;
    battleSystem->options = setup->options;
    battleSystem->palPad = setup->palPad;
    battleSystem->bagCursor = setup->bagCursor;
    battleSystem->keyPressedSave = setup->keyPressedSave;
    battleSystem->unk98 = setup->unk_128;
    battleSystem->evolutionLocation = setup->evolutionLocation;
    battleSystem->unk9C = setup->unk_134;
    battleSystem->safariBallCnt = setup->safariBalls;
    battleSystem->terrain = setup->terrain;
    battleSystem->backgroundId = setup->battleBg;
    battleSystem->location = setup->mapSection;
    battleSystem->timezone = setup->timeOfDay;
    battleSystem->regulationFlag = setup->fixedDamaageMovesBanned;
    battleSystem->unk2428 = setup->unk_164;
    battleSystem->metBill = setup->metBill;
    battleSystem->momsSavingsActive = setup->momsSavingsActive;
    battleSystem->isFishing = setup->isFishing;
    battleSystem->weather = setup->weatherType;
    battleSystem->gameStats = setup->gameStats;

    GF_ASSERT(setup->gameStats != NULL);
    battleSystem->bugContestCaughtMon = setup->bugContestMon;

    for (i = 0; i < BATTLER_MAX; i++) {
        battleSystem->trainerId[i] = setup->trainerId[i];
        battleSystem->trainers[i] = setup->trainer[i];
    }

    battleSystem->ctx = BattleContext_New(battleSystem);

    for (i = 0; i < BATTLER_MAX; i++) {
        battleSystem->trainerParty[i] = SaveArray_Party_Alloc(HEAP_ID_BATTLE);
        battleSystem->followMonSlot[i] = setup->followMonSlot[i];
    }

    int gender;

    for (i = 0; i < BATTLER_MAX; i++) {
        for (slot = 0; slot < Party_GetCount(setup->party[i]); slot++) {
            mon = Party_GetMonByIndex(setup->party[i], slot);
            gender = GetMonGender(mon);
            SetMonData(mon, MON_DATA_GENDER, &gender);
        }
    }

    if (battleSystem->battleType & BATTLE_TYPE_LINK) {
        BattleLink_Start(battleSystem);
        u8 networkID = BattleSystem_GetNetworkId(battleSystem);

        BattleSystem_ChooseLinkServer(battleSystem, setup);

        if (battleSystem->battleType & BATTLE_TYPE_FRONTIER) {
            for (i = 0; i < BATTLER_MAX; i++) {
                battlerInitData.battler = i;
                battlerInitData.battlerType = gDoublesBattlerTypes[i];
                battleSystem->opponentData[i] = OpponentData_New(battleSystem, &battlerInitData);
            }

            battleSystem->maxBattlers = i;

            for (i = 0; i < BATTLER_MAX; i++) {
                OpponentData_SetInputTasks(battleSystem, battleSystem->opponentData[i]);
                Party_Copy(setup->party[i], battleSystem->trainerParty[i]);
            }

            for (i = 0; i < battleSystem->maxBattlers; i++) {
                for (slot = 0; slot < Party_GetCount(battleSystem->trainerParty[i]); slot++) {
                    mon = Party_GetMonByIndex(battleSystem->trainerParty[i], slot);
                    if (GetMonData(mon, MON_DATA_SPECIES, NULL)
                        && !GetMonData(mon, MON_DATA_IS_EGG, NULL)
                        && GetMonData(mon, MON_DATA_HP, NULL)) {
                        break;
                    }
                }
                BattleContext_Set(battleSystem, battleSystem->ctx, 2, i, slot);
            }
            BattleSystem_InitPartyOrder(battleSystem, battleSystem->ctx);
        } else if (battleSystem->battleType & BATTLE_TYPE_MULTI) {
            for (i = 0; i < BATTLER_MAX; i++) {
                battlerInitData.battler = i;
                battlerInitData.battlerType = sLinkMultiBattlerTypes[BattleSystem_GetLinkPosition(battleSystem, networkID)][BattleSystem_GetLinkPosition(battleSystem, i)];
                battleSystem->opponentData[i] = OpponentData_New(battleSystem, &battlerInitData);
            }
            battleSystem->maxBattlers = i;
            for (i = 0; i < BATTLER_MAX; i++) {
                OpponentData_SetInputTasks(battleSystem, battleSystem->opponentData[i]);
                Party_Copy(setup->party[i], battleSystem->trainerParty[i]);
            }
            for (i = 0; i < battleSystem->maxBattlers; i++) {
                for (slot = 0; slot < Party_GetCount(battleSystem->trainerParty[i]); slot++) {
                    mon = Party_GetMonByIndex(battleSystem->trainerParty[i], slot);
                    if (GetMonData(mon, MON_DATA_SPECIES, NULL)
                        && !GetMonData(mon, MON_DATA_IS_EGG, NULL)
                        && GetMonData(mon, MON_DATA_HP, NULL)) {
                        break;
                    }
                }
                BattleContext_Set(battleSystem, battleSystem->ctx, 2, i, slot);
            }
            BattleSystem_InitPartyOrder(battleSystem, battleSystem->ctx);
        } else if (battleSystem->battleType & BATTLE_TYPE_DOUBLES) {
            for (i = 0; i < BATTLER_MAX; i++) {
                battlerInitData.battler = i;
                battlerInitData.battlerType = sLinkDoublesBattlerTypes[networkID][i];
                battleSystem->opponentData[i] = OpponentData_New(battleSystem, &battlerInitData);
                OpponentData_SetInputTasks(battleSystem, battleSystem->opponentData[i]);
            }
            battleSystem->maxBattlers = i;
            for (i = 0; i < BATTLER_MAX; i++) {
                Party_Copy(setup->party[i], battleSystem->trainerParty[i]);
            }
            for (i = 0; i < battleSystem->maxBattlers; i++) {
                for (slot = 0; slot < Party_GetCount(battleSystem->trainerParty[i & 1]); slot++) {
                    mon = Party_GetMonByIndex(battleSystem->trainerParty[i & 1], slot);
                    if (i > 1) {
                        if (BattleContext_Get(battleSystem, battleSystem->ctx, 2, i & 1) != slot
                            && GetMonData(mon, MON_DATA_SPECIES, NULL)
                            && !GetMonData(mon, MON_DATA_IS_EGG, NULL)
                            && GetMonData(mon, MON_DATA_HP, NULL)) {
                            break;
                        }
                    } else if (GetMonData(mon, MON_DATA_SPECIES, NULL)
                        && !GetMonData(mon, MON_DATA_IS_EGG, NULL)
                        && GetMonData(mon, MON_DATA_HP, NULL)) {
                        break;
                    }
                }
                BattleContext_Set(battleSystem, battleSystem->ctx, 2, i, slot);
            }
        } else {
            for (i = 0; i < BATTLER_MAX / 2; i++) {
                battlerInitData.battler = i;
                battlerInitData.battlerType = sLinkSinglesBattlerTypes[networkID * 2 + i];
                battleSystem->opponentData[i] = OpponentData_New(battleSystem, &battlerInitData);
                OpponentData_SetInputTasks(battleSystem, battleSystem->opponentData[i]);
            }
            battleSystem->maxBattlers = i;
            for (i = 0; i < BATTLER_MAX; i++) {
                Party_Copy(setup->party[i], battleSystem->trainerParty[i]);
                for (slot = 0; slot < Party_GetCount(battleSystem->trainerParty[i]); slot++) {
                    mon = Party_GetMonByIndex(battleSystem->trainerParty[i], slot);
                    if (GetMonData(mon, MON_DATA_SPECIES, NULL)
                        && !GetMonData(mon, MON_DATA_IS_EGG, NULL)
                        && GetMonData(mon, MON_DATA_HP, NULL)) {
                        break;
                    }
                }
                BattleContext_Set(battleSystem, battleSystem->ctx, 2, i, slot);
            }
        }
        BattleSystem_InitPartyOrder(battleSystem, battleSystem->ctx);
    } else if (battleSystem->battleType & BATTLE_TYPE_TAG) {
        int playerSlot;
        for (i = 0; i < BATTLER_MAX; i++) {
            battlerInitData.battler = i;
            battlerInitData.battlerType = gDoublesBattlerTypes[i];
            battleSystem->opponentData[i] = OpponentData_New(battleSystem, &battlerInitData);
            OpponentData_SetInputTasks(battleSystem, battleSystem->opponentData[i]);
        }
        battleSystem->maxBattlers = i;
        for (i = 0; i < BATTLER_MAX; i++) {
            Party_Copy(setup->party[i], battleSystem->trainerParty[i]);
        }
        for (i = 0; i < battleSystem->maxBattlers; i++) {
            for (slot = 0; slot < BattleSystem_GetPartySize(battleSystem, i); slot++) {
                mon = BattleSystem_GetPartyMon(battleSystem, i, slot);
                if (i == BATTLER_PLAYER2) {
                    if (GetMonData(mon, MON_DATA_SPECIES, NULL)
                        && !GetMonData(mon, MON_DATA_IS_EGG, NULL)
                        && GetMonData(mon, MON_DATA_HP, NULL)
                        && playerSlot != slot) {
                        break;
                    }
                } else if (GetMonData(mon, MON_DATA_SPECIES, NULL)
                    && !GetMonData(mon, MON_DATA_IS_EGG, NULL)
                    && GetMonData(mon, MON_DATA_HP, NULL)) {
                    break;
                }
            }
            BattleContext_Set(battleSystem, battleSystem->ctx, 2, i, slot);
            if (i == BATTLER_PLAYER) {
                playerSlot = slot;
            }
        }
        BattleSystem_InitPartyOrder(battleSystem, battleSystem->ctx);
        battleSystem->isServer = 1;
    } else if (battleSystem->battleType & BATTLE_TYPE_MULTI) {
        for (i = 0; i < BATTLER_MAX; i++) {
            battlerInitData.battler = i;
            battlerInitData.battlerType = gDoublesBattlerTypes[i];
            battleSystem->opponentData[i] = OpponentData_New(battleSystem, &battlerInitData);
            OpponentData_SetInputTasks(battleSystem, battleSystem->opponentData[i]);
        }
        battleSystem->maxBattlers = i;
        for (i = 0; i < BATTLER_MAX; i++) {
            Party_Copy(setup->party[i], battleSystem->trainerParty[i]);
        }
        for (i = 0; i < battleSystem->maxBattlers; i++) {
            for (slot = 0; slot < Party_GetCount(battleSystem->trainerParty[i]); slot++) {
                mon = Party_GetMonByIndex(battleSystem->trainerParty[i], slot);
                if (GetMonData(mon, MON_DATA_SPECIES, NULL)
                    && !GetMonData(mon, MON_DATA_IS_EGG, NULL)
                    && GetMonData(mon, MON_DATA_HP, NULL)) {
                    break;
                }
            }
            BattleContext_Set(battleSystem, battleSystem->ctx, 2, i, slot);
        }
        BattleSystem_InitPartyOrder(battleSystem, battleSystem->ctx);
        battleSystem->isServer = 1;
    } else if (battleSystem->battleType & BATTLE_TYPE_DOUBLES) {
        for (i = 0; i < BATTLER_MAX; i++) {
            battlerInitData.battler = i;
            battlerInitData.battlerType = gDoublesBattlerTypes[i];
            battleSystem->opponentData[i] = OpponentData_New(battleSystem, &battlerInitData);
            OpponentData_SetInputTasks(battleSystem, battleSystem->opponentData[i]);
        }
        battleSystem->maxBattlers = i;
        for (i = 0; i < BATTLER_MAX; i++) {
            Party_Copy(setup->party[i], battleSystem->trainerParty[i]);
        }
        for (i = 0; i < battleSystem->maxBattlers; i++) {
            for (slot = 0; slot < Party_GetCount(battleSystem->trainerParty[i & 1]); slot++) {
                mon = Party_GetMonByIndex(battleSystem->trainerParty[i & 1], slot);
                if (i > 1) {
                    if (BattleContext_Get(battleSystem, battleSystem->ctx, 2, i & 1) != slot
                        && GetMonData(mon, MON_DATA_SPECIES, NULL)
                        && !GetMonData(mon, MON_DATA_IS_EGG, NULL)
                        && GetMonData(mon, MON_DATA_HP, NULL)) {
                        break;
                    }
                } else if (GetMonData(mon, MON_DATA_SPECIES, NULL)
                    && !GetMonData(mon, MON_DATA_IS_EGG, NULL)
                    && GetMonData(mon, MON_DATA_HP, NULL)) {
                    break;
                }
            }
            BattleContext_Set(battleSystem, battleSystem->ctx, 2, i, slot);
        }
        BattleSystem_InitPartyOrder(battleSystem, battleSystem->ctx);
        battleSystem->isServer = 1;
    } else {
        for (i = 0; i < BATTLER_MAX / 2; i++) {
            battlerInitData.battler = i;
            battlerInitData.battlerType = sSinglesBattlerTypes[i];
            battleSystem->opponentData[i] = OpponentData_New(battleSystem, &battlerInitData);
            OpponentData_SetInputTasks(battleSystem, battleSystem->opponentData[i]);
        }
        battleSystem->maxBattlers = i;
        for (i = 0; i < BATTLER_MAX; i++) {
            Party_Copy(setup->party[i], battleSystem->trainerParty[i]);
            for (slot = 0; slot < Party_GetCount(battleSystem->trainerParty[i]); slot++) {
                mon = Party_GetMonByIndex(battleSystem->trainerParty[i], slot);
                if (GetMonData(mon, MON_DATA_SPECIES, NULL)
                    && !GetMonData(mon, MON_DATA_IS_EGG, NULL)
                    && GetMonData(mon, MON_DATA_HP, NULL)) {
                    break;
                }
            }
            BattleContext_Set(battleSystem, battleSystem->ctx, 2, i, slot);
        }
        BattleSystem_InitPartyOrder(battleSystem, battleSystem->ctx);
        battleSystem->isServer = 1;
    }

    if (battleSystem->battleType & BATTLE_TYPE_PAL_PARK) {
        mon = Party_GetMonByIndex(battleSystem->trainerParty[1], 0);
        GetMonData(mon, MON_DATA_OT_NAME, &battleSystem->trainers[1].name);
    }

    if (battleSystem->battleType & BATTLE_TYPE_TRAINER) {
        if (Battle_IsLeagueTrainerClass(battleSystem->trainers[1].data.trainerClass) == TRUE
            || Battle_IsLeagueTrainerClass(battleSystem->trainers[3].data.trainerClass) == TRUE) {
            for (i = 0; i < Party_GetCount(battleSystem->trainerParty[0]); i++) {
                mon = Party_GetMonByIndex(battleSystem->trainerParty[0], i);
                MonApplyFriendshipMod(mon, FRIENDSHIP_EVENT_LEAGUE_BATTLE, battleSystem->location);
                ApplyMonMoodModifier(mon, 2);
            }
            for (i = 0; i < Party_GetCount(battleSystem->trainerParty[2]); i++) {
                mon = Party_GetMonByIndex(battleSystem->trainerParty[2], i);
                MonApplyFriendshipMod(mon, FRIENDSHIP_EVENT_LEAGUE_BATTLE, battleSystem->location);
                ApplyMonMoodModifier(mon, 2);
            }
        }
    }

    battleSystem->linkVersionMismatch = 0;
    battleSystem->hasNonHgssPlayer = 0;
    int incompatible = 0;
    for (i = 0; i < battleSystem->maxBattlers; i++) {
        int version = PlayerProfile_GetVersion(BattleSystem_GetPlayerProfile(battleSystem, i));
        if (version != GAME_VERSION) {
            incompatible = 1;
        }
        if (version != VERSION_HEARTGOLD && version != VERSION_SOULSILVER) {
            battleSystem->hasNonHgssPlayer = 1;
        }
    }
    if (battleSystem->isServer != 0) {
        battleSystem->linkVersionMismatch = incompatible;
        return;
    }
    battleSystem->linkVersionMismatch = 0;
}

static BOOL Battle_IsLeagueTrainerClass(int trainerClass) {
    switch (trainerClass) {
    case TRAINERCLASS_LEADER_FALKNER:
    case TRAINERCLASS_LEADER_BUGSY:
    case TRAINERCLASS_LEADER_WHITNEY:
    case TRAINERCLASS_LEADER_MORTY:
    case TRAINERCLASS_LEADER_PRYCE:
    case TRAINERCLASS_LEADER_JASMINE:
    case TRAINERCLASS_LEADER_CHUCK:
    case TRAINERCLASS_LEADER_CLAIR:
    case TRAINERCLASS_CHAMPION:
    case TRAINERCLASS_ELITE_FOUR_WILL:
    case TRAINERCLASS_ELITE_FOUR_KAREN:
    case TRAINERCLASS_ELITE_FOUR_KOGA:
    case TRAINERCLASS_LEADER_BROCK:
    case TRAINERCLASS_LEADER_MISTY:
    case TRAINERCLASS_LEADER_LT_SURGE:
    case TRAINERCLASS_LEADER_ERIKA:
    case TRAINERCLASS_LEADER_JANINE:
    case TRAINERCLASS_LEADER_SABRINA:
    case TRAINERCLASS_LEADER_BLAINE:
    case TRAINERCLASS_LEADER_BLUE:
    case TRAINERCLASS_ELITE_FOUR_BRUNO:
        return TRUE;
    default:
        return FALSE;
    }
}

static GF3DVramMan *Battle_Create3DVramMan(void) {
    return GF_3DVramMan_Create(HEAP_ID_BATTLE, 0, 2, 0, 2, Battle_Setup3D);
}

static void Battle_Setup3D(void) {
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    G2_SetBG0Priority(1);
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(TRUE);
    G3X_AlphaTest(FALSE, 0);
    G3X_AlphaBlend(TRUE);
    G3X_EdgeMarking(FALSE);
    G3X_SetFog(FALSE, GX_FOGBLEND_COLOR_ALPHA, GX_FOGSLOPE_0x8000, 0);
    G3X_SetClearColor(GX_RGB(0, 0, 0), 0, 0x7FFF, 63, FALSE);
    G3_ViewPort(0, 0, 255, 191);
}

static void Battle_Delete3DVramMan(GF3DVramMan *vramMan) {
    GF_3DVramMan_Delete(vramMan);
}

static void Battle_ReserveTexAndPlttVram(void) {
    u32 tex = NNS_GfdDefaultFuncAllocTexVram(0x8000, FALSE, 0);
    u32 pltt = NNS_GfdDefaultFuncAllocPlttVram(0xC0, FALSE, 0);
    GF_ASSERT(tex != 0);
    GF_ASSERT(pltt != 0);
    ParticleSystem_ZeroAll();
}

void Battle_VBlankCallback(void *data) {
    BattleSystem *battleSystem = data;
    GraphicsBanks banks;
    GraphicsBanks banks2;

    if (battleSystem->resetBlendRequested) {
        battleSystem->resetBlendRequested = 0;
        reg_G2_BLDCNT = 0;
        reg_G2S_DB_BLDCNT = 0;
    }
    if (battleSystem->battleBanksRequested) {
        battleSystem->battleBanksRequested = 0;
        banks = sBattleRestoreGraphicsBanks;
        GfGfx_SetBanks(&banks);
    }
    if (battleSystem->subMenuBanksRequested) {
        battleSystem->subMenuBanksRequested = 0;
        banks2 = sSubMenuGraphicsBanks;
        GfGfx_SetBanks(&banks2);
    }
    PokepicManager_HandleLoadImgAndOrPltt(battleSystem->pokepicManager);
    GF_RunVramTransferTasks();
    SpriteSystem_TransferOam();
    PaletteData_PushTransparentBuffers(battleSystem->palette);
    DoScheduledBgGpuUpdates(battleSystem->bgConfig);
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static void Battle_LinkVBlankCallback(void *data) {
    BattleLinkWork *work = data;

    PaletteData_PushTransparentBuffers(work->palette);
    GF_RunVramTransferTasks();
    DoScheduledBgGpuUpdates(work->bgConfig);
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static void Task_DrawBattleGraphics(SysTask *task, void *data) {
    BattleSystem *battleSystem = data;

    CommState_FrameDummy(HEAP_ID_BATTLE, battleSystem->bgConfig);
    if (battleSystem->graphicsMode == 0 || battleSystem->graphicsMode == 3) {
        if (battleSystem->graphicsMode == 0) {
            BattleParticleSystem_DrawAll();
        }
        PokepicManager_DrawAll(battleSystem->pokepicManager);
        SpriteSystem_DrawSprites(battleSystem->gfxHandler);
        SpriteSystem_UpdateTransfer();
        RequestSwap3DBuffers(GX_SORTMODE_MANUAL, GX_BUFFERMODE_Z);
    }
}

static void Task_UpdateCriticalHpMusic(SysTask *task, void *data) {
    BattleSystem *battleSystem = data;
    int maxBattlers = BattleSystem_GetMaxBattlers(battleSystem);
    u32 criticalMask = 0;
    int flag = BattleSystem_GetCriticalHpMusicFlag(battleSystem);
    int i;

    if (BattleSystem_GetBattleType(battleSystem) & (BATTLE_TYPE_SAFARI | BATTLE_TYPE_PAL_PARK)) {
        return;
    }
    if (flag & 2) {
        if (flag & 1) {
            StopSE(SEQ_SE_DP_HINSI, 0);
            BattleSystem_SetCriticalHpMusicFlag(battleSystem, CRITICAL_MUSIC_OFF);
        }
        return;
    }
    for (i = 0; i < maxBattlers; i++) {
        OpponentData *opponentData = BattleSystem_GetOpponentData(battleSystem, i);
        if ((!OpponentData_GetInputMode(opponentData) && !(BattleSystem_GetBattleSpecial(battleSystem) & BATTLE_SPECIAL_RECORDING))
            || (!BattleSystem_GetFieldSide(battleSystem, i) && (BattleSystem_GetBattleSpecial(battleSystem) & BATTLE_SPECIAL_RECORDING))) {
            BattleHpBar *hpBar = OpponentData_GetHpBar(opponentData);
            if (hpBar && CalculateHpBarColor(hpBar->hp, hpBar->maxHp, 48) == 1) {
                criticalMask |= MaskOfFlagNo(i);
            }
        }
    }
    if (criticalMask && !BattleSystem_GetCriticalHpMusicFlag(battleSystem)) {
        PlaySE(SEQ_SE_DP_HINSI);
        BattleSystem_SetCriticalHpMusicFlag(battleSystem, 1);
        BattleSystem_SetCriticalHpMusicDelay(battleSystem, 4);
    } else if (!criticalMask && BattleSystem_GetCriticalHpMusicFlag(battleSystem)) {
        StopSE(SEQ_SE_DP_HINSI, 0);
        BattleSystem_SetCriticalHpMusicFlag(battleSystem, 0);
    }
    if (BattleSystem_GetCriticalHpMusicFlag(battleSystem)) {
        int delay = BattleSystem_GetCriticalHpMusicDelay(battleSystem);
        if (!IsSEPlaying(SEQ_SE_DP_HINSI)) {
            if (--delay == 0) {
                PlaySE(SEQ_SE_DP_HINSI);
                BattleSystem_SetCriticalHpMusicDelay(battleSystem, 4);
            } else {
                BattleSystem_SetCriticalHpMusicDelay(battleSystem, delay);
            }
        }
    }
}

static void VBlankTask_ScrollBattleBackground(SysTask *task, void *data) {
    BattleSystem *battleSystem = data;

    battleSystem->bgScrollY += 3;
    BgSetPosTextAndCommit(battleSystem->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_Y, battleSystem->bgScrollY);
    if (battleSystem->bgScrollY == 0) {
        SysTask_Destroy(task);
    }
}

static void Battle_StaticInit(void) {
    if (!CommState_IsWifi()) {
        HandleLoadOverlay(FS_OVERLAY_ID(OVY_18), OVY_LOAD_ASYNC);
    }
}

// The overlay's single static initializer entry.
#pragma define_section SINIT ".sinit" abs32 RWX
#pragma section SINIT begin
SDK_FORCE_EXPORT static void (*NitroStaticInit_[])(void) = { Battle_StaticInit };
#pragma section SINIT end

void Battle_LinkInit(OverlayManager *man, BattleSetup *setup) {
    GraphicsBanks banks;
    GraphicsModes modes;
    BgTemplate bgTemplate;
    BattleLinkWork *work = OverlayManager_CreateAndGetData(man, sizeof(BattleLinkWork), HEAP_ID_BATTLE);
    MsgData *msgData;
    String *string;
    u32 frame;

    work->setup = setup;
    work->received = 0;
    work->state = 0;
    work->timer = 0;
    work->palette = PaletteData_Init(HEAP_ID_BATTLE);
    PaletteData_SetAutoTransparent(work->palette, TRUE);
    PaletteData_AllocBuffers(work->palette, PLTTBUF_MAIN_BG, 0x200, HEAP_ID_BATTLE);
    PaletteData_FillPaletteInBuffer(work->palette, PLTTBUF_MAIN_BG, PLTTSEL_BOTH, 0, 0, 0x100);
    work->bgConfig = BgConfig_Alloc(HEAP_ID_BATTLE);
    work->window = AllocWindows(HEAP_ID_BATTLE, 1);
    BattleLink_RegisterSetupCommands(work);
    GfGfx_DisableEngineAPlanes();
    banks = sLinkGraphicsBanks;
    GfGfx_SetBanks(&banks);
    MIi_CpuClear32(0, (void *)HW_BG_VRAM, HW_BG_VRAM_SIZE);
    MIi_CpuClear32(0, (void *)HW_DB_BG_VRAM, HW_DB_BG_VRAM_SIZE);
    MIi_CpuClear32(0, (void *)HW_OBJ_VRAM, HW_OBJ_VRAM_SIZE);
    MIi_CpuClear32(0, (void *)HW_DB_OBJ_VRAM, HW_DB_OBJ_VRAM_SIZE);
    MIi_CpuClear16(0, (void *)HW_BG_PLTT, HW_BG_PLTT_SIZE);
    modes = sLinkGraphicsModes;
    SetBothScreensModesAndDisable(&modes);
    bgTemplate = sLinkBgTemplate;
    InitBgFromTemplate(work->bgConfig, GF_BG_LYR_MAIN_1, &bgTemplate, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(work->bgConfig, GF_BG_LYR_MAIN_1);
    frame = Options_GetFrame(setup->options);
    LoadUserFrameGfx2WithFill(work->bgConfig, GF_BG_LYR_MAIN_1, 1, 10, frame, HEAP_ID_BATTLE);
    PaletteData_LoadNarc(work->palette, NARC_graphic_font, 8, HEAP_ID_BATTLE, PLTTBUF_MAIN_BG, 0x20, 0xB0);
    PaletteData_LoadNarc(work->palette, NARC_a_0_3_8, GetUserFrameGfx2PaletteMember(frame), HEAP_ID_BATTLE, PLTTBUF_MAIN_BG, 0x20, 0xA0);
    PaletteData_FillPaletteInBuffer(work->palette, PLTTBUF_MAIN_BG, PLTTSEL_TRANSPARENT, 0, 0, 0x100);
    GfGfx_BothDispOn();
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, TRUE);
    reg_GX_POWCNT |= REG_GX_POWCNT_DSEL_MASK;
    AddWindowParameterized(work->bgConfig, work->window, GF_BG_LYR_MAIN_1, 2, 0x13, 0x1B, 4, 0xB, 0x1F);
    FillWindowPixelBuffer(work->window, 0xFF);
    DrawFrameAndWindow2(work->window, FALSE, 1, 0xA);
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0197_bin, HEAP_ID_BATTLE);
    string = String_New(0x100, HEAP_ID_BATTLE);
    ReadMsgDataIntoString(msgData, msg_0197_00923, string);
    AddTextPrinterParameterized(work->window, 1, string, 0, 0, TEXT_SPEED_INSTANT, NULL);
    String_Delete(string);
    DestroyMsgData(msgData);
    Main_SetVBlankIntrCB(Battle_LinkVBlankCallback, work);
    PaletteData_BeginPaletteFade(work->palette, PLTTBUF_MAIN_BG_F | PLTTBUF_MAIN_OBJ_F, 0xFFFF, 0, 0x10, 0, 0);
    work->waitingIcon = WaitingIcon_New(work->window, 1);
    Battle_CreateWirelessStatusIcon();
}

enum {
    LINK_STATE_INIT,
    LINK_STATE_WAIT_FADE,
    LINK_STATE_START_SYNC,
    LINK_STATE_WAIT_SYNC,
    LINK_STATE_SEND_AI_FLAGS,
    LINK_STATE_WAIT_AI_FLAGS,
    LINK_STATE_PREPARE_PROFILE,
    LINK_STATE_SEND_PROFILE,
    LINK_STATE_WAIT_PROFILE,
    LINK_STATE_PREPARE_TRAINER,
    LINK_STATE_SEND_TRAINER,
    LINK_STATE_WAIT_TRAINER,
    LINK_STATE_PREPARE_PARTY,
    LINK_STATE_SEND_PARTY,
    LINK_STATE_WAIT_PARTY,
    LINK_STATE_PREPARE_CHATOT,
    LINK_STATE_SEND_CHATOT,
    LINK_STATE_WAIT_CHATOT,
    LINK_STATE_PREPARE_PAL_PAD,
    LINK_STATE_SEND_PAL_PAD,
    LINK_STATE_WAIT_PAL_PAD,
    LINK_STATE_PREPARE_PARTNER_TRAINER_1,
    LINK_STATE_SEND_PARTNER_TRAINER_1,
    LINK_STATE_WAIT_PARTNER_TRAINER_1,
    LINK_STATE_PREPARE_PARTNER_TRAINER_3,
    LINK_STATE_SEND_PARTNER_TRAINER_3,
    LINK_STATE_WAIT_PARTNER_TRAINER_3,
    LINK_STATE_PREPARE_PARTNER_PARTY_1,
    LINK_STATE_SEND_PARTNER_PARTY_1,
    LINK_STATE_WAIT_PARTNER_PARTY_1,
    LINK_STATE_PREPARE_PARTNER_PARTY_3,
    LINK_STATE_SEND_PARTNER_PARTY_3,
    LINK_STATE_WAIT_PARTNER_PARTY_3,
    LINK_STATE_FINISH,
};

BOOL Battle_LinkMain(OverlayManager *man) {
    BattleLinkWork *work = OverlayManager_GetData(man);
    BOOL done;
    int i;

    CommState_FrameDummy(HEAP_ID_BATTLE, work->bgConfig);
    done = FALSE;
    switch (work->state) {
    case LINK_STATE_INIT:
        SetMasterBrightnessNeutral(PM_LCD_TOP);
        Comm_SetWifiContinuousSendAndMuteVoice(TRUE);
        work->state++;
        break;
    case LINK_STATE_WAIT_FADE:
        if (PaletteData_GetSelectedBuffersBitmask(work->palette) == 0) {
            work->state++;
        }
        break;
    case LINK_STATE_START_SYNC:
        LinkSync_StartSync(BATTLE_LINK_SYNC_START);
        work->state++;
        break;
    case LINK_STATE_WAIT_SYNC:
        if (LinkSync_IsSynced(BATTLE_LINK_SYNC_START)) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_AI_FLAGS);
            work->timer = 0;
            work->state++;
        } else {
            work->timer++;
            if (work->timer > 0x708) {
                CommState_SetError(1);
            }
        }
        break;
    case LINK_STATE_SEND_AI_FLAGS:
        if (BattleLink_SendAiFlags(work, 0x140) == TRUE) {
            work->state++;
        }
        break;
    case LINK_STATE_PREPARE_PROFILE:
        if (BattleLink_PrepareProfile(work) == TRUE) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_PROFILE);
            work->state++;
        }
        break;
    case LINK_STATE_SEND_PROFILE:
        if (BattleLink_SendProfile(work) == TRUE) {
            work->state++;
        }
        break;
    case LINK_STATE_PREPARE_TRAINER:
        if (BattleLink_PrepareTrainer(work) == TRUE) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_TRAINER);
            work->state++;
        }
        break;
    case LINK_STATE_SEND_TRAINER:
        if (BattleLink_SendTrainer(work) == TRUE) {
            work->state++;
        }
        break;
    case LINK_STATE_PREPARE_PARTY:
        if (BattleLink_PrepareParty(work) == TRUE) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_PARTY);
            work->state++;
        }
        break;
    case LINK_STATE_SEND_PARTY:
        if (BattleLink_SendParty(work) == TRUE) {
            work->state++;
        }
        break;
    case LINK_STATE_PREPARE_CHATOT:
        if (BattleLink_PrepareChatot(work) == TRUE) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_CHATOT);
            work->state++;
        }
        break;
    case LINK_STATE_SEND_CHATOT:
        if (BattleLink_SendChatot(work) == TRUE) {
            work->state++;
        }
        break;
    case LINK_STATE_PREPARE_PAL_PAD:
        if (BattleLink_PreparePalPad(work) == TRUE) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_PAL_PAD);
            work->state++;
        }
        break;
    case LINK_STATE_SEND_PAL_PAD:
        if (BattleLink_SendPalPad(work) == TRUE) {
            work->state++;
        }
        break;
    case LINK_STATE_PREPARE_PARTNER_TRAINER_1:
        if (!(work->setup->battleType & BATTLE_TYPE_FRONTIER)) {
            work->state = LINK_STATE_FINISH;
        } else if (Comm_GetLocalNetId() != 0) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_PARTNER_TRAINER_1);
            work->state++;
        } else if (BattleLink_PreparePartnerTrainer(work, 1) == TRUE) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_PARTNER_TRAINER_1);
            work->state++;
        }
        break;
    case LINK_STATE_SEND_PARTNER_TRAINER_1:
        work->received = 1;
        if (Comm_GetLocalNetId() != 0) {
            if (LinkSync_IsSynced(BATTLE_LINK_SYNC_PARTNER_TRAINER_1) == TRUE) {
                work->state++;
            }
        } else if (BattleLink_SendPartnerTrainer(work, 1, BATTLE_LINK_SYNC_PARTNER_TRAINER_1) == TRUE) {
            work->state++;
        }
        break;
    case LINK_STATE_PREPARE_PARTNER_TRAINER_3:
        if (Comm_GetLocalNetId() != 0) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_PARTNER_TRAINER_3);
            work->state++;
        } else if (BattleLink_PreparePartnerTrainer(work, 3) == TRUE) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_PARTNER_TRAINER_3);
            work->state++;
        }
        break;
    case LINK_STATE_SEND_PARTNER_TRAINER_3:
        work->received = 1;
        if (Comm_GetLocalNetId() != 0) {
            if (LinkSync_IsSynced(BATTLE_LINK_SYNC_PARTNER_TRAINER_3) == TRUE) {
                work->state++;
            }
        } else if (BattleLink_SendPartnerTrainer(work, 3, BATTLE_LINK_SYNC_PARTNER_TRAINER_3) == TRUE) {
            work->state++;
        }
        break;
    case LINK_STATE_PREPARE_PARTNER_PARTY_1:
        if (Comm_GetLocalNetId() != 0) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_PARTNER_PARTY_1);
            work->state++;
        } else if (BattleLink_PreparePartnerParty(work, 1) == TRUE) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_PARTNER_PARTY_1);
            work->state++;
        }
        break;
    case LINK_STATE_SEND_PARTNER_PARTY_1:
        work->received = 1;
        if (Comm_GetLocalNetId() != 0) {
            if (LinkSync_IsSynced(BATTLE_LINK_SYNC_PARTNER_PARTY_1) == TRUE) {
                work->state++;
            }
        } else if (BattleLink_SendPartnerParty(work, 1, BATTLE_LINK_SYNC_PARTNER_PARTY_1) == TRUE) {
            work->state++;
        }
        break;
    case LINK_STATE_PREPARE_PARTNER_PARTY_3:
        if (Comm_GetLocalNetId() != 0) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_PARTNER_PARTY_3);
            work->state++;
        } else if (BattleLink_PreparePartnerParty(work, 3) == TRUE) {
            LinkSync_StartSync(BATTLE_LINK_SYNC_PARTNER_PARTY_3);
            work->state++;
        }
        break;
    case LINK_STATE_SEND_PARTNER_PARTY_3:
        work->received = 1;
        if (Comm_GetLocalNetId() != 0) {
            if (LinkSync_IsSynced(BATTLE_LINK_SYNC_PARTNER_PARTY_3) == TRUE) {
                work->state++;
            }
        } else if (BattleLink_SendPartnerParty(work, 3, BATTLE_LINK_SYNC_PARTNER_PARTY_3) == TRUE) {
            work->state++;
        }
        break;
    case LINK_STATE_WAIT_AI_FLAGS:
    case LINK_STATE_WAIT_PROFILE:
    case LINK_STATE_WAIT_TRAINER:
    case LINK_STATE_WAIT_PARTY:
    case LINK_STATE_WAIT_CHATOT:
    case LINK_STATE_WAIT_PAL_PAD:
    case LINK_STATE_WAIT_PARTNER_TRAINER_1:
    case LINK_STATE_WAIT_PARTNER_TRAINER_3:
    case LINK_STATE_WAIT_PARTNER_PARTY_1:
    case LINK_STATE_WAIT_PARTNER_PARTY_3:
        if (work->received == Comm_CountConnected()) {
            if (work->state == LINK_STATE_WAIT_PAL_PAD) {
                for (i = 0; i < 4; i++) {
                    Heap_Free((work)->friends[i]);
                }
            }
            work->received = 0;
            work->timer = 0;
            work->state++;
            if (work->state == LINK_STATE_FINISH) {
                PaletteData_BeginPaletteFade(work->palette, PLTTBUF_MAIN_BG_F | PLTTBUF_MAIN_OBJ_F, 0xFFFF, 0, 0, 0x10, 0);
            }
        } else {
            work->timer++;
            if (work->timer > 0x708) {
                CommState_SetError(1);
            }
        }
        break;
    case LINK_STATE_FINISH:
        if (PaletteData_GetSelectedBuffersBitmask(work->palette) == 0) {
            done = TRUE;
            WaitingIcon_Delete(work->waitingIcon);
            Comm_SetWifiContinuousSendAndMuteVoice(FALSE);
        }
        break;
    default:
        break;
    }
    return done;
}

void Battle_LinkExit(OverlayManager *man) {
    BattleLinkWork *work = OverlayManager_GetData(man);

    Main_SetVBlankIntrCB(NULL, NULL);
    SetMasterBrightnessByColor(PM_LCD_TOP, 0);
    PaletteData_FreeBuffers(work->palette, PLTTBUF_MAIN_BG);
    PaletteData_Free(work->palette);
    WindowArray_Delete(work->window, 1);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
    FreeBgTilemapBuffer(work->bgConfig, GF_BG_LYR_MAIN_1);
    Heap_Free(work->bgConfig);
    Heap_Free(work);
}

BOOL Battle_PartyPreviewInit(OverlayManager *man) {
    BattleSystem *battleSystem = OverlayManager_CreateAndGetData(man, sizeof(BattleSystem), HEAP_ID_BATTLE);
    BattleSetup *setup = OverlayManager_GetArgs(man);
    u8 netId;

    MIi_CpuClearFast(0, (u32 *)battleSystem, sizeof(BattleSystem));
    BattleSystem_InitFromSetup(battleSystem, setup);
    if (!(battleSystem->battleType & BATTLE_TYPE_LINK) || (battleSystem->battleSpecial & BATTLE_SPECIAL_RECORDING) || (battleSystem->battleType & BATTLE_TYPE_FRONTIER)) {
        WirelessStatusIcon_Destroy();
        return FALSE;
    }
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_5), OVY_LOAD_ASYNC);
    if (!(battleSystem->battleType & BATTLE_TYPE_MULTI)) {
        return FALSE;
    }
    battleSystem->linkScreenArgs = Heap_Alloc(HEAP_ID_BATTLE, sizeof(LinkBattleScreenArgs));
    MI_CpuClearFast(battleSystem->linkScreenArgs, sizeof(LinkBattleScreenArgs));
    netId = Comm_GetLocalNetId();
    switch (Comm_GetBattleSlot(netId)) {
    case 0:
    case 3:
        battleSystem->linkScreenArgs->parties[0] = battleSystem->trainerParty[netId];
        battleSystem->linkScreenArgs->parties[2] = battleSystem->trainerParty[BattleSystem_GetBattlerIdPartner(battleSystem, netId)];
        break;
    case 1:
    case 2:
        battleSystem->linkScreenArgs->parties[0] = battleSystem->trainerParty[BattleSystem_GetBattlerIdPartner(battleSystem, netId)];
        battleSystem->linkScreenArgs->parties[2] = battleSystem->trainerParty[netId];
        break;
    }
    battleSystem->linkScreenArgs->heapId = HEAP_ID_BATTLE;
    battleSystem->linkScreenArgs->mode = 0;
    switch (Comm_GetBattleSlot(netId)) {
    case 0:
    case 3:
        battleSystem->linkScreenArgs->multiOrSide = 0;
        break;
    case 1:
    case 2:
        battleSystem->linkScreenArgs->multiOrSide = 1;
        break;
    }
    LinkBattleScreen_Start(battleSystem->linkScreenArgs);
    return TRUE;
}

BOOL Battle_PartyPreviewMain(OverlayManager *man) {
    BattleSystem *battleSystem = OverlayManager_GetData(man);
    int i;

    if (battleSystem->linkScreenArgs->done) {
        for (i = 0; i < 4; i++) {
            if (battleSystem->linkScreenArgs->names[i] != NULL) {
                Heap_Free(battleSystem->linkScreenArgs->names[i]);
            }
        }
        Heap_Free(battleSystem->linkScreenArgs);
        return TRUE;
    }
    return FALSE;
}

BOOL Battle_VsScreenInit(OverlayManager *man) {
    BattleSystem *battleSystem = OverlayManager_GetData(man);
    u8 netId;
    int i;
    int slot;

    OverlayManager_GetArgs(man);
    if (!(battleSystem->battleType & BATTLE_TYPE_LINK) || (battleSystem->battleSpecial & BATTLE_SPECIAL_RECORDING) || (battleSystem->battleType & BATTLE_TYPE_FRONTIER)) {
        WirelessStatusIcon_Destroy();
        return FALSE;
    }
    netId = Comm_GetLocalNetId();
    battleSystem->linkScreenArgs = Heap_Alloc(HEAP_ID_BATTLE, sizeof(LinkBattleScreenArgs));
    MI_CpuClearFast(battleSystem->linkScreenArgs, sizeof(LinkBattleScreenArgs));
    if (battleSystem->battleType & BATTLE_TYPE_MULTI) {
        for (i = 0; i < BATTLER_MAX; i++) {
            battleSystem->linkScreenArgs->parties[Comm_GetBattleSlot(i)] = battleSystem->trainerParty[i];
            slot = Comm_GetBattleSlot(i);
            battleSystem->linkScreenArgs->names[slot] = PlayerProfile_GetPlayerName_NewString(battleSystem->playerProfile[i], HEAP_ID_BATTLE);
        }
        battleSystem->linkScreenArgs->heapId = HEAP_ID_BATTLE;
        battleSystem->linkScreenArgs->mode = 1;
        battleSystem->linkScreenArgs->multiOrSide = 1;
    } else {
        int other;
        battleSystem->linkScreenArgs->parties[Comm_GetBattleSlot(netId)] = battleSystem->trainerParty[netId];
        other = netId ^ 1;
        battleSystem->linkScreenArgs->parties[Comm_GetBattleSlot(other)] = battleSystem->trainerParty[other];
        slot = Comm_GetBattleSlot(netId);
        battleSystem->linkScreenArgs->names[slot] = PlayerProfile_GetPlayerName_NewString(battleSystem->playerProfile[netId], HEAP_ID_BATTLE);
        slot = Comm_GetBattleSlot(other);
        battleSystem->linkScreenArgs->names[slot] = PlayerProfile_GetPlayerName_NewString(battleSystem->playerProfile[other], HEAP_ID_BATTLE);
        battleSystem->linkScreenArgs->heapId = HEAP_ID_BATTLE;
        battleSystem->linkScreenArgs->mode = 1;
        battleSystem->linkScreenArgs->multiOrSide = 0;
    }
    LinkBattleScreen_Start(battleSystem->linkScreenArgs);
    return TRUE;
}

BOOL Battle_VsScreenMain(OverlayManager *man) {
    BattleSystem *battleSystem = OverlayManager_GetData(man);
    int i;

    if (battleSystem->linkScreenArgs->done) {
        for (i = 0; i < 4; i++) {
            if (battleSystem->linkScreenArgs->names[i] != NULL) {
                Heap_Free(battleSystem->linkScreenArgs->names[i]);
            }
        }
        Heap_Free(battleSystem->linkScreenArgs);
        return TRUE;
    }
    return FALSE;
}

BOOL Battle_EndInit(OverlayManager *man) {
    BattleSetup *setup = OverlayManager_GetArgs(man);
    int netId;
    int i;
    int offset;
    int other;
    int slot;
    LinkBattleScreenArgs *args;

    if (!(setup->battleType & BATTLE_TYPE_LINK) || (setup->battleSpecial & BATTLE_SPECIAL_RECORDING) || (setup->battleType & BATTLE_TYPE_FRONTIER)) {
        return FALSE;
    }
    netId = (u8)Comm_GetLocalNetId();
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_5), OVY_LOAD_ASYNC);
    args = Heap_Alloc(HEAP_ID_BATTLE, sizeof(LinkBattleScreenArgs));
    setup->evolutionTaskData = (EvolutionTaskData *)args;
    MIi_CpuClearFast(0, (u32 *)args, sizeof(LinkBattleScreenArgs));
    args->setup = setup;
    switch (setup->winFlag) {
    case BATTLE_OUTCOME_WIN:
        if (!CommState_IsWifi()) {
            GameStats_Inc(setup->gameStats, GAME_STAT_LOCAL_LINK_BATTLE_WINS);
        } else {
            GameStats_Inc(setup->gameStats, GAME_STAT_WIFI_BATTLE_WINS);
        }
        break;
    case BATTLE_OUTCOME_LOSE:
        if (!CommState_IsWifi()) {
            GameStats_Inc(setup->gameStats, GAME_STAT_LOCAL_LINK_BATTLE_LOSSES);
        } else {
            GameStats_Inc(setup->gameStats, GAME_STAT_WIFI_BATTLE_LOSSES);
        }
        break;
    case BATTLE_OUTCOME_DRAW:
    case BATTLE_OUTCOME_PLAYER_FLED:
        if (!CommState_IsWifi()) {
            GameStats_Inc(setup->gameStats, GAME_STAT_LOCAL_LINK_BATTLE_DRAWS);
        } else {
            GameStats_Inc(setup->gameStats, GAME_STAT_WIFI_BATTLE_DRAWS);
        }
        break;
    case BATTLE_OUTCOME_NONE:
    case BATTLE_OUTCOME_MON_CAUGHT:
        break;
    }
    if (setup->battleType & BATTLE_TYPE_MULTI) {
        for (i = 0; i < BATTLER_MAX; i++) {
            args->parties[Comm_GetBattleSlot(i)] = setup->party[i];
            slot = Comm_GetBattleSlot(i);
            args->names[slot] = PlayerProfile_GetPlayerName_NewString(setup->profile[i], HEAP_ID_BATTLE);
        }
        args->heapId = HEAP_ID_BATTLE;
        args->mode = 2;
        args->multiOrSide = 1;
        if (setup->winFlag != BATTLE_OUTCOME_PLAYER_FLED) {
            args->outcome = setup->winFlag;
        } else {
            args->outcome = 3;
        }
    } else {
        offset = netId;
        args->parties[Comm_GetBattleSlot(netId)] = setup->party[offset];
        other = netId ^ 1;
        args->parties[Comm_GetBattleSlot(other)] = setup->party[other];
        slot = Comm_GetBattleSlot(netId);
        args->names[slot] = PlayerProfile_GetPlayerName_NewString(setup->profile[offset], HEAP_ID_BATTLE);
        slot = Comm_GetBattleSlot(other);
        args->names[slot] = PlayerProfile_GetPlayerName_NewString(setup->profile[other], HEAP_ID_BATTLE);
        args->heapId = HEAP_ID_BATTLE;
        args->mode = 2;
        args->multiOrSide = 0;
        if (setup->winFlag != BATTLE_OUTCOME_PLAYER_FLED) {
            args->outcome = setup->winFlag;
        } else {
            args->outcome = 3;
        }
    }
    args->linkBattleMode = setup->linkBattleMode;
    LinkBattleScreen_Start(args);
    return TRUE;
}

BOOL Battle_EndMain(OverlayManager *man) {
    BattleSetup *setup = OverlayManager_GetArgs(man);
    LinkBattleScreenArgs *args = (LinkBattleScreenArgs *)setup->evolutionTaskData;
    int i;

    if (args->done) {
        for (i = 0; i < 4; i++) {
            if (args->names[i] != NULL) {
                Heap_Free(args->names[i]);
            }
        }
        Heap_Free(args);
        return TRUE;
    }
    return FALSE;
}

void BattleSystem_SetupTextFlags(BattleSystem *battleSystem) {
    if ((battleSystem->battleType & (BATTLE_TYPE_LINK | BATTLE_TYPE_TUTORIAL)) != 0 || (battleSystem->battleSpecial & BATTLE_SPECIAL_RECORDING) != 0) {
        TextFlags_SetAutoScrollParam(1);
        TextFlags_SetCanABSpeedUpPrint(TRUE);
        TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    } else {
        TextFlags_SetAutoScrollParam(3);
        TextFlags_SetCanABSpeedUpPrint(TRUE);
        TextFlags_SetCanTouchSpeedUpPrint(TRUE);
    }
}

static inline void SwapInts(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void BattleSystem_ChooseLinkServer(BattleSystem *battleSystem, BattleSetup *setup) {
    int ids[4];
    int values[4];
    int netId;
    int count;
    int i;
    int j;

    if (battleSystem->battleSpecial & BATTLE_SPECIAL_RECORDING) {
        battleSystem->isServer = 1;
        return;
    }
    for (i = 0; i < BATTLER_MAX; i++) {
        ids[i] = i;
        values[i] = setup->aiFlags[i];
    }
    netId = Comm_GetLocalNetId();
    count = Comm_CountConnected();
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (values[i] < values[j]) {
                SwapInts(&ids[i], &ids[j]);
                SwapInts(&values[i], &values[j]);
            }
        }
    }
    if (ids[0] == netId) {
        battleSystem->isServer = 1;
        return;
    }
    if (!(battleSystem->battleType & BATTLE_TYPE_FRONTIER)) {
        if (battleSystem->battleType & BATTLE_TYPE_MULTI) {
            int side = Comm_GetBattleSlot(netId);
            switch (Comm_GetBattleSlot(ids[0])) {
            case 0:
            case 2:
                if (side & 1) {
                    battleSystem->battleSpecial |= 0x20;
                }
                break;
            case 1:
            case 3:
                if (!(side & 1)) {
                    battleSystem->battleSpecial |= 0x20;
                }
                break;
            }
        } else {
            battleSystem->battleSpecial |= 0x20;
        }
    }
}

static void Battle_CreateWirelessStatusIcon(void) {
    WirelessStatusIcon_Create();
    if (CommState_IsWifi()) {
        WirelessStatusIcon_SetLevel(3 - DWC_GetLinkLevel());
    } else if (CommWireless_Exists()) {
        WirelessStatusIcon_SetLevel(3 - WM_GetLinkLevel());
    }
}
