#include "application/main_menu/main_menu.h"

#include "global.h"

#include "application/main_menu/agb_cartridge.h"
#include "application/main_menu/main_menu_internal.h"
#include "application/main_menu/main_menu_shared.h"
#include "application/main_menu/main_menu_util.h"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0017.h"
#include "msgdata/msg/msg_0442.h"
#include "msgdata/msg/msg_0800.h"

#include "bg_window.h"
#include "comm_state_internal.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "main.h"
#include "menu_input_state.h"
#include "msgdata.h"
#include "mystery_gift.h"
#include "overlay_36.h"
#include "player_data.h"
#include "pokedex.h"
#include "render_window.h"
#include "sav_system_info.h"
#include "save.h"
#include "save_arrays.h"
#include "save_data_read_error.h"
#include "screen_fade.h"
#include "sound.h"
#include "sound_system.h"
#include "sprite.h"
#include "system.h"
#include "text.h"
#include "title_screen.h"
#include "touchscreen.h"
#include "sound_playback.h"
#include "oam_manager.h"
#include "vram_transfer_manager.h"

typedef enum MainMenu_AppOption {
    APPOPTION_TITLE_SCREEN,
    APPOPTION_CONTINUE,
    APPOPTION_NEW_GAME,
    APPOPTION_POKEWALKER,
    APPOPTION_MYSTERY_GIFT,
    APPOPTION_RANGER,
    APPOPTION_MIGRATE_AGB,
    APPOPTION_CONNECT_TO_WII,
    APPOPTION_WFC,
    APPOPTION_WII_SETTINGS,

    APPOPTION_COUNT = APPOPTION_WII_SETTINGS,
} MainMenu_AppOption;

typedef struct MainMenuAppData {
    BgConfig *bgConfig;
    SaveData *saveData;
    Pokedex *pokedex;
    PlayerProfile *profile;
    IGT *igt;
    MysteryGiftSave *mysteryGift;
    u32 frames; // actual purpose unknown, this is incremented in the main function but never read anywhere
    u32 unused1C;
    u32 windowBaseTile;
    u32 connectedAgbGame;
    u32 unused28;
    BOOL drawConnectToRangerButton;
    BOOL drawConnectToWiiButton;
    BOOL drawMysteryGiftButton;
    u32 wirelessButtonsShown;
    u32 unused3C;
    u32 raisedNotices;
    u32 shownNotices;
    BOOL redrawOptions;
    BOOL hasPokedex;
    u32 badges;
    u16 currentOption;
    u16 currentNewGameOption;
    MainMenu_AppOption selectedApp;
    Window optionWindows[APPOPTION_COUNT];
    u32 optionIds[APPOPTION_COUNT];
    u32 wirelessIconTypes[APPOPTION_COUNT];
    fx32 currentScreenY;
    fx32 effectiveScreenY;
    u32 beaconWatchState;
    u32 beaconWatchTimer;
    u32 noticeState;
    u32 noticeDelay;
    u32 noticeInputDelay;
    u32 noticeInput;
    Window noticeWindow;
    Window newGameOptionWindows[2];
    BOOL dontHaveSavedata;
    BOOL noticePending;
    u32 warningPending[1];
    Window warningWindow;
    Sprite *upArrowSprite;
    Sprite *downArrowSprite;
    u32 buttonBorderAnimFrame;
    MenuInputStateMgr menuInputState;
    int shownOptionCount;
    u32 optionChangeTimer;
} MainMenuAppData;

typedef BOOL (*MainMenuPrintFunction)(MainMenuAppData *, u32, MainMenuTextPrinter *, u32);

typedef struct MainMenuButton {
    MainMenu_AppOption id;
    u32 height;
    u32 msgId;
    MainMenuPrintFunction printFunction;
} MainMenuButton;

extern void Sound_SetBGMPlayerChannels(u32 mode);
extern void SystemCard_RebootIntoFile(const char *path);

extern BOOL CTRDG_IsExisting();

static void MainMenu_HighlightOption(MainMenuAppData *data, int currentOption);
static void MainMenu_HighlightNewGameOption(MainMenuAppData *data, int selection);
static BOOL ChangeCurrentAppOption(MainMenuAppData *data, int offset);
static void MainMenu_ScrollToOption(MainMenuAppData *data, int option);
static void MainMenu_UpdateArrowSprites(MainMenuAppData *data);
static void AdvanceButtonBorderAnimation(MainMenuAppData *data);

static BOOL MainMenu_PrintContinueButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y);
static BOOL MainMenu_PrintMigrateFromAgbButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y);
static BOOL MainMenu_PrintMysteryGiftButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y);
static BOOL MainMenu_PrintConnectToRangerButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y);
static BOOL MainMenu_PrintConnectToWiiButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y);
static BOOL MainMenu_PrintNintendoWFCSetupButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y);
static BOOL MainMenu_PrintConnectToPokewalkerButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y);
static BOOL MainMenu_PrintWiiMessageSettingsButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y);

static MainMenuButton sMainMenuButtons[] = {
    { .id = APPOPTION_CONTINUE,       .height = 10, .msgId = msg_0442_00000, .printFunction = MainMenu_PrintContinueButton            },
    { .id = APPOPTION_NEW_GAME,       .height = 4,  .msgId = msg_0442_00001, .printFunction = NULL                                    },
    { .id = APPOPTION_POKEWALKER,     .height = 4,  .msgId = msg_0442_00009, .printFunction = MainMenu_PrintConnectToPokewalkerButton },
    { .id = APPOPTION_MYSTERY_GIFT,   .height = 4,  .msgId = msg_0442_00002, .printFunction = MainMenu_PrintMysteryGiftButton         },
    { .id = APPOPTION_RANGER,         .height = 4,  .msgId = msg_0442_00003, .printFunction = MainMenu_PrintConnectToRangerButton     },
    { .id = APPOPTION_MIGRATE_AGB,    .height = 4,  .msgId = 0,              .printFunction = MainMenu_PrintMigrateFromAgbButton      }, // msgId can be 4, 5, 6, 7 or 8 depending on the inserted cartridge
    { .id = APPOPTION_CONNECT_TO_WII, .height = 4,  .msgId = msg_0442_00011, .printFunction = MainMenu_PrintConnectToWiiButton        },
    { .id = APPOPTION_WFC,            .height = 4,  .msgId = msg_0442_00012, .printFunction = MainMenu_PrintNintendoWFCSetupButton    },
    { .id = APPOPTION_WII_SETTINGS,   .height = 4,  .msgId = msg_0442_00010, .printFunction = MainMenu_PrintWiiMessageSettingsButton  },
};

static const TouchscreenHitbox sNewGameButtonHitboxes[] = {
    { .rect = { .top = 112, .bottom = 112 + 24, .left = 32, .right = GX_LCD_SIZE_X - 32 } },
    { .rect = { .top = 152, .bottom = 152 + 24, .left = 32, .right = GX_LCD_SIZE_X - 32 } },
    { TOUCHSCREEN_RECTLIST_END },
};

static const TouchscreenHitbox sArrowButtonHitboxes[] = {
    { .rect = { .top = 6, .bottom = 6 + 28, .left = 222, .right = 222 + 28 } },
    { .rect = { .top = 158, .bottom = 158 + 28, .left = 222, .right = 222 + 28 } },
    { TOUCHSCREEN_RECTLIST_END },
};

extern const OverlayManagerTemplate gApp_MainMenu_SelectOption_MysteryGift;
extern const OverlayManagerTemplate gApp_MainMenu_SelectOption_MigrateFromAgb;
extern const OverlayManagerTemplate gApp_MainMenu_SelectOption_ConnectToRanger;
extern const OverlayManagerTemplate gApp_MainMenu_SelectOption_NintendoWFCSetup;
extern const OverlayManagerTemplate ov112_App_MainMenu_SelectOption_ConnectToPokewalker;
extern const OverlayManagerTemplate gApp_MainMenu_SelectOption_WiiMessageSettings;

