// Pokewalker connection app, modes 6 to 10: saving after a link, choosing the Pokemon for a Stroll, the event
// log and the Stroll report.

#include "global.h"

#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/sndseq.h"
#include "constants/species.h"

#include "application/choose_starter/choose_starter_sub_res.naix"
#include "application/pokewalker/pokewalker_app.h"
#include "application/pokewalker/pokewalker_app_internal.h"
#include "application/pokewalker/pokewalker_modes2.h"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0274.h"
#include "msgdata/msg/msg_0276.h"

#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "oam_manager.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "party.h"
#include "save.h"
#include "save_arrays.h"
#include "screen_fade.h"
#include "sound.h"
#include "sound_playback.h"
#include "sound_playback_internal.h"
#include "sprite_transfer.h"
#include "string_util.h"
#include "system.h"
#include "text.h"

enum StrollReportState {
    STROLL_REPORT_START,
    STROLL_REPORT_SHOW_RESULTS,
    STROLL_REPORT_WAIT_RESULTS_FADE,
    STROLL_REPORT_PRINT_MON_ARRIVED,
    STROLL_REPORT_PRINT_LEVEL_UP,
    STROLL_REPORT_PRINT_WATTS,
    STROLL_REPORT_PRINT_ROUTE_FOUND,
    STROLL_REPORT_PRINT_ROUTE_AVAILABLE,
    STROLL_REPORT_PRINT_MILESTONE,
    STROLL_REPORT_PRINT_STARF_BERRY,
    STROLL_REPORT_FADE_OUT,
    STROLL_REPORT_WAIT_FADE_OUT,
    STROLL_REPORT_SHOW_CAUGHT_MONS,
    STROLL_REPORT_WAIT_CAUGHT_MONS_FADE,
    STROLL_REPORT_PRINT_MONS_SENT,
    STROLL_REPORT_CAUGHT_MONS_FADE_OUT,
    STROLL_REPORT_WAIT_CAUGHT_MONS_FADE_OUT,
    STROLL_REPORT_SHOW_ITEMS,
    STROLL_REPORT_WAIT_ITEMS_FADE,
    STROLL_REPORT_PRINT_ITEMS_PLACED,
    STROLL_REPORT_ITEMS_FADE_OUT,
    STROLL_REPORT_WAIT_ITEMS_FADE_OUT,
    STROLL_REPORT_GIFTS_FADE_OUT, // receiving a gift
    STROLL_REPORT_WAIT_GIFTS_FADE_OUT,
    STROLL_REPORT_SHOW_GIFTS,
    STROLL_REPORT_WAIT_GIFTS_FADE,
    STROLL_REPORT_PRINT_GIFT_WATTS,
    STROLL_REPORT_PRINT_GIFT_ROUTE_FOUND,
    STROLL_REPORT_GIFTS_DONE_FADE_OUT,
    STROLL_REPORT_WAIT_GIFTS_DONE_FADE_OUT,
    STROLL_REPORT_RECORDS_FADE_OUT, // after a Stroll started
    STROLL_REPORT_WAIT_RECORDS_FADE_OUT,
    STROLL_REPORT_SHOW_RECORDS,
    STROLL_REPORT_WAIT_RECORDS_FADE,
    STROLL_REPORT_PRINT_RECORDS,
    STROLL_REPORT_WAIT_MESSAGE, // then nextState
    STROLL_REPORT_END,
    STROLL_REPORT_DONE,
};

enum BoxDisplayWindow {
    BOX_DISPLAY_WIN_SPECIES,
    BOX_DISPLAY_WIN_LEVEL,
    BOX_DISPLAY_WIN_ITEM_LABEL,
    BOX_DISPLAY_WIN_NICKNAME,
    BOX_DISPLAY_WIN_GENDER,
    BOX_DISPLAY_WIN_ITEM,
};

static void PokewalkerApp_InitSpriteTemplate(SpriteTemplate *template, SpriteList *spriteList, const SpriteResourcesHeader *header, NNS_G2D_VRAM_TYPE whichScreen, enum HeapID heapId);
static BOOL PokewalkerApp_SelectMon_GetBoxMonIcon(PCStorage *storage, u32 box, int slot, BoxMonSelectorMon *selectorMon);
static void PokewalkerApp_SelectMon_GetBoxName(String *dest, PCStorage *storage, int box);
static void PokewalkerApp_SelectMon_InitOam(PokewalkerSelectMonWork *work);
static void PokewalkerApp_SelectMon_InitObjTransfer(void);
static void PokewalkerApp_SelectMon_SetGraphicsModes(BgConfig *bgConfig);
static void PokewalkerApp_SelectMon_SetGxBanks(void);
static void PokewalkerApp_SelectMon_ShowMonInfo(int box, int slot, void *arg);
static void PokewalkerApp_SelectMon_StoreSelection(PokewalkerSelectMonWork *work, PokewalkerApp *app);
static void PokewalkerApp_SelectMon_VBlankCB(void *data);
static Sprite *PokewalkerBoxDisplay_CreateSprite(PokewalkerBoxDisplaySprites *sprites, int resId, int drawPriority, int priority, int x, int y, int anim, BOOL visible);
static void PokewalkerBoxDisplay_CreateSprites(PokewalkerBoxDisplaySprites *sprites);
static void PokewalkerBoxDisplay_DeleteSprites(PokewalkerBoxDisplaySprites *sprites);
static void PokewalkerBoxDisplay_Free(PokewalkerBoxDisplay *display);
static void PokewalkerBoxDisplay_HideSprites(PokewalkerBoxDisplay *display);
static void PokewalkerBoxDisplay_Init(PokewalkerBoxDisplay *display, BgConfig *bgConfig);
static void PokewalkerBoxDisplay_InitBgs(BgConfig *bgConfig);
static void PokewalkerBoxDisplay_InitSprites(PokewalkerBoxDisplaySprites *sprites);
static void PokewalkerBoxDisplay_LoadBgGraphics(BgConfig *bgConfig, enum HeapID heapId);
static PokewalkerBoxDisplay *PokewalkerBoxDisplay_New(enum HeapID heapId);
static void PokewalkerBoxDisplay_PrintMonInfo(PokewalkerBoxDisplay *display, PokewalkerSelectMonInfo *info);
static void PokewalkerBoxDisplay_ShowMon(PokewalkerBoxDisplay *display, PokewalkerSelectMonInfo *info);
static void PokewalkerBoxDisplay_ShowMonSprites(PokewalkerBoxDisplay *display, PokewalkerSelectMonInfo *info);
static void PokewalkerBoxDisplay_Update(PokewalkerBoxDisplay *display);

enum LinkSaveState {
    LINK_SAVE_PRINT_SAVING,
    LINK_SAVE_WAIT_SAVING,
    LINK_SAVE_SAVE,
    LINK_SAVE_END_SAVE,
    LINK_SAVE_SET_NEXT_MODE,
    LINK_SAVE_PRINT_SAVING2,
    LINK_SAVE_WAIT_SAVING2,
    LINK_SAVE_SAVE2,
    LINK_SAVE_END_SAVE2,
    LINK_SAVE_GO_TO_STROLL_REPORT,
    LINK_SAVE_END,
    LINK_SAVE_DONE,
};

