#include "frontier/frontier_script_ui.h"

#include <string.h>

#include "global.h"

#include "constants/sndseq.h"

#include "frontier/frontier.h"
#include "frontier/frontier_map.h"
#include "frontier/frontier_script_context.h"
#include "frontier/frontier_system.h"
#include "msgdata/msg.naix"

#include "bg_window.h"
#include "char_tiles.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "list_menu.h"
#include "list_menu_2d.h"
#include "mail_message.h"
#include "message_format.h"
#include "msgdata.h"
#include "obj_pltt_transfer.h"
#include "options.h"
#include "palette.h"
#include "party_menu.h"
#include "player_data.h"
#include "pm_string.h"
#include "pokemon.h"
#include "pokemon_icon_idx.h"
#include "render_text.h"
#include "render_window.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "sprite_system.h"
#include "sys_task_api.h"
#include "system.h"
#include "text.h"

static void FrontierSystem_ShowMessageWindow(FrontierSystem *system);
static void FrontierSystem_FormatMessage(FrontierSystem *system, MsgData *msgData, u16 msgId);
static void FrontierSystem_StartTextPrinter(FrontierSystem *system, u8 font, u32 speed, BOOL canABSpeedUp, BOOL autoScroll);
static void FrontierScript_GetMailMessageString(String *dest, u16 bank, u16 number, u16 field0, u16 field1);
static void FrontierMenu_AddItemInternal(FrontierMenu *menu, u32 msgId, u16 description, u32 value);
static u32 FrontierMenu_GetWidth(FrontierMenu *menu);
static void FrontierMenu_InitTemplate(FrontierMenu *menu);
static void FrontierMenu_Task(SysTask *task, FrontierMenu *menu);
static void FrontierMenu_Close(FrontierMenu *menu);
static void FrontierMenu_PrintDescription(FrontierMenu *menu);
static void FrontierListMenu_AddItemInternal(FrontierMenu *menu, u32 msgId, u16 description, u32 value);
static u32 FrontierListMenu_GetWidth(FrontierMenu *menu);
static void FrontierListMenu_InitTemplate(FrontierMenu *menu);
static void FrontierListMenu_PrintItem(ListMenu *list, s32 value, u8 onInit);
static u32 FrontierListMenu_MoveCursorCallback(ListMenu *list);
static void FrontierListMenu_Task(SysTask *task, FrontierMenu *menu);
static void FrontierListMenu_Close(FrontierMenu *menu, BOOL playSound);
static void FrontierMenu_PrintMessage(FrontierMenu *menu, u16 msgId, u32 speed);
static void FrontierListMenu_PrintDescription(FrontierMenu *menu);
static BOOL FrontierScriptNative_WaitMessageEntry(FrontierScriptContext *ctx);

typedef void (*FrontierPrintMailMessageFunc)(FrontierSystem *system, int speed, u16 bank, u16 number, u16 field0, s16 field1, u8 canABSpeedUp);
typedef u32 (*FrontierObjectGetPosFunc)(Field2DObject *object);

#define FRONTIER_MON_SPRITE_ID_BASE 50000
#define FRONTIER_MON_ICON_ID_BASE   2000

static const u8 sFrontierMovementWaitFrames[] = { 1, 2, 4, 8, 15, 16, 32, 0 };

static const ManagedSpriteTemplate sFrontierMapItemIconTemplate = {
    .x = 0,
    .y = 0,
    .z = 0,
    .animation = 0,
    .drawPriority = 99,
    .pal = 0,
    .vram = NNS_G2D_VRAM_TYPE_2DMAIN,
    .resIdList = { 2009, 2001, 2001, 2001, -1, -1 },
    .bgPriority = 1,
    .vramTransfer = 0,
};

static const ManagedSpriteTemplate sFrontierMapMonIconTemplate = {
    .x = 0,
    .y = 0,
    .z = 0,
    .animation = 0,
    .drawPriority = 100,
    .pal = 0,
    .vram = NNS_G2D_VRAM_TYPE_2DMAIN,
    .resIdList = { 2000, 2000, 2000, 2000, -1, -1 },
    .bgPriority = 1,
    .vramTransfer = 0,
};

// Animation step and facing direction of each movement opcode.
static u16 sFrontierMovementSteps[][2] = {
    { 0,  0 },
    { 0,  1 },
    { 0,  2 },
    { 0,  3 },
    { 2,  0 },
    { 2,  1 },
    { 2,  2 },
    { 2,  3 },
    { 6,  0 },
    { 6,  1 },
    { 6,  2 },
    { 6,  3 },
    { 7,  0 },
    { 7,  1 },
    { 7,  2 },
    { 7,  3 },
    { 10, 0 },
    { 10, 1 },
    { 10, 2 },
    { 10, 3 },
    { 11, 0 },
    { 11, 1 },
    { 11, 2 },
    { 11, 3 },
    { 8,  0 },
    { 8,  1 },
    { 8,  2 },
    { 8,  3 },
    { 9,  0 },
    { 9,  1 },
    { 9,  2 },
    { 9,  3 },
};

