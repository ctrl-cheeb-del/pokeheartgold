#include "render_window_internal.h"

void sub_0200F5C4(void *owner, u8 a, u8 b, u8 c, u32 priority) {
    u8 *state = SysTask_GetData(CreateSysTaskAndEnvironment(sub_0200F54C, 0x170, 0, priority));
    state[0x16f] = 0;
    *(void **)(state + 0x168) = owner;
    state[0x16c] = a;
    state[0x16d] = b;
    state[0x16e] = c;
}
