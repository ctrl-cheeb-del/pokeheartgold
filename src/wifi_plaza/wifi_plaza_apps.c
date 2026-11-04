#include <nitro/rtc.h>

#include "global.h"

#include "application/footprint_stamp.h"
#include "application/plaza_game_mime_jr_top.h"
#include "application/plaza_game_swalot_plop.h"
#include "application/plaza_news.h"
#include "wifi_plaza/wifi_plaza_connect.h"
#include "wifi_plaza/wifi_plaza_internal.h"
#include "wifi_plaza/wifi_plaza_visitor_profiles.h"

#include "comm_state.h"
#include "comm_state_internal.h"
#include "location_gmm_dat.h"
#include "overlay_manager.h"
#include "poke_overlay.h"
#include "wifi_connection.h"
#include "wobbuffet_pop.h"

// The applications of the plaza, one overlay at a time. Each app has an entry in the four tables below (index =
// app): make its arguments, free them, start its overlay, and pick the next app when the overlay has finished.

FS_EXTERN_OVERLAY(OVY_46);
FS_EXTERN_OVERLAY(OVY_47);
FS_EXTERN_OVERLAY(OVY_48);
FS_EXTERN_OVERLAY(OVY_49);
FS_EXTERN_OVERLAY(OVY_88);
FS_EXTERN_OVERLAY(OVY_89);
FS_EXTERN_OVERLAY(OVY_90);
FS_EXTERN_OVERLAY(OVY_91);
FS_EXTERN_OVERLAY(OVY_92);
FS_EXTERN_OVERLAY(OVY_93);

enum WiFiPlazaApp {
    WIFI_PLAZA_APP_MAIN,
    WIFI_PLAZA_APP_VISITOR_PROFILES,
    WIFI_PLAZA_APP_PLAZA_NEWS,
    WIFI_PLAZA_APP_FOOTPRINT_STAMP_BOARD_0,
    WIFI_PLAZA_APP_FOOTPRINT_STAMP_BOARD_1,
    WIFI_PLAZA_APP_CONNECT,
    WIFI_PLAZA_APP_SWALOT_PLOP,
    WIFI_PLAZA_APP_MIME_JR_TOP,
    WIFI_PLAZA_APP_WOBBUFFET_POP,
    WIFI_PLAZA_APP_DISCONNECT,
    WIFI_PLAZA_APP_CLOSED_DISCONNECT,
    WIFI_PLAZA_APP_SURVEY_ANSWER,
    WIFI_PLAZA_APP_SURVEY_RESULTS,
};

// Arguments of app 0, the plaza.
typedef struct WiFiPlazaMainArgs {
    SaveData *save;
    int group;
    int variant;
    u16 startParams[6];
    u32 result; // what to do next
    WiFiPlazaWork *work;
} WiFiPlazaMainArgs;

