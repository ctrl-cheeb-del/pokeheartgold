#include <string.h>

#include "unk020124b0_sol_partial_internal.h"

void sub_020125D4(Interpolation *interp, int numerator, int denominator) {
    int value = interp->delta * numerator / denominator;
    interp->value = value + interp->start;
}

void sub_020125EC(FadeOwner *work, const FadeParam *param) {
    work->effect = Heap_Alloc((enum HeapID)work->heapId, sizeof(FadeEffect));
    memset(work->effect, 0, sizeof(FadeEffect));
    sub_0201268C(work->effect, param, work->unk04, work->unk08, work->unk10, work->unk18, work->unk1C, work->heapId);
    work->state++;
}

BOOL sub_0201262C(FadeOwner *work) {
    FadeEffect *effect = work->effect;
    BOOL done = FALSE;

    switch (work->state) {
    case 1:
        if (sub_0201275C(effect) == TRUE) {
            sub_02010F34(effect->color, effect->callbackArg, work->unk10);
            work->state++;
        }
        break;
    case 2:
        sub_020127B4(effect);
        sub_02010EC8(effect);
        Heap_Free(work->effect);
        work->effect = NULL;
        work->state++;
        done = TRUE;
        break;
    case 3:
        done = TRUE;
        break;
    default:
        GF_AssertFail();
        break;
    }
    return done;
}
