#include "r40_unk_020100C4_private.h"

void sub_020100C4(ComplexBufferR40 *);

void sub_020100C4(ComplexBufferR40 *work) {
    memset(work->head, 0, sizeof(work->head));
    memset(work->block14, 0, sizeof(work->block14));
    memset(work->block44, 0, sizeof(work->block44));
    memset(work->small74, 0, sizeof(work->small74));
    memset(work->tail8C, 0, sizeof(work->tail8C));
}