void FrontierSystem_PrintMessage(FrontierSystem *system, MsgData *msgData, u16 msgId, u16 canABSpeedUp, const FrontierMessageParams *params) {
    u8 speed, autoScroll, font;

    FrontierSystem_ShowMessageWindow(system);
    FrontierSystem_FormatMessage(system, msgData, msgId);
    if (params == NULL) {
        speed = Options_GetTextFrameDelay(Frontier_GetLaunchArgs(FrontierSystem_GetFrontierMap(system)->frontier)->options);
        autoScroll = 0;
        font = 1;
    } else {
        speed = params->speed;
        autoScroll = params->autoScroll;
        font = params->font;
    }
    FrontierSystem_StartTextPrinter(system, font, speed, canABSpeedUp, autoScroll);
}

static void FrontierSystem_ShowMessageWindow(FrontierSystem *system) {
    FrontierMap *map = FrontierSystem_GetFrontierMap(system);

    if (!system->messageWindowAdded) {
        AddWindowParameterized(map->bgConfig, &system->messageWindow, GF_BG_LYR_MAIN_1, 2, 19, 27, 4, 13, 0x36D);
        FillWindowPixelBuffer(&system->messageWindow, 15);
        DrawFrameAndWindow2(&system->messageWindow, FALSE, 0x3E2, 11);
        system->messageWindowAdded = TRUE;
    } else {
        FillWindowPixelBuffer(&system->messageWindow, 15);
    }
}

static void FrontierSystem_FormatMessage(FrontierSystem *system, MsgData *msgData, u16 msgId) {
    ReadMsgDataIntoString(msgData, msgId, system->msgTemplate);
    StringExpandPlaceholders(system->msgFormat, system->msgBuffer, system->msgTemplate);
}

static void FrontierSystem_StartTextPrinter(FrontierSystem *system, u8 font, u32 speed, BOOL canABSpeedUp, BOOL autoScroll) {
    TextFlags_SetCanABSpeedUpPrint(canABSpeedUp);
    TextFlags_SetAutoScrollParam(autoScroll);
    if (speed == 0 || speed == 0xFF) {
        TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    } else {
        TextFlags_SetCanTouchSpeedUpPrint(TRUE);
    }
    system->textPrinterId = AddTextPrinterParameterized(&system->messageWindow, font, system->msgBuffer, 0, 0, speed, NULL);
}

void FrontierSystem_CloseMessageWindow(FrontierSystem *system) {
    GF_ASSERT(system->messageWindowAdded == TRUE);
    ClearFrameAndWindow2(&system->messageWindow, FALSE);
    RemoveWindow(&system->messageWindow);
    system->messageWindowAdded = FALSE;
}

static void FrontierSystem_PrintMailMessage(FrontierSystem *system, int speed, u16 bank, u16 number, u16 field0, u16 field1, u8 canABSpeedUp) {
    FrontierSystem_ShowMessageWindow(system);
    FrontierScript_GetMailMessageString(system->msgBuffer, bank, number, field0, field1);
    if (canABSpeedUp != 0xFF) {
        FrontierSystem_StartTextPrinter(system, 1, speed, canABSpeedUp, FALSE);
    } else {
        FrontierSystem_StartTextPrinter(system, 1, 0, canABSpeedUp, FALSE);
    }
}

static void FrontierScript_GetMailMessageString(String *dest, u16 bank, u16 number, u16 field0, u16 field1) {
    MailMessage message;
    String *expanded;

    MailMsg_Init(&message);
    MailMsg_SetMsgBankAndNum(&message, bank, number);
    MailMsg_SetFieldI(&message, 0, field0);
    MailMsg_SetFieldI(&message, 1, field1);
    expanded = MailMsg_GetExpandedString(&message, HEAP_ID_FIELD3);
    String_Copy(dest, expanded);
    String_Delete(expanded);
}

static void FrontierMenu_Init(FrontierSystem *system, FrontierMenu *menu, u8 x, u8 y, u8 initialSelection, u8 canCancel, u16 *result, MessageFormat *msgFormat, MsgData *msgData) {
    int i;

    if (msgData == NULL) {
        menu->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0191_bin, system->heapId);
        menu->ownsMsgData = TRUE;
    } else {
        menu->msgData = msgData;
        menu->ownsMsgData = FALSE;
    }
    menu->msgFormat = msgFormat;
    menu->system = system;
    menu->result = result;
    *menu->result = 0;
    menu->canCancel = canCancel;
    menu->initialSelection = initialSelection;
    menu->x = x;
    menu->y = y;
    menu->count = 0;
    menu->messageWindow = &system->messageWindow;
    menu->delay = 3;
    menu->listCursorPos = initialSelection;
    for (i = 0; i < FRONTIER_MENU_ITEMS_MAX; i++) {
        menu->menuItems[i].text = NULL;
        menu->menuItems[i].value = 0;
    }
    for (i = 0; i < FRONTIER_MENU_ITEMS_MAX; i++) {
        menu->listItems[i].text = NULL;
        menu->listItems[i].value = 0;
        menu->descriptions[i] = FRONTIER_MENU_NO_DESCRIPTION;
    }
    for (i = 0; i < FRONTIER_MENU_ITEMS_MAX; i++) {
        menu->strings[i] = String_New(80, system->heapId);
    }
    *menu->result = FRONTIER_MENU_RESULT_WAITING;
}

