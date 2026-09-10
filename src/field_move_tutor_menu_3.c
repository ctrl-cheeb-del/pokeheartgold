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

void ov01_021EE014(MoveTutorMenu *menu, u16 a1) {
    ov01_021EE01C(menu, a1);
}

void ov01_021EE01C(MoveTutorMenu *menu, u16 a1) {
    if (menu->count > 8) {
        AddWindowParameterized(menu->fieldSystem->bgConfig, &menu->window, 3, menu->x, menu->y, (u8)a1, 16, 13, 0x3D);
    } else {
        AddWindowParameterized(menu->fieldSystem->bgConfig, &menu->window, 3, menu->x, menu->y, (u8)a1, (u8)(menu->count * 2), 13, 0x3D);
    }
    LoadUserFrameGfx1(menu->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 0x3D9, 11, 0, HEAP_ID_FIELD1);
    DrawFrameAndWindow1(&menu->window, 1, 0x3D9, 11);
    ov01_021EE324(menu);
    menu->listMenu = ListMenuInit(&menu->listTemplate, 0, menu->initCursorPos, HEAP_ID_FIELD1);
    ov01_021EE634(menu);
    menu->task = SysTask_CreateOnMainQueue((SysTaskFunc)ov01_021EE49C, menu, 0);
}
