#include "wireless_internal.h"
void sub_02032844(int state);
void WVR_TerminateAsync(void (*callback)(void *), void *arg);
void sub_02033214(void *arg);
void sub_02033234(u32 value);
void sub_02033240(void *ptr, u16 value);
u16 sub_02033250(void);
u16 sub_02033264(void);
u32 sub_02033298(void);
u32 sub_020332AC(void);

void sub_02033214(void *arg) {
    if (*(u16 *)((u8 *)arg + 2) != 0) {
        sub_02032844(10);
    } else {
        WVR_TerminateAsync(NULL, NULL);
        sub_02032844(0);
    }
}
void sub_02033234(u32 value) {
    _021D4124.work->userValue = value;
}
void sub_02033240(void *ptr, u16 value) {
    _021D4124.work->context = ptr;
    _021D4124.work->contextValue = value;
}
u16 sub_02033250(void) {
    return _021D4124.work->activeBitmap;
}
u16 sub_02033264(void) {
    int count = 0;
    int i = count;
    u16 bits = _021D4124.work->activeBitmap;
    for (; i < 16; i++) {
        if (bits & 1) {
            count++;
        }
        bits >>= 1;
    }
    return count;
}
u32 sub_02033298(void) {
    return _021D4124.work->state;
}
u32 sub_020332AC(void) {
    return _021D4124.work->error;
}
