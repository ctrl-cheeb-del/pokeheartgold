#ifndef POKEHEARTGOLD_APPLICATION_POKEWALKER_POKEWALKER_APP_H
#define POKEHEARTGOLD_APPLICATION_POKEWALKER_POKEWALKER_APP_H

#include "application/pokewalker/pokewalker_ir.h"
#include "application/pokewalker/pokewalker_trainer_house.h"

#include "bag.h"
#include "bg_window.h"
#include "box_mon_selector.h"
#include "font_types_def.h"
#include "message_format.h"
#include "msgdata.h"
#include "options.h"
#include "overlay_manager.h"
#include "player_data.h"
#include "pokedex.h"
#include "pokewalker.h"
#include "render_window.h"
#include "save.h"
#include "sprite_system.h"

// Modes of the app (gPokewalkerAppModes).
enum PokewalkerAppMode {
    POKEWALKER_APP_MODE_MAIN_MENU,
    POKEWALKER_APP_MODE_QUIT_MESSAGE,
    POKEWALKER_APP_MODE_ERASE_RECORDS,
    POKEWALKER_APP_MODE_LINK,
    POKEWALKER_APP_MODE_WAIT_KEY_TO_SAVE,
    POKEWALKER_APP_MODE_START_STROLL,
    POKEWALKER_APP_MODE_LINK_SAVE,
    POKEWALKER_APP_MODE_SELECT_MON,
    POKEWALKER_APP_MODE_EVENT_LOG,
    POKEWALKER_APP_MODE_WAIT_KEY,
    POKEWALKER_APP_MODE_STROLL_REPORT,
    POKEWALKER_APP_MODE_EXIT, // leaves the app
};

// States of PokewalkerApp_Main; the mode functions return the next one.
enum PokewalkerAppState {
    POKEWALKER_APP_STATE_FADE_IN,
    POKEWALKER_APP_STATE_ENTER,
    POKEWALKER_APP_STATE_UPDATE,
    POKEWALKER_APP_STATE_EXIT,
    POKEWALKER_APP_STATE_FADE_OUT,
};

// What the link with the Pokewalker is for (chosen in the main menu).
enum PokewalkerLinkAction {
    POKEWALKER_LINK_GO_FOR_STROLL,
    POKEWALKER_LINK_RETURN_FROM_STROLL,
    POKEWALKER_LINK_RECEIVE_GIFT,
    POKEWALKER_LINK_STROLL_STARTED,
    POKEWALKER_LINK_SEND_MON_BACK,
};

// A Pokemon that can be found on a Pokewalker course.
typedef struct PokewalkerRouteMon {
    u16 species;
    u16 level;
    u16 heldItem;
    u8 form;
    u8 gender;
    u16 moves[MAX_MON_MOVES];
    u16 steps;        // steps needed before it can appear
    u16 chance;       // percent
} PokewalkerRouteMon;

// An item that can be found on a Pokewalker course.
typedef struct PokewalkerRouteItem {
    u16 item;
    u16 steps;
    u16 chance;
} PokewalkerRouteItem;

// Pokewalker course (table sPokewalkerCourses, one per course).
typedef struct PokewalkerCourse {
    u32 wattsRequired;          // watts needed to unlock the course
    u32 routeImageId;           // index into the route image table
    PokewalkerRouteMon mons[6]; // pairs; one of each pair is picked
    PokewalkerRouteItem items[10];
    u8 advantageTypes[3]; // a Pokemon of these types finds the course's Pokemon sooner
    u8 padding_BF;
} PokewalkerCourse;

