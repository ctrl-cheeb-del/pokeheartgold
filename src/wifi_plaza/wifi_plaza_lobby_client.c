#include <string.h>

#include "global.h"

#include "wifi_plaza/wifi_plaza_internal.h"

#include "assert.h"
#include "friend_roster.h"
#include "heap.h"
#include "ppw_lobby_state.h"
#include "save_wifi_history.h"
#include "wifi_connection.h"

static BOOL WiFiPlazaLobbyClient_InitializeEx(const WiFiPlazaPlayer *player, int mode);
static void WiFiPlazaLobbyClient_ClearErrors(void);
static BOOL WiFiPlazaLobbyClient_AddOwnLocation(WiFiPlazaLobbyClient *client);
static void WiFiPlazaLobbyClient_AllocPlayerData(WiFiPlazaLobbyClient *client, u32 size, enum HeapID heapID);
static void WiFiPlazaLobbyClient_FreePlayerData(WiFiPlazaLobbyClient *client);
static void WiFiPlazaLobbyClient_AllocIdLists(WiFiPlazaLobbyClient *client, u32 lobbyCapacity, u32 channelCapacity, enum HeapID heapID);
static void WiFiPlazaLobbyClient_FreeIdLists(WiFiPlazaLobbyClient *client);
static void WiFiPlazaLobbyClient_ClearIdList(WiFiPlazaLobbyClient *client, int scope);

// The lobby client of the Wi-Fi Plaza, on top of the lobby library: the lobby state, the location of every lobby
// slot, the message tables, the lobby time and up to three matchmaking sessions.

WiFiPlazaLobbyClient *gWiFiPlazaLobbyClient;

const char *gWiFiPlazaLocationListKey = "b_lby_wlddata";

// Slot getter of news event type 8 (gWiFiPlazaNewsEventSlotGetters).
u16 WiFiPlazaNewsEvent_GetMinigameResultSlot(WiFiPlazaNewsEvent *event, u32 index) {
    if (event->b <= index) {
        return WIFI_PLAZA_NEWS_NO_SLOT;
    }
    return event->slots[index];
}

BOOL WiFiPlaza_IsMinigamePlayerCountValid(u32 activity, u32 count) {
    if (activity <= 1) {
        if (count < 1 || count > 4) {
            return FALSE;
        }
    } else {
        if (count < 2 || count > 4) {
            return FALSE;
        }
    }
    return TRUE;
}

void WiFiPlazaLobbyClient_Init(enum HeapID heapID, SaveData *save, u32 count, WiFiPlazaCallbacks *callbacks, void *callbackArg) {
    GF_ASSERT(gWiFiPlazaLobbyClient == NULL);
    GF_ASSERT(count < 300);
    gWiFiPlazaLobbyClient = Heap_Alloc(heapID, sizeof(WiFiPlazaLobbyClient));
    memset(gWiFiPlazaLobbyClient, 0, sizeof(WiFiPlazaLobbyClient));
    gWiFiPlazaLobbyClient->save = save;
    gWiFiPlazaLobbyClient->friendRoster = Save_FriendRoster_Get(save);
    gWiFiPlazaLobbyClient->wifiHistory = Save_WiFiHistory_Get(save);
    gWiFiPlazaLobbyClient->callbacks = *callbacks;
    gWiFiPlazaLobbyClient->callbackArg = callbackArg;
    WiFiPlazaLobbyClient_AllocPlayerData(gWiFiPlazaLobbyClient, count, heapID);
    WiFiPlazaLobbyClient_AllocIdLists(gWiFiPlazaLobbyClient, WIFI_PLAZA_MAX_PLAYERS, 8, heapID);
    WiFiPlazaLobbyClient_InitMatches(gWiFiPlazaLobbyClient);
    WiFiPlazaLobbyIdValueList_Init(&gWiFiPlazaLobbyClient->specialVisitors, 128, heapID);
    gWiFiPlazaLobbyClient->initResult = PPW_LOBBY_RESULT_SUCCESS;
}

void WiFiPlazaLobbyClient_Free(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    WiFiPlazaLobbyIdValueList_Free(&gWiFiPlazaLobbyClient->specialVisitors);
    WiFiPlazaLobbyClient_FreeIdLists(gWiFiPlazaLobbyClient);
    WiFiPlazaLobbyClient_FreePlayerData(gWiFiPlazaLobbyClient);
    Heap_Free(gWiFiPlazaLobbyClient);
    gWiFiPlazaLobbyClient = NULL;
}

