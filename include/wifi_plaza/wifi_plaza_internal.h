#ifndef POKEHEARTGOLD_WIFI_PLAZA_INTERNAL_H
#define POKEHEARTGOLD_WIFI_PLAZA_INTERNAL_H

// Wi-Fi Plaza: the work data and the functions shared between its source files.

#include "global.h"

#include "constants/wifi_plaza.h"

#include "billboard_internal.h"
#include "billboard_lists.h"
#include "easy_chat.h"
#include "filesystem.h"
#include "friend_roster.h"
#include "gf_3d_loader.h"
#include "gf_gfx_loader.h"
#include "message_format.h"
#include "model_animation.h"
#include "msgdata.h"
#include "overlay_42.h"
#include "overlay_manager.h"
#include "player_data.h"
#include "ppw_lobby_work.h"
#include "pm_string.h"
#include "save.h"
#include "save_wifi_history.h"

typedef struct WiFiPlazaArgs {
    s64 *loginTime;
    SaveData *save;
    u32 skipPrompt;
} WiFiPlazaArgs;

// Second part of a plaza player record (copied to the save data when the plaza is left).
typedef struct WiFiPlazaPlayerSurvey {
    u32 surveyId;
    u32 answer; // < 3
} WiFiPlazaPlayerSurvey;

// A player in the plaza lobby: the own one is WiFiPlazaWork.profile.player, the others come from the lobby
// library.
typedef struct WiFiPlazaPlayer {
    u32 lobbyId;
    u32 trainerId;
    u16 name[8];
    u32 entryTime;   // WiFiPlaza_SecondsToTime of the entry time
    u32 localTime; // WiFiPlazaTime: local time of the location
    u16 species[6];
    u8 forms[6];
    u8 isEgg[6];
    u8 gender; // >= 2: taken from the avatar table
    u8 language;
    u16 avatarIndex; // mapped to the avatar by WiFiPlaza_IndexToAvatar
    u16 country;
    u8 region;
    u8 hasNationalDex;
    u8 gameCleared;
    u8 tapToy; // < 27
    u8 version;
    u8 activity;  // < 15
    s64 unk_44;   // SysInfo_RTC.seconds_since_nitro_epoch
    u8 slots[12]; // < 24: used
    s32 slotData[12];
    u16 favoriteTypes[2]; // < 18
    WiFiPlazaPlayerSurvey survey;
} WiFiPlazaPlayer;

typedef struct WiFiPlazaProfile {
    u16 name[8];
    u16 lobbyName[8]; // the name received from the lobby
    WiFiPlazaPlayer player;
    u32 crc; // of player
} WiFiPlazaProfile;

// The ids of the players in the lobby: -1 = free.
typedef struct WiFiPlazaPlayerList {
    s32 count;
    s32 *ids;
} WiFiPlazaPlayerList;

typedef struct WiFiPlazaAvatarEntry {
    u16 avatar;
    u16 unk_02;
} WiFiPlazaAvatarEntry;

// An exchange with one other player of the lobby.
typedef struct WiFiPlazaTalkSession {
    u32 talkedWith; // bit per lobby slot
    u16 partnerSlot;
    u8 state;
    u8 partnerArrived;
    u16 partnerMessage;
    u8 role; // 0 = none, 1 = asked the other player, 2 = asked by it
    u8 isFirstTalk;
    u8 talkCounts[WIFI_PLAZA_MAX_PLAYERS]; // per lobby slot, counts up to 6
    u16 sendMessage;
    u16 sendState;
    u16 timeoutActive;
    s16 timeoutCounter; // counts up to 900 while timeoutActive is set
} WiFiPlazaTalkSession;

// A message to the lobby (type 4).
typedef struct WiFiPlazaLobbyMessage {
    u32 ids[4]; // WiFiPlazaLobbyClient_SlotToId of lobby slots
    u8 count;
    u8 type;
    u8 tapToy;
    u8 option : 7;
    u8 allPlayers : 1;
} WiFiPlazaLobbyMessage;

typedef struct WiFiPlazaEventSchedule {
    u8 flag0 : 1;
    u8 flag1 : 1;
    u8 mode2 : 2;
    u8 flag4 : 1;
    u8 mode5 : 2;
    u8 flag7 : 1;
    u8 colorEvent;
    u8 light1Event;
    u8 thirdEvent;
    s16 closeTimer;
    s16 lightingDelay;
    s16 fireworksDelay;
    s16 paradeDelay;
    u8 minigameActive;
    u8 lowVolume;
    u8 bgmFadedOut;
    u8 low : 4;
    u8 high : 4;
} WiFiPlazaEventSchedule;

typedef struct WiFiPlazaSessionState {
    s16 timer;
    u8 appQuitForClosing;
    u8 unk_03;
    u8 flags[8];
} WiFiPlazaSessionState;

// Own status data sent to the other players of the lobby session; the same record as WifiClubPlayerStatus, of
// which the plaza fills in only the trainer.
typedef struct WiFiPlazaPlayerInfo {
    u16 species[6];
    u16 heldItems[6];
    u8 version;
    u8 language;
    u8 hasNationalDex;
    u8 status; // 28 in the Wi-Fi Plaza
    u8 unk_1C;
    u8 avatar;
    u8 gender;
    u8 country;
    u8 region;
    u8 voiceChat;
    u8 voiceChatSetting;
    u8 unk_23;
} WiFiPlazaPlayerInfo;

// A timer in 1/30 s of the lobby time.
typedef struct WiFiPlazaTimer {
    u32 active;
    s64 start;
    s32 elapsed;
    s32 duration;
    u32 phase;   // sWiFiPlazaTimerPhases[].phase, then 5 at the end
    u32 counter; // updates in the current phase
    WiFiPlazaPlayerInfo *playerInfo;
} WiFiPlazaTimer;

// A phase of WiFiPlazaTimer and its share of the duration (in 1/256).
typedef struct WiFiPlazaTimerPhase {
    u16 phase;
    u16 length;
} WiFiPlazaTimerPhase;

// The chance of each group of WiFiPlazaWork.groups.
typedef struct WiFiPlazaGroupWeights {
    u8 weights[WIFI_PLAZA_GROUP_COUNT];
    u8 padding_09[3];
    u8 seen[WIFI_PLAZA_MAX_PLAYERS]; // per lobby slot
} WiFiPlazaGroupWeights;

// Four words per lobby slot, made from a code.
typedef struct WiFiPlazaWordSet {
    u8 flags[WIFI_PLAZA_MAX_PLAYERS];
    u16 words[WIFI_PLAZA_MAX_PLAYERS][4];
    WallpaperPasswordBank *bank;
} WiFiPlazaWordSet;

// The survey tally of this plaza (WiFiPlazaSurveyTally), cached by the survey results screen.
typedef struct WiFiPlazaTallyCache {
    u32 words[5];
} WiFiPlazaTallyCache;

typedef struct WiFiPlazaOwnProfileData {
    PlayerProfile *profile; // the own profile as the lobby sees it
    BOOL gameConnectionLost;
    WiFiPlazaTallyCache tally;
    BOOL hasTally;
} WiFiPlazaOwnProfileData;

// Nine groups of three lobby slots.
typedef struct WiFiPlazaGroups {
    u32 active;
    s32 time;
    s32 counters[WIFI_PLAZA_GROUP_COUNT];
    u32 states[WIFI_PLAZA_GROUP_COUNT];
    u32 ids[WIFI_PLAZA_GROUP_COUNT][WIFI_PLAZA_GROUP_SEATS]; // -1 = free
    u32 markerCounts[WIFI_PLAZA_GROUP_COUNT][WIFI_PLAZA_GROUP_SEATS];
    u32 actionRequests[WIFI_PLAZA_GROUP_COUNT][WIFI_PLAZA_GROUP_SEATS];
} WiFiPlazaGroups;

// A time of day.
typedef union WiFiPlazaTime {
    u32 word;

    struct {
        u8 hour;
        u8 minute;
        u8 second;
        u8 unk_03;
    } field;

    u8 value[4];
    s8 signedValue[4];
} WiFiPlazaTime;

