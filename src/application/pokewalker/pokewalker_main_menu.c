// Pokewalker connection app, mode 0: the main menu.

#include "global.h"

#include "application/pokewalker/pokewalker_app.h"
#include "application/pokewalker/pokewalker_app_internal.h"
#include "msgdata/msg/msg_0274.h"

#include "message_format.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "save_arrays.h"
#include "screen_fade.h"
#include "sound.h"
#include "sound_playback.h"
#include "sound_system.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"

static BOOL PokewalkerApp_IsDownXLHeld(void);
static BOOL PokewalkerApp_IsUpSelectRHeld(void);
static void PokewalkerApp_MainMenu_StartEraseRecords(PokewalkerApp *app, int bank);
static BOOL PokewalkerApp_MainMenu_TrySendMonBack(PokewalkerApp *app, int bank);
static void PokewalkerApp_ShowWalkerRecords(PokewalkerApp *app, BOOL onStroll);

enum MainMenuState {
    MAIN_MENU_START,
    MAIN_MENU_WAIT_FADE,
    MAIN_MENU_SHOW_TOP_MENU,
    MAIN_MENU_HANDLE_TOP_MENU,
    MAIN_MENU_PRINT_WELCOME,
    MAIN_MENU_WAIT_WELCOME,
    MAIN_MENU_PRINT_STROLL_READY,
    MAIN_MENU_SHOW_STROLL_MENU,
    MAIN_MENU_HANDLE_STROLL_MENU,
    MAIN_MENU_END_STROLL_MENU,
    MAIN_MENU_PRINT_RECEIVE,
    MAIN_MENU_WAIT_RECEIVE,
    MAIN_MENU_SHOW_RECEIVE_MENU,
    MAIN_MENU_HANDLE_RECEIVE_MENU,
    MAIN_MENU_END_RECEIVE_MENU,
    MAIN_MENU_PRINT_STROLL_READY2,
    MAIN_MENU_WAIT_STROLL_READY2,
    MAIN_MENU_SHOW_FULL_MENU,
    MAIN_MENU_HANDLE_FULL_MENU,
    MAIN_MENU_END_FULL_MENU,
    MAIN_MENU_PRINT_BOXES_FULL,
    MAIN_MENU_WAIT_BOXES_FULL,
    MAIN_MENU_QUIT,
    MAIN_MENU_PRINT_NO_POKEMON,
    MAIN_MENU_WAIT_MESSAGE,
    MAIN_MENU_WAIT_CURSOR,
    MAIN_MENU_END,
    MAIN_MENU_DONE,
};

enum PokewalkerAppState PokewalkerApp_MainMenu_Enter(PokewalkerApp *app) {
    Sound_SetSceneAndPlayBGM(73, SEQ_GS_PHC, 0);
    PlayBGM(SEQ_GS_PHC);
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_MainMenu_Update(PokewalkerApp *app) {
    app->state = gMainMenuStates[app->state](app);
    if (app->state == MAIN_MENU_DONE) {
        app->state = 0;
        return POKEWALKER_APP_STATE_EXIT;
    }
    return POKEWALKER_APP_STATE_UPDATE;
}

enum PokewalkerAppState PokewalkerApp_MainMenu_Exit(PokewalkerApp *app) {
    return POKEWALKER_APP_STATE_ENTER;
}

int PokewalkerApp_MainMenu_Start(PokewalkerApp *app) {
    struct {
        u16 unk2;
        u16 strollState;
    } walkerState;
    PCStorage *storage = SaveArray_PCStorage_Get(app->saveData);
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_154);
    if (PCStorage_CountEmptySpotsInAllBoxes(storage) < 5) {
        PokewalkerApp_RemoveWindowBank(app, 3);
        PokewalkerApp_AddWindowBank(app, 1);
        return MAIN_MENU_PRINT_BOXES_FULL;
    }
    if (PCStorage_CountMonsInAllBoxes(storage) == 0 && Pokewalker_GetLinkCount(app->pokewalker) == 0) {
        PokewalkerApp_RemoveWindowBank(app, 3);
        PokewalkerApp_AddWindowBank(app, 1);
        return MAIN_MENU_PRINT_NO_POKEMON;
    }
    Pokewalker_GetStrollState(app->pokewalker, &walkerState.strollState, &walkerState.unk2);
    switch (walkerState.strollState) {
    case 0:
        app->nextMode = POKEWALKER_APP_MODE_LINK;
        app->selectMon.species = SPECIES_NONE;
        app->linkAction = POKEWALKER_LINK_GO_FOR_STROLL;
        PokewalkerApp_RemoveWindowBank(app, 3);
        PokewalkerApp_AddWindowBank(app, 1);
        FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
        BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
        Pokewalker_SetStrollState(app->pokewalker, 0, 0);
        return MAIN_MENU_PRINT_WELCOME;
    case 1:
        app->selectMon.species = SPECIES_NONE;
        app->linkAction = POKEWALKER_LINK_GO_FOR_STROLL;
        PokewalkerApp_RemoveWindowBank(app, 3);
        PokewalkerApp_AddWindowBank(app, 7);
        FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
        BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
        PokewalkerApp_ShowWalkerRecords(app, FALSE);
        return MAIN_MENU_PRINT_STROLL_READY2;
    case 2:
        PokewalkerApp_RemoveWindowBank(app, 3);
        PokewalkerApp_AddWindowBank(app, 1);
        FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
        BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
        PokewalkerApp_ShowWalkerRecords(app, TRUE);
        return MAIN_MENU_PRINT_RECEIVE;
    }
    return MAIN_MENU_WAIT_FADE;
}

