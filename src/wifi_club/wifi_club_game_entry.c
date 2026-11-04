
#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0778.h"

#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "overlay_00_arm.h"
#include "overlay_00_thumb.h"
#include "overlay_42.h"
#include "overlay_44.h"
#include "overlay_manager.h"
#include "poke_overlay.h"
#include "screen_fade.h"
#include "sound_system.h"
#include "sprite.h"
#include "text.h"
#include "sound_playback.h"
#include "sprite_resource.h"
#include "oam_manager.h"
#include "communication_player_state.h"
#include "communication_core.h"
#include "link_synchronization.h"
#include "comm_state.h"
#include "comm_state_internal.h"
#include "wireless_status_icon.h"
#include "wifi_club_comm.h"
#include "vram_transfer_manager.h"

const u8 sWifiClubGameEntryAvatarSpinFrames[4] = { 0x08, 0x00, 0x04, 0x0C };

const WindowTemplate sWifiClubGameEntryYesNoWindowTemplate = {
    .bgId = 2,
    .left = 25,
    .top = 13,
    .width = 5,
    .height = 4,
    .palette = 1,
    .baseTile = 57,
};

const WifiClubGameEntryAvatarFunc sWifiClubGameEntryAvatarFuncs[4] = { WifiClubGameEntry_AvatarNone, WifiClubGameEntry_AvatarStartSpin, WifiClubGameEntry_AvatarUpdateSpin, WifiClubGameEntry_AvatarIdle };

const ObjCharTransferTemplate sWifiClubGameEntryObjCharTransferTemplate = {
    4,
    0x20000,
    0x4000,
    HEAP_ID_DEFAULT
};
const GraphicsModes sWifiClubGameEntryGraphicsModes = {
    GX_DISPMODE_GRAPHICS,
    GX_BGMODE_0,
    GX_BGMODE_0,
    GX_BG0_AS_2D
};

const BgTemplate sWifiClubGameEntryBgTemplateMain0 = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xe000,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 2,
    .areaOver = GX_BG_AREAOVER_XLU,
    .dummy = 0,
    .mosaic = 0,
};

const BgTemplate sWifiClubGameEntryBgTemplateMain2 = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xd800,
    .charBase = GX_BG_CHARBASE_0x08000,
    .bgExtPltt = GX_BG_EXTPLTT_23,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .dummy = 0,
    .mosaic = 0,
};

const BgTemplate sWifiClubGameEntryBgTemplateMain1 = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xd000,
    .charBase = GX_BG_CHARBASE_0x10000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .dummy = 0,
    .mosaic = 0,
};

const GraphicsBanks sWifiClubGameEntryGraphicsBanks = {
    GX_VRAM_BG_128_A, GX_VRAM_BGEXTPLTT_NONE, GX_VRAM_SUB_BG_128_C, GX_VRAM_SUB_BGEXTPLTT_NONE, GX_VRAM_OBJ_128_B, GX_VRAM_OBJEXTPLTT_NONE, GX_VRAM_SUB_OBJ_16_I, GX_VRAM_SUB_OBJEXTPLTT_NONE, GX_VRAM_TEX_NONE, GX_VRAM_TEXPLTT_NONE
};

const Field2DObjectTemplate sWifiClubGameEntryAvatarTemplates[4] = {
    { 208, 48, 0, 0, 1, 0 },
    { 232, 72, 1, 0, 2, 0 },
    { 208, 96, 2, 0, 0, 0 },
    { 184, 72, 3, 0, 3, 0 },
};

const WifiClubGameEntryStateFunc sWifiClubGameEntryMemberStates[30] = {
    WifiClubGameEntry_Member_Start,
    WifiClubGameEntry_Member_WaitLeaderInfo,
    Wifi_PromptAwaitingResponse,
    WifiClubGameEntry_Member_WaitJoinAnswer,
    WifiClubGameEntry_Member_PrintApproved,
    WifiClubGameEntry_Member_WaitApproved,
    WifiClubGameEntry_Member_PrintRefused,
    WifiClubGameEntry_Member_EndRefused,
    Wifi_PromptAwaitingMembers,
    WifiClubGameEntry_Member_WaitAwaitingMessage,
    WifiClubGameEntry_Member_WaitStart,
    WifiClubGameEntry_Member_SendStatus,
    WifiClubGameEntry_Member_CheckStatuses,
    WifiClubGameEntry_Member_StartFinalSync,
    WifiClubGameEntry_Member_WaitFinalSync,
    WifiClubGameEntry_Member_OnDropped,
    Wifi_PromptMemberDrop,
    WifiClubGameEntry_Member_EndAfterDropped,
    Wifi_PromptToggleVoiceChat_,
    WifiClubGameEntry_Member_ShowVoiceChatYesNo,
    WifiClubGameEntry_Member_HandleVoiceChatYesNo,
    WifiClubGameEntry_Member_PrintLeaderBusy,
    WifiClubGameEntry_Member_ShowApplyAgainYesNo,
    WifiClubGameEntry_Member_HandleApplyAgainYesNo,
    WifiClubGameEntry_Member_PrintContacting,
    WifiClubGameEntry_Member_ApplyAgain,
    WifiClubGameEntry_Member_WaitReconnected,
    WifiClubGameEntry_Member_RebuildScreen,
    WifiClubGameEntry_Member_WaitFadeIn,
    WifiClubGameEntry_Member_Cancel,
};

const WifiClubGameEntryStateFunc sWifiClubGameEntryLeaderStates[33] = {
    WifiClubGameEntry_Leader_Start,
    Wifi_PromptReadyMessage,
    WifiClubGameEntry_Leader_HandleInput,
    Wifi_PromptUserJoinRequest,
    WifiClubGameEntry_Leader_ShowAcceptYesNo,
    WifiClubGameEntry_Leader_HandleAcceptYesNo,
    Wifi_PromptInsufficientMembers,
    WifiClubGameEntry_Leader_WaitNotEnoughMembers,
    Wifi_PromptConfirmMembers,
    WifiClubGameEntry_Leader_ShowConfirmYesNo,
    WifiClubGameEntry_Leader_HandleConfirmYesNo,
    WifiClubGameEntry_Leader_StartCommunicating,
    WifiClubGameEntry_Leader_WaitMembersConnected,
    WifiClubGameEntry_Leader_SendStartCommand,
    WifiClubGameEntry_Leader_WaitStartSync,
    WifiClubGameEntry_Leader_SendStatus,
    WifiClubGameEntry_Leader_CheckStatuses,
    WifiClubGameEntry_Leader_StartFinalSync,
    WifiClubGameEntry_Leader_WaitFinalSync,
    Wifi_PromptStopFindingMembers,
    WifiClubGameEntry_Leader_ShowStopSeekingYesNo,
    WifiClubGameEntry_Leader_HandleStopSeekingYesNo,
    Wifi_PromptDropAsLeader,
    WifiClubGameEntry_Leader_ShowDisbandYesNo,
    WifiClubGameEntry_Leader_HandleDisbandYesNo,
    Wifi_PromptCancelInvites,
    WifiClubGameEntry_Leader_Cancel,
    WifiClubGameEntry_Leader_OnMemberDropped,
    Wifi_PromptMemberDropped,
    WifiClubGameEntry_Leader_EndAfterMemberDropped,
    Wifi_PromptToggleVoiceChat,
    WifiClubGameEntry_Leader_ShowVoiceChatYesNo,
    WifiClubGameEntry_Leader_HandleVoiceChatYesNo,
};

const u8 sWifiClubGameEntryBgPaletteFrames[20] = { 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5, 5, 0, 0 };

u8 sWifiClubGameEntryTitleMsgIds[4] = { 126, 127, 127, 127 };

FS_EXTERN_OVERLAY(OVY_42);

BOOL WifiClubGameEntry_Init(OverlayManager *man, int *state) {
    WifiClubGameEntryArgs *args = OverlayManager_GetArgs(man);
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_42), OVY_LOAD_ASYNC);
    GF_ASSERT(CommState_IsWifi() == 1);
    Heap_Create(HEAP_ID_3, HEAP_ID_103, 0x18000);
    Heap_Create(HEAP_ID_3, HEAP_ID_104, 0xA000);
    WifiClubGameEntry *gameEntry = OverlayManager_CreateAndGetData(man, sizeof(WifiClubGameEntry), HEAP_ID_103);
    MI_CpuFill8(gameEntry, 0, sizeof(WifiClubGameEntry));
    MI_CpuFill8(gameEntry->shownVoiceChatFlags, 1, 4);
    MI_CpuFill8(gameEntry->voiceChatFlags, 1, 4);
    GF_CreateVramTransferManager(16, HEAP_ID_103);
    WifiClubStatusData *statusData = CommState_GetWifiClubData();
    gameEntry->clubStatus = &statusData->own;
    statusData->own.voiceChat = statusData->own.voiceChatSetting;
    gameEntry->isLeader = WifiClubGameEntry_IsLocalLeader(gameEntry);
    gameEntry->applicantNetId = 255;
    WifiClubComm_RegisterCommands(gameEntry);
    WifiClubGameEntry_SetDisconnectCallback(gameEntry);
    WifiClubGameEntry_InitScreen(gameEntry, args, HEAP_ID_103);
    Main_SetVBlankIntrCB(WifiClubGameEntry_VBlankCB, gameEntry);
    WirelessStatusIcon_Create();
    gameEntry->watchConnection = 1;
    return TRUE;
}

