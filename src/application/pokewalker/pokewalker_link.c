// Pokewalker connection app, mode 3: choosing a course and linking with the Pokewalker. linkAction: 0 = send a
// Pokemon on a Stroll, 1 / 2 = receive the Pokemon and gifts, 4 = send the Pokemon back.

#include "global.h"

#include "constants/sndseq.h"

#include "application/pokewalker/pokewalker_app.h"
#include "application/pokewalker/pokewalker_app_internal.h"
#include "msgdata/msg/msg_0274.h"

#include "math_util.h"
#include "message_format.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "string_util.h"
#include "sys_task_api.h"
#include "system.h"
#include "text.h"

#define LINK_MOTION(app) ((PokewalkerAppMotion *)(app)->unk_1F2C0)

extern const PokewalkerAppStateFunc gLinkStates[];
extern const s32 gCourseMenuCursorPositions[];

#include "global.h"

#include "constants/maps.h"
#include "constants/sndseq.h"
#include "constants/species.h"

#include "application/pokewalker/pokewalker_app.h"
#include "msgdata/msg/msg_0274.h"

#include "math_util.h"
#include "message_format.h"
#include "msgdata.h"
#include "pm_string.h"
#include "pokemon.h"
#include "save_local_field_data.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "system.h"
#include "text.h"

void RTC_GetDateTime(RTCDate *date, RTCTime *time);

#define LINK_MOTION(app) ((PokewalkerAppMotion *)(app)->unk_1F2C0)

int PokewalkerApp_Link_Enter(PokewalkerApp *app) {
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_SUB_0, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_SUB_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    PokewalkerApp_HideSprite(app, 7);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_SUB_0);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_SUB_1);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_2);
    app->subBgScrollX = 0;
    return POKEWALKER_APP_STATE_UPDATE;
}

int PokewalkerApp_Link_Update(PokewalkerApp *app) {
    app->state = gLinkStates[app->state](app);
    if (app->state == 67) {
        app->state = 0;
        return POKEWALKER_APP_STATE_EXIT;
    }
    PokewalkerApp_UpdateParticles(app);
    return POKEWALKER_APP_STATE_UPDATE;
}

int PokewalkerApp_Link_Exit(PokewalkerApp *app) {
    app->subBgScrollX = 0;
    return POKEWALKER_APP_STATE_ENTER;
}

int PokewalkerApp_Link_Start(PokewalkerApp *app) {
    if (app->linkAction == POKEWALKER_LINK_RETURN_FROM_STROLL) {
        app->nextState = 1;
        return 19;
    } else if (app->linkAction == POKEWALKER_LINK_RECEIVE_GIFT) {
        app->nextState = 22;
        return 19;
    } else if (app->linkAction == POKEWALKER_LINK_SEND_MON_BACK) {
        return 43;
    } else if (app->selectMon.species) {
        return 5;
    }
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_2);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_SUB_0, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_SUB_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_SUB_0);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_SUB_1);
    PokewalkerApp_HideSprite(app, 3);
    PokewalkerApp_HideSprite(app, 4);
    PokewalkerApp_StartMessage(app, 2, msg_0274_00011, 3);
    return 64;
}

int PokewalkerApp_Link_PrintPointAtCard(PokewalkerApp *app) {
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_1);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 14);
    PokewalkerApp_PrintExit(app, 1);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00005);
    PokewalkerApp_StartSubBgScroll(app);
    return 2;
}

int PokewalkerApp_Link_WaitPointAtCard(PokewalkerApp *app) {
    if (TextPrinterCheckActive(app->textPrinterId) == FALSE) {
        return 26;
    }
    return 2;
}

int PokewalkerApp_Link_FadeOutToSelectMon(PokewalkerApp *app) {
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_154);
    return 4;
}

int PokewalkerApp_Link_WaitFadeOutToSelectMon(PokewalkerApp *app) {
    if (IsPaletteFadeFinished() == TRUE) {
        app->nextMode = POKEWALKER_APP_MODE_SELECT_MON;
        return 66;
    }
    return 4;
}

int PokewalkerApp_Link_FadeIn(PokewalkerApp *app) {
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_154);
    return 6;
}

int PokewalkerApp_Link_WaitFadeIn(PokewalkerApp *app) {
    if (IsPaletteFadeFinished() == TRUE) {
        return 7;
    }
    return 6;
}

int PokewalkerApp_Link_PrintSelectCourse(PokewalkerApp *app) {
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_2);
    PokewalkerApp_HideSprite(app, 3);
    PokewalkerApp_HideSprite(app, 4);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00012);
    return 8;
}

int PokewalkerApp_Link_WaitSelectCourse(PokewalkerApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId)) {
        PokewalkerApp_RemoveWindowBank(app, 1);
        PokewalkerApp_RemoveWindowBank(app, 0);
        PokewalkerApp_AddWindowBank(app, 3);
        PokewalkerApp_AddWindowBank(app, 2);
        return 9;
    }
    return 8;
}

int PokewalkerApp_GetCoursePageCount(PokewalkerApp *app) {
    return ((int)app->numCourses - 1) / 5 + 1;
}

