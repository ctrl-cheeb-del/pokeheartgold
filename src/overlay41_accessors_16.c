#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_0224B848(void *p, void *q) { ov41_0224825C((u8 *)p+0x190, *(void **)((u8 *)q+0x5C), *(void **)((u8 *)q+0x68)); }

void ov41_0224B85C(void *p) { ov41_022480E0((u8 *)p+0x190); ov41_02247F90((u8 *)p+0x190); }
