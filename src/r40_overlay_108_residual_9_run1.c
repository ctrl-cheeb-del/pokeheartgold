#include "global.h"

#include "r40_overlay_108_residual_9_private.h"

void ov108_021E7224(R40Ov108Work9 *work) {
    work->listA = ListMenuItems_New(3, (enum HeapID)work->heapId);
    work->listB = ListMenuItems_New(2, (enum HeapID)work->heapId);
    ListMenuItems_AppendFromMsgData(work->listA, work->msg, 7, 0);
    ListMenuItems_AppendFromMsgData(work->listA, work->msg, 8, 1);
    ListMenuItems_AppendFromMsgData(work->listA, work->msg, 6, 2);
    ListMenuItems_AppendFromMsgData(work->listB, work->msg, 5, 0);
    ListMenuItems_AppendFromMsgData(work->listB, work->msg, 6, 1);
}
