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

ListMenuItem *ov01_021EEF58(MoveTutorMenu *menu) {
    return menu->items;
}

u8 ov01_021EEF60(MoveTutorMenu *menu) {
    return menu->count;
}

Window *ov01_021EEF68(FieldSystem *fieldSystem, u16 a1) {
    Window *windows = AllocWindows(HEAP_ID_FIELD1, 1);
    ov03_02256730(fieldSystem, windows, a1);
    return windows;
}

void ov01_021EEF88(Window *window) {
    sub_0200E5D4(window, 0);
    WindowArray_Delete(window, 1);
}

void ov01_021EEF9C(MoveTutorMenu *menu, int idx) {
    String *tmp;
    String *dest;

    if (menu->msgIds[idx] == 0xFF) {
        return;
    }
    tmp = String_New(90, HEAP_ID_FIELD1);
    dest = String_New(90, HEAP_ID_FIELD1);
    FillWindowPixelBuffer(menu->printWindow, 15);
    ReadMsgDataIntoString(menu->msgData, menu->msgIds[idx], tmp);
    StringExpandPlaceholders(menu->msgFmt, dest, tmp);
    AddTextPrinterParameterized(menu->printWindow, 1, dest, 0, 0, 0, 0);
    String_Delete(tmp);
    String_Delete(dest);
}

u8 ov01_021EF00C(MoveTutorMenu *menu) {
    return menu->cancellable;
}
