#include "wireless_internal.h"
void sub_02032844(int state);
void sub_02033214(void *arg);
int WM_End(void (*callback)(void *));
int WM_SetGameInfo(void *callback, const void *data, u16 length, u32 ggid, u16 tgid, u32 attr);
int WM_SetEntry(void (*callback)(void *), BOOL enabled);

BOOL sub_020338D0(void);
u16 sub_020338F4(void);
void sub_02033908(u8 value);
BOOL sub_02033920(void);
BOOL sub_0203393C(void);
BOOL sub_02033958(void);
BOOL sub_02033974(void);
BOOL sub_02033990(void);
void sub_020339B4(const void *data, int length, u32 ggid, int tgid);
void sub_020339F0(void *arg);
BOOL sub_02033A0C(BOOL enabled);
BOOL sub_02033A44(void);
void sub_02033A68(void);
void sub_02033A7C(void *callback);
void sub_02033A90(void *callback);
void sub_02033AA4(u8 value);
u8 sub_02033AB8(void);
void sub_02033ACC(u8 value);

BOOL sub_020338D0(void) {
    sub_02032844(3);
    if (WM_End(sub_02033214) != 2) {
        sub_02032844(9);
        return FALSE;
    }
    return TRUE;
}

u16 sub_020338F4(void) {
    return _021D4124.work->connectedBitmap;
}
void sub_02033908(u8 value) {
    if (_021D4124.work != NULL) {
        _021D4124.work->maxMachines = value;
    }
}
BOOL sub_02033920(void) {
    return _021D4124.work->state == 1;
}
BOOL sub_0203393C(void) {
    return _021D4124.work->state == 3;
}
BOOL sub_02033958(void) {
    return _021D4124.work->state == 9;
}
BOOL sub_02033974(void) {
    return _021D4124.work->state == 10;
}
BOOL sub_02033990(void) {
    WirelessWork *work = _021D4124.work;
    if (work != NULL) {
        if (work->state == 2) {
            return TRUE;
        }
        return FALSE;
    }
    return FALSE;
}

void sub_020339B4(const void *data, int length, u32 ggid, int tgid) {
    if (_021D4124.work->state == 4) {
        WM_SetGameInfo(NULL, data, (u16)length, ggid, (u16)tgid, 1);
    }
}

void sub_020339F0(void *arg) {
    if (*(u16 *)((u8 *)arg + 2) == 0) {
        _021D4124.work->entryComplete = 1;
    }
}

BOOL sub_02033A0C(BOOL enabled) {
    _021D4124.work->entryComplete = 0;
    if (_021D4124.work->state == 4 && WM_SetEntry(sub_020339F0, enabled) == 2) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02033A44(void) {
    WirelessWork *work = _021D4124.work;
    if (work != NULL) {
        if (work->retryCount >= 6) {
            return TRUE;
        }
        return FALSE;
    }
    return FALSE;
}
void sub_02033A68(void) {
    _021D4124.work->retryCount = 0;
}
void sub_02033A7C(void *callback) {
    _021D4124.work->parentCallback = callback;
}
void sub_02033A90(void *callback) {
    _021D4124.work->childCallback = callback;
}
void sub_02033AA4(u8 value) {
    _021D4124.work->flag1342 = value;
}
u8 sub_02033AB8(void) {
    return _021D4124.work->flag1342;
}
void sub_02033ACC(u8 value) {
    _021D4124.work->flag1343 = value;
}