// A country and region.
typedef struct WiFiPlazaPlace {
    u16 country;
    u8 region;
    u8 value : 4;
    u8 occupied : 4;
} WiFiPlazaPlace;

// The last activities of the own player (id < 24, 24 = none; value -1 = none), a ring of 13 entries; crc covers
// everything before save.
typedef struct WiFiPlazaHistory {
    s32 values[13];
    u8 ids[13];
    u8 oldest;
    u8 next;
    SaveData *save;
    u16 crc;
    u16 corrupt;
} WiFiPlazaHistory;

// The applications of the plaza, one overlay at a time.
typedef struct WiFiPlazaApps {
    OverlayManager *manager;
    void *args[13]; // per app
    u8 current;     // app
    u8 skipPrompt;
    u16 heapID;
    struct WiFiPlazaWork *work;
    SaveData *save;
    s64 *loginTime;
} WiFiPlazaApps;

// What the lobby request handlers pass to the plaza news (with the player profiles in
// WiFiPlazaWork.profiles).
typedef struct WiFiPlazaPairRequest {
    PlayerProfile *profiles[2];
    u16 slots[2];
} WiFiPlazaPairRequest;

typedef struct WiFiPlazaPairOptionRequest {
    PlayerProfile *profiles[2];
    u16 slots[2];
    u32 option;
} WiFiPlazaPairOptionRequest;

typedef struct WiFiPlazaGroupRequest {
    u32 count;
    PlayerProfile *profiles[4];
    u16 slots[4];
} WiFiPlazaGroupRequest;

typedef struct WiFiPlazaGroupFlagRequest {
    u32 option;
    u32 count;
    PlayerProfile *profiles[4];
    u16 slots[4];
    u32 flag;
} WiFiPlazaGroupFlagRequest;

typedef struct WiFiPlazaSingleRequest {
    u32 option;
    u32 count;
    PlayerProfile *profile;
    u16 slot;
} WiFiPlazaSingleRequest;

typedef struct WiFiPlazaGroupOptionRequest {
    u32 option;
    u32 count;
    PlayerProfile *profiles[4];
    u16 slots[4];
} WiFiPlazaGroupOptionRequest;

typedef struct WiFiPlazaLobbyNotice {
    u32 *time;
    u32 which;
} WiFiPlazaLobbyNotice;

// A lobby slot in the plaza news.
typedef struct WiFiPlazaNewsSlot {
    u16 state; // 2: empty
    u16 flags; // bit 1: the oldest player
} WiFiPlazaNewsSlot;

typedef struct WiFiPlazaNewsSlots {
    WiFiPlazaNewsSlot slots[WIFI_PLAZA_MAX_PLAYERS];
    u16 change; // 1: a player came, 2: a player left
    u16 lastSlot;
} WiFiPlazaNewsSlots;

// An event (topic) of the plaza news: type 0-8 (message sWiFiPlazaNewsEventFormatters[type]), up to four player names and slots.
typedef struct WiFiPlazaNewsEvent {
    u8 type;
    u32 a;
    u32 b;
    u32 c;
    String *names[4];
    u16 slots[4];
    u16 rank;
    s16 timer;
    struct WiFiPlazaNewsEvent *next;
    struct WiFiPlazaNewsEvent *prev;
} WiFiPlazaNewsEvent;

typedef struct WiFiPlazaNewsEventList {
    WiFiPlazaNewsEvent events[8];
    WiFiPlazaNewsEvent head; // of the list ordered by rank
} WiFiPlazaNewsEventList;

// The plaza news, handed to the plaza news app.
typedef struct WiFiPlazaNews {
    u32 openTime; // WiFiPlazaTime of the lobby opening
    BOOL isOpen;
    WiFiPlazaNewsSlots slots;
    WiFiPlazaNewsEventList events;
} WiFiPlazaNews;

typedef struct WiFiPlazaWork {
    SaveData *save;
    WiFiPlazaNews *news;
    u32 lightingStarted;
    WiFiPlazaPlace places[50]; // filled from the profile
    WiFiPlazaTime currentTime;
    s64 lobbyTime;     // refreshed every frame
    s64 lobbyOpenTime; // PPW_LobbyGetTimeInfo when the lobby opened
    PlayerProfile *profiles[4];
    u32 changeFlags[4]; // per lobby slot: entered, left, events, updated
    WiFiPlazaProfile profile;
    WiFiPlazaTalkSession talk;
    u8 tapToyPlayed[WIFI_PLAZA_MAX_PLAYERS];
    WiFiPlazaEventSchedule eventSchedule;
    WiFiPlazaGroups groups;
    WiFiPlazaSessionState sessionState;
    WiFiPlazaGroupWeights groupWeights;
    u8 specialVisitors[WIFI_PLAZA_MAX_PLAYERS]; // per lobby slot
    u8 gameMembers[4];
    WiFiPlazaWordSet wordSet;
    WiFiPlazaTimer timer;
    WiFiPlazaHistory history;
    WiFiPlazaOwnProfileData ownProfileData;
    enum HeapID heapID;
    BOOL hasError;
} WiFiPlazaWork;

// Location tables of the earth place NARC (as in the Geonet globe app); y is the longitude angle.
typedef struct WiFiPlazaEarthCountry {
    u16 kind; // 2: the country has regions
    s16 x;
    s16 y;
} WiFiPlazaEarthCountry;

typedef struct WiFiPlazaEarthRegion {
    s16 x;
    s16 y;
} WiFiPlazaEarthRegion;

// Lobby callbacks (with the work as the last argument).
typedef struct WiFiPlazaCallbacks {
    void (*onPlayerEnter)(int id, WiFiPlazaPlayer *player, WiFiPlazaWork *work, BOOL isOwn);
    void (*onPlayerLeave)(int id, WiFiPlazaWork *work);
    void (*onPlayerUpdate)(int id, WiFiPlazaPlayer *player, WiFiPlazaWork *work);
    void (*onLobbyEvent)(u32 event, WiFiPlazaWork *work);
    void (*onOwnRecord)(const WiFiPlazaPlayer *data, u32 size, WiFiPlazaWork *work);
} WiFiPlazaCallbacks;

// The time a player entered the lobby (an s64 kept as two words).
typedef struct WiFiPlazaLobbyEntryTime {
    u32 lo;
    u32 hi;
} WiFiPlazaLobbyEntryTime;

// What the lobby keeps per player.
typedef struct WiFiPlazaLobbyPlayerRecord {
    WiFiPlazaLobbyEntryTime entryTime;
    u32 channel; // lobby library channel, WIFI_PLAZA_LOBBY_LIB_CHANNEL_NONE = none
} WiFiPlazaLobbyPlayerRecord;

// The lobby as a whole and the own channel: the index of gWiFiPlazaLobbyClient->idLists and commandTables.
enum WiFiPlazaLobbyScope {
    WIFI_PLAZA_LOBBY_SCOPE_LOBBY,
    WIFI_PLAZA_LOBBY_SCOPE_CHANNEL,
    WIFI_PLAZA_LOBBY_SCOPE_COUNT,
};

// The ids of the players in the lobby or in the own channel, -1 = free.
typedef struct WiFiPlazaLobbyIdList {
    s16 count;
    u16 capacity;
    s32 *ids;
} WiFiPlazaLobbyIdList;

// A message type of the lobby client: its receive callback and the size of its data.
typedef struct WiFiPlazaLobbyCommand {
    void (*callback)(int id, const void *data, u32 size, void *arg);
    u32 size;
} WiFiPlazaLobbyCommand;

typedef struct WiFiPlazaLobbyCommandTable {
    const WiFiPlazaLobbyCommand *commands;
    u32 count;
    void *arg;
} WiFiPlazaLobbyCommandTable;

typedef struct WiFiPlazaLobbyLocation {
    u16 country;
    u8 region;
    u8 active;
} WiFiPlazaLobbyLocation;

