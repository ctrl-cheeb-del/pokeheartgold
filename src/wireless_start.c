#include "global.h"
typedef struct WirelessGlobal {
    u32 unused;
    u8 *work;
} WirelessGlobal;
extern WirelessGlobal _021D4124;
void sub_02032844(int);
u16 sub_020338F4(void);
u16 sub_02033250(void);
BOOL sub_0203314C(const void *, u32, int, u32);
void sub_020331CC(void *);
BOOL sub_02033108(void);
int WM_SetPortCallback(u16 port, void (*callback)(void *), void *arg);
void sub_020337D0(void *callback, int port);
BOOL sub_02033800(const void *data, u32 length, int priority, u32 port);
void sub_02033830(void);
void sub_020337D0(void *callback, int port) {
    int result;
    *(void **)(_021D4124.work + 0x1318) = callback;
    result = WM_SetPortCallback((u16)port, sub_020331CC, NULL);
    if (result != 0) {
        sub_02032844(9);
        for (;;) {}
    }
}
BOOL sub_02033800(const void *data, u32 length, int priority, u32 port) {
    if (sub_020338F4() == 0) {
        if ((sub_02033250() & 0xFE) == 0) {
            return FALSE;
        }
    }
    return sub_0203314C(data, length, priority, port);
}
void sub_02033830(void) {
    if (*(u32 *)(_021D4124.work + 0x1310) == 2) {
        for (;;) {}
    }
    if (!sub_02033108()) {
        sub_02032844(10);
    }
}
