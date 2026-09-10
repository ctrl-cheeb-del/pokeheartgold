#include "global.h"
typedef void (*WMCallback)(void *);
void sub_02032844(int state);
void sub_02032858(int error);
void sub_02033858(void);
void sub_02033830(void);
BOOL sub_020330C8(void);
void sub_020330A4(void *arg);
void sub_020330F0(void *arg);
void sub_0203312C(void *arg);
int WM_EndMP(WMCallback callback);
int WM_Disconnect(WMCallback callback, u16 aid);
int WM_Reset(WMCallback callback);
BOOL sub_02033080(void);
void sub_020330A4(void *arg);
BOOL sub_020330C8(void);
void sub_020330F0(void *arg);
BOOL sub_02033108(void);
void sub_0203312C(void *arg);

BOOL sub_02033080(void) {
    int result;
    sub_02032844(3);
    result = WM_EndMP(sub_020330A4);
    if (result != 2) {
        sub_02032858(result);
        return FALSE;
    }
    return TRUE;
}
void sub_020330A4(void *arg) {
    u16 error = *(u16 *)((u8 *)arg + 2);
    if (error != 0) {
        sub_02032858(error);
        sub_02033858();
    } else if (!sub_020330C8()) {
        sub_02032844(9);
    }
}
BOOL sub_020330C8(void) {
    int result;
    sub_02032844(3);
    result = WM_Disconnect(sub_020330F0, 0);
    if (result != 2) {
        sub_02032858(result);
        sub_02033830();
        return FALSE;
    }
    return TRUE;
}
void sub_020330F0(void *arg) {
    u16 error = *(u16 *)((u8 *)arg + 2);
    if (error != 0) {
        sub_02032858(error);
    } else {
        sub_02032844(1);
    }
}
BOOL sub_02033108(void) {
    int result;
    sub_02032844(3);
    result = WM_Reset(sub_0203312C);
    if (result != 2) {
        sub_02032858(result);
        return FALSE;
    }
    return TRUE;
}
void sub_0203312C(void *arg) {
    if (*(u16 *)((u8 *)arg + 2) != 0) {
        sub_02032844(9);
        sub_02032858(*(u16 *)((u8 *)arg + 2));
    } else {
        sub_02032844(1);
    }
}
