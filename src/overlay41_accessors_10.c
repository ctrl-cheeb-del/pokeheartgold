#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_0224ABF0(void *p) { if (*(u32 *)((u8 *)p+0x138)&0x10) ov41_0224B250((u8 *)p+0xA0); }