enum PokewalkerAppState PokewalkerApp_LinkSave_Enter(PokewalkerApp *app) {
    app->strollMon = NULL;
    if (app->linkAction == POKEWALKER_LINK_RETURN_FROM_STROLL) {
        PokewalkerApp_ReturnStrollMon(app);
        PokewalkerApp_ReceiveMons(app, TRUE);
        PokewalkerApp_ReceiveItems(app);
        PokewalkerApp_GiveStarfBerry(app);
        if (app->peerIdentity.hasWalkerMon == 0) {
            Pokewalker_SetStrollState(app->pokewalker, 1, 0);
        }
        if (app->strollMon != NULL) {
            PokewalkerApp_LoadMonPicture(app->strollMon, app->monSpriteBuffer, &app->monPicTemplate, 0);
            PokewalkerApp_ShowMonPicture(app);
            PokewalkerApp_HideMotionSprites(app);
            app->unk_1F2C2 = 0;
            PlayFanfare(SEQ_ME_KEYITEM);
        } else {
            PokewalkerApp_HideMotionSprites(app);
            app->monPicAlpha = 31;
        }
        PokewalkerApp_UnlockNextCourse(app);
        app->state = LINK_SAVE_PRINT_SAVING;
    } else if (app->linkAction == POKEWALKER_LINK_RECEIVE_GIFT) {
        PokewalkerApp_ReceiveItems(app);
        PokewalkerApp_ReceiveMons(app, FALSE);
        app->state = LINK_SAVE_PRINT_SAVING2;
    } else if (app->linkAction == POKEWALKER_LINK_SEND_MON_BACK) {
        PokewalkerApp_ReturnStrollMon(app);
        PokewalkerApp_LoadMonPicture(app->strollMon, app->monSpriteBuffer, &app->monPicTemplate, 0);
        PokewalkerApp_ShowMonPicture(app);
        app->state = LINK_SAVE_PRINT_SAVING;
        Pokewalker_SetStrollState(app->pokewalker, 1, 0);
    }
    app->peerIdentity.hasWalkerMon = 0;
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_LinkSave_Update(PokewalkerApp *app) {
    int state = gLinkSaveStates[app->state](app);
    app->state = state;
    if (state == LINK_SAVE_DONE) {
        app->state = 0;
        return POKEWALKER_APP_STATE_EXIT;
    }
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_LinkSave_Exit(PokewalkerApp *app) {
    PokewalkerApp_HideSprite(app, 8);
    return POKEWALKER_APP_STATE_ENTER;
}

int PokewalkerApp_LinkSave_PrintSaving(PokewalkerApp *app) {
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 2, msg_0274_00013);
    PokewalkerApp_ShowConnectionSprites(app, 0);
    return LINK_SAVE_WAIT_SAVING;
}

int PokewalkerApp_LinkSave_WaitSaving(PokewalkerApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId) && app->monPicAlpha == 31 && !IsFanfarePlayingOrWaiting()) {
        IsFanfarePlaying();
        PokewalkerApp_CreateWaitingIcon(app);
        return LINK_SAVE_SAVE;
    }
    return LINK_SAVE_WAIT_SAVING;
}

int PokewalkerApp_LinkSave_Save(PokewalkerApp *app) {
    SaveGameNormal(app->saveData);
    Save_ClearStatusFlags(app->saveData);
    return LINK_SAVE_END_SAVE;
}

int PokewalkerApp_LinkSave_EndSave(PokewalkerApp *app) {
    PokewalkerApp_DeleteWaitingIcon(app);
    return LINK_SAVE_SET_NEXT_MODE;
}

int PokewalkerApp_LinkSave_SetNextMode(PokewalkerApp *app) {
    app->nextMode = app->linkAction == POKEWALKER_LINK_SEND_MON_BACK ? POKEWALKER_APP_MODE_MAIN_MENU : POKEWALKER_APP_MODE_EVENT_LOG;
    return LINK_SAVE_END;
}

int PokewalkerApp_LinkSave_PrintSaving2(PokewalkerApp *app) {
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 2, msg_0274_00013);
    PokewalkerApp_ShowConnectionSprites(app, 0);
    return LINK_SAVE_WAIT_SAVING2;
}

int PokewalkerApp_LinkSave_WaitSaving2(PokewalkerApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId)) {
        PokewalkerApp_CreateWaitingIcon(app);
        return LINK_SAVE_SAVE2;
    }
    return LINK_SAVE_WAIT_SAVING2;
}

int PokewalkerApp_LinkSave_Save2(PokewalkerApp *app) {
    SaveGameNormal(app->saveData);
    Save_ClearStatusFlags(app->saveData);
    return LINK_SAVE_END_SAVE2;
}

int PokewalkerApp_LinkSave_EndSave2(PokewalkerApp *app) {
    PokewalkerApp_DeleteWaitingIcon(app);
    return LINK_SAVE_GO_TO_STROLL_REPORT;
}

int PokewalkerApp_LinkSave_GoToStrollReport(PokewalkerApp *app) {
    app->nextMode = POKEWALKER_APP_MODE_STROLL_REPORT;
    return LINK_SAVE_END;
}

int PokewalkerApp_LinkSave_End(PokewalkerApp *app) {
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
    PokewalkerApp_HideSprite(app, 6);
    return LINK_SAVE_DONE;
}

#define SELECT_MON_WORK(app, member) ((u8 *)(app) + offsetof(PokewalkerApp, selectMon) + offsetof(PokewalkerSelectMonWork, member))

enum PokewalkerAppState PokewalkerApp_SelectMon_Enter(PokewalkerApp *app) {
    PCStorage *storage;
    Party *party;

    switch (*(int *)SELECT_MON_WORK(app, state)) {
    case 0:
        PokewalkerApp_Teardown(app);
        *(int *)SELECT_MON_WORK(app, state) = 1;
        break;
    case 1:
        app->bgConfig = BgConfig_Alloc(HEAP_ID_154);
        PokewalkerApp_SelectMon_SetGxBanks();
        *(BoxMonSelector **)SELECT_MON_WORK(app, boxSelector) = BoxMonSelector_New(HEAP_ID_154, 1, NUM_BOXES);
        *(PokewalkerBoxDisplay **)SELECT_MON_WORK(app, boxDisplay) = PokewalkerBoxDisplay_New(HEAP_ID_154);
        PokewalkerApp_SelectMon_SetGraphicsModes(app->bgConfig);
        PokewalkerApp_SelectMon_InitObjTransfer();
        PokewalkerApp_SelectMon_InitOam(&app->selectMon);
        app->selectMon.state = 0;
        storage = SaveArray_PCStorage_Get(app->saveData);
        party = SaveArray_Party_Get(app->saveData);
        BoxMonSelector_Init(*(BoxMonSelector **)SELECT_MON_WORK(app, boxSelector), app->bgConfig, storage, party, 0, 0, TRUE, 0, PokewalkerApp_SelectMon_GetBoxMonIcon, PokewalkerApp_SelectMon_GetBoxName, (BoxMonSelectorResult *)SELECT_MON_WORK(app, selection), PokewalkerApp_SelectMon_ShowMonInfo, app);
        PokewalkerBoxDisplay_Init(*(PokewalkerBoxDisplay **)SELECT_MON_WORK(app, boxDisplay), app->bgConfig);
        Main_SetVBlankIntrCB(PokewalkerApp_SelectMon_VBlankCB, &app->selectMon);
        *(int *)SELECT_MON_WORK(app, state) = 0;
        return POKEWALKER_APP_STATE_UPDATE;
    }
    return POKEWALKER_APP_STATE_ENTER;
}

#undef SELECT_MON_WORK

enum PokewalkerAppState PokewalkerApp_SelectMon_Update(PokewalkerApp *app) {
    PokewalkerSelectMonWork *work = &app->selectMon;

    switch (work->state) {
    case 0:
        work->state = 1;
        break;
    case 1:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_154);
        work->state = 2;
        break;
    case 2:
        if (IsPaletteFadeFinished()) {
            work->state = 3;
        }
        break;
    case 3: {
        int result = BoxMonSelector_Run(work->boxSelector);
        if (result == BOX_MON_SELECTOR_DONE) {
            work->cancelled = FALSE;
            work->state = 4;
        } else if (result == BOX_MON_SELECTOR_CANCEL) {
            work->cancelled = TRUE;
            work->state = 4;
        }
        break;
    }
    case 4:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_154);
        work->state = 5;
        break;
    case 5:
        if (IsPaletteFadeFinished()) {
            PokewalkerApp_SelectMon_StoreSelection(work, app);
            return POKEWALKER_APP_STATE_EXIT;
        }
        break;
    }

    BoxMonSelector_RenderSprites(work->boxSelector);
    PokewalkerBoxDisplay_Update(work->boxDisplay);
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_SelectMon_Exit(PokewalkerApp *app) {
    app->selectMon.state = 0;
    Main_SetVBlankIntrCB(NULL, NULL);
    BoxMonSelector_Delete(app->selectMon.boxSelector);
    PokewalkerBoxDisplay_Free(app->selectMon.boxDisplay);
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    Heap_Free(app->bgConfig);
    PokewalkerApp_Setup(app);
    app->nextMode = app->selectMon.cancelled == TRUE ? POKEWALKER_APP_MODE_MAIN_MENU : POKEWALKER_APP_MODE_LINK;
    return POKEWALKER_APP_STATE_ENTER;
}

