#include "wifi_plaza/wifi_plaza_room.h"

#include <string.h>

#include "global.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0777.h"
#include "msgdata/msg/msg_0800.h"
#include "wifi_plaza/wifi_plaza_event.h"

#include "assert.h"
#include "comm_state.h"
#include "comm_state_internal.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "oam_manager.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "options.h"
#include "overlay_manager.h"
#include "palette.h"
#include "pokemon.h"
#include "render_text.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "sprite_transfer.h"
#include "swap_3d_buffers.h"
#include "sys_task_api.h"
#include "system.h"
#include "text.h"
#include "type_icon_resources.h"
#include "vram_transfer_manager.h"
#include "wireless_status_icon.h"

enum WiFiPlazaRoomState {
    WIFI_PLAZA_ROOM_FADE_IN,
    WIFI_PLAZA_ROOM_WAIT_FADE_IN,
    WIFI_PLAZA_ROOM_UPDATE,
    WIFI_PLAZA_ROOM_SHOW_ERROR,
    WIFI_PLAZA_ROOM_WAIT_ERROR,
    WIFI_PLAZA_ROOM_SHOW_CLOSING,
    WIFI_PLAZA_ROOM_WAIT_CLOSING,
    WIFI_PLAZA_ROOM_FADE_OUT,
    WIFI_PLAZA_ROOM_WAIT_FADE_OUT,
};

enum WiFiPlazaInfoPanelState {
    WIFI_PLAZA_PANEL_WAIT_START,
    WIFI_PLAZA_PANEL_FADE_OUT_START,
    WIFI_PLAZA_PANEL_SHOW_START_CARD,
    WIFI_PLAZA_PANEL_FADE_IN_START,
    WIFI_PLAZA_PANEL_WAIT_FADE_IN_START,
    WIFI_PLAZA_PANEL_IDLE,
    WIFI_PLAZA_PANEL_FADE_OUT,
    WIFI_PLAZA_PANEL_HIDE_PAGE,
    WIFI_PLAZA_PANEL_SHOW_PAGE,
    WIFI_PLAZA_PANEL_FADE_IN,
    WIFI_PLAZA_PANEL_WAIT_FADE_IN,
};

enum WiFiPlazaInfoPanelPage {
    WIFI_PLAZA_PANEL_PAGE_NONE,
    WIFI_PLAZA_PANEL_PAGE_OWN_CARD,
    WIFI_PLAZA_PANEL_PAGE_PLAYER_CARD,
    WIFI_PLAZA_PANEL_PAGE_INSTRUMENT,
    WIFI_PLAZA_PANEL_PAGE_START_CARD,
};

static void WiFiPlazaRoom_VBlank(void *data);
static void WiFiPlazaRoom_InitGraphics(WiFiPlazaRoomGraphics *graphics, SaveData *save, enum HeapID heapID);
static void WiFiPlazaRoom_DrawSprites(WiFiPlazaRoomGraphics *graphics);
static void WiFiPlazaRoom_FreeGraphics(WiFiPlazaRoomGraphics *graphics);
static void WiFiPlazaRoom_GraphicsVBlank(WiFiPlazaRoomGraphics *graphics);
static void WiFiPlazaRoom_Setup3D(void);
static void WiFiPlazaRoom_Update(WiFiPlazaRoomWork *room);
static void WiFiPlazaRoom_Draw(WiFiPlazaRoomWork *room);
static void WiFiPlazaRoom_UpdateMatchSigns(WiFiPlazaRoomWork *room);
static void WiFiPlazaMsgWindow_Init(WiFiPlazaMsgWindow *window, WiFiPlazaRoomGraphics *graphics, SaveData *save, enum HeapID heapID);
static void WiFiPlazaMsgWindow_Free(WiFiPlazaMsgWindow *window);
static void WiFiPlazaMsgWindow_Print(WiFiPlazaMsgWindow *window, String *string);
static void WiFiPlazaMsgWindow_PrintInstant(WiFiPlazaMsgWindow *window, String *string);
static void WiFiPlazaMsgWindow_ShowWaitingIcon(WiFiPlazaMsgWindow *window);
static void WiFiPlazaMsgWindow_HideWaitingIcon(WiFiPlazaMsgWindow *window);
static void WiFiPlazaMsgWindow_DeleteWaitingIcon(WiFiPlazaMsgWindow *window);
static BOOL WiFiPlazaMsgWindow_IsWaitingIconShown(WiFiPlazaMsgWindow *window);
static BOOL WiFiPlazaMsgWindow_IsPrintFinished(WiFiPlazaMsgWindow *window);
static void WiFiPlazaMsgWindow_Close(WiFiPlazaMsgWindow *window);
static void WiFiPlazaSignWindow_Init(WiFiPlazaMsgWindow *window, WiFiPlazaRoomGraphics *graphics, SaveData *save, enum HeapID heapID);
static void WiFiPlazaSignWindow_Free(WiFiPlazaMsgWindow *window);
static void WiFiPlazaSignWindow_Print(WiFiPlazaMsgWindow *window, String *string);
static void WiFiPlazaListMenu_Init(WiFiPlazaListMenu *menu, WiFiPlazaRoomGraphics *graphics, enum HeapID heapID);
static void WiFiPlazaListMenu_Free(WiFiPlazaListMenu *menu, WiFiPlazaRoomGraphics *graphics);
static void WiFiPlazaListMenu_CreateItems(WiFiPlazaListMenu *menu, u32 count, enum HeapID heapID, int value);
static void WiFiPlazaListMenu_DeleteItems(WiFiPlazaListMenu *menu);
static void WiFiPlazaListMenu_AddItem(WiFiPlazaListMenu *menu, String *text, int value);
static ListMenuItem *WiFiPlazaListMenu_GetItems(WiFiPlazaListMenu *menu);
static BOOL WiFiPlazaListMenu_HasItemValue(WiFiPlazaListMenu *menu, int value);
static void WiFiPlazaListMenu_Open(WiFiPlazaListMenu *menu, const ListMenuTemplate *template, WiFiPlazaRoomGraphics *graphics, u16 cursorPos, u16 itemsAbove, enum HeapID heapID, u8 x, u8 y, u8 width);
static s32 WiFiPlazaListMenu_ProcessInput(WiFiPlazaListMenu *menu);
static void WiFiPlazaListMenu_Close(WiFiPlazaListMenu *menu, u16 *cursorPos, u16 *itemsAbove);
static void WiFiPlazaListMenu_OnCursorMove(ListMenu *listMenu, s32 index, u8 onInit);
static void WiFiPlazaListMenu_SetShowArrows(WiFiPlazaListMenu *menu, BOOL show);
static void WiFiPlazaListMenu_UpdateArrows(WiFiPlazaListMenu *menu);
static void WiFiPlazaTextWindow_Init(Window *window, WiFiPlazaRoomGraphics *graphics, enum HeapID heapID);
static void WiFiPlazaTextWindow_Free(Window *window);
static void WiFiPlazaTextWindow_Open(Window *window, WiFiPlazaRoomGraphics *graphics, enum HeapID heapID, u8 x, u8 y, u8 width, u8 height);
static void WiFiPlazaTextWindow_Close(Window *window);
static void WiFiPlazaTextWindow_Print(Window *window, String *string, u32 x, u32 y);
static void WiFiPlazaTextWindow_FillRect(Window *window, u16 x, u16 y, u16 width, u16 height);
static void WiFiPlazaYesNoMenu_Init(WiFiPlazaYesNoMenu *menu, WiFiPlazaRoomMsg *msg, enum HeapID heapID);
static void WiFiPlazaYesNoMenu_Free(WiFiPlazaYesNoMenu *menu);
static void WiFiPlazaErrorWindow_Init(Window *window, WiFiPlazaRoomGraphics *graphics, enum HeapID heapID);
static void WiFiPlazaErrorWindow_Free(Window *window);
static void WiFiPlazaErrorWindow_Print(Window *window, String *string);
static void WiFiPlazaErrorWindow_PrintCommError(Window *window, WiFiPlazaRoomMsg *msg);
static void WiFiPlazaErrorWindow_PrintLobbyError(Window *window, WiFiPlazaRoomMsg *msg, u32 error);
static void WiFiPlazaErrorWindow_PrintDisconnected(Window *window, WiFiPlazaRoomMsg *msg, u32 unused);
static void WiFiPlazaRoomMsg_Init(WiFiPlazaRoomMsg *msg, enum HeapID heapID);
static void WiFiPlazaRoomMsg_Free(WiFiPlazaRoomMsg *msg);
static String *WiFiPlazaRoomMsg_GetString(WiFiPlazaRoomMsg *msg, int bank, int msgId);
static void WiFiPlazaRoomMsg_BufferInt(WiFiPlazaRoomMsg *msg, int value, int digits, int field, int style);
static void WiFiPlazaRoomMsg_BufferPlayerName(WiFiPlazaRoomMsg *msg, PlayerProfile *profile, u32 field);
static void WiFiPlazaRoomMsg_BufferActivityName(WiFiPlazaRoomMsg *msg, u32 activity, u32 field);
static void WiFiPlazaRoomMsg_BufferEventName(WiFiPlazaRoomMsg *msg, u32 event, u32 field);
static void WiFiPlazaRoomMsg_BufferInstrumentName(WiFiPlazaRoomMsg *msg, u32 instrument, u32 field);
static void WiFiPlazaRoomMsg_BufferCountryName(WiFiPlazaRoomMsg *msg, u32 country, u32 field);
static void WiFiPlazaRoomMsg_BufferCityName(WiFiPlazaRoomMsg *msg, u32 country, u32 city, u32 field);
static void WiFiPlazaRoomMsg_BufferECWord(WiFiPlazaRoomMsg *msg, u32 field, u16 word);
static void WiFiPlazaRoomMsg_ResetBuffers(WiFiPlazaRoomMsg *msg);
static void WiFiPlazaRoom_SetPanelButtonPressed(WiFiPlazaRoomWork *room);
static void WiFiPlazaInfoPanel_Init(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomEntry *startParams, WiFiPlazaRoomGraphics *graphics, PlayerProfile *profile, enum HeapID heapID);
static void WiFiPlazaInfoPanel_Free(WiFiPlazaInfoPanel *panel, WiFiPlazaMsgWindow *signWindow, WiFiPlazaRoomGraphics *graphics);
static void WiFiPlazaInfoPanel_Update(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomWork *room, BOOL paused, enum HeapID heapID);
static u8 WiFiPlazaInfoPanel_GetState(WiFiPlazaInfoPanel *panel);
static void WiFiPlazaInfoPanel_RequestPlayerCard(WiFiPlazaInfoPanel *panel, u32 playerIndex, u32 showMessage);
static void WiFiPlazaInfoPanel_SetCardIcon(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics, u32 icon, enum HeapID heapID);
static void WiFiPlazaInfoPanel_RequestOwnCard(WiFiPlazaInfoPanel *panel);
static void WiFiPlazaInfoPanel_RequestInstrument(WiFiPlazaInfoPanel *panel);
static u8 WiFiPlazaInfoPanel_GetCardPlayer(WiFiPlazaInfoPanel *panel);
static BOOL WiFiPlazaInfoPanel_IsPlayerCardShown(WiFiPlazaInfoPanel *panel);
static BOOL WiFiPlazaInfoPanel_IsPlayerCardIdle(WiFiPlazaInfoPanel *panel);
static BOOL WiFiPlazaInfoPanel_CardShowsMessage(WiFiPlazaInfoPanel *panel);
static BOOL WiFiPlazaInfoPanel_HasRequest(WiFiPlazaInfoPanel *panel);
static void WiFiPlazaInfoPanel_ShowPlayerCard(WiFiPlazaInfoPanel *panel, WiFiPlazaMsgWindow *signWindow, WiFiPlazaRoomGraphics *graphics, WiFiPlazaRoomMsg *msg, BOOL isOwn, enum HeapID heapID, struct WiFiPlazaPlayer *player, struct WiFiPlazaPlayer *myPlayer, int special, BOOL hasMessage, u16 *message, BOOL showIcon);
static void WiFiPlazaInfoPanel_HidePlayerCard(WiFiPlazaInfoPanel *panel, WiFiPlazaMsgWindow *signWindow, WiFiPlazaRoomGraphics *graphics);
static void WiFiPlazaInfoPanel_ShowOwnCard(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics, WiFiPlazaRoomMsg *msg, enum HeapID heapID, struct WiFiPlazaPlayer *player);
static void WiFiPlazaInfoPanel_ShowInstrument(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics, enum HeapID heapID, u32 type);
static void WiFiPlazaInfoPanel_HideButtonPage(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics);
static void WiFiPlazaInfoPanel_SetButtonDisabled(WiFiPlazaInfoPanel *panel, u16 disabled);
static SysTask *WiFiPlazaInfoPanel_StartPaletteLoad(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics, u32 member, enum HeapID heapID);
static void WiFiPlazaInfoPanel_LoadPaletteTask(SysTask *task, void *data);
static void WiFiPlazaInfoPanel_LoadGraphics(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics, NARC *narc, u32 gender, enum HeapID heapID);
static void WiFiPlazaInfoPanel_FreeGraphics(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics);
static void WiFiPlazaInfoPanel_LoadScreen(WiFiPlazaRoomGraphics *graphics, NARC *narc, int member, GFBgLayer bgId, int tileOffset, enum HeapID heapID);
static void WiFiPlazaPlayerCard_Init(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics, NARC *narc, enum HeapID heapID);
static void WiFiPlazaPlayerCard_Free(WiFiPlazaPlayerCard *card, WiFiPlazaMsgWindow *signWindow, WiFiPlazaRoomGraphics *graphics);
static void WiFiPlazaPlayerCard_Update(WiFiPlazaPlayerCard *card, WiFiPlazaMsgWindow *signWindow);
static void WiFiPlazaPlayerCard_Show(WiFiPlazaInfoPanel *panel, WiFiPlazaMsgWindow *signWindow, WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics, WiFiPlazaRoomMsg *msg, BOOL isOwn, NARC *narc, enum HeapID heapID, struct WiFiPlazaPlayer *player, struct WiFiPlazaPlayer *myPlayer, int special, BOOL hasMessage, u16 *message, BOOL showIcon);
static void WiFiPlazaPlayerCard_LoadTypeIcons(WiFiPlazaInfoPanel *unused0, WiFiPlazaPlayerCard *unused1, WiFiPlazaRoomGraphics *graphics, enum HeapID heapID, struct WiFiPlazaPlayer *player);
static void WiFiPlazaPlayerCard_Clear(WiFiPlazaPlayerCard *card, WiFiPlazaMsgWindow *unused, WiFiPlazaRoomGraphics *graphics);
static void WiFiPlazaPlayerCard_ChangeIcon(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics, NARC *narc, enum HeapID heapID, u32 icon);
static BOOL WiFiPlazaPlayerCard_ShowsMessage(WiFiPlazaPlayerCard *card);
static void WiFiPlazaPlayerCard_LoadIcon(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics, NARC *narc, enum HeapID heapID, u32 icon, BOOL draw);
static void WiFiPlazaPlayerCard_FreeIcon(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics);
static void WiFiPlazaPlayerCard_LoadAvatar(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics, NARC *narc, enum HeapID heapID, u32 avatar);
static void WiFiPlazaPlayerCard_FreeAvatar(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics);
static void WiFiPlazaInfoPanel_TintPalette(NNSG2dPaletteData *pltt);
static void WiFiPlazaPlayerCard_ClearWindows(WiFiPlazaPlayerCard *card);
static void WiFiPlazaPlayerCard_Print(WiFiPlazaPlayerCard *card, WiFiPlazaRoomMsg *msg, int window, int msgId, u8 x, u8 y, u32 color);
static void WiFiPlazaPlayerCard_PrintRightAligned(WiFiPlazaPlayerCard *card, WiFiPlazaRoomMsg *msg, int window, int msgId, u8 width, u8 y, u32 color);
static void WiFiPlazaPlayerCard_CopyWindow(WiFiPlazaPlayerCard *card, int window);
static void WiFiPlazaPlayerCard_BufferName(WiFiPlazaPlayerCard *card, WiFiPlazaRoomMsg *msg, PlayerProfile *profile);
static void WiFiPlazaPlayerCard_BufferLocation(WiFiPlazaPlayerCard *card, WiFiPlazaRoomMsg *msg, struct WiFiPlazaPlayer *player);
static void WiFiPlazaPlayerCard_BufferMessage(WiFiPlazaPlayerCard *card, WiFiPlazaRoomMsg *msg, u16 *words);
static void WiFiPlazaPlayerCard_LoadMons(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics, NARC *panelNarc, enum HeapID heapID, struct WiFiPlazaPlayer *player, struct WiFiPlazaPlayer *myPlayer);
static void WiFiPlazaPlayerCard_FreeMons(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics);
static const WiFiPlazaCardMonInfo *WiFiPlazaPlayerCard_GetMonInfo(int species, int form, int version, int gender);
static void WiFiPlazaPanelButton_Init(WiFiPlazaPanelButton *button, WiFiPlazaRoomGraphics *graphics, NARC *narc, enum HeapID heapID);
static void WiFiPlazaPanelButton_Free(WiFiPlazaPanelButton *button);
static BOOL WiFiPlazaPanelButton_Update(WiFiPlazaPanelButton *button, WiFiPlazaRoomGraphics *graphics, NARC *narc, enum HeapID heapID);
static void WiFiPlazaPanelButton_ShowOwnCard(WiFiPlazaPanelButton *button, WiFiPlazaRoomGraphics *graphics, WiFiPlazaRoomMsg *msg, struct WiFiPlazaPlayer *player, NARC *narc, enum HeapID heapID);
static void WiFiPlazaPanelButton_ShowInstrument(WiFiPlazaPanelButton *button, WiFiPlazaRoomGraphics *graphics, u32 type, NARC *narc, enum HeapID heapID);
static void WiFiPlazaPanelButton_Clear(WiFiPlazaPanelButton *unused, WiFiPlazaRoomGraphics *graphics);
static void WiFiPlazaPanelButton_Draw(WiFiPlazaPanelButton *button, WiFiPlazaRoomGraphics *graphics, int index, NARC *narc, enum HeapID heapID);
static void WiFiPlazaPanelButton_OnTouch(u32 index, u32 event, void *arg);
static void WiFiPlazaPanelButton_ResetTimer(WiFiPlazaPanelButton *button);

