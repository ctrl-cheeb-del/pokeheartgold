#include "field_link_messages_internal.h"

void sub_0205AC4C(struct UnkStruct_02059E1C *p) {
    Heap_Free(p->unk188[0]);
    Heap_Free(p->unk188[1]);
    Heap_Free(p->unk184);
}

void *sub_0205AC70(struct UnkStruct_02059E1C *p) {
    return sub_02036FD8(0x69, p->unk184, 0x66C);
}