void PokewalkerApp_PrintCoursePage(PokewalkerApp *app) {
    int i;
    String *string;
    for (i = 0; i < 5; i++) {
        s8 course = app->courseList[i + app->coursePage * 5];
        if (course >= 0) {
            string = NewString_ReadMsgData(app->msgData, course + msg_0274_00091);
        } else {
            string = NewString_ReadMsgData(app->msgData, msg_0274_00118);
        }
        PokewalkerApp_PrintString(app, i, string, 4, MAKE_TEXT_COLOR(15, 1, 0));
        String_Delete(string);
    }
    BufferIntegerAsString(app->msgFormat, 10, app->coursePage + 1, 1, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(app->msgFormat, 11, PokewalkerApp_GetCoursePageCount(app), 1, PRINTING_MODE_LEFT_ALIGN, TRUE);
    string = ReadMsgData_ExpandPlaceholders(app->msgFormat, app->msgData, msg_0274_00081, HEAP_ID_154);
    PokewalkerApp_PrintString(app, 7, string, 0, MAKE_TEXT_COLOR(1, 14, 0));
    String_Delete(string);
    PokewalkerApp_PrintCourseInfo(app, app->coursePage, app->menuSelection);
}

// Course name and description of the selected course on the sub screen.
void PokewalkerApp_PrintCourseInfo(PokewalkerApp *app, int page, int selection) {
    String *string;
    if (selection == 5 || PokewalkerApp_GetSelectedCourse(app) == -1) {
        string = NewString_ReadMsgData(app->msgData, msg_0274_00118);
        PokewalkerApp_PrintSubString(app, 0, string, 0, MAKE_TEXT_COLOR(1, 2, 0));
        String_Delete(string);
        FillWindowPixelBuffer(&app->subWindows[1], 0);
        CopyWindowToVram(&app->subWindows[1]);
    } else {
        string = NewString_ReadMsgData(app->msgData, PokewalkerApp_GetSelectedCourse(app) + msg_0274_00091);
        PokewalkerApp_PrintSubString(app, 0, string, 0, MAKE_TEXT_COLOR(1, 2, 0));
        String_Delete(string);
        string = NewString_ReadMsgData(app->msgData, PokewalkerApp_GetSelectedCourse(app) + msg_0274_00119);
        PokewalkerApp_PrintSubString(app, 1, string, 0, MAKE_TEXT_COLOR(1, 2, 0));
        String_Delete(string);
    }
}

int PokewalkerApp_ListUnlockedCourses(PokewalkerApp *app) {
    int course, count;
    app->coursePage = 0;
    app->menuSelection = 0;
    MI_CpuFill8(app->courseList, -1, sizeof(app->courseList));
    count = 0;
    course = count;
    do {
        if (Pokewalker_CourseIsUnlocked(app->pokewalker, course)) {
            app->courseList[count] = course;
            count++;
        }
        course++;
    } while (course < 27);
    return count;
}

int PokewalkerApp_Link_ShowCourseMenu(PokewalkerApp *app) {
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 16, 32, 8, TILEMAP_FILL_KEEP_PAL);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_SUB_1, 17);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 23);
    app->numCourses = PokewalkerApp_ListUnlockedCourses(app);
    PokewalkerApp_PrintCoursePage(app);
    PokewalkerApp_PrintExit(app, 6);
    PokewalkerApp_UpdatePageArrows(app, app->coursePage);
    PokewalkerApp_SetCursorPosition(app, gCourseMenuCursorPositions[app->menuSelection]);
    return 10;
}

// Sprites 3 / 4 = arrows to the previous / next page.
void PokewalkerApp_UpdatePageArrows(PokewalkerApp *app, int page) {
    int numPages = PokewalkerApp_GetCoursePageCount(app);
    if (app->numCourses > 5) {
        if (page == 0) {
            PokewalkerApp_HideSprite(app, 3);
            PokewalkerApp_ShowSprite(app, 4);
        } else if (page > 0 && page < numPages - 1) {
            PokewalkerApp_ShowSprite(app, 3);
            PokewalkerApp_ShowSprite(app, 4);
        } else if (page == numPages - 1) {
            PokewalkerApp_ShowSprite(app, 3);
            PokewalkerApp_HideSprite(app, 4);
        }
    } else {
        PokewalkerApp_HideSprite(app, 3);
        PokewalkerApp_HideSprite(app, 4);
    }
}

int PokewalkerApp_GetSelectedCourse(PokewalkerApp *app) {
    return app->courseList[app->coursePage * 5 + app->menuSelection];
}

int PokewalkerApp_Link_HandleCourseMenu(PokewalkerApp *app) {
    u32 button = PokewalkerApp_GetTouchedButton(4);
    if (button != -1) {
        if (button <= 4) {
            app->menuSelection = button;
            if (PokewalkerApp_GetSelectedCourse(app) >= 0) {
                PokewalkerApp_SelectMenuItem(app, button, gCourseMenuCursorPositions[button], 11);
                PlaySE(SEQ_SE_DP_DECIDE);
                PokewalkerApp_PrintCourseInfo(app, app->coursePage, app->menuSelection);
                return 65;
            }
            PokewalkerApp_PrintCourseInfo(app, app->coursePage, app->menuSelection);
            PlaySE(SEQ_SE_DP_SELECT);
            PokewalkerApp_SetCursorPosition(app, gCourseMenuCursorPositions[app->menuSelection]);
        } else if (button == 6) {
            PokewalkerApp_ChangeCoursePage(app, -1);
            PokewalkerApp_UpdatePageArrows(app, app->coursePage);
            PokewalkerApp_SetSpriteAnim(app, 3, 2);
        } else if (button == 7) {
            PokewalkerApp_ChangeCoursePage(app, 1);
            PokewalkerApp_UpdatePageArrows(app, app->coursePage);
            PokewalkerApp_SetSpriteAnim(app, 4, 3);
        } else {
            PokewalkerApp_SelectMenuItem(app, button, gCourseMenuCursorPositions[button], 11);
            PlaySE(SEQ_SE_DP_DECIDE);
            return 65;
        }
        return 10;
    }
    if (gSystem.newKeys & PAD_KEY_UP) {
        if (app->menuSelection > 0) {
            app->menuSelection--;
            PlaySE(SEQ_SE_DP_SELECT);
        }
        PokewalkerApp_SetCursorPosition(app, gCourseMenuCursorPositions[app->menuSelection]);
        PokewalkerApp_PrintCourseInfo(app, app->coursePage, app->menuSelection);
    } else if (gSystem.newKeys & PAD_KEY_DOWN) {
        if (app->menuSelection < 5) {
            app->menuSelection++;
            PlaySE(SEQ_SE_DP_SELECT);
        }
        PokewalkerApp_SetCursorPosition(app, gCourseMenuCursorPositions[app->menuSelection]);
        PokewalkerApp_PrintCourseInfo(app, app->coursePage, app->menuSelection);
    } else if (gSystem.newKeys & PAD_KEY_LEFT) {
        PokewalkerApp_ChangeCoursePage(app, -1);
        PokewalkerApp_UpdatePageArrows(app, app->coursePage);
        PokewalkerApp_SetSpriteAnim(app, 3, 2);
    } else if (gSystem.newKeys & PAD_KEY_RIGHT) {
        PokewalkerApp_ChangeCoursePage(app, 1);
        PokewalkerApp_UpdatePageArrows(app, app->coursePage);
        PokewalkerApp_SetSpriteAnim(app, 4, 3);
    } else if (gSystem.newKeys & PAD_BUTTON_A) {
        if (app->menuSelection > 4) {
            PokewalkerApp_SelectMenuItem(app, app->menuSelection, gCourseMenuCursorPositions[app->menuSelection], 11);
            PlaySE(SEQ_SE_DP_DECIDE);
            return 65;
        }
        if (PokewalkerApp_GetSelectedCourse(app) >= 0) {
            PokewalkerApp_SelectMenuItem(app, app->menuSelection, gCourseMenuCursorPositions[app->menuSelection], 11);
            PlaySE(SEQ_SE_DP_DECIDE);
            return 65;
        }
        PlaySE(SEQ_SE_DP_SELECT);
    } else if (gSystem.newKeys & PAD_BUTTON_B) {
        PokewalkerApp_SelectMenuItem(app, 5, 3, 11);
        PlaySE(SEQ_SE_DP_SELECT);
        return 65;
    }
    return 10;
}

