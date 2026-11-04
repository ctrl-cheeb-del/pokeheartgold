#include "global.h"

#include "constants/dwc_status.h"
#include "comm_state_internal.h"
#include "save_fashion.h"

#include "global_terminal/global_terminal_app_internal.h"
#include "global_terminal/global_terminal_net.h"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0775.h"
#include "msgdata/msg/msg_0778.h"
#include "msgdata/msg/msg_0800.h"

#include "assert.h"
#include "bg_window.h"
#include "comm_state.h"
#include "dwc/dwc_main_internal.h"
#include "dwc/net_common_internal.h"
#include "dwc/stats_upload_internal.h"
#include "filesystem.h"
#include "font.h"
#include "friend_roster.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "launch_application.h"
#include "message_format.h"
#include "msgdata.h"
#include "oam_manager.h"
#include "options.h"
#include "overlay_00_thumb.h"
#include "overlay_manager.h"
#include "palette.h"
#include "player_data.h"
#include "pm_string.h"
#include "render_text.h"
#include "render_window.h"
#include "sav_system_info.h"
#include "screen_fade.h"
#include "string_util.h"
#include "sys_task_api.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"
#include "vram_transfer_manager.h"
#include "wireless_status_icon.h"
#include "yes_no_prompt.h"

// Global Terminal: connects to (and disconnects from) Nintendo Wi-Fi Connection around the VS Recorder

enum GlobalTerminalConnectState {
    GTC_STATE_ASK_CONNECT,
    GTC_STATE_START_CONNECT,
    GTC_STATE_WAIT_CONNECT,
    GTC_STATE_3,
    GTC_STATE_4,
    GTC_STATE_SAVE_PROFILE_ID,
    GTC_STATE_SHOW_ERROR,
    GTC_STATE_WAIT_ERROR_ACK,
    GTC_STATE_EXIT,
    GTC_STATE_EXIT_CONNECTED,
    GTC_STATE_SHOW_SERVER_ERROR,
    GTC_STATE_SERVER_ERROR_DISCONNECT,
    GTC_STATE_WAIT_MESSAGE,
    GTC_STATE_DISCONNECT,
};

enum GlobalTerminalConnectMainState {
    GTC_MAIN_WAIT_FADE_IN,
    GTC_MAIN_RUN,
    GTC_MAIN_WAIT_FADE_OUT,
};

enum GlobalTerminalConnectAskStep {
    GTC_ASK_START,
    GTC_ASK_PRINT_QUESTION,
    GTC_ASK_OPEN_YES_NO,
    GTC_ASK_HANDLE_YES_NO,
    GTC_ASK_CONNECT,
};

enum GlobalTerminalConnectStartStep {
    GTC_START_PRINT_CONNECTING,
    GTC_START_WAIT_MESSAGE,
    GTC_START_CONNECT,
};

enum GlobalTerminalConnectDisconnectStep {
    GTC_DISCONNECT_PRINT_DISCONNECTING,
    GTC_DISCONNECT_DISCONNECT,
    GTC_DISCONNECT_PRINT_DISCONNECTED,
    GTC_DISCONNECT_WAIT,
};

// The GlobalTerminalApp the connect app is started with.
typedef struct GlobalTerminalConnectBgTemplates {
    BgTemplate templates[2];
} GlobalTerminalConnectBgTemplates;

// SysTask data: the BG palette cycles through 21 palettes blended between the 4 base palettes
typedef struct GlobalTerminalConnectPaletteCycle {
    SysTask *task;
    u32 enabled;
    u16 basePalettes[4][16];
    u16 palettes[21][16];
    s16 index;
    s8 direction;
    u8 frame;
    u32 screens; // 0 = both, 1 = main, 2 = sub
} GlobalTerminalConnectPaletteCycle;

typedef struct GlobalTerminalConnectWork {
    GlobalTerminalApp *app;
    BgConfig *bgConfig;
    u32 state;
    u32 nextState;
    s32 serverError;
    s32 dwcResult;
    s32 errorCode;
    s32 errorType;
    MessageFormat *msgFormat;
    MsgData *msgDataGts;
    MsgData *msgDataConnecting;
    MsgData *msgDataWifi;
    u8 unk_30[4];
    String *string;
    String *title;
    String *errorString;
    u32 printerId;
    Window messageWindow;
    Window titleWindow;
    Window errorWindow;
    u8 unk_74[0x84 - 0x74];
    YesNoPrompt *yesNoPrompt;
    WaitingIcon *waitingIcon;
    u32 unk_8C;
    u32 textSpeed;
    u32 substate;
    s32 timer;
    u32 unk_9C;
    u8 unk_A0[8];
    GlobalTerminalConnectPaletteCycle paletteCycle;
} GlobalTerminalConnectWork;

void GF_TouchpadResetSampling(void);
void GF_TouchpadStartSampling(int frequency);
void GF_TouchpadStopSampling(void);

// What GlobalTerminalConnect_StateWaitConnect reads back from the connection.
typedef struct GlobalTerminalConnectInetResult {
    int lastError;
    int errorType;
    int errorCode;
    NetApInfo apInfo;
} GlobalTerminalConnectInetResult;

extern const GlobalTerminalConnectBgTemplates sGlobalTerminalConnectSubBgTemplates;

