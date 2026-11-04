#include "record_mixing/record_mixing.h"

#include "global.h"

#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0422.h"
#include "record_mixing/record_mixing_exchange.h"
#include "record_mixing/record_mixing_internal.h"

#include "assert.h"
#include "bg_window.h"
#include "comm_state.h"
#include "comm_state_internal.h"
#include "communication_core.h"
#include "communication_player_state.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "link_synchronization.h"
#include "math_util.h"
#include "message_format.h"
#include "msgdata.h"
#include "oam_manager.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "player_data.h"
#include "pm_string.h"
#include "render_window.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "sound_system.h"
#include "sprite.h"
#include "sprite_resource.h"
#include "sprite_resource_header.h"
#include "sprite_transfer.h"
#include "string_util.h"
#include "sys_task_api.h"
#include "system.h"
#include "text.h"
#include "touchpad.h"
#include "touchscreen.h"
#include "union_room_avatar.h"
#include "union_room_objects.h"
#include "union_room_talk.h"
#include "vram_transfer_manager.h"
#include "wireless_manager.h"
#include "wireless_status_icon.h"
#include "yes_no_prompt.h"

enum RecordMixingInitState {
    RECORD_MIXING_INIT_SETUP,
    RECORD_MIXING_INIT_DONE,
};

enum RecordMixingMainState {
    RECORD_MIXING_MAIN_WAIT_FADE_IN,
    RECORD_MIXING_MAIN_RUN_GROUP,
    RECORD_MIXING_MAIN_RUN,
    RECORD_MIXING_MAIN_WAIT_FADE_OUT,
};

enum RecordMixingMemberState {
    RECORD_MIXING_MEMBER_NONE,
    RECORD_MIXING_MEMBER_APPEAR,
    RECORD_MIXING_MEMBER_SHOWN,
    RECORD_MIXING_MEMBER_LEAVE,
};

enum RecordMixingState {
    RECORD_MIXING_STATE_PRINT_GROUP_PROMPT,
    RECORD_MIXING_STATE_WAIT_TEXT_THEN_RESET_MENU,
    RECORD_MIXING_STATE_RESET_LEADER_MENU_STATE,
    RECORD_MIXING_STATE_HANDLE_GROUP_MENU,
    RECORD_MIXING_STATE_SHOW_CANCEL_YES_NO,
    RECORD_MIXING_STATE_HANDLE_CANCEL_YES_NO,
    RECORD_MIXING_STATE_WAIT_LEAVE_REPLY,
    RECORD_MIXING_STATE_SEND_LEAVE,
    RECORD_MIXING_STATE_ABORT_LEAVE,
    RECORD_MIXING_STATE_PRINT_CANCELED,
    RECORD_MIXING_STATE_FADE_OUT_AFTER_DELAY,
    RECORD_MIXING_STATE_SHOW_DISBAND_YES_NO,
    RECORD_MIXING_STATE_HANDLE_DISBAND_YES_NO,
    RECORD_MIXING_STATE_PRINT_DISBAND,
    RECORD_MIXING_STATE_WAIT_DISBAND,
    RECORD_MIXING_STATE_START_EXIT_SYNC,
    RECORD_MIXING_STATE_WAIT_EXIT_SYNC,
    RECORD_MIXING_STATE_PRINT_MEMBER_UNAVAILABLE,
    RECORD_MIXING_STATE_WAIT_MEMBER_UNAVAILABLE,
    RECORD_MIXING_STATE_PRINT_MEMBER_LEFT,
    RECORD_MIXING_STATE_START_MEMBER_LEFT_WAIT,
    RECORD_MIXING_STATE_WAIT_MEMBER_LEFT,
    RECORD_MIXING_STATE_SHOW_CONFIRM_YES_NO,
    RECORD_MIXING_STATE_HANDLE_CONFIRM_YES_NO,
    RECORD_MIXING_STATE_SEND_START_MIXING,
    RECORD_MIXING_STATE_WAIT_RECORDS,
    RECORD_MIXING_STATE_MERGE_RECORDS,
    RECORD_MIXING_STATE_START_SAVE,
    RECORD_MIXING_STATE_SAVE,
    RECORD_MIXING_STATE_WAIT_AFTER_SAVE,
    RECORD_MIXING_STATE_WAIT_TEXT,
};

// One step of the player sprite flash; a palette of 0xFF restarts the cycle.
typedef struct RecordMixingFlashFrame {
    u8 duration;
    u8 palette;
} RecordMixingFlashFrame;


typedef int (*RecordMixingStateFunc)(RecordMixingApp *app, int state);

static void RecordMixing_VBlankTask(SysTask *task, RecordMixingApp *app);
static void RecordMixing_VBlankCB(RecordMixingApp *app);
static void RecordMixing_SetGfxBanks(void);
static void RecordMixing_InitBgs(BgConfig *bgConfig);
static void RecordMixing_InitResources(RecordMixingApp *app, NARC *narc);
static void RecordMixing_FreeResources(RecordMixingApp *app);
static void RecordMixing_FreeBgs(BgConfig *bgConfig);
static void RecordMixing_LoadBgGraphics(RecordMixingApp *app, NARC *narc);
static void RecordMixing_FreeButtonScreen(RecordMixingApp *app);
static void RecordMixing_InitObjTransfer(void);
static void RecordMixing_InitSpriteGraphics(RecordMixingApp *app, NARC *narc);
static void RecordMixing_CreateSprites(RecordMixingApp *app);
static void RecordMixing_AddWindows(RecordMixingApp *app, OverlayManager *unused);
static void RecordMixing_PrintCenteredString(Window *window, String *string, int textSpeed);
static void RecordMixing_RemoveWindows(RecordMixingApp *app);
static int RecordMixing_State_PrintGroupPrompt(RecordMixingApp *app, int state);
static int RecordMixing_State_HandleGroupMenu(RecordMixingApp *app, int state);
static BOOL RecordMixing_UpdateMenuInputState(RecordMixingApp *app);
static void RecordMixing_HandleInput(RecordMixingApp *app);
static void RecordMixing_UpdateDummy(RecordMixingApp *app);
static int RecordMixing_State_WaitTextThenResetMenu(RecordMixingApp *app, int state);
static void RecordMixing_SetStateAfterText(RecordMixingApp *app, int nextState);
static int RecordMixing_State_WaitText(RecordMixingApp *app, int state);
static int RecordMixing_State_ResetLeaderMenuState(RecordMixingApp *app, int state);
static void RecordMixing_ShowYesNo(RecordMixingApp *app);
static void RecordMixing_HideYesNo(RecordMixingApp *app);
static int RecordMixing_State_ShowCancelYesNo(RecordMixingApp *app, int state);
static int RecordMixing_State_HandleCancelYesNo(RecordMixingApp *app, int state);
static int RecordMixing_State_WaitLeaveReply(RecordMixingApp *app, int state);
static int RecordMixing_State_SendLeave(RecordMixingApp *app, int state);
static int RecordMixing_State_ShowConfirmYesNo(RecordMixingApp *app, int state);
static int RecordMixing_State_HandleConfirmYesNo(RecordMixingApp *app, int state);
static int RecordMixing_State_SendStartMixing(RecordMixingApp *app, int state);
static int RecordMixing_State_WaitRecords(RecordMixingApp *app, int state);
static int RecordMixing_State_MergeRecords(RecordMixingApp *app, int state);
static int RecordMixing_State_StartSave(RecordMixingApp *app, int state);
static int RecordMixing_State_Save(RecordMixingApp *app, int state);
static int RecordMixing_State_WaitAfterSave(RecordMixingApp *app, int state);
static int RecordMixing_State_PrintCanceled(RecordMixingApp *app, int state);
static int RecordMixing_State_FadeOutAfterDelay(RecordMixingApp *app, int state);
static int RecordMixing_State_ShowDisbandYesNo(RecordMixingApp *app, int state);
static int RecordMixing_State_HandleDisbandYesNo(RecordMixingApp *app, int state);
static int RecordMixing_State_PrintDisband(RecordMixingApp *app, int state);
static int RecordMixing_State_WaitDisband(RecordMixingApp *app, int state);
static int RecordMixing_State_StartExitSync(RecordMixingApp *app, int state);
static int RecordMixing_State_WaitExitSync(RecordMixingApp *app, int state);
static int RecordMixing_State_PrintMemberUnavailable(RecordMixingApp *app, int state);
static int RecordMixing_State_WaitMemberUnavailable(RecordMixingApp *app, int state);
static int RecordMixing_State_PrintMemberLeft(RecordMixingApp *app, int state);
static int RecordMixing_State_StartMemberLeftWait(RecordMixingApp *app, int state);
static int RecordMixing_State_WaitMemberLeft(RecordMixingApp *app, int state);
static void RecordMixing_SetButtonState(RecordMixingApp *app, int button, int buttonState);
static void RecordMixing_PrintButtons(RecordMixingApp *app);
static void RecordMixing_PulsePalette(u16 *angle);
static int RecordMixing_CountProfiles(void);
static BOOL RecordMixing_PrintMemberList(Window *window, int unused, u32 color, RecordMixingApp *app);
static void RecordMixing_HandleGroupMenuDummy(RecordMixingApp *app);
static int RecordMixing_CountMembers(void);
static BOOL RecordMixing_UpdateMembers(RecordMixingApp *app);
static void RecordMixing_PrintMessage(RecordMixingApp *app, int msgId, BOOL immediate);
static BOOL RecordMixing_IsPrinterDone(u32 printerId);
static void RecordMixing_ClearMessageWindow(RecordMixingApp *app);
static void RecordMixing_UpdateMemberSprites(RecordMixingApp *app);
static void RecordMixing_LoadAvatarGraphics(RecordMixingApp *app, NARC *narc);
static void RecordMixing_LoadAvatar(NNSG2dCharacterData **charData, NNSG2dPaletteData **plttData, u32 slot, int trainerClass, int gender);
static void RecordMixing_FreeAvatarGraphics(RecordMixingApp *app);
static int RecordMixing_GetTextSpeed(RecordMixingApp *app);
static void RecordMixing_UpdateMaxEntries(RecordMixingApp *app, int index);
static int RecordMixing_LeaderUpdateMembers(RecordMixingApp *app, int index);