static u32 MainMenu_GetNewInput(MainMenuAppData *data) {
    if (gSystem.newKeys & (PAD_BUTTON_Y | PAD_BUTTON_X | PAD_KEY_UP | PAD_KEY_DOWN | PAD_KEY_LEFT | PAD_KEY_RIGHT | PAD_BUTTON_B | PAD_BUTTON_A)) {
        data->menuInputState.state = MENU_INPUT_STATE_BUTTONS;
        return gSystem.newKeys;
    } else if (System_GetTouchNew()) {
        data->menuInputState.state = MENU_INPUT_STATE_TOUCH;
        return PAD_BUTTON_A;
    }

    return 0;
}

static u32 GetNthAvailableApp(MainMenuAppData *data, u8 n) {
    for (u32 i = 0, apps = 0; i < APPOPTION_COUNT; i++) {
        if (data->optionIds[i] != 0 && apps++ == n) {
            return i;
        }
    }
    return 0;
}

static u32 MainMenu_ConfirmOption(MainMenuAppData *data, int *state, BOOL cancelled) {
    if (!cancelled) {
        PlaySE(SEQ_SE_DP_SELECT);
        data->selectedApp = (MainMenu_AppOption)data->optionIds[data->currentOption];
        if (data->selectedApp == APPOPTION_MIGRATE_AGB && CTRDG_IsPulledOut() == TRUE) {
            if (data->beaconWatchState != 12) {
                CommState_StopBeaconWatch();
            }
            ShowGBACartRemovedError(HEAP_ID_MAIN_MENU);
        }
    } else {
        PlaySE(SEQ_SE_DP_SELECT);
        data->selectedApp = APPOPTION_TITLE_SCREEN;
        MainMenuUtil_SetFadeWhite(1);
    }

    if (data->selectedApp == APPOPTION_NEW_GAME) {
        data->raisedNotices |= (1 << 7);
        data->noticeDelay = 1;
        *state = 6;
    } else {
        if (data->selectedApp == APPOPTION_CONNECT_TO_WII) {
            MainMenuUtil_SetFadeWhite(1);
        }
        MainMenuUtil_StartFade(FADE_TYPE_BRIGHTNESS_OUT, 7, state, 8);
    }

    if (data->beaconWatchState == 13) {
        data->beaconWatchState = 14;
    }

    return TRUE;
}

static int CountAvailableAppsBefore(MainMenuAppData *data, int index) {
    int i;
    int apps = 0;
    for (i = 0; i < index; i++) {
        if (data->optionIds[i] != 0) {
            apps++;
        }
    }
    return apps;
}

static BOOL MainMenu_HandleKeyInput(MainMenuAppData *data, int *state) {
    BOOL changedOption = FALSE;

    if (gSystem.newKeys & (PAD_BUTTON_Y | PAD_BUTTON_X | PAD_KEY_UP | PAD_KEY_DOWN | PAD_KEY_LEFT | PAD_KEY_RIGHT | PAD_BUTTON_B | PAD_BUTTON_A) && data->menuInputState.state == MENU_INPUT_STATE_TOUCH) {
        data->menuInputState.state = MENU_INPUT_STATE_BUTTONS;
        MainMenu_HighlightOption(data, data->currentOption);
        return FALSE;
    }

    if (gSystem.newKeys & PAD_BUTTON_A) {
        return MainMenu_ConfirmOption(data, state, FALSE);
    } else if (gSystem.newKeys & PAD_BUTTON_B) {
        return MainMenu_ConfirmOption(data, state, TRUE);
    }

    if (data->redrawOptions) {
        return FALSE;
    }

    u32 scrollOption;
    u32 oldOption = data->currentOption;
    if (gSystem.newKeys & PAD_KEY_UP) {
        if (ChangeCurrentAppOption(data, -1)) {
            scrollOption = CountAvailableAppsBefore(data, oldOption);
            if (scrollOption == 7) {
                scrollOption = 3;
                changedOption = TRUE;
            } else if (scrollOption == 3) {
                scrollOption = 0;
                changedOption = TRUE;
            }
        }
    } else if (gSystem.newKeys & PAD_KEY_DOWN) {
        changedOption = ChangeCurrentAppOption(data, 1);
        scrollOption = data->currentOption;
    }

    if (changedOption) {
        MainMenu_ScrollToOption(data, scrollOption);
    }

    return FALSE;
}

static BOOL MainMenu_HandleTouchInput(MainMenuAppData *data, int *state, BOOL *validInput) {
    BOOL hitArrowButton;

    int hitboxNum = -1;
    hitArrowButton = FALSE;

    if (!System_GetTouchNew()) {
        return FALSE;
    }

    if (!data->redrawOptions && data->optionChangeTimer == 0) {
        hitboxNum = TouchscreenHitbox_FindRectAtTouchNew(sArrowButtonHitboxes);
    }

    if (hitboxNum == 0 && Sprite_GetAnimationNumber(data->upArrowSprite) / 2 != 0) {
        Sprite_SetAnimActiveFlag(data->upArrowSprite, TRUE);
        Sprite_ResetAnimCtrlState(data->upArrowSprite);
        if (data->currentOption > 3 && data->effectiveScreenY > FX32_CONST(GX_LCD_SIZE_Y)) {
            data->currentOption = GetNthAvailableApp(data, 3);
        } else {
            data->currentOption = GetNthAvailableApp(data, 0);
        }
        hitArrowButton = TRUE;
        *validInput = TRUE;
    } else if (hitboxNum == 1 && Sprite_GetAnimationNumber(data->downArrowSprite) / 2 != 0) {
        Sprite_SetAnimActiveFlag(data->downArrowSprite, TRUE);
        Sprite_ResetAnimCtrlState(data->downArrowSprite);
        if (data->currentOption < 3) {
            data->currentOption = GetNthAvailableApp(data, 3);
        } else {
            data->currentOption = GetNthAvailableApp(data, 7);
        }
        hitArrowButton = TRUE;
        *validInput = TRUE;
    }

    if (hitArrowButton) {
        data->menuInputState.state = MENU_INPUT_STATE_TOUCH;
        MainMenu_HighlightOption(data, data->currentOption);
        MainMenu_ScrollToOption(data, data->currentOption);
        data->optionChangeTimer = 6;
        return FALSE;
    }

    u16 pixel = 0xFFFF & ~(1 << 0);
    u16 effectiveTouchY = gSystem.touchY + (data->effectiveScreenY / FX32_ONE);
    if (effectiveTouchY >= 512) {
        return FALSE;
    }
    if (!DoesPixelAtScreenXYMatchPtrVal(data->bgConfig, GF_BG_LYR_MAIN_0, gSystem.touchX, effectiveTouchY, &pixel)) {
        return FALSE;
    }

    *validInput = TRUE;

    // Button heights are 48 pixels.
    u16 touchedOption = gSystem.touchY / 48;
    if (data->effectiveScreenY == 0) {
        // The continue button is twice the height of the other buttons, so we need to account for one button being two buttons tall.
        if (touchedOption != 0) {
            touchedOption--;
        }
    } else if (data->effectiveScreenY == FX32_CONST(GX_LCD_SIZE_Y)) {
        touchedOption += 3;
    } else {
        touchedOption += 7;
    }

    if (touchedOption >= data->shownOptionCount) {
        return FALSE;
    }

    data->currentOption = GetNthAvailableApp(data, touchedOption);

    data->menuInputState.state = MENU_INPUT_STATE_TOUCH;
    MainMenu_HighlightOption(data, data->currentOption);
    return MainMenu_ConfirmOption(data, state, FALSE);
}

static BOOL MainMenu_HandleInput(MainMenuAppData *data, int *newState) {
    BOOL hadTouchInput = FALSE;
    BOOL touchResult = MainMenu_HandleTouchInput(data, newState, &hadTouchInput);
    if (hadTouchInput) {
        data->menuInputState.state = MENU_INPUT_STATE_TOUCH;
        if (data->optionChangeTimer != 6) {
            MainMenu_HighlightOption(data, 0xFF);
        }
        return touchResult;
    }
    return MainMenu_HandleKeyInput(data, newState);
}

