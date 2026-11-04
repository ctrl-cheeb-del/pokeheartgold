#include "global.h"

#include "constants/pokemon.h"
#include "constants/sndseq.h"

#include "dwc/net_common_internal.h"
#include "gts/gts_internal.h"
#include "gts/gts_server.h"
#include "msgdata/msg/msg_0775.h"

#include "bg_window.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "options.h"
#include "pokemon.h"
#include "render_window.h"
#include "save_gts.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "sprite.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"
#include "wireless_status_icon.h"
#include "yes_no_prompt.h"

typedef struct GtsWindowPosition {
    u16 x;
    u16 y;
} GtsWindowPosition;

// What search.asp is asked when the player recently deposited or traded (two more results per date).
typedef struct GtsSearchRequestEx {
    GtsWantedMon wanted;
    u8 count;
    u8 country;
} GtsSearchRequestEx;

typedef struct GtsSearchButtonCell {
    u8 column;
    u8 row;
} GtsSearchButtonCell;

typedef struct GtsSearchCursorPosition {
    u16 x;
    u16 y;
    u16 anim;
} GtsSearchCursorPosition;

static void GtsSearch_InitBgs(BgConfig *bgConfig);
static void GtsSearch_FreeBgs(BgConfig *bgConfig);
static void GtsSearch_LoadGraphics(GtsApp *app);
static void GtsSearch_CreateSprites(GtsApp *app);
static void GtsSearch_DeleteSprites(GtsApp *app);
static void GtsSearch_CreateWindows(GtsApp *app);
static void GtsSearch_RemoveWindows(GtsApp *app);
static void GtsSearch_CreateData(GtsApp *app);
static void GtsSearch_FreeData(GtsApp *app);
static enum GtsAppState GtsSearch_Start(GtsApp *app);
static int GtsSearch_GetTouchedButton(void);
static void GtsSearch_SelectButton(GtsApp *app, int button);
static enum GtsAppState GtsSearch_HandleInput(GtsApp *app);
static enum GtsAppState GtsSearch_StartSearch(GtsApp *app);
static BOOL GtsSearch_IsDateRecent(GtsApp *app, int which);
static enum GtsAppState GtsSearch_SendSearch(GtsApp *app);
static enum GtsAppState GtsSearch_WaitSearch(GtsApp *app);
static enum GtsAppState GtsSearch_ShowResultCount(GtsApp *app);
static enum GtsAppState GtsSearch_WaitResultsShown(GtsApp *app);
static enum GtsAppState GtsSearch_SearchFailed(GtsApp *app);
static enum GtsAppState GtsSearch_ServerError(GtsApp *app);
static enum GtsAppState GtsSearch_ServerErrorExit(GtsApp *app);
static int GtsSearch_GetCursorButton(GtsApp *app);
static void GtsSearch_MoveCursor(GtsApp *app);
static void GtsSearch_SetCursor(GtsApp *app, int button);
static enum GtsAppState GtsSearch_FadeOut(GtsApp *app);
static enum GtsAppState GtsSearch_AskSpecies(GtsApp *app);
static enum GtsAppState GtsSearch_OpenSpeciesSelector(GtsApp *app);
static enum GtsAppState GtsSearch_HandleSpeciesSelector(GtsApp *app);
static enum GtsAppState GtsSearch_AskGender(GtsApp *app);
static enum GtsAppState GtsSearch_OpenGenderSelector(GtsApp *app);
static enum GtsAppState GtsSearch_HandleGenderSelector(GtsApp *app);
static enum GtsAppState GtsSearch_AskLevel(GtsApp *app);
static enum GtsAppState GtsSearch_OpenLevelSelector(GtsApp *app);
static enum GtsAppState GtsSearch_HandleLevelSelector(GtsApp *app);
static enum GtsAppState GtsSearch_AskCountry(GtsApp *app);
static enum GtsAppState GtsSearch_OpenCountrySelector(GtsApp *app);
static enum GtsAppState GtsSearch_HandleCountrySelector(GtsApp *app);
static enum GtsAppState GtsSearch_ShowExitPrompt(GtsApp *app);
static enum GtsAppState GtsSearch_HandleExitPrompt(GtsApp *app);
static enum GtsAppState GtsSearch_ReturnToInput(GtsApp *app);

void CommState_ShowRestartErrorAndHalt(void);

static GtsSearchButtonCell sGtsSearchButtonCells[] = {
    { 0, 0 },
    { 0, 1 },
    { 0, 2 },
    { 0, 3 },
    { 1, 0 },
    { 1, 1 },
    { 1, 2 },
};

static const GtsWindowPosition sGtsSearchLineWindowPositions[2] = {
    { 1, 16 },
    { 2, 18 },
};

static const GtsWindowPosition sGtsSearchValueWindowPositions[3] = {
    { 22, 8  },
    { 22, 13 },
    { 22, 3  },
};

static const GtsWindowPosition sGtsSearchFieldWindowPositions[6] = {
    { 1, 1  },
    { 2, 3  },
    { 1, 6  },
    { 2, 8  },
    { 1, 11 },
    { 2, 13 },
};

