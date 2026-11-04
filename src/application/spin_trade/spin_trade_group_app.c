#include "global.h"

#include "constants/game_stats.h"
#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0207.h"

#include "bg_window.h"
#include "comm_state.h"
#include "comm_state_internal.h"
#include "communication_core.h"
#include "communication_player_state.h"
#include "filesystem.h"
#include "font.h"
#include "game_stats.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "link_synchronization.h"
#include "list_menu_2d.h"
#include "math_util.h"
#include "message_format.h"
#include "msgdata.h"
#include "oam_manager.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "options.h"
#include "overlay_manager.h"
#include "player_data.h"
#include "screen_fade_legacy.h"
#include "sound_playback.h"
#include "sound_system.h"
#include "spin_trade_link.h"
#include "sprite.h"
#include "sprite_resource.h"
#include "sprite_resource_header.h"
#include "sprite_transfer.h"
#include "sys_task_api.h"
#include "system.h"
#include "text.h"
#include "union_room_avatar.h"
#include "union_room_talk.h"
#include "vram_transfer_manager.h"
#include "wireless_manager.h"
#include "wireless_status_icon.h"

enum SpinTradeGroupState {
    SPIN_TRADE_GROUP_STATE_SHOW_PROMPT,
    SPIN_TRADE_GROUP_STATE_WAIT_TEXT_THEN_RESET_MENU,
    SPIN_TRADE_GROUP_STATE_RESET_LEADER_MENU_STATE,
    SPIN_TRADE_GROUP_STATE_HANDLE_INPUT,
    SPIN_TRADE_GROUP_STATE_SHOW_CANCEL_YES_NO,
    SPIN_TRADE_GROUP_STATE_HANDLE_CANCEL_YES_NO,
    SPIN_TRADE_GROUP_STATE_RESET_LEAVE_WAIT,
    SPIN_TRADE_GROUP_STATE_SEND_LEAVE,
    SPIN_TRADE_GROUP_STATE_ABORT_LEAVE,
    SPIN_TRADE_GROUP_STATE_SHOW_CANCELED,
    SPIN_TRADE_GROUP_STATE_FADE_OUT_CANCELED,
    SPIN_TRADE_GROUP_STATE_SHOW_DISBAND_YES_NO,
    SPIN_TRADE_GROUP_STATE_HANDLE_DISBAND_YES_NO,
    SPIN_TRADE_GROUP_STATE_SHOW_DISBANDED,
    SPIN_TRADE_GROUP_STATE_WAIT_BEFORE_EXIT,
    SPIN_TRADE_GROUP_STATE_START_EXIT_SYNC,
    SPIN_TRADE_GROUP_STATE_WAIT_EXIT_SYNC,
    SPIN_TRADE_GROUP_STATE_SHOW_MEMBER_DROPPED,
    SPIN_TRADE_GROUP_STATE_WAIT_MEMBER_DROPPED,
    SPIN_TRADE_GROUP_STATE_SHOW_MEMBER_LEFT,
    SPIN_TRADE_GROUP_STATE_START_MEMBER_LEFT_WAIT,
    SPIN_TRADE_GROUP_STATE_WAIT_MEMBER_LEFT,
    SPIN_TRADE_GROUP_STATE_SHOW_CONFIRM_YES_NO,
    SPIN_TRADE_GROUP_STATE_HANDLE_CONFIRM_YES_NO,
    SPIN_TRADE_GROUP_STATE_SEND_START_SYNC,
    SPIN_TRADE_GROUP_STATE_WAIT_SYNC_COUNT,
    SPIN_TRADE_GROUP_STATE_BEFORE_SAVE,
    SPIN_TRADE_GROUP_STATE_START_SAVE,
    SPIN_TRADE_GROUP_STATE_SAVE,
    SPIN_TRADE_GROUP_STATE_WAIT_AFTER_SAVE,
    SPIN_TRADE_GROUP_STATE_WAIT_PRINTER,
    SPIN_TRADE_GROUP_STATE_PROCEED,
};

// Leader marker palette animation
typedef struct SpinTradeGroupBlink {
    BOOL active;
    int frame;
    int timer;
    void *plttFile;
    NNSG2dPaletteData *pltt;
} SpinTradeGroupBlink;

typedef struct SpinTradeGroupMember {
    PlayerProfile *profile;
    PlayerProfile *prevProfile;
} SpinTradeGroupMember;

typedef union SpinTradeGroupTrainerId {
    u64 raw;
    struct {
        u32 id;
        u32 valid;
    } f;
} SpinTradeGroupTrainerId;

typedef struct SpinTradeGroupTrainerIds {
    SpinTradeGroupTrainerId cur;
    SpinTradeGroupTrainerId prev;
} SpinTradeGroupTrainerIds;

typedef struct SpinTradeGroupPos {
    u16 x;
    u16 y;
} SpinTradeGroupPos;

typedef struct SpinTradeGroupApp {
    int state;
    u8 unk_0004[4];
    u32 result;
    SpinTradeArgs *args;
    SpinTradeLink *menu;
    BgConfig *bgConfig;
    u8 unk_0018[4];
    SpinTradeGroupBlink blink;
    SysTask *blinkTask;
    MessageFormat *msgFormat;
    MsgData *msgData;
    String *names[5];
    u8 unk_0050[4];
    String *msgString;
    String *titleString;
    u32 printerId;
    SpriteList *spriteList;
    G2dRenderer renderer;
    GF_2DGfxResMan *resMan[4];
    u8 unk_019C[0x20];
    SpriteResource *charRes;
    SpriteResource *plttRes;
    SpriteResource *cellRes;
    SpriteResource *animRes;
    u8 unk_01CC[0x48];
    SpriteResourcesHeader resHeader;
    u8 unk_0238[4];
    Sprite *avatars[5];
    u8 unk_0250[0x58];
    Window memberWindow;
    u8 unk_02B8[0x40];
    Window msgWindow;
    Window unk_308;
    Window titleWindow;
    u8 unk_0328[8];
    struct ListMenu2D *yesNoMenu;
    void *charFiles[2];
    NNSG2dCharacterData *chars[2];
    void *plttFiles[2];
    NNSG2dPaletteData *pltts[2];
    u32 subState; // index into sSpinTradeGroupStateFuncs
    u32 nextSubState;
    u8 unk_035C[4];
    s32 timer;
    u8 unk_0364[0x10];
    SpinTradeGroupMember members[5];
    u32 memberStates[5];
    s32 saveState;
    u16 blinkAngle;
    u16 unk_3B6;
    void *avatarPalette;
    u8 unk_03BC[0xF80 - 0x3BC];
    u8 unk_F80[0x3AC4];
    int lastMemberCount;
    u32 joinPending;
    u32 unk_4A4C;
    u8 leaveRequested;
    s8 maxEntriesMode;
    u8 startMemberCount;
    u8 unk_4A53;
    s32 leaveTimeout;
    u32 leaveConnectedCount;
    s16 leaveWaitFrames;
    u8 unk_4A5E[2];
    SpinTradeGroupTrainerIds trainerIds[5];
} SpinTradeGroupApp;

typedef struct SpinTradeGroupBlinkFrame {
    u8 duration;
    u8 palette;
} SpinTradeGroupBlinkFrame;