static u32 MainMenu_NewGame_HandleTouchInput(MainMenuAppData *data, BOOL *validInput) {
    if (!System_GetTouchNew()) {
        return 0;
    }

    int hitboxId = TouchscreenHitbox_FindRectAtTouchNew(sNewGameButtonHitboxes);
    if (hitboxId == -1) {
        return 0;
    }

    // Make sure the player didn't touch a transparent pixel (because of the hitbox sizes and positions, this will always be true)
    u16 pixel = 0xFFFF & ~(1 << 0);
    if (!DoesPixelAtScreenXYMatchPtrVal(data->bgConfig, GF_BG_LYR_MAIN_1, gSystem.touchX, gSystem.touchY, &pixel)) {
        return 0;
    }

    u32 ret = 1;
    *validInput = TRUE;
    if (hitboxId != 0) {
        ret = 2;
    }

    return ret;
}

static u32 MainMenu_NewGame_HandleInput(MainMenuAppData *data) {
    BOOL hadTouchInput = FALSE;
    u32 touchResult = MainMenu_NewGame_HandleTouchInput(data, &hadTouchInput);
    if (hadTouchInput) {
        data->menuInputState.state = MENU_INPUT_STATE_TOUCH;
        MainMenu_HighlightNewGameOption(data, 0xFF);
        return touchResult;
    }

    if (gSystem.newKeys == 0) {
        return 0;
    }

    if (gSystem.newKeys & (PAD_BUTTON_Y | PAD_BUTTON_X | PAD_KEY_UP | PAD_KEY_DOWN | PAD_KEY_LEFT | PAD_KEY_RIGHT | PAD_BUTTON_B | PAD_BUTTON_A) && data->menuInputState.state == MENU_INPUT_STATE_TOUCH) {
        data->menuInputState.state = MENU_INPUT_STATE_BUTTONS;
        MainMenu_HighlightNewGameOption(data, data->currentNewGameOption);
        return 0;
    }

    if (gSystem.newKeys & (PAD_KEY_UP | PAD_KEY_DOWN)) {
        data->currentNewGameOption ^= 1;
        MainMenu_HighlightNewGameOption(data, data->currentNewGameOption);
        PlaySE(SEQ_SE_DP_SELECT);
        return 0;
    }

    u32 ret = 1;
    if (gSystem.newKeys & PAD_BUTTON_A) {
        if (data->currentNewGameOption != 0) {
            ret = 2;
        }
    } else {
        ret = 2;
        if (!(gSystem.newKeys & PAD_BUTTON_B)) {
            ret = 0;
        }
    }

    return ret;
}

static u32 MainMenu_AlwaysZero(MainMenuAppData *data) {
    return 0;
}

typedef struct MainMenuWarningBox {
    u32 x;
    u32 y;
    u32 width;
    u32 height;
    u32 gmmId;
    u32 msgId;
    u32 unused18;
} MainMenuWarningBox;

// Unused warning screen for wifi user info
static BOOL MainMenu_PrintWifiInfoErasedWarning(MainMenuAppData *data) {
    static MainMenuWarningBox ov74_0223BBD4[] = {
        {
         .x = 5,
         .y = 5,
         .width = 22,
         .height = 14,
         .gmmId = NARC_msg_msg_0800_bin,
         // clang-format off
         .msgId = msg_0800_00016, // "Your Nintendo Wi-Fi Connection User Information may have been erased. [...]"
         .unused18 = 0,
         // clang-format on
        },
    };

    if (!WindowIsInUse(&data->warningWindow)) {
        for (int i = 0; i < (int)NELEMS(data->warningPending); i++) {
            if (data->warningPending[i] == 1) {
                data->warningPending[i] = 0;
                MainMenuTextPrinter printer;
                const MainMenuWarningBox *box = &ov74_0223BBD4[i];
                MainMenuTextPrinter_Init(&printer, &data->warningWindow, 0, box->gmmId, 0x3F7, 2);
                MainMenuTextPrinter_SetSize(&printer, box->width, box->height, 1);
                MainMenuTextPrinter_AddWindowAndPrint(data->bgConfig, &printer, box->x, box->y, box->msgId);
                return TRUE;
            }
        }
    } else {
        if (MainMenu_GetNewInput(data) & (PAD_BUTTON_B | PAD_BUTTON_A)) {
            PlaySE(SEQ_SE_DP_SELECT);
            EraseFrameAndWindow1(&data->warningWindow, FALSE);
            RemoveWindow(&data->warningWindow);
        }
        return TRUE;
    }

    return FALSE;
}

static void DetectInsertedGBACart(MainMenuAppData *data) {
    u32 offsets = PmAgbCartridgeGetOffsets(0);
    u32 version = 0;
    data->connectedAgbGame = 0;

    if (offsets != 0) {
        return;
    }

    switch (PmAgbCartridge_GetVersionInternal()) {
    case 0:
        version = VERSION_RUBY;
        break;
    case 1:
        version = VERSION_SAPPHIRE;
        break;
    case 2:
        version = VERSION_LEAFGREEN;
        break;
    case 3:
        version = VERSION_FIRERED;
        break;
    case 4:
        version = VERSION_EMERALD;
        break;
    }
    Sys_SetAgbCartridgeVersion(version);

    if (Pokedex_GetNatDexFlag(data->pokedex) && gGameLanguage == PmAgbCartridge_GetLanguage()) {
        data->connectedAgbGame = PmAgbCartridge_GetVersionInternal() + 1;
        MainMenuUtil_IgnoreCartridgeIrq();
    }
}

static void MainMenu_UpdateBeaconWatch(MainMenuAppData *data) {
    switch (data->beaconWatchState) {
    case 10:
        data->beaconWatchState = 11;
        break;
    case 11:
        CommState_StartBeaconWatch(data->saveData);
        data->beaconWatchTimer = 120;
        data->beaconWatchState = 13;
        data->raisedNotices = 0;
        if (SaveMysteryGift_TestFlagx7FF(data->mysteryGift) == TRUE) {
            data->raisedNotices |= (1 << 0);
            data->shownNotices |= (1 << 0);
        }
        break;
    case 13: {
        if (data->noticeDelay != 0) {
            break;
        }

        u32 seenGames = CommState_GetSeenGames();
        u32 newNotices = ~data->raisedNotices & seenGames;
        if (newNotices != 0 && data->noticeState == 15 && data->noticeDelay == 0 && data->raisedNotices != newNotices) {
            data->redrawOptions = TRUE;

            if (newNotices & (1 << 0)) {
                data->drawMysteryGiftButton = TRUE;
                newNotices = (1 << 0);
            }

            if (newNotices & (1 << 1)) {
                data->drawConnectToRangerButton = TRUE;
                newNotices = (1 << 1);
            }

            if (newNotices & (1 << 2)) {
                data->drawConnectToWiiButton = TRUE;
                newNotices = (1 << 2);
            }

            if (newNotices & (1 << 1 | 1 << 0)) {
                data->noticePending = TRUE;
            }

            data->raisedNotices |= newNotices;
        }

        data->beaconWatchTimer--;
        if (data->beaconWatchTimer == 0) {
            CommState_StopBeaconWatch();
            data->beaconWatchState = 12;
        }

        break;
    }
    case 14:
        CommState_StopBeaconWatch();
        data->beaconWatchState = 12;
        break;
    }
}

typedef struct MainMenuNoticeBox {
    u32 x;
    u32 y;
    u32 width;
    u32 height;
    u32 msgId;
} MainMenuNoticeBox;