FrontierMenu *FrontierMenu_New(FrontierSystem *system, u8 x, u8 y, u8 initialSelection, u8 canCancel, u16 *result, MessageFormat *msgFormat, MsgData *msgData) {
    FrontierMenu *menu = Heap_Alloc(system->heapId, sizeof(FrontierMenu));
    if (menu == NULL) {
        return NULL;
    }
    memset(menu, 0, sizeof(FrontierMenu));
    FrontierMenu_Init(system, menu, x, y, initialSelection, canCancel, result, msgFormat, msgData);
    return menu;
}

void FrontierMenu_AddItem(FrontierMenu *menu, u16 msgId, u16 description, u16 value) {
    FrontierMenu_AddItemInternal(menu, msgId, description, value);
}

void FrontierMenu_Show(FrontierMenu *menu) {
    u32 width;
    FrontierMap *map;

    map = FrontierSystem_GetFrontierMap(menu->system);
    width = FrontierMenu_GetWidth(menu);
    if ((width & 7) == 0) {
        width >>= 3;
    } else {
        width = (width >> 3) + 1;
    }
    if (menu->alignRight) {
        menu->x -= width;
    }
    if (menu->alignBottom) {
        menu->y -= menu->count * 2;
    }
    AddWindowParameterized(map->bgConfig, &menu->window, GF_BG_LYR_MAIN_1, menu->x, menu->y, width, menu->count * 2, 14, 1);
    DrawFrameAndWindow1(&menu->window, TRUE, 0x3D9, 12);
    FrontierMenu_InitTemplate(menu);
    menu->menu = Create2dMenu(&menu->menuTemplate, menu->initialSelection, (u8)menu->system->heapId);
    FrontierMenu_PrintDescription(menu);
    menu->task = SysTask_CreateOnMainQueue((SysTaskFunc)FrontierMenu_Task, menu, 0);
}

static void FrontierMenu_AddItemInternal(FrontierMenu *menu, u32 msgId, u16 description, u32 value) {
    String *string;

    string = String_New(80, menu->system->heapId);
    ReadMsgDataIntoString(menu->msgData, msgId, string);
    StringExpandPlaceholders(menu->msgFormat, menu->strings[menu->count], string);
    menu->menuItems[menu->count].text = menu->strings[menu->count];
    String_Delete(string);
    menu->descriptions[menu->count] = description;
    menu->menuItems[menu->count].value = value;
    menu->count++;
}

static u32 FrontierMenu_GetWidth(FrontierMenu *menu) {
    u32 width = 0;
    s32 i;

    for (i = 0; i < menu->count; i++) {
        String *string = menu->menuItems[i].text;
        u32 itemWidth;
        if (string == NULL) {
            break;
        }
        itemWidth = FontID_String_GetWidth(0, string, 0);
        if (width < itemWidth) {
            width = itemWidth;
        }
    }
    return width + 12;
}

static void FrontierMenu_InitTemplate(FrontierMenu *menu) {
    menu->menuTemplate.items = menu->menuItems;
    menu->menuTemplate.window = &menu->window;
    menu->menuTemplate.fontId = 0;
    menu->menuTemplate.itemsWide = 1;
    menu->menuTemplate.itemsHigh = menu->count;
    menu->menuTemplate.yTop = 0;
    menu->menuTemplate.cursorType = 0;
    if (menu->count >= 4) {
        menu->menuTemplate.enableWrap = 1;
    } else {
        menu->menuTemplate.enableWrap = 0;
    }
}

static void FrontierMenu_Task(SysTask *task, FrontierMenu *menu) {
    u32 selection;

    if (menu->delay) {
        menu->delay--;
        return;
    }
    if (IsPaletteFadeFinished()) {
        selection = Handle2dMenuInput(menu->menu);
        if (selection == LIST_NOTHING_CHOSEN && System_GetTouchNew() == TRUE) {
            selection = Get2dMenuSelection(menu->menu);
        }
        if ((gSystem.newAndRepeatedKeys & PAD_KEY_UP) || (gSystem.newAndRepeatedKeys & PAD_KEY_DOWN) || (gSystem.newAndRepeatedKeys & PAD_KEY_LEFT) || (gSystem.newAndRepeatedKeys & PAD_KEY_RIGHT)) {
            FrontierMenu_PrintDescription(menu);
        }
        if (*menu->result == FRONTIER_MENU_RESULT_CLOSE) {
            FrontierMenu_Close(menu);
            return;
        }
        switch (selection) {
        case LIST_CANCEL:
            if (menu->canCancel == TRUE) {
                *menu->result = FRONTIER_MENU_RESULT_CANCEL;
                FrontierMenu_Close(menu);
            }
            break;
        case LIST_NOTHING_CHOSEN:
            break;
        default:
            *menu->result = selection;
            FrontierMenu_Close(menu);
            break;
        }
    }
}