static void GlobalTerminalConnect_VBlankCB(GlobalTerminalConnectWork *work);
static void GlobalTerminalConnect_InitBgs(BgConfig *bgConfig);
static void GlobalTerminalConnect_FreeBgs(BgConfig *bgConfig);
static void GlobalTerminalConnect_LoadGraphics(GlobalTerminalConnectWork *work);
static void GlobalTerminalConnect_PaletteCycleTask(SysTask *task, GlobalTerminalConnectPaletteCycle *cycle);
static void GlobalTerminalConnect_CreateWindows(GlobalTerminalConnectWork *work);
static void GlobalTerminalConnect_RemoveWindows(GlobalTerminalConnectWork *work);
static int GlobalTerminalConnect_GetAlignedX(Window *window, String *string, int x, int alignment, int unused, int fontId);
static void GlobalTerminalConnect_PrintAligned(Window *window, String *string, int x, int y, int alignment, u32 color);
static void GlobalTerminalConnect_ShowErrorWindow(GlobalTerminalConnectWork *work, int msgId);
static void GlobalTerminalConnect_ShowErrorCode(GlobalTerminalConnectWork *work, int msgId, int errorNumber);
static BOOL GlobalTerminalConnect_IsPrinting(u32 printerId);
static void GlobalTerminalConnect_ShowWaitingIcon(GlobalTerminalConnectWork *work);
static void GlobalTerminalConnect_HideWaitingIcon(GlobalTerminalConnectWork *work);
static YesNoPrompt *GlobalTerminalConnect_CreateYesNoPrompt(BgConfig *bgConfig, int tileStart);
static void GlobalTerminalConnect_PrintMessage(GlobalTerminalConnectWork *work, MsgData *msgData, int msgId, int textSpeed, u32 color);
static void GlobalTerminalConnect_SetStateAndNext(GlobalTerminalConnectWork *work, u32 state, u32 nextState);
static BOOL GlobalTerminalConnect_ErrorAllowsRetry(int errorCode, int errorType);
static BOOL GlobalTerminalConnect_StateAskConnect(GlobalTerminalConnectWork *work);
static BOOL GlobalTerminalConnect_StateStartConnect(GlobalTerminalConnectWork *work);
static BOOL GlobalTerminalConnect_StateWaitConnect(GlobalTerminalConnectWork *work);
static BOOL GlobalTerminalConnect_StateStartAuth(GlobalTerminalConnectWork *work);
static BOOL GlobalTerminalConnect_StateWaitAuth(GlobalTerminalConnectWork *work);
static BOOL GlobalTerminalConnect_StateSaveProfileId(GlobalTerminalConnectWork *work);
static BOOL GlobalTerminalConnect_StateShowError(GlobalTerminalConnectWork *work);
static BOOL GlobalTerminalConnect_StateWaitErrorAck(GlobalTerminalConnectWork *work);
static BOOL GlobalTerminalConnect_StateExit(GlobalTerminalConnectWork *work);
static BOOL GlobalTerminalConnect_StateShowServerError(GlobalTerminalConnectWork *work);
static BOOL GlobalTerminalConnect_StateServerErrorDisconnect(GlobalTerminalConnectWork *work);
static BOOL GlobalTerminalConnect_StateWaitMessage(GlobalTerminalConnectWork *work);
static BOOL GlobalTerminalConnect_StateDisconnect(GlobalTerminalConnectWork *work);

static BOOL (*sGlobalTerminalConnectStates[14])(GlobalTerminalConnectWork *) = {
    GlobalTerminalConnect_StateAskConnect,
    GlobalTerminalConnect_StateStartConnect,
    GlobalTerminalConnect_StateWaitConnect,
    GlobalTerminalConnect_StateStartAuth,
    GlobalTerminalConnect_StateWaitAuth,
    GlobalTerminalConnect_StateSaveProfileId,
    GlobalTerminalConnect_StateShowError,
    GlobalTerminalConnect_StateWaitErrorAck,
    GlobalTerminalConnect_StateExit,
    GlobalTerminalConnect_StateExit,
    GlobalTerminalConnect_StateShowServerError,
    GlobalTerminalConnect_StateServerErrorDisconnect,
    GlobalTerminalConnect_StateWaitMessage,
    GlobalTerminalConnect_StateDisconnect,
};

static const GraphicsModes sGlobalTerminalConnectGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_2D,
};