static GtsSearchCursorPosition sGtsSearchCursorPositions[] = {
    { 0, 0, 45 },
    { 0, 40, 45 },
    { 0, 80, 45 },
    { 0, 120, 45 },
    { 192, 32, 46 },
    { 192, 72, 46 },
    { 192, 112, 46 },
};

static enum GtsAppState (*sGtsSearchStates[])(GtsApp *app) = {
    GtsSearch_Start,
    GtsSearch_HandleInput,
    GtsSearch_FadeOut,
    GtsSearch_AskSpecies,
    GtsSearch_OpenSpeciesSelector,
    GtsSearch_HandleSpeciesSelector,
    GtsSearch_AskGender,
    GtsSearch_OpenGenderSelector,
    GtsSearch_HandleGenderSelector,
    GtsSearch_AskLevel,
    GtsSearch_OpenLevelSelector,
    GtsSearch_HandleLevelSelector,
    GtsSearch_AskCountry,
    GtsSearch_OpenCountrySelector,
    GtsSearch_HandleCountrySelector,
    GtsSearch_StartSearch,
    GtsSearch_SendSearch,
    GtsSearch_WaitSearch,
    GtsSearch_ShowResultCount,
    GtsSearch_WaitResultsShown,
    GtsSearch_SearchFailed,
    GtsSearch_WaitText,
    GtsSearch_WaitTextAndPause,
    GtsSearch_ShowExitPrompt,
    GtsSearch_HandleExitPrompt,
    GtsSearch_ReturnToInput,
    GtsSearch_PrintSearchFailed,
    GtsSearch_ServerError,
    GtsSearch_ServerErrorExit,
    GtsSearch_ScrollOut,
    GtsSearch_ScrollIn,
    GtsSearch_HandleScrolledOut,
};

static const BgTemplate sGtsSearchBg2Template = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0x1000,
    .charBase = GX_BG_CHARBASE_0x08000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sGtsSearchBg0Template = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0x0000,
    .charBase = GX_BG_CHARBASE_0x04000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sGtsSearchBg3Template = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0x1800,
    .charBase = GX_BG_CHARBASE_0x1c000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 2,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sGtsSearchBg1Template = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0x0800,
    .charBase = GX_BG_CHARBASE_0x0c000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 3,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const TouchscreenHitbox sGtsSearchButtonHitboxes[8] = {
    { .rect = { 3, 41, 2, 99 } },
    { .rect = { 43, 81, 2, 99 } },
    { .rect = { 83, 121, 2, 99 } },
    { .rect = { 123, 161, 2, 99 } },
    { .rect = { 19, 45, 145, 255 } },
    { .rect = { 58, 85, 145, 255 } },
    { .rect = { 98, 125, 145, 255 } },
    { .rect = { TOUCHSCREEN_RECTLIST_END } },
};

enum GtsAppState GtsSearch_Init(GtsApp *app, int state) {
    GtsSelectorArgs args;

    GtsSearch_CreateData(app);
    GtsSearch_InitBgs(app->bgConfig);
    GtsSearch_LoadGraphics(app);
    GtsSearch_CreateWindows(app);
    GtsSearch_CreateSprites(app);
    args.bgConfig = app->bgConfig;
    args.windows = app->windows;
    args.messageWindow = &app->selectorWindow;
    args.sprites[0] = app->selectorCursorSprite;
    args.sprites[1] = app->arrowSprites[0];
    args.sprites[2] = app->arrowSprites[1];
    args.sprites[3] = app->cursorSprite;
    args.gtsMsgData = app->gtsMsgData;
    args.speciesNames = app->speciesNames;
    args.countryNames = app->countryNames;
    args.pokedex = app->args->pokedex;
    args.johtoDexFlags = app->searchCursor->johtoDexFlags;
    app->selector = GtsSelector_New(&args, GF_BG_LYR_MAIN_2, 1);
    GtsSearch_DrawFieldLabels(app->infoWindows, &app->wideWindows[0], app->gtsMsgData);
    GtsSearch_DrawResultsButton(app->bgConfig, &app->infoWindows[8], app->gtsMsgData, app->hasSearchResults);
    Gts_PrintSpeciesName(&app->infoWindows[1], app->speciesNames, app->searchCriteria.species, 0, 0, MAKE_TEXT_COLOR(1, 2, 0));
    Gts_PrintGender(&app->infoWindows[3], app->gtsMsgData, app->searchCriteria.gender, TRUE, 0, 0, MAKE_TEXT_COLOR(1, 2, 0));
    Gts_PrintLevelRange(&app->infoWindows[5], app->gtsMsgData, Gts_FindLevelRange(app->searchCriteria.minLevel, app->searchCriteria.maxLevel, 1), 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 1);
    Gts_PrintCountryName(&app->wideWindows[1], app->countryNames, app->gtsMsgData, app->searchCountry, 0, 0, MAKE_TEXT_COLOR(1, 2, 0));
    app->vblankFunc = GtsSearch_ScrollBgs;
    if (app->nextScreenArg == 13) {
        BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_61);
    }
    app->state = GTS_SEARCH_STATE_START;
    return GTS_APP_STATE_WAIT_FADE_IN;
}