int RecordMixing_State_AbortLeave(RecordMixingApp *app, int state);
int RecordMixing_GetMemberCount(void);

static const u8 sRecordMixingButtonX[2] = { 16, 24 };

static const u16 sRecordMixingAvatarVramOffsets[5] = { 0x1A0, 0x7A0, 0xDA0, 0x13A0, 0x19A0 };

static const RecordMixingFlashFrame sRecordMixingFlashFrames[5] = {
    { 8,  2   },
    { 8,  3   },
    { 8,  4   },
    { 24, 0   },
    { 0,  255 },
};

static const TouchscreenHitbox sRecordMixingButtonHitboxes[3] = {
    { 160, 192, 128, 192 },
    { 160, 192, 192, 0   },
    { 255, 0,   0,   0   }
};

static const GraphicsModes sRecordMixingGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_2D,
};

static const ObjCharTransferTemplate sRecordMixingObjCharTransferTemplate = {
    .maxTasks = 20,
    .sizeMain = 0x800,
    .sizeSub = 0x800,
    .heapID = HEAP_ID_50,
};

static const u16 sRecordMixingSpritePositions[6][2] = {
    { 84,  104 },
    { 85,  72  },
    { 114, 88  },
    { 103, 117 },
    { 66,  117 },
    { 55,  88  },
};

static const BgTemplate sRecordMixingBgTemplate_Main0 = {
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

static const BgTemplate sRecordMixingBgTemplate_Sub0 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf800,
    .charBase = GX_BG_CHARBASE_0x04000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sRecordMixingBgTemplate_Sub1 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf000,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sRecordMixingBgTemplate_Main1 = {
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

static const GraphicsBanks sRecordMixingGraphicsBanks = {
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

static RecordMixingStateFunc sRecordMixingStateFuncs[31] = {
    RecordMixing_State_PrintGroupPrompt,
    RecordMixing_State_WaitTextThenResetMenu,
    RecordMixing_State_ResetLeaderMenuState,
    RecordMixing_State_HandleGroupMenu,
    RecordMixing_State_ShowCancelYesNo,
    RecordMixing_State_HandleCancelYesNo,
    RecordMixing_State_WaitLeaveReply,
    RecordMixing_State_SendLeave,
    RecordMixing_State_AbortLeave,
    RecordMixing_State_PrintCanceled,
    RecordMixing_State_FadeOutAfterDelay,
    RecordMixing_State_ShowDisbandYesNo,
    RecordMixing_State_HandleDisbandYesNo,
    RecordMixing_State_PrintDisband,
    RecordMixing_State_WaitDisband,
    RecordMixing_State_StartExitSync,
    RecordMixing_State_WaitExitSync,
    RecordMixing_State_PrintMemberUnavailable,
    RecordMixing_State_WaitMemberUnavailable,
    RecordMixing_State_PrintMemberLeft,
    RecordMixing_State_StartMemberLeftWait,
    RecordMixing_State_WaitMemberLeft,
    RecordMixing_State_ShowConfirmYesNo,
    RecordMixing_State_HandleConfirmYesNo,
    RecordMixing_State_SendStartMixing,
    RecordMixing_State_WaitRecords,
    RecordMixing_State_MergeRecords,
    RecordMixing_State_StartSave,
    RecordMixing_State_Save,
    RecordMixing_State_WaitAfterSave,
    RecordMixing_State_WaitText,
};

BOOL RecordMixing_Init(OverlayManager *man, int *state) {
    RecordMixingApp *app;
    NARC *narc;

    switch (*state) {
    case RECORD_MIXING_INIT_SETUP:
        Main_SetVBlankIntrCB(NULL, NULL);
        HBlankInterruptDisable();
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        reg_GX_DISPCNT &= ~REG_GX_DISPCNT_DISPLAY_MASK;
        reg_GXS_DB_DISPCNT &= ~REG_GXS_DB_DISPCNT_DISPLAY_MASK;
        Heap_Create(HEAP_ID_3, HEAP_ID_50, 0x41000);
        narc = NARC_New(NARC_application_record_record, HEAP_ID_50);
        app = OverlayManager_CreateAndGetData(man, sizeof(RecordMixingApp), HEAP_ID_50);
        memset(app, 0, sizeof(RecordMixingApp));
        app->bgConfig = BgConfig_Alloc(HEAP_ID_50);
        app->args = OverlayManager_GetArgs(man);
        app->saveData = app->args->saveData;
        app->menuInputState = MenuInputStateMgr_GetState(app->args->menuInputStatePtr);
        app->msgFmt = MessageFormat_New(HEAP_ID_50);
        app->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0422_bin, HEAP_ID_50);
        FontID_Alloc(4, HEAP_ID_50);
        SetKeyRepeatTimers(4, 8);
        RecordMixing_SetGfxBanks();
        RecordMixing_InitBgs(app->bgConfig);
        SetMasterBrightnessNeutral(PM_LCD_TOP);
        SetMasterBrightnessNeutral(PM_LCD_BOTTOM);
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, (enum FadeType)17, (enum FadeType)17, RGB_BLACK, 16, 1, HEAP_ID_50);
        RecordMixing_LoadBgGraphics(app, narc);
        GF_TouchpadResetSampling();
        GF_TouchpadStartSampling(2);
        Main_SetVBlankIntrCB((GFIntrCB)RecordMixing_VBlankCB, app);
        RecordMixing_InitResources(app, narc);
        RecordMixing_InitObjTransfer();
        RecordMixing_InitSpriteGraphics(app, narc);
        RecordMixing_CreateSprites(app);
        RecordMixing_AddWindows(app, man);
        RecordMixing_PrintButtons(app);
        Sound_SetSceneAndPlayBGM(0x34, 0, 0);
        GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
        RecordMixingLink_RegisterCommands(app);
        CommState_SetRecordMixingLinkMode();
        CommState_SetMaxEntries(3);
        if (!Comm_GetLocalNetId()) {
            UnionRoom_SetBeaconActivity(UNION_ACTIVITY_RECORD_MIX_RECRUIT);
        }
        WirelessStatusIcon_Create();
        RecordMixing_BuildSendBuffer(app->saveData, &app->sendBuffer);
        app->task = SysTask_CreateOnVBlankQueue((SysTaskFunc)RecordMixing_VBlankTask, app, 5);
        NARC_Delete(narc);
        (*state)++;
        break;
    case RECORD_MIXING_INIT_DONE:
        OverlayManager_GetData(man);
        *state = RECORD_MIXING_INIT_SETUP;
        return TRUE;
    }
    return FALSE;
}

BOOL RecordMixing_Main(OverlayManager *man, int *state) {
    RecordMixingApp *app = OverlayManager_GetData(man);

    if (Comm_GetLocalNetId() == 0 && app->leavingMask != 0) {
        app->leavingMask &= Wireless_GetConnectedBitmap();
    }
    switch (*state) {
    case RECORD_MIXING_MAIN_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            *state = RECORD_MIXING_MAIN_RUN_GROUP;
            if (Comm_GetLocalNetId() && RecordMixing_CountMembers() > 2) {
                Comm_SendCommand(114, NULL, 0);
            }
        }
        break;
    case RECORD_MIXING_MAIN_RUN_GROUP:
        if (sRecordMixingStateFuncs[app->state]) {
            *state = sRecordMixingStateFuncs[app->state](app, *state);
        }
        if (app->isMixing == 0) {
            RecordMixing_PrintMemberList(&app->memberListWindow, 0, 0x10300, app);
        }
        RecordMixing_UpdateMemberSprites(app);
        if (Comm_GetLocalNetId() == 0) {
            int value = RecordMixing_LeaderUpdateMembers(app, 1);
            if (*state == RECORD_MIXING_MAIN_RUN_GROUP) {
                *state = value;
            }
        }
        break;
    case RECORD_MIXING_MAIN_RUN:
        if (sRecordMixingStateFuncs[app->state]) {
            *state = sRecordMixingStateFuncs[app->state](app, *state);
        }
        break;
    case RECORD_MIXING_MAIN_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished()) {
            return TRUE;
        }
        break;
    }
    SpriteList_RenderAndAnimateSprites(app->spriteList);
    return FALSE;
}

