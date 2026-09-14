#include "to47_overlay87_private.h"

int ov87_021E7008(State *p) {
    int r;
    ov87_021E810C(*(void **)((u8 *)p + 0x58), (u8 *)p + 0x5c);
    r = ov87_021E6F38(p, (u8 *)p + 0x5c, 6, 1, 1, 0, 1, 2, 15, 0);
    ScheduleWindowCopyToVram((u8 *)p + 0x5c);
    return r;
}
int ov87_021E7048(State *p) {
    int r;
    ov87_021E7244(p, 0, *((u8 *)p + 0xe) + 1);
    r = ov87_021E6F38(p, (u8 *)p + 0x14c, 12, 1, 1, 0, 1, 2, 15, 1);
    ScheduleWindowCopyToVram((u8 *)p + 0x14c);
    return r;
}
int ov87_021E708C(State *p) {
    int r;
    ov87_021E7244(p, 0, *((u8 *)p + 0xe) + 1);
    r = ov87_021E6F98(p, (u8 *)p + 0xfc, 9, 0x30, 5, 0, 1, 2, 0, 0);
    ScheduleWindowCopyToVram((u8 *)p + 0xfc);
    return r;
}
