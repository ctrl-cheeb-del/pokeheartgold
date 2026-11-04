#ifndef POKEHEARTGOLD_APPLICATION_POKEWALKER_POKEWALKER_MODES2_H
#define POKEHEARTGOLD_APPLICATION_POKEWALKER_POKEWALKER_MODES2_H

#include "application/pokewalker/pokewalker_app.h"

#include "pokemon_storage_system.h"
#include "sprite.h"
#include "sprite_resource_header.h"
#include "sprite_resource.h"

// A PC box or party Pokemon as the box selector (BoxMonSelector_New..) reads it through its callbacks.
typedef struct PokewalkerBoxMon {
    u32 species;
    u32 personality;
    u16 isEgg;
    u16 form;
    u16 heldItem;
    u16 unk_0E;
    u16 isShiny;
    u16 gender;
    u16 level;
    u16 markings;
    u16 nickname[POKEMON_NAME_LENGTH + 2];
} PokewalkerBoxMon;

// What the box selector shows about the Pokemon under the cursor (ov112_021F04DC).
typedef struct PokewalkerSelectMonInfo {
    u32 personality;
    u16 species;
    u8 isShiny;
    u8 form;
    u8 gender;
    u8 state; // 0 = no Pokemon, 2 = Pokemon
    u16 nickname[POKEMON_NAME_LENGTH + 1];
    u8 markings[6];
    u16 heldItem;
    u8 level;
} PokewalkerSelectMonInfo;

// Arguments of the Pokewalker event log app (mode 8): PokewalkerApp eventLogSaveData / eventLogRecords.
typedef struct PokewalkerEventLogArgs {
    SaveData *saveData;
    PokewalkerIrRecord *records; // the 24 event log entries read from the Pokewalker
} PokewalkerEventLogArgs;

// Sprites of the box display: the six marking sprites and the picture of the Pokemon (sub screen).
typedef struct PokewalkerBoxDisplaySprites {
    enum HeapID heapId;
    SpriteList *spriteList;
    G2dRenderer renderer;
    GF_2DGfxResMan *resMan[GF_GFX_RES_TYPE_MAX];
    SpriteResource *resObjs[2][GF_GFX_RES_TYPE_MAX]; // 0 = markings, 1 = Pokemon picture
    u8 unk_178[0x24];
    Sprite *markingSprites[6];
    Sprite *monSprite;
    void *monCharData; // 80x80 4bpp
    u16 monPalette[16];
    u32 monCharLocation; // sub screen OBJ VRAM
    u32 monPlttLocation;
} PokewalkerBoxDisplaySprites;

// Sub screen of the PC box selection (mode 7): the Pokemon under the cursor with its picture, markings, nickname,
// species, gender, level and held item.
typedef struct PokewalkerBoxDisplay {
    enum HeapID heapId;
    BgConfig *bgConfig;
    Window windows[6];
    MsgData *msgData;
    MessageFormat *msgFormat;
    String *string;
    PokewalkerBoxDisplaySprites sprites;
} PokewalkerBoxDisplay;