// Once per frame: follows the state of the lobby library and the channel, refreshes the lobby time and the
// matchmaking sessions.
int WiFiPlazaLobbyClient_Update(void) {
    if (gWiFiPlazaLobbyClient == NULL) {
        return WIFI_PLAZA_LOBBY_STATE_DISCONNECTED;
    }
    switch (PPW_LobbyProcess()) {
    case PPW_LOBBY_STATE_NOT_INITIALIZED:
        gWiFiPlazaLobbyClient->state = WIFI_PLAZA_LOBBY_STATE_DISCONNECTED;
        break;
    case PPW_LOBBY_STATE_CONNECTING:
    case PPW_LOBBY_STATE_CONNECTED:
    case PPW_LOBBY_STATE_WAIT_SCHEDULE:
    case PPW_LOBBY_STATE_ENUM_CHANNELS:
    case PPW_LOBBY_STATE_SEARCHING_CHANNEL:
    case PPW_LOBBY_STATE_ENTER_MAIN_CHANNEL:
    case PPW_LOBBY_STATE_WAIT_MAIN_CHANNEL:
        gWiFiPlazaLobbyClient->state = WIFI_PLAZA_LOBBY_STATE_CONNECTING;
        break;
    case PPW_LOBBY_STATE_READY:
        gWiFiPlazaLobbyClient->state = WIFI_PLAZA_LOBBY_STATE_IN_LOBBY;
        break;
    case PPW_LOBBY_STATE_CLOSED:
        gWiFiPlazaLobbyClient->state = WIFI_PLAZA_LOBBY_STATE_CLOSING;
        break;
    case PPW_LOBBY_STATE_ERROR:
        gWiFiPlazaLobbyClient->state = WIFI_PLAZA_LOBBY_STATE_ERROR;
        break;
    }
    if (gWiFiPlazaLobbyClient->state == WIFI_PLAZA_LOBBY_STATE_IN_LOBBY) {
        WiFiPlazaLobbyMatches_Update(gWiFiPlazaLobbyClient);
        PPW_LobbyGetTimeInfo(&gWiFiPlazaLobbyClient->time);
        switch (PPW_LobbyGetSubChannelState()) {
        case PPW_LOBBY_CHANNEL_STATE_NONE:
            gWiFiPlazaLobbyClient->channelState = WIFI_PLAZA_CHANNEL_STATE_NONE;
            gWiFiPlazaLobbyClient->channel = WIFI_PLAZA_LOBBY_CHANNEL_NONE;
            break;
        case PPW_LOBBY_CHANNEL_STATE_JOINING:
            gWiFiPlazaLobbyClient->channelState = WIFI_PLAZA_CHANNEL_STATE_JOINING;
            break;
        case PPW_LOBBY_CHANNEL_STATE_JOINED:
            if (gWiFiPlazaLobbyClient->channelState != WIFI_PLAZA_CHANNEL_STATE_LEAVING) {
                gWiFiPlazaLobbyClient->channelState = WIFI_PLAZA_CHANNEL_STATE_JOINED;
            }
            break;
        case PPW_LOBBY_CHANNEL_STATE_ERROR:
            gWiFiPlazaLobbyClient->channelState = WIFI_PLAZA_CHANNEL_STATE_ERROR;
            break;
        }
    }
    return WiFiPlazaLobbyClient_GetState();
}

u32 WiFiPlazaLobbyClient_GetLastError(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    if (gWiFiPlazaLobbyClient->initResult != PPW_LOBBY_RESULT_SUCCESS) {
        return PPW_LobbyInitResultToLastError(gWiFiPlazaLobbyClient->initResult);
    } else {
        return PPW_LobbyGetLastError();
    }
}

u32 WiFiPlazaLobbyClient_ToErrorCode(u32 error) {
    return PPW_LobbyToErrorCode(error);
}

BOOL WiFiPlazaLobbyClient_Initialize(const WiFiPlazaPlayer *player) {
    return WiFiPlazaLobbyClient_InitializeEx(player, 0);
}

static BOOL WiFiPlazaLobbyClient_InitializeEx(const WiFiPlazaPlayer *player, int mode) {
    PPWLobbyCallbacks callbacks;
    void *userData;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    callbacks.onEnterChannel = WiFiPlazaLobbyClient_OnEnterChannel;
    callbacks.onPlayerEnter = WiFiPlazaLobbyClient_OnPlayerEnter;
    callbacks.onPlayerLeave = WiFiPlazaLobbyClient_OnPlayerLeave;
    callbacks.onStringMessage = WiFiPlazaLobbyClient_OnEvent3Dummy;
    callbacks.onMessage = WiFiPlazaLobbyClient_OnMessage;
    callbacks.onLocationsChanged = WiFiPlazaLobbyClient_OnLocationsChanged;
    callbacks.onPlayerRecordChanged = WiFiPlazaLobbyClient_OnPlayerRecordChanged;
    callbacks.onPlayerUpdate = WiFiPlazaLobbyClient_OnPlayerUpdate;
    callbacks.onMatchInfo = WiFiPlazaLobbyClient_OnMatchInfo;
    callbacks.onMatchClosed = WiFiPlazaLobbyClient_OnMatchClosed;
    callbacks.onLobbyEvent = WiFiPlazaLobbyClient_OnLobbyEvent;
    callbacks.onOwnRecord = WiFiPlazaLobbyClient_OnOwnRecord;
    callbacks.onScheduleReceived = WiFiPlazaLobbyClient_OnScheduleReceived;
    callbacks.onSpecialVisitorsReceived = WiFiPlazaLobbyClient_OnSpecialVisitorsReceived;
    callbacks.onSurveyReceived = WiFiPlazaLobbyClient_OnSurveyReceived;
    callbacks.onSurveySubmitted = WiFiPlazaLobbyClient_OnSurveySubmitted;
    callbacks.onExcessFlood = WiFiPlazaLobbyClient_OnExcessFlood;
    userData = FriendRoster_GetUserData(gWiFiPlazaLobbyClient->friendRoster);
    gWiFiPlazaLobbyClient->initResult = PPW_LobbyInitializeAsync("pokemonplatds", "IIup73", mode, &callbacks, userData, player, gWiFiPlazaLobbyClient->playerDataSize);
    return WiFiPlazaLobbyClient_CheckResult(gWiFiPlazaLobbyClient->initResult);
}

BOOL WiFiPlazaLobbyClient_IsInLobby(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    return gWiFiPlazaLobbyClient->state == WIFI_PLAZA_LOBBY_STATE_IN_LOBBY;
}

void WiFiPlazaLobbyClient_Shutdown(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    WiFiPlazaLobbyClient_ClearErrors();
    GF_ASSERT(WiFiPlazaLobbyClient_CheckResult(PPW_LobbyShutdownAsync()));
}

BOOL WiFiPlazaLobbyClient_IsDisconnected(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    return gWiFiPlazaLobbyClient->state == WIFI_PLAZA_LOBBY_STATE_DISCONNECTED;
}

// The lobby state, 4 (error) when the channel or the client failed.
int WiFiPlazaLobbyClient_GetState(void) {
    WiFiPlazaLobbyClient *client;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    client = gWiFiPlazaLobbyClient;
    if (client->channel != WIFI_PLAZA_LOBBY_CHANNEL_NONE && client->channelState == WIFI_PLAZA_CHANNEL_STATE_ERROR) {
        return WIFI_PLAZA_LOBBY_STATE_ERROR;
    }
    if (client->ownRecordError) {
        return WIFI_PLAZA_LOBBY_STATE_ERROR;
    }
    if (client->requestError) {
        return WIFI_PLAZA_LOBBY_STATE_ERROR;
    }
    return client->state;
}

