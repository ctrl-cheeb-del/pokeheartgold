#include "wifi_plaza/wifi_plaza_game_entry.h"

#include "global.h"

#include "constants/sndseq.h"

#include "msgdata/msg/msg_0776.h"
#include "msgdata/msg/msg_0777.h"

#include "comm_state.h"
#include "comm_state_internal.h"
#include "communication_core.h"
#include "communication_player_state.h"
#include "font.h"
#include "link_synchronization.h"
#include "sound_playback.h"
#include "system.h"

enum WiFiPlazaRegisterStep {
    WIFI_PLAZA_REGISTER_INIT,
    WIFI_PLAZA_REGISTER_CHECK_OPEN,
    WIFI_PLAZA_REGISTER_ASK_PLAY,
    WIFI_PLAZA_REGISTER_OPEN_MENU,
    WIFI_PLAZA_REGISTER_HANDLE_MENU,
    WIFI_PLAZA_REGISTER_SHOW_RULES,
    WIFI_PLAZA_REGISTER_JOIN,
    WIFI_PLAZA_REGISTER_WAIT_MEMBERS,
    WIFI_PLAZA_REGISTER_WAIT_LINK,
    WIFI_PLAZA_REGISTER_START_LINK,
    WIFI_PLAZA_REGISTER_SEND_PLAYER_INFO,
    WIFI_PLAZA_REGISTER_RECEIVE_PLAYER_INFO,
    WIFI_PLAZA_REGISTER_START_ID_EXCHANGE,
    WIFI_PLAZA_REGISTER_SEND_LOBBY_ID,
    WIFI_PLAZA_REGISTER_RECEIVE_LOBBY_IDS,
    WIFI_PLAZA_REGISTER_START_GAME,
    WIFI_PLAZA_REGISTER_ASK_DROP_OUT,
    WIFI_PLAZA_REGISTER_WAIT_ASK_DROP_OUT,
    WIFI_PLAZA_REGISTER_OPEN_YES_NO,
    WIFI_PLAZA_REGISTER_HANDLE_YES_NO,
    WIFI_PLAZA_REGISTER_RESUME_WAITING,
    WIFI_PLAZA_REGISTER_SESSION_FILLED,
    WIFI_PLAZA_REGISTER_TIME_UP,
    WIFI_PLAZA_REGISTER_END_LINK,
    WIFI_PLAZA_REGISTER_WAIT_END_LINK,
    WIFI_PLAZA_REGISTER_WAIT_MESSAGE,
    WIFI_PLAZA_REGISTER_SYNC,
    WIFI_PLAZA_REGISTER_WAIT_SYNC,
    WIFI_PLAZA_REGISTER_END,
};

enum WiFiPlazaGameEntryMenuItem {
    WIFI_PLAZA_GAME_ENTRY_MENU_JOIN,
    WIFI_PLAZA_GAME_ENTRY_MENU_RULES,
    WIFI_PLAZA_GAME_ENTRY_MENU_CANCEL,
};

enum WiFiPlazaEndLinkStep {
    WIFI_PLAZA_END_LINK_START,
    WIFI_PLAZA_END_LINK_WAIT_LOBBY,
};

enum WiFiPlazaSignStep {
    WIFI_PLAZA_SIGN_SHOW,
    WIFI_PLAZA_SIGN_WAIT_INPUT,
};

static void WiFiPlazaGameEntry_PrintMessage(WiFiPlazaGameEntry *entry, WiFiPlazaPlayerState *state, WiFiPlazaRoomWork *room, u32 msgId, u32 nextStep);
static void WiFiPlazaGameEntry_StartSync(WiFiPlazaGameEntry *entry, WiFiPlazaPlayerState *state, u8 nextStep, u8 syncId);
static void WiFiPlazaGameEntry_InitMenu(WiFiPlazaGameEntry *entry, WiFiPlazaRoomWork *room, u32 count, u32 firstMsg);
static void WiFiPlazaGameEntry_FreeMenu(WiFiPlazaGameEntry *entry, WiFiPlazaRoomWork *room);
static BOOL WiFiPlazaGameEntry_UpdateWaiting(WiFiPlazaGameEntry *entry, WiFiPlazaRoomWork *room, WiFiPlazaGameEntryParam *param, WiFiPlazaPlayerState *state, int playerIndex);
static void WiFiPlazaGameStatus_Open(WiFiPlazaGameStatus *status, WiFiPlazaRoomWork *room, u32 game, u32 showSeconds, s32 frames);
static void WiFiPlazaGameStatus_Close(WiFiPlazaGameStatus *status, WiFiPlazaRoomWork *room);
static void WiFiPlazaGameStatus_SetFrames(WiFiPlazaGameStatus *status, s32 frames);
static void WiFiPlazaGameStatus_Update(WiFiPlazaGameStatus *status, WiFiPlazaRoomWork *room, u32 force);
static void WiFiPlazaGameStatus_UpdateInPlay(WiFiPlazaGameStatus *status, WiFiPlazaRoomWork *room, u32 force);
static void WiFiPlazaGameStatus_Draw(WiFiPlazaGameStatus *status, WiFiPlazaRoomWork *room, u32 force, u32 showInPlay);

static const u8 sWiFiPlazaGameStatusHeights[2] = { 8, 10 };

static const ListMenuTemplate sWiFiPlazaGameEntryMenuTemplate = {
    .items = NULL,
    .moveCursorFunc = NULL,
    .itemPrintFunc = NULL,
    .window = NULL,
    .totalItems = 0,
    .maxShowed = 3,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 0,
    .cursorPal = 1,
    .fillValue = 15,
    .cursorShadowPal = 2,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 0,
    .cursorKind = 0,
    .data = NULL,
};