static const GraphicsBanks sGlobalTerminalConnectGraphicsBanks = {
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

static const GlobalTerminalConnectBgTemplates sGlobalTerminalConnectMainBgTemplates = {
    .templates = {
        {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xf800,
            .charBase = GX_BG_CHARBASE_0x00000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
        {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xf000,
            .charBase = GX_BG_CHARBASE_0x08000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
    },
};

BOOL GlobalTerminalConnect_Init(OverlayManager *manager, int *state) {
    GlobalTerminalConnectWork *work;

    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    GX_SetVisiblePlane(GX_PLANEMASK_NONE);
    GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
    GX_SetVisibleWnd(GX_WNDMASK_NONE);
    GXS_SetVisibleWnd(GX_WNDMASK_NONE);
    G2_BlendNone();
    G2S_BlendNone();
    Heap_Create(HEAP_ID_3, HEAP_ID_124, 0x50000);
    work = OverlayManager_CreateAndGetData(manager, sizeof(GlobalTerminalConnectWork), HEAP_ID_124);
    MI_CpuFill8(work, 0, sizeof(GlobalTerminalConnectWork));
    work->app = OverlayManager_GetArgs(manager);
    work->bgConfig = BgConfig_Alloc(HEAP_ID_124);
    GF_CreateVramTransferManager(64, HEAP_ID_124);
    SetKeyRepeatTimers(4, 8);
    GlobalTerminalConnect_InitBgs(work->bgConfig);
    GF_TouchpadResetSampling();
    GF_TouchpadStartSampling(4);
    {
        MessageFormat *msgFormat = MessageFormat_New_Custom(11, 64, HEAP_ID_124);
        work->msgFormat = msgFormat;
    }
    work->msgDataGts = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0775_bin, HEAP_ID_124);
    work->msgDataConnecting = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0778_bin, HEAP_ID_124);
    work->msgDataWifi = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0800_bin, HEAP_ID_124);
    work->string = String_New(180, HEAP_ID_124);
    work->errorString = String_New(256, HEAP_ID_124);
    work->title = NewString_ReadMsgData(work->msgDataGts, msg_0775_00031);
    GlobalTerminalConnect_LoadGraphics(work);
    GlobalTerminalConnect_CreateWindows(work);
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_124);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_ON);
    gSystem.screensFlipped = 1;
    GfGfx_SwapDisplay();
    TextFlags_SetCanABSpeedUpPrint(TRUE);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(TRUE);
    Main_SetVBlankIntrCB((GFIntrCB)GlobalTerminalConnect_VBlankCB, work);
    if (work->app->disconnect) {
        WirelessStatusIcon_Create();
        GlobalTerminalConnect_SetStateAndNext(work, GTC_STATE_DISCONNECT, GTC_STATE_EXIT);
    } else {
        if (work->app->args->connectDirectly != 0) {
            work->state = GTC_STATE_START_CONNECT;
        } else {
            work->state = GTC_STATE_ASK_CONNECT;
        }
    }
    work->textSpeed = Options_GetTextFrameDelay(Save_PlayerData_GetOptionsAddr(work->app->args->saveData));
    work->app->isConnected = FALSE;
    return TRUE;
}

BOOL GlobalTerminalConnect_Main(OverlayManager *manager, int *state) {
    GlobalTerminalConnectWork *work = OverlayManager_GetData(manager);
    BOOL result;
    u32 oldState;

    switch (*state) {
    case GTC_MAIN_WAIT_FADE_IN:
        if (IsPaletteFadeFinished() == TRUE) {
            *state = GTC_MAIN_RUN;
        }
        break;
    case GTC_MAIN_RUN:
        oldState = work->state;
        result = sGlobalTerminalConnectStates[oldState](work);
        if (oldState != work->state) {
            work->substate = 0;
            work->unk_9C = 0;
            work->timer = 0;
        }
        if (result == TRUE) {
            *state = GTC_MAIN_WAIT_FADE_OUT;
        }
        break;
    case GTC_MAIN_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL GlobalTerminalConnect_Exit(OverlayManager *manager, int *state) {
    GlobalTerminalConnectWork *work = OverlayManager_GetData(manager);

    if (work->paletteCycle.task != NULL) {
        SysTask_Destroy(work->paletteCycle.task);
        work->paletteCycle.task = NULL;
        work->paletteCycle.enabled = 0;
    }
    DestroyMsgData(work->msgDataWifi);
    DestroyMsgData(work->msgDataConnecting);
    DestroyMsgData(work->msgDataGts);
    MessageFormat_Delete(work->msgFormat);
    String_Delete(work->title);
    String_Delete(work->errorString);
    String_Delete(work->string);
    GlobalTerminalConnect_RemoveWindows(work);
    Heap_Free(work->bgConfig);
    GlobalTerminalConnect_FreeBgs(work->bgConfig);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GF_DestroyVramTransferManager();
    GF_TouchpadStopSampling();
    TextFlags_SetCanABSpeedUpPrint(FALSE);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    WirelessStatusIcon_Destroy();
    OverlayManager_FreeData(manager);
    Heap_Destroy(HEAP_ID_124);
    gSystem.screensFlipped = 0;
    GfGfx_SwapDisplay();
    return TRUE;
}

static void GlobalTerminalConnect_VBlankCB(GlobalTerminalConnectWork *work) {
    vu32 *dtcm = (vu32 *)0x027E0000; // OS_SetIrqCheckFlag, with the DTCM address as a constant

    GF_RunVramTransferTasks();
    OamManager_ApplyAndResetBuffers();
    DoScheduledBgGpuUpdates(work->bgConfig);
    dtcm[0x3FF8 / sizeof(u32)] |= OS_IE_V_BLANK;
}

static void GlobalTerminalConnect_InitBgs(BgConfig *bgConfig) {
    GraphicsBanks banks;
    GraphicsModes modes;
    GlobalTerminalConnectBgTemplates mainTemplates;
    GlobalTerminalConnectBgTemplates subTemplates;

    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    banks = sGlobalTerminalConnectGraphicsBanks;
    GfGfx_SetBanks(&banks);
    MI_CpuClear32((void *)HW_BG_VRAM, HW_BG_VRAM_SIZE);
    MI_CpuClear32((void *)HW_DB_BG_VRAM, HW_DB_BG_VRAM_SIZE);
    MI_CpuClear32((void *)HW_OBJ_VRAM, HW_OBJ_VRAM_SIZE);
    MI_CpuClear32((void *)HW_DB_OBJ_VRAM, HW_DB_OBJ_VRAM_SIZE);
    modes = sGlobalTerminalConnectGraphicsModes;
    SetBothScreensModesAndDisable(&modes);
    mainTemplates = sGlobalTerminalConnectMainBgTemplates;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &mainTemplates.templates[0], GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_Y, 0);
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &mainTemplates.templates[1], GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_Y, 0);
    subTemplates = sGlobalTerminalConnectSubBgTemplates;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &subTemplates.templates[0], GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_SUB_0, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_SUB_0, BG_POS_OP_SET_Y, 0);
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &subTemplates.templates[1], GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_Y, 0);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 0x20, 0, HEAP_ID_124);
    BG_ClearCharDataRange(GF_BG_LYR_SUB_0, 0x20, 0, HEAP_ID_124);
}

