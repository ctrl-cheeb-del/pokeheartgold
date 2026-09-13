#include "global.h"

#include "r40_unk_020355DC_private.h"

BOOL sub_020355DC(u16 index) {
    if (_021D4134.work == NULL) {
        return FALSE;
    }
    if (sub_02033298() != 4) {
        return FALSE;
    }
    if (sub_02033250() & (1 << index)) {
        return TRUE;
    }
    return FALSE;
}