static void FrontierMenu_Close(FrontierMenu *menu) {
    FrontierSystem *system = menu->system;
    s32 i;

    PlaySE(SEQ_SE_DP_SELECT);
    Delete2dMenu(menu->menu, NULL);
    EraseFrameAndWindow1(menu->menuTemplate.window, FALSE);
    RemoveWindow(menu->menuTemplate.window);
    for (i = 0; i < FRONTIER_MENU_ITEMS_MAX; i++) {
        String_Delete(menu->strings[i]);
    }
    if (menu->ownsMsgData == TRUE) {
        DestroyMsgData(menu->msgData);
    }
    SysTask_Destroy(menu->task);
    Heap_Free(menu);
    system->menu = NULL;
}

static void FrontierMenu_PrintDescription(FrontierMenu *menu) {
    u32 selection = Get2dMenuSelection(menu->menu);
    u16 description = menu->descriptions[selection];
    if (description != FRONTIER_MENU_NO_DESCRIPTION) {
        FrontierMenu_PrintMessage(menu, description, 0);
    }
}

FrontierMenu *FrontierListMenu_New(FrontierSystem *system, u8 x, u8 y, u8 initialSelection, u8 canCancel, u16 *result, MessageFormat *msgFormat, MsgData *msgData) {
    return FrontierMenu_New(system, x, y, initialSelection, canCancel, result, msgFormat, msgData);
}

void FrontierListMenu_AddItem(FrontierMenu *menu, u16 msgId, u16 description, u16 value) {
    FrontierListMenu_AddItemInternal(menu, msgId, description, value);
}

void FrontierListMenu_Show(FrontierMenu *menu) {
    u32 width;
    FrontierMap *map;

    map = FrontierSystem_GetFrontierMap(menu->system);
    width = FrontierListMenu_GetWidth(menu);
    if ((width & 7) == 0) {
        width >>= 3;
    } else {
        width = (width >> 3) + 1;
    }
    if (menu->alignRight) {
        menu->x -= width;
    }
    if (menu->count > 8) {
        if (menu->alignBottom) {
            menu->y -= 16;
        }
        AddWindowParameterized(map->bgConfig, &menu->window, GF_BG_LYR_MAIN_1, menu->x, menu->y, width, 16, 14, 1);
    } else {
        if (menu->alignBottom) {
            menu->y -= menu->count * 2;
        }
        AddWindowParameterized(map->bgConfig, &menu->window, GF_BG_LYR_MAIN_1, menu->x, menu->y, width, menu->count * 2, 14, 1);
    }
    DrawFrameAndWindow1(&menu->window, TRUE, 0x3D9, 12);
    FrontierListMenu_InitTemplate(menu);
    menu->listMenu = ListMenuInit(&menu->listTemplate, 0, menu->initialSelection, (enum HeapID)(u8)menu->system->heapId);
    FrontierListMenu_PrintDescription(menu);
    menu->task = SysTask_CreateOnMainQueue((SysTaskFunc)FrontierListMenu_Task, menu, 0);
}

// value 0xFA adds a header line (value -3, printed in other colors).
static void FrontierListMenu_AddItemInternal(FrontierMenu *menu, u32 msgId, u16 description, u32 value) {
    String *string;
    u8 count;

    string = String_New(80, menu->system->heapId);
    ReadMsgDataIntoString(menu->msgData, msgId, string);
    StringExpandPlaceholders(menu->msgFormat, menu->strings[menu->count], string);
    count = menu->count;
    menu->listItems[count].text = menu->strings[count];
    String_Delete(string);
    if (value == 0xFA) {
        menu->listItems[menu->count].value = LIST_HEADER;
    } else {
        menu->listItems[menu->count].value = value;
    }
    menu->descriptions[menu->count] = description;
    menu->count++;
}

static u32 FrontierListMenu_GetWidth(FrontierMenu *menu) {
    u32 width = 0;
    s32 i;

    for (i = 0; i < menu->count; i++) {
        String *string = menu->listItems[i].text;
        u32 itemWidth;
        if (string == NULL) {
            break;
        }
        itemWidth = FontID_String_GetWidth(0, string, 0);
        if (width < itemWidth) {
            width = itemWidth;
        }
    }
    return width + 12;
}

static void FrontierListMenu_InitTemplate(FrontierMenu *menu) {
    menu->listTemplate.items = menu->listItems;
    menu->listTemplate.moveCursorFunc = (LM_MoveCursorFunc_t)FrontierListMenu_MoveCursorCallback;
    menu->listTemplate.itemPrintFunc = FrontierListMenu_PrintItem;
    menu->listTemplate.window = &menu->window;
    menu->listTemplate.totalItems = menu->count;
    menu->listTemplate.maxShowed = 8;
    menu->listTemplate.header_X = 1;
    menu->listTemplate.item_X = 12;
    menu->listTemplate.cursor_X = 2;
    menu->listTemplate.upText_Y = 1;
    menu->listTemplate.cursorPal = 1;
    menu->listTemplate.fillValue = 15;
    menu->listTemplate.cursorShadowPal = 2;
    menu->listTemplate.lettersSpacing = 0;
    menu->listTemplate.itemVerticalPadding = 0;
    menu->listTemplate.scrollMultiple = 0;
    menu->listTemplate.fontId = 0;
    menu->listTemplate.cursorKind = 0;
    menu->listTemplate.data = menu;
}

