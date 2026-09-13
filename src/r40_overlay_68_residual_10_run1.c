#include "r40_overlay_68_residual_10_private.h"

void ov68_021E68D4(MoveRelearner *d, s32 move) {
    u32 value;
    void *msgData;

    FillWindowPixelBuffer(&d->windows[5], 0);
    FillWindowPixelBuffer(&d->windows[3], 0);
    FillWindowPixelBuffer(&d->windows[4], 0);
    ManagedSprite_SetDrawFlag(*(void **)((u8 *)d + 0x130), FALSE);

    if (move != -2) {
        value = GetMoveAttr(move, 2);
        if (value <= 1) {
            ReadMsgDataIntoString(d->msgData, 0x21, d->unk_100);
        } else {
            ov68_021E62D4(d, 0x1d, value, 3, 0);
        }
        ov68_021E6234(d, 3, 0, 0x10200, 1, 0);

        value = GetMoveAttr(move, 4);
        if (value == 0) {
            ReadMsgDataIntoString(d->msgData, 0x21, d->unk_100);
        } else {
            ov68_021E62D4(d, 0x1e, value, 3, 0);
        }
        ov68_021E6234(d, 4, 0, 0x10200, 1, 0);

        msgData = NewMsgDataFromNarc(1, 0x1b, 0x2ed, 0x42);
        ReadMsgDataIntoString(msgData, move, d->unk_100);
        ov68_021E6234(d, 5, 0, 0x10200, 0, 0);
        DestroyMsgData(msgData);
        ov68_021E7124(d, (u16)move);
        ManagedSprite_SetDrawFlag(*(void **)((u8 *)d + 0x130), TRUE);
        ScheduleWindowCopyToVram(&d->windows[0]);
        ScheduleWindowCopyToVram(&d->windows[1]);
        ScheduleWindowCopyToVram(&d->windows[2]);
    } else {
        ClearWindowTilemapAndScheduleTransfer(&d->windows[0]);
        ClearWindowTilemapAndScheduleTransfer(&d->windows[1]);
        ClearWindowTilemapAndScheduleTransfer(&d->windows[2]);
    }
    ScheduleWindowCopyToVram(&d->windows[5]);
    ScheduleWindowCopyToVram(&d->windows[3]);
    ScheduleWindowCopyToVram(&d->windows[4]);
}

void ov68_021E6A2C(MoveRelearner *d, u32 msgNo) {
    void *str;
    void *boxMon;

    switch (msgNo) {
    case 0:
        boxMon = Mon_GetBoxMon(d->args->unk_00);
        BufferBoxMonNickname(d->msgFmt, 0, boxMon);
        break;
    case 1:
        BufferMoveName(d->msgFmt, 1, ov68_021E6BEC(d));
        break;
    case 2:
        boxMon = Mon_GetBoxMon(d->args->unk_00);
        BufferBoxMonNickname(d->msgFmt, 0, boxMon);
        break;
    case 3:
        boxMon = Mon_GetBoxMon(d->args->unk_00);
        BufferBoxMonNickname(d->msgFmt, 0, boxMon);
        BufferMoveName(d->msgFmt, 1, ov68_021E6BEC(d));
        break;
    case 4:
        boxMon = Mon_GetBoxMon(d->args->unk_00);
        BufferBoxMonNickname(d->msgFmt, 0, boxMon);
        BufferMoveName(d->msgFmt, 1, ov68_021E6BEC(d));
        break;
    case 5:
        boxMon = Mon_GetBoxMon(d->args->unk_00);
        BufferBoxMonNickname(d->msgFmt, 0, boxMon);
        BufferMoveName(d->msgFmt, 1, ov68_021E6BFC(d));
        break;
    case 6:
        boxMon = Mon_GetBoxMon(d->args->unk_00);
        BufferBoxMonNickname(d->msgFmt, 0, boxMon);
        BufferMoveName(d->msgFmt, 1, ov68_021E6BEC(d));
        break;
    case 7:
        BufferMoveName(d->msgFmt, 1, ov68_021E6BEC(d));
        break;
    case 8:
        boxMon = Mon_GetBoxMon(d->args->unk_00);
        BufferBoxMonNickname(d->msgFmt, 0, boxMon);
        BufferMoveName(d->msgFmt, 1, ov68_021E6BEC(d));
        break;
    case 9:
        BufferPlayersName(d->msgFmt, 2, *(void **)((u8 *)d->args + 4));
        break;
    case 10:
        BufferMoveName(d->msgFmt, 0, ov68_021E6BFC(d));
        break;
    }

    str = NewString_ReadMsgData(d->msgData,
        ov68_021E7DA4[*((u8 *)d->args + 0x19)][msgNo]);
    StringExpandPlaceholders(d->msgFmt, d->unk_100, str);
    String_Delete(str);
}
