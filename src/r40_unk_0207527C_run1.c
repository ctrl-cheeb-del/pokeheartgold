#include "r40_unk_0207527C_private.h"

BOOL sub_0207527C(LinkWork7527C *work) {
    u8 *setup;
    int index;
    int i;
    if (sub_02037190() != 264) {
        return FALSE;
    }
    setup = work->setup;
    if (*(u32 *)setup & 0x80) {
        index = sub_0203769C() * 8;
    } else {
        index = sub_0203769C() * 4;
    }
    sub_02075554(*(void **)(setup + 0xF8 + index), *(void **)(setup + 0x148), work->buffer);
    for (i = 0; i < 4; i++) {
        work->friends[i] = Heap_Alloc(5, 0x88);
    }
    return TRUE;
}
