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

void MoveTutorMenu_SetListItem_Internal(MoveTutorMenu *menu, int msgId, int a2, int value) {
    String *tmp = String_New(80, HEAP_ID_FIELD1);
    ReadMsgDataIntoString(menu->msgData, msgId, tmp);
    StringExpandPlaceholders(menu->msgFmt, menu->strbufs[menu->count], tmp);
    menu->items[menu->count].text = menu->strbufs[menu->count];
    String_Delete(tmp);
    if (value == 0xFA) {
        menu->items[menu->count].value = -3;
    } else {
        menu->items[menu->count].value = value;
    }
    menu->msgIds[menu->count] = a2;
    menu->count++;
}

u32 ov01_021EE2E4(MoveTutorMenu *menu) {
    u32 maxWidth = 0;
    int i;

    for (i = 0; i < menu->count; i++) {
        if (menu->items[i].text == NULL) {
            break;
        }
        {
            u32 width = FontID_String_GetWidth(0, menu->items[i].text, 0);
            if (maxWidth < width) {
                maxWidth = width;
            }
        }
    }
    return maxWidth + 12;
}

void ov01_021EE324(MoveTutorMenu *menu) {
    menu->listTemplate.items = menu->items;
    menu->listTemplate.moveCursorFunc = (LM_MoveCursorFunc_t)ov01_021EE458;
    menu->listTemplate.itemPrintFunc = (LM_ItemPrintFunc_t)ov01_021EE434;
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
    menu->listTemplate.scrollMultiple = 1;
    menu->listTemplate.fontId = 0;
    menu->listTemplate.cursorKind = 0;
    menu->listTemplate.data = menu;
}

void ov01_021EE434(MoveTutorMenu *menu, s32 itemId, u8 onInit) {
    if (itemId == -3) {
        ListMenuOverrideSetColors((ListMenu *)menu, 3, 15, 4);
    } else {
        ListMenuOverrideSetColors((ListMenu *)menu, 1, 15, 2);
    }
}

void ov01_021EE458(ListMenu *listMenu, s32 itemId, u8 onInit) {
    u16 row;
    u16 scroll;
    MoveTutorMenu *menu;

    row = 0;
    scroll = 0;
    menu = (MoveTutorMenu *)ListMenuGetTemplateField(listMenu, (enum ListMenuAttr)0x13);
    ListMenuGetScrollAndRow(listMenu, &row, &scroll);
    if (menu->scroll_p != NULL && menu->row_p != NULL) {
        *menu->scroll_p = row;
        *menu->row_p = scroll;
    }
}
