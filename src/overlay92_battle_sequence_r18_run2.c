#include "overlay92_battle_sequence_r18_private.h"

void ov92_022613F0(Ov92AnimState *work) {
    if (work->active != 0) {
        switch (work->state) {
        case 0:
            ov92_022610E8(work->sprites[0], &work->unk54);
            work->unk28 = 0;
            work->state++;
            break;
        case 1:
            if (work->unk50 == 1 && ++work->unk28 >= 15) {
                work->unk54 = 1;
                work->state++;
            }
            break;
        default:
            if (work->unk54 == 0) {
                work->unk50 = 0;
                work->active = 0;
                work->state = 0;
            }
            break;
        }
    }
}

void ov92_02261448(SysTask *task, void *arg) {
    u8 *work = arg;
    u8 *fade = PTR(work, 0x264);
    if (IsPaletteFadeFinished() == 0 || *(u8 *)(fade + 0x34) == 1) {
        SysTask_Destroy(task);
        return;
    }
    switch (WORD(PTR(work, 4), 0)) {
    case 5:
        if (WORD(work, 0x1ec) == 0) {
            WORD(work, 0x1ec) = 1;
            WORD(work, 0x238) = 0;
        }
    case 4:
        if (WORD(work, 0x174) == 0) {
            PlaySE(0x60e);
            WORD(work, 0x174) = 1;
            WORD(work, 0x1c0) = 0;
        }
    case 3:
        if (WORD(work, 0xfc) == 0) {
            WORD(work, 0xfc) = 1;
            WORD(work, 0x148) = 0;
        }
    case 2:
        if (WORD(work, 0x84) == 0) {
            PlaySE(0x589);
            WORD(work, 0x84) = 1;
            WORD(work, 0xd0) = 0;
        }
    case 1:
        if (WORD(work, 0xc) == 0) {
            WORD(work, 0xc) = 1;
            WORD(work, 0x58) = 0;
        }
        break;
    default:
        if (WORD(PTR(work, 4), 0) != WORD(work, 0)) {
            WORD(work, 0x58) = 1;
            WORD(work, 0xd0) = 1;
            WORD(work, 0x148) = 1;
            WORD(work, 0x1c0) = 1;
            WORD(work, 0x238) = 1;
            StopSE(0x589, 0);
        }
        break;
    }
    ov92_02261118((Ov92AnimState *)(work + 8));
    ov92_02261208((Ov92AnimState *)(work + 0x80));
    ov92_0226135C((Ov92AnimState *)(work + 0xf8));
    ov92_02261208((Ov92AnimState *)(work + 0x170));
    ov92_022613F0((Ov92AnimState *)(work + 0x1e8));
    WORD(work, 0) = WORD(PTR(work, 4), 0);
}