static void SpinTradeGroup_VBlankTask(SysTask *task, void *data);
static void SpinTradeGroup_VBlankCallback(void *data);
static void SpinTradeGroup_SetGraphicsBanks(void);
static void SpinTradeGroup_InitBgLayers(BgConfig *bgConfig);
static void SpinTradeGroup_InitData(SpinTradeGroupApp *app, NARC *narc);
static void SpinTradeGroup_FreeData(SpinTradeGroupApp *app);
static void SpinTradeGroup_FreeBgLayers(BgConfig *bgConfig);
static void SpinTradeGroup_LoadBgGraphics(SpinTradeGroupApp *app, NARC *narc);
static void SpinTradeGroup_InitObjTransfer(void);
static void SpinTradeGroup_InitSpriteResources(SpinTradeGroupApp *app, NARC *narc);
static void SpinTradeGroup_CreateAvatarSprites(SpinTradeGroupApp *app);
static void SpinTradeGroup_InitWindows(SpinTradeGroupApp *app);
static void SpinTradeGroup_PrintTitle(Window *window, String *str, u32 speed);
static void SpinTradeGroup_RemoveWindows(SpinTradeGroupApp *app);
static int SpinTradeGroup_State_ShowPrompt(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_HandleInput(SpinTradeGroupApp *app, int state);
static void SpinTradeGroup_HandleButtons(SpinTradeGroupApp *app);
static void SpinTradeGroup_UpdateDummy(SpinTradeGroupApp *app);
static int SpinTradeGroup_State_WaitTextThenResetMenu(SpinTradeGroupApp *app, int state);
static void SpinTradeGroup_WaitPrinterThen(SpinTradeGroupApp *app, u32 nextSubState);
static int SpinTradeGroup_State_WaitPrinter(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_ResetLeaderMenuState(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_ShowCancelYesNo(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_HandleCancelYesNo(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_ResetLeaveWait(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_SendLeave(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_AbortLeave(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_ShowConfirmYesNo(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_HandleConfirmYesNo(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_SendStartSync(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_WaitSyncCount(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_BeforeSave(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_StartSave(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_Save(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_WaitAfterSave(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_ShowCanceled(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_FadeOutCanceled(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_ShowDisbandYesNo(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_HandleDisbandYesNo(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_ShowDisbanded(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_WaitBeforeExit(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_StartExitSync(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_WaitExitSync(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_ShowMemberDropped(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_WaitMemberDropped(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_ShowMemberLeft(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_StartMemberLeftWait(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_WaitMemberLeft(SpinTradeGroupApp *app, int state);
static int SpinTradeGroup_State_Proceed(SpinTradeGroupApp *app, int state);
static void SpinTradeGroup_CycleHighlightColor(u16 *p);
static int SpinTradeGroup_CountProfiles(void);
static BOOL SpinTradeGroup_PrintMemberList(Window *window, u32 unused, u32 color, SpinTradeGroupApp *app);
static void SpinTradeGroup_HandleInputDummy(SpinTradeGroupApp *app);
static int SpinTradeGroup_CountMembers(void);
static u32 SpinTradeGroup_GetMemberMask(void);
static BOOL SpinTradeGroup_UpdateMembers(SpinTradeGroupApp *app);
static void SpinTradeGroup_PrintMessage(SpinTradeGroupApp *app, int msgId, int instant);
static BOOL SpinTradeGroup_IsPrinterDone(u32 printerId);
static void SpinTradeGroup_ClearMessage(SpinTradeGroupApp *app);
static void SpinTradeGroup_UpdateAvatars(SpinTradeGroupApp *app);
static void SpinTradeGroup_LoadAvatarGraphics(SpinTradeGroupApp *app, NARC *narc);
static void SpinTradeGroup_LoadAvatar(NNSG2dCharacterData **chars, NNSG2dPaletteData **pltts, int slot, int avatar, int gender);
static void SpinTradeGroup_FreeAvatarGraphics(SpinTradeGroupApp *app);
static int SpinTradeGroup_GetTextSpeed(SpinTradeGroupApp *app);
static void SpinTradeGroup_SetMaxConnections(SpinTradeGroupApp *app, int extraEntries);
static int SpinTradeGroup_CheckMembers(SpinTradeGroupApp *app, int extraEntries);
static void SpinTradeGroup_SaveDummy(SaveData *saveData, u8 *buffer);

BOOL SpinTradeGroupApp_Init(OverlayManager *manager, int *state);
BOOL SpinTradeGroupApp_Main(OverlayManager *man, int *state);
BOOL SpinTradeGroupApp_Exit(OverlayManager *man, int *state);

static const WindowTemplate sSpinTradeGroupYesNoWindowTemplate = {
    .bgId = GF_BG_LYR_MAIN_0,
    .left = 23,
    .top = 13,
    .width = 7,
    .height = 4,
    .palette = 13,
    .baseTile = 0x178,
};

static const u16 sSpinTradeGroupAvatarCharOffsets[5] = { 0x1A0, 0x7A0, 0xDA0, 0x13A0, 0x19A0 };

static const SpinTradeGroupBlinkFrame sSpinTradeGroupBlinkFrames[5] = {
    { 8, 2 },
    { 8, 3 },
    { 8, 4 },
    { 24, 0 },
    { 0, 255 },
};

static const GraphicsModes sSpinTradeGroupGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_2D,
};

static const ObjCharTransferTemplate sSpinTradeGroupObjCharTransferTemplate = {
    .maxTasks = 20,
    .sizeMain = 0x800,
    .sizeSub = 0x800,
    .heapID = HEAP_ID_102,
};

static const SpinTradeGroupPos sSpinTradeGroupAvatarPositions[6] = {
    { 0xCC, 0x54 },
    { 0xCC, 0x35 },
    { 0xE9, 0x48 },
    { 0xDF, 0x67 },
    { 0xB8, 0x67 },
    { 0xAE, 0x48 },
};

static const BgTemplate sSpinTradeGroupBgTemplate_Sub2 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xd800,
    .charBase = GX_BG_CHARBASE_0x08000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 2,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sSpinTradeGroupBgTemplate_Main0 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf800,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sSpinTradeGroupBgTemplate_Sub0 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf000,
    .charBase = GX_BG_CHARBASE_0x10000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sSpinTradeGroupBgTemplate_Sub1 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf800,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sSpinTradeGroupBgTemplate_Main1 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf000,
    .charBase = GX_BG_CHARBASE_0x08000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const GraphicsBanks sSpinTradeGroupGraphicsBanks = {
    .bg = GX_VRAM_BG_128_A,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_128_C,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_128_B,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_NONE,
    .texpltt = GX_VRAM_TEXPLTT_NONE,
};

static int (*const sSpinTradeGroupStateFuncs[32])(SpinTradeGroupApp *, int) = {
    SpinTradeGroup_State_ShowPrompt,
    SpinTradeGroup_State_WaitTextThenResetMenu,
    SpinTradeGroup_State_ResetLeaderMenuState,
    SpinTradeGroup_State_HandleInput,
    SpinTradeGroup_State_ShowCancelYesNo,
    SpinTradeGroup_State_HandleCancelYesNo,
    SpinTradeGroup_State_ResetLeaveWait,
    SpinTradeGroup_State_SendLeave,
    SpinTradeGroup_State_AbortLeave,
    SpinTradeGroup_State_ShowCanceled,
    SpinTradeGroup_State_FadeOutCanceled,
    SpinTradeGroup_State_ShowDisbandYesNo,
    SpinTradeGroup_State_HandleDisbandYesNo,
    SpinTradeGroup_State_ShowDisbanded,
    SpinTradeGroup_State_WaitBeforeExit,
    SpinTradeGroup_State_StartExitSync,
    SpinTradeGroup_State_WaitExitSync,
    SpinTradeGroup_State_ShowMemberDropped,
    SpinTradeGroup_State_WaitMemberDropped,
    SpinTradeGroup_State_ShowMemberLeft,
    SpinTradeGroup_State_StartMemberLeftWait,
    SpinTradeGroup_State_WaitMemberLeft,
    SpinTradeGroup_State_ShowConfirmYesNo,
    SpinTradeGroup_State_HandleConfirmYesNo,
    SpinTradeGroup_State_SendStartSync,
    SpinTradeGroup_State_WaitSyncCount,
    SpinTradeGroup_State_BeforeSave,
    SpinTradeGroup_State_StartSave,
    SpinTradeGroup_State_Save,
    SpinTradeGroup_State_WaitAfterSave,
    SpinTradeGroup_State_WaitPrinter,
    SpinTradeGroup_State_Proceed,
};

BOOL SpinTradeGroupApp_Init(OverlayManager *manager, int *state) {
    NARC *narc;
    SpinTradeArgs *args = OverlayManager_GetArgs(manager);
    SpinTradeGroupApp *app;
    switch (*state) {
    case 0:
        Main_SetVBlankIntrCB(NULL, NULL);
        HBlankInterruptDisable();
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        *(vu32 *)0x04000000 &= 0xffffe0ff;
        *(vu32 *)0x04001000 &= 0xffffe0ff;
        Heap_Create(HEAP_ID_3, HEAP_ID_102, 0x80000);
        narc = NARC_New(NARC_a_2_1_5, HEAP_ID_102);
        GF_ASSERT(narc != NULL);
        app = OverlayManager_CreateAndGetData(manager, sizeof(SpinTradeGroupApp), HEAP_ID_102);
        memset(app, 0, sizeof(SpinTradeGroupApp));
        args->groupApp = app;
        app->args = args;
        app->menu = args->menu;
        app->bgConfig = BgConfig_Alloc(HEAP_ID_102);
        app->msgFormat = MessageFormat_New(HEAP_ID_102);
        app->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0207_bin, HEAP_ID_102);
        SetKeyRepeatTimers(4, 8);
        SpinTradeGroup_SetGraphicsBanks();
        SpinTradeGroup_InitBgLayers(app->bgConfig);
        BeginNormalPaletteFade(0, 0x11, 0x11, RGB_BLACK, 16, 1, HEAP_ID_102);
        SpinTradeGroup_LoadBgGraphics(app, narc);
        Main_SetVBlankIntrCB(SpinTradeGroup_VBlankCallback, app);
        SpinTradeGroup_InitData(app, narc);
        SpinTradeGroup_InitObjTransfer();
        SpinTradeGroup_InitSpriteResources(app, narc);
        SpinTradeGroup_CreateAvatarSprites(app);
        SpinTradeGroup_InitWindows(app);
        Sound_SetSceneAndPlayBGM(52, SEQ_NONE, 0);
        SpinTradeLink_RegisterCommands(args->menu);
        CommState_SetSpinTradeLinkMode();
        CommState_SetMaxEntries(3);
        if (!Comm_GetLocalNetId()) {
            UnionRoom_SetBeaconActivity(UNION_ACTIVITY_SPIN_TRADE_RECRUIT);
        }
        WirelessStatusIcon_Create();
        app->blinkTask = SysTask_CreateOnVBlankQueue(SpinTradeGroup_VBlankTask, app, 5);
        NARC_Delete(narc);
        (*state)++;
        break;
    case 1:
        *state = 0;
        return TRUE;
    }
    return FALSE;
}

BOOL SpinTradeGroupApp_Main(OverlayManager *man, int *state) {
    SpinTradeGroupApp *app = OverlayManager_GetData(man);
    int mode;

    if (System_GetTouchNew()) {
        gSystem.simulatedInputs = 1;
    }
    if (Comm_GetLocalNetId() == 0 && app->menu->leavingMask) {
        u32 mask = Wireless_GetConnectedBitmap();
        app->menu->leavingMask = mask & app->menu->leavingMask;
    }
    mode = app->state;
    switch (mode) {
    case 0:
        if (IsPaletteFadeFinished()) {
            app->state = 1;
            if (Comm_GetLocalNetId() != 0 && SpinTradeGroup_CountMembers() > 2) {
                SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_JOIN_NOTICE, NULL, 0);
            }
        }
        break;
    case 1:
        if (sSpinTradeGroupStateFuncs[app->subState]) {
            app->state = sSpinTradeGroupStateFuncs[app->subState](app, mode);
        }
        if (app->menu->state == 0) {
            SpinTradeGroup_PrintMemberList(&app->memberWindow, 0, MAKE_TEXT_COLOR(1, 3, 0), app);
        }
        SpinTradeGroup_UpdateAvatars(app);
        if (Comm_GetLocalNetId() == 0) {
            int next = SpinTradeGroup_CheckMembers(app, 1);
            if (app->state == 1) {
                app->state = next;
            }
        }
        break;
    case 2:
        if (sSpinTradeGroupStateFuncs[app->subState]) {
            app->state = sSpinTradeGroupStateFuncs[app->subState](app, mode);
        }
        break;
    case 3:
        if (IsPaletteFadeFinished()) {
            return TRUE;
        }
        break;
    }
    SpriteList_RenderAndAnimateSprites(app->spriteList);
    return FALSE;
}

BOOL SpinTradeGroupApp_Exit(OverlayManager *man, int *state) {
#pragma unused(state)
    int i;
    SpinTradeGroupApp *app = OverlayManager_GetData(man);
    SysTask_Destroy(app->blinkTask);
    SpriteTransfer_DeleteCharTransferTask(app->charRes);
    SpriteTransfer_DeletePlttTransferTask(app->plttRes);
    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(app->resMan[i]);
    }
    SpriteList_Delete(app->spriteList);
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    SpinTradeGroup_RemoveWindows(app);
    SpinTradeGroup_FreeBgLayers(app->bgConfig);
    DestroyMsgData(app->msgData);
    MessageFormat_Delete(app->msgFormat);
    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);
    Main_SetVBlankIntrCB(NULL, NULL);
    app->args->result = app->result;
    app->args->playerCount = SpinTradeGroup_CountMembers();
    app->args->memberMask = SpinTradeGroup_GetMemberMask();
    SpinTradeGroup_FreeData(app);
    OverlayManager_FreeData(man);
    Heap_Destroy(HEAP_ID_102);
    return TRUE;
}

static void SpinTradeGroup_VBlankTask(SysTask *task, void *data) {
    SpinTradeGroupApp *app = data;
    SpinTradeGroupBlink *blink = &app->blink;
    if (app->blink.active) {
        if (blink->timer > sSpinTradeGroupBlinkFrames[blink->frame].duration) {
            blink->timer = 0;
            blink->frame++;
            if (sSpinTradeGroupBlinkFrames[blink->frame].palette == 0xFF) {
                blink->frame = 0;
            }
            GX_LoadOBJPltt((u8 *)blink->pltt->pRawData + sSpinTradeGroupBlinkFrames[blink->frame].palette * 32, 0, 0x20);
        } else {
            app->blink.timer++;
        }
        SpinTradeGroup_CycleHighlightColor(&app->blinkAngle);
    }
}

// VBlank callback; registered with the app pointer as its argument
static void SpinTradeGroup_VBlankCallback(void *data) {
    GF_RunVramTransferTasks();
    OamManager_ApplyAndResetBuffers();
    DoScheduledBgGpuUpdates(data);
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static void SpinTradeGroup_SetGraphicsBanks(void) {
    GraphicsBanks banks = sSpinTradeGroupGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

static void SpinTradeGroup_InitBgLayers(BgConfig *bgConfig) {
    GraphicsModes modes = sSpinTradeGroupGraphicsModes;
    BgTemplate subBg0, subBg1, subBg2, mainBg0, mainBg1;

    SetBothScreensModesAndDisable(&modes);
    subBg0 = sSpinTradeGroupBgTemplate_Sub0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &subBg0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    subBg1 = sSpinTradeGroupBgTemplate_Sub1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &subBg1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    subBg2 = sSpinTradeGroupBgTemplate_Sub2;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_2, &subBg2, GF_BG_TYPE_TEXT);
    mainBg0 = sSpinTradeGroupBgTemplate_Main0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &mainBg0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    mainBg1 = sSpinTradeGroupBgTemplate_Main1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &mainBg1, GF_BG_TYPE_TEXT);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 32, 0, HEAP_ID_102);
    BG_ClearCharDataRange(GF_BG_LYR_SUB_0, 32, 0, HEAP_ID_102);
}

static void SpinTradeGroup_InitData(SpinTradeGroupApp *app, NARC *narc) {
    int i;
    for (i = 0; i < 5; i++) {
        app->names[i] = String_New(8, HEAP_ID_102);
        app->members[i].profile = NULL;
        app->members[i].prevProfile = NULL;
        app->memberStates[i] = 0;
    }
    app->msgString = String_New(0xB4, HEAP_ID_102);
    app->titleString = String_New(0x28, HEAP_ID_102);
    app->subState = SPIN_TRADE_GROUP_STATE_SHOW_PROMPT;
    ReadMsgDataIntoString(app->msgData, msg_0207_00017, app->titleString);
    SpinTradeGroup_LoadAvatarGraphics(app, narc);
    app->avatarPalette = UnionRoom_LoadAvatarPalette(HEAP_ID_102);
    app->blink.active = FALSE;
    app->blink.timer = 0;
    app->blink.frame = 0;
    app->blink.plttFile = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 1, &app->blink.pltt, HEAP_ID_102);
    app->lastMemberCount = 0;
    app->yesNoMenu = NULL;
    app->menu->participantCount = 2;
}

static void SpinTradeGroup_FreeData(SpinTradeGroupApp *app) {
    int i;
    SpinTradeGroup_FreeAvatarGraphics(app);
    Heap_Free(app->blink.plttFile);
    Heap_Free(app->avatarPalette);
    for (i = 0; i < 5; i++) {
        String_Delete(app->names[i]);
    }
    String_Delete(app->titleString);
    String_Delete(app->msgString);
}

static void SpinTradeGroup_FreeBgLayers(BgConfig *bgConfig) {
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_2);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_0);
    Heap_Free(bgConfig);
}

static void SpinTradeGroup_LoadBgGraphics(SpinTradeGroupApp *app, NARC *narc) {
    BgConfig *bgConfig = app->bgConfig;

    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x200, HEAP_ID_102);
    GfGfxLoader_GXLoadPal(NARC_a_0_1_4, 71, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x20, HEAP_ID_102);
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_13_OFFSET, HEAP_ID_102);
    LoadFontPal1(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_13_OFFSET, HEAP_ID_102);
    GfGfxLoader_LoadCharData(NARC_a_0_1_4, 10, bgConfig, GF_BG_LYR_SUB_2, 0, 0, TRUE, HEAP_ID_102);
    GfGfxLoader_LoadScrnData(NARC_a_0_1_4, 11, bgConfig, GF_BG_LYR_SUB_2, 0, 0, TRUE, HEAP_ID_102);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 2, bgConfig, GF_BG_LYR_MAIN_1, 0, 0x2000, TRUE, HEAP_ID_102);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 3, bgConfig, GF_BG_LYR_MAIN_1, 0, 0x600, TRUE, HEAP_ID_102);
    LoadUserFrameGfx2(bgConfig, GF_BG_LYR_MAIN_0, 1, 10, Options_GetFrame(app->args->input.options), HEAP_ID_102);
    LoadUserFrameGfx1(bgConfig, GF_BG_LYR_MAIN_0, 31, 11, 0, HEAP_ID_102);
}

static void SpinTradeGroup_InitObjTransfer(void) {
    ObjCharTransferTemplate tmpl = sSpinTradeGroupObjCharTransferTemplate;
    ObjCharTransfer_Init(&tmpl);
    ObjPlttTransfer_Init(0x14, HEAP_ID_102);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
}

static void SpinTradeGroup_InitSpriteResources(SpinTradeGroupApp *app, NARC *narc) {
    int i;

    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 0x7E, 0, 0x20, 0, 0x7E, 0, 0x20, HEAP_ID_102);
    app->spriteList = G2dRenderer_Init(0x1E, &app->renderer, HEAP_ID_102);
    GF_ASSERT(app->spriteList != NULL);
    G2dRenderer_SetSubSurfaceCoords(&app->renderer, 0, FX32_CONST(256));
    for (i = 0; i < 4; i++) {
        app->resMan[i] = Create2DGfxResObjMan(3, (GfGfxResType)i, HEAP_ID_102);
    }
    app->charRes = AddCharResObjFromOpenNarc(app->resMan[0], narc, 0xC, TRUE, 2, NNS_G2D_VRAM_TYPE_2DMAIN, HEAP_ID_102);
    app->plttRes = AddPlttResObjFromOpenNarc(app->resMan[1], narc, 1, FALSE, 2, NNS_G2D_VRAM_TYPE_2DMAIN, 0xF, HEAP_ID_102);
    app->cellRes = AddCellOrAnimResObjFromOpenNarc(app->resMan[2], narc, 0xD, TRUE, 2, GF_GFX_RES_TYPE_CELL, HEAP_ID_102);
    app->animRes = AddCellOrAnimResObjFromOpenNarc(app->resMan[3], narc, 0xE, TRUE, 2, GF_GFX_RES_TYPE_ANIM, HEAP_ID_102);
    SpriteTransfer_CreateCharTransferTask(app->charRes);
    SpriteTransfer_CreateExtPlttTransferTask(app->plttRes);
}

static void SpinTradeGroup_CreateAvatarSprites(SpinTradeGroupApp *app) {
    SpriteTemplate tmpl;
    int i;

    CreateSpriteResourcesHeader(&app->resHeader, 2, 2, 2, 2, -1, -1, 0, 1, app->resMan[0], app->resMan[1], app->resMan[2], app->resMan[3], NULL, NULL);
    tmpl.spriteList = app->spriteList;
    tmpl.header = &app->resHeader;
    tmpl.position.z = 0;
    tmpl.scale.x = FX32_ONE;
    tmpl.scale.y = FX32_ONE;
    tmpl.scale.z = FX32_ONE;
    tmpl.rotation = 0;
    tmpl.drawPriority = 1;
    tmpl.whichScreen = (NNS_G2D_VRAM_TYPE)1;
    tmpl.heapID = HEAP_ID_102;
    for (i = 0; i < 5; i++) {
        tmpl.position.x = sSpinTradeGroupAvatarPositions[i + 1].x << 12;
        tmpl.position.y = sSpinTradeGroupAvatarPositions[i + 1].y << 12;
        app->avatars[i] = Sprite_CreateAffine(&tmpl);
        Sprite_SetAnimActiveFlag(app->avatars[i], TRUE);
        Sprite_SetAnimCtrlSeq(app->avatars[i], (i - 1) * 2 + 0x1B);
        Sprite_SetDrawFlag(app->avatars[i], FALSE);
    }
    tmpl.position.x = FX32_CONST(24);
    tmpl.position.y = FX32_CONST(416);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
}

static void SpinTradeGroup_InitWindows(SpinTradeGroupApp *app) {
    AddWindowParameterized(app->bgConfig, &app->unk_308, GF_BG_LYR_SUB_1, 0x1A, 0x14, 6, 2, 0xD, 0x1C3);
    FillWindowPixelBuffer(&app->unk_308, 0);
    AddWindowParameterized(app->bgConfig, &app->msgWindow, GF_BG_LYR_MAIN_0, 2, 0x13, 0x1B, 4, 0xD, 0x28);
    FillWindowPixelBuffer(&app->msgWindow, 0xF);
    AddWindowParameterized(app->bgConfig, &app->titleWindow, GF_BG_LYR_MAIN_0, 3, 1, 0x1A, 2, 0xF, 0x94);
    SpinTradeGroup_PrintTitle(&app->titleWindow, app->titleString, 0);
    AddWindowParameterized(app->bgConfig, &app->memberWindow, GF_BG_LYR_MAIN_0, 2, 6, 0x10, 0xB, 0xF, 0xC8);
    FillWindowPixelBuffer(&app->memberWindow, 0);
    SpinTradeGroup_PrintMemberList(&app->memberWindow, 0, 0x10300, app);
}

static void SpinTradeGroup_PrintTitle(Window *window, String *str, u32 speed) {
    u32 width = FontID_String_GetWidth(1, str, 0);
    FillWindowPixelBuffer(window, 0);
    AddTextPrinterParameterizedWithColor(window, 1, str, (0xD0 - (int)width) / 2, 1, speed, 0x10400, NULL);
}

static void SpinTradeGroup_RemoveWindows(SpinTradeGroupApp *app) {
    RemoveWindow(&app->memberWindow);
    RemoveWindow(&app->titleWindow);
    RemoveWindow(&app->unk_308);
    RemoveWindow(&app->msgWindow);
}

static int SpinTradeGroup_State_ShowPrompt(SpinTradeGroupApp *app, int state) {
    CommState_SetErrorWatch(FALSE, TRUE);
    if (!Comm_GetLocalNetId()) {
        if ((int)Comm_CountConnected() >= 2) {
            SpinTradeGroup_PrintMessage(app, msg_0207_00002, 0);
        }
    } else {
        SpinTradeGroup_PrintMessage(app, msg_0207_00008, 0);
    }
    SpinTradeGroup_WaitPrinterThen(app, SPIN_TRADE_GROUP_STATE_HANDLE_INPUT);
    return state;
}

static int SpinTradeGroup_State_HandleInput(SpinTradeGroupApp *app, int state) {
    SpinTradeGroup_HandleButtons(app);
    if (!Comm_GetLocalNetId()) {
        if (SpinTradeGroup_CountProfiles() != 1) {
            SpinTradeGroup_HandleInputDummy(app);
        }
    } else {
        SpinTradeGroup_HandleInputDummy(app);
    }
    return state;
}

static void SpinTradeGroup_HandleButtons(SpinTradeGroupApp *app) {
    u8 confirmOpen;
    u8 cancelOpen;
    u8 menuClosed;

    if (gSystem.newKeys & PAD_BUTTON_A) {
        if (!Comm_GetLocalNetId()) {
            if (app->menu->participantCount == (u32)SpinTradeGroup_CountMembers() && app->menu->leavingMask == 0) {
                confirmOpen = 1;
                SpinTradeGroup_PrintMessage(app, msg_0207_00003, 0);
                SpinTradeGroup_WaitPrinterThen(app, SPIN_TRADE_GROUP_STATE_SHOW_CONFIRM_YES_NO);
                SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_LEADER_MENU_STATE, &confirmOpen, 1);
                SpinTradeGroup_SetMaxConnections(app, 0);
            } else {
                PlaySE(SEQ_SE_DP_CUSTOM06);
            }
        }
    } else if (gSystem.newKeys & PAD_BUTTON_B) {
        if (Comm_GetLocalNetId()) {
            if (app->menu->leaderJoinPending == 0) {
                SpinTradeGroup_PrintMessage(app, msg_0207_00004, 0);
                SpinTradeGroup_WaitPrinterThen(app, SPIN_TRADE_GROUP_STATE_SHOW_CANCEL_YES_NO);
            } else {
                PlaySE(SEQ_SE_DP_CUSTOM06);
            }
        } else {
            if (app->menu->participantCount == Comm_CountConnected() && app->menu->leavingMask == 0) {
                cancelOpen = 1;
                SpinTradeGroup_PrintMessage(app, msg_0207_00004, 0);
                SpinTradeGroup_WaitPrinterThen(app, SPIN_TRADE_GROUP_STATE_SHOW_CANCEL_YES_NO);
                SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_LEADER_MENU_STATE, &cancelOpen, 1);
                SpinTradeGroup_SetMaxConnections(app, 0);
            } else {
                PlaySE(SEQ_SE_DP_CUSTOM06);
            }
        }
    } else {
        if (app->joinPending == 0 && !Comm_GetLocalNetId() && app->menu->participantCount == Comm_CountConnected()) {
            menuClosed = 0;
            SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_LEADER_MENU_STATE, &menuClosed, 1);
        }
    }
}

static void SpinTradeGroup_UpdateDummy(SpinTradeGroupApp *app) {
#pragma unused(app)
}

static int SpinTradeGroup_State_WaitTextThenResetMenu(SpinTradeGroupApp *app, int state) {
    SpinTradeGroup_WaitPrinterThen(app, SPIN_TRADE_GROUP_STATE_RESET_LEADER_MENU_STATE);
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static void SpinTradeGroup_WaitPrinterThen(SpinTradeGroupApp *app, u32 nextSubState) {
    app->subState = SPIN_TRADE_GROUP_STATE_WAIT_PRINTER;
    app->nextSubState = nextSubState;
}

static int SpinTradeGroup_State_WaitPrinter(SpinTradeGroupApp *app, int state) {
    if (SpinTradeGroup_IsPrinterDone(app->printerId)) {
        app->subState = app->nextSubState;
    }
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_ResetLeaderMenuState(SpinTradeGroupApp *app, int state) {
    u32 menuState;
    if (!Comm_GetLocalNetId()) {
        menuState = 0;
        SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_LEADER_MENU_STATE, &menuState, 1);
    }
    app->subState = SPIN_TRADE_GROUP_STATE_HANDLE_INPUT;
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_ShowCancelYesNo(SpinTradeGroupApp *app, int state) {
    app->yesNoMenu = Std_CreateYesNoMenu(app->bgConfig, &sSpinTradeGroupYesNoWindowTemplate, 0x1F, 0xB, HEAP_ID_102);
    app->subState = SPIN_TRADE_GROUP_STATE_HANDLE_CANCEL_YES_NO;
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_HandleCancelYesNo(SpinTradeGroupApp *app, int state) {
    u32 menuState;
    u8 buf[4];
    int input;

    if (Comm_GetLocalNetId()) {
        if (app->menu->leaderJoinPending) {
            if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B | PAD_KEY_UP | PAD_KEY_DOWN)) {
                PlaySE(SEQ_SE_DP_CUSTOM06);
            }
            SpinTradeGroup_UpdateDummy(app);
            return state;
        }
    } else {
        if (app->menu->leavingMask) {
            if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B | PAD_KEY_UP | PAD_KEY_DOWN)) {
                PlaySE(SEQ_SE_DP_CUSTOM06);
            }
            SpinTradeGroup_UpdateDummy(app);
            return state;
        }
    }
    if ((u32)SpinTradeGroup_CountMembers() != Comm_CountConnected()) {
        SpinTradeGroup_UpdateDummy(app);
        return state;
    }
    input = Handle2dMenuInput_DeleteOnFinish(app->yesNoMenu, HEAP_ID_102);
    if (input != -1) {
        if (input == -2) {
            if (!Comm_GetLocalNetId()) {
                menuState = 0;
                SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_LEADER_MENU_STATE, &menuState, 1);
                SpinTradeGroup_SetMaxConnections(app, 1);
            }
            SpinTradeGroup_WaitPrinterThen(app, SPIN_TRADE_GROUP_STATE_SHOW_PROMPT);
        } else if (!Comm_GetLocalNetId()) {
            SpinTradeGroup_WaitPrinterThen(app, SPIN_TRADE_GROUP_STATE_SHOW_DISBAND_YES_NO);
            SpinTradeGroup_PrintMessage(app, msg_0207_00014, 0);
        } else {
            MI_CpuFill8(buf, 0, 4);
            buf[2] = 0;
            buf[0] = Comm_GetLocalNetId();
            app->leaveRequested = 1;
            app->leaveWaitFrames = 0;
            app->subState = SPIN_TRADE_GROUP_STATE_RESET_LEAVE_WAIT;
            SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_JOIN_REQUEST, buf, 4);
        }
        app->yesNoMenu = NULL;
    }
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_ResetLeaveWait(SpinTradeGroupApp *app, int state) {
    app->leaveWaitFrames = 0;
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_SendLeave(SpinTradeGroupApp *app, int state) {
    if (app->menu->assignedCount != Comm_CountConnected() || app->menu->assignedCount != SpinTradeGroup_CountMembers()) {
        app->leaveWaitFrames = 0;
        app->subState = SPIN_TRADE_GROUP_STATE_ABORT_LEAVE;
        SpinTradeGroup_UpdateDummy(app);
        return state;
    }
    app->leaveWaitFrames++;
    if (app->leaveWaitFrames > 30) {
        u8 buf[4];
        MI_CpuFill8(buf, 0, 4);
        buf[2] = 1;
        buf[0] = Comm_GetLocalNetId();
        SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_JOIN_REQUEST, buf, 4);
        app->leaveWaitFrames = 0;
        app->subState = SPIN_TRADE_GROUP_STATE_SHOW_CANCELED;
    }
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_AbortLeave(SpinTradeGroupApp *app, int state) {
    app->leaveRequested = 0;
    SpinTradeGroup_WaitPrinterThen(app, SPIN_TRADE_GROUP_STATE_SHOW_PROMPT);
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_ShowConfirmYesNo(SpinTradeGroupApp *app, int state) {
    app->yesNoMenu = Std_CreateYesNoMenu(app->bgConfig, &sSpinTradeGroupYesNoWindowTemplate, 0x1F, 0xB, HEAP_ID_102);
    app->subState = SPIN_TRADE_GROUP_STATE_HANDLE_CONFIRM_YES_NO;
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_HandleConfirmYesNo(SpinTradeGroupApp *app, int state) {
    SpinTradeLink *link = app->menu;
    if (link->participantCount != SpinTradeGroup_CountMembers() || link->leavingMask != 0) {
        if (0xC3 & gSystem.newKeys) {
            PlaySE(SEQ_SE_DP_CUSTOM06);
        }
        SpinTradeGroup_UpdateDummy(app);
        return state;
    }
    {
        int input = Handle2dMenuInput_DeleteOnFinish(app->yesNoMenu, HEAP_ID_102);
        if (input != -1) {
            if (input == -2) {
                u32 menuState = 0;
                SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_LEADER_MENU_STATE, &menuState, 1);
                SpinTradeGroup_SetMaxConnections(app, 1);
                SpinTradeGroup_WaitPrinterThen(app, SPIN_TRADE_GROUP_STATE_SHOW_PROMPT);
            } else if (Comm_GetLocalNetId() == 0) {
                app->subState = SPIN_TRADE_GROUP_STATE_SEND_START_SYNC;
                app->startMemberCount = SpinTradeGroup_CountMembers();
                UnionRoom_SetBeaconActivity(UNION_ACTIVITY_SPIN_TRADE);
            } else {
                GF_ASSERT(FALSE);
            }
            app->yesNoMenu = NULL;
        }
    }
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_SendStartSync(SpinTradeGroupApp *app, int state) {
    if (app->unk_4A53 == 0) {
        if (SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_START_SYNC, NULL, 0) == 1) {
            app->subState = SPIN_TRADE_GROUP_STATE_PROCEED;
        }
    }
    return state;
}

static int SpinTradeGroup_State_WaitSyncCount(SpinTradeGroupApp *app, int state) {
    if (!Comm_GetLocalNetId()) {
        Comm_CountConnected();
    }
    if (app->menu->count == Comm_CountConnected()) {
        app->subState = SPIN_TRADE_GROUP_STATE_PROCEED;
    }
    return state;
}

static int SpinTradeGroup_State_BeforeSave(SpinTradeGroupApp *app, int state) {
    SpinTradeGroup_SaveDummy(app->args->input.saveData, app->unk_F80);
    app->subState = SPIN_TRADE_GROUP_STATE_START_SAVE;
    return state;
}

static int SpinTradeGroup_State_StartSave(SpinTradeGroupApp *app, int state) {
    gSystem.softResetDisabled = 1;
    GameStats_AddScore(app->args->input.gameStats, SCORE_EVENT_RECORDS_MIXED);
    Comm_InitSyncedSave(&app->saveState);
    app->subState = SPIN_TRADE_GROUP_STATE_SAVE;
    return state;
}

static int SpinTradeGroup_State_Save(SpinTradeGroupApp *app, int state) {
    if (Comm_GetLocalNetId() == 0) {
        Comm_CountConnected();
    }
    if (Comm_SyncedSave(app->args->input.saveData, 2, &app->saveState)) {
        StopSE(SEQ_SE_DP_F209, 8);
        SpinTradeGroup_PrintMessage(app, msg_0207_00013, 0);
        SpinTradeGroup_WaitPrinterThen(app, SPIN_TRADE_GROUP_STATE_WAIT_AFTER_SAVE);
        app->blink.active = FALSE;
        app->timer = 0;
        gSystem.softResetDisabled = 0;
        app->menu->state = 0;
    }
    return state;
}

static int SpinTradeGroup_State_WaitAfterSave(SpinTradeGroupApp *app, int state) {
    if (app->timer++ > 0x3C) {
        app->subState = SPIN_TRADE_GROUP_STATE_START_EXIT_SYNC;
    }
    return state;
}

static int SpinTradeGroup_State_ShowCanceled(SpinTradeGroupApp *app, int state) {
    SpinTradeGroup_PrintMessage(app, msg_0207_00005, 0);
    SpinTradeGroup_WaitPrinterThen(app, SPIN_TRADE_GROUP_STATE_FADE_OUT_CANCELED);
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_FadeOutCanceled(SpinTradeGroupApp *app, int state) {
    app->timer++;
    if (app->timer > 0x3C) {
        BeginNormalPaletteFade(0, 0x10, 0x10, RGB_BLACK, 0x10, 1, HEAP_ID_102);
        state = 3;
    }
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_ShowDisbandYesNo(SpinTradeGroupApp *app, int state) {
    app->yesNoMenu = Std_CreateYesNoMenu(app->bgConfig, &sSpinTradeGroupYesNoWindowTemplate, 0x1F, 0xB, HEAP_ID_102);
    app->subState = SPIN_TRADE_GROUP_STATE_HANDLE_DISBAND_YES_NO;
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_HandleDisbandYesNo(SpinTradeGroupApp *app, int state) {
    SpinTradeLink *link = app->menu;
    if (link->participantCount != SpinTradeGroup_CountMembers() || link->leavingMask != 0) {
        if (0xC3 & gSystem.newKeys) {
            PlaySE(SEQ_SE_DP_CUSTOM06);
        }
        SpinTradeGroup_UpdateDummy(app);
        return state;
    }
    {
        int input = Handle2dMenuInput_DeleteOnFinish(app->yesNoMenu, HEAP_ID_102);
        if (input != -1) {
            if (input == -2) {
                u32 menuState = 0;
                app->subState = SPIN_TRADE_GROUP_STATE_SHOW_PROMPT;
                SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_LEADER_MENU_STATE, &menuState, 1);
                SpinTradeGroup_SetMaxConnections(app, 1);
            } else {
                app->subState = SPIN_TRADE_GROUP_STATE_SHOW_DISBANDED;
                SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_CLOSE_YES_NO, NULL, 0);
                BufferPlayersName(app->msgFormat, 0, CommPlayerInfo_GetProfile(0));
            }
            app->yesNoMenu = NULL;
        }
    }
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_ShowDisbanded(SpinTradeGroupApp *app, int state) {
    if (Comm_GetLocalNetId() == 0) {
        SpinTradeGroup_PrintMessage(app, msg_0207_00005, 0);
    } else {
        BufferPlayersName(app->msgFormat, 0, CommPlayerInfo_GetProfile(0));
        SpinTradeGroup_PrintMessage(app, msg_0207_00016, 0);
    }
    SpinTradeGroup_WaitPrinterThen(app, SPIN_TRADE_GROUP_STATE_WAIT_BEFORE_EXIT);
    app->timer = 0;
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_WaitBeforeExit(SpinTradeGroupApp *app, int state) {
    app->timer++;
    if (app->timer > 0x2D) {
        app->subState = SPIN_TRADE_GROUP_STATE_START_EXIT_SYNC;
    }
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_StartExitSync(SpinTradeGroupApp *app, int state) {
    LinkSync_StartSync(0xCA);
    app->subState = SPIN_TRADE_GROUP_STATE_WAIT_EXIT_SYNC;
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_WaitExitSync(SpinTradeGroupApp *app, int state) {
    if (LinkSync_IsSynced(0xCA)) {
        CommState_SetErrorWatch(FALSE, FALSE);
        BeginNormalPaletteFade(0, 0x10, 0x10, RGB_BLACK, 0x10, 1, HEAP_ID_102);
        state = 3;
    }
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_ShowMemberDropped(SpinTradeGroupApp *app, int state) {
    if (SpinTradeGroup_IsPrinterDone(app->printerId)) {
        SpinTradeGroup_PrintMessage(app, msg_0207_00009, 0);
    }
    app->subState = SPIN_TRADE_GROUP_STATE_WAIT_MEMBER_DROPPED;
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_WaitMemberDropped(SpinTradeGroupApp *app, int state) {
    if (SpinTradeGroup_IsPrinterDone(app->printerId)) {
        app->subState = SPIN_TRADE_GROUP_STATE_FADE_OUT_CANCELED;
    }
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_ShowMemberLeft(SpinTradeGroupApp *app, int state) {
    if (app->printerId != 0xFF && !SpinTradeGroup_IsPrinterDone(app->printerId)) {
        RemoveTextPrinter(app->printerId);
    }
    SpinTradeGroup_PrintMessage(app, msg_0207_00015, 1);
    app->subState = SPIN_TRADE_GROUP_STATE_START_MEMBER_LEFT_WAIT;
    if (Comm_GetLocalNetId() == 0) {
        SpinTradeGroup_SetMaxConnections(app, 0);
    }
    app->leaveConnectedCount = Comm_CountConnected();
    app->leaveTimeout = 0x12C;
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_StartMemberLeftWait(SpinTradeGroupApp *app, int state) {
    if (app->leaveConnectedCount != 0) {
        if (app->leaveConnectedCount != Comm_CountConnected()) {
            app->leaveConnectedCount = 0;
        }
    }
    app->subState = SPIN_TRADE_GROUP_STATE_WAIT_MEMBER_LEFT;
    app->timer = 0;
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_WaitMemberLeft(SpinTradeGroupApp *app, int state) {
    if (app->leaveConnectedCount != 0) {
        if (app->leaveConnectedCount != Comm_CountConnected()) {
            app->leaveConnectedCount = 0;
        }
    }
    app->leaveTimeout--;
    if (app->leaveTimeout < 0) {
        app->leaveConnectedCount = 0;
    }
    app->timer++;
    if (app->timer > 0x3C && app->leaveConnectedCount == 0) {
        app->subState = SPIN_TRADE_GROUP_STATE_SHOW_PROMPT;
        if (Comm_GetLocalNetId() == 0) {
            SpinTradeGroup_SetMaxConnections(app, 1);
        }
    }
    SpinTradeGroup_UpdateDummy(app);
    return state;
}

static int SpinTradeGroup_State_Proceed(SpinTradeGroupApp *app, int state) {
#pragma unused(state)
    UnionRoom_SetBeaconActivity(UNION_ACTIVITY_SPIN_TRADE);
    BeginNormalPaletteFade(0, 0x10, 0x10, RGB_BLACK, 0x10, 1, HEAP_ID_102);
    app->result = 1;
    SpinTradeGroup_UpdateDummy(app);
    return 3;
}

void SpinTradeGroup_HandleLinkEvent(SpinTradeGroupApp *app, int msg, int value) {
    switch (msg) {
    case 2:
        SpinTradeGroup_ClearMessage(app);
        break;
    case 7:
    case 8:
        break;
    case 0xD:
        if (app->yesNoMenu != NULL) {
            Clear2dMenuWindowAndDelete(app->yesNoMenu, HEAP_ID_102);
            app->yesNoMenu = NULL;
        }
        break;
    case 0x19:
        if (!SpinTradeGroup_IsPrinterDone(app->printerId)) {
            RemoveTextPrinter(app->printerId);
        }
        SpinTradeGroup_PrintMessage(app, msg_0207_00012, 0);
        if (app->yesNoMenu != NULL) {
            Clear2dMenuWindowAndDelete(app->yesNoMenu, HEAP_ID_102);
            app->yesNoMenu = NULL;
        }
        break;
    case 0x13:
        if (app->leaveRequested == 1) {
            return;
        }
        BufferPlayersName(app->msgFormat, 0, CommPlayerInfo_GetProfile(value));
        if (value == Comm_GetLocalNetId()) {
            return;
        }
        if (app->yesNoMenu != NULL) {
            Clear2dMenuWindowAndDelete(app->yesNoMenu, HEAP_ID_102);
            app->yesNoMenu = NULL;
        }
        if (Comm_GetLocalNetId() == 0) {
            app->menu->leavingMask &= 0xFFFF ^ value;
        }
        break;
    case 0x1F:
        if (!SpinTradeGroup_IsPrinterDone(app->printerId)) {
            RemoveTextPrinter(app->printerId);
        }
        if (app->yesNoMenu != NULL) {
            Clear2dMenuWindowAndDelete(app->yesNoMenu, HEAP_ID_102);
            app->yesNoMenu = NULL;
        }
        break;
    default:
        return;
    }
    app->subState = msg;
}

void SpinTradeGroup_HandleMemberEvent(SpinTradeGroupApp *app, int event, int netId) {
    if (app->subState == SPIN_TRADE_GROUP_STATE_HANDLE_INPUT) {
        switch (event) {
        case 1: {
            SpinTradeLink *link;
            BufferPlayersName(app->msgFormat, 0, CommPlayerInfo_GetProfile(netId));
            SpinTradeGroup_SetMaxConnections(app, 1);
            app->subState = event;
            app->menu->participantCount = Comm_CountConnected();
            link = app->menu;
            link->leavingMask = 0;
            if (Comm_GetLocalNetId() == 0) {
                u32 menuOpen = 1;
                SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_LEADER_MENU_STATE, &menuOpen, 1);
            }
            break;
        }
        case 0x13:
            BufferPlayersName(app->msgFormat, 0, CommPlayerInfo_GetProfile(netId));
            if (netId != Comm_GetLocalNetId()) {
                if (Comm_GetLocalNetId() == 0) {
                    SpinTradeLink *link = app->menu;
                    link->leavingMask = (0xFFFF ^ netId) & link->leavingMask;
                }
                app->subState = event;
            }
            break;
        default:
            GF_ASSERT(FALSE);
            break;
        }
    } else if (event == 1) {
        app->menu->leavingMask = 0;
        app->menu->participantCount = Comm_CountConnected();
    }
}

static void SpinTradeGroup_CycleHighlightColor(u16 *p) {
    u16 color;
    *p += 10;
    if (*p > 360) {
        *p = 0;
    }
    color = (((GF_SinDeg(*p) * 10) / FX32_ONE) + 15) << 5 | 29;
    GX_LoadOBJPltt(&color, 10, 2);
    GX_LoadOBJPltt(&color, 42, 2);
}

static int SpinTradeGroup_CountProfiles(void) {
    int i;
    int count;
    count = 0;
    i = 0;
    for (; i < 5; i++) {
        if (CommPlayerInfo_GetProfile(i)) {
            count++;
        }
    }
    return count;
}

static BOOL SpinTradeGroup_PrintMemberList(Window *window, u32 unused, u32 color, SpinTradeGroupApp *app) {
    int i;
    int sel;
    String *str;
    u32 tid;

    sel = Comm_GetLocalNetId();
    if (!SpinTradeGroup_UpdateMembers(app)) {
        return FALSE;
    }
    FillWindowPixelBuffer(window, 0);
    for (i = 0; i < 5; i++) {
        if (app->members[i].profile != NULL) {
            tid = PlayerProfile_GetTrainerID_VisibleHalf(app->members[i].profile);
            PlayerName_FlatToString(app->members[i].profile, app->names[i]);
            BufferIntegerAsString(app->msgFormat, 0, tid, 5, PRINTING_MODE_LEADING_ZEROS, TRUE);
            str = ReadMsgData_ExpandPlaceholders(app->msgFormat, app->msgData, msg_0207_00001, HEAP_ID_102);
            if (sel == i) {
                AddTextPrinterParameterizedWithColor(window, 0, app->names[i], 5, i * 0x12 + 1, TEXT_SPEED_NOTRANSFER, 0x20300, NULL);
                AddTextPrinterParameterizedWithColor(window, 0, str, 0x46, i * 0x12 + 1, TEXT_SPEED_NOTRANSFER, 0x20300, NULL);
            } else {
                AddTextPrinterParameterizedWithColor(window, 0, app->names[i], 5, i * 0x12 + 1, TEXT_SPEED_NOTRANSFER, color, NULL);
                AddTextPrinterParameterizedWithColor(window, 0, str, 0x46, i * 0x12 + 1, TEXT_SPEED_NOTRANSFER, color, NULL);
            }
            String_Delete(str);
        }
    }
    CopyWindowToVram(window);
    return TRUE;
}

static void SpinTradeGroup_HandleInputDummy(SpinTradeGroupApp *app) {
#pragma unused(app)
}

static int SpinTradeGroup_CountMembers(void) {
    int i;
    int count;
    count = 0;
    i = 0;
    for (; i < 5; i++) {
        if (CommPlayerInfo_GetProfile(i)) {
            count++;
        }
    }
    return count;
}

static u32 SpinTradeGroup_GetMemberMask(void) {
    int i;
    u32 mask;
    mask = 0;
    i = 0;
    for (; i < 5; i++) {
        if (CommPlayerInfo_GetProfile(i)) {
            mask |= 1 << i;
        }
    }
    return mask;
}

static BOOL SpinTradeGroup_UpdateMembers(SpinTradeGroupApp *app) {
    int i;
    BOOL changed = FALSE;
    for (i = 0; i < 5; i++) {
        app->members[i].prevProfile = app->members[i].profile;
        app->members[i].profile = CommPlayerInfo_GetProfile(i);
        app->trainerIds[i].prev = app->trainerIds[i].cur;
        if (app->members[i].profile != NULL) {
            app->trainerIds[i].cur.f.id = PlayerProfile_GetTrainerID(app->members[i].profile);
            app->trainerIds[i].cur.f.valid = 1;
        } else {
            app->trainerIds[i].cur.f.id = 0;
            app->trainerIds[i].cur.f.valid = 0;
        }
    }
    for (i = 0; i < 5; i++) {
        if (app->members[i].prevProfile != app->members[i].profile) {
            changed = TRUE;
            if (app->members[i].profile == NULL) {
                app->memberStates[i] = 3;
            } else {
                app->memberStates[i] = 1;
            }
        } else if (app->trainerIds[i].cur.raw != app->trainerIds[i].prev.raw) {
            changed = TRUE;
            if (app->trainerIds[i].cur.f.valid == 0) {
                app->memberStates[i] = 3;
            } else {
                app->memberStates[i] = 1;
            }
        }
    }
    return changed;
}

static void SpinTradeGroup_PrintMessage(SpinTradeGroupApp *app, int msgId, int instant) {
    String *str = String_New(0xB4, HEAP_ID_102);
    ReadMsgDataIntoString(app->msgData, msgId, str);
    StringExpandPlaceholders(app->msgFormat, app->msgString, str);
    String_Delete(str);
    FillWindowPixelBuffer(&app->msgWindow, 0xF);
    DrawFrameAndWindow2(&app->msgWindow, FALSE, 1, 0xA);
    if (instant == 0) {
        app->printerId = AddTextPrinterParameterized(&app->msgWindow, 1, app->msgString, 0, 0, SpinTradeGroup_GetTextSpeed(app), NULL);
    } else {
        AddTextPrinterParameterized(&app->msgWindow, 1, app->msgString, 0, 0, TEXT_SPEED_INSTANT, NULL);
        app->printerId = 0xFF;
    }
}

static BOOL SpinTradeGroup_IsPrinterDone(u32 printerId) {
    if (printerId == 0xFF) {
        return TRUE;
    }
    if (!TextPrinterCheckActive(printerId)) {
        return TRUE;
    }
    return FALSE;
}

static void SpinTradeGroup_ClearMessage(SpinTradeGroupApp *app) {
    ClearFrameAndWindow2(&app->msgWindow, FALSE);
}

static void SpinTradeGroup_UpdateAvatars(SpinTradeGroupApp *app) {
    int i;
    int played = 0;
    for (i = 0; i < 5; i++) {
        switch (app->memberStates[i]) {
        case 0:
            break;
        case 1: {
            int gender;
            int avatar;
            GF_ASSERT(app->members[i].profile != NULL);
            gender = PlayerProfile_GetTrainerGender(app->members[i].profile);
            avatar = PlayerProfile_GetAvatar(app->members[i].profile);
            if (i == Comm_GetLocalNetId()) {
                Sprite_SetAnimCtrlSeq(app->avatars[i], gender * 2 + 0x26);
            } else {
                SpinTradeGroup_LoadAvatar(app->chars, app->pltts, i, avatar, gender);
                Sprite_SetAnimCtrlSeq(app->avatars[i], i * 2 + 0x1B);
            }
            Sprite_SetDrawFlag(app->avatars[i], TRUE);
            app->memberStates[i] = 2;
            played = 1;
            break;
        }
        case 2:
            break;
        case 3:
            if (i == Comm_GetLocalNetId()) {
                Sprite_SetAnimCtrlSeq(app->avatars[i], PlayerProfile_GetTrainerGender(app->members[i].profile) * 2 + 0x27);
            } else {
                Sprite_SetAnimCtrlSeq(app->avatars[i], i * 2 + 0x1C);
            }
            app->memberStates[i] = 0;
            break;
        }
    }
    if (played) {
        PlaySE(SEQ_SE_DP_TELE2);
    }
}

static void SpinTradeGroup_LoadAvatarGraphics(SpinTradeGroupApp *app, NARC *narc) {
    app->plttFiles[0] = GfGfxLoader_GetPlttData(NARC_a_1_0_0, 9, &app->pltts[0], HEAP_ID_102);
    app->plttFiles[1] = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 7, &app->pltts[1], HEAP_ID_102);
    app->charFiles[0] = GfGfxLoader_GetCharData(NARC_a_1_0_0, 0x2B, TRUE, &app->chars[0], HEAP_ID_102);
    app->charFiles[1] = GfGfxLoader_GetCharDataFromOpenNarc(narc, 9, TRUE, &app->chars[1], HEAP_ID_102);
}

static void SpinTradeGroup_LoadAvatar(NNSG2dCharacterData **chars, NNSG2dPaletteData **pltts, int slot, int avatar, int gender) {
    int idx = SpriteToUnionRoomAvatarIdx(gender, avatar);
    void *pltt = pltts[1]->pRawData;
    GX_LoadOBJ((u8 *)chars[1]->pRawData + idx * 0x600, sSpinTradeGroupAvatarCharOffsets[slot], 0x600);
    GX_LoadOBJPltt((u8 *)pltt + idx * 0x20, (slot + 7) * 0x20, 0x20);
}

static void SpinTradeGroup_FreeAvatarGraphics(SpinTradeGroupApp *app) {
    Heap_Free(app->plttFiles[0]);
    Heap_Free(app->plttFiles[1]);
    Heap_Free(app->charFiles[0]);
    Heap_Free(app->charFiles[1]);
}

static int SpinTradeGroup_GetTextSpeed(SpinTradeGroupApp *app) {
#pragma unused(app)
    return 1;
}

static void SpinTradeGroup_SetMaxConnections(SpinTradeGroupApp *app, int extraEntries) {
    if (Comm_GetLocalNetId() == 0) {
        if (extraEntries == -1) {
            CommState_SetMaxEntries(1);
        } else {
            int maxEntries = extraEntries + Comm_CountConnected();
            if (maxEntries > 5) {
                maxEntries = 5;
            }
            CommState_SetMaxEntries(maxEntries);
        }
        if (extraEntries == -1) {
            app->maxEntriesMode = 2;
        } else if (extraEntries == 0) {
            app->maxEntriesMode = 1;
        } else {
            app->maxEntriesMode = 0;
        }
    }
}

static int SpinTradeGroup_CheckMembers(SpinTradeGroupApp *app, int extraEntries) {
    int memberCount = SpinTradeGroup_CountMembers();
    if (memberCount > (int)app->menu->participantCount) {
        u8 menuOpen = 1;
        SpinTradeLink_SendCommand(app->menu, SPIN_TRADE_CMD_LEADER_MENU_STATE, &menuOpen, 1);
        app->joinPending = 1;
    } else {
        app->joinPending = 0;
    }
    if (memberCount == (int)app->lastMemberCount) {
        return 1;
    }
    switch (memberCount) {
    case 1:
        if ((int)Comm_CountConnected() > 1 || Wireless_GetConnectedBitmap() > 1) {
            return 1;
        }
        app->subState = SPIN_TRADE_GROUP_STATE_SHOW_MEMBER_DROPPED;
        SpinTradeGroup_SetMaxConnections(app, -1);
        if (app->yesNoMenu != NULL) {
            Clear2dMenuWindowAndDelete(app->yesNoMenu, HEAP_ID_102);
            app->yesNoMenu = NULL;
        }
        return 2;
    case 2:
    case 3:
    case 4:
        UnionRoom_SetBeaconActivity(UNION_ACTIVITY_SPIN_TRADE_RECRUIT);
        if (memberCount < (int)app->lastMemberCount) {
            switch (app->maxEntriesMode) {
            case 0:
                SpinTradeGroup_SetMaxConnections(app, extraEntries);
                break;
            case 1:
                SpinTradeGroup_SetMaxConnections(app, 0);
                break;
            }
            app->menu->participantCount = Comm_CountConnected();
        }
        break;
    case 5:
        UnionRoom_SetBeaconActivity(UNION_ACTIVITY_SPIN_TRADE);
        SpinTradeGroup_SetMaxConnections(app, extraEntries);
        break;
    }
    app->lastMemberCount = SpinTradeGroup_CountMembers();
    return 1;
}

static void SpinTradeGroup_SaveDummy(SaveData *saveData, u8 *buffer) {
#pragma unused(saveData)
#pragma unused(buffer)
}