static void WiFiPlazaApps_StartOverlay(WiFiPlazaApps *apps, void **args, const OverlayManagerTemplate *template);
static void WiFiPlazaApps_InitArgs(WiFiPlazaApps *apps, u32 app, enum HeapID heapID);
static void WiFiPlazaApps_FreeArgs(WiFiPlazaApps *apps, u32 app);
static void WiFiPlazaApps_Start(WiFiPlazaApps *apps, u32 app);
static BOOL WiFiPlazaApps_End(WiFiPlazaApps *apps, u32 app);
static void WiFiPlazaGameArgs_NewProfiles(PlazaGameArgs *args, enum HeapID heapID);
static void WiFiPlazaGameArgs_FreeProfiles(PlazaGameArgs *args);
static void WiFiPlazaGameArgs_Setup(PlazaGameArgs *args, WiFiPlazaWork *work, enum HeapID heapID);
static void WiFiPlazaApps_NewMainArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID);
static void WiFiPlazaApps_FreeMainArgs(void **args);
static void WiFiPlazaApps_StartMain(WiFiPlazaApps *apps, void **args);
static BOOL WiFiPlazaApps_EndMain(WiFiPlazaApps *apps, void **args);
static void WiFiPlazaApps_NewVisitorProfilesArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID);
static void WiFiPlazaApps_FreeVisitorProfilesArgs(void **args);
static void WiFiPlazaApps_StartVisitorProfiles(WiFiPlazaApps *apps, void **args);
static BOOL WiFiPlazaApps_EndVisitorProfiles(WiFiPlazaApps *apps, void **args);
static void WiFiPlazaApps_NewPlazaNewsArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID);
static void WiFiPlazaApps_FreePlazaNewsArgs(void **args);
static void WiFiPlazaApps_StartPlazaNews(WiFiPlazaApps *apps, void **args);
static BOOL WiFiPlazaApps_EndPlazaNews(WiFiPlazaApps *apps, void **args);
static void WiFiPlazaApps_NewConnectArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID);
static void WiFiPlazaApps_FreeConnectArgs(void **args);
static void WiFiPlazaApps_StartConnect(WiFiPlazaApps *apps, void **args);
static BOOL WiFiPlazaApps_EndConnect(WiFiPlazaApps *apps, void **args);
static void WiFiPlazaApps_NewSwalotPlopArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID);
static void WiFiPlazaApps_FreeSwalotPlopArgs(void **args);
static void WiFiPlazaApps_StartSwalotPlop(WiFiPlazaApps *apps, void **args);
static BOOL WiFiPlazaApps_EndSwalotPlop(WiFiPlazaApps *apps, void **args);
static void WiFiPlazaApps_NewMimeJrTopArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID);
static void WiFiPlazaApps_FreeMimeJrTopArgs(void **args);
static void WiFiPlazaApps_StartMimeJrTop(WiFiPlazaApps *apps, void **args);
static BOOL WiFiPlazaApps_EndMimeJrTop(WiFiPlazaApps *apps, void **args);
static void WiFiPlazaApps_NewWobbuffetPopArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID);
static void WiFiPlazaApps_FreeWobbuffetPopArgs(void **args);
static void WiFiPlazaApps_StartWobbuffetPop(WiFiPlazaApps *apps, void **args);
static BOOL WiFiPlazaApps_EndWobbuffetPop(WiFiPlazaApps *apps, void **args);
static void WiFiPlazaApps_NewFootprintStampArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID);
static void WiFiPlazaApps_FreeFootprintStampArgs(void **args);
static BOOL WiFiPlazaApps_EndFootprintStamp(WiFiPlazaApps *apps, void **args);
static void WiFiPlazaApps_StartFootprintStampBoard0(WiFiPlazaApps *apps, void **args);
static void WiFiPlazaApps_StartFootprintStampBoard1(WiFiPlazaApps *apps, void **args);
static void WiFiPlazaApps_NewDisconnectArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID);
static void WiFiPlazaApps_FreeDisconnectArgs(void **args);
static void WiFiPlazaApps_StartDisconnect(WiFiPlazaApps *apps, void **args);
static void WiFiPlazaApps_StartClosedDisconnect(WiFiPlazaApps *apps, void **args);
static void WiFiPlazaApps_StartDisconnectOverlay(WiFiPlazaApps *apps, void **args, u32 mode);
static BOOL WiFiPlazaApps_EndDisconnect(WiFiPlazaApps *apps, void **args);
static void WiFiPlazaApps_NewSurveyAnswerArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID);
static void WiFiPlazaApps_NewSurveyResultsArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID);
static void WiFiPlazaApps_FreeSurveyArgs(void **args);
static void WiFiPlazaApps_StartSurvey(WiFiPlazaApps *apps, void **args);
static BOOL WiFiPlazaApps_EndSurvey(WiFiPlazaApps *apps, void **args);

// The entries of the app tables (and their helpers).

static const OverlayManagerTemplate sWiFiPlazaFootprintStampBoard0OverlayTemplate = {
    .init = FootprintStamp_Init,
    .exec = FootprintStamp_Main,
    .exit = FootprintStamp_Exit,
    .ovy_id = FS_OVERLAY_ID(OVY_89),
};

static const OverlayManagerTemplate sWiFiPlazaWobbuffetPopOverlayTemplate = {
    .init = WobbuffetPopApp_Init,
    .exec = WobbuffetPopApp_Main,
    .exit = WobbuffetPopApp_Exit,
    .ovy_id = FS_OVERLAY_ID(OVY_93),
};

static const OverlayManagerTemplate sWiFiPlazaFootprintStampBoard1OverlayTemplate = {
    .init = FootprintStamp_Init,
    .exec = FootprintStamp_Main,
    .exit = FootprintStamp_Exit,
    .ovy_id = FS_OVERLAY_ID(OVY_89),
};

static const OverlayManagerTemplate sWiFiPlazaDisconnectOverlayTemplate = {
    .init = WiFiPlazaConnect_DisconnectInit,
    .exec = WiFiPlazaConnect_DisconnectMain,
    .exit = WiFiPlazaConnect_DisconnectExit,
    .ovy_id = FS_OVERLAY_ID(OVY_46),
};

static const OverlayManagerTemplate sWiFiPlazaMimeJrTopOverlayTemplate = {
    .init = MimeJrTop_Init,
    .exec = MimeJrTop_Main,
    .exit = MimeJrTop_Exit,
    .ovy_id = FS_OVERLAY_ID(OVY_92),
};

static const OverlayManagerTemplate sWiFiPlazaMainOverlayTemplate = {
    .init = WiFiPlazaRoom_Init,
    .exec = WiFiPlazaRoom_Main,
    .exit = WiFiPlazaRoom_Exit,
    .ovy_id = FS_OVERLAY_ID(OVY_49),
};

static const OverlayManagerTemplate sWiFiPlazaVisitorProfilesOverlayTemplate = {
    .init = VisitorProfiles_Init,
    .exec = VisitorProfiles_Main,
    .exit = VisitorProfiles_Exit,
    .ovy_id = FS_OVERLAY_ID(OVY_48),
};

static const OverlayManagerTemplate sWiFiPlazaNewsOverlayTemplate = {
    .init = PlazaNews_Init,
    .exec = PlazaNews_Main,
    .exit = PlazaNews_Exit,
    .ovy_id = FS_OVERLAY_ID(OVY_88),
};

