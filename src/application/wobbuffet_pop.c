#include "wobbuffet_pop.h"

#include <nnsys/g2d_internal.h>

#include "global.h"

#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0012.h"

#include "comm_state.h"
#include "comm_state_internal.h"
#include "communication_core.h"
#include "communication_player_state.h"
#include "error_handling.h"
#include "filesystem.h"
#include "font.h"
#include "gf_3d_render.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "link_synchronization.h"
#include "particle_system.h"
#include "player_data.h"
#include "render_text.h"
#include "render_window.h"
#include "screen_fade.h"
#include "screen_fade_internal.h"
#include "sound_playback.h"
#include "swap_3d_buffers.h"
#include "system.h"
#include "text.h"
#include "touchpad.h"
#include "vram_transfer_manager.h"
#include "wifi_connection.h"
#include "wireless_status_icon.h"
#include "wobbuffet_pop_internal.h"

static BOOL WobbuffetPop_Init(OverlayManager *man, int *state);
static BOOL WobbuffetPop_Main(OverlayManager *man, int *state);
static BOOL WobbuffetPop_Exit(OverlayManager *man, int *state);
BOOL WobbuffetPop_HostStartGame(WobbuffetPop *game, WobbuffetPopSequence *sequence);
BOOL WobbuffetPop_HostPlayGame(WobbuffetPop *game, WobbuffetPopSequence *sequence);
BOOL WobbuffetPop_HostFinishGame(WobbuffetPop *game, WobbuffetPopSequence *sequence);

enum WobbuffetPopAppState {
    WOBBUFFET_POP_APP_START_PLAYER_LIST,
    WOBBUFFET_POP_APP_RUN_PLAYER_LIST,
    WOBBUFFET_POP_APP_START_GAME,
    WOBBUFFET_POP_APP_RUN_GAME,
    WOBBUFFET_POP_APP_START_RESULTS,
    WOBBUFFET_POP_APP_RUN_RESULTS,
    WOBBUFFET_POP_APP_START_SYNC,
    WOBBUFFET_POP_APP_WAIT_SYNC,
    WOBBUFFET_POP_APP_DONE,
};

enum WobbuffetPopState {
    WOBBUFFET_POP_STATE_WAIT_FADE_IN,
    WOBBUFFET_POP_STATE_START_SYNC,
    WOBBUFFET_POP_STATE_WAIT_SYNC,
    WOBBUFFET_POP_STATE_SEND_PLAYER_VALUE,
    WOBBUFFET_POP_STATE_WAIT_PLAYERS,
    WOBBUFFET_POP_STATE_PLAY,
    WOBBUFFET_POP_STATE_WAIT_FADE_OUT,
};

enum WobbuffetPopHostStep {
    WOBBUFFET_POP_HOST_START,
    WOBBUFFET_POP_HOST_PLAY,
    WOBBUFFET_POP_HOST_FINISH,
    WOBBUFFET_POP_HOST_DONE,
};

enum WobbuffetPopHostStartState {
    WOBBUFFET_POP_HOST_START_QUEUE_SYNC,
    WOBBUFFET_POP_HOST_START_WAIT_SYNC,
    WOBBUFFET_POP_HOST_START_QUEUE_DEMO,
    WOBBUFFET_POP_HOST_START_WAIT_DEMO,
    WOBBUFFET_POP_HOST_START_QUEUE_COUNTDOWN,
    WOBBUFFET_POP_HOST_START_WAIT_COUNTDOWN,
};

enum WobbuffetPopHostPlayState {
    WOBBUFFET_POP_HOST_PLAY_QUEUE_BALLOON,
    WOBBUFFET_POP_HOST_PLAY_WAIT_BALLOON,
    WOBBUFFET_POP_HOST_PLAY_WATCH_AIR,
    WOBBUFFET_POP_HOST_PLAY_WAIT_POP,
};

enum WobbuffetPopHostFinishState {
    WOBBUFFET_POP_HOST_FINISH_QUEUE,
    WOBBUFFET_POP_HOST_FINISH_WAIT_SYNC,
    WOBBUFFET_POP_HOST_FINISH_WAIT_SIGN,
    WOBBUFFET_POP_HOST_FINISH_SEND,
};

static void WobbuffetPopApp_InitRoster(WobbuffetPopApp *app, PlazaGameArgs *args);
static BOOL WobbuffetPopApp_CheckConnectionLost(WobbuffetPopApp *app);
static void WobbuffetPop_VBlankCB(void *data);
static GF3DVramMan *WobbuffetPop_Create3DVramMan(enum HeapID heapId);
static void WobbuffetPop_Init3D(void);
static void WobbuffetPop_Delete3DVramMan(GF3DVramMan *vramMan);
static void WobbuffetPop_CreateCameras(WobbuffetPop *game);
static void WobbuffetPop_DeleteCameras(WobbuffetPop *game);
static void WobbuffetPop_DrawTask(SysTask *task, void *data);
static void WobbuffetPop_InitBgs(BgConfig *bgConfig);
static void WobbuffetPop_AddWindows(WobbuffetPop *game);
static void WobbuffetPop_ShowMessage(WobbuffetPop *game);
static void WobbuffetPop_HideMessageWindow(WobbuffetPop *game);
static void WobbuffetPop_PrintPlayerNames(WobbuffetPop *game);
static void WobbuffetPop_ClearPlayerPanels(WobbuffetPop *game, int started);
static void WobbuffetPop_CreateParticleSystem(WobbuffetPop *game);
static void WobbuffetPop_DestroyParticleSystem(WobbuffetPop *game);
static void WobbuffetPop_EmitParticles(WobbuffetPop *game, int effect);
static u32 WobbuffetPop_AllocParticleTexVram(u32 size, BOOL is4x4comp);
static u32 WobbuffetPop_AllocParticlePlttVram(u32 size, BOOL is4pltt);
static void WobbuffetPop_LoadMainObjGraphics(WobbuffetPop *game, NARC *narc);
static void WobbuffetPop_FreeMainObjGraphics(WobbuffetPop *game);
static void WobbuffetPop_LoadSubObjGraphics(WobbuffetPop *game, NARC *narc);
static void WobbuffetPop_FreeSubObjGraphics(WobbuffetPop *game);
static void WobbuffetPop_LoadMainBgGraphics(WobbuffetPop *game, NARC *narc);
static void WobbuffetPop_FreeMainBgGraphics(WobbuffetPop *game);
static void WobbuffetPop_LoadSubBgGraphics(WobbuffetPop *game, NARC *narc);
static void WobbuffetPop_FreeSubBgGraphics(WobbuffetPop *game);
static void WobbuffetPop_LoadModels(WobbuffetPop *game, NARC *narc);
static void WobbuffetPop_FreeModels(WobbuffetPop *game);
static inline BOOL WobbuffetPop_ShowBalloonModel(WobbuffetPopModels *models, int row, int type, ModelResource *resource);
static void WobbuffetPop_RemoveModelSlot(WobbuffetPop *game, int row, int type);
static void WobbuffetPop_AnimateModelSlots(WobbuffetPop *game);
static void WobbuffetPop_DrawModelSlots(WobbuffetPop *game);
static BOOL WobbuffetPop_IsHost(WobbuffetPop *game);
static int WobbuffetPop_ChooseHost(WobbuffetPop *game);
static WobbuffetPopEvent *WobbuffetPop_GetPlayerEvent(WobbuffetPop *game, int netId);
static BOOL WobbuffetPop_HoldPlayerEvent(WobbuffetPop *game, int netId, const WobbuffetPopEvent *event);
static BOOL WobbuffetPop_HoldEvent(WobbuffetPop *game, const WobbuffetPopEvent *event);
static WobbuffetPopEvent *WobbuffetPop_PeekEvent(WobbuffetPop *game);
static BOOL WobbuffetPop_ProcessEvent(WobbuffetPop *game);
static void WobbuffetPop_ProcessPlayerEvents(WobbuffetPop *game);
static u32 WobbuffetPop_GetBalloonIndex(WobbuffetPop *game);
static int WobbuffetPop_GetPlayerIndex(WobbuffetPop *game, int netId);
static BOOL WobbuffetPop_UpdateSync(WobbuffetPop *game);
static BOOL WobbuffetPop_IsSyncDone(WobbuffetPop *game, u8 syncId);
static BOOL WobbuffetPop_RunHostSteps(WobbuffetPop *game);
static void WobbuffetPop_UpdateCameraDummy(Camera *camera);
static WobbuffetPopBalloon *WobbuffetPopBalloon_New(WobbuffetPop *game);
static void WobbuffetPopBalloon_Free(WobbuffetPop *game, WobbuffetPopBalloon *balloon);
static void WobbuffetPopBalloon_Update(WobbuffetPop *game, WobbuffetPopBalloon *balloon);
static void WobbuffetPopBalloon_VBlank(WobbuffetPop *game, WobbuffetPopBalloon *balloon);
static s32 WobbuffetPopBalloon_CalcAirAmount(WobbuffetPopBalloon *balloon, s32 request);
static void WobbuffetPopBalloon_UpdateReboundSpeed(WobbuffetPopBalloon *balloon, s32 request);
static void WobbuffetPopBalloon_EmitPumpParticles(WobbuffetPop *game, WobbuffetPopBalloon *balloon, u32 request, u32 bonus);
static void WobbuffetPopBalloon_Draw(WobbuffetPopBalloon *balloon);
static void WobbuffetPopBalloon_LoadTexture(WobbuffetPopBalloon *balloon);
static void WobbuffetPopBalloon_LoadPalette(WobbuffetPopBalloon *balloon);
static void WobbuffetPopBalloon_BlendPalette(WobbuffetPopBalloon *balloon, s32 air);
static BOOL WobbuffetPopBalloon_AddAir(WobbuffetPopBalloon *balloon, s32 air);
static void WobbuffetPopBalloon_ResetAir(WobbuffetPopBalloon *balloon);
static void WobbuffetPopBalloon_UpdateFlash(WobbuffetPopBalloon *balloon);
static void WobbuffetPopBalloon_SetMaterial(u32 diffuseIsVertexColor, u32 useShininess);

static const OverlayManagerTemplate sWobbuffetPopGameOverlayTemplate = {
    .init = WobbuffetPop_Init,
    .exec = WobbuffetPop_Main,
    .exit = WobbuffetPop_Exit,
    .ovy_id = 0xFFFFFFFF,
};

static const OverlayManagerTemplate sWobbuffetPopPlazaScreenOverlayTemplate = {
    .init = WobbuffetPopPlazaScreen_Init,
    .exec = WobbuffetPopPlazaScreen_Main,
    .exit = WobbuffetPopPlazaScreen_Exit,
    .ovy_id = 0xFFFFFFFF,
};