static void PokewalkerApp_SelectMon_SetGxBanks(void) {
    GraphicsBanks banks = gSelectMonGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

static void PokewalkerApp_SelectMon_SetGraphicsModes(BgConfig *bgConfig) {
    GraphicsModes modes = gSelectMonGraphicsModes;
    SetBothScreensModesAndDisable(&modes);
}

static void PokewalkerApp_SelectMon_InitObjTransfer(void) {
    ObjCharTransferTemplate template = gSelectMonObjCharTransferTemplate;
    ObjCharTransfer_Init(&template);
    ObjPlttTransfer_Init(20, HEAP_ID_154);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
}

static void PokewalkerApp_SelectMon_InitOam(PokewalkerSelectMonWork *work) {
    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 126, 0, 32, 0, 126, 0, 32, HEAP_ID_154);
}

static BOOL PokewalkerApp_SelectMon_GetBoxMon(PCStorage *storage, u32 box, u32 slot, PokewalkerBoxMon *mon) {
    BoxPokemon *boxMon = PCStorage_GetMonByIndexPair(storage, box, slot);
    if (GetBoxMonData(boxMon, MON_DATA_SPECIES_EXISTS, NULL)) {
        mon->species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
        mon->personality = GetBoxMonData(boxMon, MON_DATA_PERSONALITY, NULL);
        mon->isEgg = GetBoxMonData(boxMon, MON_DATA_IS_EGG, NULL);
        mon->form = GetBoxMonData(boxMon, MON_DATA_FORM, NULL);
        mon->heldItem = GetBoxMonData(boxMon, MON_DATA_HELD_ITEM, NULL);
        mon->unk_0E = 0;
        GetBoxMonData(boxMon, MON_DATA_NICKNAME, mon->nickname);
        mon->isShiny = BoxMonIsShiny(boxMon);
        mon->gender = GetBoxMonData(boxMon, MON_DATA_GENDER, NULL);
        mon->level = GetBoxMonData(boxMon, MON_DATA_LEVEL, NULL);
        mon->markings = GetBoxMonData(boxMon, MON_DATA_MARKINGS, NULL);
        return TRUE;
    }
    mon->species = SPECIES_NONE;
    mon->personality = 0;
    mon->isEgg = 0;
    mon->form = 0;
    mon->heldItem = ITEM_NONE;
    mon->unk_0E = 0;
    mon->isShiny = 0;
    mon->gender = 0;
    return FALSE;
}

// Only what the box icons need.
static BOOL PokewalkerApp_SelectMon_GetBoxMonIcon(PCStorage *storage, u32 box, int slot, BoxMonSelectorMon *selectorMon) {
    PokewalkerBoxMon *mon = (PokewalkerBoxMon *)selectorMon;
    BoxPokemon *boxMon = PCStorage_GetMonByIndexPair(storage, box, slot);
    if (GetBoxMonData(boxMon, MON_DATA_SPECIES_EXISTS, NULL)) {
        mon->species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
        mon->personality = 0;
        mon->isEgg = GetBoxMonData(boxMon, MON_DATA_IS_EGG, NULL);
        mon->form = GetBoxMonData(boxMon, MON_DATA_FORM, NULL);
        mon->heldItem = ITEM_NONE;
        mon->unk_0E = 0;
        mon->isShiny = 0;
        mon->gender = 0;
        mon->level = 0;
        mon->markings = 0;
        return TRUE;
    }
    mon->species = SPECIES_NONE;
    mon->personality = 0;
    mon->isEgg = 0;
    mon->form = 0;
    mon->heldItem = ITEM_NONE;
    mon->unk_0E = 0;
    mon->isShiny = 0;
    mon->gender = 0;
    mon->level = 0;
    mon->markings = 0;
    return FALSE;
}

static void PokewalkerApp_SelectMon_GetBoxName(String *dest, PCStorage *storage, int box) {
    PCStorage_GetBoxName(storage, box, dest);
}

static void PokewalkerApp_SelectMon_VBlankCB(void *data) {
    PokewalkerSelectMonWork *work = data;
    BoxMonSelector_VBlank(work->boxSelector);
}

static void PokewalkerApp_SelectMon_StoreSelection(PokewalkerSelectMonWork *work, PokewalkerApp *app) {
    if (!work->cancelled) {
        u32 box = work->selection.page;
        if (box == BOX_MON_SELECTOR_PARTY_PAGE) {
            Pokemon *mon = Party_GetMonByIndex(SaveArray_Party_Get(app->saveData), work->selection.slot);
            work->species = GetMonData(mon, MON_DATA_SPECIES, NULL);
            work->form = GetMonData(mon, MON_DATA_FORM, NULL);
            GetMonData(mon, MON_DATA_NICKNAME, work->nickname);
            work->isShiny = MonIsShiny(mon);
            work->gender = GetMonData(mon, MON_DATA_GENDER, NULL);
            app->strollPartyMon = mon;
            app->strollMon = NULL;
        } else {
            PCStorage *storage = SaveArray_PCStorage_Get(app->saveData);
            BoxPokemon *boxMon = PCStorage_GetMonByIndexPair(storage, box, work->selection.slot);
            PokewalkerBoxMon boxMonInfo;
            if (GetBoxMonData(boxMon, MON_DATA_SPECIES_EXISTS, NULL) != 0) {
                app->strollMon = boxMon;
                app->strollPartyMon = NULL;
            }
            storage = SaveArray_PCStorage_Get(app->saveData);
            PokewalkerApp_SelectMon_GetBoxMon(storage, work->selection.page, work->selection.slot, &boxMonInfo);
            work->species = boxMonInfo.species;
            work->form = boxMonInfo.form;
            CopyU16StringArrayN(work->nickname, boxMonInfo.nickname, POKEMON_NAME_LENGTH + 1);
            work->isShiny = boxMonInfo.isShiny;
            work->gender = boxMonInfo.gender;
        }
    }
}

static void PokewalkerApp_SelectMon_ShowMonInfo(int box, int slot, void *arg) {
    PokewalkerApp *app = arg;
    PokewalkerSelectMonWork *work = &app->selectMon;
    PokewalkerSelectMonInfo info;

    if (box != -1 && slot != -1) {
        info.state = 2;
        if (box == BOX_MON_SELECTOR_PARTY_PAGE) {
            Pokemon *mon = Party_GetMonByIndex(SaveArray_Party_Get(app->saveData), slot);
            u8 i;
            s32 markings;
            info.personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
            info.species = GetMonData(mon, MON_DATA_SPECIES, NULL);
            info.form = GetMonData(mon, MON_DATA_FORM, NULL);
            GetMonData(mon, MON_DATA_NICKNAME, info.nickname);
            info.isShiny = MonIsShiny(mon);
            info.gender = GetMonData(mon, MON_DATA_GENDER, NULL);
            markings = GetMonData(mon, MON_DATA_MARKINGS, NULL);
            for (i = 0; i < 6; i++) {
                if ((markings >> i) & 1) {
                    info.markings[i] = 1;
                } else {
                    info.markings[i] = 0;
                }
            }
            info.heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
            info.level = GetMonData(mon, MON_DATA_LEVEL, NULL);
            PokewalkerBoxDisplay_ShowMon(work->boxDisplay, &info);
            return;
        } else {
            s32 markings;
            u8 i;
            PokewalkerBoxMon boxMonInfo;
            PokewalkerApp_SelectMon_GetBoxMon(SaveArray_PCStorage_Get(app->saveData), box, slot, &boxMonInfo);
            info.personality = boxMonInfo.personality;
            info.species = boxMonInfo.species;
            info.form = boxMonInfo.form;
            CopyU16StringArrayN(info.nickname, boxMonInfo.nickname, POKEMON_NAME_LENGTH + 1);
            info.isShiny = boxMonInfo.isShiny;
            info.gender = boxMonInfo.gender;
            markings = boxMonInfo.markings;
            for (i = 0; i < 6; i++) {
                if ((markings >> i) & 1) {
                    info.markings[i] = 1;
                } else {
                    info.markings[i] = 0;
                }
            }
            info.heldItem = boxMonInfo.heldItem;
            info.level = boxMonInfo.level;
            PokewalkerBoxDisplay_ShowMon(work->boxDisplay, &info);
            return;
        }
    }
    info.state = 0;
    PokewalkerBoxDisplay_ShowMon(work->boxDisplay, &info);
}