BOOL WifiClubGameEntry_Main(OverlayManager *man, int *state) {
    WifiClubGameEntryArgs *args;
    WifiClubGameEntry *gameEntry;
    s32 done;

    gameEntry = OverlayManager_GetData(man);
    args = OverlayManager_GetArgs(man);
    switch (state[0]) {
    case 0:
        BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_103);
        state[0]++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            state[0]++;
        }
        break;
    case 2:
        if (gameEntry->watchConnection != 0) {
            WifiClubGameEntry_CheckConnectionLost(gameEntry, args, HEAP_ID_103);
        }
        if (gameEntry->isLeader != 0) {
            if (CommPlayerInfo_Exists() == 1) {
                WifiClubGameEntry_SendVoiceChatFlags(gameEntry);
                CommPlayerInfo_HostRedistribute();
                WifiClubGameEntry_RefuseLateApplicants(gameEntry);
            }
            done = sWifiClubGameEntryLeaderStates[gameEntry->state](gameEntry, args, HEAP_ID_103);
        } else {
            done = sWifiClubGameEntryMemberStates[gameEntry->state](gameEntry, args, HEAP_ID_103);
            if (CommPlayerInfo_Exists() == 1) {
                WifiClubGameEntry_AcceptAnnouncedMembers(gameEntry, HEAP_ID_103);
            }
        }
        if (WifiClubGameEntry_CheckMemberListChanged(gameEntry) != 0) {
            WifiClubGameEntry_DrawMemberList(gameEntry, args, HEAP_ID_103);
        }
        WifiClubGameEntry_UpdateAvatars(gameEntry);
        if (done == 1) {
            args->result = gameEntry->result;
            args->voiceChat = gameEntry->voiceChatOn;
            state[0]++;
        }
        break;
    case 3:
        BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_103);
        state[0]++;
        break;
    case 4:
        if (IsPaletteFadeFinished()) {
            return 1;
        }
    }
    WifiClubGameEntry_AnimateBgPalette(&gameEntry->screen);
    SpriteList_RenderAndAnimateSprites(gameEntry->screen.spriteList);
    return 0;
}

BOOL WifiClubGameEntry_Exit(OverlayManager *man, int *state) {
    WifiClubGameEntry *gameEntry;

    gameEntry = OverlayManager_GetData(man);
    OverlayManager_GetArgs(man);
    Main_SetVBlankIntrCB(0, 0);
    WifiClubGameEntry_ClearDisconnectCallback(gameEntry);
    WifiClubGameEntry_DeleteAvatars(gameEntry);
    WifiClubGameEntry_StopVoiceChat(gameEntry);
    WifiClubGameEntry_FreeScreen(gameEntry, HEAP_ID_103);
    GF_DestroyVramTransferManager();
    OverlayManager_FreeData(man);
    Heap_Destroy(HEAP_ID_104);
    Heap_Destroy(HEAP_ID_103);
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_42));
    return 1;
}

void WifiClubGameEntry_OnJoinAnswer(WifiClubGameEntry *gameEntry, String *string) {
    if (gameEntry->isLeader == 0) {

        if (string->maxsize == Comm_GetLocalNetId()) {
            switch (string->magic) {
            case 1:
                gameEntry->joinAnswer = 1;
                return;
            case 0:
                gameEntry->joinAnswer = 2;
                return;

            case 2:
                gameEntry->joinAnswer = 3;
                return;
            }
        } else {
            switch (string->magic) {
            case 0:
                break;
            case 1:
                gameEntry->acceptedByLeader[string->maxsize] = 1;
                return;
            case 2:
                break;
            default:
                return;
            }
            if (CommPlayerInfo_Exists() == 1) {
                CommPlayerInfo_ClearPlayer(string->maxsize);
            }
        }
    }
}

void WifiClubGameEntry_OnStartCommand(WifiClubGameEntry *gameEntry) {
    if (gameEntry->startSyncStarted == 0) {
        gameEntry->startSyncStarted = 1;
        LinkSync_StartSync(13);
    }
}

void WifiClubGameEntry_OnVoiceChatFlags(WifiClubGameEntry *gameEntry, String *string) {
    if (gameEntry->isLeader != 1) {
        memcpy(gameEntry->voiceChatFlags, string, 4);
    }
}

void WifiClubGameEntry_VBlankCB(void *data) {
    WifiClubGameEntry *gameEntry = data;

    DoScheduledBgGpuUpdates(gameEntry->screen.bgConfig);
    GF_RunVramTransferTasks();
    OamManager_ApplyAndResetBuffers();
}

s32 WifiClubGameEntry_IsLocalLeader(WifiClubGameEntry *gameEntry) {
    if (Comm_GetLocalNetId() == 0) {
        return 1;
    }
    return 0;
}

void WifiClubGameEntry_InitScreen(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    WifiClubGameEntry_SetGfxBanks();
    InitBgAndScrnData(&gameEntry->screen, heapID);
    InitWindowList(&gameEntry->screen, args, heapID);
    InitStringAndMsgData(&gameEntry->screen, args, heapID);
    WifiClubGameEntry_PrintTitle(&gameEntry->screen, args, heapID);
    WifiClubGameEntry_DrawMemberList(gameEntry, args, heapID);
    InitSpritesAnd2DGfxResObjs(&gameEntry->screen, heapID);
}

void WifiClubGameEntry_FreeScreen(WifiClubGameEntry *gameEntry, enum HeapID heapID) {
    FreeSpritesAnd2DGfxResObjs(&gameEntry->screen);
    FreeStringAndMsgData(&gameEntry->screen);
    FreeWindowList(&gameEntry->screen, heapID);
    FreeBgAndScreenData(&gameEntry->screen);
}

void WifiClubGameEntry_SetGfxBanks(void) {
    GraphicsBanks graphicsBanks = sWifiClubGameEntryGraphicsBanks;
    GfGfx_SetBanks(&graphicsBanks);
}

void InitBgAndScrnData(WifiClubGameEntryScreen *screen, enum HeapID heapID) {
    screen->bgConfig = BgConfig_Alloc(heapID);
    GraphicsModes graphicModes = sWifiClubGameEntryGraphicsModes;
    SetBothScreensModesAndDisable(&graphicModes);

    BgTemplate bgTemplate1 = sWifiClubGameEntryBgTemplateMain0;
    InitBgFromTemplate(screen->bgConfig, GF_BG_LYR_MAIN_0, &bgTemplate1, 0);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 32, 0, heapID);
    BgClearTilemapBufferAndCommit(screen->bgConfig, GF_BG_LYR_MAIN_0);

    BgTemplate bgTemplate2 = sWifiClubGameEntryBgTemplateMain1;
    InitBgFromTemplate(screen->bgConfig, GF_BG_LYR_MAIN_1, &bgTemplate2, 0);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_1, 32, 0, heapID);
    BgClearTilemapBufferAndCommit(screen->bgConfig, GF_BG_LYR_MAIN_1);

    BgTemplate bgTemplate3 = sWifiClubGameEntryBgTemplateMain2;
    InitBgFromTemplate(screen->bgConfig, GF_BG_LYR_MAIN_2, &bgTemplate3, 0);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_2, 32, 0, heapID);
    BgClearTilemapBufferAndCommit(screen->bgConfig, GF_BG_LYR_MAIN_2);

    GfGfx_EngineATogglePlanes(8, 0);
    GfGfx_EngineATogglePlanes(16, 1);
    GfGfx_EngineBTogglePlanes(1, 0);
    GfGfx_EngineBTogglePlanes(2, 0);
    GfGfx_EngineBTogglePlanes(4, 0);
    GfGfx_EngineBTogglePlanes(8, 0);
    GfGfx_EngineBTogglePlanes(16, 0);

    NARC *narc = NARC_New(NARC_a_0_8_8, heapID);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 14, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_5_OFFSET, 32, heapID);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 13, screen->bgConfig, GF_BG_LYR_MAIN_2, 0, 1536, 0, heapID);
    screen->scrnDataRaw = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 15, 0, &screen->scrnData, heapID);
    screen->plttDataRaw = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 45, &screen->plttData, heapID);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 46, screen->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, 0, heapID);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 47, screen->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, 0, heapID);
    WifiClubGameEntry_LoadBgPaletteFrame(screen, 0);
    screen->paletteTimer = 3;
    screen->paletteFrame = 1;
    NARC_Delete(narc);
}

void FreeBgAndScreenData(WifiClubGameEntryScreen *screen) {
    Heap_Free(screen->scrnDataRaw);
    Heap_Free(screen->plttDataRaw);
    FreeBgTilemapBuffer(screen->bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(screen->bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(screen->bgConfig, GF_BG_LYR_MAIN_0);
    Heap_Free(screen->bgConfig);
}

void InitWindowList(WifiClubGameEntryScreen *screen, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_1_OFFSET, heapID);

    Options *options = Save_PlayerData_GetOptionsAddr(args->saveData);
    LoadUserFrameGfx2(screen->bgConfig, GF_BG_LYR_MAIN_1, 1, 2, Options_GetFrame(options), heapID);
    LoadUserFrameGfx1(screen->bgConfig, GF_BG_LYR_MAIN_1, 31, 3, 0, heapID);
    LoadUserFrameGfx1(screen->bgConfig, GF_BG_LYR_MAIN_2, 48, 4, 0, heapID);
    AddWindowParameterized(screen->bgConfig, &screen->windowList[0], GF_BG_LYR_MAIN_1, 2, 19, 27, 4, 1, 40);
    FillWindowPixelBuffer(&screen->windowList[0], 15);
    DrawFrameAndWindow2(&screen->windowList[0], 1, 1, 2);
    AddWindowParameterized(screen->bgConfig, &screen->windowList[1], GF_BG_LYR_MAIN_1, 1, 1, 27, 2, 1, 148);
    FillWindowPixelBuffer(&screen->windowList[1], 15);
    DrawFrameAndWindow1(&screen->windowList[1], 1, 31, 3);
    AddWindowParameterized(screen->bgConfig, &screen->windowList[2], GF_BG_LYR_MAIN_1, 2, 16, 28, 2, 1, 202);
    FillWindowPixelBuffer(&screen->windowList[2], 0);
    AddWindowParameterized(screen->bgConfig, &screen->windowList[3], GF_BG_LYR_MAIN_1, 1, 5, 20, 8, 1, 258);
    FillWindowPixelBuffer(&screen->windowList[3], 15);
    DrawFrameAndWindow1(&screen->windowList[3], 1, 31, 3);
    AddWindowParameterized(screen->bgConfig, &screen->windowList[4], GF_BG_LYR_MAIN_1, 23, 5, 7, 5, 1, 418);
    FillWindowPixelBuffer(&screen->windowList[4], 15);
}

void FreeWindowList(WifiClubGameEntryScreen *screen, enum HeapID heapID) {
    WifiClubGameEntry_ClearMessage(screen);
    ClearFrameAndWindow2(&screen->windowList[0], 0);
    RemoveWindow(&screen->windowList[0]);
    EraseFrameAndWindow1(&screen->windowList[1], 0);
    RemoveWindow(&screen->windowList[1]);
    RemoveWindow(&screen->windowList[2]);
    EraseFrameAndWindow1(&screen->windowList[3], 0);
    RemoveWindow(&screen->windowList[3]);
    EraseFrameAndWindow1(&screen->windowList[4], 0);
    RemoveWindow(&screen->windowList[4]);

    if (screen->listMenu2D != NULL) {
        Clear2dMenuWindowAndDelete(screen->listMenu2D, heapID);
    }
}

void InitStringAndMsgData(WifiClubGameEntryScreen *screen, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    screen->msgFmt = MessageFormat_New(heapID);
    screen->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0778_bin, heapID);
    screen->string1 = String_New(256, heapID);
    screen->string2 = String_New(256, heapID);
    screen->printerId = 255;

    Options *options = Save_PlayerData_GetOptionsAddr(args->saveData);
    screen->textFrameDelay = Options_GetTextFrameDelay(options);
}