BOOL WiFiPlazaGameEntry_Register(WiFiPlazaPlayerState *state, WiFiPlazaRoomWork *room, u32 playerIndex) {
    u8 memberIds[4];
    WiFiPlazaWork *lobby;
    s32 connection;
    u32 memberCount __attribute__((aligned(8)));
    s32 myNetId;
    s32 hostFound;
    s32 hostId;
    s32 failed;
    int savedPlayerIndex;
    WiFiPlazaPlayerState *savedState;
    u16 *packet;
    s32 netId;
    s32 timeout;
    s32 yesNo;
    s32 linkState;
    String *message;
    String *message2;
    s32 msgId;
    s32 i;
    s32 msgId2;
    s32 closeMenu;
    s32 received;
    s8 delay;
    u32 step;
    u32 members3;
    u32 linkError;
    u32 step2;
    u32 menuResult;
    u32 linkError2;
    u32 accepted2;
    u32 accepted;
    u32 members;
    u32 members2;
    WiFiPlazaGameEntry *entry;
    WiFiPlazaGameEntryParam *param;

    savedState = state;
    savedPlayerIndex = playerIndex;
    param = WiFiPlazaPlayerState_GetArg(state);
    entry = WiFiPlazaPlayerState_GetWork(state);
    lobby = WiFiPlazaRoom_GetLobby(room);

    // while waiting or linking: give up when the session or the link broke down
    step = WiFiPlazaPlayerState_GetStep(state);
    switch (step) {
    case WIFI_PLAZA_REGISTER_START_LINK:
    case WIFI_PLAZA_REGISTER_SEND_PLAYER_INFO:
    case WIFI_PLAZA_REGISTER_RECEIVE_PLAYER_INFO:
    case WIFI_PLAZA_REGISTER_START_ID_EXCHANGE:
    case WIFI_PLAZA_REGISTER_SEND_LOBBY_ID:
    case WIFI_PLAZA_REGISTER_RECEIVE_LOBBY_IDS:
    case WIFI_PLAZA_REGISTER_SYNC:
    case WIFI_PLAZA_REGISTER_WAIT_SYNC:
        if ((u32)entry->members > WiFiPlazaLobbyClient_GetMatchPlayerCount(param->slot)) {
            param->result = WIFI_PLAZA_GAME_ENTRY_LINK_ERROR;
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
        } else if ((s32)entry->members > Comm_CountConnected()) {
            param->result = WIFI_PLAZA_GAME_ENTRY_LINK_ERROR;
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
        } else if (CommState_GetPlazaMatchStatus() == 0) {
            param->result = WIFI_PLAZA_GAME_ENTRY_LINK_ERROR;
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
        } else {
        case WIFI_PLAZA_REGISTER_WAIT_LINK:
            if (WiFiPlazaLobbyClient_IsMatchHost() == 1 && WiFiPlazaLobbyClient_GetMatchPlayerCount(param->slot) <= 1) {
                param->result = WIFI_PLAZA_GAME_ENTRY_LINK_ERROR;
                WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
            } else {
                timeout = entry->timeout - 1;
                entry->timeout = timeout;
                if (timeout < 0) {
                    param->result = WIFI_PLAZA_GAME_ENTRY_LINK_ERROR;
                    WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
                } else {
                case WIFI_PLAZA_REGISTER_WAIT_MEMBERS:
                case WIFI_PLAZA_REGISTER_WAIT_ASK_DROP_OUT:
                case WIFI_PLAZA_REGISTER_OPEN_YES_NO:
                case WIFI_PLAZA_REGISTER_HANDLE_YES_NO:
                case WIFI_PLAZA_REGISTER_RESUME_WAITING:
                case WIFI_PLAZA_REGISTER_SESSION_FILLED:
                case WIFI_PLAZA_REGISTER_TIME_UP:
                    linkError = CommState_GetWifiMatchStatus();
                    switch (linkError) {
                    case WIFI_MATCH_STATUS_LOBBY:
                    case WIFI_MATCH_STATUS_CONNECTED:
                        break;
                    case WIFI_MATCH_STATUS_OTHER:
                    case WIFI_MATCH_STATUS_TIMED_OUT:
                    case WIFI_MATCH_STATUS_DISCONNECTED:
                    case WIFI_MATCH_STATUS_CANCELLED:
                        param->result = WIFI_PLAZA_GAME_ENTRY_LINK_ERROR;
                        WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
                        break;
                    }
                }
            }
        }
        break;
    }

    step2 = WiFiPlazaPlayerState_GetStep(savedState);
    switch (step2) {
    case WIFI_PLAZA_REGISTER_INIT:
        WiFiPlazaPlayerState_AllocWork(savedState, sizeof(WiFiPlazaGameEntry));
        WiFiPlazaPlayerState_NextStep(savedState);
    default:
        break;
    case WIFI_PLAZA_REGISTER_CHECK_OPEN:
        if (WiFiPlazaWork_IsGameEntryCoolingDown(lobby)) {
            param->result = WIFI_PLAZA_GAME_ENTRY_NOT_READY;
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END);
        } else if (WiFiPlazaWork_GetEventScheduleMode5(lobby) != 0) {
            param->result = WIFI_PLAZA_GAME_ENTRY_PLAZA_CLOSING;
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END);
        } else {
            PlaySE(SEQ_SE_DP_DECIDE);
            WiFiPlazaPlayerState_NextStep(savedState);
        }
        break;
    case WIFI_PLAZA_REGISTER_ASK_PLAY: // "Would you like to play ...?"
        WiFiPlazaRoom_BufferActivityName(room, param->game, 0);
        WiFiPlazaGameEntry_PrintMessage(entry, savedState, room, msg_0776_00000, WIFI_PLAZA_REGISTER_OPEN_MENU);
        break;
    case WIFI_PLAZA_REGISTER_OPEN_MENU: // JOIN / RULES / CANCEL
        WiFiPlazaGameEntry_InitMenu(entry, room, 3, 1);
        WiFiPlazaRoom_OpenList(room, &entry->menuTemplate, 0, 0);
        WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_HANDLE_MENU);
        break;
    case WIFI_PLAZA_REGISTER_HANDLE_MENU:
        closeMenu = 0;
        menuResult = WiFiPlazaRoom_ProcessList(room);
        switch (menuResult) {
        case LIST_CANCEL:
        case WIFI_PLAZA_GAME_ENTRY_MENU_CANCEL:
            param->result = WIFI_PLAZA_GAME_ENTRY_CANCELLED;
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END);
            closeMenu = 1;
            break;
        case WIFI_PLAZA_GAME_ENTRY_MENU_RULES:
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_SHOW_RULES);
            closeMenu = 1;
            break;
        case WIFI_PLAZA_GAME_ENTRY_MENU_JOIN:
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_JOIN);
            closeMenu = 1;
            break;
        }
        if (closeMenu == 1) {
            WiFiPlazaRoom_CloseList(room, NULL, NULL);
            WiFiPlazaGameEntry_FreeMenu(entry, room);
        }
        break;
    case WIFI_PLAZA_REGISTER_SHOW_RULES:
        WiFiPlazaRoom_BufferActivityName(room, param->game, 0);
        WiFiPlazaGameEntry_PrintMessage(entry, savedState, room, param->game + 0x22, WIFI_PLAZA_REGISTER_ASK_PLAY);
        break;
    case WIFI_PLAZA_REGISTER_JOIN:
        if (WiFiPlazaWork_GetEventScheduleMode5(lobby) != 0) {
            param->result = WIFI_PLAZA_GAME_ENTRY_PLAZA_CLOSING;
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END);
        } else {
            if (WiFiPlazaLobbyClient_IsMatchActive(param->slot) == TRUE) {
                if (WiFiPlazaLobbyClient_GetMatchFreePlaces(param->slot) == 0 || !WiFiPlazaLobbyClient_IsMatchOpen(param->slot)) {
                    param->result = WIFI_PLAZA_GAME_ENTRY_SESSION_FULL;
                    WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END);
                    break;
                }
                if ((s16)WiFiPlazaLobbyClient_GetMatchTimer(param->slot) == 0) {
                    param->result = WIFI_PLAZA_GAME_ENTRY_NOT_READY;
                    WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END);
                    break;
                }
            }
            entry->timeLeft = WiFiPlazaLobbyClient_GetMatchTimer(param->slot);
            entry->timeout = 30 * 30;
            if (entry->timeLeft > 330) {
                message = WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_GAME_ENTRY, msg_0776_00010);
            } else {
                entry->startingSoon = TRUE;
                message = WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_GAME_ENTRY, msg_0776_00011);
            }
            WiFiPlazaRoom_PrintMessageInstant(room, message);
            WiFiPlazaRoom_ShowWaitingIcon(room);
            CommState_StartPlazaMatch(param->slot);
            if (WiFiPlazaLobbyClient_IsMatchHost() == 1) {
                WiFiPlaza_SendActivityNews(lobby, param->game, 1, savedPlayerIndex, 0, 0, 0, 0);
                entry->reportedMembers = 1;
            }
            WiFiPlazaGameStatus_Open(&entry->status, room, param->game, TRUE, entry->timeLeft);
            WiFiPlazaGameStatus_UpdateInPlay(&entry->status, room, TRUE);
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_WAIT_MEMBERS);
        }
        break;
    case WIFI_PLAZA_REGISTER_WAIT_MEMBERS:
        connection = CommState_GetPlazaMatchStatus();
        members = WiFiPlazaLobbyClient_GetMatchPlayerCount(param->slot);
        entry->timeLeft = WiFiPlazaLobbyClient_GetMatchTimer(param->slot);
        WiFiPlazaGameStatus_SetFrames(&entry->status, entry->timeLeft);
        if (entry->timeLeft <= 330 && !entry->startingSoon) {
            WiFiPlazaRoom_HideWaitingIcon(room);
            entry->startingSoon = TRUE;
            WiFiPlazaRoom_PrintMessageInstant(room, WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_GAME_ENTRY, msg_0776_00011));
            WiFiPlazaRoom_ShowWaitingIcon(room);
        }
        WiFiPlazaGameStatus_Update(&entry->status, room, FALSE);
        if (connection == 0) {
            param->result = WIFI_PLAZA_GAME_ENTRY_LINK_ERROR;
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
        } else if (connection == 2) {
            param->result = WIFI_PLAZA_GAME_ENTRY_STARTED;
            if (members == 4) {
                msgId2 = msg_0776_00016;
            } else {
                msgId2 = msg_0776_00018;
            }
            WiFiPlazaRoom_HideWaitingIcon(room);
            WiFiPlazaRoom_PrintMessageInstant(room, WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_GAME_ENTRY, msgId2));
            WiFiPlazaRoom_ShowWaitingIcon(room);
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_START_LINK);
            entry->members = members;
            WiFiPlazaGameStatus_SetFrames(&entry->status, 0);
            WiFiPlazaGameStatus_Update(&entry->status, room, FALSE);
        } else if (!entry->startingSoon && (gSystem.newKeys & PAD_BUTTON_B)) {
            PlaySE(SEQ_SE_DP_SELECT);
            if (!WiFiPlazaLobbyClient_IsMatchHost()) {
                param->result = WIFI_PLAZA_GAME_ENTRY_DROPPED_OUT;
                WiFiPlazaRoom_HideWaitingIcon(room);
                WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
            } else {
                param->result = WIFI_PLAZA_GAME_ENTRY_DROPPED_OUT;
                WiFiPlazaRoom_HideWaitingIcon(room);
                WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_ASK_DROP_OUT);
            }
        } else {
            if (WiFiPlazaLobbyClient_IsMatchHost() == 1) {
                if (entry->reportedMembers != members) {
                    entry->reportedMembers = members;
                    if (members != 4) {
                        WiFiPlaza_SendActivityNews(lobby, param->game, members, savedPlayerIndex, 0, 0, 0, 0);
                    }
                }
                if (entry->timeLeft == 0 && WiFiPlazaLobbyClient_GetMatchPlayerCount(param->slot) <= 1) {
                    param->result = WIFI_PLAZA_GAME_ENTRY_NO_MEMBERS;
                    WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
                    break;
                }
            }
            if (WiFiPlazaLobbyClient_IsMatchActive(param->slot) == TRUE && !WiFiPlazaLobbyClient_IsMatchOpen(param->slot)) {
                param->result = WIFI_PLAZA_GAME_ENTRY_IN_PLAY;
                WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
            } else if (entry->timeLeft == 0) {
                WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_WAIT_LINK);
                WiFiPlazaRoom_HideWaitingIcon(room);
                WiFiPlazaRoom_PrintMessageInstant(room, WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_GAME_ENTRY, msg_0776_00018));
                WiFiPlazaRoom_ShowWaitingIcon(room);
            }
        }
        break;
    case WIFI_PLAZA_REGISTER_WAIT_LINK: // time is up, waiting for the link
        WiFiPlazaGameStatus_SetFrames(&entry->status, 0);
        WiFiPlazaGameStatus_Update(&entry->status, room, FALSE);
        linkState = CommState_GetPlazaMatchStatus();
        members2 = WiFiPlazaLobbyClient_GetMatchPlayerCount(param->slot);
        linkError2 = CommState_GetWifiMatchStatus();
        switch (linkError2) {
        case WIFI_MATCH_STATUS_TIMED_OUT:
        case WIFI_MATCH_STATUS_DISCONNECTED:
            param->result = WIFI_PLAZA_GAME_ENTRY_LINK_ERROR;
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
            break;
        }
        if (linkState == 0) {
            param->result = WIFI_PLAZA_GAME_ENTRY_LINK_ERROR;
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
        } else if (linkState == 2) {
            param->result = WIFI_PLAZA_GAME_ENTRY_STARTED;
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_START_LINK);
            entry->members = members2;
        } else if (WiFiPlazaLobbyClient_IsMatchActive(param->slot) != TRUE || WiFiPlazaLobbyClient_IsMatchOpen(param->slot)) {

        } else {
            param->result = WIFI_PLAZA_GAME_ENTRY_IN_PLAY;
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
        }
        break;
    case WIFI_PLAZA_REGISTER_START_LINK: // linked: exchange the player info
        WiFiPlazaGameStatus_SetFrames(&entry->status, 0);
        WiFiPlazaGameStatus_Update(&entry->status, room, FALSE);
        WiFiPlazaWork_SetActivity(WiFiPlazaRoom_GetLobby(room), param->playerStatus);
        CommState_SetPlazaLinkMode();
        CommPlayerInfo_Init(WiFiPlazaWork_GetSaveData(WiFiPlazaRoom_GetLobby(room)), 0);
        CommPlayerInfo_SetProfile(WiFiPlazaWork_GetOwnPlayerProfile(lobby));
        Comm_SetWifiContinuousSend(0);
        WiFiPlazaGameEntry_StartSync(entry, savedState, WIFI_PLAZA_REGISTER_SEND_PLAYER_INFO, 17);
        break;
    case WIFI_PLAZA_REGISTER_SEND_PLAYER_INFO:
        WiFiPlazaGameStatus_SetFrames(&entry->status, 0);
        WiFiPlazaGameStatus_Update(&entry->status, room, FALSE);
        CommPlayerInfo_SendLocal();
        CommPlayerInfo_Accept(Comm_GetLocalNetId());
        WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_RECEIVE_PLAYER_INFO);
        break;
    case WIFI_PLAZA_REGISTER_RECEIVE_PLAYER_INFO:
        WiFiPlazaGameStatus_SetFrames(&entry->status, 0);
        WiFiPlazaGameStatus_Update(&entry->status, room, FALSE);
        netId = CommPlayerInfo_FindReceived();
        if (netId != 0xFF) {
            do {
                CommPlayerInfo_Accept(netId);
                netId = CommPlayerInfo_FindReceived();
            } while (netId != 0xFF);
        }
        accepted = CommPlayerInfo_CountAccepted();
        if (accepted >= WiFiPlazaLobbyClient_GetMatchPlayerCount(param->slot)) {
            if (WiFiPlazaLobbyClient_IsMatchHost() == 1 && !entry->entriesClosed) {
                WiFiPlazaLobbyClient_CloseMatch();
                entry->entriesClosed = TRUE;
            }
            if (WiFiPlazaLobbyClient_IsCurrentMatchClosed() == TRUE) {
                WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_START_ID_EXCHANGE);
            }
        } else if (WiFiPlazaLobbyClient_IsCurrentMatchClosed() == TRUE) {
            param->result = WIFI_PLAZA_GAME_ENTRY_LINK_ERROR;
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
        }
        break;
    case WIFI_PLAZA_REGISTER_START_ID_EXCHANGE:
        WiFiPlazaGameStatus_SetFrames(&entry->status, 0);
        WiFiPlazaGameStatus_Update(&entry->status, room, FALSE);
        LinkSync_ClearPackets();
        WiFiPlazaWork_ClearGameMembers(lobby);
        WiFiPlazaGameEntry_StartSync(entry, savedState, WIFI_PLAZA_REGISTER_SEND_LOBBY_ID, 14);
        break;
    case WIFI_PLAZA_REGISTER_SEND_LOBBY_ID:
        WiFiPlazaGameStatus_SetFrames(&entry->status, 0);
        WiFiPlazaGameStatus_Update(&entry->status, room, FALSE);
        entry->lobbyId = WiFiPlazaWork_GetOwnId(lobby);
        if (LinkSync_SendPacket(Comm_GetLocalNetId(), (s16 *)&entry->lobbyId) != TRUE) {

        } else {
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_RECEIVE_LOBBY_IDS);
        }
        break;
    case WIFI_PLAZA_REGISTER_RECEIVE_LOBBY_IDS:
        WiFiPlazaGameStatus_SetFrames(&entry->status, 0);
        WiFiPlazaGameStatus_Update(&entry->status, room, FALSE);
        failed = FALSE;
        accepted2 = CommPlayerInfo_CountAccepted();
        memberCount = accepted2;
        myNetId = Comm_GetLocalNetId();
        received = 0;
        hostFound = received;
        hostId = WiFiPlazaLobbyClient_GetMatchHostId();
        i = received;
        if ((s32)accepted2 > 0) {
            do {
                if (myNetId != i) {
                    packet = LinkSync_GetPacket(i);
                    if (packet) {
                        if (WiFiPlazaLobbyClient_IdToSlot(*(s32 *)packet) == -1) {
                            failed = TRUE;
                            param->result = WIFI_PLAZA_GAME_ENTRY_LINK_ERROR;
                            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
                            break;
                        }
                        WiFiPlazaWork_SetGameMember(lobby, *(s32 *)packet, i);
                        if (*(s32 *)packet == hostId) {
                            hostFound = TRUE;
                        }
                        received += 1;
                    }
                } else {
                    WiFiPlazaWork_SetOwnGameMember(lobby, i);
                    if (WiFiPlazaLobbyClient_IsMatchHost() == 1) {
                        hostFound = TRUE;
                    }
                    received += 1;
                }
                i += 1;
            } while (i < (s32)memberCount);
        }
        if (!failed && received == memberCount) {
            if (hostFound == TRUE) {
                WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_START_GAME);
            } else {
                param->result = WIFI_PLAZA_GAME_ENTRY_LINK_ERROR;
                WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
            }
        }
        break;
    case WIFI_PLAZA_REGISTER_START_GAME:
        CommState_SetErrorWatch(FALSE, TRUE);
        if (WiFiPlazaLobbyClient_IsMatchHost() == 1) {
            WiFiPlazaWork_GetGameMembers(lobby, memberIds);
            WiFiPlaza_SendActivityNews(lobby, param->game, WiFiPlazaLobbyClient_GetMatchPlayerCount(param->slot), memberIds[0], memberIds[1], memberIds[2], memberIds[3], 1);
        }
        WiFiPlazaRoom_HideWaitingIcon(room);
        WiFiPlazaGameEntry_StartSync(entry, savedState, WIFI_PLAZA_REGISTER_END, 18);
        break;
    case WIFI_PLAZA_REGISTER_ASK_DROP_OUT: // the host drops out: "If you drop out, the group will be disbanded. Is that OK?"
        WiFiPlazaRoom_PrintMessage(room, WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_GAME_ENTRY, msg_0776_00026));
        WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_WAIT_ASK_DROP_OUT);
        WiFiPlazaGameStatus_Close(&entry->status, room);
        break;
    case WIFI_PLAZA_REGISTER_WAIT_ASK_DROP_OUT:
        if (!WiFiPlazaGameEntry_UpdateWaiting(entry, room, param, savedState, savedPlayerIndex) && WiFiPlazaRoom_IsMessageFinished(room) == TRUE) {
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_OPEN_YES_NO);
        }
        break;
    case WIFI_PLAZA_REGISTER_OPEN_YES_NO:
        WiFiPlazaRoom_OpenYesNoMenuDefaultNo(room);
        WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_HANDLE_YES_NO);
        break;
    case WIFI_PLAZA_REGISTER_HANDLE_YES_NO:
        yesNo = WiFiPlazaRoom_GetYesNoResult(room);
        switch (yesNo) {
        case WIFI_PLAZA_YES_NO_YES:
            WiFiPlazaRoom_CloseYesNoMenu(room);
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END_LINK);
            WiFiPlazaWork_StartGameEntryCooldown(lobby);
            break;
        case WIFI_PLAZA_YES_NO_NO:
            WiFiPlazaRoom_CloseYesNoMenu(room);
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_RESUME_WAITING);
            break;
        case WIFI_PLAZA_YES_NO_OPEN:
            if (WiFiPlazaGameEntry_UpdateWaiting(entry, room, param, savedState, savedPlayerIndex) != TRUE) {

            } else {
                WiFiPlazaRoom_CloseYesNoMenu(room);
            }
            break;
        }
        break;
    case WIFI_PLAZA_REGISTER_RESUME_WAITING: // stays: back to waiting
        entry->timeLeft = WiFiPlazaLobbyClient_GetMatchTimer(param->slot);
        WiFiPlazaGameStatus_Open(&entry->status, room, param->game, TRUE, entry->timeLeft);
        WiFiPlazaGameStatus_UpdateInPlay(&entry->status, room, TRUE);
        if (entry->timeLeft > 330) {
            message2 = WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_GAME_ENTRY, msg_0776_00010);
        } else {
            entry->startingSoon = TRUE;
            message2 = WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_GAME_ENTRY, msg_0776_00011);
        }
        WiFiPlazaRoom_PrintMessageInstant(room, message2);
        WiFiPlazaRoom_ShowWaitingIcon(room);
        WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_WAIT_MEMBERS);
        break;
    case WIFI_PLAZA_REGISTER_SESSION_FILLED: // the session filled up while the question was open
        members3 = WiFiPlazaLobbyClient_GetMatchPlayerCount(param->slot);
        param->result = WIFI_PLAZA_GAME_ENTRY_STARTED;
        if (members3 == 4) {
            msgId = msg_0776_00016;
        } else {
            msgId = msg_0776_00018;
        }
        WiFiPlazaRoom_PrintMessageInstant(room, WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_GAME_ENTRY, msgId));
        WiFiPlazaRoom_ShowWaitingIcon(room);
        WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_START_LINK);
        WiFiPlazaGameStatus_Open(&entry->status, room, param->game, TRUE, 0);
        WiFiPlazaGameStatus_UpdateInPlay(&entry->status, room, TRUE);
        break;
    case WIFI_PLAZA_REGISTER_TIME_UP: // the time ran out while the question was open
        WiFiPlazaRoom_PrintMessageInstant(room, WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_GAME_ENTRY, msg_0776_00018));
        WiFiPlazaRoom_ShowWaitingIcon(room);
        WiFiPlazaGameStatus_Open(&entry->status, room, param->game, TRUE, 0);
        WiFiPlazaGameStatus_SetFrames(&entry->status, 0);
        WiFiPlazaGameStatus_Update(&entry->status, room, TRUE);
        WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_WAIT_LINK);
        break;
    case WIFI_PLAZA_REGISTER_END_LINK: // failed: end the link
        CommPlayerInfo_Free();
        CommState_EndPlazaMatch();
        WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_WAIT_END_LINK);
        break;
    case WIFI_PLAZA_REGISTER_WAIT_END_LINK:
        if (CommState_GetPlazaMatchStatus() == 0) {
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_END);
        }
        break;
    case WIFI_PLAZA_REGISTER_WAIT_MESSAGE:
        if (WiFiPlazaRoom_IsMessageFinished(room) == TRUE) {
            WiFiPlazaPlayerState_SetStep(savedState, entry->nextStep);
        }
        break;
    case WIFI_PLAZA_REGISTER_SYNC:
        delay = entry->syncDelay;
        if (delay > 0) {
            entry->syncDelay = delay - 1;
        }
        if (entry->syncDelay == 0) {
            LinkSync_StartSync(entry->syncId);
            WiFiPlazaPlayerState_SetStep(savedState, WIFI_PLAZA_REGISTER_WAIT_SYNC);
        }
        break;
    case WIFI_PLAZA_REGISTER_WAIT_SYNC:
        entry->syncTimer++;
        if (entry->syncTimer >= 150) {
            LinkSync_StartSync(entry->syncId);
            entry->syncTimer = 0;
        }
        if (LinkSync_IsSynced(entry->syncId)) {
            WiFiPlazaPlayerState_SetStep(savedState, entry->nextStep);
        }
        break;
    case WIFI_PLAZA_REGISTER_END:
        WiFiPlazaRoom_CloseMessage(room);
        WiFiPlazaGameEntry_FreeMenu(entry, room);
        WiFiPlazaGameStatus_Close(&entry->status, room);
        WiFiPlazaRoom_CloseYesNoMenu(room);
        WiFiPlazaPlayerState_FreeWork(savedState);
        return TRUE;
    }
    return FALSE;
}