BOOL WobbuffetPopApp_Init(OverlayManager *man, int *state) {
    PlazaGameArgs *args;
    WobbuffetPopApp *app;

    args = OverlayManager_GetArgs(man);
    Heap_Create(HEAP_ID_3, HEAP_ID_117, 3 << 17);
    app = OverlayManager_CreateAndGetData(man, sizeof(WobbuffetPopApp), HEAP_ID_117);
    MI_CpuFill8(app, 0, sizeof(WobbuffetPopApp));
    WobbuffetPopApp_InitRoster(app, args);
    return TRUE;
}

BOOL WobbuffetPopApp_Main(OverlayManager *man, int *state) {
    WobbuffetPopApp *app = OverlayManager_GetData(man);
    PlazaGameArgs *args = OverlayManager_GetArgs(man);

    if (WobbuffetPopApp_CheckConnectionLost(app) == TRUE) {
        return TRUE;
    }

    switch (*state) {
    case WOBBUFFET_POP_APP_START_PLAYER_LIST:
        app->screenId = WOBBUFFET_POP_SCREEN_PLAYER_LIST;
        app->screen = OverlayManager_New(&sWobbuffetPopPlazaScreenOverlayTemplate, app, HEAP_ID_117);
        (*state)++;
        break;
    case WOBBUFFET_POP_APP_RUN_PLAYER_LIST:
        if (OverlayManager_Run(app->screen) == TRUE) {
            OverlayManager_Delete(app->screen);
            app->screen = NULL;
            (*state)++;
        }
        break;
    case WOBBUFFET_POP_APP_START_GAME:
        app->screenId = WOBBUFFET_POP_SCREEN_GAME;
        app->screen = OverlayManager_New(&sWobbuffetPopGameOverlayTemplate, app, HEAP_ID_117);
        (*state)++;
        break;
    case WOBBUFFET_POP_APP_RUN_GAME:
        if (OverlayManager_Run(app->screen) == TRUE) {
            OverlayManager_Delete(app->screen);
            app->screen = NULL;
            (*state)++;
        }
        break;
    case WOBBUFFET_POP_APP_START_RESULTS:
        if (args->voiceChat) {
            WifiConnection_StopVoiceChat();
        }
        app->screenId = WOBBUFFET_POP_SCREEN_RESULTS;
        app->screen = OverlayManager_New(&sWobbuffetPopPlazaScreenOverlayTemplate, app, HEAP_ID_117);
        (*state)++;
        break;
    case WOBBUFFET_POP_APP_RUN_RESULTS:
        if (OverlayManager_Run(app->screen) == TRUE) {
            OverlayManager_Delete(app->screen);
            app->screen = NULL;
            if (app->playAgain == TRUE) {
                *state = WOBBUFFET_POP_APP_START_PLAYER_LIST;
            } else {
                (*state)++;
            }
        }
        break;
    case WOBBUFFET_POP_APP_START_SYNC:
        CommState_SetErrorWatch(FALSE, TRUE);
        LinkSync_StartSync(222);
        (*state)++;
        break;
    case WOBBUFFET_POP_APP_WAIT_SYNC:
        if (LinkSync_IsSynced(222) != TRUE) {
            int count = Comm_CountConnected();
            if (count >= CommPlayerInfo_CountAccepted()) {
                break;
            }
        }
        (*state)++;
        break;
    case WOBBUFFET_POP_APP_DONE:
    default:
        return TRUE;
    }
    return FALSE;
}

BOOL WobbuffetPopApp_Exit(OverlayManager *man, int *state) {
    OverlayManager_GetData(man);
    OverlayManager_FreeData(man);
    Heap_Destroy(HEAP_ID_117);
    return TRUE;
}

static void WobbuffetPopApp_InitRoster(WobbuffetPopApp *app, PlazaGameArgs *args) {
    int i;
    int count;

    Comm_GetLocalNetId();
    count = 0;
    for (i = 0; i < 4; i++) {
        if (CommPlayerInfo_GetProfile(i) != NULL) {
            app->netIds[count] = i;
            count++;
        } else {
            app->netIds[i] = 0xFF;
        }
    }
    app->playerCount = count;
    app->voiceChat = args->voiceChat;
    PlazaGameRoster_Init(&app->roster, args->fromLobby, args->saveData, args->voiceChat, args);
}

static BOOL WobbuffetPopApp_CheckConnectionLost(WobbuffetPopApp *app) {
    if (!app->connectionLost) {
        if (PlazaGameRoster_CheckConnectionLost(&app->roster) == TRUE) {
            app->connectionLost = TRUE;
        }
    }
    if (app->connectionLost == TRUE) {
        if (app->screen == NULL) {
            return TRUE;
        }
    }
    return FALSE;
}

static BOOL WobbuffetPop_Init(OverlayManager *man, int *state) {
    WobbuffetPop *game;
    NARC *narc;

    Main_SetVBlankIntrCB(NULL, NULL);
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
    GX_SetVisibleWnd(GX_WNDMASK_NONE);
    GXS_SetVisibleWnd(GX_WNDMASK_NONE);
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG0, GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ | GX_BLEND_PLANEMASK_BD, 16, 16);
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_BG3, GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ, 13, 3);
    game = OverlayManager_CreateAndGetData(man, sizeof(WobbuffetPop), HEAP_ID_117);
    MI_CpuFill8(game, 0, sizeof(WobbuffetPop));
    HeapExp_FndInitAllocator(&game->allocator, HEAP_ID_117, 32);
    game->vramMan = WobbuffetPop_Create3DVramMan(HEAP_ID_117);
    game->app = OverlayManager_GetArgs(man);
    WobbuffetPop_RegisterCommands(game);
    game->paletteData = PaletteData_Init(HEAP_ID_117);
    PaletteData_SetAutoTransparent(game->paletteData, TRUE);
    PaletteData_AllocBuffers(game->paletteData, PLTTBUF_MAIN_BG, 0x200, HEAP_ID_117);
    PaletteData_AllocBuffers(game->paletteData, PLTTBUF_SUB_BG, 0x200, HEAP_ID_117);
    PaletteData_AllocBuffers(game->paletteData, PLTTBUF_MAIN_OBJ, 0x1C0, HEAP_ID_117);
    PaletteData_AllocBuffers(game->paletteData, PLTTBUF_SUB_OBJ, 0x200, HEAP_ID_117);
    game->bgConfig = BgConfig_Alloc(HEAP_ID_117);
    GF_CreateVramTransferManager(64, HEAP_ID_117);
    SetKeyRepeatTimers(4, 8);
    WobbuffetPop_InitBgs(game->bgConfig);
    GF_TouchpadResetSampling();
    GF_TouchpadStartSampling(4);
    WobbuffetPop_CreateCameras(game);
    game->spriteSystem = SpriteSystem_Alloc(HEAP_ID_117);
    SpriteSystem_Init(game->spriteSystem, &gWobbuffetPopOamManagerParam, &gWobbuffetPopOamCharTransfer, 32);
    G2dRenderer_SetObjCharTransferReservedRegion(NNS_G2D_VRAM_TYPE_2DMAIN, GX_OBJVRAMMODE_CHAR_1D_64K);
    G2dRenderer_SetPlttTransferReservedRegion(NNS_G2D_VRAM_TYPE_2DMAIN);
    game->spriteManager = SpriteManager_New(game->spriteSystem);
    SpriteSystem_InitSprites(game->spriteSystem, game->spriteManager, 224);
    SpriteSystem_InitManagerWithCapacities(game->spriteSystem, game->spriteManager, (SpriteResourceCountsListUnion *)&gWobbuffetPopSpriteResourceCounts);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(game->spriteSystem), 0, 352 * FX32_ONE);
    WobbuffetPop_CreateParticleSystem(game);
    game->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0012_bin, HEAP_ID_117);
    game->msgFormat = MessageFormat_New(HEAP_ID_117);
    game->string = String_New(320, HEAP_ID_117);
    game->fontSystem = FontSystem_NewInit(19, HEAP_ID_117);
    WobbuffetPopBonusRing_Init(game, &game->bonusRing);
    narc = NARC_New(NARC_a_1_9_9, HEAP_ID_117);
    WobbuffetPop_LoadMainBgGraphics(game, narc);
    WobbuffetPop_LoadSubBgGraphics(game, narc);
    WobbuffetPop_AddWindows(game);
    WobbuffetPop_LoadMainObjGraphics(game, narc);
    WobbuffetPop_LoadSubObjGraphics(game, narc);
    WobbuffetPop_LoadModels(game, narc);
    NARC_Delete(narc);
    PaletteData_LoadNarc(game->paletteData, NARC_graphic_font, 7, HEAP_ID_117, PLTTBUF_MAIN_BG, 0x20, 0xE0);
    PaletteData_LoadNarc(game->paletteData, NARC_graphic_font, 7, HEAP_ID_117, PLTTBUF_SUB_BG, 0x20, 0x50);
    WobbuffetPop_PrintPlayerNames(game);
    WobbuffetPop_ClearPlayerPanels(game, FALSE);
    WobbuffetPop_ShowMessage(game);
    WirelessStatusIcon_Create();
    game->balloon = WobbuffetPopBalloon_New(game);
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, (enum FadeType)27, (enum FadeType)27, RGB_BLACK, 6, 1, HEAP_ID_117);
    game->drawTask = SysTask_CreateOnMainQueue(WobbuffetPop_DrawTask, game, 60000);
    gSystem.screensFlipped = TRUE;
    GfGfx_SwapDisplay();
    GfGfx_BothDispOn();
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    TextFlags_SetAutoScrollParam(1);
    TextFlags_SetCanABSpeedUpPrint(FALSE);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    game->sign = PlazaGameSign_New(SpriteManager_GetSpriteList(game->spriteManager), HEAP_ID_117);
    PaletteData_LoadPaletteSlotFromHardware(game->paletteData, PLTTBUF_MAIN_OBJ, (u16)(PlazaGameSign_GetPlttOffset(game->sign) << 4), 0x60);
    Main_SetVBlankIntrCB(WobbuffetPop_VBlankCB, game);
    if (game->app->voiceChat) {
        WifiConnection_StartVoiceChat(HEAP_ID_117);
    }
    return TRUE;
}

