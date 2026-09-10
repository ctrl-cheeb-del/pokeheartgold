#include "overlay39_helpers_internal.h"

BOOL ov39_02227DB8(Ov39Work *work) {
    if (ov39_02227DE4(work) == 0 && work->unk3E8 == 0x59DC && work->unk3EC == 0x59DC) {
        return TRUE;
    }
    return FALSE;
}
