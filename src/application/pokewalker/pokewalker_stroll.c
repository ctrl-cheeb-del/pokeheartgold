// Pokewalker connection app, modes 4 and 5: waiting before the save, and starting a Stroll.

#include "global.h"

#include "constants/items.h"

#include "application/pokewalker/pokewalker_app.h"
#include "application/pokewalker/pokewalker_app_internal.h"
#include "msgdata/msg/msg_0274.h"

#include "bag.h"
#include "math_util.h"
#include "player_data.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "pokewalker.h"
#include "save.h"
#include "save_arrays.h"
#include "system.h"
#include "text.h"
#include "trainer_memo.h"

static BOOL PokewalkerApp_AddStrollExp(BoxPokemon *boxMon, Pokemon *mon, int exp);
static void PokewalkerApp_AddStrollFriendship(BoxPokemon *boxMon, int steps);
static void PokewalkerApp_CreateWalkerMon(Pokemon *mon, u32 otId, const PokewalkerMon *walkerMon, u32 nature, BOOL genMode);
static void PokewalkerApp_CreateWalkerMonWithOT(Pokemon *mon, PlayerProfile *profile, const PokewalkerMon *walkerMon, u32 nature, BOOL genMode);
static void PokewalkerApp_ReceiveGifts(PokewalkerApp *app);

enum StartStrollState {
    START_STROLL_PRINT_SAVING,
    START_STROLL_WAIT_SAVING,
    START_STROLL_SAVE,
    START_STROLL_END_SAVE,
    START_STROLL_CHECK_FIRST_STROLL,
    START_STROLL_PRINT_REGISTERED,
    START_STROLL_WAIT_REGISTERED,
    START_STROLL_END,
    START_STROLL_DONE,
};

enum PokewalkerAppState PokewalkerApp_WaitKeyToSave_Enter(PokewalkerApp *app) {
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_WaitKeyToSave_Update(PokewalkerApp *app) {
    if (gSystem.newKeys & PAD_KEY_DOWN) {
        app->nextMode = POKEWALKER_APP_MODE_LINK_SAVE;
        return POKEWALKER_APP_STATE_EXIT;
    }
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_WaitKeyToSave_Exit(PokewalkerApp *app) {
    return POKEWALKER_APP_STATE_ENTER;
}

enum PokewalkerAppState PokewalkerApp_StartStroll_Enter(PokewalkerApp *app) {
    PCStorage *pcStorage = SaveArray_PCStorage_Get(app->saveData);
    int box = app->selectMon.selection.page;
    int slot = app->selectMon.selection.slot;
    ((void (*)(POKEWALKER *, int, int))Pokewalker_SetStrollState)(app->pokewalker, 2, box);
    ((void (*)(POKEWALKER *, int))Pokewalker_SetCourse)(app->pokewalker, app->courseId);
    Pokewalker_SetBoxMon(app->pokewalker, PCStorage_GetMonByIndexPair(pcStorage, box, slot));
    PCStorage_DeleteBoxMonByIndexPair(pcStorage, box, slot);
    PokewalkerApp_ReceiveGifts(app);
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_StartStroll_Update(PokewalkerApp *app) {
    app->state = gStartStrollStates[app->state](app);
    if (app->state == START_STROLL_DONE) {
        app->state = 0;
        return POKEWALKER_APP_STATE_EXIT;
    }
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_StartStroll_Exit(PokewalkerApp *app) {
    return POKEWALKER_APP_STATE_ENTER;
}

int PokewalkerApp_StartStroll_PrintSaving(PokewalkerApp *app) {
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 2, msg_0274_00013);
    PokewalkerApp_ShowConnectionSprites(app, 0);
    return START_STROLL_WAIT_SAVING;
}

int PokewalkerApp_StartStroll_WaitSaving(PokewalkerApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId)) {
        PokewalkerApp_CreateWaitingIcon(app);
        return START_STROLL_SAVE;
    }
    return START_STROLL_WAIT_SAVING;
}

int PokewalkerApp_StartStroll_Save(PokewalkerApp *app) {
    SaveGameNormal(app->saveData);
    Save_ClearStatusFlags(app->saveData);
    return START_STROLL_END_SAVE;
}

int PokewalkerApp_StartStroll_EndSave(PokewalkerApp *app) {
    PokewalkerApp_DeleteWaitingIcon(app);
    return START_STROLL_CHECK_FIRST_STROLL;
}

int PokewalkerApp_StartStroll_CheckFirstStroll(PokewalkerApp *app) {
    if (Pokewalker_GetLinkCount(app->pokewalker) == 1) {
        return START_STROLL_PRINT_REGISTERED;
    }
    app->nextMode = POKEWALKER_APP_MODE_STROLL_REPORT;
    app->linkAction = POKEWALKER_LINK_STROLL_STARTED;
    return START_STROLL_END;
}

int PokewalkerApp_StartStroll_PrintRegistered(PokewalkerApp *app) {
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 2, msg_0274_00025);
    return START_STROLL_WAIT_REGISTERED;
}