u8 WiFiPlazaLobbyClient_TakeExcessFlood(void) {
    u8 value;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    value = gWiFiPlazaLobbyClient->excessFlood;
    gWiFiPlazaLobbyClient->excessFlood = 0;
    return value;
}

int WiFiPlazaLobbyClient_GetOwnId(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    return PPW_LobbyGetMyUserId();
}

void WiFiPlazaLobbyClient_SetOwnPlayer(WiFiPlazaPlayer *player) {
    int ownId;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    ownId = PPW_LobbyGetMyUserId();
    WiFiPlazaLobbyClient_SetPlayerData(gWiFiPlazaLobbyClient, ownId, player);
    PPW_LobbyUpdateMyProfile(player, gWiFiPlazaLobbyClient->playerDataSize, FALSE);
}

WiFiPlazaPlayer *WiFiPlazaLobbyClient_GetPlayer(int id) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    return WiFiPlazaLobbyClient_GetPlayerData(gWiFiPlazaLobbyClient, id);
}

// The time the player entered the lobby.
void WiFiPlazaLobbyClient_GetEntryTime(int id, s64 *time) {
    WiFiPlazaLobbyEntryTime *entered;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    entered = &WiFiPlazaLobbyClient_GetPlayerRecord(gWiFiPlazaLobbyClient, id)->entryTime;
    *(WiFiPlazaLobbyEntryTime *)time = *entered;
}

// The player who has been in the lobby the longest, -1 if none.
int WiFiPlazaLobbyClient_GetOldestPlayer(void) {
    s64 oldest;
    s64 time;
    int result;
    int slot;

    result = -1;
    oldest = 0x0FFFFFFFFFFFFFFFLL;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    for (slot = 0; slot < WIFI_PLAZA_MAX_PLAYERS; slot++) {
        int id = WiFiPlazaLobbyClient_GetIdListEntry(gWiFiPlazaLobbyClient, slot, WIFI_PLAZA_LOBBY_SCOPE_LOBBY);
        if (id != -1) {
            WiFiPlazaLobbyClient_GetEntryTime(id, &time);
            if (time < oldest) {
                oldest = time;
                result = id;
            }
        }
    }
    return result;
}

// The same without the given player.
int WiFiPlazaLobbyClient_GetOldestOtherPlayer(int excluded) {
    s64 oldest;
    s64 time;
    int result;
    int slot;

    result = -1;
    oldest = 0x0FFFFFFFFFFFFFFFLL;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    for (slot = 0; slot < WIFI_PLAZA_MAX_PLAYERS; slot++) {
        int id = WiFiPlazaLobbyClient_GetIdListEntry(gWiFiPlazaLobbyClient, slot, WIFI_PLAZA_LOBBY_SCOPE_LOBBY);
        if (id != -1 && id != excluded) {
            WiFiPlazaLobbyClient_GetEntryTime(id, &time);
            if (time < oldest) {
                oldest = time;
                result = id;
            }
        }
    }
    return result;
}

BOOL WiFiPlazaLobbyClient_JoinChannel(int channel) {
    BOOL result;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    result = WiFiPlazaLobbyClient_CheckResult(PPW_LobbyJoinSubChannelAsync(WiFiPlazaLobbyClient_ChannelToLib(channel)));
    if (result == TRUE) {
        gWiFiPlazaLobbyClient->channel = channel;
        gWiFiPlazaLobbyClient->joinChannelResult = WIFI_PLAZA_JOIN_CHANNEL_PENDING;
    }
    return result;
}

u8 WiFiPlazaLobbyClient_GetJoinChannelResult(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    return gWiFiPlazaLobbyClient->joinChannelResult;
}

BOOL WiFiPlazaLobbyClient_LeaveChannel(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    {
        BOOL result = WiFiPlazaLobbyClient_CheckResult(PPW_LobbyLeaveSubChannel());
        if (result == TRUE) {
            gWiFiPlazaLobbyClient->channelState = WIFI_PLAZA_CHANNEL_STATE_LEAVING;
        }
        return result;
    }
}

BOOL WiFiPlazaLobbyClient_IsNotInChannel(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    return gWiFiPlazaLobbyClient->channelState == WIFI_PLAZA_CHANNEL_STATE_NONE;
}

BOOL WiFiPlazaLobbyClient_CanJoinChannel(int channel) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    return WiFiPlazaLobbyClient_HasChannelRoom(gWiFiPlazaLobbyClient, channel);
}

void WiFiPlazaLobbyClient_GetPlayerList(WiFiPlazaPlayerList *list) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    list->count = gWiFiPlazaLobbyClient->idLists[WIFI_PLAZA_LOBBY_SCOPE_LOBBY].count;
    list->ids = gWiFiPlazaLobbyClient->idLists[WIFI_PLAZA_LOBBY_SCOPE_LOBBY].ids;
}

void WiFiPlazaLobbyClient_GetChannelPlayerList(WiFiPlazaPlayerList *list) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    list->count = gWiFiPlazaLobbyClient->idLists[WIFI_PLAZA_LOBBY_SCOPE_CHANNEL].count;
    list->ids = gWiFiPlazaLobbyClient->idLists[WIFI_PLAZA_LOBBY_SCOPE_CHANNEL].ids;
}

// Lobby player id <-> lobby slot.
int WiFiPlazaLobbyClient_IdToSlot(int id) {
    return WiFiPlazaLobbyClient_FindInIdList(gWiFiPlazaLobbyClient, id, WIFI_PLAZA_LOBBY_SCOPE_LOBBY);
}

int WiFiPlazaLobbyClient_IdToChannelSlot(int id) {
    return WiFiPlazaLobbyClient_FindInIdList(gWiFiPlazaLobbyClient, id, WIFI_PLAZA_LOBBY_SCOPE_CHANNEL);
}

int WiFiPlazaLobbyClient_SlotToId(int slot) {
    return WiFiPlazaLobbyClient_GetIdListEntry(gWiFiPlazaLobbyClient, slot, WIFI_PLAZA_LOBBY_SCOPE_LOBBY);
}

