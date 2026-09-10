#include "global.h"
typedef void (*WMCallback)(void *);
void sub_02032844(int);
void sub_02032858(int);
void sub_02033830(void);
BOOL sub_02032B50(void);
void sub_02032B30(void *);
void sub_02032B6C(void *);
int WM_EndMP(WMCallback);
int WM_EndParent(WMCallback);
BOOL sub_02032B0C(void);
void sub_02032B30(void *);
BOOL sub_02032B50(void);
void sub_02032B6C(void *);
BOOL sub_02032B0C(void) {
    int r;
    sub_02032844(3);
    r = WM_EndMP(sub_02032B30);
    if (r != 2) {
        sub_02032858(r);
        return FALSE;
    }
    return TRUE;
}
void sub_02032B30(void *a) {
    if (*(u16 *)((u8 *)a + 2) != 0) {
        sub_02032858(*(u16 *)((u8 *)a + 2));
        sub_02033830();
    } else if (!sub_02032B50()) {
        sub_02033830();
    }
}
BOOL sub_02032B50(void) {
    int r = WM_EndParent(sub_02032B6C);
    if (r != 2) {
        sub_02032858(r);
        return FALSE;
    }
    return TRUE;
}
void sub_02032B6C(void *a) {
    if (*(u16 *)((u8 *)a + 2) != 0) {
        sub_02032858(*(u16 *)((u8 *)a + 2));
    } else {
        sub_02032844(1);
    }
}
