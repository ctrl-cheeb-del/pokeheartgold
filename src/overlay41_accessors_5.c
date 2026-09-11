#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_0224A1A8(void *p) { Sprite_Delete(*(void **)p); memset(p,0,0x10); }

void ov41_0224A1C0(void *p) { ov41_0224A1A8(p); FontOAM_Delete(*(void **)((u8 *)p+0x10)); memset(p,0,0x20); }