static BOOL WobbuffetPop_Main(OverlayManager *man, int *state) {
    WobbuffetPop *game = OverlayManager_GetData(man);

    if (game->app->connectionLost == TRUE) {
        switch (game->app->connectionLostState) {
        case WOBBUFFET_POP_CONNECTION_LOST_BLACK_OUT:
            if (IsPaletteFadeFinished() == TRUE) {
                StopPaletteFade();
            }
            SetBothScreensBrightnessByColor(0);
            GX_SetVisibleWnd(GX_WNDMASK_NONE);
            game->app->connectionLostState++;
            break;
        case WOBBUFFET_POP_CONNECTION_LOST_WAIT:
        default:
            if (PlazaGameRoster_ProcessConnectionLost(&game->app->roster) == TRUE) {
                return TRUE;
            }
            break;
        }
        return FALSE;
    }

    switch (*state) {
    case WOBBUFFET_POP_STATE_WAIT_FADE_IN:
        if (IsPaletteFadeFinished() == TRUE) {
            (*state)++;
        }
        break;
    case WOBBUFFET_POP_STATE_START_SYNC:
        LinkSync_StartSync(211);
        (*state)++;
        break;
    case WOBBUFFET_POP_STATE_WAIT_SYNC:
        if (LinkSync_IsSynced(211) == TRUE) {
            (*state)++;
        }
        break;
    case WOBBUFFET_POP_STATE_SEND_PLAYER_VALUE:
        if (WobbuffetPop_SendPlayerValue() == TRUE) {
            (*state)++;
        }
        break;
    case WOBBUFFET_POP_STATE_WAIT_PLAYERS:
        if (game->readyCount >= game->app->playerCount) {
            WobbuffetPop_ChooseHost(game);
            (*state)++;
        }
        break;
    case WOBBUFFET_POP_STATE_PLAY:
        if (game->finished == TRUE) {
            WobbuffetPop_CreateScoreLabels(game);
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, (enum FadeType)26, (enum FadeType)26, RGB_BLACK, 6, 1, HEAP_ID_117);
            (*state)++;
        }
        WobbuffetPop_RunHostSteps(game);
        switch (game->gameState) {
        case WOBBUFFET_POP_GAME_START_DEMO:
            GX_SetVisibleWnd(GX_WNDMASK_W1);
            G2_SetWnd1Position(4, 168, 76, 184);
            G2_SetWnd1InsidePlane(GX_WND_PLANEMASK_OBJ, FALSE);
            G2_SetWndOutsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, TRUE);
            WobbuffetPop_FreeScoreLabels(game);
            game->gameState = WOBBUFFET_POP_GAME_DEMO;
        case WOBBUFFET_POP_GAME_DEMO:
            if (WobbuffetPop_RunDemo(game, &game->demo) == TRUE) {
                game->demoDone = TRUE;
                game->gameState = WOBBUFFET_POP_GAME_IDLE;
            }
            break;
        case WOBBUFFET_POP_GAME_START_COUNTDOWN:
            PlazaGameSign_StartCountdown(game->sign);
            game->gameState = WOBBUFFET_POP_GAME_COUNTDOWN;
            break;
        case WOBBUFFET_POP_GAME_COUNTDOWN:
            if (PlazaGameSign_IsDone(game->sign) == TRUE) {
                game->started = TRUE;
                game->bonusRing.done = 0;
                game->gameState = WOBBUFFET_POP_GAME_PLAYING;
                WobbuffetPop_HideMessageWindow(game);
                WobbuffetPop_ClearPlayerPanels(game, TRUE);
            }
            break;
        case WOBBUFFET_POP_GAME_START_FINISH:
            PlazaGameSign_StartFinish(game->sign);
            game->gameState = WOBBUFFET_POP_GAME_FINISH;
            break;
        case WOBBUFFET_POP_GAME_FINISH:
            if (PlazaGameSign_IsDone(game->sign) == TRUE) {
                game->gameState = WOBBUFFET_POP_GAME_FINISHED;
            }
            break;
        }
        WobbuffetPop_UpdateSync(game);
        WobbuffetPop_ProcessPlayerEvents(game);
        if (game->gameOver != TRUE) {
            if (WobbuffetPop_ProcessEvent(game) == TRUE) {
                game->eventDelay = 13;
            }
            if (game->started == TRUE && game->timer <= 1302) {
                game->timer++;
            }
        }
        break;
    case WOBBUFFET_POP_STATE_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    WobbuffetPop_UpdateCameraDummy(game->camera);
    game->frameCounter++;
    return FALSE;
}

