#include "overlay39_helpers_internal.h"

BOOL ov39_022276A4(Ov39Work *work) {
    if (!ov39_02227DB8(work)) {
        return FALSE;
    }
    MI_CpuFill8(&work->unk190, 0, 4);
    work->unk190 = 0x140;
    work->unk3F0 = 1;
    work->unk3E8 = 0x59D9;
    return TRUE;
}

BOOL ov39_022276E0(Ov39Work *work) {
    if (!ov39_02227DB8(work)) {
        return FALSE;
    }
    MI_CpuFill8(&work->unk190, 0, 4);
    work->unk190 = 0x140;
    work->unk3F0 = 2;
    work->unk3E8 = 0x59D9;
    return TRUE;
}

BOOL ov39_02227720(Ov39Work *work, u32 a1, u32 a2) {
    if (!ov39_02227DB8(work)) {
        return FALSE;
    }
    work->unk3AC.w = a1;
    work->unk3B0 = a2;
    work->unk3E8 = 0x59DA;
    return TRUE;
}

BOOL ov39_0222774C(Ov39Work *work, u32 a1, u32 a2) {
    if (!ov39_02227DB8(work)) {
        return FALSE;
    }
    work->unk3AC.w = a1;
    work->unk3B0 = a2;
    work->unk3E8 = 0x59DB;
    return TRUE;
}