// Sub screen: total watts and steps, watts needed for the next course, and the Pokemon on a Stroll.
static void PokewalkerApp_ShowWalkerRecords(PokewalkerApp *app, BOOL onStroll) {
    u32 steps, watts;
    int wattsNeeded;
    Pokemon *mon;
    BoxPokemon *boxMon;
    Pokewalker_GetStepsAndWatts(app->pokewalker, &steps, &watts);
    BufferIntegerAsString(app->msgFormat, 7, watts, 7, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(app->msgFormat, 6, steps, 7, PRINTING_MODE_LEFT_ALIGN, TRUE);
    wattsNeeded = PokewalkerApp_GetWattsToNextCourse(app, watts);
    BufferIntegerAsString(app->msgFormat, 12, wattsNeeded, 7, PRINTING_MODE_LEFT_ALIGN, TRUE);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_SUB_1, 16);
    PokewalkerApp_ShowSubBg1(app, TRUE);
    app->subBgScrollX = 0;
    PokewalkerApp_PrintSubString(app, 1, app->totalWattsText, 0, MAKE_TEXT_COLOR(1, 2, 0));
    PokewalkerApp_PrintSubMessage(app, 2, msg_0274_00083, MAKE_TEXT_COLOR(1, 2, 0));
    PokewalkerApp_PrintSubString(app, 3, app->totalStepsText, 0, MAKE_TEXT_COLOR(1, 2, 0));
    PokewalkerApp_PrintSubMessage(app, 4, msg_0274_00084, MAKE_TEXT_COLOR(1, 2, 0));
    if (wattsNeeded < 0) {
        PokewalkerApp_PrintSubMessage(app, 0, msg_0274_00088, MAKE_TEXT_COLOR(1, 2, 0));
    } else if (wattsNeeded == 0) {
        PokewalkerApp_PrintSubMessage(app, 0, msg_0274_00087, MAKE_TEXT_COLOR(1, 2, 0));
    } else {
        PokewalkerApp_PrintSubMessage(app, 0, msg_0274_00086, MAKE_TEXT_COLOR(1, 2, 0));
    }
    if (onStroll) {
        mon = AllocMonZeroed(HEAP_ID_154);
        boxMon = Mon_GetBoxMon(mon);
        Pokewalker_TryGetBoxMon(app->pokewalker, boxMon);
        BufferBoxMonNickname(app->msgFormat, 13, boxMon);
        PokewalkerApp_PrintSubMessage(app, 5, msg_0274_00089, MAKE_TEXT_COLOR(3, 4, 0));
        PokewalkerApp_LoadMonPicture(boxMon, app->monSpriteBuffer, &app->monPicTemplate, 1);
        PokewalkerApp_ShowSprite(app, 7);
        Heap_Free(mon);
    } else {
        PokewalkerApp_HideSprite(app, 7);
        FillWindowPixelBuffer(&app->subWindows[5], 0);
        CopyWindowToVram(&app->subWindows[5]);
    }
    PokewalkerApp_HideConnectionSprites(app);
}