enum GtsAppState GtsSearch_Main(GtsApp *app, int state) {
    enum GtsAppState ret = sGtsSearchStates[app->state](app);
    int i;
    int x;
    int y;

    for (i = 0; i < 8; i++) {
        Gts_SetSpritePosition(app->avatarSprites[i], app->avatarPositions[i][0], app->scrollY + app->avatarPositions[i][1]);
        Gts_SetSpritePosition(app->panelSprite, 55, app->scrollY + 424);
    }
    x = GtsSearch_GetCursorButton(app);
    y = GtsSearch_GetCursorButton(app);
    Gts_SetSpritePosition(app->cursorSprite, sGtsSearchCursorPositions[x].x, sGtsSearchCursorPositions[y].y - app->scrollY);
    return ret;
}

enum GtsAppState GtsSearch_Exit(GtsApp *app, int state) {
    app->vblankFunc = NULL;
    GtsSelector_Delete(app->selector);
    GtsSearch_DeleteSprites(app);
    GtsSearch_FreeData(app);
    GtsSearch_RemoveWindows(app);
    GtsSearch_FreeBgs(app->bgConfig);
    Sprite_SetDrawFlag(app->panelSprite, FALSE);
    Gts_SwitchScreen(app);
    return GTS_APP_STATE_INIT_SCREEN;
}

static void GtsSearch_InitBgs(BgConfig *bgConfig) {
    BgTemplate bg0 = sGtsSearchBg0Template;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &bg0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    {
        BgTemplate bg1 = sGtsSearchBg1Template;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &bg1, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    }
    {
        BgTemplate bg2 = sGtsSearchBg2Template;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &bg2, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
    }
    {
        BgTemplate bg3 = sGtsSearchBg3Template;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &bg3, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
    }
    Gts_InitSubScreenBgs(bgConfig, 0, FALSE);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_2, 0x20, 0, HEAP_ID_61);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 0x20, 0, HEAP_ID_61);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_3, 0x20, 0, HEAP_ID_61);
}

static void GtsSearch_FreeBgs(BgConfig *bgConfig) {
    Gts_FreeSubScreenBgs(bgConfig);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_0);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_3);
}

static void GtsSearch_LoadGraphics(GtsApp *app) {
    BgConfig *bgConfig = app->bgConfig;
    NARC *narc = NARC_New(NARC_a_1_0_0, HEAP_ID_61);

    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 3, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x60, HEAP_ID_61);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 5, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x100, HEAP_ID_61);
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_13_OFFSET, HEAP_ID_61);
    LoadUserFrameGfx2(bgConfig, GF_BG_LYR_MAIN_0, 1, 14, Options_GetFrame(app->args->options), HEAP_ID_61);
    LoadUserFrameGfx1(bgConfig, GF_BG_LYR_MAIN_0, 0x1F, 11, 0, HEAP_ID_61);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 14, bgConfig, GF_BG_LYR_MAIN_1, 0, 0xA00, TRUE, HEAP_ID_61);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 29, bgConfig, GF_BG_LYR_MAIN_1, 0, 0x600, TRUE, HEAP_ID_61);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 15, bgConfig, GF_BG_LYR_MAIN_2, 0, 0x600, TRUE, HEAP_ID_61);
    LoadFontPal1(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_1_OFFSET, HEAP_ID_61);
    Gts_ShowSubScreenPanel(app);
    NARC_Delete(narc);
}

// The cursor and the selector's sprites.
static void GtsSearch_CreateSprites(GtsApp *app) {
    SpriteTemplate template;

    Gts_InitSpriteTemplate(&template, app, &app->headers[0], NNS_G2D_VRAM_TYPE_2DMAIN);
    template.position.x = sGtsSearchCursorPositions[0].x << FX32_SHIFT;
    template.position.y = sGtsSearchCursorPositions[0].y << FX32_SHIFT;
    app->cursorSprite = Sprite_CreateAffine(&template);
    Sprite_SetAnimActiveFlag(app->cursorSprite, TRUE);
    Sprite_SetAnimCtrlSeq(app->cursorSprite, 45);
    Sprite_SetPriority(app->cursorSprite, 1);
    Sprite_SetOamMode(app->cursorSprite, GX_OAM_MODE_XLU);

    template.position.x = 10 << 16;
    template.position.y = 2 << 16;
    app->selectorCursorSprite = Sprite_CreateAffine(&template);
    Sprite_SetAnimCtrlSeq(app->selectorCursorSprite, 47);
    Sprite_SetDrawFlag(app->selectorCursorSprite, FALSE);

    template.position.x = 57 << 14;
    template.position.y = 117 * FX32_ONE;
    app->arrowSprites[0] = Sprite_CreateAffine(&template);
    Sprite_SetAnimCtrlSeq(app->arrowSprites[0], 38);
    Sprite_SetDrawFlag(app->arrowSprites[0], FALSE);

    template.position.x = 35 << 14;
    app->arrowSprites[1] = Sprite_CreateAffine(&template);
    Sprite_SetAnimCtrlSeq(app->arrowSprites[1], 39);
    Sprite_SetDrawFlag(app->arrowSprites[1], FALSE);
    WirelessStatusIcon_Create();
}

