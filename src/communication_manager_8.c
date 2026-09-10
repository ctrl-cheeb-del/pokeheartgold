#include "communication_manager_internal.h"

int sub_02036DA0(u8 *data) {
    u16 flags;
    if (_021D4140.work[0x65E] != 0) {
        return 0;
    }
    if (!sub_0203751C()) {
        return 0;
    }
    if (_021D4140.work[0x6B1] != 0) {
        _021D4140.work[0x6B1]--;
    }
    flags = *(u16 *)(_021D4140.work + 0x65C);
    if (flags & 0x40) {
        *data |= 0x10;
        _021D4140.work[0x6B1] = 8;
    } else if (flags & 0x80) {
        *data |= 0x14;
        _021D4140.work[0x6B1] = 8;
    } else if (flags & 0x20) {
        *data |= 0x18;
        _021D4140.work[0x6B1] = 8;
    } else if (flags & 0x10) {
        *data |= 0x1C;
        _021D4140.work[0x6B1] = 8;
    }
    *data |= _021D4140.work[0x65F] << 5;
    return 0;
}
