#include "overlay82_state_e5d4_private.h"
BOOL ov82_0223E5D4(Ov82Work *work) {
    switch (work->unk008) {
    case 0:
        if (ov82_0223F6E8(work, 5, ov82_0223F6C4(work->unk01A)) == TRUE) {
            work->unk01B = 0;
            work->unk01A = 0;
            work->unk017 = 0;
            work->unk008 = 1;
        }
        break;
    case 1:
        if (work->unk01B != 0) {
            work->unk01B--;
        } else if (work->unk016 >= 2) {
            work->unk016 = 0;
            if (work->unk018 < 0x14) {
                if (sub_0203769C() == 0) {
                    work->unk008 = 2;
                } else {
                    work->unk008 = 3;
                }
            } else {
                if (sub_0203769C() == 0) {
                    work->unk008 = 3;
                } else {
                    work->unk008 = 2;
                }
            }
        }
        break;
    case 3:
        ov82_0223F948(0);
        work->unk014 = 0;
        ov82_0223FCB0(work->unk208, 0);
        ov82_0223FD78(&work->windows[0], Options_GetFrame(work->options));
        ov80_0222A7CC(work->unk024, 0);
        work->unk00A = ov82_0223EF7C(work, 0xb, 1);
        work->unk01B = 0xa;
        ov82_0223F5E0(work->bgConfig, work->unk27C, 2);
        ScheduleBgTilemapBufferTransfer(work->bgConfig, 3);
        work->unk008 = 4;
        break;
    case 4:
        if (work->unk27D != 0) {
            if (work->unk27D == 1) {
                work->unk00D = work->unk27C;
                return TRUE;
            }
            ov82_0223F90C(work);
            ov82_0223F5E0(work->bgConfig, work->unk27C, 0);
            ScheduleBgTilemapBufferTransfer(work->bgConfig, 3);
            work->unk27C = 0xff;
            work->unk27D = 0;
            work->unk018 = 0xff;
            work->unk019 = 1;
            return TRUE;
        }
        break;
    case 2:
        ov82_0223F5E0(work->bgConfig, work->unk00D, 1);
        ScheduleBgTilemapBufferTransfer(work->bgConfig, 3);
        ov82_0223F84C(work);
        work->unk008 = 5;
        break;
    case 5:
        switch (ov82_0223FE18(work->yesNo)) {
        case 0:
            break;
        case 1:
            StopSE(0x5dc, 0);
            PlaySE(0x623);
            ov82_0223F834(work);
            work->unk008 = 6;
            break;
        case 2:
            ov82_0223F834(work);
            work->unk008 = 7;
            break;
        }
        break;
    case 6:
        if (ov82_0223F6E8(work, 6, 1) == TRUE) {
            return TRUE;
        }
        break;
    case 7:
        if (work->unk014 > 0) {
            work->unk014--;
            ov82_0223F948(-work->unk014);
        } else if (ov82_0223F6E8(work, 6, 2) == TRUE) {
            ov82_0223F8E4(work);
            work->unk27C = 0xff;
            work->unk018 = 0xff;
            work->unk019 = 1;
            return TRUE;
        }
        break;
    case 8:
        sub_02037BEC();
        sub_02037AC0(0x68);
        work->unk008 = 9;
        break;
    case 9:
        if (sub_02037B38(0x68) == TRUE) {
            sub_02037BEC();
            sub_020379A0(0x69);
            work->unk018 = 0xff;
            return TRUE;
        }
        break;
    }
    return FALSE;
}