static void GlobalTerminalConnect_FreeBgs(BgConfig *bgConfig) {
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_0);
}

static void GlobalTerminalConnect_LoadGraphics(GlobalTerminalConnectWork *work) {
    NNSG2dPaletteData *plttData;
    u8 *colors;
    volatile int coefficient;
    NARC *narc;
    void *raw;
    BgConfig *bgConfig = work->bgConfig;
    int outer;
    int palette;

    narc = NARC_New(NARC_a_0_8_8, HEAP_ID_124);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 3, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0, HEAP_ID_124);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 3, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, HEAP_ID_124);
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_13_OFFSET, HEAP_ID_124);
    LoadFontPal1(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_13_OFFSET, HEAP_ID_124);
    LoadUserFrameGfx2(bgConfig, GF_BG_LYR_MAIN_0, 1, 10, Options_GetFrame(Save_PlayerData_GetOptionsAddr(work->app->args->saveData)), HEAP_ID_124);
    LoadUserFrameGfx1(bgConfig, GF_BG_LYR_MAIN_0, 0x1F, 11, 0, HEAP_ID_124);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 2, bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, HEAP_ID_124);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 6, bgConfig, GF_BG_LYR_MAIN_1, 0, 0x600, FALSE, HEAP_ID_124);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 11, bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_124);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 12, bgConfig, GF_BG_LYR_SUB_1, 0, 0x600, FALSE, HEAP_ID_124);
    BG_SetMaskColor(GF_BG_LYR_MAIN_0, RGB_BLACK);
    BG_SetMaskColor(GF_BG_LYR_SUB_0, RGB_BLACK);
    MI_CpuFill8(&work->paletteCycle, 0, sizeof(GlobalTerminalConnectPaletteCycle));
    raw = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 5, &plttData, HEAP_ID_124);
    // the first 4 palettes of the file are the cycle's base palettes; palette 0 is also the first blended one
    MIi_CpuCopy16(plttData->pRawData, work->paletteCycle.basePalettes[0], 0x80);
    MIi_CpuCopy16(plttData->pRawData, work->paletteCycle.palettes[0], 0x80);
    Heap_Free(raw);
    palette = 0;
    outer = 0;
    {
        // 3 x 7 palettes: base palette n blended towards base palette n+1 in steps of 3/16 (color 0 unchanged)
        int blend;
        int last;
        u8 *dest = (u8 *)work + 0x130;
        u8 *src = (u8 *)work + 0xB0;
        while (outer < 3) {
            blend = 0;
            last = 0;
            colors = (u8 *)work + (outer + 1) * 0x20;
            do {
                int i;
                u8 *color;
                u8 *dst;
                u8 *source;
                GF_ASSERT(palette < 21);
                color = colors + 2;
                dst = dest + 2;
                source = src + 2;
                coefficient = (u8)(blend >> 8);
                for (i = 1; i < 16; i++) {
                    ((void (*)(const u16 *, u16 *, u16, int, u16))BlendPalette)((u16 *)source, (u16 *)dst, 1, coefficient, *(u16 *)(color + 0xB0));
                    color += 2;
                    dst += 2;
                    source += 2;
                }
                dest += 0x20;
                palette++;
                if (last == 1) {
                    break;
                }
                blend += 0x300;
                if (blend >= 0x1000) {
                    blend = 0x1000;
                    last = 1;
                }
            } while (1);
            src += 0x20;
            outer++;
        }
    }
    DC_FlushRange(work->paletteCycle.palettes, sizeof(work->paletteCycle.palettes));
    work->paletteCycle.enabled = 1;
    work->paletteCycle.screens = 0;
    work->paletteCycle.task = SysTask_CreateOnVBlankQueue((SysTaskFunc)GlobalTerminalConnect_PaletteCycleTask, &work->paletteCycle, 20);
    NARC_Delete(narc);
}

static void GlobalTerminalConnect_PaletteCycleTask(SysTask *task, GlobalTerminalConnectPaletteCycle *cycle) {
    if (cycle->enabled != 0) {
        cycle->frame ^= 1;
        if (!(cycle->frame & 1)) {
            if (cycle->screens <= 1) {
                GX_LoadBGPltt(cycle->palettes[cycle->index], 0, 0x20);
            }
            if (cycle->screens == 0 || cycle->screens == 2) {
                GXS_LoadBGPltt(cycle->palettes[cycle->index], 0, 0x20);
            }
            if (cycle->direction == 0) {
                cycle->index++;
                if (cycle->index >= 21) {
                    cycle->index = 19;
                    cycle->direction ^= 1;
                }
            } else {
                cycle->index--;
                if (cycle->index < 0) {
                    cycle->index = 1;
                    cycle->direction ^= 1;
                }
            }
        }
    }
}

