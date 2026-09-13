#include "overlay92_battle_sequence_r14_task_setup_to42_private.h"

typedef struct Copy12 {
    u32 values[3];
} Copy12;

void ov92_0225EEBC(void *work) {
    u8 *task = Heap_Alloc(HEAP_ID_113, 0x7c);
    memset(task, 0, 0x7c);
    PTR_AT(task, 0xc) = PTRTac(work, 0x110);
    PTR_AT(task, 0x10) = PTRTac(work, 0x320);
    PTR_AT(task, 0x14) = PTRTac(work, 0x114);
    *(Copy12 *)PTRTac(task, 0x20) = *(Copy12 *)PTRTac(work, 0x1fc8);
    PTR_AT(task, 0x74) = PTR_AT(work, 0x2bb4);
    PTR_AT(task, 0x78) = PTR_AT(work, 0x14);
    ov92_0225DD48(work, 0);
    sub_02018198(PTRTac(work, 0x3a8), 0);
    sub_02018198(PTRTac(work, 0x5b4), 0);
    sub_02018198(PTRTac(work, 0x7c0), 0);
    SysTask_CreateOnMainQueue(ov92_0225EF4C, task, 1 << 12);
}