int WiFiPlazaLobbyClient_ChannelSlotToId(int slot) {
    return WiFiPlazaLobbyClient_GetIdListEntry(gWiFiPlazaLobbyClient, slot, WIFI_PLAZA_LOBBY_SCOPE_CHANNEL);
}

void WiFiPlazaLobbyClient_GetTime(s64 *time) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    *time = gWiFiPlazaLobbyClient->time.currentTime;
}

u32 WiFiPlazaLobbyClient_GetScheduleValue(enum WiFiPlazaScheduleField field) {
    WiFiPlazaLobbySchedule *schedule;
    u32 result;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    {
        BOOL valid = TRUE;
        if (gWiFiPlazaLobbyClient->state != WIFI_PLAZA_LOBBY_STATE_IN_LOBBY && gWiFiPlazaLobbyClient->state != WIFI_PLAZA_LOBBY_STATE_ERROR) {
            valid = FALSE;
        }
        GF_ASSERT(valid);
    }
    GF_ASSERT(field < 8);
    schedule = &gWiFiPlazaLobbyClient->schedule;
    switch (field) {
    case WIFI_PLAZA_SCHEDULE_LOCK_TIME:
        result = schedule->record.lockTime;
        break;
    case 1:
        result = schedule->record.unk_04;
        break;
    case WIFI_PLAZA_SCHEDULE_ROOM_TYPE:
        result = schedule->record.roomType;
        break;
    case WIFI_PLAZA_SCHEDULE_SEASON:
        result = schedule->record.season;
        break;
    case WIFI_PLAZA_SCHEDULE_ARCEUS:
        result = (schedule->record.roomFlag & 1) != 0;
        break;
    case WIFI_PLAZA_SCHEDULE_CLOSE_TIME:
        result = WiFiPlazaLobbySchedule_FindValue(schedule, WIFI_PLAZA_EVENT_CLOSE);
        break;
    case WIFI_PLAZA_SCHEDULE_FIREWORKS_START_TIME:
        result = WiFiPlazaLobbySchedule_FindValue(schedule, WIFI_PLAZA_EVENT_FIREWORKS_START);
        break;
    case WIFI_PLAZA_SCHEDULE_FIREWORKS_END_TIME:
        result = WiFiPlazaLobbySchedule_FindValue(schedule, WIFI_PLAZA_EVENT_FIREWORKS_END);
        break;
    }
    return result;
}

BOOL WiFiPlazaLobbyClient_StartAddOwnLocation(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    {
        BOOL result = WiFiPlazaLobbyClient_AddOwnLocation(gWiFiPlazaLobbyClient);
        if (result) {
            gWiFiPlazaLobbyClient->addingLocation = TRUE;
        }
        return result;
    }
}

BOOL WiFiPlazaLobbyClient_IsOwnLocationAdded(void) {
    return !gWiFiPlazaLobbyClient->addingLocation;
}

u32 WiFiPlazaLobbyClient_GetLocationCountry(u8 slot) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    GF_ASSERT((u32)slot < NELEMS(gWiFiPlazaLobbyClient->locations));
    return gWiFiPlazaLobbyClient->locations[slot].country;
}

u8 WiFiPlazaLobbyClient_GetLocationRegion(u8 slot) {
    WiFiPlazaLobbyLocation *location;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    GF_ASSERT((u32)slot < NELEMS(gWiFiPlazaLobbyClient->locations));
    location = &gWiFiPlazaLobbyClient->locations[slot];
    return location->region;
}

// The message types sent with WiFiPlazaLobbyClient_SendToLobby / SendToPlayer (each with the size of its data).
void WiFiPlazaLobbyClient_SetLobbyCommands(const WiFiPlazaLobbyCommand *commands, u32 count, void *arg) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_LOBBY].commands = commands;
    gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_LOBBY].count = count;
    gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_LOBBY].arg = arg;
}

// The message types sent with WiFiPlazaLobbyClient_SendToChannel.
void WiFiPlazaLobbyClient_SetChannelCommands(const WiFiPlazaLobbyCommand *commands, u32 count, void *arg) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_CHANNEL].commands = commands;
    gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_CHANNEL].count = count;
    gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_CHANNEL].arg = arg;
}

void WiFiPlazaLobbyClient_ClearLobbyCommands(void) {
    u8 *bytes;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    bytes = (u8 *)&gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_LOBBY];
    bytes[0] = 0;
    bytes[1] = 0;
    bytes[2] = 0;
    bytes[3] = 0;
    bytes[4] = 0;
    bytes[5] = 0;
    bytes[6] = 0;
    bytes[7] = 0;
    bytes[8] = 0;
    bytes[9] = 0;
    bytes[10] = 0;
    bytes[11] = 0;
}

void WiFiPlazaLobbyClient_ClearChannelCommands(void) {
    u8 *bytes;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    bytes = (u8 *)&gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_CHANNEL];
    bytes[0] = 0;
    bytes[1] = 0;
    bytes[2] = 0;
    bytes[3] = 0;
    bytes[4] = 0;
    bytes[5] = 0;
    bytes[6] = 0;
    bytes[7] = 0;
    bytes[8] = 0;
    bytes[9] = 0;
    bytes[10] = 0;
    bytes[11] = 0;
}

void WiFiPlazaLobbyClient_SendToLobby(int type, const void *data, int size) {
    const WiFiPlazaLobbyCommand *command;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    GF_ASSERT(gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_LOBBY].count > (u32)type);
    command = &gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_LOBBY].commands[type];
    GF_ASSERT(size == command->size);
    GF_ASSERT(WiFiPlazaLobbyClient_CheckResult(PPW_LobbySendChannelBinaryMessage(PPW_LOBBY_CHANNEL_KIND_MAIN, type, data, size)) == TRUE);
}

void WiFiPlazaLobbyClient_SendToPlayer(int type, int id, const void *data, int size) {
    const WiFiPlazaLobbyCommand *command;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    GF_ASSERT(gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_LOBBY].count > (u32)type);
    command = &gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_LOBBY].commands[type];
    GF_ASSERT(size == command->size);
    GF_ASSERT(WiFiPlazaLobbyClient_CheckResult(PPW_LobbySendPlayerBinaryMessage(id, type, data, size)) == TRUE);
}

