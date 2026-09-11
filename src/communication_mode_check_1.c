#include "communication_mode_check_internal.h"

int sub_02036D14(const u8 *data, int slot) {
    u8 value;
    u8 direction;
    int decoded;

    ((u16 *)(_021D4140.work + 0x644))[slot] = 0;
    value = *data;
    if ((value & 0x10) == 0x10) {
        direction = value & 0x0c;
        if (direction == 0) {
            ((u16 *)(_021D4140.work + 0x644))[slot] |= 0x40;
        } else if (direction == 4) {
            ((u16 *)(_021D4140.work + 0x644))[slot] |= 0x80;
        } else if (direction == 8) {
            ((u16 *)(_021D4140.work + 0x644))[slot] |= 0x20;
        } else if (direction == 0x0c) {
            ((u16 *)(_021D4140.work + 0x644))[slot] |= 0x10;
        }
        decoded = *data >> 5;
        decoded &= 7;
        {
            u8 *work = _021D4140.work + slot;
            work[0x654] = decoded;
        }
    }
    return 1;
}
