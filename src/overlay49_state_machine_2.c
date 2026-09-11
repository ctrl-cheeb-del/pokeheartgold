#include "overlay49_state_machine_private.h"

Ov49Work *ov49_0225EEAC(void *ctx, int heap)
{
    int i;
    Ov49Work *work = Heap_Alloc(heap, sizeof(Ov49Work));
    memset(work, 0, sizeof(Ov49Work));
    work->heap = heap;
    work->ctx = ctx;
    for (i = 0; i < 20; i++) ov49_0225F068(&work->entries[i], i, heap);
    ov49_0225F068(&work->extra, 0, heap);
    return work;
}

void ov49_0225EEF8(Ov49Work *work)
{
    int i;
    for (i = 0; i < 20; i++) ov49_0225F074(&work->entries[i]);
    ov49_0225F074(&work->extra);
    Heap_Free(work);
}