BOOL RecordMixing_Exit(OverlayManager *man, int *state) {
    RecordMixingApp *app = OverlayManager_GetData(man);
    s32 i;

    SysTask_Destroy(app->task);
    SpriteTransfer_DeleteCharTransferTask(app->charRes);
    SpriteTransfer_DeletePlttTransferTask(app->plttRes);
    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(app->resMan[i]);
    }
    SpriteList_Delete(app->spriteList);
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    RecordMixing_RemoveWindows(app);
    RecordMixing_FreeButtonScreen(app);
    RecordMixing_FreeBgs(app->bgConfig);
    CommState_SetMaxEntries(2);
    CommState_ResumeAlternateSearch();
    UnionRoomObjects_ResetSlots(app->args->unionRoomObjects);
    GF_TouchpadStopSampling();
    FontID_Release(4);
    DestroyMsgData(app->msgData);
    MessageFormat_Delete(app->msgFmt);
    MenuInputStateMgr_SetState(app->args->menuInputStatePtr, app->menuInputState);
    RecordMixing_FreeResources(app);
    OverlayManager_FreeData(man);
    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);
    UnionRoom_SetBeaconActivity(UNION_ACTIVITY_NONE);
    Main_SetVBlankIntrCB(NULL, NULL);
    Heap_Destroy(HEAP_ID_50);
    return TRUE;
}

static void RecordMixing_VBlankTask(SysTask *task, RecordMixingApp *app) {
    RecordMixingFlash *flash = &app->flash;
    if (app->flash.active) {
        if (flash->timer > sRecordMixingFlashFrames[flash->frame].duration) {
            flash->timer = 0;
            flash->frame++;
            if (sRecordMixingFlashFrames[flash->frame].palette == 0xFF) {
                flash->frame = 0;
            }
            GX_LoadOBJPltt((u8 *)flash->pltt->pRawData + sRecordMixingFlashFrames[flash->frame].palette * 0x20, 0, 0x20);
        } else {
            app->flash.timer++;
        }
        RecordMixing_PulsePalette(&app->pulseAngle);
    }
}

static void RecordMixing_VBlankCB(RecordMixingApp *app) {
    GF_RunVramTransferTasks();
    OamManager_ApplyAndResetBuffers();
    DoScheduledBgGpuUpdates(app->bgConfig);
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static void RecordMixing_SetGfxBanks(void) {
    GraphicsBanks banks = sRecordMixingGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

static void RecordMixing_InitBgs(BgConfig *bgConfig) {
    {
        GraphicsModes modes = sRecordMixingGraphicsModes;
        SetBothScreensModesAndDisable(&modes);
    }
    {
        BgTemplate template = sRecordMixingBgTemplate_Sub0;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &template, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    }
    {
        BgTemplate template = sRecordMixingBgTemplate_Sub1;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &template, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    }
    {
        BgTemplate template = sRecordMixingBgTemplate_Main0;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &template, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    }
    {
        BgTemplate template = sRecordMixingBgTemplate_Main1;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &template, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    }
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 0x20, 0, HEAP_ID_50);
    BG_ClearCharDataRange(GF_BG_LYR_SUB_0, 0x20, 0, HEAP_ID_50);
}

static void RecordMixing_InitResources(RecordMixingApp *app, NARC *narc) {
    s32 i;

    for (i = 0; i < RECORD_MIXING_MAX_MEMBERS; i++) {
        app->memberNames[i] = String_New(8, HEAP_ID_50);
        app->members[i].cur = NULL;
        app->members[i].prev = NULL;
        app->memberKeys[i].cur.s.id = 0;
        app->memberKeys[i].cur.s.valid = 0;
        app->memberKeys[i].prev.s.id = 0;
        app->memberKeys[i].prev.s.valid = 0;
        app->memberStates[i] = RECORD_MIXING_MEMBER_NONE;
    }
    app->messageText = String_New(180, HEAP_ID_50);
    app->titleText = String_New(40, HEAP_ID_50);
    app->state = RECORD_MIXING_STATE_PRINT_GROUP_PROMPT;
    ReadMsgDataIntoString(app->msgData, msg_0422_00017, app->titleText);
    RecordMixing_LoadAvatarGraphics(app, narc);
    app->avatarPalette = UnionRoom_LoadAvatarPalette(HEAP_ID_50);
    app->flash.active = 0;
    app->flash.timer = 0;
    app->flash.frame = 0;
    app->flash.plttRaw = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 7, &app->flash.pltt, HEAP_ID_50);
    app->lastMemberCount = 0;
    app->participantCount = 2;
    app->yesNoActive = 0;
}

static void RecordMixing_FreeResources(RecordMixingApp *app) {
    s32 i;

    RecordMixing_FreeAvatarGraphics(app);
    Heap_Free(app->flash.plttRaw);
    Heap_Free(app->avatarPalette);
    for (i = 0; i < RECORD_MIXING_MAX_MEMBERS; i++) {
        String_Delete(app->memberNames[i]);
    }
    String_Delete(app->titleText);
    String_Delete(app->messageText);
}

static void RecordMixing_FreeBgs(BgConfig *bgConfig) {
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_0);
    Heap_Free(bgConfig);
}

static void RecordMixing_LoadBgGraphics(RecordMixingApp *app, NARC *narc) {
    BgConfig *bgConfig = app->bgConfig;

    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0, HEAP_ID_50);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 4, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, HEAP_ID_50);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 5, bgConfig, GF_BG_LYR_SUB_1, 0, 0, TRUE, HEAP_ID_50);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 6, bgConfig, GF_BG_LYR_SUB_1, 0, 0, TRUE, HEAP_ID_50);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 1, bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, HEAP_ID_50);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 2, bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, HEAP_ID_50);
    app->buttonScreenRaw = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 3, TRUE, &app->buttonScreen, HEAP_ID_50);
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, (enum GFPalSlotOffset)0x180, HEAP_ID_50);
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, (enum GFPalSlotOffset)0x1A0, HEAP_ID_50);
    LoadFontPal1(GF_PAL_LOCATION_SUB_BG, (enum GFPalSlotOffset)0x180, HEAP_ID_50);
    LoadFontPal0(GF_PAL_LOCATION_SUB_BG, (enum GFPalSlotOffset)0x1A0, HEAP_ID_50);
    LoadUserFrameGfx2(bgConfig, GF_BG_LYR_MAIN_0, 1, 11, Options_GetFrame(app->args->options), HEAP_ID_50);
    LoadUserFrameGfx1(bgConfig, GF_BG_LYR_MAIN_0, 31, 10, 0, HEAP_ID_50);
}

static void RecordMixing_FreeButtonScreen(RecordMixingApp *app) {
    Heap_Free(app->buttonScreenRaw);
    app->buttonScreenRaw = NULL;
}

static void RecordMixing_InitObjTransfer(void) {
    ObjCharTransferTemplate template = sRecordMixingObjCharTransferTemplate;
    ObjCharTransfer_Init(&template);
    ObjPlttTransfer_Init(20, HEAP_ID_50);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
}