static const OverlayManagerTemplate sWiFiPlazaConnectOverlayTemplate = {
    .init = WiFiPlazaConnect_Init,
    .exec = WiFiPlazaConnect_Main,
    .exit = WiFiPlazaConnect_Exit,
    .ovy_id = FS_OVERLAY_ID(OVY_46),
};

static const OverlayManagerTemplate sWiFiPlazaSwalotPlopOverlayTemplate = {
    .init = SwalotPlop_Init,
    .exec = SwalotPlop_Main,
    .exit = SwalotPlop_Exit,
    .ovy_id = FS_OVERLAY_ID(OVY_91),
};

static const OverlayManagerTemplate sWiFiPlazaSurveyOverlayTemplate = {
    .init = WiFiPlazaSurvey_Init,
    .exec = WiFiPlazaSurvey_Main,
    .exit = WiFiPlazaSurvey_Exit,
    .ovy_id = FS_OVERLAY_ID(OVY_47),
};

static const u8 sWiFiPlazaTypeChoices[20] = { 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 0, 0 };

static void (*sWiFiPlazaAppStartFuncs[13])(WiFiPlazaApps *, void **) = {
    WiFiPlazaApps_StartMain,
    WiFiPlazaApps_StartVisitorProfiles,
    WiFiPlazaApps_StartPlazaNews,
    WiFiPlazaApps_StartFootprintStampBoard0,
    WiFiPlazaApps_StartFootprintStampBoard1,
    WiFiPlazaApps_StartConnect,
    WiFiPlazaApps_StartSwalotPlop,
    WiFiPlazaApps_StartMimeJrTop,
    WiFiPlazaApps_StartWobbuffetPop,
    WiFiPlazaApps_StartDisconnect,
    WiFiPlazaApps_StartClosedDisconnect,
    WiFiPlazaApps_StartSurvey,
    WiFiPlazaApps_StartSurvey,
};

static void (*sWiFiPlazaAppFreeArgsFuncs[13])(void **) = {
    WiFiPlazaApps_FreeMainArgs,
    WiFiPlazaApps_FreeVisitorProfilesArgs,
    WiFiPlazaApps_FreePlazaNewsArgs,
    WiFiPlazaApps_FreeFootprintStampArgs,
    WiFiPlazaApps_FreeFootprintStampArgs,
    WiFiPlazaApps_FreeConnectArgs,
    WiFiPlazaApps_FreeSwalotPlopArgs,
    WiFiPlazaApps_FreeMimeJrTopArgs,
    WiFiPlazaApps_FreeWobbuffetPopArgs,
    WiFiPlazaApps_FreeDisconnectArgs,
    WiFiPlazaApps_FreeDisconnectArgs,
    WiFiPlazaApps_FreeSurveyArgs,
    WiFiPlazaApps_FreeSurveyArgs,
};

static void (*sWiFiPlazaAppInitArgsFuncs[13])(WiFiPlazaApps *, void **, enum HeapID) = {
    WiFiPlazaApps_NewMainArgs,
    WiFiPlazaApps_NewVisitorProfilesArgs,
    WiFiPlazaApps_NewPlazaNewsArgs,
    WiFiPlazaApps_NewFootprintStampArgs,
    WiFiPlazaApps_NewFootprintStampArgs,
    WiFiPlazaApps_NewConnectArgs,
    WiFiPlazaApps_NewSwalotPlopArgs,
    WiFiPlazaApps_NewMimeJrTopArgs,
    WiFiPlazaApps_NewWobbuffetPopArgs,
    WiFiPlazaApps_NewDisconnectArgs,
    WiFiPlazaApps_NewDisconnectArgs,
    WiFiPlazaApps_NewSurveyAnswerArgs,
    WiFiPlazaApps_NewSurveyResultsArgs,
};

static BOOL (*sWiFiPlazaAppEndFuncs[13])(WiFiPlazaApps *, void **) = {
    WiFiPlazaApps_EndMain,
    WiFiPlazaApps_EndVisitorProfiles,
    WiFiPlazaApps_EndPlazaNews,
    WiFiPlazaApps_EndFootprintStamp,
    WiFiPlazaApps_EndFootprintStamp,
    WiFiPlazaApps_EndConnect,
    WiFiPlazaApps_EndSwalotPlop,
    WiFiPlazaApps_EndMimeJrTop,
    WiFiPlazaApps_EndWobbuffetPop,
    WiFiPlazaApps_EndDisconnect,
    WiFiPlazaApps_EndDisconnect,
    WiFiPlazaApps_EndSurvey,
    WiFiPlazaApps_EndSurvey,
};

int WiFiPlaza_AvatarToIndex(u16 avatar) {
    int i;
    for (i = 0; i < 16; i++) {
        if (avatar == gWiFiPlazaAvatars[i].avatar) {
            return i;
        }
    }
    return 16;
}

u16 WiFiPlaza_IndexToAvatar(u32 index) {
    if (index < 16) {
        return gWiFiPlazaAvatars[index].avatar;
    }
    return 0xffff;
}

WiFiPlazaApps *WiFiPlazaApps_New(u32 skipPrompt, SaveData *save, s64 *loginTime, WiFiPlazaWork *work, enum HeapID heapID) {
    WiFiPlazaApps *apps = Heap_Alloc(heapID, sizeof(WiFiPlazaApps));
    int i;
    memset(apps, 0, sizeof(WiFiPlazaApps));
    apps->work = work;
    apps->save = save;
    apps->loginTime = loginTime;
    apps->skipPrompt = skipPrompt;
    apps->heapID = heapID;
    for (i = 0; i < 13; i++) {
        WiFiPlazaApps_InitArgs(apps, i, heapID);
    }
    return apps;
}

