#include "to47_overlay87_private.h"

int ov87_021E7134(State *p) {
    int r;
    PlaySE(0x5f3);
    r = ov87_021E6F98(p, (u8 *)p + 0x11c, 11, 0x30, 5, 0, 1, 2, 0, 0);
    ScheduleWindowCopyToVram((u8 *)p + 0x11c);
    return r;
}
int ov87_021E717C(State *p) {
    int r;
    r = ov87_021E6F98(p, (u8 *)p + 0x12c, 4, 0x30, 1, 0, 1, 1, 0, 2);
    ScheduleWindowCopyToVram((u8 *)p + 0x12c);
    return r;
}
int ov87_021E71B4(State *p) {
    int r;
    r = ov87_021E6F98(p, (u8 *)p + 0x13c, 5, 0x18, 1, 0, 1, 1, 0, 2);
    ScheduleWindowCopyToVram((u8 *)p + 0x13c);
    return r;
}