static void FrontierListMenu_PrintItem(ListMenu *list, s32 value, u8 onInit) {
    if (value == LIST_HEADER) {
        ListMenuOverrideSetColors(list, 3, 15, 4);
    } else {
        ListMenuOverrideSetColors(list, 1, 15, 2);
    }
}

static u32 FrontierListMenu_MoveCursorCallback(ListMenu *list) {
    return ListMenuGetTemplateField(list, (enum ListMenuAttr)19);
}

static void FrontierListMenu_Task(SysTask *task, FrontierMenu *menu) {
    s32 selection;
    u16 prevPos;

    if (menu->delay != 0) {
        menu->delay--;
        return;
    }
    if (IsPaletteFadeFinished()) {
        selection = ListMenu_ProcessInput(menu->listMenu);
        prevPos = menu->listCursorPos;
        ListMenuGetCurrentItemArrayId(menu->listMenu, &menu->listCursorPos);
        if (prevPos != menu->listCursorPos) {
            PlaySE(SEQ_SE_DP_SELECT);
        }
        if ((gSystem.newAndRepeatedKeys & PAD_KEY_UP) || (gSystem.newAndRepeatedKeys & PAD_KEY_DOWN) || (gSystem.newAndRepeatedKeys & PAD_KEY_LEFT) || (gSystem.newAndRepeatedKeys & PAD_KEY_RIGHT)) {
            FrontierListMenu_PrintDescription(menu);
        }
        if (selection == LIST_NOTHING_CHOSEN && System_GetTouchNew() == TRUE) {
            selection = ListMenuGetValueByArrayId(menu->listMenu, menu->listCursorPos);
        }
        if (*menu->result == FRONTIER_MENU_RESULT_CLOSE) {
            FrontierListMenu_Close(menu, FALSE);
            return;
        }
        switch (selection) {
        case LIST_CANCEL:
            if (menu->canCancel == TRUE) {
                PlaySE(SEQ_SE_DP_SELECT);
                *menu->result = FRONTIER_MENU_RESULT_CANCEL;
                FrontierListMenu_Close(menu, TRUE);
                return;
            }
            break;
        case LIST_NOTHING_CHOSEN:
            break;
        default:
            PlaySE(SEQ_SE_DP_SELECT);
            *menu->result = selection;
            FrontierListMenu_Close(menu, TRUE);
            break;
        }
    }
}

static void FrontierListMenu_Close(FrontierMenu *menu, BOOL playSound) {
    int i;
    FrontierSystem *system = menu->system;

    if (playSound == TRUE) {
        PlaySE(SEQ_SE_DP_SELECT);
    }
    DestroyListMenu(menu->listMenu, NULL, NULL);
    EraseFrameAndWindow1(menu->listTemplate.window, FALSE);
    RemoveWindow(&menu->window);
    for (i = 0; i < FRONTIER_MENU_ITEMS_MAX; i++) {
        String_Delete(menu->strings[i]);
    }
    if (menu->ownsMsgData == TRUE) {
        DestroyMsgData(menu->msgData);
    }
    SysTask_Destroy(menu->task);
    Heap_Free(menu);
    system->menu = NULL;
}

static void FrontierMenu_PrintMessage(FrontierMenu *menu, u16 msgId, u32 speed) {
    String *raw;
    String *expanded;

    raw = String_New(80, menu->system->heapId);
    expanded = String_New(80, menu->system->heapId);
    FillWindowPixelBuffer(menu->messageWindow, 15);
    ReadMsgDataIntoString(menu->msgData, msgId, raw);
    StringExpandPlaceholders(menu->msgFormat, expanded, raw);
    AddTextPrinterParameterized(menu->messageWindow, 1, expanded, 0, 0, speed, NULL);
    String_Delete(raw);
    String_Delete(expanded);
}

static void FrontierListMenu_PrintDescription(FrontierMenu *menu) {
    u16 description;

    ListMenuGetCurrentItemArrayId(menu->listMenu, &menu->listCursor);
    description = menu->descriptions[menu->listCursor];
    if (description != FRONTIER_MENU_NO_DESCRIPTION) {
        FrontierMenu_PrintMessage(menu, description, 0);
    }
}

void FrontierListMenu_Cancel(FrontierMenu *menu) {
    if (menu) {
        *menu->result = FRONTIER_MENU_RESULT_CANCEL;
        FrontierListMenu_Close(menu, FALSE);
    }
}

enum {
    MOVEMENT_TASK_CHECK_END,
    MOVEMENT_TASK_RUN,
    MOVEMENT_TASK_FINISH,
};