void WiFiPlazaLobbyClient_SendToChannel(int type, const void *data, int size) {
    const WiFiPlazaLobbyCommand *command;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    GF_ASSERT(gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_CHANNEL].count > (u32)type);
    command = &gWiFiPlazaLobbyClient->commandTables[WIFI_PLAZA_LOBBY_SCOPE_CHANNEL].commands[type];
    GF_ASSERT(size == command->size);
    GF_ASSERT(gWiFiPlazaLobbyClient->channel != WIFI_PLAZA_LOBBY_CHANNEL_NONE);
    GF_ASSERT(WiFiPlazaLobbyClient_CheckResult(PPW_LobbySendChannelBinaryMessage(WiFiPlazaLobbyClient_ChannelToLib(gWiFiPlazaLobbyClient->channel), type, data, size)) == TRUE);
}

#pragma opt_propagation off

// Starts matchmaking session `index` as its host.
BOOL WiFiPlazaLobbyClient_HostMatch(int index, int maxPlayers) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    if (WiFiPlazaLobbyMatches_IsActive(gWiFiPlazaLobbyClient, index) == TRUE) {
        return FALSE;
    }
    if (gWiFiPlazaLobbyClient->currentMatch != WIFI_PLAZA_LOBBY_MATCH_NONE) {
        return FALSE;
    }
    gWiFiPlazaLobbyClient->matches[index].info.index = index;
    gWiFiPlazaLobbyClient->matches[index].info.maxPlayers = maxPlayers;
    gWiFiPlazaLobbyClient->matches[index].info.playerCount = 1;
    gWiFiPlazaLobbyClient->matches[index].info.state = WIFI_PLAZA_MATCH_OPEN;
    WiFiPlazaLobbyMatchInfo_SetStartTime(&gWiFiPlazaLobbyClient->matches[index].info, &gWiFiPlazaLobbyClient->time.currentTime);
    GF_ASSERT(WiFiPlazaLobbyClient_CheckResult(PPW_LobbyStartRecruit(&gWiFiPlazaLobbyClient->matches[index])));
    gWiFiPlazaLobbyClient->matches[index].active = TRUE;
    gWiFiPlazaLobbyClient->matches[index].hostId = PPW_LobbyGetMyUserId();
    gWiFiPlazaLobbyClient->matches[index].timer = 1800;
    gWiFiPlazaLobbyClient->currentMatch = index;
    gWiFiPlazaLobbyClient->isMatchHost = TRUE;
    gWiFiPlazaLobbyClient->matchCancelled = FALSE;
    WifiConnection_StartAnybodyMatchmaking(gWiFiPlazaLobbyClient->matches[index].info.name, maxPlayers, 1, gWiFiPlazaLobbyClient->matches[index].timer / 30);
    WifiConnection_SetClientCallback(WiFiPlazaLobbyClient_OnMatchClientDummy, gWiFiPlazaLobbyClient);
    WifiConnection_SetDisconnectCallback(WiFiPlazaLobbyClient_OnMatchDisconnect, gWiFiPlazaLobbyClient);
    return TRUE;
}

#pragma opt_propagation reset

void WiFiPlazaLobbyClient_StopMatch(void) {
    WiFiPlazaLobbyClient *client;
    int ownId;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    if (gWiFiPlazaLobbyClient->currentMatch != WIFI_PLAZA_LOBBY_MATCH_NONE && gWiFiPlazaLobbyClient->isMatchHost) {
        GF_ASSERT(WiFiPlazaLobbyClient_CheckResult(PPW_LobbyStopRecruit()));
        client = gWiFiPlazaLobbyClient;
        ownId = PPW_LobbyGetMyUserId();
        GF_ASSERT(WiFiPlazaLobbyMatches_Remove(client, client->currentMatch, ownId));
        gWiFiPlazaLobbyClient->isMatchHost = FALSE;
    }
}

void WiFiPlazaLobbyClient_CloseMatch(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    if (gWiFiPlazaLobbyClient->isMatchHost) {
        gWiFiPlazaLobbyClient->matches[gWiFiPlazaLobbyClient->currentMatch].info.state = WIFI_PLAZA_MATCH_CLOSED;
        GF_ASSERT(WiFiPlazaLobbyClient_CheckResult(PPW_LobbyUpdateRecruitInfo(&gWiFiPlazaLobbyClient->matches[gWiFiPlazaLobbyClient->currentMatch])));
    }
}

BOOL WiFiPlazaLobbyClient_IsCurrentMatchClosed(void) {
    u16 index;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    index = gWiFiPlazaLobbyClient->currentMatch;
    if (index == WIFI_PLAZA_LOBBY_MATCH_NONE) {
        return FALSE;
    }
    return gWiFiPlazaLobbyClient->matches[index].info.state == WIFI_PLAZA_MATCH_CLOSED;
}

u8 WiFiPlazaLobbyClient_WasMatchCancelled(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    return gWiFiPlazaLobbyClient->matchCancelled;
}

BOOL WiFiPlazaLobbyClient_IsMatchActive(int index) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    return WiFiPlazaLobbyMatches_IsActive(gWiFiPlazaLobbyClient, index);
}

BOOL WiFiPlazaLobbyClient_IsMatchOpen(int index) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    if (!WiFiPlazaLobbyClient_IsMatchActive(index)) {
        return FALSE;
    }
    return gWiFiPlazaLobbyClient->matches[index].info.state == WIFI_PLAZA_MATCH_OPEN;
}

// Free places of matchmaking session `index`.
int WiFiPlazaLobbyClient_GetMatchFreePlaces(int index) {
    WiFiPlazaLobbyMatch *match;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    GF_ASSERT(index < WIFI_PLAZA_LOBBY_MATCH_COUNT);
    if (!WiFiPlazaLobbyMatches_IsActive(gWiFiPlazaLobbyClient, index)) {
        return 0;
    }
    match = WiFiPlazaLobbyMatches_Get(gWiFiPlazaLobbyClient, index);
    return match->info.maxPlayers - match->info.playerCount;
}

