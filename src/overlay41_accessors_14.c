#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_0224B50C(void *p) { ov41_02249CF8((u8 *)p+4,1); }

void ov41_0224B518(void *p) { ov41_02249D60((u8 *)p+4); memset(p,0,0x1C); }
