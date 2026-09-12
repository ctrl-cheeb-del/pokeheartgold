#include "overlay92_battle_sequence_r14_private.h"

void ov92_0225FC2C(Ov92BattleSequenceR14 *work) {
    if (work->progress < 0x4b0) {
        ov92_0225FAB8(work);
        ov92_0225F9C4(work);
        if (ov92_0225F8EC(work) == 1) {
            ov92_0225EE60(work, U32_AT(work, 0));
            ov92_0225F8B0(work);
            PlaySE(0x58c);
        }
        ov92_0225FEE4(work);
        work->value++;
        work->progress++;
        work->count++;
    }
}