static void RecordMixing_InitSpriteGraphics(RecordMixingApp *app, NARC *narc) {
    int i;
    RecordMixingApp *walk;

    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 126, 0, 32, 0, 126, 0, 32, HEAP_ID_50);
    app->spriteList = G2dRenderer_Init(30, &app->renderer, HEAP_ID_50);
    G2dRenderer_SetSubSurfaceCoords(&app->renderer, 0, FX32_CONST(256));
    i = 0;
    walk = app;
    while (i < 4) {
        walk->resMan[0] = Create2DGfxResObjMan(3, (GfGfxResType)i, HEAP_ID_50);
        i++;
        walk = (RecordMixingApp *)((u8 *)walk + 4);
    }
    app->charRes = AddCharResObjFromOpenNarc(app->resMan[GF_GFX_RES_TYPE_CHAR], narc, 8, TRUE, 2, NNS_G2D_VRAM_TYPE_2DMAIN, HEAP_ID_50);
    app->plttRes = AddPlttResObjFromOpenNarc(app->resMan[GF_GFX_RES_TYPE_PLTT], narc, 7, FALSE, 2, NNS_G2D_VRAM_TYPE_2DMAIN, 15, HEAP_ID_50);
    app->cellRes = AddCellOrAnimResObjFromOpenNarc(app->resMan[GF_GFX_RES_TYPE_CELL], narc, 9, TRUE, 2, GF_GFX_RES_TYPE_CELL, HEAP_ID_50);
    app->animRes = AddCellOrAnimResObjFromOpenNarc(app->resMan[GF_GFX_RES_TYPE_ANIM], narc, 10, TRUE, 2, GF_GFX_RES_TYPE_ANIM, HEAP_ID_50);
    SpriteTransfer_CreateCharTransferTask(app->charRes);
    SpriteTransfer_CreateExtPlttTransferTask(app->plttRes);
}

static void RecordMixing_CreateSprites(RecordMixingApp *app) {
    SpriteTemplate template;
    int i;
    const u16 *pos;
    RecordMixingApp *walk;

    CreateSpriteResourcesHeader(&app->spriteHeader, 2, 2, 2, 2, -1, -1, 0, 1, app->resMan[GF_GFX_RES_TYPE_CHAR], app->resMan[GF_GFX_RES_TYPE_PLTT], app->resMan[GF_GFX_RES_TYPE_CELL], app->resMan[GF_GFX_RES_TYPE_ANIM], NULL, NULL);
    template.spriteList = app->spriteList;
    template.header = &app->spriteHeader;
    template.position.z = 0;
    template.scale.x = FX32_ONE;
    template.scale.y = FX32_ONE;
    template.scale.z = FX32_ONE;
    template.rotation = 0;
    template.drawPriority = 1;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.heapID = HEAP_ID_50;
    template.position.x = FX32_CONST(84);
    template.position.y = FX32_CONST(104);
    app->playerSprite = Sprite_CreateAffine(&template);
    Sprite_SetAnimActiveFlag(app->playerSprite, TRUE);
    Sprite_SetDrawFlag(app->playerSprite, TRUE);
    Sprite_SetDrawPriority(app->playerSprite, 100);
    for (i = 0, pos = &sRecordMixingSpritePositions[0][0], walk = app; i < RECORD_MIXING_MAX_MEMBERS; i++, pos += 2, walk = (RecordMixingApp *)((u8 *)walk + 4)) {
        template.position.x = pos[2] << FX32_SHIFT;
        template.position.y = pos[3] << FX32_SHIFT;
        walk->memberSprites[0] = Sprite_CreateAffine(&template);
        Sprite_SetAnimActiveFlag(walk->memberSprites[0], TRUE);
        Sprite_SetAnimCtrlSeq(walk->memberSprites[0], (i - 1) * 2 + 27);
        Sprite_SetDrawFlag(walk->memberSprites[0], FALSE);
    }
    template.position.x = 24 << FX32_SHIFT;
    template.position.y = 416 << FX32_SHIFT;
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
}

static void RecordMixing_AddWindows(RecordMixingApp *app, OverlayManager *unused) {
    AddWindowParameterized(app->bgConfig, &app->messageWindow, GF_BG_LYR_MAIN_0, 2, 1, 27, 4, 12, 0x5B);
    FillWindowPixelBuffer(&app->messageWindow, 15);
    AddWindowParameterized(app->bgConfig, &app->buttonWindows[0], GF_BG_LYR_MAIN_0, 16, 21, 8, 2, 9, 0xC7);
    FillWindowPixelBuffer(&app->buttonWindows[0], 0);
    AddWindowParameterized(app->bgConfig, &app->buttonWindows[1], GF_BG_LYR_MAIN_0, 24, 21, 8, 2, 9, 0x133);
    FillWindowPixelBuffer(&app->buttonWindows[1], 0);
    AddWindowParameterized(app->bgConfig, &app->titleWindow, GF_BG_LYR_SUB_0, 3, 1, 26, 2, 9, 1);
    RecordMixing_PrintCenteredString(&app->titleWindow, app->titleText, TEXT_SPEED_INSTANT);
    AddWindowParameterized(app->bgConfig, &app->memberListWindow, GF_BG_LYR_SUB_0, 8, 7, 16, 11, 9, 0x35);
    FillWindowPixelBuffer(&app->memberListWindow, 0);
    RecordMixing_PrintMemberList(&app->memberListWindow, 0, 0x10300, app);
    app->yesNoPrompt = YesNoPrompt_Create(HEAP_ID_50);
}

static void RecordMixing_PrintCenteredString(Window *window, String *string, int textSpeed) {
    int width = FontID_String_GetWidth(1, string, 0);
    FillWindowPixelBuffer(window, 0);
    AddTextPrinterParameterizedWithColor(window, 1, string, (208 - width) / 2, 1, textSpeed, 0x10400, NULL);
}

static void RecordMixing_RemoveWindows(RecordMixingApp *app) {
    YesNoPrompt_Destroy(app->yesNoPrompt);
    RemoveWindow(&app->memberListWindow);
    RemoveWindow(&app->titleWindow);
    RemoveWindow(&app->messageWindow);
    RemoveWindow(&app->buttonWindows[0]);
    RemoveWindow(&app->buttonWindows[1]);
}

static int RecordMixing_State_PrintGroupPrompt(RecordMixingApp *app, int state) {
    CommState_SetErrorWatch(FALSE, TRUE);
    if (Comm_GetLocalNetId() == 0) {
        if (Comm_CountConnected() >= 2) {
            RecordMixing_PrintMessage(app, msg_0422_00002, FALSE);
        }
    } else {
        RecordMixing_PrintMessage(app, msg_0422_00008, FALSE);
    }
    RecordMixing_SetStateAfterText(app, RECORD_MIXING_STATE_HANDLE_GROUP_MENU);
    return state;
}

static int RecordMixing_State_HandleGroupMenu(RecordMixingApp *app, int state) {
    RecordMixing_HandleInput(app);
    if (Comm_GetLocalNetId() == 0) {
        if (RecordMixing_CountProfiles() != 1) {
            RecordMixing_HandleGroupMenuDummy(app);
        }
    } else {
        RecordMixing_HandleGroupMenuDummy(app);
    }
    return state;
}

static BOOL RecordMixing_UpdateMenuInputState(RecordMixingApp *app) {
    if (app->menuInputState == MENU_INPUT_STATE_TOUCH) {
        if (System_GetTouchHeld()) {
            return FALSE;
        }
        if (gSystem.heldKeys != 0) {
            app->menuInputState = MENU_INPUT_STATE_BUTTONS;
            return TRUE;
        }
    } else {
        if (gSystem.heldKeys != 0) {
            return FALSE;
        }
        if (System_GetTouchHeld()) {
            app->menuInputState = MENU_INPUT_STATE_TOUCH;
            return FALSE;
        }
    }
    return FALSE;
}