void WiFiPlazaApps_Delete(WiFiPlazaApps *apps) {
    int i;
    for (i = 0; i < 13; i++) {
        WiFiPlazaApps_FreeArgs(apps, i);
    }
    Heap_Free(apps);
}

void WiFiPlazaApps_StartFirst(WiFiPlazaApps *apps) {
    WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_CONNECT);
}

// TRUE when the last app has finished.
BOOL WiFiPlazaApps_Run(WiFiPlazaApps *apps) {
    BOOL done = FALSE;
    if (apps->manager && OverlayManager_Run(apps->manager)) {
        OverlayManager_Delete(apps->manager);
        apps->manager = NULL;
        done = WiFiPlazaApps_End(apps, apps->current);
    }
    return done;
}

void WiFiPlazaApps_VBlank(WiFiPlazaApps *apps) {
}

static void WiFiPlazaApps_StartOverlay(WiFiPlazaApps *apps, void **args, const OverlayManagerTemplate *template) {
    GF_ASSERT(apps->manager == NULL);
    apps->manager = OverlayManager_New(template, *args, (enum HeapID)apps->heapID);
}

static void WiFiPlazaApps_InitArgs(WiFiPlazaApps *apps, u32 app, enum HeapID heapID) {
    GF_ASSERT(app < 13);
    sWiFiPlazaAppInitArgsFuncs[app](apps, &apps->args[app], heapID);
}

static void WiFiPlazaApps_FreeArgs(WiFiPlazaApps *apps, u32 app) {
    GF_ASSERT(app < 13);
    sWiFiPlazaAppFreeArgsFuncs[app](&apps->args[app]);
}

static void WiFiPlazaApps_Start(WiFiPlazaApps *apps, u32 app) {
    GF_ASSERT(app < 13);
    sWiFiPlazaAppStartFuncs[app](apps, &apps->args[app]);
    apps->current = app;
}

static BOOL WiFiPlazaApps_End(WiFiPlazaApps *apps, u32 app) {
    GF_ASSERT(app < 13);
    return sWiFiPlazaAppEndFuncs[app](apps, &apps->args[app]);
}

static void WiFiPlazaGameArgs_NewProfiles(PlazaGameArgs *args, enum HeapID heapID) {
    int i;
    for (i = 0; i < 4; i++) {
        args->profiles[i] = PlayerProfile_New(heapID);
    }
}

static void WiFiPlazaGameArgs_FreeProfiles(PlazaGameArgs *args) {
    int i;
    void *nullp = NULL;
    for (i = 0; i < 4; i++) {
        Heap_Free(args->profiles[i]);
        args->profiles[i] = nullp;
    }
}

static void WiFiPlazaGameArgs_Setup(PlazaGameArgs *args, WiFiPlazaWork *work, enum HeapID heapID) {
    int i;
    args->tapToy = WiFiPlazaPlayer_GetTapToy(WiFiPlazaWork_GetMyPlayer(work));
    WiFiPlazaWork_GetSpecialVisitors(work, args->specialVisitors);
    WiFiPlazaWork_GetGameMembers(work, args->slots);
    args->plazaWork = work;
    args->connectionLost = FALSE;
    for (i = 0; i < 4; i++) {
        WiFiPlazaPlayer *player = WiFiPlazaWork_GetPlayer(work, args->slots[i]);
        if (player) {
            WiFiPlazaPlayer_CopyToProfile(player, args->profiles[i], heapID);
        }
    }
}

// App 0, the plaza.
static void WiFiPlazaApps_NewMainArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID) {
    WiFiPlazaApps *state = apps;
    void **dest = out;
    WiFiPlazaMainArgs *args;
    *dest = Heap_Alloc(heapID, sizeof(WiFiPlazaMainArgs));
    memset(*dest, 0, sizeof(WiFiPlazaMainArgs));
    args = *dest;
    args->save = state->save;
    args->work = state->work;
}

static void WiFiPlazaApps_FreeMainArgs(void **args) {
    GF_ASSERT(*args != NULL);
    Heap_Free(*args);
    *args = NULL;
}

static void WiFiPlazaApps_StartMain(WiFiPlazaApps *apps, void **args) {
    WiFiPlazaMainArgs *main = *args;
    main->group = WiFiPlazaWork_GetScheduleValue3(apps->work);
    main->variant = WiFiPlazaWork_GetScheduleValue2(apps->work);
    WiFiPlazaApps_StartOverlay(apps, args, &sWiFiPlazaMainOverlayTemplate);
}