static const GraphicsModes sWiFiPlazaRoomGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_3D,
};

static const u8 sWiFiPlazaListArrowY[2] = { 20, 136 };

static const BgTemplate sWiFiPlazaRoomBgTemplates[4] = {
    {
     .x = 0,
     .y = 0,
     .bufferSize = 0x800,
     .baseTile = 0,
     .size = GF_BG_SCR_SIZE_256x256,
     .colorMode = GX_BG_COLORMODE_16,
     .screenBase = GX_BG_SCRBASE_0x7800,
     .charBase = GX_BG_CHARBASE_0x00000,
     .bgExtPltt = GX_BG_EXTPLTT_01,
     .priority = 0,
     .areaOver = GX_BG_AREAOVER_XLU,
     .mosaic = FALSE,
     },
    {
     .x = 0,
     .y = 0,
     .bufferSize = 0x800,
     .baseTile = 0,
     .size = GF_BG_SCR_SIZE_256x256,
     .colorMode = GX_BG_COLORMODE_16,
     .screenBase = GX_BG_SCRBASE_0x7800,
     .charBase = GX_BG_CHARBASE_0x00000,
     .bgExtPltt = GX_BG_EXTPLTT_01,
     .priority = 2,
     .areaOver = GX_BG_AREAOVER_XLU,
     .mosaic = FALSE,
     },
    {
     .x = 0,
     .y = 0,
     .bufferSize = 0x800,
     .baseTile = 0,
     .size = GF_BG_SCR_SIZE_256x256,
     .colorMode = GX_BG_COLORMODE_16,
     .screenBase = GX_BG_SCRBASE_0x7000,
     .charBase = GX_BG_CHARBASE_0x00000,
     .bgExtPltt = GX_BG_EXTPLTT_01,
     .priority = 1,
     .areaOver = GX_BG_AREAOVER_XLU,
     .mosaic = FALSE,
     },
    {
     .x = 0,
     .y = 0,
     .bufferSize = 0x800,
     .baseTile = 0,
     .size = GF_BG_SCR_SIZE_256x256,
     .colorMode = GX_BG_COLORMODE_16,
     .screenBase = GX_BG_SCRBASE_0x6800,
     .charBase = GX_BG_CHARBASE_0x00000,
     .bgExtPltt = GX_BG_EXTPLTT_01,
     .priority = 0,
     .areaOver = GX_BG_AREAOVER_XLU,
     .mosaic = FALSE,
     },
};

static const ObjCharTransferTemplate sWiFiPlazaRoomCharTransfer = {
    .maxTasks = 24,
    .sizeMain = 0x8000,
    .sizeSub = 0x4000,
    .heapID = HEAP_ID_119,
};

static const GraphicsBanks sWiFiPlazaRoomBanks = {
    .bg = GX_VRAM_BG_128_B,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_32_H,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_32_FG,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_01_AC,
    .texpltt = GX_VRAM_TEXPLTT_0123_E,
};

static const ListMenuTemplate sWiFiPlazaYesNoTemplate = {
    .items = NULL,
    .moveCursorFunc = NULL,
    .itemPrintFunc = NULL,
    .window = NULL,
    .totalItems = 0,
    .maxShowed = 2,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 0,
    .cursorPal = 1,
    .fillValue = 15,
    .cursorShadowPal = 2,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 0,
    .cursorKind = 0,
    .data = NULL,
};

static const u32 sWiFiPlazaRoomBgIds[4] = { GF_BG_LYR_MAIN_1, GF_BG_LYR_SUB_0, GF_BG_LYR_SUB_1, GF_BG_LYR_SUB_2 };

static const GXRgb sWiFiPlazaRoomEdgeColors[8] = { GX_RGB(0, 0, 0), GX_RGB(4, 4, 4), GX_RGB(4, 4, 4), GX_RGB(4, 4, 4), GX_RGB(4, 4, 4), GX_RGB(4, 4, 4), GX_RGB(4, 4, 4), GX_RGB(4, 4, 4) };

static const u32 sWiFiPlazaRoomMsgBanks[WIFI_PLAZA_MSG_BANK_COUNT] = { NARC_msg_msg_0776_bin, NARC_msg_msg_0777_bin, NARC_msg_msg_0800_bin, NARC_msg_msg_0766_bin };

BOOL WiFiPlazaObj_UpdateLight(WiFiPlazaObjLight *light, struct WiFiPlazaPlayerObjects *avatars) {
    if (light->active == 0) {
        return TRUE;
    }
    light->frame++;
    if (light->frame >= light->duration) {
        light->active = 0;
    }
    light->value = light->frame * light->delta / light->duration;
    light->value += light->start;
    WiFiPlazaPlayerObjects_SetModelAlpha(avatars, light->value);
    return FALSE;
}

BOOL WiFiPlazaRoom_Init(OverlayManager *manager, int *state) {
    WiFiPlazaRoomWork *room;
    WiFiPlazaRoomArgs *args = OverlayManager_GetArgs(manager);

    Heap_Create(HEAP_ID_3, HEAP_ID_119, 0x3A000);
    Heap_Create(HEAP_ID_3, HEAP_ID_120, 0x3D000);
    room = OverlayManager_CreateAndGetData(manager, sizeof(WiFiPlazaRoomWork), HEAP_ID_119);
    memset(room, 0, sizeof(WiFiPlazaRoomWork));
    room->startParams = &args->startParams;
    room->lobby = args->lobby;
    room->ownPlayerIndex = WiFiPlazaWork_GetOwnSlot(room->lobby);
    GF_ASSERT(WiFiPlazaWork_GetOwnSlot(room->lobby) != -1);
    TextFlags_SetCanABSpeedUpPrint(TRUE);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    room->profile = Save_PlayerData_GetProfile(args->save);
    WiFiPlazaRoom_InitGraphics(&room->graphics, args->save, HEAP_ID_119);
    room->map = WiFiPlazaMap_Create(HEAP_ID_119);
    room->objManager = WiFiPlazaObj_CreateManager(24, PlayerProfile_GetTrainerGender(room->profile), room->map, HEAP_ID_119, HEAP_ID_120);
    room->models = WiFiPlazaModels_Create(args->group, args->variant, room->map, HEAP_ID_119, HEAP_ID_120);
    room->camera = WiFiPlazaCamera_Create(HEAP_ID_119);
    WiFiPlazaMsgWindow_Init(&room->msgWindow, &room->graphics, args->save, HEAP_ID_119);
    WiFiPlazaSignWindow_Init(&room->signWindow, &room->graphics, args->save, HEAP_ID_119);
    WiFiPlazaListMenu_Init(&room->listMenu, &room->graphics, HEAP_ID_119);
    WiFiPlazaErrorWindow_Init(&room->errorWindow, &room->graphics, HEAP_ID_119);
    WiFiPlazaTextWindow_Init(&room->textWindow, &room->graphics, HEAP_ID_119);
    WiFiPlazaRoomMsg_Init(&room->msg, HEAP_ID_119);
    WiFiPlazaYesNoMenu_Init(&room->yesNoMenu, &room->msg, HEAP_ID_119);
    WiFiPlazaInfoPanel_Init(&room->infoPanel, room->startParams, &room->graphics, room->profile, HEAP_ID_119);
    args = (WiFiPlazaRoomArgs *)WiFiPlazaWork_GetMyPlayer(room->lobby);
    if (WiFiPlazaPlayer_HasTapToy((WiFiPlazaPlayer *)args) == TRUE) {
        WiFiPlazaInfoPanel_ShowOwnCard(&room->infoPanel, &room->graphics, &room->msg, HEAP_ID_119, (struct WiFiPlazaPlayer *)args);
    }
    room->playerStates = WiFiPlazaPlayerState_CreateManager(room, HEAP_ID_119);
    WiFiPlazaPlayerState_InitOwn(room);
    WiFiPlazaPlayerState_InitOthers(room);
    room->instruments = WiFiPlazaInstrument_Create(room->lobby, room->map, room->camera, room->objManager, HEAP_ID_119, HEAP_ID_120);
    room->event = WiFiPlazaEvent_Create(HEAP_ID_119, room);
    Main_SetVBlankIntrCB(WiFiPlazaRoom_VBlank, room);
    HBlankInterruptDisable();
    return TRUE;
}

BOOL WiFiPlazaRoom_Main(OverlayManager *manager, int *state) {
    WiFiPlazaRoomWork *room = OverlayManager_GetData(manager);
    u32 result;

    OverlayManager_GetArgs(manager);
    switch (*state) {
    case WIFI_PLAZA_ROOM_FADE_IN:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_119);
        room->fading = TRUE;
        (*state)++;
        break;
    case WIFI_PLAZA_ROOM_WAIT_FADE_IN:
        if (IsPaletteFadeFinished() == TRUE) {
            room->fading = FALSE;
            (*state)++;
        }
        break;
    case WIFI_PLAZA_ROOM_UPDATE:
        if (room->mode == 1) {
            if (WiFiPlaza_HasConnectionFailed() == TRUE || WiFiPlazaWork_HasError(room->lobby)) {
                room->error = 1;
            }
        }
        if (!room->ignorePlazaClosing && WiFiPlazaWork_IsClosed(room->lobby) == TRUE) {
            room->plazaClosing = TRUE;
            WiFiPlazaRoom_SetResult(room, WIFI_PLAZA_ROOM_RESULT_PLAZA_CLOSED);
        }
        if (room->finished == TRUE || room->error == 1 || room->plazaClosing == TRUE) {
            if (room->error != 0) {
                *state = WIFI_PLAZA_ROOM_SHOW_ERROR;
            } else if (room->plazaClosing == TRUE) {
                *state = WIFI_PLAZA_ROOM_SHOW_CLOSING;
            } else {
                *state = WIFI_PLAZA_ROOM_FADE_OUT;
            }
        }
        break;
    case WIFI_PLAZA_ROOM_SHOW_ERROR:
        WiFiPlazaMsgWindow_Close(&room->msgWindow);
        WiFiPlazaListMenu_Close(&room->listMenu, NULL, NULL);
        WiFiPlazaTextWindow_Close(&room->textWindow);
        WiFiPlazaYesNoMenu_Free(&room->yesNoMenu);
        if (CommState_HasWifiFailed()) {
            WiFiPlazaErrorWindow_PrintCommError(&room->errorWindow, &room->msg);
        } else if (CommState_HasPlazaLobbyFailed()) {
            WiFiPlazaErrorWindow_PrintLobbyError(&room->errorWindow, &room->msg, WiFiPlazaLobbyClient_GetLastError());
        } else {
            WiFiPlazaErrorWindow_PrintDisconnected(&room->errorWindow, &room->msg, WiFiPlazaWork_HasError(room->lobby));
        }
        *state = WIFI_PLAZA_ROOM_WAIT_ERROR;
        break;
    case WIFI_PLAZA_ROOM_WAIT_ERROR:
        if (gSystem.newKeys & PAD_BUTTON_A) {
            *state = WIFI_PLAZA_ROOM_FADE_OUT;
        }
        break;
    case WIFI_PLAZA_ROOM_SHOW_CLOSING:
        WiFiPlazaMsgWindow_Close(&room->msgWindow);
        WiFiPlazaListMenu_Close(&room->listMenu, NULL, NULL);
        WiFiPlazaTextWindow_Close(&room->textWindow);
        WiFiPlazaYesNoMenu_Free(&room->yesNoMenu);
        WiFiPlazaMsgWindow_Print(&room->msgWindow, WiFiPlazaRoomMsg_GetString(&room->msg, WIFI_PLAZA_MSG_BANK_PLAZA, msg_0777_00070));
        *state = WIFI_PLAZA_ROOM_WAIT_CLOSING;
        room->closingTimer = 60;
        break;
    case WIFI_PLAZA_ROOM_WAIT_CLOSING:
        if (WiFiPlazaMsgWindow_IsPrintFinished(&room->msgWindow)) {
            room->closingTimer--;
            if (room->closingTimer <= 0) {
                *state = WIFI_PLAZA_ROOM_FADE_OUT;
            }
        }
        break;
    case WIFI_PLAZA_ROOM_FADE_OUT:
        result = WiFiPlazaInfoPanel_GetState(&room->infoPanel);
        if (result == WIFI_PLAZA_PANEL_IDLE) {
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_119);
            room->fading = TRUE;
            (*state)++;
        } else if (result == WIFI_PLAZA_PANEL_WAIT_START) {
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_119);
            room->fading = TRUE;
            (*state)++;
        }
        break;
    case WIFI_PLAZA_ROOM_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished() == TRUE) {
            room->fading = FALSE;
            return TRUE;
        }
        break;
    }
    WiFiPlazaRoom_Update(room);
    WiFiPlazaRoom_Draw(room);
    return FALSE;
}

BOOL WiFiPlazaRoom_Exit(OverlayManager *manager, int *state) {
    WiFiPlazaRoomWork *room = OverlayManager_GetData(manager);
    WiFiPlazaRoomArgs *args = OverlayManager_GetArgs(manager);

    args->result = room->result;
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    WiFiPlazaEvent_Delete(room->event);
    WiFiPlazaInstrument_Delete(room->instruments);
    WiFiPlazaPlayerState_DeleteManager(room->playerStates);
    WiFiPlazaInfoPanel_Free(&room->infoPanel, &room->signWindow, &room->graphics);
    WiFiPlazaRoomMsg_Free(&room->msg);
    WiFiPlazaMsgWindow_Free(&room->msgWindow);
    WiFiPlazaSignWindow_Free(&room->signWindow);
    WiFiPlazaListMenu_Free(&room->listMenu, &room->graphics);
    WiFiPlazaErrorWindow_Free(&room->errorWindow);
    WiFiPlazaYesNoMenu_Free(&room->yesNoMenu);
    WiFiPlazaTextWindow_Free(&room->textWindow);
    WiFiPlazaCamera_Delete(room->camera);
    WiFiPlazaModels_Delete(room->models);
    WiFiPlazaObj_DeleteManager(room->objManager);
    WiFiPlazaMap_Delete(room->map);
    WiFiPlazaRoom_FreeGraphics(&room->graphics);
    Heap_Free(room);
    Heap_Destroy(HEAP_ID_119);
    Heap_Destroy(HEAP_ID_120);
    StopAllSE(0);
    StopCry(0);
    return TRUE;
}

WiFiPlazaWork *WiFiPlazaRoom_GetLobby(WiFiPlazaRoomWork *room) {
    return room->lobby;
}

WiFiPlazaRoomEntry *WiFiPlazaRoom_GetStartParams(WiFiPlazaRoomWork *room) {
    return room->startParams;
}

WiFiPlazaObjManager *WiFiPlazaRoom_GetObjManager(WiFiPlazaRoomWork *room) {
    return room->objManager;
}

WiFiPlazaModels *WiFiPlazaRoom_GetModels(WiFiPlazaRoomWork *room) {
    return room->models;
}

WiFiPlazaMap *WiFiPlazaRoom_GetMap(WiFiPlazaRoomWork *room) {
    return room->map;
}

WiFiPlazaCamera *WiFiPlazaRoom_GetCamera(WiFiPlazaRoomWork *room) {
    return room->camera;
}

WiFiPlazaPlayerStateManager *WiFiPlazaRoom_GetPlayerStates(WiFiPlazaRoomWork *room) {
    return room->playerStates;
}

void WiFiPlazaRoom_SetMode(WiFiPlazaRoomWork *room, u32 mode) {
    room->mode = mode;
}

u8 WiFiPlazaRoom_GetOwnPlayerIndex(WiFiPlazaRoomWork *room) {
    return room->ownPlayerIndex;
}

u8 WiFiPlazaRoom_IsFading(WiFiPlazaRoomWork *room) {
    return room->fading;
}

void WiFiPlazaRoom_SetFinished(WiFiPlazaRoomWork *room, u8 finished) {
    room->finished = finished;
}

void WiFiPlazaRoom_SetResult(WiFiPlazaRoomWork *room, u8 result) {
    room->result = result;
}