static BOOL MainMenu_UpdateNoticeBoxes(MainMenuAppData *data) {
    static MainMenuNoticeBox ov74_0223BC30[] = {
        { .x = 4, .y = 2,  .width = 24, .height = 20, .msgId = msg_0017_00001 }, // Found a mystery gift
        { .x = 4, .y = 4,  .width = 24, .height = 16, .msgId = msg_0017_00003 }, // Found a mystery gift, but don't have the Pokédex
        { .x = 4, .y = 1,  .width = 24, .height = 22, .msgId = msg_0017_00000 }, // Got a recruitment message from Ranger
        { .x = 4, .y = 3,  .width = 24, .height = 18, .msgId = msg_0017_00002 }, // Got a recruitment message from Ranger, but don't have the Pokédex
        { .x = 0, .y = 1,  .width = 32, .height = 11, .msgId = msg_0017_00005 }, // "WARNING! There's already a saved game file. [...]"
        { .x = 4, .y = 14, .width = 24, .height = 3,  .msgId = msg_0017_00006 }, // "Begin adventure"
        { .x = 4, .y = 19, .width = 24, .height = 3,  .msgId = msg_0017_00007 }, // "Return to the menu"
    };

    switch (data->noticeState) {
    case 15:
        if (data->noticeDelay == 0) {
            return FALSE;
        }

        data->noticeDelay--;
        if (data->noticeDelay == 0) {
            data->noticeState = 16;
        }
        return TRUE;
    case 16:
        LoadUserFrameGfx1(data->bgConfig, GF_BG_LYR_MAIN_1, 0x3F7, 2, 0, HEAP_ID_MAIN_MENU);
        LoadUserFrameGfx1(data->bgConfig, GF_BG_LYR_MAIN_1, 0x3EE, 3, 1, HEAP_ID_MAIN_MENU);
        BgClearTilemapBufferAndCommit(data->bgConfig, GF_BG_LYR_MAIN_1);
        ((vu16 *)HW_PLTT)[33] = RGB(26, 26, 26);
        data->noticeState = 17;
        break;
    case 17: {
        MainMenuTextPrinter printer;
        MainMenuTextPrinter_Init(&printer, &data->noticeWindow, 0, NARC_msg_msg_0017_bin, 0x3F7, 2);
        MainMenuNoticeBox *box;
        u32 unk3 = data->raisedNotices & ~data->shownNotices;
        if (unk3 & (1 << 0)) {
            box = (data->wirelessButtonsShown & (1 << 0)) ? &ov74_0223BC30[0] : &ov74_0223BC30[1];
        } else if (unk3 & (1 << 1)) {
            box = (data->wirelessButtonsShown & (1 << 1)) ? &ov74_0223BC30[2] : &ov74_0223BC30[3];
        } else if (unk3 & (1 << 7)) {
            printer.frameType = 2;
            box = &ov74_0223BC30[4];
            MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, printer.msgFileId, HEAP_ID_MAIN_MENU);
            String *string = NewString_ReadMsgData(msgData, box->msgId);
            u32 width = FontID_String_GetWidthMultiline(printer.fontId, string, 0);
            printer.textX = (box->width * 8 - width) / 2;
            String_Delete(string);
            DestroyMsgData(msgData);
            printer.textY = 4;
        }
        MainMenuTextPrinter_SetSize(&printer, box->width, box->height, 0x91);
        printer.bgId = GF_BG_LYR_MAIN_1;
        MainMenuTextPrinter_AddWindowAndPrint(data->bgConfig, &printer, box->x, box->y, box->msgId);

        BgTilemapRectChangePalette(data->bgConfig, GF_BG_LYR_MAIN_1, GetWindowX(printer.window), GetWindowY(printer.window), GetWindowWidth(printer.window), GetWindowHeight(printer.window), 0);

        if ((unk3 & (1 << 7)) && !(unk3 & (1 << 1 | 1 << 0))) {
            for (int i = 0; i < (int)NELEMS(data->newGameOptionWindows); i++) {
                Window *window = &data->newGameOptionWindows[i];
                MainMenuTextPrinter_Init(&printer, window, 0, NARC_msg_msg_0017_bin, 0x3F7, 2);
                MainMenuNoticeBox *unk3 = &ov74_0223BC30[i + 5];
                printer.textY = 4;
                MainMenuTextPrinter_SetSize(&printer, unk3->width, unk3->height, (i * 72) + 1);
                printer.bgId = GF_BG_LYR_MAIN_1;
                MainMenuTextPrinter_AddWindowAndPrint(data->bgConfig, &printer, unk3->x, unk3->y, unk3->msgId);
            }
            data->currentNewGameOption = 0;
            MainMenu_HighlightNewGameOption(data, -1);
            data->noticeState = 19;
            data->noticeInputDelay = 30;
        } else {
            data->shownNotices |= unk3;
            data->noticeState = 18;
            data->noticeInputDelay = 30;
        }

        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_OFF);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_OFF);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_ON);
        break;
    }
    case 18: {
        if (data->noticeInputDelay != 0) {
            data->noticeInputDelay--;
            break;
        }

        u32 oldInputState = data->menuInputState.state;
        u32 printer = MainMenu_GetNewInput(data);
        if (printer & (PAD_BUTTON_B | PAD_BUTTON_A)) {
            if (oldInputState != data->menuInputState.state) {
                MainMenu_HighlightOption(data, data->currentOption);
            }
            RemoveWindow(&data->noticeWindow);
            data->noticeState = 20;
            data->noticeInput = printer;
            PlaySE(SEQ_SE_DP_SELECT);
        }
        break;
    }
    case 19:
        if (data->noticeInputDelay != 0) {
            data->noticeInputDelay--;
            if (data->noticeInputDelay == 0) {
                MainMenu_HighlightNewGameOption(data, 0);
            }
        } else {
            u32 inputResult = MainMenu_NewGame_HandleInput(data);
            AdvanceButtonBorderAnimation(data);
            if (inputResult & 3) {
                RemoveWindow(&data->noticeWindow);
                RemoveWindow(&data->newGameOptionWindows[0]);
                RemoveWindow(&data->newGameOptionWindows[1]);
                MainMenu_HighlightOption(data, data->currentOption);
                data->noticeState = 20;
                data->noticeInput = inputResult;
                PlaySE(SEQ_SE_DP_SELECT);
            }
        }
        break;
    case 20:
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
        data->noticeState = 15;
        break;
    }

    return TRUE;
}

static void HandleScreenScroll(MainMenuAppData *data) {
    if (data->currentScreenY == data->effectiveScreenY) {
        return;
    }

#define ABS(x) (((x) ^ ((x) >> 31)) - ((x) >> 31))

    fx32 scrollStep = (data->effectiveScreenY - data->currentScreenY) / 4;
    if (ABS(scrollStep) > FX32_CONST(12)) {
        if (scrollStep > 0) {
            scrollStep = FX32_CONST(12);
        } else {
            scrollStep = FX32_CONST(-12);
        }
    }
    data->currentScreenY += scrollStep;

    if (ABS(data->effectiveScreenY - data->currentScreenY) < FX32_CONST(0.125f)) {
        data->currentScreenY = data->effectiveScreenY;
    }

    ScheduleSetBgPosText(data->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_Y, data->currentScreenY / FX32_ONE);
    ScheduleSetBgPosText(data->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, data->currentScreenY / FX32_ONE);
}

