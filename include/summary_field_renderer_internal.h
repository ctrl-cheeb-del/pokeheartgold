#ifndef UNK_020887C4_PRIVATE_H
#define UNK_020887C4_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "gf_gfx_loader.h"

typedef struct SummaryGraphicsWork {
    BgConfig *bgConfig;
} SummaryGraphicsWork;

void sub_020887C4(SummaryGraphicsWork *, int, NARC *);

#endif
