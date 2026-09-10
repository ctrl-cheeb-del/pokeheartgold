#include "overlay39_helpers_internal.h"

BOOL ov39_0222748C(Ov39Work *work, u8 a1) {
    if (!ov39_02227DB8(work)) {
        return FALSE;
    }
    work->unk3AC.b = a1;
    work->unk3E8 = 0x5209;
    return TRUE;
}

BOOL ov39_022274B4(Ov39Work *work) {
    if (!ov39_02227DB8(work)) {
        return FALSE;
    }
    work->unk3E8 = 0x55F0;
    return TRUE;
}