BOOL WiFiPlazaGameEntry_EndLink(WiFiPlazaPlayerState *state, WiFiPlazaRoomWork *room, u32 index) {
    switch (WiFiPlazaPlayerState_GetStep(state)) {
    case WIFI_PLAZA_END_LINK_START:
        CommState_SetErrorWatch(FALSE, FALSE);
        if (!CommState_IsWifiInLobby()) {
            CommPlayerInfo_Free();
            CommState_EndPlazaMatch();
        }
        WiFiPlazaRoom_SetMode(room, 1);
        WiFiPlazaPlayerState_SetStep(state, WIFI_PLAZA_END_LINK_WAIT_LOBBY);
        break;
    case WIFI_PLAZA_END_LINK_WAIT_LOBBY:
        if (CommState_IsWifiInLobby() == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL WiFiPlazaGameEntry_ReadSign(WiFiPlazaPlayerState *state, WiFiPlazaRoomWork *room, u32 index) {
    WiFiPlazaGameStatus *status = WiFiPlazaPlayerState_GetWork(state);
    u32 game;
    u32 msgId;
    WiFiPlazaGameStatus *newStatus;
    WiFiPlazaObjManager *objManager;

    switch (WiFiPlazaPlayerState_GetStep(state)) {
    case WIFI_PLAZA_SIGN_SHOW:
        newStatus = WiFiPlazaPlayerState_AllocWork(state, sizeof(WiFiPlazaGameStatus));
        switch (WiFiPlazaRoom_GetActionTile(room)) {
        case 0x27:
            msgId = msg_0777_00042;
            game = 0;
            break;
        case 0x28:
            msgId = msg_0777_00041;
            game = 1;
            break;
        case 0x29:
            msgId = msg_0777_00043;
            game = 2;
            break;
        default:
            GF_ASSERT(FALSE);
            return TRUE;
        }
        WiFiPlazaRoom_BufferActivityName(room, game, 0);
        WiFiPlazaRoom_PrintSign(room, WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_PLAZA, msgId));
        WiFiPlazaGameStatus_Open(newStatus, room, game, FALSE, 0);
        WiFiPlazaGameStatus_UpdateInPlay(newStatus, room, TRUE);
        WiFiPlazaPlayerState_NextStep(state);
        break;
    case WIFI_PLAZA_SIGN_WAIT_INPUT:
        if ((gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B | PAD_KEY_UP | PAD_KEY_DOWN | PAD_KEY_LEFT | PAD_KEY_RIGHT)) != 0) {
            WiFiPlazaGameStatus_Close(status, room);
            WiFiPlazaRoom_CloseMessage(room);
            objManager = WiFiPlazaRoom_GetObjManager(room);
            WiFiPlazaObj_SetHandler(objManager, WiFiPlazaObj_GetOwnPlayer(objManager), WIFI_PLAZA_OBJ_HANDLER_PLAYER_INPUT);
            WiFiPlazaPlayerState_FreeWork(state);
            return TRUE;
        }
        WiFiPlazaGameStatus_UpdateInPlay(status, room, FALSE);
        break;
    }
    return FALSE;
}

static void WiFiPlazaGameEntry_PrintMessage(WiFiPlazaGameEntry *entry, WiFiPlazaPlayerState *state, WiFiPlazaRoomWork *room, u32 msgId, u32 nextStep) {
    WiFiPlazaRoom_PrintMessage(room, WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_GAME_ENTRY, msgId));
    entry->nextStep = nextStep;
    WiFiPlazaPlayerState_SetStep(state, WIFI_PLAZA_REGISTER_WAIT_MESSAGE);
}

