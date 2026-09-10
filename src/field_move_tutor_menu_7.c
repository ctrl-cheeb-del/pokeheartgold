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

int ov01_021EE934(u32 mapId, int a1, u8 *width_p) {
    switch (mapId) {
    case 0x1B9:
        if (a1 == 0) {
            *width_p = 0x20;
            return 0x7A;
        }
        break;
    case 0x1BB:
    case 0x1BC:
        if (a1 == 3) {
            *width_p = 0x10;
            return 0x7D;
        }
        break;
    }
    *width_p = 0x20;
    return 0x11;
}
