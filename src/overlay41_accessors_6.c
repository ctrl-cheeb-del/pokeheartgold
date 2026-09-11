#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_0224A238(void *p, u32 a, u32 b, u32 c) { if(p==NULL) GF_AssertFail(); ((u32 *)p)[1]=c;((u32 *)p)[2]=b;((u32 *)p)[3]=a; }

void ov41_0224A254(void *unused) { }

void ov41_0224A258(void **p) { Sprite_SetAnimationFrame(*p, 2); }

void ov41_0224A264(void **p) { Sprite_SetAnimationFrame(*p, 0); }

void ov41_0224A270(void **p) { Sprite_SetAnimationFrame(*p, 1); }