enum PokewalkerAppState PokewalkerApp_EventLog_Enter(PokewalkerApp *app) {
    app->eventLogSaveData = app->saveData;
    app->eventLogRecords = app->irStatus.records;
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_WHITE, 6, 1, HEAP_ID_154);
    GF_SndStartFadeOutBGM(0, 16);
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_EventLog_Update(PokewalkerApp *app) {
    switch (app->state) {
    case 0:
        if (IsPaletteFadeFinished() == TRUE) {
            PokewalkerApp_Teardown(app);
            if (PokewalkerApp_IsEventLogInvalid(app->irStatus.records)) {
                return POKEWALKER_APP_STATE_EXIT;
            }
            app->state = 1;
        }
        break;
    case 1:
        app->childApp = OverlayManager_New(&gEventLogAppTemplate, &app->eventLogSaveData, HEAP_ID_154);
        app->state = 2;
        break;
    case 2:
        if (OverlayManager_Run(app->childApp)) {
            OverlayManager_Delete(app->childApp);
            app->state = 3;
        }
        break;
    case 3:
        return POKEWALKER_APP_STATE_EXIT;
    }
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_EventLog_Exit(PokewalkerApp *app) {
    PokewalkerApp_Setup(app);
    app->state = 0;
    app->nextMode = POKEWALKER_APP_MODE_STROLL_REPORT;
    return POKEWALKER_APP_STATE_ENTER;
}

enum PokewalkerAppState PokewalkerApp_WaitKey_Enter(PokewalkerApp *app) {
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_WaitKey_Update(PokewalkerApp *app) {
    if (gSystem.newKeys & PAD_KEY_DOWN) {
        app->nextMode = POKEWALKER_APP_MODE_LINK;
        return POKEWALKER_APP_STATE_EXIT;
    }
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_WaitKey_Exit(PokewalkerApp *app) {
    return POKEWALKER_APP_STATE_ENTER;
}

enum PokewalkerAppState PokewalkerApp_StrollReport_Enter(PokewalkerApp *app) {
    PokewalkerApp_RemoveWindowBank(app, 1);
    PokewalkerApp_AddWindowBank(app, 4);
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_StrollReport_Update(PokewalkerApp *app) {
    int state = gStrollReportStates[app->state](app);
    app->state = state;
    if (state == STROLL_REPORT_DONE) {
        app->state = 0;
        return POKEWALKER_APP_STATE_EXIT;
    }
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_StrollReport_Exit(PokewalkerApp *app) {
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_2);
    PokewalkerApp_RemoveWindowBank(app, 6);
    PokewalkerApp_AddWindowBank(app, 1);
    return POKEWALKER_APP_STATE_ENTER;
}

int PokewalkerApp_StrollReport_Start(PokewalkerApp *app) {
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    if (app->linkAction == POKEWALKER_LINK_RECEIVE_GIFT) {
        return STROLL_REPORT_GIFTS_FADE_OUT;
    }
    if (app->linkAction == POKEWALKER_LINK_STROLL_STARTED) {
        return STROLL_REPORT_RECORDS_FADE_OUT;
    }
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 15);
    PokewalkerApp_PrintStringDefaultColor(app, 1, app->strollResultsText, 0);
    return STROLL_REPORT_SHOW_RESULTS;
}

int PokewalkerApp_StrollReport_ShowResults(PokewalkerApp *app) {
    u32 totalSteps;
    u32 totalWatts;
    u32 strollSteps = 0;
    u32 currentSteps;
    u32 startSteps;

    BufferPokewalkerCourseName(app->msgFormat, 2, (u8)Pokewalker_GetCourse(app->pokewalker));
    currentSteps = app->peerIdentity.steps;
    startSteps = app->walkerSteps;
    if (currentSteps > startSteps) {
        strollSteps = currentSteps - startSteps;
    }
    Pokewalker_GetStepsAndWatts(app->pokewalker, &totalSteps, &totalWatts);
    BufferIntegerAsString(app->msgFormat, 5, strollSteps, 7, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(app->msgFormat, 3, app->irStatus.watts, 7, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(app->msgFormat, 6, totalSteps, 7, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(app->msgFormat, 7, totalWatts, 7, PRINTING_MODE_LEFT_ALIGN, TRUE);
    PokewalkerApp_PrintMessage(app, 2, msg_0274_00056, MAKE_TEXT_COLOR(3, 4, 0));
    PokewalkerApp_PrintMessage(app, 3, msg_0274_00057, MAKE_TEXT_COLOR(3, 4, 0));
    PokewalkerApp_PrintMessage(app, 4, msg_0274_00058, MAKE_TEXT_COLOR(3, 4, 0));
    PokewalkerApp_PrintString(app, 5, app->stepsToDateText, 0, MAKE_TEXT_COLOR(3, 4, 0));
    PokewalkerApp_PrintMessage(app, 6, msg_0274_00060, MAKE_TEXT_COLOR(3, 4, 0));
    PokewalkerApp_PrintString(app, 7, app->wattsToDateText, 0, MAKE_TEXT_COLOR(3, 4, 0));
    PokewalkerApp_PrintMessage(app, 8, msg_0274_00062, MAKE_TEXT_COLOR(3, 4, 0));
    PokewalkerApp_ShowSprite(app, 9);
    PokewalkerApp_SetSpritePosition(app, 9, 210, 64);
    PokewalkerApp_LoadMonIcon(app, 0, app->walkerMon.species, app->walkerMon.form);
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_154);
    return STROLL_REPORT_WAIT_RESULTS_FADE;
}

int PokewalkerApp_StrollReport_WaitResultsFade(PokewalkerApp *app) {
    if (IsPaletteFadeFinished() == TRUE) {
        return STROLL_REPORT_PRINT_MON_ARRIVED;
    }
    return STROLL_REPORT_WAIT_RESULTS_FADE;
}

int PokewalkerApp_StrollReport_PrintMonArrived(PokewalkerApp *app) {
    String *nickname;

    BufferPokewalkerCourseName(app->msgFormat, 1, (u8)Pokewalker_GetCourse(app->pokewalker));
    nickname = String_New(POKEMON_NAME_LENGTH + 2, HEAP_ID_154);
    CopyU16ArrayToStringN(nickname, app->walkerMonNickname, POKEMON_NAME_LENGTH + 1);
    BufferString(app->msgFormat, 1, nickname, app->walkerMon.gender, 1, app->peerIdentity.unk_04);
    String_Delete(nickname);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00044);
    app->nextState = STROLL_REPORT_PRINT_LEVEL_UP;
    return STROLL_REPORT_WAIT_MESSAGE;
}

int PokewalkerApp_StrollReport_PrintLevelUp(PokewalkerApp *app) {
    if (!app->strollMonLeveledUp) {
        return STROLL_REPORT_PRINT_WATTS;
    }
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00052);
    app->nextState = STROLL_REPORT_PRINT_WATTS;
    PlayFanfare(SEQ_ME_LVUP);
    app->strollMonLeveledUp = FALSE;
    return STROLL_REPORT_WAIT_MESSAGE;
}

int PokewalkerApp_StrollReport_PrintWatts(PokewalkerApp *app) {
    if (app->irStatus.watts == 0) {
        app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00046);
    } else {
        PlayFanfare(SEQ_ME_ITEM);
        app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00045);
    }
    app->nextState = STROLL_REPORT_PRINT_ROUTE_FOUND;
    return STROLL_REPORT_WAIT_MESSAGE;
}

int PokewalkerApp_StrollReport_PrintRouteFound(PokewalkerApp *app) {
    u32 course = app->unlockedCourse;
    if (course != 0) {
        BufferPokewalkerCourseName(app->msgFormat, 4, (u8)course);
        app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00048);
        app->nextState = STROLL_REPORT_PRINT_ROUTE_AVAILABLE;
        app->unlockedCourse = 0;
        return STROLL_REPORT_WAIT_MESSAGE;
    }
    return STROLL_REPORT_PRINT_MILESTONE;
}

int PokewalkerApp_StrollReport_PrintRouteAvailable(PokewalkerApp *app) {
    PlayFanfare(SEQ_ME_KEYITEM);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00055);
    app->nextState = STROLL_REPORT_PRINT_MILESTONE;
    return STROLL_REPORT_WAIT_MESSAGE;
}

int PokewalkerApp_StrollReport_PrintMilestone(PokewalkerApp *app) {
    if (app->receivedStarfBerry) {
        app->receivedStarfBerry = FALSE;
        app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00053);
        app->nextState = STROLL_REPORT_PRINT_STARF_BERRY;
        return STROLL_REPORT_WAIT_MESSAGE;
    }
    return STROLL_REPORT_FADE_OUT;
}

int PokewalkerApp_StrollReport_PrintStarfBerry(PokewalkerApp *app) {
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00054);
    app->nextState = STROLL_REPORT_FADE_OUT;
    PlayFanfare(SEQ_ME_KEYITEM);
    return STROLL_REPORT_WAIT_MESSAGE;
}