int PokewalkerApp_StartStroll_WaitRegistered(PokewalkerApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId)) {
        app->nextMode = POKEWALKER_APP_MODE_EXIT;
        return START_STROLL_END;
    }
    return START_STROLL_WAIT_REGISTERED;
}

int PokewalkerApp_StartStroll_End(PokewalkerApp *app) {
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
    return START_STROLL_DONE;
}

#pragma opt_propagation off

// Puts the Pokemon back from its Stroll into the first free PC slot: the Pokemon stored in the save data, with the
// steps walked as experience, or (peer flag hasWalkerMon) a new Pokemon made from the one on the Pokewalker.
void PokewalkerApp_ReturnStrollMon(PokewalkerApp *app) {
    PCStorage *pcStorage = SaveArray_PCStorage_Get(app->saveData);
    Pokemon *mon = AllocMonZeroed(HEAP_ID_154);
    BoxPokemon *boxMon = Mon_GetBoxMon(mon);
    int box, slot;
    u16 walkerData[2];
    BOOL received;

    Pokewalker_GetStrollState(app->pokewalker, &walkerData[0], &walkerData[1]);
    box = walkerData[1];
    slot = 0;
    if (!app->peerIdentity.hasWalkerMon) {
        received = Pokewalker_TryGetBoxMon(app->pokewalker, boxMon);
        if (received) {
            app->strollMonLeveledUp = PokewalkerApp_AddStrollExp(boxMon, mon, app->strollSteps);
        }
        PokewalkerApp_AddStrollFriendship(boxMon, app->strollSteps);
        app->strollSteps = 0;
        Pokewalker_ClearBoxMon(app->pokewalker);
    } else {
        PokewalkerMon *walkerMon = &app->walkerMon;
        u32 nature = MTRandom() % 24;
        PokewalkerApp_CreateWalkerMonWithOT(mon, app->profile, walkerMon, nature, FALSE);
        BoxMonSetTrainerMemo(Mon_GetBoxMon(mon), app->profile, 0, 233, HEAP_ID_154);
        received = TRUE;
    }
    if (received) {
        PCStorage_FindFirstEmptySlot(pcStorage, &box, &slot);
        PCStorage_PlaceMonInBoxByIndexPair(pcStorage, box, slot, boxMon);
        app->strollMon = PCStorage_GetMonByIndexPair(pcStorage, box, slot);
        Pokedex_SetMonSeenFlag(app->pokedex, mon);
        Pokedex_SetMonCaughtFlag(app->pokedex, mon);
    }
    Heap_Free(mon);
}

#pragma opt_propagation reset

// Adds the steps walked as experience, at most up to the next level. Returns whether the Pokemon leveled up.
static BOOL PokewalkerApp_AddStrollExp(BoxPokemon *boxMon, Pokemon *mon, int exp) {
    BOOL leveledUp = FALSE;

    if (GetBoxMonData(boxMon, MON_DATA_LEVEL, NULL) < MAX_LEVEL) {
        int toNextLevel;
        if (exp < 0) {
            exp = 0;
        }
        toNextLevel = CalcBoxMonExpToNextLevel(boxMon);
        if (exp >= toNextLevel) {
            exp = toNextLevel;
            leveledUp = TRUE;
        }
        {
            u32 totalExp = GetBoxMonData(boxMon, MON_DATA_EXPERIENCE, NULL);
            totalExp += exp;
            CopyBoxPokemonToPokemon(boxMon, mon);
            SetMonData(mon, MON_DATA_EXPERIENCE, &totalExp);
        }
        CalcMonLevelAndStats(mon);
        if (leveledUp) {
            MonApplyFriendshipMod(mon, 0, 8);
        }
    }
    return leveledUp;
}

