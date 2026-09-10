#include "overlay_27_helpers_internal.h"

void ov27_0225C8D0(Ov27Window *window, MsgData *msgData, u32 msgId) {
    String *str = NewString_ReadMsgData(msgData, msgId);
    FillWindowPixelBuffer(window, 0);
    AddTextPrinterParameterizedWithColor(window, 4, str, 0, 0, 0xff, 0x20100, 0);
    ScheduleWindowCopyToVram(window);
    String_Delete(str);
}

void ov27_0225C914(Ov27Work *work) {
    work->unk50 = MessageFormat_New(8);
    work->unk4C = NewMsgDataFromNarc(0, 27, 191, 8);
}

void ov27_0225C930(Ov27Work *work) {
    DestroyMsgData(work->unk4C);
    MessageFormat_Delete(work->unk50);
}

u32 ov27_0225C944(Ov27Work *work) {
    work->unk00 = 1;
    return 0;
}

u32 ov27_0225C94C(Ov27Work *work) {
    work->unk394 = 0;
    ov27_0225C540(work);
    Sprite_SetDrawFlag(work->unk388, TRUE);
    ov27_0225CCE0(work, work->unk394);
    Sprite_SetAnimCtrlSeq(work->unk388, 1);
    work->unk00 = 4;
    return 0;
}

u32 ov27_0225C988(Ov27Work *work) {
    ov27_0225CD94(work);
    return 0;
}

u32 ov27_0225C994(Ov27Work *work) {
    if (!Sprite_IsAnimated(work->unk388)) {
        Sprite_SetDrawFlag(work->unk388, FALSE);
        ov27_0225C5E4(work);
        *(u16 *)work->unk04 = work->unk394;
        work->unk00 = 6;
    }
    return 0;
}

u32 ov27_0225C9CC(Ov27Work *work) {
    Sprite_SetDrawFlag(work->unk388, FALSE);
    work->unk00 = 1;
    return 0;
}

u32 ov27_0225C9E4(Ov27Timer *p) {
    p->unk10++;
    if (p->unk10 > 20) {
        return 1;
    }
    return 0;
}
