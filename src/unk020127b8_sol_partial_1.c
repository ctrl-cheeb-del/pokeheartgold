#include "unk020127b8_sol_partial_internal.h"

void sub_02012884(Interpolation *interp, int numerator, int denominator) {
    int value = interp->delta * numerator / denominator;
    value += interp->start;
    interp->value = value;
}

void sub_0201289C(FadeTask *work, const void *param_) {
    const FadeParam8 *param = param_;
    work->allocation = Heap_Alloc(work->heapId, 0x334);
    memset(work->allocation, 0, 0x334);
    sub_02012940(work->allocation, param, work->unk04, work->unk08, work->unk10, work->unk18, work->unk1C, work->heapId);
    work->state++;
}

BOOL sub_020128E0(FadeTask *work) {
    BOOL result = FALSE;
    u8 *state = work->allocation;

    switch (work->state) {
    case 1:
        if (sub_02012A2C(state) == TRUE) {
            sub_02010F34(*(u32 *)(state + 0x324), *(u32 *)(state + 0x32c), work->unk10);
            work->state++;
        }
        break;
    case 2:
        sub_02012A8C(state);
        Heap_Free(work->allocation);
        work->allocation = NULL;
        work->state++;
        result = TRUE;
        break;
    case 3:
        result = TRUE;
        break;
    default:
        GF_AssertFail();
        break;
    }
    return result;
}