// The plaza tells which app comes next.
static BOOL WiFiPlazaApps_EndMain(WiFiPlazaApps *apps, void **args) {
    WiFiPlazaMainArgs *mainArgs = *args;
    switch (mainArgs->result) {
    case 0:
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_DISCONNECT);
        break;
    case 1:
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_VISITOR_PROFILES);
        break;
    case 2:
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_PLAZA_NEWS);
        break;
    case 6:
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_FOOTPRINT_STAMP_BOARD_0);
        break;
    case 7:
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_FOOTPRINT_STAMP_BOARD_1);
        break;
    case 3:
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_SWALOT_PLOP);
        break;
    case 4:
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_MIME_JR_TOP);
        break;
    case 5:
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_WOBBUFFET_POP);
        break;
    case 8:
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_CLOSED_DISCONNECT);
        break;
    case 9:
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_SURVEY_ANSWER);
        break;
    case 10:
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_SURVEY_RESULTS);
        break;
    default:
        GF_ASSERT(FALSE);
    }
    return FALSE;
}

// App 1, the visitor profiles.
static void WiFiPlazaApps_NewVisitorProfilesArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID) {
    u8 *p;
    VisitorProfilesArgs *profilesArgs;
    u32 count;
    p = Heap_Alloc(heapID, sizeof(VisitorProfilesArgs));
    *out = p;
    count = sizeof(VisitorProfilesArgs);
    do {
        *p = 0;
        p++;
        count--;
    } while (count);
    profilesArgs = *out;
    profilesArgs->saveData = apps->save;
    profilesArgs->lobby = apps->work;
}

static void WiFiPlazaApps_FreeVisitorProfilesArgs(void **args) {
    Heap_Free(*args);
}

static void WiFiPlazaApps_StartVisitorProfiles(WiFiPlazaApps *apps, void **args) {
    VisitorProfilesArgs *visitor = *args;
    visitor->visitors = WiFiPlazaWork_GetPlaces(apps->work);
    visitor->clock.raw = WiFiPlazaWork_GetCurrentTimePtr(apps->work)->word;
    WiFiPlazaApps_StartOverlay(apps, args, &sWiFiPlazaVisitorProfilesOverlayTemplate);
}

static BOOL WiFiPlazaApps_EndVisitorProfiles(WiFiPlazaApps *apps, void **args) {
    if (WiFiPlazaWork_IsClosed(apps->work)) {
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_CLOSED_DISCONNECT);
    } else {
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_MAIN);
    }
    return FALSE;
}

// App 2, the plaza news.
static void WiFiPlazaApps_NewPlazaNewsArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID) {
    PlazaNewsArgs *newsArgs;
    u8 *p = Heap_Alloc(heapID, 12);
    *out = p;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    newsArgs = *out;
    newsArgs->news = WiFiPlazaWork_GetNews(apps->work);
    newsArgs->time = WiFiPlazaWork_GetCurrentTimePtr(apps->work);
    newsArgs->lobby = apps->work;
}

static void WiFiPlazaApps_FreePlazaNewsArgs(void **args) {
    Heap_Free(*args);
}

static void WiFiPlazaApps_StartPlazaNews(WiFiPlazaApps *apps, void **args) {
    WiFiPlazaApps_StartOverlay(apps, args, &sWiFiPlazaNewsOverlayTemplate);
}

static BOOL WiFiPlazaApps_EndPlazaNews(WiFiPlazaApps *apps, void **args) {
    if (WiFiPlazaWork_IsClosed(apps->work)) {
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_CLOSED_DISCONNECT);
    } else {
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_MAIN);
    }
    return FALSE;
}

// App 5, connect.
static void WiFiPlazaApps_NewConnectArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID) {
    u8 *p;
    WiFiPlazaConnectArgs *connectArgs;
    u32 count;
    p = Heap_Alloc(heapID, sizeof(WiFiPlazaConnectArgs));
    *out = p;
    count = sizeof(WiFiPlazaConnectArgs);
    do {
        *p = 0;
        p++;
        count--;
    } while (count);
    connectArgs = *out;
    connectArgs->saveData = apps->save;
    connectArgs->work = apps->work;
    connectArgs->skipPrompt = apps->skipPrompt;
    connectArgs->loginTime = apps->loginTime;
}

static void WiFiPlazaApps_FreeConnectArgs(void **args) {
    Heap_Free(*args);
}

static void WiFiPlazaApps_StartConnect(WiFiPlazaApps *apps, void **args) {
    WiFiPlazaApps_StartOverlay(apps, args, &sWiFiPlazaConnectOverlayTemplate);
}

// TRUE (the plaza ends) unless the connection was made.
static BOOL WiFiPlazaApps_EndConnect(WiFiPlazaApps *apps, void **args) {
    WiFiPlazaConnectArgs *connectArgs = *args;
    if (!connectArgs->connected) {
        return TRUE;
    }
    WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_MAIN);
    return FALSE;
}

// Apps 6, 7, 8, the games.
static void WiFiPlazaApps_NewSwalotPlopArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID) {
    PlazaGameArgs *gameArgs;
    *out = Heap_Alloc(heapID, sizeof(PlazaGameArgs) - 4); // without mimeJrTopVoiceChat
    memset(*out, 0, sizeof(PlazaGameArgs) - 4);
    gameArgs = *out;
    gameArgs->voiceChat = 0;
    gameArgs->fromLobby = 1;
    gameArgs->saveData = apps->save;
    WiFiPlazaGameArgs_NewProfiles(gameArgs, heapID);
}