// Stroll data sent to the Pokewalker with the Pokemon: the Pokemon, its course, the course's Pokemon and items,
// and their pictures and names rendered to the Pokewalker's 2bpp format.
typedef struct PokewalkerStrollData {
    PokewalkerMon mon;
    u16 nickname[POKEMON_NAME_LENGTH + 1];
    u8 friendship;
    u8 routeImageId;
    u16 courseName[21];
    PokewalkerMon routeMons[3];
    u16 routeMonSteps[3];
    u8 routeMonChances[3];
    u8 padding_8B;
    u16 routeItems[10];
    u16 routeItemSteps[10];
    u8 routeItemChances[10];
    u8 routeImage[0xC0];
    u8 courseNameImage[0x140];
    u8 monIcon[0x180];
    u8 monPicture[0x600];
    u8 nicknameImage[0x140];
    u8 routeMonIcons[3 * 0x180];
    u8 routeMonPicture[0x600];
    u8 routeMonNameImages[3 * 0x140];
    u8 routeItemNameImages[10 * 0x180];
} PokewalkerStrollData;

// Record of another game read from the Pokewalker (10 of them); the same layout as the game's own record.
typedef struct PokewalkerPeerRecord {
    u32 unk_00;
    u16 version; // GAME_VERSION of that game
    u16 unk_06;
    PokewalkerIrClock clock;
    PokewalkerTrainerHouseData trainerHouseData;
} PokewalkerPeerRecord;

// Pokemon data added to the event log (PokewalkerEventLog_InitStrollEndRecord / PokewalkerEventLog_SetGiftMon).
typedef struct PokewalkerEventLogMon {
    u16 species;
    u8 form : 5;
    u8 gender : 2;
    u8 isShiny : 1;
    u8 padding_03;
} PokewalkerEventLogMon;

typedef struct PokewalkerEventLogParams {
    u16 *nickname;
    u32 steps;
    PokewalkerEventLogMon mon;
} PokewalkerEventLogParams;

// Particle of the effect shown while data is transferred (sprites 17-116 on the main screen, 117-216 on the sub screen).
typedef struct PokewalkerAppParticle {
    u8 active;
    u8 unk_01;
    s8 swayFactor;
    s8 speed; // pixels per frame, upwards
    s16 x;
    s16 y; // < 0: sub screen
    s16 dx;
    s16 dy;
    u16 angle; // degrees
    s16 life;
} PokewalkerAppParticle;

// Position and vertical speed of the object drawn with sprites 13 (main screen) and 14 (sub screen).
typedef struct PokewalkerAppMotion {
    u8 unk_00[2];
    s8 delta; // added to y each frame; 0 = stopped, 101 = arrived at the bottom
    u8 unk_03;
    s16 x;
    s16 y; // < 0: sub screen
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 time;
} PokewalkerAppMotion;

// The PC box selection (mode 7) and the Pokemon chosen to go on a stroll.
typedef struct PokewalkerSelectMonWork {
    int state;
    BoxMonSelector *boxSelector;
    struct PokewalkerBoxDisplay *boxDisplay;
    BoxMonSelectorResult selection;
    u32 cancelled;
    u16 species;
    u16 nickname[POKEMON_NAME_LENGTH + 1];
    u8 form;
    u8 isShiny;
    u8 gender;
} PokewalkerSelectMonWork;

