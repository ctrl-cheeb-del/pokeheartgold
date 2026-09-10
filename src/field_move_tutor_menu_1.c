#include "field_move_tutor_menu_internal.h"

void ov01_021EDAFC(FieldSystem *fieldSystem, MoveTutorMenu *menu, u8 x, u8 y, u8 initCursorPos, u8 cancellable, u16 *ret_p, MessageFormat *msgFmt, Window *window, MsgData *msgData);
MoveTutorMenu *ov01_021EDC28(FieldSystem *fieldSystem, u8 x, u8 y, u8 initCursorPos, u8 cancellable, u16 *ret_p, MessageFormat *msgFmt, Window *window, MsgData *msgData);
void ov01_021EDD68(MoveTutorMenu *menu, u32 msgId, u32 value);
u32 ov01_021EDDD8(MoveTutorMenu *menu);
void ov01_021EDE18(MoveTutorMenu *menu);
void ov01_021EDE8C(SysTask *task, MoveTutorMenu *menu);
void ov01_021EE01C(MoveTutorMenu *menu, u16 a1);
void MoveTutorMenu_SetListItem_Internal(MoveTutorMenu *menu, int msgId, int a2, int value);
u32 ov01_021EE2E4(MoveTutorMenu *menu);
void ov01_021EE324(MoveTutorMenu *menu);
void ov01_021EE434(MoveTutorMenu *menu, s32 itemId, u8 onInit);
void ov01_021EE458(ListMenu *listMenu, s32 itemId, u8 onInit);
void ov01_021EE49C(SysTask *task, MoveTutorMenu *menu);
void ov01_021EE568(MoveTutorMenu *menu);
void ov01_021EE5D0(MoveTutorMenu *menu, u32 msgId, u32 a2);
void ov01_021EE634(MoveTutorMenu *menu);
void ov01_021EE754(MoveTutorMenu *menu, u32 msgId, u32 x, u32 y);
void ov01_021EE7B8(SysTask *task, MoveTutorMenu *menu);

void ov01_021EDAFC(FieldSystem *fieldSystem, MoveTutorMenu *menu, u8 x, u8 y, u8 initCursorPos, u8 cancellable, u16 *ret_p, MessageFormat *msgFmt, Window *window, MsgData *msgData) {
    int i;

    if (msgData == NULL) {
        menu->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, 191, HEAP_ID_FIELD1);
        menu->ownMsgData = TRUE;
    } else {
        menu->msgData = msgData;
        menu->ownMsgData = FALSE;
    }
    menu->msgFmt = msgFmt;
    menu->fieldSystem = fieldSystem;
    menu->ret_p = ret_p;
    menu->scroll_p = NULL;
    menu->row_p = NULL;
    menu->cancellable = cancellable;
    menu->initCursorPos = initCursorPos;
    menu->unk_97_6 = 0;
    menu->unk_97_7 = 0;
    menu->x = x;
    menu->y = y;
    menu->count = 0;
    menu->printWindow = window;
    menu->delay = 3;
    menu->lastRow = initCursorPos;
    for (i = 0; i < 28; i++) {
        menu->entries[i].text = NULL;
        menu->entries[i].value = 0;
    }
    for (i = 0; i < 28; i++) {
        menu->items[i].text = NULL;
        menu->items[i].value = 0;
        menu->msgIds[i] = 0xFF;
    }
    for (i = 0; i < 28; i++) {
        menu->strbufs[i] = String_New(80, HEAP_ID_FIELD1);
    }
    *menu->ret_p = 0xEEEE;
}

MoveTutorMenu *ov01_021EDC28(FieldSystem *fieldSystem, u8 x, u8 y, u8 initCursorPos, u8 cancellable, u16 *ret_p, MessageFormat *msgFmt, Window *window, MsgData *msgData) {
    MoveTutorMenu *menu = Heap_Alloc(HEAP_ID_FIELD1, sizeof(MoveTutorMenu));
    if (menu == NULL) {
        return NULL;
    }
    memset(menu, 0, sizeof(MoveTutorMenu));
    ov01_021EDAFC(fieldSystem, menu, x, y, initCursorPos, cancellable, ret_p, msgFmt, window, msgData);
    return menu;
}

void ov01_021EDC7C(MoveTutorMenu *menu, u32 msgId, u32 value) {
    ov01_021EDD68(menu, msgId, value);
}

void ov01_021EDC84(MoveTutorMenu *menu) {
    u32 width;

    width = ov01_021EDDD8(menu);
    if ((width & 7) == 0) {
        width = width >> 3;
    } else {
        width = (width >> 3) + 1;
    }
    if (menu->unk_97_6) {
        menu->x -= width;
    }
    if (menu->unk_97_7) {
        menu->y -= menu->count * 2;
    }
    AddWindowParameterized(menu->fieldSystem->bgConfig, &menu->window, 3, menu->x, menu->y, (u8)width, (u8)(menu->count * 2), 13, 0x3D);
    LoadUserFrameGfx1(menu->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 0x3D9, 11, 0, HEAP_ID_FIELD1);
    DrawFrameAndWindow1(&menu->window, 1, 0x3D9, 11);
    ov01_021EDE18(menu);
    menu->menu2dPtr = Create2dMenu(&menu->menu2d, menu->initCursorPos, HEAP_ID_FIELD1);
    menu->task = SysTask_CreateOnMainQueue((SysTaskFunc)ov01_021EDE8C, menu, 0);
}

void ov01_021EDD68(MoveTutorMenu *menu, u32 msgId, u32 value) {
    String *tmp = String_New(80, HEAP_ID_FIELD1);
    ReadMsgDataIntoString(menu->msgData, msgId, tmp);
    StringExpandPlaceholders(menu->msgFmt, menu->strbufs[menu->count], tmp);
    menu->entries[menu->count].text = menu->strbufs[menu->count];
    String_Delete(tmp);
    menu->entries[menu->count].value = value;
    menu->count++;
}

u32 ov01_021EDDD8(MoveTutorMenu *menu) {
    u32 maxWidth = 0;
    int i;

    for (i = 0; i < menu->count; i++) {
        if (menu->entries[i].text == NULL) {
            break;
        }
        {
            u32 width = FontID_String_GetWidth(0, menu->entries[i].text, 0);
            if (maxWidth < width) {
                maxWidth = width;
            }
        }
    }
    return maxWidth + 12;
}

void ov01_021EDE18(MoveTutorMenu *menu) {
    menu->menu2d.items = (ListMenuItem *)menu->entries;
    menu->menu2d.window = &menu->window;
    menu->menu2d.fontId = 0;
    menu->menu2d.itemsWide = 1;
    menu->menu2d.itemsHigh = menu->count;
    menu->menu2d.yTop = 0;
    menu->menu2d.cursorType = 0;
    if (menu->count >= 4) {
        menu->menu2d.enableWrap = 1;
    } else {
        menu->menu2d.enableWrap = 0;
    }
}