void FreeStringAndMsgData(WifiClubGameEntryScreen *screen) {
    String_Delete(screen->string2);
    String_Delete(screen->string1);
    DestroyMsgData(screen->msgData);
    MessageFormat_Delete(screen->msgFmt);
}

void WifiClubGameEntry_PrintTitle(WifiClubGameEntryScreen *screen, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    switch (args->game) {
    case 0:
        break;
    case 1:
        BufferWiFiPlazaActivityName(screen->msgFmt, 0, 0);
        break;
    case 2:
        BufferWiFiPlazaActivityName(screen->msgFmt, 0, 1);
        break;
    case 3:
        BufferWiFiPlazaActivityName(screen->msgFmt, 0, 2);
        break;
    }

    // Seeking Poffin cooks! OR // Seeking {STRVAR_3 0, 0, 0} players!
    ReadMsgDataIntoString(screen->msgData, sWifiClubGameEntryTitleMsgIds[args->game], screen->string2);
    StringExpandPlaceholders(screen->msgFmt, screen->string1, screen->string2);
    AddTextPrinterParameterizedWithColor(&screen->windowList[1], 0, screen->string1, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 15), 0);
    ScheduleWindowCopyToVram(&screen->windowList[1]);
    ScheduleWindowCopyToVram(&screen->windowList[3]);

    // Voice Chat ON/OFF: X Button
    ReadMsgDataIntoString(screen->msgData, msg_0778_00128, screen->string1);
    AddTextPrinterParameterizedWithColor(&screen->windowList[2], 0, screen->string1, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 0), 0);
    ScheduleWindowCopyToVram(&screen->windowList[2]);
    ScheduleWindowCopyToVram(&screen->windowList[0]);
}

void InitSpritesAnd2DGfxResObjs(WifiClubGameEntryScreen *screen, enum HeapID heapID) {
    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 126, 0, 31, 0, 126, 0, 31, heapID);
    ObjCharTransferTemplate objCharTransferTemplate = sWifiClubGameEntryObjCharTransferTemplate;
    objCharTransferTemplate.heapID = heapID;
    ObjCharTransfer_InitEx(&objCharTransferTemplate, GX_OBJVRAMMODE_CHAR_1D_128K, GX_OBJVRAMMODE_CHAR_1D_32K);
    ObjPlttTransfer_Init(4, heapID);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
    G2dRenderer_SetObjCharTransferReservedRegion(NNS_G2D_VRAM_TYPE_2DMAIN, GX_OBJVRAMMODE_CHAR_1D_128K);
    G2dRenderer_SetPlttTransferReservedRegion(NNS_G2D_VRAM_TYPE_2DMAIN);
    screen->spriteList = G2dRenderer_Init(4, &screen->g2dRenderer, heapID);

    for (s32 i = 0; i < 4; i++) {
        screen->gf2DGfxResManList[i] = Create2DGfxResObjMan(4, (GfGfxResType)i, heapID);
    }

    screen->objects = Field2DObjectManager_New(4, heapID);
    screen->drawers = Field2DObjectSpriteManager_New(screen->spriteList, 0, 4, 1, heapID);
}

void FreeSpritesAnd2DGfxResObjs(WifiClubGameEntryScreen *screen) {
    Field2DObjectSpriteManager_Free(screen->drawers);
    Field2DObjectManager_Free(screen->objects);
    SpriteList_Delete(screen->spriteList);

    for (s32 i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(screen->gf2DGfxResManList[i]);
    }

    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    OamManager_Free();
}

void Wifi_LoadAndPrintTextToWindowWrapper(WifiClubGameEntryScreen *screen, WifiClubGameEntryArgs *args, s32 strno, enum HeapID heapID) {
    Wifi_LoadAndPrintTextToWindow(screen, args, strno, 0, heapID);
}

void Wifi_LoadAndPrintTextToWindow(WifiClubGameEntryScreen *screen, WifiClubGameEntryArgs *args, s32 strno, s32 messageDelay, enum HeapID heapID) {
    if ((screen->printerId != 255) && (TextPrinterCheckActive(screen->printerId) != 0)) {
        RemoveTextPrinter(screen->printerId);
        screen->printerId = 255;
    }
    FillWindowPixelBuffer(&screen->windowList[0], 15);
    String *string = String_New(256, heapID);
    ReadMsgDataIntoString(screen->msgData, strno, string);
    StringExpandPlaceholders(screen->msgFmt, screen->string1, string);
    screen->printerId = AddTextPrinterParameterizedWithColor(&screen->windowList[0], 1, screen->string1, 0, 0, screen->textFrameDelay, MAKE_TEXT_COLOR(1, 2, 15), 0);
    ScheduleWindowCopyToVram(&screen->windowList[0]);
    String_Delete(string);
    Options *options = Save_PlayerData_GetOptionsAddr(args->saveData);
    LoadUserFrameGfx2(screen->bgConfig, GF_BG_LYR_MAIN_1, 1, 2, Options_GetFrame(options), heapID);
    screen->messageDelay = messageDelay;
}

s32 WifiClubGameEntry_IsMessageFinished(WifiClubGameEntryScreen *screen) {
    if (screen->printerId == 255) {
        if (screen->messageDelay != 0) {
            screen->messageDelay--;
            return 0;
        }
    } else if ((TextPrinterCheckActive(screen->printerId) == 0) && (screen->printerId != 255)) {
        screen->printerId = 255;
    }
    if ((screen->printerId == 255) && (screen->messageDelay == 0)) {
        return 1;
    }
    return 0;
}

void WifiClubGameEntry_ClearMessage(WifiClubGameEntryScreen *screen) {
    if (screen->printerId != 255) {
        if (TextPrinterCheckActive(screen->printerId) != 0) {
            RemoveTextPrinter(screen->printerId);
        }
        screen->printerId = 255;
    }
    FillWindowPixelBuffer(&screen->windowList[0], 15);
    ScheduleWindowCopyToVram(&screen->windowList[0]);
    screen->messageDelay = 0;
}

// {STRVAR_1 3, 0, 0}\nID {STRVAR_1 54, 1, 0}
void WifiClubGameEntry_ShowApplicantInfo(WifiClubGameEntryScreen *screen, WifiClubGameEntryArgs *args, s32 netId, enum HeapID heapID) {
    String *string1 = String_New(256, heapID);
    String *string2 = String_New(256, heapID);

    WifiClubGameEntry_BufferPlayerName(screen, args, netId, 0, heapID);
    WifiClubGameEntry_BufferTrainerId(screen, args, netId, 1, heapID);

    ReadMsgDataIntoString(screen->msgData, msg_0778_00131, string1);
    StringExpandPlaceholders(screen->msgFmt, string2, string1);
    FillWindowPixelBuffer(&screen->windowList[4], 15);
    AddTextPrinterParameterizedWithColor(&screen->windowList[4], 0, string2, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 15), 0);
    DrawFrameAndWindow1(&screen->windowList[4], 1, 31, 3);
    ScheduleWindowCopyToVram(&screen->windowList[4]);
    String_Delete(string1);
    String_Delete(string2);
}

void WifiClubGameEntry_HideApplicantInfo(WifiClubGameEntryScreen *screen) {
    EraseFrameAndWindow1(&screen->windowList[4], 1);
    ClearWindowTilemapAndScheduleTransfer(&screen->windowList[4]);
}

void WifiClubGameEntry_DrawMemberList(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    WifiClubGameEntryScreen *screen;

    if (CommPlayerInfo_Exists() != 0) {
        screen = &gameEntry->screen;
        for (s32 i = 0; i < 4; i++) {
            if ((i == 0) && (CommPlayerInfo_IsReceivedOrAccepted(i) == 1)) {
                WifiClubGameEntry_DrawMember(gameEntry, screen, args, i, heapID);
            } else if (CommPlayerInfo_IsAccepted(i) == 1) {
                WifiClubGameEntry_DrawMember(gameEntry, screen, args, i, heapID);
            } else {
                WifiClubGameEntry_ClearMember(screen, args, i, heapID);
            }
        }
    }
}

