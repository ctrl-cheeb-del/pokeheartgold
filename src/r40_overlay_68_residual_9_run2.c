#include "r40_overlay_68_residual_9_private.h"

void ov68_021E67E0(MoveRelearner *d) {
    u32 i;

    FillWindowPixelBuffer(&d->windows[10], 0);
    for (i = 0; i < 4; i++) {
        ov68_021E66F0(d, (u8)d->args->unk_16, (u8)i);
    }
    ScheduleWindowCopyToVram(&d->windows[10]);
    ScheduleBgTilemapBufferTransfer(d->bgConfig, 7);
    ov68_021E70BC(d);
}

void ov68_021E6820(MoveRelearner *d) {
    u32 i;
    void *msgData;

    d->unk_1B8 = ov68_021E6678(d);
    d->unk_110 = ListMenuItems_New(d->unk_1B8, 0x42);
    msgData = NewMsgDataFromNarc(0, 0x1b, 0x2ee, 0x42);

    for (i = 0; i < d->unk_1B8; i++) {
        u16 move = d->args->unk_10[i];
        if (move != 0xffff) {
            ListMenuItems_AppendFromMsgData(d->unk_110, msgData, move, move);
        } else {
            ListMenuItems_AppendFromMsgData(d->unk_110, d->msgData, 0x20, -2);
            break;
        }
    }
    DestroyMsgData(msgData);
    *(u8 *)((u8 *)d + 0x1bb) = 0;
    *(u8 *)((u8 *)d + 0x1bc) = d->args->unk_14;
    ov68_021E67E0(d);
}