static void WiFiPlazaGameEntry_StartSync(WiFiPlazaGameEntry *entry, WiFiPlazaPlayerState *state, u8 nextStep, u8 syncId) {
    entry->nextStep = nextStep;
    entry->syncId = syncId;
    entry->syncDelay = 0;
    entry->syncTimer = 0;
    WiFiPlazaPlayerState_SetStep(state, WIFI_PLAZA_REGISTER_SYNC);
}

static void WiFiPlazaGameEntry_InitMenu(WiFiPlazaGameEntry *entry, WiFiPlazaRoomWork *room, u32 count, u32 firstMsg) {
    u32 i;

    WiFiPlazaRoom_CreateListItems(room, count);
    entry->menuCount = count;
    for (i = 0; i < count; i++) {
        WiFiPlazaRoom_AddListItem(room, WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_GAME_ENTRY, firstMsg + i), i);
    }
    entry->menuTemplate = sWiFiPlazaGameEntryMenuTemplate;
    entry->menuTemplate.totalItems = entry->menuCount;
    if (entry->menuTemplate.maxShowed > entry->menuCount) {
        entry->menuTemplate.maxShowed = entry->menuCount;
    }
    entry->menuTemplate.items = WiFiPlazaRoom_GetListItems(room);
}

static void WiFiPlazaGameEntry_FreeMenu(WiFiPlazaGameEntry *entry, WiFiPlazaRoomWork *room) {
    WiFiPlazaRoom_DeleteListItems(room);
}