void WifiClubGameEntry_DrawMember(WifiClubGameEntry *gameEntry, WifiClubGameEntryScreen *screen, WifiClubGameEntryArgs *args, s32 netId, enum HeapID heapID) {
    String *string1 = String_New(256, heapID);
    String *string2 = String_New(256, heapID);
    WifiClubGameEntry_BufferPlayerName(screen, args, netId, 0, heapID);

    // {STRVAR_1 3, 0, 0}
    ReadMsgDataIntoString(screen->msgData, msg_0778_00129, string1);
    StringExpandPlaceholders(screen->msgFmt, string2, string1);

    u32 y = netId * 16;
    FillWindowPixelRect(&screen->windowList[3], 15, 0, y, 160, 16);
    AddTextPrinterParameterizedWithColor(&screen->windowList[3], 0, string2, 0, y, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 15), 0);
    WifiClubGameEntry_BufferTrainerId(screen, args, netId, 0, heapID);

    // ID {STRVAR_1 54, 0, 0}
    ReadMsgDataIntoString(screen->msgData, msg_0778_00130, string1);
    StringExpandPlaceholders(screen->msgFmt, string2, string1);
    AddTextPrinterParameterizedWithColor(&screen->windowList[3], 0, string2, 72, y, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 15), 0);
    ScheduleWindowCopyToVram(&screen->windowList[3]);
    s32 voiceChatIcon;
    if (netId == Comm_GetLocalNetId()) {
        if (gameEntry->clubStatus->voiceChat != 0) {
            voiceChatIcon = 2;
        } else {
            voiceChatIcon = 1;
        }
    } else if (gameEntry->voiceChatFlags[netId] != 0) {
        voiceChatIcon = 2;
    } else {
        voiceChatIcon = 1;
    }

    NNSG2dScreenData *screenData = screen->scrnData;
    u32 tileY = (netId << 1) + 5;
    CopyToBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_2, 18, tileY, 2, 2, &screenData->rawData[0], voiceChatIcon * 2, 0, screenData->screenWidth / 8, screenData->screenHeight / 8);
    BgTilemapRectChangePalette(screen->bgConfig, GF_BG_LYR_MAIN_2, 18, tileY, 2, 2, 5);
    ScheduleBgTilemapBufferTransfer(screen->bgConfig, GF_BG_LYR_MAIN_2);
    String_Delete(string1);
    String_Delete(string2);
}

void WifiClubGameEntry_ClearMember(WifiClubGameEntryScreen *screen, WifiClubGameEntryArgs *args, s32 netId, enum HeapID heapID) {
    FillWindowPixelRect(&screen->windowList[3], 15, 0, netId * 16, 160, 16);

    NNSG2dScreenData *screenData = screen->scrnData;
    CopyToBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_2, 18, netId * 2 + 5, 2, 2, &screenData->rawData[0], 0, 0, screenData->screenWidth / 8, screenData->screenHeight / 8);
    ScheduleBgTilemapBufferTransfer(screen->bgConfig, GF_BG_LYR_MAIN_2);
    ScheduleWindowCopyToVram(&screen->windowList[3]);
}

void WifiClubGameEntry_BufferPlayerName(WifiClubGameEntryScreen *screen, WifiClubGameEntryArgs *args, s32 netId, s32 idx, enum HeapID heapID) {
    BufferPlayersName(screen->msgFmt, idx, CommPlayerInfo_GetProfile(netId));
}

void WifiClubGameEntry_BufferTrainerId(WifiClubGameEntryScreen *screen, WifiClubGameEntryArgs *args, s32 netId, s32 idx, enum HeapID heapID) {
    BufferIntegerAsString(screen->msgFmt, idx, PlayerProfile_GetTrainerID_VisibleHalf(CommPlayerInfo_GetProfile(netId)), 5, PRINTING_MODE_LEADING_ZEROS, 1);
}

void WifiClubGameEntry_AnimateBgPalette(WifiClubGameEntryScreen *screen) {
    if (screen->paletteTimer <= 0) {
        WifiClubGameEntry_LoadBgPaletteFrame(screen, screen->paletteFrame);
        screen->paletteTimer = 3;
        screen->paletteFrame = (screen->paletteFrame + 1) % 18;
        return;
    }
    screen->paletteTimer--;
}

void WifiClubGameEntry_LoadBgPaletteFrame(WifiClubGameEntryScreen *screen, s32 frame) {
    GF_ASSERT(GF_CreateNewVramTransferTask(NNS_GFD_DST_2D_BG_PLTT_MAIN, 0, (sWifiClubGameEntryBgPaletteFrames[frame] << 5) + screen->plttData->pRawData, 32));
}

u8 WifiClubGameEntry_ToggleVoiceChat(WifiClubGameEntry *gameEntry, enum HeapID heapID) {
    gameEntry->clubStatus->voiceChatSetting = 1 - gameEntry->clubStatus->voiceChatSetting;
    gameEntry->clubStatus->voiceChat = gameEntry->clubStatus->voiceChatSetting;
    WifiConnection_SetVoiceChatEnabled(gameEntry->clubStatus->voiceChat);
    WifiConnection_SetOwnStatusData(gameEntry->clubStatus, 36);
    if (gameEntry->clubStatus->voiceChat == 1) {
        WifiClubGameEntry_EnableVoiceChat(gameEntry);
    } else {
        WifiClubGameEntry_DisableVoiceChat(gameEntry);
    }
    return gameEntry->clubStatus->voiceChatSetting;
}

void WifiClubGameEntry_CheckConnectionLost(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 memberDisconnected;
    s32 timedOut;
    s32 memberMissing;

    if (gameEntry->isLeader != 0) {
        if ((u8)(gameEntry->state + 229) <= 2) {
            return;
        }
        if ((CommState_GetWifiMatchStatus() <= WIFI_MATCH_STATUS_OTHER) && (WifiClubGameEntry_CountMembers(gameEntry) <= 1) && (WifiClubGameEntry_IsAnyoneConnected(gameEntry) == 0)) {
            return;
        }
    } else if ((gameEntry->state == 15) || (gameEntry->state == 16) || (gameEntry->state == 17) || ((u8)(gameEntry->state + 250) <= 1)) {
        return;
    }

    timedOut = WifiClubGameEntry_HasTimedOut(gameEntry);
    memberDisconnected = WifiClubGameEntry_CheckMemberDisconnected(gameEntry);
    if (WifiClubGameEntry_CountMembers(gameEntry) > Comm_CountConnected()) {
        memberMissing = 1;
    } else {
        memberMissing = 0;
    }
    if ((CommState_GetWifiMatchStatus() >= WIFI_MATCH_STATUS_TIMED_OUT) || (CommState_HasWifiFailed() != 0) || (CommState_WasWifiDisconnected() != 0) || (Comm_IsNetIdConnected(0) == 0) || (WifiClubGameEntry_IsAnyoneConnected(gameEntry) == 0) || (memberMissing == 1) || (timedOut == 1) || (memberDisconnected == 1)) {
        if (gameEntry->isLeader != 0) {
            gameEntry->state = 27;
            return;
        }
        gameEntry->state = 15;
    }
}

void WifiClubGameEntry_CheckMatchFailed(WifiClubGameEntry *gameEntry) {
    if ((CommState_GetWifiMatchStatus() > WIFI_MATCH_STATUS_TIMED_OUT) || (CommState_WasWifiDisconnected() != 0) || (CommState_HasWifiFailed() != 0)) {
        gameEntry->state = 15;
    }
}

s32 WifiClubGameEntry_IsAnyoneConnected(WifiClubGameEntry *gameEntry) {
    if (Comm_CountConnected() > 0) {
        return 1;
    }
    return 0;
}

s32 WifiClubGameEntry_StartMatch(u32 friendIndex, u32 game) {
    s32 result = CommState_StartWifiMatch(friendIndex);
    if (result == 1) {
        switch (game) {
        case 0:
            CommState_SetWifiPeerLinkMode29();
            break;
        case 1:
        case 2:
        case 3:
            CommState_SetClubWifiLinkMode();
        }
    }
    return result;
}

void WifiClubGameEntry_SetPlayingStatus(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args) {
    switch (args->game) {
    case 0:
        gameEntry->clubStatus->status = 18;
        break;
    case 1:
        gameEntry->clubStatus->status = 22;
        break;
    case 2:
        gameEntry->clubStatus->status = 24;
        break;
    case 3:
        gameEntry->clubStatus->status = 26;
        break;
    }
    WifiConnection_SetOwnStatusData(gameEntry->clubStatus, 36);
}

s32 WifiClubGameEntry_StartVoiceChat(WifiClubGameEntry *gameEntry) {
    if (gameEntry->voiceChatOn == 1) {
        return 0;
    }
    if (WifiClubGameEntry_IsAnyoneConnected(gameEntry) == 1) {
        WifiConnection_StartVoiceChat(104);
        gameEntry->voiceChatOn = 1;
        return 1;
    }
    return 0;
}

s32 WifiClubGameEntry_StopVoiceChat(WifiClubGameEntry *gameEntry) {
    if (gameEntry->voiceChatOn == 0) {
        return 0;
    }
    WifiConnection_StopVoiceChat();
    gameEntry->voiceChatOn = 0;
    return 1;
}

void WifiClubGameEntry_EnableVoiceChat(WifiClubGameEntry *gameEntry) {
    if (WifiClubGameEntry_StartVoiceChat(gameEntry) != 0) {
        GF_GetCurrentPlayingBGM();
        Sound_ApplyVoiceChatVolumeForSeq();
    }
}

void WifiClubGameEntry_DisableVoiceChat(WifiClubGameEntry *gameEntry) {
    if (WifiClubGameEntry_StopVoiceChat(gameEntry) != 0) {
        GF_SndHandleSetInitialVolume(0, 120);
    }
}

s32 WifiClubGameEntry_CountMembers(WifiClubGameEntry *gameEntry) {
    return CommPlayerInfo_CountAccepted();
}

s32 WifiClubGameEntry_AcceptEarlierMembers(WifiClubGameEntry *gameEntry, enum HeapID heapID) {
    s32 allAccepted = 1;
    for (s32 i = Comm_GetLocalNetId() - 1; i >= 0; i--) {
        if (CommPlayerInfo_IsReceived(i) == 1) {
            WifiClubGameEntry_AcceptMember(gameEntry, i, heapID);
        } else if (CommPlayerInfo_IsAccepted(i) == 0) {
            allAccepted = 0;
        }
    }
    return allAccepted;
}

void WifiClubGameEntry_RefusePendingApplicants(WifiClubGameEntry *gameEntry) {
    WifiClubGameEntryJoinAnswer answer;
    answer.answer = 0;
    for (s32 i = 1; i < 4; i++) {
        if (CommPlayerInfo_IsReceived(i) == 1) {
            answer.netId = i;
            GF_ASSERT(Comm_SendCommand(22, &answer, 8) == TRUE);
            CommPlayerInfo_ClearPlayer(i);
        }
    }
}