// Work of the Pokewalker connection app (main menu option).
typedef struct PokewalkerApp {
    enum PokewalkerAppMode mode; // index into the mode table (enter/update/exit functions)
    enum PokewalkerAppMode nextMode;
    int state;     // state of the current mode
    int nextState; // state to go to after a message or the cursor animation
    enum PokewalkerLinkAction linkAction;
    u16 linkError;     // error of the IR link (message id once shown), 0 = none
    u16 linkConnected; // the Pokewalker answered (message 6 shown)
    BgConfig *bgConfig;
    OverlayManager *childApp; // Pokewalker event log app (mode 8)
    SaveData *saveData;
    u8 irThreadStack[0x1000];
    PokewalkerIrIdentity identity;
    PokewalkerIrIdentity peerIdentity;
    u8 uploadImage[0x8C50];  // built by PokewalkerApp_BuildUploadImage
    PokewalkerMon walkerMon; // the Pokemon on the Pokewalker
    u16 walkerMonNickname[POKEMON_NAME_LENGTH + 1];
    u8 unk_9D6A[6];
    PokewalkerIrStatus irStatus;          // read from the Pokewalker
    PokewalkerIrBlocks irBlocks;          // read from the Pokewalker
    PokewalkerPeerRecord peerRecords[11]; // IR buffer; 1-10 read from the Pokewalker
    PokewalkerStrollData strollData;
    u32 unk_F1D0;
    u16 ownRecordVersion;
    u8 unk_F1D6[2];
    PokewalkerIrClock ownRecordClock;               // copied from the Pokewalker save data
    PokewalkerTrainerHouseData ownTrainerHouseData; // filled by PokewalkerApp_BuildTrainerHouseData
    u8 unk_F3F4[0x1440];
    u8 irCompressBuffer[0xCF1C];
    SaveData *eventLogSaveData; // arguments of the Pokewalker event log app (mode 8)
    PokewalkerIrRecord *eventLogRecords;
    u32 walkerSteps; // Pokewalker step count at the last link (save data)
    u32 walkerWatts;
    u16 linkProgress; // highest transfer progress while connected
    u8 unk_1D762[2];
    PokewalkerSelectMonWork selectMon;
    int courseId;
    PokepicTemplate monPicTemplate;
    u8 monSpriteBuffer[0xC80]; // 80x80 4bpp
    Pokemon *strollPartyMon;
    BoxPokemon *strollMon;
    Bag *bag;
    PlayerProfile *profile;
    Options *options;
    POKEWALKER *pokewalker;
    Pokedex *pokedex;
    MessageFormat *msgFormat;
    MsgData *msgData;
    MsgData *msgDataItemNames;
    String *string;
    String *eraseRecordsText;
    String *goForStrollText;
    String *receiveGiftText;
    String *returnFromStrollText;
    String *sendHomeText;
    String *saveAndStrollText;
    String *blankText;
    String *exitText;
    String *unk_1E478[7];
    String *strollResultsText;
    String *giftsReceivedText;
    String *walkerRecordsText;
    String *yourPokemonText;
    String *itemsObtainedText;
    String *strollResultsText2;
    String *itemsObtainedText2;
    String *exitText2;
    String *stepsToDateText;
    String *unk_1E4B8;
    String *wattsToDateText;
    String *unk_1E4C0[19];
    String *totalWattsText;
    String *totalStepsText;
    String *yesText;
    String *noText;
    u8 unk_1E51C[8];
    u32 textPrinterId;
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    ManagedSprite *sprites[217]; // 0 cursor, 9.. Pokemon icons, 17-116 / 117-216 particles (main / sub)
    u8 unk_1E894[0x1CC];
    void *monIconFile;
    NNSG2dCharacterData *monIconCharData;
    Window windows[20];    // main screen
    Window subWindows[10]; // sub screen
    u8 windowCounts[2];    // main / sub screen
    u8 windowBank;         // 0xFF = none
    u8 subWindowBank;
    WaitingIcon *waitingIcon;
    int menuSelection;
    int coursePage;    // page of the course menu
    s8 courseList[30]; // unlocked courses, 5 per page, -1 = none
    u16 numCourses;
    int unlockedCourse; // set by PokewalkerApp_UnlockNextCourse
    u32 strollSteps;    // steps walked on the Stroll (experience for the Pokemon)
    PokewalkerAppParticle particles[100];
    u8 unk_1F2C0[2];
    u8 unk_1F2C2; // mode 6: cleared before the fanfare
    u8 unk_1F2C3[0xD];
    int timer;
    u16 motionStarted;        // the motion object was started (transfer progress > 200)
    u16 monPicAlpha;          // alpha of the Pokemon picture fading in, 31 = done
    SysTask *monFadeTask;
    SysTask *subBgScrollTask;
    u16 subBgScrollX; // BG 5 (sub screen) x offset, slides in to 256
    u16 menuState;
    u16 eraseSteps; // answer to "Carry over the step count?"
    u8 unk_1F2E6[2];
    BoxPokemon returnedMon; // the Pokemon taken back from the Pokewalker
    s16 returnedMonBox;     // its PC box, -1 if none
    u8 unk_1F372[2];
    u16 strollMonLeveledUp;
    u16 receivedStarfBerry;
} PokewalkerApp;

