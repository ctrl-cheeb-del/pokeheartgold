#include "global.h"

#include "constants/comm_type.h"

#include "field/fieldmap.h"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0014.h"

#include "bag.h"
#include "colosseum_internal.h"
#include "comm_state.h"
#include "comm_state_internal.h"
#include "communication_core.h"
#include "communication_player_state.h"
#include "dialog_box.h"
#include "heap.h"
#include "launch_application.h"
#include "link_synchronization.h"
#include "link_synchronization_internal.h"
#include "map_object.h"
#include "map_object_movement_commands.h"
#include "player_avatar.h"
#include "pokedex_util.h"
#include "pokemon.h"
#include "render_window.h"
#include "save_link_ruleset.h"
#include "save_special_ribbons.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "system.h"
#include "text.h"
#include "union_room_internal.h"

enum ColosseumTrainerCardState {
    COLOSSEUM_CARD_STATE_PRINT,
    COLOSSEUM_CARD_STATE_WAIT_INPUT,
    COLOSSEUM_CARD_STATE_WAIT_FADE_OUT,
    COLOSSEUM_CARD_STATE_LAUNCH,
    COLOSSEUM_CARD_STATE_WAIT_APP,
    COLOSSEUM_CARD_STATE_LOAD_FIELD,
    COLOSSEUM_CARD_STATE_WAIT_FIELD,
    COLOSSEUM_CARD_STATE_FINISH,
};

void CommPlayerManager_ResyncLocalPlayer(void);
void CommPlayerManager_FaceRoomCenter(void);
void CommPlayerManager_ResumeField(void);
int CommPlayerManager_GetPlayerX(int netId);
int CommPlayerManager_GetPlayerZ(int netId);
int CommPlayerManager_GetPlayerFrontX(void);
int CommPlayerManager_GetPlayerFrontZ(int netId);
u8 *CommClubLink_GetCard(int netId, int a1, int a2);

#define ListMenuUpdateCursorObj_Int ((void (*)(struct ListMenuCursor *, Window *, int, int))ListMenuUpdateCursorObj)

static void Colosseum_OpenSummary(ColosseumEntry *entry, FieldSystem *fieldSystem, Party *party, int partySlot, int mode, enum HeapID heapId);
static void Colosseum_OpenPartyMenu(ColosseumEntry *entry, enum HeapID heapId);
static BOOL Colosseum_FinishSummary(ColosseumEntry *entry, FieldSystem *fieldSystem);
static BOOL Colosseum_WaitFieldResumed(ColosseumEntry *entry);
static BOOL Colosseum_AnyPlayerCancelled(void);
static BOOL Task_ColosseumEntry(TaskManager *taskManager);
static u8 Colosseum_PrintMessage(ColosseumEntry *entry, String *message);
static void Colosseum_RemoveWindows(ColosseumEntry *entry, BOOL clearFrame);
static void Colosseum_FreeEntry(ColosseumEntry *entry);
static ColosseumEntry *Colosseum_GetEntry(FieldSystem *fieldSystem);
static void Colosseum_PackMixBattleMons(ColosseumEntry *entry, BOOL ready);
static BOOL Colosseum_SendMixBattleMons(ColosseumEntry *entry);
static BOOL Colosseum_MixBattleMonsExchanged(ColosseumEntry *entry);
static BOOL Colosseum_OpponentIsReady(ColosseumEntry *entry);
static BOOL Colosseum_SendMixBattleChoice(ColosseumEntry *entry);
static BOOL Colosseum_MixBattleChoicesExchanged(ColosseumEntry *entry);
static void Colosseum_SetOpponentParty(ColosseumEntry *entry);
static void Colosseum_ExchangeMixBattleMons(ColosseumEntry *entry);
static void Colosseum_ShowOpponentMons(ColosseumEntry *entry, int cursor);
static void Colosseum_ShowChoiceMenu(ColosseumEntry *entry, int cursor);
static void Colosseum_CloseMenu(ColosseumEntry *entry);

// Summary pages shown for a Pokemon of the party being entered.
ALIGN(4)
static const u8 sColosseumSummaryPages[8] = { 0, 1, 2, 3, 4, 0, 0, 0 };

// Union Room state.
ALIGN(4)
UnionRoomScratch gUnionRoomScratch = { 0 };
ALIGN(4)
void *gUnionRoomRecords[UNION_ROOM_MAX_RECORDS] = { 0 };

static void Colosseum_OpenSummary(ColosseumEntry *entry, FieldSystem *fieldSystem, Party *party, int partySlot, int mode, enum HeapID heapId) {
    SaveData *saveData = fieldSystem->saveData;
    PokemonSummaryArgs *args = Heap_AllocAtEnd(heapId, sizeof(PokemonSummaryArgs));
    MI_CpuFill8(args, 0, sizeof(PokemonSummaryArgs));
    PokemonSummaryArgs_SetPlayer(args, Save_PlayerData_GetProfile(fieldSystem->saveData));
    args->natDexEnabled = SaveArray_IsNatDexEnabled(saveData);
    args->unk2C = PokemonSummary_GetDefaultUnk2C(saveData);
    args->options = Save_PlayerData_GetOptionsAddr(saveData);
    args->party = party;
    args->monDataType = 1;
    args->partySlot = partySlot;
    args->partyCount = Party_GetCount(args->party);
    args->moveToLearn = 0;
    args->mode = mode;
    args->ribbons = Save_SpecialRibbons_Get(saveData);
    args->menuInputStatePtr = NULL;
    args->isFlag982Set = PokemonSummary_IsPokeathlonUnlocked(saveData);
    PokemonSummary_SetPages(args, sColosseumSummaryPages);
    FieldSystem_LaunchApplication(fieldSystem, &gOverlayTemplate_PokemonSummary, args);
    entry->summaryArgs = args;
}