static void GtsSearch_DeleteSprites(GtsApp *app) {
    Sprite_Delete(app->cursorSprite);
    Sprite_Delete(app->selectorCursorSprite);
    Sprite_Delete(app->arrowSprites[0]);
    Sprite_Delete(app->arrowSprites[1]);
}

// The message window; the field labels and values (infoWindows[0..5]), the two wide lines (wideWindows) and three
// more windows (infoWindows[6..8]).
static void GtsSearch_CreateWindows(GtsApp *app) {
    int i;
    int baseTile;
    const GtsWindowPosition *position;
    Window *window;

    AddWindowParameterized(app->bgConfig, &app->waitingIconWindow, GF_BG_LYR_MAIN_0, 2, 21, 27, 2, 13, 96);
    FillWindowPixelBuffer(&app->waitingIconWindow, 0);
    position = sGtsSearchFieldWindowPositions;
    i = 0;
    baseTile = 1;
    window = app->infoWindows;
    for (; i < 6; i++, baseTile += 22, position++, window++) {
        AddWindowParameterized(app->bgConfig, window, GF_BG_LYR_MAIN_3, position->x, position->y, 11, 2, 13, baseTile);
        FillWindowPixelBuffer(window, 0);
    }
    position = sGtsSearchLineWindowPositions;
    i = 0;
    baseTile = 133;
    window = app->wideWindows;
    for (; i < 2; i++, baseTile += 56, position++, window++) {
        AddWindowParameterized(app->bgConfig, window, GF_BG_LYR_MAIN_3, position->x, position->y, 28, 2, 13, baseTile);
        FillWindowPixelBuffer(window, 0);
    }
    i = 0;
    window = app->infoWindows;
    baseTile = 285;
    position = sGtsSearchValueWindowPositions;
    for (; i < 3; i++, baseTile += 20, position++) {
        int index = i + 6;
        AddWindowParameterized(app->bgConfig, &window[index], GF_BG_LYR_MAIN_3, position->x, position->y, 10, 2, 13, baseTile);
        FillWindowPixelBuffer(&window[index], 0);
    }
    Gts_CreatePanelWindow(app, 4);
}

static void GtsSearch_RemoveWindows(GtsApp *app) {
    int i;
    Window *window;

    RemoveWindow(&app->panelWindow);
    RemoveWindow(&app->waitingIconWindow);
    for (i = 0, window = app->infoWindows; i < 9; i++, window++) {
        RemoveWindow(window);
    }
    for (i = 0, window = app->wideWindows; i < 2; i++, window++) {
        RemoveWindow(window);
    }
}

static void GtsSearch_CreateData(GtsApp *app) {
    app->msgBuffer = String_New(180, HEAP_ID_61);
    app->titleString = NewString_ReadMsgData(app->gtsMsgData, msg_0775_00042); // SEEK POKEMON
    app->searchCursor = Heap_Alloc(HEAP_ID_61, sizeof(GtsSearchCursor));
    MIi_CpuClearFast(0, (u32 *)app->searchCursor, sizeof(GtsSearchCursor));
    app->searchCursor->johtoDexFlags = Gts_CreateJohtoDexFlags(HEAP_ID_61);
    GtsCursorValueTable_Clear(&app->unk_1234);
}

static void GtsSearch_FreeData(GtsApp *app) {
    Heap_Free(app->searchCursor->johtoDexFlags);
    Heap_Free(app->searchCursor);
    String_Delete(app->msgBuffer);
    String_Delete(app->titleString);
}

static enum GtsAppState GtsSearch_Start(GtsApp *app) {
    if (app->nextScreenArg == 15) {
        GtsSearch_PrintMessage(app, msg_0775_00032, 0, 0, 0xF0F); // Touch "SELECT" to set trade partner.
        if (GX_GetMasterBrightness() == -16) {
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 16, 1, HEAP_ID_61);
            app->state = GTS_SEARCH_STATE_SCROLL_IN;
        } else {
            app->state = GTS_SEARCH_STATE_HANDLE_INPUT;
        }
    } else {
        GtsSearch_PrintMessage(app, msg_0775_00008, 1, 0, 0xF0F); // What kind of Pokemon are you seeking?
        Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_HANDLE_INPUT);
    }
    Sprite_SetDrawFlag(app->panelSprite, TRUE);
    return GTS_APP_STATE_RUN_SCREEN;
}

static int GtsSearch_GetTouchedButton(void) {
    return TouchscreenHitbox_FindRectAtTouchNew(sGtsSearchButtonHitboxes);
}