void WifiClubGameEntry_ReleaseAllMembers(WifiClubGameEntry *gameEntry) {
    WifiClubGameEntryJoinAnswer answer;
    answer.answer = 0;
    for (s32 i = 1; i < 4; i++) {
        if (CommPlayerInfo_IsReceivedOrAccepted(i) == 1) {
            answer.netId = i;
            GF_ASSERT(Comm_SendCommand(22, &answer, 8) == TRUE);
            CommPlayerInfo_ClearPlayer(i);
        }
    }
}

void WifiClubGameEntry_SetDisconnectCallback(WifiClubGameEntry *gameEntry) {
    WifiConnection_SetDisconnectCallback(WifiClubGameEntry_OnDisconnect, gameEntry);
}

void WifiClubGameEntry_ClearDisconnectCallback(WifiClubGameEntry *gameEntry) {
    WifiConnection_SetDisconnectCallback(0, 0);
}

s32 WifiClubGameEntry_CheckMemberDisconnected(WifiClubGameEntry *gameEntry) {
    s32 disconnected = 0;
    for (s32 i = 0; i < 4; i++) {
        if (gameEntry->disconnected[i] == 1) {
            if (CommPlayerInfo_IsAccepted(gameEntry->disconnectedNetIds[i]) == 1) {
                disconnected = 1;
            }
            gameEntry->disconnected[i] = 0;
            gameEntry->disconnectedNetIds[i] = 0;
        }
    }
    return disconnected;
}

void WifiClubGameEntry_OnDisconnect(u8 netId, WifiClubGameEntry *gameEntry, s32 arg2) {
    gameEntry->disconnected[netId] = 1;
    gameEntry->disconnectedNetIds[netId] = netId;
}

s32 WifiClubGameEntry_CheckMemberListChanged(WifiClubGameEntry *gameEntry) {
    s32 i;
    s32 ret = 0;
    for (i = 0; i < 4; i++) {
        if (gameEntry->shownVoiceChatFlags[i] != gameEntry->voiceChatFlags[i]) {
            ret = 1;
        }
        gameEntry->shownVoiceChatFlags[i] = gameEntry->voiceChatFlags[i];
    }

    if (gameEntry->memberListDirty != 0) {
        gameEntry->memberListDirty = 0;
        ret = 1;
    }

    return ret;
}

void WifiClubGameEntry_RequestMemberListRedraw(WifiClubGameEntry *gameEntry) {
    gameEntry->memberListDirty = 1;
}

void WifiClubGameEntry_AcceptMember(WifiClubGameEntry *gameEntry, s32 netId, enum HeapID heapID) {
    if (CommPlayerInfo_IsAccepted(netId) == 0) {
        CommPlayerInfo_Accept(netId);
        gameEntry->lastAcceptedNetId = netId;
        WifiClubGameEntry_AddMemberAvatar(gameEntry, netId, heapID);
        WifiClubGameEntry_RequestMemberListRedraw(gameEntry);
    }
}

void WifiClubGameEntry_AddMemberAvatar(WifiClubGameEntry *gameEntry, s32 netId, enum HeapID heapID) {
    Field2DObjectTemplate template;

    if (gameEntry->screen.avatars[netId].object == 0) {
        template = sWifiClubGameEntryAvatarTemplates[netId];

        if (netId != Comm_GetLocalNetId()) {
            PlayerProfile *playerProfile = CommPlayerInfo_GetProfile(netId);
            GF_ASSERT(playerProfile);
            template.spriteId = PlayerProfile_GetAvatar(playerProfile);
        } else if (gameEntry->clubStatus->trainerInfo[2] == 0) {
            template.spriteId = 0;
        } else {
            template.spriteId = 97;
        }
        gameEntry->screen.avatars[netId].object = Field2DObjectManager_AddObject(gameEntry->screen.objects, &template);
        if (Field2DObjectSpriteManager_IsCharLoaded(gameEntry->screen.drawers, template.spriteId) == 0) {
            Field2DObjectSpriteManager_LoadChar(gameEntry->screen.drawers, template.spriteId, 2, heapID);
        }

        gameEntry->screen.avatars[netId].drawer = Field2DObjectSpriteManager_CreateSprite(gameEntry->screen.drawers, gameEntry->screen.avatars[netId].object, 0, heapID);
        Field2DObjectSprite_SetVisible(gameEntry->screen.avatars[netId].drawer, 0);
        gameEntry->screen.avatars[netId].state++;
    }
}

void WifiClubGameEntry_UpdateAvatars(WifiClubGameEntry *gameEntry) {
    for (s32 i = 0; i < 4; i++) {
        WifiClubGameEntryAvatarFunc ov44_func = sWifiClubGameEntryAvatarFuncs[gameEntry->screen.avatars[i].state];
        ov44_func(gameEntry, &gameEntry->screen.avatars[i]);
    }
    Field2DObjectManager_Update(gameEntry->screen.objects);
    Field2DObjectSpriteManager_Update(gameEntry->screen.drawers);
}

void WifiClubGameEntry_DeleteAvatars(WifiClubGameEntry *gameEntry) {
    Field2DObjectSpriteManager_UnloadAllChars(gameEntry->screen.drawers);
    memset(&gameEntry->screen.avatars, 0, 48);
}

void WifiClubGameEntry_SendLeaderBusy(WifiClubGameEntry *gameEntry, s32 netId) {
    WifiClubGameEntryJoinAnswer answer;
    answer.netId = netId;
    answer.answer = 2;
    GF_ASSERT(Comm_SendCommand(22, &answer, 8) == 1);
}

void WifiClubGameEntry_RefuseLateApplicants(WifiClubGameEntry *gameEntry) {
    for (s32 i = 0; i < 4; i++) {
        if (((gameEntry->lastAcceptedNetId + 1) < i) && (CommPlayerInfo_IsReceived(i) == 1)) {
            WifiClubGameEntry_SendLeaderBusy(gameEntry, i);
            CommPlayerInfo_ClearPlayer(i);
        }
    }
}

void WifiClubGameEntry_AcceptAnnouncedMembers(WifiClubGameEntry *gameEntry, enum HeapID heapID) {
    for (s32 i = 0; i < 4; i++) {
        if ((gameEntry->acceptedByLeader[i] == 1) && (CommPlayerInfo_IsReceivedOrAccepted(i) == 1)) {
            WifiClubGameEntry_AcceptMember(gameEntry, i, heapID);
            gameEntry->acceptedByLeader[i] = 0;
            gameEntry->membersChanged = 1;
        }
    }
}

void WifiClubGameEntry_ShowWaitingIcon(WifiClubGameEntry *gameEntry) {
    GF_ASSERT(!gameEntry->screen.waitingIcon);
    gameEntry->screen.waitingIcon = WaitingIcon_New(&gameEntry->screen.windowList[0], 1);
}

void WifiClubGameEntry_HideWaitingIcon(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (gameEntry->screen.waitingIcon != 0) {
        WaitingIcon_Delete(gameEntry->screen.waitingIcon);
        gameEntry->screen.waitingIcon = 0;
        Options *options = Save_PlayerData_GetOptionsAddr(args->saveData);
        LoadUserFrameGfx2(gameEntry->screen.bgConfig, GF_BG_LYR_MAIN_1, 1, 2, Options_GetFrame(options), heapID);
    }
}

void WifiClubGameEntry_AvatarNone(WifiClubGameEntry *gameEntry, WifiClubGameEntryAvatar *avatar) {
}

void WifiClubGameEntry_AvatarStartSpin(WifiClubGameEntry *gameEntry, WifiClubGameEntryAvatar *avatar) {
    Field2DObjectSprite_SetAutoUpdate(avatar->drawer, 0);
    Field2DObjectSprite_StartLoopAnim(avatar->drawer);
    Field2DObjectSprite_SetVisible(avatar->drawer, 1);
    avatar->state = 2;
    s32 idx = Field2DObject_GetParam(avatar->object, FIELD2D_OBJECT_PARAM_DIRECTION);
    avatar->timer = sWifiClubGameEntryAvatarSpinFrames[idx] + 16;
}

void WifiClubGameEntry_AvatarUpdateSpin(WifiClubGameEntry *gameEntry, WifiClubGameEntryAvatar *avatar) {
    Field2DObjectSprite_UpdateAnim(avatar->drawer);
    avatar->timer = (avatar->timer - 1);
    if (avatar->timer <= 0) {
        Field2DObjectSprite_SyncAnim(avatar->drawer);
        Field2DObjectSprite_SetAutoUpdate(avatar->drawer, 1);
        avatar->state = 3;
    }
}

void WifiClubGameEntry_AvatarIdle(WifiClubGameEntry *gameEntry, WifiClubGameEntryAvatar *avatar) {
}

void WifiClubGameEntry_SendVoiceChatFlags(WifiClubGameEntry *gameEntry) {
    int changed = 0;
    if (CommPlayerInfo_Exists() != 0) {
        int acceptedCount = CommPlayerInfo_CountAccepted();
        if ((CommPlayerInfo_HasNewEntries() != 0) && (Comm_ParentQueueHasCommand(5) == 0)) {
            changed = 1;
        }
        int netId = 0;
        int voiceChat;
        if (acceptedCount > 0) {
            do {
                if (netId == 0) {
                    voiceChat = gameEntry->clubStatus->voiceChat;
                } else {
                    int friendIndex = CommPlayerInfo_GetFriendIndex(netId);
                    GF_ASSERT(friendIndex != 32);
                    voiceChat = gameEntry->clubStatus[(friendIndex + 1)].voiceChat;
                }
                if (voiceChat != gameEntry->voiceChatFlags[netId]) {
                    changed = 1;
                }
                gameEntry->voiceChatFlags[netId] = voiceChat;
                netId += 1;
            } while (netId < acceptedCount);
        }
        if (changed == 1) {
            u8 flags[4];
            memcpy(&flags, gameEntry->voiceChatFlags, 4);
            Comm_SendCommand(24, &flags, 4);
        }
    }
}