static BOOL WobbuffetPop_Exit(OverlayManager *man, int *state) {
    WobbuffetPop *game;
    Window *window;
    int i;

    game = OverlayManager_GetData(man);
    game->app->results.total = game->total;
    PlazaGameSign_Free(game->sign);
    WobbuffetPop_FreePuffs(game);
    WobbuffetPop_FreeConfetti(game);
    Main_SetVBlankIntrCB(NULL, NULL);
    WobbuffetPop_DestroyParticleSystem(game);
    WobbuffetPop_FreeMainObjGraphics(game);
    WobbuffetPop_FreeSubObjGraphics(game);
    WobbuffetPop_FreeMainBgGraphics(game);
    WobbuffetPop_FreeSubBgGraphics(game);
    WobbuffetPop_FreeModels(game);
    WobbuffetPopBalloon_Free(game, game->balloon);
    i = 0;
    window = game->playerNameWindows;
    for (; i < 5; i++, window++) {
        RemoveWindow(window);
    }
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_OFF);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
    FreeBgTilemapBuffer(game->bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(game->bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(game->bgConfig, GF_BG_LYR_MAIN_3);
    FreeBgTilemapBuffer(game->bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(game->bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(game->bgConfig, GF_BG_LYR_SUB_2);
    FreeBgTilemapBuffer(game->bgConfig, GF_BG_LYR_SUB_3);
    FontSystem_Delete(game->fontSystem);
    SpriteSystem_FreeResourcesAndManager(game->spriteSystem, game->spriteManager);
    SpriteSystem_Free(game->spriteSystem);
    GF_DestroyVramTransferManager();
    PaletteData_FreeBuffers(game->paletteData, PLTTBUF_MAIN_BG);
    PaletteData_FreeBuffers(game->paletteData, PLTTBUF_SUB_BG);
    PaletteData_FreeBuffers(game->paletteData, PLTTBUF_MAIN_OBJ);
    PaletteData_FreeBuffers(game->paletteData, PLTTBUF_SUB_OBJ);
    PaletteData_Free(game->paletteData);
    String_Delete(game->string);
    MessageFormat_Delete(game->msgFormat);
    DestroyMsgData(game->msgData);
    Heap_Free(game->bgConfig);
    WobbuffetPop_DeleteCameras(game);
    SysTask_Destroy(game->drawTask);
    GX_SetVisibleWnd(GX_WNDMASK_NONE);
    GXS_SetVisibleWnd(GX_WNDMASK_NONE);
    WobbuffetPop_Delete3DVramMan(game->vramMan);
    GF_TouchpadStopSampling();
    OverlayManager_FreeData(man);
    TextFlags_SetCanABSpeedUpPrint(FALSE);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    WirelessStatusIcon_Destroy();
    return TRUE;
}

static void WobbuffetPop_VBlankCB(void *data) {
    WobbuffetPop *game = data;

    WobbuffetPopBalloon_VBlank(game, game->balloon);
    GF_RunVramTransferTasks();
    SpriteSystem_TransferOam();
    PaletteData_PushTransparentBuffers(game->paletteData);
    if (game->inflation.showBg == TRUE) {
        ToggleBgLayer(GF_BG_LYR_SUB_3, GF_PLANE_TOGGLE_ON);
        game->inflation.showBg = FALSE;
    } else if (game->inflation.hideBg == TRUE) {
        ToggleBgLayer(GF_BG_LYR_SUB_3, GF_PLANE_TOGGLE_OFF);
        game->inflation.hideBg = FALSE;
    }
    DoScheduledBgGpuUpdates(game->bgConfig);
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static GF3DVramMan *WobbuffetPop_Create3DVramMan(enum HeapID heapId) {
    return GF_3DVramMan_Create(heapId, 0, 1, 0, 2, WobbuffetPop_Init3D);
}

static void WobbuffetPop_Init3D(void) {
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

static void WobbuffetPop_Delete3DVramMan(GF3DVramMan *vramMan) {
    GF_3DVramMan_Delete(vramMan);
}

static void WobbuffetPop_CreateCameras(WobbuffetPop *game) {
    VecFx32 target = gWobbuffetPopCameraTarget;

    game->camera = Camera_New(HEAP_ID_117);
    Camera_Init_FromTargetDistanceAndAngle(&target, 123 * FX32_ONE, &gWobbuffetPopCameraAngle, 4004, 1, FALSE, game->camera);
    Camera_SetPerspectiveClippingPlane(FX32_ONE, 900 * FX32_ONE, game->camera);
    Camera_SetStaticPtr(game->camera);
    game->particleCamera = Camera_New(HEAP_ID_117);
    Camera_Init_FromTargetDistanceAndAngle(&target, 80 * FX32_ONE, &gWobbuffetPopCameraAngle, 4004, 1, FALSE, game->particleCamera);
    Camera_SetPerspectiveClippingPlane(FX32_ONE, 900 * FX32_ONE, game->particleCamera);
}

static void WobbuffetPop_DeleteCameras(WobbuffetPop *game) {
    Camera_Delete(game->camera);
    Camera_Delete(game->particleCamera);
}

static void WobbuffetPop_DrawTask(SysTask *task, void *data) {
    WobbuffetPop *game = data;
    VecFx32 scale;
    VecFx32 trans;
    MtxFx33 rot;
    u32 swapArg;

    scale.x = FX32_ONE;
    scale.y = FX32_ONE;
    scale.z = FX32_ONE;
    trans.x = 0;
    trans.y = 0;
    trans.z = 0;
    MTX_Identity33_(&rot);
    WobbuffetPopScoreDisplay_Update(game, &game->scoreDisplay);
    WobbuffetPopBonusRing_Update(game, &game->bonusRing);
    WobbuffetPop_UpdateBonusPopups(game, game->bonusPopups);
    WobbuffetPop_UpdatePuffs(game);
    WobbuffetPop_UpdateInflation(game, game->bgConfig, &game->inflation);
    WobbuffetPop_UpdateConfetti(game);
    WobbuffetPop_AnimateModelSlots(game);
    WobbuffetPop_UpdateBalloonIcons(game);
    Thunk_G3X_Reset();
    Camera_SetStaticPtr(game->camera);
    Camera_ApplyPerspectiveType(1, game->camera);
    Camera_PushLookAtToNNSGlb();
    NNS_G3dGlbLightVector(GX_LIGHTID_0, 0, -FX32_ONE, 0);
    NNS_G3dGlbLightColor(GX_LIGHTID_0, GX_RGB(28, 28, 28));
    NNS_G3dGlbMaterialColorDiffAmb(GX_RGB(31, 31, 31), GX_RGB(31, 31, 31), FALSE);
    NNS_G3dGlbMaterialColorSpecEmi(GX_RGB(31, 31, 31), GX_RGB(31, 31, 31), FALSE);
    NNS_G3dGlbSetBaseTrans(&trans);
    NNS_G3dGlbSetBaseRot(&rot);
    NNS_G3dGlbSetBaseScale(&scale);
    NNS_G3dGlbFlushP();
    WobbuffetPopBalloon_Update(game, game->balloon);
    NNS_G3dGeBufferOP_N(G3OP_MTX_PUSH, NULL, 0);
    ModelInstance_Draw(&game->common.instance);
    ModelInstance_Draw(&game->models.localModel);
    WobbuffetPop_DrawModelSlots(game);
    swapArg = 1;
    NNS_G3dGeBufferOP_N(G3OP_MTX_POP, &swapArg, 1);
    Thunk_G3X_Reset();
    if (ParticleSystem_DrawAll() > 0) {
        Thunk_G3X_Reset();
    }
    ParticleSystem_CalcAll();
    SpriteSystem_DrawSprites(game->spriteManager);
    SpriteSystem_UpdateTransfer();
    RequestSwap3DBuffers(GX_SORTMODE_AUTO, GX_BUFFERMODE_Z);
    CommState_FrameDummy(HEAP_ID_117, game->bgConfig);
}

static void WobbuffetPop_InitBgs(BgConfig *bgConfig) {
    BgTemplate templates[3];
    GraphicsBanks banks;
    GraphicsModes modes;
    int i;

    GfGfx_DisableEngineAPlanes();
    banks = gWobbuffetPopBanks;
    GfGfx_SetBanks(&banks);
    MI_CpuClear32((void *)HW_BG_VRAM, HW_BG_VRAM_SIZE);
    MI_CpuClear32((void *)HW_DB_BG_VRAM, HW_DB_BG_VRAM_SIZE);
    MI_CpuClear32((void *)HW_OBJ_VRAM, HW_OBJ_VRAM_SIZE);
    MI_CpuClear32((void *)HW_DB_OBJ_VRAM, HW_DB_OBJ_VRAM_SIZE);
    modes = gWobbuffetPopGraphicsModes;
    SetBothScreensModesAndDisable(&modes);
    ARRAY_ASSIGN(templates, gWobbuffetPopMainBgTemplates);
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &templates[0], GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_Y, 0);
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &templates[1], GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, 0);
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &templates[2], GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_Y, 0);
    G2_SetBG0Priority(2);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    for (i = 0; i < NELEMS(gWobbuffetPopSubBgTemplates); i++) {
        if (i < 3) {
            InitBgFromTemplate(bgConfig, (u8)(i + GF_BG_LYR_SUB_0), &gWobbuffetPopSubBgTemplates[i], GF_BG_TYPE_TEXT);
        } else {
            InitBgFromTemplate(bgConfig, (u8)(i + GF_BG_LYR_SUB_0), &gWobbuffetPopSubBgTemplates[i], GF_BG_TYPE_AFFINE);
        }
        BG_ClearCharDataRange((u8)(i + GF_BG_LYR_SUB_0), 0x20, 0, HEAP_ID_117);
        BgClearTilemapBufferAndCommit(bgConfig, (u8)(i + GF_BG_LYR_SUB_0));
        BgSetPosTextAndCommit(bgConfig, (u8)(i + GF_BG_LYR_SUB_0), BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, (u8)(i + GF_BG_LYR_SUB_0), BG_POS_OP_SET_Y, 0);
    }
    ToggleBgLayer(GF_BG_LYR_SUB_3, GF_PLANE_TOGGLE_OFF);
}

static void WobbuffetPop_AddWindows(WobbuffetPop *game) {
    AddWindowParameterized(game->bgConfig, &game->playerNameWindows[0], GF_BG_LYR_MAIN_1, 11, 19, 20, 4, 14, 0x300);
    AddWindowParameterized(game->bgConfig, &game->playerNameWindows[1], GF_BG_LYR_SUB_0, 18, 1, 10, 2, 5, 0x314);
    AddWindowParameterized(game->bgConfig, &game->playerNameWindows[2], GF_BG_LYR_SUB_0, 21, 14, 10, 2, 5, 0x328);
    AddWindowParameterized(game->bgConfig, &game->playerNameWindows[3], GF_BG_LYR_SUB_0, 1, 14, 10, 2, 5, 0x33C);
    FillWindowPixelBuffer(&game->playerNameWindows[1], 15);
    FillWindowPixelBuffer(&game->playerNameWindows[2], 15);
    FillWindowPixelBuffer(&game->playerNameWindows[3], 15);
    AddWindowParameterized(game->bgConfig, &game->messageWindow, GF_BG_LYR_SUB_0, 2, 19, 28, 4, 5, 0x359);
    FillWindowPixelBuffer(&game->messageWindow, 15);
}

static void WobbuffetPop_ShowMessage(WobbuffetPop *game) {
    String *string;

    DrawFrameAndWindow1(&game->messageWindow, TRUE, 0x350, 6);
    string = NewString_ReadMsgData(game->msgData, msg_0012_00003);
    AddTextPrinterParameterizedWithColor(&game->messageWindow, 0, string, 0, 0, 0, MAKE_TEXT_COLOR(1, 2, 15), NULL);
    String_Delete(string);
    ScheduleWindowCopyToVram(&game->messageWindow);
}

static void WobbuffetPop_HideMessageWindow(WobbuffetPop *game) {
    FillBgTilemapRect(game->bgConfig, GF_BG_LYR_SUB_0, 0x3FF, 1, 18, 30, 6, TILEMAP_FILL_OVWT_PAL);
    ScheduleBgTilemapBufferTransfer(game->bgConfig, GF_BG_LYR_SUB_0);
}

#pragma opt_common_subs off
#pragma opt_rotateloops off
static void WobbuffetPop_PrintPlayerNames(WobbuffetPop *game) {
    int position;
    int width;
    String *name;
    int self;
    int i;
    int color;
    int x;

    self = Comm_GetLocalNetId();
    for (i = 0; i < game->app->playerCount; i++) {
        if (self != game->app->netIds[i]) {
            name = PlayerProfile_GetPlayerName_NewString(PlazaGameRoster_GetProfile(&game->app->roster, game->app->netIds[i]), HEAP_ID_117);
            position = WobbuffetPop_GetPlayerSeat(game, game->app->netIds[i]);
            if (PlazaGameRoster_IsSpecialVisitor(&game->app->roster, game->app->netIds[i]) == TRUE) {
                color = MAKE_TEXT_COLOR(7, 8, 15);
            } else {
                color = MAKE_TEXT_COLOR(1, 2, 15);
            }
            width = FontID_String_GetWidth(0, name, 0);
            x = 40 - width / 2;
            if (width & 1) {
                x--;
            }
            AddTextPrinterParameterizedWithColor(&game->playerNameWindows[(gWobbuffetPopNameWindowIndices + 4 * game->app->playerCount)[position]], 0, name, x, 0, 0, color, NULL);
            Heap_Free(name);
        }
    }
}
#pragma opt_rotateloops reset
#pragma opt_common_subs reset

static void WobbuffetPop_ClearPlayerPanels(WobbuffetPop *game, int started) {
    if (started == TRUE) {
        FillBgTilemapRect(game->bgConfig, GF_BG_LYR_SUB_0, 0x3FF, 0, 13, 12, 4, TILEMAP_FILL_OVWT_PAL);
        FillBgTilemapRect(game->bgConfig, GF_BG_LYR_SUB_0, 0x3FF, 17, 0, 12, 4, TILEMAP_FILL_OVWT_PAL);
        FillBgTilemapRect(game->bgConfig, GF_BG_LYR_SUB_0, 0x3FF, 20, 13, 12, 4, TILEMAP_FILL_OVWT_PAL);
    } else {
        switch (game->app->playerCount) {
        case 2:
            FillBgTilemapRect(game->bgConfig, GF_BG_LYR_SUB_0, 0x3FF, 0, 13, 12, 4, TILEMAP_FILL_OVWT_PAL);
            FillBgTilemapRect(game->bgConfig, GF_BG_LYR_SUB_0, 0x3FF, 20, 13, 12, 4, TILEMAP_FILL_OVWT_PAL);
            break;
        case 3:
            FillBgTilemapRect(game->bgConfig, GF_BG_LYR_SUB_0, 0x3FF, 17, 0, 12, 4, TILEMAP_FILL_OVWT_PAL);
            break;
        }
    }
    ScheduleBgTilemapBufferTransfer(game->bgConfig, GF_BG_LYR_SUB_0);
}

static void WobbuffetPop_CreateParticleSystem(WobbuffetPop *game) {
    void *heap;

    ParticleSystem_ZeroAll();
    heap = Heap_Alloc(HEAP_ID_117, 0x4800);
    game->particleSystem = ParticleSystem_New(WobbuffetPop_AllocParticleTexVram, WobbuffetPop_AllocParticlePlttVram, heap, 0x4800, TRUE, HEAP_ID_117);
    Camera_SetPerspectiveClippingPlane(FX32_ONE, 900 * FX32_ONE, ParticleSystem_GetCamera(game->particleSystem));
    ParticleSystem_SetResource(game->particleSystem, ParticleSystem_LoadResourceFile(NARC_a_2_1_1, 0, HEAP_ID_117), 10, TRUE);
}

static void WobbuffetPop_DestroyParticleSystem(WobbuffetPop *game) {
    void *heap = ParticleSystem_GetHeap(game->particleSystem);

    ParticleSystem_Free(game->particleSystem);
    Heap_Free(heap);
}

static void WobbuffetPop_EmitParticles(WobbuffetPop *game, int effect) {
    switch (effect) {
    case 0:
        ParticleSystem_CreateEmitterWithParam(game->particleSystem, 0, NULL, game);
        break;
    case 1:
        ParticleSystem_CreateEmitterWithParam(game->particleSystem, 1, NULL, game);
        break;
    case 2:
        ParticleSystem_CreateEmitterWithParam(game->particleSystem, 2, NULL, game);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

static u32 WobbuffetPop_AllocParticleTexVram(u32 size, BOOL is4x4comp) {
    NNSGfdTexKey key = NNS_GfdAllocTexVram(size, is4x4comp, 0);

    GF_ASSERT(key != NNS_GFD_ALLOC_ERROR_TEXKEY);
    ParticleSystem_RegisterTexKey(key);
    return NNS_GfdGetTexKeyAddr(key);
}

static u32 WobbuffetPop_AllocParticlePlttVram(u32 size, BOOL is4pltt) {
    NNSGfdPlttKey key = NNS_GfdAllocPlttVram(size, is4pltt, TRUE);

    GF_ASSERT(key != NNS_GFD_ALLOC_ERROR_PLTTKEY);
    ParticleSystem_RegisterPlttKey(key);
    return NNS_GfdGetPlttKeyAddr(key);
}

static void WobbuffetPop_LoadMainObjGraphics(WobbuffetPop *game, NARC *narc) {
    String *string;
    String *string1;
    int i;
    String *string0;
    u32 x;
    WobbuffetPopTextObj *top;
    WobbuffetPopTextObj *bottom;

    SpriteSystem_LoadPaletteBufferFromOpenNarc(game->paletteData, PLTTBUF_MAIN_OBJ, game->spriteSystem, game->spriteManager, narc, 27, FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 10003);
    string = NewString_ReadMsgData(game->msgData, msg_0012_00002);
    x = ((30 - FontID_String_GetWidth(0, string, 0)) >> 1) + 6;
    WobbuffetPop_NewTextObj(game->bgConfig, game->spriteManager, game->fontSystem, &game->scoreDisplay.title, string, 0, MAKE_TEXT_COLOR(14, 15, 0), 0, 10003, x + 36, 168, 0, 1, 12, 2);
    String_Delete(string);
    string0 = NewString_ReadMsgData(game->msgData, msg_0012_00000);
    string1 = NewString_ReadMsgData(game->msgData, msg_0012_00001);
    i = 0;
    top = &game->scoreDisplay.digits[0].top;
    bottom = &game->scoreDisplay.digits[0].bottom;
    for (; i < 6; i++) {
        WobbuffetPop_NewTextObj(game->bgConfig, game->spriteManager, game->fontSystem, top, string0, 0, MAKE_TEXT_COLOR(14, 15, 0), 0, 10003, x, 168, 0, 3, 12, 10);
        WobbuffetPop_NewTextObj(game->bgConfig, game->spriteManager, game->fontSystem, bottom, string1, 0, MAKE_TEXT_COLOR(14, 15, 0), 0, 10003, x, 168, 0, 3, 12, 10);
        x += 6;
        top += 2; // next digit: skip its top and bottom text
        bottom += 2;
    }
    String_Delete(string0);
    String_Delete(string1);
    WobbuffetPopScoreDisplay_PlaceDigits(&game->scoreDisplay);
    WobbuffetPop_CreateScoreLabels(game);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(game->paletteData, PLTTBUF_MAIN_OBJ, game->spriteSystem, game->spriteManager, narc, 27, FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 10004);
    SpriteSystem_LoadCharResObjFromOpenNarc(game->spriteSystem, game->spriteManager, narc, 24, FALSE, NNS_G2D_VRAM_TYPE_2DMAIN, 10002);
    SpriteSystem_LoadCellResObjFromOpenNarc(game->spriteSystem, game->spriteManager, narc, 26, FALSE, 10002);
    SpriteSystem_LoadAnimResObjFromOpenNarc(game->spriteSystem, game->spriteManager, narc, 25, FALSE, 10002);
    game->scoreDisplay.frame = WobbuffetPop_CreateScoreFrameSprite(game);
    SpriteSystem_LoadPaletteBuffer(game->paletteData, PLTTBUF_MAIN_OBJ, game->spriteSystem, game->spriteManager, NARC_a_1_9_8, 20, FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 10002);
    SpriteSystem_LoadCharResObj(game->spriteSystem, game->spriteManager, NARC_a_1_9_8, 21, FALSE, NNS_G2D_VRAM_TYPE_2DMAIN, 10001);
    SpriteSystem_LoadCellResObj(game->spriteSystem, game->spriteManager, NARC_a_1_9_8, 22, FALSE, 10001);
    SpriteSystem_LoadAnimResObj(game->spriteSystem, game->spriteManager, NARC_a_1_9_8, 23, FALSE, 10001);
    game->demo.stylus = WobbuffetPop_CreateDemoStylusSprite(game);
}

static void WobbuffetPop_FreeMainObjGraphics(WobbuffetPop *game) {
    int i;
    WobbuffetPopTextObj *top;
    WobbuffetPopTextObj *bottom;

    top = &game->scoreDisplay.digits[0].top;
    bottom = &game->scoreDisplay.digits[0].bottom;
    for (i = 0; i < 6; i++, top += 2, bottom += 2) {
        WobbuffetPopTextObj_Free(top);
        WobbuffetPopTextObj_Free(bottom);
    }
    WobbuffetPopTextObj_Free(&game->scoreDisplay.title);
    WobbuffetPop_FreeScoreLabels(game);
    WobbuffetPop_DeleteScoreFrameSprite(game, game->scoreDisplay.frame);
    WobbuffetPop_DeleteDemoStylusSprite(game, game->demo.stylus);
}

static void WobbuffetPop_LoadSubObjGraphics(WobbuffetPop *game, NARC *narc) {
    SpriteSystem_LoadPaletteBufferFromOpenNarc(game->paletteData, PLTTBUF_SUB_OBJ, game->spriteSystem, game->spriteManager, narc, 23, FALSE, 9, NNS_G2D_VRAM_TYPE_2DSUB, 10006);
    SpriteSystem_LoadCharResObjFromOpenNarc(game->spriteSystem, game->spriteManager, narc, 20, FALSE, NNS_G2D_VRAM_TYPE_2DSUB, 10004);
    SpriteSystem_LoadCellResObjFromOpenNarc(game->spriteSystem, game->spriteManager, narc, 22, FALSE, 10004);
    SpriteSystem_LoadAnimResObjFromOpenNarc(game->spriteSystem, game->spriteManager, narc, 21, FALSE, 10004);
    WobbuffetPop_InitBalloonIcons(game);
    WobbuffetPop_CreateSeatSprites(game, game->seatSprites);
    WobbuffetPopBonusRing_CreateSprites(game, &game->bonusRing);
    WobbuffetPop_CreateBonusPopupSprites(game, game->bonusPopups);
    WobbuffetPop_SetPlayerSubObjPalettes(game);
    WobbuffetPop_SetPlayerSubObjColors(game);
}

static void WobbuffetPop_FreeSubObjGraphics(WobbuffetPop *game) {
    WobbuffetPop_FreeBalloonIcons(game);
    WobbuffetPop_FreeSeatSprites(game, game->seatSprites);
    WobbuffetPopBonusRing_FreeSprites(game, &game->bonusRing);
    WobbuffetPop_FreeBonusPopupSprites(game, game->bonusPopups);
}

static void WobbuffetPop_LoadMainBgGraphics(WobbuffetPop *game, NARC *narc) {
    PaletteData_LoadNarc(game->paletteData, NARC_a_1_9_9, 4, HEAP_ID_117, PLTTBUF_MAIN_BG, 0, 0);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 2, game->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, FALSE, HEAP_ID_117);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 3, game->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, FALSE, HEAP_ID_117);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0, game->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, FALSE, HEAP_ID_117);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 1, game->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, FALSE, HEAP_ID_117);
    PaletteData_FillPaletteInBuffer(game->paletteData, PLTTBUF_MAIN_BG, PLTTSEL_BOTH, RGB_BLACK, 0, 1);
}

