#include "overlay43_scene_helpers_private.h"

void ov43_0222B440(u32 *selection, u8 *work) {
    ov43_0222A318(work, ov43_0222F0CC[*selection], 0);
}

void ov43_0222B458(u8 *windowState, u8 *work) {
    ov43_0222AA70(work);
    FillBgTilemapRect(*(void **)work, 2, 0, 0, 0, 0x20, 0x18, 0);
    ScheduleBgTilemapBufferTransfer(*(void **)work, 2);
    FillBgTilemapRect(*(void **)work, 3, 0, 0, 0, 0x20, 0x18, 0);
    ScheduleBgTilemapBufferTransfer(*(void **)work, 3);
    ClearWindowTilemapAndScheduleTransfer((Window *)(windowState + 8));
    ov43_0222AD74(work, 0, 0xFF);
}

void ov43_0222B4BC(u8 *state, u8 *work, int msgNo, int heapId) {
    String *temp = String_New(0x80, (enum HeapID)heapId);
    FillWindowPixelBuffer((Window *)(state + 0x20), 0xF);
    ReadMsgDataIntoString(*(MsgData **)(work + 0x54), msgNo, temp);
    StringExpandPlaceholders(*(MessageFormat **)(work + 0x50), *(String **)(state + 0x3C), temp);
    TextFlags_SetCanTouchSpeedUpPrint(TRUE);
    *(u32 *)(state + 0x34) = AddTextPrinterParameterizedWithColor((Window *)(state + 0x20), 1, *(String **)(state + 0x3C), 0, 0, *(u32 *)(state + 0x38), 0x10200, NULL);
    DrawFrameAndWindow2(state + 0x20, 1, 0x46, 0xC);
    ScheduleWindowCopyToVram((Window *)(state + 0x20));
    String_Delete(temp);
}

BOOL ov43_0222B534(u8 *windowState, u32 *touchSpeed) {
    if (!TextPrinterCheckActive((u8)*(u32 *)(windowState + 0x34))) {
        TextFlags_SetCanTouchSpeedUpPrint(FALSE);
        *touchSpeed = TextFlags_GetIsTouchSpeedingUpPrint();
        return TRUE;
    }
    return FALSE;
}
