#include "wireless_scan_param_internal.h"

BOOL sub_02032B84(void *a0, const u16 *mac, u16 channel) {
    _021D4124.work->mpSendSize = 0x200;
    _021D4124.work->mpRecvSize = 0x40;
    sub_02032844(2);
    *(u16 *)((u8 *)_021D4124.work + 0x1256) = 1;
    *(u16 *)((u8 *)_021D4124.work + 0x12EC) = mac[2];
    *(u16 *)((u8 *)_021D4124.work + 0x12EA) = mac[1];
    *(u16 *)((u8 *)_021D4124.work + 0x12E8) = mac[0];
    *(void **)((u8 *)_021D4124.work + 0x1314) = a0;
    *(void **)((u8 *)_021D4124.work + 0x1300) = NULL;
    _021D4124.work->channel = channel;
    *(u16 *)((u8 *)_021D4124.work + 0x12E4) = 0;
    _021D4124.work->connectPending = 1;
    if (!sub_02032C84()) {
        sub_02032844(9);
        return FALSE;
    }
    return TRUE;
}

BOOL sub_02032C1C(void *a0, const u16 *mac, u16 channel) {
    sub_02032844(2);
    *(void **)((u8 *)_021D4124.work + 0x1300) = a0;
    _021D4124.work->channel = channel;
    *(u16 *)((u8 *)_021D4124.work + 0x12E4) = 0;
    _021D4124.work->connectPending = 0;
    *(u16 *)((u8 *)_021D4124.work + 0x12EC) = mac[2];
    *(u16 *)((u8 *)_021D4124.work + 0x12EA) = mac[1];
    *(u16 *)((u8 *)_021D4124.work + 0x12E8) = mac[0];
    if (!sub_02032C84()) {
        sub_02032844(9);
        return FALSE;
    }
    return TRUE;
}