void WiFiPlazaRoom_SetActionTile(WiFiPlazaRoomWork *room, u8 value) {
    room->actionTile = value;
}

u8 WiFiPlazaRoom_GetActionTile(WiFiPlazaRoomWork *room) {
    return room->actionTile;
}

void WiFiPlazaRoom_IgnorePlazaClosing(WiFiPlazaRoomWork *room) {
    room->ignorePlazaClosing = TRUE;
}

void WiFiPlazaRoom_SetPlayerBusy(WiFiPlazaRoomWork *room, u8 index, u8 value) {
    GF_ASSERT(index < WIFI_PLAZA_MAX_PLAYERS);
    room->playerBusy[index] = value;
}

u8 WiFiPlazaRoom_IsPlayerBusy(WiFiPlazaRoomWork *room, u32 index) {
    return room->playerBusy[index];
}

void WiFiPlazaRoom_SetCardBlocked(WiFiPlazaRoomWork *room, u8 index, u8 value) {
    GF_ASSERT(index < WIFI_PLAZA_MAX_PLAYERS);
    room->cardBlocked[index] = value;
}

u8 WiFiPlazaRoom_IsCardBlocked(WiFiPlazaRoomWork *room, u32 index) {
    return room->cardBlocked[index];
}

void WiFiPlazaRoom_PrintMessage(WiFiPlazaRoomWork *room, String *message) {
    WiFiPlazaMsgWindow_Print(&room->msgWindow, message);
}

void WiFiPlazaRoom_PrintMessageInstant(WiFiPlazaRoomWork *room, String *message) {
    WiFiPlazaMsgWindow_PrintInstant(&room->msgWindow, message);
}

BOOL WiFiPlazaRoom_IsMessageFinished(WiFiPlazaRoomWork *room) {
    return WiFiPlazaMsgWindow_IsPrintFinished(&room->msgWindow);
}

void WiFiPlazaRoom_ShowWaitingIcon(WiFiPlazaRoomWork *room) {
    WiFiPlazaMsgWindow_ShowWaitingIcon(&room->msgWindow);
}

void WiFiPlazaRoom_HideWaitingIcon(WiFiPlazaRoomWork *room) {
    WiFiPlazaMsgWindow_HideWaitingIcon(&room->msgWindow);
}

BOOL WiFiPlazaRoom_IsWaitingIconShown(WiFiPlazaRoomWork *room) {
    return WiFiPlazaMsgWindow_IsWaitingIconShown(&room->msgWindow);
}

void WiFiPlazaRoom_CloseMessage(WiFiPlazaRoomWork *room) {
    WiFiPlazaMsgWindow_Close(&room->msgWindow);
}

void WiFiPlazaRoom_PrintSign(WiFiPlazaRoomWork *room, String *message) {
    WiFiPlazaSignWindow_Print(&room->signWindow, message);
}

void WiFiPlazaRoom_CreateListItems(WiFiPlazaRoomWork *room, u32 count) {
    WiFiPlazaListMenu_CreateItems(&room->listMenu, count, HEAP_ID_120, 0);
}

void WiFiPlazaRoom_CreateListItemsWithValue(WiFiPlazaRoomWork *room, u32 count, int value) {
    WiFiPlazaListMenu_CreateItems(&room->listMenu, count, HEAP_ID_120, value);
}

void WiFiPlazaRoom_DeleteListItems(WiFiPlazaRoomWork *room) {
    WiFiPlazaListMenu_DeleteItems(&room->listMenu);
}

void WiFiPlazaRoom_AddListItem(WiFiPlazaRoomWork *room, String *text, int value) {
    WiFiPlazaListMenu_AddItem(&room->listMenu, text, value);
}

ListMenuItem *WiFiPlazaRoom_GetListItems(WiFiPlazaRoomWork *room) {
    return WiFiPlazaListMenu_GetItems(&room->listMenu);
}

BOOL WiFiPlazaRoom_HasListItemValue(WiFiPlazaRoomWork *room, int value) {
    return WiFiPlazaListMenu_HasItemValue(&room->listMenu, value);
}

void WiFiPlazaRoom_OpenList(WiFiPlazaRoomWork *room, const ListMenuTemplate *template, u16 cursorPos, u16 itemsAbove) {
    WiFiPlazaListMenu_Open(&room->listMenu, template, &room->graphics, cursorPos, itemsAbove, HEAP_ID_119, 16, 3, 15);
}

void WiFiPlazaRoom_OpenListAt(WiFiPlazaRoomWork *room, const ListMenuTemplate *template, u16 cursorPos, u16 itemsAbove, u8 x, u8 y, u8 width) {
    WiFiPlazaListMenu_Open(&room->listMenu, template, &room->graphics, cursorPos, itemsAbove, HEAP_ID_119, x, y, width);
}

u32 WiFiPlazaRoom_ProcessList(WiFiPlazaRoomWork *room) {
    return WiFiPlazaListMenu_ProcessInput(&room->listMenu);
}

void WiFiPlazaRoom_CloseList(WiFiPlazaRoomWork *room, u16 *cursorPos, u16 *itemsAbove) {
    WiFiPlazaListMenu_Close(&room->listMenu, cursorPos, itemsAbove);
}

void WiFiPlazaRoom_SetListArrows(WiFiPlazaRoomWork *room, BOOL show) {
    WiFiPlazaListMenu_SetShowArrows(&room->listMenu, show);
}

void WiFiPlazaRoom_OpenTextWindow(WiFiPlazaRoomWork *room, u8 x, u8 y, u8 width, u8 height) {
    WiFiPlazaTextWindow_Open(&room->textWindow, &room->graphics, HEAP_ID_119, x, y, width, height);
}

void WiFiPlazaRoom_CloseTextWindow(WiFiPlazaRoomWork *room) {
    WiFiPlazaTextWindow_Close(&room->textWindow);
}

void WiFiPlazaRoom_PrintTextWindow(WiFiPlazaRoomWork *room, String *string, u32 x, u32 y) {
    WiFiPlazaTextWindow_Print(&room->textWindow, string, x, y);
}

void WiFiPlazaRoom_FillTextWindowRect(WiFiPlazaRoomWork *room, u16 x, u16 y, u16 width, u16 height) {
    WiFiPlazaTextWindow_FillRect(&room->textWindow, x, y, width, height);
}

void WiFiPlazaRoom_OpenYesNoMenu(WiFiPlazaRoomWork *room) {
    WiFiPlazaListMenu_Open(&room->listMenu, &room->yesNoMenu.template, &room->graphics, 0, 0, HEAP_ID_119, 25, 13, 6);
}

void WiFiPlazaRoom_OpenYesNoMenuDefaultNo(WiFiPlazaRoomWork *room) {
    WiFiPlazaListMenu_Open(&room->listMenu, &room->yesNoMenu.template, &room->graphics, 0, 1, HEAP_ID_119, 25, 13, 6);
}

u32 WiFiPlazaRoom_GetYesNoResult(WiFiPlazaRoomWork *room) {
    u32 input = WiFiPlazaListMenu_ProcessInput(&room->listMenu);
    switch (input) {
    case LIST_CANCEL:
        PlaySE(SEQ_SE_DP_SELECT);
        // fallthrough
    case 1:
        return WIFI_PLAZA_YES_NO_NO;
    case 0:
        return WIFI_PLAZA_YES_NO_YES;
    default:
        return WIFI_PLAZA_YES_NO_OPEN;
    }
}

void WiFiPlazaRoom_CloseYesNoMenu(WiFiPlazaRoomWork *room) {
    WiFiPlazaListMenu_Close(&room->listMenu, NULL, NULL);
}

String *WiFiPlazaRoom_GetMsgString(WiFiPlazaRoomWork *room, int bank, int msgId) {
    return WiFiPlazaRoomMsg_GetString(&room->msg, bank, msgId);
}

void WiFiPlazaRoom_BufferInt(WiFiPlazaRoomWork *room, int value, int digits, int field, int style) {
    WiFiPlazaRoomMsg_BufferInt(&room->msg, value, digits, field, style);
}

void WiFiPlazaRoom_BufferPlayerName(WiFiPlazaRoomWork *room, u32 playerIndex, u32 field) {
    PlayerProfile *profile = PlayerProfile_New(HEAP_ID_119);
    struct WiFiPlazaPlayer *player;
    if (playerIndex == WiFiPlazaWork_GetOwnSlot(room->lobby)) {
        player = WiFiPlazaWork_GetMyPlayer(room->lobby);
    } else {
        player = WiFiPlazaWork_GetPlayer(room->lobby, playerIndex);
    }
    WiFiPlazaPlayer_CopyToProfile(player, profile, HEAP_ID_119);
    WiFiPlazaRoomMsg_BufferPlayerName(&room->msg, profile, field);
    Heap_Free(profile);
}

void WiFiPlazaRoom_BufferActivityName(WiFiPlazaRoomWork *room, u32 activity, u32 field) {
    WiFiPlazaRoomMsg_BufferActivityName(&room->msg, activity, field);
}

void WiFiPlazaRoom_BufferEventName(WiFiPlazaRoomWork *room, u32 event, u32 field) {
    WiFiPlazaRoomMsg_BufferEventName(&room->msg, event, field);
}

void WiFiPlazaRoom_BufferInstrumentName(WiFiPlazaRoomWork *room, u32 instrument, u32 field) {
    WiFiPlazaRoomMsg_BufferInstrumentName(&room->msg, instrument, field);
}

void WiFiPlazaRoom_BufferJPGreeting(WiFiPlazaRoomWork *room, u32 field, u32 timeOfDay) {
    BufferJPGreeting(room->msg.format, field, timeOfDay);
}

void WiFiPlazaRoom_BufferENGreeting(WiFiPlazaRoomWork *room, u32 field, u32 timeOfDay) {
    BufferENGreeting(room->msg.format, field, timeOfDay);
}

void WiFiPlazaRoom_BufferFRGreeting(WiFiPlazaRoomWork *room, u32 field, u32 timeOfDay) {
    BufferFRGreeting(room->msg.format, field, timeOfDay);
}

void WiFiPlazaRoom_BufferITGreeting(WiFiPlazaRoomWork *room, u32 field, u32 timeOfDay) {
    BufferITGreeting(room->msg.format, field, timeOfDay);
}

void WiFiPlazaRoom_BufferDEGreeting(WiFiPlazaRoomWork *room, u32 field, u32 timeOfDay) {
    BufferDEGreeting(room->msg.format, field, timeOfDay);
}

void WiFiPlazaRoom_BufferSPGreeting(WiFiPlazaRoomWork *room, u32 field, u32 timeOfDay) {
    BufferSPGreeting(room->msg.format, field, timeOfDay);
}

void WiFiPlazaRoom_BufferTypeName(WiFiPlazaRoomWork *room, u32 field, u32 index) {
    BufferTypeName(room->msg.format, field, WiFiPlaza_GetTypeByChoice(index));
}

void WiFiPlazaRoom_ShowPlayerCard(WiFiPlazaRoomWork *room, u32 playerIndex, u32 arg) {
    if (playerIndex != WiFiPlazaInfoPanel_GetCardPlayer(&room->infoPanel) || WiFiPlazaInfoPanel_IsPlayerCardShown(&room->infoPanel) != TRUE || WiFiPlazaInfoPanel_HasRequest(&room->infoPanel) || arg != WiFiPlazaInfoPanel_CardShowsMessage(&room->infoPanel)) {
        WiFiPlazaInfoPanel_RequestPlayerCard(&room->infoPanel, playerIndex, arg);
    }
}

void WiFiPlazaRoom_SetPlayerCardIcon(WiFiPlazaRoomWork *room, u32 icon) {
    WiFiPlazaInfoPanel_SetCardIcon(&room->infoPanel, &room->graphics, icon, HEAP_ID_119);
}

void WiFiPlazaRoom_RefreshPlayerCardTypes(WiFiPlazaRoomWork *room) {
    if (WiFiPlazaInfoPanel_IsPlayerCardShown(&room->infoPanel)) {
        WiFiPlazaPlayerCard_LoadTypeIcons(&room->infoPanel, &room->infoPanel.card, &room->graphics, HEAP_ID_119, WiFiPlazaWork_GetPlayer(room->lobby, WiFiPlazaInfoPanel_GetCardPlayer(&room->infoPanel)));
    }
}

void WiFiPlazaRoom_ShowOwnCard(WiFiPlazaRoomWork *room) {
    WiFiPlazaInfoPanel_RequestOwnCard(&room->infoPanel);
}

u32 WiFiPlazaRoom_GetPlayerCardPlayer(WiFiPlazaRoomWork *room) {
    return WiFiPlazaInfoPanel_GetCardPlayer(&room->infoPanel);
}

BOOL WiFiPlazaRoom_IsPlayerCardShown(WiFiPlazaRoomWork *room) {
    return WiFiPlazaInfoPanel_IsPlayerCardShown(&room->infoPanel);
}

BOOL WiFiPlazaRoom_IsPlayerCardIdle(WiFiPlazaRoomWork *room) {
    return WiFiPlazaInfoPanel_IsPlayerCardIdle(&room->infoPanel);
}

void WiFiPlazaRoom_ShowInstrumentPanel(WiFiPlazaRoomWork *room) {
    WiFiPlazaInfoPanel_RequestInstrument(&room->infoPanel);
}

BOOL WiFiPlazaRoom_IsMoverWobbling(WiFiPlazaRoomWork *room, u32 index) {
    return WiFiPlazaEvent_GetMoverState(room->event, index, 1);
}

void WiFiPlazaRoom_StartInfoPanel(WiFiPlazaRoomWork *room) {
    room->infoPanel.started = TRUE;
}

void WiFiPlazaRoom_SetPanelButtonDisabled(WiFiPlazaRoomWork *room, u16 disabled) {
    WiFiPlazaInfoPanel_SetButtonDisabled(&room->infoPanel, disabled);
}

void WiFiPlazaRoom_ResetPanelButton(WiFiPlazaRoomWork *room) {
    WiFiPlazaPanelButton_ResetTimer(&room->infoPanel.button);
}

BOOL WiFiPlazaRoom_TakePanelButtonPress(WiFiPlazaRoomWork *room) {
    BOOL pressed = room->panelButtonPressed;
    room->panelButtonPressed = FALSE;
    return pressed;
}

void WiFiPlazaRoom_StartInstrument(WiFiPlazaRoomWork *room, u32 playerIndex) {
    u32 instrument;
    GF_ASSERT(playerIndex < WIFI_PLAZA_MAX_PLAYERS);
    instrument = WiFiPlazaPlayer_GetTapToy(WiFiPlazaWork_GetPlayer(room->lobby, playerIndex));
    WiFiPlazaInstrument_Start(room->instruments, playerIndex, instrument);
    if (playerIndex == WiFiPlazaWork_GetOwnSlot(room->lobby)) {
        WiFiPlazaWork_SendTapToyPlayed(room->lobby, instrument);
    }
}

BOOL WiFiPlazaRoom_IsInstrumentFinished(WiFiPlazaRoomWork *room, u32 playerIndex) {
    GF_ASSERT(playerIndex < WIFI_PLAZA_MAX_PLAYERS);
    return WiFiPlazaInstrument_IsFinished(room->instruments, playerIndex);
}

static void WiFiPlazaRoom_VBlank(void *data) {
    WiFiPlazaRoomWork *room = data;
    WiFiPlazaModels_VBlank(room->models);
    WiFiPlazaObj_ClearPendingFree(room->objManager);
    WiFiPlazaRoom_GraphicsVBlank(&room->graphics);
}

static void WiFiPlazaRoom_InitGraphics(WiFiPlazaRoomGraphics *graphics, SaveData *save, enum HeapID heapID) {
    s32 i;
    s32 j;
    u8 frame;

    G2_BlendNone();
    G2S_BlendNone();
    GF_CreateVramTransferManager(32, heapID);
    GfGfx_SetBanks(&sWiFiPlazaRoomBanks);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    BG_SetMaskColor(GF_BG_LYR_MAIN_0, 0);
    SetBothScreensModesAndDisable(&sWiFiPlazaRoomGraphicsModes);
    graphics->bgConfig = BgConfig_Alloc(heapID);

    for (i = 0; i < 4; i++) {
        InitBgFromTemplate(graphics->bgConfig, sWiFiPlazaRoomBgIds[i], &sWiFiPlazaRoomBgTemplates[i], GF_BG_TYPE_TEXT);
        BG_ClearCharDataRange(sWiFiPlazaRoomBgIds[i], 32, 0, heapID);
        BgClearTilemapBufferAndCommit(graphics->bgConfig, sWiFiPlazaRoomBgIds[i]);
    }

    frame = Options_GetFrame(Save_PlayerData_GetOptionsAddr(save));
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_5_OFFSET, heapID);
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_4_OFFSET, heapID);
    LoadUserFrameGfx1(graphics->bgConfig, GF_BG_LYR_MAIN_1, 0x55, 3, 0, heapID);
    LoadUserFrameGfx2(graphics->bgConfig, GF_BG_LYR_MAIN_1, 1, 1, frame, heapID);
    LoadMapSignpostFrameAndGraphic(graphics->bgConfig, GF_BG_LYR_MAIN_1, 0x1F, 2, 3, 0, heapID);
    GfGfxLoader_GXLoadPal(NARC_a_2_0_7, 0x5A, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_2_OFFSET, 0x20, heapID);
    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 0x7E, 0, 0x1F, 0, 0x7E, 0, 0x1F, heapID);
    ObjCharTransfer_InitEx(&sWiFiPlazaRoomCharTransfer, GX_OBJVRAMMODE_CHAR_1D_32K, GX_OBJVRAMMODE_CHAR_1D_64K);
    ObjPlttTransfer_Init(24, heapID);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
    G2dRenderer_SetObjCharTransferReservedRegion(NNS_G2D_VRAM_TYPE_2DMAIN, GX_OBJVRAMMODE_CHAR_1D_32K);
    G2dRenderer_SetPlttTransferReservedRegion(NNS_G2D_VRAM_TYPE_2DMAIN);
    WirelessStatusIcon_Create();
    graphics->spriteList = G2dRenderer_Init(24, &graphics->renderer, heapID);
    G2dRenderer_SetSubSurfaceCoords(&graphics->renderer, 0, FX32_CONST(256));
    for (j = 0; j < 4; j++) {
        graphics->resManagers[j] = Create2DGfxResObjMan(24, (GfGfxResType)j, heapID);
    }
    graphics->cellTransfer = CreateCellTransferStateManager(24, heapID);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    graphics->vramManager = GF_3DVramMan_Create(heapID, GF_3D_TEXALLOC_LNK, 2, GF_3D_PLTTALLOC_LNK, 4, WiFiPlazaRoom_Setup3D);
}

