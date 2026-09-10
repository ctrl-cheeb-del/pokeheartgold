#include "overlay39_helpers_internal.h"

BOOL ov39_022273F8(Ov39Work *work, u16 a1) {
    if (!ov39_02227DB8(work)) {
        return FALSE;
    }
    work->unk3AC.h = a1;
    work->unk3E8 = 0x4E21;
    return TRUE;
}
