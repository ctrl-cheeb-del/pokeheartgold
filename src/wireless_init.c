#include "global.h"
typedef struct WirelessGlobal {
    u32 unused;
    u8 *work;
} WirelessGlobal;
extern WirelessGlobal _021D4124;
void sub_02032844(int);
void sub_02032858(int);
void sub_02039AD8(int);
typedef void (*WMCallback)(void *);
int WM_Initialize(void *work, WMCallback callback, int dma);
int WM_InitializeForListening(void *work, WMCallback callback, int dma, int flags);
int WM_SetIndCallback(WMCallback callback);
u32 sub_020335B4(void);
void sub_020335BC(void *arg);
BOOL sub_020335D4(int mode);
void sub_02033620(void *arg);
void sub_02033664(void);
u32 sub_020335B4(void) {
    return 0x1380;
}
void sub_020335BC(void *arg) {
    if (*(u16 *)((u8 *)arg + 2) == 8) {
        sub_02032844(9);
        sub_02032858(25);
    }
}
BOOL sub_020335D4(int mode) {
    int result;
    sub_02032844(3);
    if (mode == 1) {
        result = WM_Initialize(_021D4124.work + 0x40, sub_02033620, 2);
    } else {
        result = WM_InitializeForListening(_021D4124.work + 0x40, sub_02033620, 2, 0);
    }
    if (result != 2) {
        sub_02032858(result);
        sub_02032844(10);
        return FALSE;
    }
    return TRUE;
}
void sub_02033620(void *arg) {
    int result;
    if (*(u16 *)((u8 *)arg + 2) != 0) {
        sub_02032858(*(u16 *)((u8 *)arg + 2));
        sub_02032844(10);
        sub_02039AD8(5);
        return;
    }
    result = WM_SetIndCallback(sub_020335BC);
    if (result != 0) {
        sub_02032858(result);
        sub_02032844(10);
        sub_02039AD8(5);
        return;
    }
    sub_02032844(1);
}
void sub_02033664(void) {
}
