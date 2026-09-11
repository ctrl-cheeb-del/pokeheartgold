#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_02249B94(Ov41Dispatch *d, s32 *x, s32 *y) {
    if (d->mode < 3) ov41_02245FD8(d->obj, x, y);
    else ov41_022497A0(d->obj, x, y);
}