static void GlobalTerminalConnect_CreateWindows(GlobalTerminalConnectWork *work) {
    AddWindowParameterized(work->bgConfig, &work->errorWindow, GF_BG_LYR_MAIN_0, 4, 4, 23, 16, 13, 0x94);
    FillWindowPixelBuffer(&work->errorWindow, 0);
    AddWindowParameterized(work->bgConfig, &work->titleWindow, GF_BG_LYR_MAIN_0, 4, 1, 24, 2, 13, 0x204);
    FillWindowPixelBuffer(&work->titleWindow, 0);
    GlobalTerminalConnect_PrintAligned(&work->titleWindow, work->title, 0, 1, 1, MAKE_TEXT_COLOR(15, 14, 0));
    AddWindowParameterized(work->bgConfig, &work->messageWindow, GF_BG_LYR_MAIN_0, 2, 19, 27, 4, 13, 0x28);
    FillWindowPixelBuffer(&work->messageWindow, 0);
}

static void GlobalTerminalConnect_RemoveWindows(GlobalTerminalConnectWork *work) {
    RemoveWindow(&work->messageWindow);
    RemoveWindow(&work->titleWindow);
    RemoveWindow(&work->errorWindow);
}

// alignment 1 = centred, 2 = right-aligned, otherwise x
static int GlobalTerminalConnect_GetAlignedX(Window *window, String *string, int x, int alignment, int unused, int fontId) {
    switch (alignment) {
    case 1:
        x = ((window->width << 3) - (int)FontID_String_GetWidth(fontId, string, 0)) / 2;
        break;
    case 2:
        x = (window->width << 3) - FontID_String_GetWidth(fontId, string, 0);
        break;
    }
    return x;
}

static void GlobalTerminalConnect_PrintAligned(Window *window, String *string, int x, int y, int alignment, u32 color) {
    x = GlobalTerminalConnect_GetAlignedX(window, string, x, alignment, color, 1);
    AddTextPrinterParameterizedWithColor(window, 1, string, x, y, TEXT_SPEED_INSTANT, color, NULL);
}

static void GlobalTerminalConnect_ShowErrorWindow(GlobalTerminalConnectWork *work, int msgId) {
    String *string = String_New(256, HEAP_ID_124);
    ReadMsgDataIntoString(work->msgDataWifi, msgId, string);
    StringExpandPlaceholders(work->msgFormat, work->errorString, string);
    FillWindowPixelBuffer(&work->errorWindow, 15);
    DrawFrameAndWindow1(&work->errorWindow, TRUE, 0x1F, 11);
    AddTextPrinterParameterized(&work->errorWindow, 1, work->errorString, 0, 0, TEXT_SPEED_INSTANT, NULL);
    work->printerId = 0xFF;
    String_Delete(string);
}

static void GlobalTerminalConnect_ShowErrorCode(GlobalTerminalConnectWork *work, int msgId, int errorNumber) {
    if (msgId == -1) {
        msgId = 11;
    }
    BufferIntegerAsString(work->msgFormat, 0, errorNumber, 5, PRINTING_MODE_LEADING_ZEROS, TRUE);
    ClearFrameAndWindow2(&work->messageWindow, TRUE);
    GlobalTerminalConnect_ShowErrorWindow(work, msgId);
}

static BOOL GlobalTerminalConnect_IsPrinting(u32 printerId) {
    if (printerId == 0xFF || !TextPrinterCheckActive(printerId)) {
        return FALSE;
    }
    return TRUE;
}

static void GlobalTerminalConnect_ShowWaitingIcon(GlobalTerminalConnectWork *work) {
    if (work->waitingIcon == NULL) {
        work->waitingIcon = WaitingIcon_New(&work->messageWindow, 1);
    }
}

static void GlobalTerminalConnect_HideWaitingIcon(GlobalTerminalConnectWork *work) {
    if (work->waitingIcon != NULL) {
        WaitingIcon_Delete(work->waitingIcon);
        work->waitingIcon = NULL;
    }
}

static YesNoPrompt *GlobalTerminalConnect_CreateYesNoPrompt(BgConfig *bgConfig, int tileStart) {
    YesNoPromptTemplate template;
    YesNoPrompt *prompt = YesNoPrompt_Create(HEAP_ID_124);

    template.bgConfig = bgConfig;
    template.bgId = GF_BG_LYR_MAIN_0;
    template.tileStart = tileStart;
    template.plttSlot = 14;
    template.x = 25;
    template.y = 10;
    template.ignoreTouchFlag = 0;
    template.initialCursorPos = 0;
    template.shapeParam = 0;
    YesNoPrompt_InitFromTemplate(prompt, &template);
    return prompt;
}