// The Pokewalker gives a Starf Berry once (flag in the Pokewalker save data).
void PokewalkerApp_GiveStarfBerry(PokewalkerApp *app) {
    app->receivedStarfBerry = 0;
    if (app->irStatus.giveStarfBerry && Pokewalker_HasReceivedStarfBerry(app->pokewalker) == 0) {
        Pokewalker_SetReceivedStarfBerry(app->pokewalker);
        Bag_AddItem(app->bag, ITEM_STARF_BERRY, 1, HEAP_ID_154);
        app->receivedStarfBerry = 1;
    }
}

// One point of friendship for a Stroll of at least 5000 steps.
static void PokewalkerApp_AddStrollFriendship(BoxPokemon *boxMon, int steps) {
    u8 friendship;
    if (steps >= 5000) {
        friendship = GetBoxMonData(boxMon, MON_DATA_FRIENDSHIP, NULL);
        if (friendship < 255) {
            friendship++;
            SetBoxMonData(boxMon, MON_DATA_FRIENDSHIP, &friendship);
        }
    }
}

static void PokewalkerApp_CreateWalkerMonWithOT(Pokemon *mon, PlayerProfile *profile, const PokewalkerMon *walkerMon, u32 nature, BOOL genMode) {
    String *name = PlayerProfile_GetPlayerName_NewString(profile, HEAP_ID_154);
    u32 otId = PlayerProfile_GetTrainerID(profile);
    PokewalkerApp_CreateWalkerMon(mon, otId, walkerMon, nature, genMode);
    SetMonData(mon, MON_DATA_OT_NAME_STRING, name);
    String_Delete(name);
}

static void PokewalkerApp_CreateWalkerMon(Pokemon *mon, u32 otId, const PokewalkerMon *walkerMon, u32 nature, BOOL genMode) {
    u8 form = walkerMon->form;
    u8 gender = MON_RATIO_MALE;

    if (walkerMon->gender == 1) {
        gender = MON_RATIO_FEMALE;
    }
    {
        u32 personality = ChangePersonalityToNatureGenderAndAbility(otId, walkerMon->species, nature, gender, nature & 1, genMode);
        CreateMon(mon, walkerMon->species, walkerMon->level, 32, TRUE, personality, OT_ID_PRESET, otId);
    }
    SetMonData(mon, MON_DATA_HELD_ITEM, &walkerMon->heldItem);
    SetMonData(mon, MON_DATA_MOVE1, &walkerMon->moves[0]);
    SetMonData(mon, MON_DATA_MOVE2, &walkerMon->moves[1]);
    SetMonData(mon, MON_DATA_MOVE3, &walkerMon->moves[2]);
    SetMonData(mon, MON_DATA_MOVE4, &walkerMon->moves[3]);
    SetMonData(mon, MON_DATA_FORM, &form);
}

// Puts the items the Pokewalker found and its gift item into the bag.
void PokewalkerApp_ReceiveItems(PokewalkerApp *app) {
    int i;
    for (i = 0; i < 3; i++) {
        u16 item = app->irStatus.items[i].item;
        if (item != ITEM_NONE) {
            Bag_AddItem(app->bag, item, 1, HEAP_ID_154);
        }
    }
    for (i = 0; i < 10; i++) {
        u16 item = app->irStatus.unk_48[i].item;
        if (item != ITEM_NONE) {
            Bag_AddItem(app->bag, item, 1, HEAP_ID_154);
        }
    }
    if (app->irBlocks.flags.hasGiftItem) {
        Bag_AddItem(app->bag, app->irBlocks.giftItem.item, 1, HEAP_ID_154);
    }
}