static void WiFiPlazaRoom_DrawSprites(WiFiPlazaRoomGraphics *graphics) {
    SpriteList_RenderAndAnimateSprites(graphics->spriteList);
    thunk_UpdateCellTransferStateManager();
}

static void WiFiPlazaRoom_FreeGraphics(WiFiPlazaRoomGraphics *graphics) {
    int i;
    int j;
    const u32 *bgIds;

    GF_DestroyVramTransferManager();
    bgIds = sWiFiPlazaRoomBgIds;
    for (i = 0; i < 4; i++, bgIds++) {
        FreeBgTilemapBuffer(graphics->bgConfig, *bgIds);
    }
    Heap_Free(graphics->bgConfig);
    DestroyCellTransferStateManager(graphics->cellTransfer);
    graphics->cellTransfer = NULL;
    for (j = 0; j < 4; j++) {
        Destroy2DGfxResObjMan(graphics->resManagers[j]);
    }
    SpriteList_Delete(graphics->spriteList);
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    OamManager_Free();
    GF_3DVramMan_Delete(graphics->vramManager);
}

static void WiFiPlazaRoom_GraphicsVBlank(WiFiPlazaRoomGraphics *graphics) {
    DoScheduledBgGpuUpdates(graphics->bgConfig);
    OamManager_ApplyAndResetBuffers();
    GF_RunVramTransferTasks();
}

static void WiFiPlazaRoom_Setup3D(void) {
    VecFx16 vec;
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    G2_SetBG0Priority(1);
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(TRUE);
    G3X_AlphaTest(FALSE, 0);
    G3X_AlphaBlend(TRUE);
    G3X_EdgeMarking(TRUE);
    G3X_SetEdgeColorTable(sWiFiPlazaRoomEdgeColors);
    G3X_SetFog(FALSE, GX_FOGBLEND_COLOR_ALPHA, GX_FOGSLOPE_0x8000, 0);
    G3X_SetClearColor(GX_RGB(26, 26, 26), 0, GF_GX_CLEARCOLORDEPTH_MAX, 63, FALSE);
    G3_ViewPort(0, 0, 255, 191);
    NNS_G3dGlbLightVector(GX_LIGHTID_0, -2043, -3548, 110);

    vec.x = 0;
    vec.y = 0;
    vec.z = FX16_ONE;
    VEC_Fx16Normalize(&vec, &vec);
    NNS_G3dGlbLightVector(GX_LIGHTID_1, vec.x, vec.y, vec.z);
    vec.x = 0;
    vec.y = 0;
    vec.z = FX16_ONE;
    VEC_Fx16Normalize(&vec, &vec);
    NNS_G3dGlbLightVector(GX_LIGHTID_2, vec.x, vec.y, vec.z);
    NNS_G3dGlbLightColor(GX_LIGHTID_2, GX_RGB(31, 31, 31));
    vec.x = 0;
    vec.y = 0;
    vec.z = FX16_ONE;
    VEC_Fx16Normalize(&vec, &vec);
    NNS_G3dGlbLightVector(GX_LIGHTID_3, vec.x, vec.y, vec.z);
    NNS_G3dGlbLightColor(GX_LIGHTID_3, GX_RGB(31, 31, 31));
}

static void WiFiPlazaRoom_Update(WiFiPlazaRoomWork *room) {
    u32 error;
    WiFiPlazaObj_UpdateObjsAndLight(room->objManager);
    error = room->error;
    if (error == 0 && !room->plazaClosing) {
        WiFiPlazaPlayerState_Update(room->playerStates);
    }
    WiFiPlazaModels_Update(room->models);
    error = room->error;
    if (error == 0 && !room->plazaClosing) {
        WiFiPlazaObj_UpdateManager(room->objManager);
        WiFiPlazaPlayerState_LateUpdate(room->playerStates);
        WiFiPlazaEvent_Update(room->event);
    }
    WiFiPlazaRoom_UpdateMatchSigns(room);
    if (!room->fading) {
        u32 paused;
        error = room->error;
        if (error == 1 || room->plazaClosing == TRUE || room->finished == TRUE) {
            paused = TRUE;
        } else {
            paused = FALSE;
        }
        WiFiPlazaInfoPanel_Update(&room->infoPanel, room, paused, HEAP_ID_119);
    }
    WiFiPlazaInstrument_Update(room->instruments);
}

static void WiFiPlazaRoom_Draw(WiFiPlazaRoomWork *room) {
    Thunk_G3X_Reset();
    WiFiPlazaCamera_Update(room->camera);
    WiFiPlazaModels_Draw(room->models);
    WiFiPlazaObj_DrawAvatars(room->objManager);
    WiFiPlazaInstrument_Draw(room->instruments);
    RequestSwap3DBuffers(GX_SORTMODE_AUTO, GX_BUFFERMODE_Z);
    WiFiPlazaRoom_DrawSprites(&room->graphics);
}

// The signs of the three Pokemon match ups
static void WiFiPlazaRoom_UpdateMatchSigns(WiFiPlazaRoomWork *room) {
    int i;
    u32 state;
    u32 recruiting;
    u32 stop = WiFiPlazaWork_GetEventScheduleMode5(room->lobby);
    for (i = 0; i < 3; i++) {
        state = WiFiPlazaLobbyClient_IsMatchActive(i);
        if (state == TRUE) {
            if (!WiFiPlazaLobbyClient_IsMatchOpen(i)) {
                recruiting = TRUE;
            } else {
                recruiting = FALSE;
            }
        } else {
            recruiting = FALSE;
        }
        WiFiPlazaModels_UpdateMatchSign(room->models, i, WiFiPlazaLobbyClient_GetMatchPlayerCount(i), state, recruiting, stop);
    }
}

static void WiFiPlazaMsgWindow_Init(WiFiPlazaMsgWindow *window, WiFiPlazaRoomGraphics *graphics, SaveData *save, enum HeapID heapID) {
    AddWindowParameterized(graphics->bgConfig, &window->window, GF_BG_LYR_MAIN_1, 2, 19, 27, 4, 4, 0x5E);
    FillWindowPixelBuffer(&window->window, 15);
    window->string = String_New(0x180, heapID);
    window->textSpeed = Options_GetTextFrameDelay(Save_PlayerData_GetOptionsAddr(save));
}

static void WiFiPlazaMsgWindow_Free(WiFiPlazaMsgWindow *window) {
    if (TextPrinterCheckActive(window->printerId)) {
        RemoveTextPrinter(window->printerId);
    }
    WiFiPlazaMsgWindow_DeleteWaitingIcon(window);
    String_Delete(window->string);
    RemoveWindow(&window->window);
}

static void WiFiPlazaMsgWindow_Print(WiFiPlazaMsgWindow *window, String *string) {
    if (TextPrinterCheckActive(window->printerId)) {
        RemoveTextPrinter(window->printerId);
    }
    FillWindowPixelBuffer(&window->window, 15);
    String_Copy(window->string, string);
    window->printerId = AddTextPrinterParameterizedWithColor(&window->window, 1, window->string, 0, 0, window->textSpeed, MAKE_TEXT_COLOR(1, 2, 15), NULL);
    DrawFrameAndWindow2(&window->window, TRUE, 1, 1);
}

static void WiFiPlazaMsgWindow_PrintInstant(WiFiPlazaMsgWindow *window, String *string) {
    if (TextPrinterCheckActive(window->printerId)) {
        RemoveTextPrinter(window->printerId);
    }
    FillWindowPixelBuffer(&window->window, 15);
    String_Copy(window->string, string);
    AddTextPrinterParameterizedWithColor(&window->window, 1, window->string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 15), NULL);
    DrawFrameAndWindow2(&window->window, TRUE, 1, 1);
    ScheduleWindowCopyToVram(&window->window);
}

static void WiFiPlazaMsgWindow_ShowWaitingIcon(WiFiPlazaMsgWindow *window) {
    GF_ASSERT(window->waitingIcon == NULL);
    window->waitingIcon = WaitingIcon_New(&window->window, 1);
}

static void WiFiPlazaMsgWindow_HideWaitingIcon(WiFiPlazaMsgWindow *window) {
    WaitingIcon *icon = window->waitingIcon;
    if (icon != NULL) {
        WaitingIcon_Delete(icon);
        window->waitingIcon = NULL;
    }
}

static void WiFiPlazaMsgWindow_DeleteWaitingIcon(WiFiPlazaMsgWindow *window) {
    WaitingIcon *icon = window->waitingIcon;
    if (icon != NULL) {
        WaitingIcon_DeleteWithoutRestore(icon);
        window->waitingIcon = NULL;
    }
}

static BOOL WiFiPlazaMsgWindow_IsWaitingIconShown(WiFiPlazaMsgWindow *window) {
    return window->waitingIcon != NULL;
}

static BOOL WiFiPlazaMsgWindow_IsPrintFinished(WiFiPlazaMsgWindow *window) {
    if (!TextPrinterCheckActive(window->printerId)) {
        return TRUE;
    }
    return FALSE;
}

static void WiFiPlazaMsgWindow_Close(WiFiPlazaMsgWindow *window) {
    if (TextPrinterCheckActive(window->printerId)) {
        RemoveTextPrinter(window->printerId);
    }
    WiFiPlazaMsgWindow_DeleteWaitingIcon(window);
    ClearFrameAndWindow2(&window->window, TRUE);
    ClearWindowTilemapAndScheduleTransfer(&window->window);
}

static void WiFiPlazaSignWindow_Init(WiFiPlazaMsgWindow *window, WiFiPlazaRoomGraphics *graphics, SaveData *save, enum HeapID heapID) {
    WiFiPlazaMsgWindow_Init(window, graphics, save, heapID);
    SetWindowPaletteNum(&window->window, 2);
}

static void WiFiPlazaSignWindow_Free(WiFiPlazaMsgWindow *window) {
    WiFiPlazaMsgWindow_Free(window);
}

static void WiFiPlazaSignWindow_Print(WiFiPlazaMsgWindow *window, String *string) {
    if (TextPrinterCheckActive(window->printerId)) {
        RemoveTextPrinter(window->printerId);
    }
    FillWindowPixelBuffer(&window->window, 15);
    String_Copy(window->string, string);
    window->printerId = AddTextPrinterParameterized(&window->window, 1, window->string, 0, 0, window->textSpeed, NULL);
    DrawFrameAndWindow3(&window->window, TRUE, 0x1F, 2, 3);
}

static void WiFiPlazaListMenu_Init(WiFiPlazaListMenu *menu, WiFiPlazaRoomGraphics *graphics, enum HeapID heapID) {
    SpriteResourcesHeader header;
    SimpleSpriteTemplate template;
    int i;
    NARC *narc = NARC_New(NARC_a_0_6_0, heapID);

    menu->arrowResources[GF_GFX_RES_TYPE_CHAR] = AddCharResObjFromOpenNarc(graphics->resManagers[GF_GFX_RES_TYPE_CHAR], narc, 4, FALSE, 5000, NNS_G2D_VRAM_TYPE_2DMAIN, heapID);
    menu->arrowResources[GF_GFX_RES_TYPE_PLTT] = AddPlttResObjFromOpenNarc(graphics->resManagers[GF_GFX_RES_TYPE_PLTT], narc, 10, FALSE, 5000, NNS_G2D_VRAM_TYPE_2DMAIN, 1, heapID);
    menu->arrowResources[GF_GFX_RES_TYPE_CELL] = AddCellOrAnimResObjFromOpenNarc(graphics->resManagers[GF_GFX_RES_TYPE_CELL], narc, 5, FALSE, 5000, GF_GFX_RES_TYPE_CELL, heapID);
    menu->arrowResources[GF_GFX_RES_TYPE_ANIM] = AddCellOrAnimResObjFromOpenNarc(graphics->resManagers[GF_GFX_RES_TYPE_ANIM], narc, 6, FALSE, 5000, GF_GFX_RES_TYPE_ANIM, heapID);
    NARC_Delete(narc);
    SpriteTransfer_CreateCharTransferTask_AllocAtEnd(menu->arrowResources[GF_GFX_RES_TYPE_CHAR]);
    SpriteTransfer_CreatePlttTransferTask(menu->arrowResources[GF_GFX_RES_TYPE_PLTT]);
    CreateSpriteResourcesHeader(&header, 5000, 5000, 5000, 5000, -1, -1, FALSE, 0, graphics->resManagers[GF_GFX_RES_TYPE_CHAR], graphics->resManagers[GF_GFX_RES_TYPE_PLTT], graphics->resManagers[GF_GFX_RES_TYPE_CELL], graphics->resManagers[GF_GFX_RES_TYPE_ANIM], NULL, NULL);
    template.spriteList = graphics->spriteList;
    template.header = &header;
    template.priority = 0;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.heapID = heapID;
    template.position.x = FX32_CONST(192);
    for (i = 0; i < 2; i++) {
        template.position.y = sWiFiPlazaListArrowY[i] << FX32_SHIFT;
        menu->arrows[i] = Sprite_Create(&template);
        Sprite_SetAnimCtrlSeq(menu->arrows[i], i);
        Sprite_SetAnimActiveFlag(menu->arrows[i], TRUE);
        Sprite_SetDrawFlag(menu->arrows[i], FALSE);
    }
    menu->showArrows = FALSE;
}

static void WiFiPlazaListMenu_Free(WiFiPlazaListMenu *menu, WiFiPlazaRoomGraphics *graphics) {
    int i;
    if (menu->items) {
        WiFiPlazaListMenu_DeleteItems(menu);
    }
    if (menu->listMenu) {
        WiFiPlazaListMenu_Close(menu, NULL, NULL);
    }
    for (i = 0; i < 2; i++) {
        Sprite_Delete(menu->arrows[i]);
        menu->arrows[i] = NULL;
    }
    SpriteTransfer_DeleteCharTransferTask(menu->arrowResources[GF_GFX_RES_TYPE_CHAR]);
    SpriteTransfer_DeletePlttTransferTask(menu->arrowResources[GF_GFX_RES_TYPE_PLTT]);
    for (i = 0; i < 4; i++) {
        DestroySingle2DGfxResObj(graphics->resManagers[i], menu->arrowResources[i]);
    }
}

static void WiFiPlazaListMenu_CreateItems(WiFiPlazaListMenu *menu, u32 count, enum HeapID heapID, int value) {
    u32 i;
    GF_ASSERT(menu->items == NULL);
    menu->items = ListMenuItems_New(count, heapID);
    menu->itemCount = count;
    for (i = 0; i < count; i++) {
        menu->items[i].value = value;
    }
}

static void WiFiPlazaListMenu_DeleteItems(WiFiPlazaListMenu *menu) {
    ListMenuItem *items = menu->items;
    if (items != NULL) {
        ListMenuItems_Delete(items);
        menu->items = NULL;
        menu->itemCount = 0;
    }
}

static void WiFiPlazaListMenu_AddItem(WiFiPlazaListMenu *menu, String *text, int value) {
    ListMenuItems_AddItem(menu->items, text, value);
}

static ListMenuItem *WiFiPlazaListMenu_GetItems(WiFiPlazaListMenu *menu) {
    return menu->items;
}

static BOOL WiFiPlazaListMenu_HasItemValue(WiFiPlazaListMenu *menu, int value) {
    int i;
    ListMenuItem *item;
    i = 0;
    if (i < menu->itemCount) {
        item = menu->items;
        do {
            if (value == item->value) {
                return TRUE;
            }
            i++;
            item++;
        } while (i < *(volatile u16 *)&menu->itemCount);
    }
    return FALSE;
}