int PokewalkerApp_MainMenu_WaitFade(PokewalkerApp *app) {
    return IsPaletteFadeFinished() == TRUE ? MAIN_MENU_PRINT_WELCOME : MAIN_MENU_SHOW_TOP_MENU;
}

// Top menu: 6 items (cursor positions gTopMenuCursorPositions).
int PokewalkerApp_MainMenu_ShowTopMenu(PokewalkerApp *app) {
    int i;

    PokewalkerApp_RemoveWindowBank(app, 1);
    PokewalkerApp_AddWindowBank(app, 3);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_SUB_1, 17);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 23);
    for (i = 0; i < 4; i++) {
        String *string = NewString_ReadMsgData(app->msgData, msg_0274_00152 + i);
        PokewalkerApp_PrintString(app, i, string, 4, MAKE_TEXT_COLOR(15, 1, 0));
        String_Delete(string);
    }
    PokewalkerApp_PrintExit(app, 6);
    app->menuSelection = 0;
    PokewalkerApp_SetCursorPosition(app, gTopMenuCursorPositions[app->menuSelection]);
    return MAIN_MENU_HANDLE_TOP_MENU;
}

int PokewalkerApp_MainMenu_HandleTopMenu(PokewalkerApp *app) {
    u32 keys = gSystem.newKeys;

    if (keys & PAD_KEY_UP) {
        if (app->menuSelection > 0) {
            app->menuSelection--;
        }
        PokewalkerApp_SetCursorPosition(app, gTopMenuCursorPositions[app->menuSelection]);
    } else if (keys & PAD_KEY_DOWN) {
        if (app->menuSelection < 5) {
            app->menuSelection++;
        }
        PokewalkerApp_SetCursorPosition(app, gTopMenuCursorPositions[app->menuSelection]);
    } else if (keys & PAD_BUTTON_A) {
        switch (app->menuSelection) {
        case 0:
            app->nextMode = POKEWALKER_APP_MODE_ERASE_RECORDS;
            Pokewalker_SetStrollState(app->pokewalker, 0, 0);
            PokewalkerApp_RemoveWindowBank(app, 3);
            PokewalkerApp_AddWindowBank(app, 1);
            FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
            BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
            return MAIN_MENU_END;
        case 1:
            app->nextMode = POKEWALKER_APP_MODE_LINK;
            app->selectMon.species = SPECIES_NONE;
            app->linkAction = POKEWALKER_LINK_GO_FOR_STROLL;
            PokewalkerApp_RemoveWindowBank(app, 3);
            PokewalkerApp_AddWindowBank(app, 1);
            FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
            BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
            Pokewalker_SetStrollState(app->pokewalker, 0, 0);
            return MAIN_MENU_PRINT_WELCOME;
        case 2:
            Pokewalker_SetStrollState(app->pokewalker, 1, 1);
            app->selectMon.species = SPECIES_NONE;
            app->linkAction = POKEWALKER_LINK_GO_FOR_STROLL;
            PokewalkerApp_RemoveWindowBank(app, 3);
            PokewalkerApp_AddWindowBank(app, 7);
            FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
            BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
            return MAIN_MENU_PRINT_STROLL_READY2;
        case 3:
            PokewalkerApp_RemoveWindowBank(app, 3);
            PokewalkerApp_AddWindowBank(app, 1);
            FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
            BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
            return MAIN_MENU_PRINT_RECEIVE;
        case 4:
            PokewalkerApp_RemoveWindowBank(app, 3);
            PokewalkerApp_AddWindowBank(app, 1);
            FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
            BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
            return MAIN_MENU_PRINT_STROLL_READY2;
        }
    }
    return MAIN_MENU_HANDLE_TOP_MENU;
}

