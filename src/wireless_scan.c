#include "global.h"
typedef struct WirelessGlobal {
    u32 unused;
    u8 *work;
} WirelessGlobal;
extern WirelessGlobal _021D4124;
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
    if (*(u32 *)(_021D4124.work + 0x1310) != 2) {
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
    if (*(u16 *)(_021D4124.work + 0x130E) != 0 && !sub_02032E9C()) {
        sub_02032844(9);
    }
}