static BOOL WiFiPlazaGameEntry_UpdateWaiting(WiFiPlazaGameEntry *entry, WiFiPlazaRoomWork *room, WiFiPlazaGameEntryParam *param, WiFiPlazaPlayerState *state, int playerIndex) {
    WiFiPlazaWork *lobby = WiFiPlazaRoom_GetLobby(room);
    s32 connection = CommState_GetPlazaMatchStatus();
    u32 members = WiFiPlazaLobbyClient_GetMatchPlayerCount(param->slot);

    if (connection == 0) {
        param->result = WIFI_PLAZA_GAME_ENTRY_LINK_ERROR;
        WiFiPlazaPlayerState_SetStep(state, WIFI_PLAZA_REGISTER_END_LINK);
        return TRUE;
    }
    if (connection == 2) {
        entry->members = members;
        WiFiPlazaPlayerState_SetStep(state, WIFI_PLAZA_REGISTER_SESSION_FILLED);
        return TRUE;
    }
    if (entry->reportedMembers != members) {
        entry->reportedMembers = members;
        if (members != 4) {
            WiFiPlaza_SendActivityNews(lobby, param->game, members, playerIndex, 0, 0, 0, 0);
        }
    }
    entry->timeLeft = WiFiPlazaLobbyClient_GetMatchTimer(param->slot);
    if (entry->timeLeft == 0) {
        if (WiFiPlazaLobbyClient_GetMatchPlayerCount(param->slot) <= 1) {
            param->result = WIFI_PLAZA_GAME_ENTRY_NO_MEMBERS;
            WiFiPlazaPlayerState_SetStep(state, WIFI_PLAZA_REGISTER_END_LINK);
            return TRUE;
        }
        WiFiPlazaPlayerState_SetStep(state, WIFI_PLAZA_REGISTER_TIME_UP);
        return TRUE;
    }
    if (entry->timeLeft <= 330) {
        WiFiPlazaPlayerState_SetStep(state, WIFI_PLAZA_REGISTER_RESUME_WAITING);
        return TRUE;
    }
    return FALSE;
}