// What the host of a matchmaking session sends about it.
typedef struct WiFiPlazaLobbyMatchInfo {
    int index;
    int maxPlayers;
    int playerCount; // WifiConnection_GetNumConnectionHost for the own session
    int state;       // WIFI_PLAZA_MATCH_*
    WiFiPlazaLobbyEntryTime startTime;
    u8 padding_18[0x18];
    char name[0x14];
} WiFiPlazaLobbyMatchInfo;

typedef struct WiFiPlazaLobbyMatch {
    WiFiPlazaLobbyMatchInfo info;
    u16 active;
    u16 timer;  // frames left, 1800 at the start
    int hostId; // own id when hosting
} WiFiPlazaLobbyMatch;

typedef struct WiFiPlazaLobbyIdValue {
    u32 id;
    u32 value;
} WiFiPlazaLobbyIdValue;

// The special visitors of the lobby with their codes.
typedef struct WiFiPlazaLobbyIdValueList {
    WiFiPlazaLobbyIdValue *items;
    u16 capacity;
    volatile u16 count;
} WiFiPlazaLobbyIdValueList;

// The lobby schedule as PPW_LobbyGetSchedule copies it: the record (roomFlag bit 0: the Arceus footprint is shown)
// and room for the rest of its events.
typedef struct WiFiPlazaLobbySchedule {
    PPWLobbyScheduleRecord record;
    LobbyEvent moreEvents[125];
} WiFiPlazaLobbySchedule;

typedef struct WiFiPlazaLobbySurvey {
    u32 surveyId;
    s32 questionNo;
    u8 questionText[0xDC];
    u8 answerTexts[3][0x24];
    u8 languageFlags[12];
    BOOL isSpecial;
} WiFiPlazaLobbySurvey;

// This week's and last week's survey and last week's results.
typedef struct WiFiPlazaLobbySurveyData {
    WiFiPlazaLobbySurvey surveys[2];
    u32 unk_2D0[3];
    u32 lastWeekTotals[3];
} WiFiPlazaLobbySurveyData;

// A player on the plaza map: a billboard sprite of the field character models with a model under it.
typedef struct WiFiPlazaPlayerObject {
    u8 mode : 4; // 0: plays `effect`, else follows the player's action
    u8 culled : 2;
    u8 visible : 2;
    u8 effectActive : 1;
    u8 effect : 7; // index into sWiFiPlazaPlayerObjectEffects
    u8 timer;
    u8 step;
    Field2DObject *player; // NULL = free slot
    BillboardObject *billboard;
    ModelInstance model;
    u8 action;        // Field2DObject_GetParam field 5
    u8 savedSequence; // sequence and frame when an action that keeps the sequence ended
    u16 actionFrame;  // Field2DObject_GetParam field 8
    u32 savedFrame;
    u32 lightFlags;
} WiFiPlazaPlayerObject;

typedef struct WiFiPlazaObjectModel {
    ModelResource resource;
    int alpha; // 0 = the models are not drawn
} WiFiPlazaObjectModel;

typedef struct WiFiPlazaPlayerObjects {
    GF_2DGfxRawResMan *models;    // the billboard model
    GF_2DGfxRawResMan *sequences; // 2 sprite sequences (sWiFiPlazaSpriteSequenceFiles)
    GF_3DGfxRawResMan *textures;  // 20 sprites (sWiFiPlazaSpriteConfigs)
    Billboard *billboards;
    WiFiPlazaPlayerObject *objects;
    u32 count;
    WiFiPlazaObjectModel model;
    u32 lightFlags; // of the billboard model
} WiFiPlazaPlayerObjects;

typedef struct WiFiPlazaSpriteConfig {
    u16 spriteId; // Field2DObject_GetParam field 7
    u16 fileId : 15;
    u16 ownTexture : 1; // texture loaded per object instead of once into VRAM
} WiFiPlazaSpriteConfig;

// gWiFiPlazaLobbyClient->state
#define WIFI_PLAZA_LOBBY_STATE_DISCONNECTED 0
#define WIFI_PLAZA_LOBBY_STATE_CONNECTING   1
#define WIFI_PLAZA_LOBBY_STATE_IN_LOBBY     2
#define WIFI_PLAZA_LOBBY_STATE_CLOSING      3
#define WIFI_PLAZA_LOBBY_STATE_ERROR        4

// gWiFiPlazaLobbyClient->channel when in no channel, and the lobby library's channel number for no channel
#define WIFI_PLAZA_LOBBY_CHANNEL_NONE     4
#define WIFI_PLAZA_LOBBY_LIB_CHANNEL_NONE 5

// gWiFiPlazaLobbyClient->matches; currentMatch is WIFI_PLAZA_LOBBY_MATCH_NONE when in no match
#define WIFI_PLAZA_LOBBY_MATCH_COUNT 3
#define WIFI_PLAZA_LOBBY_MATCH_NONE  WIFI_PLAZA_LOBBY_MATCH_COUNT

// gWiFiPlazaLobbyClient->channelState
#define WIFI_PLAZA_CHANNEL_STATE_NONE    0
#define WIFI_PLAZA_CHANNEL_STATE_JOINING 1
#define WIFI_PLAZA_CHANNEL_STATE_JOINED  2
#define WIFI_PLAZA_CHANNEL_STATE_LEAVING 3
#define WIFI_PLAZA_CHANNEL_STATE_ERROR   4

// gWiFiPlazaLobbyClient->joinChannelResult
enum WiFiPlazaJoinChannelResult {
    WIFI_PLAZA_JOIN_CHANNEL_PENDING,
    WIFI_PLAZA_JOIN_CHANNEL_DONE,
    WIFI_PLAZA_JOIN_CHANNEL_FAILED,
};

// WiFiPlazaLobbyMatchInfo.state
#define WIFI_PLAZA_MATCH_OPEN   0
#define WIFI_PLAZA_MATCH_CLOSED 1

// The lobby client (gWiFiPlazaLobbyClient).
typedef struct WiFiPlazaLobbyClient {
    SaveData *save;
    FriendRoster *friendRoster;
    SaveWiFiHistory *wifiHistory;
    WiFiPlazaCallbacks callbacks;
    void *callbackArg; // last argument of the callbacks
    u8 *playerData;    // playerDataSize bytes per lobby slot
    u32 playerDataSize;
    WiFiPlazaLobbyPlayerRecord records[WIFI_PLAZA_MAX_PLAYERS];
    WiFiPlazaLobbyIdList idLists[WIFI_PLAZA_LOBBY_SCOPE_COUNT];
    u8 state;        // WIFI_PLAZA_LOBBY_STATE_*
    u8 channel;      // WIFI_PLAZA_LOBBY_CHANNEL_NONE = none
    u8 channelState; // WIFI_PLAZA_CHANNEL_STATE_*
    u8 joinChannelResult;
    u8 addingLocation;
    u8 excessFlood;
    u8 requestError;
    u8 ownRecordError;
    WiFiPlazaLobbyLocation locations[WIFI_PLAZA_MAX_PLAYERS];
    WiFiPlazaLobbyCommandTable commandTables[WIFI_PLAZA_LOBBY_SCOPE_COUNT];
    PPWLobbyTimeInfo time;                       // refreshed every frame
    WiFiPlazaLobbySchedule schedule; // received with PPW_LobbyGetSchedule
    u32 scheduleSize;
    WiFiPlazaLobbyMatch matches[WIFI_PLAZA_LOBBY_MATCH_COUNT];
    u16 currentMatch; // WIFI_PLAZA_LOBBY_MATCH_NONE = none
    u8 isMatchHost;
    u8 matchCancelled;
    WiFiPlazaLobbyIdValueList specialVisitors;
    WiFiPlazaLobbySurveyData surveyData;
    enum WiFiPlazaSurveySubmitState surveySubmitState;
    enum PPWLobbyResult initResult;
} WiFiPlazaLobbyClient;