static void RecordMixing_HandleInput(RecordMixingApp *app) {
    u8 button = 0;

    struct {
        u8 send[3];
        u16 pixel;
    } packet;

    int index;

    RecordMixing_UpdateMenuInputState(app);
    index = TouchscreenHitbox_FindRectAtTouchNew(sRecordMixingButtonHitboxes);
    packet.pixel = 0xFFD5;
    if (index != TOUCH_MENU_NO_INPUT && DoesPixelAtScreenXYMatchPtrVal(app->bgConfig, GF_BG_LYR_MAIN_1, gSystem.touchX, gSystem.touchY, &packet.pixel)) {
        button = index + 1;
    }
    if ((gSystem.newKeys & PAD_BUTTON_A) || button == 1) {
        if (!Comm_GetLocalNetId()) {
            if (app->participantCount == RecordMixing_CountMembers() && app->leavingMask == 0) {
                packet.send[2] = 1;
                RecordMixing_PrintMessage(app, msg_0422_00003, FALSE);
                RecordMixing_SetStateAfterText(app, RECORD_MIXING_STATE_SHOW_CONFIRM_YES_NO);
                Comm_SendCommand(117, &packet.send[2], 1);
                RecordMixing_UpdateMaxEntries(app, 0);
                PlaySE(SEQ_SE_DP_SELECT);
                RecordMixing_SetButtonState(app, 0, 1);
                ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_1);
            } else {
                PlaySE(SEQ_SE_DP_CUSTOM06);
            }
        }
    } else if ((gSystem.newKeys & PAD_BUTTON_B) || button == 2) {
        if (Comm_GetLocalNetId()) {
            if (app->leaderJoinPending == 0) {
                RecordMixing_PrintMessage(app, msg_0422_00004, FALSE);
                RecordMixing_SetStateAfterText(app, RECORD_MIXING_STATE_SHOW_CANCEL_YES_NO);
                PlaySE(SEQ_SE_GS_GEARCANCEL);
            } else if (app->buttonHighlightTimer < 0) {
                app->buttonHighlightTimer = 2;
                PlaySE(SEQ_SE_DP_CUSTOM06);
            }
        } else {
            if (app->participantCount == Comm_CountConnected() && app->leavingMask == 0) {
                packet.send[1] = 1;
                RecordMixing_PrintMessage(app, msg_0422_00004, FALSE);
                RecordMixing_SetStateAfterText(app, RECORD_MIXING_STATE_SHOW_CANCEL_YES_NO);
                Comm_SendCommand(117, &packet.send[1], 1);
                RecordMixing_UpdateMaxEntries(app, 0);
                PlaySE(SEQ_SE_GS_GEARCANCEL);
                RecordMixing_SetButtonState(app, 1, 1);
                ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_1);
            } else {
                PlaySE(SEQ_SE_DP_CUSTOM06);
            }
        }
    } else if (app->joinPending == 0 && !Comm_GetLocalNetId() && app->participantCount == Comm_CountConnected()) {
        packet.send[0] = 0;
        Comm_SendCommand(117, packet.send, 1);
    }
    if (app->buttonHighlightTimer >= 0) {
        app->buttonHighlightTimer--;
    }
    if (app->buttonHighlightTimer == 0) {
        RecordMixing_SetButtonState(app, 1, 0);
        ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_1);
    }
}

static void RecordMixing_UpdateDummy(RecordMixingApp *app) {
}

static int RecordMixing_State_WaitTextThenResetMenu(RecordMixingApp *app, int state) {
    RecordMixing_SetStateAfterText(app, RECORD_MIXING_STATE_RESET_LEADER_MENU_STATE);
    RecordMixing_UpdateDummy(app);
    return state;
}

static void RecordMixing_SetStateAfterText(RecordMixingApp *app, int nextState) {
    app->state = RECORD_MIXING_STATE_WAIT_TEXT;
    app->nextState = nextState;
}

static int RecordMixing_State_WaitText(RecordMixingApp *app, int state) {
    if (RecordMixing_IsPrinterDone(app->printerId)) {
        app->state = app->nextState;
        if (app->nextState == RECORD_MIXING_STATE_HANDLE_GROUP_MENU) {
            if (Comm_GetLocalNetId() == 0) {
                RecordMixing_SetButtonState(app, 0, 0);
            }
            app->buttonHighlightTimer = -1;
            RecordMixing_SetButtonState(app, 1, 0);
            ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_1);
        }
    }
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_ResetLeaderMenuState(RecordMixingApp *app, int state) {
    u32 data;

    if (Comm_GetLocalNetId() == 0) {
        data = 0;
        Comm_SendCommand(117, &data, 1);
    }
    app->state = RECORD_MIXING_STATE_HANDLE_GROUP_MENU;
    RecordMixing_UpdateDummy(app);
    return state;
}

static void RecordMixing_ShowYesNo(RecordMixingApp *app) {
    YesNoPromptTemplate template;

    MI_CpuFill8(&template, 0, sizeof(template));
    template.bgConfig = app->bgConfig;
    template.bgId = GF_BG_LYR_MAIN_0;
    template.tileStart = 31;
    template.plttSlot = 14;
    template.x = 25;
    template.y = 6;
    template.ignoreTouchFlag = app->menuInputState;
    template.initialCursorPos = 0;
    YesNoPrompt_InitFromTemplate(app->yesNoPrompt, &template);
    app->yesNoActive = 1;
    if (Comm_GetLocalNetId() == 0) {
        RecordMixing_SetButtonState(app, 0, 2);
    }
    RecordMixing_SetButtonState(app, 1, 2);
    ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_1);
}

static void RecordMixing_HideYesNo(RecordMixingApp *app) {
    if (app->yesNoActive != 0) {
        app->menuInputState = YesNoPrompt_IsInTouchMode(app->yesNoPrompt);
        YesNoPrompt_Reset(app->yesNoPrompt);
        app->yesNoActive = 0;
        if (Comm_GetLocalNetId() == 0) {
            RecordMixing_SetButtonState(app, 0, 0);
        }
        app->buttonHighlightTimer = -1;
        RecordMixing_SetButtonState(app, 1, 0);
        ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_1);
    }
}