static void MainMenu_SetupGraphics(MainMenuAppData *data) {
    static const GraphicsBanks sMainMenuGraphicsBanks = {
        .bg = GX_VRAM_BG_128_A,
        .subbg = GX_VRAM_SUB_BG_128_C,
        .obj = GX_VRAM_OBJ_64_E,
        .subobj = GX_VRAM_SUB_OBJ_16_I,
        .tex = GX_VRAM_TEX_0_B,
        .texpltt = GX_VRAM_TEXPLTT_01_FG,
    };
    GraphicsBanks banks = sMainMenuGraphicsBanks;
    static const GraphicsModes sMainMenuGraphicsModes = {
        .dispMode = GX_DISPMODE_GRAPHICS,
        .bgMode = GX_BGMODE_0,
        .subMode = GX_BGMODE_0,
        ._2d3dMode = GX_BG0_AS_2D,
    };
    GraphicsModes modes = sMainMenuGraphicsModes;
    GfGfx_SetBanks(&banks);
    SetBothScreensModesAndDisable(&modes);

    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);

    MainMenuUtil_InitBg(data->bgConfig, GF_BG_LYR_MAIN_0, GF_BG_SCR_SIZE_256x512, 0xF000, 0x0);
    G2_SetBG0Priority(2);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 32, 0, HEAP_ID_MAIN_MENU);
    BgClearTilemapBufferAndCommit(data->bgConfig, GF_BG_LYR_MAIN_0);

    MainMenuUtil_InitBg(data->bgConfig, GF_BG_LYR_MAIN_1, GF_BG_SCR_SIZE_256x256, 0xD800, 0x8000);
    G2_SetBG1Priority(1);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_1, 32, 0, HEAP_ID_MAIN_MENU);
    BgClearTilemapBufferAndCommit(data->bgConfig, GF_BG_LYR_MAIN_1);

    MainMenuUtil_InitBg(data->bgConfig, GF_BG_LYR_MAIN_2, GF_BG_SCR_SIZE_256x512, 0xE000, 0x0);
    G2_SetBG2Priority(0);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_2, 32, 0, HEAP_ID_MAIN_MENU);
    BgClearTilemapBufferAndCommit(data->bgConfig, GF_BG_LYR_MAIN_2);

    ResetAllTextPrinters();

    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_1_OFFSET, HEAP_ID_MAIN_MENU);
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, HEAP_ID_MAIN_MENU);

    ((vu16 *)HW_PLTT)[0] = RGB_BLACK;
    ((vu16 *)HW_PLTT)[31] = RGB(26, 26, 26);

    LoadUserFrameGfx1(data->bgConfig, GF_BG_LYR_MAIN_0, 0x3F7, 2, 0, HEAP_ID_MAIN_MENU);
    LoadUserFrameGfx1(data->bgConfig, GF_BG_LYR_MAIN_0, 0x3EE, 3, 1, HEAP_ID_MAIN_MENU);

    ((vu16 *)HW_PLTT)[33] = RGB(26, 26, 26);
}

static void MainMenu_SetupSprites(MainMenuAppData *data) {
    MainMenuUtil_InitObjTransfer();
    MainMenuUtil_InitSprites();
    // FIXME: Unpack a/1/1/3 and use NAIX constants here.
    MainMenuUtil_LoadSpriteResources(NARC_a_1_1_3, 47, 44, 46, 45, 0);

    data->upArrowSprite = MainMenuUtil_CreateSprite(0, data->upArrowSprite, 236, 20, 0);
    Sprite_SetDrawFlag(data->upArrowSprite, TRUE);
    Sprite_SetAnimActiveFlag(data->upArrowSprite, FALSE);

    data->downArrowSprite = MainMenuUtil_CreateSprite(0, data->downArrowSprite, 236, 172, 1);
    Sprite_SetDrawFlag(data->downArrowSprite, TRUE);
    Sprite_SetAnimActiveFlag(data->downArrowSprite, FALSE);
}

static void MainMenu_SetupWifiTiles(MainMenuAppData *data) {
    // FIXME: Unpack a/1/1/3 and use NAIX constants here.
    GfGfxLoader_GXLoadPal(NARC_a_1_1_3, 49, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_4_OFFSET, 32, HEAP_ID_MAIN_MENU);
    GfGfxLoader_LoadCharData(NARC_a_1_1_3, 48, data->bgConfig, GF_BG_LYR_MAIN_2, 0x3E6, 0x100, FALSE, HEAP_ID_MAIN_MENU);
}

static void DrawWirelessIcon(MainMenuAppData *data, u32 x, u32 y, u32 type) {
    u16 *buffer = GetBgTilemapBuffer(data->bgConfig, GF_BG_LYR_MAIN_2);

    // Bits 15-12: palette, 11-0: tile number
    u32 tileId = (4 << 12) | 0x3E6;
    if (type == 2) {
        tileId += 4;
    }

    u32 offset = (y + 0) * 32 + x;
    buffer[offset++] = tileId + 0;
    buffer[offset++] = tileId + 1;
    offset = (y + 1) * 32 + x;
    buffer[offset++] = tileId + 2;
    buffer[offset++] = tileId + 3;

    BgCommitTilemapBufferToVram(data->bgConfig, GF_BG_LYR_MAIN_2);
}

static void ClearWirelessIcon(MainMenuAppData *data, u32 x, u32 y) {
    u16 *buffer = GetBgTilemapBuffer(data->bgConfig, GF_BG_LYR_MAIN_2);

    u32 offset = (y + 0) * 32 + x;
    buffer[offset++] = 0;
    buffer[offset++] = 0;
    offset = (y + 1) * 32 + x;
    buffer[offset++] = 0;
    buffer[offset++] = 0;

    BgCommitTilemapBufferToVram(data->bgConfig, GF_BG_LYR_MAIN_2);
}

static void PrintPlayerInfoField(Window *window, MsgData *msgData, MessageFormat *msgFmt, u32 color, u32 msgId, u32 y) {
    String *string = ReadMsgData_ExpandPlaceholders(msgFmt, msgData, msgId, HEAP_ID_MAIN_MENU);
    int stringPixelWidth = FontID_String_GetWidth(0, string, GetFontAttribute(0, 2));
    u32 x = GetWindowWidth(window) * 8 - (stringPixelWidth + 32);
    AddTextPrinterParameterizedWithColor(window, 0, string, x, y, TEXT_SPEED_NOTRANSFER, color, NULL);
    String_Delete(string);
}

static void MainMenu_BufferAlignedNumber(MessageFormat *messageFormat, int number) {
    u32 digits;
    PrintingMode printingMode;

    if (number >= 100) {
        digits = 3;
        printingMode = PRINTING_MODE_LEFT_ALIGN;
    } else if (number >= 10) {
        digits = 3;
        printingMode = PRINTING_MODE_RIGHT_ALIGN;
    } else {
        digits = 2;
        printingMode = PRINTING_MODE_RIGHT_ALIGN;
    }

    BufferIntegerAsString(messageFormat, 0, number, digits, printingMode, 1);
}

static BOOL MainMenu_PrintContinueButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y) {
    MessageFormat *messageFormat;
    MsgData *msgData;

    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0442_bin, HEAP_ID_MAIN_MENU);
    messageFormat = MessageFormat_New(HEAP_ID_MAIN_MENU);
    u32 textColor = (PlayerProfile_GetTrainerGender(data->profile) == PLAYER_GENDER_FEMALE) ? MAKE_TEXT_COLOR(3, 4, 15) : MAKE_TEXT_COLOR(7, 8, 15);

    MainMenuTextPrinter_AddWindowAndPrint(data->bgConfig, printer, 3, y, sMainMenuButtons[index].msgId);

    static u32 sContinueButtonMsgs[] = {
        msg_0442_00000, // "CONTINUE"
        msg_0442_00013, // "PLAYER"
        msg_0442_00014, // "TIME"
        msg_0442_00016, // "BADGES"
        msg_0442_00015, // "POKéDEX"
    };
    for (u32 i = 1; i < NELEMS(sContinueButtonMsgs); i++) {
        if (i == 4 && !data->hasPokedex) {
            continue;
        }

        String *string = ReadMsgData_ExpandPlaceholders(messageFormat, msgData, sContinueButtonMsgs[i], HEAP_ID_MAIN_MENU);
        AddTextPrinterParameterizedWithColor(printer->window, 0, string, 32, i * 16, TEXT_SPEED_NOTRANSFER, textColor, NULL);
        String_Delete(string);
    }

    BufferPlayersName(messageFormat, 0, data->profile);
    PrintPlayerInfoField(printer->window, msgData, messageFormat, textColor, msg_0442_00017, 16);

    MainMenu_BufferAlignedNumber(messageFormat, GetIGTHours(data->igt));
    BufferIntegerAsString(messageFormat, 1, GetIGTMinutes(data->igt), 2, PRINTING_MODE_LEADING_ZEROS, 1);
    PrintPlayerInfoField(printer->window, msgData, messageFormat, textColor, msg_0442_00018, 32);

    BufferIntegerAsString(messageFormat, 0, data->badges, 2, PRINTING_MODE_LEFT_ALIGN, 1);
    PrintPlayerInfoField(printer->window, msgData, messageFormat, textColor, msg_0442_00020, 48);

    if (data->hasPokedex) {
        MainMenu_BufferAlignedNumber(messageFormat, Pokedex_CountDexOwned(data->pokedex));
        PrintPlayerInfoField(printer->window, msgData, messageFormat, textColor, msg_0442_00019, 64);
    }

    DrawFrameAndWindow1(printer->window, FALSE, printer->frameBaseTile, printer->framePalette);

    data->optionIds[index] = sMainMenuButtons[index].id;
    MessageFormat_Delete(messageFormat);
    DestroyMsgData(msgData);

    return TRUE;
}

