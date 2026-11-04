#ifndef POKEHEARTGOLD_FRONTIER_LINK_LOBBY_H
#define POKEHEARTGOLD_FRONTIER_LINK_LOBBY_H

#include "field_types_def.h"
#include "frontier_save_access.h"
#include "save.h"

struct PartyMenuArgs;
struct PokemonSummaryArgs;

#define LINK_LOBBY_PARTY_SIZE 4

// What the linked players exchange in the frontier lobby before a link challenge: the facility, the streak and the chosen party.
typedef struct FrontierLinkLobby {
    SaveData *saveData;
    u8 padding_04[4];
    u16 sendBuffer[20]; // link message being sent
    u8 padding_30[0x28];
    u8 partnerGender; // copied to the tower's linkAllyGender by FrtCmd_LinkLobbyStartTower
    u8 partnerChoice;
    u8 padding_5A[0x10];
    u8 partySlots[LINK_LOBBY_PARTY_SIZE];
    u8 partnerFacility;
    u8 receiveCount; // link messages received (both players count)
    u8 padding_70;
    u8 partnerValue71;
    u16 partnerStreak;
    u16 partnerValue74;
    u16 species[LINK_LOBBY_PARTY_SIZE]; // of the chosen party
    u16 items[LINK_LOBBY_PARTY_SIZE];
    u16 partnerSpecies[LINK_LOBBY_PARTY_SIZE];
    u16 partnerItems[LINK_LOBBY_PARTY_SIZE];
    u8 padding_96[2];
    FieldSystem *fieldSystem;
    u8 padding_9C;
    u8 appResult;
    u8 padding_9E;
    u8 partySlot; // cursor of the party menu / summary
    u8 facility;
    u8 selectedOrder[2];
    u8 padding_A3[5];
    struct PartyMenuArgs *partyMenuArgs;
    struct PokemonSummaryArgs *summaryArgs;
    u16 *resultVar; // script variable that receives the app result
} FrontierLinkLobby;

// FrontierLinkLobby_Send
#define LINK_LOBBY_SEND_FACILITY 0
#define LINK_LOBBY_SEND_CHOICE   1
#define LINK_LOBBY_SEND_PARTY    2
#define LINK_LOBBY_SEND_VALUE74  4
#define LINK_LOBBY_SEND_VALUE71  5

// FrontierLinkLobby_RunPartyApp
#define LINK_LOBBY_APP_LAUNCH_PARTY_MENU   0
#define LINK_LOBBY_APP_READ_PARTY_MENU     1
#define LINK_LOBBY_APP_LAUNCH_SUMMARY      2
#define LINK_LOBBY_APP_READ_SUMMARY        3

void FrontierLinkLobby_Free(FrontierLinkLobby *lobby);
BOOL FrontierLinkLobby_Send(FrontierLinkLobby *lobby, int kind, u16 value, u16 secondValue);
void FrontierLinkLobby_RunPartyApp(void *frontierWork, FrontierLinkLobby *lobby, u32 kind);

// The summary pages shown for the chosen party
extern const u8 gFrontierLinkLobbySummaryPages[];

extern const u8 gBattleHallCellTypes[20];
FrontierLinkLobby *FrontierLinkLobby_New(SaveData *);

#endif // POKEHEARTGOLD_FRONTIER_LINK_LOBBY_H