BOOL WiFiPlazaWork_HasError(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_TakeExcessFlood(WiFiPlazaWork *work);
WiFiPlazaNews *WiFiPlazaWork_GetNews(WiFiPlazaWork *work);
WiFiPlazaPlace *WiFiPlazaWork_GetPlaces(WiFiPlazaWork *work);
WiFiPlazaTime *WiFiPlazaWork_GetCurrentTimePtr(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_TakePlayerEntered(WiFiPlazaWork *work, int bit);
BOOL WiFiPlazaWork_TakePlayerLeft(WiFiPlazaWork *work, int bit);
BOOL WiFiPlazaWork_IsEventFlagSet(WiFiPlazaWork *work, int bit);
BOOL WiFiPlazaWork_TakePlayerUpdated(WiFiPlazaWork *work, int bit);
SaveData *WiFiPlazaWork_GetSaveData(WiFiPlazaWork *work);
int WiFiPlazaWork_IsArceusFootprintShown(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_HasAnsweredSurvey(WiFiPlazaWork *work);
u32 WiFiPlazaWork_GetEventScheduleHigh(WiFiPlazaWork *work);
void WiFiPlazaWork_SetEventScheduleHigh(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_IsLobbyOpen(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_IsClosing(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_IsClosed(WiFiPlazaWork *work);
u32 WiFiPlazaWork_GetFireworksState(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_IsParadeStarted(WiFiPlazaWork *work);
u32 WiFiPlazaWork_GetEventScheduleMode5(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_IsLightingStarted(WiFiPlazaWork *work);
u32 WiFiPlazaWork_GetColorEvent(WiFiPlazaWork *work);
u32 WiFiPlazaWork_GetLight1Event(WiFiPlazaWork *work);
u32 WiFiPlazaWork_GetThirdEvent(WiFiPlazaWork *work);
void WiFiPlazaWork_StartGameEntryCooldown(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_IsGameEntryCoolingDown(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_GetGameConnectionLost(WiFiPlazaWork *work);
void WiFiPlazaWork_SetGameConnectionLost(WiFiPlazaWork *work, BOOL value);
void WiFiPlazaWork_ClearGameMembers(WiFiPlazaWork *work);
void WiFiPlazaWork_SetGameMember(WiFiPlazaWork *work, int id, u32 index);
void WiFiPlazaWork_SetOwnGameMember(WiFiPlazaWork *work, u32 index);
void WiFiPlazaWork_GetGameMembers(WiFiPlazaWork *work, u8 *dest);
void WiFiPlazaWork_SetAppQuitForClosing(WiFiPlazaWork *work);
int WiFiPlazaWork_DidAppQuitForClosing(WiFiPlazaWork *work);
void WiFiPlazaWork_SetMinigameActiveFlag(WiFiPlazaWork *work, u8 value);

void WiFiPlazaWork_PlayBGM(WiFiPlazaWork *work);
void WiFiPlazaWork_SetLowVolume(WiFiPlazaWork *work, int value);
int WiFiPlazaWork_GetOwnSlot(WiFiPlazaWork *work);
int WiFiPlazaWork_GetOwnId(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_IsSlotOccupied(WiFiPlazaWork *work, int index);
WiFiPlazaPlayer *WiFiPlazaWork_GetPlayer(WiFiPlazaWork *work, u32 index);
WiFiPlazaPlayer *WiFiPlazaWork_GetMyPlayer(WiFiPlazaWork *work);
void WiFiPlazaWork_SetActivity(WiFiPlazaWork *work, int value);
void WiFiPlazaWork_AddHistory(WiFiPlazaWork *work, int index, int value);
void WiFiPlazaWork_SetTapToy(WiFiPlazaWork *work, u32 value);
void WiFiPlazaWork_SetFavoriteTypes(WiFiPlazaWork *work, int a, int b);
void WiFiPlazaWork_SetSurveyAnswer(WiFiPlazaWork *work, u32 a, u32 b);
void WiFiPlazaPlayer_CopyToProfile(WiFiPlazaPlayer *player, PlayerProfile *profile, enum HeapID heapID);
int WiFiPlazaPlayer_GetActivity(WiFiPlazaPlayer *player);
u8 WiFiPlazaPlayer_GetHistoryId(WiFiPlazaPlayer *player, u32 index);
int WiFiPlazaPlayer_GetHistoryValue(WiFiPlazaPlayer *player, u32 index);
u32 WiFiPlazaPlayer_GetLobbyId(WiFiPlazaPlayer *player);
int WiFiPlazaPlayer_GetAvatarIndex(WiFiPlazaPlayer *player);
u32 WiFiPlazaPlayer_GetLocalTime(WiFiPlazaPlayer *player);
u32 WiFiPlazaPlayer_GetGender(WiFiPlazaPlayer *player);
u32 WiFiPlazaPlayer_GetLanguage(WiFiPlazaPlayer *player);
BOOL WiFiPlazaPlayer_IsLanguageValid(WiFiPlazaPlayer *player);
u8 WiFiPlazaPlayer_GetRawLanguage(WiFiPlazaPlayer *player);
u16 WiFiPlazaPlayer_GetAvatar(WiFiPlazaPlayer *player);
u16 WiFiPlazaPlayer_GetCountry(WiFiPlazaPlayer *player);
u8 WiFiPlazaPlayer_GetRegion(WiFiPlazaPlayer *player);
u8 WiFiPlazaPlayer_GetTapToy(WiFiPlazaPlayer *player);
BOOL WiFiPlazaPlayer_HasTapToy(WiFiPlazaPlayer *player);
u16 WiFiPlazaPlayer_GetFavoriteType(WiFiPlazaPlayer *player, u32 index);
void WiFiPlazaPlayer_GetSurvey(WiFiPlazaPlayer *player, WiFiPlazaPlayerSurvey *out);

PlayerProfile *WiFiPlazaWork_GetOwnPlayerProfile(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_IsSpecialVisitor(WiFiPlazaWork *work, int slot);
void WiFiPlazaWork_GetSpecialVisitors(WiFiPlazaWork *work, u8 *dest);
BOOL WiFiPlazaWork_HasWordSet(WiFiPlazaWork *work, int slot);
u16 *WiFiPlazaWork_GetWordSet(WiFiPlazaWork *work, int slot);
u32 WiFiPlaza_GetChannelPlayerCount(WiFiPlazaWork *work);
int WiFiPlaza_ChannelSlotToSlot(WiFiPlazaWork *work, int channelSlot);
void WiFiPlaza_SendChatNews(WiFiPlazaWork *work, u32 slot0, u32 slot1);
void WiFiPlaza_SendTapToyTradeNews(WiFiPlazaWork *work, u32 slot0, u32 slot1, u8 value);
void WiFiPlaza_SendActivityNews(WiFiPlazaWork *work, int selector, int count, int slot0, int slot1, int slot2, int slot3, int flag);
void WiFiPlaza_SendMinigameResultNews(WiFiPlazaWork *work, int game, int count, u32 slot0, u32 slot1, u32 slot2, u32 slot3);
int WiFiPlazaWork_GetScheduleValue3(WiFiPlazaWork *work);
int WiFiPlazaWork_GetScheduleValue2(WiFiPlazaWork *work);
int WiFiPlazaWork_GetOpenDuration(WiFiPlazaWork *work);
u8 WiFiPlazaWork_HasPlayedTapToy(WiFiPlazaWork *work, u32 index);
void WiFiPlazaWork_SendTapToyPlayed(WiFiPlazaWork *work, u32 value);
int WiFiPlazaWork_GetGroupState(WiFiPlazaWork *work, int group);
int WiFiPlazaWork_GetGroupCounter(WiFiPlazaWork *work, int group);
int WiFiPlazaWork_GetGroupDuration(WiFiPlazaWork *work);
int WiFiPlazaWork_FindGroupPlace(WiFiPlazaWork *work, int id);
int WiFiPlazaWork_JoinGroup(WiFiPlazaWork *work, int id, int value);
void WiFiPlazaWork_LeaveGroup(WiFiPlazaWork *work, int id);
void WiFiPlazaWork_RequestGroupAction(WiFiPlazaWork *work, int id);
int WiFiPlazaWork_GetGroupActionRequest(WiFiPlazaWork *work, int place);
void WiFiPlazaWork_ClearGroupActionRequest(WiFiPlazaWork *work, int place);
void WiFiPlaza_SplitGroupPlace(u32 value, u32 *quotient, u32 *remainder);
void WiFiPlazaWork_SetGroupMarkerPassed(WiFiPlazaWork *work, int place, int value);
int WiFiPlazaWork_GetGroupMarkerCount(WiFiPlazaWork *work, int place);
void WiFiPlazaWork_SendJoinGroup(WiFiPlazaWork *work);
void WiFiPlazaWork_SendGroupAction(WiFiPlazaWork *work);
void WiFiPlazaWork_ResetTalk(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_StartTalk(WiFiPlazaWork *work, int slot);
void WiFiPlazaWork_AdvanceTalk(WiFiPlazaWork *work, int value);
void WiFiPlazaWork_CancelTalkRequest(WiFiPlazaWork *work);
void WiFiPlazaWork_EndTalk(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_IsTalking(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_WasAskedToTalk(WiFiPlazaWork *work);
u16 WiFiPlazaWork_GetTalkPartner(WiFiPlazaWork *work);
u8 WiFiPlazaWork_IsFirstTalk(WiFiPlazaWork *work);
u8 WiFiPlazaWork_GetTalkState(WiFiPlazaWork *work);
u16 WiFiPlazaWork_GetTalkPartnerMessage(WiFiPlazaWork *work);
BOOL WiFiPlazaWork_IsTalkOver(WiFiPlazaWork *work);
s16 WiFiPlazaWork_GetTalkTimeoutCounter(WiFiPlazaWork *work);
void WiFiPlazaWork_SetTalkPartnerArrived(WiFiPlazaWork *work);
u8 WiFiPlazaWork_HasTalkPartnerArrived(WiFiPlazaWork *work);

void WiFiPlazaWork_IncPartnerTalkCount(WiFiPlazaWork *work);
void WiFiPlazaWork_IncTalkCount(WiFiPlazaWork *work, int slot);
void WiFiPlazaWork_SetTalkedWith(WiFiPlazaWork *work, int slot);
void IncrementGameStat47(WiFiPlazaWork *work);
void IncrementGameStat119(WiFiPlazaWork *work);
void WiFiPlazaWork_MarkActivityDone(WiFiPlazaWork *work, int slot);
int WiFiPlazaWork_GetNextUndoneActivity(WiFiPlazaWork *work);
int WiFiPlazaWork_PickTapToy(WiFiPlazaWork *work);
u32 WiFiPlazaWork_GetFireworksPhase(WiFiPlazaWork *work);
u32 WiFiPlazaWork_GetFireworksCounter(WiFiPlazaWork *work);
void WiFiPlazaWork_SetSurveyTally(WiFiPlazaWork *work, const WiFiPlazaTallyCache *tally);
BOOL WiFiPlazaWork_GetSurveyTally(WiFiPlazaWork *work, WiFiPlazaTallyCache *tally);
void WiFiPlazaWork_NewPlayerInfo(WiFiPlazaWork *work);
void WiFiPlazaWork_FreePlayerInfo(WiFiPlazaWork *work);

BOOL WiFiPlaza_Init(OverlayManager *man, int *state);
BOOL WiFiPlaza_Main(OverlayManager *man, int *state);
BOOL WiFiPlaza_Exit(OverlayManager *man, int *state);

void WiFiPlazaHistory_Init(WiFiPlazaHistory *history, SaveData *save);
void WiFiPlazaHistory_Add(WiFiPlazaHistory *history, int id, s32 value);
BOOL WiFiPlazaHistory_ReplaceValue(WiFiPlazaHistory *history, s32 oldValue, s32 newValue);
u8 WiFiPlazaHistory_RemoveOldest(WiFiPlazaHistory *history);
u8 WiFiPlazaHistory_GetId(WiFiPlazaHistory *history, u32 index);
s32 WiFiPlazaHistory_GetValue(WiFiPlazaHistory *history, u32 index);
void WiFiPlazaHistory_UpdateChecksum(WiFiPlazaHistory *history);
void WiFiPlazaHistory_CheckChecksum(WiFiPlazaHistory *history);
u16 WiFiPlazaHistory_IsCorrupt(WiFiPlazaHistory *history);

int WiFiPlaza_AvatarToIndex(u16 avatar);
u16 WiFiPlaza_IndexToAvatar(u32 index);
WiFiPlazaApps *WiFiPlazaApps_New(u32 skipPrompt, SaveData *save, s64 *loginTime, WiFiPlazaWork *work, enum HeapID heapID);
void WiFiPlazaApps_Delete(WiFiPlazaApps *apps);
void WiFiPlazaApps_StartFirst(WiFiPlazaApps *apps);
BOOL WiFiPlazaApps_Run(WiFiPlazaApps *apps);
void WiFiPlazaApps_VBlank(WiFiPlazaApps *apps);
void WiFiPlaza_SecondsToTime(u32 *out, s64 *seconds);

void WiFiPlazaTime_Add(const WiFiPlazaTime *left, const WiFiPlazaTime *right, WiFiPlazaTime *out);
void WiFiPlazaTime_Subtract(const WiFiPlazaTime *first, const WiFiPlazaTime *second, WiFiPlazaTime *out);
void WiFiPlazaPlaces_Add(WiFiPlazaPlace *places, u32 country, u32 region, u32 value);
u32 WiFiPlazaPlaces_GetCountry(WiFiPlazaPlace *places, u8 index);
u32 WiFiPlazaPlaces_GetRegion(WiFiPlazaPlace *places, u8 index);
u32 WiFiPlazaPlaces_GetValue(WiFiPlazaPlace *places, u8 index);
u32 WiFiPlazaPlaces_IsOccupied(WiFiPlazaPlace *places, u8 index);
void WiFiPlaza_DisableModelLighting(NNSG3dResFileHeader *file);
BOOL WiFiPlaza_IsRegionValid(u32 country, u32 region);
u32 WiFiPlaza_GetTypeByChoice(u32 index);
int WiFiPlaza_GetErrorMessageClass(u32 errorCode, u32 context);
BOOL WiFiPlaza_IsErrorRecoverable(u32 errorCode, u32 context);
BOOL WiFiPlaza_HasConnectionFailed(void);
// WiFiPlazaNews_GetEventSlot: the event names no further lobby slot.
#define WIFI_PLAZA_NEWS_NO_SLOT WIFI_PLAZA_MAX_PLAYERS

WiFiPlazaNews *WiFiPlazaNews_New(enum HeapID heapID);
void WiFiPlazaNews_Delete(WiFiPlazaNews *news);
void WiFiPlazaNews_Update(WiFiPlazaNews *news);

void WiFiPlazaNews_SetOpenTime(WiFiPlazaNews *news, u32 *openTime);
void WiFiPlazaNews_AddPlayer(WiFiPlazaNews *news, int slot, int state, int flags);
BOOL WiFiPlazaNews_RemovePlayer(WiFiPlazaNews *news, int slot);
void WiFiPlazaNews_SetOldestPlayer(WiFiPlazaNews *news, int slot);
void WiFiPlazaNews_AddChatEvent(WiFiPlazaNews *news, WiFiPlazaPairRequest *req);
void WiFiPlazaNews_AddTapToyTradeEvent(WiFiPlazaNews *news, WiFiPlazaPairOptionRequest *req);
void WiFiPlazaNews_AddMinigameEntryEvent(WiFiPlazaNews *news, WiFiPlazaGroupFlagRequest *req);
void WiFiPlazaNews_AddFootprintStampEvent(WiFiPlazaNews *news, WiFiPlazaSingleRequest *req);
void WiFiPlazaNews_AddVisitorProfilesEvent(WiFiPlazaNews *news, WiFiPlazaGroupRequest *req);
void WiFiPlazaNews_AddPlazaNewsEvent(WiFiPlazaNews *news, WiFiPlazaGroupRequest *req);
void WiFiPlazaNews_AddLobbyEventNotice(WiFiPlazaNews *news, WiFiPlazaLobbyNotice *notice);
void WiFiPlazaNews_AddSpecialVisitorEvent(WiFiPlazaNews *news, int *slot, const u8 *flags);
void WiFiPlazaNews_AddMinigameResultEvent(WiFiPlazaNews *news, WiFiPlazaGroupOptionRequest *req);
void WiFiPlazaNews_RemoveCurrentEvent(WiFiPlazaNews *news);
u32 WiFiPlazaNews_GetOpenTime(WiFiPlazaNews *news, u32 *openTime);
BOOL WiFiPlazaNews_IsSlotOccupied(WiFiPlazaNews *news, int slot);
int WiFiPlazaNews_GetSlotGender(WiFiPlazaNews *news, int slot);
BOOL WiFiPlazaNews_IsOwnSlot(WiFiPlazaNews *news, int slot);
BOOL WiFiPlazaNews_IsOldestSlot(WiFiPlazaNews *news, int slot);
BOOL WiFiPlazaNews_IsLastJoinedSlot(WiFiPlazaNews *news, int slot);
u16 WiFiPlazaNews_GetSlotChange(WiFiPlazaNews *news);
BOOL WiFiPlazaNews_HasEvent(WiFiPlazaNews *news);
u8 WiFiPlazaNews_GetEventType(WiFiPlazaNews *news);
BOOL WiFiPlazaNews_FormatEvent(WiFiPlazaNews *news, const u8 *flags, int unused, String *out, enum HeapID heapID);
int WiFiPlazaNews_GetEventSlot(WiFiPlazaNews *news, int unused, int index);
void WiFiPlazaNewsSlots_Init(WiFiPlazaNewsSlots *slots);
void WiFiPlazaNewsSlots_Set(WiFiPlazaNewsSlots *slots, int slot, int state, int flags);
void WiFiPlazaNewsSlots_AddPlayer(WiFiPlazaNewsSlots *slots, int slot, int state, int flags);
void WiFiPlazaNewsSlots_RemovePlayer(WiFiPlazaNewsSlots *slots, int slot);
void WiFiPlazaNewsSlots_SetFlags(WiFiPlazaNewsSlots *slots, int slot, int flags);
void WiFiPlazaNewsSlots_SetChange(WiFiPlazaNewsSlots *slots, int change);
void WiFiPlazaNewsSlots_SetLastJoined(WiFiPlazaNewsSlots *slots, int slot);
BOOL WiFiPlazaNewsSlots_IsOccupied(WiFiPlazaNewsSlots *slots, int slot);
int WiFiPlazaNewsSlots_GetGender(WiFiPlazaNewsSlots *slots, int slot);
BOOL WiFiPlazaNewsSlots_IsOwn(WiFiPlazaNewsSlots *slots, int slot);
BOOL WiFiPlazaNewsSlots_IsOldest(WiFiPlazaNewsSlots *slots, int slot);
int WiFiPlazaNewsSlots_GetFlags(WiFiPlazaNewsSlots *slots, int slot);
u16 WiFiPlazaNewsSlots_GetChange(WiFiPlazaNewsSlots *slots);

BOOL WiFiPlazaNewsSlots_IsLastJoined(WiFiPlazaNewsSlots *slots, u32 slot);
void WiFiPlazaNewsEventList_Init(WiFiPlazaNewsEventList *list, enum HeapID heapID);
void WiFiPlazaNewsEventList_Free(WiFiPlazaNewsEventList *list);
void WiFiPlazaNewsEventList_Update(WiFiPlazaNewsEventList *list);
void WiFiPlazaNewsEventList_RemoveFirst(WiFiPlazaNewsEventList *list);
WiFiPlazaNewsEvent *WiFiPlazaNewsEventList_GetFreeEvent(WiFiPlazaNewsEventList *list, u16 rank);
void WiFiPlazaNewsEvent_InsertAfter(WiFiPlazaNewsEvent *at, WiFiPlazaNewsEvent *event);
void WiFiPlazaNewsEventList_Insert(WiFiPlazaNewsEventList *list, WiFiPlazaNewsEvent *event);
void WiFiPlazaNewsEventList_Remove(WiFiPlazaNewsEventList *list, WiFiPlazaNewsEvent *event);
void WiFiPlazaNewsEvent_Set(WiFiPlazaNewsEvent *event, u32 a, u32 b, u32 c, const PlayerProfile *player0, const PlayerProfile *player1, const PlayerProfile *player2, const PlayerProfile *player3, u16 slot0, u16 slot1, u16 slot2, u16 slot3, u32 timer, u32 rank, u32 type);
BOOL WiFiPlazaNewsEvent_FormatChat(WiFiPlazaNewsEvent *event, const u8 *flags, MessageFormat *format, MsgData *msgData, String *out, enum HeapID heapID);
BOOL WiFiPlazaNewsEvent_FormatTapToyTrade(WiFiPlazaNewsEvent *event, const u8 *flags, MessageFormat *format, MsgData *msgData, String *out, enum HeapID heapID);
BOOL WiFiPlazaNewsEvent_FormatMinigameEntry(WiFiPlazaNewsEvent *event, const u8 *flags, MessageFormat *format, MsgData *msgData, String *out, enum HeapID heapID);
BOOL WiFiPlazaNewsEvent_FormatFootprintStamp(WiFiPlazaNewsEvent *event, const u8 *flags, MessageFormat *format, MsgData *msgData, String *out, enum HeapID heapID);
BOOL WiFiPlazaNewsEvent_FormatChecking(WiFiPlazaNewsEvent *event, const u8 *flags, MessageFormat *format, MsgData *msgData, String *out, enum HeapID heapID);
BOOL WiFiPlazaNewsEvent_FormatLobbyEventNotice(WiFiPlazaNewsEvent *event, const u8 *flags, MessageFormat *format, MsgData *msgData, String *out, enum HeapID heapID);
BOOL WiFiPlazaNewsEvent_FormatSpecialVisitor(WiFiPlazaNewsEvent *event, const u8 *flags, MessageFormat *format, MsgData *msgData, String *out, enum HeapID heapID);
BOOL WiFiPlazaNewsEvent_FormatMinigameResult(WiFiPlazaNewsEvent *event, const u8 *flags, MessageFormat *format, MsgData *msgData, String *out, enum HeapID heapID);
u16 WiFiPlazaNewsEvent_GetChatSlot(WiFiPlazaNewsEvent *event, u32 index);
u16 WiFiPlazaNewsEvent_GetTapToyTradeSlot(WiFiPlazaNewsEvent *event, u32 index);
u16 WiFiPlazaNewsEvent_GetMinigameEntrySlot(WiFiPlazaNewsEvent *event, u32 index);
u16 WiFiPlazaNewsEvent_GetFootprintStampSlot(WiFiPlazaNewsEvent *event, u32 index);
u16 WiFiPlazaNewsEvent_GetCheckingSlot(WiFiPlazaNewsEvent *event, u32 index);
u16 WiFiPlazaNewsEvent_GetLobbyEventNoticeSlot(WiFiPlazaNewsEvent *event, u32 index);
u16 WiFiPlazaNewsEvent_GetSpecialVisitorSlot(WiFiPlazaNewsEvent *event, u32 index);

extern WiFiPlazaLobbyClient *gWiFiPlazaLobbyClient;
u16 WiFiPlazaNewsEvent_GetMinigameResultSlot(WiFiPlazaNewsEvent *event, u32 index);
BOOL WiFiPlaza_IsMinigamePlayerCountValid(u32 activity, u32 count);
void WiFiPlazaLobbyClient_Init(enum HeapID heapID, SaveData *save, u32 count, WiFiPlazaCallbacks *callbacks, void *callbackArg);
void WiFiPlazaLobbyClient_Free(void);
int WiFiPlazaLobbyClient_Update(void);
u32 WiFiPlazaLobbyClient_GetLastError(void);
u32 WiFiPlazaLobbyClient_ToErrorCode(u32 error);
BOOL WiFiPlazaLobbyClient_Initialize(const WiFiPlazaPlayer *player);
BOOL WiFiPlazaLobbyClient_IsInLobby(void);
void WiFiPlazaLobbyClient_Shutdown(void);
BOOL WiFiPlazaLobbyClient_IsDisconnected(void);
int WiFiPlazaLobbyClient_GetState(void);
u8 WiFiPlazaLobbyClient_TakeExcessFlood(void);
int WiFiPlazaLobbyClient_GetOwnId(void);
void WiFiPlazaLobbyClient_SetOwnPlayer(WiFiPlazaPlayer *player);
WiFiPlazaPlayer *WiFiPlazaLobbyClient_GetPlayer(int id);
void WiFiPlazaLobbyClient_GetEntryTime(int id, s64 *time);
int WiFiPlazaLobbyClient_GetOldestPlayer(void);
int WiFiPlazaLobbyClient_GetOldestOtherPlayer(int excluded);
BOOL WiFiPlazaLobbyClient_JoinChannel(int channel);
u8 WiFiPlazaLobbyClient_GetJoinChannelResult(void);
BOOL WiFiPlazaLobbyClient_LeaveChannel(void);
BOOL WiFiPlazaLobbyClient_IsNotInChannel(void);
BOOL WiFiPlazaLobbyClient_CanJoinChannel(int channel);
void WiFiPlazaLobbyClient_GetPlayerList(WiFiPlazaPlayerList *list);
void WiFiPlazaLobbyClient_GetChannelPlayerList(WiFiPlazaPlayerList *list);
int WiFiPlazaLobbyClient_IdToSlot(int id);
int WiFiPlazaLobbyClient_IdToChannelSlot(int id);
int WiFiPlazaLobbyClient_SlotToId(int slot);
int WiFiPlazaLobbyClient_ChannelSlotToId(int slot);
void WiFiPlazaLobbyClient_GetTime(s64 *time);
u32 WiFiPlazaLobbyClient_GetScheduleValue(enum WiFiPlazaScheduleField field);
BOOL WiFiPlazaLobbyClient_StartAddOwnLocation(void);
BOOL WiFiPlazaLobbyClient_IsOwnLocationAdded(void);
u32 WiFiPlazaLobbyClient_GetLocationCountry(u8 slot);
u8 WiFiPlazaLobbyClient_GetLocationRegion(u8 slot);
void WiFiPlazaLobbyClient_SetLobbyCommands(const WiFiPlazaLobbyCommand *commands, u32 count, void *arg);
void WiFiPlazaLobbyClient_SetChannelCommands(const WiFiPlazaLobbyCommand *commands, u32 count, void *arg);
void WiFiPlazaLobbyClient_ClearLobbyCommands(void);
void WiFiPlazaLobbyClient_ClearChannelCommands(void);
void WiFiPlazaLobbyClient_SendToLobby(int type, const void *data, int size);
void WiFiPlazaLobbyClient_SendToPlayer(int type, int id, const void *data, int size);
void WiFiPlazaLobbyClient_SendToChannel(int type, const void *data, int size);
BOOL WiFiPlazaLobbyClient_HostMatch(int index, int maxPlayers);
void WiFiPlazaLobbyClient_StopMatch(void);
void WiFiPlazaLobbyClient_CloseMatch(void);
BOOL WiFiPlazaLobbyClient_IsCurrentMatchClosed(void);
u8 WiFiPlazaLobbyClient_WasMatchCancelled(void);
BOOL WiFiPlazaLobbyClient_IsMatchActive(int index);
BOOL WiFiPlazaLobbyClient_IsMatchOpen(int index);
int WiFiPlazaLobbyClient_GetMatchFreePlaces(int index);
u32 WiFiPlazaLobbyClient_GetMatchPlayerCount(int index);
BOOL WiFiPlazaLobbyClient_JoinMatch(int index);
u32 WiFiPlazaLobbyClient_GetMatchTimer(int index);
int WiFiPlazaLobbyClient_GetMatchHostId(void);
u8 WiFiPlazaLobbyClient_IsMatchHost(void);
BOOL WiFiPlazaLobbyClient_IsSpecialVisitor(int id);
int WiFiPlazaLobbyClient_GetSpecialVisitorCode(int id);
void WiFiPlazaLobbyClient_SubmitSurveyAnswer(int index);
enum WiFiPlazaSurveySubmitState WiFiPlazaLobbyClient_GetSurveySubmitState(void);
u32 WiFiPlazaLobbyClient_GetSurveyValue(int field);
void *WiFiPlazaLobbyClient_GetSurveyText(int field);
u8 WiFiPlazaLobbyClient_GetSurveyFlag(int which, int index);
void WiFiPlazaLobbyClient_EndMatch(void);
BOOL WiFiPlazaLobbyClient_CheckResult(enum PPWLobbyResult result);
int WiFiPlazaLobbyClient_ChannelFromLib(int libChannel);
int WiFiPlazaLobbyClient_ChannelToLib(int channel);

void WiFiPlazaLobbyClient_SetPlayerData(WiFiPlazaLobbyClient *client, int id, const void *data);
void WiFiPlazaLobbyClient_CopyPlayerData(WiFiPlazaLobbyClient *client, int id, const void *data, u32 size);
WiFiPlazaPlayer *WiFiPlazaLobbyClient_GetPlayerData(WiFiPlazaLobbyClient *client, int id);
void WiFiPlazaLobbyClient_ClearPlayerData(WiFiPlazaLobbyClient *client, int id);
void WiFiPlazaLobbyClient_SetPlayerRecord(WiFiPlazaLobbyClient *client, int id, const WiFiPlazaLobbyPlayerRecord *record);
WiFiPlazaLobbyPlayerRecord *WiFiPlazaLobbyClient_GetPlayerRecord(WiFiPlazaLobbyClient *client, int id);
void WiFiPlazaLobbyClient_ClearPlayerRecord(WiFiPlazaLobbyClient *client, int id);
void WiFiPlazaLobbyClient_AddToIdList(WiFiPlazaLobbyClient *client, int id, enum WiFiPlazaLobbyScope scope);
void WiFiPlazaLobbyClient_RemoveFromIdList(WiFiPlazaLobbyClient *client, int id, enum WiFiPlazaLobbyScope scope);
int WiFiPlazaLobbyClient_FindInIdList(WiFiPlazaLobbyClient *client, int id, enum WiFiPlazaLobbyScope scope);
int WiFiPlazaLobbyClient_GetIdListEntry(WiFiPlazaLobbyClient *client, int slot, enum WiFiPlazaLobbyScope scope);
void WiFiPlazaLobbyClient_RebuildChannelList(WiFiPlazaLobbyClient *client, u32 channel);

BOOL WiFiPlazaLobbyClient_HasChannelRoom(WiFiPlazaLobbyClient *client, int channel);
void WiFiPlazaLobbyClient_OnEnterChannel(int result, u32 libChannel);
void WiFiPlazaLobbyClient_OnPlayerEnter(int id, const void *record, const void *data, u32 size);
void WiFiPlazaLobbyClient_OnPlayerLeave(int id);
void WiFiPlazaLobbyClient_OnEvent3Dummy(int id, int libChannel, int type, const void *data);
void WiFiPlazaLobbyClient_OnMessage(int id, u32 libChannel, u32 type, const void *data, u32 size);
void WiFiPlazaLobbyClient_OnLocationsChanged(BOOL success, BOOL broadcast, int channelKind, int userId, const char *key, const void *data, u32 size, u32 param);
void WiFiPlazaLobbyClient_OnPlayerRecordChanged(int id, const void *data);
void WiFiPlazaLobbyClient_OnPlayerUpdate(int id, const void *data, u32 size);
void WiFiPlazaLobbyClient_OnMatchInfo(int id, void *data);
void WiFiPlazaLobbyClient_OnMatchClosed(int id, const void *data);
void WiFiPlazaLobbyClient_OnLobbyEvent(u32 event);
void WiFiPlazaLobbyClient_OnOwnRecord(enum PPWLobbyWebResult result, const void *data, u32 size);
BOOL WiFiPlazaLobbyClient_OnScheduleReceived(enum PPWLobbyWebResult result, const void *schedule);
void WiFiPlazaLobbyClient_OnSpecialVisitorsReceived(enum PPWLobbyWebResult result, const void *data, u32 size);
void WiFiPlazaLobbyClient_OnSurveyReceived(enum PPWLobbyWebResult result, const void *data);
void WiFiPlazaLobbyClient_OnSurveySubmitted(s32 result);
void WiFiPlazaLobbyClient_OnExcessFlood(int id);
void WiFiPlazaLobbyClient_InitMatches(WiFiPlazaLobbyClient *client);

BOOL WiFiPlazaLobbyMatches_Remove(WiFiPlazaLobbyClient *client, int index, int hostId);
BOOL WiFiPlazaLobbyMatches_IsActive(WiFiPlazaLobbyClient *client, int index);
WiFiPlazaLobbyMatch *WiFiPlazaLobbyMatches_Get(WiFiPlazaLobbyClient *client, int index);
void WiFiPlazaLobbyMatches_Update(WiFiPlazaLobbyClient *client);
void WiFiPlazaLobbyMatchInfo_SetStartTime(WiFiPlazaLobbyMatchInfo *info, const s64 *time);
void WiFiPlazaLobbyClient_OnMatchClientDummy(int result, void *arg);

void WiFiPlazaLobbyClient_OnMatchDisconnect(int result, void *arg);
u32 WiFiPlazaLobbySchedule_FindValue(const volatile WiFiPlazaLobbySchedule *schedule, enum WiFiPlazaLobbyEvent event);
void WiFiPlazaLobbyIdValueList_Init(WiFiPlazaLobbyIdValueList *list, int count, enum HeapID heapID);
void WiFiPlazaLobbyIdValueList_Free(WiFiPlazaLobbyIdValueList *list);
BOOL WiFiPlazaLobbyIdValueList_Contains(WiFiPlazaLobbyIdValueList *list, int id);
u32 WiFiPlazaLobbyIdValueList_GetValue(WiFiPlazaLobbyIdValueList *list, int id);
WiFiPlazaPlayerObjects *WiFiPlazaPlayerObjects_New(u32 count, BOOL mode, enum HeapID heapID, enum HeapID loadHeapID);
void WiFiPlazaPlayerObjects_Delete(WiFiPlazaPlayerObjects *objects);
void WiFiPlazaPlayerObjects_Update(WiFiPlazaPlayerObjects *objects);
void WiFiPlazaPlayerObjects_Draw(WiFiPlazaPlayerObjects *objects);
void WiFiPlazaPlayerObjects_ClearPendingFree(WiFiPlazaPlayerObjects *objects);
void WiFiPlazaPlayerObjects_SetModelAlpha(WiFiPlazaPlayerObjects *objects, int alpha);
WiFiPlazaPlayerObject *WiFiPlazaPlayerObjects_Add(WiFiPlazaPlayerObjects *objects, Field2DObject *player);
void WiFiPlazaPlayerObject_Delete(WiFiPlazaPlayerObject *object);
void WiFiPlazaPlayerObject_SetMode(WiFiPlazaPlayerObject *object, u32 mode);
void WiFiPlazaPlayerObject_SetLightFlags(WiFiPlazaPlayerObject *object, u32 lightFlags);
BOOL WiFiPlazaPlayerObject_IsCulled(WiFiPlazaPlayerObject *object);
void WiFiPlazaPlayerObject_SetGridPosition(WiFiPlazaPlayerObject *object, const Field2DPoint *gridPos);
void WiFiPlazaPlayerObject_SetPosition(WiFiPlazaPlayerObject *object, const VecFx32 *position);
void WiFiPlazaPlayerObject_GetPosition(WiFiPlazaPlayerObject *object, VecFx32 *position);
void WiFiPlazaPlayerObject_SetStandingSequence(WiFiPlazaPlayerObject *object, u32 sequence);
void WiFiPlazaPlayerObject_StartEffect(WiFiPlazaPlayerObject *object, u32 effect);
void WiFiPlazaPlayerObject_StopEffect(WiFiPlazaPlayerObject *object);
void WiFiPlazaPlayerObject_SetEffectStep(WiFiPlazaPlayerObject *object, u8 step);
void WiFiPlazaPlayerObject_SetVisible(WiFiPlazaPlayerObject *object, BOOL visible);
BOOL WiFiPlazaPlayerObject_IsVisible(WiFiPlazaPlayerObject *object);
void WiFiPlazaPlayerObject_ShowStandingSprite(WiFiPlazaPlayerObject *object);
void WiFiPlazaPlayerObject_PlayStandingSequence(WiFiPlazaPlayerObject *object);
void WiFiPlazaPlayerObject_HoldWalkFrameThenRestart(WiFiPlazaPlayerObject *object);
void WiFiPlazaPlayerObject_PlayWalkingSequence(WiFiPlazaPlayerObject *object);

BOOL WiFiPlaza_IsBillboardInView(BillboardObject *billboard);

WiFiPlazaTime WiFiPlaza_GetLocalTime(int country, u16 region, u32 time, enum HeapID heapID);
void WiFiPlaza_GetLongitude(NARC *narc, enum HeapID heapID, int country, u16 region, s32 *longitude);

extern const WiFiPlazaAvatarEntry gWiFiPlazaAvatars[16];
extern u16 (*const gWiFiPlazaNewsEventSlotGetters[9])(WiFiPlazaNewsEvent *event, u32 index); // lobby slot of a news event per type
extern const char *gWiFiPlazaLocationListKey;                                                 // lobby data key of the location list
extern void (*const gWiFiPlazaPlayerObjectActions[])(WiFiPlazaPlayerObject *object);       // per player action

// lobby library (the rest of its interface is in ppw_lobby_work.h)
enum PPWLobbyResult PPW_LobbyStartRecruit(WiFiPlazaLobbyMatch *match);
enum PPWLobbyResult PPW_LobbyUpdateRecruitInfo(WiFiPlazaLobbyMatch *match);
enum PPWLobbyResult PPW_LobbyStopRecruit(void);

BOOL WiFiPlazaRoom_Init(OverlayManager *manager, int *state);
BOOL WiFiPlazaRoom_Main(OverlayManager *manager, int *state);
BOOL WiFiPlazaRoom_Exit(OverlayManager *manager, int *state);
BOOL WiFiPlazaSurvey_Init(OverlayManager *man, int *state);
BOOL WiFiPlazaSurvey_Main(OverlayManager *man, int *state);
BOOL WiFiPlazaSurvey_Exit(OverlayManager *man, int *state);
void WiFiPlazaMap_PosToVecFx32(const s16 *gridPos, s32 *position);
void WiFiPlazaMap_LoadModelFile(NNSG3dResFileHeader **file, NARC *narc, int fileId, enum HeapID heapID);
// billboards
u32 NNS_G3dMdlGetMdlLightEnableFlag(const NNSG3dResMdl *pResMdl, u32 matID);
void NNS_G3dMdlSetMdlLightEnableFlagAll(NNSG3dResMdl *pResMdl, u32 light);
void NNS_G3dMdlSetMdlPolygonIDAll(NNSG3dResMdl *pResMdl, u32 polygonID);
void NNS_G3dMdlSetMdlAlphaAll(NNSG3dResMdl *pResMdl, u32 alpha);
WiFiPlazaPlayerInfo *WiFiPlazaPlayerInfo_New(PlayerProfile *profile, enum HeapID heapID);
void WiFiPlazaPlayerInfo_Free(WiFiPlazaPlayerInfo *info);

#endif // POKEHEARTGOLD_WIFI_PLAZA_INTERNAL_H
