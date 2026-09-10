#include "wireless_internal.h"
typedef void (*WMCallback)(void *);
void sub_02032844(int);
void sub_02032858(int);
BOOL sub_02032E9C(void);
void sub_02032E64(void *);
int WM_EndScan(WMCallback);
BOOL sub_02032E24(void);
BOOL sub_02032E48(void);
void sub_02032E64(void *);
BOOL sub_02032E24(void) {
    if (_021D4124.work->state != 2) {
        return FALSE;
    }
    sub_02032844(3);
    return TRUE;
}
BOOL sub_02032E48(void) {
    int r = WM_EndScan(sub_02032E64);
    if (r != 2) {
        sub_02032858(r);
        return FALSE;
    }
    return TRUE;
}
void sub_02032E64(void *a) {
    if (*(u16 *)((u8 *)a + 2) != 0) {
        sub_02032858(*(u16 *)((u8 *)a + 2));
        return;
    }
    sub_02032844(1);
    if (_021D4124.work->connectPending != 0 && !sub_02032E9C()) {
        sub_02032844(9);
    }
}
