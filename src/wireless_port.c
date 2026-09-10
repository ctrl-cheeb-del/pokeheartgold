#include "wireless_internal.h"
void sub_02032858(int error);
void sub_020331A4(void *arg);
void sub_020331CC(void *arg);
int WM_SetMPDataToPortEx(void (*callback)(void *), u32 port, const void *data, u32 length, u16 dest, u16 priority, u32 flag);
BOOL sub_0203314C(const void *data, u32 length, int priority, u32 port);
void sub_020331A4(void *arg);
void sub_020331CC(void *arg);

BOOL sub_0203314C(const void *data, u32 length, int priority, u32 port) {
    int result;
    DC_FlushRange((u8 *)_021D4124.work + 0xF40, _021D4124.work->mpRecvSize);
    result = WM_SetMPDataToPortEx(sub_020331A4, port, data, length, 0xFFFF, priority, 2);
    if (result == 2) {
        return TRUE;
    }
    return FALSE;
}
void sub_020331A4(void *arg) {
    u16 error = *(u16 *)((u8 *)arg + 2);
    if (error != 0 && error != 15) {
        sub_02032858(error);
        return;
    }
    if (*(void (**)(BOOL))((u8 *)arg + 0x20) != NULL) {
        (*(void (**)(BOOL))((u8 *)arg + 0x20))(error == 0);
    }
}
void sub_020331CC(void *arg) {
    u8 *event = arg;
    u16 error = *(u16 *)(event + 2);
    void (*callback)(u16, void *, u16);
    if (error != 0) {
        sub_02032858(error);
        return;
    }
    callback = (void (*)(u16, void *, u16))_021D4124.work->portCallback;
    if (callback == NULL) {
        return;
    }
    if (*(u16 *)(event + 4) == 0x19) {
        return;
    }
    if (*(u16 *)(event + 4) == 0x15) {
        callback(*(u16 *)(event + 0x12), *(void **)(event + 0xC), *(u16 *)(event + 0x10));
    } else if (*(u16 *)(event + 4) == 9) {
        callback(*(u16 *)(event + 0x12), NULL, 0);
    }
}
