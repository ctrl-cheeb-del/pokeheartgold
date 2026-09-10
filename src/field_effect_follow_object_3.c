#include "field_effect_follow_object_internal.h"

BOOL ov01_021FF418(void *a0, FieldEffectSimpleWork *work) {
    return sub_02023DA4(work->sprite);
}

void ov01_021FF424(void *a0, FieldEffectSimpleWork *work) {
    switch (work->state) {
    case 0:
        if (sub_02023F04(work->sprite, 1 << 12) == 1) {
            work->unk4 = TRUE;
            work->state++;
        }
        break;
    case 1:
        break;
    }
}

void ov01_021FF44C(void *a0, FieldEffectSimpleWork *work) {
    VecFx32 pos;

    sub_02068DB8(a0, &pos);
    sub_02023E50(work->sprite, &pos);
}
