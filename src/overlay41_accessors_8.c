#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_0224A9B0(void *p) { WindowArray_Delete(p, 1); }
