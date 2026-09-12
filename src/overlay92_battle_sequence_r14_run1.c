#include "overlay92_battle_sequence_r14_private.h"

void ov92_0225EE60(void *work, int index) {
    u8 *task = (u8 *)work + 0x29d0 + index * 0x44;

    if (U32_AT(task, 0x30) != 1) {
        PTR_AT(task, 0x40) = PTR_AT(work, 0x2bb4);
        U32_AT(task, 0x30) = 1;
        PTR_AT(task, 0x2c) = PTR_AT_OFFSET(work, 0x2aec);
        PTR_AT(task, 0x28) = *(void **)PTR_AT(task, 0x2c);
        PTR_AT(task, 0x34) = PTR_AT_OFFSET(work, 0x1bb0);
        PTR_AT(task, 0x38) = PTR_AT_OFFSET(work, 0x1dbc);
        U32_AT(task, 0) = 0;
        U32_AT(task, 4) = 0;
        PTR_AT(task, 0x3c) = PTR_AT(work, 0x14);
        SysTask_CreateOnMainQueue(ov92_0225F530, task, 1 << 12);
    }
}