static void Colosseum_OpenPartyMenu(ColosseumEntry *entry, enum HeapID heapId) {
    PartyMenuArgs *args = Heap_Alloc(heapId, sizeof(PartyMenuArgs));
    int i;
    MI_CpuFill8(args, 0, sizeof(PartyMenuArgs));
    args->options = Save_PlayerData_GetOptionsAddr(entry->fieldSystem->saveData);
    args->linkBattleRuleset = entry->fieldSystem->linkBattleRuleset;
    args->party = SaveArray_Party_Get(entry->fieldSystem->saveData);
    args->bag = Save_Bag_Get(entry->fieldSystem->saveData);
    args->menuInputStatePtr = &entry->fieldSystem->menuInputState;
    args->panelLayout = 0;
    args->context = PARTY_MENU_CONTEXT_UNION_ROOM_BATTLE_SELECT;
    if (entry->fieldSystem->linkBattleRuleset != NULL) {
        args->minMonsToSelect = LinkBattleRuleset_GetRuleValue(entry->fieldSystem->linkBattleRuleset, LINKBATTLERULE_PARTY_COUNT);
        args->maxMonsToSelect = args->minMonsToSelect;
    } else {
        args->minMonsToSelect = 3;
        args->maxMonsToSelect = 3;
    }
    args->maxLevel = MAX_LEVEL;
    args->partySlot = entry->partySlot;
    for (i = 0; i < PARTY_SIZE; i++) {
        args->selectedOrder[i] = entry->selectedOrder[i];
    }
    FieldSystem_LaunchApplication(entry->fieldSystem, &gOverlayTemplate_PartyMenu, args);
    entry->partyMenuArgs = args;
}

BOOL Colosseum_FinishPartyMenu(ColosseumEntry *entry, FieldSystem *fieldSystem) {
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return FALSE;
    }
    MI_CpuCopy8(entry->partyMenuArgs->selectedOrder, entry->selectedOrder, PARTY_SIZE);
    switch (entry->partyMenuArgs->partySlot) {
    case 7:
        entry->partyMenuResult = COLOSSEUM_PARTY_MENU_CANCEL;
        break;
    case 6:
        entry->partyMenuResult = COLOSSEUM_PARTY_MENU_CONFIRM;
        break;
    default:
        entry->partyMenuResult = COLOSSEUM_PARTY_MENU_SUMMARY;
        break;
    }
    entry->partySlot = entry->partyMenuArgs->partySlot;
    Heap_Free(entry->partyMenuArgs);
    entry->partyMenuArgs = NULL;
    return TRUE;
}

static BOOL Colosseum_FinishSummary(ColosseumEntry *entry, FieldSystem *fieldSystem) {
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return FALSE;
    }
    entry->partySlot = entry->summaryArgs->partySlot;
    Heap_Free(entry->summaryArgs);
    entry->summaryArgs = NULL;
    return TRUE;
}

static BOOL Colosseum_WaitFieldResumed(ColosseumEntry *entry) {
    if (FieldSystem_IsOverworldRestored(entry->fieldSystem)) {
        FieldMap_FadeScreen(FADE_TYPE_BRIGHTNESS_IN);
        CommPlayerManager_ResyncLocalPlayer();
        return TRUE;
    }
    return FALSE;
}

static BOOL Colosseum_AnyPlayerCancelled(void) {
    int i;
    int count = Comm_CountConnected();
    i = 0;
    for (i = 0; i < count; i++) {
        if (LinkSync_GetPlayerState(i) == 94) {
            return TRUE;
        }
    }
    return FALSE;
}

