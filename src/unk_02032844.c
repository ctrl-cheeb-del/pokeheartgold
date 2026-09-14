#include "unk_02032844_internal.h"

BOOL sub_02032A40(void) {
    WirelessWork *work;
    int result;

    if ((u32)(_021D4124.work->state - 4) <= 2) {
        return TRUE;
    }
    sub_02032844(4);
    work = _021D4124.work;
    result = WM_StartMP(sub_02032AB0,
        (u8 *)work + 0x1020,
        (u16)work->mpSendSize,
        (u8 *)work + 0xF40,
        (u16)work->mpRecvSize,
        1);
    if (result != 2) {
        sub_02032858(result);
        return FALSE;
    }
    return TRUE;
}

void sub_02032AB0(void *arg) {
    u8 *data = arg;
    u16 error = *(u16 *)(data + 2);
    u16 event;

    if (error != 0) {
        sub_02032858(error);
        sub_02032844(9);
        return;
    }
    event = *(u16 *)(data + 4);
    switch (event) {
    case 10:
        if (_021D4124.work->wmState == 2) {
            if (_021D4124.work->state != 4) {
                if (_021D4124.work->state == 6) {
                    break;
                }
            }
        }
        sub_02032844(4);
        break;
    case 11:
    case 12:
    case 13:
    default:
        break;
    }
}