static void WobbuffetPop_FreeMainBgGraphics(WobbuffetPop *game) {
}

static void WobbuffetPop_LoadSubBgGraphics(WobbuffetPop *game, NARC *narc) {
    PaletteData_LoadNarc(game->paletteData, NARC_a_1_9_9, 5, HEAP_ID_117, PLTTBUF_SUB_BG, 0xA0, 0);
    PaletteData_LoadFromNarc(game->paletteData, NARC_a_1_9_9, 6, HEAP_ID_117, PLTTBUF_SUB_BG, 0x140, 0x60, 0x60);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 13, game->bgConfig, GF_BG_LYR_SUB_2, 0, 0, FALSE, HEAP_ID_117);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 14, game->bgConfig, GF_BG_LYR_SUB_2, 0, 0, FALSE, HEAP_ID_117);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 18, game->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_117);
    switch (game->app->playerCount) {
    case 2:
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 15, game->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_117);
        break;
    case 3:
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 16, game->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_117);
        break;
    default:
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 17, game->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_117);
        break;
    }
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 18, game->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, HEAP_ID_117);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 19, game->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, HEAP_ID_117);
    WobbuffetPop_SetPlayerSubBgColors(game);
    WobbuffetPop_SetupThreePlayerSubBg(game);
    LoadUserFrameGfx1(game->bgConfig, GF_BG_LYR_SUB_0, 0x350, 6, 0, HEAP_ID_117);
    PaletteData_LoadPaletteSlotFromHardware(game->paletteData, PLTTBUF_SUB_BG, 0x60, 0x20);
    PaletteData_FillPaletteInBuffer(game->paletteData, PLTTBUF_SUB_BG, PLTTSEL_BOTH, RGB_BLACK, 0, 1);
}

static void WobbuffetPop_FreeSubBgGraphics(WobbuffetPop *game) {
}

static void WobbuffetPop_LoadModels(WobbuffetPop *game, NARC *narc) {
    void *animationFile;
    int index;
    WobbuffetPopModels *models;
    int row;
    int type;
    WobbuffetPopCommonModel *common;

    models = &game->models;
    common = &game->common;
    animationFile = NULL;
    index = WobbuffetPop_GetPlayerIndex(game, Comm_GetLocalNetId());
    ModelResource_LoadFromNarc(&models->localResource, narc, gWobbuffetPopLocalModelFiles[index].files[0], HEAP_ID_117);
    ModelInstance_Init(&models->localModel, &models->localResource);
    ModelInstance_SetPosition(&models->localModel, 0, -25 * FX32_ONE, 0);
    ModelInstance_SetScale(&models->localModel, FX32_ONE, FX32_ONE, FX32_ONE);
    ModelInstance_SetVisible(&models->localModel, TRUE);
    ModelResource_LoadFromNarc(&models->slotResources[0], narc, gWobbuffetPopSlotModelFiles0[index].files[0], HEAP_ID_117);
    ModelResource_LoadFromNarc(&models->slotResources[1], narc, gWobbuffetPopSlotModelFiles1[index].files[0], HEAP_ID_117);
    ModelResource_LoadFromNarc(&models->slotResources[2], narc, gWobbuffetPopSlotModelFiles2[index].files[0], HEAP_ID_117);
    ModelResource_LoadFromNarc(&models->slotResources[3], narc, gWobbuffetPopSlotModelFiles3[index].files[0], HEAP_ID_117);
    row = 0;
    for (; row < 8; row++) {
        for (type = 0; type < 4; type++) {
            if (animationFile == NULL) {
                ModelAnimation_LoadFromNarc(&models->slots[row][type].animation, &models->slotResources[type], narc, type + 35, HEAP_ID_117, &game->allocator);
                animationFile = models->slots[row][type].animation.file;
            } else {
                ModelAnimation_InitFromFile(&models->slots[row][type].animation, &models->slotResources[type], animationFile, &game->allocator);
            }
            ModelAnimation_SetFrame(&models->slots[row][type].animation, 0);
        }
    }
    ModelResource_LoadFromNarc(&common->resource, narc, 30, HEAP_ID_117);
    ModelInstance_Init(&common->instance, &common->resource);
    ModelInstance_SetPosition(&common->instance, 0, -25 * FX32_ONE, 0);
    ModelInstance_SetScale(&common->instance, FX32_ONE, FX32_ONE, FX32_ONE);
    ModelInstance_SetVisible(&common->instance, TRUE);
}

static void WobbuffetPop_FreeModels(WobbuffetPop *game) {
    int i;
    int j;
    WobbuffetPopModels *models = &game->models;

    ModelResource_Free(&models->localResource);
    for (i = 0; i < 4; i++) {
        ModelResource_Free(&models->slotResources[i]);
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            ModelAnimation_Free(&models->slots[i][j].animation, &game->allocator);
        }
    }
    ModelResource_Free(&game->common.resource);
}