static void WiFiPlazaListMenu_Open(WiFiPlazaListMenu *menu, const ListMenuTemplate *template, WiFiPlazaRoomGraphics *graphics, u16 cursorPos, u16 itemsAbove, enum HeapID heapID, u8 x, u8 y, u8 width) {
    GF_ASSERT(menu->listMenu == NULL);
    GF_ASSERT(template->maxShowed * 2 < 18);
    menu->template = *template;
    menu->template.window = &menu->window;
    menu->totalItems = template->totalItems;
    menu->template.moveCursorFunc = WiFiPlazaListMenu_OnCursorMove;
    AddWindowParameterized(graphics->bgConfig, &menu->window, GF_BG_LYR_MAIN_1, x, y, width, template->maxShowed * 2, 5, 0xCA);
    FillWindowPixelBuffer(&menu->window, 15);
    DrawFrameAndWindow1(&menu->window, TRUE, 0x55, 3);
    menu->listMenu = ListMenuInit(&menu->template, cursorPos, itemsAbove, (enum HeapID)(u8)heapID);
    ScheduleWindowCopyToVram(&menu->window);
}

static s32 WiFiPlazaListMenu_ProcessInput(WiFiPlazaListMenu *menu) {
    s32 input;
    if (menu->listMenu == NULL) {
        return LIST_CANCEL;
    }
    input = ListMenu_ProcessInput(menu->listMenu);
    switch (input) {
    case LIST_CANCEL:
    case LIST_NOTHING_CHOSEN:
        WiFiPlazaListMenu_UpdateArrows(menu);
        break;
    default:
        PlaySE(SEQ_SE_DP_SELECT);
        break;
    }
    return input;
}

static void WiFiPlazaListMenu_Close(WiFiPlazaListMenu *menu, u16 *cursorPos, u16 *itemsAbove) {
    int i;
    if (menu->listMenu != NULL) {
        DestroyListMenu(menu->listMenu, cursorPos, itemsAbove);
        menu->listMenu = NULL;
        EraseFrameAndWindow1(&menu->window, TRUE);
        ClearWindowTilemapAndScheduleTransfer(&menu->window);
        RemoveWindow(&menu->window);
        menu->showArrows = FALSE;
        for (i = 0; i < 2; i++) {
            Sprite_SetDrawFlag(menu->arrows[i], FALSE);
        }
    }
}

static void WiFiPlazaListMenu_OnCursorMove(ListMenu *listMenu, s32 index, u8 onInit) {
    if (!onInit) {
        PlaySE(SEQ_SE_DP_SELECT);
    }
}

static void WiFiPlazaListMenu_SetShowArrows(WiFiPlazaListMenu *menu, BOOL show) {
    menu->showArrows = show;
}

static void WiFiPlazaListMenu_UpdateArrows(WiFiPlazaListMenu *menu) {
    u16 scroll;
    if (!menu->showArrows) {
        Sprite_SetDrawFlag(menu->arrows[0], FALSE);
        Sprite_SetDrawFlag(menu->arrows[1], FALSE);
        return;
    }
    ListMenuGetScrollAndRow(menu->listMenu, &scroll, NULL);
    if (scroll == 0) {
        Sprite_SetDrawFlag(menu->arrows[0], FALSE);
    } else {
        Sprite_SetDrawFlag(menu->arrows[0], TRUE);
    }
    if (scroll >= menu->totalItems - 7) {
        Sprite_SetDrawFlag(menu->arrows[1], FALSE);
    } else {
        Sprite_SetDrawFlag(menu->arrows[1], TRUE);
    }
}

static void WiFiPlazaTextWindow_Init(Window *window, WiFiPlazaRoomGraphics *graphics, enum HeapID heapID) {
}

static void WiFiPlazaTextWindow_Free(Window *window) {
    WiFiPlazaTextWindow_Close(window);
}

static void WiFiPlazaTextWindow_Open(Window *window, WiFiPlazaRoomGraphics *graphics, enum HeapID heapID, u8 x, u8 y, u8 width, u8 height) {
    AddWindowParameterized(graphics->bgConfig, window, GF_BG_LYR_MAIN_1, x, y, width, height, 5, 0xCA);
    DrawFrameAndWindow1(window, TRUE, 0x55, 3);
    FillWindowPixelBuffer(window, 15);
    ScheduleWindowCopyToVram(window);
}

static void WiFiPlazaTextWindow_Close(Window *window) {
    if (WindowIsInUse(window) == TRUE) {
        EraseFrameAndWindow1(window, TRUE);
        ClearWindowTilemapAndScheduleTransfer(window);
        RemoveWindow(window);
    }
}

static void WiFiPlazaTextWindow_Print(Window *window, String *string, u32 x, u32 y) {
    AddTextPrinterParameterizedWithColor(window, 0, string, x, y, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 15), NULL);
    ScheduleWindowCopyToVram(window);
}

static void WiFiPlazaTextWindow_FillRect(Window *window, u16 x, u16 y, u16 width, u16 height) {
    FillWindowPixelRect(window, 15, x, y, width, height);
}

static void WiFiPlazaYesNoMenu_Init(WiFiPlazaYesNoMenu *menu, WiFiPlazaRoomMsg *msg, enum HeapID heapID) {
    String *text;
    GF_ASSERT(menu->items == NULL);
    menu->items = ListMenuItems_New(2, heapID);
    text = WiFiPlazaRoomMsg_GetString(msg, WIFI_PLAZA_MSG_BANK_PLAZA, msg_0777_00067);
    ListMenuItems_AddItem(menu->items, text, 0);
    text = WiFiPlazaRoomMsg_GetString(msg, WIFI_PLAZA_MSG_BANK_PLAZA, msg_0777_00066);
    ListMenuItems_AddItem(menu->items, text, 1);
    menu->template = sWiFiPlazaYesNoTemplate;
    menu->template.totalItems = 2;
    menu->template.items = menu->items;
}

static void WiFiPlazaYesNoMenu_Free(WiFiPlazaYesNoMenu *menu) {
    ListMenuItem *items = menu->items;
    if (items != NULL) {
        ListMenuItems_Delete(items);
        menu->items = NULL;
    }
}

static void WiFiPlazaErrorWindow_Init(Window *window, WiFiPlazaRoomGraphics *graphics, enum HeapID heapID) {
    AddWindowParameterized(graphics->bgConfig, window, GF_BG_LYR_MAIN_1, 4, 4, 23, 16, 5, 0x5E);
    FillWindowPixelBuffer(window, 15);
}

static void WiFiPlazaErrorWindow_Free(Window *window) {
    RemoveWindow(window);
}

static void WiFiPlazaErrorWindow_Print(Window *window, String *string) {
    AddTextPrinterParameterizedWithColor(window, 0, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 15), NULL);
    DrawFrameAndWindow1(window, TRUE, 0x55, 3);
    ScheduleWindowCopyToVram(window);
}

static void WiFiPlazaErrorWindow_PrintCommError(Window *window, WiFiPlazaRoomMsg *msg) {
    u32 *error = CommState_GetWifiError();
    u32 msgId = WiFiPlaza_GetErrorMessageClass(error[0], error[1]);
    WiFiPlazaRoomMsg_BufferInt(msg, error[0], 5, 0, 2);
    WiFiPlazaErrorWindow_Print(window, WiFiPlazaRoomMsg_GetString(msg, WIFI_PLAZA_MSG_BANK_CONNECTION, msgId));
}

static void WiFiPlazaErrorWindow_PrintLobbyError(Window *window, WiFiPlazaRoomMsg *msg, u32 error) {
    u32 code = WiFiPlazaLobbyClient_ToErrorCode(error);
    WiFiPlazaRoomMsg_BufferInt(msg, code, 5, 0, 2);
    WiFiPlazaErrorWindow_Print(window, WiFiPlazaRoomMsg_GetString(msg, WIFI_PLAZA_MSG_BANK_CONNECTION, msg_0800_00032));
}

static void WiFiPlazaErrorWindow_PrintDisconnected(Window *window, WiFiPlazaRoomMsg *msg, u32 unused) {
    WiFiPlazaErrorWindow_Print(window, WiFiPlazaRoomMsg_GetString(msg, WIFI_PLAZA_MSG_BANK_CONNECTION, msg_0800_00014));
}

static void WiFiPlazaRoomMsg_Init(WiFiPlazaRoomMsg *msg, enum HeapID heapID) {
    int i;
    msg->format = MessageFormat_New_Custom(8, 64, heapID);
    for (i = 0; i < 4; i++) {
        msg->msgData[i] = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, sWiFiPlazaRoomMsgBanks[i], heapID);
    }
    msg->formatted = String_New(0x1E0, heapID);
    msg->raw = String_New(0x1E0, heapID);
}

static void WiFiPlazaRoomMsg_Free(WiFiPlazaRoomMsg *msg) {
    int i;
    MessageFormat_Delete(msg->format);
    for (i = 0; i < 4; i++) {
        DestroyMsgData(msg->msgData[i]);
    }
    String_Delete(msg->formatted);
    String_Delete(msg->raw);
}

static String *WiFiPlazaRoomMsg_GetString(WiFiPlazaRoomMsg *msg, int bank, int msgId) {
    ReadMsgDataIntoString(msg->msgData[bank], msgId, msg->raw);
    StringExpandPlaceholders(msg->format, msg->formatted, msg->raw);
    return msg->formatted;
}

static void WiFiPlazaRoomMsg_BufferInt(WiFiPlazaRoomMsg *msg, int value, int digits, int field, int style) {
    BufferIntegerAsString(msg->format, field, value, digits, (PrintingMode)style, TRUE);
}

static void WiFiPlazaRoomMsg_BufferPlayerName(WiFiPlazaRoomMsg *msg, PlayerProfile *profile, u32 field) {
    BufferPlayersName(msg->format, field, profile);
}

static void WiFiPlazaRoomMsg_BufferActivityName(WiFiPlazaRoomMsg *msg, u32 activity, u32 field) {
    BufferWiFiPlazaActivityName(msg->format, field, activity);
}

static void WiFiPlazaRoomMsg_BufferEventName(WiFiPlazaRoomMsg *msg, u32 event, u32 field) {
    BufferWiFiPlazaEventName(msg->format, field, event);
}

static void WiFiPlazaRoomMsg_BufferInstrumentName(WiFiPlazaRoomMsg *msg, u32 instrument, u32 field) {
    BufferWiFiPlazaInstrumentName(msg->format, field, instrument);
}

static void WiFiPlazaRoomMsg_BufferCountryName(WiFiPlazaRoomMsg *msg, u32 country, u32 field) {
    BufferCountryName(msg->format, field, country);
}

static void WiFiPlazaRoomMsg_BufferCityName(WiFiPlazaRoomMsg *msg, u32 country, u32 city, u32 field) {
    BufferCityName(msg->format, field, country, city);
}

static void WiFiPlazaRoomMsg_BufferECWord(WiFiPlazaRoomMsg *msg, u32 field, u16 word) {
    BufferECWord(msg->format, field, word);
}

static void WiFiPlazaRoomMsg_ResetBuffers(WiFiPlazaRoomMsg *msg) {
    MessageFormat_ResetBuffers(msg->format);
}

static void WiFiPlazaRoom_SetPanelButtonPressed(WiFiPlazaRoomWork *room) {
    room->panelButtonPressed = TRUE;
}

// The touch screen of the plaza room: the own trainer card (with a button that plays the own Tap Toy), the
// card of another player (name, ID, country, easy chat message or Pokemon, Tap Toy icon, avatar) and the Tap Toy
// panel. Page switches fade the sub screen out and in.

static const u8 sWiFiPlazaPanelButtonScreenBases[4] = { 0, 1, 0, 0 };

static const WindowTemplate sWiFiPlazaPanelButtonWindowTemplate = {
    .bgId = GF_BG_LYR_SUB_1,
    .left = 1,
    .top = 0,
    .width = 24,
    .height = 3,
    .palette = 5,
    .baseTile = 0x1D0,
};

static const u16 sWiFiPlazaCardTypeIconTileBases[2] = { 0x2E4, 0x2EC };

static const u16 sWiFiPlazaCardMonCellFiles[4] = { 2, 104, 51, 55 };

static const WiFiPlazaCardMonResources sWiFiPlazaCardMonResources[4] = {
    { 215, 0,   8 },
    { 209, 102, 2 },
    { 215, 49,  1 },
    { 215, 53,  1 },
};

static const WiFiPlazaCardMonInfo sWiFiPlazaCardSpeciesMonInfo[24] = {
    { 0, 0, 1,   -8, -6 },
    { 0, 6, 4,   -8, -6 },
    { 0, 1, 7,   -8, -6 },
    { 0, 2, 10,  -8, -6 },
    { 0, 6, 13,  -8, -6 },
    { 0, 5, 16,  -8, -6 },
    { 0, 3, 19,  -8, -6 },
    { 0, 4, 22,  -8, -6 },
    { 0, 0, 25,  -8, -6 },
    { 0, 7, 28,  -8, -6 },
    { 0, 4, 31,  -8, -6 },
    { 0, 1, 34,  -8, -6 },
    { 0, 5, 37,  -8, -6 },
    { 0, 5, 40,  -8, -6 },
    { 0, 2, 43,  -8, -6 },
    { 0, 3, 46,  -8, -6 },
    { 1, 0, 103, 0,  0  },
    { 1, 1, 106, 0,  0  },
    { 1, 0, 109, 0,  0  },
    { 1, 0, 118, 0,  0  },
    { 1, 1, 115, 0,  0  },
    { 1, 0, 112, 0,  0  },
    { 1, 1, 121, 0,  0  },
    { 1, 0, 124, 0,  0  },
};

static const WindowTemplate sWiFiPlazaCardWindowTemplates[5] = {
    {
     .bgId = GF_BG_LYR_SUB_2,
     .left = 8,
     .top = 2,
     .width = 16,
     .height = 4,
     .palette = 5,
     .baseTile = 0x140,
     },
    {
     .bgId = GF_BG_LYR_SUB_2,
     .left = 1,
     .top = 7,
     .width = 30,
     .height = 6,
     .palette = 5,
     .baseTile = 0x180,
     },
    {
     .bgId = GF_BG_LYR_SUB_2,
     .left = 1,
     .top = 14,
     .width = 19,
     .height = 4,
     .palette = 5,
     .baseTile = 0x234,
     },
    {
     .bgId = GF_BG_LYR_SUB_2,
     .left = 1,
     .top = 19,
     .width = 19,
     .height = 4,
     .palette = 5,
     .baseTile = 0x280,
     },
    {
     .bgId = GF_BG_LYR_SUB_2,
     .left = 0,
     .top = 14,
     .width = 22,
     .height = 8,
     .palette = 5,
     .baseTile = 0x234,
     },
};

static const WiFiPlazaCardAvatar sWiFiPlazaCardAvatars[18] = {
    { 0,  0,  33, 35 },
    { 97, 1,  38, 36 },
    { 3,  60, 38, 25 },
    { 5,  6,  44, 32 },
    { 11, 24, 38, 44 },
    { 31, 57, 40, 40 },
    { 50, 48, 44, 26 },
    { 51, 14, 44, 37 },
    { 62, 32, 29, 40 },
    { 70, 49, 42, 44 },
    { 6,  3,  39, 34 },
    { 7,  10, 40, 36 },
    { 13, 36, 38, 41 },
    { 14, 25, 36, 42 },
    { 35, 85, 38, 38 },
    { 37, 35, 38, 39 },
    { 42, 18, 38, 35 },
    { 63, 33, 40, 44 },
};

static const u16 sWiFiPlazaCardMonAnimFiles[4] = { 3, 105, 52, 56 };

static const VecFx32 sWiFiPlazaCardMonPositions[12] = {
    { FX32_CONST(32),  FX32_CONST(400), 0 },
    { FX32_CONST(56),  FX32_CONST(400), 0 },
    { FX32_CONST(80),  FX32_CONST(400), 0 },
    { FX32_CONST(104), FX32_CONST(400), 0 },
    { FX32_CONST(128), FX32_CONST(400), 0 },
    { FX32_CONST(152), FX32_CONST(400), 0 },
    { FX32_CONST(32),  FX32_CONST(432), 0 },
    { FX32_CONST(56),  FX32_CONST(432), 0 },
    { FX32_CONST(80),  FX32_CONST(432), 0 },
    { FX32_CONST(104), FX32_CONST(432), 0 },
    { FX32_CONST(128), FX32_CONST(432), 0 },
    { FX32_CONST(152), FX32_CONST(432), 0 },
};

static const WiFiPlazaCardMonInfo sWiFiPlazaCardPlayerMonInfo[2] = {
    { 2, 0, 50, -8, -6 },
    { 3, 0, 54, -8, -6 },
};

static const TouchscreenHitbox sWiFiPlazaPanelButtonHitbox[1] = {
    { .rect = { 32, 160, 40, 216 } },
};

static const s8 sWiFiPlazaPanelButtonScrollY[4] = { 0, 9, 6, 0 };

static const u8 sWiFiPlazaCardTypeIconTiles[2][16] = {
    { 228, 2, 229, 2, 230, 2, 231, 2, 232, 2, 233, 2, 234, 2, 235, 2 },
    { 236, 2, 237, 2, 238, 2, 239, 2, 240, 2, 241, 2, 242, 2, 243, 2 },
};