static BOOL MainMenu_PrintMigrateFromAgbButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y) {
    if (data->connectedAgbGame == 0) {
        return FALSE;
    }

    u32 msgId;
    switch (data->connectedAgbGame - 1) {
    case 0:
        msgId = msg_0442_00004; // "MIGRATE FROM RUBY"
        break;
    case 1:
        msgId = msg_0442_00005; // "MIGRATE FROM SAPPHIRE"
        break;
    case 2:
        msgId = msg_0442_00006; // "MIGRATE FROM LEAFGREEN"
        break;
    case 3:
        msgId = msg_0442_00007; // "MIGRATE FROM FIRERED"
        break;
    case 4:
        msgId = msg_0442_00008; // "MIGRATE FROM EMERALD"
        break;
    }

    MainMenuTextPrinter_AddWindowAndPrint(data->bgConfig, printer, 3, y, msgId);
    ClearWirelessIcon(data, 23, y);
    data->optionIds[index] = sMainMenuButtons[index].id;

    return TRUE;
}

static BOOL MainMenu_PrintMysteryGiftButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y) {
    if (!data->drawMysteryGiftButton) {
        if (SaveMysteryGift_TestFlagx7FF(data->mysteryGift) == TRUE) {
            data->drawMysteryGiftButton = TRUE;
        }

        if (Save_SysInfo_GetMysteryGiftActive(Save_SysInfo_Get(data->saveData)) == TRUE) {
            data->drawMysteryGiftButton = TRUE;
        }

        MainMenuUtil_SetCryptoHeap(HEAP_ID_MAIN_MENU);

        if (MainMenuUtil_GetCartridgeGiftSize() != 0) {
            data->drawMysteryGiftButton = TRUE;
            MainMenuUtil_EnableCartridgePullOutCheck(TRUE);
        }
    }

    if (data->drawMysteryGiftButton == TRUE && !data->hasPokedex) {
        data->drawMysteryGiftButton = FALSE;
    }

    if (data->drawMysteryGiftButton == TRUE) {
        MainMenuTextPrinter_AddWindowAndPrint(data->bgConfig, printer, 3, y, sMainMenuButtons[index].msgId);
        ClearWirelessIcon(data, 23, y);
        data->optionIds[index] = sMainMenuButtons[index].id;
        data->wirelessButtonsShown |= (1 << 0);
        SaveMysteryGift_SetFlagx7FF(data->mysteryGift);

        return TRUE;
    }

    return FALSE;
}

static BOOL MainMenu_PrintConnectToRangerButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y) {
    if (data->drawConnectToRangerButton == TRUE && data->hasPokedex == TRUE) {
        MainMenuTextPrinter_AddWindowAndPrint(data->bgConfig, printer, 3, y, sMainMenuButtons[index].msgId);
        DrawWirelessIcon(data, 23, y, 1);
        data->wirelessIconTypes[index] = 1;
        data->optionIds[index] = sMainMenuButtons[index].id;
        data->wirelessButtonsShown |= (1 << 1);

        return TRUE;
    }

    return FALSE;
}

static BOOL MainMenu_PrintConnectToWiiButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y) {
    if (data->drawConnectToWiiButton == TRUE) {
        MainMenuTextPrinter_AddWindowAndPrint(data->bgConfig, printer, 3, y, sMainMenuButtons[index].msgId);
        data->wirelessIconTypes[index] = 1;
        DrawWirelessIcon(data, 23, y, 1);
        data->optionIds[index] = sMainMenuButtons[index].id;

        return TRUE;
    }

    return FALSE;
}

static BOOL MainMenu_PrintNintendoWFCSetupButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y) {
    MainMenuTextPrinter_AddWindowAndPrint(data->bgConfig, printer, 3, y, sMainMenuButtons[index].msgId);
    data->wirelessIconTypes[index] = 2;
    DrawWirelessIcon(data, 23, y, 2);
    data->optionIds[index] = sMainMenuButtons[index].id;

    return TRUE;
}

static BOOL MainMenu_PrintConnectToPokewalkerButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y) {
    MainMenuTextPrinter_AddWindowAndPrint(data->bgConfig, printer, 3, y, sMainMenuButtons[index].msgId);
    ClearWirelessIcon(data, 23, y);
    data->optionIds[index] = sMainMenuButtons[index].id;

    return TRUE;
}

static BOOL MainMenu_PrintWiiMessageSettingsButton(MainMenuAppData *data, u32 index, MainMenuTextPrinter *printer, u32 y) {
    MainMenuTextPrinter_AddWindowAndPrint(data->bgConfig, printer, 3, y, sMainMenuButtons[index].msgId);
    ClearWirelessIcon(data, 23, y);
    data->optionIds[index] = sMainMenuButtons[index].id;

    return TRUE;
}

static BOOL MainMenu_DrawOptionWindows(MainMenuAppData *data) {
    u32 y;
    u32 i;

    BOOL ret = FALSE;

    data->shownOptionCount = 0;
    data->windowBaseTile = 1;

    for (i = 0, y = 1; i < APPOPTION_COUNT; i++) {
        const MainMenuButton *button = &sMainMenuButtons[i];
        MainMenuTextPrinter printer;
        MainMenuTextPrinter_Init(&printer, &data->optionWindows[i], 1, NARC_msg_msg_0442_bin, 0x3F7, 2);
        MainMenuTextPrinter_SetSize(&printer, 23, button->height, data->windowBaseTile);
        if (button->printFunction != NULL) {
            if (data->optionIds[i] != 0) {
                SetWindowX(printer.window, 3);
                SetWindowY(printer.window, y);
                DrawFrameAndWindow1(printer.window, FALSE, printer.frameBaseTile, printer.framePalette);

                if (data->wirelessIconTypes[i] != 0) {
                    DrawWirelessIcon(data, 23, y, data->wirelessIconTypes[i]);
                } else {
                    ClearWirelessIcon(data, 23, y);
                }
                y += button->height + 2;
                ret = TRUE;
            } else {
                if (button->printFunction(data, i, &printer, y) == TRUE) {
                    y += button->height + 2;
                    ret = TRUE;
                }
            }
        } else {
            MainMenuTextPrinter_AddWindowAndPrint(data->bgConfig, &printer, 3, y, button->msgId);
            data->optionIds[i] = button->id;
            y += button->height + 2;
        }

        data->windowBaseTile += button->height * 23;
        if (data->optionIds[i] != 0) {
            data->shownOptionCount++;
        }
    }

    MainMenu_UpdateArrowSprites(data);
    MainMenu_HighlightOption(data, data->currentOption);

    return ret;
}

static void MainMenu_HighlightOption(MainMenuAppData *data, int currentOption) {
    for (int i = 0; i < NELEMS(data->optionWindows); i++) {
        Window *window = &data->optionWindows[i];
        if (!WindowIsInUse(window)) {
            continue;
        }

        if (i == 0 && data->effectiveScreenY == FX32_CONST(GX_LCD_SIZE_Y * 2)) {
            continue;
        }

        if (i < currentOption - 5 || i > currentOption + 5) {
            continue;
        }

        if (data->menuInputState.state == MENU_INPUT_STATE_TOUCH) {
            DrawFrameAndWindow1(window, TRUE, 0x3EE, 2);
            BgTilemapRectChangePalette(data->bgConfig, GF_BG_LYR_MAIN_0, GetWindowX(window), GetWindowY(window), GetWindowWidth(window), GetWindowHeight(window), 0);
        } else if (i == currentOption) {
            DrawFrameAndWindow1(window, TRUE, 0x3EE, 3);
            BgTilemapRectChangePalette(data->bgConfig, GF_BG_LYR_MAIN_0, GetWindowX(window), GetWindowY(window), GetWindowWidth(window), GetWindowHeight(window), 0);
        } else {
            DrawFrameAndWindow1(window, TRUE, 0x3F7, 2);
            BgTilemapRectChangePalette(data->bgConfig, GF_BG_LYR_MAIN_0, GetWindowX(window), GetWindowY(window), GetWindowWidth(window), GetWindowHeight(window), 1);
        }
    }

    BgCommitTilemapBufferToVram(data->bgConfig, GF_BG_LYR_MAIN_0);
}