// Buttons: 0 POKEMON, 1 GENDER, 2 LEVEL, 3 country, 4 the results, 5 SEARCH, 6 BACK.
static void GtsSearch_SelectButton(GtsApp *app, int button) {
    switch (button) {
    case 0:
        app->state = GTS_SEARCH_STATE_ASK_SPECIES;
        PlaySE(SEQ_SE_DP_SELECT);
        break;
    case 1:
        if (app->searchCriteria.species != SPECIES_NONE) {
            u32 genderRatio = GetMonBaseStat(app->searchCriteria.species, BASE_GENDER_RATIO);
            app->searchCursor->genderRatio = genderRatio;
            if (Gts_SetFixedGender(&app->searchCriteria, app->searchCursor->genderRatio)) {
                PlaySE(SEQ_SE_DP_SELECT);
                break;
            }
        }
        app->state = GTS_SEARCH_STATE_ASK_GENDER;
        PlaySE(SEQ_SE_DP_SELECT);
        break;
    case 2:
        app->state = GTS_SEARCH_STATE_ASK_LEVEL;
        PlaySE(SEQ_SE_DP_SELECT);
        break;
    case 3:
        app->state = GTS_SEARCH_STATE_ASK_COUNTRY;
        PlaySE(SEQ_SE_DP_SELECT);
        break;
    case 4:
        if (app->searchResultCount != 0) {
            app->state = GTS_SEARCH_STATE_SCROLL_OUT;
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 16, 1, HEAP_ID_61);
            PlaySE(SEQ_SE_DP_SELECT);
        }
        break;
    case 5:
        app->state = GTS_SEARCH_STATE_START_SEARCH;
        break;
    case 6:
        GtsSearch_PrintMessage(app, msg_0775_00015, 1, 0, 0xF0F); // Stop searching?
        Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_SHOW_EXIT_PROMPT);
        PlaySE(SEQ_SE_DP_SELECT);
        break;
    }
}

static enum GtsAppState GtsSearch_HandleInput(GtsApp *app) {
    int button = GtsSearch_GetTouchedButton();
    if (button != -1) {
        GtsSearch_SetCursor(app, button);
        GtsSearch_SelectButton(app, button);
    } else {
        GtsSearch_MoveCursor(app);
        if (gSystem.newKeys & PAD_BUTTON_A) {
            GtsSearch_SelectButton(app, GtsSearch_GetCursorButton(app));
        } else if (gSystem.newKeys & PAD_BUTTON_B) {
            GtsSearch_PrintMessage(app, msg_0775_00015, 1, 0, 0xF0F); // Stop searching?
            Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_SHOW_EXIT_PROMPT);
            PlaySE(SEQ_SE_DP_SELECT);
        }
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_StartSearch(GtsApp *app) {
    if (app->searchCriteria.species == SPECIES_NONE) {
        GtsSearch_PrintMessage(app, msg_0775_00012, 1, 0, 0xF0F); // Please choose the Pokemon you want!
        Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_HANDLE_INPUT);
        PlaySE(SEQ_SE_DP_BOX03);
    } else if (GtsSearch_IsSameSearch(&app->searchCriteria, &app->lastSearch, app->searchCountry, app->lastSearchCountry)) {
        GtsSearch_PrintMessage(app, msg_0775_00033, 1, 0, 0xF0F); // Please change your conditions.
        Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_HANDLE_INPUT);
        PlaySE(SEQ_SE_DP_BOX03);
    } else {
        PlaySE(SEQ_SE_DP_Z_SEARCH);
        GtsSearch_PrintMessage(app, msg_0775_00013, 1, 0, 0xF0F); // Searching for the Pokemon you want...
        Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_SEND_SEARCH);
        Gts_StopAvatarAnims(app);
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

// Whether the player deposited (which 1) or traded (which 0) on the GTS in the last three days.
static BOOL GtsSearch_IsDateRecent(GtsApp *app, int which) {
    RTCDate saved;
    RTCDate current;
    RTCTime time;
    u32 packed;
    s32 days;

    if (which == 1) {
        packed = GtsSave_GetTradeDate(app->args->gtsSave);
    } else {
        packed = GtsSave_GetDepositDate(app->args->gtsSave);
    }
    saved.year = (packed >> 24) & 0xFF;
    saved.month = (packed >> 16) & 0xFF;
    saved.day = (packed >> 8) & 0xFF;
    saved.week = (RTCWeek)(packed & 0xFF);
    DWC_GetDateTime(&current, &time);
    days = RTC_ConvertDateToDay(&current) - RTC_ConvertDateToDay(&saved);
    return days >= 0 && days < 3;
}

// Three results, two more for each recent deposit or trade.
static enum GtsAppState GtsSearch_SendSearch(GtsApp *app) {
    int count = 3;
    GtsSearchRequestEx request;