static void WiFiPlazaInfoPanel_Init(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomEntry *startParams, WiFiPlazaRoomGraphics *graphics, PlayerProfile *profile, enum HeapID heapID) {
    u32 gender = PlayerProfile_GetTrainerGender(profile);

    panel->narc = NARC_New(NARC_a_2_0_7, heapID);
    WiFiPlazaInfoPanel_LoadGraphics(panel, graphics, panel->narc, gender, heapID);
    WiFiPlazaPlayerCard_Init(&panel->card, graphics, panel->narc, heapID);
    WiFiPlazaPanelButton_Init(&panel->button, graphics, panel->narc, heapID);
    panel->request = WIFI_PLAZA_PANEL_PAGE_NONE;
    panel->page = WIFI_PLAZA_PANEL_PAGE_NONE;
    if (startParams->entryMode == WIFI_PLAZA_ENTRY_ARRIVAL) {
        panel->state = WIFI_PLAZA_PANEL_WAIT_START;
        BG_SetMaskColor(GF_BG_LYR_SUB_0, 0);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_OFF);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_OFF);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
    } else {
        panel->state = WIFI_PLAZA_PANEL_IDLE;
    }
}

static void WiFiPlazaInfoPanel_Free(WiFiPlazaInfoPanel *panel, WiFiPlazaMsgWindow *signWindow, WiFiPlazaRoomGraphics *graphics) {
    WiFiPlazaPanelButton_Free(&panel->button);
    WiFiPlazaPlayerCard_Free(&panel->card, signWindow, graphics);
    WiFiPlazaInfoPanel_FreeGraphics(panel, graphics);
    NARC_Delete(panel->narc);
}

typedef struct WiFiPlazaInstrumentToken {
    u32 type;
    u32 index;
} WiFiPlazaInstrumentToken;

#pragma opt_propagation off

static void WiFiPlazaInfoPanel_Update(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomWork *room, BOOL paused, enum HeapID heapID) {
    WiFiPlazaInstrumentToken started, own;
    WiFiPlazaWork *lobby;
    int offset;
    WiFiPlazaRoomGraphics *graphics;
    int special, hasMessage, isOwn, message, token;
    struct WiFiPlazaPlayer *myPlayer;
    int playerIndex;
    struct WiFiPlazaPlayer *player;

    graphics = &room->graphics;
    lobby = room->lobby;
    offset = offsetof(WiFiPlazaRoomWork, msg);
    switch (panel->state) {
    case WIFI_PLAZA_PANEL_WAIT_START:
        if (panel->started == TRUE) {
            panel->state++;
        }
        break;
    case WIFI_PLAZA_PANEL_FADE_OUT_START:
        BeginNormalPaletteFade(FADE_SUB_ONLY, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_WHITE, 4, 1, heapID);
        panel->state++;
        break;
    case WIFI_PLAZA_PANEL_SHOW_START_CARD:
        if (IsPaletteFadeFinished() == TRUE) {
            WiFiPlazaInfoPanel_ShowOwnCard(panel, graphics, &room->msg, heapID, WiFiPlazaWork_GetMyPlayer(lobby));
            panel->page = WIFI_PLAZA_PANEL_PAGE_START_CARD;
            GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
            GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_ON);
            GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_ON);
            GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
            panel->state++;
        }
        break;
    case WIFI_PLAZA_PANEL_FADE_IN_START:
        BeginNormalPaletteFade(FADE_SUB_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_WHITE, 6, 1, heapID);
        panel->state++;
        break;
    case WIFI_PLAZA_PANEL_WAIT_FADE_IN_START:
        if (IsPaletteFadeFinished() == TRUE) {
            panel->state++;
        }
        break;
    case WIFI_PLAZA_PANEL_IDLE:
        if (paused != TRUE) {
            switch (panel->page) {
            case WIFI_PLAZA_PANEL_PAGE_NONE:
            case WIFI_PLAZA_PANEL_PAGE_START_CARD:
                break;
            case WIFI_PLAZA_PANEL_PAGE_OWN_CARD:
                if (WiFiPlazaPanelButton_Update(&panel->button, graphics, panel->narc, heapID) == TRUE) {
                    WiFiPlazaRoom_SetPanelButtonPressed(room);
                }
                break;
            case WIFI_PLAZA_PANEL_PAGE_INSTRUMENT:
                if (panel->instrumentPlaying) {
                    if (WiFiPlazaEvent_GetMoverState(room->event, panel->instrumentIndex, panel->instrumentType) == 0) {
                        panel->instrumentPlaying = FALSE;
                        WiFiPlazaPanelButton_ResetTimer(&panel->button);
                    }
                }
                if (WiFiPlazaPanelButton_Update(&panel->button, graphics, panel->narc, heapID) == TRUE) {
                    WiFiPlazaWork_RequestGroupAction(lobby, WiFiPlazaWork_GetOwnSlot(lobby));
                    WiFiPlazaWork_SendGroupAction(lobby);
                    WiFiPlaza_SplitGroupPlace(WiFiPlazaWork_FindGroupPlace(lobby, WiFiPlazaWork_GetOwnSlot(lobby)), &started.index, &started.type);
                    panel->instrumentPlaying = TRUE;
                    panel->instrumentIndex = started.index;
                    panel->instrumentType = started.type;
                }
                break;
            case WIFI_PLAZA_PANEL_PAGE_PLAYER_CARD:
                WiFiPlazaPlayerCard_Update(&panel->card, (WiFiPlazaMsgWindow *)((u8 *)room + (offset + 0x3C)));
                offset += 0x3C;
                break;
            }
            if (panel->request) {
                panel->state++;
            }
        }
        break;
    case WIFI_PLAZA_PANEL_FADE_OUT:
        BeginNormalPaletteFade(FADE_SUB_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 3, 1, heapID);
        panel->state++;
        break;
    case WIFI_PLAZA_PANEL_HIDE_PAGE:
        if (IsPaletteFadeFinished() != TRUE) {
            break;
        }
        switch (panel->page) {
        case WIFI_PLAZA_PANEL_PAGE_NONE:
            break;
        case WIFI_PLAZA_PANEL_PAGE_OWN_CARD:
        case WIFI_PLAZA_PANEL_PAGE_INSTRUMENT:
        case WIFI_PLAZA_PANEL_PAGE_START_CARD:
            WiFiPlazaInfoPanel_HideButtonPage(panel, graphics);
            break;
        case WIFI_PLAZA_PANEL_PAGE_PLAYER_CARD:
            WiFiPlazaInfoPanel_HidePlayerCard(panel, &room->signWindow, graphics);
            break;
        }
        panel->state++;
        break;
    case WIFI_PLAZA_PANEL_SHOW_PAGE:
        switch (panel->request) {
        case WIFI_PLAZA_PANEL_PAGE_NONE:
            break;
        case WIFI_PLAZA_PANEL_PAGE_OWN_CARD:
        case WIFI_PLAZA_PANEL_PAGE_START_CARD:
            WiFiPlazaInfoPanel_ShowOwnCard(panel, graphics, &room->msg, heapID, WiFiPlazaWork_GetMyPlayer(lobby));
            break;
        case WIFI_PLAZA_PANEL_PAGE_PLAYER_CARD:
            myPlayer = WiFiPlazaWork_GetMyPlayer(lobby);
            playerIndex = panel->requestPlayer;
            if (playerIndex == WiFiPlazaWork_GetOwnSlot(lobby)) {
                player = WiFiPlazaWork_GetMyPlayer(lobby);
                isOwn = TRUE;
            } else {
                player = WiFiPlazaWork_GetPlayer(lobby, playerIndex);
                isOwn = FALSE;
            }
            special = WiFiPlazaWork_IsSpecialVisitor(lobby, panel->requestPlayer);
            if (panel->requestArg == TRUE) {
                hasMessage = WiFiPlazaWork_HasWordSet(lobby, panel->requestPlayer);
                message = (int)WiFiPlazaWork_GetWordSet(lobby, panel->requestPlayer);
                if (message == 0) {
                    hasMessage = FALSE;
                }
            } else {
                hasMessage = FALSE;
                message = 0;
            }
            WiFiPlazaInfoPanel_ShowPlayerCard(panel, &room->signWindow, graphics, (WiFiPlazaRoomMsg *)((u8 *)room + offset), isOwn, heapID, player, myPlayer, special, hasMessage, (u16 *)message, TRUE);
            break;
        case WIFI_PLAZA_PANEL_PAGE_INSTRUMENT:
            token = WiFiPlazaWork_FindGroupPlace(lobby, WiFiPlazaWork_GetOwnSlot(lobby));
            if (token == -1) {
                GF_ASSERT(FALSE);
                token = 0;
            }
            WiFiPlaza_SplitGroupPlace(token, &own.index, &own.type);
            WiFiPlazaInfoPanel_ShowInstrument(panel, graphics, heapID, own.type);
            break;
        }
        panel->request = WIFI_PLAZA_PANEL_PAGE_NONE;
        panel->state++;
        break;
    case WIFI_PLAZA_PANEL_FADE_IN:
        BeginNormalPaletteFade(FADE_SUB_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 3, 1, heapID);
        if (panel->page == WIFI_PLAZA_PANEL_PAGE_PLAYER_CARD) {
            WiFiPlazaPlayerCard_Update(&panel->card, &room->signWindow);
        }
        panel->state++;
        break;
    case WIFI_PLAZA_PANEL_WAIT_FADE_IN:
        if (IsPaletteFadeFinished() == TRUE) {
            panel->state = WIFI_PLAZA_PANEL_IDLE;
        }
        break;
    }
}

#pragma opt_propagation reset

static u8 WiFiPlazaInfoPanel_GetState(WiFiPlazaInfoPanel *panel) {
    return panel->state;
}

static void WiFiPlazaInfoPanel_RequestPlayerCard(WiFiPlazaInfoPanel *panel, u32 playerIndex, u32 showMessage) {
    panel->request = WIFI_PLAZA_PANEL_PAGE_PLAYER_CARD;
    panel->requestPlayer = playerIndex;
    panel->requestArg = showMessage;
}

static void WiFiPlazaInfoPanel_SetCardIcon(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics, u32 icon, enum HeapID heapID) {
    GF_ASSERT(icon < 27);
    GF_ASSERT(panel->page == WIFI_PLAZA_PANEL_PAGE_PLAYER_CARD);
    if (panel->page == WIFI_PLAZA_PANEL_PAGE_PLAYER_CARD) {
        WiFiPlazaPlayerCard_ChangeIcon(&panel->card, graphics, panel->narc, heapID, icon);
    }
}

static void WiFiPlazaInfoPanel_RequestOwnCard(WiFiPlazaInfoPanel *panel) {
    if (panel->page != WIFI_PLAZA_PANEL_PAGE_OWN_CARD) {
        panel->request = WIFI_PLAZA_PANEL_PAGE_OWN_CARD;
    }
}

static void WiFiPlazaInfoPanel_RequestInstrument(WiFiPlazaInfoPanel *panel) {
    if (panel->page != WIFI_PLAZA_PANEL_PAGE_INSTRUMENT) {
        panel->request = WIFI_PLAZA_PANEL_PAGE_INSTRUMENT;
    }
}

static u8 WiFiPlazaInfoPanel_GetCardPlayer(WiFiPlazaInfoPanel *panel) {
    return panel->requestPlayer;
}

static BOOL WiFiPlazaInfoPanel_IsPlayerCardShown(WiFiPlazaInfoPanel *panel) {
    if (panel->request == WIFI_PLAZA_PANEL_PAGE_PLAYER_CARD) {
        return TRUE;
    }
    if (panel->page == WIFI_PLAZA_PANEL_PAGE_PLAYER_CARD) {
        return TRUE;
    }
    return FALSE;
}

static BOOL WiFiPlazaInfoPanel_IsPlayerCardIdle(WiFiPlazaInfoPanel *panel) {
    return panel->request == WIFI_PLAZA_PANEL_PAGE_NONE && panel->page == WIFI_PLAZA_PANEL_PAGE_PLAYER_CARD;
}

static BOOL WiFiPlazaInfoPanel_CardShowsMessage(WiFiPlazaInfoPanel *panel) {
    return WiFiPlazaPlayerCard_ShowsMessage(&panel->card);
}

static BOOL WiFiPlazaInfoPanel_HasRequest(WiFiPlazaInfoPanel *panel) {
    return panel->request != WIFI_PLAZA_PANEL_PAGE_NONE;
}

static void WiFiPlazaInfoPanel_ShowPlayerCard(WiFiPlazaInfoPanel *panel, WiFiPlazaMsgWindow *signWindow, WiFiPlazaRoomGraphics *graphics, WiFiPlazaRoomMsg *msg, BOOL isOwn, enum HeapID heapID, struct WiFiPlazaPlayer *player, struct WiFiPlazaPlayer *myPlayer, int special, BOOL hasMessage, u16 *message, BOOL showIcon) {
    if (panel->page == WIFI_PLAZA_PANEL_PAGE_PLAYER_CARD) {
        WiFiPlazaInfoPanel_HidePlayerCard(panel, signWindow, graphics);
    }
    WiFiPlazaPlayerCard_Show(panel, signWindow, &panel->card, graphics, msg, isOwn, panel->narc, heapID, player, myPlayer, special, hasMessage, message, showIcon);
    panel->page = WIFI_PLAZA_PANEL_PAGE_PLAYER_CARD;
}

static void WiFiPlazaInfoPanel_HidePlayerCard(WiFiPlazaInfoPanel *panel, WiFiPlazaMsgWindow *signWindow, WiFiPlazaRoomGraphics *graphics) {
    WiFiPlazaPlayerCard_Clear(&panel->card, signWindow, graphics);
    panel->page = WIFI_PLAZA_PANEL_PAGE_NONE;
}

static void WiFiPlazaInfoPanel_ShowOwnCard(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics, WiFiPlazaRoomMsg *msg, enum HeapID heapID, struct WiFiPlazaPlayer *player) {
    if (panel->page == WIFI_PLAZA_PANEL_PAGE_OWN_CARD || panel->page == WIFI_PLAZA_PANEL_PAGE_INSTRUMENT || panel->page == WIFI_PLAZA_PANEL_PAGE_START_CARD) {
        WiFiPlazaInfoPanel_HideButtonPage(panel, graphics);
    }
    WiFiPlazaPanelButton_ShowOwnCard(&panel->button, graphics, msg, player, panel->narc, heapID);
    panel->page = WIFI_PLAZA_PANEL_PAGE_OWN_CARD;
}

static void WiFiPlazaInfoPanel_ShowInstrument(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics, enum HeapID heapID, u32 type) {
    if (panel->page == WIFI_PLAZA_PANEL_PAGE_INSTRUMENT) {
        WiFiPlazaInfoPanel_HideButtonPage(panel, graphics);
    }
    WiFiPlazaPanelButton_ShowInstrument(&panel->button, graphics, type, panel->narc, heapID);
    panel->page = WIFI_PLAZA_PANEL_PAGE_INSTRUMENT;
}

static void WiFiPlazaInfoPanel_HideButtonPage(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics) {
    WiFiPlazaPanelButton_Clear(&panel->button, graphics);
    panel->page = WIFI_PLAZA_PANEL_PAGE_NONE;
}

static void WiFiPlazaInfoPanel_SetButtonDisabled(WiFiPlazaInfoPanel *panel, u16 disabled) {
    panel->button.disabled = disabled;
}

static SysTask *WiFiPlazaInfoPanel_StartPaletteLoad(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics, u32 member, enum HeapID heapID) {
    panel->paletteMember = member;
    panel->paletteHeapID = heapID;
    return SysTask_CreateOnVWaitQueue(WiFiPlazaInfoPanel_LoadPaletteTask, panel, 0);
}

static void WiFiPlazaInfoPanel_LoadPaletteTask(SysTask *task, void *data) {
    WiFiPlazaInfoPanel *panel = data;
    NarcId narcId;
    int memberNo;

    GfGfxLoader_GXLoadPalFromOpenNarc(panel->narc, panel->paletteMember, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, (enum HeapID)panel->paletteHeapID);
    LoadFontPal0(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_5_OFFSET, (enum HeapID)panel->paletteHeapID);
    narcId = TypeIcon_GetNarc();
    memberNo = TypeIcon_GetPlttFile();
    GfGfxLoader_GXLoadPal(narcId, memberNo, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_11_OFFSET, 0x60, (enum HeapID)panel->paletteHeapID);
    SysTask_Destroy(task);
}

static void WiFiPlazaInfoPanel_LoadGraphics(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics, NARC *narc, u32 gender, enum HeapID heapID) {
    if (gender == 0) {
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0x56, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, heapID);
    } else {
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0x57, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, heapID);
    }
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0x36, graphics->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, heapID);
    LoadFontPal0(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_5_OFFSET, heapID);
}

static void WiFiPlazaInfoPanel_FreeGraphics(WiFiPlazaInfoPanel *panel, WiFiPlazaRoomGraphics *graphics) {
}