// Puts the Pokemon the Pokewalker caught and its gift Pokemon into the PC (from the Pokewalker's box if useWalkerBox).
void PokewalkerApp_ReceiveMons(PokewalkerApp *app, BOOL useWalkerBox) {
    int box;
    int slot;
    u16 unused;
    u16 walkerBox;
    u8 otGender;
    u8 fatefulEncounter;
    BoxPokemon *boxMon;
    PokewalkerIrGiftMon *giftMon;
    String *playerName;
    int i;
    String *otName;
    PCStorage *pcStorage;
    Pokemon *mon;
    PokewalkerMon *caughtMon;
    BoxPokemon *giftBoxMon;

    pcStorage = SaveArray_PCStorage_Get(app->saveData);
    mon = AllocMonZeroed(HEAP_ID_154);
    playerName = PlayerProfile_GetPlayerName_NewString(app->profile, HEAP_ID_154);
    Pokewalker_GetStrollState(app->pokewalker, &unused, &walkerBox);
    if (useWalkerBox) {
        box = walkerBox;
    } else {
        box = 0;
    }
    slot = 0;
    caughtMon = app->irStatus.caughtMons;
    for (i = 0; i < 3; i++, caughtMon++) {
        if (caughtMon->species != SPECIES_NONE) {
            PokewalkerApp_CreateWalkerMonWithOT(mon, app->profile, caughtMon, MTRandom() % 24, FALSE);
            BoxMonSetTrainerMemo(Mon_GetBoxMon(mon), app->profile, 0, 233, HEAP_ID_154);
            boxMon = Mon_GetBoxMon(mon);
            PCStorage_FindFirstEmptySlot(pcStorage, &box, &slot);
            PCStorage_PlaceMonInBoxByIndexPair(pcStorage, box, slot, boxMon);
            Pokedex_SetMonSeenFlag(app->pokedex, mon);
            Pokedex_SetMonCaughtFlag(app->pokedex, mon);
        }
    }
    if (app->irBlocks.flags.hasGiftMon) {
        otName = String_New(16, HEAP_ID_154);
        giftMon = &app->irBlocks.giftMon;
        if (giftMon->mon.species != SPECIES_NONE) {
            CopyU16ArrayToString(otName, app->irBlocks.giftMon.otName);
            ZeroMonData(mon);
            giftBoxMon = Mon_GetBoxMon(mon);
            PokewalkerApp_CreateWalkerMon(mon, app->irBlocks.giftMon.otId, &giftMon->mon, MTRandom() % 24, giftMon->mon.isShiny);
            otGender = app->irBlocks.giftMon.otGender;
            SetBoxMonData(giftBoxMon, MON_DATA_OT_GENDER, &otGender);
            SetBoxMonData(giftBoxMon, MON_DATA_OT_NAME_STRING, otName);
            BoxMonSetTrainerMemo(Mon_GetBoxMon(mon), app->profile, 4, app->irBlocks.giftMon.metLocation, HEAP_ID_154);
            SetBoxMonData(giftBoxMon, MON_DATA_ABILITY, &app->irBlocks.giftMon.ability);
            fatefulEncounter = TRUE;
            SetBoxMonData(giftBoxMon, MON_DATA_FATEFUL_ENCOUNTER, &fatefulEncounter);
            SetBoxMonData(giftBoxMon, MON_DATA_POKEBALL, &app->irBlocks.giftMon.pokeball);
            PCStorage_FindFirstEmptySlot(pcStorage, &box, &slot);
            PCStorage_PlaceMonInBoxByIndexPair(pcStorage, box, slot, giftBoxMon);
            Pokedex_SetMonSeenFlag(app->pokedex, mon);
            Pokedex_SetMonCaughtFlag(app->pokedex, mon);
            if (app->strollMon == NULL) {
                app->strollMon = PCStorage_GetMonByIndexPair(pcStorage, box, slot);
            }
        }
        String_Delete(otName);
    }
    String_Delete(playerName);
    Heap_Free(mon);
}

static void PokewalkerApp_ReceiveGifts(PokewalkerApp *app) {
    PokewalkerApp_ReceiveMons(app, TRUE);
    PokewalkerApp_ReceiveItems(app);
    PokewalkerApp_GiveStarfBerry(app);
}