int PokewalkerApp_StrollReport_FadeOut(PokewalkerApp *app) {
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_154);
    return STROLL_REPORT_WAIT_FADE_OUT;
}

int PokewalkerApp_StrollReport_WaitFadeOut(PokewalkerApp *app) {
    if (IsPaletteFadeFinished() == TRUE) {
        return STROLL_REPORT_SHOW_CAUGHT_MONS;
    }
    return STROLL_REPORT_WAIT_FADE_OUT;
}

// Pokemon caught on the Stroll plus the gift Pokemon the Pokewalker holds.
static int PokewalkerApp_CountReceivedMons(PokewalkerIrStatus *status, PokewalkerIrBlocks *blocks) {
    int count = 0;
    int i;
    for (i = 0; i < 3; i++) {
        u16 species = status->caughtMons[i].species;
        if (species != SPECIES_NONE && species <= NATIONAL_DEX_COUNT) {
            count++;
        }
    }
    if (blocks->flags.hasGiftMon) {
        u16 species = blocks->giftMon.mon.species;
        if (species != SPECIES_NONE && species <= NATIONAL_DEX_COUNT) {
            count++;
        }
    }
    return count;
}

int PokewalkerApp_StrollReport_ShowCaughtMons(PokewalkerApp *app) {
    int i;
    PokewalkerMon *mon;

    PokewalkerApp_RemoveWindowBank(app, 4);
    PokewalkerApp_AddWindowBank(app, 5);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    if (!PokewalkerApp_CountReceivedMons(&app->irStatus, &app->irBlocks)) {
        PokewalkerApp_HideSprite(app, 9);
        return STROLL_REPORT_SHOW_ITEMS;
    }
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 15);
    PokewalkerApp_PrintStringDefaultColor(app, 1, app->yourPokemonText, 0);
    PokewalkerApp_PrintStringDefaultColor(app, 1, app->yourPokemonText, 0);
    for (i = 0; i < 4; i++) {
        PokewalkerApp_HideSprite(app, i + 9);
    }
    PokewalkerApp_SetSpritePosition(app, 9, 40, 64);
    PokewalkerApp_SetSpritePosition(app, 10, 144, 64);
    PokewalkerApp_SetSpritePosition(app, 11, 40, 96);
    PokewalkerApp_SetSpritePosition(app, 12, 144, 96);
    for (i = 0; i < 3; i++) {
        if (app->irStatus.caughtMons[i].species != SPECIES_NONE) {
            PokewalkerApp_ShowSprite(app, i + 9);
            BufferSpeciesName(app->msgFormat, i + 8, app->irStatus.caughtMons[i].species);
            PokewalkerApp_PrintMessage(app, i + 3, i + msg_0274_00067, MAKE_TEXT_COLOR(3, 4, 0));
            PokewalkerApp_LoadMonIcon(app, i, app->irStatus.caughtMons[i].species, app->irStatus.caughtMons[i].form);
        }
    }
    if (app->irBlocks.flags.hasGiftMon) {
        mon = &app->irBlocks.giftMon.mon;
        if (mon->species != SPECIES_NONE) {
            PokewalkerApp_ShowSprite(app, 12);
            BufferSpeciesName(app->msgFormat, 11, mon->species);
            PokewalkerApp_PrintMessage(app, 6, msg_0274_00070, MAKE_TEXT_COLOR(3, 4, 0));
            PokewalkerApp_LoadMonIcon(app, 3, mon->species, mon->form);
        }
    }
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_154);
    return STROLL_REPORT_WAIT_CAUGHT_MONS_FADE;
}

int PokewalkerApp_StrollReport_WaitCaughtMonsFade(PokewalkerApp *app) {
    if (IsPaletteFadeFinished() == TRUE) {
        return STROLL_REPORT_PRINT_MONS_SENT;
    }
    return STROLL_REPORT_WAIT_CAUGHT_MONS_FADE;
}

int PokewalkerApp_StrollReport_PrintMonsSent(PokewalkerApp *app) {
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00049);
    app->nextState = STROLL_REPORT_CAUGHT_MONS_FADE_OUT;
    PlayFanfare(SEQ_ME_KEYITEM);
    return STROLL_REPORT_WAIT_MESSAGE;
}

int PokewalkerApp_StrollReport_CaughtMonsFadeOut(PokewalkerApp *app) {
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_154);
    return STROLL_REPORT_WAIT_CAUGHT_MONS_FADE_OUT;
}

int PokewalkerApp_StrollReport_WaitCaughtMonsFadeOut(PokewalkerApp *app) {
    int i;
    if (IsPaletteFadeFinished() == TRUE) {
        for (i = 0; i < 4; i++) {
            PokewalkerApp_HideSprite(app, i + 9);
        }
        return STROLL_REPORT_SHOW_ITEMS;
    }
    return STROLL_REPORT_WAIT_CAUGHT_MONS_FADE_OUT;
}

// Adds item to the first free slot of a zero-terminated list of 14.
static void PokewalkerApp_AddItemToList(u16 *items, u16 item) {
    int i;
    for (i = 0; i < 14; i++) {
        if (items[i] == ITEM_NONE) {
            break;
        }
    }
    GF_ASSERT(i < 14);
    items[i] = item;
}

// Items found on the Stroll plus the gift item the Pokewalker holds.
static int PokewalkerApp_CountReceivedItems(PokewalkerApp *app) {
    int count = 0;
    int i;
    for (i = 0; i < 3; i++) {
        if (app->irStatus.items[i].item != ITEM_NONE) {
            count++;
        }
    }
    for (i = 0; i < 10; i++) {
        if (app->irStatus.unk_48[i].item != ITEM_NONE) {
            count++;
        }
    }
    if (app->irBlocks.flags.hasGiftItem && app->irBlocks.giftItem.item != ITEM_NONE) {
        count++;
    }
    return count;
}

int PokewalkerApp_StrollReport_ShowItems(PokewalkerApp *app) {
    u16 items[14];
    int i;
    String *string;

    PokewalkerApp_RemoveWindowBank(app, 5);
    PokewalkerApp_AddWindowBank(app, 6);
    if (!PokewalkerApp_CountReceivedItems(app)) {
        return STROLL_REPORT_END;
    }
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 15);
    PokewalkerApp_PrintStringDefaultColor(app, 1, app->itemsObtainedText, 0);
    MI_CpuClearFast(items, sizeof(items));
    for (i = 0; i < 3; i++) {
        PokewalkerApp_AddItemToList(items, app->irStatus.items[i].item);
    }
    for (i = 0; i < 10; i++) {
        PokewalkerApp_AddItemToList(items, app->irStatus.unk_48[i].item);
    }
    if (app->irBlocks.flags.hasGiftItem) {
        PokewalkerApp_AddItemToList(items, app->irBlocks.giftItem.item);
        MI_CpuClearFast(&app->irBlocks, sizeof(PokewalkerIrBlocks));
        MI_CpuClearFast(&app->irStatus, sizeof(PokewalkerIrStatus));
    }
    string = String_New(19, HEAP_ID_154);
    for (i = 0; i < 14; i++) {
        if (items[i] == ITEM_NONE) {
            break;
        }
        GetItemNameIntoString(string, items[i], HEAP_ID_154);
        PokewalkerApp_PrintString(app, i + 2, string, 0, MAKE_TEXT_COLOR(3, 4, 0));
    }
    String_Delete(string);
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_154);
    return STROLL_REPORT_WAIT_ITEMS_FADE;
}

int PokewalkerApp_StrollReport_WaitItemsFade(PokewalkerApp *app) {
    if (IsPaletteFadeFinished() == TRUE) {
        return STROLL_REPORT_PRINT_ITEMS_PLACED;
    }
    return STROLL_REPORT_WAIT_ITEMS_FADE;
}

int PokewalkerApp_StrollReport_PrintItemsPlaced(PokewalkerApp *app) {
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00050);
    app->nextState = STROLL_REPORT_ITEMS_FADE_OUT;
    PlayFanfare(SEQ_ME_KEYITEM);
    return STROLL_REPORT_WAIT_MESSAGE;
}

int PokewalkerApp_StrollReport_ItemsFadeOut(PokewalkerApp *app) {
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_154);
    return STROLL_REPORT_WAIT_ITEMS_FADE_OUT;
}

int PokewalkerApp_StrollReport_WaitItemsFadeOut(PokewalkerApp *app) {
    if (IsPaletteFadeFinished() == TRUE) {
        return STROLL_REPORT_END;
    }
    return STROLL_REPORT_WAIT_ITEMS_FADE_OUT;
}