int PokewalkerApp_Link_EndCourseMenu(PokewalkerApp *app) {
    PokewalkerApp_HideCursor(app);
    switch (app->menuSelection) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        PokewalkerApp_SetCursorPosition(app, gCourseMenuCursorPositions[app->menuSelection]);
        if (PokewalkerApp_GetSelectedCourse(app) < 0) {
            break;
        }
        PokewalkerApp_HideCursor(app);
        FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 16, 32, 8, TILEMAP_FILL_KEEP_PAL);
        app->courseId = PokewalkerApp_GetSelectedCourse(app);
        return 12;
    case 5: // Exit
        PokewalkerApp_RemoveWindowBank(app, 2);
        PokewalkerApp_RemoveWindowBank(app, 3);
        PokewalkerApp_AddWindowBank(app, 1);
        PokewalkerApp_AddWindowBank(app, 0);
        app->selectMon.species = SPECIES_NONE;
        PokewalkerApp_HideCursor(app);
        FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 16, 32, 8, TILEMAP_FILL_KEEP_PAL);
        return 0;
    default:
        GF_ASSERT(app->menuSelection < 6);
        break;
    }
    return 10;
}

void PokewalkerApp_ChangeCoursePage(PokewalkerApp *app, int direction) {
    if (direction < 0) {
        if (app->menuSelection != 5 && (s8)app->coursePage > 0) {
            app->coursePage--;
            app->menuSelection = 0;
            PlaySE(SEQ_SE_DP_SELECT);
        }
    } else {
        if (app->menuSelection != 5) {
            int page = (s8)app->coursePage;
            if (page < PokewalkerApp_GetCoursePageCount(app) - 1) {
                app->coursePage++;
                app->menuSelection = 0;
                PlaySE(SEQ_SE_DP_SELECT);
            }
        }
    }
    PokewalkerApp_SetCursorPosition(app, gCourseMenuCursorPositions[app->menuSelection]);
    PokewalkerApp_PrintCoursePage(app);
}

int PokewalkerApp_Link_PrintConfirmCourse(PokewalkerApp *app) {
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_2);
    PokewalkerApp_HideSprite(app, 3);
    PokewalkerApp_HideSprite(app, 4);
    PokewalkerApp_RemoveWindowBank(app, 2);
    PokewalkerApp_RemoveWindowBank(app, 3);
    PokewalkerApp_AddWindowBank(app, 1);
    PokewalkerApp_AddWindowBank(app, 0);
    BufferPokewalkerCourseName(app->msgFormat, 0, (u8)app->courseId);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 2, msg_0274_00021);
    return 13;
}

int PokewalkerApp_Link_WaitConfirmCourse(PokewalkerApp *app) {
    return !TextPrinterCheckActive(app->textPrinterId) ? 14 : 13;
}

int PokewalkerApp_Link_ShowConfirmCourseYesNo(PokewalkerApp *app) {
    PokewalkerApp_ShowYesNoMenu(app, 0);
    return 15;
}

int PokewalkerApp_Link_HandleConfirmCourseYesNo(PokewalkerApp *app) {
    switch (PokewalkerApp_HandleTwoChoiceMenu(app)) {
    case 0:
        PokewalkerApp_HideCursor(app);
        if (PokewalkerApp_IsStrollStateNonzero(app) == TRUE) {
            app->nextState = 20;
            return 18;
        }
        app->nextState = 16;
        return 18;
    case 1:
        PokewalkerApp_HideCursor(app);
        return 7;
    default:
        return 15;
    }
}

int PokewalkerApp_Link_PrintInstructions(PokewalkerApp *app) {
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_SUB_0);
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_SUB_1);
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_1);
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_2);
    PokewalkerApp_HideSprite(app, 3);
    PokewalkerApp_HideSprite(app, 4);
    PokewalkerApp_StartSubBgScroll(app);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00007);
    return 17;
}

int PokewalkerApp_Link_WaitInstructions(PokewalkerApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId) && app->monPicAlpha == 31 && app->subBgScrollX == 256) {
        PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 14);
        PokewalkerApp_PrintExit(app, 1);
        return 24;
    }
    return 17;
}

int PokewalkerApp_Link_PrintWillConnectWithMon(PokewalkerApp *app) {
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_SUB_0);
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_SUB_1);
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_1);
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_2);
    PokewalkerApp_HideSprite(app, 3);
    PokewalkerApp_HideSprite(app, 4);
    PokewalkerApp_FadeInMonPicture(app);
    PokewalkerApp_StartMessage(app, 2, msg_0274_00016, app->nextState);
    return 64;
}

int PokewalkerApp_Link_PrintWillConnect(PokewalkerApp *app) {
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_SUB_0);
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_SUB_1);
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_1);
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_2);
    PokewalkerApp_StartMessage(app, 2, msg_0274_00016, app->nextState);
    return 64;
}

int PokewalkerApp_Link_PrintPointAtCardForStroll(PokewalkerApp *app) {
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_1);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 14);
    PokewalkerApp_PrintExit(app, 1);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00005);
    PokewalkerApp_StartSubBgScroll(app);
    return 21;
}

int PokewalkerApp_Link_WaitPointAtCardForStroll(PokewalkerApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId) && app->monPicAlpha == 31 && app->subBgScrollX == 256) {
        return 30;
    }
    return 21;
}

void PokewalkerApp_ShowMonPicture(PokewalkerApp *app) {
    PokewalkerApp_FadeInMonPicture(app);
}

// Shows the picture of the Pokemon going on the Stroll (sprite 8), alpha-blended in over BG 3.
void PokewalkerApp_FadeInMonPicture(PokewalkerApp *app) {
    PokewalkerApp_LoadMonPicture(app->strollMon, app->monSpriteBuffer, &app->monPicTemplate, 0);
    ManagedSprite_SetOamMode(app->sprites[8], GX_OAM_MODE_XLU);
    PokewalkerApp_ShowSprite(app, 8);
    app->monPicAlpha = 0;
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG3, 0, 31);
    app->monFadeTask = SysTask_CreateOnMainQueue((SysTaskFunc)PokewalkerApp_FadeInMonPictureTask, app, 2);
}

void PokewalkerApp_FadeInMonPictureTask(SysTask *task, PokewalkerApp *app) {
    app->monPicAlpha += 2;
    if (app->monPicAlpha >= 31) {
        app->monPicAlpha = 31;
    }
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG3, app->monPicAlpha, 31 - app->monPicAlpha);
    if (app->monPicAlpha == 31) {
        SysTask_Destroy(task);
    }
}

void PokewalkerApp_ScrollSubBgTask(SysTask *task, void *data) {
    u16 *scrollX = &((PokewalkerApp *)data)->subBgScrollX;
    *scrollX += 16;
    if (*scrollX > 256) {
        *scrollX = 256;
        SysTask_Destroy(task);
    }
}