    if (GtsSearch_IsDateRecent(app, 1)) {
        count += 2;
    }
    if (GtsSearch_IsDateRecent(app, 0)) {
        count += 2;
    }
    if (app->searchCountry == 0) {
        GtsServer_RequestSearch(&app->searchCriteria, count, app->searchResults);
    } else {
        MI_CpuFill8(&request, 0, sizeof(request));
        request.wanted.species = app->searchCriteria.species;
        request.wanted.gender = app->searchCriteria.gender;
        request.wanted.minLevel = app->searchCriteria.minLevel;
        request.wanted.maxLevel = app->searchCriteria.maxLevel;
        request.wanted.unk_5 = app->searchCriteria.unk_5;
        request.count = count;
        request.country = app->searchCountry;
        GtsServer_RequestSearchEx(&request, app->searchResults);
    }
    *(u16 *)&app->lastSearch.species = *(u16 *)&app->searchCriteria.species;
    *(u16 *)&app->lastSearch.gender = *(u16 *)&app->searchCriteria.gender;
    *(u16 *)&app->lastSearch.maxLevel = *(u16 *)&app->searchCriteria.maxLevel;
    app->lastSearchCountry = app->searchCountry;
    app->requestFrames = 0;
    app->state = GTS_SEARCH_STATE_WAIT_SEARCH;
    app->hasSearchResults = FALSE;
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_WaitSearch(GtsApp *app) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        app->requestFrames = 0;
        switch (result) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            app->searchResultCount = result;
            StopSE(SEQ_SE_DP_Z_SEARCH, 0);
            Gts_ShowResultAvatars(app, result, TRUE);
            if (result == 0) {
                GtsSearch_DrawResultsButton(app->bgConfig, &app->infoWindows[8], app->gtsMsgData, FALSE);
            } else {
                GtsSearch_DrawResultsButton(app->bgConfig, &app->infoWindows[8], app->gtsMsgData, TRUE);
            }
            app->state = GTS_SEARCH_STATE_SHOW_RESULT_COUNT;
            break;
        case -14:
        case -2:
            app->state = GTS_SEARCH_STATE_SERVER_ERROR;
            break;
        case -13:
            CommState_ShowRestartErrorAndHalt();
            break;
        case -15:
        case -12:
            app->state = GTS_SEARCH_STATE_SEARCH_FAILED;
            break;
        }
    } else {
        app->requestFrames++;
        if (app->requestFrames == 60 * 60) {
            CommState_ShowRestartErrorAndHalt();
        }
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_ShowResultCount(GtsApp *app) {
    if (app->searchResultCount == 0) {
        GtsSearch_PrintMessage(app, msg_0775_00014, 1, 0, 0xF0F); // None were found!
        Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_HANDLE_INPUT);
        PlaySE(SEQ_SE_DP_BOX03);
    } else {
        GtsSearch_PrintMessage(app, msg_0775_00030, 1, 0, 0xF0F); // A trade partner has been found!
        Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_WAIT_RESULTS_SHOWN);
        app->waitFrames = 0;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_WaitResultsShown(GtsApp *app) {
    app->waitFrames++;
    if (app->waitFrames > 45) {
        GtsSearch_PrintMessage(app, msg_0775_00032, 1, 0, 0xF0F); // Touch "SELECT" to set trade partner.
        Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_HANDLE_INPUT);
        app->hasSearchResults = TRUE;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_SearchFailed(GtsApp *app) {
    app->lastSearch.species = SPECIES_NONE;
    GtsSearch_PrintMessage(app, msg_0775_00038, 1, 0, 0xF0F); // GTS check failed.
    Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_HANDLE_INPUT);
    PlaySE(SEQ_SE_DP_BOX03);
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_ServerError(GtsApp *app) {
    GtsSearch_PrintMessage(app, msg_0775_00153, 4, 0, 0xF0F);
    Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT_AND_PAUSE, GTS_SEARCH_STATE_SERVER_ERROR_EXIT);
    app->waitFrames = 0;
    PlaySE(SEQ_SE_DP_BOX03);
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_ServerErrorExit(GtsApp *app) {
    GtsSearch_PrintMessage(app, msg_0775_00158, 4, 0, 0xF0F);
    Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT_AND_PAUSE, GTS_SEARCH_STATE_FADE_OUT);
    Gts_SetNextScreen(app, GTS_SCREEN_CONNECTION, 0);
    PlaySE(SEQ_SE_DP_BOX03);
    return GTS_APP_STATE_RUN_SCREEN;
}

// The button under the cursor: rows 0..3 of the left column, then rows 0..2 of the right one.
static int GtsSearch_GetCursorButton(GtsApp *app) {
    GtsSearchCursor *cursor = app->searchCursor;
    if (cursor->column == 0) {
        return cursor->leftRow;
    }
    return cursor->rightRow + 4;
}

static void GtsSearch_MoveCursor(GtsApp *app) {
    int keys = gSystem.newKeys;
    GtsSearchCursor *cursor;
    int x;
    int y;

    if (keys & PAD_KEY_UP) {
        cursor = app->searchCursor;
        if (cursor->column == 0) {
            if (cursor->leftRow > 0) {
                cursor->leftRow--;
                PlaySE(SEQ_SE_DP_SELECT);
            }
        } else {
            if (cursor->rightRow > 0) {
                PlaySE(SEQ_SE_DP_SELECT);
                app->searchCursor->rightRow--;
            }
        }
    } else if (keys & PAD_KEY_DOWN) {
        cursor = app->searchCursor;
        if (cursor->column == 0) {
            if (cursor->leftRow < 3) {
                cursor->leftRow++;
                PlaySE(SEQ_SE_DP_SELECT);
            }
        } else {
            if (cursor->rightRow < 2) {
                PlaySE(SEQ_SE_DP_SELECT);
                app->searchCursor->rightRow++;
            }
        }
    } else if (keys & PAD_KEY_RIGHT) {
        if (app->searchCursor->column != 1) {
            PlaySE(SEQ_SE_DP_SELECT);
        }
        app->searchCursor->column = 1;
    } else if (keys & PAD_KEY_LEFT) {
        if (app->searchCursor->column != 0) {
            PlaySE(SEQ_SE_DP_SELECT);
        }
        app->searchCursor->column = 0;
    }
    x = GtsSearch_GetCursorButton(app);
    y = GtsSearch_GetCursorButton(app);
    Gts_SetSpritePosition(app->cursorSprite, sGtsSearchCursorPositions[x].x, sGtsSearchCursorPositions[y].y);
    Sprite_SetAnimCtrlSeq(app->cursorSprite, sGtsSearchCursorPositions[GtsSearch_GetCursorButton(app)].anim);
}

static void GtsSearch_SetCursor(GtsApp *app, int button) {
    int x;
    int y;

    if (sGtsSearchButtonCells[button].column == 0) {
        app->searchCursor->column = 0;
        app->searchCursor->leftRow = sGtsSearchButtonCells[button].row;
    } else {
        app->searchCursor->column = 1;
        app->searchCursor->rightRow = sGtsSearchButtonCells[button].row;
    }
    x = GtsSearch_GetCursorButton(app);
    y = GtsSearch_GetCursorButton(app);
    Gts_SetSpritePosition(app->cursorSprite, sGtsSearchCursorPositions[x].x, sGtsSearchCursorPositions[y].y);
    y = GtsSearch_GetCursorButton(app);
    Sprite_SetAnimCtrlSeq(app->cursorSprite, sGtsSearchCursorPositions[y].anim);
}

static enum GtsAppState GtsSearch_FadeOut(GtsApp *app) {
    if (app->scrollY == 0) {
        BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_61);
    }
    app->state = GTS_SEARCH_STATE_START;
    return GTS_APP_STATE_EXIT_SCREEN;
}