int PokewalkerApp_StrollReport_GiftsFadeOut(PokewalkerApp *app) {
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_154);
    return STROLL_REPORT_WAIT_GIFTS_FADE_OUT;
}

int PokewalkerApp_StrollReport_WaitGiftsFadeOut(PokewalkerApp *app) {
    if (IsPaletteFadeFinished() == TRUE) {
        return STROLL_REPORT_SHOW_GIFTS;
    }
    return STROLL_REPORT_WAIT_GIFTS_FADE_OUT;
}

int PokewalkerApp_StrollReport_ShowGifts(PokewalkerApp *app) {
    u32 strollSteps = 0;
    u32 totalSteps;
    u32 totalWatts;
    u32 currentSteps;
    u32 startSteps;

    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 15);
    PokewalkerApp_PrintStringDefaultColor(app, 1, app->giftsReceivedText, 0);
    BufferPokewalkerCourseName(app->msgFormat, 2, (u8)Pokewalker_GetCourse(app->pokewalker));
    currentSteps = app->peerIdentity.steps;
    startSteps = app->walkerSteps;
    if (currentSteps > startSteps) {
        strollSteps = currentSteps - startSteps;
    }
    Pokewalker_GetStepsAndWatts(app->pokewalker, &totalSteps, &totalWatts);
    BufferIntegerAsString(app->msgFormat, 5, strollSteps, 7, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(app->msgFormat, 3, app->irStatus.watts, 5, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(app->msgFormat, 6, totalSteps, 7, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(app->msgFormat, 7, totalWatts, 7, PRINTING_MODE_LEFT_ALIGN, TRUE);
    PokewalkerApp_PrintString(app, 5, app->stepsToDateText, 0, MAKE_TEXT_COLOR(3, 4, 0));
    PokewalkerApp_PrintMessage(app, 6, msg_0274_00060, MAKE_TEXT_COLOR(3, 4, 0));
    PokewalkerApp_PrintString(app, 7, app->wattsToDateText, 0, MAKE_TEXT_COLOR(3, 4, 0));
    PokewalkerApp_PrintMessage(app, 8, msg_0274_00062, MAKE_TEXT_COLOR(3, 4, 0));
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_154);
    return STROLL_REPORT_WAIT_GIFTS_FADE;
}

int PokewalkerApp_StrollReport_WaitGiftsFade(PokewalkerApp *app) {
    if (IsPaletteFadeFinished() == TRUE) {
        return STROLL_REPORT_PRINT_GIFT_WATTS;
    }
    return STROLL_REPORT_WAIT_GIFTS_FADE;
}

int PokewalkerApp_StrollReport_PrintGiftWatts(PokewalkerApp *app) {
    if (app->irStatus.watts == 0) {
        app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00046);
    } else {
        app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00045);
    }
    app->nextState = STROLL_REPORT_PRINT_GIFT_ROUTE_FOUND;
    return STROLL_REPORT_WAIT_MESSAGE;
}

int PokewalkerApp_StrollReport_PrintGiftRouteFound(PokewalkerApp *app) {
    u32 course = app->unlockedCourse;
    if (course != 0) {
        BufferPokewalkerCourseName(app->msgFormat, 4, (u8)course);
        app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00048);
        app->nextState = STROLL_REPORT_GIFTS_DONE_FADE_OUT;
        app->unlockedCourse = 0;
        return STROLL_REPORT_WAIT_MESSAGE;
    }
    return STROLL_REPORT_GIFTS_DONE_FADE_OUT;
}

int PokewalkerApp_StrollReport_GiftsDoneFadeOut(PokewalkerApp *app) {
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_154);
    return STROLL_REPORT_WAIT_GIFTS_DONE_FADE_OUT;
}

int PokewalkerApp_StrollReport_WaitGiftsDoneFadeOut(PokewalkerApp *app) {
    if (IsPaletteFadeFinished() == TRUE) {
        return STROLL_REPORT_SHOW_CAUGHT_MONS;
    }
    return STROLL_REPORT_WAIT_GIFTS_DONE_FADE_OUT;
}

int PokewalkerApp_StrollReport_RecordsFadeOut(PokewalkerApp *app) {
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_154);
    return STROLL_REPORT_WAIT_RECORDS_FADE_OUT;
}

int PokewalkerApp_StrollReport_WaitRecordsFadeOut(PokewalkerApp *app) {
    if (IsPaletteFadeFinished() == TRUE) {
        return STROLL_REPORT_SHOW_RECORDS;
    }
    return STROLL_REPORT_WAIT_RECORDS_FADE_OUT;
}

int PokewalkerApp_StrollReport_ShowRecords(PokewalkerApp *app) {
    u32 strollSteps = 0;
    u32 totalSteps;
    u32 totalWatts;
    u32 currentSteps;
    u32 startSteps;

    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 15);
    PokewalkerApp_PrintStringDefaultColor(app, 1, app->walkerRecordsText, 0);
    BufferPokewalkerCourseName(app->msgFormat, 2, (u8)Pokewalker_GetCourse(app->pokewalker));
    currentSteps = app->peerIdentity.steps;
    startSteps = app->walkerSteps;
    if (currentSteps > startSteps) {
        strollSteps = currentSteps - startSteps;
    }
    Pokewalker_GetStepsAndWatts(app->pokewalker, &totalSteps, &totalWatts);
    BufferIntegerAsString(app->msgFormat, 5, strollSteps, 7, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(app->msgFormat, 3, app->irStatus.watts, 5, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(app->msgFormat, 6, totalSteps, 7, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(app->msgFormat, 7, totalWatts, 7, PRINTING_MODE_LEFT_ALIGN, TRUE);
    PokewalkerApp_PrintString(app, 5, app->stepsToDateText, 0, MAKE_TEXT_COLOR(3, 4, 0));
    PokewalkerApp_PrintMessage(app, 6, msg_0274_00060, MAKE_TEXT_COLOR(3, 4, 0));
    PokewalkerApp_PrintString(app, 7, app->wattsToDateText, 0, MAKE_TEXT_COLOR(3, 4, 0));
    PokewalkerApp_PrintMessage(app, 8, msg_0274_00062, MAKE_TEXT_COLOR(3, 4, 0));
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_154);
    return STROLL_REPORT_WAIT_RECORDS_FADE;
}

int PokewalkerApp_StrollReport_WaitRecordsFade(PokewalkerApp *app) {
    if (IsPaletteFadeFinished() == TRUE) {
        return STROLL_REPORT_PRINT_RECORDS;
    }
    return STROLL_REPORT_WAIT_RECORDS_FADE;
}

int PokewalkerApp_StrollReport_PrintRecords(PokewalkerApp *app) {
    if (app->irStatus.watts == 0) {
        app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00047);
    } else {
        PlayFanfare(SEQ_ME_ITEM);
        app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00045);
    }
    app->nextState = STROLL_REPORT_PRINT_MILESTONE;
    return STROLL_REPORT_WAIT_MESSAGE;
}

int PokewalkerApp_StrollReport_WaitMessage(PokewalkerApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId) && !IsFanfarePlaying()) {
        u32 state = app->nextState;
        app->state = state;
        return state;
    }
    return STROLL_REPORT_WAIT_MESSAGE;
}

int PokewalkerApp_StrollReport_End(PokewalkerApp *app) {
    app->nextMode = POKEWALKER_APP_MODE_MAIN_MENU;
    return STROLL_REPORT_DONE;
}

static PokewalkerBoxDisplay *PokewalkerBoxDisplay_New(enum HeapID heapId) {
    PokewalkerBoxDisplay *display = Heap_Alloc(heapId, sizeof(PokewalkerBoxDisplay));
    MI_CpuFill8(display, 0, sizeof(PokewalkerBoxDisplay));
    display->heapId = heapId;
    display->sprites.heapId = heapId;
    return display;
}