int PokewalkerApp_Link_PrintPointAtCardForGifts(PokewalkerApp *app) {
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_SUB_0);
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_SUB_1);
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_1);
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_2);
    PokewalkerApp_RemoveWindowBank(app, 2);
    PokewalkerApp_RemoveWindowBank(app, 3);
    PokewalkerApp_AddWindowBank(app, 0);
    PokewalkerApp_AddWindowBank(app, 1);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 14);
    PokewalkerApp_PrintExit(app, 1);
    PokewalkerApp_HideSprite(app, 3);
    PokewalkerApp_HideSprite(app, 4);
    PokewalkerApp_StartSubBgScroll(app);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00005);
    return 23;
}

int PokewalkerApp_Link_WaitPointAtCardForGifts(PokewalkerApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId) && app->subBgScrollX == 256) {
        PokewalkerApp_ShowConnectionSprites(app, 2);
        return 28;
    }
    return 23;
}

void PokewalkerApp_ResetLinkError(PokewalkerApp *app) {
    app->linkError = 0;
    app->linkConnected = 0;
}

// Request 0x32: registers the Pokewalker and sends the upload image and the Stroll data.
int PokewalkerApp_Link_StartUpload(PokewalkerApp *app) {
    MIi_CpuClearFast(0, (u32 *)&app->irBlocks, sizeof(PokewalkerIrBlocks));
    MIi_CpuClearFast(0, (u32 *)&app->irStatus, sizeof(PokewalkerIrStatus));
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 14);
    PokewalkerApp_PrintExit(app, 1);
    PokewalkerApp_BuildUploadData(app);
    PokewalkerIr_RequestUpload(app->uploadImage, (u8 *)&app->strollData, (u8 *)&app->unk_F1D0);
    PokewalkerApp_StartLink(app);
    PokewalkerApp_ShowConnectionSprites(app, 2);
    ManagedSprite_SetAnim(app->sprites[8], 25);
    ManagedSprite_SetAnimationFrame(app->sprites[8], 0);
    PokewalkerApp_ResetLinkError(app);
    return 25;
}

void PokewalkerApp_StartSubBgScroll(PokewalkerApp *app) {
    PokewalkerApp_LoadSubBg1Tilemap(app);
    app->subBgScrollTask = SysTask_CreateOnMainQueue(PokewalkerApp_ScrollSubBgTask, app, 2);
}

void PokewalkerApp_PlayTransferSE(int progress) {
    if (progress != 0 && !IsSEPlaying(SEQ_SE_GS_PHC_POKEMONIDOU)) {
        PlaySE(SEQ_SE_GS_PHC_POKEMONIDOU);
    }
}

// Returns the highest transfer progress seen while the link is up (the progress restarts with each block).
int PokewalkerApp_UpdateLinkProgress(PokewalkerApp *app, int progress) {
    if (PokewalkerIrStatus_IsConnected()) {
        u16 highest = app->linkProgress;
        if (highest < progress) {
            app->linkProgress = progress;
        } else {
            progress = highest;
        }
    } else {
        app->linkProgress = 0;
    }
    return progress;
}

int PokewalkerApp_Link_UpdateUpload(PokewalkerApp *app) {
    u8 progress;
    int error;
    PokewalkerIr_GetChunkProgress();
    progress = PokewalkerApp_UpdateLinkProgress(app, PokewalkerIr_GetTotalProgress());
    if (progress > MTRandom() % 255) {
        PokewalkerApp_SpawnRisingParticle(app);
    }
    PokewalkerApp_UpdateConnectionAnim(app);
    PokewalkerApp_PlayTransferSE(progress);
    PokewalkerApp_SetWalkerIconFrame(app, progress);
    if (progress > 200) {
        if (app->motionStarted == 0) {
            PokewalkerApp_InitMotion(app, LINK_MOTION(app), 2);
            app->motionStarted = 1;
        }
    } else {
        PokewalkerApp_HideMotionSprites(app);
        app->motionStarted = 0;
    }
    error = PokewalkerIr_GetAndClearError();
    switch (error) {
    case 2:
        if (app->linkConnected == 1) {
            app->linkError = 42;
        }
        break;
    case 4:
    case 7:
    case 8:
    case 9:
    case 11:
    case 12:
    case 13:
        app->linkError = error;
        break;
    case 15: // done
        ManagedSprite_SetDrawFlag(app->sprites[2], FALSE);
        Pokewalker_IncrementLinkCount(app->pokewalker);
        PokewalkerApp_HideSprite(app, 8);
        PokewalkerApp_InitMotion(app, LINK_MOTION(app), 0);
        return 35;
    }
    if (app->linkError) {
        ManagedSprite_SetDrawFlag(app->sprites[2], FALSE);
        app->nextState = 58;
        PokewalkerIr_Stop();
        return 32;
    }
    if (!PokewalkerIrStatus_IsConnected()) {
        PokewalkerApp_ShowSubBg1(app, TRUE);
        if (PokewalkerApp_GetTouchedButton(5) == 0 || (gSystem.newKeys & PAD_BUTTON_A) || (gSystem.newKeys & PAD_BUTTON_B)) {
            app->linkError = 33;
            PokewalkerIr_Stop();
            PokewalkerApp_SelectMenuItem(app, 3, 3, 33);
            PlaySE(SEQ_SE_DP_DECIDE);
            return 65;
        }
    } else {
        if (app->linkConnected == 0) {
            PokewalkerApp_ShowMessageBox(app, 2, msg_0274_00006);
            app->linkConnected = 1;
        }
        PokewalkerApp_ShowSubBg1(app, FALSE);
    }
    return 25;
}

// Request 0x40: reads the Pokewalker's Pokemon, status and blocks.
int PokewalkerApp_Link_StartReceive(PokewalkerApp *app) {
    MIi_CpuClearFast(0, (u32 *)app->irStatus.records, sizeof(app->irStatus.records));
    PokewalkerIr_RequestReceive((u8 *)&app->walkerMon, (u8 *)&app->irStatus, (u8 *)&app->irBlocks, (u8 *)app->peerRecords);
    PokewalkerApp_StartLink(app);
    PokewalkerApp_ResetLinkError(app);
    PokewalkerApp_ShowConnectionSprites(app, 2);
    ManagedSprite_SetAnimationFrame(app->sprites[8], 0);
    return 27;
}

// Adds the Trainer House sets of other HeartGold / SoulSilver games met by the Pokewalker (not while the player is in
// the Trainer House).
void PokewalkerApp_AddPeerTrainerHouseSets(PokewalkerApp *app) {
    int i;
    if (LocalFieldData_GetCurrentPosition(Save_LocalFieldData_Get(app->saveData))->mapId == MAP_VIRIDIAN_TRAINER_HOUSE_B1F) {
        return;
    }
    for (i = 9; i >= 0; i--) {
        if (app->peerRecords[i + 1].version == VERSION_HEARTGOLD || app->peerRecords[i + 1].version == VERSION_SOULSILVER) {
            PokewalkerApp_SaveTrainerHouseData(app->saveData, &app->peerRecords[i + 1].trainerHouseData);
        }
    }
}