static void WiFiPlazaGameStatus_Open(WiFiPlazaGameStatus *status, WiFiPlazaRoomWork *room, u32 game, u32 showSeconds, s32 frames) {
    GF_ASSERT(showSeconds < 2);
    status->sessionActive = 0;
    status->space = 0;
    status->accepting = 0;
    status->game = 0;
    ((u8 *)&status->seconds)[0] = 0;
    ((u8 *)&status->seconds)[1] = 0;
    status->showSeconds = 0;
    status->redraw = 0;
    status->showSeconds = showSeconds;
    status->game = game;
    WiFiPlazaGameStatus_SetFrames(status, frames);
    WiFiPlazaRoom_OpenTextWindow(room, 18, 3, 13, sWiFiPlazaGameStatusHeights[showSeconds]);
}

static void WiFiPlazaGameStatus_Close(WiFiPlazaGameStatus *status, WiFiPlazaRoomWork *room) {
    status->sessionActive = 0;
    status->space = 0;
    status->accepting = 0;
    status->game = 0;
    ((u8 *)&status->seconds)[0] = 0;
    ((u8 *)&status->seconds)[1] = 0;
    status->showSeconds = 0;
    status->redraw = 0;
    WiFiPlazaRoom_CloseTextWindow(room);
}

static void WiFiPlazaGameStatus_SetFrames(WiFiPlazaGameStatus *status, s32 frames) {
    s16 seconds = frames / 30;

    if (seconds != status->seconds) {
        status->seconds = seconds;
        status->redraw |= WIFI_PLAZA_GAME_STATUS_SECONDS;
    }
}