static void PokewalkerBoxDisplay_Init(PokewalkerBoxDisplay *display, BgConfig *bgConfig) {
    display->bgConfig = bgConfig;
    PokewalkerBoxDisplay_LoadBgGraphics(bgConfig, display->heapId);
    AddWindowParameterized(display->bgConfig, &display->windows[BOX_DISPLAY_WIN_SPECIES], GF_BG_LYR_SUB_1, 14, 9, 10, 2, 15, 29);
    AddWindowParameterized(display->bgConfig, &display->windows[BOX_DISPLAY_WIN_LEVEL], GF_BG_LYR_SUB_1, 23, 6, 5, 2, 15, 17);
    AddWindowParameterized(display->bgConfig, &display->windows[BOX_DISPLAY_WIN_ITEM_LABEL], GF_BG_LYR_SUB_1, 14, 12, 8, 2, 15, 49);
    AddWindowParameterized(display->bgConfig, &display->windows[BOX_DISPLAY_WIN_NICKNAME], GF_BG_LYR_SUB_1, 14, 6, 8, 2, 15, 1);
    AddWindowParameterized(display->bgConfig, &display->windows[BOX_DISPLAY_WIN_GENDER], GF_BG_LYR_SUB_1, 22, 6, 1, 2, 15, 27);
    AddWindowParameterized(display->bgConfig, &display->windows[BOX_DISPLAY_WIN_ITEM], GF_BG_LYR_SUB_1, 14, 14, 16, 2, 15, 65);
    display->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0276_bin, display->heapId);
    display->msgFormat = MessageFormat_New(display->heapId);
    display->string = String_New(11, display->heapId);
    PokewalkerBoxDisplay_InitSprites(&display->sprites);
    PokewalkerBoxDisplay_CreateSprites(&display->sprites);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_OFF);
}

static void PokewalkerBoxDisplay_ShowMon(PokewalkerBoxDisplay *display, PokewalkerSelectMonInfo *info) {
    if (info->state == 2) {
        PokewalkerBoxDisplay_ShowMonSprites(display, info);
        PokewalkerBoxDisplay_PrintMonInfo(display, info);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_ON);
    } else {
        PokewalkerBoxDisplay_HideSprites(display);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
    }
}

static void PokewalkerBoxDisplay_Update(PokewalkerBoxDisplay *display) {
    if (display->sprites.spriteList != NULL) {
        SpriteList_RenderAndAnimateSprites(display->sprites.spriteList);
    }
}

static void PokewalkerBoxDisplay_Free(PokewalkerBoxDisplay *display) {
    u8 i;
    PokewalkerBoxDisplaySprites *sprites;

    DestroyMsgData(display->msgData);
    MessageFormat_Delete(display->msgFormat);
    String_Delete(display->string);
    RemoveWindow(&display->windows[0]);
    RemoveWindow(&display->windows[1]);
    RemoveWindow(&display->windows[2]);
    RemoveWindow(&display->windows[3]);
    RemoveWindow(&display->windows[4]);
    RemoveWindow(&display->windows[5]);
    FreeBgTilemapBuffer(display->bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(display->bgConfig, GF_BG_LYR_SUB_3);
    sprites = &display->sprites;
    PokewalkerBoxDisplay_DeleteSprites(sprites);
    for (i = 0; i < 2; i++) {
        SpriteTransfer_DeleteCharTransferTask(sprites->resObjs[i][GF_GFX_RES_TYPE_CHAR]);
        SpriteTransfer_DeletePlttTransferTask(sprites->resObjs[i][GF_GFX_RES_TYPE_PLTT]);
    }
    for (i = 0; i < 6; i++) {
        Destroy2DGfxResObjMan(sprites->resMan[i]);
    }
    SpriteList_Delete(sprites->spriteList);
    Heap_Free(display);
}

static void PokewalkerBoxDisplay_DeleteSprites(PokewalkerBoxDisplaySprites *sprites) {
    int i;
    for (i = 0; i < 6; i++) {
        Sprite_Delete(sprites->markingSprites[i]);
    }
    Sprite_Delete(sprites->monSprite);
    Heap_Free(sprites->monCharData);
}

static void PokewalkerBoxDisplay_LoadBgGraphics(BgConfig *bgConfig, enum HeapID heapId) {
    PokewalkerBoxDisplay_InitBgs(bgConfig);
    GfGfxLoader_GXLoadPal(NARC_a_2_5_7, 0, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, heapId);
    GfGfxLoader_LoadCharData(NARC_a_2_5_7, 1, bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_5_7, 2, bgConfig, GF_BG_LYR_SUB_3, 0, 0x600, TRUE, heapId);
    BgCommitTilemapBufferToVram(bgConfig, GF_BG_LYR_SUB_3);
    LoadFontPal0(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_15_OFFSET, heapId);
}

static void PokewalkerBoxDisplay_InitBgs(BgConfig *bgConfig) {
    {
        BgTemplate template = gBoxDisplayBgTemplateSub1;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &template, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    }
    {
        BgTemplate template = gBoxDisplayBgTemplateSub3;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_3, &template, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_3);
    }
}

static void PokewalkerBoxDisplay_PrintMonInfo(PokewalkerBoxDisplay *display, PokewalkerSelectMonInfo *info) {
    String *string;
    u32 level = info->level;
    u16 heldItem = info->heldItem;
    u32 windowWidth;
    u32 x;

    CopyU16ArrayToString(display->string, info->nickname);
    FillWindowPixelBuffer(&display->windows[BOX_DISPLAY_WIN_NICKNAME], 0);
    AddTextPrinterParameterizedWithColor(&display->windows[BOX_DISPLAY_WIN_NICKNAME], 0, display->string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 0), NULL);
    CopyWindowToVram(&display->windows[BOX_DISPLAY_WIN_NICKNAME]);

    string = GetSpeciesName(info->species, display->heapId);
    BufferString(display->msgFormat, 0, string, 2, 1, 2);
    String_Delete(string);
    string = ReadMsgData_ExpandPlaceholders(display->msgFormat, display->msgData, msg_0276_00000, display->heapId);
    FillWindowPixelBuffer(&display->windows[BOX_DISPLAY_WIN_SPECIES], 0);
    AddTextPrinterParameterizedWithColor(&display->windows[BOX_DISPLAY_WIN_SPECIES], 0, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 0), NULL);
    CopyWindowToVram(&display->windows[BOX_DISPLAY_WIN_SPECIES]);
    String_Delete(string);

    BufferIntegerAsString(display->msgFormat, 0, level, 3, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    string = ReadMsgData_ExpandPlaceholders(display->msgFormat, display->msgData, msg_0276_00003, display->heapId);
    FillWindowPixelBuffer(&display->windows[BOX_DISPLAY_WIN_LEVEL], 0);
    windowWidth = GetWindowWidth(&display->windows[BOX_DISPLAY_WIN_LEVEL]);
    x = FontID_String_GetWidth(0, string, 0);
    x = windowWidth * 8 - x;
    AddTextPrinterParameterizedWithColor(&display->windows[BOX_DISPLAY_WIN_LEVEL], 0, string, x, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 0), NULL);
    CopyWindowToVram(&display->windows[BOX_DISPLAY_WIN_LEVEL]);
    String_Delete(string);

    if (info->gender == MON_MALE) {
        string = NewString_ReadMsgData(display->msgData, msg_0276_00001);
        FillWindowPixelBuffer(&display->windows[BOX_DISPLAY_WIN_GENDER], 0);
        AddTextPrinterParameterizedWithColor(&display->windows[BOX_DISPLAY_WIN_GENDER], 0, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(7, 8, 0), NULL);
        CopyWindowToVram(&display->windows[BOX_DISPLAY_WIN_GENDER]);
        String_Delete(string);
    } else if (info->gender == MON_FEMALE) {
        string = NewString_ReadMsgData(display->msgData, msg_0276_00002);
        FillWindowPixelBuffer(&display->windows[BOX_DISPLAY_WIN_GENDER], 0);
        AddTextPrinterParameterizedWithColor(&display->windows[BOX_DISPLAY_WIN_GENDER], 0, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(3, 4, 0), NULL);
        CopyWindowToVram(&display->windows[BOX_DISPLAY_WIN_GENDER]);
        String_Delete(string);
    } else {
        FillWindowPixelBuffer(&display->windows[BOX_DISPLAY_WIN_GENDER], 0);
        CopyWindowToVram(&display->windows[BOX_DISPLAY_WIN_GENDER]);
    }

    string = NewString_ReadMsgData(display->msgData, msg_0276_00004);
    FillWindowPixelBuffer(&display->windows[BOX_DISPLAY_WIN_ITEM_LABEL], 0);
    AddTextPrinterParameterizedWithColor(&display->windows[BOX_DISPLAY_WIN_ITEM_LABEL], 0, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 0), NULL);
    CopyWindowToVram(&display->windows[BOX_DISPLAY_WIN_ITEM_LABEL]);
    String_Delete(string);

    BufferItemName(display->msgFormat, 0, heldItem);
    string = ReadMsgData_ExpandPlaceholders(display->msgFormat, display->msgData, msg_0276_00005, display->heapId);
    FillWindowPixelBuffer(&display->windows[BOX_DISPLAY_WIN_ITEM], 0);
    AddTextPrinterParameterizedWithColor(&display->windows[BOX_DISPLAY_WIN_ITEM], 0, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 0), NULL);
    CopyWindowToVram(&display->windows[BOX_DISPLAY_WIN_ITEM]);
    String_Delete(string);
}

