#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_0224B5C8(void *p) { ov41_022465CC(p); }

void ov41_0224B5D0(void *p, u32 v) { *(u32 *)((u8 *)p + 0x264) = v; }