static void WiFiPlazaApps_FreeSwalotPlopArgs(void **args) {
    WiFiPlazaGameArgs_FreeProfiles(*args);
    Heap_Free(*args);
}

static void WiFiPlazaApps_StartSwalotPlop(WiFiPlazaApps *apps, void **args) {
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_90), OVY_LOAD_ASYNC);
    WiFiPlazaGameArgs_Setup(*args, apps->work, (enum HeapID)apps->heapID);
    WiFiPlazaApps_StartOverlay(apps, args, &sWiFiPlazaSwalotPlopOverlayTemplate);
}

static BOOL WiFiPlazaApps_EndSwalotPlop(WiFiPlazaApps *apps, void **args) {
    PlazaGameArgs *game;
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_90));
    game = *args;
    WiFiPlazaWork_SetGameConnectionLost(apps->work, game->connectionLost);
    WiFiPlazaWork_SetTapToy(apps->work, game->tapToy);
    WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_MAIN);
    return FALSE;
}

static void WiFiPlazaApps_NewMimeJrTopArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID) {
    PlazaGameArgs *gameArgs;
    *out = Heap_Alloc(heapID, sizeof(PlazaGameArgs));
    memset(*out, 0, sizeof(PlazaGameArgs));
    gameArgs = *out;
    gameArgs->mimeJrTopVoiceChat = 0;
    *(u32 *)&gameArgs->voiceChat = 1;
    gameArgs->saveData = apps->save;
    WiFiPlazaGameArgs_NewProfiles(gameArgs, heapID);
}

static void WiFiPlazaApps_FreeMimeJrTopArgs(void **args) {
    WiFiPlazaGameArgs_FreeProfiles(*args);
    Heap_Free(*args);
}

static void WiFiPlazaApps_StartMimeJrTop(WiFiPlazaApps *apps, void **args) {
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_90), OVY_LOAD_ASYNC);
    WiFiPlazaGameArgs_Setup(*args, apps->work, (enum HeapID)apps->heapID);
    WiFiPlazaApps_StartOverlay(apps, args, &sWiFiPlazaMimeJrTopOverlayTemplate);
}

static BOOL WiFiPlazaApps_EndMimeJrTop(WiFiPlazaApps *apps, void **args) {
    PlazaGameArgs *game;
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_90));
    game = *args;
    WiFiPlazaWork_SetGameConnectionLost(apps->work, game->connectionLost);
    WiFiPlazaWork_SetTapToy(apps->work, game->tapToy);
    WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_MAIN);
    return FALSE;
}

static void WiFiPlazaApps_NewWobbuffetPopArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID) {
    PlazaGameArgs *gameArgs;
    *out = Heap_Alloc(heapID, sizeof(PlazaGameArgs) - 4); // without mimeJrTopVoiceChat
    memset(*out, 0, sizeof(PlazaGameArgs) - 4);
    gameArgs = *out;
    gameArgs->voiceChat = 0;
    gameArgs->fromLobby = 1;
    gameArgs->saveData = apps->save;
    WiFiPlazaGameArgs_NewProfiles(gameArgs, heapID);
}

static void WiFiPlazaApps_FreeWobbuffetPopArgs(void **args) {
    WiFiPlazaGameArgs_FreeProfiles(*args);
    Heap_Free(*args);
}

static void WiFiPlazaApps_StartWobbuffetPop(WiFiPlazaApps *apps, void **args) {
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_90), OVY_LOAD_ASYNC);
    WiFiPlazaGameArgs_Setup(*args, apps->work, (enum HeapID)apps->heapID);
    WiFiPlazaApps_StartOverlay(apps, args, &sWiFiPlazaWobbuffetPopOverlayTemplate);
}

static BOOL WiFiPlazaApps_EndWobbuffetPop(WiFiPlazaApps *apps, void **args) {
    PlazaGameArgs *game;
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_90));
    game = *args;
    WiFiPlazaWork_SetGameConnectionLost(apps->work, game->connectionLost);
    WiFiPlazaWork_SetTapToy(apps->work, game->tapToy);
    WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_MAIN);
    return FALSE;
}

// Apps 3 and 4, the footprint stamp.
static void WiFiPlazaApps_NewFootprintStampArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID) {
    FootprintStampArgs *stampArgs;
    u8 *p = Heap_Alloc(heapID, 8);
    *out = p;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    stampArgs = *out;
    stampArgs->lobby = apps->work;
}

static void WiFiPlazaApps_FreeFootprintStampArgs(void **args) {
    Heap_Free(*args);
}

static BOOL WiFiPlazaApps_EndFootprintStamp(WiFiPlazaApps *apps, void **args) {
    if (WiFiPlazaWork_IsClosed(apps->work)) {
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_CLOSED_DISCONNECT);
    } else {
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_MAIN);
    }
    return FALSE;
}

static void WiFiPlazaApps_StartFootprintStampBoard0(WiFiPlazaApps *apps, void **args) {
    FootprintStampArgs *stampArgs = *args;
    stampArgs->boardType = 0;
    WiFiPlazaApps_StartOverlay(apps, args, &sWiFiPlazaFootprintStampBoard0OverlayTemplate);
}