int PokewalkerApp_MainMenu_PrintWelcome(PokewalkerApp *app) {
    PokewalkerApp_StartMessage(app, 2, msg_0274_00000, MAIN_MENU_PRINT_STROLL_READY);
    return MAIN_MENU_WAIT_MESSAGE;
}

int PokewalkerApp_MainMenu_WaitWelcome(PokewalkerApp *app) {
    return !TextPrinterCheckActive(app->textPrinterId) ? MAIN_MENU_SHOW_STROLL_MENU : MAIN_MENU_WAIT_WELCOME;
}

int PokewalkerApp_MainMenu_PrintStrollReady(PokewalkerApp *app) {
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
    PokewalkerApp_StartMessage(app, 0, msg_0274_00008, MAIN_MENU_SHOW_STROLL_MENU);
    return MAIN_MENU_WAIT_MESSAGE;
}

// "Save, then go for a Stroll" / exit.
int PokewalkerApp_MainMenu_ShowStrollMenu(PokewalkerApp *app) {
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 10);
    PokewalkerApp_PrintString(app, 5, app->saveAndStrollText, 4, MAKE_TEXT_COLOR(15, 1, 0));
    PokewalkerApp_PrintExit(app, 1);
    app->menuSelection = 0;
    PokewalkerApp_SetCursorPosition(app, 2);
    return MAIN_MENU_HANDLE_STROLL_MENU;
}

int PokewalkerApp_MainMenu_HandleStrollMenu(PokewalkerApp *app) {
    int selection = PokewalkerApp_GetTouchedButton(1);
    if (selection != TOUCH_MENU_NO_INPUT) {
        PokewalkerApp_SelectMenuItem(app, selection, selection + 2, 9);
        PlaySE(SEQ_SE_DP_DECIDE);
        return MAIN_MENU_WAIT_CURSOR;
    }
    if (gSystem.newKeys & PAD_KEY_UP) {
        if (app->menuSelection != 0) {
            PlaySE(SEQ_SE_DP_SELECT);
        }
        PokewalkerApp_SetCursorPosition(app, 2);
        app->menuSelection = 0;
    } else if (gSystem.newKeys & PAD_KEY_DOWN) {
        if (app->menuSelection != 1) {
            PlaySE(SEQ_SE_DP_SELECT);
        }
        PokewalkerApp_SetCursorPosition(app, 3);
        app->menuSelection = 1;
    } else if (gSystem.newKeys & PAD_BUTTON_A) {
        PlaySE(SEQ_SE_DP_DECIDE);
        selection = app->menuSelection;
        PokewalkerApp_SelectMenuItem(app, selection, selection + 2, 9);
        return MAIN_MENU_WAIT_CURSOR;
    } else if (gSystem.newKeys & PAD_BUTTON_B) {
        PlaySE(SEQ_SE_DP_DECIDE);
        PokewalkerApp_SelectMenuItem(app, 1, 3, 9);
        return MAIN_MENU_WAIT_CURSOR;
    } else if (PokewalkerApp_IsDownXLHeld()) {
        PlaySE(SEQ_SE_DP_SELECT);
        PokewalkerApp_MainMenu_StartEraseRecords(app, 3);
        return MAIN_MENU_END;
    } else if (PokewalkerApp_IsUpSelectRHeld() && PokewalkerApp_MainMenu_TrySendMonBack(app, 3)) {
        PlaySE(SEQ_SE_DP_SELECT);
        return MAIN_MENU_END;
    }
    return MAIN_MENU_HANDLE_STROLL_MENU;
}

int PokewalkerApp_MainMenu_EndStrollMenu(PokewalkerApp *app) {
    PokewalkerApp_HideCursor(app);
    if (app->menuSelection == 0) {
        app->nextMode = POKEWALKER_APP_MODE_LINK;
    } else {
        app->nextMode = POKEWALKER_APP_MODE_EXIT;
    }
    return MAIN_MENU_END;
}

int PokewalkerApp_MainMenu_PrintReceive(PokewalkerApp *app) {
    PokewalkerApp_StartMessage(app, 0, msg_0274_00002, MAIN_MENU_SHOW_RECEIVE_MENU);
    return MAIN_MENU_WAIT_MESSAGE;
}

