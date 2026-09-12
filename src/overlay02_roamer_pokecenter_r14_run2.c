#include "overlay02_roamer_pokecenter_r14_private.h"

void ov02_0224BDE8(void *fs, u8 direction, u8 length) {
    if (sub_02054C20(fs, 0xd0, NULL, NULL)) {
        u8 *env = Heap_AllocAtEnd(4, 4);
        env[0] = length;
        env[1] = direction;
        env[2] = 0;
        TaskManager_Call(PTR(fs, 0x10), ov02_0224BE24, env);
    } else {
        GF_AssertFail();
    }
}
