#include <string.h>

#include "unk020124b0_sol_partial_internal.h"

BOOL sub_0201275C(FadeEffect *effect) {
    effect->counter++;
    if (effect->counter >= effect->delay) {
        effect->counter = 0;
        int next = effect->frame + 1;
        if (next <= effect->duration) {
            effect->frame = next;
            sub_02012884(&effect->start, effect->frame, effect->duration);
            sub_020127B8(effect);
            SysTask_CreateOnVWaitQueue(sub_02010F00, effect, 0x3FF);
        } else {
            sub_0200FFB4(effect->unk34, effect->unk08, effect->heapId);
            return TRUE;
        }
    }
    return FALSE;
}