int PokewalkerApp_MainMenu_WaitReceive(PokewalkerApp *app) {
    return !TextPrinterCheckActive(app->textPrinterId) ? MAIN_MENU_SHOW_RECEIVE_MENU : MAIN_MENU_WAIT_RECEIVE;
}

// "Return from a Stroll" / "Receive a gift" / exit.
int PokewalkerApp_MainMenu_ShowReceiveMenu(PokewalkerApp *app) {
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 11);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_SUB_1, 16);
    PokewalkerApp_PrintString(app, 3, app->returnFromStrollText, 4, MAKE_TEXT_COLOR(15, 1, 0));
    PokewalkerApp_PrintString(app, 4, app->receiveGiftText, 4, MAKE_TEXT_COLOR(15, 1, 0));
    PokewalkerApp_PrintExit(app, 1);
    app->menuSelection = 0;
    PokewalkerApp_SetCursorPosition(app, gReceiveMenuCursorPositions[app->menuSelection]);
    return MAIN_MENU_HANDLE_RECEIVE_MENU;
}

int PokewalkerApp_MainMenu_HandleReceiveMenu(PokewalkerApp *app) {
    int selection = PokewalkerApp_GetTouchedButton(2);
    if (selection != TOUCH_MENU_NO_INPUT) {
        PokewalkerApp_SelectMenuItem(app, selection, gReceiveMenuCursorPositions[selection], 14);
        PlaySE(SEQ_SE_DP_DECIDE);
        return MAIN_MENU_WAIT_CURSOR;
    }
    if (gSystem.newKeys & PAD_KEY_UP) {
        if (app->menuSelection != 0) {
            PlaySE(SEQ_SE_DP_SELECT);
            --app->menuSelection;
        }
        PokewalkerApp_SetCursorPosition(app, gReceiveMenuCursorPositions[app->menuSelection]);
    } else if (gSystem.newKeys & PAD_KEY_DOWN) {
        if (app->menuSelection < 2) {
            PlaySE(SEQ_SE_DP_SELECT);
            ++app->menuSelection;
        }
        PokewalkerApp_SetCursorPosition(app, gReceiveMenuCursorPositions[app->menuSelection]);
    } else if (gSystem.newKeys & PAD_BUTTON_A) {
        PlaySE(SEQ_SE_DP_DECIDE);
        PokewalkerApp_SelectMenuItem(app, app->menuSelection, gReceiveMenuCursorPositions[app->menuSelection], 14);
        return MAIN_MENU_WAIT_CURSOR;
    } else if (gSystem.newKeys & PAD_BUTTON_B) {
        PlaySE(SEQ_SE_DP_SELECT);
        PokewalkerApp_SelectMenuItem(app, 2, 3, 14);
        return MAIN_MENU_WAIT_CURSOR;
    } else if (PokewalkerApp_IsDownXLHeld()) {
        PlaySE(SEQ_SE_DP_SELECT);
        PokewalkerApp_MainMenu_StartEraseRecords(app, 3);
        return MAIN_MENU_END;
    } else if (PokewalkerApp_IsUpSelectRHeld()) {
        if (PokewalkerApp_MainMenu_TrySendMonBack(app, 3)) {
            PlaySE(SEQ_SE_DP_SELECT);
            return MAIN_MENU_END;
        }
    }
    return MAIN_MENU_HANDLE_RECEIVE_MENU;
}

int PokewalkerApp_MainMenu_EndReceiveMenu(PokewalkerApp *app) {
    PokewalkerApp_HideCursor(app);
    switch (app->menuSelection) {
    case 0:
        app->nextMode = POKEWALKER_APP_MODE_LINK;
        app->linkAction = POKEWALKER_LINK_RETURN_FROM_STROLL;
        break;
    case 1:
        app->nextMode = POKEWALKER_APP_MODE_LINK;
        app->linkAction = POKEWALKER_LINK_RECEIVE_GIFT;
        break;
    case 2:
        app->nextMode = POKEWALKER_APP_MODE_EXIT;
        break;
    default:
        GF_ASSERT((s32)app->menuSelection < 3);
        break;
    }
    return MAIN_MENU_END;
}

