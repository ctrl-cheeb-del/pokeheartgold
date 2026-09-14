#include "overlay99_residual_12_private.h"

void ov99_021E93DC(Ov99ContextR12 *context, void **source) {
    Ov99WorkR12 *work = Heap_Alloc(context->heapId, sizeof(Ov99WorkR12));

    MI_CpuFill8(work, 0, sizeof(Ov99WorkR12));
    work->source = source;
    ov99_021E92EC(context, *source, work->records);
    work->string = String_New(8, context->heapId);
    context->work = work;
}
