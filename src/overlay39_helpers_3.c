#include "overlay39_helpers_internal.h"

BOOL ov39_02227334(Ov39Work *work) {
    ov39_0222A130(work);
    work->unk3C4 = 0;
    return TRUE;
}

BOOL ov39_02227348(Ov39Work *work) {
    ov00_021EC210();
    ov00_021EC8D8();
    sub_0203946C();
    work->unk3C8 = 0;
    return TRUE;
}

BOOL ov39_02227364(Ov39Work *work) {
    int res = ov00_021E6A70(-work->unk3E0, work->unk3E4);
    ov39_02227D5C(work, res, -work->unk3E0);
    return TRUE;
}

BOOL ov39_0222738C(Ov39Cb *cb) {
    u32 keys = gSystem.heldKeys;
    if ((keys & 1) || (keys & 2)) {
        ov39_02227D50(cb, 0);
        return TRUE;
    }
    return FALSE;
}