// Runs a movement script on a map object: (opcode, count) pairs ending with 0xFD13; opcodes 0x20-0x26 wait,
// 0x27/0x28 turn the object's sprite flag on/off, the others are steps (Field2DMoveQueue_Push) repeated count times.
void FrontierScript_MovementTask(SysTask *task, FrontierMovementTask *data) {
    Field2DMove step;
    u16 opcode = data->script[0];
    u16 count = data->script[1];

    switch (data->state) {
    case MOVEMENT_TASK_CHECK_END:
        if (opcode == 0xFD13) {
            data->state = MOVEMENT_TASK_FINISH;
            return;
        }
    case MOVEMENT_TASK_RUN:
        if (Field2DObject_GetParam(data->object->object, FIELD2D_OBJECT_PARAM_ACTION) != 0) {
            return;
        }
        if (opcode >= 0x20 && opcode <= 0x26) {
            data->wait++;
            if (data->wait >= sFrontierMovementWaitFrames[opcode - 0x20]) {
                data->wait = 0;
                data->script += 2;
                return;
            }
            return;
        }
        if (opcode >= 0x27 && opcode < 0x29) {
            switch (opcode) {
            case 0x27:
                Field2DObjectSprite_SetVisible(data->object->objectSprite, 1);
                break;
            case 0x28:
                Field2DObjectSprite_SetVisible(data->object->objectSprite, 0);
                break;
            default:
                GF_ASSERT(FALSE);
                break;
            }
            data->script += 2;
            return;
        }
        FrontierScript_GetMovementStep(&step, data->object->object, data->id, opcode);
        Field2DMoveQueue_Push(data->moveQueue, &step);
        data->repeat++;
        if (data->repeat >= count) {
            data->repeat = 0;
            data->script += 2;
        }
        data->state = MOVEMENT_TASK_CHECK_END;
        return;
    case MOVEMENT_TASK_FINISH:
        if (Field2DObject_GetParam(data->object->object, FIELD2D_OBJECT_PARAM_ACTION) == 0) {
            (*data->runningCount)--;
            data->object->movementTask = NULL;
            Heap_Free(data);
            SysTask_Destroy(task);
        }
        return;
    }
}

void FrontierScript_GetMovementStep(Field2DMove *step, Field2DObject *object, u16 id, s32 opcode) {
    step->objectId = id;
    step->direction = sFrontierMovementSteps[opcode][1];
    step->action = sFrontierMovementSteps[opcode][0];
    if (step->action == 2 || step->action == 3 || step->action == 6) {
        volatile u16 position[2];
        u32 raw = ((FrontierObjectGetPosFunc)Field2DObject_GetPrevPos)(object);
        position[0] = raw;
        position[1] = raw >> 16;
        step->startPos.x = position[0];
        step->startPos.y = position[1];
        return;
    } else {
        volatile u16 position[2];
        u32 raw = ((FrontierObjectGetPosFunc)Field2DObject_GetPos)(object);
        position[0] = raw;
        position[1] = raw >> 16;
        step->startPos.x = position[0];
        step->startPos.y = position[1];
    }
}

// Creates the battle sprite of a Pokemon as a map sprite (resource id id, slot id - 50000).
void FrontierMap_CreateMonSprite(FrontierMap *map, Pokemon *mon, enum HeapID heapId, int id, int x, int y, int drawPriority, int bgPriority, int blend, u16 blendColor) {
    PaletteData *paletteData = map->paletteData;
    SpriteSystem *spriteSystem = map->spriteSystem;
    SpriteManager *spriteManager = map->spriteManager;
    NARC *narc = NARC_New(NARC_a_0_0_8, heapId);
    PokepicTemplate pokepic;
    ManagedSpriteTemplate template;
    ManagedSprite *sprite;
    void *buffer;
    u32 personality;
    int species, i;
    NNSG2dImageProxy *image;
    u32 offset;

    SpriteSystem_LoadCharResObjFromOpenNarc(spriteSystem, spriteManager, narc, 112, FALSE, NNS_G2D_VRAM_TYPE_2DMAIN, id);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(paletteData, PLTTBUF_MAIN_OBJ, spriteSystem, spriteManager, narc, 111, FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, id);
    SpriteSystem_LoadCellResObjFromOpenNarc(spriteSystem, spriteManager, narc, 113, FALSE, id);
    SpriteSystem_LoadAnimResObjFromOpenNarc(spriteSystem, spriteManager, narc, 114, FALSE, id);
    NARC_Delete(narc);
    MI_CpuFill8(&template, 0, sizeof(template));
    template.x = x;
    template.y = y;
    template.z = 0;
    template.animation = 0;
    template.drawPriority = drawPriority;
    template.pal = 0;
    template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.bgPriority = bgPriority;
    template.vramTransfer = FALSE;
    for (i = 0; i < 6; i++) {
        template.resIdList[i] = id;
    }
    sprite = SpriteSystem_NewSprite(spriteSystem, spriteManager, &template);
    ManagedSprite_TickFrame(sprite);
    buffer = Heap_Alloc(heapId, 3200);
    personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    GetPokemonSpriteCharAndPlttNarcIds(&pokepic, mon, 2);
    CharTiles_LoadMonObjBlocksFromNarc((NarcId)pokepic.narcID, pokepic.charDataID, heapId, 0, 0, 10, 10, buffer, personality, FALSE, 2, species);
    image = Sprite_GetImageProxy(sprite->sprite);
    DC_FlushRange(buffer, 4);
    GX_LoadOBJ(buffer, image->vramLocation.baseAddrOfVram[NNS_G2D_VRAM_TYPE_2DMAIN], 3200);
    offset = ObjPlttTransfer_GetPaletteVramOffset(Sprite_GetPaletteProxy(sprite->sprite), NNS_G2D_VRAM_TYPE_2DMAIN) * 16;
    PaletteData_LoadNarc(paletteData, (NarcId)pokepic.narcID, pokepic.palDataID, heapId, PLTTBUF_MAIN_OBJ, 32, offset);
    if (blend > 0) {
        PaletteData_BlendPalette(paletteData, PLTTBUF_MAIN_OBJ, offset, 16, blend, blendColor);
    }
    Heap_Free(buffer);
    GF_ASSERT(map->monSprites[id - FRONTIER_MON_SPRITE_ID_BASE] == NULL);
    map->monSprites[id - FRONTIER_MON_SPRITE_ID_BASE] = sprite;
}

