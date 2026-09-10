#include "wireless_internal.h"
typedef void (*WMCallback)(void *);
int WM_SetParentParameter(WMCallback callback, void *param);
int WM_StartParent(WMCallback callback);
void *WMi_GetStatusAddress(void);

void sub_02032844(int state);
void sub_02032858(int error);
BOOL sub_02032874(void);
void sub_020328A4(void *arg);
BOOL sub_020328C8(void);
void sub_02032934(void *arg);

void sub_02032844(int state) {
    _021D4124.work->state = state;
}

void sub_02032858(int error) {
    int state = _021D4124.work->state;
    if ((u32)(state - 9) > 1) {
        _021D4124.work->error = error;
    }
}

BOOL sub_02032874(void) {
    int result;
    sub_02032844(3);
    result = WM_SetParentParameter(sub_020328A4, _021D4124.work);
    if (result != 2) {
        sub_02032858(result);
        sub_02032844(9);
        return FALSE;
    }
    return TRUE;
}

void sub_020328A4(void *arg) {
    if (*(u16 *)((u8 *)arg + 2) != 0) {
        sub_02032858(*(u16 *)((u8 *)arg + 2));
        sub_02032844(9);
    } else if (!sub_020328C8()) {
        sub_02032844(9);
    }
}

BOOL sub_020328C8(void) {
    u8 *status;
    int result;
    if ((u32)(_021D4124.work->state - 4) <= 2) {
        return TRUE;
    }
    status = WMi_GetStatusAddress();
    DC_InvalidateRange(status + 0x198, 4);
    *(u32 *)(status + 0x198) = 0;
    DC_FlushRange(status + 0x198, 4);
    result = WM_StartParent(sub_02032934);
    if (result != 2) {
        sub_02032858(result);
        return FALSE;
    }
    _021D4124.work->connectedBitmap = 0;
    _021D4124.work->activeBitmap = 1;
    return TRUE;
}
