#include "r40_overlay_103_residual_6_private.h"

void ov103_021ED00C(Ov103Work6 *work) {
    u32 i;

    work->context->count = 0;
    for (i = 0; i < 20; i++) {
        work->context->order[i] = 0xFF;
        work->context->mail[i] = Mailbox_AllocAndFetchMailI(work->mailbox, 0, i, 0x9D);
        if (Mail_TypeIsValid(work->context->mail[i]) == TRUE) {
            work->context->order[work->context->count] = i;
            work->context->count++;
        }
    }
    if (work->context->count == 0) {
        work->context->page = 0;
    } else {
        work->context->page = (work->context->count - 1) / 10;
    }
}
