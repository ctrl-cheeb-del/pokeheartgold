#include "overlay92_battle_sequence_r14_private.h"

int ov92_0225F8EC(Ov92BattleSequenceR14 *work) {
    switch (work->value) {
    case 0x77:
        work->mode = 1;
        break;
    case 0x10d:
        work->mode = 2;
        break;
    case 0x1a3:
        work->mode = 3;
        break;
    case 0x239:
        work->mode = 4;
        break;
    case 0x2cf:
        work->mode = 5;
        break;
    case 0:
        work->mode = 0;
        break;
    }
    return ov92_0225F968(work, work->value, &work->index);
}

int ov92_0225F968(Ov92BattleSequenceR14 *work, int value, u32 *out) {
    switch (value) {
    case 0x12b:
        *out = 1;
        return 1;
    case 0x257:
        *out = 2;
        return 1;
    case 0x383:
        *out = 3;
        return 1;
    case 0x4af:
        *out = 4;
        return 1;
    case 0:
        *out = 0;
    }
    return 0;
}