// Modes of the app's mode table: enter / update / exit.
enum PokewalkerAppState PokewalkerApp_LinkSave_Enter(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_LinkSave_Update(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_LinkSave_Exit(PokewalkerApp *app);
int PokewalkerApp_LinkSave_PrintSaving(PokewalkerApp *app);
int PokewalkerApp_LinkSave_WaitSaving(PokewalkerApp *app);
int PokewalkerApp_LinkSave_Save(PokewalkerApp *app);
int PokewalkerApp_LinkSave_EndSave(PokewalkerApp *app);
int PokewalkerApp_LinkSave_SetNextMode(PokewalkerApp *app);
int PokewalkerApp_LinkSave_PrintSaving2(PokewalkerApp *app);
int PokewalkerApp_LinkSave_WaitSaving2(PokewalkerApp *app);
int PokewalkerApp_LinkSave_Save2(PokewalkerApp *app);
int PokewalkerApp_LinkSave_EndSave2(PokewalkerApp *app);
int PokewalkerApp_LinkSave_GoToStrollReport(PokewalkerApp *app);
int PokewalkerApp_LinkSave_End(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_SelectMon_Enter(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_SelectMon_Update(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_SelectMon_Exit(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_EventLog_Enter(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_EventLog_Update(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_EventLog_Exit(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_WaitKey_Enter(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_WaitKey_Update(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_WaitKey_Exit(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_StrollReport_Enter(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_StrollReport_Update(PokewalkerApp *app);
enum PokewalkerAppState PokewalkerApp_StrollReport_Exit(PokewalkerApp *app);

// States of mode 10 (gStrollReportStates).
int PokewalkerApp_StrollReport_Start(PokewalkerApp *app);
int PokewalkerApp_StrollReport_ShowResults(PokewalkerApp *app);
int PokewalkerApp_StrollReport_WaitResultsFade(PokewalkerApp *app);
int PokewalkerApp_StrollReport_PrintMonArrived(PokewalkerApp *app);
int PokewalkerApp_StrollReport_PrintLevelUp(PokewalkerApp *app);
int PokewalkerApp_StrollReport_PrintWatts(PokewalkerApp *app);
int PokewalkerApp_StrollReport_PrintRouteFound(PokewalkerApp *app);
int PokewalkerApp_StrollReport_PrintRouteAvailable(PokewalkerApp *app);
int PokewalkerApp_StrollReport_PrintMilestone(PokewalkerApp *app);
int PokewalkerApp_StrollReport_PrintStarfBerry(PokewalkerApp *app);
int PokewalkerApp_StrollReport_FadeOut(PokewalkerApp *app);
int PokewalkerApp_StrollReport_WaitFadeOut(PokewalkerApp *app);
int PokewalkerApp_StrollReport_ShowCaughtMons(PokewalkerApp *app);
int PokewalkerApp_StrollReport_WaitCaughtMonsFade(PokewalkerApp *app);
int PokewalkerApp_StrollReport_PrintMonsSent(PokewalkerApp *app);
int PokewalkerApp_StrollReport_CaughtMonsFadeOut(PokewalkerApp *app);
int PokewalkerApp_StrollReport_WaitCaughtMonsFadeOut(PokewalkerApp *app);
int PokewalkerApp_StrollReport_ShowItems(PokewalkerApp *app);
int PokewalkerApp_StrollReport_WaitItemsFade(PokewalkerApp *app);
int PokewalkerApp_StrollReport_PrintItemsPlaced(PokewalkerApp *app);
int PokewalkerApp_StrollReport_ItemsFadeOut(PokewalkerApp *app);
int PokewalkerApp_StrollReport_WaitItemsFadeOut(PokewalkerApp *app);
int PokewalkerApp_StrollReport_GiftsFadeOut(PokewalkerApp *app);
int PokewalkerApp_StrollReport_WaitGiftsFadeOut(PokewalkerApp *app);
int PokewalkerApp_StrollReport_ShowGifts(PokewalkerApp *app);
int PokewalkerApp_StrollReport_WaitGiftsFade(PokewalkerApp *app);
int PokewalkerApp_StrollReport_PrintGiftWatts(PokewalkerApp *app);
int PokewalkerApp_StrollReport_PrintGiftRouteFound(PokewalkerApp *app);
int PokewalkerApp_StrollReport_GiftsDoneFadeOut(PokewalkerApp *app);
int PokewalkerApp_StrollReport_WaitGiftsDoneFadeOut(PokewalkerApp *app);
int PokewalkerApp_StrollReport_RecordsFadeOut(PokewalkerApp *app);
int PokewalkerApp_StrollReport_WaitRecordsFadeOut(PokewalkerApp *app);
int PokewalkerApp_StrollReport_ShowRecords(PokewalkerApp *app);
int PokewalkerApp_StrollReport_WaitRecordsFade(PokewalkerApp *app);
int PokewalkerApp_StrollReport_PrintRecords(PokewalkerApp *app);
int PokewalkerApp_StrollReport_WaitMessage(PokewalkerApp *app);
int PokewalkerApp_StrollReport_End(PokewalkerApp *app);

// Sub screen of the PC box selection (mode 7).
void PokewalkerBoxDisplay_GetMonPictureLocation(PokewalkerBoxDisplaySprites *sprites);
void PokewalkerBoxDisplay_LoadMonPicture(PokewalkerBoxDisplaySprites *sprites, PokewalkerSelectMonInfo *info);
void PokewalkerBoxDisplay_TransferMonPicture(PokewalkerBoxDisplaySprites *sprites);

// Shared by the box display and the Pokewalker event log app.

// Pokewalker event log app.
BOOL PokewalkerApp_IsEventLogInvalid(PokewalkerIrRecord *records);

#endif // POKEHEARTGOLD_APPLICATION_POKEWALKER_POKEWALKER_MODES2_H