void FrontierMap_DeleteMonSprite(FrontierMap *map, u32 id) {
    u32 index = id - FRONTIER_MON_SPRITE_ID_BASE;
    Sprite_DeleteAndFreeResources(map->monSprites[index]);
    map->monSprites[index] = NULL;
    SpriteManager_UnloadCharObjById(map->spriteManager, id);
    SpriteManager_UnloadPlttObjById(map->spriteManager, id);
    SpriteManager_UnloadCellObjById(map->spriteManager, id);
    SpriteManager_UnloadAnimObjById(map->spriteManager, id);
}

void FrontierMap_LoadMonIconResources(FrontierMap *map) {
    SpriteSystem_LoadPaletteBuffer(map->paletteData, PLTTBUF_MAIN_OBJ, map->spriteSystem, map->spriteManager, NARC_poketool_icongra_poke_icon, GetMonIconPlttNaix(), FALSE, 3, NNS_G2D_VRAM_TYPE_2DMAIN, FRONTIER_MON_ICON_ID_BASE);
    SpriteSystem_LoadCellResObj(map->spriteSystem, map->spriteManager, NARC_poketool_icongra_poke_icon, GetMonIconCell32KNaix(), FALSE, FRONTIER_MON_ICON_ID_BASE);
    SpriteSystem_LoadAnimResObj(map->spriteSystem, map->spriteManager, NARC_poketool_icongra_poke_icon, GetMonIconAnim32KNaix(), FALSE, FRONTIER_MON_ICON_ID_BASE);
}

void FrontierMap_UnloadMonIconResources(FrontierMap *map) {
    SpriteManager_UnloadCellObjById(map->spriteManager, FRONTIER_MON_ICON_ID_BASE);
    SpriteManager_UnloadAnimObjById(map->spriteManager, FRONTIER_MON_ICON_ID_BASE);
    SpriteManager_UnloadPlttObjById(map->spriteManager, FRONTIER_MON_ICON_ID_BASE);
}

ManagedSprite *FrontierMap_CreateMonIcon(FrontierMap *map, Pokemon *mon, s32 index, s32 x, s32 y) {
    ManagedSpriteTemplate template;
    ManagedSprite *sprite;

    GF_ASSERT(index < 8);
    SpriteSystem_LoadCharResObjAtEndWithHardwareMappingType(map->spriteSystem, map->spriteManager, NARC_poketool_icongra_poke_icon, Pokemon_GetIconNaix(mon), FALSE, NNS_G2D_VRAM_TYPE_2DMAIN, index + FRONTIER_MON_ICON_ID_BASE);
    template = sFrontierMapMonIconTemplate;
    template.resIdList[GF_GFX_RES_TYPE_CHAR] += index;
    template.x = x;
    template.y = y;
    template.drawPriority = 200;
    sprite = SpriteSystem_NewSprite(map->spriteSystem, map->spriteManager, &template);
    Sprite_SetPalOffsetRespectVramOffset(sprite->sprite, Pokemon_GetIconPalette(mon));
    ManagedSprite_TickFrame(sprite);
    return sprite;
}

void FrontierMap_DeleteMonIcon(FrontierMap *map, ManagedSprite *sprite, u32 index) {
    SpriteManager_UnloadCharObjById(map->spriteManager, index + FRONTIER_MON_ICON_ID_BASE);
    Sprite_DeleteAndFreeResources(sprite);
}