void PokewalkerApp_UpdateSavedSteps(PokewalkerApp *app) {
    u32 steps;
    Pokewalker_GetStepsAndWatts(app->pokewalker, &app->walkerSteps, &app->walkerWatts);
    steps = app->peerIdentity.steps;
    if (steps < app->walkerSteps) {
        Pokewalker_SetStepsAddWatts(app->pokewalker, app->walkerSteps, app->irStatus.watts);
    } else {
        Pokewalker_SetStepsAddWatts(app->pokewalker, steps, app->irStatus.watts);
    }
}

void PokewalkerApp_AddSavedTotal(PokewalkerApp *app) {
    Pokewalker_GetStepsAndWatts(app->pokewalker, &app->walkerSteps, &app->walkerWatts);
    Pokewalker_SetStepsAddWatts(app->pokewalker, app->walkerSteps, app->irStatus.watts);
}

BOOL PokewalkerApp_IsWalkerMonValid(PokewalkerApp *app) {
    u16 species;
    if (app->peerIdentity.hasWalkerMon == 1) {
        species = app->walkerMon.species;
        if (species == SPECIES_NONE || species > NATIONAL_DEX_COUNT) {
            return FALSE;
        }
    }
    return TRUE;
}

BOOL PokewalkerApp_IsGiftMonValid(PokewalkerApp *app) {
    u16 species;
    if (app->irBlocks.flags.hasGiftMon == 1) {
        species = app->irBlocks.giftMon.mon.species;
        if (species == SPECIES_NONE || species > NATIONAL_DEX_COUNT) {
            return FALSE;
        }
    }
    return TRUE;
}