// color is not used: the frame and printer use their defaults
static void GlobalTerminalConnect_PrintMessage(GlobalTerminalConnectWork *work, MsgData *msgData, int msgId, int textSpeed, u32 color) {
    String *string = NewString_ReadMsgData(msgData, msgId);
    StringExpandPlaceholders(work->msgFormat, work->string, string);
    String_Delete(string);
    FillWindowPixelBuffer(&work->messageWindow, 15);
    DrawFrameAndWindow2(&work->messageWindow, FALSE, 1, 10);
    work->printerId = AddTextPrinterParameterized(&work->messageWindow, 1, work->string, 0, 0, textSpeed, NULL);
    work->unk_8C = 0;
    if (textSpeed == TEXT_SPEED_NOTRANSFER || textSpeed == TEXT_SPEED_INSTANT) {
        work->printerId = 0xFF;
    }
}

static void GlobalTerminalConnect_SetStateAndNext(GlobalTerminalConnectWork *work, u32 state, u32 nextState) {
    work->state = state;
    work->nextState = nextState;
}

static BOOL GlobalTerminalConnect_ErrorAllowsRetry(int errorCode, int errorType) {
    switch (WifiConnection_ClassifyErrorCode(errorCode, errorType)) {
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        return TRUE;
    case 0:
    case 2:
    case 3:
    default:
        return FALSE;
    }
}

static BOOL GlobalTerminalConnect_StateAskConnect(GlobalTerminalConnectWork *work) {
    YesNoResponse result;

    if (GlobalTerminalConnect_IsPrinting(work->printerId) == TRUE) {
        return FALSE;
    }
    switch (work->substate) {
    case GTC_ASK_START:
        work->substate++;
        break;
    case GTC_ASK_PRINT_QUESTION:
        GlobalTerminalConnect_PrintMessage(work, work->msgDataWifi, msg_0800_00017, work->textSpeed, MAKE_TEXT_COLOR(0, 15, 15));
        work->substate++;
        break;
    case GTC_ASK_OPEN_YES_NO:
        work->yesNoPrompt = GlobalTerminalConnect_CreateYesNoPrompt(work->bgConfig, 0x234);
        work->substate++;
        break;
    case GTC_ASK_HANDLE_YES_NO:
        result = YesNoPrompt_HandleInput(work->yesNoPrompt);
        if (result == YESNORESPONSE_YES) {
            YesNoPrompt_Destroy(work->yesNoPrompt);
            work->substate++;
        } else if (result == YESNORESPONSE_NO) {
            YesNoPrompt_Destroy(work->yesNoPrompt);
            work->state = GTC_STATE_EXIT;
        }
        break;
    case GTC_ASK_CONNECT:
        work->state = GTC_STATE_START_CONNECT;
        break;
    }
    return FALSE;
}

static BOOL GlobalTerminalConnect_StateStartConnect(GlobalTerminalConnectWork *work) {
    switch (work->substate) {
    case GTC_START_PRINT_CONNECTING:
        CommState_InitWfcSession(work->app->args->saveData);
        Sys_SetSleepDisableFlag(4);
        WirelessStatusIcon_Create();
        GlobalTerminalConnect_PrintMessage(work, work->msgDataConnecting, msg_0778_00001, work->textSpeed, MAKE_TEXT_COLOR(0, 15, 15));
        GlobalTerminalConnect_ShowWaitingIcon(work);
        work->substate++;
        break;
    case GTC_START_WAIT_MESSAGE:
        if (!GlobalTerminalConnect_IsPrinting(work->printerId)) {
            work->substate++;
        }
        break;
    case GTC_START_CONNECT:
        DWC_InitInetEx(&work->app->wifiConnection, 2, 1, 20);
        DWC_SetAuthServer(2);
        DWC_ConnectInetAsync();
        work->state = GTC_STATE_WAIT_CONNECT;
        break;
    }
    return FALSE;
}

static BOOL GlobalTerminalConnect_StateWaitConnect(GlobalTerminalConnectWork *work) {
    GlobalTerminalConnectInetResult result;

    DWC_ProcessInet();
    if (DWC_CheckInet()) {
        switch (DWC_GetInetStatus()) {
        case DWC_CONNECTINET_STATE_ERROR:
            work->dwcResult = DWC_GetLastErrorEx(&result.errorCode, &result.errorType);
            work->errorCode = result.errorCode;
            work->errorType = result.errorType;
            DWC_ClearError();
            DWC_CleanupInet();
            GlobalTerminalConnect_HideWaitingIcon(work);
            work->state = GTC_STATE_SHOW_ERROR;
            break;
        case DWC_CONNECTINET_STATE_NOT_INITIALIZED:
        case DWC_CONNECTINET_STATE_IDLE:
        case DWC_CONNECTINET_STATE_OPERATING:
        case DWC_CONNECTINET_STATE_OPERATED:
        case DWC_CONNECTINET_STATE_DISCONNECTING:
        case DWC_CONNECTINET_STATE_DISCONNECTED:
        case DWC_CONNECTINET_STATE_FATAL_ERROR:
        default:
            DWC_GetLastError(&result.lastError);
            GlobalTerminalConnect_HideWaitingIcon(work);
            work->state = GTC_STATE_SHOW_SERVER_ERROR;
            work->serverError = -2;
            break;
        case DWC_CONNECTINET_STATE_CONNECTED:
            DWC_GetApInfo(&result.apInfo);
            work->state = GTC_STATE_3;
            break;
        }
    }
    return FALSE;
}