int WifiClubGameEntry_IsStartSynced(WifiClubGameEntry *gameEntry) {
    if (LinkSync_IsSynced(13) != 0) {
        return 1;
    }
    return 0;
}

void WifiClubGameEntry_StartTimeout(WifiClubGameEntry *gameEntry) {
    gameEntry->timeoutRunning = 1;
    gameEntry->timeoutTimer = 1800;
}

void WifiClubGameEntry_StopTimeout(WifiClubGameEntry *gameEntry) {
    gameEntry->timeoutRunning = 0;
}

s32 WifiClubGameEntry_HasTimedOut(WifiClubGameEntry *gameEntry) {
    if (gameEntry->timeoutRunning == 0) {
        return 0;
    }
    if (gameEntry->timeoutTimer > 0) {
        gameEntry->timeoutTimer--;
        return 0;
    }
    return 1;
}

s32 WifiClubGameEntry_Leader_Start(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (gameEntry->clubStatus->voiceChat == 1) {
        WifiClubGameEntry_EnableVoiceChat(gameEntry);
    }
    WifiConnection_SetDisconnectWhenAlone(0);
    CommState_SetErrorWatch(FALSE, TRUE);
    WifiClubGameEntry_AddMemberAvatar(gameEntry, Comm_GetLocalNetId(), heapID);
    gameEntry->state = 1;
    return 0;
}

// When the group is ready:\nA Button: Proceed   B Button: Cancel
s32 Wifi_PromptReadyMessage(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00107, heapID);
    gameEntry->state = 2;
    return 0;
}

s32 WifiClubGameEntry_Leader_HandleInput(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 netId;

    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    if (WifiClubGameEntry_IsAnyoneConnected(gameEntry) == 1) {
        netId = CommPlayerInfo_FindReceived();
        if ((netId != 255) && (gameEntry->applicantNetId != 0)) {
            if (CommPlayerInfo_GetFriendIndex(netId) == 32) {
                WifiClubGameEntryJoinAnswer answer;
                answer.netId = netId;
                answer.answer = 0;
                CommPlayerInfo_ClearPlayer(netId);
                GF_ASSERT(Comm_SendCommand(22, &answer, 8) == TRUE);
            } else {
                gameEntry->applicantNetId = netId;
            }
        }
    }
    if (gSystem.newKeys & PAD_BUTTON_A) {
        PlaySE(SEQ_SE_DP_DECIDE);
        if (WifiClubGameEntry_IsAnyoneConnected(gameEntry) == 0) {
            gameEntry->state = 6;
        } else if (args->minPlayers <= WifiClubGameEntry_CountMembers(gameEntry)) {
            gameEntry->state = 8;
        } else {
            gameEntry->state = 6;
        }
    } else if (gSystem.newKeys & PAD_BUTTON_B) {
        PlaySE(SEQ_SE_DP_DECIDE);
        gameEntry->state = 22;
    } else if (gameEntry->applicantNetId != 255) {
        PlaySE(SEQ_SE_DP_DECIDE);
        gameEntry->state = 3;
    } else if (gSystem.newKeys & PAD_BUTTON_X) {
        gameEntry->state = 30;
        PlaySE(SEQ_SE_DP_DECIDE);
    }
    return 0;
}

// Someone wishes to join.\nAccept this Trainer as a member?
s32 Wifi_PromptUserJoinRequest(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    WifiClubGameEntry_ShowApplicantInfo(&gameEntry->screen, args, gameEntry->applicantNetId, heapID);
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00108, heapID);
    gameEntry->state = 4;
    return 0;
}

s32 WifiClubGameEntry_Leader_ShowAcceptYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    gameEntry->screen.listMenu2D = Std_CreateYesNoMenu(gameEntry->screen.bgConfig, &sWifiClubGameEntryYesNoWindowTemplate, 48, 4, heapID);
    gameEntry->state = 5;
    return 0;
}

s32 WifiClubGameEntry_Leader_HandleAcceptYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 selection;

    selection = Handle2dMenuInput_DeleteOnFinish(gameEntry->screen.listMenu2D, heapID);
    if (selection != -1) {
        WifiClubGameEntryJoinAnswer answer;
        answer.netId = (s16)gameEntry->applicantNetId;
        if (selection == 0) {
            answer.answer = 1;
            WifiClubGameEntry_AcceptMember(gameEntry, gameEntry->applicantNetId, heapID);
            if (gameEntry->clubStatus->voiceChat == 1) {
                WifiClubGameEntry_StopVoiceChat(gameEntry);
                WifiClubGameEntry_EnableVoiceChat(gameEntry);
            }
            if (args->maxPlayers <= WifiClubGameEntry_CountMembers(gameEntry)) {
                gameEntry->state = 8;
            } else {
                gameEntry->state = 1;
            }
        } else {
            answer.answer = 0;
            CommPlayerInfo_ClearPlayer(gameEntry->applicantNetId);
            gameEntry->state = 1;
        }
        GF_ASSERT(Comm_SendCommand(22, &answer, 8) == TRUE);
        gameEntry->applicantNetId = 255;
        WifiClubGameEntry_HideApplicantInfo(&gameEntry->screen);
        gameEntry->screen.listMenu2D = NULL;
    }
    return 0;
}

// There aren’t enough members.\r
s32 Wifi_PromptInsufficientMembers(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00119, heapID);
    gameEntry->state = 7;
    return 0;
}

s32 WifiClubGameEntry_Leader_WaitNotEnoughMembers(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    gameEntry->state = 19;
    return 0;
}

// Are these members OK?
s32 Wifi_PromptConfirmMembers(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00111, heapID);
    gameEntry->state = 9;
    return 0;
}

s32 WifiClubGameEntry_Leader_ShowConfirmYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    gameEntry->screen.listMenu2D = Std_CreateYesNoMenu(gameEntry->screen.bgConfig, &sWifiClubGameEntryYesNoWindowTemplate, 48, 4, heapID);
    gameEntry->state = 10;
    return 0;
}

s32 WifiClubGameEntry_Leader_HandleConfirmYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 selection;

    selection = Handle2dMenuInput_DeleteOnFinish(gameEntry->screen.listMenu2D, heapID);
    if (selection != -1) {
        if (selection == 0) {
            gameEntry->state = 11;
        } else if (args->maxPlayers <= WifiClubGameEntry_CountMembers(gameEntry)) {
            gameEntry->state = 19;
        } else {
            gameEntry->state = 1;
        }
        gameEntry->screen.listMenu2D = NULL;
    }
    return 0;
}

// Communicating. Please stand by...
s32 WifiClubGameEntry_Leader_StartCommunicating(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    gameEntry->timer = 30;
    WifiClubGameEntry_RefusePendingApplicants(gameEntry);
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00102, heapID);
    WifiClubGameEntry_ShowWaitingIcon(gameEntry);
    WifiClubGameEntry_StartTimeout(gameEntry);
    gameEntry->state = 12;
    WifiConnection_ResetStopServerMatching();
    return 0;
}

s32 WifiClubGameEntry_Leader_WaitMembersConnected(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (Comm_CountConnected() != CommPlayerInfo_CountAccepted()) {
        WifiClubGameEntry_RefusePendingApplicants(gameEntry);
        return 0;
    }
    if (WifiConnection_StopServerMatching() == 0) {
        return 0;
    }
    WifiConnection_SetDisconnectWhenAlone(1);
    gameEntry->state = 13;
    return 0;
}

s32 WifiClubGameEntry_Leader_SendStartCommand(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (gameEntry->timer == 0) {
        if (Comm_SendCommand(23, NULL, 0) != 0) {
            gameEntry->state = 14;
        }
    } else {
        gameEntry->timer--;
    }
    return 0;
}

s32 WifiClubGameEntry_Leader_WaitStartSync(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (LinkSync_IsSynced(13) != 0) {
        WifiClubGameEntry_SetPlayingStatus(gameEntry, args);
        LinkSync_ClearPackets();
        LinkSync_StartSync(14);
        gameEntry->state = 15;
    }
    return 0;
}

s32 WifiClubGameEntry_Leader_SendStatus(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (LinkSync_IsSynced(14) != 0) {
        s16 status = (s16)gameEntry->clubStatus->status;
        if (LinkSync_SendPacket(Comm_GetLocalNetId(), &status) == 1) {
            gameEntry->state = 16;
        }
    }
    return 0;
}

s32 WifiClubGameEntry_Leader_CheckStatuses(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 i = 0;
    s32 memberCount = WifiClubGameEntry_CountMembers(gameEntry);
    s32 localNetId = Comm_GetLocalNetId();
    s32 readyCount = 0;

    for (i = 0; i < memberCount; i++) {
        if (localNetId != i) {
            u16 *packet = LinkSync_GetPacket(i);
            if (packet != NULL) {
                if (packet[0] == gameEntry->clubStatus->status) {
                    readyCount++;
                } else {
                    gameEntry->state = 27;
                }
            }
        } else {
            readyCount++;
        }
    }
    if (readyCount == memberCount) {
        gameEntry->state = 17;
    }
    return 0;
}

s32 WifiClubGameEntry_Leader_StartFinalSync(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    CommState_SetErrorWatch(TRUE, TRUE);
    LinkSync_StartSync(18);
    gameEntry->state = 18;
    return 0;
}

s32 WifiClubGameEntry_Leader_WaitFinalSync(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (LinkSync_IsSynced(18) != 0) {
        gameEntry->result = 1;
        WifiClubGameEntry_HideWaitingIcon(gameEntry, args, heapID);
        return 1;
    }
    return 0;
}

// Stop looking for members?
s32 Wifi_PromptStopFindingMembers(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00120, heapID);
    gameEntry->state = 20;
    return 0;
}

s32 WifiClubGameEntry_Leader_ShowStopSeekingYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    gameEntry->screen.listMenu2D = CreateYesNoMenu(gameEntry->screen.bgConfig, &sWifiClubGameEntryYesNoWindowTemplate, 48U, 4, 1, heapID);
    gameEntry->state = 21;
    return 0;
}