int PokewalkerApp_Link_UpdateReceive(PokewalkerApp *app) {
    int result;

    PokewalkerIr_GetChunkProgress();
    result = PokewalkerIr_GetTotalProgress();
    if (result != 0) {
        PokewalkerApp_SpawnFallingParticle(app);
    }
    PokewalkerApp_UpdateConnectionAnim(app);
    PokewalkerApp_PlayTransferSE(result);

    result = PokewalkerIr_GetAndClearError();
    switch (result) {
    case 2:
        if (app->linkConnected == 1) {
            app->linkError = 42;
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
    case 12:
    case 13:
        app->linkError = result;
        break;
    case 15: // done
        ManagedSprite_SetDrawFlag(app->sprites[2], FALSE);
        if (PokewalkerApp_IsWalkerMonValid(app) && app->peerIdentity.hasWalkerMon == 1) {
            GetSpeciesNameIntoArray(app->walkerMon.species, HEAP_ID_154, app->walkerMonNickname);
        }
        PokewalkerApp_InitMotion(app, LINK_MOTION(app), 1);
        PokewalkerApp_AddPeerTrainerHouseSets(app);
        PokewalkerApp_UpdateSavedSteps(app);
        PokewalkerApp_AddStrollToEventLog(app);
        app->strollSteps = app->peerIdentity.steps - app->walkerSteps;
        return 37;
    }

    if (app->linkError != 0) {
        ManagedSprite_SetDrawFlag(app->sprites[2], FALSE);
        app->nextState = 60;
        PokewalkerIr_Stop();
        return 32;
    }
    if (!PokewalkerIrStatus_IsConnected()) {
        PokewalkerApp_ShowSubBg1(app, TRUE);
        if (PokewalkerApp_GetTouchedButton(5) == 0 || (gSystem.newKeys & PAD_BUTTON_A) || (gSystem.newKeys & PAD_BUTTON_B)) {
            app->linkError = 33;
            app->nextState = 66;
            PokewalkerIr_Stop();
            PokewalkerApp_SelectMenuItem(app, 3, 3, 33);
            PlaySE(SEQ_SE_DP_DECIDE);
            return 65;
        }
    } else {
        if (app->linkConnected == 0) {
            PokewalkerApp_ShowMessageBox(app, 2, msg_0274_00006);
            app->linkConnected = 1;
        }
        PokewalkerApp_ShowSubBg1(app, FALSE);
    }
    return 27;
}

// Adds the Stroll to the event log (the last record) and, if the Pokewalker brought a gift Pokemon, that too.
void PokewalkerApp_AddStrollToEventLog(PokewalkerApp *app) {
    PokewalkerEventLogParams params = { 0 };
    PokewalkerEventLogMon giftMon;
    params.nickname = app->walkerMonNickname;
    params.mon.species = app->walkerMon.species;
    params.mon.form = app->walkerMon.form;
    params.mon.gender = app->walkerMon.gender;
    params.mon.isShiny = app->walkerMon.isShiny;
    u32 steps = app->peerIdentity.steps;
    u32 savedSteps = app->walkerSteps;
    if (steps < savedSteps) {
        params.steps = 0;
    } else {
        params.steps = steps - savedSteps;
    }
    PokewalkerEventLog_InitStrollEndRecord(&app->irStatus.records[23], &params);
    if (PokewalkerEventLog_HasGiftMon(app->irStatus.records)) {
        giftMon.species = app->irBlocks.giftMon.mon.species;
        giftMon.form = app->irBlocks.giftMon.mon.form;
        giftMon.gender = app->irBlocks.giftMon.mon.gender;
        giftMon.isShiny = app->irBlocks.giftMon.mon.isShiny;
        PokewalkerEventLog_SetGiftMon(app->irStatus.records, &giftMon);
    }
}

// Request 0x60: reads the Pokewalker's status, blocks and the other games' records.
int PokewalkerApp_Link_StartReceiveGifts(PokewalkerApp *app) {
    MIi_CpuClearFast(0, (u32 *)&app->irBlocks, sizeof(PokewalkerIrBlocks));
    PokewalkerIr_RequestReceiveGifts(&app->irStatus, app->peerRecords);
    PokewalkerApp_StartLink(app);
    PokewalkerApp_ResetLinkError(app);
    return 29;
}

int PokewalkerApp_Link_UpdateReceiveGifts(PokewalkerApp *app) {
    int progress, error;
    RTCDate date;
    RTCTime time;

    PokewalkerIr_GetChunkProgress();
    progress = PokewalkerIr_GetTotalProgress();
    if (progress) {
        PokewalkerApp_SpawnFallingParticle(app);
    }
    PokewalkerApp_PlayTransferSE(progress);
    PokewalkerApp_UpdateConnectionAnim(app);
    error = PokewalkerIr_GetAndClearError();
    switch (error) {
    case 2:
        if (app->linkConnected == 1) {
            app->linkError = 42;
        }
        break;
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
    case 11:
    case 12:
    case 13:
        app->linkError = error;
        break;
    case 15: // done
        ManagedSprite_SetDrawFlag(app->sprites[2], FALSE);
        RTC_GetDateTime(&date, &time);
        RTC_ConvertDateTimeToSecond(&date, &time);
        PokewalkerApp_AddPeerTrainerHouseSets(app);
        PokewalkerApp_AddSavedTotal(app);
        PokewalkerApp_ShowSprite(app, 6);
        return 41;
    }
    if (app->linkError) {
        ManagedSprite_SetDrawFlag(app->sprites[2], FALSE);
        app->nextState = 61;
        PokewalkerIr_Stop();
        return 32;
    }
    if (!PokewalkerIrStatus_IsConnected()) {
        PokewalkerApp_ShowSubBg1(app, TRUE);
        if (!PokewalkerApp_GetTouchedButton(5) || (gSystem.newKeys & PAD_BUTTON_A) || (gSystem.newKeys & PAD_BUTTON_B)) {
            PokewalkerIr_Stop();
            app->linkError = 33;
            app->nextState = 66;
            PokewalkerApp_SelectMenuItem(app, 3, 3, 33);
            PlaySE(SEQ_SE_DP_DECIDE);
            return 65;
        }
    } else {
        if (!app->linkConnected) {
            PokewalkerApp_ShowMessageBox(app, 2, msg_0274_00006);
            app->linkConnected = 1;
        }
        PokewalkerApp_ShowSubBg1(app, FALSE);
    }
    return 29;
}

// Request 0x52: sends the Stroll data again (the Pokewalker is already registered).
int PokewalkerApp_Link_StartSendStroll(PokewalkerApp *app) {
    PokewalkerApp_BuildSendStrollData(app);
    PokewalkerIr_RequestSendStroll((u8 *)&app->strollData, (u8 *)&app->unk_F1D0, (u8 *)&app->irStatus, (u8 *)&app->irBlocks);
    PokewalkerApp_StartLink(app);
    if (app->strollPartyMon) {
        PokewalkerApp_LoadMonPicture(&app->strollPartyMon->box, app->monSpriteBuffer, &app->monPicTemplate, 0);
    } else {
        PokewalkerApp_LoadMonPicture(app->strollMon, app->monSpriteBuffer, &app->monPicTemplate, 0);
    }
    ManagedSprite_SetOamMode(app->sprites[8], GX_OAM_MODE_XLU);
    PokewalkerApp_ShowSprite(app, 8);
    ManagedSprite_SetAnim(app->sprites[8], 25);
    ManagedSprite_SetAnimationFrame(app->sprites[8], 0);
    app->motionStarted = 0;
    PokewalkerApp_ShowConnectionSprites(app, 2);
    PokewalkerApp_ResetLinkError(app);
    return 31;
}

// The walker icon (sprite 8) follows the transfer progress.
void PokewalkerApp_SetWalkerIconFrame(PokewalkerApp *app, int progress) {
    if (progress == 0) {
        ManagedSprite_SetAnimationFrame(app->sprites[8], 0);
    } else if (progress > 30) {
        ManagedSprite_SetAnimationFrame(app->sprites[8], (progress - 30) / 4);
    }
}

int PokewalkerApp_Link_UpdateSendStroll(PokewalkerApp *app) {
    u32 progress, error;
    int total;
    PokewalkerIr_GetChunkProgress();
    total = PokewalkerIr_GetTotalProgress();
    progress = PokewalkerApp_UpdateLinkProgress(app, (u8)total);
    if (progress) {
        PokewalkerApp_SpawnRisingParticle(app);
    }
    PokewalkerApp_UpdateConnectionAnim(app);
    PokewalkerApp_PlayTransferSE(progress);
    PokewalkerApp_SetWalkerIconFrame(app, progress);
    if (progress > 200) {
        if (app->motionStarted == 0) {
            PokewalkerApp_InitMotion(app, LINK_MOTION(app), 2);
            app->motionStarted = 1;
        }
    } else {
        PokewalkerApp_HideMotionSprites(app);
        app->motionStarted = 0;
    }
    error = PokewalkerIr_GetAndClearError();
    switch (error) {
    case 2:
        if (app->linkConnected == 1) {
            app->linkError = 42;
        }
        break;
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
    case 11:
    case 12:
    case 13:
        app->linkError = error;
        break;
    case 15: // done
        ManagedSprite_SetDrawFlag(app->sprites[2], FALSE);
        Pokewalker_GetStepsAndWatts(app->pokewalker, &app->walkerSteps, &app->walkerWatts);
        PokewalkerApp_UpdateSavedSteps(app);
        Pokewalker_IncrementLinkCount(app->pokewalker);
        PokewalkerApp_HideSprite(app, 8);
        PokewalkerApp_InitMotion(app, LINK_MOTION(app), 0);
        return 35;
    }
    if (app->linkError) {
        ManagedSprite_SetDrawFlag(app->sprites[2], FALSE);
        app->nextState = 59;
        PokewalkerIr_Stop();
        return 32;
    }
    if (!PokewalkerIrStatus_IsConnected()) {
        PokewalkerApp_ShowSubBg1(app, TRUE);
        if (!PokewalkerApp_GetTouchedButton(5) || (gSystem.newKeys & PAD_BUTTON_A) || (gSystem.newKeys & PAD_BUTTON_B)) {
            app->linkError = 33;
            app->nextState = 66;
            PokewalkerIr_Stop();
            PokewalkerApp_SelectMenuItem(app, 3, 3, 33);
            PlaySE(SEQ_SE_DP_DECIDE);
            return 65;
        }
    } else {
        if (app->linkConnected == 0) {
            PokewalkerApp_ShowMessageBox(app, 2, msg_0274_00006);
            app->linkConnected = 1;
        }
        PokewalkerApp_ShowSubBg1(app, FALSE);
    }
    return 31;
}

// Message shown for a link error (PokewalkerIr_GetAndClearError, 33 = canceled, 42 = connection lost).
int PokewalkerApp_GetLinkErrorMessage(int error) {
    switch (error) {
    case 4:
        return msg_0274_00034;
    case 5:
        return msg_0274_00036;
    case 7:
        return msg_0274_00037;
    case 6:
        return msg_0274_00043;
    case 8:
    case 9:
        return msg_0274_00038;
    case 3:
    case 11:
    case 12:
        return msg_0274_00039;
    case 13:
        return msg_0274_00035;
    case 14:
        return msg_0274_00042;
    case 33:
    case 42:
        break;
    }
    return error;
}

int PokewalkerApp_Link_PrintError(PokewalkerApp *app) {
    PokewalkerApp_HideCursor(app);
    app->linkError = PokewalkerApp_GetLinkErrorMessage(app->linkError);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 2, app->linkError);
    return 34;
}

