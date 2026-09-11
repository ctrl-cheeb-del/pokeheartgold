#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_0224B310(void *p) { s32 v=*(s32 *)((u8 *)p+0x20)-1; if(v>=0) *(s32 *)((u8 *)p+0x20)=v; }

void ov41_0224B31C(void *p, s32 a, s32 b, s32 c) { s32 *q=p; q[0]=a;q[1]=a;q[2]=b-a;q[4]=c;q[3]=0; }