static inline BOOL WobbuffetPop_ShowBalloonModel(WobbuffetPopModels *models, int row, int type, ModelResource *resource) {
    ModelInstance *instance = &models->slots[row][type].instance;
    ModelAnimation *animation;

    ModelInstance_Init(instance, resource);
    ModelInstance_SetPosition(instance, 0, -25 * FX32_ONE, 0);
    ModelInstance_SetScale(instance, FX32_ONE, FX32_ONE, FX32_ONE);
    ModelInstance_SetVisible(instance, TRUE);
    animation = &models->slots[row][type].animation;
    ModelAnimation_SetFrame(animation, 0);
    ModelInstance_AddAnimation(instance, animation);
    models->slots[row][type].active = TRUE;
    PlaySE(SEQ_SE_PL_BALLOON03_2);
    return TRUE;
}

BOOL WobbuffetPop_AddModelSlot(WobbuffetPop *game, u32 amount) {
    s32 value = (s32)amount;
    WobbuffetPopModels *models = &game->models;
    int type;
    int row;
    ModelResource *resource;

    if (value > 1200) {
        type = 3;
    } else if (value > 2) {
        type = 2;
    } else if (value > 1) {
        type = 1;
    } else {
        type = 0;
    }
    resource = &models->slotResources[type];
    for (row = 0; row < 8; row++) {
        if (models->slots[row][type].active == FALSE) {
            return WobbuffetPop_ShowBalloonModel(models, row, type, resource);
        }
    }
    return FALSE;
}

static void WobbuffetPop_RemoveModelSlot(WobbuffetPop *game, int row, int type) {
    WobbuffetPopModels *models = &game->models;

    ModelInstance_RemoveAnimation(&models->slots[row][type].instance, &models->slots[row][type].animation);
    models->slots[row][type].active = FALSE;
}

#define MODEL_SLOT(slot) (((WobbuffetPopModels *)(slot))->slots[0][0])

static void WobbuffetPop_AnimateModelSlots(WobbuffetPop *game) {
    u8 *slotRow = (u8 *)&game->models;
    u8 *animationRow;
    int i;
    int j;

    i = 0;
    animationRow = (u8 *)&MODEL_SLOT(slotRow).animation;
    for (; i < 8; i++) {
        u8 *slot = slotRow;
        u8 *animation = animationRow;
        for (j = 0; j < 4; j++) {
            if (MODEL_SLOT(slot).active == TRUE && ModelAnimation_Advance((ModelAnimation *)animation, FX32_ONE) == TRUE) {
                WobbuffetPop_RemoveModelSlot(game, i, j);
            }
            slot += sizeof(WobbuffetPopModelSlot);
            animation += sizeof(WobbuffetPopModelSlot);
        }
        slotRow += sizeof(game->models.slots[0]);
        animationRow += sizeof(game->models.slots[0]);
    }
}

static void WobbuffetPop_DrawModelSlots(WobbuffetPop *game) {
    int i;
    u8 *slotRow;
    u8 *instanceRow;
    int j;

    slotRow = (u8 *)&game->models;
    instanceRow = slotRow;
    i = 0;
    instanceRow = (u8 *)&MODEL_SLOT(instanceRow).instance;
    for (; i < 8; i++) {
        u8 *slot;
        u8 *instance;
        slot = slotRow;
        j = 0;
        instance = instanceRow;
        for (; j < 4; j++) {
            if (MODEL_SLOT(slot).active == TRUE) {
                ModelInstance_Draw((ModelInstance *)instance);
            }
            slot += sizeof(WobbuffetPopModelSlot);
            instance += sizeof(WobbuffetPopModelSlot);
        }
        slotRow += sizeof(game->models.slots[0]);
        instanceRow += sizeof(game->models.slots[0]);
    }
}

#undef MODEL_SLOT

static BOOL WobbuffetPop_IsHost(WobbuffetPop *game) {
    if (game->hostNetId == Comm_GetLocalNetId()) {
        return TRUE;
    }
    return FALSE;
}

static int WobbuffetPop_ChooseHost(WobbuffetPop *game) {
    int hostNetId;
    int i;
    u32 max;

    max = game->playerValues[0];
    hostNetId = game->app->netIds[0];
    for (i = 1; i < game->app->playerCount; i++) {
        if (max < game->playerValues[i]) {
            max = game->playerValues[i];
            hostNetId = game->app->netIds[i];
        }
    }
    game->hostNetId = hostNetId;
    return hostNetId;
}

void WobbuffetPop_QueuePlayerEvent(WobbuffetPop *game, int netId, const WobbuffetPopEvent *event) {
    s32 *counts;
    WobbuffetPopEvent *dest;

    if (WobbuffetPop_HoldPlayerEvent(game, netId, event) == TRUE) {
        return;
    }
    counts = game->playerEventWriteCounts;
    dest = &game->playerEvents[netId][counts[netId] % WOBBUFFET_POP_EVENT_QUEUE_SIZE];
    counts[netId]++;
    GF_ASSERT(dest->kind == WOBBUFFET_POP_EVENT_NONE);
    *dest = *event;
}

static WobbuffetPopEvent *WobbuffetPop_GetPlayerEvent(WobbuffetPop *game, int netId) {
    u32 *counts;
    s32 index;
    WobbuffetPopEvent *queue;

    counts = game->playerEventReadCounts;
    index = (s32)counts[netId] % WOBBUFFET_POP_EVENT_QUEUE_SIZE;
    queue = game->playerEvents[netId];
    if (queue[index].kind != WOBBUFFET_POP_EVENT_NONE) {
        counts[netId]++;
        return &queue[index];
    }
    return NULL;
}

static BOOL WobbuffetPop_HoldPlayerEvent(WobbuffetPop *game, int netId, const WobbuffetPopEvent *event) {
    switch (event->kind) {
    case WOBBUFFET_POP_EVENT_NONE:
        break;
    case WOBBUFFET_POP_EVENT_PUMP:
        break;
    case WOBBUFFET_POP_EVENT_POP:
    case WOBBUFFET_POP_EVENT_NEW_BALLOON:
    case WOBBUFFET_POP_EVENT_COUNTDOWN:
    case WOBBUFFET_POP_EVENT_FINISH:
    case WOBBUFFET_POP_EVENT_SYNC:
    case WOBBUFFET_POP_EVENT_DEMO:
        GF_ASSERT(game->pendingEvent.kind == WOBBUFFET_POP_EVENT_NONE);
        game->pendingEvent = *event;
        return TRUE;
    }
    return FALSE;
}

void WobbuffetPop_QueueEvent(WobbuffetPop *game, const WobbuffetPopEvent *event) {
    WobbuffetPopEvent *dest;

    if (WobbuffetPop_HoldEvent(game, event) == TRUE) {
        return;
    }
    dest = &game->events[game->eventWriteCount % WOBBUFFET_POP_EVENT_QUEUE_SIZE];
    game->eventWriteCount++;
    GF_ASSERT(dest->kind == WOBBUFFET_POP_EVENT_NONE);
    *dest = *event;
}

static BOOL WobbuffetPop_HoldEvent(WobbuffetPop *game, const WobbuffetPopEvent *event) {
    u32 kind = event->kind;
    u32 current;

    switch (kind) {
    case WOBBUFFET_POP_EVENT_NONE:
        break;
    case WOBBUFFET_POP_EVENT_PUMP:
        break;
    case WOBBUFFET_POP_EVENT_POP:
    case WOBBUFFET_POP_EVENT_NEW_BALLOON:
    case WOBBUFFET_POP_EVENT_COUNTDOWN:
    case WOBBUFFET_POP_EVENT_FINISH:
    case WOBBUFFET_POP_EVENT_SYNC:
    case WOBBUFFET_POP_EVENT_DEMO:
        current = game->currentEvent.kind;
        if (current == WOBBUFFET_POP_EVENT_NONE) {
            game->currentEvent = *event;
            return TRUE;
        }
        if (kind == current) {
            return TRUE;
        }
        GF_ASSERT(FALSE);
        return FALSE;
    }
    return FALSE;
}

static WobbuffetPopEvent *WobbuffetPop_PeekEvent(WobbuffetPop *game) {
    WobbuffetPopEvent *event = &game->events[game->eventReadCount % WOBBUFFET_POP_EVENT_QUEUE_SIZE];

    if (event->kind == WOBBUFFET_POP_EVENT_NONE) {
        return NULL;
    }
    return event;
}

static BOOL WobbuffetPop_ProcessEvent(WobbuffetPop *game) {
    WobbuffetPopEvent *event;

    if (game->eventDelay > 0) {
        game->eventDelay = game->eventDelay - 1;
        return FALSE;
    }
    if (game->currentEvent.kind != WOBBUFFET_POP_EVENT_NONE) {
        if (WobbuffetPop_SendEvent(game, &game->currentEvent) == TRUE) {
            game->currentEvent.kind = WOBBUFFET_POP_EVENT_NONE;
            return TRUE;
        }
        return FALSE;
    }
    event = WobbuffetPop_PeekEvent(game);
    if (event == NULL) {
        return FALSE;
    }
    if (WobbuffetPop_SendEvent(game, event) == TRUE) {
        event->kind = WOBBUFFET_POP_EVENT_NONE;
        game->eventReadCount++;
        return TRUE;
    }
    return FALSE;
}

static void WobbuffetPop_ProcessPlayerEvents(WobbuffetPop *game) {
    int i;
    WobbuffetPopEvent *event;

    if (WobbuffetPop_RunEvent(game, &game->pendingEvent) == TRUE) {
        return;
    }
    i = 0;
    for (; i < game->app->playerCount; i++) {
        do {
            event = WobbuffetPop_GetPlayerEvent(game, game->app->netIds[i]);
            if (event == NULL) {
                break;
            }
            WobbuffetPop_RunEvent(game, event);
        } while (TRUE);
    }
}

static u32 WobbuffetPop_GetBalloonIndex(WobbuffetPop *game) {
    return game->balloonIndex;
}

#pragma optimization_level 2
#pragma opt_common_subs off
#pragma opt_rebuildlogicals off
int WobbuffetPop_GetPlayerSeat(WobbuffetPop *game, int netId) {
    int localNetId;
    int them;
    int me;
    int i;
    int themPos;
    int mePos;
    int diff;

    localNetId = Comm_GetLocalNetId();
    them = 0xFF;
    me = them;
    for (i = 0; i < game->app->playerCount; i++) {
        if (localNetId == game->app->netIds[i]) {
            me = i;
        }
        if (netId == game->app->netIds[i]) {
            them = i;
        }
    }
    GF_ASSERT(them != 0xFF && me != 0xFF);
    for (i = 0; i < game->app->playerCount; i++) {
        if (me == gWobbuffetPopSeatOrders[game->app->playerCount][i]) {
            mePos = i;
        }
        if (them == gWobbuffetPopSeatOrders[game->app->playerCount][i]) {
            themPos = i;
        }
    }
    diff = themPos - mePos;
    if (diff < 0) {
        diff += game->app->playerCount;
    }
    return diff;
}
#pragma opt_rebuildlogicals reset
#pragma opt_common_subs reset
#pragma optimization_level reset

