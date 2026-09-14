#include "field_move_tutor_menu_internal.h"
#include "render_window.h"

u32 ov01_021EDDD8(MoveTutorMenu *menu);
void ov01_021EDE8C(SysTask *task, MoveTutorMenu *menu);
void ov01_021EEA44(MoveTutorMenu *menu, u8 wide, u8 high);
Window *FieldSystem_ShowMoneyBox(FieldSystem *fieldSystem, u8 x, u8 y);

void ov01_021EE974(MoveTutorMenu *menu, u8 divisor) {
    u32 width;
    int rows;
    u8 columns;

    width = ov01_021EDDD8(menu);
    if ((width & 7) == 0) {
        rows = width >> 3;
    } else {
        rows = (width >> 3) + 1;
    }
    columns = menu->count / divisor;
    if (menu->count % divisor) {
        columns++;
    }
    AddWindowParameterized(menu->fieldSystem->bgConfig, &menu->window, GF_BG_LYR_MAIN_3, menu->x, menu->y, (u8)(rows * divisor), (u8)(columns * 2), 13, 0x3D);
    LoadUserFrameGfx1(menu->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 0x3D9, 11, 0, HEAP_ID_FIELD1);
    DrawFrameAndWindow1(&menu->window, TRUE, 0x3D9, 11);
    ov01_021EEA44(menu, divisor, columns);
    menu->menu2dPtr = Create2dMenu(&menu->menu2d, menu->initCursorPos, HEAP_ID_FIELD1);
    menu->task = SysTask_CreateOnMainQueue((SysTaskFunc)ov01_021EDE8C, menu, 0);
}

void ov01_021EEA44(MoveTutorMenu *menu, u8 wide, u8 high) {
    menu->menu2d.items = (ListMenuItem *)menu->entries;
    menu->menu2d.window = &menu->window;
    menu->menu2d.fontId = 0;
    menu->menu2d.itemsWide = wide;
    menu->menu2d.itemsHigh = high;
    menu->menu2d.yTop = 0;
    menu->menu2d.cursorType = 0;
}

Window *FieldSystem_ShowMoneyBox(FieldSystem *fieldSystem, u8 x, u8 y) {
    Window *window;
    MsgData *msgData;
    String *string;

    window = AllocWindows(HEAP_ID_FIELD1, 1);
    AddWindowParameterized(fieldSystem->bgConfig, window, GF_BG_LYR_MAIN_3, x, y, 10, 4, 13, 1);
    LoadUserFrameGfx1(fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 0x3D9, 11, 0, HEAP_ID_FIELD1);
    DrawFrameAndWindow1(window, TRUE, 0x3D9, 11);
    FillWindowPixelBuffer(window, 15);
    msgData = NewMsgDataFromNarc((MsgDataLoadType)0, NARC_msgdata_msg, 0x1B3, HEAP_ID_FIELD1);
    string = NewString_ReadMsgData(msgData, 30);
    AddTextPrinterParameterized(window, 0, string, 0, 0, 0xFF, 0);
    DestroyMsgData(msgData);
    String_Delete(string);
    MoneyBoxSys_Update(fieldSystem, window);
    return window;
}