int PokewalkerApp_Link_PrintCanceled(PokewalkerApp *app) {
    PokewalkerApp_HideCursor(app);
    app->linkError = PokewalkerApp_GetLinkErrorMessage(app->linkError);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 2, app->linkError);
    app->nextState = 66;
    return 34;
}

int PokewalkerApp_Link_RetryInstructions(PokewalkerApp *app) {
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_1);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00007);
    return 17;
}

int PokewalkerApp_Link_RetryPointAtCardForStroll(PokewalkerApp *app) {
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_1);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00005);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 14);
    PokewalkerApp_PrintExit(app, 1);
    return 21;
}

int PokewalkerApp_Link_RetryPointAtCard(PokewalkerApp *app) {
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_1);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00005);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 14);
    PokewalkerApp_PrintExit(app, 1);
    return 2;
}

int PokewalkerApp_Link_RetryPointAtCardForGifts(PokewalkerApp *app) {
    BgClearTilemapBufferAndCommit(app->bgConfig, GF_BG_LYR_MAIN_1);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00005);
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 14);
    PokewalkerApp_PrintExit(app, 1);
    return 23;
}

int PokewalkerApp_Link_WaitError(PokewalkerApp *app) {
    int next;
    if (!TextPrinterCheckActive(app->textPrinterId)) {
        app->nextMode = POKEWALKER_APP_MODE_MAIN_MENU;
        FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
        BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_2);
        next = app->nextState;
        app->state = next;
        return next;
    }
    return 34;
}

int PokewalkerApp_Link_PrintWentToWalker(PokewalkerApp *app) {
    BoxPokemon *boxMon;
    PokewalkerIr_Stop();
    if (!PokewalkerApp_IsGiftMonValid(app)) {
        MIi_CpuClearFast(0, (u32 *)&app->irBlocks.giftMon, sizeof(PokewalkerIrGiftMon));
        app->irBlocks.flags.hasGiftMon = FALSE;
    }
    boxMon = &app->strollPartyMon->box;
    if (boxMon) {
        BufferBoxMonNickname(app->msgFormat, 1, boxMon);
    } else {
        BufferBoxMonNickname(app->msgFormat, 1, app->strollMon);
    }
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_2);
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 2, msg_0274_00024);
    PlayFanfare(SEQ_ME_KEYITEM);
    return 36;
}

int PokewalkerApp_Link_WaitWentToWalker(PokewalkerApp *app) {
    PokewalkerApp_UpdateMotion(app, LINK_MOTION(app));
    if (!TextPrinterCheckActive(app->textPrinterId) && !PokewalkerApp_AgeParticles(app) && !IsFanfarePlaying()) {
        app->nextMode = POKEWALKER_APP_MODE_START_STROLL;
        return 66;
    }
    return 36;
}

int PokewalkerApp_Link_PrintReturned(PokewalkerApp *app) {
    String *nickname = String_New(12, HEAP_ID_154);
    int printerId;
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_2);
    if (PokewalkerApp_IsWalkerMonValid(app)) {
        CopyU16ArrayToStringN(nickname, app->walkerMonNickname, 12);
        BufferString(app->msgFormat, 1, nickname, app->walkerMon.gender, 1, 1);
        printerId = PokewalkerApp_StartMessageBox(app, 2, msg_0274_00027);
    } else {
        printerId = PokewalkerApp_StartMessageBox(app, 2, msg_0274_00032);
    }
    app->textPrinterId = printerId;
    PokewalkerIr_Stop();
    String_Delete(nickname);
    return 38;
}

// Whether the Pokemon stored in the save data for the Stroll is the one the Pokewalker has.
BOOL PokewalkerApp_IsWalkerMonInSave(PokewalkerApp *app) {
    BOOL result = TRUE;
    Pokemon *mon;
    u32 species;
    u32 form;
    mon = AllocMonZeroed(HEAP_ID_154);
    if (!Pokewalker_TryGetBoxMon(app->pokewalker, (BoxPokemon *)mon)) {
        result = FALSE;
    }
    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    form = GetMonData(mon, MON_DATA_FORM, NULL);
    if (app->walkerMon.species != species || app->walkerMon.form != form) {
        result = FALSE;
    }
    Heap_Free(mon);
    return result;
}

int PokewalkerApp_Link_WaitReturned(PokewalkerApp *app) {
    PokewalkerApp_UpdateMotion(app, LINK_MOTION(app));
    if (!TextPrinterCheckActive(app->textPrinterId)) {
        if (!IsFanfarePlaying()) {
            if (!PokewalkerApp_IsWalkerMonValid(app)) {
                MIi_CpuClearFast(0, (u32 *)&app->walkerMon, sizeof(PokewalkerMon));
                app->peerIdentity.hasWalkerMon = 0;
            }
            if (!PokewalkerApp_IsGiftMonValid(app)) {
                MIi_CpuClearFast(0, (u32 *)&app->irBlocks.giftMon, sizeof(PokewalkerIrGiftMon));
                app->irBlocks.flags.hasGiftMon = FALSE;
            }
            if (PokewalkerApp_IsWalkerMonInSave(app) || app->irBlocks.flags.hasGiftMon || app->irBlocks.flags.hasGiftItem || app->peerIdentity.hasWalkerMon) {
                app->nextMode = POKEWALKER_APP_MODE_LINK_SAVE;
                return 66;
            }
            return 39;
        }
    }
    return 38;
}

int PokewalkerApp_Link_PrintReleased(PokewalkerApp *app) {
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 2, msg_0274_00020);
    return 40;
}

int PokewalkerApp_Link_WaitReleased(PokewalkerApp *app) {
    return !TextPrinterCheckActive(app->textPrinterId) ? 62 : 40;
}

int PokewalkerApp_Link_PrintReceivedGifts(PokewalkerApp *app) {
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 2, msg_0274_00029);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_2);
    PokewalkerIr_Stop();
    PlayFanfare(SEQ_ME_ITEM);
    return 42;
}

int PokewalkerApp_Link_WaitReceivedGifts(PokewalkerApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId) && !IsFanfarePlaying()) {
        app->nextMode = POKEWALKER_APP_MODE_LINK_SAVE;
        return 66;
    }
    return 42;
}

int PokewalkerApp_Link_PrintSendBackCaution(PokewalkerApp *app) {
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 2, msg_0274_00018);
    return 44;
}

int PokewalkerApp_Link_WaitSendBackCaution(PokewalkerApp *app) {
    return !TextPrinterCheckActive(app->textPrinterId) ? 45 : 44;
}