static void PokewalkerBoxDisplay_ShowMonSprites(PokewalkerBoxDisplay *display, PokewalkerSelectMonInfo *info) {
    u8 i;
    PokewalkerBoxDisplaySprites *sprites = &display->sprites;

    PokewalkerBoxDisplay_LoadMonPicture(sprites, info);
    PokewalkerBoxDisplay_TransferMonPicture(&display->sprites);
    Sprite_SetDrawFlag(display->sprites.monSprite, TRUE);
    for (i = 0; i < 6; i++) {
        if (info->markings[i]) {
            Sprite_SetDrawFlag(sprites->markingSprites[i], TRUE);
            Sprite_SetAnimCtrlSeq(sprites->markingSprites[i], i * 2 + 1);
        } else {
            Sprite_SetDrawFlag(sprites->markingSprites[i], TRUE);
            Sprite_SetAnimCtrlSeq(sprites->markingSprites[i], i * 2);
        }
    }
}

static void PokewalkerBoxDisplay_HideSprites(PokewalkerBoxDisplay *display) {
    u8 i;
    PokewalkerBoxDisplaySprites *sprites = &display->sprites;
    for (i = 0; i < 6; i++) {
        Sprite_SetDrawFlag(sprites->markingSprites[i], FALSE);
    }
    Sprite_SetDrawFlag(sprites->monSprite, FALSE);
}

static void PokewalkerBoxDisplay_InitSprites(PokewalkerBoxDisplaySprites *sprites) {
    int i;

    sprites->spriteList = G2dRenderer_Init(7, &sprites->renderer, sprites->heapId);
    G2dRenderer_SetSubSurfaceCoords(&sprites->renderer, 0, FX32_CONST(256));
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    for (i = 0; i < 6; i++) {
        sprites->resMan[i] = Create2DGfxResObjMan(2, (GfGfxResType)i, sprites->heapId);
    }
    sprites->resObjs[0][GF_GFX_RES_TYPE_CHAR] = AddCharResObjFromNarc(sprites->resMan[GF_GFX_RES_TYPE_CHAR], NARC_a_2_5_7, 4, TRUE, 1, NNS_G2D_VRAM_TYPE_2DSUB, sprites->heapId);
    sprites->resObjs[0][GF_GFX_RES_TYPE_PLTT] = AddPlttResObjFromNarc(sprites->resMan[GF_GFX_RES_TYPE_PLTT], NARC_a_2_5_7, 3, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 4, sprites->heapId);
    sprites->resObjs[0][GF_GFX_RES_TYPE_CELL] = AddCellOrAnimResObjFromNarc(sprites->resMan[GF_GFX_RES_TYPE_CELL], NARC_a_2_5_7, 6, TRUE, 1, GF_GFX_RES_TYPE_CELL, sprites->heapId);
    sprites->resObjs[0][GF_GFX_RES_TYPE_ANIM] = AddCellOrAnimResObjFromNarc(sprites->resMan[GF_GFX_RES_TYPE_ANIM], NARC_a_2_5_7, 5, TRUE, 1, GF_GFX_RES_TYPE_ANIM, sprites->heapId);
    SpriteTransfer_CreateCharTransferTask_AllocAtEnd(sprites->resObjs[0][GF_GFX_RES_TYPE_CHAR]);
    SpriteTransfer_CreateExtPlttTransferTask(sprites->resObjs[0][GF_GFX_RES_TYPE_PLTT]);
    sprites->resObjs[1][GF_GFX_RES_TYPE_CHAR] = AddCharResObjFromNarc(sprites->resMan[GF_GFX_RES_TYPE_CHAR], NARC_application_choose_starter_choose_starter_sub_res, NARC_choose_starter_sub_res_choose_starter_sub_res_00000009_NCGR, FALSE, 2, NNS_G2D_VRAM_TYPE_2DSUB, sprites->heapId);
    sprites->resObjs[1][GF_GFX_RES_TYPE_PLTT] = AddPlttResObjFromNarc(sprites->resMan[GF_GFX_RES_TYPE_PLTT], NARC_application_choose_starter_choose_starter_sub_res, NARC_choose_starter_sub_res_choose_starter_sub_res_00000006_NCLR, FALSE, 2, NNS_G2D_VRAM_TYPE_2DSUB, 4, sprites->heapId);
    sprites->resObjs[1][GF_GFX_RES_TYPE_CELL] = AddCellOrAnimResObjFromNarc(sprites->resMan[GF_GFX_RES_TYPE_CELL], NARC_application_choose_starter_choose_starter_sub_res, NARC_choose_starter_sub_res_choose_starter_sub_res_00000010_NCER, FALSE, 2, GF_GFX_RES_TYPE_CELL, sprites->heapId);
    sprites->resObjs[1][GF_GFX_RES_TYPE_ANIM] = AddCellOrAnimResObjFromNarc(sprites->resMan[GF_GFX_RES_TYPE_ANIM], NARC_application_choose_starter_choose_starter_sub_res, NARC_choose_starter_sub_res_choose_starter_sub_res_00000010_NCER, FALSE, 2, GF_GFX_RES_TYPE_ANIM, sprites->heapId);
    SpriteTransfer_CreateCharTransferTask_AllocAtEnd(sprites->resObjs[1][GF_GFX_RES_TYPE_CHAR]);
    SpriteTransfer_CreateExtPlttTransferTask(sprites->resObjs[1][GF_GFX_RES_TYPE_PLTT]);
}

static void PokewalkerBoxDisplay_CreateSprites(PokewalkerBoxDisplaySprites *sprites) {
    u8 i;
    for (i = 0; i < 6; i++) {
        sprites->markingSprites[i] = PokewalkerBoxDisplay_CreateSprite(sprites, 1, 1, 0, i * 8 + 24, 144, i * 2, FALSE);
    }
    sprites->monSprite = PokewalkerBoxDisplay_CreateSprite(sprites, 2, 0, 0, 48, 88, 0, FALSE);
    sprites->monCharData = Heap_Alloc(sprites->heapId, 0xC80);
    PokewalkerBoxDisplay_GetMonPictureLocation(sprites);
}

static Sprite *PokewalkerBoxDisplay_CreateSprite(PokewalkerBoxDisplaySprites *sprites, int resId, int drawPriority, int priority, int x, int y, int anim, BOOL visible) {
    SpriteTemplate template;
    SpriteResourcesHeader header;
    Sprite *sprite;

    CreateSpriteResourcesHeader(&header, resId, resId, resId, resId, -1, -1, FALSE, priority, sprites->resMan[GF_GFX_RES_TYPE_CHAR], sprites->resMan[GF_GFX_RES_TYPE_PLTT], sprites->resMan[GF_GFX_RES_TYPE_CELL], sprites->resMan[GF_GFX_RES_TYPE_ANIM], NULL, NULL);
    PokewalkerApp_InitSpriteTemplate(&template, sprites->spriteList, &header, NNS_G2D_VRAM_TYPE_2DSUB, sprites->heapId);
    template.drawPriority = drawPriority;
    template.position.x = x << FX32_SHIFT;
    template.position.y = (y << FX32_SHIFT) + FX32_CONST(256);
    sprite = Sprite_CreateAffine(&template);
    Sprite_SetAnimActiveFlag(sprite, TRUE);
    Sprite_SetAnimCtrlSeq(sprite, anim);
    Sprite_SetPriority(sprite, 1);
    Sprite_SetDrawFlag(sprite, visible);
    return sprite;
}

static void PokewalkerApp_InitSpriteTemplate(SpriteTemplate *template, SpriteList *spriteList, const SpriteResourcesHeader *header, NNS_G2D_VRAM_TYPE whichScreen, enum HeapID heapId) {
    template->spriteList = spriteList;
    template->header = header;
    template->position.z = 0;
    template->scale.x = FX32_ONE;
    template->scale.y = FX32_ONE;
    template->scale.z = FX32_ONE;
    template->rotation = 0;
    template->drawPriority = 0;
    template->whichScreen = whichScreen;
    template->heapID = heapId;
}