static BOOL GlobalTerminalConnect_StateStartAuth(GlobalTerminalConnectWork *work) {
    DWC_NASLoginAsync();
    work->state = GTC_STATE_4;
    return FALSE;
}

static BOOL GlobalTerminalConnect_StateWaitAuth(GlobalTerminalConnectWork *work) {
    int errorCode;
    int errorType;

    switch (DWC_NASLoginProcess()) {
    case DWC_NASLOGIN_STATE_SUCCESS:
        work->state = GTC_STATE_SAVE_PROFILE_ID;
        break;
    case DWC_NASLOGIN_STATE_DIRTY:
    case DWC_NASLOGIN_STATE_ERROR:
    case DWC_NASLOGIN_STATE_CANCELED:
        GlobalTerminalConnect_HideWaitingIcon(work);
        work->dwcResult = DWC_GetLastErrorEx(&errorCode, &errorType);
        work->errorCode = errorCode;
        work->errorType = errorType;
        DWC_ClearError();
        DWC_CleanupInet();
        work->state = GTC_STATE_SHOW_ERROR;
        switch (errorType) {
        case DWC_ETYPE_LIGHT:
        case DWC_ETYPE_SHOW_ERROR:
            work->state = GTC_STATE_SHOW_ERROR;
            break;
        case DWC_ETYPE_SHUTDOWN_GHTTP:
            DWC_ShutdownGHTTP();
            work->state = GTC_STATE_SHOW_ERROR;
            break;
        case DWC_ETYPE_DISCONNECT:
            work->state = GTC_STATE_SHOW_ERROR;
            break;
        case DWC_ETYPE_SHUTDOWN_FM:
            DWC_ShutdownFriendsMatch();
            work->state = GTC_STATE_SHOW_ERROR;
            break;
        case DWC_ETYPE_SHUTDOWN_ND:
        case DWC_ETYPE_FATAL:
            CommState_ShowRestartErrorAndHalt();
            break;
        }
        if (errorCode < -20000 && errorCode >= -29999) {
            work->state = GTC_STATE_SHOW_ERROR;
        }
        break;
    }
    return FALSE;
}

static BOOL GlobalTerminalConnect_StateSaveProfileId(GlobalTerminalConnectWork *work) {
    FriendRoster *wifiList = Save_FriendRoster_Get(work->app->args->saveData);
    SysInfo *sysInfo = Save_SysInfo_Get(work->app->args->saveData);

    FriendRoster_GetUserData(wifiList);
    if (Save_SysInfo_GetDwcProfileId(sysInfo) == 0) {
        Save_SysInfo_SetDwcProfileId(sysInfo, Comm_GetOwnGsProfileId(wifiList));
    }
    Save_SysInfo_GetDwcProfileId(sysInfo);
    work->state = GTC_STATE_EXIT_CONNECTED;
    work->app->isConnected = TRUE;
    return FALSE;
}

static BOOL GlobalTerminalConnect_StateShowError(GlobalTerminalConnectWork *work) {
    int msgId = WifiConnection_ClassifyErrorCode(-work->errorCode, work->errorType);
    GlobalTerminalConnect_ShowErrorCode(work, msgId, -work->errorCode);
    work->state = GTC_STATE_WAIT_ERROR_ACK;
    return FALSE;
}

static BOOL GlobalTerminalConnect_StateWaitErrorAck(GlobalTerminalConnectWork *work) {
    if ((gSystem.newKeys & PAD_BUTTON_A) || (gSystem.newKeys & PAD_BUTTON_B) || System_GetTouchNew() == TRUE) {
        EraseFrameAndWindow1(&work->errorWindow, FALSE);
        work->substate = 0;
        if (GlobalTerminalConnect_ErrorAllowsRetry(-work->errorCode, work->errorType) == TRUE) {
            work->state = GTC_STATE_ASK_CONNECT;
        } else {
            work->state = GTC_STATE_EXIT;
        }
    }
    return FALSE;
}

static BOOL GlobalTerminalConnect_StateExit(GlobalTerminalConnectWork *work) {
    if (work->state != GTC_STATE_EXIT_CONNECTED) {
        CommState_FreeWfcSession();
    }
    WirelessStatusIcon_Destroy();
    GlobalTerminalConnect_HideWaitingIcon(work);
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_124);
    work->state = GTC_STATE_ASK_CONNECT;
    return TRUE;
}

static BOOL GlobalTerminalConnect_StateShowServerError(GlobalTerminalConnectWork *work) {
    int msgId = 0;

    switch (work->serverError + 15) {
    case 16:
        msgId = msg_0775_00150;
        break;
    case 14:
    case 17:
        msgId = msg_0775_00151;
        break;
    case 1:
    case 13:
        msgId = msg_0775_00156;
        break;
    case 0:
    case 3:
    case 10:
    case 12:
        msgId = msg_0775_00155;
        break;
    }
    GlobalTerminalConnect_PrintMessage(work, work->msgDataGts, msgId, work->textSpeed, MAKE_TEXT_COLOR(0, 15, 15));
    GlobalTerminalConnect_SetStateAndNext(work, GTC_STATE_WAIT_MESSAGE, GTC_STATE_SERVER_ERROR_DISCONNECT);
    return FALSE;
}