static void WiFiPlazaInfoPanel_LoadScreen(WiFiPlazaRoomGraphics *graphics, NARC *narc, int member, GFBgLayer bgId, int tileOffset, enum HeapID heapID) {
    NNSG2dScreenData *screen;
    void *allocation;
    int i;
    int count;
    u16 *rawData;

    allocation = GfGfxLoader_GetScrnDataFromOpenNarc(narc, member, FALSE, &screen, heapID);
    count = screen->szByte >> 1;
    rawData = (u16 *)screen->rawData;
    for (i = 0; i < count; i++) {
        rawData[i] += tileOffset;
    }
    LoadRectToBgTilemapRect(graphics->bgConfig, bgId, screen->rawData, 0, 0, screen->screenWidth >> 3, screen->screenHeight >> 3);
    ScheduleBgTilemapBufferTransfer(graphics->bgConfig, bgId);
    Heap_Free(allocation);
}

static void WiFiPlazaPlayerCard_Init(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics, NARC *narc, enum HeapID heapID) {
    int i;
    const WindowTemplate *template = sWiFiPlazaCardWindowTemplates;
    Window *window;

    i = 0;
    window = card->windows;
    do {
        AddWindow(graphics->bgConfig, window, template);
        i++;
        template ++;
        window++;
    } while (i < 5);
}

static void WiFiPlazaPlayerCard_Free(WiFiPlazaPlayerCard *card, WiFiPlazaMsgWindow *signWindow, WiFiPlazaRoomGraphics *graphics) {
    int i;

    if (card->iconSprite != NULL) {
        WiFiPlazaPlayerCard_Clear(card, signWindow, graphics);
    }
    for (i = 0; i < 5; i++) {
        RemoveWindow(&card->windows[i]);
    }
}

static void WiFiPlazaPlayerCard_Update(WiFiPlazaPlayerCard *card, WiFiPlazaMsgWindow *signWindow) {
}

static void WiFiPlazaPlayerCard_Show(WiFiPlazaInfoPanel *panel, WiFiPlazaMsgWindow *signWindow, WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics, WiFiPlazaRoomMsg *msg, BOOL isOwn, NARC *narc, enum HeapID heapID, struct WiFiPlazaPlayer *player, struct WiFiPlazaPlayer *myPlayer, int special, BOOL hasMessage, u16 *message, BOOL showIcon) {
    int color, avatar;
    PlayerProfile *profile;

    WiFiPlazaRoomMsg_ResetBuffers(msg);
    if (!WiFiPlazaPlayer_GetGender(player)) {
        color = MAKE_TEXT_COLOR(7, 8, 0);
        if (!special) {
            WiFiPlazaInfoPanel_StartPaletteLoad(panel, graphics, 86, heapID);
        } else {
            WiFiPlazaInfoPanel_StartPaletteLoad(panel, graphics, 88, heapID);
        }
    } else {
        color = MAKE_TEXT_COLOR(3, 4, 0);
        if (!special) {
            WiFiPlazaInfoPanel_StartPaletteLoad(panel, graphics, 87, heapID);
        } else {
            WiFiPlazaInfoPanel_StartPaletteLoad(panel, graphics, 88, heapID);
        }
    }
    BgFillTilemapBufferAndSchedule(graphics->bgConfig, GF_BG_LYR_SUB_0, 0);
    BgFillTilemapBufferAndSchedule(graphics->bgConfig, GF_BG_LYR_SUB_1, 0);
    BgFillTilemapBufferAndSchedule(graphics->bgConfig, GF_BG_LYR_SUB_2, 0);
    WiFiPlazaPlayerCard_ClearWindows(card);
    WiFiPlazaInfoPanel_LoadScreen(graphics, narc, 92, GF_BG_LYR_SUB_0, 0, heapID);
    profile = PlayerProfile_New(heapID);
    WiFiPlazaPlayer_CopyToProfile(player, profile, heapID);
    WiFiPlazaPlayerCard_Print(card, msg, 0, msg_0777_00044, 0, 0, color);
    WiFiPlazaRoomMsg_BufferInt(msg, PlayerProfile_GetTrainerID_VisibleHalf(profile), 5, 0, 2);
    WiFiPlazaPlayerCard_PrintRightAligned(card, msg, 0, msg_0777_00049, 122, 0, MAKE_TEXT_COLOR(1, 2, 0));
    WiFiPlazaPlayerCard_Print(card, msg, 0, msg_0777_00045, 0, 16, color);
    WiFiPlazaPlayerCard_BufferName(card, msg, profile);
    WiFiPlazaPlayerCard_PrintRightAligned(card, msg, 0, msg_0777_00050, 122, 16, MAKE_TEXT_COLOR(1, 2, 0));
    WiFiPlazaPlayerCard_CopyWindow(card, 0);
    WiFiPlazaPlayerCard_Print(card, msg, 1, msg_0777_00046, 0, 0, color);
    if (!WiFiPlazaPlayer_GetCountry(player)) {
        WiFiPlazaPlayerCard_Print(card, msg, 1, msg_0777_00055, 32, 16, MAKE_TEXT_COLOR(1, 2, 0));
    } else {
        WiFiPlazaPlayerCard_BufferLocation(card, msg, player);
        WiFiPlazaPlayerCard_Print(card, msg, 1, msg_0777_00051, 32, 16, MAKE_TEXT_COLOR(1, 2, 0));
    }
    WiFiPlazaPlayerCard_CopyWindow(card, 1);
    if (hasMessage) {
        card->showsMessage = TRUE;
        WiFiPlazaPlayerCard_BufferName(card, msg, profile);
        WiFiPlazaPlayerCard_Print(card, msg, 4, msg_0777_00056, 8, 0, color);
        WiFiPlazaPlayerCard_BufferMessage(card, msg, message);
        WiFiPlazaPlayerCard_Print(card, msg, 4, msg_0777_00059, 6, 24, MAKE_TEXT_COLOR(1, 2, 0));
        WiFiPlazaPlayerCard_Print(card, msg, 4, msg_0777_00060, 90, 24, MAKE_TEXT_COLOR(1, 2, 0));
        WiFiPlazaPlayerCard_Print(card, msg, 4, msg_0777_00061, 6, 44, MAKE_TEXT_COLOR(1, 2, 0));
        WiFiPlazaPlayerCard_Print(card, msg, 4, msg_0777_00062, 90, 44, MAKE_TEXT_COLOR(1, 2, 0));
        WiFiPlazaPlayerCard_CopyWindow(card, 4);
    } else {
        card->showsMessage = FALSE;
        WiFiPlazaPlayerCard_Print(card, msg, 4, msg_0777_00048, 8, 0, color);
        WiFiPlazaPlayerCard_CopyWindow(card, 4);
        WiFiPlazaPlayerCard_LoadMons(card, graphics, narc, heapID, player, myPlayer);
    }
    WiFiPlazaPlayerCard_LoadIcon(card, graphics, narc, heapID, WiFiPlazaPlayer_GetTapToy(player), showIcon);
    if (isOwn == TRUE) {
        if (WiFiPlazaPlayer_GetGender(player) == 1) {
            avatar = 97;
        } else {
            avatar = 0;
        }
    } else {
        avatar = WiFiPlazaPlayer_GetAvatar(player);
    }
    WiFiPlazaPlayerCard_LoadAvatar(card, graphics, narc, heapID, avatar);
    WiFiPlazaPlayerCard_LoadTypeIcons(panel, card, graphics, heapID, player);
    Heap_Free(profile);
}

static void WiFiPlazaPlayerCard_LoadTypeIcons(WiFiPlazaInfoPanel *unused0, WiFiPlazaPlayerCard *unused1, WiFiPlazaRoomGraphics *graphics, enum HeapID heapID, struct WiFiPlazaPlayer *player) {
    s32 i = 0;
    const u16 *tileBase = sWiFiPlazaCardTypeIconTileBases;
    const u8(*tiles)[0x10] = sWiFiPlazaCardTypeIconTiles;
    u32 y = 2;

    for (; i < 2; i++) {
        u16 choice = WiFiPlazaPlayer_GetFavoriteType(player, i);
        if (choice != 0) {
            u16 type = WiFiPlaza_GetTypeByChoice(choice);
            NarcId narcId = TypeIcon_GetNarc();
            u32 member = TypeIcon_GetCharFile(type);
            void *buf = GfGfxLoader_LoadFromNarc(narcId, member, TRUE, heapID, TRUE);
            NNSG2dCharacterData *charData;

            NNS_G2dGetUnpackedCharacterData(buf, &charData);
            BG_LoadCharTilesData(graphics->bgConfig, GF_BG_LYR_SUB_2, charData->pRawData, 0x100, *tileBase);
            Heap_Free(buf);
            CopyToBgTilemapRect(graphics->bgConfig, GF_BG_LYR_SUB_2, 26, y, 4, 2, *tiles, 0, 0, 4, 2);
            BgTilemapRectChangePalette(graphics->bgConfig, GF_BG_LYR_SUB_2, 26, y, 4, 2, TypeIcon_GetPalette(type) + 11);
            ScheduleBgTilemapBufferTransfer(graphics->bgConfig, GF_BG_LYR_SUB_2);
        }
        tiles++;
        tileBase++;
        y += 2;
    }
}

static void WiFiPlazaPlayerCard_Clear(WiFiPlazaPlayerCard *card, WiFiPlazaMsgWindow *unused, WiFiPlazaRoomGraphics *graphics) {
    if (card->showsMessage == TRUE) {
        card->showsMessage = FALSE;
    } else {
        WiFiPlazaPlayerCard_FreeMons(card, graphics);
    }
    WiFiPlazaPlayerCard_FreeIcon(card, graphics);
    WiFiPlazaPlayerCard_FreeAvatar(card, graphics);
    BgClearTilemapBufferAndCommit(graphics->bgConfig, GF_BG_LYR_SUB_0);
    BgClearTilemapBufferAndCommit(graphics->bgConfig, GF_BG_LYR_SUB_1);
    BgClearTilemapBufferAndCommit(graphics->bgConfig, GF_BG_LYR_SUB_2);
}

static void WiFiPlazaPlayerCard_ChangeIcon(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics, NARC *narc, enum HeapID heapID, u32 icon) {
    WiFiPlazaPlayerCard_FreeIcon(card, graphics);
    WiFiPlazaPlayerCard_LoadIcon(card, graphics, narc, heapID, icon, TRUE);
}

static BOOL WiFiPlazaPlayerCard_ShowsMessage(WiFiPlazaPlayerCard *card) {
    return card->showsMessage;
}

// Tap Toy icon: 27 icons, 3 animations per graphics set
static void WiFiPlazaPlayerCard_LoadIcon(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics, NARC *narc, enum HeapID heapID, u32 icon, BOOL draw) {
    SpriteResourcesHeader header;
    u32 set, anim;

    GF_ASSERT(icon < 27);
    GF_ASSERT(card->iconSprite == NULL);
    set = icon / 3;
    anim = icon % 3;

    card->iconResources[GF_GFX_RES_TYPE_CHAR] = AddCharResObjFromOpenNarc(graphics->resManagers[GF_GFX_RES_TYPE_CHAR], narc, set * 3 + 0x3D, FALSE, 100, NNS_G2D_VRAM_TYPE_2DSUB, heapID);
    GF_ASSERT(SpriteTransfer_CreateCharTransferTask_AllocAtEnd(card->iconResources[GF_GFX_RES_TYPE_CHAR]));
    GF2DGfxResObj_FreeData(card->iconResources[GF_GFX_RES_TYPE_CHAR]);
    card->iconResources[GF_GFX_RES_TYPE_PLTT] = AddPlttResObjFromOpenNarc(graphics->resManagers[GF_GFX_RES_TYPE_PLTT], narc, 0x59, FALSE, 100, NNS_G2D_VRAM_TYPE_2DSUB, 3, heapID);
    GF_ASSERT(SpriteTransfer_CreatePlttTransferTask(card->iconResources[GF_GFX_RES_TYPE_PLTT]));
    GF2DGfxResObj_FreeData(card->iconResources[GF_GFX_RES_TYPE_PLTT]);
    card->iconResources[GF_GFX_RES_TYPE_CELL] = AddCellOrAnimResObjFromOpenNarc(graphics->resManagers[GF_GFX_RES_TYPE_CELL], narc, set * 3 + 0x3C, FALSE, 100, GF_GFX_RES_TYPE_CELL, heapID);
    card->iconResources[GF_GFX_RES_TYPE_ANIM] = AddCellOrAnimResObjFromOpenNarc(graphics->resManagers[GF_GFX_RES_TYPE_ANIM], narc, set * 3 + 0x3B, FALSE, 100, GF_GFX_RES_TYPE_ANIM, heapID);

    SimpleSpriteTemplate template = { 0 };
    CreateSpriteResourcesHeader(&header, 100, 100, 100, 100, -1, -1, FALSE, 0, graphics->resManagers[GF_GFX_RES_TYPE_CHAR], graphics->resManagers[GF_GFX_RES_TYPE_PLTT], graphics->resManagers[GF_GFX_RES_TYPE_CELL], graphics->resManagers[GF_GFX_RES_TYPE_ANIM], NULL, NULL);
    template.spriteList = graphics->spriteList;
    template.header = &header;
    template.priority = 16;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DSUB;
    template.position.x = FX32_CONST(208);
    template.position.y = FX32_CONST(408);
    template.heapID = heapID;
    card->iconSprite = Sprite_Create(&template);
    Sprite_SetAnimCtrlSeq(card->iconSprite, anim);
    Sprite_SetDrawFlag(card->iconSprite, draw);
}

static void WiFiPlazaPlayerCard_FreeIcon(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics) {
    int i;

    Sprite_Delete(card->iconSprite);
    card->iconSprite = NULL;
    SpriteTransfer_DeleteCharTransferTask(card->iconResources[GF_GFX_RES_TYPE_CHAR]);
    SpriteTransfer_DeletePlttTransferTask(card->iconResources[GF_GFX_RES_TYPE_PLTT]);
    for (i = 0; i < 4; i++) {
        DestroySingle2DGfxResObj(graphics->resManagers[i], card->iconResources[i]);
    }
}

static void WiFiPlazaPlayerCard_LoadAvatar(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics, NARC *narc, enum HeapID heapID, u32 avatar) {
    TrainerPicFileIds files;
    SpriteResourcesHeader header;
    u16 trainerClass, x;
    u16 y;
    u32 i;

    GF_ASSERT(card->avatarSprite == NULL);
    for (i = 0; i < 18; i++) {
        if (avatar == sWiFiPlazaCardAvatars[i].avatar) {
            trainerClass = sWiFiPlazaCardAvatars[i].trainerClass;
            x = sWiFiPlazaCardAvatars[i].x;
            y = sWiFiPlazaCardAvatars[i].y;
        }
    }
    GetTrainerPicFileIdsNoLink(trainerClass, 2, &files);

    card->avatarResources[GF_GFX_RES_TYPE_CHAR] = AddCharResObjFromNarc(graphics->resManagers[GF_GFX_RES_TYPE_CHAR], files.narcId, files.ncgr_id, FALSE, 101, NNS_G2D_VRAM_TYPE_2DSUB, heapID);
    GF_ASSERT(SpriteTransfer_CreateCharTransferTask_AllocAtEnd(card->avatarResources[GF_GFX_RES_TYPE_CHAR]));
    card->avatarResources[GF_GFX_RES_TYPE_PLTT] = AddPlttResObjFromNarc(graphics->resManagers[GF_GFX_RES_TYPE_PLTT], files.narcId, files.nclr_id, FALSE, 101, NNS_G2D_VRAM_TYPE_2DSUB, 1, heapID);
    WiFiPlazaInfoPanel_TintPalette(GF2DGfxResObj_GetPlttDataPtr(card->avatarResources[GF_GFX_RES_TYPE_PLTT]));
    GF_ASSERT(SpriteTransfer_CreatePlttTransferTask(card->avatarResources[GF_GFX_RES_TYPE_PLTT]));
    GF2DGfxResObj_FreeData(card->avatarResources[GF_GFX_RES_TYPE_PLTT]);
    card->avatarResources[GF_GFX_RES_TYPE_CELL] = AddCellOrAnimResObjFromNarc(graphics->resManagers[GF_GFX_RES_TYPE_CELL], files.narcId, files.ncer_id, FALSE, 101, GF_GFX_RES_TYPE_CELL, heapID);
    card->avatarResources[GF_GFX_RES_TYPE_ANIM] = AddCellOrAnimResObjFromNarc(graphics->resManagers[GF_GFX_RES_TYPE_ANIM], files.narcId, files.nanr_id, FALSE, 101, GF_GFX_RES_TYPE_ANIM, heapID);

    SimpleSpriteTemplate template = { 0 };
    CreateSpriteResourcesHeader(&header, 101, 101, 101, 101, -1, -1, TRUE, 3, graphics->resManagers[GF_GFX_RES_TYPE_CHAR], graphics->resManagers[GF_GFX_RES_TYPE_PLTT], graphics->resManagers[GF_GFX_RES_TYPE_CELL], graphics->resManagers[GF_GFX_RES_TYPE_ANIM], NULL, NULL);
    template.spriteList = graphics->spriteList;
    template.header = &header;
    template.priority = 32;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DSUB;
    template.heapID = heapID;
    template.position.x = FX32_CONST(x);
    template.position.y = FX32_CONST(y) + FX32_CONST(256);
    card->avatarSprite = Sprite_Create(&template);
}