int PokewalkerApp_MainMenu_PrintStrollReady2(PokewalkerApp *app) {
    PokewalkerApp_StartMessage(app, 0, msg_0274_00008, MAIN_MENU_SHOW_FULL_MENU);
    return MAIN_MENU_WAIT_MESSAGE;
}

int PokewalkerApp_MainMenu_WaitStrollReady2(PokewalkerApp *app) {
    return !TextPrinterCheckActive(app->textPrinterId) ? MAIN_MENU_SHOW_FULL_MENU : MAIN_MENU_WAIT_STROLL_READY2;
}

// "Go for a Stroll" / "Receive a gift" / "Return from a Stroll" / exit.
int PokewalkerApp_MainMenu_ShowFullMenu(PokewalkerApp *app) {
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 12);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_SUB_1, 16);
    PokewalkerApp_PrintString(app, 3, app->goForStrollText, 4, MAKE_TEXT_COLOR(15, 1, 0));
    PokewalkerApp_PrintString(app, 4, app->receiveGiftText, 4, MAKE_TEXT_COLOR(15, 1, 0));
    PokewalkerApp_PrintString(app, 5, app->returnFromStrollText, 4, MAKE_TEXT_COLOR(15, 1, 0));
    PokewalkerApp_PrintExit(app, 1);
    app->menuSelection = 0;
    PokewalkerApp_SetCursorPosition(app, gFullMenuCursorPositions[app->menuSelection]);
    return MAIN_MENU_HANDLE_FULL_MENU;
}

int PokewalkerApp_MainMenu_HandleFullMenu(PokewalkerApp *app) {
    int selection = PokewalkerApp_GetTouchedButton(3);
    if (selection != TOUCH_MENU_NO_INPUT) {
        PokewalkerApp_SelectMenuItem(app, selection, gFullMenuCursorPositions[selection], 19);
        PlaySE(SEQ_SE_DP_DECIDE);
        return MAIN_MENU_WAIT_CURSOR;
    }
    if (gSystem.newKeys & PAD_KEY_UP) {
        if (app->menuSelection != 0) {
            PlaySE(SEQ_SE_DP_SELECT);
            app->menuSelection--;
        }
        PokewalkerApp_SetCursorPosition(app, gFullMenuCursorPositions[app->menuSelection]);
    } else if (gSystem.newKeys & PAD_KEY_DOWN) {
        if (app->menuSelection < 3) {
            PlaySE(SEQ_SE_DP_SELECT);
            app->menuSelection++;
        }
        PokewalkerApp_SetCursorPosition(app, gFullMenuCursorPositions[app->menuSelection]);
    } else if (gSystem.newKeys & PAD_BUTTON_A) {
        PlaySE(SEQ_SE_DP_DECIDE);
        selection = app->menuSelection;
        PokewalkerApp_SelectMenuItem(app, selection, gFullMenuCursorPositions[selection], 19);
        return MAIN_MENU_WAIT_CURSOR;
    } else if (gSystem.newKeys & PAD_BUTTON_B) {
        PlaySE(SEQ_SE_DP_SELECT);
        PokewalkerApp_SelectMenuItem(app, 3, 3, 19);
        return MAIN_MENU_WAIT_CURSOR;
    } else if (PokewalkerApp_IsDownXLHeld()) {
        PlaySE(SEQ_SE_DP_SELECT);
        PokewalkerApp_MainMenu_StartEraseRecords(app, 7);
        return MAIN_MENU_END;
    } else if (PokewalkerApp_IsUpSelectRHeld() && PokewalkerApp_MainMenu_TrySendMonBack(app, 3)) {
        PlaySE(SEQ_SE_DP_SELECT);
        return MAIN_MENU_END;
    }
    return MAIN_MENU_HANDLE_FULL_MENU;
}