static BOOL GlobalTerminalConnect_StateServerErrorDisconnect(GlobalTerminalConnectWork *work) {
    switch (work->substate) {
    case GTC_DISCONNECT_PRINT_DISCONNECTING:
        GlobalTerminalConnect_PrintMessage(work, work->msgDataGts, msg_0775_00186, work->textSpeed, MAKE_TEXT_COLOR(0, 15, 15));
        work->substate++;
        break;
    case GTC_DISCONNECT_DISCONNECT:
        if (!GlobalTerminalConnect_IsPrinting(work->printerId)) {
            CommState_FreeWfcSession();
            DWC_CleanupInet();
            work->substate++;
        }
        break;
    case GTC_DISCONNECT_PRINT_DISCONNECTED:
        GlobalTerminalConnect_PrintMessage(work, work->msgDataGts, msg_0775_00187, work->textSpeed, MAKE_TEXT_COLOR(0, 15, 15));
        work->substate++;
        break;
    case GTC_DISCONNECT_WAIT:
        if (!GlobalTerminalConnect_IsPrinting(work->printerId)) {
            work->substate++;
        }
        break;
    default:
        work->timer++;
        if (work->timer > 30) {
            work->state = GTC_STATE_EXIT;
        }
        break;
    }
    return FALSE;
}

static BOOL GlobalTerminalConnect_StateWaitMessage(GlobalTerminalConnectWork *work) {
    if (!GlobalTerminalConnect_IsPrinting(work->printerId)) {
        work->state = work->nextState;
    }
    return FALSE;
}

static BOOL GlobalTerminalConnect_StateDisconnect(GlobalTerminalConnectWork *work) {
    if (GlobalTerminalConnect_IsPrinting(work->printerId) == TRUE) {
        return FALSE;
    }
    switch (work->substate) {
    case GTC_DISCONNECT_PRINT_DISCONNECTING:
        GlobalTerminalConnect_PrintMessage(work, work->msgDataWifi, msg_0800_00026, work->textSpeed, MAKE_TEXT_COLOR(0, 15, 15));
        work->substate++;
        break;
    case GTC_DISCONNECT_DISCONNECT:
        DWC_CleanupInet();
        CommState_FreeWfcSession();
        work->substate++;
        break;
    case GTC_DISCONNECT_PRINT_DISCONNECTED:
        WirelessStatusIcon_Destroy();
        GlobalTerminalConnect_PrintMessage(work, work->msgDataWifi, msg_0800_00027, work->textSpeed, MAKE_TEXT_COLOR(0, 15, 15));
        work->substate++;
        break;
    case GTC_DISCONNECT_WAIT:
        work->timer++;
        if (work->timer > 30) {
            work->state = work->nextState;
        }
        break;
    }
    return FALSE;
}

void GlobalTerminalNet_DressUpToUploadForm(const SaveFashionDataSub *src, GlobalTerminalNetDressUpForm *dst) {
    int i;

    MI_CpuFill8(dst, 0, sizeof(GlobalTerminalNetDressUpForm));
    dst->magic = src->magic;
    dst->personality = src->personality;
    dst->otId = src->otId;
    dst->species = src->species;
    for (i = 0; i < 8; i++) {
        dst->secondText[i] = src->secondText[i];
    }
    dst->z = src->z;
    dst->x = src->x;
    dst->y = src->y;
    dst->form = src->form;
    dst->itemMask = src->itemMask;
    dst->mailMsgBank = src->mailMessage.msg_bank;
    dst->mailMsgNo = src->mailMessage.msg_no;
    dst->mailField0 = src->mailMessage.fields[0];
    dst->mailField1 = src->mailMessage.fields[1];
    {
        const u8 *item = src->items[0];
        for (i = 0; i < 10; i++) {
            dst->items[i][0] = item[0];
            dst->items[i][1] = item[1];
            dst->items[i][2] = item[2];
            dst->items[i][3] = item[3];
            item += 4;
        }
    }
    dst->backdrop = src->backdrop;
    dst->language = src->language;
}

void GlobalTerminalNet_UploadFormToDressUp(const GlobalTerminalNetDressUpForm *src, SaveFashionDataSub *dst) {
    int i;

    MI_CpuFill8(dst, 0, FashionEntry_sizeof());
    dst->magic = src->magic;
    dst->personality = src->personality;
    dst->otId = src->otId;
    dst->species = src->species;
    for (i = 0; i < 8; i++) {
        dst->secondText[i] = src->secondText[i];
    }
    dst->z = src->z;
    dst->x = src->x;
    dst->y = src->y;
    dst->form = src->form;
    dst->itemMask = src->itemMask;
    dst->mailMessage.msg_bank = src->mailMsgBank;
    dst->mailMessage.msg_no = src->mailMsgNo;
    dst->mailMessage.fields[0] = src->mailField0;
    dst->mailMessage.fields[1] = src->mailField1;
    {
        const u8 *item = src->items[0];
        for (i = 0; i < 10; i++) {
            dst->items[i][0] = item[0];
            dst->items[i][1] = item[1];
            dst->items[i][2] = item[2];
            dst->items[i][3] = item[3];
            item += 4;
        }
    }
    dst->backdrop = src->backdrop;
    dst->language = src->language;
    for (i = 0; i < 11; i++) {
        dst->nickname[i] = EOS;
    }
    dst->secondTextGender = 0;
}
