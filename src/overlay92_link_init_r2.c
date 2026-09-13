#include <string.h>

#include "overlay92_link_init_r2_private.h"

u32 ov92_0225CAB4(void *manager) {
    void *work;
    void *args;
    int i;
    u8 *input;
    u8 *output;

    Heap_Create(3, 0x71, 0x65 << 12);
    work = OverlayManager_CreateAndGetData(manager, 0xd0, 0x71);
    memset(work, 0, 0xd0);
    args = OverlayManager_GetArgs(manager);
    PAT(work, 0x88) = args;

    input = work;
    i = 0;
    output = input;
    do {
        U32AT(input, 0xbc) = 0xff;
        if (sub_02034818(i) != NULL) {
            U32AT(output, 0xbc) = i;
            output += 4;
        }
        i++;
        input += 4;
    } while (i < 4);

    args = PAT(work, 0x88);
    ov90_02258800((u8 *)work + 0x8c, PAT(args, 0x38), U32AT(args, 0x34), U32AT(args, 0x3c), args);
    return 1;
}