s32 WifiClubGameEntry_Leader_HandleStopSeekingYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 selection;

    selection = Handle2dMenuInput_DeleteOnFinish(gameEntry->screen.listMenu2D, heapID);
    if (selection != -1) {
        if (selection == 0) {
            gameEntry->state = 22;
        } else if (WifiClubGameEntry_IsAnyoneConnected(gameEntry) != 0) {
            if (args->maxPlayers <= WifiClubGameEntry_CountMembers(gameEntry)) {
                gameEntry->state = 8;
            } else {
                gameEntry->state = 1;
            }
        } else {
            gameEntry->state = 1;
        }
        gameEntry->screen.listMenu2D = NULL;
    }
    return 0;
}

// If the leader drops out, the group will\nbe disbanded. Is that OK?
s32 Wifi_PromptDropAsLeader(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00121, heapID);
    gameEntry->state = 23;
    return 0;
}

s32 WifiClubGameEntry_Leader_ShowDisbandYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    gameEntry->screen.listMenu2D = CreateYesNoMenu(gameEntry->screen.bgConfig, &sWifiClubGameEntryYesNoWindowTemplate, 48, 4, 1, heapID);
    gameEntry->state = 24;
    return 0;
}

s32 WifiClubGameEntry_Leader_HandleDisbandYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 selection;

    selection = Handle2dMenuInput_DeleteOnFinish(gameEntry->screen.listMenu2D, heapID);
    if (selection != -1) {
        if (selection == 0) {
            gameEntry->state = 25;
        } else if (WifiClubGameEntry_IsAnyoneConnected(gameEntry) != 0) {
            if (args->maxPlayers <= WifiClubGameEntry_CountMembers(gameEntry)) {
                gameEntry->state = 8;
            } else {
                gameEntry->state = 1;
            }
        } else {
            gameEntry->state = 1;
        }
        gameEntry->screen.listMenu2D = NULL;
    }
    return 0;
}

// The member invitations will be canceled.
s32 Wifi_PromptCancelInvites(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00122, heapID);
    gameEntry->timer = 30;
    gameEntry->state = 26;
    return 0;
}

s32 WifiClubGameEntry_Leader_Cancel(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 timer;

    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    timer = gameEntry->timer - 1;
    gameEntry->timer = timer;
    if (timer > 0) {
        return 0;
    }
    gameEntry->result = 0;
    CommState_LeaveWifiMatch();
    WifiClubGameEntry_ReleaseAllMembers(gameEntry);
    CommState_SetWifiClubLinkMode();
    CommState_SetErrorWatch(FALSE, TRUE);
    return 1;
}

s32 WifiClubGameEntry_Leader_OnMemberDropped(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (gameEntry->screen.listMenu2D != NULL) {
        Clear2dMenuWindowAndDelete(gameEntry->screen.listMenu2D, heapID);
        gameEntry->screen.listMenu2D = NULL;
    }
    WifiClubGameEntry_HideApplicantInfo(&gameEntry->screen);
    WifiClubGameEntry_HideWaitingIcon(gameEntry, args, heapID);
    gameEntry->state = 28;
    return 0;
}

// A member had to drop out.\nPlease register from the start again.\r
s32 Wifi_PromptMemberDropped(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00118, heapID);
    gameEntry->state = 29;
    WifiClubGameEntry_ReleaseAllMembers(gameEntry);
    WifiClubGameEntry_SetPlayingStatus(gameEntry, args);
    if ((u32)(CommState_GetWifiMatchStatus() - WIFI_MATCH_STATUS_DISCONNECTED) <= 1U) {
        DWC_ProcessFriendsMatch();
    }
    return 0;
}

s32 WifiClubGameEntry_Leader_EndAfterMemberDropped(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if ((u32)(CommState_GetWifiMatchStatus() - WIFI_MATCH_STATUS_DISCONNECTED) <= 1) {
        DWC_ProcessFriendsMatch();
    }
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    CommState_LeaveWifiMatch();
    CommState_SetWifiClubLinkMode();
    WifiClubGameEntry_ReleaseAllMembers(gameEntry);
    gameEntry->result = 0;
    CommState_SetErrorWatch(FALSE, TRUE);
    return 1;
}

s32 Wifi_PromptToggleVoiceChat(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 strno;

    if (gameEntry->clubStatus->voiceChat == 1) {
        // Is it OK to turn off the Voice Chat?
        strno = msg_0778_00125;
    } else {
        // Is it OK to turn on the Voice Chat?
        strno = msg_0778_00124;
    }
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, strno, heapID);
    gameEntry->state = 31;
    return 0;
}

s32 WifiClubGameEntry_Leader_ShowVoiceChatYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    gameEntry->screen.listMenu2D = Std_CreateYesNoMenu(gameEntry->screen.bgConfig, &sWifiClubGameEntryYesNoWindowTemplate, 48, 4, heapID);
    gameEntry->state = 32;
    return 0;
}

s32 WifiClubGameEntry_Leader_HandleVoiceChatYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 selection;

    selection = Handle2dMenuInput_DeleteOnFinish(gameEntry->screen.listMenu2D, heapID);
    if (selection != -1) {
        if (selection == 0) {
            WifiClubGameEntry_ToggleVoiceChat(gameEntry, heapID);
            WifiClubGameEntry_RequestMemberListRedraw(gameEntry);
        }
        gameEntry->state = 1;
        gameEntry->screen.listMenu2D = NULL;
    }
    return 0;
}

s32 WifiClubGameEntry_Member_Start(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    CommPlayerInfo_SendLocal();
    CommState_SetErrorWatch(FALSE, TRUE);
    WifiClubGameEntry_StartTimeout(gameEntry);
    gameEntry->state = 1;
    return 0;
}

s32 WifiClubGameEntry_Member_WaitLeaderInfo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    WifiClubGameEntry_AcceptEarlierMembers(gameEntry, heapID);
    if (Comm_IsNetIdConnected(0) == 0) {
        WifiClubGameEntry_StopTimeout(gameEntry);
        gameEntry->state = 15;
    } else if (CommPlayerInfo_IsAccepted(0) != 0) {
        WifiClubGameEntry_StopTimeout(gameEntry);
        gameEntry->state = 2;
    }
    return 0;
}

// Awaiting {STRVAR_1 3, 0, 0}’s response...
s32 Wifi_PromptAwaitingResponse(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    WifiClubGameEntry_AcceptEarlierMembers(gameEntry, heapID);
    WifiClubGameEntry_BufferPlayerName(&gameEntry->screen, args, 0, 0, heapID);
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00114, heapID);
    WifiClubGameEntry_ShowWaitingIcon(gameEntry);
    gameEntry->state = 3;
    return 0;
}

s32 WifiClubGameEntry_Member_WaitJoinAnswer(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    u8 joinAnswer;

    WifiClubGameEntry_AcceptEarlierMembers(gameEntry, heapID);
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    if (gameEntry->joinAnswer != 0) {
        WifiClubGameEntry_HideWaitingIcon(gameEntry, args, heapID);
        joinAnswer = gameEntry->joinAnswer;
        switch (joinAnswer) {
        case 1:
            gameEntry->state = 4;
            break;
        case 2:
            gameEntry->state = 6;
            gameEntry->refusedMsg = 116;
            break;
        case 3:
            gameEntry->state = 6;
            gameEntry->refusedMsg = 132;
            break;
        }
    }
    return 0;
}

// {STRVAR_1 3, 0, 0} approved your\nmember-registration request.
s32 WifiClubGameEntry_Member_PrintApproved(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    WifiClubGameEntry_BufferPlayerName(&gameEntry->screen, args, 0, 0, heapID);

    Wifi_LoadAndPrintTextToWindow(&gameEntry->screen, args, msg_0778_00115, 30, heapID);
    gameEntry->state = 5;
    WifiClubGameEntry_AcceptMember(gameEntry, Comm_GetLocalNetId(), HEAP_ID_103);
    return 0;
}

s32 WifiClubGameEntry_Member_WaitApproved(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    WifiClubGameEntry_AcceptEarlierMembers(gameEntry, heapID);
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    gameEntry->state = 8;
    return 0;
}

s32 WifiClubGameEntry_Member_PrintRefused(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    WifiClubGameEntry_BufferPlayerName(&gameEntry->screen, args, 0, 0, heapID);
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, gameEntry->refusedMsg, heapID);
    gameEntry->state = 7;
    CommState_LeaveWifiMatch();
    CommState_SetWifiClubLinkMode();
    return 0;
}

s32 WifiClubGameEntry_Member_EndRefused(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    gameEntry->result = 0;
    CommState_SetErrorWatch(FALSE, TRUE);
    return 1;
}

// Awaiting other members.
s32 Wifi_PromptAwaitingMembers(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    WifiClubGameEntry_AcceptEarlierMembers(gameEntry, heapID);
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00123, heapID);
    WifiClubGameEntry_ShowWaitingIcon(gameEntry);
    gameEntry->state = 9;
    if (gameEntry->clubStatus->voiceChat == 1) {
        WifiClubGameEntry_EnableVoiceChat(gameEntry);
    }
    return 0;
}

s32 WifiClubGameEntry_Member_WaitAwaitingMessage(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    WifiClubGameEntry_AcceptEarlierMembers(gameEntry, heapID);
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    gameEntry->state = 10;
    return 0;
}

// Communicating. Please stand by...
s32 WifiClubGameEntry_Member_WaitStart(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    WifiClubGameEntry_AcceptEarlierMembers(gameEntry, heapID);
    if (gameEntry->membersChanged != 0) {
        gameEntry->membersChanged = 0U;
        if (gameEntry->clubStatus->voiceChat == 1) {
            WifiClubGameEntry_StopVoiceChat(gameEntry);
            WifiClubGameEntry_EnableVoiceChat(gameEntry);
        }
        WifiClubGameEntry_RequestMemberListRedraw(gameEntry);
    }
    if (WifiClubGameEntry_IsStartSynced(gameEntry) == 1) {
        LinkSync_ClearPackets();
        LinkSync_StartSync(14);
        WifiClubGameEntry_HideWaitingIcon(gameEntry, args, heapID);
        Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00102, heapID);
        WifiClubGameEntry_StartTimeout(gameEntry);
        gameEntry->timer = 300;
        WifiClubGameEntry_ShowWaitingIcon(gameEntry);
        gameEntry->state = 11;
    } else if (gSystem.newKeys & PAD_BUTTON_X) {
        WifiClubGameEntry_HideWaitingIcon(gameEntry, args, heapID);
        gameEntry->state = 18;
    }
    return 0;
}