static void MainMenu_HighlightNewGameOption(MainMenuAppData *data, int selection) {
    for (int i = 0; i < (int)NELEMS(data->newGameOptionWindows); i++) {
        Window *window = &data->newGameOptionWindows[i];
        if (!WindowIsInUse(window)) {
            continue;
        }

        if (selection < 0) {
            DrawFrameAndWindow1(window, TRUE, 0x3F7, 2);
            BgTilemapRectChangePalette(data->bgConfig, GF_BG_LYR_MAIN_1, GetWindowX(window), GetWindowY(window), GetWindowWidth(window), GetWindowHeight(window), 1);
        } else if (data->menuInputState.state == MENU_INPUT_STATE_TOUCH) {
            DrawFrameAndWindow1(window, TRUE, 0x3EE, 2);
            BgTilemapRectChangePalette(data->bgConfig, GF_BG_LYR_MAIN_1, GetWindowX(window), GetWindowY(window), GetWindowWidth(window), GetWindowHeight(window), 0);
        } else if (i == selection) {
            DrawFrameAndWindow1(window, TRUE, 0x3EE, 3);
            BgTilemapRectChangePalette(data->bgConfig, GF_BG_LYR_MAIN_1, GetWindowX(window), GetWindowY(window), GetWindowWidth(window), GetWindowHeight(window), 0);
        } else {
            DrawFrameAndWindow1(window, TRUE, 0x3F7, 2);
            BgTilemapRectChangePalette(data->bgConfig, GF_BG_LYR_MAIN_1, GetWindowX(window), GetWindowY(window), GetWindowWidth(window), GetWindowHeight(window), 1);
        }
    }
    BgCommitTilemapBufferToVram(data->bgConfig, GF_BG_LYR_MAIN_1);
}

static BOOL ChangeCurrentAppOption(MainMenuAppData *data, int offset) {
    int option = data->currentOption;
    int oldOption = data->currentOption;

    while (TRUE) {
        option += offset;

        if (option == -1) {
            option = 0;
        }

        if (option == NELEMS(sMainMenuButtons)) {
            option = NELEMS(sMainMenuButtons) - 1;
        }

        if (option == data->currentOption) {
            break;
        }

        if (data->optionIds[option] != 0) {
            PlaySE(SEQ_SE_DP_SELECT);
            break;
        }
    }
    data->currentOption = option;

    if (data->currentOption != oldOption) {
        MainMenu_HighlightOption(data, data->currentOption);
        data->optionChangeTimer = 6;
        return TRUE;
    }

    return FALSE;
}

static void MainMenu_ScrollToOption(MainMenuAppData *data, int option) {
    Window *window = &data->optionWindows[option];

    int optionY = (GetWindowY(window) - 1) * 8;
    int optionHeight = GetWindowHeight(window); // unused
    int screenY = data->effectiveScreenY / FX32_ONE;

    if (screenY <= optionY && screenY + GX_LCD_SIZE_Y > optionY) {
        return;
    }

    data->effectiveScreenY = optionY * FX32_ONE;

    MainMenu_UpdateArrowSprites(data);
    if (data->effectiveScreenY == FX32_CONST(GX_LCD_SIZE_Y * 2)) {
        FillBgTilemapRect(data->bgConfig, GF_BG_LYR_MAIN_0, 0x0, 0, 0, 32, 12, 0);
        FillBgTilemapRect(data->bgConfig, GF_BG_LYR_MAIN_2, 0x0, 0, 0, 32, 12, 0);
        ScheduleBgTilemapBufferTransfer(data->bgConfig, GF_BG_LYR_MAIN_0);
        ScheduleBgTilemapBufferTransfer(data->bgConfig, GF_BG_LYR_MAIN_2);
    } else if (data->effectiveScreenY == 0) {
        MainMenu_DrawOptionWindows(data);
    }
}

static void MainMenu_UpdateArrowSprites(MainMenuAppData *data) {
    BOOL upArrowEnabled;
    BOOL downArrowEnabled;

    downArrowEnabled = FALSE;
    upArrowEnabled = FALSE;
    int screenY = data->effectiveScreenY / FX32_ONE;

    for (int i = 0; i < NELEMS(data->optionWindows); i++) {
        Window *window = &data->optionWindows[i];
        if (!WindowIsInUse(window)) {
            continue;
        }

        int optionY = (GetWindowY(window) - 1) * 8;
        int optionHeight = GetWindowHeight(window); // unused

        if (screenY > optionY) {
            upArrowEnabled = TRUE;
        }

        if (screenY + GX_LCD_SIZE_Y <= optionY) {
            downArrowEnabled = TRUE;
        }
    }

    Sprite_SetAnimCtrlSeq(data->upArrowSprite, upArrowEnabled * 2);
    Sprite_SetAnimActiveFlag(data->upArrowSprite, FALSE);
    Sprite_SetAnimCtrlSeq(data->downArrowSprite, downArrowEnabled * 2 + 1);
    Sprite_SetAnimActiveFlag(data->downArrowSprite, FALSE);
}

static void MainMenu_FreeGraphics(OverlayManager *manager) {
    MainMenuAppData *data = OverlayManager_GetData(manager);

    if (data->upArrowSprite != NULL || data->downArrowSprite != NULL) {
        Sprite_Delete(data->upArrowSprite);
        Sprite_Delete(data->downArrowSprite);
        MainMenuUtil_FreeSprites();
    }

    for (u32 i = 0; i < NELEMS(data->optionWindows); i++) {
        if (data->optionWindows[i].bgConfig != NULL) {
            ClearWindowTilemapAndCopyToVram(&data->optionWindows[i]);
            RemoveWindow(&data->optionWindows[i]);
        }
    }

    FreeBgTilemapBuffer(data->bgConfig, GF_BG_LYR_MAIN_0);
    FreeBgTilemapBuffer(data->bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(data->bgConfig, GF_BG_LYR_MAIN_2);

    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);

    Heap_Free(data->bgConfig);
    Main_SetVBlankIntrCB(NULL, NULL);
}

static void AdvanceButtonBorderAnimation(MainMenuAppData *data) {
    static u16 sButtonBorderAnimation[] = {
        RGB(1, 28, 20),
        RGB(3, 28, 20),
        RGB(5, 28, 20),
        RGB(7, 28, 20),
        RGB(9, 28, 20),
        RGB(11, 28, 20),
        RGB(13, 28, 20),
        RGB(15, 28, 20),
        RGB(17, 28, 20),
        RGB(19, 28, 20),
        RGB(21, 28, 20),
        RGB(23, 28, 20),
        RGB(25, 28, 20),
        RGB(27, 28, 20),
        RGB(29, 28, 20),
        RGB(31, 28, 20),
        RGB(29, 28, 20),
        RGB(27, 28, 20),
        RGB(25, 28, 20),
        RGB(23, 28, 20),
        RGB(21, 28, 20),
        RGB(19, 28, 20),
        RGB(17, 28, 20),
        RGB(15, 28, 20),
        RGB(13, 28, 20),
        RGB(11, 28, 20),
        RGB(9, 28, 20),
        RGB(7, 28, 20),
        RGB(5, 28, 20),
        RGB(3, 28, 20),
        0,
    };

    if (sButtonBorderAnimation[data->buttonBorderAnimFrame] == 0) {
        data->buttonBorderAnimFrame = 0;
    }
    ((vu16 *)HW_PLTT)[54] = sButtonBorderAnimation[data->buttonBorderAnimFrame++];
}