static void WiFiPlazaApps_StartFootprintStampBoard1(WiFiPlazaApps *apps, void **args) {
    FootprintStampArgs *stampArgs = *args;
    stampArgs->boardType = 1;
    WiFiPlazaApps_StartOverlay(apps, args, &sWiFiPlazaFootprintStampBoard1OverlayTemplate);
}

// Apps 9 and 10, disconnect.
static void WiFiPlazaApps_NewDisconnectArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID) {
    WiFiPlazaDisconnectArgs *disconnectArgs;
    u8 *p = Heap_Alloc(heapID, 12);
    *out = p;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    disconnectArgs = *out;
    disconnectArgs->saveData = apps->save;
    disconnectArgs->work = apps->work;
}

static void WiFiPlazaApps_FreeDisconnectArgs(void **args) {
    Heap_Free(*args);
}

static void WiFiPlazaApps_StartDisconnect(WiFiPlazaApps *apps, void **args) {
    WiFiPlazaApps_StartDisconnectOverlay(apps, args, 0);
}

static void WiFiPlazaApps_StartClosedDisconnect(WiFiPlazaApps *apps, void **args) {
    WiFiPlazaApps_StartDisconnectOverlay(apps, args, 1);
}

static void WiFiPlazaApps_StartDisconnectOverlay(WiFiPlazaApps *apps, void **args, u32 mode) {
    WiFiPlazaDisconnectArgs *disconnectArgs = *args;
    disconnectArgs->mode = mode;
    WiFiPlazaApps_StartOverlay(apps, args, &sWiFiPlazaDisconnectOverlayTemplate);
}

static BOOL WiFiPlazaApps_EndDisconnect(WiFiPlazaApps *apps, void **args) {
    return TRUE;
}

// Apps 11 and 12.
static void WiFiPlazaApps_NewSurveyAnswerArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID) {
    WiFiPlazaDisconnectArgs *surveyArgs;
    u8 *p = Heap_Alloc(heapID, 12);
    *out = p;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    surveyArgs = *out;
    surveyArgs->saveData = apps->save;
    surveyArgs->work = apps->work;
    surveyArgs->mode = 0;
}

static void WiFiPlazaApps_NewSurveyResultsArgs(WiFiPlazaApps *apps, void **out, enum HeapID heapID) {
    WiFiPlazaDisconnectArgs *surveyArgs;
    u8 *p = Heap_Alloc(heapID, 12);
    *out = p;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    surveyArgs = *out;
    surveyArgs->saveData = apps->save;
    surveyArgs->work = apps->work;
    surveyArgs->mode = 1;
}

static void WiFiPlazaApps_FreeSurveyArgs(void **args) {
    Heap_Free(*args);
}

static void WiFiPlazaApps_StartSurvey(WiFiPlazaApps *apps, void **args) {
    WiFiPlazaApps_StartOverlay(apps, args, &sWiFiPlazaSurveyOverlayTemplate);
}

static BOOL WiFiPlazaApps_EndSurvey(WiFiPlazaApps *apps, void **args) {
    if (WiFiPlazaWork_IsClosed(apps->work)) {
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_CLOSED_DISCONNECT);
    } else {
        WiFiPlazaApps_Start(apps, WIFI_PLAZA_APP_MAIN);
    }
    return FALSE;
}

// Hour, minute and second of a time in seconds, in the low three bytes of out.
void WiFiPlaza_SecondsToTime(u32 *out, s64 *seconds) {
    RTCDate date;
    RTCTime time;
    RTC_ConvertSecondToDateTime(&date, &time, *seconds);
    ((u8 *)out)[0] = time.hour;
    ((u8 *)out)[1] = time.minute;
    ((u8 *)out)[2] = time.second;
}

// out = left + right (hour, minute, second; the hour wraps at 24).
void WiFiPlazaTime_Add(const WiFiPlazaTime *left, const WiFiPlazaTime *right, WiFiPlazaTime *out) {
    WiFiPlazaTime a = *left, b = *right;
    a.field.second += b.field.second;
    a.field.minute += a.field.second / 60;
    out->field.second = a.field.second % 60;
    a.field.minute += b.field.minute;
    a.field.hour += a.field.minute / 60;
    out->field.minute = a.field.minute % 60;
    a.field.hour += b.field.hour;
    out->field.hour = a.field.hour % 24;
}

// out = first - second (hour, minute, second; the hour wraps at 24).
void WiFiPlazaTime_Subtract(const WiFiPlazaTime *first, const WiFiPlazaTime *second, WiFiPlazaTime *out) {
    WiFiPlazaTime a = *first, b = *second;
    int delta;
    u8 value;
    value = b.value[2];
    delta = a.signedValue[2] - (s8)value;
    if (delta < 0) {
        int borrow = (-delta) / 60 + 1;
        a.value[2] = a.value[2] + borrow * 60;
        a.value[1] = a.value[1] - borrow;
    }
    out->value[2] = a.value[2] - value;
    value = b.value[1];
    delta = a.signedValue[1] - (s8)value;
    if (delta < 0) {
        int borrow = (-delta) / 60 + 1;
        a.value[1] = a.value[1] + borrow * 60;
        a.value[0] = a.value[0] - borrow;
    }
    out->value[1] = a.value[1] - value;
    delta = (s8)a.value[0] - (s8)b.value[0];
    if (delta < 0) {
        int borrow = (-delta) / 24 + 1;
        a.value[0] = a.value[0] + borrow * 24;
    }
    out->value[0] = a.value[0] - b.value[0];
}

