#ifndef POKEHEARTGOLD_FIELD_LAUNCH_APPLICATION_INTERNAL_H
#define POKEHEARTGOLD_FIELD_LAUNCH_APPLICATION_INTERNAL_H

#include "launch_application.h"
#include "naming_screen.h"
#include "friend_roster.h"

typedef enum PartyMenuMoveSelectState {
    PMMS_OPEN_PARTY_MENU,
    PMMS_WAIT_PARTY_MENU,
    PMMS_OPEN_SUMMARY,
    PMMS_WAIT_SUMMARY,
    PMMS_FREE,
} PartyMenuMoveSelectState;

typedef enum EasyChatTaskState {
    EASY_CHAT_TASK_STATE_LAUNCH,
    EASY_CHAT_TASK_STATE_WAIT,
    EASY_CHAT_TASK_STATE_FINISH,
} EasyChatTaskState;

typedef enum DressUpTaskState {
    DRESS_UP_TASK_STATE_LAUNCH,
    DRESS_UP_TASK_STATE_WAIT,
} DressUpTaskState;

typedef enum WirelessTradeState {
    WIRELESS_TRADE_STATE_0,
    WIRELESS_TRADE_STATE_1,
    WIRELESS_TRADE_STATE_2,
    WIRELESS_TRADE_STATE_3,
    WIRELESS_TRADE_STATE_4,
    WIRELESS_TRADE_STATE_5,
    WIRELESS_TRADE_STATE_6,
    WIRELESS_TRADE_STATE_7,
} WirelessTradeState;

typedef struct PartyMenuUnionRoomBattleSelectData {
    enum HeapID heapID;
    PartyMenuArgs *partyMenu;
    u8 unk8[0x4];
} PartyMenuUnionRoomBattleSelectData;

typedef struct EasyChatTaskData {
    EasyChatResult *result;
    u16 *retVar0;
    u16 *retVar1;
    EasyChatArgs *easyChat;
    int mode;
} EasyChatTaskData;

typedef struct DressUpArgs {
    Pokemon *mon;
    SaveFashionDataSub *fashionEntry;
    FashionCase *fashionCase;
    Options *options;
    GameStats *gameStats;
    PlayerProfile *profile;
    int *savedResult;
    int showTutorial;
    MenuInputStateMgr *menuInputStatePtr;
} DressUpArgs;

typedef struct DressUpTaskData {
    int state;
    u16 *retVar;
    int saved;
    DressUpArgs *args;
} DressUpTaskData;

typedef struct WirelessTradeSelectMonArgs {
    FieldSystem *fieldSystem;
    PlayerProfile *profile;
    Party *party;
    SavePalPad *palPad;
    SaveData *saveData;
    SaveWiFiHistory *wifiHistory;
    Options *options;
    GameStats *gameStats;
    Pokedex *pokedex;
    int tradeAccepted;
    int tradedSlot;
    BOOL natDexEnabled;
    int tradeCount;
    PlayerProfile *partnerProfile;
    Pokemon *sentMon;
    Pokemon *receivedMon;
} WirelessTradeSelectMonArgs;

typedef enum TradeSequenceBackground {
    TS_BG_DAY,
    TS_BG_EVENING,
    TS_BG_NIGHT,
    TS_BG_UNK_3,
} TradeSequenceBackground;

typedef struct TradeSequenceArgs {
    BoxPokemon *sentMon;
    BoxPokemon *receivedMon;
    PlayerProfile *partnerProfile;
    TradeSequenceBackground bgType;
    int tradeMode;
    Options *options;
    EvolutionTaskData *evolutionTaskData;
    u8 unk1C[0x4];
} TradeSequenceArgs;

typedef struct WirelessTradeData {
    int state;
    WirelessTradeSelectMonArgs wirelessTradeSelectMon;
    TradeSequenceArgs tradeSequence;
} WirelessTradeData;

typedef struct DrawingSessionArgs {
    struct UnionRoomObjects *unionRoomObjects;
    Options *options;
} DrawingSessionArgs;

typedef struct NamingScreenData {
    int state;
    int partyIdx;
    u16 *retVar;
    NamingScreenArgs *args;
    String *defaultName;
} NamingScreenData;

typedef struct GtsArgs {
    struct GtsSave *gtsSave;
    SysInfo *sysInfo;
    Party *party;
    PCStorage *pcStorage;
    Pokedex *pokedex;
    FriendRoster *friendRoster;
    SaveWiFiHistory *wifiHistory;
    PlayerProfile *profile;
    SaveData *saveData;
    Options *options;
    GameStats *gameStats;
    Bag *bag;
    BOOL natDexEnabled;
    void *gsProfileId;
    u32 unk38;
    int connectDirectly;
} GtsArgs;

typedef struct PartyMenuArgsSlotView {
    u8 unk0[0x26];
    u8 partySlot;
} PartyMenuArgsSlotView;

typedef struct PartyMenuMoveSelectData {
    enum HeapID heapID;
    PartyMenuArgsSlotView *partyMenu;
    PokemonSummaryArgs *pokemonSummary;
} PartyMenuMoveSelectData;

#endif // POKEHEARTGOLD_FIELD_LAUNCH_APPLICATION_INTERNAL_H