static int RecordMixing_State_ShowCancelYesNo(RecordMixingApp *app, int state) {
    RecordMixing_ShowYesNo(app);
    app->state = RECORD_MIXING_STATE_HANDLE_CANCEL_YES_NO;
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_HandleCancelYesNo(RecordMixingApp *app, int state) {
    u32 noData;
    u8 data[4];
    YesNoResponse input;

    if (Comm_GetLocalNetId() != 0) {
        if (app->leaderJoinPending != 0) {
            if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B | PAD_KEY_UP | PAD_KEY_DOWN)) {
                PlaySE(SEQ_SE_DP_CUSTOM06);
            }
            RecordMixing_UpdateDummy(app);
            return state;
        }
    } else {
        if (app->leavingMask != 0) {
            if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B | PAD_KEY_UP | PAD_KEY_DOWN)) {
                PlaySE(SEQ_SE_DP_CUSTOM06);
            }
            RecordMixing_UpdateDummy(app);
            return state;
        }
    }
    if (RecordMixing_CountMembers() != Comm_CountConnected()) {
        RecordMixing_UpdateDummy(app);
        return state;
    }
    input = YesNoPrompt_HandleInput(app->yesNoPrompt);
    if (input != YESNORESPONSE_WAIT) {
        if (input == YESNORESPONSE_NO) {
            if (Comm_GetLocalNetId() == 0) {
                noData = 0;
                Comm_SendCommand(117, &noData, 1);
                RecordMixing_UpdateMaxEntries(app, 1);
            }
            RecordMixing_SetStateAfterText(app, RECORD_MIXING_STATE_PRINT_GROUP_PROMPT);
        } else if (Comm_GetLocalNetId() == 0) {
            RecordMixing_SetStateAfterText(app, RECORD_MIXING_STATE_SHOW_DISBAND_YES_NO);
            RecordMixing_PrintMessage(app, msg_0422_00014, FALSE);
        } else {
            MI_CpuFill8(data, 0, 4);
            data[2] = 0;
            data[0] = Comm_GetLocalNetId();
            app->leaveRequested = 1;
            app->leaveWaitFrames = 0;
            app->state = RECORD_MIXING_STATE_WAIT_LEAVE_REPLY;
            Comm_SendCommand(112, data, 4);
        }
        RecordMixing_HideYesNo(app);
    }
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_WaitLeaveReply(RecordMixingApp *app, int state) {
    app->leaveWaitFrames = 0;
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_SendLeave(RecordMixingApp *app, int state) {
    u8 data[4];

    if (app->assignedCount != Comm_CountConnected() || app->assignedCount != RecordMixing_CountMembers()) {
        app->leaveWaitFrames = 0;
        app->state = RECORD_MIXING_STATE_ABORT_LEAVE;
        RecordMixing_UpdateDummy(app);
        return state;
    }
    app->leaveWaitFrames++;
    if (app->leaveWaitFrames > 30) {
        MI_CpuFill8(data, 0, 4);
        data[2] = 1;
        data[0] = Comm_GetLocalNetId();
        Comm_SendCommand(112, data, 4);
        app->leaveWaitFrames = 0;
        app->state = RECORD_MIXING_STATE_PRINT_CANCELED;
    }
    RecordMixing_UpdateDummy(app);
    return state;
}

int RecordMixing_State_AbortLeave(RecordMixingApp *app, int state) {
    app->leaveRequested = 0;
    RecordMixing_SetStateAfterText(app, RECORD_MIXING_STATE_PRINT_GROUP_PROMPT);
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_ShowConfirmYesNo(RecordMixingApp *app, int state) {
    RecordMixing_ShowYesNo(app);
    app->state = RECORD_MIXING_STATE_HANDLE_CONFIRM_YES_NO;
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_HandleConfirmYesNo(RecordMixingApp *app, int state) {
    u32 data;
    YesNoResponse input;

    if (app->participantCount != RecordMixing_CountMembers() || app->leavingMask != 0) {
        if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B | PAD_KEY_UP | PAD_KEY_DOWN)) {
            PlaySE(SEQ_SE_DP_CUSTOM06);
        }
        RecordMixing_UpdateDummy(app);
        return state;
    }
    input = YesNoPrompt_HandleInput(app->yesNoPrompt);
    if (input != YESNORESPONSE_WAIT) {
        RecordMixing_HideYesNo(app);
        if (input == YESNORESPONSE_NO) {
            data = 0;
            Comm_SendCommand(117, &data, 1);
            RecordMixing_UpdateMaxEntries(app, 1);
            RecordMixing_SetStateAfterText(app, RECORD_MIXING_STATE_PRINT_GROUP_PROMPT);
        } else {
            RecordMixing_SetButtonState(app, 1, 2);
            RecordMixing_SetButtonState(app, 0, 2);
            if (Comm_GetLocalNetId() == 0) {
                app->state = RECORD_MIXING_STATE_SEND_START_MIXING;
                app->startMemberCount = RecordMixing_CountMembers();
            } else {
                GF_ASSERT(FALSE);
            }
        }
    }
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_SendStartMixing(RecordMixingApp *app, int state) {
    if (app->startMixingSent == 0 && Comm_SendCommand(115, NULL, 0) == TRUE) {
        app->startMixingSent = 1;
    }
    return state;
}

void RecordMixing_StartFlash(RecordMixingApp *app) {
    ReadMsgDataIntoString(app->msgData, msg_0422_00018, app->titleText);
    RecordMixing_PrintCenteredString(&app->titleWindow, app->titleText, TEXT_SPEED_INSTANT);
    Sprite_SetAnimCtrlSeq(app->playerSprite, 37);
    app->flash.active = 1;
}

static int RecordMixing_State_WaitRecords(RecordMixingApp *app, int state) {
    if (Comm_GetLocalNetId() == 0) {
        Comm_CountConnected();
    }
    if (app->recordsReceived == Comm_CountConnected()) {
        app->state = RECORD_MIXING_STATE_MERGE_RECORDS;
    }
    return state;
}

static int RecordMixing_State_MergeRecords(RecordMixingApp *app, int state) {
    RecordMixing_MergeReceivedRecords(app->saveData, app->receiveBuffers);
    app->state = RECORD_MIXING_STATE_START_SAVE;
    return state;
}

static int RecordMixing_State_StartSave(RecordMixingApp *app, int state) {
    gSystem.softResetDisabled = TRUE;
    GameStats_AddScore(app->args->gameStats, SCORE_EVENT_RECORDS_MIXED);
    Comm_InitSyncedSave(&app->saveState);
    app->state = RECORD_MIXING_STATE_SAVE;
    return state;
}

static int RecordMixing_State_Save(RecordMixingApp *app, int state) {
    if (Comm_GetLocalNetId() == 0) {
        Comm_CountConnected();
    }
    if (Comm_SyncedSave(app->args->saveData, 2, &app->saveState)) {
        StopSE(SEQ_SE_DP_F209, 8);
        RecordMixing_PrintMessage(app, msg_0422_00013, FALSE);
        RecordMixing_SetStateAfterText(app, RECORD_MIXING_STATE_WAIT_AFTER_SAVE);
        Sprite_SetAnimCtrlSeq(app->playerSprite, 0);
        app->flash.active = 0;
        app->counter = 0;
        gSystem.softResetDisabled = FALSE;
        app->isMixing = 0;
    }
    return state;
}

static int RecordMixing_State_WaitAfterSave(RecordMixingApp *app, int state) {
    if (app->counter++ > 60) {
        app->state = RECORD_MIXING_STATE_START_EXIT_SYNC;
    }
    return state;
}

static int RecordMixing_State_PrintCanceled(RecordMixingApp *app, int state) {
    RecordMixing_PrintMessage(app, msg_0422_00005, FALSE);
    RecordMixing_SetStateAfterText(app, RECORD_MIXING_STATE_FADE_OUT_AFTER_DELAY);
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_FadeOutAfterDelay(RecordMixingApp *app, int state) {
    app->counter++;
    if (app->counter > 60) {
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, (enum FadeType)16, (enum FadeType)16, RGB_BLACK, 16, 1, HEAP_ID_50);
        state = RECORD_MIXING_MAIN_WAIT_FADE_OUT;
    }
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_ShowDisbandYesNo(RecordMixingApp *app, int state) {
    RecordMixing_ShowYesNo(app);
    app->state = RECORD_MIXING_STATE_HANDLE_DISBAND_YES_NO;
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_HandleDisbandYesNo(RecordMixingApp *app, int state) {
    YesNoResponse input;
    int data;

    if (app->participantCount != RecordMixing_CountMembers() || app->leavingMask) {
        if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B | PAD_KEY_UP | PAD_KEY_DOWN)) {
            PlaySE(SEQ_SE_DP_CUSTOM06);
        }
        RecordMixing_UpdateDummy(app);
        return state;
    }
    input = YesNoPrompt_HandleInput(app->yesNoPrompt);
    if (input) {
        if (input == YESNORESPONSE_NO) {
            data = 0;
            app->state = RECORD_MIXING_STATE_PRINT_GROUP_PROMPT;
            Comm_SendCommand(117, &data, 1);
            RecordMixing_UpdateMaxEntries(app, 1);
        } else {
            app->state = RECORD_MIXING_STATE_PRINT_DISBAND;
            Comm_SendCommand(113, NULL, 0);
            BufferPlayersName(app->msgFmt, 0, CommPlayerInfo_GetProfile(0));
        }
        RecordMixing_HideYesNo(app);
    }
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_PrintDisband(RecordMixingApp *app, int state) {
    if (Comm_GetLocalNetId() == 0) {
        RecordMixing_PrintMessage(app, msg_0422_00005, FALSE);
    } else {
        PlayerProfile *leader = CommPlayerInfo_GetProfile(0);
        BufferPlayersName(app->msgFmt, 0, leader);
        RecordMixing_PrintMessage(app, msg_0422_00016, FALSE);
    }
    RecordMixing_SetStateAfterText(app, RECORD_MIXING_STATE_WAIT_DISBAND);
    app->counter = 0;
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_WaitDisband(RecordMixingApp *app, int state) {
    app->counter++;
    if (app->counter > 45) {
        app->state = RECORD_MIXING_STATE_START_EXIT_SYNC;
    }
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_StartExitSync(RecordMixingApp *app, int state) {
    LinkSync_StartSync(201);
    app->state = RECORD_MIXING_STATE_WAIT_EXIT_SYNC;
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_WaitExitSync(RecordMixingApp *app, int state) {
    if (LinkSync_IsSynced(201)) {
        CommState_SetErrorWatch(FALSE, FALSE);
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, (enum FadeType)16, (enum FadeType)16, RGB_BLACK, 16, 1, HEAP_ID_50);
        state = RECORD_MIXING_MAIN_WAIT_FADE_OUT;
    }
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_PrintMemberUnavailable(RecordMixingApp *app, int state) {
    if (RecordMixing_IsPrinterDone(app->printerId)) {
        RecordMixing_PrintMessage(app, msg_0422_00009, FALSE);
    }
    app->state = RECORD_MIXING_STATE_WAIT_MEMBER_UNAVAILABLE;
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_WaitMemberUnavailable(RecordMixingApp *app, int state) {
    if (RecordMixing_IsPrinterDone(app->printerId)) {
        app->state = RECORD_MIXING_STATE_FADE_OUT_AFTER_DELAY;
    }
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_PrintMemberLeft(RecordMixingApp *app, int state) {
    if (Comm_GetLocalNetId() == 0) {
        RecordMixing_SetButtonState(app, 0, 2);
    }
    app->buttonHighlightTimer = -1;
    RecordMixing_SetButtonState(app, 1, 2);
    ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_1);
    if (app->printerId != 0xFF && !RecordMixing_IsPrinterDone(app->printerId)) {
        RemoveTextPrinter(app->printerId);
    }
    RecordMixing_PrintMessage(app, msg_0422_00015, TRUE);
    app->state = RECORD_MIXING_STATE_START_MEMBER_LEFT_WAIT;
    if (Comm_GetLocalNetId() == 0) {
        RecordMixing_UpdateMaxEntries(app, 0);
    }
    app->leaveConnectedCount = Comm_CountConnected();
    app->leaveTimeout = 300;
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_StartMemberLeftWait(RecordMixingApp *app, int state) {
    if (app->leaveConnectedCount != 0) {
        int connected = Comm_CountConnected();
        if (app->leaveConnectedCount != connected) {
            app->leaveConnectedCount = 0;
        }
    }
    app->state = RECORD_MIXING_STATE_WAIT_MEMBER_LEFT;
    app->counter = 0;
    RecordMixing_UpdateDummy(app);
    return state;
}

static int RecordMixing_State_WaitMemberLeft(RecordMixingApp *app, int state) {
    if (app->leaveConnectedCount != 0) {
        int connected = Comm_CountConnected();
        if (app->leaveConnectedCount != connected) {
            app->leaveConnectedCount = 0;
        }
    }
    app->leaveTimeout--;
    if (app->leaveTimeout < 0) {
        app->leaveConnectedCount = 0;
    }
    app->counter++;
    if (app->counter > 60 && app->leaveConnectedCount == 0) {
        app->state = RECORD_MIXING_STATE_PRINT_GROUP_PROMPT;
        if (Comm_GetLocalNetId() == 0) {
            RecordMixing_UpdateMaxEntries(app, 1);
        }
    }
    RecordMixing_UpdateDummy(app);
    return state;
}

void RecordMixing_SetStateFromLink(RecordMixingApp *app, int state, int netId) {
    switch (state) {
    case RECORD_MIXING_STATE_RESET_LEADER_MENU_STATE:
        RecordMixing_ClearMessageWindow(app);
        break;
    case RECORD_MIXING_STATE_PRINT_DISBAND:
        RecordMixing_HideYesNo(app);
        break;
    case RECORD_MIXING_STATE_WAIT_RECORDS:
        if (!RecordMixing_IsPrinterDone(app->printerId)) {
            RemoveTextPrinter(app->printerId);
        }
        RecordMixing_SetButtonState(app, 1, 2);
        ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_1);
        RecordMixing_PrintMessage(app, msg_0422_00012, FALSE);
        RecordMixing_HideYesNo(app);
        break;
    case RECORD_MIXING_STATE_PRINT_MEMBER_LEFT:
        if (app->leaveRequested == 1) {
            return;
        }
        BufferPlayersName(app->msgFmt, 0, CommPlayerInfo_GetProfile(netId));
        if (netId == Comm_GetLocalNetId()) {
            return;
        }
        RecordMixing_HideYesNo(app);
        if (Comm_GetLocalNetId() == 0) {
            app->leavingMask &= netId ^ 0xFFFF;
        }
        break;
    case RECORD_MIXING_STATE_SEND_LEAVE:
    case RECORD_MIXING_STATE_ABORT_LEAVE:
        break;
    default:
        return;
    }
    app->state = state;
}

void RecordMixing_SetStateFromLinkInMenu(RecordMixingApp *app, int state, int netId) {
    if (app->state == RECORD_MIXING_STATE_HANDLE_GROUP_MENU) {
        switch (state) {
        case RECORD_MIXING_STATE_WAIT_TEXT_THEN_RESET_MENU: {
            u32 one;
            BufferPlayersName(app->msgFmt, 0, CommPlayerInfo_GetProfile(netId));
            RecordMixing_UpdateMaxEntries(app, 1);
            app->state = state;
            app->participantCount = Comm_CountConnected();
            app->leavingMask = 0;
            if (Comm_GetLocalNetId() == 0) {
                one = 1;
                Comm_SendCommand(117, &one, one);
            }
            return;
        }
        case RECORD_MIXING_STATE_PRINT_MEMBER_LEFT:
            BufferPlayersName(app->msgFmt, 0, CommPlayerInfo_GetProfile(netId));
            if (netId == Comm_GetLocalNetId()) {
                return;
            }
            if (Comm_GetLocalNetId() == 0) {
                app->leavingMask &= netId ^ 0xFFFF;
            }
            app->state = state;
            return;
        default:
            GF_ASSERT(FALSE);
            return;
        }
    }
    if (state == RECORD_MIXING_STATE_WAIT_TEXT_THEN_RESET_MENU) {
        app->leavingMask = 0;
        app->participantCount = Comm_CountConnected();
    }
}

// buttonState: 0 normal, 1 pressed, 2 disabled (rows of the button screen)
static void RecordMixing_SetButtonState(RecordMixingApp *app, int button, int buttonState) {
    NNSG2dScreenData *screen = app->buttonScreen;
    CopyToBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, sRecordMixingButtonX[button], 20, 8, 4, screen->rawData, 0, buttonState * 4, screen->screenWidth / 8, screen->screenHeight / 8);
}

static void RecordMixing_PrintButtons(RecordMixingApp *app) {
    String *string;
    int x;

    if (!Comm_GetLocalNetId()) {
        RecordMixing_SetButtonState(app, 0, 0);
        string = NewString_ReadMsgData(app->msgData, msg_0422_00021);
        x = 64 - FontID_String_GetWidth(4, string, 0);
        AddTextPrinterParameterizedWithColor(&app->buttonWindows[0], 4, string, x / 2, 0, TEXT_SPEED_INSTANT, 0x40100, NULL);
        String_Delete(string);
    }
    app->buttonHighlightTimer = -1;
    RecordMixing_SetButtonState(app, 1, 0);
    string = NewString_ReadMsgData(app->msgData, msg_0422_00022);
    x = 64 - FontID_String_GetWidth(4, string, 0);
    AddTextPrinterParameterizedWithColor(&app->buttonWindows[1], 4, string, x / 2, 0, TEXT_SPEED_INSTANT, 0x40100, NULL);
    String_Delete(string);
    ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_1);
    ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_0);
}

static void RecordMixing_PulsePalette(u16 *angle) {
    u16 color;

    *angle += 10;
    if (*angle > 360) {
        *angle = 0;
    }
    color = 29 | ((GF_SinDeg(*angle) * 10 / FX32_ONE + 15) << 5);
    GX_LoadOBJPltt(&color, 10, 2);
    GX_LoadOBJPltt(&color, 42, 2);
}

static int RecordMixing_CountProfiles(void) {
    int i, n = 0;
    for (i = 0; i < RECORD_MIXING_MAX_MEMBERS; i++) {
        if (CommPlayerInfo_GetProfile(i)) {
            n++;
        }
    }
    return n;
}

static BOOL RecordMixing_PrintMemberList(Window *window, int unused, u32 color, RecordMixingApp *app) {
    int i;
    int localId = Comm_GetLocalNetId();
    RecordMixingApp *memberWalk;
    RecordMixingApp *nameWalk;
    int y;

    if (!RecordMixing_UpdateMembers(app)) {
        return FALSE;
    }
    FillWindowPixelBuffer(window, 0);
    memberWalk = app;
    i = 0;
    nameWalk = app;
    y = 1;
    do {
        if (memberWalk->members[0].cur) {
            int id = PlayerProfile_GetTrainerID_VisibleHalf(memberWalk->members[0].cur);
            String *idText;
            PlayerName_FlatToString(memberWalk->members[0].cur, nameWalk->memberNames[0]);
            BufferIntegerAsString(app->msgFmt, 0, id, 5, PRINTING_MODE_LEADING_ZEROS, TRUE);
            idText = ReadMsgData_ExpandPlaceholders(app->msgFmt, app->msgData, msg_0422_00001, HEAP_ID_50);
            if (localId == i) {
                AddTextPrinterParameterizedWithColor(window, 0, nameWalk->memberNames[0], 5, y, TEXT_SPEED_NOTRANSFER, 0x20300, NULL);
                AddTextPrinterParameterizedWithColor(window, 0, idText, 70, y, TEXT_SPEED_NOTRANSFER, 0x20300, NULL);
            } else {
                AddTextPrinterParameterizedWithColor(window, 0, nameWalk->memberNames[0], 5, y, TEXT_SPEED_NOTRANSFER, color, NULL);
                AddTextPrinterParameterizedWithColor(window, 0, idText, 70, y, TEXT_SPEED_NOTRANSFER, color, NULL);
            }
            String_Delete(idText);
        }
        memberWalk = (RecordMixingApp *)((u8 *)memberWalk + sizeof(RecordMixingMember));
        nameWalk = (RecordMixingApp *)((u8 *)nameWalk + sizeof(String *));
        y += 18;
        i++;
    } while (i < RECORD_MIXING_MAX_MEMBERS);
    CopyWindowToVram(window);
    return TRUE;
}

static void RecordMixing_HandleGroupMenuDummy(RecordMixingApp *app) {
}

static int RecordMixing_CountMembers(void) {
    int i, n = 0;
    for (i = 0; i < RECORD_MIXING_MAX_MEMBERS; i++) {
        if (CommPlayerInfo_GetProfile(i)) {
            n++;
        }
    }
    return n;
}

int RecordMixing_GetMemberCount(void) {
    return RecordMixing_CountMembers();
}

// memberStates: 0 none, 1 joined, 2 shown, 3 left

static BOOL RecordMixing_UpdateMembers(RecordMixingApp *app) {
    int i;
    BOOL changed = FALSE;

    for (i = 0; i < RECORD_MIXING_MAX_MEMBERS; i++) {
        app->members[i].prev = app->members[i].cur;
        app->members[i].cur = CommPlayerInfo_GetProfile(i);
        app->memberKeys[i].prev = app->memberKeys[i].cur;
        if (app->members[i].cur != NULL) {
            app->memberKeys[i].cur.s.id = PlayerProfile_GetTrainerID(app->members[i].cur);
            app->memberKeys[i].cur.s.valid = TRUE;
        } else {
            app->memberKeys[i].cur.s.id = 0;
            app->memberKeys[i].cur.s.valid = FALSE;
        }
    }
    for (i = 0; i < RECORD_MIXING_MAX_MEMBERS; i++) {
        if (app->members[i].prev != app->members[i].cur) {
            changed = TRUE;
            if (app->members[i].cur == NULL) {
                app->memberStates[i] = RECORD_MIXING_MEMBER_LEAVE;
            } else {
                app->memberStates[i] = RECORD_MIXING_MEMBER_APPEAR;
            }
        } else if (app->memberKeys[i].cur.raw != app->memberKeys[i].prev.raw) {
            changed = TRUE;
            if (!app->memberKeys[i].cur.s.valid) {
                app->memberStates[i] = RECORD_MIXING_MEMBER_LEAVE;
            } else {
                app->memberStates[i] = RECORD_MIXING_MEMBER_APPEAR;
            }
        }
    }
    return changed;
}

static void RecordMixing_PrintMessage(RecordMixingApp *app, int msgId, BOOL immediate) {
    String *string = String_New(180, HEAP_ID_50);
    ReadMsgDataIntoString(app->msgData, msgId, string);
    StringExpandPlaceholders(app->msgFmt, app->messageText, string);
    String_Delete(string);
    FillWindowPixelBuffer(&app->messageWindow, 15);
    DrawFrameAndWindow2(&app->messageWindow, FALSE, 1, 11);
    if (!immediate) {
        int textSpeed = RecordMixing_GetTextSpeed(app);
        app->printerId = AddTextPrinterParameterized(&app->messageWindow, 1, app->messageText, 0, 0, textSpeed, NULL);
    } else {
        AddTextPrinterParameterized(&app->messageWindow, 1, app->messageText, 0, 0, TEXT_SPEED_INSTANT, NULL);
        app->printerId = 0xFF;
    }
}

static BOOL RecordMixing_IsPrinterDone(u32 printerId) {
    if (printerId == 0xFF) {
        return TRUE;
    }
    if (!TextPrinterCheckActive(printerId)) {
        return TRUE;
    }
    return FALSE;
}

static void RecordMixing_ClearMessageWindow(RecordMixingApp *app) {
    ClearFrameAndWindow2(&app->messageWindow, FALSE);
}

static void RecordMixing_UpdateMemberSprites(RecordMixingApp *app) {
    int i;
    BOOL appeared = FALSE;
    int gender;
    int avatar;

    for (i = 0; i < RECORD_MIXING_MAX_MEMBERS; i++) {
        switch (app->memberStates[i]) {
        case RECORD_MIXING_MEMBER_NONE:
            break;
        case RECORD_MIXING_MEMBER_APPEAR:
            GF_ASSERT(app->members[i].cur != NULL);
            gender = PlayerProfile_GetTrainerGender(app->members[i].cur);
            avatar = PlayerProfile_GetAvatar(app->members[i].cur);
            if (i == Comm_GetLocalNetId()) {
                Sprite_SetAnimCtrlSeq(app->memberSprites[i], gender * 2 + 38);
            } else {
                RecordMixing_LoadAvatar(app->avatarChar, app->avatarPltt, i, avatar, gender);
                Sprite_SetAnimCtrlSeq(app->memberSprites[i], i * 2 + 27);
            }
            Sprite_SetDrawFlag(app->memberSprites[i], TRUE);
            app->memberStates[i] = RECORD_MIXING_MEMBER_SHOWN;
            appeared = TRUE;
            break;
        case RECORD_MIXING_MEMBER_SHOWN:
            break;
        case RECORD_MIXING_MEMBER_LEAVE:
            if (i == Comm_GetLocalNetId()) {
                Sprite_SetAnimCtrlSeq(app->memberSprites[i], PlayerProfile_GetTrainerGender(app->members[i].cur) * 2 + 39);
            } else {
                Sprite_SetAnimCtrlSeq(app->memberSprites[i], i * 2 + 28);
            }
            app->memberStates[i] = RECORD_MIXING_MEMBER_NONE;
            break;
        }
    }
    if (appeared) {
        PlaySE(SEQ_SE_DP_TELE2);
    }
}

static void RecordMixing_LoadAvatarGraphics(RecordMixingApp *app, NARC *narc) {
    app->avatarPlttRaw[0] = GfGfxLoader_GetPlttData(NARC_a_1_0_0, 9, &app->avatarPltt[0], HEAP_ID_50);
    app->avatarPlttRaw[1] = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 11, &app->avatarPltt[1], HEAP_ID_50);
    app->avatarCharRaw[0] = GfGfxLoader_GetCharData(NARC_a_1_0_0, 43, TRUE, &app->avatarChar[0], HEAP_ID_50);
    app->avatarCharRaw[1] = GfGfxLoader_GetCharDataFromOpenNarc(narc, 12, TRUE, &app->avatarChar[1], HEAP_ID_50);
}

static void RecordMixing_LoadAvatar(NNSG2dCharacterData **charData, NNSG2dPaletteData **plttData, u32 slot, int trainerClass, int gender) {
    int avatar = SpriteToUnionRoomAvatarIdx(gender, trainerClass);
    u8 *pltt = plttData[1]->pRawData;
    u8 *chars = charData[1]->pRawData;
    GX_LoadOBJ(chars + avatar * 0x600, sRecordMixingAvatarVramOffsets[slot], 0x600);
    GX_LoadOBJPltt(pltt + avatar * 0x20, (slot + 7) * 0x20, 0x20);
}

static void RecordMixing_FreeAvatarGraphics(RecordMixingApp *app) {
    Heap_Free(app->avatarPlttRaw[0]);
    Heap_Free(app->avatarPlttRaw[1]);
    Heap_Free(app->avatarCharRaw[0]);
    Heap_Free(app->avatarCharRaw[1]);
}

static int RecordMixing_GetTextSpeed(RecordMixingApp *app) {
    return 1;
}

static void RecordMixing_UpdateMaxEntries(RecordMixingApp *app, int index) {
    if (Comm_GetLocalNetId() == 0) {
        if (index == -1) {
            CommState_SetMaxEntries(1);
        } else {
            int count = Comm_CountConnected() + index;
            if (count > RECORD_MIXING_MAX_MEMBERS) {
                count = RECORD_MIXING_MAX_MEMBERS;
            }
            CommState_SetMaxEntries(count);
        }
        if (index == -1) {
            app->maxEntriesMode = 2;
        } else if (index == 0) {
            app->maxEntriesMode = 1;
        } else {
            app->maxEntriesMode = 0;
        }
    }
}

static int RecordMixing_LeaderUpdateMembers(RecordMixingApp *app, int index) {
    u8 flag[1];
    int n = RecordMixing_CountMembers();

    if (n > app->participantCount) {
        flag[0] = 1;
        Comm_SendCommand(117, flag, 1);
        app->joinPending = 1;
    } else {
        app->joinPending = 0;
    }
    if (n == app->lastMemberCount) {
        return RECORD_MIXING_MAIN_RUN_GROUP;
    }
    switch (n) {
    case 1:
        if (Comm_CountConnected() > 1 || Wireless_GetConnectedBitmap() > 1) {
            return RECORD_MIXING_MAIN_RUN_GROUP;
        }
        app->state = RECORD_MIXING_STATE_PRINT_MEMBER_UNAVAILABLE;
        RecordMixing_UpdateMaxEntries(app, -1);
        RecordMixing_HideYesNo(app);
        return RECORD_MIXING_MAIN_RUN;
    case 2:
    case 3:
    case 4:
        UnionRoom_SetBeaconActivity(UNION_ACTIVITY_RECORD_MIX_RECRUIT);
        if (n < app->lastMemberCount) {
            switch (app->maxEntriesMode) {
            case 0:
                RecordMixing_UpdateMaxEntries(app, index);
                break;
            case 1:
                RecordMixing_UpdateMaxEntries(app, 0);
                break;
            }
            app->participantCount = Comm_CountConnected();
        }
        break;
    case 5:
        UnionRoom_SetBeaconActivity(UNION_ACTIVITY_RECORD_MIX);
        RecordMixing_UpdateMaxEntries(app, index);
        break;
    }
    app->lastMemberCount = RecordMixing_CountMembers();
    return RECORD_MIXING_MAIN_RUN_GROUP;
}