int PokewalkerApp_MainMenu_EndFullMenu(PokewalkerApp *app) {
    PokewalkerApp_HideCursor(app);
    switch (app->menuSelection) {
    case 0:
        app->nextMode = POKEWALKER_APP_MODE_LINK;
        app->linkAction = POKEWALKER_LINK_GO_FOR_STROLL;
        break;
    case 1:
        app->nextMode = POKEWALKER_APP_MODE_LINK;
        app->linkAction = POKEWALKER_LINK_RETURN_FROM_STROLL;
        break;
    case 2:
        app->nextMode = POKEWALKER_APP_MODE_LINK;
        app->linkAction = POKEWALKER_LINK_RECEIVE_GIFT;
        break;
    case 3:
        app->nextMode = POKEWALKER_APP_MODE_EXIT;
        break;
    default:
        GF_ASSERT(app->menuSelection < 4);
        break;
    }
    return MAIN_MENU_END;
}

int PokewalkerApp_MainMenu_PrintBoxesFull(PokewalkerApp *app) {
    PokewalkerApp_HideCursor(app);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_2);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
    PokewalkerApp_StartMessage(app, 2, msg_0274_00015, MAIN_MENU_QUIT);
    return MAIN_MENU_WAIT_MESSAGE;
}

int PokewalkerApp_MainMenu_WaitBoxesFull(PokewalkerApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId)) {
        app->nextMode = POKEWALKER_APP_MODE_EXIT;
        return MAIN_MENU_END;
    }
    return MAIN_MENU_WAIT_BOXES_FULL;
}

int PokewalkerApp_MainMenu_Quit(PokewalkerApp *app) {
    app->nextMode = POKEWALKER_APP_MODE_EXIT;
    return MAIN_MENU_END;
}

int PokewalkerApp_MainMenu_PrintNoPokemon(PokewalkerApp *app) {
    PokewalkerApp_HideCursor(app);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_2);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
    PokewalkerApp_StartMessage(app, 2, msg_0274_00022, MAIN_MENU_QUIT);
    return MAIN_MENU_WAIT_MESSAGE;
}

// Waits for the message, then goes to nextState.
int PokewalkerApp_MainMenu_WaitMessage(PokewalkerApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId)) {
        app->state = app->nextState;
        return app->state;
    }
    return MAIN_MENU_WAIT_MESSAGE;
}

// Waits for the cursor animation, then goes to nextState.
int PokewalkerApp_MainMenu_WaitCursor(PokewalkerApp *app) {
    if (!ManagedSprite_IsAnimated(app->sprites[0])) {
        app->state = app->nextState;
        return app->state;
    }
    return MAIN_MENU_WAIT_CURSOR;
}

int PokewalkerApp_MainMenu_End(PokewalkerApp *app) {
    return MAIN_MENU_DONE;
}

static void PokewalkerApp_MainMenu_StartEraseRecords(PokewalkerApp *app, int bank) {
    app->nextMode = POKEWALKER_APP_MODE_ERASE_RECORDS;
    PokewalkerApp_RemoveWindowBank(app, bank);
    PokewalkerApp_AddWindowBank(app, 1);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
    PokewalkerApp_HideCursor(app);
}

static BOOL PokewalkerApp_MainMenu_TrySendMonBack(PokewalkerApp *app, int bank) {
    struct {
        u16 unk2;
        u16 strollState;
    } walkerState;
    Pokewalker_GetStrollState(app->pokewalker, &walkerState.strollState, &walkerState.unk2);
    if (walkerState.strollState != 2) {
        return FALSE;
    }
    app->nextMode = POKEWALKER_APP_MODE_LINK;
    app->linkAction = POKEWALKER_LINK_SEND_MON_BACK;
    PokewalkerApp_RemoveWindowBank(app, bank);
    PokewalkerApp_AddWindowBank(app, 1);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
    PokewalkerApp_HideCursor(app);
    return TRUE;
}

static BOOL PokewalkerApp_IsDownXLHeld(void) {
    u32 keys = gSystem.heldKeys;
    return (keys & PAD_KEY_DOWN) && (keys & PAD_BUTTON_X) && (keys & PAD_BUTTON_L);
}

static BOOL PokewalkerApp_IsUpSelectRHeld(void) {
    u32 keys = gSystem.heldKeys;
    return (keys & PAD_KEY_UP) && (keys & PAD_BUTTON_SELECT) && (keys & PAD_BUTTON_R);
}