void FrontierMap_LoadItemIconResources(FrontierMap *map) {
    NARC *narc = NARC_New(NARC_graphic_plist_gra, HEAP_ID_101);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(map->paletteData, PLTTBUF_MAIN_OBJ, map->spriteSystem, map->spriteManager, narc, PartyMenu_GetHeldItemIconNCLR(), FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 0x7D1);
    SpriteSystem_LoadCellResObjFromOpenNarc(map->spriteSystem, map->spriteManager, narc, PartyMenu_GetHeldItemIconNCER(), FALSE, 0x7D1);
    SpriteSystem_LoadAnimResObjFromOpenNarc(map->spriteSystem, map->spriteManager, narc, PartyMenu_GetHeldItemIconNANR(), FALSE, 0x7D1);
    SpriteSystem_LoadCharResObjAtEndWithHardwareMappingType(map->spriteSystem, map->spriteManager, NARC_graphic_plist_gra, PartyMenu_GetHeldItemIconNCGR(), FALSE, NNS_G2D_VRAM_TYPE_2DMAIN, 0x7D9);
    NARC_Delete(narc);
}

void FrontierMap_UnloadItemIconResources(FrontierMap *map) {
    SpriteManager_UnloadCharObjById(map->spriteManager, 0x7D9);
    SpriteManager_UnloadCellObjById(map->spriteManager, 0x7D1);
    SpriteManager_UnloadAnimObjById(map->spriteManager, 0x7D1);
    SpriteManager_UnloadPlttObjById(map->spriteManager, 0x7D1);
}

ManagedSprite *FrontierMap_CreateItemIcon(FrontierMap *map, int x, int y) {
    ManagedSpriteTemplate template = sFrontierMapItemIconTemplate;
    ManagedSprite *sprite;

    template.x = x;
    template.y = y;
    template.drawPriority = 300;
    sprite = SpriteSystem_NewSprite(map->spriteSystem, map->spriteManager, &template);
    ManagedSprite_TickFrame(sprite);
    return sprite;
}

void FrontierMap_DeleteItemIcon(FrontierMap *map, ManagedSprite *sprite) {
    Sprite_DeleteAndFreeResources(sprite);
}

void FrontierScript_PrintMessageEntry(FrontierScriptContext *ctx, const u16 *entry) {
    FrontierScript_PrintMessageEntryFromBank(ctx, entry, NARC_msg_msg_0724_bin);
}

// entry: (0xFFFF, msgId) prints message msgId of the bank; otherwise (mail bank, number, field 0, field 1) prints
// that mail message.
void FrontierScript_PrintMessageEntryFromBank(FrontierScriptContext *ctx, const u16 *entry, u32 bank) {
    FrontierLaunchArgs *args;

    args = Frontier_GetLaunchArgs(ctx->frontierSystem->frontierWork);
    if (entry[0] == 0xFFFF) {
        MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, bank, HEAP_ID_FIELD3);
        FrontierSystem_PrintMessage(ctx->frontierSystem, msgData, entry[1], TRUE, NULL);
        DestroyMsgData(msgData);
    } else {
        u32 speed = Options_GetTextFrameDelay(Save_PlayerData_GetOptionsAddr(args->saveData));
        ((FrontierPrintMailMessageFunc)FrontierSystem_PrintMailMessage)(ctx->frontierSystem, speed, entry[0], entry[1], entry[2], (s16)entry[3], TRUE);
    }
    FrontierScriptContext_Pause(ctx, FrontierScriptNative_WaitMessageEntry);
}

static BOOL FrontierScriptNative_WaitMessageEntry(FrontierScriptContext *ctx) {
    if (!TextPrinterCheckActive(ctx->frontierSystem->textPrinterId)) {
        TextFlags_SetCanTouchSpeedUpPrint(FALSE);
        return TRUE;
    }
    return FALSE;
}

// Tasks of the frontier map's shake (FrtCmd_ShakeMap) and window (FrtCmd_SetWindowDelayed) commands, and the menu alignment flags
// (FrtCmd_MenuSetAlignRight/MenuSetAlignBottom).

void FrontierMap_ShakeTask(SysTask *task, FrontierMapShake *shake) {
    shake->frame++;
    if (shake->frame > shake->interval) {
        shake->frame = 0;
        shake->count--;
        if (shake->count < 0) {
            SysTask_Destroy(task);
            MI_CpuFill8(shake, 0, sizeof(FrontierMapShake));
            return;
        }
        shake->x = -shake->x;
        shake->y = -shake->y;
    }
}

void FrontierMap_WindowTask(SysTask *task, FrontierMapWindowTask *data) {
    if (data->delay <= 0) {
        if (data->enable == TRUE) {
            G2_SetWnd0InsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3, TRUE);
            G2_SetWndOutsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, TRUE);
            G2_SetWnd0Position(data->left, data->top, data->right, data->bottom);
            GX_SetVisibleWnd(GX_WNDMASK_W0);
        } else {
            GX_SetVisibleWnd(GX_WNDMASK_NONE);
        }
        SysTask_Destroy(task);
        MI_CpuFill8(data, 0, sizeof(FrontierMapWindowTask));
    } else {
        data->delay--;
    }
}

void FrontierMenu_SetAlignRight(FrontierMenu *menu, int value) {
    menu->alignRight = value;
}

void FrontierMenu_SetAlignBottom(FrontierMenu *menu, int value) {
    menu->alignBottom = value;
}