extern const PokewalkerCourse sPokewalkerCourses[];

BOOL PokewalkerApp_Init(OverlayManager *manager, int *state);
BOOL PokewalkerApp_Main(OverlayManager *manager, int *state);
BOOL PokewalkerApp_Exit(OverlayManager *manager, int *state);
void PokewalkerApp_Setup(PokewalkerApp *app);
void PokewalkerApp_Teardown(PokewalkerApp *app);
void PokewalkerApp_LoadTilemap(PokewalkerApp *app, GFBgLayer bgId, int member);
void PokewalkerApp_StartLink(PokewalkerApp *app);
void PokewalkerApp_BuildUploadData(PokewalkerApp *app);
void PokewalkerApp_BuildSendStrollData(PokewalkerApp *app);
void PokewalkerApp_BuildUploadImage(PokewalkerApp *app, u8 *dst);
void PokewalkerApp_BuildStrollData(PokewalkerStrollData *data, PokewalkerApp *app);
int PokewalkerApp_LoadMonPicture(BoxPokemon *boxMon, void *buffer, PokepicTemplate *template, int screen);
BOOL PokewalkerApp_IsStrollStateNonzero(PokewalkerApp *app);
u32 PokewalkerApp_GetBoxMonIconFile(BoxPokemon *boxMon);
u32 PokewalkerApp_GetSpeciesIconFile(u16 species);
int PokewalkerApp_GetPictureFile(int species, int gender, int form);
void PokewalkerApp_UnlockNextCourse(PokewalkerApp *app);
int PokewalkerApp_GetWattsToNextCourse(PokewalkerApp *app, int watts);
void PokewalkerApp_ShowYesNoMenu(PokewalkerApp *app, int selection);
void PokewalkerApp_ShowSaveEraseStepsMenu(PokewalkerApp *app, int selection);
int PokewalkerApp_HandleTwoChoiceMenu(PokewalkerApp *app);
int PokewalkerApp_GetTouchedButton(int index);
void PokewalkerApp_LoadSubBg1Tilemap(PokewalkerApp *app);
void PokewalkerApp_ShowSubBg1(PokewalkerApp *app, BOOL show);
void PokewalkerApp_DrawSpindaSpotsOnPicture(void *picture, const void *mask, u32 personality);
void PokewalkerApp_AddWindowBank(PokewalkerApp *app, int bank);
void PokewalkerApp_RemoveWindowBank(PokewalkerApp *app, int bank);
void PokewalkerApp_OnModeChangeDummy(PokewalkerApp *app);
void PokewalkerApp_LoadStrings(PokewalkerApp *app);
void PokewalkerApp_FreeStrings(PokewalkerApp *app);
void PokewalkerApp_PrintExit(PokewalkerApp *app, int window);
void PokewalkerApp_PrintMessage(PokewalkerApp *app, int window, int msgId, u32 color);
void PokewalkerApp_PrintString(PokewalkerApp *app, int window, String *string, FontID fontId, u32 color);
void PokewalkerApp_PrintStringDefaultColor(PokewalkerApp *app, int window, String *string, FontID fontId);
void PokewalkerApp_PrintSubString(PokewalkerApp *app, int window, String *string, FontID fontId, u32 color);
void PokewalkerApp_PrintSubMessage(PokewalkerApp *app, int window, int msgId, u32 color);
u8 PokewalkerApp_StartMessageBox(PokewalkerApp *app, int window, int msgId);
void PokewalkerApp_ShowMessageBox(PokewalkerApp *app, int window, int msgId);
void PokewalkerApp_CreateWaitingIcon(PokewalkerApp *app);
void PokewalkerApp_DeleteWaitingIcon(PokewalkerApp *app);
void PokewalkerApp_InitSprites(PokewalkerApp *app);
void PokewalkerApp_FreeSprites(PokewalkerApp *app);
void PokewalkerApp_ResetCursor(PokewalkerApp *app);
void PokewalkerApp_SetCursorPosition(PokewalkerApp *app, int position);
void PokewalkerApp_HideCursor(PokewalkerApp *app);
void PokewalkerApp_PressCursor(PokewalkerApp *app);
void PokewalkerApp_ShowConnectionSprites(PokewalkerApp *app, int anim);
void PokewalkerApp_UpdateConnectionAnim(PokewalkerApp *app);
void PokewalkerApp_HideConnectionSprites(PokewalkerApp *app);
void PokewalkerApp_ShowSprite(PokewalkerApp *app, int index);
void PokewalkerApp_HideSprite(PokewalkerApp *app, int index);
void PokewalkerApp_SetSpriteAnim(PokewalkerApp *app, int index, int anim);
void PokewalkerApp_SetSpritePosition(PokewalkerApp *app, int index, int x, int y);
void PokewalkerApp_SpawnRisingParticle(PokewalkerApp *app);
void PokewalkerApp_SpawnFallingParticle(PokewalkerApp *app);
int PokewalkerApp_AgeParticles(PokewalkerApp *app);
void PokewalkerApp_UpdateParticles(PokewalkerApp *app);
void PokewalkerApp_HideMotionSprites(PokewalkerApp *app);
void PokewalkerApp_InitMotion(PokewalkerApp *app, PokewalkerAppMotion *motion, int kind);
BOOL PokewalkerApp_UpdateMotion(PokewalkerApp *app, PokewalkerAppMotion *motion);
void PokewalkerApp_LoadMonIcon(PokewalkerApp *app, int slot, int species, int form);
enum PokewalkerAppState PokewalkerApp_MainMenu_Enter(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_MainMenu_Update(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_MainMenu_Exit(PokewalkerApp *app);
int PokewalkerApp_MainMenu_Start(PokewalkerApp *app);
int PokewalkerApp_MainMenu_WaitFade(PokewalkerApp *app);
int PokewalkerApp_MainMenu_ShowTopMenu(PokewalkerApp *app);
int PokewalkerApp_MainMenu_HandleTopMenu(PokewalkerApp *app);
int PokewalkerApp_MainMenu_PrintWelcome(PokewalkerApp *app);
int PokewalkerApp_MainMenu_WaitWelcome(PokewalkerApp *app);
int PokewalkerApp_MainMenu_PrintStrollReady(PokewalkerApp *app);
int PokewalkerApp_MainMenu_ShowStrollMenu(PokewalkerApp *app);
int PokewalkerApp_MainMenu_HandleStrollMenu(PokewalkerApp *app);
int PokewalkerApp_MainMenu_EndStrollMenu(PokewalkerApp *app);
int PokewalkerApp_MainMenu_PrintReceive(PokewalkerApp *app);
int PokewalkerApp_MainMenu_WaitReceive(PokewalkerApp *app);
int PokewalkerApp_MainMenu_ShowReceiveMenu(PokewalkerApp *app);
int PokewalkerApp_MainMenu_HandleReceiveMenu(PokewalkerApp *app);
int PokewalkerApp_MainMenu_EndReceiveMenu(PokewalkerApp *app);
int PokewalkerApp_MainMenu_PrintStrollReady2(PokewalkerApp *app);
int PokewalkerApp_MainMenu_WaitStrollReady2(PokewalkerApp *app);
int PokewalkerApp_MainMenu_ShowFullMenu(PokewalkerApp *app);
int PokewalkerApp_MainMenu_HandleFullMenu(PokewalkerApp *app);
int PokewalkerApp_MainMenu_EndFullMenu(PokewalkerApp *app);
int PokewalkerApp_MainMenu_PrintBoxesFull(PokewalkerApp *app);
int PokewalkerApp_MainMenu_WaitBoxesFull(PokewalkerApp *app);
int PokewalkerApp_MainMenu_Quit(PokewalkerApp *app);
int PokewalkerApp_MainMenu_PrintNoPokemon(PokewalkerApp *app);
int PokewalkerApp_MainMenu_WaitMessage(PokewalkerApp *app);
int PokewalkerApp_MainMenu_WaitCursor(PokewalkerApp *app);
int PokewalkerApp_MainMenu_End(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_QuitMessage_Enter(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_QuitMessage_Update(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_QuitMessage_Exit(PokewalkerApp *app);
int PokewalkerApp_QuitMessage_Print(PokewalkerApp *app);
int PokewalkerApp_QuitMessage_WaitPrint(PokewalkerApp *app);
int PokewalkerApp_QuitMessage_WaitInput(PokewalkerApp *app);
int PokewalkerApp_QuitMessage_End(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_EraseRecords_Enter(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_EraseRecords_Update(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_EraseRecords_Exit(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_PrintCaution(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_WaitCaution(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_HandleCautionYesNo(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_PrintWillErase(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_ShowEraseMenu(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_HandleEraseMenu(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_EndEraseMenu(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_PrintCarryOverSteps(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_WaitCarryOverSteps(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_ShowCarryOverStepsMenu(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_HandleCarryOverStepsMenu(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_PrintConnect(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_WaitMessage(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_PrintPointAtCard(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_WaitPointAtCard(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_PrepareLink(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_StartLink(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_UpdateLink(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_PrintCanceled(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_WaitCanceled(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_PrintInitialized(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_WaitInitialized(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_PrintComeBack(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_WaitComeBack(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_ShowReturnedMon(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_AnimateReturnedMon(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_AfterAnimation(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_PrintArrived(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_WaitArrived(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_PrintSaving(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_WaitSaving(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_Save(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_EndSave(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_WaitCursor(PokewalkerApp *app);
int PokewalkerApp_EraseRecords_End(PokewalkerApp *app);
void PokewalkerApp_SelectMenuItem(PokewalkerApp *app, int selection, int cursorPosition, int nextState);
void PokewalkerApp_StartMessage(PokewalkerApp *app, int window, int msgId, int nextState);
enum PokewalkerAppState PokewalkerApp_WaitKeyToSave_Enter(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_WaitKeyToSave_Update(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_WaitKeyToSave_Exit(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_StartStroll_Enter(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_StartStroll_Update(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_StartStroll_Exit(PokewalkerApp *app);
int PokewalkerApp_StartStroll_PrintSaving(PokewalkerApp *app);
int PokewalkerApp_StartStroll_WaitSaving(PokewalkerApp *app);
int PokewalkerApp_StartStroll_Save(PokewalkerApp *app);
int PokewalkerApp_StartStroll_EndSave(PokewalkerApp *app);
int PokewalkerApp_StartStroll_CheckFirstStroll(PokewalkerApp *app);
int PokewalkerApp_StartStroll_PrintRegistered(PokewalkerApp *app);
int PokewalkerApp_StartStroll_WaitRegistered(PokewalkerApp *app);
int PokewalkerApp_StartStroll_End(PokewalkerApp *app);
void PokewalkerApp_ReturnStrollMon(PokewalkerApp *app);
void PokewalkerApp_GiveStarfBerry(PokewalkerApp *app);
void PokewalkerApp_ReceiveItems(PokewalkerApp *app);
void PokewalkerApp_ReceiveMons(PokewalkerApp *app, BOOL useWalkerBox);
int PokewalkerApp_Link_Enter(PokewalkerApp *app);
int PokewalkerApp_Link_Update(PokewalkerApp *app);
int PokewalkerApp_Link_Exit(PokewalkerApp *app);
int PokewalkerApp_Link_Start(PokewalkerApp *app);
int PokewalkerApp_Link_PrintPointAtCard(PokewalkerApp *app);
int PokewalkerApp_Link_WaitPointAtCard(PokewalkerApp *app);
int PokewalkerApp_Link_FadeOutToSelectMon(PokewalkerApp *app);
int PokewalkerApp_Link_WaitFadeOutToSelectMon(PokewalkerApp *app);
int PokewalkerApp_Link_FadeIn(PokewalkerApp *app);
int PokewalkerApp_Link_WaitFadeIn(PokewalkerApp *app);
int PokewalkerApp_Link_PrintSelectCourse(PokewalkerApp *app);
int PokewalkerApp_Link_WaitSelectCourse(PokewalkerApp *app);
int PokewalkerApp_GetCoursePageCount(PokewalkerApp *app);
void PokewalkerApp_PrintCoursePage(PokewalkerApp *app);
void PokewalkerApp_PrintCourseInfo(PokewalkerApp *app, int page, int selection);
int PokewalkerApp_ListUnlockedCourses(PokewalkerApp *app);
int PokewalkerApp_Link_ShowCourseMenu(PokewalkerApp *app);
void PokewalkerApp_UpdatePageArrows(PokewalkerApp *app, int page);
int PokewalkerApp_GetSelectedCourse(PokewalkerApp *app);
int PokewalkerApp_Link_HandleCourseMenu(PokewalkerApp *app);
int PokewalkerApp_Link_EndCourseMenu(PokewalkerApp *app);
void PokewalkerApp_ChangeCoursePage(PokewalkerApp *app, int direction);
int PokewalkerApp_Link_PrintConfirmCourse(PokewalkerApp *app);
int PokewalkerApp_Link_WaitConfirmCourse(PokewalkerApp *app);
int PokewalkerApp_Link_ShowConfirmCourseYesNo(PokewalkerApp *app);
int PokewalkerApp_Link_HandleConfirmCourseYesNo(PokewalkerApp *app);
int PokewalkerApp_Link_PrintInstructions(PokewalkerApp *app);
int PokewalkerApp_Link_WaitInstructions(PokewalkerApp *app);
int PokewalkerApp_Link_PrintWillConnectWithMon(PokewalkerApp *app);
int PokewalkerApp_Link_PrintWillConnect(PokewalkerApp *app);
int PokewalkerApp_Link_PrintPointAtCardForStroll(PokewalkerApp *app);
int PokewalkerApp_Link_WaitPointAtCardForStroll(PokewalkerApp *app);
void PokewalkerApp_ShowMonPicture(PokewalkerApp *app);
void PokewalkerApp_FadeInMonPicture(PokewalkerApp *app);
void PokewalkerApp_FadeInMonPictureTask(SysTask *task, PokewalkerApp *app);
void PokewalkerApp_ScrollSubBgTask(SysTask *task, void *data);
int PokewalkerApp_Link_PrintPointAtCardForGifts(PokewalkerApp *app);
int PokewalkerApp_Link_WaitPointAtCardForGifts(PokewalkerApp *app);
void PokewalkerApp_ResetLinkError(PokewalkerApp *app);
int PokewalkerApp_Link_StartUpload(PokewalkerApp *app);
void PokewalkerApp_StartSubBgScroll(PokewalkerApp *app);
void PokewalkerApp_PlayTransferSE(int progress);
int PokewalkerApp_UpdateLinkProgress(PokewalkerApp *app, int progress);
int PokewalkerApp_Link_UpdateUpload(PokewalkerApp *app);
int PokewalkerApp_Link_StartReceive(PokewalkerApp *app);
void PokewalkerApp_AddPeerTrainerHouseSets(PokewalkerApp *app);
void PokewalkerApp_UpdateSavedSteps(PokewalkerApp *app);
void PokewalkerApp_AddSavedTotal(PokewalkerApp *app);
BOOL PokewalkerApp_IsWalkerMonValid(PokewalkerApp *app);
BOOL PokewalkerApp_IsGiftMonValid(PokewalkerApp *app);
int PokewalkerApp_Link_UpdateReceive(PokewalkerApp *app);
int PokewalkerApp_Link_StartReceiveGifts(PokewalkerApp *app);
int PokewalkerApp_Link_UpdateReceiveGifts(PokewalkerApp *app);
int PokewalkerApp_Link_StartSendStroll(PokewalkerApp *app);
void PokewalkerApp_SetWalkerIconFrame(PokewalkerApp *app, int progress);
int PokewalkerApp_Link_UpdateSendStroll(PokewalkerApp *app);
int PokewalkerApp_GetLinkErrorMessage(int error);
int PokewalkerApp_Link_PrintError(PokewalkerApp *app);
int PokewalkerApp_Link_PrintCanceled(PokewalkerApp *app);
int PokewalkerApp_Link_RetryInstructions(PokewalkerApp *app);
int PokewalkerApp_Link_RetryPointAtCardForStroll(PokewalkerApp *app);
int PokewalkerApp_Link_RetryPointAtCard(PokewalkerApp *app);
int PokewalkerApp_Link_RetryPointAtCardForGifts(PokewalkerApp *app);
int PokewalkerApp_Link_WaitError(PokewalkerApp *app);
int PokewalkerApp_Link_PrintWentToWalker(PokewalkerApp *app);
int PokewalkerApp_Link_WaitWentToWalker(PokewalkerApp *app);
int PokewalkerApp_Link_PrintReturned(PokewalkerApp *app);
BOOL PokewalkerApp_IsWalkerMonInSave(PokewalkerApp *app);
int PokewalkerApp_Link_WaitReturned(PokewalkerApp *app);
int PokewalkerApp_Link_PrintReleased(PokewalkerApp *app);
int PokewalkerApp_Link_WaitReleased(PokewalkerApp *app);
int PokewalkerApp_Link_PrintReceivedGifts(PokewalkerApp *app);
int PokewalkerApp_Link_WaitReceivedGifts(PokewalkerApp *app);
int PokewalkerApp_Link_PrintSendBackCaution(PokewalkerApp *app);
int PokewalkerApp_Link_WaitSendBackCaution(PokewalkerApp *app);
int PokewalkerApp_Link_ShowSendBackYesNo(PokewalkerApp *app);
int PokewalkerApp_Link_HandleSendBackYesNo(PokewalkerApp *app);
int PokewalkerApp_Link_PrintWillSendBack(PokewalkerApp *app);
int PokewalkerApp_Link_WaitWillSendBack(PokewalkerApp *app);
int PokewalkerApp_Link_ShowSendBackMenu(PokewalkerApp *app);
int PokewalkerApp_Link_HandleSendBackMenu(PokewalkerApp *app);
int PokewalkerApp_Link_EndSendBackMenu(PokewalkerApp *app);
int PokewalkerApp_Link_PrintComeBack(PokewalkerApp *app);
int PokewalkerApp_Link_StartReturnAnimation(PokewalkerApp *app);
int PokewalkerApp_Link_AnimateReturn(PokewalkerApp *app);
int PokewalkerApp_Link_AfterReturnAnimation(PokewalkerApp *app);
int PokewalkerApp_Link_PrintArrived(PokewalkerApp *app);
int PokewalkerApp_Link_EndSendBack(PokewalkerApp *app);
int PokewalkerApp_Link_FadeOut(PokewalkerApp *app);
int PokewalkerApp_Link_WaitFadeOut(PokewalkerApp *app);
int PokewalkerApp_Link_WaitMessage(PokewalkerApp *app);
int PokewalkerApp_Link_WaitCursor(PokewalkerApp *app);
int PokewalkerApp_Link_End(PokewalkerApp *app);
void PokewalkerApp_AddStrollToEventLog(PokewalkerApp *app);
void PokewalkerEventLog_InitStrollEndRecord(PokewalkerIrRecord *record, PokewalkerEventLogParams *params);
void PokewalkerEventLog_SetGiftMon(PokewalkerIrRecord *records, PokewalkerEventLogMon *mon);
BOOL PokewalkerEventLog_HasGiftMon(PokewalkerIrRecord *records);

#endif // POKEHEARTGOLD_APPLICATION_POKEWALKER_POKEWALKER_APP_H