u32 WiFiPlazaLobbyClient_GetMatchPlayerCount(int index) {
    WiFiPlazaLobbyMatch *match;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    GF_ASSERT(index < WIFI_PLAZA_LOBBY_MATCH_COUNT);
    if (!WiFiPlazaLobbyMatches_IsActive(gWiFiPlazaLobbyClient, index)) {
        return 0;
    }
    match = WiFiPlazaLobbyMatches_Get(gWiFiPlazaLobbyClient, index);
    return match->info.playerCount;
}

// Joins matchmaking session `index` of another host.
BOOL WiFiPlazaLobbyClient_JoinMatch(int index) {
    WiFiPlazaLobbyClient *client;
    WiFiPlazaLobbyMatch *match;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    if (!WiFiPlazaLobbyMatches_IsActive(gWiFiPlazaLobbyClient, index)) {
        return FALSE;
    }
    if (gWiFiPlazaLobbyClient->currentMatch != WIFI_PLAZA_LOBBY_MATCH_NONE) {
        return FALSE;
    }
    match = &gWiFiPlazaLobbyClient->matches[index];
    if (match->info.state == WIFI_PLAZA_MATCH_CLOSED) {
        return FALSE;
    }
    gWiFiPlazaLobbyClient->currentMatch = index;
    client = gWiFiPlazaLobbyClient;
    WifiConnection_StartAnybodyMatchmaking(client->matches[index].info.name, client->matches[index].info.maxPlayers, 0, client->matches[index].timer / 30);
    WifiConnection_SetClientCallback(WiFiPlazaLobbyClient_OnMatchClientDummy, gWiFiPlazaLobbyClient);
    WifiConnection_SetDisconnectCallback(WiFiPlazaLobbyClient_OnMatchDisconnect, gWiFiPlazaLobbyClient);
    return TRUE;
}

u32 WiFiPlazaLobbyClient_GetMatchTimer(int index) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    GF_ASSERT(index < WIFI_PLAZA_LOBBY_MATCH_COUNT);
    if (!WiFiPlazaLobbyMatches_IsActive(gWiFiPlazaLobbyClient, index)) {
        return 1800;
    }
    return gWiFiPlazaLobbyClient->matches[index].timer;
}

int WiFiPlazaLobbyClient_GetMatchHostId(void) {
    u16 index;
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    index = gWiFiPlazaLobbyClient->currentMatch;
    if (index == WIFI_PLAZA_LOBBY_MATCH_NONE) {
        return -1;
    }
    return gWiFiPlazaLobbyClient->matches[index].hostId;
}

u8 WiFiPlazaLobbyClient_IsMatchHost(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    return gWiFiPlazaLobbyClient->isMatchHost;
}

BOOL WiFiPlazaLobbyClient_IsSpecialVisitor(int id) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    return WiFiPlazaLobbyIdValueList_Contains(&gWiFiPlazaLobbyClient->specialVisitors, id);
}

int WiFiPlazaLobbyClient_GetSpecialVisitorCode(int id) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    return WiFiPlazaLobbyIdValueList_GetValue(&gWiFiPlazaLobbyClient->specialVisitors, id);
}

void WiFiPlazaLobbyClient_SubmitSurveyAnswer(int index) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    GF_ASSERT(index < WIFI_PLAZA_LOBBY_MATCH_COUNT);
    GF_ASSERT(gWiFiPlazaLobbyClient->surveySubmitState != WIFI_PLAZA_SURVEY_SUBMIT_SENT);
    GF_ASSERT(WiFiPlazaLobbyClient_CheckResult(PPW_LobbySubmitQuestionnaire(index)) == TRUE);
    gWiFiPlazaLobbyClient->surveySubmitState = WIFI_PLAZA_SURVEY_SUBMIT_SENT;
}

enum WiFiPlazaSurveySubmitState WiFiPlazaLobbyClient_GetSurveySubmitState(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    return gWiFiPlazaLobbyClient->surveySubmitState;
}

u32 WiFiPlazaLobbyClient_GetSurveyValue(int field) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    GF_ASSERT(field < 11);
    switch (field) {
    case 0:
        return gWiFiPlazaLobbyClient->surveyData.surveys[0].surveyId;
    case 1:
        return gWiFiPlazaLobbyClient->surveyData.surveys[0].questionNo;
    case 2:
        return gWiFiPlazaLobbyClient->surveyData.surveys[0].isSpecial;
    case 3:
        return gWiFiPlazaLobbyClient->surveyData.surveys[0].questionNo >= 1000;
    case 4:
        return gWiFiPlazaLobbyClient->surveyData.surveys[1].surveyId;
    case 5:
        return gWiFiPlazaLobbyClient->surveyData.surveys[1].questionNo;
    case 6:
        return gWiFiPlazaLobbyClient->surveyData.surveys[1].isSpecial;
    case 7:
        return gWiFiPlazaLobbyClient->surveyData.surveys[1].questionNo >= 1000;
    case 8:
    case 9:
    case 10:
        return gWiFiPlazaLobbyClient->surveyData.lastWeekTotals[field - 8];
    default:
        GF_ASSERT(FALSE);
        return 0;
    }
}

void *WiFiPlazaLobbyClient_GetSurveyText(int field) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    GF_ASSERT(field < 8);
    switch (field) {
    case 0:
        return gWiFiPlazaLobbyClient->surveyData.surveys[0].questionText;
    case 1:
    case 2:
    case 3:
        return gWiFiPlazaLobbyClient->surveyData.surveys[0].answerTexts[field - 1];
    case 4:
        return gWiFiPlazaLobbyClient->surveyData.surveys[1].questionText;
    case 5:
    case 6:
    case 7:
        return gWiFiPlazaLobbyClient->surveyData.surveys[1].answerTexts[field - 5];
    default:
        GF_ASSERT(FALSE);
        return NULL;
    }
}