static void WiFiPlazaPlayerCard_FreeAvatar(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics) {
    int i;

    ObjCharTransfer_DeleteTaskCopyByProxyPtr(Sprite_GetImageProxy(card->avatarSprite));
    Sprite_Delete(card->avatarSprite);
    card->avatarSprite = NULL;
    SpriteTransfer_DeleteCharTransferTask(card->avatarResources[GF_GFX_RES_TYPE_CHAR]);
    SpriteTransfer_DeletePlttTransferTask(card->avatarResources[GF_GFX_RES_TYPE_PLTT]);
    for (i = 0; i < 4; i++) {
        DestroySingle2DGfxResObj(graphics->resManagers[i], card->avatarResources[i]);
    }
}

// Tints the avatar palette: grey level of each colour, mapped to a blue-green shade.
#pragma opt_propagation off

static void WiFiPlazaInfoPanel_TintPalette(NNSG2dPaletteData *pltt) {
    int i;
    int n = pltt->szByte / 2;
    u16 *p = pltt->pRawData;
    int r, g, b, gray;
    i = 0;
    if (n > 0) {
        do {
            r = *p & 0x1F;
            g = (*p >> 5) & 0x1F;
            b = (*p >> 10) & 0x1F;
            gray = (r * 76 + g * 151 + b * 29) >> 8;
            *p = (((gray * 128) >> 8) << 10) | (((gray * 200) >> 8) << 5) | ((gray * 256) >> 8);
            p++;
        } while (++i < n);
    }
}

#pragma opt_propagation reset

static void WiFiPlazaPlayerCard_ClearWindows(WiFiPlazaPlayerCard *card) {
    int i;
    Window *window = card->windows;
    for (i = 0; i < 5; i++, window++) {
        FillWindowPixelBuffer(window, 0);
    }
}

static void WiFiPlazaPlayerCard_Print(WiFiPlazaPlayerCard *card, WiFiPlazaRoomMsg *msg, int window, int msgId, u8 x, u8 y, u32 color) {
    String *string = WiFiPlazaRoomMsg_GetString(msg, WIFI_PLAZA_MSG_BANK_PLAZA, msgId);
    AddTextPrinterParameterizedWithColor(&card->windows[window], 0, string, x, y, TEXT_SPEED_NOTRANSFER, color, NULL);
}

static void WiFiPlazaPlayerCard_PrintRightAligned(WiFiPlazaPlayerCard *card, WiFiPlazaRoomMsg *msg, int window, int msgId, u8 width, u8 y, u32 color) {
    String *string = WiFiPlazaRoomMsg_GetString(msg, WIFI_PLAZA_MSG_BANK_PLAZA, msgId);
    int x = width - FontID_String_GetWidth(0, string, 0);
    if (x < 0) {
        x = 0;
    }
    AddTextPrinterParameterizedWithColor(&card->windows[window], 0, string, x, y, TEXT_SPEED_NOTRANSFER, color, NULL);
}

static void WiFiPlazaPlayerCard_CopyWindow(WiFiPlazaPlayerCard *card, int window) {
    ScheduleWindowCopyToVram(&card->windows[window]);
}

static void WiFiPlazaPlayerCard_BufferName(WiFiPlazaPlayerCard *card, WiFiPlazaRoomMsg *msg, PlayerProfile *profile) {
    WiFiPlazaRoomMsg_BufferPlayerName(msg, profile, 0);
}

static void WiFiPlazaPlayerCard_BufferLocation(WiFiPlazaPlayerCard *card, WiFiPlazaRoomMsg *msg, struct WiFiPlazaPlayer *player) {
    u32 country = WiFiPlazaPlayer_GetCountry(player);
    u32 region = WiFiPlazaPlayer_GetRegion(player);
    WiFiPlazaRoomMsg_BufferCountryName(msg, country, 0);
    WiFiPlazaRoomMsg_BufferCityName(msg, country, region, 1);
}

static void WiFiPlazaPlayerCard_BufferMessage(WiFiPlazaPlayerCard *card, WiFiPlazaRoomMsg *msg, u16 *words) {
    int i;
    for (i = 0; i < 4; i++) {
        WiFiPlazaRoomMsg_BufferECWord(msg, i, words[i]);
    }
}

// The player's Pokemon (12 slots, species 24 = empty) with shared palettes / cells / animations per kind.

static void WiFiPlazaPlayerCard_LoadMons(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics, NARC *panelNarc, enum HeapID heapID, struct WiFiPlazaPlayer *player, struct WiFiPlazaPlayer *myPlayer) {
    NARC *narc = NARC_New(NARC_a_2_1_3, heapID);
    int gender;
    const VecFx32 *pos;
    int version = WiFiPlazaPlayer_GetLobbyId(myPlayer);
    NARC *use;
    int i;
    SimpleSpriteTemplate template;
    SpriteResourcesHeader header;

    gender = WiFiPlazaPlayer_GetGender(myPlayer);
    for (i = 0; i < 4; i++) {
        if (i == 2) {
            if (gender == 1) {
                card->monPltts[i] = NULL;
                card->monCells[i] = NULL;
                card->monAnims[i] = NULL;
                continue;
            }
        } else if (i == 3) {
            if (gender == 0) {
                card->monPltts[i] = NULL;
                card->monCells[i] = NULL;
                card->monAnims[i] = NULL;
                continue;
            }
        }
        use = sWiFiPlazaCardMonResources[i].narc == 215 ? narc : panelNarc;
        card->monPltts[i] = AddPlttResObjFromOpenNarc(graphics->resManagers[GF_GFX_RES_TYPE_PLTT], use, sWiFiPlazaCardMonResources[i].member, FALSE, 150 + i, NNS_G2D_VRAM_TYPE_2DSUB, sWiFiPlazaCardMonResources[i].count, heapID);
        if (!SpriteTransfer_CreatePlttTransferTask(card->monPltts[i])) {
            GF_ASSERT(FALSE);
        }
        GF2DGfxResObj_FreeData(card->monPltts[i]);
        card->monCells[i] = AddCellOrAnimResObjFromOpenNarc(graphics->resManagers[GF_GFX_RES_TYPE_CELL], use, sWiFiPlazaCardMonCellFiles[i], FALSE, 150 + i, GF_GFX_RES_TYPE_CELL, heapID);
        card->monAnims[i] = AddCellOrAnimResObjFromOpenNarc(graphics->resManagers[GF_GFX_RES_TYPE_ANIM], use, sWiFiPlazaCardMonAnimFiles[i], FALSE, 150 + i, GF_GFX_RES_TYPE_ANIM, heapID);
    }
    pos = sWiFiPlazaCardMonPositions;
    for (i = 0; i < 12; i++) {
        int species = WiFiPlazaPlayer_GetHistoryId(player, i);
        int form = WiFiPlazaPlayer_GetHistoryValue(player, i);
        if (species == 24) {
            card->monChars[0] = NULL;
            card->monSprites[0] = NULL;
        } else {
            const WiFiPlazaCardMonInfo *info = WiFiPlazaPlayerCard_GetMonInfo(species, form, version, gender);
            card->monChars[0] = AddCharResObjFromOpenNarc(graphics->resManagers[GF_GFX_RES_TYPE_CHAR], info->source == 1 ? panelNarc : narc, info->member, FALSE, 150 + i, NNS_G2D_VRAM_TYPE_2DSUB, heapID);
            if (!SpriteTransfer_CreateCharTransferTask_AllocAtEnd(card->monChars[0])) {
                GF_ASSERT(FALSE);
            }
            GF2DGfxResObj_FreeData(card->monChars[0]);
            CreateSpriteResourcesHeader(&header, 150 + i, 150 + info->source, 150 + info->source, 150 + info->source, -1, -1, FALSE, 0, graphics->resManagers[GF_GFX_RES_TYPE_CHAR], graphics->resManagers[GF_GFX_RES_TYPE_PLTT], graphics->resManagers[GF_GFX_RES_TYPE_CELL], graphics->resManagers[GF_GFX_RES_TYPE_ANIM], NULL, NULL);
            template.spriteList = graphics->spriteList;
            template.header = &header;
            template.priority = 0;
            template.whichScreen = NNS_G2D_VRAM_TYPE_2DSUB;
            template.heapID = heapID;
            template.position = *pos;
            template.position.x += (int)(info->x > 0 ? 0.5f + (float)(info->x << FX32_SHIFT) : (float)(info->x << FX32_SHIFT) - 0.5f);
            template.position.y += (int)(info->y > 0 ? 0.5f + (float)(info->y << FX32_SHIFT) : (float)(info->y << FX32_SHIFT) - 0.5f);
            card->monSprites[0] = Sprite_Create(&template);
            Sprite_SetPalOffsetRespectVramOffset(card->monSprites[0], info->palette);
        }
        pos++;
        card = (WiFiPlazaPlayerCard *)((u8 *)card + 4);
    }
    NARC_Delete(narc);
}

static void WiFiPlazaPlayerCard_FreeMons(WiFiPlazaPlayerCard *card, WiFiPlazaRoomGraphics *graphics) {
    int i = 0;
    u8 *cursor = (u8 *)card;
    for (; i < 12; i++, cursor += 4) {
        WiFiPlazaPlayerCard *slot = (WiFiPlazaPlayerCard *)cursor;
        if (slot->monChars[0]) {
            Sprite_Delete(slot->monSprites[0]);
            slot->monSprites[0] = NULL;
            SpriteTransfer_DeleteCharTransferTask(slot->monChars[0]);
            DestroySingle2DGfxResObj(graphics->resManagers[GF_GFX_RES_TYPE_CHAR], slot->monChars[0]);
            slot->monChars[0] = NULL;
        }
    }
    cursor = (u8 *)card;
    for (i = 0; i < 4; i++, cursor += 4) {
        WiFiPlazaPlayerCard *slot = (WiFiPlazaPlayerCard *)cursor;
        if (slot->monPltts[0]) {
            SpriteTransfer_DeletePlttTransferTask(slot->monPltts[0]);
            DestroySingle2DGfxResObj(graphics->resManagers[GF_GFX_RES_TYPE_PLTT], slot->monPltts[0]);
            DestroySingle2DGfxResObj(graphics->resManagers[GF_GFX_RES_TYPE_CELL], slot->monCells[0]);
            DestroySingle2DGfxResObj(graphics->resManagers[GF_GFX_RES_TYPE_ANIM], slot->monAnims[0]);
            slot->monPltts[0] = NULL;
        }
    }
}

static const WiFiPlazaCardMonInfo *WiFiPlazaPlayerCard_GetMonInfo(int species, int form, int version, int gender) {
    if (form == version) {
        return &sWiFiPlazaCardPlayerMonInfo[gender];
    }
    return &sWiFiPlazaCardSpeciesMonInfo[species];
}

static void WiFiPlazaPanelButton_Init(WiFiPlazaPanelButton *button, WiFiPlazaRoomGraphics *graphics, NARC *narc, enum HeapID heapID) {
    s32 i;

    AddWindow(graphics->bgConfig, &button->window, &sWiFiPlazaPanelButtonWindowTemplate);
    for (i = 0; i < 3; i++) {
        button->screenAllocs[i] = GfGfxLoader_GetScrnDataFromOpenNarc(narc, i + 0x38, FALSE, &button->screens[i], heapID);
    }
    button->touch = TouchHitboxController_Create(sWiFiPlazaPanelButtonHitbox, 1, WiFiPlazaPanelButton_OnTouch, button, heapID);
    button->disabled = TRUE;
}

static void WiFiPlazaPanelButton_Free(WiFiPlazaPanelButton *button) {
    int i;
    u8 *cursor;
    TouchHitboxController_Destroy(button->touch);
    RemoveWindow(&button->window);
    i = 0;
    cursor = (u8 *)button;
    for (; i < 3; i++, cursor += 4) {
        Heap_Free(((WiFiPlazaPanelButton *)cursor)->screenAllocs[0]);
    }
    button->active = FALSE;
}

static BOOL WiFiPlazaPanelButton_Update(WiFiPlazaPanelButton *button, WiFiPlazaRoomGraphics *graphics, NARC *narc, enum HeapID heapID) {
    BOOL pressed = FALSE;
    if (!button->disabled) {
        TouchHitboxController_IsTriggered(button->touch);
    } else {
        button->selected = 1;
    }
    if (button->active == TRUE && button->timer == 0) {
        button->active = FALSE;
        WiFiPlazaPanelButton_Draw(button, graphics, 0, narc, heapID);
    }
    if (button->selected != button->previous) {
        button->previous = button->selected;
        if (button->selected == 2) {
            WiFiPlazaPanelButton_Draw(button, graphics, 1, narc, heapID);
        } else if (!button->active) {
            WiFiPlazaPanelButton_Draw(button, graphics, 0, narc, heapID);
        } else {
            WiFiPlazaPanelButton_Draw(button, graphics, 2, narc, heapID);
        }
        if (!button->active && button->selected == 2) {
            button->active = TRUE;
            pressed = TRUE;
            button->timer = 1;
        }
    }
    return pressed;
}

static void WiFiPlazaPanelButton_ShowOwnCard(WiFiPlazaPanelButton *button, WiFiPlazaRoomGraphics *graphics, WiFiPlazaRoomMsg *msg, struct WiFiPlazaPlayer *player, NARC *narc, enum HeapID heapID) {
    String *text;
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0x37, graphics->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, heapID);
    button->instrumentMode = FALSE;
    button->graphic = WiFiPlazaPlayer_GetTapToy(player);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, button->graphic, graphics->bgConfig, GF_BG_LYR_SUB_2, 0x140, 0, FALSE, heapID);
    WiFiPlazaInfoPanel_LoadScreen(graphics, narc, button->graphic + 0x1B, GF_BG_LYR_SUB_2, 0x140, heapID);
    text = WiFiPlazaRoomMsg_GetString(msg, WIFI_PLAZA_MSG_BANK_PLAZA, msg_0777_00063);
    FillWindowPixelBuffer(&button->window, 0);
    AddTextPrinterParameterizedWithColor(&button->window, 0, text, 0, 4, TEXT_SPEED_INSTANT, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    if (!button->active) {
        WiFiPlazaPanelButton_Draw(button, graphics, 0, narc, heapID);
    } else {
        WiFiPlazaPanelButton_Draw(button, graphics, 2, narc, heapID);
    }
}

static void WiFiPlazaPanelButton_ShowInstrument(WiFiPlazaPanelButton *button, WiFiPlazaRoomGraphics *graphics, u32 type, NARC *narc, enum HeapID heapID) {
    GF_ASSERT(type < 3);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0x37, graphics->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, heapID);
    button->instrumentMode = TRUE;
    button->graphic = type;
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, button->graphic + 0x5D, graphics->bgConfig, GF_BG_LYR_SUB_2, 0x140, 0, FALSE, heapID);
    if (!button->active) {
        WiFiPlazaPanelButton_Draw(button, graphics, 0, narc, heapID);
    } else {
        WiFiPlazaPanelButton_Draw(button, graphics, 2, narc, heapID);
    }
}

static void WiFiPlazaPanelButton_Clear(WiFiPlazaPanelButton *unused, WiFiPlazaRoomGraphics *graphics) {
    BgClearTilemapBufferAndCommit(graphics->bgConfig, GF_BG_LYR_SUB_0);
    BgClearTilemapBufferAndCommit(graphics->bgConfig, GF_BG_LYR_SUB_1);
    BgClearTilemapBufferAndCommit(graphics->bgConfig, GF_BG_LYR_SUB_2);
    BgSetPosTextAndCommit(graphics->bgConfig, GF_BG_LYR_SUB_2, BG_POS_OP_SET_Y, 0);
}

// index 0: up, 1: pressed, 2: playing

static void WiFiPlazaPanelButton_Draw(WiFiPlazaPanelButton *button, WiFiPlazaRoomGraphics *graphics, int index, NARC *narc, enum HeapID heapID) {
    CopyToBgTilemapRect(graphics->bgConfig, GF_BG_LYR_SUB_1, 0, 3, 32, 21, button->screens[index]->rawData, 0, 3, 32, 32);
    ScheduleBgTilemapBufferTransfer(graphics->bgConfig, GF_BG_LYR_SUB_1);
    if (button->instrumentMode == TRUE) {
        WiFiPlazaInfoPanel_LoadScreen(graphics, narc, sWiFiPlazaPanelButtonScreenBases[index] + button->graphic * 2 + 96, GF_BG_LYR_SUB_2, 320, heapID);
    }
    ScheduleSetBgPosText(graphics->bgConfig, GF_BG_LYR_SUB_2, BG_POS_OP_SET_Y, sWiFiPlazaPanelButtonScrollY[index]);
}

static void WiFiPlazaPanelButton_OnTouch(u32 index, u32 event, void *arg) {
    WiFiPlazaPanelButton *button = arg;
    button->selected = event;
    if (button->selected == 0) {
        button->selected = 2;
    } else if (button->selected == 3) {
        button->selected = 1;
    }
}

static void WiFiPlazaPanelButton_ResetTimer(WiFiPlazaPanelButton *button) {
    button->timer = 0;
}

u32 WiFiPlazaRoom_GetTextSpeed(WiFiPlazaRoomWork *room) {
    return room->msgWindow.textSpeed;
}
