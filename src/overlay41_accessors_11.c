#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_0224AC80(void *p) { String_Delete(*(void **)((u8 *)p+0x144)); *(void **)((u8 *)p+0x144)=NULL; }

void ov41_0224AC98(void *p) { ov41_0224AF8C((u8 *)p + 0x38); }