int PokewalkerApp_Link_ShowSendBackYesNo(PokewalkerApp *app) {
    PokewalkerApp_ShowYesNoMenu(app, 1);
    return 46;
}

int PokewalkerApp_Link_HandleSendBackYesNo(PokewalkerApp *app) {
    switch (PokewalkerApp_HandleTwoChoiceMenu(app)) {
    case 0:
        PokewalkerApp_HideCursor(app);
        FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
        FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
        ClearWindowTilemapAndCopyToVram(&app->windows[3]);
        ClearWindowTilemapAndCopyToVram(&app->windows[4]);
        BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_2);
        return 47;
    case 1:
        FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 16, 32, 8, TILEMAP_FILL_KEEP_PAL);
        ClearWindowTilemapAndCopyToVram(&app->windows[3]);
        ClearWindowTilemapAndCopyToVram(&app->windows[4]);
        PokewalkerApp_HideCursor(app);
        app->nextMode = POKEWALKER_APP_MODE_MAIN_MENU;
        return 66;
    default:
        return 46;
    }
}

int PokewalkerApp_Link_PrintWillSendBack(PokewalkerApp *app) {
    app->textPrinterId = PokewalkerApp_StartMessageBox(app, 0, msg_0274_00019);
    return 48;
}

int PokewalkerApp_Link_WaitWillSendBack(PokewalkerApp *app) {
    return !TextPrinterCheckActive(app->textPrinterId) ? 49 : 48;
}

int PokewalkerApp_Link_ShowSendBackMenu(PokewalkerApp *app) {
    PokewalkerApp_LoadTilemap(app, GF_BG_LYR_MAIN_2, 10);
    PokewalkerApp_PrintString(app, 5, app->sendHomeText, 4, MAKE_TEXT_COLOR(15, 1, 0));
    PokewalkerApp_PrintExit(app, 1);
    app->menuSelection = 0;
    PokewalkerApp_SetCursorPosition(app, 2);
    return 50;
}

int PokewalkerApp_Link_HandleSendBackMenu(PokewalkerApp *app) {
    int button = PokewalkerApp_GetTouchedButton(1);
    if (button != -1) {
        PokewalkerApp_SelectMenuItem(app, button, button + 2, 51);
        PlaySE(SEQ_SE_DP_DECIDE);
        return 65;
    }
    if (gSystem.newKeys & PAD_KEY_UP) {
        PokewalkerApp_SetCursorPosition(app, 2);
        if (app->menuSelection != 0) {
            PlaySE(SEQ_SE_DP_SELECT);
        }
        app->menuSelection = 0;
    } else if (gSystem.newKeys & PAD_KEY_DOWN) {
        PokewalkerApp_SetCursorPosition(app, 3);
        if (app->menuSelection != 1) {
            PlaySE(SEQ_SE_DP_SELECT);
        }
        app->menuSelection = 1;
    } else if (gSystem.newKeys & PAD_BUTTON_A) {
        PokewalkerApp_SelectMenuItem(app, app->menuSelection, app->menuSelection + 2, 51);
        PlaySE(SEQ_SE_DP_DECIDE);
        return 65;
    } else if (gSystem.newKeys & PAD_BUTTON_B) {
        PokewalkerApp_SelectMenuItem(app, 1, 3, 51);
        PlaySE(SEQ_SE_DP_SELECT);
        return 65;
    }
    return 50;
}

int PokewalkerApp_Link_EndSendBackMenu(PokewalkerApp *app) {
    PokewalkerApp_HideCursor(app);
    if (app->menuSelection == 0) {
        FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
        FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
        ClearWindowTilemapAndCopyToVram(&app->windows[3]);
        ClearWindowTilemapAndCopyToVram(&app->windows[4]);
        BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_2);
        app->strollSteps = 0;
        return 52;
    }
    app->nextMode = POKEWALKER_APP_MODE_EXIT;
    return 66;
}

int PokewalkerApp_Link_PrintComeBack(PokewalkerApp *app) {
    BoxPokemon *boxMon = &app->returnedMon;
    Pokewalker_TryGetBoxMon(app->pokewalker, boxMon);
    PokewalkerApp_ShowConnectionSprites(app, 0);
    BufferBoxMonNickname(app->msgFormat, 1, boxMon);
    PokewalkerApp_LoadMonPicture(boxMon, app->monSpriteBuffer, &app->monPicTemplate, 0);
    PokewalkerApp_StartMessage(app, 2, msg_0274_00026, 53);
    return 64;
}

int PokewalkerApp_Link_StartReturnAnimation(PokewalkerApp *app) {
    app->timer = 0;
    PokewalkerApp_HideSprite(app, 8);
    return 54;
}

int PokewalkerApp_Link_AnimateReturn(PokewalkerApp *app) {
    app->timer++;
    if (app->timer > 180) {
        return 55;
    }
    if ((u32)app->timer > MTRandom() % 180) {
        PokewalkerApp_SpawnFallingParticle(app);
    }
    PokewalkerApp_PlayTransferSE(app->timer);
    return 54;
}

int PokewalkerApp_Link_AfterReturnAnimation(PokewalkerApp *app) {
    return 56;
}

int PokewalkerApp_Link_PrintArrived(PokewalkerApp *app) {
    PokewalkerApp_StartMessage(app, 2, msg_0274_00027, 57);
    return 64;
}

int PokewalkerApp_Link_EndSendBack(PokewalkerApp *app) {
    app->nextMode = POKEWALKER_APP_MODE_LINK_SAVE;
    return 66;
}

int PokewalkerApp_Link_FadeOut(PokewalkerApp *app) {
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_154);
    return 63;
}

int PokewalkerApp_Link_WaitFadeOut(PokewalkerApp *app) {
    if (IsPaletteFadeFinished() == TRUE) {
        PokewalkerApp_HideMotionSprites(app);
        app->nextMode = POKEWALKER_APP_MODE_MAIN_MENU;
        return 66;
    }
    return 63;
}

int PokewalkerApp_Link_WaitMessage(PokewalkerApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId)) {
        return app->state = app->nextState;
    }
    return 64;
}

int PokewalkerApp_Link_WaitCursor(PokewalkerApp *app) {
    if (!ManagedSprite_IsAnimated(app->sprites[0])) {
        PokewalkerApp_HideCursor(app);
        return app->state = app->nextState;
    }
    return 65;
}

int PokewalkerApp_Link_End(PokewalkerApp *app) {
    PokewalkerApp_HideConnectionSprites(app);
    PokewalkerApp_HideSprite(app, 3);
    PokewalkerApp_HideSprite(app, 4);
    PokewalkerApp_HideSprite(app, 8);
    FillBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 0, 32, 24, TILEMAP_FILL_KEEP_PAL);
    BgCommitTilemapBufferToVram(app->bgConfig, GF_BG_LYR_MAIN_1);
    return 67;
}
