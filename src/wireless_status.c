#include "global.h"
typedef struct WirelessGlobal {
    u32 unused;
    u8 *work;
} WirelessGlobal;
extern WirelessGlobal _021D4124;
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
    *(u32 *)(_021D4124.work + 8) = value;
}
void sub_02033240(void *ptr, u16 value) {
    *(void **)_021D4124.work = ptr;
    *(u16 *)(_021D4124.work + 4) = value;
}
u16 sub_02033250(void) {
    return *(u16 *)(_021D4124.work + 0x132E);
}
u16 sub_02033264(void) {
    int count = 0;
    int i = count;
    u16 bits = *(u16 *)(_021D4124.work + 0x132E);
    for (; i < 16; i++) {
        if (bits & 1) {
            count++;
        }
        bits >>= 1;
    }
    return count;
}
u32 sub_02033298(void) {
    return *(u32 *)(_021D4124.work + 0x1310);
}
u32 sub_020332AC(void) {
    return *(u32 *)(_021D4124.work + 0x1330);
}