// Adds a country and region to the list (the first free entry, or the entry of the same place unless value is 1).
void WiFiPlazaPlaces_Add(WiFiPlazaPlace *places, u32 country, u32 region, u32 value) {
    s32 i;
    BOOL use;
    if (country == 0) {
        return;
    }
    if (region > (u32)LocationGmmDatRegionCountGetByCountryMsgNo(country)) {
        return;
    }
    use = FALSE;
    for (i = 0; i < 50; i++) {
        if (places[i].occupied == 0) {
            use = TRUE;
        } else if (places[i].country == country && places[i].region == region) {
            if (value == 1) {
                return;
            }
            use = TRUE;
        }
        if (use) {
            places[i].country = country;
            places[i].region = region;
            places[i].value = value;
            places[i].occupied = 1;
            return;
        }
    }
}

u32 WiFiPlazaPlaces_GetCountry(WiFiPlazaPlace *places, u8 index) {
    GF_ASSERT(index < 50);
    places += index;
    GF_ASSERT(places->occupied == 1);
    return places->country;
}

u32 WiFiPlazaPlaces_GetRegion(WiFiPlazaPlace *places, u8 index) {
    GF_ASSERT(index < 50);
    GF_ASSERT(places[index].occupied == 1);
    return places[index].region;
}

u32 WiFiPlazaPlaces_GetValue(WiFiPlazaPlace *places, u8 index) {
    GF_ASSERT(index < 50);
    places += index;
    GF_ASSERT(places->occupied == 1);
    return places->value;
}

u32 WiFiPlazaPlaces_IsOccupied(WiFiPlazaPlace *places, u8 index) {
    GF_ASSERT(index < 50);
    return places[index].occupied;
}

// Turns off the diffuse, ambient, specular and emission flags of the materials of the first model of file.
void WiFiPlaza_DisableModelLighting(NNSG3dResFileHeader *file) {
    NNSG3dResMdlSet *set = NNS_G3dGetMdlSet(file);
    NNSG3dResMdl *model = NNS_G3dGetMdlByIdx(set, 0);
    NNSi_G3dModifyMatFlag(model, FALSE, NNS_G3D_MATFLAG_DIFFUSE);
    NNSi_G3dModifyMatFlag(model, FALSE, NNS_G3D_MATFLAG_AMBIENT);
    NNSi_G3dModifyMatFlag(model, FALSE, NNS_G3D_MATFLAG_SPECULAR);
    NNSi_G3dModifyMatFlag(model, FALSE, NNS_G3D_MATFLAG_EMISSION);
}

// TRUE if region exists in country (region 0 for a country without regions).
BOOL WiFiPlaza_IsRegionValid(u32 country, u32 region) {
    u32 count = LocationGmmDatRegionCountGetByCountryMsgNo(country);
    if (count == 0 && region == 0) {
        return TRUE;
    }
    if (region >= 1 && region <= count) {
        return TRUE;
    }
    return FALSE;
}

u32 WiFiPlaza_GetTypeByChoice(u32 index) {
    return sWiFiPlazaTypeChoices[index];
}

// The error message class of a connection error (WifiConnection_ClassifyErrorCode, with the plaza's own errors 25 and
// 26).
int WiFiPlaza_GetErrorMessageClass(u32 errorCode, u32 context) {
    int class = WifiConnection_ClassifyErrorCode(errorCode, context);
    if (class == 11 || errorCode == 25) {
        if (context != 2) {
            return 14;
        }
        return 11;
    }
    if (errorCode == 26) {
        return 13;
    }
    if (class < 0) {
        class = 11;
    }
    return class;
}

// FALSE for the errors that end the connection.
BOOL WiFiPlaza_IsErrorRecoverable(u32 errorCode, u32 context) {
    int class = WifiConnection_ClassifyErrorCode(errorCode, context);
    if (errorCode == 25) {
        class = 11;
    } else if (errorCode == 26) {
        class = 12;
    }
    switch (class) {
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        return FALSE;
    default:
        return TRUE;
    }
}

BOOL WiFiPlaza_HasConnectionFailed(void) {
    if (CommState_HasWifiFailed() || CommState_HasPlazaLobbyFailed()) {
        return TRUE;
    }
    return FALSE;
}

WiFiPlazaNews *WiFiPlazaNews_New(enum HeapID heapID) {
    WiFiPlazaNews *news = Heap_Alloc(heapID, sizeof(WiFiPlazaNews));
    memset(news, 0, sizeof(WiFiPlazaNews));
    WiFiPlazaNewsSlots_Init(&news->slots);
    WiFiPlazaNewsEventList_Init(&news->events, heapID);
    return news;
}

void WiFiPlazaNews_Delete(WiFiPlazaNews *news) {
    WiFiPlazaNewsEventList_Free(&news->events);
    Heap_Free(news);
}

void WiFiPlazaNews_Update(WiFiPlazaNews *news) {
    WiFiPlazaNewsEventList_Update(&news->events);
    WiFiPlazaNewsSlots_SetChange(&news->slots, 0);
}