static enum GtsAppState GtsSearch_AskSpecies(GtsApp *app) {
    GtsSearch_PrintMessage(app, msg_0775_00009, 1, 0, 0xF0F); // Please choose the Pokemon you want.
    Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_OPEN_SPECIES_SELECTOR);
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_OpenSpeciesSelector(GtsApp *app) {
    GtsSelector_Start(app->selector, GTS_SELECTOR_MODE_SPECIES);
    GtsSearch_SetBlendBrightness(9);
    app->state = GTS_SEARCH_STATE_HANDLE_SPECIES_SELECTOR;
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_HandleSpeciesSelector(GtsApp *app) {
    int selection = GtsSelector_Main(app->selector);
    switch (selection) {
    case GTS_SELECTOR_BACK:
        GtsSearch_SetBlendBrightness(0);
        app->state = GTS_SEARCH_STATE_START;
        GtsCursorValueTable_SetEntry(&app->unk_1234, app->searchCursor->unk_06 + app->searchCursor->unk_04, app->searchCursor->unk_0A, app->searchCursor->unk_08);
        break;
    case GTS_SELECTOR_NONE:
        break;
    default:
        GtsSearch_SetBlendBrightness(0);
        app->searchCriteria.species = selection;
        app->state = GTS_SEARCH_STATE_START;
        FillWindowPixelBuffer(&app->infoWindows[1], 0);
        Gts_PrintSpeciesName(&app->infoWindows[1], app->speciesNames, selection, 0, 0, MAKE_TEXT_COLOR(1, 2, 0));
        app->searchCursor->genderRatio = GetMonBaseStat(selection, BASE_GENDER_RATIO);
        GtsCursorValueTable_SetEntry(&app->unk_1234, app->searchCursor->unk_06 + app->searchCursor->unk_04, app->searchCursor->unk_0A, app->searchCursor->unk_08);
        if (Gts_SetFixedGender(&app->searchCriteria, app->searchCursor->genderRatio)) {
            FillWindowPixelBuffer(&app->infoWindows[3], 0);
            Gts_PrintGender(&app->infoWindows[3], app->gtsMsgData, app->searchCriteria.gender, TRUE, 0, 0, MAKE_TEXT_COLOR(1, 2, 0));
        }
        break;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_AskGender(GtsApp *app) {
    GtsSearch_PrintMessage(app, msg_0775_00010, 1, 0, 0xF0F); // Please choose its gender.
    Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_OPEN_GENDER_SELECTOR);
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_OpenGenderSelector(GtsApp *app) {
    GtsSelector_Start(app->selector, GTS_SELECTOR_MODE_GENDER);
    GtsSearch_SetBlendBrightness(9);
    app->state = GTS_SEARCH_STATE_HANDLE_GENDER_SELECTOR;
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_HandleGenderSelector(GtsApp *app) {
    u32 selection = GtsSelector_Main(app->selector);
    switch (selection) {
    case (u32)GTS_SELECTOR_BACK:
        GtsSearch_SetBlendBrightness(0);
        ClearFrameAndWindow2(&app->waitingIconWindow, FALSE);
        app->state = GTS_SEARCH_STATE_START;
        break;
    case 0:
    case 1:
    case 2:
        GtsSearch_SetBlendBrightness(0);
        app->searchCriteria.gender = selection + 1;
        app->state = GTS_SEARCH_STATE_START;
        FillWindowPixelBuffer(&app->infoWindows[3], 0);
        Gts_PrintGender(&app->infoWindows[3], app->gtsMsgData, app->searchCriteria.gender, TRUE, 0, 0, MAKE_TEXT_COLOR(1, 2, 0));
        break;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_AskLevel(GtsApp *app) {
    GtsSearch_PrintMessage(app, msg_0775_00011, 1, 0, 0xF0F); // Please choose the level.
    Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_OPEN_LEVEL_SELECTOR);
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_OpenLevelSelector(GtsApp *app) {
    app->unk_0118 = 0xFFFF;
    GtsSelector_Start(app->selector, GTS_SELECTOR_MODE_LEVEL);
    GtsSearch_SetBlendBrightness(9);
    app->state = GTS_SEARCH_STATE_HANDLE_LEVEL_SELECTOR;
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_HandleLevelSelector(GtsApp *app) {
    u32 selection = GtsSelector_Main(app->selector);
    switch (selection) {
    case 11:
    case (u32)GTS_SELECTOR_BACK:
        GtsSearch_SetBlendBrightness(0);
        app->state = GTS_SEARCH_STATE_START;
        break;
    case (u32)GTS_SELECTOR_NONE:
        break;
    default:
        GtsSearch_SetBlendBrightness(0);
        Gts_SetLevelRange(&app->searchCriteria, selection, 1);
        app->state = GTS_SEARCH_STATE_START;
        FillWindowPixelBuffer(&app->infoWindows[5], 0);
        Gts_PrintLevelRange(&app->infoWindows[5], app->gtsMsgData, selection, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 1);
        break;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_AskCountry(GtsApp *app) {
    GtsSearch_PrintMessage(app, msg_0775_00176, 1, 0, 0xF0F);
    Gts_SetState(app, GTS_SEARCH_STATE_WAIT_TEXT, GTS_SEARCH_STATE_OPEN_COUNTRY_SELECTOR);
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_OpenCountrySelector(GtsApp *app) {
    app->unk_0118 = 0xFFFF;
    GtsSelector_Start(app->selector, GTS_SELECTOR_MODE_COUNTRY);
    GtsSearch_SetBlendBrightness(9);
    app->state = GTS_SEARCH_STATE_HANDLE_COUNTRY_SELECTOR;
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_HandleCountrySelector(GtsApp *app) {
    int selection = GtsSelector_Main(app->selector);
    if (selection != GTS_SELECTOR_NONE) {
        if (selection == GTS_SELECTOR_BACK || selection == gGtsCountryCount[0] + 1) {
            GtsSearch_SetBlendBrightness(0);
            ClearFrameAndWindow2(&app->waitingIconWindow, FALSE);
            app->state = GTS_SEARCH_STATE_START;
        } else {
            GtsSearch_SetBlendBrightness(0);
            Gts_SetSearchCountry(app, selection);
            app->state = GTS_SEARCH_STATE_START;
            FillWindowPixelBuffer(&app->wideWindows[1], 0);
            Gts_PrintCountryName(&app->wideWindows[1], app->countryNames, app->gtsMsgData, app->searchCountry, 0, 0, MAKE_TEXT_COLOR(1, 2, 0));
        }
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_ShowExitPrompt(GtsApp *app) {
    app->yesNoPrompt = Gts_CreateYesNoPrompt(app->bgConfig, 12, 0x120, 3, 1);
    app->state = GTS_SEARCH_STATE_HANDLE_EXIT_PROMPT;
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_HandleExitPrompt(GtsApp *app) {
    YesNoResponse response = Gts_HandleYesNoPrompt(app);
    if (response == YESNORESPONSE_YES) {
        YesNoPrompt_Destroy(app->yesNoPrompt);
        app->state = GTS_SEARCH_STATE_FADE_OUT;
        Gts_SetNextScreen(app, GTS_SCREEN_MAIN_MENU, 0);
        Gts_StopAvatarAnims(app);
        app->searchResultCount = 0;
    } else if (response == YESNORESPONSE_NO) {
        YesNoPrompt_Destroy(app->yesNoPrompt);
        app->state = GTS_SEARCH_STATE_START;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

static enum GtsAppState GtsSearch_ReturnToInput(GtsApp *app) {
    app->state = GTS_SEARCH_STATE_HANDLE_INPUT;
    return GTS_APP_STATE_RUN_SCREEN;
}