s32 WifiClubGameEntry_Member_SendStatus(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 timer;

    if (LinkSync_IsSynced(14) != 0) {
        s16 status = (s16)gameEntry->clubStatus->status;
        if (WifiClubGameEntry_CountMembers(gameEntry) != Comm_CountConnected()) {
            timer = gameEntry->timer - 1;
            gameEntry->timer = timer;
            if (timer <= 0) {
                gameEntry->state = 15;
            }
            return 0;
        }
        if (LinkSync_SendPacket(Comm_GetLocalNetId(), &status) == 1) {
            gameEntry->state = 12;
        }
    }
    return 0;
}

s32 WifiClubGameEntry_Member_CheckStatuses(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 i = 0;
    s32 memberCount = WifiClubGameEntry_CountMembers(gameEntry);
    s32 localNetId = Comm_GetLocalNetId();
    s32 readyCount = 0;

    for (i = 0; i < memberCount; i++) {
        if (localNetId != i) {
            u16 *packet = LinkSync_GetPacket(i);
            if (packet != NULL) {
                if (packet[0] == gameEntry->clubStatus->status) {
                    readyCount++;
                } else {
                    gameEntry->state = 0xF;
                }
            }
        } else {
            readyCount++;
        }
    }

    if (readyCount == memberCount) {
        gameEntry->state = 0xD;
    }
    return 0;
}

s32 WifiClubGameEntry_Member_StartFinalSync(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    CommState_SetErrorWatch(TRUE, TRUE);
    LinkSync_StartSync(18);
    gameEntry->state = 14;
    return 0;
}

s32 WifiClubGameEntry_Member_WaitFinalSync(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (LinkSync_IsSynced(18) != 0) {
        WifiClubGameEntry_HideWaitingIcon(gameEntry, args, heapID);
        gameEntry->result = 1;
        return 1;
    }
    return 0;
}

s32 WifiClubGameEntry_Member_OnDropped(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (gameEntry->screen.listMenu2D != NULL) {
        Clear2dMenuWindowAndDelete(gameEntry->screen.listMenu2D, heapID);
        gameEntry->screen.listMenu2D = NULL;
    }
    WifiClubGameEntry_HideApplicantInfo(&gameEntry->screen);
    WifiClubGameEntry_HideWaitingIcon(gameEntry, args, heapID);
    gameEntry->state = 16;
    return 0;
}

// A member had to drop out.\nPlease register from the start again.\r
s32 Wifi_PromptMemberDrop(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00118, heapID);
    gameEntry->state = 17;
    return 0;
}

s32 WifiClubGameEntry_Member_EndAfterDropped(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    CommState_LeaveWifiMatch();
    CommState_SetWifiClubLinkMode();
    gameEntry->result = 0;
    CommState_SetErrorWatch(FALSE, TRUE);
    return 1;
}

s32 Wifi_PromptToggleVoiceChat_(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 strno;

    WifiClubGameEntry_AcceptEarlierMembers(gameEntry, heapID);
    if (gameEntry->clubStatus->voiceChat == 1) {
        // Is it OK to turn off the Voice Chat?
        strno = msg_0778_00125;
    } else {
        // Is it OK to turn on the Voice Chat?
        strno = msg_0778_00124;
    }
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, strno, heapID);
    gameEntry->state = 19;
    return 0;
}

s32 WifiClubGameEntry_Member_ShowVoiceChatYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    WifiClubGameEntry_AcceptEarlierMembers(gameEntry, heapID);
    if (WifiClubGameEntry_IsStartSynced(gameEntry) == 1) {
        gameEntry->state = 10;
        WifiClubGameEntry_ClearMessage(&gameEntry->screen);
        return 0;
    }
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    gameEntry->screen.listMenu2D = Std_CreateYesNoMenu(gameEntry->screen.bgConfig, &sWifiClubGameEntryYesNoWindowTemplate, 48, 4, heapID);
    gameEntry->state = 20;
    return 0;
}

s32 WifiClubGameEntry_Member_HandleVoiceChatYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 selection;

    WifiClubGameEntry_AcceptEarlierMembers(gameEntry, heapID);
    if (WifiClubGameEntry_IsStartSynced(gameEntry) == 1) {
        gameEntry->state = 10;
        WifiClubGameEntry_ClearMessage(&gameEntry->screen);
        Clear2dMenuWindowAndDelete(gameEntry->screen.listMenu2D, heapID);
        gameEntry->screen.listMenu2D = 0;
        return 0;
    }
    selection = Handle2dMenuInput_DeleteOnFinish(gameEntry->screen.listMenu2D, heapID);
    if (selection != -1) {
        if (selection == 0) {
            WifiClubGameEntry_ToggleVoiceChat(gameEntry, heapID);
            WifiClubGameEntry_RequestMemberListRedraw(gameEntry);
        }
        gameEntry->state = 8;
        gameEntry->screen.listMenu2D = 0;
    }
    return 0;
}

// The leader appears busy.\nPlease apply again.\r
s32 WifiClubGameEntry_Member_PrintLeaderBusy(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    gameEntry->leaderFriendIndex = CommPlayerInfo_GetFriendIndex(0);
    GF_ASSERT(gameEntry->leaderFriendIndex != 32);
    WifiClubGameEntry_BufferPlayerName(&gameEntry->screen, args, 0, 0, heapID);
    CommState_LeaveWifiMatch();
    gameEntry->watchConnection = 0;
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00132, heapID);
    gameEntry->state = 22;
    return 0;
}

s32 WifiClubGameEntry_Member_ShowApplyAgainYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    gameEntry->screen.listMenu2D = Std_CreateYesNoMenu(gameEntry->screen.bgConfig, &sWifiClubGameEntryYesNoWindowTemplate, 48, 4, heapID);
    gameEntry->state = 23;
    return 0;
}

s32 WifiClubGameEntry_Member_HandleApplyAgainYesNo(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    s32 selection;
    s8 nextState;

    selection = Handle2dMenuInput_DeleteOnFinish(gameEntry->screen.listMenu2D, heapID);
    if (selection != -1) {
        if (selection == 0) {
            nextState = 24;
        } else {
            nextState = 29;
        }
        gameEntry->state = nextState;
        gameEntry->screen.listMenu2D = 0;
    }
    return 0;
}

// Communicating with {STRVAR_1 3, 0, 0}...
s32 WifiClubGameEntry_Member_PrintContacting(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    Wifi_LoadAndPrintTextToWindowWrapper(&gameEntry->screen, args, msg_0778_00017, heapID);
    WifiClubGameEntry_ShowWaitingIcon(gameEntry);
    gameEntry->timer = 90;
    gameEntry->state = 25;
    return 0;
}

s32 WifiClubGameEntry_Member_ApplyAgain(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (gameEntry->timer > 0) {
        gameEntry->timer = gameEntry->timer - 1;
        return 0;
    }
    if (WifiClubGameEntry_IsMessageFinished(&gameEntry->screen) == 0) {
        return 0;
    }
    if (WifiClubGameEntry_StartMatch(gameEntry->leaderFriendIndex, args->game) != 0) {
        gameEntry->state = 26;
    }
    return 0;
}

s32 WifiClubGameEntry_Member_WaitReconnected(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    WifiClubGameEntry_CheckMatchFailed(gameEntry);
    if (CommState_GetWifiMatchStatus() == WIFI_MATCH_STATUS_CONNECTED && Comm_IsNetIdConnected(0) == 1) {
        Comm_SetWifiContinuousSend(0);
        WifiClubGameEntry_HideWaitingIcon(gameEntry, args, heapID);
        BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, heapID);
        gameEntry->state = 27;
    }
    return 0;
}

s32 WifiClubGameEntry_Member_RebuildScreen(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    u8 *flags;

    if (IsPaletteFadeFinished()) {
        CommPlayerInfo_Init(args->saveData, 0);
        gameEntry->watchConnection = 1;
        WifiClubGameEntry_DeleteAvatars(gameEntry);
        WifiClubGameEntry_FreeScreen(gameEntry, heapID);
        gameEntry = gameEntry;
        memset(&gameEntry->screen, 0, 504);
        WifiClubGameEntry_SetDisconnectCallback(gameEntry);
        WifiClubGameEntry_InitScreen(gameEntry, args, heapID);
        WirelessStatusIcon_Create();
        gameEntry->membersChanged = 0;
        gameEntry->joinAnswer = 0;
        flags = gameEntry->disconnected;
        gameEntry->disconnected[0] = 0;
        flags[1] = 0;
        flags[2] = 0;
        flags[3] = 0;
        flags = gameEntry->disconnectedNetIds;
        gameEntry->disconnectedNetIds[0] = 0;
        flags[1] = 0;
        flags[2] = 0;
        flags[3] = 0;
        MI_CpuFill8(&gameEntry->shownVoiceChatFlags, 1, 4);
        MI_CpuFill8(&gameEntry->voiceChatFlags, 1, 4);
        flags = gameEntry->acceptedByLeader;
        gameEntry->memberListDirty = 0;
        gameEntry->leaderFriendIndex = 0;
        gameEntry->acceptedByLeader[0] = 0;
        flags[1] = 0;
        flags[2] = 0;
        flags[3] = 0;
        BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, heapID);
        gameEntry->state = 28;
    }
    return 0;
}

s32 WifiClubGameEntry_Member_WaitFadeIn(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    if (IsPaletteFadeFinished() != 0) {
        gameEntry->state = 0;
    }
    return 0;
}

s32 WifiClubGameEntry_Member_Cancel(WifiClubGameEntry *gameEntry, WifiClubGameEntryArgs *args, enum HeapID heapID) {
    CommState_LeaveWifiMatch();
    CommState_SetWifiClubLinkMode();
    gameEntry->result = 0;
    CommState_SetErrorWatch(FALSE, TRUE);
    return 1;
}