u8 WiFiPlazaLobbyClient_GetSurveyFlag(int which, int index) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    GF_ASSERT(which < 2);
    GF_ASSERT((u32)index < NELEMS(gWiFiPlazaLobbyClient->surveyData.surveys[0].languageFlags));
    if (which >= 2) {
        return 0;
    }
    if ((u32)index >= NELEMS(gWiFiPlazaLobbyClient->surveyData.surveys[0].languageFlags)) {
        return 0;
    }
    if (which == 0) {
        return gWiFiPlazaLobbyClient->surveyData.surveys[0].languageFlags[index];
    }
    return gWiFiPlazaLobbyClient->surveyData.surveys[1].languageFlags[index];
}

// Ends the matchmaking session.
void WiFiPlazaLobbyClient_EndMatch(void) {
    GF_ASSERT(gWiFiPlazaLobbyClient != NULL);
    WifiConnection_SetClientCallback(NULL, NULL);
    WifiConnection_SetDisconnectCallback(NULL, NULL);
    gWiFiPlazaLobbyClient->currentMatch = WIFI_PLAZA_LOBBY_MATCH_NONE;
    gWiFiPlazaLobbyClient->isMatchHost = FALSE;
    gWiFiPlazaLobbyClient->matchCancelled = FALSE;
}

// TRUE when a lobby library call succeeded (PPW_LOBBY_RESULT_SUCCESS).
BOOL WiFiPlazaLobbyClient_CheckResult(enum PPWLobbyResult result) {
    BOOL ret = TRUE;
    switch (result) {
    case PPW_LOBBY_RESULT_SUCCESS:
        break;
    case PPW_LOBBY_RESULT_ERROR_ALLOC:
    case PPW_LOBBY_RESULT_ERROR_SESSION:
    case PPW_LOBBY_RESULT_ERROR_STATE:
    case PPW_LOBBY_RESULT_ERROR_CHANNEL:
        ret = FALSE;
        break;
    case PPW_LOBBY_RESULT_ERROR_PARAM:
    case PPW_LOBBY_RESULT_ERROR_NODATA:
        GF_ASSERT(FALSE);
        ret = FALSE;
        break;
    case PPW_LOBBY_RESULT_ERROR_CONDITION:
        ret = FALSE;
        break;
    default:
        GF_ASSERT(FALSE);
        ret = FALSE;
        break;
    }
    return ret;
}

static void WiFiPlazaLobbyClient_ClearErrors(void) {
    gWiFiPlazaLobbyClient->ownRecordError = FALSE;
    gWiFiPlazaLobbyClient->requestError = FALSE;
}

// Channel <-> lobby library channel.
int WiFiPlazaLobbyClient_ChannelFromLib(int libChannel) {
    libChannel--;
    return libChannel < 0 ? WIFI_PLAZA_LOBBY_CHANNEL_NONE : libChannel;
}

int WiFiPlazaLobbyClient_ChannelToLib(int channel) {
    return channel + 1;
}

// The players of the lobby client: the data every player sends (playerDataSize bytes per lobby slot), the record of
// each slot (entry time, channel) and the two id lists (the lobby, the current channel).