static int WobbuffetPop_GetPlayerIndex(WobbuffetPop *game, int netId) {
    int i;

    for (i = 0; i < game->app->playerCount; i++) {
        if (netId == game->app->netIds[i]) {
            return i;
        }
    }
    GF_ASSERT(FALSE);
    return 0;
}

void WobbuffetPop_RequestSync(WobbuffetPop *game, u32 kind, u32 syncId) {
    GF_ASSERT(game->syncKind == WOBBUFFET_POP_SYNC_NONE);
    game->syncKind = kind;
    game->syncId = syncId;
}

static BOOL WobbuffetPop_UpdateSync(WobbuffetPop *game) {
    BOOL ready = FALSE;

    switch (game->syncKind) {
    case WOBBUFFET_POP_SYNC_START:
        ready = TRUE;
        break;
    case WOBBUFFET_POP_SYNC_COUNTDOWN:
        ready = TRUE;
        break;
    case WOBBUFFET_POP_SYNC_FINISH:
        ready = TRUE;
        break;
    case WOBBUFFET_POP_SYNC_NEW_BALLOON:
        if (game->balloonInPlay == TRUE) {
            ready = TRUE;
        }
        break;
    case WOBBUFFET_POP_SYNC_POP:
        if (!game->confetti.active) {
            ready = TRUE;
        }
        break;
    case WOBBUFFET_POP_SYNC_DEMO:
        if (game->demoDone == TRUE) {
            ready = TRUE;
        }
        break;
    default:
        return FALSE;
    }
    if (ready == TRUE) {
        LinkSync_StartSync(game->syncId);
        if (WobbuffetPop_IsHost(game) == TRUE) {
            game->syncKind = WOBBUFFET_POP_SYNC_WAITING;
        } else {
            game->syncKind = WOBBUFFET_POP_SYNC_NONE;
        }
        return TRUE;
    }
    return FALSE;
}

static BOOL WobbuffetPop_IsSyncDone(WobbuffetPop *game, u8 syncId) {
    if (game->syncKind != WOBBUFFET_POP_SYNC_WAITING) {
        return FALSE;
    }
    if (game->syncId != syncId) {
        return FALSE;
    }
    if (LinkSync_IsSynced(game->syncId) == TRUE) {
        game->syncKind = WOBBUFFET_POP_SYNC_NONE;
        return TRUE;
    }
    return FALSE;
}

