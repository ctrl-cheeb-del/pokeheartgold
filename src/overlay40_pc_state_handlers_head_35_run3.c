#include "overlay40_pc_state_handlers_tail_35_private.h"

BOOL ov40_0223DB94(void *p) {
    void *inner = PTR(p, 0x860);
    if (HALF(inner, 0x4C0) != 0xFFFF) {
        return TRUE;
    }
    if (BYTE(inner, 0x4C2) != 0xFF) {
        return TRUE;
    }
    if (BYTE(inner, 0x4C3) != 0xFF || BYTE(inner, 0x4C4) != 0xFF) {
        return TRUE;
    }
    return FALSE;
}