static void WiFiPlazaGameStatus_Update(WiFiPlazaGameStatus *status, WiFiPlazaRoomWork *room, u32 force) {
    WiFiPlazaGameStatus_Draw(status, room, force, FALSE);
}

static void WiFiPlazaGameStatus_UpdateInPlay(WiFiPlazaGameStatus *status, WiFiPlazaRoomWork *room, u32 force) {
    WiFiPlazaGameStatus_Draw(status, room, force, TRUE);
}

static void WiFiPlazaGameStatus_Draw(WiFiPlazaGameStatus *status, WiFiPlazaRoomWork *room, u32 force, u32 showInPlay) {
    u32 slot;
    u32 value;
    u32 sessionActive;
    String *message;
    u8 x;

    if (force) {
        status->redraw = 0xFF;
    }
    switch (status->game) {
    case 0:
        slot = 0;
        break;
    case 1:
        slot = 1;
        break;
    case 2:
        slot = 2;
        break;
    default:
        GF_ASSERT(FALSE);
        slot = 2;
        break;
    }

    sessionActive = WiFiPlazaLobbyClient_IsMatchActive(slot);
    if (status->sessionActive != sessionActive) {
        status->redraw |= WIFI_PLAZA_GAME_STATUS_STATE;
    }
    status->sessionActive = sessionActive;

    value = WiFiPlazaLobbyClient_IsMatchOpen(slot);
    if (status->accepting != value) {
        status->redraw |= WIFI_PLAZA_GAME_STATUS_STATE;
    }
    status->accepting = value;

    if (sessionActive == TRUE) {
        value = WiFiPlazaLobbyClient_GetMatchFreePlaces(slot);
    } else {
        value = 4;
    }
    if (status->space != value) {
        status->redraw |= WIFI_PLAZA_GAME_STATUS_COUNTS;
    }
    status->space = value;

    if (status->redraw & WIFI_PLAZA_GAME_STATUS_TITLE) {
        WiFiPlazaRoom_FillTextWindowRect(room, 0, 0, 104, 16);
        WiFiPlazaRoom_BufferActivityName(room, status->game, 0);
        message = WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_PLAZA, msg_0777_00054);
        WiFiPlazaRoom_PrintTextWindow(room, message, 0, 0);
    }
    if (status->redraw & WIFI_PLAZA_GAME_STATUS_STATE) {
        WiFiPlazaRoom_FillTextWindowRect(room, 0, 16, 104, 16);
        if (showInPlay == TRUE && !status->accepting && status->sessionActive == TRUE) {
            message = WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_PLAZA, msg_0777_00069); // "GAME IN PLAY..."
            x = 104 - FontID_String_GetWidth(0, message, 0);
            WiFiPlazaRoom_PrintTextWindow(room, message, x, 16);
        }
    }
    if (status->redraw & WIFI_PLAZA_GAME_STATUS_COUNTS) {
        WiFiPlazaRoom_FillTextWindowRect(room, 0, 32, 104, 32);
        WiFiPlazaRoom_BufferInt(room, status->space, 1, 1, 2);
        WiFiPlazaRoom_BufferInt(room, 4 - status->space, 1, 0, 2);
        message = WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_PLAZA, msg_0777_00068); // "PLAYERS: / SPACE:"
        WiFiPlazaRoom_PrintTextWindow(room, message, 0, 32);
    }
    if (status->showSeconds == TRUE && (status->redraw & WIFI_PLAZA_GAME_STATUS_SECONDS)) {
        WiFiPlazaRoom_FillTextWindowRect(room, 0, 64, 104, 16);
        WiFiPlazaRoom_BufferInt(room, status->seconds, 2, 0, 2);
        message = WiFiPlazaRoom_GetMsgString(room, WIFI_PLAZA_MSG_BANK_GAME_ENTRY, msg_0776_00015); // "... seconds to go"
        WiFiPlazaRoom_PrintTextWindow(room, message, 0, 64);
    }
    status->redraw = 0;
}
