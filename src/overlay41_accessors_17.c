#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_0224B8DC(void *p, const void *q) { *(u32 *)((u8 *)p+0x58)=((u32 *)q)[0]; *(u32 *)((u8 *)p+0x60)=((u32 *)q)[1]; *(u32 *)((u8 *)p+0x64)=((u32 *)q)[2]; *(u32 *)((u8 *)p+0x68)=((u32 *)q)[3]; }