BOOL WobbuffetPop_HostStartGame(WobbuffetPop *game, WobbuffetPopSequence *sequence) {
    switch (sequence->state) {
    case WOBBUFFET_POP_HOST_START_QUEUE_SYNC:
        WobbuffetPop_QueueSyncEvent(game, WOBBUFFET_POP_SYNC_START, sequence->syncId);
        sequence->state++;
        break;
    case WOBBUFFET_POP_HOST_START_WAIT_SYNC:
        if (WobbuffetPop_IsSyncDone(game, sequence->syncId) == TRUE) {
            sequence->syncId++;
            sequence->state++;
        }
        break;
    case WOBBUFFET_POP_HOST_START_QUEUE_DEMO:
        WobbuffetPop_QueueDemoEvent(game, sequence->syncId);
        sequence->state++;
        break;
    case WOBBUFFET_POP_HOST_START_WAIT_DEMO:
        if (WobbuffetPop_IsSyncDone(game, sequence->syncId) == TRUE) {
            sequence->syncId++;
            sequence->state++;
        }
        break;
    case WOBBUFFET_POP_HOST_START_QUEUE_COUNTDOWN:
        WobbuffetPop_QueueCountdownEvent(game, sequence->syncId);
        sequence->state++;
        break;
    case WOBBUFFET_POP_HOST_START_WAIT_COUNTDOWN:
        if (WobbuffetPop_IsSyncDone(game, sequence->syncId) == TRUE) {
            sequence->syncId++;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL WobbuffetPop_HostPlayGame(WobbuffetPop *game, WobbuffetPopSequence *sequence) {
    if (game->timer > 1302 && !game->syncKind && !game->currentEvent.kind && !game->pendingEvent.kind) {
        return TRUE;
    }
    switch (sequence->state) {
    case WOBBUFFET_POP_HOST_PLAY_QUEUE_BALLOON: {
        int value = WobbuffetPop_GetBalloonSize(game->balloonIndex);
        WobbuffetPop_QueueNewBalloonEvent(game, game->balloonIndex, value, sequence->syncId);
        sequence->state++;
        break;
    }
    case WOBBUFFET_POP_HOST_PLAY_WAIT_BALLOON:
        if (WobbuffetPop_IsSyncDone(game, sequence->syncId) == TRUE) {
            sequence->syncId++;
            sequence->state++;
        }
        break;
    case WOBBUFFET_POP_HOST_PLAY_WATCH_AIR:
        if (game->inflation.capacity != 0 && game->inflation.air >= game->inflation.capacity) {
            game->balloonIndex++;
            WobbuffetPop_QueuePopEvent(game, WobbuffetPop_GetBalloonIndex(game), sequence->syncId);
            sequence->state++;
        }
        break;
    case WOBBUFFET_POP_HOST_PLAY_WAIT_POP:
        if (WobbuffetPop_IsSyncDone(game, sequence->syncId) == TRUE) {
            sequence->syncId++;
            sequence->state = WOBBUFFET_POP_HOST_PLAY_QUEUE_BALLOON;
        }
        break;
    }
    return FALSE;
}

BOOL WobbuffetPop_HostFinishGame(WobbuffetPop *game, WobbuffetPopSequence *sequence) {
    switch (sequence->state) {
    case WOBBUFFET_POP_HOST_FINISH_QUEUE:
        WobbuffetPop_QueueFinishEvent(game, sequence->syncId);
        sequence->state++;
        break;
    case WOBBUFFET_POP_HOST_FINISH_WAIT_SYNC:
        if (WobbuffetPop_IsSyncDone(game, sequence->syncId) == TRUE) {
            sequence->syncId++;
            sequence->state++;
        }
        break;
    case WOBBUFFET_POP_HOST_FINISH_WAIT_SIGN:
        if (game->gameState == WOBBUFFET_POP_GAME_FINISHED) {
            sequence->state++;
        }
        break;
    case WOBBUFFET_POP_HOST_FINISH_SEND:
        sequence->timer++;
        if (sequence->timer >= 90 && WobbuffetPop_SendFinished(game) == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static BOOL WobbuffetPop_RunHostSteps(WobbuffetPop *game) {
    WobbuffetPopSequence *sequence;

    if (!WobbuffetPop_IsHost(game)) {
        return FALSE;
    }
    sequence = &game->sequence;
    if (game->sequence.step >= WOBBUFFET_POP_HOST_DONE) {
        return TRUE;
    }
    if (gWobbuffetPopHostSteps[game->sequence.step](game, sequence) == TRUE) {
        sequence->step++;
        sequence->state = 0;
        sequence->timer = 0;
        sequence->unk_10 = 0;
    }
    return FALSE;
}

static void WobbuffetPop_UpdateCameraDummy(Camera *camera) {
}

static WobbuffetPopBalloon *WobbuffetPopBalloon_New(WobbuffetPop *game) {
    WobbuffetPopBalloon *balloon = Heap_Alloc(HEAP_ID_117, sizeof(WobbuffetPopBalloon));

    MI_CpuFill8(balloon, 0, sizeof(WobbuffetPopBalloon));
    balloon->selection = game->app->selection;
    WobbuffetPopBalloon_LoadTexture(balloon);
    WobbuffetPopBalloon_InitMeshVertices(balloon);
    WobbuffetPopBalloon_InitMeshTexCoords(balloon);
    switch (game->app->selection) {
    case 2:
        balloon->scaleX = 64 * FX32_ONE;
        balloon->scaleY = 104 * FX32_ONE;
        break;
    case 1:
        balloon->scaleX = 144 * FX32_ONE;
        balloon->scaleY = 112 * FX32_ONE;
        break;
    default:
        balloon->scaleX = 96 * FX32_ONE;
        balloon->scaleY = 96 * FX32_ONE;
        break;
    }
    balloon->handleX = 128;
    balloon->unk_220 = 40;
    WobbuffetPop_LoadHandleSpriteResources(game);
    balloon->sprite = WobbuffetPop_CreateHandleSprite(game);
    WobbuffetPopBalloon_UpdateHandleSprite(balloon, balloon->sprite);
    balloon->reboundSpeed = 2 * FX32_ONE;
    return balloon;
}

static void WobbuffetPopBalloon_Free(WobbuffetPop *game, WobbuffetPopBalloon *balloon) {
    WobbuffetPop_DeleteHandleSprite(balloon->sprite);
    WobbuffetPop_FreeHandleSpriteResources(game);
    Heap_Free(balloon->textureFile);
    Heap_Free(balloon->paletteSrc);
    Heap_Free(balloon->paletteDest);
    Heap_Free(balloon);
}

static void WobbuffetPopBalloon_Update(WobbuffetPop *game, WobbuffetPopBalloon *balloon) {
    WobbuffetPopPump pump;

    balloon->pumpStrength = 0;
    if (game->gameState == WOBBUFFET_POP_GAME_DEMO) {
        balloon->touch[0] = game->demo.touch[0];
        balloon->touch[1] = game->demo.touch[1];
        balloon->touch[2] = game->demo.touch[2];
        balloon->touch[3] = game->demo.touch[3];
    } else if (!game->started || game->gameOver == TRUE) {
        balloon->touch[0] = 0;
        balloon->touch[1] = 0;
        balloon->touch[2] = 0;
        balloon->touch[3] = 0;
    } else {
        balloon->touch[0] = gSystem.touchX;
        balloon->touch[1] = gSystem.touchY;
        balloon->touch[2] = gSystem.touchHeld;
        balloon->touch[3] = gSystem.touchNew;
    }
    WobbuffetPopBalloon_TryGrabHandle(balloon);
    if (balloon->touch[2] == 0) {
        WobbuffetPopBalloon_ReleaseTouch(balloon);
        if (balloon->vertices[0].topRightY == 0) {
            if (balloon->vertices[0].topRightY == 0) {
                balloon->playingPumpSe = 0;
            }
        }
    }
    WobbuffetPopBalloon_UpdateDrag(balloon);
    WobbuffetPopBalloon_Draw(balloon);
    WobbuffetPopBalloon_UpdateHandleSprite(balloon, balloon->sprite);
    if (balloon->squash > 0) {
        balloon->squash += 8;
        if (balloon->squash > 30) {
            balloon->squash = 30;
        }
        WobbuffetPopBalloon_UpdateFlash(balloon);
    }
    if (!game->gameOver && game->started == TRUE && balloon->pumpStrength > 0) {
        int bonus = 0;
        int amount;
        if (balloon->air < 800) {
            if (WobbuffetPopBalloon_AddAir(balloon, balloon->pumpStrength) == TRUE) {
                balloon->squash = 8;
                balloon->flashCounter = 0;
                PlaySE(SEQ_SE_PL_BALLOON01);
            }
        } else {
            WobbuffetPopBalloon_ResetAir(balloon);
            balloon->squash = 0;
            bonus = 1;
        }
        amount = WobbuffetPopBalloon_CalcAirAmount(balloon, balloon->pumpStrength);
        if (bonus == 1) {
            amount += 25 * amount / 100;
        }
        WobbuffetPop_InitPump(game, game->balloonIndex, amount, &pump);
        WobbuffetPop_QueuePump(game, &pump);
        WobbuffetPop_LaunchPuff(game, &pump);
        WobbuffetPopBalloon_UpdateReboundSpeed(balloon, balloon->pumpStrength);
        WobbuffetPopBalloon_EmitPumpParticles(game, balloon, balloon->pumpStrength, bonus);
        balloon->pumpStrength = 0;
    }
}

static void WobbuffetPopBalloon_VBlank(WobbuffetPop *game, WobbuffetPopBalloon *balloon) {
    if (balloon->paletteDirty == TRUE) {
        balloon->paletteDirty = FALSE;
        WobbuffetPopBalloon_LoadPalette(balloon);
    }
}

static s32 WobbuffetPopBalloon_CalcAirAmount(WobbuffetPopBalloon *balloon, s32 request) {
    s32 amount;

    if (request >= 98) {
        amount = 1200;
    } else {
        amount = request * 10;
    }
    return gWobbuffetPopBalloonAirRates[balloon->selection] * amount / 100;
}

static void WobbuffetPopBalloon_UpdateReboundSpeed(WobbuffetPopBalloon *balloon, s32 request) {
    if (balloon->pumpStrength >= 98) {
        balloon->reboundSpeed += FX32_ONE;
    } else if (balloon->pumpStrength >= 98) {
        balloon->reboundSpeed += FX32_ONE;
    } else {
        balloon->reboundSpeed = 2 * FX32_ONE;
    }
    if (balloon->reboundSpeed > 17 * FX32_ONE) {
        balloon->reboundSpeed = 17 * FX32_ONE;
    }
}

static void WobbuffetPopBalloon_EmitPumpParticles(WobbuffetPop *game, WobbuffetPopBalloon *balloon, u32 request, u32 bonus) {
    s32 x;
    s32 y;

    if (bonus == TRUE && balloon->pumpStrength >= 98) {
        WobbuffetPop_EmitParticles(game, 0);
        PlaySE(SEQ_SE_PL_BALLOON04);
        return;
    }
    if (balloon->pumpStrength < 98) {
        x = balloon->vertices[0].topRightY;
        y = balloon->vertices[0].topLeftY;
        if (y < x) {
            WobbuffetPop_EmitParticles(game, 2);
            PlaySE(SEQ_SE_PL_BALLOON03);
            return;
        }
        if (y > x) {
            WobbuffetPop_EmitParticles(game, 1);
            PlaySE(SEQ_SE_PL_BALLOON03);
        }
    }
}

void WobbuffetPopBalloon_ReleaseTouch(WobbuffetPopBalloon *balloon) {
    if (balloon->grabbing != 0) {
        balloon->grabbing = 0;
        balloon->lastTouchY = -1;
        balloon->pumpStrength = balloon->grabAreaPercent - WobbuffetPopBalloon_CalcMeshAreaPercent(balloon);
        if (balloon->pumpStrength < 25) {
            balloon->pumpStrength = 0;
        }
    }
}

static void WobbuffetPopBalloon_Draw(WobbuffetPopBalloon *balloon) {
    u32 lightVector;
    u32 lightColor;
    VecFx32 translate;
    VecFx32 scale;
    u32 matrixMode;
    u32 matrixMode2;
    u32 texImageParam;
    u32 texPlttBase;
    u32 polygonAttr;
    u32 restore;
    s32 scaleY;
    s32 scaleX;
    s32 base;
    NNSG3dResTex *texture;

    lightVector = 0x2D8B6127;
    NNS_G3dGeBufferOP_N(G3OP_LIGHT_VECTOR, &lightVector, 1);
    lightColor = GX_RGB(31, 31, 31);
    NNS_G3dGeBufferOP_N(G3OP_LIGHT_COLOR, &lightColor, 1);
    NNS_G3dGeBufferOP_N(G3OP_MTX_PUSH, NULL, 0);
    translate.x = 0;
    translate.y = 19 * FX32_ONE;
    translate.z = -5 * FX32_ONE;
    NNS_G3dGeBufferOP_N(G3OP_MTX_TRANS, (u32 *)&translate, 3);
    base = balloon->scaleY;
    scaleY = base + base * balloon->extraScaleYPercent / 100;
    base = balloon->scaleX;
    scaleX = base + base * (balloon->squash + balloon->extraScaleXPercent) / 100;
    scale.x = scaleX;
    scale.z = FX32_ONE;
    scale.y = scaleY;
    NNS_G3dGeBufferOP_N(G3OP_MTX_SCALE, (u32 *)&scale, 3);
    matrixMode = GX_MTXMODE_TEXTURE;
    NNS_G3dGeBufferOP_N(G3OP_MTX_MODE, &matrixMode, 1);
    NNS_G3dGeBufferOP_N(G3OP_MTX_IDENTITY, NULL, 0);
    matrixMode2 = GX_MTXMODE_POSITION_VECTOR;
    NNS_G3dGeBufferOP_N(G3OP_MTX_MODE, &matrixMode2, 1);
    WobbuffetPopBalloon_SetMaterial(1, 1);
    WobbuffetPopBalloon_LoadShininessTable();
    texture = balloon->texture;
    base = (u16)texture->plttInfo.vramKey;
    texImageParam = 0x72400000 | ((u16)texture->texInfo.vramKey & 0x1FFFFFFF);
    NNS_G3dGeBufferOP_N(G3OP_TEXIMAGE_PARAM, &texImageParam, 1);
    texPlttBase = (u32)base >> 1;
    NNS_G3dGeBufferOP_N(G3OP_TEXPLTT_BASE, &texPlttBase, 1);
    polygonAttr = 0x1F00C1;
    NNS_G3dGeBufferOP_N(G3OP_POLYGON_ATTR, &polygonAttr, 1);
    WobbuffetPopBalloon_DrawMesh(balloon);
    restore = 1;
    NNS_G3dGeBufferOP_N(G3OP_MTX_POP, &restore, 1);
    NNS_G3dGeFlushBuffer();
}

static void WobbuffetPopBalloon_LoadTexture(WobbuffetPopBalloon *balloon) {
    NNSG3dResTex *texture;
    u32 paletteSize;
    u32 paletteOffset;
    u32 paletteAddr;

    balloon->textureFile = AllocAndReadWholeNarcMemberByIdPair(NARC_a_1_9_9, 29, HEAP_ID_117);
    balloon->texture = NNS_G3dGetTex((NNSG3dResFileHeader *)balloon->textureFile);
    GF3dRender_AllocAndLoadTexResources(balloon->texture);
    texture = balloon->texture;
    paletteSize = texture->plttInfo.sizePltt << 3;
    paletteOffset = texture->plttInfo.ofsPlttData;
    paletteAddr = (texture->plttInfo.vramKey & 0xFFFF) << 3;
    GF_ASSERT(balloon->paletteSrc == NULL);
    balloon->paletteSrc = Heap_Alloc(HEAP_ID_117, paletteSize);
    balloon->paletteDest = Heap_Alloc(HEAP_ID_117, paletteSize);
    MI_CpuCopy8((u8 *)texture + paletteOffset, balloon->paletteSrc, paletteSize);
    MI_CpuCopy8((u8 *)texture + paletteOffset, balloon->paletteDest, paletteSize);
    DC_FlushRange(balloon->paletteDest, paletteSize);
    balloon->paletteAddr = paletteAddr;
    balloon->paletteSize = paletteSize;
    GF_ASSERT(balloon->texture->texInfo.ofsTex != 0);
    Heap_Realloc(balloon->textureFile, (u8 *)balloon->texture + balloon->texture->texInfo.ofsTex - (u8 *)balloon->textureFile);
}

static void WobbuffetPopBalloon_LoadPalette(WobbuffetPopBalloon *balloon) {
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(balloon->paletteDest, balloon->paletteAddr, balloon->paletteSize);
    GX_EndLoadTexPltt();
}

static void WobbuffetPopBalloon_BlendPalette(WobbuffetPopBalloon *balloon, s32 air) {
    s32 fraction;

    fraction = (air * 3 << 10) / 800;
    fraction = (fraction + 0x80) >> 8;
    if (fraction > 16) {
        fraction = 16;
    }
    BlendPalette(balloon->paletteSrc, balloon->paletteDest, (u16)(balloon->paletteSize >> 1), fraction, RGB(31, 0, 0));
    DC_FlushRange(balloon->paletteDest, balloon->paletteSize);
    balloon->paletteDirty = TRUE;
}

static BOOL WobbuffetPopBalloon_AddAir(WobbuffetPopBalloon *balloon, s32 air) {
    BOOL full = FALSE;

    balloon->air += air;
    if (balloon->air >= 800) {
        balloon->air = 800;
        full = TRUE;
    }
    WobbuffetPopBalloon_BlendPalette(balloon, balloon->air);
    return full;
}

static void WobbuffetPopBalloon_ResetAir(WobbuffetPopBalloon *balloon) {
    balloon->air = 0;
    WobbuffetPopBalloon_BlendPalette(balloon, balloon->air);
}

static void WobbuffetPopBalloon_UpdateFlash(WobbuffetPopBalloon *balloon) {
    if (balloon->squash != 0) {
        balloon->flashCounter++;
        if (balloon->flashCounter == 4) {
            WobbuffetPopBalloon_BlendPalette(balloon, balloon->air / 2);
            return;
        }
        if (balloon->flashCounter == 8) {
            WobbuffetPopBalloon_BlendPalette(balloon, balloon->air);
            balloon->flashCounter = 0;
        }
    }
}

static void WobbuffetPopBalloon_SetMaterial(u32 diffuseIsVertexColor, u32 useShininess) {
    u32 diffAmb;
    u32 specEmi;

    diffAmb = GX_PACK_DIFFAMB_PARAM(GX_RGB(23, 23, 23), GX_RGB(8, 8, 8), 0) | ((diffuseIsVertexColor != 0 ? 1 : 0) << 15);
    NNS_G3dGeBufferOP_N(G3OP_DIF_AMB, &diffAmb, 1);
    specEmi = GX_RGB(31, 31, 31) | ((useShininess != 0 ? 1 : 0) << 15);
    NNS_G3dGeBufferOP_N(G3OP_SPE_EMI, &specEmi, 1);
}
