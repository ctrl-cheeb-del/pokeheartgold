#include "to47_overlay39_state_control_r6_private.h"



BOOL ov39_02227778(Ov39Work *work) {
    Ov39StateFn *table;

    if (work->unk3C4 == 1) {
        if (work->unk3E8 != 0x59DC) {
            if (work->unk411 != 0) {
                work->unk411--;
            } else {
                switch (ov39_0222A13C()) {
                case 1:
                case 7:
                case 8:
                case 9:
                    if (ov39_022278D4(work) == TRUE) {
                        work->unk3E8 = 0x59DC;
                    }
                    break;
                }
            }
        }
        ov39_02227A5C(work);
        if (work->unk40C != NULL) {
            if (work->unk40C(work, &work->unk400) == TRUE) {
                work->unk40C = NULL;
                if (work->unk400 != NULL) {
                    work->unk400(work->unk150, &work->unk17C);
                    work->unk400 = NULL;
                }
                MI_CpuFill8(&work->unk400, 0, 16);
                work->unk3EC = 0x59DC;
            }
        }
    }

    table = ov39_0222A8B4[work->unk3BC];
    if (table != NULL) {
        switch (table[work->unk3C0](work, &work->unk3CC)) {
        case 0:
            break;
        case 1:
            MI_CpuFill8(&work->unk3CC, 0, 12);
            work->unk3C0++;
            MI_CpuFill8(&work->unk3CC, 0, 12);
            if (ov39_0222A8B4[work->unk3BC][work->unk3C0] == NULL) {
                work->unk3C0 = 0;
                work->unk3BC = 0;
            }
            break;
        case 2:
            MI_CpuFill8(&work->unk3CC, 0, 12);
            work->unk3C0 = 0;
            break;
        }
    }
    return TRUE;
}

BOOL ov39_022278D4(Ov39Work *work) {
    BOOL res = FALSE;

    switch (work->unk3E8) {
    case 0x4E20:
        res = ov39_0222A164(&work->unk190, work->unk3B4);
        break;
    case 0x4E21:
        res = ov39_0222A1C0(work->unk3AC.h, work->unk3B4);
        break;
    case 0x5208:
        res = ov39_0222A200(work->unk3AC.b, &work->unk190, work->unk3B4);
        break;
    case 0x5209:
        res = ov39_0222A268(work->unk3AC.b, work->unk3B4);
        break;
    case 0x55F0:
        res = ov39_0222A2CC(work->unk3B4);
        break;
    case 0x55F1:
        res = ov39_0222A2EC(&work->unk190, work->unk3B4);
        break;
    case 0x59D8:
        res = ov39_0222A33C(work->unk190, work->unk3B4);
        break;
    case 0x59D9:
        switch (work->unk3F0) {
        case 0:
            res = ov39_0222A394(&work->unk190, work->unk3B4);
            break;
        case 1:
            res = ov39_0222A3DC(&work->unk190, work->unk3B4);
            break;
        case 2:
            res = ov39_0222A434(&work->unk190, work->unk3B4);
            break;
        }
        break;
    case 0x59DA:
        res = ov39_0222A48C(work->unk3AC.w, work->unk3B0, 0x140, work->unk3B4);
        break;
    case 0x59DB:
        res = ov39_0222A4C0(work->unk3AC.w, work->unk3B0, work->unk3B4);
        break;
    default:
        GF_AssertFail();
        break;
    }

    if (res == TRUE) {
        work->unk3EC = work->unk3E8;
    }
    return res;
}

BOOL ov39_02227A5C(Ov39Work *work) {
    if (work->unk3EC == 0x59DC) {
        return TRUE;
    }
    work->unk148 = ov39_0222A13C();
    if (work->unk148 != work->unk14C) {
        switch (work->unk148) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            break;
        case 7:
            work->unk180 = 1;
            work->unk184 = 0;
            work->unk188 = 7;
            work->unk17C = 1;
            work->unk40C = ov39_02227B58;
            break;
        case 8:
            work->unk40C = ov39_02227B1C;
            ov39_02227B5C(work);
            break;
        case 9:
            work->unk180 = 0;
            work->unk184 = 0;
            work->unk188 = ov39_0222A158();
            work->unk17C = 1;
            work->unk40C = ov39_02227B58;
            break;
        }
        work->unk14C = work->unk148;
    }
    return TRUE;
}