// Adds the own country and region to the lobby locations (once) and sends the list.
static BOOL WiFiPlazaLobbyClient_AddOwnLocation(WiFiPlazaLobbyClient *client) {
    int country = WifiHistory_GetPlayerCountry(client->wifiHistory);
    int region = WiFiHistory_GetPlayerRegion(client->wifiHistory);
    int i;
    if (!country) {
        return FALSE;
    }
    for (i = 0; i < WIFI_PLAZA_MAX_PLAYERS; i++) {
        if (!client->locations[i].active) {
            break;
        }
        if (country == client->locations[i].country && region == client->locations[i].region) {
            return FALSE;
        }
    }
    if (i >= WIFI_PLAZA_MAX_PLAYERS) {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    client->locations[i].country = country;
    client->locations[i].region = region;
    client->locations[i].active = TRUE;
    return WiFiPlazaLobbyClient_CheckResult(PPW_LobbySetChannelData(-1, PPW_LOBBY_CHANNEL_KIND_MAIN, gWiFiPlazaLocationListKey, client->locations, sizeof(client->locations)));
}

static void WiFiPlazaLobbyClient_AllocPlayerData(WiFiPlazaLobbyClient *client, u32 size, enum HeapID heapID) {
    u32 bytes = size * WIFI_PLAZA_MAX_PLAYERS;
    gWiFiPlazaLobbyClient->playerData = Heap_Alloc(heapID, bytes);
    memset(gWiFiPlazaLobbyClient->playerData, 0, bytes);
    gWiFiPlazaLobbyClient->playerDataSize = size;
}

static void WiFiPlazaLobbyClient_FreePlayerData(WiFiPlazaLobbyClient *client) {
    Heap_Free(gWiFiPlazaLobbyClient->playerData);
}

void WiFiPlazaLobbyClient_SetPlayerData(WiFiPlazaLobbyClient *client, int id, const void *data) {
    WiFiPlazaLobbyClient_CopyPlayerData(client, id, data, client->playerDataSize);
}

void WiFiPlazaLobbyClient_CopyPlayerData(WiFiPlazaLobbyClient *client, int id, const void *data, u32 size) {
    int slot;
    u32 stride;
    u32 offset;
    u8 *base;
    slot = WiFiPlazaLobbyClient_FindInIdList(client, id, WIFI_PLAZA_LOBBY_SCOPE_LOBBY);
    GF_ASSERT(slot != -1);
    stride = client->playerDataSize;
    base = client->playerData;
    offset = stride * slot;
    if (stride > size) {
        memset(base + offset, 0, stride);
    } else {
        size = stride;
    }
    memcpy(base + offset, data, size);
}

WiFiPlazaPlayer *WiFiPlazaLobbyClient_GetPlayerData(WiFiPlazaLobbyClient *client, int id) {
    int slot = WiFiPlazaLobbyClient_FindInIdList(client, id, WIFI_PLAZA_LOBBY_SCOPE_LOBBY);
    GF_ASSERT(slot != -1);
    return (WiFiPlazaPlayer *)(client->playerData + client->playerDataSize * slot);
}

void WiFiPlazaLobbyClient_ClearPlayerData(WiFiPlazaLobbyClient *client, int id) {
    int slot = WiFiPlazaLobbyClient_FindInIdList(client, id, WIFI_PLAZA_LOBBY_SCOPE_LOBBY);
    GF_ASSERT(slot != -1);
    memset(client->playerData + client->playerDataSize * slot, 0, client->playerDataSize);
}

void WiFiPlazaLobbyClient_SetPlayerRecord(WiFiPlazaLobbyClient *client, int id, const WiFiPlazaLobbyPlayerRecord *record) {
    int slot = WiFiPlazaLobbyClient_FindInIdList(client, id, WIFI_PLAZA_LOBBY_SCOPE_LOBBY);
    WiFiPlazaLobbyPlayerRecord *dest;
    GF_ASSERT(slot != -1);
    dest = &client->records[slot];
    *dest = *record;
}

WiFiPlazaLobbyPlayerRecord *WiFiPlazaLobbyClient_GetPlayerRecord(WiFiPlazaLobbyClient *client, int id) {
    int slot = WiFiPlazaLobbyClient_FindInIdList(client, id, WIFI_PLAZA_LOBBY_SCOPE_LOBBY);
    GF_ASSERT(slot != -1);
    return &client->records[slot];
}

void WiFiPlazaLobbyClient_ClearPlayerRecord(WiFiPlazaLobbyClient *client, int id) {
    int slot = WiFiPlazaLobbyClient_FindInIdList(client, id, WIFI_PLAZA_LOBBY_SCOPE_LOBBY);
    u8 *bytes;
    GF_ASSERT(slot != -1);
    bytes = (u8 *)&client->records[slot];
    bytes[0] = 0;
    bytes[1] = 0;
    bytes[2] = 0;
    bytes[3] = 0;
    bytes[4] = 0;
    bytes[5] = 0;
    bytes[6] = 0;
    bytes[7] = 0;
    bytes[8] = 0;
    bytes[9] = 0;
    bytes[10] = 0;
    bytes[11] = 0;
}

static void WiFiPlazaLobbyClient_AllocIdLists(WiFiPlazaLobbyClient *client, u32 lobbyCapacity, u32 channelCapacity, enum HeapID heapID) {
    int i;
    u32 capacity;
    for (i = 0; i < WIFI_PLAZA_LOBBY_SCOPE_COUNT; i++) {
        GF_ASSERT(client->idLists[i].ids == NULL);
        if (i == WIFI_PLAZA_LOBBY_SCOPE_LOBBY) {
            capacity = lobbyCapacity;
        } else {
            capacity = channelCapacity;
        }
        client->idLists[i].count = 0;
        client->idLists[i].ids = Heap_Alloc(heapID, capacity * sizeof(s32));
        client->idLists[i].capacity = capacity;
        WiFiPlazaLobbyClient_ClearIdList(client, i);
    }
}

static void WiFiPlazaLobbyClient_FreeIdLists(WiFiPlazaLobbyClient *client) {
    int i;
    for (i = 0; i < WIFI_PLAZA_LOBBY_SCOPE_COUNT; i++) {
        GF_ASSERT(client->idLists[i].ids != NULL);
        Heap_Free(client->idLists[i].ids);
        client->idLists[i].ids = NULL;
    }
}

static void WiFiPlazaLobbyClient_ClearIdList(WiFiPlazaLobbyClient *client, int scope) {
    int i;
    client->idLists[scope].count = 0;
    for (i = 0; i < client->idLists[scope].capacity; i++) {
        client->idLists[scope].ids[i] = -1;
    }
}

void WiFiPlazaLobbyClient_AddToIdList(WiFiPlazaLobbyClient *client, int id, enum WiFiPlazaLobbyScope scope) {
    int i;
    int freeSlot;
    if (WiFiPlazaLobbyClient_FindInIdList(client, id, scope) == -1) {
        GF_ASSERT(client->idLists[scope].count < client->idLists[scope].capacity);
        if (client->idLists[scope].count < client->idLists[scope].capacity) {
            for (i = 0; i < client->idLists[scope].capacity; i++) {
                if (client->idLists[scope].ids[i] == -1) {
                    freeSlot = i;
                    break;
                }
            }
            client->idLists[scope].ids[freeSlot] = id;
            client->idLists[scope].count++;
        }
    }
}

void WiFiPlazaLobbyClient_RemoveFromIdList(WiFiPlazaLobbyClient *client, int id, enum WiFiPlazaLobbyScope scope) {
    int i = WiFiPlazaLobbyClient_FindInIdList(client, id, scope);
    if (i != -1) {
        client->idLists[scope].ids[i] = -1;
        client->idLists[scope].count--;
    }
}

// Lobby slot of a player id, -1 if not in the list.
int WiFiPlazaLobbyClient_FindInIdList(WiFiPlazaLobbyClient *client, int id, enum WiFiPlazaLobbyScope scope) {
    int i;
    for (i = 0; i < client->idLists[scope].capacity; i++) {
        if (client->idLists[scope].ids[i] == id) {
            return i;
        }
    }
    return -1;
}

int WiFiPlazaLobbyClient_GetIdListEntry(WiFiPlazaLobbyClient *client, int slot, enum WiFiPlazaLobbyScope scope) {
    GF_ASSERT(slot < client->idLists[scope].capacity);
    return client->idLists[scope].ids[slot];
}

// Rebuilds the channel list from the players' channels.
void WiFiPlazaLobbyClient_RebuildChannelList(WiFiPlazaLobbyClient *client, u32 channel) {
    int i;
    u32 libChannel = WiFiPlazaLobbyClient_ChannelToLib(channel);
    WiFiPlazaLobbyClient_ClearIdList(client, WIFI_PLAZA_LOBBY_SCOPE_CHANNEL);
    for (i = 0; i < client->idLists[WIFI_PLAZA_LOBBY_SCOPE_LOBBY].capacity; i++) {
        int id = WiFiPlazaLobbyClient_GetIdListEntry(client, i, WIFI_PLAZA_LOBBY_SCOPE_LOBBY);
        if (id != -1 && libChannel == client->records[i].channel) {
            WiFiPlazaLobbyClient_AddToIdList(client, id, WIFI_PLAZA_LOBBY_SCOPE_CHANNEL);
        }
    }
}