static BOOL Task_ColosseumEntry(TaskManager *taskManager) {
    ColosseumEntry *entry = TaskManager_GetEnvironment(taskManager);
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);

    switch (entry->state) {
    case COLOSSEUM_ENTRY_STATE_FACE_CENTER:
        entry->timer--;

        if (entry->timer == 0) {
            entry->state = COLOSSEUM_ENTRY_STATE_PRINT_WAIT;
            CommPlayerManager_FaceRoomCenter();
        }
        break;
    case COLOSSEUM_ENTRY_STATE_PRINT_WAIT:
        ReadMsgDataIntoString(entry->msgData, msg_0014_00001, entry->message);
        entry->printerId = Colosseum_PrintMessage(entry, entry->message);
        entry->state = COLOSSEUM_ENTRY_STATE_START_SYNC;
        break;
    case COLOSSEUM_ENTRY_STATE_START_SYNC:
        if (DialogBox_IsPrintFinished(entry->printerId)) {
            LinkSync_StartSync(93);
            entry->state = COLOSSEUM_ENTRY_STATE_WAIT_SYNC;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_WAIT_SYNC:
        if (LinkSync_IsSynced(93)) {
            entry->state = COLOSSEUM_ENTRY_STATE_EXIT_TO_BATTLE;
            MapObjectManager_SuspendMovement(entry->fieldSystem->mapObjectManager);
            entry->callback(TRUE, entry->party);
        } else if (gSystem.newKeys & PAD_BUTTON_B) {
            entry->state = COLOSSEUM_ENTRY_STATE_CANCEL;
            LinkSync_StartSync(92);
            entry->timer = 5;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_CANCEL:
        if (LinkSync_IsSynced(93)) {
            entry->state = COLOSSEUM_ENTRY_STATE_EXIT_TO_BATTLE;
            MapObjectManager_SuspendMovement(entry->fieldSystem->mapObjectManager);
            entry->callback(TRUE, entry->party);
        }

        entry->timer--;

        if (entry->timer == 0) {
            entry->state = COLOSSEUM_ENTRY_STATE_REPORT_RESULT;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_EXIT_TO_BATTLE:
        Colosseum_FreeEntry(entry);
        Heap_Free(entry);
        return TRUE;
    case COLOSSEUM_ENTRY_STATE_EXIT:
        Colosseum_FreeEntry(entry);
        Heap_Free(entry);
        CommPlayerManager_ResumeField();
        return TRUE;
    case COLOSSEUM_ENTRY_STATE_REPORT_RESULT:
        if (LinkSync_IsSynced(93)) {
            entry->state = COLOSSEUM_ENTRY_STATE_EXIT;
            entry->callback(TRUE, entry->party);
        } else {
            entry->callback(FALSE, entry->party);
            entry->state = COLOSSEUM_ENTRY_STATE_EXIT;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_START_CHOOSE:
        entry->state = COLOSSEUM_ENTRY_STATE_WAIT_PLAYER_STOP;
        entry->delay = 5;
        break;
    case COLOSSEUM_ENTRY_STATE_WAIT_PLAYER_STOP:
        if (entry->delay != 0) {
            entry->delay--;
        } else {
            if (MapObject_IsMovementPaused(PlayerAvatar_GetMapObject(fieldSystem->playerAvatar))) {
                entry->state = COLOSSEUM_ENTRY_STATE_PRINT_CHOOSE;
            }
        }
        break;
    case COLOSSEUM_ENTRY_STATE_PRINT_CHOOSE:
        CommPlayerManager_FaceRoomCenter();
        ReadMsgDataIntoString(entry->msgData, msg_0014_00013, entry->message);

        entry->printerId = Colosseum_PrintMessage(entry, entry->message);
        entry->state = COLOSSEUM_ENTRY_STATE_WAIT_PRINT_CHOOSE;
        break;
    case COLOSSEUM_ENTRY_STATE_WAIT_PRINT_CHOOSE:
        if (DialogBox_IsPrintFinished(entry->printerId)) {
            entry->state = COLOSSEUM_ENTRY_STATE_FADE_OUT;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_FADE_OUT:
        FieldMap_FadeScreen(FADE_TYPE_BRIGHTNESS_OUT);
        entry->state = COLOSSEUM_ENTRY_STATE_WAIT_FADE_OUT;
        break;
    case COLOSSEUM_ENTRY_STATE_WAIT_FADE_OUT:
        entry->timer--;

        if (entry->timer == 0) {
            CommPlayerManager_FaceRoomCenter();
            entry->state = COLOSSEUM_ENTRY_STATE_OPEN_PARTY_MENU;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_OPEN_PARTY_MENU:
        Colosseum_RemoveWindows(entry, FALSE);
        Colosseum_OpenPartyMenu(entry, HEAP_ID_FIELD2);
        entry->state = COLOSSEUM_ENTRY_STATE_PARTY_MENU;
        break;
    case COLOSSEUM_ENTRY_STATE_PARTY_MENU:
        if (Colosseum_FinishPartyMenu(entry, entry->fieldSystem)) {
            switch (entry->partyMenuResult) {
            case COLOSSEUM_PARTY_MENU_CANCEL:
                entry->state = COLOSSEUM_ENTRY_STATE_PARTY_CANCELLED;
                break;
            case COLOSSEUM_PARTY_MENU_CONFIRM:
                entry->state = COLOSSEUM_ENTRY_STATE_PARTY_CONFIRMED;
                break;
            case COLOSSEUM_PARTY_MENU_SUMMARY:
                entry->state = COLOSSEUM_ENTRY_STATE_OPEN_SUMMARY;
                break;
            }
        }
        break;
    case COLOSSEUM_ENTRY_STATE_OPEN_SUMMARY:
        Colosseum_OpenSummary(entry, entry->fieldSystem, SaveArray_Party_Get(entry->fieldSystem->saveData), entry->partySlot, 0, HEAP_ID_FIELD2);
        entry->state = COLOSSEUM_ENTRY_STATE_SUMMARY;
        break;
    case COLOSSEUM_ENTRY_STATE_SUMMARY:
        if (Colosseum_FinishSummary(entry, entry->fieldSystem)) {
            entry->state = COLOSSEUM_ENTRY_STATE_OPEN_PARTY_MENU;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_PARTY_CONFIRMED:
        FieldSystem_LoadFieldOverlay(entry->fieldSystem);

        if (entry->linkMode != COMM_TYPE_MIX_BATTLE) {
            entry->timer = 5;
            entry->state = COLOSSEUM_ENTRY_STATE_RETURN_TO_FIELD;
        } else {
            entry->state = COLOSSEUM_ENTRY_STATE_MIX_START_SYNC;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_RETURN_TO_FIELD:
        CommState_SetSelectedOrder(entry->selectedOrder);

        if (Colosseum_WaitFieldResumed(entry)) {
            entry->timer = 5;
            entry->state = COLOSSEUM_ENTRY_STATE_FACE_CENTER;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_PARTY_CANCELLED:
        FieldSystem_LoadFieldOverlay(entry->fieldSystem);

        if (entry->linkMode != COMM_TYPE_MIX_BATTLE) {
            entry->state = COLOSSEUM_ENTRY_STATE_RETURN_CANCELLED;
        } else {
            entry->state = COLOSSEUM_ENTRY_STATE_MIX_START_SYNC;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_RETURN_CANCELLED:
        if (Colosseum_WaitFieldResumed(entry)) {
            entry->state = COLOSSEUM_ENTRY_STATE_REPORT_RESULT;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_DELAY:
        entry->delay--;

        if (entry->delay == 0) {
            entry->state = COLOSSEUM_ENTRY_STATE_MIX_PRINT_CHOOSE;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_PRINT_CHOOSE:
        CommPlayerManager_FaceRoomCenter();
        ReadMsgDataIntoString(entry->msgData, msg_0014_00019, entry->message);
        entry->printerId = Colosseum_PrintMessage(entry, entry->message);
        entry->state = COLOSSEUM_ENTRY_STATE_MIX_WAIT_PRINT_CHOOSE;
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_WAIT_PRINT_CHOOSE:
        if (DialogBox_IsPrintFinished(entry->printerId)) {
            entry->state = COLOSSEUM_ENTRY_STATE_FADE_OUT;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_START_SYNC:
        if (Colosseum_WaitFieldResumed(entry)) {
            if (Colosseum_AnyPlayerCancelled()) {
                entry->state = COLOSSEUM_ENTRY_STATE_EXIT;
            } else {
                entry->ready = (entry->partyMenuResult != COLOSSEUM_PARTY_MENU_CANCEL);
                Colosseum_PackMixBattleMons(entry, entry->ready);
                LinkSync_StartSync(0);
                BufferPlayersName(entry->msgFormat, 0, entry->opponentProfile);
                ReadMsgDataIntoString(entry->msgData, msg_0014_00014, entry->message);
                StringExpandPlaceholders(entry->msgFormat, entry->expandedMessage, entry->message);
                entry->printerId = Colosseum_PrintMessage(entry, entry->expandedMessage);
                entry->state = COLOSSEUM_ENTRY_STATE_MIX_SEND_MONS;
            }
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_SEND_MONS:
        if (DialogBox_IsPrintFinished(entry->printerId)) {
            if (Colosseum_AnyPlayerCancelled()) {
                entry->state = COLOSSEUM_ENTRY_STATE_EXIT;
            } else if (LinkSync_IsSynced(0)) {
                Colosseum_SendMixBattleMons(entry);
                entry->state = COLOSSEUM_ENTRY_STATE_MIX_WAIT_MONS;
            }
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_WAIT_MONS:
        if (Colosseum_MixBattleMonsExchanged(entry)) {
            LinkSync_StartSync(1);
            entry->state = COLOSSEUM_ENTRY_STATE_MIX_CHECK_READY;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_CHECK_READY:
        if (LinkSync_IsSynced(1)) {
            entry->opponentReady = Colosseum_OpponentIsReady(entry);

            if (entry->ready && entry->opponentReady) {
                ReadMsgDataIntoString(entry->msgData, msg_0014_00020, entry->message);
                entry->printerId = Colosseum_PrintMessage(entry, entry->message);
                entry->state = COLOSSEUM_ENTRY_STATE_MIX_PRINT_SELECT;
            } else {
                entry->state = COLOSSEUM_ENTRY_STATE_PRINT_CANCELLED;
            }
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_PRINT_SELECT:
        if (DialogBox_IsPrintFinished(entry->printerId)) {
            entry->exchangeFlags = 0;
            ReadMsgDataIntoString(entry->msgData, msg_0014_00017, entry->message);
            entry->printerId = Colosseum_PrintMessage(entry, entry->message);
            entry->choice = 0;
            entry->state = COLOSSEUM_ENTRY_STATE_MIX_SHOW_MONS;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_SHOW_MONS:
        if (DialogBox_IsPrintFinished(entry->printerId)) {
            Colosseum_SetOpponentParty(entry);
            Colosseum_ShowOpponentMons(entry, entry->choice);
            entry->state = COLOSSEUM_ENTRY_STATE_MIX_SELECT_MON;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_SELECT_MON:
        switch (Colosseum_HandleMenuInput(entry)) {
        case COLOSSEUM_MENU_SELECT:
            Colosseum_CloseMenu(entry);
            entry->choice = entry->menuCursor;
            entry->state = COLOSSEUM_ENTRY_STATE_MIX_PRINT_CONFIRM;
            break;
        case COLOSSEUM_MENU_CANCEL:
            Colosseum_CloseMenu(entry);
            entry->choice = COLOSSEUM_NO_CHOICE;
            ReadMsgDataIntoString(entry->msgData, msg_0014_00015, entry->message);
            entry->printerId = Colosseum_PrintMessage(entry, entry->message);
            LinkSync_StartSync(2);
            entry->state = COLOSSEUM_ENTRY_STATE_MIX_SEND_CHOICE;
            break;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_PRINT_CONFIRM:
        BufferBoxMonSpeciesName(entry->msgFormat, 1, Mon_GetBoxMon(Party_GetMonByIndex(entry->party, entry->choice)));
        ReadMsgDataIntoString(entry->msgData, msg_0014_00018, entry->message);
        StringExpandPlaceholders(entry->msgFormat, entry->expandedMessage, entry->message);
        entry->printerId = Colosseum_PrintMessage(entry, entry->expandedMessage);
        entry->state = COLOSSEUM_ENTRY_STATE_MIX_SHOW_CHOICES;
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_SHOW_CHOICES:
        if (DialogBox_IsPrintFinished(entry->printerId)) {
            Colosseum_ShowChoiceMenu(entry, 0);
            entry->state = COLOSSEUM_ENTRY_STATE_MIX_CONFIRM;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_CONFIRM:
        switch (Colosseum_HandleMenuInput(entry)) {
        case COLOSSEUM_MENU_CANCEL:
            Colosseum_CloseMenu(entry);
            ReadMsgDataIntoString(entry->msgData, msg_0014_00017, entry->message);
            entry->printerId = Colosseum_PrintMessage(entry, entry->message);
            entry->state = COLOSSEUM_ENTRY_STATE_MIX_SHOW_MONS;
            break;
        case COLOSSEUM_MENU_SELECT:
            if (entry->menuCursor == 1) {
                Colosseum_CloseMenu(entry);
                ReadMsgDataIntoString(entry->msgData, msg_0014_00014, entry->message);
                StringExpandPlaceholders(entry->msgFormat, entry->expandedMessage, entry->message);
                entry->printerId = Colosseum_PrintMessage(entry, entry->expandedMessage);
                LinkSync_StartSync(2);
                entry->state = COLOSSEUM_ENTRY_STATE_MIX_SEND_CHOICE;
            } else {
                FieldMap_FadeScreen(FADE_TYPE_BRIGHTNESS_OUT);
                entry->state = COLOSSEUM_ENTRY_STATE_MIX_OPEN_SUMMARY;
            }
            break;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_OPEN_SUMMARY:
        if (IsPaletteFadeFinished()) {
            Colosseum_RemoveWindows(entry, FALSE);
            Colosseum_OpenSummary(entry, entry->fieldSystem, entry->party, entry->choice, 1, HEAP_ID_FIELD2);
            entry->state = COLOSSEUM_ENTRY_STATE_MIX_SUMMARY;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_SUMMARY:
        if (Colosseum_FinishSummary(entry, entry->fieldSystem)) {
            FieldSystem_LoadFieldOverlay(entry->fieldSystem);
            entry->state = COLOSSEUM_ENTRY_STATE_MIX_RETURN_TO_FIELD;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_RETURN_TO_FIELD:
        if (Colosseum_WaitFieldResumed(entry)) {
            entry->state = COLOSSEUM_ENTRY_STATE_MIX_PRINT_CONFIRM;
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_SEND_CHOICE:
        if (DialogBox_IsPrintFinished(entry->printerId)) {
            if (LinkSync_IsSynced(2)) {
                Colosseum_SendMixBattleChoice(entry);
                entry->state = COLOSSEUM_ENTRY_STATE_MIX_WAIT_CHOICES;
            }
        }
        break;
    case COLOSSEUM_ENTRY_STATE_MIX_WAIT_CHOICES:
        if (Colosseum_MixBattleChoicesExchanged(entry)) {
            if (entry->choice == COLOSSEUM_NO_CHOICE) {
                LinkSync_StartSync(4);
                entry->state = COLOSSEUM_ENTRY_STATE_WAIT_END_SYNC;
            } else if (entry->opponentChoice == COLOSSEUM_NO_CHOICE) {
                entry->state = COLOSSEUM_ENTRY_STATE_PRINT_CANCELLED;
            } else {
                Colosseum_ExchangeMixBattleMons(entry);
                LinkSync_StartSync(93);
                entry->state = COLOSSEUM_ENTRY_STATE_START_SYNC;
            }
        }
        break;
    case COLOSSEUM_ENTRY_STATE_PRINT_CANCELLED:
        ReadMsgDataIntoString(entry->msgData, msg_0014_00015, entry->message);
        entry->printerId = Colosseum_PrintMessage(entry, entry->message);
        entry->timer = 0;
        entry->state = COLOSSEUM_ENTRY_STATE_WAIT_PRINT_CANCELLED;
        break;
    case COLOSSEUM_ENTRY_STATE_WAIT_PRINT_CANCELLED:
        if (DialogBox_IsPrintFinished(entry->printerId)) {
            if (++entry->timer > 60) {
                LinkSync_StartSync(4);
                entry->state = COLOSSEUM_ENTRY_STATE_WAIT_END_SYNC;
            }
        }
        break;
    case COLOSSEUM_ENTRY_STATE_WAIT_END_SYNC:
        if (LinkSync_IsSynced(4)) {
            ClearFrameAndWindow2(&entry->messageWindow, FALSE);
            entry->callback(FALSE, NULL);
            entry->state = COLOSSEUM_ENTRY_STATE_EXIT;
        }
        break;
    }

    return FALSE;
}

static u8 Colosseum_PrintMessage(ColosseumEntry *entry, String *message) {
    Window *window = &entry->messageWindow;
    Options *options;
    if (!WindowIsInUse(window)) {
        DialogBox_AddWindowToLayer3(entry->fieldSystem->bgConfig, window, GF_BG_LYR_MAIN_3);
        options = Save_PlayerData_GetOptionsAddr(entry->fieldSystem->saveData);
        DialogBox_LoadFrame(window, options);
    } else {
        DialogBox_Clear(window);
    }
    options = Save_PlayerData_GetOptionsAddr(entry->fieldSystem->saveData);
    return DialogBox_PrintMessage(window, message, options, TRUE);
}

static void Colosseum_RemoveWindows(ColosseumEntry *entry, BOOL clearFrame) {
    if (WindowIsInUse(&entry->messageWindow)) {
        if (clearFrame) {
            ClearFrameAndWindow2(&entry->messageWindow, FALSE);
            ClearWindowTilemapAndCopyToVram(&entry->messageWindow);
        }
        RemoveWindow(&entry->messageWindow);
        InitWindow(&entry->messageWindow);
    }
    if (WindowIsInUse(&entry->monListWindow)) {
        RemoveWindow(&entry->monListWindow);
        InitWindow(&entry->monListWindow);
    }
    if (WindowIsInUse(&entry->choiceWindow)) {
        RemoveWindow(&entry->choiceWindow);
        InitWindow(&entry->choiceWindow);
    }
}

void Colosseum_StartEntry(FieldSystem *fieldSystem, ColosseumEntryCallback callback) {
    ColosseumEntry *entry;
    u32 size;
    if (fieldSystem->taskman != NULL) {
        return;
    }
    entry = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(ColosseumEntry));
    MI_CpuFill8(entry, 0, sizeof(ColosseumEntry));
    entry->timer = 5;
    entry->fieldSystem = fieldSystem;
    entry->callback = callback;
    entry->msgFormat = MessageFormat_New(HEAP_ID_FIELD2);
    entry->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0014_bin, HEAP_ID_FIELD2);
    entry->message = String_New(200, HEAP_ID_FIELD2);
    entry->expandedMessage = String_New(200, HEAP_ID_FIELD2);
    InitWindow(&entry->messageWindow);
    InitWindow(&entry->monListWindow);
    InitWindow(&entry->choiceWindow);
    entry->cursor = ListMenuCursorNew(HEAP_ID_FIELD2);
    entry->linkMode = CommState_GetLinkMode();
    entry->sentMons = NULL;
    entry->receivedMons = NULL;
    entry->party = NULL;
    entry->exchangeFlags = 0;
    entry->netId = Comm_GetLocalNetId();
    entry->opponentProfile = CommPlayerInfo_GetProfile(1 ^ entry->netId);
    switch (entry->linkMode) {
    case COMM_TYPE_MIX_BATTLE:
        size = Colosseum_GetMixBattleMonsSize();
        entry->sentMons = Heap_AllocAtEnd(HEAP_ID_FIELD2, size);
        entry->receivedMons = Heap_AllocAtEnd(HEAP_ID_FIELD2, size);
        entry->party = SaveArray_Party_Alloc(HEAP_ID_FIELD2);
        Party_InitWithMaxSize(entry->party, COLOSSEUM_MIX_BATTLE_MONS);
        entry->delay = 5;
        entry->state = COLOSSEUM_ENTRY_STATE_MIX_DELAY;
        break;
    case COMM_TYPE_MULTI_BATTLE_1:
        entry->state = COLOSSEUM_ENTRY_STATE_START_CHOOSE;
        break;
    default:
        if (entry->fieldSystem->linkBattleRuleset != NULL) {
            entry->state = COLOSSEUM_ENTRY_STATE_START_CHOOSE;
        } else {
            entry->state = COLOSSEUM_ENTRY_STATE_FACE_CENTER;
        }
        break;
    }
    FieldSystem_CreateTask(fieldSystem, Task_ColosseumEntry, entry);
}

static void Colosseum_FreeEntry(ColosseumEntry *entry) {
    if (entry->party) {
        Heap_Free(entry->party);
    }
    if (entry->sentMons) {
        Heap_Free(entry->sentMons);
    }
    if (entry->receivedMons) {
        Heap_Free(entry->receivedMons);
    }
    DestroyMsgData(entry->msgData);
    MessageFormat_Delete(entry->msgFormat);
    String_Delete(entry->message);
    String_Delete(entry->expandedMessage);
    DestroyListMenuCursorObj(entry->cursor);
    Colosseum_RemoveWindows(entry, TRUE);
}

static ColosseumEntry *Colosseum_GetEntry(FieldSystem *fieldSystem) {
    return TaskManager_GetEnvironment(fieldSystem->taskman);
}

// The three Pokemon sent in a Mix Battle, followed by the ready flag (NULL: we cancelled).
static void Colosseum_PackMixBattleMons(ColosseumEntry *entry, BOOL ready) {
    Party *party = SaveArray_Party_Get(entry->fieldSystem->saveData);
    u8 *buffer = entry->sentMons;
    u32 size = Pokemon_sizeof();
    int i;
    *(BOOL *)(buffer + size * COLOSSEUM_MIX_BATTLE_MONS) = ready;
    if (*(BOOL *)(buffer + size * COLOSSEUM_MIX_BATTLE_MONS)) {
        for (i = 0; i < COLOSSEUM_MIX_BATTLE_MONS; i++) {
            Pokemon *mon = Party_GetMonByIndex(party, entry->selectedOrder[i] - 1);
            MI_CpuCopy8(mon, buffer, size);
            buffer += size;
        }
    }
}

static BOOL Colosseum_SendMixBattleMons(ColosseumEntry *entry) {
    BOOL result;
    if ((entry->exchangeFlags & COLOSSEUM_EXCHANGE_SENT) == 0) {
        u8 *mons = entry->sentMons;
        u32 size = Colosseum_GetMixBattleMonsSize();
        if (entry->netId == 0) {
            result = Comm_SendParentCommandNoCopy(106, mons, size);
        } else {
            result = Comm_SendCommandNoCopy(106, mons, size);
        }
        if (result) {
            entry->exchangeFlags |= COLOSSEUM_EXCHANGE_SENT;
        }
    } else {
        result = TRUE;
    }
    return result;
}

static BOOL Colosseum_MixBattleMonsExchanged(ColosseumEntry *entry) {
    return entry->exchangeFlags == COLOSSEUM_EXCHANGE_DONE;
}

static BOOL Colosseum_OpponentIsReady(ColosseumEntry *entry) {
    u32 size = Pokemon_sizeof();
    return *(BOOL *)(entry->receivedMons + size * COLOSSEUM_MIX_BATTLE_MONS);
}

static BOOL Colosseum_SendMixBattleChoice(ColosseumEntry *entry) {
    BOOL result;
    if (entry->netId == 0) {
        result = Comm_SendParentCommand(107, &entry->choice, 1);
    } else {
        result = Comm_SendCommand(107, &entry->choice, 1);
    }
    if (result) {
        entry->exchangeFlags |= COLOSSEUM_EXCHANGE_SENT;
    }
    return result;
}

static BOOL Colosseum_MixBattleChoicesExchanged(ColosseumEntry *entry) {
    return entry->exchangeFlags == COLOSSEUM_EXCHANGE_DONE;
}

static void Colosseum_SetOpponentParty(ColosseumEntry *entry) {
    u32 size = Pokemon_sizeof();
    int i;
    Party_InitWithMaxSize(entry->party, COLOSSEUM_MIX_BATTLE_MONS);
    for (i = 0; i < COLOSSEUM_MIX_BATTLE_MONS; i++) {
        Party_AddMon(entry->party, (Pokemon *)(entry->receivedMons + i * size));
    }
}

// Our Pokemon the opponent picked is replaced with the one we picked from theirs.
static void Colosseum_ExchangeMixBattleMons(ColosseumEntry *entry) {
    u32 size = Pokemon_sizeof();
    u8 choice = entry->choice;
    u8 opponentChoice = entry->opponentChoice;
    int i;
    MI_CpuCopy8(entry->receivedMons + choice * size, entry->sentMons + opponentChoice * size, size);
    Party_InitWithMaxSize(entry->party, COLOSSEUM_MIX_BATTLE_MONS);
    for (i = 0; i < COLOSSEUM_MIX_BATTLE_MONS; i++) {
        Party_AddMon(entry->party, (Pokemon *)(entry->sentMons + i * size));
    }
}

static void Colosseum_ShowOpponentMons(ColosseumEntry *entry, int cursor) {
    Window *window = &entry->monListWindow;
    u32 monSize;
    MsgData *speciesNames;
    int i, offset, y;
    if (!WindowIsInUse(window)) {
        speciesNames = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0237_bin, HEAP_ID_FIELD1);
        monSize = Pokemon_sizeof();
        AddWindowParameterized(entry->fieldSystem->bgConfig, window, GF_BG_LYR_MAIN_3, 21, 9, 10, 8, 13, 10);
        LoadUserFrameGfx1(entry->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 1, 11, 0, HEAP_ID_FIELD1);
        FillWindowPixelBuffer(window, 15);
        i = 0;
        offset = i;
        y = i;
        for (; i < COLOSSEUM_MIX_BATTLE_MONS; i++) {
            ReadMsgDataIntoString(speciesNames, GetMonData((Pokemon *)(entry->receivedMons + offset), MON_DATA_SPECIES, NULL), entry->message);
            AddTextPrinterParameterized(window, 0, entry->message, 16, y, TEXT_SPEED_NOTRANSFER, NULL);
            offset += monSize;
            y += 16;
        }
        ReadMsgDataIntoString(entry->msgData, msg_0014_00021, entry->message);
        AddTextPrinterParameterized(window, 0, entry->message, 16, i << 4, TEXT_SPEED_NOTRANSFER, NULL);
        DestroyMsgData(speciesNames);
    }
    FillWindowPixelRect(window, 15, 0, 0, 16, window->height * 8);
    ListMenuUpdateCursorObj_Int(entry->cursor, &entry->monListWindow, 0, cursor << 4);
    DrawFrameAndWindow1(&entry->monListWindow, FALSE, 1, 11);
    entry->menuCursor = cursor;
    entry->menuCount = COLOSSEUM_MIX_BATTLE_MONS + 1;
    entry->menuWindow = window;
}

// SUMMARY / OK / CANCEL for the picked Pokemon.
static void Colosseum_ShowChoiceMenu(ColosseumEntry *entry, int cursor) {
    Window *window = &entry->choiceWindow;
    int i;
    int y;

    if (!WindowIsInUse(window)) {
        AddWindowParameterized(entry->fieldSystem->bgConfig, window, GF_BG_LYR_MAIN_3, 20, 11, 11, 6, 13, 90);
        LoadUserFrameGfx1(entry->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 1, 11, 0, HEAP_ID_FIELD1);
        FillWindowPixelBuffer(window, 15);
        for (i = 0, y = 0; i < 3; i++, y += 16) {
            ReadMsgDataIntoString(entry->msgData, i + msg_0014_00022, entry->message);
            AddTextPrinterParameterized(window, 0, entry->message, 16, y, TEXT_SPEED_NOTRANSFER, NULL);
        }
    }
    entry->menuCount = 3;
    entry->menuWindow = window;
    entry->menuCursor = cursor;
    FillWindowPixelRect(window, 15, 0, 0, 16, window->height * 8);
    ListMenuUpdateCursorObj_Int(entry->cursor, entry->menuWindow, 0, cursor * 16);
    DrawFrameAndWindow1(entry->menuWindow, FALSE, 1, 11);
}

enum ColosseumMenuInput Colosseum_HandleMenuInput(ColosseumEntry *entry) {
    int cursor;

    if (gSystem.newKeys & PAD_KEY_UP) {
        entry->menuCursor = entry->menuCursor == 0 ? entry->menuCount - 1 : entry->menuCursor - 1;
    } else if (gSystem.newKeys & PAD_KEY_DOWN) {
        cursor = entry->menuCursor;
        if (cursor == entry->menuCount - 1) {
            cursor = 0;
        } else {
            cursor++;
        }
        entry->menuCursor = cursor;
    } else if (gSystem.newKeys & PAD_BUTTON_A) {
        PlaySE(SEQ_SE_DP_SELECT);
        if (entry->menuCursor < entry->menuCount - 1) {
            return COLOSSEUM_MENU_SELECT;
        }
        return COLOSSEUM_MENU_CANCEL;
    } else if (gSystem.newKeys & PAD_BUTTON_B) {
        PlaySE(SEQ_SE_DP_SELECT);
        return COLOSSEUM_MENU_CANCEL;
    } else {
        return COLOSSEUM_MENU_NONE;
    }

    PlaySE(SEQ_SE_DP_SELECT);
    FillWindowPixelRect(entry->menuWindow, 15, 0, 0, 16, entry->menuWindow->height * 8);
    ListMenuUpdateCursorObj_Int(entry->cursor, entry->menuWindow, 0, entry->menuCursor << 4);
    CopyWindowPixelsToVram_TextMode(entry->menuWindow);
    return COLOSSEUM_MENU_NONE;
}

static void Colosseum_CloseMenu(ColosseumEntry *entry) {
    EraseFrameAndWindow1(entry->menuWindow, TRUE);
}

void Colosseum_RecvMixBattleMons(int netId, int size, void *data, FieldSystem *fieldSystem) {
    ColosseumEntry *entry = Colosseum_GetEntry(fieldSystem);
    if (entry->netId != netId) {
        entry->exchangeFlags |= COLOSSEUM_EXCHANGE_RECEIVED;
    }
}

u32 Colosseum_GetMixBattleMonsSize(void) {
    u32 size = Pokemon_sizeof();
    return size * COLOSSEUM_MIX_BATTLE_MONS + 4;
}

u8 *Colosseum_GetMixBattleMonsBuffer(int netId, FieldSystem *fieldSystem) {
    ColosseumEntry *entry = Colosseum_GetEntry(fieldSystem);
    if (entry->netId != netId) {
        return entry->receivedMons;
    }
    return NULL;
}

void Colosseum_RecvMixBattleChoice(int netId, int size, const u8 *data, FieldSystem *fieldSystem) {
    ColosseumEntry *entry = Colosseum_GetEntry(fieldSystem);
    if (entry->netId != netId) {
        entry->opponentChoice = *data;
        entry->exchangeFlags |= COLOSSEUM_EXCHANGE_RECEIVED;
    }
}

BOOL Task_ColosseumTrainerCard(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    ColosseumTrainerCard *env = TaskManager_GetEnvironment(taskManager);
    u8 *card = CommClubLink_GetCard(env->netId, 0, 0);
    switch (env->state) {
    case COLOSSEUM_CARD_STATE_PRINT: {
        int message;
        env->msgFormat = MessageFormat_New(HEAP_ID_FIELD1);
        env->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0014_bin, HEAP_ID_FIELD1);
        env->strings[0] = String_New(200, HEAP_ID_FIELD1);
        env->strings[1] = String_New(200, HEAP_ID_FIELD1);
        // card[0]: game version; card[3]: stars
        switch (card[0]) {
        case VERSION_HEARTGOLD:
        case VERSION_SOULSILVER:
            message = card[3] + msg_0014_00002;
            break;
        case VERSION_DIAMOND:
            message = msg_0014_00025;
            break;
        case VERSION_PEARL:
            message = msg_0014_00026;
            break;
        case VERSION_PLATINUM:
            message = msg_0014_00027;
            break;
        default:
            message = msg_0014_00002;
            break;
        }
        ReadMsgDataIntoString(env->msgData, message, env->strings[0]);
        BufferPlayersName(env->msgFormat, 0, CommPlayerInfo_GetProfile(env->netId));
        StringExpandPlaceholders(env->msgFormat, env->strings[1], env->strings[0]);
        DialogBox_AddWindowToLayer3(fieldSystem->bgConfig, &env->window, GF_BG_LYR_MAIN_3);
        DialogBox_LoadFrame(&env->window, Save_PlayerData_GetOptionsAddr(fieldSystem->saveData));
        env->printerId = DialogBox_PrintMessage(&env->window, env->strings[1], Save_PlayerData_GetOptionsAddr(fieldSystem->saveData), TRUE);
        env->state++;
    } break;
    case COLOSSEUM_CARD_STATE_WAIT_INPUT:
        if (DialogBox_IsPrintFinished(env->printerId) && gSystem.newKeys & PAD_BUTTON_A) {
            DestroyMsgData(env->msgData);
            MessageFormat_Delete(env->msgFormat);
            String_Delete(env->strings[0]);
            String_Delete(env->strings[1]);
            ClearFrameAndWindow2(&env->window, FALSE);
            RemoveWindow(&env->window);
            FieldMap_FadeScreen(FADE_TYPE_BRIGHTNESS_OUT);
            env->state++;
        }
        break;
    case COLOSSEUM_CARD_STATE_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished()) {
            env->state++;
        }
        break;
    case COLOSSEUM_CARD_STATE_LAUNCH:
        MI_CpuCopy8(card, env->cardArgs.card, sizeof(env->cardArgs.card));
        TrainerCard_LaunchApp(fieldSystem, &env->cardArgs);
        env->state++;
        break;
    case COLOSSEUM_CARD_STATE_WAIT_APP:
        if (!FieldSystem_ApplicationIsRunning(fieldSystem)) {
            env->state++;
        }
        break;
    case COLOSSEUM_CARD_STATE_LOAD_FIELD:
        FieldSystem_LoadFieldOverlay(fieldSystem);
        env->state++;
        break;
    case COLOSSEUM_CARD_STATE_WAIT_FIELD:
        if (!FieldSystem_IsOverworldRestored(fieldSystem)) {
            FieldMap_FadeScreen(FADE_TYPE_BRIGHTNESS_IN);
            CommPlayerManager_ResyncLocalPlayer();
            env->state++;
        }
        break;
    case COLOSSEUM_CARD_STATE_FINISH:
        CommPlayerManager_ResumeField();
        Heap_Free(env);
        return TRUE;
    default:
        return TRUE;
    }
    return FALSE;
}

// The player pressed A: show the Trainer Card of the player sitting opposite (on the square the player faces).
void Colosseum_ShowOpponentTrainerCard(FieldSystem *fieldSystem) {
    int i;
    u32 localNetId = Comm_GetLocalNetId();
    int frontX = CommPlayerManager_GetPlayerFrontX();
    int frontZ = CommPlayerManager_GetPlayerFrontZ(localNetId);

    for (i = 0; i < Comm_CountConnected(); i++) {
        if (i != localNetId && frontX == CommPlayerManager_GetPlayerX(i) && frontZ == CommPlayerManager_GetPlayerZ(i)) {
            ColosseumTrainerCard *env = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(ColosseumTrainerCard));
            env->netId = i;
            env->state = COLOSSEUM_CARD_STATE_PRINT;
            FieldSystem_CreateTask(fieldSystem, Task_ColosseumTrainerCard, env);
            FieldSystem_PauseProcesses();
            return;
        }
    }
}