static void MainMenu_OnVBlank(BgConfig *bgConfig) {
    GF_RunVramTransferTasks();
    OamManager_ApplyAndResetBuffers();
    DoScheduledBgGpuUpdates(bgConfig);
    OS_SetIrqCheckFlag(OS_IE_VBLANK);
}

BOOL MainMenuApp_Init(OverlayManager *manager, int *state) {
    Heap_Create(HEAP_ID_3, HEAP_ID_MAIN_MENU, 0x40000);

    MainMenuAppData *data = OverlayManager_CreateAndGetData(manager, sizeof(MainMenuAppData), HEAP_ID_MAIN_MENU);
    memset(data, 0, sizeof(MainMenuAppData));

    data->bgConfig = BgConfig_Alloc(HEAP_ID_MAIN_MENU);

    SetMasterBrightnessByColor(PM_LCD_TOP, RGB_BLACK);
    SetMasterBrightnessByColor(PM_LCD_BOTTOM, RGB_BLACK);

    MainOverlayArgs *args = OverlayManager_GetArgs(manager);
    data->saveData = args->saveData;

    data->mysteryGift = Save_MysteryGift_Get(data->saveData);
    data->currentScreenY = 0;
    data->effectiveScreenY = 0;
    data->profile = Save_PlayerData_GetProfile(data->saveData);
    data->pokedex = Save_Pokedex_Get(data->saveData);
    data->igt = Save_PlayerData_GetIGTAddr(data->saveData);
    data->hasPokedex = Pokedex_IsEnabled(data->pokedex);
    data->badges = PlayerProfile_CountBadges(data->profile);
    data->noticeState = 15;

    MainMenuUtil_InitWork(HEAP_ID_MAIN_MENU);
    if (!Save_FileExists(data->saveData)) {
        data->dontHaveSavedata = TRUE;
    }
    Sound_SetBGMPlayerChannels(0);
    Sound_SetScene(SOUND_SCENE_NONE);

    return TRUE;
}

#define MAIN_MENU_BACKGROUND_COLOR RGB(12, 12, 31)

BOOL MainMenuApp_Main(OverlayManager *manager, int *state) {
    MainMenuAppData *data = OverlayManager_GetData(manager);
    data->frames++;
    BOOL cartInserted = CTRDG_IsExisting(); // unused

    if (MainMenu_UpdateNoticeBoxes(data) == TRUE) {
        MainMenu_UpdateBeaconWatch(data);
        HandleScreenScroll(data);
        return FALSE;
    }

    AdvanceButtonBorderAnimation(data);

    if (data->optionChangeTimer != 0) {
        data->optionChangeTimer--;
    }

    switch (*state) {
    case 0:
        MainMenu_SetupGraphics(data);
        *state = 1;
        break;
    case 1:
        if (MainMenu_AlwaysZero(data) == 0) { // always 0
            *state = 3;
        } else {
            MainMenuUtil_StartFade(FADE_TYPE_BRIGHTNESS_IN, 2, state, 8);
            ((vu16 *)HW_PLTT)[0] = MAIN_MENU_BACKGROUND_COLOR;
        }
        break;
    case 2:
        if (!MainMenu_PrintWifiInfoErasedWarning(data)) {
            MainMenuUtil_StartFade(FADE_TYPE_BRIGHTNESS_OUT, 3, state, 8);
        }
        break;
    case 3:
        data->beaconWatchState = 12;
        if (data->dontHaveSavedata == TRUE) {
            data->selectedApp = APPOPTION_NEW_GAME;
            MainMenuUtil_StartFade(FADE_TYPE_BRIGHTNESS_OUT, 7, state, 8);
        } else {
            DetectInsertedGBACart(data);
            *state = 4;
        }
        break;
    case 4:
        MainMenu_SetupSprites(data);
        MainMenu_SetupWifiTiles(data);
        Main_SetVBlankIntrCB((GFIntrCB)MainMenu_OnVBlank, data->bgConfig);
        MainMenu_DrawOptionWindows(data);
        MainMenu_HighlightOption(data, data->currentOption);
        MainMenuUtil_StartFade(FADE_TYPE_BRIGHTNESS_IN, 5, state, 8);
        ((vu16 *)HW_PLTT)[0] = MAIN_MENU_BACKGROUND_COLOR;
        data->beaconWatchState = 10;
        break;
    case 5:
        MainMenu_HandleInput(data, state);
        if (data->redrawOptions == TRUE) {
            MainMenu_DrawOptionWindows(data);
            data->redrawOptions = FALSE;
        } else if (*state == 5 && data->noticePending == TRUE) {
            data->noticePending = FALSE;
            data->noticeDelay = 1;
        }
        break;
    case 6:
        if (data->noticeState == 15) {
            if (data->noticeInput & PAD_BUTTON_B) {
                *state = 5;
            } else {
                MainMenuUtil_StartFade(FADE_TYPE_BRIGHTNESS_OUT, 7, state, 8);
            }
        }
        break;
    case 7:
        MainMenu_FreeGraphics(manager);
        return TRUE;
    case 8: // Wait for palette fade
        MainMenuUtil_WaitFade(state);
        break;
    case 9: // Unused exit state
        return TRUE;
    }

    MainMenu_UpdateBeaconWatch(data);
    HandleScreenScroll(data);
    MainMenuUtil_UpdateSprites();
    return FALSE;
}

static void MainMenu_QueueSelectedApp(MainMenuAppData *data) {
    FS_EXTERN_OVERLAY(OVY_75);
    FS_EXTERN_OVERLAY(OVY_112);

    switch (data->selectedApp) {
    case APPOPTION_CONTINUE:
        RegisterMainOverlay(FS_OVERLAY_ID(OVY_36), &ov36_App_MainMenu_SelectOption_Continue);
        break;
    case APPOPTION_NEW_GAME:
        RegisterMainOverlay(FS_OVERLAY_ID(OVY_36), &ov36_App_MainMenu_SelectOption_NewGame);
        break;
    case APPOPTION_MYSTERY_GIFT:
        RegisterMainOverlay(FS_OVERLAY_ID(OVY_74), &gApp_MainMenu_SelectOption_MysteryGift);
        break;
    case APPOPTION_MIGRATE_AGB:
        RegisterMainOverlay(FS_OVERLAY_ID(OVY_74), &gApp_MainMenu_SelectOption_MigrateFromAgb);
        break;
    case APPOPTION_RANGER:
        RegisterMainOverlay(FS_OVERLAY_ID(OVY_74), &gApp_MainMenu_SelectOption_ConnectToRanger);
        break;
    case APPOPTION_CONNECT_TO_WII:
        SystemCard_RebootIntoFile("data/eoo.dat");
        break;
    case APPOPTION_WFC:
        Sound_Stop();
        RegisterMainOverlay(FS_OVERLAY_ID_NONE, &gApp_MainMenu_SelectOption_NintendoWFCSetup);
        break;
    case APPOPTION_POKEWALKER:
        Sound_Stop();
        RegisterMainOverlay(FS_OVERLAY_ID(OVY_112), &ov112_App_MainMenu_SelectOption_ConnectToPokewalker);
        break;
    case APPOPTION_WII_SETTINGS:
        Sound_Stop();
        RegisterMainOverlay(FS_OVERLAY_ID(OVY_75), &gApp_MainMenu_SelectOption_WiiMessageSettings);
        break;
    case APPOPTION_TITLE_SCREEN:
        RegisterMainOverlay(FS_OVERLAY_ID(intro_title), &gApplication_TitleScreen);
        break;
    }
}

BOOL MainMenuApp_Exit(OverlayManager *manager, int *state) {
    MainMenuAppData *data = OverlayManager_GetData(manager);

    MainMenu_QueueSelectedApp(data);

    OverlayManager_FreeData(manager);
    Heap_Destroy(HEAP_ID_MAIN_MENU);

    MainMenuUtil_EnableCartridgePullOutCheck(FALSE);

    return TRUE;
}
